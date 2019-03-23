/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include "counterExample/abstractCE.h"
#include "counterExample/simulation.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "Utilities/gradient.h"
#include "core_system/math/analyticODESol.h"
#include "InputOutput/io_utility.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "Utilities/Post_Assignment.h"
#include "core_system/math/matrix.h"

#include <fstream>
#include <sstream>

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
std::vector<double> simulate_trajectory(const std::vector<double>& x0,
		Dynamics& D, const double& time, double& distance, polytope::ptr Inv,
		std::vector<double>& grad) {
	/**
	 * This function is to simulate trajectory from x0 for time units.
	 * todo: current dummy implementation to be completed
	 */

	simulation::ptr s = simulation::ptr(new simulation(x0.size(),100,D));
	std::vector<double> y;
//	If trace validation is enabled.
//	y = s->bounded_simulation(x0, time, Inv); // validated trace generation

	distance = 0;
	for(unsigned int i=0;i<grad.size();i++){
		grad[i] = 0;
	}

	y = s->metric_simulate(x0,time,distance,Inv,grad);
// 	if trace validation is not enabled, call the following simulate function
//	y = s->simulate(x0, time); // no trace validation
	assert(y.size() == dim);
	return y;
}

//constructor method
abstractCE::abstractCE(std::list<symbolic_states::ptr> s_states,
		std::list<transition::ptr> ts, hybrid_automata::ptr h, polytope::ptr fpoly) {

	sym_states = s_states;
	trans = ts;
	length = sym_states.size();
	H = h;
	forbid_poly = fpoly;
}

symbolic_states::const_ptr abstractCE::get_first_symbolic_state() const
{
	std::list<symbolic_states::ptr>::const_iterator it = sym_states.begin();
	return *it;

}
symbolic_states::const_ptr abstractCE::get_last_symbolic_state() const
{
	std::list<symbolic_states::ptr>::const_iterator it = sym_states.end();
	return *it;
}

void abstractCE::set_sym_states(std::list<symbolic_states::ptr> sym) {
	sym_states = sym;
	length = sym_states.size();
}

symbolic_states::const_ptr abstractCE::get_symbolic_state(unsigned int i) const {
	assert(0 <= i && i < get_length());
	unsigned int j = 0;
	std::list<symbolic_states::ptr>::const_iterator it =
			sym_states.begin();
	while (j < i){
		it++;
		j++;
	}
	return *it;
}

bool abstractCE::filter(std::vector<unsigned int> template_seq){

	if(template_seq.size()==0)
		return true;

	if(template_seq.size()!=this->length)
		return false;

	unsigned int locid;
	std::list<symbolic_states::ptr>::iterator iter = this->sym_states.begin();

	for(unsigned int i=0;i<template_seq.size();i++){
		symbolic_states::ptr symb_state = *iter;
		//ensure that the symbolic state has just one discrete location
		assert(symb_state->getDiscreteSet().getDiscreteElements().size()==1);

		locid = *(symb_state->getDiscreteSet().getDiscreteElements().begin());
		if(template_seq[i] != locid){
			return false;
		}
		iter++;
	}
	return true;
}
//void abstractCE::plot(unsigned int i, unsigned int j) {
//	/** Plotting the abstract counter example in a tracefile */
//	std::ofstream tracefile;
//	tracefile.open("./ceTrace.o");
//	math::matrix<double> vertices_list;
//	std::list<symbolic_states::ptr>::iterator it;
//	for (it = sym_states.begin(); it != sym_states.end(); it++) {
//		vertices_list = (*it)->getContinuousSet()->get_2dVertices(i, j);
//		// ------------- Printing the vertices on the Output File -------------
//		for (unsigned int p = 0; p < vertices_list.size1(); p++) {
//			for (unsigned int q = 0; q < vertices_list.size2(); q++) {
//				tracefile << vertices_list(p, q) << " ";
//			}
//			tracefile << std::endl;
//		}
//		tracefile << std::endl; // 1 gap after each polytope plotted
//	}
//	tracefile.close();
//	/**end of tracefile generation */
//}

/**
 * Routine to compute concrete trajectory from given
 * abstract counter example using non-linear optimization
 * routine and using the constraints from flowpipe
 *
 * @Rajarshi
 * 28th January 2016
 */
concreteCE::ptr abstractCE::gen_concreteCE(double tolerance, const std::list<refinement_point>& refinements) {

//	 Generate an nlopt object with the constraints defined by the Abstract
//	 counter example

//	 1. Get the dimension of the optimization problem by
//	 getting the dimension of the continuous set of the abstract counter example

	symbolic_states::const_ptr S = get_first_symbolic_state();
	//dim = S->getContinuousSetptr()->get_dimension();	//@Amit modified: Since when called from WoFC, will not have this set
	dim = S->getInitialPolytope()->getSystemDimension();
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size()+1; // the length of the counter example
	bad_poly = this->forbid_poly;
	ref_pts = refinements;


	//assert that the number of transitions equals 1 less than the length of the abstract CE path

	std::cout << "Length of the CE, N=" << N << std::endl;
	std::cout << "gen_concreteCE: dimension =" << dim <<", length of CE=" << N << std::endl;

	// initialize the global locIdList
	locIdList.resize(N);
      
	std::cout << "Location ID sequence in symbolic CE: ";
	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout << locIdList[i] << " | " ;
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
	double max,min,start_min,start_max;

	// Generate bounds for each start point. Also initialize each start point as the average of min and max
	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		// dxli: the whole flowpipe is a sequence of sub-flowpipes, each of which
		// denotes \omega in each location.
		// S is the sub-flowpipe in i-th sequence; P is the first \omega in S.
		S = get_symbolic_state(i);
		polytope::ptr P = S->getInitialPolytope();

		lp_solver lp(GLPK_SOLVER);

		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());

		// 	we add bound constraints on the position parameters, which are required to run global opt routines.
		std::vector<double> dir(dim,0);
		double min, max;
		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			dir[j] = -1;
			try{
				min = -1 * lp.Compute_LLP(dir);
			}catch(...){
				// assuming that the exception is caused due to an unbounded solution
				min = -999;	// an arbitrary value set as solution
			}
			dir[j] = 1;
			try{
				max = lp.Compute_LLP(dir);
			}catch(...){
				// assuming that the exception is caused due to an unbounded solution
				max = +999; // an arbitrary value set as solution
			}
			unsigned int index = i*dim+j;

			lb[index] = min;
			ub[index] = max;

			dir[j] = 0;
			// dxli: using the (min+max)/2 to initialize variables.
			x[index] = (lb[index] + ub[index])/2;
		}
	}
//	std::cout << "generated initial points\n";
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

	bool aggregation=true; //default is ON

	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		polytope::ptr P;
		if(i==N-1){
			// If last abstract symbolic state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,bad_poly,1);
			assert(polys.size()>=0); // The last sym state of an abstract CE must intersect with the bad set

			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P = polys.front();

			P = P->GetPolytope_Intersection(bad_poly);
		}
		else {
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGaurd();
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,guard,1);

			assert(polys.size()>=1); // An abstract CE state must have intersection with the trans guard
			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P=polys.front();
			// Now intersect P with guard
			P = P->GetPolytope_Intersection(guard);

		}

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());
		// ensure that time is always positive
		try{
			max = lp.Compute_LLP(dmax);
		}catch(...){
			// assuming that the exception is caused due to an unbounded solution
			max = 999; // an arbitrary large value set as solution
		}
		try{
			min = -1 * lp.Compute_LLP(dmin);
		}catch(...){
			// assuming that the exception is caused due to an unbounded solution
			min = 0; // the min value that time can take is 0.

		}

		// we add the bounds as constraints in the nlopt

		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		polytope::ptr init_of_symb = S->getInitialPolytope();

		lp1.setConstraints(init_of_symb->getCoeffMatrix(), init_of_symb->getColumnVector(),init_of_symb->getInEqualitySign());
		// Ensure that the time is positive
		start_min = -1 * lp1.Compute_LLP(dmin);
		start_max = lp1.Compute_LLP(dmax);
		ub[N*dim+i] = max - start_min;
		if(min<=start_max)
			lb[N*dim+i] = 0;
		else
			lb[N*dim+i] = min-start_max;

		// We may choose to take the average time as the initial dwell time
		x[N * dim + i] = (lb[N*dim+i] + ub[N*dim+i])/2;

		// Increment the Transition to the next in the symbolic path
		if(it!=transList.end())
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
		std::cout << "Local optimization algorithm called:" << myopt.get_algorithm_name() << std::endl;
		myopt.set_stopval(tolerance);
		unsigned int res = myopt.optimize(x, minf);

		if(res==NLOPT_SUCCESS)
			std::cout << "Splicing with FC: NLOPT stopped successfully returning the found minimum\n";
		else if(res == NLOPT_STOPVAL_REACHED)
			std::cout << "Splicing with FC: NLOPT stopped due to stopping value (1e-6) reached\n";
		else if (res == NLOPT_MAXEVAL_REACHED)
			std::cout << "Splicing with FC: NLOPT stopped due to reaching maxeval = " << maxeval << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "nlopt returned min : " << minf << "\n";
	std::cout << "Length of abstract counter example:" << N <<"\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance << ", with no. of refined search:" << refinements.size() << std::endl;
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
 */
//concreteCE::ptr abstractCE::gen_concreteCE_NLP_LP(double tolerance, const std::list<refinement_point>& refinements) {
//
//	symbolic_states::const_ptr S = get_first_symbolic_state();
//	dim = S->getContinuousSetptr()->get_dimension();
//	N = get_length(); // the length of the counter example
//	HA = this->get_automaton();
//	transList = this->get_CE_transitions();
//	bad_poly = this->forbid_poly;
//	ref_pts = refinements;
//	ce_sym_states = this->get_CE_sym_states();
//	X0 = std::vector<std::vector<double> >(N);
//
//	std::cout << "gen_concreteCE_NLP_LP: dimension =" << dim <<", length of CE=" << N << std::endl;
//	// initialize the global locIdList
//	locIdList.resize(N);
//
//
//	std::set<int> d;
//	for(unsigned int i=0;i<N;i++){
//		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
//		locIdList[i] = *(d.begin());
////		std::cout << "printing loc ids:" << locIdList[i] << " " << std::endl;
//	}
//
//
////	 The dimensionality of the NLP opt problem is N dwell times.
//
//	unsigned int optD = N;
//	std::cout << "nlopt problem dimension = " << optD << std::endl;
//
//	// choose the type of NLOPT solver
////	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative based
//	nlopt::opt myopt(nlopt::LN_COBYLA,optD); // derivative free method
//
//	myopt.set_maxeval(5000);
//	myopt.set_stopval(1e-6);
//
////	myopt.set_xtol_rel(1e-4);
//
//	myopt.set_min_objective(myobjfunc3, NULL);
//	//myopt.set_initial_step(0.001);
//
//	//Set Initial value to the optimization problem
//	std::vector<double> x(optD, 0);
//	polytope::ptr P;
//
////	We assume that the time variable is named as 't' in the model.
////	We find out the min,max components of the time variable
//
//	unsigned int t_index = get_first_symbolic_state()->getInitialPolytope()->get_index("t");
//
//	assert((t_index >= 0) && (t_index < dim));Trajectories
//
//	std::vector<double> dmin(dim, 0), dmax(dim, 0);
//	dmax[t_index] = 1;
//	dmin[t_index] = -1;
//
//	boundConstraint B[N],B1[N];
//
//	std::list<transition::ptr>::iterator it = transList.begin();
//	transition::ptr T;
//
//	std::list<polytope::ptr> polys;
//	polytope::ptr guard;
//
//	double max,min,start_min;
//	for (unsigned int i = 0; i < N; i++) {
//		S = get_symbolic_state(i);
//		if(i==N-1){
//			// If last abst sym state, then take time projection of flowpipe \cap bad_poly
//			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(bad_poly,1);
//		}
//		else{
//			// Take time projection of flowpipe \cap transition guard
//			T = *(it);
//			guard = T->getGaurd();
//			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(guard,1);
//		}
////		To get a point from the polytope, we create a random obj function and
////		solve the lp. The solution point is taken as an initial valu./hg_xspeed --model 2 --direction 1 --time-horizon 10 --time-step 0.01 --depth 5 -v t,x -o test.o -F "loc==-1 & x>=2 & x<=4 & t>=15 & t<=16"e.
//
//		// we keep this assert to first handle the simple case when flowpipe intersects the guard only at one place
//		assert(polys.size()==1);
//		P=polys.front();
//
//		lp_solver lp(GLPK_SOLVER);
//		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());
//		max = lp.Compute_LLP(dmax);
//		min = -1 * lp.Compute_LLP(dmin);
//		// we add the bounds as constraints in the nlopt
//
//		B[i].var_index = i;
//		B[i].bound = max;
//		B[i].is_ge = false;
//		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
//		B1[i].var_index = B[i].var_index;
//		B1[i].is_ge=true;
//		B1[i].bound = min;
//		myopt.add_inequalit./hg_xspeed --model 2 --direction 1 --time-horizon 10 --time-step 0.01 --depth 5 -v t,x -o test.o -F "loc==-1 & x>=2 & x<=4 & t>=15 & t<=16"y_constraint(myBoundConstraint, &B1[i], 1e-8);
//		// We DBL_MAXmay choose to take the max-min as the initial dwell time
//		x[i] = (max + min)/2;
//		if(it!=transList.end())
//			it++;
////		std::cout << "First time range: min = " << min << ", max = " << max << std::endl;
//	}
//
//	double minf;
//	try {
//		nlopt::result result = myopt.optimize(x, minf);
//		if (result < 0)
//			throw "abstractCE: gen_concreteCE: NLOpt failed\n";
//
//	} catch (std::exception& e) {
//		std::cout << "Nlopt caused exception:" << e.what() << std::endl;
//	}
//	std::cout << "nlopt returned min : " << minf << "\n";
//	std::cout << "Length of abstract counter example:" << N <<"\n";
////	std::cout << "Number of samples by NLopt: " << samples << "\n";
//
//	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
//	cexample->set_automaton(HA);
//	if (minf > tolerance) {
//		std::cout << "Obtained minimum greater than " << tolerance << std::endl;
//		return cexample;
//	} else {
//
//		// one trajectory per symbolic state to be added in the concreteCE
//		// Assumption: X0 contains the start points of the trajectory segments returned by NLOPT
//		for (unsigned int i = 1; i < N; i++) {
//			// create the sample
//			concreteCE::sample s;
//			std::set<int>::iterator dset_iter =
//					get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
//			unsigned int locId = *dset_iter;
//
//			std::vector<double> y(dim);
//			y = X0[i-1]; // X0 is initiated by the LP solver
//
//			double time = x[i];
//			s.first = y;
//			//s.second = y[dim-1];
//			s.second = time;
//			concreteCE::traj_segment traj;
//			traj.first = locId;
//			traj.second = s;
//			cexample->push_back(traj);
//		}
//	}
//
//	return cexample;
//}




/**
 * Generate concrete trajectory using splicing with mixed NLP-LP problem (Goran's Idea).
 * dxli: September, 2018
 */
concreteCE::ptr abstractCE::gen_concreteCE_NLP_LP(double tolerance, const std::list<refinement_point>& refinements) {
	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();

	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size()+1; // the length of the counter example
	bad_poly = this->forbid_poly;
	ref_pts = refinements;

	std::cout << "Length of the CE, N=" << N << std::endl;
	std::cout << "gen_concreteCE_NLP_LP: dimension =" << dim <<", length of CE=" << N << std::endl;

	// initialize the global locIdList
	locIdList.resize(N);

	std::cout << "Location ID sequence in symbolic CE: ";
	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout << locIdList[i] << " | " ;
	}
	std::cout << "\n";

	// 1. Initialize values of starting points and dwelling time by projections and also get bound info
	unsigned int optDimDwellTime = N;
	unsigned int optDimStateVars = N * dim;

	std::vector<double> t(optDimDwellTime, 0);
	std::vector<double> lb_t(optDimDwellTime), ub_t(optDimDwellTime);

	std::vector<double> x(optDimStateVars, 0);
	std::vector<double> lb_x(optDimStateVars, 0), ub_x(optDimStateVars, 0);
	std::vector<std::vector<double> > y(dim);

	// ======================================
	// set initial values for starting points
	double max,min,start_min,start_max;
	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		// dxli: the whole flowpipe is a sequence of sub-flowpipes, each of which
		// denotes \omega in each location.
		// S is the sub-flowpipe in i-th sequence; P is the first \omega in S.
		S = get_symbolic_state(i);
		polytope::ptr P = S->getInitialPolytope();

		lp_solver lp(GLPK_SOLVER);

		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());

		// 	we add bound constraints on the position parameters, which are required to run global opt routines.
		std::vector<double> dir(dim,0);
		double min, max;
		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			dir[j] = -1;
			try{
				min = -1 * lp.Compute_LLP(dir);
			}catch(...){
				// assuming that the exception is caused due to an unbounded solution
				min = -999;	// an arbitrary value set as solution
			}
			dir[j] = 1;
			try{
				max = lp.Compute_LLP(dir);
			}catch(...){
				// assuming that the exception is caused due to an unbounded solution
				max = +999; // an arbitrary value set as solution
			}
			unsigned int index = i*dim+j;

			dir[j] = 0;
			// dxli: using the (min+max)/2 to initialize variables.
			x[index] = (min + max)/2;
			lb_x[index] = min;
			ub_x[index] = max;

			cout << index << endl;
			cout << lb_x[index] << endl;
			cout << ub_x[index] << endl;
		}
	}

	// ======================================
	// set initial values for dwell time
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

	bool aggregation=true; //default is ON

	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		polytope::ptr P;
		if(i==N-1){
			// If last abstract symbolic state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,bad_poly,1);
			assert(polys.size()>=0); // The last sym state of an abstract CE must intersect with the bad set

			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P = polys.front();

			P = P->GetPolytope_Intersection(bad_poly);
		}
		else {
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGaurd();
			if(guard->getIsUniverse())
				std::cout << "#Guard is Universe#\n" << std::endl;

			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,guard,1);

			assert(polys.size()>=1); // An abstract CE state must have intersection with the trans guard
			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P=polys.front();
			// Now intersect P with guard
			P = P->GetPolytope_Intersection(guard);

		}

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());
		// ensure that time is always positive
		try{
			max = lp.Compute_LLP(dmax);
		}catch(...){
			// assuming that the exception is caused due to an unbounded solution
			max = 999; // an arbitrary large value set as solution
		}
		try{
			min = -1 * lp.Compute_LLP(dmin);
		}catch(...){
			// assuming that the exception is caused due to an unbounded solution
			min = 0; // the min value a time can take is 0.

		}

		// we add the bounds as constraints in the nlopt

		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		polytope::ptr init_of_symb = S->getInitialPolytope();

		lp1.setConstraints(init_of_symb->getCoeffMatrix(), init_of_symb->getColumnVector(),init_of_symb->getInEqualitySign());
		// Ensure that the time is positive
		start_min = -1 * lp1.Compute_LLP(dmin);
		start_max = lp1.Compute_LLP(dmax);
		ub_t[i] = max - start_min;
		if(min<=start_max)
			lb_t[i] = 0;
		else
			lb_t[i] = min-start_max;

		// We may choose to take the average time as the initial dwell time
		t[i] = (lb_t[i] + ub_t[i])/2;

		// Increment the Transition to the next in the symbolic path
		if(it!=transList.end())
			it++;
	}

	// ======================================
	// 2. Fixing state vars. The optimization over time variable t is a nonlinear
	// optimization problem.
	nlopt::opt myoptDwellTime(nlopt::LD_MMA, optDimDwellTime); // derivative based

	myoptDwellTime.set_lower_bounds(lb_t);
	myoptDwellTime.set_upper_bounds(ub_t);

	myoptDwellTime.set_min_objective(myobjfuncOnDwellTime, &x);
	myoptDwellTime.set_stopval(tolerance);
	myoptDwellTime.set_xtol_rel(1e-6);
	myoptDwellTime.set_maxeval(500);

	// ======================================
	// 3. Fixing time variable t, taking Chebyshev distance, the optimization over
	// state variable xi can be formulated as a linear program.
	unsigned int lpDim = dim * N + (N-1);
	math::vector<double> obj_vec(lpDim, 0);
	for (unsigned int i=N*dim; i<obj_vec.size(); i++){
		obj_vec[i] = 1;
	}

	math::matrix<double> bounds_coeff = math::matrix<double>(1, lpDim);
	std::vector<double> bounds_col;

	construct_bound_constraints(bounds_coeff, bounds_col, lb_x, ub_x, dim);

	lp_solver mylp;
//	lp_solver mylp = construct_LP(lpDim, t);
//	double optimal_val = mylp.Compute_LLP(obj_vec);
//	std::vector<double> optimal_point = mylp.get_sv();
//	for (unsigned int i = 0; i < x.size(); i++){
//		x[i] = optimal_point[i];
//	}

	double minf = 1e10;
	try {
		while (minf > tolerance){
			std::cout << "Local optimization algorithm called:" << myoptDwellTime.get_algorithm_name() << std::endl;
//
			myoptDwellTime.set_min_objective(myobjfuncOnDwellTime, &x);
			myoptDwellTime.optimize(t, minf);
			cout << "time variables: " << endl;
			for (unsigned int i = 0; i < t.size(); i++)
			{
				cout << t[i] << endl;
			}

			// build LP
			lp_solver mylp = construct_LP(lpDim, t, bounds_coeff, bounds_col);
			// solve LP
			double optimal_val = mylp.Compute_LLP(obj_vec);
			std::vector<double> optimal_point = mylp.get_sv();
			// copy result to x

//			cout <<endl;
			for (unsigned int i = 0; i < x.size(); i++){
				x[i] = optimal_point[i];
//				cout << x[i] << endl;
			}
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "nlopt returned min : " << minf << "\n";
	std::cout << "Length of abstract counter example:" << N <<"\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance << std::endl;
		return cexample;
	} else {
		std::ofstream ce_trace;
		std::cout << "Successfully found a concrete trajectory." << endl;
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

			double time = t[i];
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
/*
 *  dxli: September, 2018
 */
void abstractCE::construct_bound_constraints(math::matrix<double> &coeff_mat, std::vector<double> &col, std::vector<double> lb, std::vector<double> ub, unsigned int dim){
	// number of segments in abstract traj.
	unsigned int N = lb.size() / dim;
	unsigned int lpDim = coeff_mat.size2();

	math::matrix<double> row_temp = math::matrix<double>(1, lpDim);
	double col_temp;
	for (unsigned int i=0; i<N; i++){
		for (unsigned int j=0; j<row_temp.size2(); j++){
			row_temp(0,j) = 0;
		}

		for (unsigned int j=0; j<dim; j++){
			// upper bound
			row_temp(0, i*dim+j) = 1;
			col_temp = ub[i*dim+j];

			if (i==0 && j==0){
				row_temp.matrix_copy(coeff_mat);
			} else {
				coeff_mat.matrix_join(row_temp, coeff_mat);
			}
			col.push_back(col_temp);

			// lower bound, need to flip the sign
			row_temp(0, i*dim+j) = -1;
			col_temp = -lb[i*dim+j];

			coeff_mat.matrix_join(row_temp, coeff_mat);
			col.push_back(col_temp);

			row_temp(0, i*dim+j) = 0;
		}

	}
}
/*
 *  dxli: September, 2018
 */
lp_solver abstractCE::construct_LP(unsigned int lpDim, std::vector<double> &t, math::matrix<double> lp_coeff_mat, std::vector<double> lp_col){
	lp_solver mylp(GLPK_SOLVER);

	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();

	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size()+1; // the length of the counter example
	bad_poly = this->forbid_poly;
	polytope::ptr I;

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	transition::ptr Tptr = *(T_iter);

//	math::matrix<double> lp_coeff_mat = math::matrix<double>(1, lpDim);
//	std::vector<double> lp_col;
	// dimension of the LP problem

	math::matrix<double> A, expAt;
	std::vector<double> Axplusb(dim), mapAxplusb;

	cout << lpDim << endl;

	for (unsigned int i=0; i<N; i++){
		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		I = HA->getLocation(loc_index)->getInvariant();

		if(d.isEmptyMatrixA){
			A = math::matrix<double>(dim,dim);
			for(unsigned int i=0;i<dim;i++){
				for(unsigned int j=0;j<dim;j++){
					A(i,j)=0;
				}
			}
		}
		else
			A = d.MatrixA;

//		cout << "Location " << i << endl;
//		cout << "coeff matrix:" << A << endl;
//		cout << "dwelling time:" << t[i] << endl;

		math::matrix<double> At(A);
		At.scalar_multiply(t[i]);
		At.matrix_exponentiation(expAt);

		std::vector<double> inhomo_term = ODESol_inhomogenous(d, t[i]);

		cout << "inhomo_term: ";
		for(auto ele:inhomo_term){
			cout << ele << " ";
		}

		if (i==N-1){
			math::matrix<double> C = bad_poly->getCoeffMatrix();
			math::vector<double> b = bad_poly->getColumnVector();

			math::matrix<double> row = math::matrix<double>(1, C.size2());
			math::matrix<double> res_row = math::matrix<double>(1, dim);
			math::matrix<double> res_row_with_padding = math::matrix<double>(1, lpDim);
			std::vector<double> res_col;

			// linear constraint saying that the last ending point is in the bad poly
			for (unsigned int j=0; j<C.size1();j++){
				for (unsigned int k=0; k<C.size2();k++){
					row(0,k) = C(j, k);
				}
				row.multiply(expAt, res_row);
				// padding with 0
				// somehow resize does not padding with 0??
//				res_row.resize(1, lpDim);
				for (unsigned int l=0; l<lpDim; l++){
					if (l<i*dim || l>=(i+1)*dim){
						res_row_with_padding(0,l) = 0;
					} else {
						res_row_with_padding(0,l) = res_row(0, l-i*dim);
					}
				}
				row.mult_vector(inhomo_term, res_col);

//				cout << "checkpoint 991" << endl;
//				cout << "inhome term" << endl;
//				for (auto elem: inhomo_term){
//					cout << elem << endl;
//				}
//				cout << "row:" << endl;
//				cout << row << endl;
//				for (auto elem:res_col){
//					cout << elem << endl;
//				}

//				cout << "badpoly: " << j << "constraints:";
//				cout << "b[j]=" << b[j] << endl;
//				cout << "res_col=" << res_col[0] << endl;
				lp_col.push_back(b[j] - res_col[0]);
//				cout << "lp_col new elem:" << lp_col[lp_col.size()-1]<<endl;
//				cout << "checkpoint 998" << endl;

//				if (i==0 && j==0){
//					res_row.matrix_copy(lp_coeff_mat);
//				} else {
				lp_coeff_mat.matrix_join(res_row_with_padding, lp_coeff_mat);
//				}
			}

//			cout << "bad_poly coeff:" << C << endl;
//			cout << "bad_poly vec: ";
//			for(auto ele:b){
//				cout << ele << " ";
//			}
//
//			cout << "checkpoint 952" << endl;
//			for (auto elem : b){
//				cout << elem << " ";
//			}
//			cout << endl << endl;
//			cout << "badpoly coefficient:" << endl;
//			cout << C << endl;
//			cout<<endl;
//
//			cout << "badpoly column:" << endl;
//			for (auto elem : b){
//				cout << elem << endl;
//			}
//
//			cout << "\n expAt:" << endl;
//			cout << expAt << endl;
//			cout<<endl;
//
//			cout << "inhomogeous term:" << endl;
//			for (auto elem : inhomo_term){
//				cout << elem << endl;
//			}
		} else {
			polytope::ptr g;
			Assign R;

			// assign the transition pointer
			Tptr = *(T_iter);

			// assignment of the form: Rx + w
			R = Tptr->getAssignT();
//			cout << "Jump Map: " << R.Map << endl;
//			cout << "Jump vec: ";
//			for(auto ele:R.b){
//				cout << ele << " ";
//			}
//			cout << endl;

			//guard as a polytope
			g = Tptr->getGaurd();

			// guard \cap invariant distance, to address Eq. (12) in CDC 13' paper
			polytope::ptr guard_intersect_inv;
			guard_intersect_inv = I->GetPolytope_Intersection(g);

			// ======================
			// add constraints saying ending points yi should be in the intersection of guard and invariant.
			math::matrix<double> C = guard_intersect_inv->getCoeffMatrix();
			math::vector<double> b = guard_intersect_inv->getColumnVector();

//			cout << "Guard intersect inv coeff:" << C << endl;
//			cout << "Guard intersect inv vec: ";
//			for(auto ele:b){
//				cout << ele << " ";
//			}
//			cout << endl;

			math::matrix<double> row = math::matrix<double>(1, C.size2());
			math::matrix<double> res_row = math::matrix<double>(1, dim);
			math::matrix<double> res_row_with_padding = math::matrix<double>(1, lpDim);
			std::vector<double> res_col;

			for (unsigned int j=0; j<C.size1();j++){
				for (unsigned int k=0; k<C.size2();k++){
					row(0,k) = C(j, k);
				}
				row.multiply(expAt, res_row);
				// padding with 0
				// somehow resize does not padding with 0 but 0/1??
//				res_row.resize(1, lpDim);
//				for (unsigned int l=dim; l<lpDim; l++){
//					res_row(0,l) = 0;
//				}
//				cout << "res_row" << res_row << endl;
				for (unsigned int l=0; l<lpDim; l++){
					if (l<i*dim || l>=(i+1)*dim){
						res_row_with_padding(0,l) = 0;
					} else {
						res_row_with_padding(0,l) = res_row(0, l-i*dim);
					}
				}
//				cout << "res_row_with_padding" << res_row_with_padding << endl;
//				cout << j << endl;
//				cout << "row: " << row;
//				cout << "inhome: ";
//				for (auto elem:inhomo_term){
//					cout << elem << " ";
//				}

				row.mult_vector(inhomo_term, res_col);
//				cout << "res_col: " << res_col[0] << endl;
//				cout << "b[j]=" << b[j] << endl;
				lp_col.push_back(b[j] - res_col[0]);
//				cout << "push_back:" << b[j] - res_col[0] << endl;

//				if (i==0 && j==0){
////					res_row.matrix_copy(lp_coeff_mat);
//				} else {
				lp_coeff_mat.matrix_join(res_row_with_padding, lp_coeff_mat);
//				}

			}

			// =======================================
			// Adding linear constraints minimizing \inf-norm{R(y[i]) -x[i]}
			// denote inf norm of a vector as |v|_{inf}
			// By definition: |v|_{inf} = max{|vi|} across dimensions
			//
			// |v|_{inf} = max{|vi|}
			// is equiv. to min w
			//              s.t. -w - vi <= 0, for all i
			//                   -w + vi <= 0, for all i
			//                   -w      <= 0
			// See
			// (1) https://optimization.mccormick.northwestern.edu/index.php/Optimization_with_absolute_values
			// (2) http://agecon2.tamu.edu/people/faculty/mccarl-bruce/mccspr/new09.pdf, page 10

			R = Tptr->getAssignT();
			math::matrix<double> mapExpAt(expAt);

//			cout << "checkpoint 1" << endl;

			// - ( R(y_{i,j}) - x_{i+1,j} ) - wi <= 0
			math::matrix<double> res_row_pos = math::matrix<double>(1, lpDim);
			// - ( R(y_{i,j}) - x_{i+1,j} ) - wi <= 0
			math::matrix<double> res_row_neg = math::matrix<double>(1, lpDim);

			std::vector<double> transform;

			R.Map.multiply(expAt,mapExpAt);
			R.Map.mult_vector(inhomo_term, transform);

//			cout << "checkpoint 2" << endl;
			for (unsigned int j=0; j<dim; j++){
//				cout << "checkpoint 3" << endl;
				// reset containers to 0 vectors
				for (unsigned int k = 0; k < lpDim; k++){
					res_row_pos(0, k) = 0;
					res_row_neg(0, k) = 0;
				}

//				cout << "checkpoint 4" << endl;
				for (unsigned int k=0; k<dim; k++){
					//  R(y_{i,j})
					res_row_pos(0,i*dim+k) = mapExpAt(j, k);

					// - R(y_{i,j})
					res_row_neg(0,i*dim+k) = -mapExpAt(j, k);
				}
//				cout << "checkpoint 5" << endl;
				// - x_{i+1,j} - wi
				res_row_pos(0,j+(i+1)*dim) += -1;
//				res_row_pos(0,j+i*dim) = -1;
				res_row_pos(0,i+N*dim) = -1;

//				cout << "checkpoint 6" << endl;
				// x_{i+1,j} - wi
				res_row_neg(0,j+(i+1)*dim) += 1;
				res_row_neg(0,i+N*dim) = -1;

//				cout << "checkpoint 8" << endl;
				// pos
				lp_coeff_mat.matrix_join(res_row_pos, lp_coeff_mat);
				lp_col.push_back(-transform[j]-R.b[j]);
//				cout << "Adding " << res_row_pos << endl;
//				cout << "checkpoint 9" << endl;
				// neg
				lp_coeff_mat.matrix_join(res_row_neg, lp_coeff_mat);
				lp_col.push_back(transform[j]+R.b[j]);
//				cout << "Adding " << res_row_neg << endl;
//				cout << "checkpoint 10" << endl;

			}

			// - wi <= 0
//			cout << "checkpoint 7" << endl;
			math::matrix<double> res_row_w = math::matrix<double>(1, lpDim);
			for (unsigned int j=0;j<res_row_w.size2();j++){
				if (j == i+N*dim){
					res_row_w(0,j) = -1;
				} else {
					res_row_w(0,j) = 0;
				}
			}

//			cout << "Adding \n" << res_row_w << endl;

			// w
			lp_coeff_mat.matrix_join(res_row_w, lp_coeff_mat);
			lp_col.push_back(0);
		}

		T_iter++; // Moving to the next transition.
	}

	int MYLP_EQUALITY_SIGN = 1;
	unsigned int MIN_OR_MAX = 1;
	mylp.setConstraints(lp_coeff_mat, lp_col, MYLP_EQUALITY_SIGN);
	mylp.setMin_Or_Max(MIN_OR_MAX);

	math::vector<double> obj_vec(lpDim, 0);
	for (unsigned int i=N*dim; i<obj_vec.size(); i++){
		obj_vec[i] = 1;
	}

	double optimal_val = mylp.Compute_LLP(obj_vec);
//	std::vector<double> optimal_point = mylp.get_sv();
//	cout << endl;
//	for (unsigned int i = 0; i < optimal_point.size(); i++){
//		cout << optimal_point[i] << endl;
//	}

	/*   solution status:
	 The routine glp_get_status reports the generic status of the current basic solution for
	 the specified problem object as follows:

	 #define GLP_UNDEF          1  // solution is undefined
	 #define GLP_FEAS           2  // solution is feasible
	 #define GLP_INFEAS         3  // solution is infeasible
	 #define GLP_NOFEAS         4  // no feasible solution exists
	 #define GLP_OPT            5  // solution is optimal
	 #define GLP_UNBND          6  // solution is unbounded
	 */
//	cout << lp_coeff_mat << endl;
//	cout << "\n lp_col:" << endl;
//	for (auto i : lp_col){
//		cout << i << " ";
//	}
//	exit(0);
	if ( mylp.getStatus() == 4 ){
		cout << "\n lp_coeff_mat:" << endl;
		cout << lp_coeff_mat << endl;
	//	cout << "\n lp_col:" << endl;
	//	for (auto i : lp_col){
	//		cout << i << " ";
	//	}
	//	cout << lp_coeff_mat.size1() << endl;
	//	cout << lp_coeff_mat.size2() << endl << endl;
	//
		cout << "\n lp_col:" << endl;
		for (auto i : lp_col){
			cout << i << " ";
		}

		cout << "\n time vars: " << endl;
		for (auto elem : t){
			cout << elem << " ";
		}

		exit(0);
	}

	return mylp;
}
/*
 *  dxli: September, 2018
 */
concreteCE::ptr abstractCE::gen_concreteCE_NLP_LP_softconstr(double tolerance, const std::list<refinement_point>& refinements) {
	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();

	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size()+1; // the length of the counter example
	bad_poly = this->forbid_poly;
	ref_pts = refinements;

	std::cout << "Length of the CE, N=" << N << std::endl;
	std::cout << "gen_concreteCE_NLP_LP: dimension =" << dim <<", length of CE=" << N << std::endl;

	// initialize the global locIdList
	locIdList.resize(N);

	std::cout << "Location ID sequence in symbolic CE: ";
	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout << locIdList[i] << " | " ;
	}
	std::cout << "\n";

	// 1. Initialize values of starting points and dwelling time by projections and also get bound info
	unsigned int optDimDwellTime = N;
	unsigned int optDimStateVars = N * dim;

	std::vector<double> t(optDimDwellTime, 0);
	std::vector<double> lb_t(optDimDwellTime), ub_t(optDimDwellTime);

	// dim * N state variables
	// for N polys/badpoly we need 2 extra variables to encode the sum over distance between the point to each constraint of the poly
	// for each yi, xi+1 pair, introduce an extra variable to encode the maximization over chebyshev distance between the two vectors
	unsigned int lpDim = dim * N + N * 2 + (N-1);
	std::vector<double> x(optDimStateVars, 0);
	std::vector<double> lb_x(optDimStateVars, 0), ub_x(optDimStateVars, 0);
	std::vector<std::vector<double> > y(dim);

	// ======================================
	// set initial values for starting points
	double max,min,start_min,start_max;
	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		// dxli: the whole flowpipe is a sequence of sub-flowpipes, each of which
		// denotes \omega in each location.
		// S is the sub-flowpipe in i-th sequence; P is the first \omega in S.
		S = get_symbolic_state(i);
		polytope::ptr P = S->getInitialPolytope();

		lp_solver lp(GLPK_SOLVER);

		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());

		// 	we add bound constraints on the position parameters, which are required to run global opt routines.
		std::vector<double> dir(dim,0);
		double min, max;
		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			dir[j] = -1;
			try{
				min = -1 * lp.Compute_LLP(dir);
			}catch(...){
				// assuming that the exception is caused due to an unbounded solution
				min = -999;	// an arbitrary value set as solution
			}
			dir[j] = 1;
			try{
				max = lp.Compute_LLP(dir);
			}catch(...){
				// assuming that the exception is caused due to an unbounded solution
				max = +999; // an arbitrary value set as solution
			}
			unsigned int index = i*dim+j;

			dir[j] = 0;
			// dxli: using the (min+max)/2 to initialize variables.
			x[index] = (min + max)/2;
			lb_x[index] = min;
			ub_x[index] = max;

			cout << index << endl;
			cout << lb_x[index] << endl;
			cout << ub_x[index] << endl;
		}
	}

	// ======================================
	// set initial values for dwell time
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

	bool aggregation=true; //default is ON

	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		polytope::ptr P;
		if(i==N-1){
			// If last abstract symbolic state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,bad_poly,1);
			assert(polys.size()>=0); // The last sym state of an abstract CE must intersect with the bad set

			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P = polys.front();

			P = P->GetPolytope_Intersection(bad_poly);
		}
		else {
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGaurd();
			if(guard->getIsUniverse())
				std::cout << "#Guard is Universe#\n" << std::endl;

			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,guard,1);

			assert(polys.size()>=1); // An abstract CE state must have intersection with the trans guard
			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P=polys.front();
			// Now intersect P with guard
			P = P->GetPolytope_Intersection(guard);

		}

		cout << i << " " << P->getCoeffMatrix().size1() << endl;

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());
		// ensure that time is always positive
		try{
			max = lp.Compute_LLP(dmax);
		}catch(...){
			// assuming that the exception is caused due to an unbounded solution
			max = 999; // an arbitrary large value set as solution
		}
		try{
			min = -1 * lp.Compute_LLP(dmin);
		}catch(...){
			// assuming that the exception is caused due to an unbounded solution
			min = 0; // the min value a time can take is 0.

		}

		// we add the bounds as constraints in the nlopt

		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		polytope::ptr init_of_symb = S->getInitialPolytope();

		lp1.setConstraints(init_of_symb->getCoeffMatrix(), init_of_symb->getColumnVector(),init_of_symb->getInEqualitySign());
		// Ensure that the time is positive
		start_min = -1 * lp1.Compute_LLP(dmin);
		start_max = lp1.Compute_LLP(dmax);
		ub_t[i] = max - start_min;
		if(min<=start_max)
			lb_t[i] = 0;
		else
			lb_t[i] = min-start_max;

		// We may choose to take the average time as the initial dwell time
		t[i] = (lb_t[i] + ub_t[i])/2;

		// Increment the Transition to the next in the symbolic path
		if(it!=transList.end())
			it++;
	}

	// ======================================
	// 2. Fixing state vars. The optimization over time variable t is a nonlinear
	// optimization problem.
	nlopt::opt myoptDwellTime(nlopt::LD_MMA, optDimDwellTime); // derivative based

	myoptDwellTime.set_lower_bounds(lb_t);
	myoptDwellTime.set_upper_bounds(ub_t);

	myoptDwellTime.set_min_objective(myobjfuncOnDwellTime, &x);
	myoptDwellTime.set_stopval(tolerance);
	myoptDwellTime.set_xtol_rel(1e-6);
	myoptDwellTime.set_maxeval(500);


	// ======================================
	// 3. Fixing time variable t, taking Chebyshev distance, the optimization over
	// state variable xi can be formulated as a linear program.

	// 3.1 in case LP is trapped, we use an nlp solver
	nlopt::opt myoptStateVars(nlopt::LD_MMA, optDimStateVars); // derivative based
	cout << "checkpoint 0" << endl;
	myoptStateVars.set_lower_bounds(lb_x);
	myoptStateVars.set_upper_bounds(ub_x);

	cout << "checkpoint 1" << endl;

	myoptStateVars.set_min_objective(myobjfuncOnStateVars, &x);
	myoptStateVars.set_stopval(tolerance);
	myoptStateVars.set_xtol_rel(1e-6);
	myoptStateVars.set_maxeval(500);

	cout << "checkpoint 2" << endl;
	// 3.2 construct LP
	math::vector<double> obj_vec(lpDim, 0);
	for (unsigned int i=N*dim; i<obj_vec.size(); i++){
		obj_vec[i] = 1;
	}

	math::matrix<double> bounds_coeff = math::matrix<double>(1, lpDim);
	std::vector<double> bounds_col;

	construct_bound_constraints(bounds_coeff, bounds_col, lb_x, ub_x, dim);

	lp_solver mylp;
//	lp_solver mylp = construct_LP(lpDim, t);
//	double optimal_val = mylp.Compute_LLP(obj_vec);
//	std::vector<double> optimal_point = mylp.get_sv();
//	for (unsigned int i = 0; i < x.size(); i++){
//		x[i] = optimal_point[i];
//	}

	double minf = 1e10;
	double prev_minf = 1e10;
	try {
		while (minf > tolerance){
			std::cout << "Local optimization algorithm called:" << myoptDwellTime.get_algorithm_name() << std::endl;
//
			myoptDwellTime.set_min_objective(myobjfuncOnDwellTime, &x);
			myoptDwellTime.optimize(t, minf);

			if (false){ // LP is not trapped
				prev_minf = minf;

				// build LP
				lp_solver mylp = construct_LP_softconstr(lpDim, t, bounds_coeff, bounds_col);
				// solve LP
				double optimal_val = mylp.Compute_LLP(obj_vec);
				std::vector<double> optimal_point = mylp.get_sv();
				cout << "state vars: " << endl;
				for (unsigned int i = 0; i < x.size(); i++){
					x[i] = optimal_point[i];
					cout << x[i] << " ";
				}
				cout << endl;

			} else { // LP is trapped
				cout << "checkpoint 200" << endl;
				myoptStateVars.set_min_objective(myobjfuncOnStateVars, &t);
				myoptStateVars.optimize(x, minf);
			}

			cout << "time vars: " << endl;
			for (unsigned int i = 0; i < t.size(); i++)
			{
				cout << t[i] << " ";
			}
			cout << endl;
//
//			// build LP
//			lp_solver mylp = construct_LP_softconstr(lpDim, t, bounds_coeff, bounds_col);
//			// solve LP
//			double optimal_val = mylp.Compute_LLP(obj_vec);
//			std::vector<double> optimal_point = mylp.get_sv();
//			// copy result to x
//
////			cout <<endl;
//			cout << "state vars: " << endl;
//			for (unsigned int i = 0; i < x.size(); i++){
//				x[i] = optimal_point[i];
//				cout << x[i] << " ";
//			}
//			cout << endl;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "nlopt returned min : " << minf << "\n";
	std::cout << "Length of abstract counter example:" << N <<"\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance << std::endl;
		return cexample;
	} else {
		std::ofstream ce_trace;
		std::cout << "Successfully found a concrete trajectory." << endl;
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

			double time = t[i];
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
/*
 *  dxli: September, 2018
 */
concreteCE::ptr abstractCE::gen_concreteCE_iterative(double tolerance, const std::list<refinement_point>& refinements) {
	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();

	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size()+1; // the length of the counter example
	bad_poly = this->forbid_poly;
	ref_pts = refinements;

	std::cout << "Length of the CE, N=" << N << std::endl;
	std::cout << "gen_concreteCE_iterative: dimension =" << dim <<", length of CE=" << N << std::endl;

	// initialize the global locIdList
	locIdList.resize(N);

	std::cout << "Location ID sequence in symbolic CE: ";
	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout << locIdList[i] << " | " ;
	}
	std::cout << "\n";

	/* 1. Declare the sub-problem by fixing starting points of each location.
	 * This problem is supposed to be a nonlinear problem.
	 *
	 * The length of the counter example is N. When fixing the starting point of
	 * each location, the decision variables are dwell time in each location.
	 * Therefore, the dimension of the opt problem is N.
	 *
	 */
	unsigned int optDimDwellTime = N;
	unsigned int optDimStateVars = N * dim;
	// LD_LBFGS
	nlopt::opt myoptDwellTime(nlopt::LD_MMA, optDimDwellTime); // derivative based
	nlopt::opt myoptStateVars(nlopt::LD_MMA, optDimStateVars); // derivative based
//
//	nlopt::opt myoptDwellTime(nlopt::LD_LBFGS, optDimDwellTime); // derivative based
//	nlopt::opt myoptStateVars(nlopt::LD_LBFGS, optDimStateVars); // derivative based

	std::vector<double> t(optDimDwellTime, 0);
	std::vector<double> lb_t(optDimDwellTime), ub_t(optDimDwellTime);

	std::vector<double> x(optDimStateVars, 0);
	std::vector<double> lb_x(optDimStateVars), ub_x(optDimStateVars);

	double max,min,start_min,start_max;
	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		// dxli: the whole flowpipe is a sequence of sub-flowpipes, each of which
		// denotes \omega in each location.
		// S is the sub-flowpipe in i-th sequence; P is the first \omega in S.
		S = get_symbolic_state(i);
		polytope::ptr P = S->getInitialPolytope();

		lp_solver lp(GLPK_SOLVER);

		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());

		// 	we add bound constraints on the position parameters, which are required to run global opt routines.
		std::vector<double> dir(dim,0);
		double min, max;
		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			dir[j] = -1;
			try{
				min = -1 * lp.Compute_LLP(dir);
			}catch(...){
				// assuming that the exception is caused due to an unbounded solution
				min = -999;	// an arbitrary value set as solution
			}
			dir[j] = 1;
			try{
				max = lp.Compute_LLP(dir);
			}catch(...){
				// assuming that the exception is caused due to an unbounded solution
				max = +999; // an arbitrary value set as solution
			}
			unsigned int index = i*dim+j;

			lb_x[index] = min;
			ub_x[index] = max;

			dir[j] = 0;
			// dxli: using the (min+max)/2 to initialize variables.
			x[index] = (lb_x[index] + ub_x[index])/2;
		}
	}

	myoptStateVars.set_lower_bounds(lb_x);
	myoptStateVars.set_upper_bounds(ub_x);

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

	bool aggregation=true; //default is ON

	// initialize values for dwell time
	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		polytope::ptr P;
		if(i==N-1){
			// If last abstract symbolic state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,bad_poly,1);
			assert(polys.size()>=0); // The last sym state of an abstract CE must intersect with the bad set

			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P = polys.front();

			P = P->GetPolytope_Intersection(bad_poly);
		}
		else {
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGaurd();
			if(guard->getIsUniverse())
				std::cout << "#Guard is Universe#\n" << std::endl;

			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,guard,1);

			assert(polys.size()>=1); // An abstract CE state must have intersection with the trans guard
			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P=polys.front();
			// Now intersect P with guard
			P = P->GetPolytope_Intersection(guard);

		}

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());
		// ensure that time is always positive
		try{
			max = lp.Compute_LLP(dmax);
		}catch(...){
			// assuming that the exception is caused due to an unbounded solution
			max = 999; // an arbitrary large value set as solution
		}
		try{
			min = -1 * lp.Compute_LLP(dmin);
		}catch(...){
			// assuming that the exception is caused due to an unbounded solution
			min = 0; // the min value a time can take is 0.

		}

		// we add the bounds as constraints in the nlopt

		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		polytope::ptr init_of_symb = S->getInitialPolytope();

		lp1.setConstraints(init_of_symb->getCoeffMatrix(), init_of_symb->getColumnVector(),init_of_symb->getInEqualitySign());
		// Ensure that the time is positive
		start_min = -1 * lp1.Compute_LLP(dmin);
		start_max = lp1.Compute_LLP(dmax);
		ub_t[i] = max - start_min;
		if(min<=start_max)
			lb_t[i] = 0;
		else
			lb_t[i] = min-start_max;

		// We may choose to take the average time as the initial dwell time
		t[i] = (lb_t[i] + ub_t[i])/2;

		// Increment the Transition to the next in the symbolic path
		if(it!=transList.end())
			it++;
	}

	myoptDwellTime.set_lower_bounds(lb_t);
	myoptDwellTime.set_upper_bounds(ub_t);

	myoptDwellTime.set_min_objective(myobjfuncOnDwellTime, &x);
	myoptDwellTime.set_stopval(tolerance);
//			nlopt_set_xtol_rel(nlopt_opt opt, double tol)
	myoptDwellTime.set_xtol_rel(1e-4);
	myoptDwellTime.set_maxeval(500);


	myoptStateVars.set_min_objective(myobjfuncOnStateVars, &t);
	myoptStateVars.set_stopval(tolerance);
	myoptStateVars.set_xtol_rel(1e-4);
	myoptStateVars.set_maxeval(500);

	double minf = 1e10;
	try {
		while (minf > tolerance){
			std::cout << "Local optimization algorithm called:" << myoptDwellTime.get_algorithm_name() << std::endl;
//
			myoptDwellTime.set_min_objective(myobjfuncOnDwellTime, &x);
			myoptDwellTime.optimize(t, minf);
//
			myoptStateVars.set_min_objective(myobjfuncOnStateVars, &t);
			myoptStateVars.optimize(x, minf);
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "nlopt returned min : " << minf << "\n";
	std::cout << "Length of abstract counter example:" << N <<"\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance << std::endl;
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

			double time = t[i];
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
/*
 *  dxli: September, 2018
 */
lp_solver abstractCE::construct_LP_softconstr(unsigned int lpDim, std::vector<double> &t, math::matrix<double> lp_coeff_mat, std::vector<double> lp_col){
	lp_solver mylp(GLPK_SOLVER);

	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();

	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	N = transList.size()+1; // the length of the counter example
	bad_poly = this->forbid_poly;
	polytope::ptr I;

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	transition::ptr Tptr = *(T_iter);

//	math::matrix<double> lp_coeff_mat = math::matrix<double>(1, lpDim);
//	std::vector<double> lp_col;
	// dimension of the LP problem

	math::matrix<double> A, expAt;
	std::vector<double> Axplusb(dim), mapAxplusb;

	cout << lpDim << endl;

	for (unsigned int i=0; i<N; i++){
		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();
		I = HA->getLocation(loc_index)->getInvariant();

		if(d.isEmptyMatrixA){
			A = math::matrix<double>(dim,dim);
			for(unsigned int i=0;i<dim;i++){
				for(unsigned int j=0;j<dim;j++){
					A(i,j)=0;
				}
			}
		}
		else
			A = d.MatrixA;

//		cout << "Location " << i << endl;
//		cout << "coeff matrix:" << A << endl;
//		cout << "dwelling time:" << t[i] << endl;

		math::matrix<double> At(A);
		At.scalar_multiply(t[i]);
		At.matrix_exponentiation(expAt);

		std::vector<double> inhomo_term = ODESol_inhomogenous(d, t[i]);
//		cout << "inhomo_term: ";
//		for(auto ele:inhomo_term){
//			cout << ele << " ";
//		}

		if (i==N-1){
			math::matrix<double> C = bad_poly->getCoeffMatrix();
			math::vector<double> b = bad_poly->getColumnVector();

			math::matrix<double> row = math::matrix<double>(1, C.size2());
			math::matrix<double> res_row = math::matrix<double>(1, dim);
			std::vector<double> res_col;

			math::matrix<double> res_row_with_padding_pos = math::matrix<double>(1, lpDim);
			math::matrix<double> res_row_with_padding_neg = math::matrix<double>(1, lpDim);

			math::matrix<double> epsilon_row_pos = math::matrix<double>(1, lpDim);
			math::matrix<double> epsilon_row_neg = math::matrix<double>(1, lpDim);

			std::vector<double> sum_col_pos;
			std::vector<double> sum_col_neg;
			sum_col_pos.push_back(0);
			sum_col_neg.push_back(0);

			for (unsigned int j=0; j<lpDim;j++){
				epsilon_row_pos(0, j) = 0;
				epsilon_row_neg(0, j) = 0;
				res_row_with_padding_pos(0,j) = 0;
				res_row_with_padding_neg(0,j) = 0;
			}

			// \eps_pos >= 0 is equiv. to -\eps_pos <= 0
			// \eps_neg >= 0 is equiv. to -\eps_neg <= 0
			epsilon_row_pos(0, N*dim+i*2) = -1;
			epsilon_row_neg(0, N*dim+i*2+1) = -1;
//
			lp_col.push_back(0);
			lp_col.push_back(0);
			lp_coeff_mat.matrix_join(epsilon_row_pos, lp_coeff_mat);
			lp_coeff_mat.matrix_join(epsilon_row_neg, lp_coeff_mat);

			// linear constraint saying that the last ending point is in the bad poly
			for (unsigned int j=0; j<C.size1();j++){
				for (unsigned int k=0; k<C.size2();k++){
					row(0,k) = C(j, k);
				}
				row.multiply(expAt, res_row);
				// padding with 0
				// somehow resize does not padding with 0??
//				res_row.resize(1, lpDim);
				for (unsigned int l=0; l<lpDim; l++){
					if (l>=i*dim && l<(i+1)*dim){
						res_row_with_padding_pos(0,l) += res_row(0, l-i*dim);
						res_row_with_padding_neg(0,l) += -res_row(0, l-i*dim);
					}
				}

				// \eps_pos + \eps_neg = Ax + b
				// we express it as:
				// \eps_pos + \eps_neg <= Ax + b
				// and
				// (\eps_pos + \eps_neg) <= -(Ax + b)
				res_row_with_padding_pos(0, N*dim+i*2) = 1;
				res_row_with_padding_pos(0, N*dim+i*2+1) = -1;

				res_row_with_padding_neg(0, N*dim+i*2) = -1;
				res_row_with_padding_neg(0, N*dim+i*2+1) = 1;

				row.mult_vector(inhomo_term, res_col);

				sum_col_pos[0] += b[j] - res_col[0];
				sum_col_neg[0] += res_col[0] - b[j];
			}

			lp_col.push_back(sum_col_pos[0]);
			lp_coeff_mat.matrix_join(res_row_with_padding_pos, lp_coeff_mat);

			lp_col.push_back(sum_col_neg[0]);
			lp_coeff_mat.matrix_join(res_row_with_padding_neg, lp_coeff_mat);

		} else {
			polytope::ptr g;
			Assign R;

			// assign the transition pointer
			Tptr = *(T_iter);

			// assignment of the form: Rx + w
			R = Tptr->getAssignT();
//			cout << "Jump Map: " << R.Map << endl;
//			cout << "Jump vec: ";
//			for(auto ele:R.b){
//				cout << ele << " ";
//			}
//			cout << endl;

			//guard as a polytope
			g = Tptr->getGaurd();

			// guard \cap invariant distance, to address Eq. (12) in CDC 13' paper
			polytope::ptr guard_intersect_inv;
			guard_intersect_inv = I->GetPolytope_Intersection(g);

			// ======================
			// add constraints saying ending points yi should be in the intersection of guard and invariant.
			math::matrix<double> C = guard_intersect_inv->getCoeffMatrix();
			math::vector<double> b = guard_intersect_inv->getColumnVector();

//			cout << "Guard intersect inv coeff:" << C << endl;
//			cout << "Guard intersect inv vec: ";
//			for(auto ele:b){
//				cout << ele << " ";
//			}
//			cout << endl;

			math::matrix<double> row = math::matrix<double>(1, C.size2());
			math::matrix<double> res_row = math::matrix<double>(1, dim);
			math::matrix<double> res_row_with_padding_pos = math::matrix<double>(1, lpDim);
			math::matrix<double> res_row_with_padding_neg = math::matrix<double>(1, lpDim);
			math::matrix<double> epsilon_row_pos = math::matrix<double>(1, lpDim);
			math::matrix<double> epsilon_row_neg = math::matrix<double>(1, lpDim);
			std::vector<double> res_col;

			std::vector<double> sum_col_pos;
			std::vector<double> sum_col_neg;
			sum_col_pos.push_back(0);
			sum_col_neg.push_back(0);

			sum_col_pos.push_back(0);
			sum_col_neg.push_back(0);

			for (unsigned int j=0; j<lpDim;j++){
				epsilon_row_pos(0, j) = 0;
				epsilon_row_neg(0, j) = 0;
				res_row_with_padding_pos(0,j) = 0;
				res_row_with_padding_neg(0,j) = 0;
			}

			// \eps_pos >= 0 is equiv. to -\eps_pos <= 0
			// \eps_neg >= 0 is equiv. to -\eps_neg <= 0
			epsilon_row_pos(0, N*dim+i*2) = -1;
			epsilon_row_neg(0, N*dim+i*2+1) = -1;
//
			lp_col.push_back(0);
			lp_col.push_back(0);
			lp_coeff_mat.matrix_join(epsilon_row_pos, lp_coeff_mat);
			lp_coeff_mat.matrix_join(epsilon_row_neg, lp_coeff_mat);

			// linear constraint saying that the last ending point is in the bad poly
			for (unsigned int j=0; j<C.size1();j++){
				for (unsigned int k=0; k<C.size2();k++){
					row(0,k) = C(j, k);
				}
				row.multiply(expAt, res_row);
				// padding with 0
				// somehow resize does not padding with 0??
//				res_row.resize(1, lpDim);
				for (unsigned int l=0; l<lpDim; l++){
					if (l>=i*dim && l<(i+1)*dim){
						res_row_with_padding_pos(0,l) += res_row(0, l-i*dim);
						res_row_with_padding_neg(0,l) += -res_row(0, l-i*dim);
					}
				}

				// \eps_pos + \eps_neg = Ax + b
				// we express it as:
				// \eps_pos + \eps_neg <= Ax + b
				// and
				// (\eps_pos + \eps_neg) <= -(Ax + b)
				res_row_with_padding_pos(0, N*dim+i*2) = 1;
				res_row_with_padding_pos(0, N*dim+i*2+1) = -1;

				res_row_with_padding_neg(0, N*dim+i*2) = -1;
				res_row_with_padding_neg(0, N*dim+i*2+1) = 1;

				row.mult_vector(inhomo_term, res_col);

				sum_col_pos[0] += b[j] - res_col[0];
				sum_col_neg[0] += res_col[0] - b[j];
			}

			lp_col.push_back(sum_col_pos[0]);
			lp_coeff_mat.matrix_join(res_row_with_padding_pos, lp_coeff_mat);

			lp_col.push_back(sum_col_neg[0]);
			lp_coeff_mat.matrix_join(res_row_with_padding_neg, lp_coeff_mat);

			// =======================================
			// Adding linear constraints minimizing \inf-norm{R(y[i]) -x[i]}
			// denote inf norm of a vector as |v|_{inf}
			// By definition: |v|_{inf} = max{|vi|} across dimensions
			//
			// |v|_{inf} = max{|vi|}
			// is equiv. to min w
			//              s.t. -w - vi <= 0, for all i
			//                   -w + vi <= 0, for all i
			//                   -w      <= 0
			// See
			// (1) https://optimization.mccormick.northwestern.edu/index.php/Optimization_with_absolute_values
			// (2) http://agecon2.tamu.edu/people/faculty/mccarl-bruce/mccspr/new09.pdf, page 10

			R = Tptr->getAssignT();
			math::matrix<double> mapExpAt(expAt);

//			cout << "checkpoint 1" << endl;

			// - ( R(y_{i,j}) - x_{i+1,j} ) - wi <= 0
			math::matrix<double> res_row_pos = math::matrix<double>(1, lpDim);
			// - ( R(y_{i,j}) - x_{i+1,j} ) - wi <= 0
			math::matrix<double> res_row_neg = math::matrix<double>(1, lpDim);

			std::vector<double> transform;

			R.Map.multiply(expAt,mapExpAt);
			R.Map.mult_vector(inhomo_term, transform);

//			cout << "checkpoint 2" << endl;
			for (unsigned int j=0; j<dim; j++){
//				cout << "checkpoint 3" << endl;
				// reset containers to 0 vectors
				for (unsigned int k = 0; k < lpDim; k++){
					res_row_pos(0, k) = 0;
					res_row_neg(0, k) = 0;
				}

//				cout << "checkpoint 4" << endl;
				for (unsigned int k=0; k<dim; k++){
					//  R(y_{i,j})
					res_row_pos(0,i*dim+k) = mapExpAt(j, k);

					// - R(y_{i,j})
					res_row_neg(0,i*dim+k) = -mapExpAt(j, k);
				}
//				cout << "checkpoint 5" << endl;
				// - x_{i+1,j} - wi
				res_row_pos(0,j+(i+1)*dim) += -1;
//				res_row_pos(0,j+i*dim) = -1;
				res_row_pos(0,N*dim+N*2+i) = -1;

//				cout << "checkpoint 6" << endl;
				// x_{i+1,j} - wi
				res_row_neg(0,j+(i+1)*dim) += 1;
				res_row_neg(0,N*dim+N*2+i) = -1;

//				cout << "checkpoint 8" << endl;
				// pos
				lp_coeff_mat.matrix_join(res_row_pos, lp_coeff_mat);
				lp_col.push_back(-transform[j]-R.b[j]);
//				cout << "Adding " << res_row_pos << endl;
//				cout << "checkpoint 9" << endl;
				// neg
				lp_coeff_mat.matrix_join(res_row_neg, lp_coeff_mat);
				lp_col.push_back(transform[j]+R.b[j]);
//				cout << "Adding " << res_row_neg << endl;
//				cout << "checkpoint 10" << endl;

			}

			// - wi <= 0
//			cout << "checkpoint 7" << endl;
			math::matrix<double> res_row_w = math::matrix<double>(1, lpDim);
			for (unsigned int j=0;j<res_row_w.size2();j++){
				if (j == N*dim+N*2+i){
					res_row_w(0,j) = -1;
				} else {
					res_row_w(0,j) = 0;
				}
			}

//			cout << "Adding \n" << res_row_w << endl;

			// w
			lp_coeff_mat.matrix_join(res_row_w, lp_coeff_mat);
			lp_col.push_back(0);
		}

		T_iter++; // Moving to the next transition.
	}

	int MYLP_EQUALITY_SIGN = 1;
	unsigned int MIN_OR_MAX = 1;
	mylp.setConstraints(lp_coeff_mat, lp_col, MYLP_EQUALITY_SIGN);
	mylp.setMin_Or_Max(MIN_OR_MAX);

	math::vector<double> obj_vec(lpDim, 0);
	for (unsigned int i=N*dim; i<obj_vec.size(); i++){
		obj_vec[i] = 1;
	}

//	double optimal_val = mylp.Compute_LLP(obj_vec);
//	std::vector<double> optimal_point = mylp.get_sv();
//	cout << endl;
//	for (unsigned int i = 0; i < optimal_point.size(); i++){
//		cout << optimal_point[i] << endl;
//	}

	/*   solution status:
	 The routine glp_get_status reports the generic status of the current basic solution for
	 the specified problem object as follows:

	 #define GLP_UNDEF          1  // solution is undefined
	 #define GLP_FEAS           2  // solution is feasible
	 #define GLP_INFEAS         3  // solution is infeasible
	 #define GLP_NOFEAS         4  // no feasible solution exists
	 #define GLP_OPT            5  // solution is optimal
	 #define GLP_UNBND          6  // solution is unbounded
	 */
	if ( mylp.getStatus() == 4 ){
		cout << "\n lp_coeff_mat:" << endl;
		cout << lp_coeff_mat << endl;
	//	cout << "\n lp_col:" << endl;
	//	for (auto i : lp_col){
	//		cout << i << " ";
	//	}
	//	cout << lp_coeff_mat.size1() << endl;
	//	cout << lp_coeff_mat.size2() << endl << endl;
	//
		cout << "\n lp_col:" << endl;
		for (auto i : lp_col){
			cout << i << " ";
		}

		cout << "\n time vars: " << endl;
		for (auto elem : t){
			cout << elem << " ";
		}

		exit(0);
	}

	return mylp;
}


/**
 * Generate concrete trajectory using splicing with NLP problem (Zutchi, Sankaranarayanan's  Idea)
 */
concreteCE::ptr abstractCE::gen_concreteCE_NLP_HA(double tolerance, const std::list<refinement_point>& refinements) {
	//	 Generate an nlopt object with the constraints defined by the Abstract
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
	std::cout << "Number of Transitions in the abstract CE: " << transList.size() << std::endl;
	std::cout << "gen_concreteCE: dimension =" << dim <<", length of CE=" << N << std::endl;

	// initialize the global locIdList
	locIdList.resize(N);

	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
		std::cout << locIdList[i] << " | " ;
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


	for(unsigned int i = 0; i < N; i++) // iterate over the N locations of the counter-example to get the invariant
	{

		if(i==0)// Initial polytope is given, so initialize the constraint polytope on x_0 to be the initial polytope
		{
			P = this->get_first_symbolic_state()->getInitialPolytope();
			// set arbitrarily large but finite time bounds
			lb[N*dim] = 0;
			ub[N*dim] = 999;

		}
		else{

			T = *(trans_iter);
			assert(T!=NULL);

			location::ptr src_loc = HA->getLocation(T->getSource_Location_Id());
			location::ptr dest_loc = HA->getLocation(T->getDestination_Location_Id());


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
			lb[N*dim+i] = 0;
			ub[N*dim+i] = 999;
		}
		//P->printPoly();

		if (P->getIsUniverse())
		{
			// set arbitrarily large but finite bounds on start points
			std::cout << "Constraint polytope is universe\n";
			for (unsigned int j = 0; j < dim; j++){
				unsigned int index = i*dim+j;
				lb[index] = -999;
				ub[index] = 999;
			}
		}
		else{
			lp_solver lp(GLPK_SOLVER);
			lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());

			//we add bound constraints on the position parameters, which are required to run global opt routines.
			std::vector<double> dir(dim,0);
			double min, max;
			for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
			{
				dir[j] = -1;
				try{
					min = -1 * lp.Compute_LLP(dir);
				}catch(...){
					// Assuming that the exception is due to unbounded solution in the min direction
					min = -999; // setting an arbitrary lower bound
				}
				dir[j] = 1;

				try{
					max = lp.Compute_LLP(dir);
				}catch(...){
					// Assuming that the exception is due to unbounded solution in the max direction
					max = 999; // setting an arbitrary upper bound
				}
				unsigned int index = i*dim+j;
				lb[index] = min;
				ub[index] = max;
				x[index] = (lb[index] + ub[index])/2;
				dir[j] = 0;
			}
		}
		// Initialize the dwell-time values to 0
		for(unsigned int i=0;i<N;i++){
			x[N*dim+i] = 0;
		}
		// increment transition iterator
		if(trans_iter!=transList.end() && i!=0) // do not increment trans iteration at the first iteration
			trans_iter++;
	}

	// debug
	std::cout << "The lower bounds are:\n";
	for(unsigned int i=0;i<lb.size();i++)
		std::cout << lb[i] << " ";
	std::cout << "\n";
	std::cout << "The upper bounds are:\n";
	for(unsigned int i=0;i<ub.size();i++)
		std::cout << ub[i] << " ";
	std::cout << "\n";
	//---

	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);

	double minf;
	try {
		std::cout << "Local optimization algorithm called:" << myopt.get_algorithm_name() << std::endl;
		myopt.set_stopval(tolerance);
		unsigned int res = myopt.optimize(x, minf);
		if(res==NLOPT_SUCCESS)
			std::cout << "Splicing WoFC: NLOPT stopped successfully returning the found minimum\n";
		else if(res == NLOPT_STOPVAL_REACHED)
			std::cout << "Splicing WoFC: NLOPT stopped due to stopping value (1e-6) reached\n";
		else if (res == NLOPT_MAXEVAL_REACHED)
			std::cout << "Splicing WoFC: NLOPT stopped due to reaching maxeval = " << maxeval << std::endl;


	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "nlopt returned min : " << minf << "\n";
	std::cout << "Length of abstract counter example:" << N <<"\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance << ", with no. of refined search:" << refinements.size() << std::endl;
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

concreteCE::ptr abstractCE::get_validated_CE(double tolerance, unsigned int algo_type)
{
	// call to genCE func with no refining trajectory
	std::list<struct refinement_point> refinements;
	refinements.clear(); // No refinement point initially

	concreteCE::ptr cexample;
	bool val_res=true;
	unsigned int max_refinements = 3, ref_count = 0; // maximum limit to refinement points to be added.

	double valid_tol = 1e-6; // validation error tolerance, on invariant crossing. @Amit changed 1e-3 to 1e-6

	do{
		struct refinement_point pt;

		if(algo_type == 1) // FC called
			cexample = gen_concreteCE(tolerance,refinements);
		else if(algo_type==2){ // WoFC called
			cexample = gen_concreteCE_NLP_HA(tolerance,refinements);
		}
		else if (algo_type == 3)	//std::cout << "LP-NLP mixed implementation not in place yet\n";
			cexample = gen_concreteCE_iterative(tolerance, refinements);
		else if (algo_type == 4)
			cexample = gen_concreteCE_NLP_LP(tolerance, refinements);
		else if (algo_type == 5)
			cexample = gen_concreteCE_NLP_LP_softconstr(tolerance, refinements);
		else {
			std::cout << "Invalid algo type specified for trajectory splicing\n";
		}

		if(cexample->is_empty()){
			cexample->set_refinement_count(ref_count);
			return cexample;
		}

		val_res = cexample->valid(pt,valid_tol);
		//putting off validation loop by refinements
		//val_res = true;
		//--

		if(!val_res){
			refinements.push_back(pt);
			ref_count++;
			//debug: print the invalid trajectory in a file, in the first two dimensions
			cexample->plot_ce("./invalid_traj.txt",0,1);
		}
		else{
			std::cout << "Generated Trace Validated with "<< ref_count << " point Refinements\n";
			cexample->set_refinement_count(ref_count);
			return cexample;
		}
		std::cout << "Restarting Search with added refinement point\n";
	}while(!val_res && ref_count< max_refinements);

	throw std::runtime_error("Validation of counter example FAILED after MAX Refinements\n");
	return concreteCE::ptr(new concreteCE());
}


concreteCE::ptr abstractCE::search_concreteCE(double tolerance, std::list<abstractCE::ptr> paths, std::vector<unsigned int> path_filter, unsigned int algo_type)
{

	concreteCE::ptr ce;
	abstractCE::ptr abs_ce;

	bool real_ce = false;
	double error_tol = tolerance; // splicing error tolerance

	for (std::list<abstractCE::ptr>::iterator it = paths.begin(); it!=paths.end();it++) {

		abs_ce = *(it);
		// add a filter function to search for concrete ce only in a specific abstract trace

		bool search_ce = abs_ce->filter(path_filter);

		if(search_ce){
			ce = abs_ce->get_validated_CE(error_tol,algo_type);
			if(ce->is_empty()){
				std::cout << "Cannot splice trajectory segments with the accepted error tolerance\n";
			}
			else{
				real_ce = true;
				break;
			}
		}
	}
	if(real_ce)
		return ce;
	else{
		ce = concreteCE::ptr(new concreteCE());
		return ce;
	}
}
