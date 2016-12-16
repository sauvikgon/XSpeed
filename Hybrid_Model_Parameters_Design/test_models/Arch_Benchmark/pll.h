/*
 * pll.h
 *
 *  Created on: 14-Dec-2016
 *      Author: amit
 */

#ifndef PLL_H_
#define PLL_H_

#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/math/matrix.h"

/*
 * * Reference for model is http://cps-vo.org/node/26546
 *
 * Model created with Hyst
 */
void setpllConv(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);



#endif /* PLL_H_ */
