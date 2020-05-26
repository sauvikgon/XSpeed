/*
 * computeInitialpolytope.h
 *
 *  Created on: 17-Nov-2014
 *      Author: amit
 */
/*
 * File containing all the trials for Parallel on Iterations
 */
#ifndef COMPUTEINITIALPOLYTOPE_H_
#define COMPUTEINITIALPOLYTOPE_H_

#include <core/continuous/polytope/polytope.h>
#include <core/reachability/postCParallel.h>
#include <utilities/templatePolyhedra.h>
#include <list>

#include "utilities/invariantBoundaryCheck.h"
#include "utilities/testPolytopePlotting.h"

//#include "MySrc/Reachability/reachabilityParallel_Iterations.h"

std::list<polytope::ptr> compute_initial_polytopes(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int NCores);	//prototype declaration

/*
 * Trying Idea :: Method(i) described in my note book
 */
std::list<polytope::ptr> compute_initial_polytopes_transMink(
		Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int NCores);	//prototype declaration

polytope::ptr create_polytope_set(supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, Dynamics& SystemDynamics);

template_polyhedra Reach_Parallel_Iteration(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr initial,
		ReachabilityParameters& reach_parameters, polytope::ptr invariant,
		bool isInvariantExist);

#endif /* COMPUTEINITIALPOLYTOPE_H_ */
