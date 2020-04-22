/*
 * Rotation_Circle_One_Location.h
 *
 *  Created on: 02-Mar-2015
 *      Author: amit
 */

#ifndef ROTATION_CIRCLE_ONE_LOCATION_H_
#define ROTATION_CIRCLE_ONE_LOCATION_H_

#include "../core/continuous/Polytope/polytope.h"
#include "../core/HybridAutomata/Hybrid_Automata.h"
#include "../core/math/matrix.h"
#include "../core/symbolic_states/initial_state.h"
#include "../core/symbolic_states/symbolic_states.h"

void SetRotationCircleOneLocation_Parameters(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* ROTATION_CIRCLE_ONE_LOCATION_H_ */
