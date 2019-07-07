/*
 * watertank_controller.h
 *
 *  Created on: 27-Jun-2018s
 *      Author: rajarshi
 */

#ifndef WATERTANK_CONTROLLER_H_
#define WATERTANK_CONTROLLER_H_

#include "application/DataStructureDirections.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/math/matrix.h"
#include "application/All_PP_Definition.h"
#include "core_system/math/uni_sphere.h"	//for obtaining uniformly distributed directions
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "application/userOptions.h"
#include "core_system/HybridAutomata/Location.h"

void set_watertank_controller(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

void WT_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);


#endif /* WATERTANK_CONTROLLER_H_ */
