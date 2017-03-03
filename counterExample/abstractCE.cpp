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
#include <string>

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
	std::cout << "#Transitions in CE" << transList.size() << std::endl;
	assert(transList.size() == N-1);
	std::cout << "gen_concreteCE: dimension =" << dim <<", length of CE=" << N << std::endl;
	// initialize the global locIdList
	locIdList.resize(N);
      
	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		locIdList[i] = *(d.begin());
	}

	//assert that the number of transitions equals 1 less than the length of the abstract CE path

	std::cout << "Length of the CE, N=" << N << std::endl;
	std::cout << "#Transitions in CE" << transList.size() << std::endl;
	assert(transList.size() == N-1);
	std::cout << "gen_concreteCE: dimension =" << dim <<", length of CE=" << N << std::endl;
// 	initialize the global locIdList


//	 2. The dimensionality of the opt problem is N vectors, one starting point
//	 for each of the abstract sym state of the CE + N dwell times. Moreover,
//	 each starting vector is of dimension dim. Therefore, the total number of
//	 variables of the optimization problem are dim*N + N

	unsigned int optD = N * dim + N;
	std::cout << "nlopt problem dimension = " << optD << std::endl;
//	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free
//	nlopt::opt myopt(nlopt::LN_AUGLAG_EQ, optD); // derivative free
//	nlopt::opt myopt(nlopt::LN_AUGLAG, optD); // derivative free
	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based
//	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative based
//	nlopt::opt myopt(nlopt::GN_ISRES,optD); // derivative free global

	// 	local optimization routine
//	nlopt::opt myopt_local(nlopt::LD_SLSQP, optD); // derivative based local
	myopt.set_min_objective(myobjfunc2, NULL);
	myopt.set_maxeval(2000);
	myopt.set_stopval(1e-6);
	//myopt.set_initial_step(0.001);

	//Set Initial value to the optimization problem
	std::vector<double> x(optD, 0);
	polytope::ptr P;

// A random objective function created for lp solving

	std::vector<double> obj(dim, 0);
	obj[0] = 1;
	std::vector<double> v(dim);

	std::vector<double> lb(optD), ub(optD);

	for (unsigned int i = 0; i < N; i++) // iterate over the N flowpipes of the counter-example
	{
		S = get_symbolic_state(i);
		P = S->getInitialPolytope();
//		To get a point from the polytope, we create a random lp obj function and
//		solve the lp. The solution point is taken as an initial value.

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());

		// we add bound constraints on the position parameters, which are required to run global opt routines.
		std::vector<double> dir(dim,0);
		double min, max;
		for (unsigned int j = 0; j < dim; j++) // iterate over each component of the x_i start point vector
		{
			dir[j] = -1;
			min = -1 * lp.Compute_LLP(dir);
			dir[j] = 1;
			max = lp.Compute_LLP(dir);
			unsigned int index = i*dim+j;
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

	//debug--
	std::ofstream tracefile;
	tracefile.open("./ceTrace.o");
	//-----

	std::list<transition::ptr>::iterator it = transList.begin();
	transition::ptr T;

	double max,min,start_min,start_max;

	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		if(i==N-1){
			// If last abst sym state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(bad_poly,1);
			if(polys.size()>1)
				P = convertBounding_Box(S->getContinuousSetptr());
			else
				P=polys.front();
			P = P->GetPolytope_Intersection(bad_poly);
		}
		else{
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGaurd();
			if(guard->getIsUniverse())
				std::cout << "#Guard is Universe#\n" << std::endl;

			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(guard,1);
			if(polys.size()>1)
				P = convertBounding_Box(S->getContinuousSetptr());
			else
				P=polys.front();

		}

//		To get a point from the polytope, we create a random obj function and
//		solve the lp. The solution point is taken as an initial value.

		// When flowpipe intersects the guard only at more than one place, take a bounding box approx of the flowpipe and project time
		//debug
//		math::matrix<double> vertices_list;
//		vertices_list = P->get_2dVertices(0, 10);
//		std::cout << "Number of vertices of the polytope: " << vertices_list.size1() << std::endl;
//
//		// ------------- Printing the vertices on the Output File -------------
//		for (unsigned int p = 0; p < vertices_list.size1(); p++) {
//			for (unsigned int q = 0; q < vertices_list.size2(); q++) {
//				tracefile << vertices_list(p, q) << " ";
//			}
//			tracefile << std::endl;
//		}
//		tracefile << std::endl; // 1 gap after each polytope plotted

		//----

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
	tracefile.close();

	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);


	std::cout << "Computed initial dwell times and added dwell time constraints\n";

//	Constraints over C_i added to the optimization problem

//	polytope::ptr C[N];
//	math::matrix<double> A;
//	std::vector<double> b;
//
//
//	polytope::ptr Inv;
//	unsigned int size=0;
//	for(unsigned int i=0;i<N;i++){
////		Inv = HA->getLocation(locIdList[i])->getInvariant();
//		C[i] = get_symbolic_state(i)->getInitialPolytope();
////		C[i] = C[i]->GetPolytope_Intersection(Inv);
//		size += C[i]->getCoeffMatrix().size1();
//	}
//	polyConstraints I[size];
//	unsigned int index = 0;
//
//	for (unsigned int i = 0; i < N; i++) {
//		A = C[i]->getCoeffMatrix();
//		b = C[i]->getColumnVector();
//
//// 		We assume that the polytope is expressed as Ax<=b
//
//		assert(C[i]->getInEqualitySign() == 1);
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
//	}
//	assert(index==size);
//	std::cout << "added constraints on starting point of each trajectory segment.\n";
// 	todo: Constraints over dwell time to be added


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
//	std::cout << "Number of samples by NLopt: " << samples << "\n";

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance << std::endl;
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
//	// adding time constraints
///*	boundConstraint B[N],B1[N];
//	for (unsigned int i = 0; i < N; i++) {
//
//		B[i].var_index = N*dim + i;
//		B[i].bound = 100;
//		B[i].is_ge = false;
//		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
//		B1[i].var_index = B[i].var_index;
//		B1[i].is_ge=true;
//		B1[i].bound = 0;
//		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
//		// We may choose to take the max-min as the initial dwell time
//		x[N * dim + i] = 0.1;
//	} */
////// TEST CODE
////	unsigned int t_index =
////		get_first_symbolic_state()->getContinuousSet()->get_index("t");
////
////	assert((t_index >= 0) && (t_index < dim));
////
////	boundConstraint B[N],B1[N];
////	std::vector<double> dmin(dim, 0), dmax(dim, 0);
////	dmax[t_index] = 1;
////	dmin[t_index] = -1;
////	it = transList.begin();
//////	transition::ptr T;
////	double max,min,start_min;
////	for (unsigned int i = 0; i < N; i++) {
////		S = get_symbolic_state(i);
////		P = S->getContinuousSet();
////		if(i==N-1){
////			// If last abst sym state, then take time projection of flowpipe \cap bad_poly
////			P=P->GetPolytope_Intersection(bad_poly);
//////			std::ofstream myfile;
//////			myfile.open("./polyBad");
//////			P->print2file("./polyBad",0,1);
////		}
////		else{
////			// Take time projection of flowpipe \cap transition guard
////			T = *(it);
////			P=P->GetPolytope_Intersection(T->getGaurd());
////		}
//////		To get a point from the polytope, we create a random obj function and
//////		solve the lp. The solution point is taken as an initial value.
////
////		lp_solver lp(GLPK_SOLVER);
////		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
////				P->getInEqualitySign());
////		max = lp.Compute_LLP(dmax);
////		min = -1 * lp.Compute_LLP(dmin);
////		// we add the bounds as constraints in the nlopt
////
////		// Get the min and max time projection of start set
////		lp_solver lp1(GLPK_SOLVER);
////		P=S->getInitialSet();
////		lp1.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
////				P->getInEqualitySign());
////
////		start_min = -1 * lp1.Compute_LLP(dmin);
////
////		B[i].var_index = N*dim + i;
////		B[i].bound = max - start_min;
////		B[i].is_ge = false;
////		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
////		B1[i].var_index = B[i].var_index;
////		B1[i].is_ge=true;
////		B1[i].bound = min-start_min;
////		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
////		// We may choose to take the max-min as the initial dwell time
////		x[N * dim + i] = (max -start_min + min - start_min)/2;
////		if(it!=transList.end())
////			it++;
////
////	}
//
////---------------
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
	unsigned int max_refinements = 100, ref_count = 100; // maximum limit to refinement points to be added.
	do{
		struct refinement_point pt;

		//cexample = gen_concreteCE_NLP_HA(tolerance,refinements); NLP_HA_algo_flag = true;
		cexample = gen_concreteCE(tolerance,refinements);
		//cexample = gen_concreteCE_NLP_LP(tolerance,refinements);
		if(cexample->is_empty())
			return cexample;

		val_res = cexample->valid(pt);

		if(!val_res){
			std::cout << "FAILED VALIDATION\n";
			break;
			if(NLP_HA_algo_flag){
				std::cout << "Splice Trace NOT VALID\n";
				return cexample = concreteCE::ptr(new concreteCE());
			}
//			refinements.push_back(pt);
//			ref_count++;
		}
		//debug
//		break;
	}while(!val_res && ref_count< max_refinements);

	if((ref_count < max_refinements) & !cexample->is_empty()){
		std::cout << "Generated Trace Validated with "<< ref_count << " point Refinements\n";
		return cexample;
	}
	else {
//		throw std::runtime_error("Validation of counter example FAILED even after MAX Refinements\n");
		return concreteCE::ptr(new concreteCE());
	}
}
