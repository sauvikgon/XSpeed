/*
 * fisher_star.h
 *
 *  Created on: 10-Apr-2017
 *      Author: amit
 */

#ifndef FISHER_STAR_H_
#define FISHER_STAR_H_


#include <application/macroDefinitions.h>
#include <application/sfDirections.h>
#include <application/sfUtility.h>
#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/math/uniSphere.h>
#include <core/symbolicStates/initialState.h>
#include <core/symbolicStates/symbolicStates.h>
#include "core/math/matrix.h"
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
