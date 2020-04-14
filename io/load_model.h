#ifndef __LOAD_MODEL_H
#define __LOAD_MODEL_H

#include <benchmarks/FiveDim_switching_system/5_dim_linear_switchCORRECTED.h>
#include <cstring>
#include <utility>


#include "../benchmarks/Satellite/bm01.h"
#include "../benchmarks/Satellite/bm02.h"
#include "../benchmarks/Satellite/bm03.h"
#include "../benchmarks/Satellite/bm04.h"
#include "../benchmarks/Satellite/bm05.h"
#include "../benchmarks/Billiard/Billiard.h"
#include "../benchmarks/BouncingBall.h"
#include "../benchmarks/ConstantMotion/ConstantMotion.h"
#include "../benchmarks/FiveDimSys.h"
#include "../benchmarks/Helicopter_model/HelicopterModel28Dim.h"
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
#include "../benchmarks/Rotation_Circle.h"
#include "../benchmarks/Rotation_Circle_FourLocation.h"
#include "../benchmarks/Rotation_Circle_One_Location.h"
#include "../benchmarks/test_models/Arch_Benchmark/build_48.h"
#include "../benchmarks/test_models/Arch_Benchmark/fisher_star.h"
#include "../benchmarks/test_models/Arch_Benchmark/fwr.h"
#include "../benchmarks/test_models/Arch_Benchmark/iss_270.h"
#include "../benchmarks/test_models/Arch_Benchmark/mesh.h"
#include "../benchmarks/test_models/Arch_Benchmark/motorcade.h"
#include "../benchmarks/test_models/Arch_Benchmark/platoon.h"
#include "../benchmarks/test_models/Arch_Benchmark/pll.h"
#include "../benchmarks/test_models/Arch_Benchmark/setNav2u.h"
#include "../benchmarks/test_models/Arch_Benchmark/setNav3u.h"
#include "../benchmarks/test_models/Arch_Benchmark/setNav4u.h"
#include "../benchmarks/test_models/Arch_Benchmark/Spacecraft/spacecraft.h"
#include "../benchmarks/TimedBouncingBall.h"
#include "../benchmarks/TTEthernet/TTEthernetModel.h"
#include "../benchmarks/vehicle_platoon/vehicle10_platoon.h"
#include "../benchmarks/vehicle_platoon/vehicle5_platoon.h"
#include "../benchmarks/Watertank_Controller/watertank_controller.h"
#include "../benchmarks/Navigation_Benchmark/NavigationBenchmark.h"
#include "../core/continuous/Polytope/Polytope.h"
#include "../core/HybridAutomata/Hybrid_Automata.h"
#include "../core/math/uni_sphere.h"
#include "../core/symbolic_states/initial_state.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "application/userOptions.h"
#include "application/DataStructureDirections.h"
#include "application/All_PP_Definition.h"
#include "benchmarks/ConstantMotion/ConstantMotion.h"


//#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/heart.h"
//Todo:: or the user_model which need to be fix if error occurs at runtime as it will be included at runtime
// **************************************************************************************

/**
 * Creates the pre-defined hybrid automata models in memory with config parameters.
 */
void load_model(std::list<initial_state::ptr>& init_state, hybrid_automata& ha,
		userOptions& op, ReachabilityParameters& reach_parameters,
		std::pair<int, polytope::ptr>& forbidden_set);

void load_ha_models(std::list<initial_state::ptr>& init_state,
		hybrid_automata& ha, ReachabilityParameters& reach_parameters, userOptions& op);

#endif
