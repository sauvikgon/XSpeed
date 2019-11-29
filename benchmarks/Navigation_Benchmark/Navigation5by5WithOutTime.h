/*
 * Navigation5by5WithOutTime.h
 *
 *  Created on: 11-Jan-2018
 *      Author: amit
 */

#ifndef NAVIGATION5BY5WITHOUTTIME_H_
#define NAVIGATION5BY5WITHOUTTIME_H_


#include "../../core/continuous/Polytope/Polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"

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
