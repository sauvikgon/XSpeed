/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include "counterExample/abstractCE.h"
#include "counterExample/simulation.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "gsl/gsl_deriv.h"
#include <fstream>
#include <string>

unsigned int dim;
unsigned int N;
hybrid_automata::ptr HA;
std::vector<int> locIdList;
std::list<transition::ptr> transList;
polytope::ptr bad_poly;
std::list<violating_CE> refinements;


unsigned int samples = 0;
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

abstract_symbolic_state::ptr abstractCE::get_symbolic_state(unsigned int i) const {
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

/*
 * Computes the distance of the trajectory to the invariant and
 * returns the end point of the simulation.
 */
std::vector<double> simulate_trajectory(const std::vector<double>& x0,
		Dynamics& D, const double& time, double& distance, polytope::ptr Inv) {
	/**
	 * This function is to simulate trajectory from x0 for time units.
	 * todo: current dummy implementation to be completed
	 */

	simulation::ptr s = simulation::ptr(new simulation(x0.size(),100,D));
	std::vector<double> y;
//	If trace validation is enabled.
//	y = s->bounded_simulation(x0, time, Inv); // validated trace generation
	distance = 0;
	y = s->metric_simulate(x0,time,distance,Inv);
// 	if trace validation is not enabled, call the following simulate function
//	y = s->simulate(x0, time); // no trace validation
	assert(y.size() == dim);
	return y;
}

/*
 * Computes the cost of the objective function on the sample x
 */

double compute_cost(double arg, void * params){

	std::vector<std::vector<double> > y(N-1);
	for(unsigned int j=0;j<N-1;j++)
		y[j] = std::vector<double>(dim,0);

	double cost = 0;
	//typecast from void* to double *
	double *x = (double *) (params);
	unsigned int arg_index = (unsigned int)(x[N*dim+N]);
	x[arg_index] = arg;

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	double trace_distance;
	for (unsigned int i = 0; i < N-1; i++) {
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}

		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
		assert(d.C.size() == dim);

		trace_distance = 0;
		y[i] = simulate_trajectory(v, d, x[N * dim + i], trace_distance, I);
		/** Add the distance of the end point to the invariant. This is for validation testing */
//		cost+=I->point_distance(y[i]);
		if(trace_distance!=0){
			//std::cout << "trace distance = " << trace_distance << std::endl;
			cost+=trace_distance;
		}

		transition::ptr Tptr= *(T_iter);
		// assignment of the form: Ax + b
		Assign R = Tptr->getAssignT();
		//guard as a polytope
		polytope::ptr g = Tptr->getGaurd();
		// If traj end point inside guard, then apply map.
		if(g->point_is_inside(y[i]))
		{
			assert(y[i].size() == R.Map.size2());
			std::vector<double> res(y[i].size(),0);
			R.Map.mult_vector(y[i],res);
			// add vectors
			assert(y[i].size() == R.b.size());
			for(unsigned int j=0;j<res.size();j++)
				y[i][j] = res[j] + R.b[j];
		}
		if(T_iter!=transList.end())
			T_iter.operator ++();

		std::vector<double> next_start(dim,0); // current jump start point
		for(unsigned int j=0;j<dim;j++)
			next_start[j] = x[(i+1)*dim + j];
		//compute the Euclidean distance between the next start point and the simulated end point
		double pt_distance = 0;
		for (unsigned int j = 0; j < dim; j++) {
			pt_distance += (y[i][j] - next_start[j]) * (y[i][j] - next_start[j]);
		}
		cost += pt_distance;
	}
	std::vector<double> v(dim, 0);
	for (unsigned int j = 0; j < dim; j++) {
		v[j] = x[ (N-1) * dim + j];
	}
	std::vector<double> trace_end_pt(dim,0);
	int loc_index = locIdList[N-1];
	Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
	polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
	trace_distance = 0;
	trace_end_pt = simulate_trajectory(v, d, x[N * dim + N-1], trace_distance, I);
	// compute the distance of this endpoint with the forbidden polytope
	cost+=trace_distance; // the last traj segment should also satisfy the location invariant
	cost+= bad_poly->point_distance(trace_end_pt);

	return cost;

}
/** obj function for automatic differentiation 
double myobjfunc(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data) {

	// 1. Get the N start vectors and dwell times from x and call the simulation routine
	// 2. Get the N end points of the simulation trace, say, y[i].
	// 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
	// Computes the L2 norm or Euclidean distances between the trace end points.

	//-----------------------------------------

	std::vector<std::vector<double> > y(N-1);
	for(unsigned int j=0;j<N-1;j++)
		y[j] = std::vector<double>(dim,0);

	stan::math::var params[x.size()];
	for(unsigned int i=0;i<x.size();i++)
		params[i] = stan::math::var(x[i]);
	
	stan::math::var cost = 0;

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	double trace_distance;
	for (unsigned int i = 0; i < N-1; i++) {
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = params[i * dim + j].val();
		}

		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
		assert(d.C.size() == dim);

		trace_distance = 0;
		y[i] = simulate_trajectory(v, d, params[N * dim + i].val(), trace_distance, I);
		
		// Add the distance of the end point to the invariant. This is for validation testing 
//		sq_sum+=I->point_distance(y[i]);
//		if(trace_distance!=0){
			//std::cout << "trace distance = " << trace_distance << std::endl;
//			cost+=trace_distance;
//		}

		transition::ptr Tptr= *(T_iter);
		// assignment of the form: Ax + b
		Assign R = Tptr->getAssignT();
		//guard as a polytope
		polytope::ptr g = Tptr->getGaurd();
		// If traj end point inside guard, then apply map.
		if(g->point_is_inside(y[i]))
		{
			assert(y[i].size() == R.Map.size2());
			std::vector<double> res(y[i].size(),0);
			R.Map.mult_vector(y[i],res);
			// add vectors
			assert(y[i].size() == R.b.size());
			for(unsigned int j=0;j<res.size();j++)
				y[i][j] = res[j] + R.b[j];
		}
		if(T_iter!=transList.end())
			T_iter.operator ++();

		std::vector<stan::math::var> next_start(dim); // current jump start point
		for(unsigned int j=0;j<dim;j++)
			next_start[j] = params[(i+1)*dim + j];
		//compute the Euclidean distance between the next start point and the simulated end point
		for (unsigned int j = 0; j < dim; j++) {
			cost += (y[i][j] - next_start[j]) * (y[i][j] - next_start[j]);
		}

	}
	std::vector<double> v(dim, 0);
	for (unsigned int j = 0; j < dim; j++) {
		v[j] = params[ (N-1) * dim + j].val();
	}
	std::vector<double> trace_end_pt(dim,0);
	int loc_index = locIdList[N-1];
	Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
	polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
	//trace_distance = 0;
	trace_end_pt = simulate_trajectory(v, d, params[N * dim + N-1].val(), trace_distance, I);
	
//	sq_sum+= I->point_distance(trace_end_pt);
	// compute the distance of this endpoint with the forbidden polytope
//	cost+=trace_distance; // the last traj segment should also satisfy the location invariant
//	cost+= bad_poly->point_distance(trace_end_pt);

	//-------------------------------


// Use the following gradient in case of constant dynamics (x'=k)

//	if (!grad.empty()) {
//		for(unsigned int i=0;i<dim;i++)
//			grad[i] = 0;
//
//		for(unsigned int i=0;i<N;i++){
//			for(unsigned int j=0;j<dim;j++){
//				if(i==0){
//					grad[i*dim+j] = 2 * (y[i][j] - x[(i+1)*dim+j]);
//				}
//				else if(i>0 && i<N-1){
//					Dynamics d = HA->getLocation(locIdList[i])->getSystem_Dynamics();
//					Dynamics d1 = HA->getLocation(locIdList[i-1])->getSystem_Dynamics();
//					grad[i*dim+j] = 4*x[i*dim+j] - 2*x[(i-1)*dim+j] -2*d1.C[j]*x[N*dim+i-1] +2*d.C[j]*x[N*dim+i] -2*x[(i+1)*dim+j];
//				}
//				else{
//					Dynamics d = HA->getLocation(locIdList[i-1])->getSystem_Dynamics();
//					grad[i*dim+j] = 2*x[i*dim+j] - 2*y[i-1][j];
//				}
//			}
//			if(i!=N-1){
//				Dynamics d = HA->getLocation(locIdList[i])->getSystem_Dynamics();
//				double k1=0,k2=0,k3=0;
//				for(unsigned int j=0;j<N;j++){
//					k1 += d.C[j]* d.C[j];
//					k2 += x[i*dim+j] * d.C[j];
//					k3 += x[(i+1)*dim+j] * d.C[j];
//				}
//				grad[N*dim + i] = 2*x[N*dim+i]*k1 + 2*k2 - 2*k3;
//			}
//			else{
//				grad[N*dim+i] = 0;
//			}
//		}
//	}

//	double cost = compute_cost(x);

	// This is an alternate version of computing gradient numerically using symmetric difference method
//	if (!grad.empty()) {
		std::vector<double> xh(x.size(),0);
		xh = x;
		long double h = 1e-6;
		long double cost_h_r, cost_h_l;
		for(unsigned int i=0;i<x.size();i++){
			xh[i] = x[i] + h;
			cost_h_r = compute_cost(xh);
			xh[i] = x[i] - h;
			cost_h_l = compute_cost(xh);
			grad[i] = (cost_h_r - cost_h_l)/(2*h);
//			std::cout << "Computed Gradient x of wrt "<< i << " = " << grad[i] << std::endl;
			xh[i] = x[i];
		}
//	}
	// automatic differentiation 
	
//	std::vector<stan::math::var> theta;
//	for(unsigned int i=0;i<x.size();i++)
//	    theta.push_back(params[i]);

//	std::vector<double> g;
//	cost.grad(theta,g);
	
//	if (!grad.empty()) {
//	  for(unsigned int i=0;i<x.size();i++){
//	      grad[i] = g[i];
	      
//	      std::cout << "gradient of param " << i << "= " << grad[i] << std::endl;
	      
//	  }
//	  exit(0); // debug statement
//	}
	std::cout << "current cost = " << cost.val() << std::endl;
//	samples++;
	return cost.val();
}
*/ //end of objective function with auto differentiation

/* objective function without auto differentiation */
double myobjfunc(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data) {

	// 1. Get the N start vectors and dwell times from x and call the simulation routine
	// 2. Get the N end points of the simulation trace, say, y[i].
	// 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
	// Computes the L2 norm or Euclidean distances between the trace end points.

	//-----------------------------------------

	std::vector<std::vector<double> > y(N-1);
	for(unsigned int j=0;j<N-1;j++)
		y[j] = std::vector<double>(dim,0);

	double cost = 0;
	std::list<transition::ptr>::iterator T_iter = transList.begin();
	double trace_distance;
	for (unsigned int i = 0; i < N-1; i++) {
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}

		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
		assert(d.C.size() == dim);

		trace_distance = 0;
		y[i] = simulate_trajectory(v, d, x[N * dim + i], trace_distance, I);
		
		/** Add the distance of the end point to the invariant. This is for validation testing */
//		cost+=I->point_distance(y[i]);
		if(trace_distance!=0){
			//std::cout << "trace distance = " << trace_distance << std::endl;
			cost+=trace_distance;
		}

		transition::ptr Tptr= *(T_iter);
		// assignment of the form: Ax + b
		Assign R = Tptr->getAssignT();
		//guard as a polytope
		polytope::ptr g = Tptr->getGaurd();
		// If traj end point inside guard, then apply map.
		if(g->point_is_inside(y[i]))
		{
			assert(y[i].size() == R.Map.size2());
			std::vector<double> res(y[i].size(),0);
			R.Map.mult_vector(y[i],res);
			// add vectors
			assert(y[i].size() == R.b.size());
			for(unsigned int j=0;j<res.size();j++)
				y[i][j] = res[j] + R.b[j];
		}
		if(T_iter!=transList.end())
			T_iter.operator ++();

		std::vector<double> next_start(dim); // current jump start point
		for(unsigned int j=0;j<dim;j++)
			next_start[j] = x[(i+1)*dim + j];
		//compute the Euclidean distance between the next start point and the simulated end point
		for (unsigned int j = 0; j < dim; j++) {
			cost += (y[i][j] - next_start[j]) * (y[i][j] - next_start[j]);
		}

	}
	std::vector<double> v(dim, 0);
	for (unsigned int j = 0; j < dim; j++) {
		v[j] = x[ (N-1) * dim + j];
	}
	std::vector<double> trace_end_pt(dim,0);
	int loc_index = locIdList[N-1];
	Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
	polytope::ptr I = HA->getLocation(loc_index)->getInvariant();
	trace_distance = 0;
	trace_end_pt = simulate_trajectory(v, d, x[N * dim + N-1], trace_distance, I);
	
	// compute the distance of this endpoint with the forbidden polytope
	cost+=trace_distance; // the last traj segment should also satisfy the location invariant
	cost+= bad_poly->point_distance(trace_end_pt);

	//-------gsl derivative
	if(!grad.empty()){
		gsl_function F;
		F.function = &compute_cost;
		double x_params[x.size()+1];
		for(unsigned int i=0;i<x.size();i++)
			x_params[i] = x[i];

		double abserr;
		for(unsigned int i=0;i<x.size();i++){
			x_params[x.size()] = i;
			F.params = &x_params;
			gsl_deriv_central(&F,x[i],1e-10,&grad[i],&abserr);
		}
	}
	//------

	// This is an alternate version of computing gradient numerically using symmetric difference method
//	if (!grad.empty()) {
//		std::vector<double> xh(x.size(),0);
//		xh = x;
//		long double h = 1e-6;
//		long double cost_h_r, cost_h_l;
//		for(unsigned int i=0;i<x.size();i++){
//			xh[i] = x[i] + h;
//			cost_h_r = compute_cost(xh);
//			xh[i] = x[i] - h;
//			cost_h_l = compute_cost(xh);
//			grad[i] = (cost_h_r - cost_h_l)/(2*h);
////			std::cout << "Computed Gradient x of wrt "<< i << " = " << grad[i] << std::endl;
//			xh[i] = x[i];
//		}
//	}
	std::cout << "current cost=" << cost << std::endl;
	return cost;
}

//double grad_descent(std::vector<double>& x)
//{
//	int it = 0;
//	double grad[x.size()], delta = 1e-6;
//	std::vector<double> x_prime(x), x_new(x.size(),0);
//	double h = 1e-8, min;
//	double iters = 200;
//
//	min = compute_cost(x);
//	std::cout << "cost before beginning descent: " << min << std::endl;
//	while(min> 0.01)
//	{
//		double f = compute_cost(x);
//		for(unsigned int i=0;i<x.size();i++)
//		{
//			x_prime[i] = x[i] + h;
//			double fh = compute_cost(x_prime);
////			std::cout << "fh=" << fh << std::endl;
////			std::cout << "f=" << f << std::endl;
//			grad[i] = (fh - f)/h;
////			std::cout << "grad[i]=" << fh << std::endl;
//			x_prime = x;
//			x_new[i] = x[i] - delta * grad[i];
//		}
//		min = compute_cost(x_new);
//		std::cout << "updated function value: " << min << std::endl;
//		it++;
//		x = x_new;
//		x_prime=x;
//	}
//	return min;
//}

/** Function to define a constraint over the optimization problem */

struct polyConstraints {
	math::vector<double> a;
	double b;
	unsigned int sstate_index;
};

struct boundConstriant {
	double bound;
	unsigned int var_index;
	bool is_ge; // to mark if bound is a >= constraint
};

double myconstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data) {
	polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
	unsigned int id = d->sstate_index;

//	unsigned int row_index = d->row_index;

	assert(id>=0 && id<N);
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

	assert(d->var_index>=N*dim && d->var_index<N*dim+N);

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


//	 1. Get the dimension of the optimization problem by
//	 getting the dimension of the continuous set of the abstract counter example


	abstract_symbolic_state::ptr S = get_first_symbolic_state();
	dim = S->getContinuousSet()->getSystemDimension();
	N = get_length(); // the length of the counter example
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	bad_poly = this->forbid_poly;
	std::cout << "gen_concreteCE: dimension =" << dim <<", length of CE=" << N << std::endl;
	// initialize the global locIdList
	locIdList.resize(N);
      
	
	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		locIdList[i] = *(d.begin());
//		std::cout << "printing loc ids:" << locIdList[i] << " " << std::endl;
	}


//	 2. The dimensionality of the opt problem is N vectors, one starting point
//	 for each of the abstract sym state of the CE + N dwell times. Moreover,
//	 each starting vector is of dimension dim. Therefore, the total number of
//	 variables of the optimization problem are dim*N + N

	unsigned int optD = N * dim + N;
	std::cout << "nlopt problem dimension = " << optD << std::endl;
//	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free
//	nlopt::opt myopt(nlopt::LN_AUGLAG_EQ, optD); // derivative free
//	nlopt::opt myopt(nlopt::LN_AUGLAG, optD); // derivative free
//	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based
	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative bases
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

//	myopt.set_maxeval(500);
	myopt.set_stopval(0.00001);

//	myopt.set_xtol_rel(1e-4);

	myopt.set_min_objective(myobjfunc, NULL);
	//myopt.set_initial_step(0.001);

	//Set Initial value to the optimization problem
	std::vector<double> x(optD, 0);
	polytope::ptr P;

	// Check satisfiability
//	std::list<transition::ptr>::iterator it = transList.begin();
//	polytope::ptr g;
//	for(unsigned int i=0;i<N-1;i++){
//
//		P = get_symbolic_state(i+1)->getInitialSet();
//		g = (*it)->getGaurd();
//		g = g->GetPolytope_Intersection(get_symbolic_state(i)->getContinuousSet());
//		g = g->GetPolytope_Intersection(P);
//		if(g->getIsEmpty()){
//			std::cout << "Not Satisfiable\n";
//			exit(0);
//		}
//		it++;
//	}
	//end of sat scheck
	// A random objective function created for lp solving

	std::vector<double> obj(dim, 0);
	obj[0] = 1;
	std::vector<double> v(dim);

	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
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

		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			x[i * dim + j] = v[j];
		}
	}
	std::cout << "generated initial points\n";
//	Set initial value to the time variables
//	Restrict dwell time within the projections of C_i in time variable



//	We assume that the time variable is named as 't' in the model.
//	We find out the min,max components of the time variable

	unsigned int t_index =
		get_first_symbolic_state()->getContinuousSet()->get_index("t");
	std::cout << "Index of time variable:" << t_index << std::endl;
	assert((t_index >= 0) && (t_index < dim));

	std::vector<double> dmin(dim, 0), dmax(dim, 0);
	dmax[t_index] = 1;
	dmin[t_index] = -1;

	boundConstriant B[N],B1[N];

	std::list<transition::ptr>::iterator it = transList.begin();
	transition::ptr T;
	double max,min,start_min;
	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		P = S->getContinuousSet();
		if(i==N-1){
			// If last abst sym state, then take time projection of flowpipe \cap bad_poly
			P=P->GetPolytope_Intersection(bad_poly);
			std::ofstream myfile;
			myfile.open("./polyBad");
			P->print2file("./polyBad",0,1);
		}
		else{
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			P=P->GetPolytope_Intersection(T->getGaurd());
		}
//		To get a point from the polytope, we create a random obj function and
//		solve the lp. The solution point is taken as an initial value.

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		max = lp.Compute_LLP(dmax);
		min = -1 * lp.Compute_LLP(dmin);
		// we add the bounds as constraints in the nlopt
		
		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		P=S->getInitialSet();
		lp1.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		
		start_min = -1 * lp1.Compute_LLP(dmin);
		
		B[i].var_index = N*dim + i;
		B[i].bound = max - start_min;
		B[i].is_ge = false;
		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
		B1[i].var_index = B[i].var_index;
		B1[i].is_ge=true;
		B1[i].bound = min-start_min;
		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
		// We may choose to take the max-min as the initial dwell time
		x[N * dim + i] = (max -start_min + min - start_min)/2;
		if(it!=transList.end())
			it++;
		
	}
	std::cout << "Computed initial dwell times and added constraints over them\n";

//	 todo: Constraints of the optimization problem is to be added
//	 nlopt expects the constraints of the form constraint(x) <=0


//	Constraints over C_i added to the optimization problem

	polytope::ptr C;
	math::matrix<double> A;
	math::vector<double> b;


	unsigned int size=0;
	for(unsigned int i=0;i<N;i++){
		size += get_symbolic_state(i)->getInitialSet()->getCoeffMatrix().size1();
	}
	polyConstraints I[size];
	unsigned int index = 0;
	for (unsigned int i = 0; i < N; i++) {
		C = get_symbolic_state(i)->getInitialSet();
//		//debug
//		std::ofstream myfile;
//		string fname = "initpoly";
//		myfile.open(fname.c_str());
//		C->print2file(fname, 0, 1);
//		system("graph -TX -BC initpoly");
//		myfile.close();
		//---
		A = C->getCoeffMatrix();
		b = C->getColumnVector();

// 		We assume that the polytope is expressed as Ax<=b

		assert(C->getInEqualitySign() == 1);
		assert(A.size2() == dim);
		assert(b.size() == A.size1());
		assert(size > index);

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
	assert(index==size);
	std::cout << "added constraints on starting point of each slice to the nlopt solver\n";
// 	todo: Constraints over dwell time to be added
	
//	Create object of concreteCE from the result of nlopt

	double minf;
	try {

		nlopt::result result = myopt.optimize(x, minf);
		if (result < 0)
			throw "abstractCE: gen_concreteCE: NLOpt failed\n";

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "nlopt returned min : " << minf << "\n";
	std::cout << "Number of samples by NLopt: " << samples << "\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum less than " << tolerance << std::endl;
		return cexample;
	} else {

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

concreteCE::ptr abstractCE::get_validated_CE(double tolerance)
{
	refinements = std::list<violating_CE>();
	// call to genCE func with no refining trajectory
	concreteCE::ptr cexample = gen_concreteCE(tolerance);
	return cexample;
//	if(cexample->validate())
//	{
//		std::cout << "Generated Trace Validated\n";
//		return cexample;
//	}
//	else
//		throw std::runtime_error("Validation of counter example FAILED\n");
/*
	violating_CE v;
	v = cexample->validate();

	if(!v.flag){
		std::cout << "Trajectory validation failed\n";
		refinements.push_back(v); // refining trajectory added
		cexample = gen_concreteCE(tolerance);
		v = cexample->validate();
	}
	else
		std::cout << "Trajectory Validation PASSED\n";*/

}
