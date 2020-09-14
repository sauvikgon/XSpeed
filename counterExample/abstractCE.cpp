/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include <application/sfDirections.h>
#include <application/sfUtility.h>
#include <io/ioUtility.h>
#include <utilities/postAssignment.h>
#include "counterExample/abstractCE.h"
#include "counterExample/simulation.h"
#include <fstream>
#include <sstream>

#include "core/continuous/polytope/polytope.h"
#include "core/hybridAutomata/hybridAutomata.h"
#include "core/math/analyticODESol.h"
#include "core/math/matrix.h"
#include "utilities/gradient.h"

unsigned int dim;
unsigned int N;

hybrid_automata* HA;
std::vector<int> locIdList;
std::list<transition::ptr> transList;
polytope::ptr bad_poly;
std::list<refinement_point> ref_pts;
std::vector<std::vector<double> > X0; // list of start point of the trajectory segments. Used only in the NLP-LP mixed program

std::list<symbolic_states::ptr> ce_sym_states; // list of CE abstract sym states. Used only in the NLP-LP mixed problem
std::vector<double> start_pos; // the start vectors of opt trajectory from LP solving. Useful in the context of CE_ALGO_TYPE 5

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
		std::list<transition::ptr> ts, hybrid_automata* h,
		polytope::ptr fpoly) {

	sym_states = s_states;
	trans = ts;
	length = sym_states.size();
	ha = h;
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
 * The approach FC in the HSCC 2019 Paper
 */
concreteCE::ptr abstractCE::gen_concreteCE(double tolerance,
		const std::list<refinement_point> &refinements) {


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

	// initialize the global locIdList
	locIdList.resize(N);

	DEBUG_MSG("Searching counterexample to safety with trajectory splicing (FC)");
	DEBUG_MSG("Location ID sequence in symbolic CE: ");
	std::set<int> d;
	for (unsigned int i = 0; i < N; i++) {
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		DEBUG_MSG(to_string(locIdList[i]) + " | ");
	}

//	 2. The dimensionality of the opt problem is N vectors, one starting point
//	 for each of the abstract sym state of the CE + N dwell times. Moreover,
//	 each starting vector is of dimension dim. Therefore, the total number of
//	 variables of the optimization problem are dim*N + N

	unsigned int optD = N * dim + N;
//	std::cout << "nlopt problem dimension = " << optD << std::endl;
//	nlopt::opt myopt(nlopt::LN_AUGLAG, optD); // derivative free
//	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free
	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based
//	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative based
//	nlopt::opt myopt(nlopt::LD_AUGLAG, optD);
//	nlopt::opt myopt(nlopt::GN_ISRES,optD); // derivative free global

	// 	Parameters of the optimization routine
	unsigned int maxeval = 20000;
	unsigned int maxtime = 60; // time-out of 1 min per abstract ce.

	myopt.set_min_objective(myobjfunc2, NULL);
	//myopt.set_maxeval(maxeval);
	myopt.set_maxtime(maxtime);
	myopt.set_stopval(tolerance); // search stopping value, set typically to 1e-6.

	//Set Initial value to the optimization problem
	std::vector<double> x(optD, 0);

	std::vector<double> v(dim);

	std::vector<double> lb(optD), ub(optD);
	double max, min, start_min, start_max;

	// Add constraints on the start points of the trajectory
	for (unsigned int i = 0; i < N; i++)
	{
		// dxli: the whole flowpipe is a sequence of sub-flowpipes, each of which
		// denotes \omega in each location.
		// S is the sub-flowpipe in i-th sequence; P is the first polytope in S.

		S = get_symbolic_state(i);
		polytope::ptr P = S->getInitialPolytope();

		// set bound constraints
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
			// (min+max)/2 initializaion of variables.
			x[index] = (lb[index] + ub[index]) / 2;
		}
	}

//	Set initial value to the time variables
//	Restrict dwell time within the projections of C_i in time variable

//	We assume that the time variable is named as 't' in the model.
//	We find out the min, max components of the time variable

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
			guard = T->getGuard();
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
		x[N * dim + i] = (ub[N * dim + i] + lb[N * dim + i]) / 2;

		// Increment the transition to the next in the symbolic path
		if (it != transList.end())
			it++;
	}
	// set the lower and upper bounds on vars
	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);

	double minf;
	try {
		myopt.set_stopval(tolerance);
		unsigned int res = myopt.optimize(x, minf);

		if (res == NLOPT_SUCCESS)
			DEBUG_MSG("Splicing with FC: NLOPT stopped successfully");
		else if (res == NLOPT_STOPVAL_REACHED)
			DEBUG_MSG("Splicing with FC: NLOPT stopped due to stopping value (1e-6) reached");
		else if (res == NLOPT_MAXEVAL_REACHED)
			DEBUG_MSG("Splicing with FC: NLOPT stopped due to reaching maxeval = " + to_string(maxeval));
		else if (res == NLOPT_MAXTIME_REACHED)
			DEBUG_MSG("Splicing with FC: NLOPT stopped due to reaching maxtime = " + to_string(myopt.get_maxtime()));

	} catch (std::exception &e) {
		string msg = e.what();
		DEBUG_MSG(msg + "\n");
	}

	DEBUG_MSG("nlopt returned min : " + to_string(minf));
	DEBUG_MSG("Length of abstract counter example:"+ to_string(N));
	DEBUG_MSG("Number of iterations completed:" + to_string(myopt.get_maxeval()));

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		DEBUG_MSG("Obtained minimum greater than " + to_string(tolerance) + ", No. of refined search:" + to_string(refinements.size()) +
				" No. of iterations completed:" + to_string(myopt.get_maxeval()));
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
	 * {x*}^i_j to represent the j-th component of the i-th end-point in an N length abstract counterexample, after transforming with transition map.
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
	 * The rest of the (N*dim) vars to represent the N transition mapped end-points of the trajectory segments.
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
	 * To relate the transition mapped end points of the segments with the start points,
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
	 * The following X2 = [2 * dim * N] rows to represent the end-point constrs, {x*}^i = e^{At}.x^i + v.
         * The last X3 = [2 * dim * N] rows to represent the bound constraints
         * on the transition mapped end-points.
	 */
	//num_constr = (2 * dim * N) + 2*N*dim + 2*N*dim + (2 * dim * (N-1) + (N*dim*2));
	unsigned int X1 = 2 * dim * (N - 1);
	unsigned int X2 = 2 * dim * N; //bounds on each variable of the start-point for N segments;
	num_constr = X1 + X1 + X2 + X2 + 2 * dim;

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

	assert(newRow == 2 * X1);

	/*
	 *  To do: using the lb_x and ub_x values, add bound constraints in the A matrix.
	 */

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

	assert(newRow == 2 * X1 + X2);

	/*
	 *  To do: Add the remaining (N * dim * 2) rows to represent the end-point constrs, y_i = e^{At}.x_i + v.
	 */
	
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
		D = ha_loc_ptr->getSystemDynamics();
		D.MatrixA.matrix_exponentiation(expAt, dwell_times[i]);

		polytope::ptr loc_inv = ha_loc_ptr->getInvariant();
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

		math::matrix<double> RexpAt; //matrix multiplication, RexpAt = R.expAt
		std::vector<double> Rvplusw(dim); // Rvplusw = R.v + w
		Assign R;
		if (i != (N - 1)) {	//For all transition except the last perform mapping operation
			T = *(it);			
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
	assert(newRow == (2 * X1 + 2 * X2));

	/*
	 * Adding Constraints on Bad-set, the last point must lie inside the bad set.
	 *
	 * Note: new bad set should be, (Flowpipe intersection with Invariant) followed by intersection with the supplied bad set.
	 * This step is crucial for benchmarks such as navigation.
	 *
	 */

// *********************** Taking care of bad set on boundaries with the next location
	S = get_symbolic_state(N - 1);
	polytope::ptr P;
	unsigned int loc_id = locIdList[N - 1];	//last location
	location::ptr ha_loc_ptr = HA->getLocation(loc_id);
	polytope::ptr loc_inv = ha_loc_ptr->getInvariant();

	P = bad_poly->GetPolytope_Intersection(loc_inv); //Invariant with Bad poly
	lp_solver lp(GLPK_SOLVER);
	lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
			P->getInEqualitySign());
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

		newCol = (X + Y) + (N - 1) * dim + j;
		A(newRow, newCol) = 1;
		b[newRow] = max;

		newRow++;

		A(newRow, newCol) = -1;
		b[newRow] = -1 * min;

		dir[j] = 0;
		newRow++;
	}

	assert(newRow == ((2 * X1 + 2 * X2) + 2 * dim));

	// Building the lp problem with the created A and b values

	lp_fixed_time.setConstraints(A, b, boundsign);

	// set the objective function: p_1' + p_1'' + p_2' + p_2''+ ... over all new vars
	for (unsigned int i = 0; i < X; i++) {
		lp_fixed_time.set_obj_coeff(i, 1);
	}

	return lp_fixed_time; // returns the built lp.
}

const userOptions& abstractCE::getUserOptions() const {
	return user_options;
}

void abstractCE::setUserOptions(const userOptions& userOptions) {
	user_options = userOptions;
}

/**
 * Implementing the LP-NLP iterative routine for trajectory splicing
 * @Rajarshi: 20 Dec 2019.
 */
concreteCE::ptr abstractCE::gen_concreteCE_iterative(double tolerance,
		const std::list<refinement_point> &refinements) {
	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();
	//debug
	//std::cout << "gen_concreteCE_iterative:Number of SFM cols:" << S->getContinuousSetptr()->getTotalIterations() << std::endl;
	//concreteCE::ptr cexample1 = concreteCE::ptr(new concreteCE());
	//return cexample1;
	//---
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size() + 1; // the length of the counter example
	bad_poly = this->forbid_poly;
	ref_pts = refinements;

	// initialize the global locIdList
	locIdList.resize(N);
	DEBUG_MSG("Location ID sequence in symbolic CE: ");

	std::set<int> d;
	for (unsigned int i = 0; i < N; i++) {
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		DEBUG_MSG(to_string(locIdList[i]) + " | ");
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

	std::vector<double> lb_t(N), ub_t(N);

	double max, min, start_min, start_max;

	std::vector<double> dwell_times(N); // contains the fixed dwell_times


	unsigned int t_index = S->getInitialPolytope()->get_index("t");

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
			assert(polys.size() >= 1); // The last sym state of an abstract CE must intersect with the bad set

			if (polys.size() > 1){
				std::runtime_error("abstractCE::gen_concreteCE_iterative: Impl missing for no set aggregation\n");
			}
			else
				P = polys.front();

			P = P->GetPolytope_Intersection(loc_inv);
			P = P->GetPolytope_Intersection(bad_poly);
		} else {
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGuard();
			if (guard->getIsUniverse())
				DEBUG_MSG("abstractCE::gen_concreteCE_iterative: Guard is Universally true predicate");

			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(
					aggregation, guard, 1);

			assert(polys.size() >= 1); // An abstract CE state must have intersection with the guard
			if (polys.size() > 1)
				std::runtime_error("abstractCE::gen_concreteCE_iterative: Impl missing for no set aggregation\n");
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

	unsigned int optD = N;
	unsigned int X1 = 2 * dim * (N - 1); //list of new variables in LP

	nlopt::opt myoptDwellTime(nlopt::LD_MMA, optD); // derivative based

	unsigned int maxeval = 100; // the max allowed iterations in nlp

	myoptDwellTime.set_lower_bounds(lb_t);
	myoptDwellTime.set_upper_bounds(ub_t);

	myoptDwellTime.set_maxeval(maxeval);
	myoptDwellTime.set_stopval(tolerance);

	double minf = 1e10; // a large value to start
	double last_iter_lpopt = 1e10; // stores the opt returned by lp-solver from the last iteration
								 // A large value in the beginning.
	const double diff = 1e-10; // the difference to decide stuck at local minima/saddle point.
	bool stuck_at_local_min=false, success=false;

	// A random restart algorithm for jumping out of local minima.
	const unsigned int max_restarts = 20; // the max allowed restarts
	unsigned int num_restart = 0; // keeps the count of number of restarts
	std::default_random_engine generator;

	boost::timer::cpu_timer timer;
	using boost::timer::cpu_times;
	using boost::timer::nanosecond_type;
	nanosecond_type const sixhundred_seconds(60 * 1000000000LL);
	// a ce search in an abstract path is to timeout after 60 secs.
	timer.start();

	for(unsigned int i=0;i<max_restarts;i++){

		while (minf > tolerance) {

			//solve the lp with fixed times
			lp_solver fixed_time_Lp = build_lp(dwell_times);

			double lp_res = fixed_time_Lp.solve();
			//std::cout << "lp returned res = " << lp_res << std::endl;

			std::vector<double> x = fixed_time_Lp.get_sv();

			//From this vector, get the N start vectors in x0
			for (unsigned int i = 0; i < N; i++) {
				x0[i].resize(dim);	//declaring each array element its size		
				for (unsigned int j = 0; j < dim; j++) {
					x0[i][j] = x[X1 + i * dim + j];
				}
			}

			minf = lp_res;
			if (lp_res < tolerance){
				success = true;
				break;
			}
			if( (last_iter_lpopt - lp_res) < diff){
				stuck_at_local_min = true;
				break;
			}
			last_iter_lpopt = lp_res; // storing this lp_res for comparison in the next iteration.
			//std::cout << "last lp_res = " << lp_res << std::endl;

			// solve the nlp with fixed start points.
			myoptDwellTime.set_min_objective(myobjfuncIterativeNLP, x0);
			double nlp_res;
			myoptDwellTime.optimize(dwell_times, nlp_res);
			//cout << "nlp returned opt. = " << nlp_res << "\n";
			minf = nlp_res;
			if (nlp_res < tolerance){
				success = true;
				break;
			}

			cpu_times const elapsed_times(timer.elapsed());
			nanosecond_type const elapsed(elapsed_times.user);
			if (elapsed > sixhundred_seconds)
			{
				std::cout << "Timed-out on the abstract counterexample\n";
				success = true; // here, success true is break the restart loop.
				break;
			}
			//std::cout << "last nlp_res = " << nlp_res << std::endl;

		} // end of alternating lp-nlp loop.

		if(success){
			std::cout << "#random restarts = " << num_restart << std::endl;
			break; // splicing complete. terminate.
		}
		//std::cout << "Number of solver restarts:" << num_restart << std::endl;
		if(stuck_at_local_min){
			// get a new random start value of the dwell times, and restart search.
			for(unsigned int j=0;j<N;j++){
				std::uniform_real_distribution<double> distribution(lb_t[j], ub_t[j]);

				double new_start = distribution(generator); //uniformly generating random numbers
				dwell_times[j] = new_start; // This is done so that for the same Location Uniform generation can be maintained
			}
			stuck_at_local_min = false;
			num_restart++;
			last_iter_lpopt=1e10; // last lp res set to a large value;
		}

	} // end of search restart loop/

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		DEBUG_MSG("Obtained minimum greater than "+ to_string(tolerance) + ", with no. of refined search:" + to_string(refinements.size()));
		return cexample;
	} else {
		DEBUG_MSG("Alternating solver returned min : " + to_string(minf)) ;
		DEBUG_MSG("Length of abstract counter example:" + to_string(N));
		DEBUG_MSG("Number of solver restarts:" + to_string(num_restart));

		std::ofstream ce_trace;
		// one trajectory per symbolic state to be added in the concreteCE
		for (unsigned int i = 0; i < N; i++) {
			// create the sample
			concreteCE::sample s;
			std::set<int>::iterator dset_iter =
					get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
			unsigned int locId = *dset_iter;

			//std::cout<< "\nSegment No = "<< i << " ce-trajectory starting point: ";
			std::vector<double> y(dim);
			for (unsigned int j = 0; j < dim; j++) {
				y[j] = x0[i][j];
			//	std::cout<<y[j] <<"   ";	//Prints all the System Variables
			}
			//std::cout <<"\n and ce-trajectory dwell-time = "<< dwell_times[i] << endl;
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
	dim = S->getInitialPolytope()->getSystemDimension();
	N = get_length(); // the length of the counter example
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	bad_poly = this->forbid_poly;
	ref_pts = refinements;

	//assert that the number of transitions equals 1 less than the length of the abstract CE path
	DEBUG_MSG("CE generation with HA implicit constraints");
	DEBUG_MSG("Length of the CE, N = " + to_string(N));

	DEBUG_MSG("Number of Transitions in the abstract CE: "+ to_string(transList.size()));
	DEBUG_MSG("gen_concreteCE: dimension =" + to_string(dim) + ", length of CE=" + to_string(N));
	// initialize the global locIdList
	locIdList.resize(N);

	std::set<int> d;
	for (unsigned int i = 0; i < N; i++) {
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		DEBUG_MSG(to_string(locIdList[i]) + " | ");
	}

	//	 2. The dimensionality of the opt problem is N vectors, one starting point
	//	 for each of the abstract sym state of the CE + N dwell times. Moreover,
	//	 each starting vector is of dimension dim. Therefore, the total number of
	//	 variables of the optimization problem are dim*N + N

	unsigned int optD = N * dim + N;

	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based

	// 	Optimization routine paramters
	unsigned int maxeval = 20000;
	unsigned int maxtime = 60; //60 secs/ 1 minute
	myopt.set_min_objective(myobjfunc2, NULL);
	myopt.set_maxtime(maxtime); // times out after maxtime
	//myopt.set_maxeval(maxeval);
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
			ub[N * dim] = 9999;

		} else {

			T = *(trans_iter);
			assert(T!=NULL);

			location::ptr src_loc = HA->getLocation(T->getSourceLocationId());
			location::ptr dest_loc = HA->getLocation(
					T->getDestinationLocationId());

			polytope::ptr src_loc_inv = src_loc->getInvariant();
			polytope::ptr dest_loc_inv = dest_loc->getInvariant();

			P = dest_loc_inv;
			assert(P!=NULL);

			// set arbitrarily large but finite time bounds
			lb[N * dim + i] = 0;
			ub[N * dim + i] = 9999;
		}

		if (P->getIsUniverse()) {
			// set arbitrarily large but finite bounds on start points
			for (unsigned int j = 0; j < dim; j++) {
				unsigned int index = i * dim + j;
				lb[index] = -9999;
				ub[index] = 9999;
			}
		} else {
			lp_solver lp(GLPK_SOLVER);
			lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
					P->getInEqualitySign());

			//we add bound constraints on the position parameters
			std::vector<double> dir(dim, 0);
			double min, max;
			for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
			{
				dir[j] = -1;
				try {
					min = -1 * lp.Compute_LLP(dir);
				} catch (...) {
					// Assuming that the exception is due to unbounded solution in the min direction
					min = -9999; // setting an arbitrary lower bound
				}
				dir[j] = 1;

				try {
					max = lp.Compute_LLP(dir);
				} catch (...) {
					// Assuming that the exception is due to unbounded solution in the max direction
					max = 9999; // setting an arbitrary upper bound
				}
				unsigned int index = i * dim + j;
				lb[index] = min;
				ub[index] = max;
				x[index] = (lb[index] + ub[index]) / 2;
				dir[j] = 0;
			}
		}
		// Initialize the dwell-time values to 0
		//for (unsigned int i = 0; i < N; i++) {
		//	x[N * dim + i] = 0;
		//}
		// increment transition iterator
		if (trans_iter != transList.end() && i != 0) // do not increment trans iteration at the first iteration
			trans_iter++;
	}

	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);

	double minf;
	try {

		myopt.set_stopval(tolerance);
		unsigned int res = myopt.optimize(x, minf);
		if (res == NLOPT_SUCCESS)
			DEBUG_MSG("Splicing WoFC: NLOPT stopped successfully returning the found minimum");
		else if (res == NLOPT_STOPVAL_REACHED)
			DEBUG_MSG("Splicing WoFC: NLOPT stopped due to stopping value (1e-6) reached");
		else if (res == NLOPT_MAXEVAL_REACHED)
			DEBUG_MSG("Splicing WoFC: NLOPT stopped due to reaching maxeval = "+ to_string(maxeval));

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	DEBUG_MSG("nlopt returned min : " + to_string(minf));

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		DEBUG_MSG("Obtained minimum greater than " + to_string(tolerance) + ", with no. of refined search:" + to_string(refinements.size()));
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

concreteCE::ptr abstractCE::get_validated_CE(double tolerance, std::string& algo_type) {

	std::list<struct refinement_point> refinements;
	refinements.clear(); // No refinement point initially

	concreteCE::ptr cexample;
	bool val_res = true;
	unsigned int max_refinements = 3, ref_count = 0; // maximum limit to refinement points to be added.

	double valid_tol = 1e-5; // validation error tolerance, on invariant crossing.

	do {
		struct refinement_point pt;

		if (algo_type.compare("FC") == 0) // FC - Trajectory splicing with constraints over the search-space derived from flowpipe.
			cexample = gen_concreteCE(tolerance, refinements);
		else if (algo_type.compare("WoFC") == 0) { // WoFC - Trajectory splicing with HA implicit constraints over the search-space.
			cexample = gen_concreteCE_NLP_HA(tolerance, refinements);
		} else if (algo_type.compare("Altmin") == 0) { // LP-NLP Alt-Min \n";
			cexample = gen_concreteCE_iterative(tolerance, refinements);
		}
		else {
			DEBUG_MSG("Invalid algo type specified for trajectory splicing");
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
			algo_type="FC";
			//debug: print the invalid trajectory in a file, in the first two dimensions
			//cexample->plot_ce("./invalid_traj.txt", 0, 1);
		} else {
			//DEBUG_MSG("Generated Trace Validated with " + to_string(ref_count) + " point Refinements");
			std::cout << "#Refinements for trace validation: " + to_string(ref_count) << std::endl;
			cexample->set_refinement_count(ref_count);
			return cexample;
		}
		DEBUG_MSG("Restarting Search with added refinement point\n");
	} while (!val_res && ref_count <= max_refinements);

	throw std::runtime_error(
			"Validation of counter example FAILED after MAX Refinements\n");
	return concreteCE::ptr(new concreteCE());
}

concreteCE::ptr abstractCE::search_concreteCE(double tolerance,
		std::list<abstractCE::ptr> paths, std::vector<unsigned int> path_filter,
		std::string& algo_type) {

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
				DEBUG_MSG("Cannot splice trajectory segments with the accepted error tolerance");
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

