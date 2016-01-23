/*
 * invariantCheckWithReachability.h
 *
 *  Created on: 15-Oct-2014
 *      Author: amit
 */

#ifndef INVARIANTCHECKWITHREACHABILITY_H_
#define INVARIANTCHECKWITHREACHABILITY_H_

#include "application/DataStructureDirections.h"
#include "application/sf_utility.h"
#include "application/CopyArray.h"
#include <omp.h>

unsigned int InvariantBoundaryCheck(Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,	int lp_solver_type_choosen);

#endif /* INVARIANTCHECKWITHREACHABILITY_H_ */
