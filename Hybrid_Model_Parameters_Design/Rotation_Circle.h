/*
 * Rotation_Circle.h
 *
 *  Created on: 17-Sep-2014
 *      Author: amit
 */

#ifndef ROTATION_CIRCLE_H_
#define ROTATION_CIRCLE_H_

#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/math/matrix.h"

void SetRotationCircle_Parameters(hybrid_automata& Hybrid_Automata,
		symbolic_states& initial_symbolic_state,
		ReachabilityParameters& reach_parameters);



#endif /* ROTATION_CIRCLE_H_ */
