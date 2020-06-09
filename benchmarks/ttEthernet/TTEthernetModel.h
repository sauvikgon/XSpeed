/*
 * TTEthernetModel.h
 *
 *  Created on: 3-Oct-2016
 *      Author: amit
 */

#ifndef TTETHERNET_H_
#define TTETHERNET_H_

#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/continuous/polytope/polytope.h"
#include "core/math/matrix.h"
#include "core/symbolicStates/symbolicStates.h"


/*
 * * Reference for model is http://cps-vo.org/node/26547
 *
 * Model created with Hyst after converting SpaceEx model to flat xml model using Hyst and then coverting the model to .cpp
 */
void setTTEthernet5(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);


#endif /* TTETHERNET_H_ */
