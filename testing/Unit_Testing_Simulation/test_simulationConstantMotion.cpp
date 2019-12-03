#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "counterExample/simulation.h"
#include "application/DataStructureDirections.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>

#include "../../benchmarks/ConstantMotion/ConstantMotion.h"
#include "../../benchmarks/Navigation_Benchmark/NavigationBenchmark.h"
#include "../../benchmarks/TimedBouncingBall.h"
#include "../../core/math/matrix.h"
#include "../../core/symbolic_states/initial_state.h"



using namespace std;

SUITE(SimulationTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};


TEST_FIXTURE(Example, TimeSimulationConstantMotion) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.1;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0,2); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	SetConstantMotion(ha,init_state,reach_parameters);

	std::vector<double> x0(3);
	x0[0]=0.5;x0[1]=0.2;x0[2]=0;

	// testing HA location simulation
	sim_start_point w;
	w.locptr = ha.getInitial_Location();
	w.cross_over_time = 0;
	w.start_point = x0;

	sim->simulateHaLocation(w,0,reach_parameters.TimeBound,ha);
	//sim->print_trace_to_outfile("constant_motion");

}

TEST_FIXTURE(Example, TestManySimulationConstantMotion) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.1;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0,2); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	SetConstantMotion(ha,init_state,reach_parameters);


	polytope::ptr initialset=init_state.front()->getInitialSet();

	// testing HA location simulation
	unsigned int n=10; // the number of start points
	std::vector<sim_start_point> start_pts = sim->get_start_points(n, initialset, ha.getInitial_Location());

	assert(start_pts.size() == n);

	for(unsigned int i=0;i<n;i++)
	{
		sim->simulateHaLocation(start_pts[i],0,reach_parameters.TimeBound,ha);
//		sim->print_trace_to_outfile("constant_motion_trace");
	}

}

TEST_FIXTURE(Example, TestHaSimulationConstantMotion) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.1;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0,2); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	SetConstantMotion(ha,init_state,reach_parameters);


	polytope::ptr initialset=init_state.front()->getInitialSet();

	// testing HA location simulation
	unsigned int n=10; // the number of start points
	std::vector<sim_start_point> start_pts = sim->get_start_points(n, initialset, ha.getInitial_Location());

	assert(start_pts.size() == n);

	for(unsigned int i=0;i<n;i++)
	{
		sim->simulateHa(start_pts[i],0,reach_parameters.TimeBound,ha);
//		sim->print_trace_to_outfile("constant_motion_trace");
	}
}

TEST_FIXTURE(Example, ParTestHaConstantMotion) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.1;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0,2); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	SetConstantMotion(ha,init_state,reach_parameters);


	polytope::ptr initialset=init_state.front()->getInitialSet();

	unsigned int n=10; // the number of start points

	sim->parSimulateHa(n,initialset, 0,reach_parameters.TimeBound,ha);
	sim->print_trace_to_outfile("constant_motion_trace");
}

}


