/*
 * setNav3u.h
 *
 *  Created on: 23-May-2017
 *      Author: rajarshi
 */

#ifndef HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_
#define HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_



#include "../../../core/continuous/Polytope/Polytope.h"
#include "../../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../../core/math/matrix.h"
#include "../../../core/math/uni_sphere.h"
#include "../../../core/symbolic_states/initial_state.h"
#include "../../../core/symbolic_states/symbolic_states.h"
#include "application/userOptions.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"


void NAV4uModule1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAV4uModule2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAV4uModule3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void NAV4uModule4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

void setNav4u(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

#endif /* HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SETNAV3U_H_ */
