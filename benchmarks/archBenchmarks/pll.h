/*
 * pll.h
 *
 *  Created on: 14-Dec-2016
 *      Author: amit
 */

#ifndef PLL_H_
#define PLL_H_

#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>
#include <core/symbolicStates/symbolicStates.h>
#include "core/math/matrix.h"

/*
 * * Reference for model is http://cps-vo.org/node/26546
 *
 * Model created with Hyst
 */
void setpllConv(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);



#endif /* PLL_H_ */
