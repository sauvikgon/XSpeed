/*
 * watertank_controller.h
 *
 *  Created on: 27-Jun-2018s
 *      Author: rajarshi
 */

#ifndef WATERTANK_CONTROLLER_H_
#define WATERTANK_CONTROLLER_H_

#include "../../core/continuous/Polytope/polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/HybridAutomata/Location.h"
#include "../../core/math/matrix.h"
#include "../../core/math/uni_sphere.h"	//for obtaining uniformly distributed directions
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"
#include "application/DataStructureDirections.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "application/userOptions.h"

void set_watertank_controller(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

void WT_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void WT_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);


#endif /* WATERTANK_CONTROLLER_H_ */
