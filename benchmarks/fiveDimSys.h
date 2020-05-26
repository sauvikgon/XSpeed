#ifndef FIVE_DIM_SYS_H_
#define FIVE_DIM_SYS_H_

#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/math/matrix.h"
#include "core/symbolicStates/symbolicStates.h"

void setFiveDimSys(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif		/* FIVE_DIM_SYS_H_	*/
