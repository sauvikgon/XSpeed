#ifndef __LOAD_MODEL_H
#define __LOAD_MODEL_H

#include <cstring>
#include <utility>
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "core_system/math/uni_sphere.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "application/userOptions.h"
#include "application/DataStructureDirections.h"
#include "application/All_PP_Definition.h"
#include "Hybrid_Model_Parameters_Design/BouncingBall.h"
#include "Hybrid_Model_Parameters_Design/FiveDimSys.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle_FourLocation.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle_One_Location.h"
#include "Hybrid_Model_Parameters_Design/TimedBouncingBall.h"
#include "Hybrid_Model_Parameters_Design/Helicopter_model/HelicopterModel28Dim.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/Nav04Timed.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/Navigation5by5WithOutTime.h"
#include "Hybrid_Model_Parameters_Design/oscillator_model/Oscillator.h"
#include "Hybrid_Model_Parameters_Design/ConstantMotion/ConstantMotion.h"

#include "Hybrid_Model_Parameters_Design/TTEthernet/TTEthernetModel.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/build_48.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/fwr.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/pll.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/iss_270.h"

#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/mesh.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/platoon.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/motorcade.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/fisher_star.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/setNav2u.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/setNav3u.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/setNav4u.h"
#include "Hybrid_Model_Parameters_Design/Watertank_Controller/watertank_controller.h"
#include "Hybrid_Model_Parameters_Design/Billiard/Billiard.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/Spacecraft/spacecraft.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/Nav22Timed.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/Nav25Timed.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/Nav30Timed.h"

#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/navT02_Timed.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/navT04_Timed.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/navT07_Timed.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/navT13_Timed.h"
#include "Hybrid_Model_Parameters_Design/vehicle_platoon/vehicle5_platoon.h"
#include "Hybrid_Model_Parameters_Design/vehicle_platoon/vehicle10_platoon.h"



// **************************************************************************************
/*
 * Only ONE out of these headers should be declared at a time
 * since they all include the module1,module2,module3 and module4 declaration
 */
#include "Navigation_Benchmark/NavigationBenchmark.h"

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
