/*
 * Billiard.h
 *
 *  Created on: 15-Feb-2018
 *      Author: amit
 */

#ifndef BILLIARD_H_
#define BILLIARD_H_


#include "../../core/continuous/Polytope/polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/math/matrix.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"
#include "application/DataStructureDirections.h"


void SetBilliardModel(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);



#endif /* BILLIARD_H_ */
