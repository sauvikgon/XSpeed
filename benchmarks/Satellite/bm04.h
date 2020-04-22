#ifndef bm04_H_
#define bm04_H_


#include "core/continuous/Polytope/polytope.h"
#include "core/HybridAutomata/Hybrid_Automata.h"
#include "core/math/matrix.h"
#include "core/math/uni_sphere.h"
#include "core/symbolic_states/initial_state.h"
#include "core/symbolic_states/symbolic_states.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"


void set_bm04_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void bm04_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void bm04_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void bm04_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
void bm04_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);
#endif /* bm04_H_ */
