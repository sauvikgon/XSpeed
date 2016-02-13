/*

 * reachability_HybridAutomata.h
 *
 *  Created on: 12-Nov-2014
 *      Author: amit
 */

#ifndef REACHABILITY_HYBRIDAUTOMATA_H_
#define REACHABILITY_HYBRIDAUTOMATA_H_

#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "counterExample/abstract_symbolic_state.h"
#include "InputOutput/io_utility.h"

//#include "core_system/PWL/pwl.h"
#include "core_system/PWL/pwlist.h"
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/symbolic_states/symbolic_states_utility.h"

#include "Utilities/testPolytopePlotting.h"
#include "Utilities/Post_Assignment.h"
#include <boost/lexical_cast.hpp>
#include "core_system/Reachability/reachabilitySequential.h"
#include "core_system/Reachability/reachParallelExplore.h"
#include "core_system/Reachability/reachabilityParallel_Process.h"
#include "core_system/Reachability/NewApproach/SameDirections_Avoid_SuppFunction.h"
#include "Utilities/computeInitialPolytope.h"
//#include "core_system/math/gurobi_lp_solver/gurobi_lp_solver.h"
#include "application/All_PP_Definition.h"
//#include "core_system/Reachability/reachabilitySequential_GPU_MatrixVector_Multiply.cuh"
//#include "core_system/Reachability/GPU_Reach/reach_Sequential_GPU.h"
#include "boost/timer/timer.hpp"
#include "counterExample/abstractCE.h"
#include <omp.h>



//Sequential Search for Discrete Jumps
std::list<symbolic_states::ptr> reach(hybrid_automata& H, initial_state::ptr& I,
		ReachabilityParameters& reach_parameters, int bound,
		unsigned int Algorithm_Type, unsigned int Total_Partition,
		int lp_solver_type_choosen, unsigned int number_of_streams,
		int Solver_GLPK_Gurobi_GPU,
		std::set<std::pair<int, polytope::ptr> > forbidden_set, abstractCE::ptr& ce);


//Parallel Breadth First Search for Discrete Jumps
std::list<symbolic_states::ptr> reach_pbfs(hybrid_automata& H, initial_state::ptr& I,
		ReachabilityParameters& reach_parameters, int bound,
		unsigned int Algorithm_Type, unsigned int Total_Partition,
		int lp_solver_type_choosen, unsigned int number_of_streams,
		int Solver_GLPK_Gurobi_GPU,
		std::set<std::pair<int, polytope::ptr> > forbidden_set, abstractCE::ptr& ce);

#endif /* REACHABILITY_HYBRIDAUTOMATA_H_ */
