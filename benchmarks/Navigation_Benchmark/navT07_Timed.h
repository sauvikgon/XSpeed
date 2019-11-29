#ifndef navT07_Timed_H_
#define navT07_Timed_H_

#include "../../core/continuous/Polytope/Polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/math/matrix.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"
#include "application/DataStructureDirections.h"
void setnavT07_Timedmodel(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);
void navT07_Timed_module1(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);
void navT07_Timed_module2(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);
void navT07_Timed_module3(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);
void navT07_Timed_module4(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);
#endif /* navT07_Timed_H_ */
