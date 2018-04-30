/*
 * reachParallelExplore.h
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */

#ifndef REACH_POSTC_PARALLEL_H_
#define REACH_POSTC_PARALLEL_H_

#include "core_system/math/glpk_lp_solver/glpk_lp_solver.h"
//#include "matrixOperation.h"
#include "core_system/math/matrix.h"
#include <fstream>
#include <omp.h>
#include "core_system/continuous/ConvexSet/transMinkPoly.h"
#include "Utilities/Template_Polyhedra.h"
#include "application/DataStructureDirections.h"
#include "core_system/math/analyticODESol.h"
#include "core_system/Reachability/reachabilitySequential.h"
#include "Utilities/invariantBoundaryCheck.h"
#include "application/sf_utility.h"
#include "Utilities/testPolytopePlotting.h"
#include "Utilities/Template_Polyhedra.h"
#include "application/All_PP_Definition.h"
#include "Utilities/computeInitialPolytope.h"


const template_polyhedra::ptr reachParallelSampling(
			unsigned int NewTotalIteration, Dynamics& SystemDynamics,
			supportFunctionProvider::ptr Initial,
			ReachabilityParameters& ReachParameters, polytope::ptr invariant,
			bool isInvariantExist, int lp_solver_type_choosen);






/**
 * Reachability function which explores the state space in parallel starting at different initial sets.
 *
 * CORES: Its the number of parallel compute cores available in the hardware architecture.
 */
const template_polyhedra::ptr reachTimeSlice(unsigned int NewTotalIteration, Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, const polytope::ptr invariant,
		bool isInvariantExist, int CORES, unsigned int Algorithm_Type,
		int lp_solver_type_choosen);


#endif /* REACH_POSTC_PARALLEL_H_ */
