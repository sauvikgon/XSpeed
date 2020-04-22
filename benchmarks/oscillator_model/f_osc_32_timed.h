#ifndef f_osc_32_timed_H_
#define f_osc_32_timed_H_
#include "../../core/continuous/Polytope/polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/math/matrix.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"
#include "application/DataStructureDirections.h"
void setf_osc_32_timedmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
#endif /* f_osc_32_timed_H_ */
