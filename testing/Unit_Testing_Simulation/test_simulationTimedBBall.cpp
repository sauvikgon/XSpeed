#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "core_system/math/matrix.h"
#include "counterExample/simulation.h"
#include "application/DataStructureDirections.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <list>
#include <cmath>
#include "core_system/symbolic_states/initial_state.h"
#include "Hybrid_Model_Parameters_Design/TimedBouncingBall.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark.h"




using namespace std;

SUITE(SimulationTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};

TEST_FIXTURE(Example, SimulationTestTimedBBall) {

	hybrid_automata ha;
		std::list<initial_state::ptr> init_state;
		ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 10; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->insert_to_map("x",0);
	sim->insert_to_map("v",1);
	sim->insert_to_map("t",2);

	std::vector<double> x0(3);
	x0[0] = 20.1; x0[1] = 0; x0[2]=0;


	sim->set_out_dimension(2,0);//output dimensions
    sim->set_time_step(reach_parameters.time_step);

    SetTimedBouncingBall_2initSet(ha,init_state,reach_parameters);

    //SetTimedBouncingBall_ParametersHystOutput(ha, init_state, reach_parameters);
	std::list<initial_state::ptr>::iterator it;
	it=init_state.begin();
	polytope::ptr initialset=(*it)->getInitialSet();
	//sim->global_simulation(ha,initialset,locID,reach_parameters);
	// testing HA location simulation
	sim_start_point w;

	w.locptr = ha.getInitial_Location();
	w.cross_over_time = 0;
	w.start_point = x0;

	sim->simulateHaLocation(w,0,reach_parameters.TimeBound,ha);
	//sim->print_trace_to_outfile("timedBball_trace");
}

TEST_FIXTURE(Example, ManySimulationTestTimedBBall) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 10; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations



	simulation::ptr sim = simulation::ptr(new simulation());

	sim->insert_to_map("x",0);
	sim->insert_to_map("v",1);
	sim->insert_to_map("t",2);


	sim->set_out_dimension(2,0);//output dimensions
    sim->set_time_step(reach_parameters.time_step);

    SetTimedBouncingBall_2initSet(ha,init_state,reach_parameters);

    //SetTimedBouncingBall_ParametersHystOutput(ha, init_state, reach_parameters);
	std::list<initial_state::ptr>::iterator it;
	it=init_state.begin();
	polytope::ptr initialset=(*it)->getInitialSet();

	// testing HA location simulation
	unsigned int n=10; // the number of start points
	std::vector<sim_start_point> start_pts = sim->get_start_points(n, initialset, ha.getInitial_Location());

	assert(start_pts.size() == n);

	for(unsigned int i=0;i<n;i++)
	{
		sim->simulateHaLocation(start_pts[i],0,reach_parameters.TimeBound,ha);
//		sim->print_trace_to_outfile("timedBball_trace");
	}
}

TEST_FIXTURE(Example, HaSimulationTestTimedBBall) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 10; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations



	simulation::ptr sim = simulation::ptr(new simulation());

	sim->insert_to_map("x",0);
	sim->insert_to_map("v",1);
	sim->insert_to_map("t",2);


	sim->set_out_dimension(2,0);//output dimensions
    sim->set_time_step(reach_parameters.time_step);

    SetTimedBouncingBall_2initSet(ha,init_state,reach_parameters);

    //SetTimedBouncingBall_ParametersHystOutput(ha, init_state, reach_parameters);
	std::list<initial_state::ptr>::iterator it;
	it=init_state.begin();
	polytope::ptr initialset=(*it)->getInitialSet();

	// testing HA location simulation
	unsigned int n=10; // the number of start points
	std::vector<sim_start_point> start_pts = sim->get_start_points(n, initialset, ha.getInitial_Location());

	assert(start_pts.size() == n);

	for(unsigned int i=0;i<n;i++)
	{
		sim->simulateHa(start_pts[i],0,reach_parameters.TimeBound,ha);
//		sim->print_trace_to_outfile("timedBball_trace");
	}
}

TEST_FIXTURE(Example, ParHaSimulationTestTimedBBall) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations



	simulation::ptr sim = simulation::ptr(new simulation());

	sim->insert_to_map("x",0);
	sim->insert_to_map("v",1);
	sim->insert_to_map("t",2);


	sim->set_out_dimension(2,0);//output dimensions
    sim->set_time_step(reach_parameters.time_step);

    SetTimedBouncingBall_2initSet(ha,init_state,reach_parameters);

    //SetTimedBouncingBall_ParametersHystOutput(ha, init_state, reach_parameters);
	std::list<initial_state::ptr>::iterator it;
	it=init_state.begin();
	polytope::ptr initialset=(*it)->getInitialSet();

	// testing HA location simulation
	unsigned int n=10; // the number of start points

	sim->parSimulateHa(n,initialset, 0,reach_parameters.TimeBound,ha);
	sim->print_trace_to_outfile("timedBball_trace");

}

}


