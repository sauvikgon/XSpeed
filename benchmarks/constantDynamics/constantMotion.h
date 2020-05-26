/*
 * ConstantMotion.h
 *
 *  Created on: 06-Jun-2016
 *      Author: amit
 */

#ifndef CONSTANTMOTION_H_
#define CONSTANTMOTION_H_

#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/symbolicStates/symbolicStates.h"

void SetConstantMotion(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);

#endif /* CONSTANTMOTION_H_ */
