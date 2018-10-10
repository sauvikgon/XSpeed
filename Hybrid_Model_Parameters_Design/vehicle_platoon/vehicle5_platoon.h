#ifndef vehicle5_platoon_H_
#define vehicle5_platoon_H_
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"
#include "application/DataStructureDirections.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"

void set5_vehicle_platoonmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

#endif /* vehicle5_platoon_H_ */
