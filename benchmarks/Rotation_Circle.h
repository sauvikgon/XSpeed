/*
 * Rotation_Circle.h
 *
 *	Model with Two Locations First the Upper-Half and Second the Lower-Half
 *
 *  Created on: 17-Sep-2014
 *      Author: amit
 */

#ifndef ROTATION_TIMED_CIRCLE_H_
#define ROTATION_TIMED_CIRCLE_H_

#include "../core/continuous/Polytope/Polytope.h"
#include "../core/HybridAutomata/Hybrid_Automata.h"
#include "../core/math/matrix.h"
#include "../core/symbolic_states/initial_state.h"
#include "../core/symbolic_states/symbolic_states.h"

void SetRotationCircle_Parameters(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

void SetRotationTimedCircle_Parameters(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* ROTATION_TIMED_CIRCLE_H_ */
