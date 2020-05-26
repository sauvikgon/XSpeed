/*
 * Oscillator.h
 *
 *  Created on: 10-May-2016
 *      Author: amit
 */

#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>

#include "core/continuous/polytope/polytope.h"
#include "core/math/matrix.h"
#include "core/symbolicStates/symbolicStates.h"

/*
 * Reference for model is https://ths.rwth-aachen.de/research/projects/hypro/filtered-oscillator/
 *
 */
void SetOscillator(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* OSCILLATOR_H_ */
