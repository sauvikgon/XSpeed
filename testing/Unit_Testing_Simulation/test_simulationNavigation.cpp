#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "counterExample/simulation.h"
#include "application/DataStructureDirections.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>

#include "../../benchmarks/Navigation_Benchmark/NavigationBenchmark.h"
#include "../../benchmarks/TimedBouncingBall.h"
#include "../../core/math/matrix.h"
#include "../../core/symbolic_states/initial_state.h"
//#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationTimed3by3.h"




using namespace std;

SUITE(SimulationTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};




TEST_FIXTURE(Example, SimulationTestNAV) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0, 1); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	SetNavigationBenchMark4Var(ha, init_state, reach_parameters); //Paper's Model

	std::vector<double> x0(4);
	x0[0] = 0.5; x0[1] = 1.5; x0[2]=0.7; x0[3]=1.1;

	// testing HA location simulation
	sim_start_point w;
	w.locptr = ha.getInitial_Location();
	w.cross_over_time = 0;
	w.start_point = x0;

	sim->simulateHaLocation(w,0,reach_parameters.TimeBound,ha);
	//sim->print_trace_to_outfile("navigation_trace");

}

TEST_FIXTURE(Example, TestManySimulationNAV) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0, 1); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	SetNavigationBenchMark4Var(ha, init_state, reach_parameters); //Paper's Model
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
//		sim->print_trace_to_outfile("navigation_trace");
	}
}
TEST_FIXTURE(Example, TestHaSimulationNAV) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0, 1); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	SetNavigationBenchMark4Var(ha, init_state, reach_parameters); //Paper's Model
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
//		sim->print_trace_to_outfile("navigation_trace");
	}
}
TEST_FIXTURE(Example, ParTestHaSimulationNAV) {

	hybrid_automata ha;
	std::list<initial_state::ptr> init_state;
	ReachabilityParameters reach_parameters;

	reach_parameters.TimeBound = 100; //Total Time Interval
	reach_parameters.time_step = 0.01;
	reach_parameters.Iterations = reach_parameters.TimeBound/reach_parameters.time_step; // number of iterations

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(0, 1); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	SetNavigationBenchMark4Var(ha, init_state, reach_parameters);

	std::list<initial_state::ptr>::iterator it;
	it=init_state.begin();
	polytope::ptr initialset=(*it)->getInitialSet();

	// testing HA location simulation
	unsigned int n=10; // the number of start points

	sim->parSimulateHa(n,initialset, 0,reach_parameters.TimeBound,ha);
	sim->print_trace_to_outfile("navigation_trace");
}
}


