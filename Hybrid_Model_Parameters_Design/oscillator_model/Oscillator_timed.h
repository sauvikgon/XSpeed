#ifndef Oscillator_timed_H_
#define Oscillator_timed_H_
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"
#include "application/DataStructureDirections.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"
void setOscillator_timedmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
#endif /* Oscillator_timed_H_ */
