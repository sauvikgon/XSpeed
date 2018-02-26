/*
 * simulationCaller.cpp
 *
 *  Created on: 26-Feb-2018
 *      Author: amit
 */

#include "application/simulationCaller.h"
#include "core_system/continuous/Polytope/Polytope.h"


void simulationCaller(ReachabilityParameters& reach_parameters,
		hybrid_automata& ha, std::list<initial_state::ptr> init_state,
		userOptions& op) {

	load_ha_models(init_state, ha, reach_parameters, op); //Loads the model and reach-parameters

	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(op.get_first_plot_dimension(), op.get_second_plot_dimension()); //output dimensions
	sim->set_time_step(reach_parameters.time_step);


	std::list<initial_state::ptr>::iterator it;
	it = init_state.begin();
	polytope::ptr initialset = (*it)->getInitialSet();

	// testing HA location simulation
	unsigned int n = op.get_simu_init_sampling_points(); // the number of start points
	unsigned int max_jump = op.get_bfs_level(); //level 0 means only first breadth, 1 means the next level bfs
	std::cout<<"Testing the number of point n= <<"<< n<<std::endl;
	std::vector<sim_start_point> start_pts = sim->get_start_points(n, initialset, ha.getInitial_Location());

	assert(start_pts.size() == n);

	if (op.get_simu_algo() == 1) { //Sequential Simulation with 'n' initial sampling-start-points
		std::cout << "\nRunning Sequential BFS Simulation Algorithm.\n";
		for (unsigned int i = 0; i < n; i++) {
			sim->simulateHaLocation(start_pts[i], 0, reach_parameters.TimeBound, ha);
			sim->print_trace_to_outfile("sequentialnavigation9x9_trace");
		}
	} else if (op.get_simu_algo() == 2) { //Adaptation of Gerard J. Holzmann's algorithm for Simulation
		std::cout << "\nRunning Simulation using adaptation of Gerard J. Holzmann's algorithm.\n";
		//Take time recording here
		sim->parSimulateHa(n, initialset, 0, reach_parameters.TimeBound, ha, max_jump); // Holzmann algorithm adaptation without lock for containment check
		//stop reading time
	}
	//TODO:: if parSimulateHa generates "list <list<trace_points>>" then can call function to merge list-list traces into one list of traces.
	sim->print_trace_to_outfile(op.getOutFilename());
}
//
