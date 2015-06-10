/*
 * reachParallelExplore.h
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */

#ifndef REACHPARALLELEXPLORE_H_
#define REACHPARALLELEXPLORE_H_

#include "core_system/math/glpk_lp_solver/glpk_lp_solver.h"
//#include "matrixOperation.h"
#include "core_system/math/matrix.h"
#include <fstream>
#include <omp.h>
#include "core_system/continuous/ConvexSet/transMinkPoly.h"
#include "Utilities/Template_Polyhedra.h"
#include "application/DataStructureDirections.h"

/**
 * Reachability function which explores the state space in parallel starting at different initial sets.
 *
 * CORES: Its the number of parallel compute cores available in the hardware architecture.
 */
const template_polyhedra reachParallelExplore(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, const polytope::ptr invariant,
		bool isInvariantExist, int CORES, unsigned int Algorithm_Type,
		int lp_solver_type_choosen);

const template_polyhedra reachabilityParallel(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen);
/*
 * Called from Parallel Algorithm for combining parallelizing over Iterations and Directions
 */
const template_polyhedra reachabilityParallel_For_Parallel_Iter_Dir(
		Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen);

/*
 * Implementation of reachability for each partitions can be made parallel using OMP approach
 */
const template_polyhedra reachabilityPartitions(Dynamics& SystemDynamics,
		polytope::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen);


const template_polyhedra reachabilityPartitions_par_iters(
		Dynamics& SystemDynamics, polytope::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int partitions_size,
		int lp_solver_type_choosen);

#endif /* REACHPARALLELEXPLORE_H_ */
