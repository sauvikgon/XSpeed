/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include "counterExample/abstractCE.h"

/** Defining some global data variables required for
 * nlopt
 */
extern unsigned int N;
extern unsigned int dim;

abstract_symbolic_state::const_ptr abstractCE::get_first_symbolic_state() const
{
	std::list<abstract_symbolic_state::const_ptr>::const_iterator it = sym_states.begin();
	return boost::shared_ptr<const abstract_symbolic_state>(*it);
}
abstract_symbolic_state::const_ptr abstractCE::get_unsafe_symbolic_state() const
{
	std::list<abstract_symbolic_state::const_ptr>::const_iterator it = sym_states.end();
	return *it;
}

abstract_symbolic_state::const_ptr abstractCE::get_symbolic_state(unsigned int i) const
{
	assert(0<=i && i<get_length());
	unsigned int j=0;
	std::list<abstract_symbolic_state::const_ptr>::const_iterator it = sym_states.begin();
	while(j<i)
		it++;
	return *it;
}

std::vector<double> simulate_trajectory(const std::vector<double>& x0, const double& time)
{
	/**
	 * This function is to simulate trajectory from x0 for time units.
	 * todo: current dummy implementation to be completed
	 */

	std::vector<double> y(x0.size(),0);
	return y;
}

double myobjfunc(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) {
	if (!grad.empty()) {
		grad[0] = 0.0;
		grad[1] = 0.5 / sqrt(x[1]);
	}
	/**
	 * 1. Get the N start vectors and dwell times from x and call the simulation routine
	 * 2. Get the N end points of the simulation trace, say, y[i].
	 * 3. Compute the Euclidean distances d(y[i],y[i+1]) and sum them up.
	 */
	double sum = 0; // Stores the sum of all Euclidean distances of the end points.
	std::vector<std::vector<double> > y(N);

	for(unsigned int i=0;i<N;i++)
	{
		std::vector<double> v(dim,0);
		for(unsigned int j=0;j<dim;j++)
		{
			v[j] = x[i*dim+j];
		}
		y[i] = simulate_trajectory(v, N*dim+i);
	}
	//Calculate Euclidean distances
	for(unsigned int i=0;i<N-1;i++)
	{
		double sq_sum = 0;
		for(unsigned int j=0;j<dim;j++)
		{
			sq_sum +=(y[i][j] - y[i+1][j]) * (y[i][j] - y[i+1][j]);
		}
		sum+=math::sqrt(sq_sum);
	}
	return sum;
}

/** Function to define a constraint over the optimization problem */

struct polyConstraints
{
	math::matrix<double> A;
	math::vector<double> b;
	unsigned int sstate_index;
	unsigned int row_index;
};

double myconstraint(const std::vector<double> &x, std::vector<double> &grad, void *data)
{
	polyConstraints *d = reinterpret_cast<polyConstraints *>(data);
    unsigned int i = d->sstate_index;
    unsigned int row_index = d->row_index;

    if (!grad.empty()) {
    	// todo: gradient to be added later
    }
    assert(d->A.size2() == dim);

    double sum=0;
    for(unsigned int j=0;i<dim;j++)
    {
    	sum+= x[i*dim+j]* d->A(row_index,j);
    }
    sum-=d->b[row_index];
    return sum;
}

/**
 * Routine to compute concrete trajectory from given
 * abstract counter example using non-linear optimization
 * routine.
 *
 * @Rajarshi
 * 28th January 2016
 */
concreteCE abstractCE::gen_concreteCE(){

	/* Generate an nlopt object with the constraints defined by the Abstract counter example
	 */

	/* 1. Get the dimensionality of the optimization problem by
	 * getting the dimension of the continuous set of the abstract counter example
	 */

	abstract_symbolic_state::const_ptr S = get_first_symbolic_state();
	dim = S->getContinuousSet()->getSystemDimension();
	N = get_length(); // the length of the counter example

	/**
	 * 2. The dimensionality of the opt problem is N vectors, one starting point
	 * for each of the abstract sym state of the CE + N dwell times. Moreover,
	 * each starting vector is of dimension dim. Therefore, the total number of
	 * variables of the optimization problem are dim*N + N
	 */
	unsigned int optD = N*dim + N;
	nlopt::opt myopt(nlopt::LN_COBYLA, optD);

	myopt.set_min_objective(myobjfunc, NULL);

	/** Set Initial value to the optimization problem */
	std::vector<double> x(optD);
	unsigned int i, j;
	polytope::ptr P;

	// A random objective function created for lp solving

	std::vector<double> obj(dim,0);
	obj[0] = 1;
	std::vector<double> v(dim);

	for(i=0;i<N;i++) // iterate over the N counter-examples
	{
		S = get_symbolic_state(i);
		P = S->getContinuousSet();
		/** To get a point from the polytope, we create a random obj function and
		 * solve the lp. The solution point is taken as an initial value.
		 */
		lp_solver lp(GLPK_SOLVER);
		lp.setConstraints(P->getCoeffMatrix(),P->getColumnVector(),P->getInEqualitySign());
		lp.Compute_LLP(obj);
		v = lp.get_sv();

		for(j=0;j<dim;j++) // iterate over each component of the x_i start point vector
		{
			x[i*dim+j] = v[j];
		}
	}
	/** Set initial value to the time variables
	 *  We initialize each dwell time to 0
	 *  \\ todo: Restrict dwell time within the projections of C_i in time variable
	 **/
	for(i=0;i<N;i++)
	{
		x[N*dim+i] = 0;
	}

	/**
	 * todo: Constraints of the optimization problem is to be added
	 * nlopt expects the constraints of the form constraint(x) <=0
	 */

	/*Constraints over C_i added to the optimization problem */

	polytope::ptr C;
	math::matrix<double> A;
	math::vector<double> b;

	for(unsigned int i=0;i<N;i++)
	{
		polyConstraints data;
		C = get_symbolic_state(i)->getContinuousSet();
		data.A = C->getCoeffMatrix();
		data.b = C->getColumnVector();

		// We assume that the polytope is expressed as Ax<=b

		assert(C->getInEqualitySign() == 1);

	    unsigned int num_rows = A.size1();

	    data.sstate_index = i;
		for(unsigned int j=0;j<num_rows;j++)
		{
			data.row_index = j;
			myopt.add_inequality_constraint(myconstraint, &data, 1e-8);
		}
	}

	/* todo: Constraints over dwell time to be added */

	/* Create object of concreteCE from the result of nlopt */

	double minf;
	try {
		nlopt::result result = myopt.optimize(x, minf);
		if (result < 0)
			throw "abstractCE: gen_concreteCE: NLOpt failed\n";

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	if(math::abs(minf) > tolerance){
		concreteCE cexample;
		return cexample;
	}
	else {
		// create a concrete counter example object
		concreteCE cexample;
		// one trajectory per symbolic state to be added in the concreteCE
		for(unsigned int i=0;i<N;i++)
		{
			// create the sample
			concreteCE::sample s;
			std::set<int>::iterator dset_iter = get_symbolic_state(i)->getDiscreteSet().getDiscreteElements().begin();
			unsigned int locId = *dset_iter;

			std::vector<double> y(dim);
			for(unsigned int j=0;j<dim;j++){
				y[j] = x[i*dim + j];
			}

			double time = x[N*dim+i];
			s.first = y;
			s.second = time;
			concreteCE::traj_segment traj;
			traj.first =locId;
			traj.second = s;
			cexample.push_back(traj);
		}
		return cexample;
	}
}
