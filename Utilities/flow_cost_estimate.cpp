/*
 * flow_cost_estimate.cpp
 *
 *  Created on: 18-Apr-2016
 *      Author: ray
 */

#include "flow_cost_estimate.h"

double flow_cost_estimate(polytope::ptr X0, polytope::ptr I, Dynamics d, double time_horizon)
{
	unsigned int dim = X0->getSystemDimension();
	assert(I->getSystemDimension() == dim);

	// Choose a coarse time-step for efficiency
	unsigned int granularity_index = 10;
	double time_step = time_horizon/granularity_index;

	simulation sim(dim,time_step,d);
	std::vector<double> x0;

	//get a random point inside X0
	std::vector<double> obj(dim, 0);
	obj[0] = 1;
	lp_solver lp(GLPK_SOLVER);
	lp.setConstraints(X0->getCoeffMatrix(), X0->getColumnVector(),
			X0->getInEqualitySign());
	lp.Compute_LLP(obj);
	x0 = lp.get_sv();

	double t = sim.bounded_simulation(x0,time_horizon,I);
}




