/*
 * iss_270.h
 *
 *  Created on: 04-Jul-2018
 *      Author: rajarshi
 */

#ifndef BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_ISS_270_H_
#define BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_ISS_270_H_



#include "core/continuous/Polytope/polytope.h"
#include "core/HybridAutomata/Hybrid_Automata.h"
#include "core/math/matrix.h"
#include "core/math/uni_sphere.h"
#include "core/symbolic_states/initial_state.h"
#include "core/symbolic_states/symbolic_states.h"
#include "application/userOptions.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"

void setISS_270(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);


#endif /* BENCHMARKS_TEST_MODELS_ARCH_BENCHMARK_ISS_270_H_ */
