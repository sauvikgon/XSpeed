
#ifndef Oscillator_timed_H_
#define Oscillator_timed_H_

#include <application/structures.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/continuous/polytope/polytope.h"
#include "core/math/matrix.h"
#include "core/symbolicStates/symbolicStates.h"

void setOscillatorTimed(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);

#endif /* Oscillator_timed_H_ */
