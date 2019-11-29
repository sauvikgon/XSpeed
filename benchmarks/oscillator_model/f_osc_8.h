#ifndef f_osc_8_H_
#define f_osc_8_H_

#include "../../core/continuous/Polytope/Polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/math/matrix.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"
#include "application/DataStructureDirections.h"

void set_f_osc_8(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

#endif /* f_osc_8_H_ */
