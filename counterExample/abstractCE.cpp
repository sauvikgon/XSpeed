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

const abstract_symbolic_state::ptr abstractCE::get_first_symbolic_state() const
{
	std::list<abstract_symbolic_state::ptr>::const_iterator it = sym_states.begin();
	return *it;

}
const abstract_symbolic_state::ptr abstractCE::get_unsafe_symbolic_state() const
{
	std::list<abstract_symbolic_state::ptr>::const_iterator it = sym_states.end();
	return *it;
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

	simulation::ptr s = simulation::ptr(new simulation(x0.size(),1000,D));
	std::vector<double> y(x0.size(), 0);
	// debug purpose
	std::string filename = "./test_sim.o";
	s->set_outfile(filename);
	s->set_out_dimension(0);
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

	std::cout << "sampled dwell time for simulation:" << time << std::endl;
//debug purpose ends

	y = s->simulate(x0, time);

/*	mycount++;
	if(mycount>2)
		exit(0); */
	return y;
}

double myobjfunc(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data) {
	//----
	/*std::cout << "Printing x from the obj func\n" << std::endl;
	for(unsigned int i=0;i<x.size();i++)
		std::cout << x[i] << " ";
	 std::cout << std::endl; */
	//----
	if (!grad.empty()) {
	/*	for(unsigned int i=0;i<(N-1)*dim;i++)
			grad[i] = 2 * (x[i] - x[i+dim]);
		for(unsigned int i=N*dim;i<N;i++)
			grad[i] = 0; */
	}
	/**
	 * 1. Get the N start vectors and dwell times from x and call the simulation routine
	 * 2. Get the N end points of the simulation trace, say, y[i].
	 * 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
	 */
	double sum = 0; // Stores the sum of all Euclidean distances of the end points.
	std::vector<double> y(dim,0);

	// Computes the L2 norm or Eucilean distances between the trace end points.
	double sq_sum = 0;
	for (unsigned int i = 0; i < N-1; i++) {
		std::vector<double> v(dim, 0);
		for (unsigned int j = 0; j < dim; j++) {
			v[j] = x[i * dim + j];
		}
		try{
			int loc_index = locIdList[i];
			y = simulate_trajectory(v, HA->getLocation(loc_index).getSystem_Dynamics(), x[N * dim + i]);
			// todo: assignment mapping to be done later.

		}catch(std::exception& e)
		{
			// check if violation of invariant/abstract CE exception thrown
			//for(unsigned int j=0;j<dim;j++){
			//	y = std::numeric_limits<double>::max();
				// Adds a high penalty to the objective function
		}
		std::vector<double> next_start(dim,0); // current jump start point
		for(unsigned int j=0;j<dim;j++)
			next_start[j]=x[(i+1)*dim + j];
		//compute the euclidean distance between the next start point and the simulated end point
		for (unsigned int i = 0; i < dim; i++) {
			sq_sum += (y[i] - next_start[i]) * (y[i] - next_start[i]);
		}
		sum += math::sqrt(sq_sum);
	}
	//Calculate Euclidean distances
	// get the next point after jump in vector t;
	std::cout << "current sum = " << sum << std::endl;
	//exit(0);
	return sum;
}

/** Function to define a constraint over the optimization problem */

struct polyConstraints {
	math::matrix<double> A;
	math::vector<double> b;
	unsigned int sstate_index;
	unsigned int row_index;
};

struct boundConstriant{
	double bound;
	unsigned int var_index;
	bool is_ge; // to mark if bound is a >= constraint
};
double myconstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data) {
	polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
	unsigned int i = d->sstate_index;
	unsigned int row_index = d->row_index;

	if (!grad.empty()) {
		// todo: gradient to be added later
/*		for(unsigned int i=0;i<x.size();i++){
			grad[i] = 0 ;
		}
		for(unsigned int j=0;j<dim;j++)
			grad[i*dim+j] = d->A(row_index,j);*/
	}
	assert(d->A.size2() == dim);

	double sum = 0;
	for (unsigned int j = 0; j < dim; j++) {
		sum += x[i * dim + j] * d->A(row_index, j);
	}
	sum -= d->b[row_index];
	return sum;
}
/** Adds bound constraint on a variable, i.e. x<=b => x-b<=0*/
double myBoundConstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data){

	boundConstriant *d = reinterpret_cast<boundConstriant *>(data);
	if (!grad.empty()) {
		// todo: gradient to be added later
	//	grad[d->var_index] = 0;
	}

	if(d->is_ge){
//		std::cout << "lower bound constraint on time with bound = " << d->bound << std::endl;
		return (-1*x[d->var_index] + d->bound);
	}
	else{
//		std::cout << "upper bound constraint on time with bound = " << d->bound << std::endl;
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

	/* Generate an nlopt object with the constraints defined by the Abstract
	 * counter example
	 */

	/* 1. Get the dimensionality of the optimization problem by
	 * getting the dimension of the continuous set of the abstract counter example
	 */

	std::cout << "entered inside gen_concreteCE\n";
	abstract_symbolic_state::ptr S = get_first_symbolic_state();
	dim = S->getContinuousSet()->getSystemDimension();
	N = get_length(); // the length of the counter example
	HA = this->get_automaton();
	std::cout << "gen_concreteCE: dimension N =" << dim <<", length of CE=" << N << std::endl;
	// initialize the global locIdList
	locIdList.resize(N);

	std::set<int> d;
	for(unsigned int i=0;i<N;i++){
		d = this->get_symbolic_state(i)->getDiscreteSet().getDiscreteElements();
		locIdList[i] = *(d.begin());
//		std::cout << "locIdList at "<< i << " = " << locIdList[i] << std::endl;
	}


	/**
	 * 2. The dimensionality of the opt problem is N vectors, one starting point
	 * for each of the abstract sym state of the CE + N dwell times. Moreover,
	 * each starting vector is of dimension dim. Therefore, the total number of
	 * variables of the optimization problem are dim*N + N
	 */
	unsigned int optD = N * dim + N;
	std::cout << "nlopt problem dimension = " << optD << std::endl;
	nlopt::opt myopt(nlopt::LN_COBYLA, optD); // derivative free
//	nlopt::opt myopt(nlopt::LD_MMA, optD); // derivative based

//	std::vector<double> lb(2);
//	lb[0] = 0.1;
//	lb[1] = 2;

//	myopt.set_lower_bounds(lb);
	myopt.set_stopval(2.3);
//	myopt.set_xtol_rel(1e-4);

	myopt.set_min_objective(myobjfunc, NULL);

	/** Set Initial value to the optimization problem */
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
		/** To get a point from the polytope, we create a random obj function and
		 * solve the lp. The solution point is taken as an initial value.
		 */
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
	/** Set initial value to the time variables
	 *  Restrict dwell time within the projections of C_i in time variable
	 **/

	/**
	 * We assume that the time variable is names as 't' in the model.
	 * We find out the min,max components of the time variable
	 */
	unsigned int t_index =
		get_first_symbolic_state()->getContinuousSet()->get_index("t");
	std::cout << "Index of time variable:" << t_index << std::endl;
	assert((t_index >= 0) && (t_index < dim));

	std::vector<double> dmin(dim, 0), dmax(dim, 0);
	dmax[t_index] = 1;
	dmin[t_index] = -1;

	boundConstriant B[N],B1[N];

	double max,min;
	for (i = 	0; i < N; i++) {
		S = get_symbolic_state(i);
		P = S->getContinuousSet();
		/** To get a point from the polytope, we create a random obj function and
		 * solve the lp. The solution point is taken as an initial value.
		 */
		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(), P->getColumnVector(),
				P->getInEqualitySign());
		max = lp.Compute_LLP(dmax);
		min = -1 * lp.Compute_LLP(dmin);
		// we add the bounds as constraints in the nlopt

		B[i].var_index = N*dim + i;
		B[i].bound = max - min;
		std::cout << "max time val:" << max << ", min time val:" << min << std::endl;
		B[i].is_ge = false;
		myopt.add_inequality_constraint(myBoundConstraint, &B[i], 1e-8);
		B1[i].var_index = B[i].var_index;
		B1[i].is_ge=true;
		B1[i].bound = 0;
		myopt.add_inequality_constraint(myBoundConstraint, &B1[i], 1e-8);
		// We may choose to take the max-min as the initial dwell time
		x[N * dim + i] = max - min;
	}
std::cout << "Computed initial dwell times and added constraints over them\n";
	/**
	 * todo: Constraints of the optimization problem is to be added
	 * nlopt expects the constraints of the form constraint(x) <=0
	 */

	/*Constraints over C_i added to the optimization problem */

	polytope::ptr C;
	math::matrix<double> A;
	math::vector<double> b;

	polyConstraints data[N];
	for (unsigned int i = 0; i < N; i++) {
		C = get_symbolic_state(i)->getInitialSet();
		data[i].A = C->getCoeffMatrix();
		data[i].b = C->getColumnVector();

		// We assume that the polytope is expressed as Ax<=b

		assert(C->getInEqualitySign() == 1);

		unsigned int num_rows = A.size1();

		data[i].sstate_index = i;
		for (unsigned int j = 0; j < num_rows; j++) {
			data[i].row_index = j;
			myopt.add_inequality_constraint(myconstraint, &data[i], 1e-8);
		}
	}
std::cout << "added constraints to the nlopt solver\n";
	/* todo: Constraints over dwell time to be added */

	/* Create object of concreteCE from the result of nlopt */

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

