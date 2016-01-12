/*
 * reach_Sequential_GPU.h
 *
 *  Created on: 18-Apr-2015
 *      Author: amit
 */

#ifndef REACH_SEQUENTIAL_GPU_H_
#define REACH_SEQUENTIAL_GPU_H_

//#include <fstream>
#include "Utilities/invariantBoundaryCheck.h"
#include "core_system/math/matrix.h"
#include "Utilities/Template_Polyhedra.h"
#include "application/sf_directions.h"

template_polyhedra::ptr reachabilitySequential_GPU(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen, unsigned int number_of_streams, int Solver_GLPK_Gurobi_GPU);


#endif /* REACH_SEQUENTIAL_GPU_H_ */