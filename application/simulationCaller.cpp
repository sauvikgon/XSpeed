
#include "application/simulationCaller.h"
#include "core/continuous/polytope/polytope.h"


void simulationCaller(hybrid_automata& ha, std::list<initial_state::ptr>& init_state, ReachabilityParameters& reach_parameters,
		std::pair<int, polytope::ptr>& forbidden_set, userOptions& op) {
	
	simulation::ptr sim = simulation::ptr(new simulation());

	sim->set_out_dimension(op.get_first_plot_dimension(), op.get_second_plot_dimension()); //output dimensions
	sim->set_time_step(op.get_timeStep());


	std::list<initial_state::ptr>::iterator it;
	it = init_state.begin();
	polytope::ptr initialset = (*it)->getInitialSet();

	// testing HA location simulation
	unsigned int n = op.get_simu_init_points(); // the number of start points

	unsigned int max_jump = op.get_bfs_level(); //level 0 means only first breadth, 1 means the next level bfs

	if(n==1)
		std::cout<<"Generating " << n << " trajectory" << std::endl;
	else
		std::cout<<"Generating " << n << " trajectories" << std::endl;

	boost::timer::cpu_timer tsim, plottime;
	tsim.start();
	if (op.get_simu_algo() == 1) { //Sequential Simulation with 'n' initial sampling-start-points
		std::cout << "\nComputing trajectories Sequentially.\n";
		//Computation time of n sampling start_points is to be recorded for a fair comparison with parSimulateHa()
		std::vector<sim_start_point> start_pts = sim->get_start_points(n, initialset, ha.getInitialLocation());
		assert(start_pts.size() == n);

		bool is_safe = true;
		unsigned int num_unsafe_traj = 0;
		for (unsigned int i = 0; i < n; i++) {
			is_safe = sim->simulateHa(start_pts[i], 0, op.get_timeHorizon(), ha, forbidden_set, max_jump);
			if(!is_safe) num_unsafe_traj++;
		}
		std::cout << num_unsafe_traj << " trajectories violated safety constraint out of " << n << std::endl;

	} else if (op.get_simu_algo() == 2) { //Adaptation of Gerard J. Holzmann's algorithm for Simulation
		std::cout << "\nComputing trajectories in parallel using an adaptation of Gerard J. Holzmann's algorithm.\n";
		//Take time recording here
		sim->parSimulateHa(n, initialset, 0, op.get_timeHorizon(), ha, forbidden_set, max_jump); // Holzmann algorithm adaptation without lock for containment check

	}
	tsim.stop();

	double wall_clock, plotTime_clock;
	wall_clock = tsim.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double sim_Time = wall_clock / (double) 1000;
	std::cout << "\nSIMULATION TIME::Boost Time taken:Wall  (in Seconds) = " << sim_Time << std::endl;
	//TODO:: if parSimulateHa generates "list <list<trace_points>>" then can call function to merge list-list traces into one list of trac
	std::ofstream myfile;
	myfile.open(op.getOutFilename().c_str(),std::ofstream::out);
	myfile.close();
	plottime.start();
	sim->print_trace_to_outfile(op.getOutFilename());
	plottime.stop();
	plotTime_clock = plottime.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double plot_Time = plotTime_clock / (double) 1000;
	std::cout << "\nSIMULATION Plotting TIME::Boost Time taken:Wall  (in Seconds) = " << plot_Time << std::endl;

	string cmdStr1;
	cmdStr1.append("graph -TX -BC -m 0 ");
	cmdStr1.append(op.getOutFilename().c_str());
	system(cmdStr1.c_str());
}
//
