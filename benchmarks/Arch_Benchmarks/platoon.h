/*
 * platoon.h
 *
 *  Created on: 19-Dec-2016
 *      Author: hazel
 */

#ifndef BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_PLATOON_H_
#define BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_PLATOON_H_



#include "core/continuous/Polytope/polytope.h"
#include "core/HybridAutomata/Hybrid_Automata.h"
#include "core/math/matrix.h"
#include "core/math/uni_sphere.h"
#include "core/symbolic_states/initial_state.h"
#include "core/symbolic_states/symbolic_states.h"
#include "application/userOptions.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"


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
