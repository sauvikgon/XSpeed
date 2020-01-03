/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include "counterExample/abstractCE.h"
#include "counterExample/simulation.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include <fstream>
#include <sstream>

#include "../core/continuous/Polytope/Polytope.h"
#include "../core/HybridAutomata/Hybrid_Automata.h"
#include "../core/math/analyticODESol.h"
#include "../core/math/matrix.h"
#include "../io/io_utility.h"
#include "../utilities/gradient.h"
#include "../utilities/Post_Assignment.h"

unsigned int dim;
unsigned int N;

hybrid_automata::ptr HA;
std::vector<int> locIdList;
std::list<transition::ptr> transList;
polytope::ptr bad_poly;
std::list<refinement_point> ref_pts;
std::vector<std::vector<double> > X0; // list of start point of the trajectory segments. Used only in the NLP-LP mixed program

std::list<symbolic_states::ptr> ce_sym_states; // list of CE abstract sym states. Used only in the NLP-LP mixed problem

unsigned int samples = 0;

/*
 * Computes the distance of the trajectory to the invariant, gradient of the distance of the trace
 * to the given invariant polytope w.r.t the trace start point. It returns the end point of the
 * simulation.
 */
std::vector<double> simulate_trajectory(const std::vector<double> &x0,
		Dynamics &D, const double &time, double &distance, polytope::ptr Inv,
		std::vector<double> &grad) {
	/**
	 * This function is to simulate trajectory from x0 for time units.
	 * todo: current dummy implementation to be completed
	 */

	simulation::ptr s = simulation::ptr(new simulation(x0.size(), 100, D));
	std::vector<double> y;
//	If trace validation is enabled.
//	y = s->bounded_simulation(x0, time, Inv); // validated trace generation

	distance = 0;
	for (unsigned int i = 0; i < grad.size(); i++) {
		grad[i] = 0;
	}

	y = s->metric_simulate(x0, time, distance, Inv, grad);
// 	if trace validation is not enabled, call the following simulate function
//	y = s->simulate(x0, time); // no trace validation
	assert(y.size() == dim);
	return y;
}

//constructor method
abstractCE::abstractCE(std::list<symbolic_states::ptr> s_states,
		std::list<transition::ptr> ts, hybrid_automata::ptr h,
		polytope::ptr fpoly) {

	sym_states = s_states;
	trans = ts;
	length = sym_states.size();
	H = h;
	forbid_poly = fpoly;
}

symbolic_states::const_ptr abstractCE::get_first_symbolic_state() const {
	std::list<symbolic_states::ptr>::const_iterator it = sym_states.begin();
	return *it;
}
symbolic_states::const_ptr abstractCE::get_last_symbolic_state() const {
	std::list<symbolic_states::ptr>::const_iterator it = sym_states.end();
	return *it;
}

void abstractCE::set_sym_states(std::list<symbolic_states::ptr> sym) {
	sym_states = sym;
	length = sym_states.size();
}

symbolic_states::const_ptr abstractCE::get_symbolic_state(
		unsigned int i) const {
	assert(0 <= i && i < get_length());
	unsigned int j = 0;
	std::list<symbolic_states::ptr>::const_iterator it = sym_states.begin();
	while (j < i) {
		it++;
		j++;
	}
	return *it;
}

bool abstractCE::filter(std::vector<unsigned int> template_seq) {

	if (template_seq.size() == 0)
		return true;

	if (template_seq.size() != this->length)
		return false;

	unsigned int locid;
	std::list<symbolic_states::ptr>::iterator iter = this->sym_states.begin();

	for (unsigned int i = 0; i < template_seq.size(); i++) {
		symbolic_states::ptr symb_state = *iter;
		//ensure that the symbolic state has just one discrete location
		assert(symb_state->getDiscreteSet().getDiscreteElements().size() == 1);

		locid = *(symb_state->getDiscreteSet().getDiscreteElements().begin());
		if (template_seq[i] != locid) {
			return false;
		}
		iter++;
	}
	return true;
}

/**
 * Routine to compute concrete trajectory from given
 * abstract counter example using non-linear optimization
 * routine and using the constraints from flowpipe
 *
 * @Rajarshi
 * 28th January 2016
 * The approach FC in the HSCC 2019 Paper
 */
concreteCE::ptr abstractCE::gen_concreteCE(double tolerance,
		const std::list<refinement_point> &refinements) {

//	 Generate an nlopt object with the constraints defined by the Abstract
//	 counter example

//	 1. Get the dimension of the optimization problem by
//	 getting the dimension of the continuous set of the abstract counter example

	symbolic_states::const_ptr S = get_first_symbolic_state();
	//dim = S->getContinuousSetptr()->get_dimension();	//@Amit modified: Since when called from WoFC, will not have this set
	dim = S->getInitialPolytope()->getSystemDimension();
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size() + 1; // the length of the counter example
	bad_poly = this->forbid_poly;
	ref_pts = refinements;

	//assert that the number of transitions equals 1 less than the length of the abstract CE path

	std::cout << "Length of the CE, N=" << N << std::endl;
	std::cout << "gen_concreteCE: dimension =" << dim << ", length of CE=" << N
			<< std::endl;

	// initialize the global locIdList
	locIdList.resize(N);

	std::cout << "Location ID sequence in symbolic CE: ";
	std::set<int> d;
	for (unsigned int i = 0; i < N; i++) {
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout << locIdList[i] << " | ";
	}
	std::cout << "\n";

//	 2. The dimensionality of the opt problem is N vectors, one starting point
//	 for each of the abstract sym state of the CE + N dwell times. Moreover,
//	 each starting vector is of dimension dim. Therefore, the total number of
//	 variables of the optimization problem are dim*N + N

	unsigned int optD = N * dim + N;
	std::cout << "nlopt problem dimension = " << optD << std::endl;
//	nlopt::opt myopt(nlopt::LN_AUGLAG, optD); // derivative free
//	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free
	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based
//	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative based
//	nlopt::opt myopt(nlopt::LD_AUGLAG, optD);
//	nlopt::opt myopt(nlopt::GN_ISRES,optD); // derivative free global

	// 	local optimization routine
	unsigned int maxeval = 20000;
	//unsigned int maxeval = 4000;
	myopt.set_min_objective(myobjfunc2, NULL);
	myopt.set_maxeval(maxeval);
	myopt.set_stopval(1e-6);

	//Set Initial value to the optimization problem
	std::vector<double> x(optD, 0);

	std::vector<double> v(dim);

	std::vector<double> lb(optD), ub(optD);
	double max, min, start_min, start_max;

	// Generate bounds for each start point. Also initialize each start point as the average of min and max
	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
			{
		// dxli: the whole flowpipe is a sequence of sub-flowpipes, each of which
		// denotes \omega in each location.
		// S is the sub-flowpipe in i-th sequence; P is the first \omega in S.
		S = get_symbolic_state(i);
		polytope::ptr P = S->getInitialPolytope();

		lp_solver lp(GLPK_SOLVER);

		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());

		// 	we add bound constraints on the position parameters, which are required to run global opt routines.
		std::vector<double> dir(dim, 0);
		double min, max;
		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
				{
			dir[j] = -1;
			try {
				min = -1 * lp.Compute_LLP(dir);
			} catch (...) {
				// assuming that the exception is caused due to an unbounded solution
				min = -999;	// an arbitrary value set as solution
			}
			dir[j] = 1;
			try {
				max = lp.Compute_LLP(dir);
			} catch (...) {
				// assuming that the exception is caused due to an unbounded solution
				max = +999; // an arbitrary value set as solution
			}
			unsigned int index = i * dim + j;

			lb[index] = min;
			ub[index] = max;

			dir[j] = 0;
			// dxli: using the (min+max)/2 to initialize variables.
			x[index] = (lb[index] + ub[index]) / 2;
		}
	}
//	Set initial value to the time variables
//	Restrict dwell time within the projections of C_i in time variable

//	We assume that the time variable is named as 't' in the model.
//	We find out the min,max components of the time variable

	unsigned int t_index =
			get_first_symbolic_state()->getInitialPolytope()->get_index("t");

	assert((t_index >= 0) && (t_index < dim));

	std::vector<double> dmin(dim, 0), dmax(dim, 0);
	dmax[t_index] = 1;
	dmin[t_index] = -1;

	std::list<polytope::ptr> polys;
	polytope::ptr guard;

	std::list<transition::ptr>::iterator it = transList.begin();
	transition::ptr T;

	bool aggregation = true; //default is ON

	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		polytope::ptr P;
		if (i == N - 1) {
			// If last abstract symbolic state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(
					aggregation, bad_poly, 1);
			assert(polys.size() >= 0); // The last sym state of an abstract CE must intersect with the bad set

			if (polys.size() > 1)
				P = get_template_hull(S->getContinuousSetptr(), 0,
						S->getContinuousSetptr()->getTotalIterations() - 1); // 100% clustering
			else
				P = polys.front();

			P = P->GetPolytope_Intersection(bad_poly);
		} else {
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGaurd();
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(
					aggregation, guard, 1);

			assert(polys.size() >= 1); // An abstract CE state must have intersection with the trans guard
			if (polys.size() > 1)
				P = get_template_hull(S->getContinuousSetptr(), 0,
						S->getContinuousSetptr()->getTotalIterations() - 1); // 100% clustering
			else
				P = polys.front();
			// Now intersect P with guard
			P = P->GetPolytope_Intersection(guard);
		}

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		// ensure that time is always positive
		try {
			max = lp.Compute_LLP(dmax);
		} catch (...) {
			// assuming that the exception is caused due to an unbounded solution
			max = 999; // an arbitrary large value set as solution
		}
		try {
			min = -1 * lp.Compute_LLP(dmin);
		} catch (...) {
			// assuming that the exception is caused due to an unbounded solution
			min = 0; // the min value that time can take is 0.
		}

		// we add the bounds as constraints in the nlopt

		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		polytope::ptr init_of_symb = S->getInitialPolytope();

		lp1.setConstraints(init_of_symb->getCoeffMatrix(),
				init_of_symb->getColumnVector(),
				init_of_symb->getInEqualitySign());
		// Ensure that the time is positive
		start_min = -1 * lp1.Compute_LLP(dmin);
		start_max = lp1.Compute_LLP(dmax);
		ub[N * dim + i] = max - start_min;
		if (min <= start_max)
			lb[N * dim + i] = 0;
		else
			lb[N * dim + i] = min - start_max;

		// We may choose to take the average time as the initial dwell time
		x[N * dim + i] = (lb[N * dim + i] + ub[N * dim + i]) / 2;

		// Increment the Transition to the next in the symbolic path
		if (it != transList.end())
			it++;
	}

	// debug (print lb,ub)
//	for(unsigned int i=0;i<lb.size();i++){
//		std::cout << "lb at " << i << " =" << lb[i] << std::endl;
//		std::cout << "ub at " << i << " =" << ub[i] << std::endl;
//		//assert(lb[i] <= ub[i]);
//	}
	//--
	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);

	double minf;
	try {
		std::cout << "Local optimization algorithm called:"
				<< myopt.get_algorithm_name() << std::endl;
		myopt.set_stopval(tolerance);
		unsigned int res = myopt.optimize(x, minf);

		if (res == NLOPT_SUCCESS)
			std::cout
					<< "Splicing with FC: NLOPT stopped successfully returning the found minimum\n";
		else if (res == NLOPT_STOPVAL_REACHED)
			std::cout
					<< "Splicing with FC: NLOPT stopped due to stopping value (1e-6) reached\n";
		else if (res == NLOPT_MAXEVAL_REACHED)
			std::cout
					<< "Splicing with FC: NLOPT stopped due to reaching maxeval = "
					<< maxeval << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "nlopt returned min : " << minf << "\n";
	std::cout << "Length of abstract counter example:" << N << "\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance
				<< ", with no. of refined search:" << refinements.size()
				<< std::endl;
		return cexample;
	} else {
		std::ofstream ce_trace;
		// one trajectory per symbolic state to be added in the concreteCE
		for (unsigned int i = 0; i < N; i++) {
			// create the sample
			concreteCE::sample s;
			std::set<int>::iterator dset_iter =
					get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
			unsigned int locId = *dset_iter;

			std::vector<double> y(dim);
			for (unsigned int j = 0; j < dim; j++) {
				y[j] = x[i * dim + j];
			}

			double time = x[N * dim + i];
			s.first = y;
			//s.second = y[dim-1];
			s.second = time;
			concreteCE::traj_segment traj;
			traj.first = locId;
			traj.second = s;
			cexample->push_back(traj);
		}
	}

	return cexample;
}

/**
 * Generate concrete trajectory using splicing with mixed NLP-LP problem (Goran's Idea).
 * @Rajarshi: Dec 2019
 */
/*
 *  dxli: September, 2018
 */
void abstractCE::construct_bound_constraints(math::matrix<double> &coeff_mat,
		std::vector<double> &col, std::vector<double> lb,
		std::vector<double> ub, unsigned int dim) {
	// number of segments in abstract traj.
	unsigned int N = lb.size() / dim;
	unsigned int lpDim = coeff_mat.size2();

	math::matrix<double> row_temp = math::matrix<double>(1, lpDim);
	double col_temp;
	for (unsigned int i = 0; i < N; i++) {
		for (unsigned int j = 0; j < row_temp.size2(); j++) {
			row_temp(0, j) = 0;
		}

		for (unsigned int j = 0; j < dim; j++) {
			// upper bound
			row_temp(0, i * dim + j) = 1;
			col_temp = ub[i * dim + j];

			if (i == 0 && j == 0) {
				row_temp.matrix_copy(coeff_mat);
			} else {
				coeff_mat.matrix_join(row_temp, coeff_mat);
			}
			col.push_back(col_temp);

			// lower bound, need to flip the sign
			row_temp(0, i * dim + j) = -1;
			col_temp = -lb[i * dim + j];

			coeff_mat.matrix_join(row_temp, coeff_mat);
			col.push_back(col_temp);

			row_temp(0, i * dim + j) = 0;
		}

	}
}

/**
 * Method to construct an LP from the abstract counter example,
 * for trajectory splicing. The LP construction is by fixing the
 * dwell time of the trajectory segments. The fixed dwell times
 * are passed as an argument to this function.
 */
lp_solver abstractCE::build_lp(std::vector<double> dwell_times) {
	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();

	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size() + 1; // the length of the counter example
	bad_poly = this->forbid_poly;

	/*
	 * 2. Declare a linear programming problem by fixing the dwell-times.
	 *
	 * The dwell-times are fixed and the starting point of the trajectory segments
	 * are variables in this setting of the optimization problem. Also, the end-points
	 * obtained by dwelling for the fixed time; are kept the variables in the LP.
	 *
	 * We present the splicing as a linear programming problem in this setting.
	 * Naming conventions:
	 * x^i_j to represent the j-th component of the i-th start-point in an N length 
	 * abstract counterexample.
	 * {x*}^i_j to represent the j-th component of the i-th end-point in an N length
	 * abstract counterexample.
	 */

	lp_solver lp_fixed_time(GLPK_SOLVER);
	unsigned int num_constr, num_vars;

	/* For each splicing point, there will be 2*dim new variables introduced
	 * E.g. |{x*}^i_j - x^{i+1}_j| will introduce variables pj_1, pj_2 to represent the constraints
	 * {x*}^i_j - x^{i+1}_j = p^i_j - {p'}^i_j; and p^i_j, {p'}^i_j >=0.
	 * For each dimension, two new variables will be introduced. Thus, (2 * dim) many new
	 * vars will be introduced per splicing point. There are total (N-1) splicing points
	 * for a N length abstract counter-example. Hence, a total of [2 * dim * (N-1)] new vars
	 * will be there in the LP.
	 * In addition, the LP has the original (N * dim) vars, representing N start points of 
	 * the N trajectory segments. 
	 *
	 * The LP must also have (N * dim) vars to represent the N end points of the segments,
	 * In total, the LP will have (N*dim) + (N*dim) + (2 * dim * (N-1)) variables.
	 *
	 * Convention:
	 * X = 2 * dim * (N-1)
	 * Cols 0 to (X - 1) to represent the new variables.
	 * Y = (N*dim) represent the no. of variables to represent N start points of the segments.
	 * Cols X to (X+Y-1) to represent these
	 * The rest of the (N*dim) vars to represent the N end-points of the trajectory segments.
	 * Cols X+Y to X+2Y-1. 
	 */
	unsigned int X = 2 * dim * (N - 1);
	unsigned int Y = N * dim;
	num_vars = X + Y + Y;

	/*
	 * We construct LPs with constraints as bounds on each variable
	 * {min}^i_j <= x^i_j <= {max}^i_j; there will be [2*dim*N] such constraints
	 *
	 * To address the mod function, there will be constraints of the form:
	 * {x*}^i_j - x^{i+1)_j = p^i_j - {p'}^i_j; there will be [2*dim*(N-1)] 
	 * inequality constraints, one for each splicing points in the N length
	 * abstract CE. Since equality constraint has be to encoded as two 
	 * inequality constraint, we have a multiplication by 2.
	 *
	 * To enforce positivity on each new variable  p^i_j, {p'}^i_j, we have
	 * additionally 2 * dim * (N-1) constraints, since there are these
	 * many new variables.
	 *
	 * To relate the end points of the segments with the start points,
	 * with the fixed dwell times, we have constraints of the form:
	 * {x*}^i = e^{At}.x^i + v., where t is the fixed dwell time.
	 * 
	 * There will be a total of (N * dim * 2) such constraints. one equality
	 * constraint per dimension of the starting point x.
	 *
	 * In total, there will be:
	 * [2 * dim * N + (N-1)*dim + 2 * dim * (N-1) + (N*dim*2)] LP constraints.
	 *
	 * Convention:
	 * The first X1 = [2 * dim * (N-1)] rows to represent the positivity constraints.
	 * The next  X1 = [2 * dim * (N-1)] rows to represent the  {x*}^i_j - x^{i+1)_j = p^i_j - {p'}^i_j constrs.
	 * The next  X2 = [2 * dim * N] rows to represent the bound constraints.
	 * The remaining X2 = (2 * dim * N) rows to represent the end-point constrs, {x*}^i = e^{At}.x^i + v.
	 */
	//num_constr = (2 * dim * N) + 2*N*dim + (2 * dim * (N-1) + (N*dim*2));
	unsigned int X1 = 2 * dim * (N - 1);
	unsigned int X2 = 2 * dim * N; //bounds on each variable of the start-point for N segments;
	num_constr = X1 + X1 + X2 + X2 + 2*dim;

	math::matrix<double> A(num_constr, num_vars, 0);

	std::vector<double> b(num_constr);
	b.assign(num_constr, 0);

	unsigned int boundsign = 1;
	lp_fixed_time.setMin_Or_Max(1);
	// populate the constraints matrix and bounds vector

	// We add the positivity constraints below p^i_j >= 0
	for (unsigned int i = 0, j = 0; i < X; i++, j++) { //X or X1
		A(i, j) = -1;
	}

	unsigned int check = X1;
//	std::cout<<"Check = "<< check <<" newRow = "<< X <<std::endl; //OK

	/*
	 *  To do: Add the next [2 * dim * (N-1)] rows to represent the  x_i - y_i = p_i' - p_i'' constrs.
	 */
	unsigned int newRow = X1, newCol = 0;
	//1st Part: constrs only on the columns related to p' and p''
	for (unsigned int i = 0; i < (N - 1); i++) // iterate over (N-1) splicing. Each splice has dim number of absolute term
	{
		for (unsigned int j = 0; j < dim; j++) // for each dimension or absolute term 2 new variables
		{
			//for (unsigned int k = 0; k < 2; k++)	//p' and p''
			//{
			newCol = i * 2 * dim + j * 2 + 0; //k=0
			A(newRow, newCol) = -1;
			newCol = i * 2 * dim + j * 2 + 1; //k=1
			A(newRow, newCol) = 1;
			//}
			newRow++;

			newCol = i * 2 * dim + j * 2 + 0; //k=0
			A(newRow, newCol) = 1;
			newCol = i * 2 * dim + j * 2 + 1; //k=1
			A(newRow, newCol) = -1;

			newRow++;
		}
	}
//	check=X1;
//	std::cout<<"Check = "<< check<<" newRow = "<< newRow <<std::endl; //OK

	newRow = X1;
	//2nd Part: constrs only on the column related to the start-points involved in splice distance computation term
	unsigned int startPoint = X;
	for (unsigned int i = 0; i < (N - 1); i++) // iterate over (N-1) transitions but access only the start-points from 2nd transition or (i+1)th transition
	{
		for (unsigned int j = 0; j < dim; j++) // for each dimension
		{
			newCol = startPoint + (i + 1) * dim + j;
			A(newRow, newCol) = -1;

			newRow++;

			newCol = startPoint + (i + 1) * dim + j;
			A(newRow, newCol) = 1;

			newRow++;
		}
	}

	//Last Part: constrs only on the column related to the end-points involved in splice distance computation term
	//check=X1;
	//std::cout<<"Check = "<< check<<" newRow = "<< newRow <<std::endl; //OK

	newRow = X1;
	startPoint = X + Y;
	for (unsigned int i = 0; i < (N - 1); i++) // iterate over N-1 transitions or splice
			{
		for (unsigned int j = 0; j < dim; j++) // for each dimension
				{
			newCol = startPoint + i * dim + j;
			A(newRow, newCol) = 1;

			newRow++;

			newCol = startPoint + i * dim + j;
			A(newRow, newCol) = -1;

			newRow++;
		}
	}
	//Todo: to be Optimized into one loop for all the three parts if possible
	//assert(newRow == 2*X1);
//	check=2*X1;
//	std::cout<<"4. Check = "<< check<<" newRow = "<< newRow <<std::endl; //OK
	assert(newRow == 2 * X1);

	/*
	 *  To do: using the lb_x and ub_x values, add bound constraints in the A matrix.
	 */

	//cout<<"N="<<N<<" Dim="<<dim<<" \n";
	startPoint = X;
	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		S = get_symbolic_state(i);
		polytope::ptr P = S->getInitialPolytope();

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());

		// we add bound constraints on the position parameters, which are required to run global opt routines.
		std::vector<double> dir(dim, 0);
		double min, max;
		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
				{
			dir[j] = -1;
			try {
				min = -1 * lp.Compute_LLP(dir);
			} catch (...) {
				// assuming that the exception is caused due to an unbounded solution
				min = -999;	// an arbitrary value set as solution
			}
			dir[j] = 1;
			try {
				max = lp.Compute_LLP(dir);
			} catch (...) {
				// assuming that the exception is caused due to an unbounded solution
				max = +999; // an arbitrary value set as solution
			}

			newCol = startPoint + i * dim + j;
			A(newRow, newCol) = 1;
			b[newRow] = max;

			newRow++;

			A(newRow, newCol) = -1;
			b[newRow] = -1 * min;

			dir[j] = 0;
			newRow++;
		}
	}

//	check=2*X1 + X2;
//	std::cout<<"5. Check = "<< check<<" newRow = "<< newRow <<std::endl;
	assert(newRow == 2 * X1 + X2);

	/*
	 *  To do: Add the remaining (N * dim * 2) rows to represent the end-point constrs, y_i = e^{At}.x_i + v.
	 */

	// To do: using the lb_x and ub_x values, add bound constraints in the A matrix.
	// To do: Add the next [2 * dim * (N-1)] rows to represent the  x_i - y_i = p_i' - p_i'' constrs.
	// Adding the (N * dim * 2) rows to represent the end-point constrs, y_i = e^{At}.x_i + v.
	// Get the sequence of loc_ids from the abstract counterexample.
	locIdList.resize(N);
	std::set<int> d;
	for (unsigned int i = 0; i < N; i++) {
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
	}


	std::list<polytope::ptr> polys;
	polytope::ptr guard;
	std::list<transition::ptr>::iterator it = transList.begin();
	transition::ptr T;


	startPoint = X + Y;
	for (unsigned int i = 0; i < N; i++) {
		Dynamics D;
		math::matrix<double> expAt; // To contain the e^At matrix, for the fixed time.
		unsigned int loc_id = locIdList[i];
		location::ptr ha_loc_ptr = HA->getLocation(loc_id);
		D = ha_loc_ptr->getSystem_Dynamics();
		D.MatrixA.matrix_exponentiation(expAt, dwell_times[i]);

		// Now, we calculate v = A^{-1}.(e^{At} - I)* D.C
		std::vector<double> v = ODESol_inhomogenous(D, dwell_times[i]);

		// Using expAt and v, add the constraints on the end-points to the LP
		/*
		 * Till here we have x1' = expAt x + v
		 * Now to obtain new start-point for the next transition we need to perform the mapping operation
		 * This gives x2 = Rx' + w; where x2 is the new start-point with R as the mapping matrix and w the mapping constant
		 * xdash = R(expAt x + v) + w
		 * xdash = R expAt x + R v + w
		 * Here R and expAt is matrix multiplication giving constant matrix and v,w are constant vectors
		 * So, we first solve these constant terms and then form equations
		 */

		math::matrix<double> RexpAt;//matrix multiplication, RexpAt = R.expAt
		std::vector<double> Rvplusw(dim); // Rvplusw = R.v + w
		Assign R;
		if (i != (N - 1)) {	//For all transition except the last perform mapping operation
			// assign the transition pointer
			T = *(it);	//runs based on the for-i-loop except the last iteration
			// assignment of the form: Rx + w
			R = T->getAssignT();
			R.Map.multiply(expAt, RexpAt);
			R.Map.mult_vector(v, Rvplusw);
			for (unsigned int j = 0; j < dim; j++) {
				Rvplusw[j] += R.b[j];
			}
		} else { //i == (N-1)  the last transition don't need mapping
			RexpAt = expAt;
			Rvplusw = v;
		}

		for (unsigned int j = 0; j < dim; j++) {
			newCol = X + Y + i * dim + j;
			A(newRow, newCol) = 1; //first inequality
			b[newRow] = Rvplusw[j];
			for (unsigned int k = 0; k < RexpAt.size2(); k++) {
				newCol = X + i * dim + k;
				A(newRow, newCol) = -1 * RexpAt(j, k); //first inequality

				A(newRow + 1, newCol) = RexpAt(j, k); //second inequality
			}
			newRow++;
			newCol = X + Y + i * dim + j;
			A(newRow, newCol) = -1;  //second inequality
			b[newRow] = -1 * Rvplusw[j];
			newRow++;
		}	// Increment the transition to the next in the symbolic path

		if (it != transList.end())
			it++;
	}
//	check=2*X1+2*X2;
//	std::cout<<"6. Check = "<< check<<" newRow = "<< newRow <<std::endl;
	assert(newRow == (2 * X1 + 2 * X2));









	/*
	 * Adding Constraints on Bad-set, the last point must lie inside the bad set.
	 *
	 * Note: new bad set should be, (Flowpipe intersection with Invariant) followed by intersection with the supplied bad set.
	 * This step is crucial for benchmarks such as navigation.
	 *
	 */

// *********************** Taking care of bad set on boundaries with the next location
	bool aggregation=true;
	S = get_symbolic_state(N - 1);
	polytope::ptr P;
	unsigned int loc_id = locIdList[N-1];	//last location
	location::ptr ha_loc_ptr = HA->getLocation(loc_id);
	polytope::ptr loc_inv = ha_loc_ptr->getInvariant();

	//bad_poly = bad_poly->GetPolytope_Intersection(loc_inv); //Invariant with Bad poly

	polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation, bad_poly, 1);
	assert(polys.size() >= 0); // The last sym state of an abstract CE must intersect with the bad set
	if (polys.size() > 1){
		P = get_template_hull(S->getContinuousSetptr(), 0,
				S->getContinuousSetptr()->getTotalIterations() - 1); // 100% clustering
	} else {
		P = polys.front();
	}
	P = P->GetPolytope_Intersection(loc_inv);	//Invariant intersection with templated flowpipe
	P = P->GetPolytope_Intersection(bad_poly);	//followed by intersection with templated flowpipe
// ***********************

	lp_solver lp(GLPK_SOLVER);
	lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());
	// we add bound constraints on
	std::vector<double> dir(dim, 0);
	double min, max;
	for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
	{
		dir[j] = -1;
		try {
			min = -1 * lp.Compute_LLP(dir);
		} catch (...) {
			// assuming that the exception is caused due to an unbounded solution
			min = -999;	// an arbitrary value set as solution
		}
		dir[j] = 1;
		try {
			max = lp.Compute_LLP(dir);
		} catch (...) {
			// assuming that the exception is caused due to an unbounded solution
			max = +999; // an arbitrary value set as solution
		}

		newCol = (X + Y) + (N-1) * dim + j;
		A(newRow, newCol) = 1;
		b[newRow] = max;

		newRow++;

		A(newRow, newCol) = -1;
		b[newRow] = -1 * min;

		dir[j] = 0;
		newRow++;
	}

assert (newRow==((2 * X1 + 2 * X2) + 2 * dim));












	// Building the lp problem with the created A and b values

	lp_fixed_time.setConstraints(A, b, boundsign);

	// set the objective function: p_1' + p_1'' + p_2' + p_2''+ ... over all new vars
	for (unsigned int i = 0; i < X; i++) {
		lp_fixed_time.set_obj_coeff(i, 1);
	}

	/*cout << "A matrix\n";
	cout << A;
	cout << endl << "Bound Vector b is\n";
	for (unsigned int i = 0; i < b.size(); i++) {
		cout << b[i] << endl;
	}*/

	return lp_fixed_time; // returns the built lp.
}


/**
 * Amit:
 * Method to construct and solve an NLP from the abstract counter example,
 * for trajectory splicing. The NLP construction is by fixing the start points but
 * keeping the dwell times of the trajectory segments as variable. The start points
 * are passed as an argument to this function.
 */
 void abstractCE::build_nlp(nlopt::opt & myoptStartPointFixed) {
	//1. Generate an nlopt object with the hard constraints on dwell times
	//2. Objective function as distance(startPts, endPts) + dp(endPts,Reach Intersects Guard) + dp(endPts, Bad_set)


	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getInitialPolytope()->getSystemDimension();
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size() + 1; // the length of the counter example
	bad_poly = this->forbid_poly;
	//ref_pts = refinements;

	// initialize the global locIdList
	locIdList.resize(N);
	std::set<int> d;
	/*for (unsigned int i = 0; i < N; i++) {
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout <<"Amit Doing AGAIN?   "<< locIdList[i] << " | ";
	}*/

	polytope::ptr P;

	bool aggregation = true; //default is ON

	//std::vector<double> solutionsTau(optD, 0);

	std::vector<double> lb_t(N), ub_t(N);
	std::vector<double> t(N, 0);
	double minf = 1e10;

	unsigned int t_index = get_first_symbolic_state()->getInitialPolytope()->get_index("t");

	assert((t_index >= 0) && (t_index < dim));
//	cout <<"1 successfull!! \n";
	std::vector<double> dmin(dim, 0), dmax(dim, 0);
	dmax[t_index] = 1;
	dmin[t_index] = -1;
	double min, max, start_min, start_max;
	std::list<polytope::ptr> polys;
	polytope::ptr guard;
	std::list<transition::ptr>::iterator it = transList.begin();
	transition::ptr T;

	//For every N-locations find the bounds on dwell time

	for (unsigned int i = 0; i < N; i++) // iterate over the N locations of the counter-example to get the invariant
	{
		S = get_symbolic_state(i);

		unsigned int loc_id = locIdList[i];	//last location
		location::ptr ha_loc_ptr = HA->getLocation(loc_id);
		polytope::ptr loc_inv = ha_loc_ptr->getInvariant();


//		cout <<"2 successfull!! \n";
		polytope::ptr P;
		if (i == (N - 1)) {	//For last location find intersection between Flowpipe and Bad set
//			cout <<"7 successfull!! \n";
			// If last abstract symbolic state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(
					aggregation, bad_poly, 1);
			assert(polys.size() >= 0); // The last sym state of an abstract CE must intersect with the bad set
//			cout <<"8 successfull!! polys.size() = "<<polys.size()<< "\n";
			if (polys.size() > 1){
				P = get_template_hull(S->getContinuousSetptr(), 0,
						S->getContinuousSetptr()->getTotalIterations() - 1); // 100% clustering
//				cout <<"8a successfull!! \n";
			} else {
				P = polys.front();
//				cout <<"8b successfull!! \n";
			}
//			cout <<"9 successfull!! \n";

			/*matrix<double> A = bad_poly->getCoeffMatrix();
			std::vector<double> b = bad_poly->getColumnVector();
			cout << "A matrix\n";
			cout << A;
			cout << endl << "Bound Vector b is\n";
			for (unsigned int i = 0; i < b.size(); i++) {
				cout << b[i] << endl;
			}

			matrix<double> A2 = P->getCoeffMatrix();
			std::vector<double> b2 = P->getColumnVector();
			cout << "A2 matrix\n";
			cout << A2;
			cout << endl << "Bound Vector b2 is\n";
			for (unsigned int i = 0; i < b2.size(); i++) {
				cout << b2[i] << endl;
			}
*/

			P = P->GetPolytope_Intersection(loc_inv);

			P = P->GetPolytope_Intersection(bad_poly);

//			cout <<"3 successfull!! \n";
		} else {
			// Take time projection of flowpipe \cap transition guard
			T = *(it);	//runs based on the for-i-loop except the last iteration
			guard = T->getGaurd();
//			cout <<"4 successfull!! \n";
			if (guard->getIsUniverse())
				std::cout << "#Guard is Universe#\n" << std::endl;

			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(
					aggregation, guard, 1);

			assert(polys.size() >= 1); // An abstract CE state must have intersection with the trans guard
			if (polys.size() > 1)
				P = get_template_hull(S->getContinuousSetptr(), 0,
						S->getContinuousSetptr()->getTotalIterations() - 1); // 100% clustering
			else
				P = polys.front();

			// Now intersect P with guard
			P = P->GetPolytope_Intersection(loc_inv);

			P = P->GetPolytope_Intersection(guard);

		}

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		// ensure that time is always positive
		try {
			max = lp.Compute_LLP(dmax);
		} catch (...) {
			// assuming that the exception is caused due to an unbounded solution
			max = 999; // an arbitrary large value set as solution
		}
		try {
			min = -1 * lp.Compute_LLP(dmin);
		} catch (...) {
			// assuming that the exception is caused due to an unbounded solution
			min = 0; // the min value a time can take is 0.
		}
//		cout <<"6 successfull!! \n";

		// we add the bounds as constraints in the nlopt
		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		polytope::ptr init_of_symb = S->getInitialPolytope();

		lp1.setConstraints(init_of_symb->getCoeffMatrix(),
				init_of_symb->getColumnVector(),
				init_of_symb->getInEqualitySign());
		// Ensure that the time is positive
		start_min = -1 * lp1.Compute_LLP(dmin);
		start_max = lp1.Compute_LLP(dmax);
		ub_t[i] = max - start_min;
		if (min <= start_max)
			lb_t[i] = 0;
		else
			lb_t[i] = min - start_max;

		// Increment the transition to the next in the symbolic path
		if (it != transList.end())
			it++;
		//t[i] = (lb_t[i] + ub_t[i]) / 2;	//setting some initial \tau value for call to optimize()

	}


	myoptStartPointFixed.set_lower_bounds(lb_t);
	myoptStartPointFixed.set_upper_bounds(ub_t);

/*
	cout << endl << "Upper Bound Vector b2 is\n";
	for (unsigned int i = 0; i < ub_t.size(); i++) {
		cout << ub_t[i] << endl;
	}
	cout << endl << "Lower Bound Vector b2 is\n";
	for (unsigned int i = 0; i < lb_t.size(); i++) {
		cout << lb_t[i] << endl;
	}
*/

/*
	cout<<"Before Call FixedStartPoints are \n";
	for (int i=0;i<N;i++){
		for (int j=0;j<fixedStartPoint[i].size();j++){
			cout << fixedStartPoint[i][j] <<"  ";
		}
	}
	cout<<endl;
*/



//	myoptStartPointFixed.optimize(t, minf);
//
//	solutionsTau = t;
	//return myoptStartPointFixed; //myoptStartPointFixed object
//	return t;

}



/**
 * Implementing the LP-NLP iterative routine for trajectory splicing
 * @Rajarshi; 20 Dec 2019.
 */
concreteCE::ptr abstractCE::gen_concreteCE_iterative(double tolerance,
		const std::list<refinement_point> &refinements) {
	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();

	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size() + 1; // the length of the counter example
	bad_poly = this->forbid_poly;
	ref_pts = refinements;



	std::cout << "Length of the CE, N=" << N << std::endl;
	std::cout << "gen_concreteCE: dimension =" << dim << ", length of CE=" << N
			<< std::endl;

	// initialize the global locIdList
	locIdList.resize(N);
	std::cout << "Location ID sequence in symbolic CE: ";

	std::set<int> d;
	for (unsigned int i = 0; i < N; i++) {
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout << locIdList[i] << " | ";
	}

	/* 1. Declare the sub-problem by fixing starting points of each location.
	 *
	 * The length of the counter example is N. When fixing the starting point of
	 * each location, the decision variables are dwell time in each location.
	 * Therefore, the dimension of the opt problem is N. This problem is supposed
	 * to be a nonlinear optimization problem.
	 */

	/* build nlp creates a trajectory splicing opt. prob.
	 * where start points of the trajectory segments are fixed
	 * and the dwell times of the segments are variables
	 */

	std::vector<double> x0[N]; // to contain the fixed start-points.
/*
cout <<"What is N="<<N <<"   ";
x0[0].resize(3);
cout <<"What is x0.size="<< x0->size() <<"   ";
*/

	std::vector<double> lb_t(N), ub_t(N);

	double max, min, start_min, start_max;

	/* build the lp where dwell times are fixed and the start points of the
	 * trajectory are variables.
	 */
	std::vector<double> dwell_times(N); // contains the fixed dwell_times

	get_first_symbolic_state()->getInitialPolytope();

	unsigned int t_index =
			get_first_symbolic_state()->getInitialPolytope()->get_index("t");

	assert((t_index >= 0) && (t_index < dim));

	std::vector<double> dmin(dim, 0), dmax(dim, 0);
	dmax[t_index] = 1;
	dmin[t_index] = -1;

	std::list<polytope::ptr> polys;
	polytope::ptr guard;

	std::list<transition::ptr>::iterator it = transList.begin();
	transition::ptr T;

	bool aggregation = true; //default is ON

	// initialize values for dwell time from calculating min, max bounds.
	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);

		unsigned int loc_id = locIdList[i];	//location ID
		location::ptr ha_loc_ptr = HA->getLocation(loc_id);
		polytope::ptr loc_inv = ha_loc_ptr->getInvariant();


		polytope::ptr P;
		if (i == N - 1) {
			// If last abstract symbolic state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(
					aggregation, bad_poly, 1);
			assert(polys.size() >= 0); // The last sym state of an abstract CE must intersect with the bad set

			if (polys.size() > 1)
				P = get_template_hull(S->getContinuousSetptr(), 0,
						S->getContinuousSetptr()->getTotalIterations() - 1); // 100% clustering
			else
				P = polys.front();

			P = P->GetPolytope_Intersection(loc_inv);
			P = P->GetPolytope_Intersection(bad_poly);
		} else {
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGaurd();
			if (guard->getIsUniverse())
				std::cout << "#Guard is Universe#\n" << std::endl;

			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(
					aggregation, guard, 1);

			assert(polys.size() >= 1); // An abstract CE state must have intersection with the trans guard
			if (polys.size() > 1)
				P = get_template_hull(S->getContinuousSetptr(), 0,
						S->getContinuousSetptr()->getTotalIterations() - 1); // 100% clustering
			else
				P = polys.front();
			// Now intersect P with guard
			P = P->GetPolytope_Intersection(loc_inv);
			P = P->GetPolytope_Intersection(guard);

		}

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		// ensure that time is always positive
		try {
			max = lp.Compute_LLP(dmax);
		} catch (...) {
			// assuming that the exception is caused due to an unbounded solution
			max = 999; // an arbitrary large value set as solution
		}
		try {
			min = -1 * lp.Compute_LLP(dmin);
		} catch (...) {
			// assuming that the exception is caused due to an unbounded solution
			min = 0; // the min value a time can take is 0.
		}

		// we add the bounds as constraints in the nlopt

		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		polytope::ptr init_of_symb = S->getInitialPolytope();

		lp1.setConstraints(init_of_symb->getCoeffMatrix(),
				init_of_symb->getColumnVector(),
				init_of_symb->getInEqualitySign());
		// Ensure that the time is positive
		start_min = -1 * lp1.Compute_LLP(dmin);
		start_max = lp1.Compute_LLP(dmax);
		ub_t[i] = max - start_min;
		if (min <= start_max)
			lb_t[i] = 0;
		else
			lb_t[i] = min - start_max;

		// We may choose to take the average time as the initial dwell time
		dwell_times[i] = (lb_t[i] + ub_t[i]) / 2;

		// Increment the transition to the next in the symbolic path
		if (it != transList.end())
			it++;
	}


	double minf = 1e10; // a large value to start
	//nlopt::opt myoptDwellTime; // nlp object;
	unsigned int optD = N;

	//	nlopt::opt myoptDwellTime(nlopt::LN_AUGLAG, optD); // derivative free
	//	nlopt::opt myoptDwellTime(nlopt::LN_COBYLA, optD); // derivative free

	nlopt::opt myoptDwellTime(nlopt::LD_MMA, optD); // derivative based

	//  nlopt::opt myoptDwellTime(nlopt::LD_MMA, optD); // derivative based
	//	nlopt::opt myoptDwellTime(nlopt::GN_ISRES,optD); // derivative free global





	unsigned int maxeval = 400;//20000;
	myoptDwellTime.set_maxeval(maxeval);
	myoptDwellTime.set_stopval(tolerance);
	myoptDwellTime.set_xtol_rel(1e-4);
	build_nlp(myoptDwellTime); // Build nlp with bounds on dwell-time for each transitions


	unsigned int X1 = 2 * dim * (N - 1); //list of new variables
	unsigned int nlp_status;
	unsigned int maxIterations = 1000, maxiter=0;
	double previousMinf=999, previousRes=999; //some large value
	double smallChange = 1e-10;
	//tolerance = 0.00001;
	cout.precision(17);

	try {

		/*
		 * Loop for Uniform-distributed Random Restart of the Search Algorithm
		 */

		unsigned int totalRuns= 10; //ToDo: We must find out what is the maximum numbers of iteration sufficient to Restart

		std::vector<std::vector<double>> mydwell_times(totalRuns);
		for (int i = 0; i < totalRuns; i++) {
			mydwell_times[i].resize(N); //dynamic memory allocation
		}

		//For each Location generating 1000 random dwell_times for performing different restart operation
		for (int j = 0; j < N; j++) {

			double a = lb_t[j], b = ub_t[j];
			std::default_random_engine generator;
			std::uniform_real_distribution<double> distribution(a, b);

			for (int i = 0; i < totalRuns; i++) {

				double number = distribution(generator); //uniformly generating random numbers
				mydwell_times[i][j] = number; //This is done so that for the same Location Uniform generation can be maintained
			}

		}

		//dwell_times[j] = number; //Random number between lb_t and ub_t


/*
 * Now create a loop for totalRuns to try out Random Restart Algorithm.....
 * Note we must fix totalRuns otherwise it will not stop searching the path which actually do not have any Concrete CE.
 *
 */
		int iterNo=0;
while (iterNo < totalRuns)
{
	//minf = 1e10; // reset a large value to restart
	dwell_times = mydwell_times[iterNo];

		while (minf > tolerance) {
			maxiter++;
			//solve the lp with fixed times
			lp_solver fixed_time_Lp = build_lp(dwell_times);
			cout <<"Dwell time\n";
			for (unsigned int j = 0; j < dwell_times.size(); j++) {
				cout << dwell_times[j] <<"  ";
			}
			cout<<endl;

			double res = fixed_time_Lp.solve();
			std::vector<double> x = fixed_time_Lp.get_sv();
			//From this vector, get the N vectors in x0 vector
			//cout << "Creating and Printing x0[i][j] (LP res = )"<< res <<" \n";
			for (unsigned int i = 0; i < N; i++) {
				x0[i].resize(dim);	//declaring each array element its size
				for (unsigned int j = 0; j < dim; j++) {
					x0[i][j] = x[X1 + i * dim + j];
				//	cout << x0[i][j] <<"  ";
				}
			//	cout<<endl;
			}

			cout <<"GLPK Solution res  = "<<res<< "\n";
			if (res < tolerance)
				break;

			// solve the nlp with fixed start points.
			//cout <<"build_nlp successfull!! \n";
			myoptDwellTime.set_min_objective(myobjfuncIterativeNLP, x0);
			//cout <<"After call to nlp Optimize \n";

			nlp_status = myoptDwellTime.optimize(dwell_times, minf);
			cout <<"nlp_optimize successfull  minf = "<<minf<< "\n";

			double newChange = fabs(previousMinf - minf);
			if (smallChange>=newChange){
				cout<< "STOPING LP-NLP loop DUE to very small change in the result!!\n";
				break;
			}
			if (((previousMinf == minf) && (previousRes == res))
					|| (maxiter == maxIterations)) { //This is WORKING
				cout
						<< "STOPING LP-NLP loop either, DUE TO no change in the result or MAX-ITERATIONS REACHed!!\n";
				break;
			}
			previousMinf = minf;
			previousRes = res;
		} //End of Search for a dwell_time

		if (minf <= tolerance)
			break; //out of the loop random restart loop

		iterNo++;
	} //Loop for next random restart search

		if (iterNo == totalRuns)
			std::cout
					<< "Splicing with Iterative LP-NLP: stopped Searching all possible random start-point!!"
					<< std::endl;
		else if (nlp_status == NLOPT_SUCCESS)
			std::cout
					<< "Splicing with Iterative LP-NLP: NLOPT stopped successfully returning the found minimum\n";
		else if (nlp_status == NLOPT_STOPVAL_REACHED)
			std::cout
					<< "Splicing with Iterative LP-NLP: NLOPT stopped due to stopping value (1e-6) reached\n";
		else if (nlp_status == NLOPT_MAXEVAL_REACHED)
			std::cout
					<< "Splicing with Iterative LP-NLP: NLOPT stopped due to reaching maxeval!!"
					<< std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "nlopt returned min : " << minf << "\n";

	//tolerance = 1.1; //Just to see all traces

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance
				 << ", with no. of refined search:" << refinements.size() << std::endl;
		return cexample;
	} else {
		std::cout << "nlopt returned min : " << minf << "\n";
		std::cout << "Length of abstract counter example:" << N << "\n";

		/*if (minf > tolerance) {
		 std::cout << "Obtained minimum greater than " << tolerance
		 << ", with no. of refined search:" << refinements.size() << std::endl;
		 return cexample;
		 } else {*/
		std::ofstream ce_trace;
		// one trajectory per symbolic state to be added in the concreteCE
		for (unsigned int i = 0; i < N; i++) {
			// create the sample
			concreteCE::sample s;
			std::set<int>::iterator dset_iter =
					get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
			unsigned int locId = *dset_iter;

			std::vector<double> y(dim);
			for (unsigned int j = 0; j < dim; j++) {
				y[j] = x0[i][j];
			}

			s.first = y;
			s.second = dwell_times[i];
			concreteCE::traj_segment traj;
			traj.first = locId;
			traj.second = s;
			cexample->push_back(traj);
		}
	}


	return cexample;
}

/**
 * Generate concrete trajectory using splicing with NLP problem (Zutchi, Sankaranarayanan's  Idea)
 * The approach WoFC in the HSCC 2019 Paper
 */
concreteCE::ptr abstractCE::gen_concreteCE_NLP_HA(double tolerance,
		const std::list<refinement_point> &refinements) {
	//	 Generate an nlopt object with the constraints defined by the abstract
	//	 counter example

	//	 1. Get the dimension of the optimization problem by
	//	 getting the dimension of the continuous set of the abstract counter example

	symbolic_states::const_ptr S = get_first_symbolic_state();
	//dim = S->getContinuousSetptr()->get_dimension(); //@Amit modified Since when called from WoFC, will not have this set
	dim = S->getInitialPolytope()->getSystemDimension();
	N = get_length(); // the length of the counter example
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	bad_poly = this->forbid_poly;
	ref_pts = refinements;

	//assert that the number of transitions equals 1 less than the length of the abstract CE path
	std::cout << "CE generation with HA implicit constraints\n";
	std::cout << "Length of the CE, N = " << N << std::endl;
	std::cout << "Number of Transitions in the abstract CE: "
			<< transList.size() << std::endl;
	std::cout << "gen_concreteCE: dimension =" << dim << ", length of CE=" << N
			<< std::endl;

	// initialize the global locIdList
	locIdList.resize(N);

	std::set<int> d;
	for (unsigned int i = 0; i < N; i++) {
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout << locIdList[i] << " | ";
	}
	std::cout << "\n";
	//	 2. The dimensionality of the opt problem is N vectors, one starting point
	//	 for each of the abstract sym state of the CE + N dwell times. Moreover,
	//	 each starting vector is of dimension dim. Therefore, the total number of
	//	 variables of the optimization problem are dim*N + N

	unsigned int optD = N * dim + N;
	std::cout << "nlopt problem dimension = " << optD << std::endl;
	//	nlopt::opt myopt(nlopt::LN_AUGLAG, optD); // derivative free
	//	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free
	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based
	//	nlopt::opt myopt(nlopt::GN_ISRES,optD); // derivative free global

	// 	local optimization routine
	unsigned int maxeval = 20000;
	myopt.set_min_objective(myobjfunc2, NULL);
	myopt.set_maxeval(maxeval);
	myopt.set_stopval(1e-6);
	std::vector<double> x(optD, 0);
	polytope::ptr P;

	// A random objective function created for lp solving
	std::vector<double> lb(optD), ub(optD);

	std::list<transition::ptr>::iterator trans_iter = transList.begin();
	transition::ptr T;

	for (unsigned int i = 0; i < N; i++) // iterate over the N locations of the counter-example to get the invariant
			{

		if (i == 0) // Initial polytope is given, so initialize the constraint polytope on x_0 to be the initial polytope
				{
			P = this->get_first_symbolic_state()->getInitialPolytope();
			// set arbitrarily large but finite time bounds
			lb[N * dim] = 0;
			ub[N * dim] = 999;

		} else {

			T = *(trans_iter);
			assert(T!=NULL);

			location::ptr src_loc = HA->getLocation(T->getSource_Location_Id());
			location::ptr dest_loc = HA->getLocation(
					T->getDestination_Location_Id());

			polytope::ptr src_loc_inv = src_loc->getInvariant();
			polytope::ptr dest_loc_inv = dest_loc->getInvariant();

			/*  This code is not Commented in Dongxu's version
			 *
			 polytope::ptr guard = T->getGaurd();

			 assert(guard!=NULL);
			 assert(src_loc_inv!=NULL);
			 assert(dest_loc_inv!=NULL);

			 polytope::ptr src_inv_inters_g = src_loc_inv->GetPolytope_Intersection(guard);

			 polytope::ptr mapped_poly;
			 polytope::ptr feas_poly; // feas_poly is the feasible region to sample start points

			 Assign trans_assign = T->getAssignT();
			 math::matrix<double> directions;

			 std::vector<std::vector<double> > box_directions;
			 box_directions = generate_axis_directions(HA->getDimension());

			 get_ublas_matrix(box_directions, directions);


			 if (trans_assign.Map.isInvertible()) {
			 mapped_poly = post_assign_exact(src_inv_inters_g, trans_assign.Map, trans_assign.b);
			 } else {
			 mapped_poly = post_assign_approx_deterministic(src_inv_inters_g,
			 trans_assign.Map, trans_assign.b, directions,1);
			 }

			 feas_poly = mapped_poly->GetPolytope_Intersection(dest_loc_inv);
			 //P = feas_poly; */
			P = dest_loc_inv; // The feasible region for start point of the traj. segment is taken as the loc invariant
			assert(P!=NULL);

			// set arbitrarily large but finite time bounds
			lb[N * dim + i] = 0;
			ub[N * dim + i] = 999;
		}
		//P->printPoly();

		if (P->getIsUniverse()) {
			// set arbitrarily large but finite bounds on start points
			std::cout << "Constraint polytope is universe\n";
			for (unsigned int j = 0; j < dim; j++) {
				unsigned int index = i * dim + j;
				lb[index] = -999;
				ub[index] = 999;
			}
		} else {
			lp_solver lp(GLPK_SOLVER);
			lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
					P->getInEqualitySign());

			//we add bound constraints on the position parameters, which are required to run global opt routines.
			std::vector<double> dir(dim, 0);
			double min, max;
			for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
					{
				dir[j] = -1;
				try {
					min = -1 * lp.Compute_LLP(dir);
				} catch (...) {
					// Assuming that the exception is due to unbounded solution in the min direction
					min = -999; // setting an arbitrary lower bound
				}
				dir[j] = 1;

				try {
					max = lp.Compute_LLP(dir);
				} catch (...) {
					// Assuming that the exception is due to unbounded solution in the max direction
					max = 999; // setting an arbitrary upper bound
				}
				unsigned int index = i * dim + j;
				lb[index] = min;
				ub[index] = max;
				x[index] = (lb[index] + ub[index]) / 2;
				dir[j] = 0;
			}
		}
		// Initialize the dwell-time values to 0
		for (unsigned int i = 0; i < N; i++) {
			x[N * dim + i] = 0;
		}
		// increment transition iterator
		if (trans_iter != transList.end() && i != 0) // do not increment trans iteration at the first iteration
			trans_iter++;
	}

	// debug
	std::cout << "The lower bounds are:\n";
	for (unsigned int i = 0; i < lb.size(); i++)
		std::cout << lb[i] << " ";
	std::cout << "\n";
	std::cout << "The upper bounds are:\n";
	for (unsigned int i = 0; i < ub.size(); i++)
		std::cout << ub[i] << " ";
	std::cout << "\n";
	//---

	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);

	double minf;
	try {
		std::cout << "Local optimization algorithm called:"
				<< myopt.get_algorithm_name() << std::endl;
		myopt.set_stopval(tolerance);
		unsigned int res = myopt.optimize(x, minf);
		if (res == NLOPT_SUCCESS)
			std::cout
					<< "Splicing WoFC: NLOPT stopped successfully returning the found minimum\n";
		else if (res == NLOPT_STOPVAL_REACHED)
			std::cout
					<< "Splicing WoFC: NLOPT stopped due to stopping value (1e-6) reached\n";
		else if (res == NLOPT_MAXEVAL_REACHED)
			std::cout
					<< "Splicing WoFC: NLOPT stopped due to reaching maxeval = "
					<< maxeval << std::endl;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "nlopt returned min : " << minf << "\n";
	std::cout << "Length of abstract counter example:" << N << "\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance
				<< ", with no. of refined search:" << refinements.size()
				<< std::endl;
		return cexample;
	} else {
		std::ofstream ce_trace;
		// one trajectory per symbolic state to be added in the concreteCE
		for (unsigned int i = 0; i < N; i++) {
			// create the sample
			concreteCE::sample s;
			std::set<int>::iterator dset_iter =
					get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
			unsigned int locId = *dset_iter;

			std::vector<double> y(dim);
			for (unsigned int j = 0; j < dim; j++) {
				y[j] = x[i * dim + j];
			}

			double time = x[N * dim + i];
			s.first = y;
			//s.second = y[dim-1];
			s.second = time;
			concreteCE::traj_segment traj;
			traj.first = locId;
			traj.second = s;
			cexample->push_back(traj);
		}
	}
	return cexample;

}

concreteCE::ptr abstractCE::get_validated_CE(double tolerance,
		unsigned int algo_type) {

	// call to genCE func with no refining trajectory
	std::list<struct refinement_point> refinements;
	refinements.clear(); // No refinement point initially

	concreteCE::ptr cexample;
	bool val_res = true;
	unsigned int max_refinements = 3, ref_count = 0; // maximum limit to refinement points to be added.

	double valid_tol = 1e-3; // validation error tolerance, on invariant crossing. @Amit changed 1e-3 to 1e-6

	do {
		struct refinement_point pt;

		if (algo_type == 1) // FC called
			cexample = gen_concreteCE(tolerance, refinements);
		else if (algo_type == 2) { // WoFC called
			cexample = gen_concreteCE_NLP_HA(tolerance, refinements);
		} else if (algo_type == 3) //std::cout << "LP-NLP mixed implementation not in place yet\n";
			cexample = gen_concreteCE_iterative(tolerance, refinements);
		else {
			std::cout
					<< "Invalid algo type specified for trajectory splicing\n";
		}

		if (cexample->is_empty()) {
			cexample->set_refinement_count(ref_count);
			return cexample;
		}

		val_res = cexample->valid(pt, valid_tol);
		//putting off validation loop by refinements
		//val_res = true;
		//--

		if (!val_res) {
			refinements.push_back(pt);
			ref_count++;
			//debug: print the invalid trajectory in a file, in the first two dimensions
			cexample->plot_ce("./invalid_traj.txt", 0, 1);
		} else {
			std::cout << "Generated Trace Validated with " << ref_count
					<< " point Refinements\n";
			cexample->set_refinement_count(ref_count);
			return cexample;
		}
		std::cout << "Restarting Search with added refinement point\n";
	} while (!val_res && ref_count < max_refinements);

	throw std::runtime_error(
			"Validation of counter example FAILED after MAX Refinements\n");
	return concreteCE::ptr(new concreteCE());
}

concreteCE::ptr abstractCE::search_concreteCE(double tolerance,
		std::list<abstractCE::ptr> paths, std::vector<unsigned int> path_filter,
		unsigned int algo_type) {

	concreteCE::ptr ce;
	abstractCE::ptr abs_ce;

	bool real_ce = false;
	double error_tol = tolerance; // splicing error tolerance

	for (std::list<abstractCE::ptr>::iterator it = paths.begin();
			it != paths.end(); it++) {

		abs_ce = *(it);
		// add a filter function to search for concrete ce only in a specific abstract trace

		bool search_ce = abs_ce->filter(path_filter);

		if (search_ce) {
			ce = abs_ce->get_validated_CE(error_tol, algo_type);
			if (ce->is_empty()) {
				std::cout
						<< "Cannot splice trajectory segments with the accepted error tolerance\n";
			} else {
				real_ce = true;
				break;
			}
		}
	}
	if (real_ce)
		return ce;
	else {
		ce = concreteCE::ptr(new concreteCE());
		return ce;
	}
}
