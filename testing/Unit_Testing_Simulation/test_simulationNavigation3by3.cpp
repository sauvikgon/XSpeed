#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "core_system/math/matrix.h"
#include "counterExample/simulation.h"
#include "application/DataStructureDirections.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>
#include "core_system/symbolic_states/initial_state.h"
#include "Hybrid_Model_Parameters_Design/TimedBouncingBall.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationTimed3by3.h"




using namespace std;

SUITE(SimulationTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};


TEST_FIXTURE(Example, SimulationTestNAV3by3) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0, 1); //output dimensions
	sim->set_time_step(reach_parameters.time_step);

	Set_NavTimed_Parameters(ha, init_state, reach_parameters);

	std::vector<double> x0(5);
	x0[0] = 0.5; x0[1] = 0.4; x0[2]=0.8; x0[3]=0, x0[4]=0;

	// testing HA location simulation
	sim_start_point w;
	w.locptr = ha.getInitial_Location();
	w.cross_over_time = 0;
	w.start_point = x0;

	sim->simulateHaLocation(w,0,reach_parameters.TimeBound,ha);
	sim->print_trace_to_outfile("navigation3x3_trace");

}

}


