/*
 * setNav3u.h
 *
 *  Created on: 23-May-2017
 *      Author: rajarshi
 */

#ifndef HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_
#define HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_



#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/math/matrix.h"
#include "application/userOptions.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "core_system/math/uni_sphere.h"


void NAVmodule1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters, userOptions& op);
void NAVmodule2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters, userOptions& op);
void NAVmodule3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters, userOptions& op);
void NAVmodule4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters, userOptions& op);

void setNav3u(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters, userOptions& op);

#endif /* HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_ */