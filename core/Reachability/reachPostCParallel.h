/*
 * reachParallelExplore.h
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */

#ifndef REACH_POSTC_PARALLEL_H_
#define REACH_POSTC_PARALLEL_H_

#include <fstream>
#include <omp.h>

#include "../../core/continuous/ConvexSet/transMinkPoly.h"
#include "../../core/math/analyticODESol.h"
#include "../../core/math/glpk_lp_solver/glpk_lp_solver.h"
#include "../../core/math/matrix.h"
#include "../../core/Reachability/reachabilitySequential.h"
#include "../../utilities/computeInitialPolytope.h"
#include "../../utilities/invariantBoundaryCheck.h"
#include "../../utilities/testPolytopePlotting.h"
#include "../../utilities/Template_Polyhedra.h"
#include "../../utilities/Template_Polyhedra.h"
#include "application/DataStructureDirections.h"
#include "application/sf_utility.h"
#include "application/All_PP_Definition.h"


const template_polyhedra::ptr reachParallelSampling(
			unsigned int NewTotalIteration, Dynamics& SystemDynamics,
			supportFunctionProvider::ptr Initial,
			ReachabilityParameters& ReachParameters, polytope::ptr invariant,
			bool isInvariantExist, int lp_solver_type);






/**
 * Reachability function which explores the state space in parallel starting at different initial sets.
 *
 * CORES: Its the number of parallel compute cores available in the hardware architecture.
 */
const template_polyhedra::ptr reachTimeSlice(unsigned int NewTotalIteration, Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, const polytope::ptr invariant,
		bool isInvariantExist, int CORES, unsigned int Algorithm_Type,
		int lp_solver_type);


#endif /* REACH_POSTC_PARALLEL_H_ */
