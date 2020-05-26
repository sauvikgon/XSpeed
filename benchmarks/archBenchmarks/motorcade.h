/*
 * motorcar.h
 *
 *  Created on: 09-Apr-2017
 *      Author: rajarshi
 */

#ifndef HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_MOTORCAR_H_
#define HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_MOTORCAR_H_

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
