/*
 * setNav3u.h
 *
 *  Created on: 23-May-2017
 *      Author: rajarshi
 */

#ifndef BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_
#define BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_



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


void NAVmodule1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAVmodule2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAVmodule3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAVmodule4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

void setNav3u(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

#endif /* BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_ */
