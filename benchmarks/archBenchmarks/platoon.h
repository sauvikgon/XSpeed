/*
 * platoon.h
 *
 *  Created on: 19-Dec-2016
 *      Author: hazel
 */

#ifndef BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_PLATOON_H_
#define BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_PLATOON_H_



#include <application/macroDefinitions.h>
#include <application/sfDirections.h>
#include <application/sfUtility.h>
#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/math/uniSphere.h>
#include <core/symbolicStates/initialState.h>
#include <core/symbolicStates/symbolicStates.h>
#include "core/math/matrix.h"
#include "application/userOptions.h"


/**
 * @Rajarshi
 *
 * Platoon model with constant input. This model is to test CE searching with trajectory splicing
 */
void setplatoon_const_input(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

void setplatoon(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

/**
 * @Rajarshi
 *
 * Platoon model for non-deterministic transition from communicating to non-communicating mode
 */
void setplatoon_ndt(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);


/**
 * @Rajarshi
 *
 * Platoon model for arbitrary number of transitions from communicating to non-communicating mode
 */
void setplatoon_na(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_PLATOON_H_ */
