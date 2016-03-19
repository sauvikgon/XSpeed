/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include "counterExample/abstractCE.h"
#include "counterExample/simulation.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include <fstream>

unsigned int dim;
unsigned int N;
hybrid_automata::ptr HA;
std::vector<int> locIdList;
polytope::ptr bad_poly;

//constructor method
abstractCE::abstractCE(std::list<abstract_symbolic_state::ptr> s_states,
		std::list<transition::ptr> ts, hybrid_automata::ptr h, polytope::ptr fpoly) {
	//Assertion to check that the length of the counter-example is one minus
	// the number of sym states in the CE.
	assert(sym_states.size() == trans.size() - 1);
	sym_states = s_states;
	trans = ts;
	length = sym_states.size();
	H = h;
	forbid_poly = fpoly;
}

const abstract_symbolic_state::ptr abstractCE::get_first_symbolic_state() const
{
	std::list<abstract_symbolic_state::ptr>::const_iterator it = sym_states.begin();
	return *it;

}
const abstract_symbolic_state::ptr abstractCE::get_last_symbolic_state() const
{
	std::list<abstract_symbolic_state::ptr>::const_iterator it = sym_states.end();
	return *it;
}

void abstractCE::set_sym_states(std::list<abstract_symbolic_state::ptr> sym) {
	sym_states = sym;
	length = sym_states.size();
}

abstract_symbolic_state::ptr abstractCE::get_symbolic_state(
		unsigned int i) const {
	assert(0 <= i && i < get_length());
	unsigned int j = 0;
	std::list<abstract_symbolic_state::ptr>::const_iterator it =
			sym_states.begin();
	while (j < i){
		it++;
		j++;
	}
	return *it;
}

void abstractCE::plot(unsigned int i, unsigned int j) {
	/** Plotting the abstract counter example in a tracefile */
	std::ofstream tracefile;
	tracefile.open("./ceTrace.o");
	math::matrix<double> vertices_list;
	std::list<abstract_symbolic_state::ptr>::iterator it;
	for (it = sym_states.begin(); it != sym_states.end(); it++) {
		vertices_list = (*it)->getContinuousSet()->get_2dVertices(i, j);
		// ------------- Printing the vertices on the Output File -------------
		for (unsigned int p = 0; p < vertices_list.size1(); p++) {
			for (unsigned int q = 0; q < vertices_list.size2(); q++) {
				tracefile << vertices_list(p, q) << " ";
			}
			tracefile << std::endl;
		}
		tracefile << std::endl; // 1 gap after each polytope plotted
	}
	tracefile.close();
	/**end of tracefile generation */
}
int mycount = 0;
std::vector<double> simulate_trajectory(const std::vector<double>& x0,
		Dynamics& D, const double& time) {
	/**
	 * This function is to simulate trajectory from x0 for time units.
	 * todo: current dummy implementation to be completed
	 */

	simulation::ptr s = simulation::ptr(new simulation(x0.size(),0.1,D));
	std::vector<double> y;
	// debug purpose
//	std::string filename = "./test_sim.o";
//	s->set_outfile(filename);
//	s->set_out_dimension(0);
//	std::cout << "initial simulation point: " << x0[0] << ", " << x0[1] << ", " << x0[2] << std::endl;
/*	std::cout << "Dynamics A:\n";
	math::matrix<double> A = D.MatrixA;
	for(unsigned int i=0;i<D.MatrixA.size1(); i++){
		for(unsigned int j=0;j<D.MatrixA.size2(); j++)
			std::cout << " " << A(i,j);
		std::cout << "\n";
	}
	std::cout << "Dynamics C: ";
	for(unsigned int i=0;i<D.C.size(); i++)
		std::cout << " " << D.C[i] << std::endl;*/

//	std::cout << "sampled dwell time for simulation:" << time << std::endl;
//debug purpose ends

	y = s->simulate(x0, time);
	assert(y.size() == dim);
	return y;
}

double myobjfunc(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data) {

	 // 1. Get the N start vectors and dwell times from x and call the simulation routine
	 // 2. Get the N end points of the simulation trace, say, y[i].
	 // 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
	 //
	double sum = 0; // Stores the sum of all Euclidean distances of the end points.
//	std::vector<double> y(dim,0);

	// Computes the L2 norm or Euclidean distances between the trace end points.
	std::vector<std::vector<double> > y(N-1);
	std::vector<double> trace_end_pt(dim,0);
	double sq_sum = 0;
	for (unsigned int i = 0; i < N-1; i++) {
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}
		try{
			int loc_index = locIdList[i];
			y[i] = simulate_trajectory(v, HA->getLocation(loc_index)->getSystem_Dynamics(), x[N * dim + i]);
			// todo: assignment mapping to be done later.
			// todo: temporary implementation of assign map. To be generalized later
			std::list<transition::ptr>& trans = HA->getLocation(loc_index)->getOut_Going_Transitions();
			transition::ptr T = *(trans.begin());
			Assign R = T->getAssignT();
			assert(y[i].size() == R.Map.size2());
			std::vector<double> res(y[i].size());
			R.Map.mult_vector(y[i],res);
			// add vectors
			assert(y[i].size() == R.b.size());
			for(unsigned int j=0;j<res.size();j++)
				y[i][j] = res[j] + R.b[j];

		}catch(std::exception& e)
		{
			// Adds a high penalty to the objective function
		}
		std::vector<double> next_start(dim,0); // current jump start point
		for(unsigned int j=0;j<dim;j++)
			next_start[j] = x[(i+1)*dim + j];
		//compute the Euclidean distance between the next start point and the simulated end point
		for (unsigned int j = 0; j < dim; j++) {
			sq_sum += (y[i][j] - next_start[j]) * (y[i][j] - next_start[j]);
		}
	}
	sum = math::sqrt(sq_sum);

	// Add the distance of the last trace end point to the forbidden polytope

	std::vector<double> v(dim, 0);
	for (unsigned int j = 0; j < dim; j++) {
		v[j] = x[ (N-1) * dim + j];
	}

	int loc_index = locIdList[N-1];
	trace_end_pt = simulate_trajectory(v, HA->getLocation(loc_index)->getSystem_Dynamics(), x[N * dim + N-1]);
	// compute the distance of this endpoint with the forbidden polytope
	double d = bad_poly->point_distance(trace_end_pt);
	std::cout << "sim end point:" <<  trace_end_pt[0] << ", " << trace_end_pt[1] << ", " << trace_end_pt[2] <<std::endl;
	std::cout << "returned poly point distance:" << d << std::endl;
	sum+=d;
//	sum+= bad_poly->point_distance(trace_end_pt);


	if (!grad.empty()) {
		for(unsigned int i=0;i<dim;i++)
			grad[i] = 0;

		for(unsigned int i=1;i<N;i++){
			for(unsigned int j=0;j<N;j++){
				grad[i*dim+j] = (0.5/sum) * 2 * (x[i*dim+j] - y[i-1][j]);
			}
		}
	}
std::cout << "current sum = " << sum << std::endl;


//	mycount++;
//	if(mycount>=3)
//		exit(0);

	return sum;
}

/** Function to define a constraint over the optimization problem */

struct polyConstraints {
	math::vector<double> a;
	double b;
	unsigned int sstate_index;
};

struct boundConstriant{
	double bound;
	unsigned int var_index;
	bool is_ge; // to mark if bound is a >= constraint
};

double myconstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data) {
	polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
	unsigned int id = d->sstate_index;
//	std::cout << "value of the symbolic state index in myconstraint :" << i << std::endl;
//	unsigned int row_index = d->row_index;

	if (!grad.empty()) {
		for(unsigned int i=0;i<x.size();i++){
			grad[i] = 0 ;
		}
		for(unsigned int j=0;j<dim;j++)
			grad[id*dim+j] = d->a[j];
	}

	assert(d->a.size() == dim);

	double sum = 0;
	for (unsigned int j = 0; j < dim; j++) {
	//	std::cout << "x at " << i*dim+j << " = " << x[i * dim + j] << std::endl;
		//std::cout << "a at  " << j << " = " << d->a[j] << std::endl;
		sum += x[id * dim + j] * d->a[j];
	}
//	std::cout << "bound " << " = " << d->b << std::endl;
	sum -= d->b;
	return sum;
}
/** Adds bound constraint on a variable, i.e. x<=b => x-b<=0*/
double myBoundConstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data){

	boundConstriant *d = reinterpret_cast<boundConstriant *>(data);
	if (!grad.empty()) {
		for(unsigned int i=0;i<x.size();i++){
			grad[i] = 0 ;
		}
	}

	if(d->is_ge){
//		std::cout << "lower bound constraint on time with bound = " << d->bound << std::endl;
		if(!grad.empty())
			grad[d->var_index] = -1;
		return (-1 * x[d->var_index] + d->bound);
	}
	else{
//		std::cout << "upper bound constraint on time with bound = " << d->bound << std::endl;
		if(!grad.empty())
			grad[d->var_index] = 1;
		return (x[d->var_index] - d->bound);

	}
}

/**
 * Routine to compute concrete trajectory from given
 * abstract counter example using non-linear optimization
 * routine.
 *
 * @Rajarshi
 * 28th January 2016
 */

concreteCE::ptr abstractCE::gen_concreteCE(double tolerance) {

//	 Generate an nlopt object with the constraints defined by the Abstract
//	 counter example


//	 1. Get the dimensionality of the optimization problem by
//	 getting the dimension of the continuous set of the abstract counter example

	abstract_symbolic_state::ptr S = get_first_symbolic_state();
	dim = S->getContinuousSet()->getSystemDimension();
	N = get_length(); // the length of the counter example
	HA = this->get_automaton();
	bad_poly = this->forbid_poly;
	std::cout << "gen_concreteCE: dimension =" << dim <<", length of CE=" << N << std::endl;
	// initialize the global locIdList
	locIdList.resize(N);

	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		locIdList[i] = *(d.begin());
	}



//	 2. The dimensionality of the opt problem is N vectors, one starting point
//	 for each of the abstract sym state of the CE + N dwell times. Moreover,
//	 each starting vector is of dimension dim. Therefore, the total number of
//	 variables of the optimization problem are dim*N + N

	unsigned int optD = N * dim + N;
	std::cout << "nlopt problem dimension = " << optD << std::endl;
	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free
//	nlopt::opt myopt(nlopt::LN_AUGLAG_EQ, optD); // derivative free
//	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based

//	std::vector<double> lb(2);
//	lb[0] = 0.1;
//	lb[1] = 2;

//	std::vector<double> lb(optD);
//	std::vector<double> ub(optD);
//	for(unsigned int i=0;i<N*dim;i++){
//		lb[i] = -500;
//		ub[i] = 500;
//	}
//	for(unsigned int i=N*dim;i<optD;i++){
//		lb[i] = 0;
//		ub[i] = 500;
//	}

//	myopt.set_lower_bounds(lb);
//	myopt.set_upper_bounds(ub);
	myopt.set_stopval(0.001);
//	myopt.set_xtol_rel(1e-4);

	myopt.set_min_objective(myobjfunc, NULL);
	//myopt.set_initial_step(0.001);

	//Set Initial value to the optimization problem
	std::vector<double> x(optD);
	unsigned int i, j;
	polytope::ptr P;
	// A random objective function created for lp solving

	std::vector<double> obj(dim, 0);
	obj[0] = 1;
	std::vector<double> v(dim);

	for (i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		S = get_symbolic_state(i);
		P = S->getInitialSet();
//		To get a point from the polytope, we create a random obj function and
//		solve the lp. The solution point is taken as an initial value.

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		lp.Compute_LLP(obj);
		v = lp.get_sv();

		for (j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			x[i * dim + j] = v[j];
		}
	}
	std::cout << "generated initial points\n";
//	Set initial value to the time variables
//	Restrict dwell time within the projections of C_i in time variable



//	We assume that the time variable is names as 't' in the model.
//	We find out the min,max components of the time variable

	unsigned int t_index =
		get_first_symbolic_state()->getContinuousSet()->get_index("t");
	std::cout << "Index of time variable:" << t_index << std::endl;
	assert((t_index >= 0) && (t_index < dim));

	std::vector<double> dmin(dim, 0), dmax(dim, 0);
	dmax[t_index] = 1;
	dmin[t_index] = -1;

	boundConstriant B[N],B1[N];

	double max,min;
	for (i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		P = S->getContinuousSet();
//		To get a point from the polytope, we create a random obj function and
//		solve the lp. The solution point is taken as an initial value.

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		max = lp.Compute_LLP(dmax);
		min = -1 * lp.Compute_LLP(dmin);
		// we add the bounds as constraints in the nlopt

		B[i].var_index = N*dim + i;
		B[i].bound = max - min;
		B[i].is_ge = false;
		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
		B1[i].var_index = B[i].var_index;
		B1[i].is_ge=true;
		B1[i].bound = 0;
		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
		// We may choose to take the max-min as the initial dwell time
		x[N * dim + i] = (max + min)/2;
	}
std::cout << "Computed initial dwell times and added constraints over them\n";

//	 todo: Constraints of the optimization problem is to be added
//	 nlopt expects the constraints of the form constraint(x) <=0


//	Constraints over C_i added to the optimization problem

	polytope::ptr C;
	math::matrix<double> A;
	math::vector<double> b;

	polyConstraints I[2*dim*N];
	unsigned int index = 0;
	for (unsigned int i = 0; i < N; i++) {
		C = get_symbolic_state(i)->getInitialSet();
		C->print2file("./initPoly",2,1);
		A = C->getCoeffMatrix();
		b = C->getColumnVector();

// 		We assume that the polytope is expressed as Ax<=b

		assert(C->getInEqualitySign() == 1);
		assert(A.size2() == dim);
		assert(b.size() == A.size1());
		assert(2*dim*N > index);

		for (unsigned int j = 0; j < A.size1(); j++) {
			I[index].sstate_index = i;
			I[index].a.resize(A.size2());

			for(unsigned int k=0;k<dim;k++){
				I[index].a[k] = A(j,k);
			}
			I[index].b = b[j];
			myopt.add_inequality_constraint(myconstraint, &I[index], 1e-8);
			index++;
		}

	}
	std::cout << "added constraints to the nlopt solver\n";
// 		todo: Constraints over dwell time to be added

//	Create object of concreteCE from the result of nlopt

	double minf;
	try {
		//debug print
		std::cout << "Printing x before calling nlopt optimize\n" << std::endl;
		for(unsigned int i=0;i<optD;i++)
			std::cout << x[i] << " ";
		 std::cout << std::endl;
		 nlopt::result result = myopt.optimize(x, minf);

		if (result < 0)
			throw "abstractCE: gen_concreteCE: NLOpt failed\n";

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
std::cout << "nlopt returned min : " << minf << "\n";
//	if (math::abs(minf) > tolerance) {
//		concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
//		return cexample;
//	} else {
		// create a concrete counter example object
		concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
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
			s.second = time;
			concreteCE::traj_segment traj;
			traj.first = locId;
			traj.second = s;
			cexample->push_back(traj);
		}
		return cexample;
//	}
}

// This constraint function s for debugging only
double myDbgBoundConstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data){

	boundConstriant *d = reinterpret_cast<boundConstriant *>(data);
	if (!grad.empty()) {
		// todo: gradient to be added later
		for(unsigned int i=0;i<x.size();i++){
			grad[i] = 0 ;
		}
	}

	if(d->is_ge){
//		std::cout << "lower bound constraint on time with bound = " << d->bound << std::endl;
		if(!grad.empty())
			grad[0] = -1;
		return (-1*x[0] + d->bound);
	}
	else{
//		std::cout << "upper bound constraint on time with bound = " << d->bound << std::endl;
		if(!grad.empty())
			grad[d->var_index] = 1;
		return (x[0] - d->bound);
	}
}
/*
// This function is for debugging
double myDbgobjfunc(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data) {
	double sum = 0; // Stores the sum of all Euclidean distances of the end points.
	std::vector<double> trace_end_pt(dim,0);
	std::vector<double> v(dim, 0);
	v[0] = x[0];
	v[1] = x[1];
	v[2] = 0.0;


	int loc_index = locIdList[0];
	trace_end_pt = simulate_trajectory(v, HA->getLocation(loc_index).getSystem_Dynamics(), x[3]);
	//compute the Euclidean distance between the next start point and the simulated end point
	std::vector<double> exp_endpt(dim,0);
	exp_endpt[0] = 0;
	exp_endpt[1] = -4.54;
	exp_endpt[2] = 4.54;

	double comp_sum;
	for (unsigned int j = 0; j < dim; j++) {
			comp_sum = 0;
//			std::cout << "trace end point of component " << j << " = " << trace_end_pt[j] << std::endl;
			comp_sum = (trace_end_pt[j] - exp_endpt[j]) * (trace_end_pt[j] - exp_endpt[j]);
//			std::cout << "Squared sum of component " << j << " = " << comp_sum << std::endl;
			sum += comp_sum;
	}
	sum = math::sqrt(sum);

	std::cout << "current sum = " << sum << std::endl;

	return sum;
}
// this gen concrete ce is for debug purpose only
concreteCE::ptr abstractCE::gen_concreteCE(double tolerance) {

//	 Generate an nlopt object with the constraints defined by the Abstract
//	 counter example


//	 1. Get the dimensionality of the optimization problem by
//	 getting the dimension of the continuous set of the abstract counter example

	abstract_symbolic_state::ptr S = get_first_symbolic_state();
	dim = S->getContinuousSet()->getSystemDimension();
	N = sym_states.size(); // the length of the counter example
	HA = this->get_automaton();
	bad_poly = this->forbid_poly;
//	std::cout << "gen_concreteCE: dimension =" << dim <<", length of CE=" << N << std::endl;
	// initialize the global locIdList
	locIdList.resize(N);

	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		locIdList[i] = *(d.begin());
	}
	unsigned int optD = N*dim+N;
	std::vector<double> x(optD);


//	 2. The dimensionality of the opt problem is N vectors, one starting point
//	 for each of the abstract sym state of the CE + N dwell times. Moreover,
//	 each starting vector is of dimension dim. Therefore, the total number of
//	 variables of the optimization problem are dim*N + N

	std::cout << "nlopt problem dimension = " << optD << std::endl;
	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free

	myopt.set_min_objective(myDbgobjfunc, NULL);

	//Set Initial value to the optimization problem
	unsigned int i, j;
	polytope::ptr P;
	// A random objective function created for lp solving

	std::vector<double> obj(dim, 0);
	obj[0] = 1;
	std::vector<double> v(dim);

	for (i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		S = get_symbolic_state(i);
		P = S->getInitialSet();
//		To get a point from the polytope, we create a random obj function and
//		solve the lp. The solution point is taken as an initial value.

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		lp.Compute_LLP(obj);
		v = lp.get_sv();

		for (j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			x[i * dim + j] = v[j];
		}
	}
	x[2] = 0; // set the initial time point to 0.

	std::cout << "generated initial points\n";


//	We assume that the time variable is names as 't' in the model.
//	We find out the min,max components of the time variable

	unsigned int t_index =
		get_first_symbolic_state()->getContinuousSet()->get_index("t");
	std::cout << "Index of time variable:" << t_index << std::endl;
	assert((t_index >= 0) && (t_index < dim));

	std::vector<double> dmin(dim, 0), dmax(dim, 0);
	dmax[t_index] = 1;
	dmin[t_index] = -1;

	boundConstriant B[N],B1[N];

	double max,min;
	for (i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		P = S->getContinuousSet();
//		To get a point from the polytope, we create a random obj function and
//		solve the lp. The solution point is taken as an initial value.

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		max = lp.Compute_LLP(dmax);
		min = -1 * lp.Compute_LLP(dmin);
		// we add the bounds as constraints in the nlopt

		B[i].var_index = N*dim + i;
		B[i].bound = max - min;
		B[i].is_ge = false;
		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
		B1[i].var_index = B[i].var_index;
		B1[i].is_ge=true;
		B1[i].bound = 0;
		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
		// We may choose to take the max-min as the initial dwell time
		x[N*dim + i] = (max + min)/2;
	}
	std::cout << "Max dwell time = " << max << ", Min dwell time=" << min << ", initial dwell time=" << x[3] << std::endl;

//	Constraints over C_i added to the optimization problem

	polytope::ptr C;
	math::matrix<double> A;
	math::vector<double> b;

	polyConstraints I[2*dim*N];
	unsigned int index = 0;
	for (unsigned int i = 0; i < N; i++) {
		C = get_symbolic_state(i)->getInitialSet();
		C->print2file("./InitPoly",2,0);
		A = C->getCoeffMatrix();
		b = C->getColumnVector();

// 		We assume that the polytope is expressed as Ax<=b

		assert(C->getInEqualitySign() == 1);
		assert(A.size2() == dim);
		assert(b.size() == A.size1());

		for (unsigned int j = 0; j < A.size1(); j++) {
			assert(index < 2*dim*N);
			I[index].sstate_index = i;
			I[index].a.resize(A.size2());

	//		std::cout << "cons vector of initpoly:\n";
			for(unsigned int k=0;k<dim;k++){
				I[index].a[k] = A(j,k);
	//			std::cout << " "<< I[index].a[k] << std::endl;
			}
			I[index].b = b[j];
	//		std::cout << "\ncons bound of initpoly:\n";
	//		std::cout << " " << I[index].b << std::endl;
			myopt.add_inequality_constraint(myconstraint, &I[index], 1e-8);
			index++;
		}
	}
	std::cout << "added constraints to the nlopt solver\n";

	double minf;
	try {
		//debug print
		std::cout << "Printing x before calling nlopt optimize\n" << std::endl;
		for(unsigned int i=0;i<optD;i++)
			std::cout << x[i] << " ";
		 std::cout << std::endl;
		 nlopt::result result = myopt.optimize(x, minf);

		if (result < 0)
			throw "abstractCE: gen_concreteCE: NLOpt failed\n";

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
std::cout << "nlopt returned min : " << minf << "\n";
//	if (math::abs(minf) > tolerance) {
//		concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
//		return cexample;
//	} else {
		// create a concrete counter example object
		concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
		// one trajectory per symbolic state to be added in the concreteCE
		for (unsigned int i = 0; i < N; i++) {
			// create the sample
			concreteCE::sample s;
			std::set<int>::iterator dset_iter =
					get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
			unsigned int locId = *dset_iter;

			std::vector<double> y(dim);
			y[0]=x[0];
			y[1]=x[1];
			y[2] =x[2];
			double time = x[3];
			s.first = y;
			s.second = time;
			concreteCE::traj_segment traj;
			traj.first = locId;
			traj.second = s;
			cexample->push_back(traj);
		}
		return cexample;
}
*/
