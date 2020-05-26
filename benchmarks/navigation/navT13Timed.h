#ifndef navT13_Timed_H_
#define navT13_Timed_H_
#include <application/structures.h>
#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/math/matrix.h"
#include "core/symbolicStates/symbolicStates.h"
void setnavT13_Timedmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void navT13_Timed_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void navT13_Timed_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void navT13_Timed_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void navT13_Timed_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
#endif /* navT13_Timed_H_ */
