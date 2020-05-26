#ifndef f_osc_32_timed_H_
#define f_osc_32_timed_H_
#include <application/structures.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/continuous/polytope/polytope.h"
#include "core/math/matrix.h"
#include "core/symbolicStates/symbolicStates.h"

void setf_osc_32_timedmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
#endif /* f_osc_32_timed_H_ */
