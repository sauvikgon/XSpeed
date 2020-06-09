/*
 * iss_270.h
 *
 *  Created on: 04-Jul-2018
 *      Author: rajarshi
 */

#ifndef BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_ISS_270_H_
#define BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_ISS_270_H_



#include <application/macroDefinitions.h>
#include <application/sfDirections.h>
#include <application/sfUtility.h>
#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/math/uniSphere.h>
#include <core/symbolicStates/initialState.h>
#include <core/symbolicStates/symbolicStates.h>
#include "core/math/matrix.h"
#include "application/userOptions.h"

void setISS_270(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);


#endif /* BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_ISS_270_H_ */
