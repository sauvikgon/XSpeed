/*
 * spacecraft.h
 *
 *  Created on: 05-Jul-2018
 *      Author: rajarshi
 */

#ifndef HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SPACECRAFT_H_
#define HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SPACECRAFT_H_


#include "core/continuous/polytope/polytope.h"
#include "core/hybridAutomata/hybridAutomata.h"
#include "core/math/matrix.h"
#include "core/math/uniSphere.h"
#include "core/symbolicStates/initialState.h"
#include "core/symbolicStates/symbolicStates.h"
#include "application/userOptions.h"
#include "application/macroDefinitions.h"
#include "application/sfDirections.h"
#include "application/sfUtility.h"


void setSpacecraft(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

void setSpacecraftAbort(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* HYBRID_MODEL_PARAMETERS_DESIGN_TEST_MODELS_ARCH_BENCHMARK_SPACECRAFT_H_ */
