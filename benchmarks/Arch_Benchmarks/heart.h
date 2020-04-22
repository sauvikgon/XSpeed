/*
 * heart.h
 *
 *  Created on: 14-Dec-2016
 *      Author: amit
 */

#ifndef HEART_H_
#define HEART_H_

#include "core/continuous/Polytope/polytope.h"
#include "core/HybridAutomata/Hybrid_Automata.h"
#include "core/math/matrix.h"
#include "core/symbolic_states/initial_state.h"
#include "core/symbolic_states/symbolic_states.h"
#include "application/userOptions.h"
/*
 * * Reference for model is http://cps-vo.org/node/26546
 *
 * Model created with Hyst
 */


void module1(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void module2(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void module3(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void module4(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);


void setheart(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);



#endif /* HEART_H_ */
