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

#include "../core/continuous/Polytope/polytope.h"
#include "../core/HybridAutomata/Hybrid_Automata.h"
#include "../core/math/matrix.h"
#include "../core/symbolic_states/initial_state.h"
#include "../core/symbolic_states/symbolic_states.h"
#include "application/DataStructureDirections.h"


void SetTimedBouncingBall(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

//Testing for 2 initial set
void SetTimedBouncingBall_2initSet(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* TIMEDBOUNCINGBALL_H_ */
