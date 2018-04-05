/*
 * Billiard.h
 *
 *  Created on: 15-Feb-2018
 *      Author: amit
 */

#ifndef BILLIARD_H_
#define BILLIARD_H_


#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"
#include "application/DataStructureDirections.h"

#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"

void SetBilliardModel(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);



#endif /* BILLIARD_H_ */