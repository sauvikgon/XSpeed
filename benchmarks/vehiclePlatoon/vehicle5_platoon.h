#ifndef vehicle5_platoon_H_
#define vehicle5_platoon_H_

#include <application/structures.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/hybridAutomata/hybridAutomata.h"
#include "core/math/matrix.h"
#include "core/symbolicStates/initialState.h"
#include "core/symbolicStates/symbolicStates.h"

void set_platoon5_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

#endif /* vehicle5_platoon_H_ */
