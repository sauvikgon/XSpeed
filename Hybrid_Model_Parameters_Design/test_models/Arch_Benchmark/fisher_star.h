/*
 * fisher_star.h
 *
 *  Created on: 10-Apr-2017
 *      Author: amit
 */

#ifndef FISHER_STAR_H_
#define FISHER_STAR_H_


#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/math/matrix.h"
#include "application/All_PP_Definition.h"
#include "core_system/math/uni_sphere.h"	//for obtaining uniformly distributed directions
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "application/userOptions.h"



void FStarModule1(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void FStarModule2(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void FStarModule3(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);
void FStarModule4(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters);

void setFisher_Star(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);



#endif /* FISHER_STAR_H_ */
