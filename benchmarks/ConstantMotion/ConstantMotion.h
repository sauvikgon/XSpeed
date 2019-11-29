/*
 * ConstantMotion.h
 *
 *  Created on: 06-Jun-2016
 *      Author: amit
 */

#ifndef CONSTANTMOTION_H_
#define CONSTANTMOTION_H_

#include "../../core/continuous/Polytope/Polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"

void SetConstantMotion(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);

#endif /* CONSTANTMOTION_H_ */
