/*
 * motorcar.h
 *
 *  Created on: 09-Apr-2017
 *      Author: rajarshi
 */

#ifndef HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_MOTORCAR_H_
#define HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_MOTORCAR_H_

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



void module1MotorCade(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void module2MotorCade(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void module3MotorCade(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void module4MotorCade(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);

void setMotorcade(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);


#endif /* HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_MOTORCAR_H_ */
