#ifndef FIVE_DIM_SYS_H_
#define FIVE_DIM_SYS_H_

#include "../core/continuous/Polytope/Polytope.h"
#include "../core/HybridAutomata/Hybrid_Automata.h"
#include "../core/math/matrix.h"
#include "../core/symbolic_states/initial_state.h"
#include "../core/symbolic_states/symbolic_states.h"

void setSysParams(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif		/* FIVE_DIM_SYS_H_	*/
