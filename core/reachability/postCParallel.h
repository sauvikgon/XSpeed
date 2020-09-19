/*
 * reachParallelExplore.h
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */

#ifndef POSTC_PARALLEL_H_
#define POSTC_PARALLEL_H_

#include <application/macroDefinitions.h>
#include <application/sfUtility.h>
#include <application/structures.h>
#include <core/continuous/convexSet/transMinkPoly.h>
#include <core/math/glpkLpSolver/glpkLpSolver.h>
#include <fstream>
#include <omp.h>

#include "core/math/analyticODESol.h"
#include "core/math/matrix.h"
#include "core/reachability/postCSequential.h"
#include "utilities/computeInitialPolytope.h"
#include "utilities/invariantBoundaryCheck.h"
#include "utilities/testPolytopePlotting.h"
#include "utilities/templatePolyhedra.h"
#include "utilities/templatePolyhedra.h"


const template_polyhedra::ptr postC_lazySf(
			unsigned int NewTotalIteration, const Dynamics& SystemDynamics,
			supportFunctionProvider::ptr Initial,
			ReachabilityParameters& ReachParameters, polytope::const_ptr invariant,
			bool isInvariantExist, int lp_solver_type);






/**
 * Reachability function which explores the state space in parallel starting at different initial sets.
 *
 * CORES: Its the number of parallel compute cores available in the hardware architecture.
 */
const template_polyhedra::ptr postC_timeslice(unsigned int NewTotalIteration, const Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, const polytope::const_ptr invariant,
		bool isInvariantExist, int CORES, unsigned int Algorithm_Type,
		int lp_solver_type);


#endif /* REACH_POSTC_PARALLEL_H_ */
