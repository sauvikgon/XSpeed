#ifndef __LOAD_MODEL_H
#define __LOAD_MODEL_H

#include <cstring>
#include <utility>


#include "../benchmarks/BouncingBall.h"
#include "../benchmarks/ConstantMotion/ConstantMotion.h"
#include "../benchmarks/FiveDimSys.h"
#include "../benchmarks/Navigation_Benchmark/navT02_Timed.h"
#include "../benchmarks/Navigation_Benchmark/navT04_Timed.h"
#include "../benchmarks/Navigation_Benchmark/navT07_Timed.h"
#include "../benchmarks/Navigation_Benchmark/navT13_Timed.h"
#include "../benchmarks/Navigation_Benchmark/Nav04Timed.h"
#include "../benchmarks/Navigation_Benchmark/Nav22Timed.h"
#include "../benchmarks/Navigation_Benchmark/Nav25Timed.h"
#include "../benchmarks/Navigation_Benchmark/Nav30Timed.h"
#include "../benchmarks/Navigation_Benchmark/Navigation5by5WithOutTime.h"
#include "../benchmarks/Navigation_Benchmark/NavigationBenchmark.h"
#include "../benchmarks/Navigation_Benchmark/NavigationTimed3by3.h"
#include "../benchmarks/oscillator_model/f_osc_32.h"
#include "../benchmarks/oscillator_model/f_osc_32_timed.h"
#include "../benchmarks/oscillator_model/f_osc_8.h"
#include "../benchmarks/oscillator_model/f_osc_8_timed.h"
#include "../benchmarks/oscillator_model/Oscillator.h"
#include "../benchmarks/oscillator_model/Oscillator_timed.h"
#include "../benchmarks/Arch_Benchmarks/build_48.h"
#include "../benchmarks/Arch_Benchmarks/fisher_star.h"
#include "../benchmarks/Arch_Benchmarks/fwr.h"
#include "../benchmarks/Arch_Benchmarks/iss_270.h"
#include "../benchmarks/Arch_Benchmarks/mesh.h"
#include "../benchmarks/Arch_Benchmarks/motorcade.h"
#include "../benchmarks/Arch_Benchmarks/platoon.h"
#include "../benchmarks/Arch_Benchmarks/pll.h"
#include "../benchmarks/Arch_Benchmarks/setNav2u.h"
#include "../benchmarks/Arch_Benchmarks/setNav3u.h"
#include "../benchmarks/Arch_Benchmarks/setNav4u.h"
#include "../benchmarks/Arch_Benchmarks/Spacecraft/spacecraft.h"
#include "../benchmarks/TimedBouncingBall.h"
#include "../benchmarks/TTEthernet/TTEthernetModel.h"
#include "../benchmarks/vehicle_platoon/vehicle10_platoon.h"
#include "../benchmarks/vehicle_platoon/vehicle5_platoon.h"
#include "../benchmarks/Watertank_Controller/watertank_controller.h"
#include "../benchmarks/Navigation_Benchmark/NavigationBenchmark.h"
#include "../core/continuous/Polytope/polytope.h"
#include "../core/HybridAutomata/Hybrid_Automata.h"
#include "../core/math/uni_sphere.h"
#include "../core/symbolic_states/initial_state.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "application/userOptions.h"
#include "application/DataStructureDirections.h"
#include "application/All_PP_Definition.h"
#include "benchmarks/ConstantMotion/ConstantMotion.h"


/* Sets the reachability options given by the user */

void set_params(std::list<initial_state::ptr>& init_state,
		userOptions& op, ReachabilityParameters& reach_parameters,
		std::pair<int, polytope::ptr>& forbidden_set);

/**
 * Creates the pre-defined hybrid automata models in memory with config parameters.
 */

void load_ha_model(std::list<initial_state::ptr>& init_state,
		hybrid_automata& ha, ReachabilityParameters& reach_parameters, userOptions& op);

#endif
