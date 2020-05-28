#ifndef __LOAD_MODEL_H
#define __LOAD_MODEL_H

#include <application/macroDefinitions.h>
#include <application/sfDirections.h>
#include <application/sfUtility.h>
#include <application/structures.h>
#include <benchmarks/archBenchmarks/build48.h>
#include <benchmarks/archBenchmarks/fisherStar.h>
#include <benchmarks/archBenchmarks/fwr.h>
#include <benchmarks/archBenchmarks/iss270.h>
#include <benchmarks/archBenchmarks/mesh.h>
#include <benchmarks/archBenchmarks/motorcade.h>
#include <benchmarks/archBenchmarks/platoon.h>
#include <benchmarks/archBenchmarks/pll.h>
#include <benchmarks/archBenchmarks/setNav2u.h>
#include <benchmarks/archBenchmarks/setNav3u.h>
#include <benchmarks/archBenchmarks/setNav4u.h>
#include <benchmarks/archBenchmarks/spacecraft/spacecraft.h>
#include <benchmarks/bouncingBall.h>
#include <benchmarks/constantDynamics/constantMotion.h>
#include <benchmarks/constantDynamics/constantMotion.h>
#include <benchmarks/fiveDimSys.h>
#include <benchmarks/navigation/nav04Timed.h>
#include <benchmarks/navigation/nav22Timed.h>
#include <benchmarks/navigation/nav25Timed.h>
#include <benchmarks/navigation/nav30Timed.h>
#include <benchmarks/navigation/navigation5by5WithOutTime.h>
#include <benchmarks/navigation/navigationBenchmark.h>
#include <benchmarks/navigation/navigationBenchmark.h>
#include <benchmarks/navigation/navigationTimed3by3.h>
#include <benchmarks/navigation/navT02Timed.h>
#include <benchmarks/navigation/navT04Timed.h>
#include <benchmarks/navigation/navT07Timed.h>
#include <benchmarks/navigation/navT13Timed.h>
#include <benchmarks/oscillatorModel/f_osc_32.h>
#include <benchmarks/oscillatorModel/f_osc_32_timed.h>
#include <benchmarks/oscillatorModel/f_osc_8.h>
#include <benchmarks/oscillatorModel/f_osc_8_timed.h>
#include <benchmarks/oscillatorModel/Oscillator.h>
#include <benchmarks/oscillatorModel/Oscillator_timed.h>
#include <benchmarks/timedBouncingBall.h>
#include <benchmarks/ttEthernet/TTEthernetModel.h>
#include <benchmarks/vehiclePlatoon/vehicle10_platoon.h>
#include <benchmarks/vehiclePlatoon/vehicle5_platoon.h>
#include <benchmarks/waterlevelController/watertank_controller.h>
#include <core/math/uniSphere.h>
#include <cstring>
#include <utility>


#include "core/continuous/polytope/polytope.h"
#include "core/hybridAutomata/hybridAutomata.h"
#include "core/symbolicStates/initialState.h"
#include "application/userOptions.h"

typedef std::pair<int, polytope::ptr> forbidden;

/* Sets the reachability options given by the user */

void set_params(std::list<initial_state::ptr>& init_state,
		userOptions& op, ReachabilityParameters& reach_parameters,
		std::vector<forbidden>& forbidden_states);

/**
 * Creates the pre-defined hybrid automata models in memory with config parameters.
 */

void load_ha_model(std::list<initial_state::ptr>& init_state,
		hybrid_automata& ha, ReachabilityParameters& reach_parameters, userOptions& op);

#endif
