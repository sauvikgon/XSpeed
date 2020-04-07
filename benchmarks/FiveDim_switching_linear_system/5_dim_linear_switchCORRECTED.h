#ifndef FIVE_dim_linear_switchCORRECTED_H_
#define FIVE_dim_linear_switchCORRECTED_H_





#include "core/continuous/Polytope/Polytope.h"
#include "core/HybridAutomata/Hybrid_Automata.h"
#include "core/math/matrix.h"
#include "core/math/uni_sphere.h"
#include "core/symbolic_states/initial_state.h"
#include "core/symbolic_states/symbolic_states.h"
#include "application/userOptions.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"

void set_5_dim_linear_switchCORRECTED_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);


#endif /* 5_dim_linear_switchCORRECTED_H_ */
