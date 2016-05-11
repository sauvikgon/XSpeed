/*
 * flow_cost_estimate.h
 *
 *  Created on: 18-Apr-2016
 *      Author: ray
 */

#ifndef UTILITIES_FLOW_COST_ESTIMATE_H_
#define UTILITIES_FLOW_COST_ESTIMATE_H_

#include "core_system/continuous/Polytope/Polytope.h"
#include "application/DataStructureDirections.h"
#include "counterExample/simulation.h"

/**
 * Returns an estimated time after which the flow dynamics
 * taken the flow outside the invariant, starting from the
 * initial states X0
 */
double flow_cost_estimate(polytope::ptr X0, polytope::ptr I, Dynamics d, double time_horizon);


#endif /* UTILITIES_FLOW_COST_ESTIMATE_H_ */
