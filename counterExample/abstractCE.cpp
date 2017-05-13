/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include "counterExample/abstractCE.h"
#include "counterExample/simulation.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "Utilities/gradient.h"
#include "core_system/math/analyticODESol.h"
#include "InputOutput/io_utility.h"
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
	//Assertion to check that the length of the counter-example is one minus
	// the number of sym states in the CE.
	assert(sym_states.size() == trans.size() - 1);
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

	// length must match the template sequence length
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
	dim = S->getContinuousSetptr()->get_dimension();
	N = get_length(); // the length of the counter example
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	bad_poly = this->forbid_poly;
	ref_pts = refinements;


	//assert that the number of transitions equals 1 less than the length of the abstract CE path

	std::cout << "Length of the CE, N=" << N << std::endl;
	assert(transList.size() == N-1);
	std::cout << "gen_concreteCE: dimension =" << dim <<", length of CE=" << N << std::endl;
	// initialize the global locIdList
	locIdList.resize(N);
      
	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		assert(d.size() == 1);
		locIdList[i] = *(d.begin());
	}

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
	myopt.set_min_objective(myobjfunc2, NULL);
	myopt.set_maxeval(4000);
	myopt.set_stopval(1e-6);
	//myopt.set_initial_step(0.001);

	//Set Initial value to the optimization problem
	std::vector<double> x(optD, 0);
	polytope::ptr P;

// A random objective function created for lp solving

	std::vector<double> v(dim);

	std::vector<double> lb(optD), ub(optD);
	double max,min,start_min,start_max;

	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		S = get_symbolic_state(i);
		P = S->getInitialPolytope();
		//debug--
//		if(i==0)
//			P->print2file("./symb_state0.txt", 9, 0);
//		else
//			P->print2file("./symb_state1.txt", 9, 0);
		//--
		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());

// 		we add bound constraints on the position parameters, which are required to run global opt routines.
		std::vector<double> dir(dim,0);
		double min, max;
		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			dir[j] = -1;
			min = -1 * lp.Compute_LLP(dir);
			dir[j] = 1;
			max = lp.Compute_LLP(dir);
			unsigned int index = i*dim+j;
			if(min>max) // swap min and max
			{
				min = min+max;
				max = min-max;
				min = min-max;
			}
			lb[index] = min;
			ub[index] = max;

			dir[j] = 0;
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

bool aggregation=true;//default is ON

	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		if(i==N-1){
			// If last abst sym state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(aggregation,bad_poly,1);
			assert(polys.size()>=0); // The last sym state of an abstract CE must intersect with the bad set

			if(polys.size()>1)
				P = get_template_hull(S->getContinuousSetptr(),0,S->getContinuousSetptr()->getTotalIterations()-1); // 100% clustering
			else
				P = polys.front();

			P = P->GetPolytope_Intersection(bad_poly);
		}
		else{
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
		}

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());
		// ensure that time is always positive
		max = lp.Compute_LLP(dmax);
		min = -1 * lp.Compute_LLP(dmin);

		// we add the bounds as constraints in the nlopt

		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		P=S->getInitialPolytope();
		lp1.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
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


	std::cout << "Computed initial dwell times and added dwell time constraints\n";

	double minf;
	try {
		std::cout << "Local optimization algorithm called:" << myopt.get_algorithm_name() << std::endl;
		myopt.set_stopval(tolerance);
		myopt.optimize(x, minf);
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
//	assert((t_index >= 0) && (t_index < dim));
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
////		solve the lp. The solution point is taken as an initial value.
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
//		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
//		// We may choose to take the max-min as the initial dwell time
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
//
///**
// * Generate concrete trajectory using splicing with NLP problem (Zutchi, Sankaranarayanan's  Idea)
// */
//
//concreteCE::ptr abstractCE::gen_concreteCE_NLP_HA(double tolerance, const std::list<refinement_point>& refinements) {
////	 Generate an nlopt object with the constraints defined by the Abstract
////	 counter example
//
//
////	 1. Get the dimension of the optimization problem by
////	 getting the dimension of the continuous set of the abstract counter example
//
//
//	symbolic_states::const_ptr S = get_first_symbolic_state();
//	dim = S->getContinuousSetptr()->get_dimension();
//	N = get_length(); // the length of the counter example
//	HA = this->get_automaton();
//	transList = this->get_CE_transitions();
//	bad_poly = this->forbid_poly;
//	ref_pts = refinements;
//
//	std::cout << "gen_concreteCE_NLP_HA: dimension =" << dim <<", length of CE=" << N << std::endl;
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
////	 2. The dimensionality of the opt problem is N vectors, one starting point
////	 for each of the abstract sym state of the CE + N dwell times. Moreover,
////	 each starting vector is of dimension dim. Therefore, the total number of
////	 variables of the optimization problem are dim*N + N
//
//	unsigned int optD = N * dim + N;
//	std::cout << "nlopt problem dimension = " << optD << std::endl;
////	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free
////	nlopt::opt myopt(nlopt::LN_AUGLAG_EQ, optD); // derivative free
////	nlopt::opt myopt(nlopt::LN_AUGLAG, optD); // derivative free
////	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based
//	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative bases
//
//	myopt.set_maxeval(4000);
//	myopt.set_stopval(1e-3);
//
////	myopt.set_xtol_rel(1e-4);
//
//	myopt.set_min_objective(myobjfunc1, NULL);
//	//myopt.set_initial_step(0.001);
//
//	//Set Initial value to the optimization problem
//	std::vector<double> x(optD, 0);
//	polytope::ptr P;
//
//// A random objective function created for lp solving
//
//	std::vector<double> obj(dim, 0);
//	obj[0] = 1;
//	std::vector<double> v(dim);
//
//	std::list<transition::ptr>::iterator it = transList.begin();
//	transition::ptr T;
//	unsigned int size=0;
//	// calculate the total constraints in all polytopes.
//	polytope::ptr PList[N];
//	for(unsigned int i=0;i<N;i++){
//		if(i==0){
//			PList[i] = get_symbolic_state(i)->getInitialPolytope();
//			size += PList[i]->getCoeffMatrix().size1();
//		}
//		else{
//			int locId = locIdList[i];
//			P = HA->getLocation(locId)->getInvariant();
////			T = *(it);
////			P=P->GetPolytope_Intersection(T->getGaurd());
//			size += P->getCoeffMatrix().size1();
//			PList[i] = P;
//			it++;
//		}
//	}
//	polyConstraints I[size];
//	unsigned int index = 0;
//
//	math::matrix<double> A;
//	std::vector<double> b;
//
//	for (unsigned int i = 0; i < N; i++) // iterate over the N invariants of the counter-example
//	{
//
//		P = PList[i];
//		A = P->getCoeffMatrix();
//		b = P->getColumnVector();
//
//// 		We assume that the polytope is expressed as Ax<=b
//
//		assert(P->getInEqualitySign() == 1);
//		assert(A.size2() == dim);
//		assert(b.size() == A.size1());
//		assert(size > index);
//
//		for (unsigned int j = 0; j < A.size1(); j++) {
//			I[index].sstate_index = i;
//			I[index].a.resize(A.size2());
//
//			for(unsigned int k=0;k<dim;k++){
//				I[index].a[k] = A(j,k);
//			}
//			I[index].b = b[j];
//			myopt.add_inequality_constraint(myconstraint, &I[index], 1e-8);
//			index++;
//		}
//
//		lp_solver lp(GLPK_SOLVER);
//		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
//				P->getInEqualitySign());
//		lp.Compute_LLP(obj);
//		v = lp.get_sv();
//
//		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
//		{
//			x[i * dim + j] = v[j];
//		}
//	}
//	// adding constraints over start points
//	assert(index==size);
//
//	double minf;
//	try {
//
//		nlopt::result result = myopt.optimize(x, minf);
//		if (result < 0)
//			throw "abstractCE: gen_concreteCE: NLOpt failed\n";
//
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//	std::cout << "nlopt returned min : " << minf << "\n";
//	std::cout << "Length of abstract counter example:" << N <<"\n";
//
//	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
//	cexample->set_automaton(HA);
//	if (minf > tolerance) {
//		std::cout << "Obtained minimum greater than " << tolerance << std::endl;
//		return cexample;
//	} else {
//
//		// one trajectory per symbolic state to be added in the concreteCE
//		for (unsigned int i = 0; i < N; i++) {
//			// create the sample
//			concreteCE::sample s;
//			std::set<int>::iterator dset_iter =
//					get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
//			unsigned int locId = *dset_iter;
//
//			std::vector<double> y(dim);
//			for (unsigned int j = 0; j < dim; j++) {
//				y[j] = x[i * dim + j];
//			}
//
//			double time = x[N * dim + i];
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

concreteCE::ptr abstractCE::get_validated_CE(double tolerance)
{
	// call to genCE func with no refining trajectory
	std::list<struct refinement_point> refinements;
	refinements.clear(); // No refinement point initially

	concreteCE::ptr cexample;
	bool val_res=true;
	bool NLP_HA_algo_flag = false;
	unsigned int max_refinements = 100, ref_count = 0; // maximum limit to refinement points to be added.
	do{
		struct refinement_point pt;

		//cexample = gen_concreteCE_NLP_HA(tolerance,refinements); NLP_HA_algo_flag = true;
		cexample = gen_concreteCE(tolerance,refinements);
		//cexample = gen_concreteCE_NLP_LP(tolerance,refinements);
		if(cexample->is_empty())
			return cexample;

		val_res = cexample->valid(pt,tolerance);

		if(!val_res){
			if(NLP_HA_algo_flag){
				std::cout << "Splice Trace NOT VALID\n";
				return cexample = concreteCE::ptr(new concreteCE());
			}
			refinements.push_back(pt);
			ref_count++;
		}
		else{
			std::cout << "Generated Trace Validated with "<< ref_count << " point Refinements\n";
			return cexample;
		}
	}while(!val_res && ref_count< max_refinements);

//	throw std::runtime_error("Validation of counter example FAILED even after MAX Refinements\n");
	return concreteCE::ptr(new concreteCE());
}
