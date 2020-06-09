/*
 * NavigationTimed3by3.h
 *
 *  Created on: 22-May-2016
 *      Author: rajarshi
 */

/**
 * Navigation 3 by 3 model with time evolution added
 * to the dynamics.
 */

#ifndef NAVIGATIONTIMED3BY3_H_
#define NAVIGATIONTIMED3BY3_H_

#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/continuous/polytope/polytope.h"
#include "core/symbolicStates/symbolicStates.h"

void Set_NavTimed_Parameters(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* NAVIGATIONTIMED3BY3_H_ */
