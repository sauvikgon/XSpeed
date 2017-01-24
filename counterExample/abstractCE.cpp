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

/**
 * Returns 0 if the arguments is negative. returns the same arguments if the argument is positive
 */
double positive(double time)
{
	if(time<0){
		std::cout << "negative time converted to positive\n";
		return 0;
	}
	else
		return time;
}
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

/*  Handmade objection function
*
* @ Rajarshi
*/

/**
 * Handmade concrete gen function for testing
 * @Rajarshi
 * 21st Jan 2017
 */


double myobjfunc_handmade(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) {

	std::list<transition::ptr>::iterator T_iter = transList.begin();
	transition::ptr Tptr = *(T_iter);
	assert(transList.size() == N-1);

	std::vector<std::vector<double> > y(N);
	double cost = 0;
	for (unsigned int i = 0; i < N; i++) {

		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}

		int loc_index = locIdList[i];
		Dynamics d = HA->getLocation(loc_index)->getSystem_Dynamics();

		assert(d.C.size() == dim);

		y[i] = ODESol(v,d,x[N*dim + i]);
		// apply transition assignment map
		if(i==N-1)
			break;
		else { // find the distance on this end point with the next start point
			polytope::ptr g;
			Assign R;
			// assignment of the form: Rx + w

			R = Tptr->getAssignT();
			//guard as a polytope
			// This matrix is require to compute the derivative
			g = Tptr->getGaurd();

			// If traj end point inside guard, then apply map.
////			double guard_dist = g->point_distance(y[i]);
////			if(guard_dist == 0)
//			{
	//			std::cout << "Inside g condition\n";
				assert(y[i].size() == R.Map.size2());
				std::vector<double> transform(y[i].size(),0);
				R.Map.mult_vector(y[i],transform);
				// add vectors
				assert(y[i].size() == R.b.size());
				for(unsigned int j=0;j<transform.size();j++)
					y[i][j] = transform[j] + R.b[j];
//			}
//			else{
	//			cost += g->point_distance(y[i]);
	//			grad_gt = dist_grad(y[i],I,Axplusb);
	//			grad_gx = dist_grad(y[i],I,diag_expAt);

//			}
			if(T_iter!=transList.end())
				T_iter++;
			for(unsigned int j=0;j<dim;j++){
				cost += (y[i][j] - x[(i+1)*dim + j]) * (y[i][j] - x[(i+1)*dim + j]);
			}
//			//debug print
//			std::cout << "trace end point:\n";
//			for(unsigned int j=0;j<dim;j++){
//				std::cout << y[i][j] << " ";
//			}
//			std::cout << "Next start point:\n";
//			for(unsigned int j=0;j<dim;j++){
//				std::cout << x[(i+1)*dim + j] << " ";
//			}
//			std::cout << "\n";
		}
	}
	// compute the distance of this endpoint with the forbidden polytope
	cost += bad_poly->point_distance(y[N-1]);
	std::cout << "cost = " << cost  << std::endl;
	return cost;

}

concreteCE::ptr gen_concreteHandmade(double tolerance, const std::list<refinement_point>& refinements) {

	unsigned int optD = N * dim + N;
	std::cout << "nlopt problem dimension = " << optD << std::endl;

// 	local optimization routine
//	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative based local
	nlopt::opt myopt(nlopt::LN_COBYLA, optD);
	myopt.set_min_objective(myobjfunc_handmade, NULL);
//	myopt.set_min_objective(myobjfunc2, NULL);
//	myopt.set_maxeval(4000);
	myopt.set_stopval(0.0019);
	//myopt.set_initial_step(0.001);

	std::vector<double> x(optD,0);
	// Assume N = 10;
	std::cout << " TEST function: N = " << N << std::endl;
	assert(N==9);

//	std::vector<double> lb(optD,0), ub(optD,0);
//	lb[0]=20; lb[3]=0; lb[6]=0; lb[9]=0; lb[12]=0; lb[15]=0; lb[18]=0; lb[21]=0; lb[24]=0; lb[27]=0;
//	lb[1]=0; lb[4]=5; lb[7]=5; lb[10]=4; lb[13]=4; lb[16]=3; lb[19]=3; lb[22]=3; lb[25]=2; lb[28]=2;
//	lb[2]=0; lb[5]=6;lb[8]=17;lb[11]=27; lb[14]=37; lb[17]=45; lb[20]=52; lb[23]=59; lb[26]=65; lb[29]=70;
//
//	ub[0]=20.2; ub[3]=0; ub[6]=0; ub[9]=0; ub[12]=0; ub[15]=0; ub[18]=0; ub[21]=0; ub[24]=0; ub[27]=0;
//	ub[1]=0; ub[4]=6; ub[7]=6; ub[10]=5; ub[13]=5; ub[16]=4; ub[19]=4; ub[22]=4; ub[25]=4; ub[28]=3;
//	ub[2]=0; ub[5]=7;ub[8]=18;ub[11]=28; ub[14]=38; ub[17]=46; ub[20]=53; ub[23]=60; ub[26]=66; ub[29]=72;
//
//	lb[30]=6; lb[31]=10; lb[32]=9; lb[33]=9; lb[34]=7; lb[35] = 6; lb[36]= 6; lb[37]= 5 ; lb[38]=4; lb[39]=3;
//	ub[30]=7; ub[31]=12; ub[32]=11; ub[33]=11; ub[34]=9; ub[35]= 8; ub[36]= 8; ub[37]= 7; ub[38]=7; ub[39]=10;

	std::vector<double> lb(optD,0), ub(optD,0);
	lb[0]=20; lb[3]=0; lb[6]=0; lb[9]=0; lb[12]=0; lb[15]=0; lb[18]=0; lb[21]=0; lb[24]= 0;
	lb[1]=0; lb[4]=5; lb[7]=5; lb[10]=4; lb[13]=4; lb[16]=3; lb[19]=3; lb[22]=2; lb[25]= 2;
	lb[2]=0; lb[5]=6;lb[8]=17;lb[11]=27; lb[14]=37; lb[17]=45; lb[20]=52; lb[23]=59; lb[26]= 65;

	ub[0]=20.2; ub[3]=0; ub[6]=0; ub[9]=0; ub[12]=0; ub[15]=0; ub[18]=0; ub[21]=0; ub[24] =0;
	ub[1]=0; ub[4]=6; ub[7]=6; ub[10]=5; ub[13]=5; ub[16]=4; ub[19]=4; ub[22] = 4; ub[25] = 4;
	ub[2]=0; ub[5]=7;ub[8]=18;ub[11]=28; ub[14]=38; ub[17]=46; ub[20]=53; ub[23] = 60; ub[26]= 66;

	lb[27]=6; lb[28]=10; lb[29]=9; lb[30]=9; lb[31]=7; lb[32]= 6; lb[33] = 6; lb[34] = 5; lb[35]= 2;
	ub[27]=7; ub[28]=12; ub[29]=11; ub[30]=11; ub[31]=9; ub[32]= 8; ub[33] = 8 ; ub[34] = 7;ub[35]= 3;

	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);

	//Set Initial value to the optimization problem
	for(unsigned int i=0;i<optD;i++)
	{
		x[i] = lb[i];
	}


	double minf;
	nlopt::result result = myopt.optimize(x, minf);

	concreteCE::ptr cexample = concreteCE::ptr(new concreteCE());
	cexample->set_automaton(HA);
	if (minf > tolerance) {
		std::cout << "Obtained minimum greater than " << tolerance << std::endl;
		return cexample;
	} else {

		// one trajectory per symbolic state to be added in the concreteCE
		// Assumption: X0 contains the start points of the trajectory segments returned by NLOPT
		for (unsigned int i = 1; i < N; i++) {
			// one trajectory per symbolic state to be added in the concreteCE
			for (unsigned int i = 0; i < N; i++) {
				// create the sample
				concreteCE::sample s;
				unsigned int locId = 1;

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
	}

	return cexample;

}
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
		// initialize the global locIdList

	// temporary debug code: to check NLOPT-------------

	if(N!=9)
		return concreteCE::ptr(new concreteCE());

	return gen_concreteHandmade(tolerance, refinements);

	//-----------end of temporary debug code-------------


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
//	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative based
//	nlopt::opt myopt(nlopt::GN_ISRES,optD); // derivative free global
	nlopt::opt myopt(nlopt::GN_ORIG_DIRECT,optD); // derivative free global

	myopt.set_maxeval(4000);
	double global_tolerance = 1e-2;

	myopt.set_stopval(global_tolerance);
//	myopt.set_ftol_abs(1e-15);

	myopt.set_min_objective(myobjfunc2, NULL);


// 	local optimization routine
	nlopt::opt myopt_local(nlopt::LD_SLSQP, optD); // derivative based local
	myopt_local.set_min_objective(myobjfunc2, NULL);
	myopt_local.set_maxeval(4000);
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
//		To get a point from the polytope, we create a random obj function and
//		solve the lp. The solution point is taken as an initial value.

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
//		lp.Compute_LLP(obj);
//		v = lp.get_sv();

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

	boundConstraint B[N],B1[N];


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
		else {
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

			if(!guard->getIsEmpty())
				P=P->GetPolytope_Intersection(guard);

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
		max = positive(lp.Compute_LLP(dmax));
		min = positive(-1 * lp.Compute_LLP(dmin));

		// we add the bounds as constraints in the nlopt

		// Get the min and max time projection of start set
		lp_solver lp1(GLPK_SOLVER);
		P=S->getInitialPolytope();
		lp1.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		// Ensure that the time is positive
		start_min = positive(-1 * lp1.Compute_LLP(dmin));
		start_max = positive(lp1.Compute_LLP(dmax));

		B[i].var_index = N*dim + i;
		B[i].bound = max - start_min;
		B[i].is_ge = false;
		ub[N*dim+i] = B[i].bound;
		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
		myopt_local.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
		B1[i].var_index = B[i].var_index;
		B1[i].is_ge=true;
		if(min<=start_max)
			B1[i].bound = 0;
		else
			B1[i].bound = min-start_max;
		lb[N*dim+i] = B1[i].bound;

		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
		myopt_local.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
		// We may choose to take the max-min as the initial dwell time
		x[N * dim + i] = (B[i].bound + B1[i].bound)/2;

		if(it!=transList.end())
			it++;

	}
	tracefile.close();

	// setting bounds on the parameters
//	std::cout << "Elements of lower and the upper bounds\n";
//	for(unsigned int k=0;k<lb.size();k++)
//	{
//		std::cout  << lb[k] << " ";
//		assert(lb[k] <= ub[k]);
//	}
//	std::cout << "\n";
//	for(unsigned int k=0;k<ub.size();k++)
//	{
//		std::cout  << ub[k] << " ";
//	}
//	std::cout << "\n";

	myopt.set_lower_bounds(lb);
	myopt.set_upper_bounds(ub);

	myopt_local.set_lower_bounds(lb);
	myopt_local.set_upper_bounds(ub);


	std::cout << "Computed initial dwell times and added constraints over them\n";

//	Constraints over C_i added to the optimization problem

	polytope::ptr C[N];
	math::matrix<double> A;
	std::vector<double> b;


	polytope::ptr Inv;
	unsigned int size=0;
	for(unsigned int i=0;i<N;i++){
//		Inv = HA->getLocation(locIdList[i])->getInvariant();
		C[i] = get_symbolic_state(i)->getInitialPolytope();
//		C[i] = C[i]->GetPolytope_Intersection(Inv);
		size += C[i]->getCoeffMatrix().size1();
	}
	polyConstraints I[size];
	unsigned int index = 0;

	for (unsigned int i = 0; i < N; i++) {
		A = C[i]->getCoeffMatrix();
		b = C[i]->getColumnVector();

// 		We assume that the polytope is expressed as Ax<=b

		assert(C[i]->getInEqualitySign() == 1);
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
			myopt_local.add_inequality_constraint(myconstraint, &I[index], 1e-8);
			index++;
		}
	}
	assert(index==size);
//	std::cout << "added constraints on starting point of each slice to the nlopt solver\n";
// 	todo: Constraints over dwell time to be added


	double minf;
	try {

		nlopt::result result = myopt.optimize(x, minf);
		if (result < 0)
			throw "abstractCE: gen_concreteCE: NLOpt failed\n";
//		 global optimization complete
		if(minf < global_tolerance){
			std::cout << "Global optimization successful, returned min: " << minf << std::endl;
			std::cout << "Local optimization algorithm called:" << myopt_local.get_algorithm_name() << std::endl;
			myopt_local.set_stopval(tolerance);
			myopt_local.optimize(x, minf);
			// Another alternative: Call the optimizer only on the position parameters.
			// Fix the dwell times returned by the first call to the optimizer.

		}

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
concreteCE::ptr abstractCE::gen_concreteCE_NLP_LP(double tolerance, const std::list<refinement_point>& refinements) {

	symbolic_states::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSetptr()->get_dimension();
	N = get_length(); // the length of the counter example
	HA = this->get_automaton();
	transList = this->get_CE_transitions();
	bad_poly = this->forbid_poly;
	ref_pts = refinements;
	ce_sym_states = this->get_CE_sym_states();
	X0 = std::vector<std::vector<double> >(N);

	std::cout << "gen_concreteCE_NLP_LP: dimension =" << dim <<", length of CE=" << N << std::endl;
	// initialize the global locIdList
	locIdList.resize(N);


	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		locIdList[i] = *(d.begin());
//		std::cout << "printing loc ids:" << locIdList[i] << " " << std::endl;
	}


//	 The dimensionality of the NLP opt problem is N dwell times.

	unsigned int optD = N;
	std::cout << "nlopt problem dimension = " << optD << std::endl;

	// choose the type of NLOPT solver
//	nlopt::opt myopt(nlopt::LD_SLSQP, optD); // derivative based
	nlopt::opt myopt(nlopt::LN_COBYLA,optD); // derivative free method

	myopt.set_maxeval(5000);
	myopt.set_stopval(1e-6);

//	myopt.set_xtol_rel(1e-4);

	myopt.set_min_objective(myobjfunc3, NULL);
	//myopt.set_initial_step(0.001);

	//Set Initial value to the optimization problem
	std::vector<double> x(optD, 0);
	polytope::ptr P;

//	We assume that the time variable is named as 't' in the model.
//	We find out the min,max components of the time variable

	unsigned int t_index = get_first_symbolic_state()->getInitialPolytope()->get_index("t");

	assert((t_index >= 0) && (t_index < dim));

	std::vector<double> dmin(dim, 0), dmax(dim, 0);
	dmax[t_index] = 1;
	dmin[t_index] = -1;

	boundConstraint B[N],B1[N];

	std::list<transition::ptr>::iterator it = transList.begin();
	transition::ptr T;

	std::list<polytope::ptr> polys;
	polytope::ptr guard;

	double max,min,start_min;
	for (unsigned int i = 0; i < N; i++) {
		S = get_symbolic_state(i);
		if(i==N-1){
			// If last abst sym state, then take time projection of flowpipe \cap bad_poly
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(bad_poly,1);
		}
		else{
			// Take time projection of flowpipe \cap transition guard
			T = *(it);
			guard = T->getGaurd();
			polys = S->getContinuousSetptr()->flowpipe_intersectionSequential(guard,1);
		}
//		To get a point from the polytope, we create a random obj function and
//		solve the lp. The solution point is taken as an initial value.

		// we keep this assert to first handle the simple case when flowpipe intersects the guard only at one place
		assert(polys.size()==1);
		P=polys.front();

		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(), P->getInEqualitySign());
		max = lp.Compute_LLP(dmax);
		min = -1 * lp.Compute_LLP(dmin);
		// we add the bounds as constraints in the nlopt

		B[i].var_index = i;
		B[i].bound = max;
		B[i].is_ge = false;
		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
		B1[i].var_index = B[i].var_index;
		B1[i].is_ge=true;
		B1[i].bound = min;
		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
		// We may choose to take the max-min as the initial dwell time
		x[i] = (max + min)/2;
		if(it!=transList.end())
			it++;
//		std::cout << "First time range: min = " << min << ", max = " << max << std::endl;
	}

	double minf;
	try {
		nlopt::result result = myopt.optimize(x, minf);
		if (result < 0)
			throw "abstractCE: gen_concreteCE: NLOpt failed\n";

	} catch (std::exception& e) {
		std::cout << "Nlopt caused exception:" << e.what() << std::endl;
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
		// Assumption: X0 contains the start points of the trajectory segments returned by NLOPT
		for (unsigned int i = 1; i < N; i++) {
			// create the sample
			concreteCE::sample s;
			std::set<int>::iterator dset_iter =
					get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
			unsigned int locId = *dset_iter;

			std::vector<double> y(dim);
			y = X0[i-1]; // X0 is initiated by the LP solver

			double time = x[i];
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
 * Generate concrete trajectory using splicing with NLP problem (Zutchi, Sankaranarayanan's  Idea)
 */

concreteCE::ptr abstractCE::gen_concreteCE_NLP_HA(double tolerance, const std::list<refinement_point>& refinements) {
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

	std::cout << "gen_concreteCE_NLP_HA: dimension =" << dim <<", length of CE=" << N << std::endl;
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

	myopt.set_maxeval(4000);
	myopt.set_stopval(1e-3);

//	myopt.set_xtol_rel(1e-4);

	myopt.set_min_objective(myobjfunc1, NULL);
	//myopt.set_initial_step(0.001);

	//Set Initial value to the optimization problem
	std::vector<double> x(optD, 0);
	polytope::ptr P;

// A random objective function created for lp solving

	std::vector<double> obj(dim, 0);
	obj[0] = 1;
	std::vector<double> v(dim);

	std::list<transition::ptr>::iterator it = transList.begin();
	transition::ptr T;
	unsigned int size=0;
	// calculate the total constraints in all polytopes.
	polytope::ptr PList[N];
	for(unsigned int i=0;i<N;i++){
		if(i==0){
			PList[i] = get_symbolic_state(i)->getInitialPolytope();
			size += PList[i]->getCoeffMatrix().size1();
		}
		else{
			int locId = locIdList[i];
			P = HA->getLocation(locId)->getInvariant();
//			T = *(it);
//			P=P->GetPolytope_Intersection(T->getGaurd());
			size += P->getCoeffMatrix().size1();
			PList[i] = P;
			it++;
		}
	}
	polyConstraints I[size];
	unsigned int index = 0;

	math::matrix<double> A;
	std::vector<double> b;

	for (unsigned int i = 0; i < N; i++) // iterate over the N invariants of the counter-example
	{

		P = PList[i];
		A = P->getCoeffMatrix();
		b = P->getColumnVector();

// 		We assume that the polytope is expressed as Ax<=b

		assert(P->getInEqualitySign() == 1);
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
	// adding constraints over start points
	assert(index==size);

	// adding time constraints
/*	boundConstraint B[N],B1[N];
	for (unsigned int i = 0; i < N; i++) {

		B[i].var_index = N*dim + i;
		B[i].bound = 100;
		B[i].is_ge = false;
		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
		B1[i].var_index = B[i].var_index;
		B1[i].is_ge=true;
		B1[i].bound = 0;
		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
		// We may choose to take the max-min as the initial dwell time
		x[N * dim + i] = 0.1;
	} */
//// TEST CODE
//	unsigned int t_index =
//		get_first_symbolic_state()->getContinuousSet()->get_index("t");
//
//	assert((t_index >= 0) && (t_index < dim));
//
//	boundConstraint B[N],B1[N];
//	std::vector<double> dmin(dim, 0), dmax(dim, 0);
//	dmax[t_index] = 1;
//	dmin[t_index] = -1;
//	it = transList.begin();
////	transition::ptr T;
//	double max,min,start_min;
//	for (unsigned int i = 0; i < N; i++) {
//		S = get_symbolic_state(i);
//		P = S->getContinuousSet();
//		if(i==N-1){
//			// If last abst sym state, then take time projection of flowpipe \cap bad_poly
//			P=P->GetPolytope_Intersection(bad_poly);
////			std::ofstream myfile;
////			myfile.open("./polyBad");
////			P->print2file("./polyBad",0,1);
//		}
//		else{
//			// Take time projection of flowpipe \cap transition guard
//			T = *(it);
//			P=P->GetPolytope_Intersection(T->getGaurd());
//		}
////		To get a point from the polytope, we create a random obj function and
////		solve the lp. The solution point is taken as an initial value.
//
//		lp_solver lp(GLPK_SOLVER);
//		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
//				P->getInEqualitySign());
//		max = lp.Compute_LLP(dmax);
//		min = -1 * lp.Compute_LLP(dmin);
//		// we add the bounds as constraints in the nlopt
//
//		// Get the min and max time projection of start set
//		lp_solver lp1(GLPK_SOLVER);
//		P=S->getInitialSet();
//		lp1.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
//				P->getInEqualitySign());
//
//		start_min = -1 * lp1.Compute_LLP(dmin);
//
//		B[i].var_index = N*dim + i;
//		B[i].bound = max - start_min;
//		B[i].is_ge = false;
//		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
//		B1[i].var_index = B[i].var_index;
//		B1[i].is_ge=true;
//		B1[i].bound = min-start_min;
//		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
//		// We may choose to take the max-min as the initial dwell time
//		x[N * dim + i] = (max -start_min + min - start_min)/2;
//		if(it!=transList.end())
//			it++;
//
//	}

//---------------

	double minf;
	try {

		nlopt::result result = myopt.optimize(x, minf);
		if (result < 0)
			throw "abstractCE: gen_concreteCE: NLOpt failed\n";

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

		val_res = cexample->valid(pt);
		// debug
		val_res = true;
		if(!val_res){
			std::cout << "FAILED VALIDATION\n";
			if(NLP_HA_algo_flag){
				std::cout << "Splice Trace NOT VALID\n";
				return cexample = concreteCE::ptr(new concreteCE());
			}
			refinements.push_back(pt);
			ref_count++;
		}
		//debug
//		break;
	}while(!val_res && ref_count< max_refinements);

	if((ref_count < max_refinements) & !cexample->is_empty()){

		std::cout << "Generated Trace Validated with "<< ref_count << " point Refinements\n";
		return cexample;
	}
	else {
		throw std::runtime_error("Validation of counter example FAILED even after MAX Refinements\n");
		return concreteCE::ptr(new concreteCE());
	}
}
