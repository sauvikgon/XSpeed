/*
 * TimedBouncingBall.h
 *
 *  Created on: 17-Sep-2014
 *      Author: amit
 */

#ifndef TIMEDBOUNCINGBALL_H_
#define TIMEDBOUNCINGBALL_H_

/*
 * Basic Model Design requirements are ---
 *
 * Initial Polytope
 * Dynamics : Matrix A, Matrix B and Polytope U
 * Guard : Polytope
 * Invariant : Polytope *
 * Transition Dynamics  Rx + w : where R is a Assignment_mapping matrix and w a constant vector or a Polytope
 *
 */

#include <application/structures.h>
#include <core/continuous/polytope/polytope.h>

#include "core/hybridAutomata/hybridAutomata.h"
#include "core/math/matrix.h"
#include "core/symbolicStates/initialState.h"
#include "core/symbolicStates/symbolicStates.h"


void SetTimedBouncingBall(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* TIMEDBOUNCINGBALL_H_ */
