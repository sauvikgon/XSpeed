/*
 * watertank_controller.h
 *
 *  Created on: 27-Jun-2018s
 *      Author: rajarshi
 */

#ifndef WATERTANK_CONTROLLER_H_
#define WATERTANK_CONTROLLER_H_

#include <application/macroDefinitions.h>
#include <application/sfDirections.h>
#include <application/sfUtility.h>
#include <application/structures.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/math/uniSphere.h>	//for obtaining uniformly distributed directions
#include <core/symbolicStates/initialState.h>

#include "core/hybridAutomata/hybridAutomata.h"
#include "core/math/matrix.h"
#include "core/symbolicStates/initialState.h"
#include "core/symbolicStates/symbolicStates.h"

#include "application/userOptions.h"
#include "core/hybridAutomata/location.h"

void set_watertank_controller(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

void WT_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);


#endif /* WATERTANK_CONTROLLER_H_ */
