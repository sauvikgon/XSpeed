/*
 * setNav3u.h
 *
 *  Created on: 23-May-2017
 *      Author: rajarshi
 */

#ifndef BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_
#define BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_



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


void NAVmodule1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAVmodule2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAVmodule3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAVmodule4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

void setNav3u(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

#endif /* BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_ */
