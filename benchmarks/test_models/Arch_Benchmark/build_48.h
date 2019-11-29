/*
 * build_48.h
 *
 *  Created on: 03-Dec-2016
 *      Author: amit
 */

#ifndef BUILD_48_H_
#define BUILD_48_H_


#include "../../../core/continuous/Polytope/Polytope.h"
#include "../../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../../core/math/matrix.h"
#include "../../../core/symbolic_states/initial_state.h"
#include "../../../core/symbolic_states/symbolic_states.h"


/*
 * * Reference for model is http://cps-vo.org/node/26546
 *
 * Model created with Hyst after using the XSpeed -xspeed option to convert into a .cpp model for XSpeed
 */
void setbuild48(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* BUILD_48_H_ */
