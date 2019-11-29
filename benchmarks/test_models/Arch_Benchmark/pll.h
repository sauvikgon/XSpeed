/*
 * pll.h
 *
 *  Created on: 14-Dec-2016
 *      Author: amit
 */

#ifndef PLL_H_
#define PLL_H_

#include "../../../core/continuous/Polytope/Polytope.h"
#include "../../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../../core/math/matrix.h"
#include "../../../core/symbolic_states/initial_state.h"
#include "../../../core/symbolic_states/symbolic_states.h"

/*
 * * Reference for model is http://cps-vo.org/node/26546
 *
 * Model created with Hyst
 */
void setpllConv(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);



#endif /* PLL_H_ */
