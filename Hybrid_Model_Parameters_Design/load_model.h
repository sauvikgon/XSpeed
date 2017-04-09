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
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationTimed3by3.h"
//#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationTimed5by5.h"
//#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationTimed9by9.h"
#include "Hybrid_Model_Parameters_Design/oscillator_model/Oscillator.h"
#include "Hybrid_Model_Parameters_Design/ConstantMotion/ConstantMotion.h"

#include "Hybrid_Model_Parameters_Design/TTEthernet/TTEthernetModel.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/build_48.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/fwr.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/pll.h"

#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/mesh.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/platoon.h"
#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/motorcar.h"

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

#endif
