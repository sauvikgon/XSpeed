/*
 * Navigation5by5WithOutTime.h
 *
 *  Created on: 11-Jan-2018
 *      Author: amit
 */

#ifndef NAVIGATION5BY5WITHOUTTIME_H_
#define NAVIGATION5BY5WITHOUTTIME_H_


#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/continuous/polytope/polytope.h"
#include "core/symbolicStates/symbolicStates.h"

void SetNavigationNav5by5WithOutTime(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);

void Nav5Module1(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

void Nav5Module2(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

void Nav5Module3(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

void Nav5Module4(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);


#endif /* NAVIGATION5BY5WITHOUTTIME_H_ */
