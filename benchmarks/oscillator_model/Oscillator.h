/*
 * Oscillator.h
 *
 *  Created on: 10-May-2016
 *      Author: amit
 */

#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include "../../core/continuous/Polytope/polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/math/matrix.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"

/*
 * Reference for model is https://ths.rwth-aachen.de/research/projects/hypro/filtered-oscillator/
 *
 */
void SetOscillator(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* OSCILLATOR_H_ */
