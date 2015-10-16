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
#include "core_system/PWL/pwl.h"

#include "Utilities/testPolytopePlotting.h"
#include "Utilities/Post_Assignment.h"
#include <boost/lexical_cast.hpp>
#include "core_system/Reachability/reachabilitySequential.h"
#include "core_system/Reachability/reachParallelExplore.h"
#include "core_system/Reachability/reachabilityParallel_Process.h"
#include "core_system/Reachability/NewApproach/SameDirections_Avoid_SuppFunction.h"
#include "Utilities/computeInitialPolytope.h"

std::list<template_polyhedra> reach(hybrid_automata& H, symbolic_states& I,
		ReachabilityParameters& reach_parameters, int bound,
		unsigned int Algorithm_Type, unsigned int Total_Partition,
		int lp_solver_type_choosen, unsigned int number_of_streams, int Solver_GLPK_Gurobi_GPU);

#endif /* REACHABILITY_HYBRIDAUTOMATA_H_ */
