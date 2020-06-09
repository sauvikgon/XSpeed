#ifndef f_osc_8_H_
#define f_osc_8_H_

#include <application/structures.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/continuous/polytope/polytope.h"
#include "core/math/matrix.h"
#include "core/symbolicStates/symbolicStates.h"

void set_f_osc_8(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

#endif /* f_osc_8_H_ */
