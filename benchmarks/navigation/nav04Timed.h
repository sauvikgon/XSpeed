/*
 * NavigationTimed3by3.h
 *
 *  Created on: 22-May-2016
 *      Author: rajarshi
 */

/**
 * Navigation instance 04 model with time evolution added
 * to the dynamics of each location.
 */

#ifndef NAV04TIMED_H_
#define NAV04TIMED_H_

#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/symbolicStates/symbolicStates.h"

void Nav04module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void Nav04module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void Nav04module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void Nav04module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

void set_nav04_timed(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

void Set_NavTimedEpsilonRelaxGuard(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* NAVIGATIONTIMED3BY3_H_ */
