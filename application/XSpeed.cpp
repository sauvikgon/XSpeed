/**
 * The main file of XSpeed.
 * @Author: Rajarshi
 */

#include <iostream>
#include <fstream>
#include "utilities/cpu_utilities/cpu_utilities.h"	//cpu usage functions
#include "utilities/memory_utilities/memory_usage.h" //memory usage functions
#include "utilities/statistics.h"
#include "application/readCommandLine.h"
#include "application/simulationCaller.h"
#include "counterExample/WoFC_counter_example.h"
#include "core/continuous/Polytope/polytope.h"

#include "counterExample/abstractCE.h"

int main(int argc, char *argv[]) {


	ReachabilityParameters reach_parameters;
	userOptions user_options;
	std::list<initial_state::ptr> init_state;
	hybrid_automata Hybrid_Automata;
	std::pair<int, polytope::ptr> forbidden_set; //(locID1,Polytope1)
	std::list<abstractCE::ptr> ce_candidates; //object of class counter_example

	int lp_solver_type = 1;

	try{
		readCommandLine(argc, argv,user_options,Hybrid_Automata,init_state,reach_parameters,forbidden_set);
	}catch(...){
		std::cout<<"\nTerminating XSpeed, caused due to error in command-line inputs.\n";
		std::cout << "Try XSpeed --help to see the command-line options\n";
		exit(0);
	}

	// ----Trajectory Simulation
	if (boost::iequals(user_options.getEngine(),"simu")==true) {
		std::cout<<"Running simulation engine ... \n";
		simulationCaller(reach_parameters, Hybrid_Automata, init_state, user_options, forbidden_set);
		return 0; //Only Trajectory Simulation is done
	}

	// ----Section for Running Exp-Graph. This code is put only for experimental task.

	int	 runExpGraph_WoFC = 0;	// To run Exp-Graph Algorithm, that is, Explore the Graph. Note should assign a valid loc-id in the forbidden set (and not -1, unlike FC algo)
	if (runExpGraph_WoFC) {
		bool found_CE = runWoFC_counter_example(Hybrid_Automata, init_state, forbidden_set, user_options);

		if (found_CE) {
			string cmdStr1;
			//cmdStr1.append("graph -TX -BC -W 0.008 out.txt -s -m 3 bad_poly -s -m 2 init_poly");
			cmdStr1.append("graph -TX -BC -W 0.008 out.txt");
			system(cmdStr1.c_str());
		}

		return 0;
	}

//End of Section Exp-Graph.




	// Reachability with CE generation
	std::list<symbolic_states::ptr> Symbolic_states_list;

	boost::timer::cpu_timer timer, plottime;
	unsigned int number_of_times = 1;	//For reporting average

	timer.start();
	init_cpu_usage(); //initializing the CPU Usage utility to start recording usages
	for (unsigned int i = 1; i <= number_of_times; i++) { //Running in a loop of number_of_times to compute the average result

		// Calls the reachability computation routine.
		reachabilityCaller(Hybrid_Automata, init_state, reach_parameters,
				user_options, lp_solver_type, forbidden_set,
				Symbolic_states_list, ce_candidates);
	}
	timer.stop();
	double cpu_usage = getCurrent_ProcessCPU_usage();
	long mem_usage = getCurrentProcess_PhysicalMemoryUsed();
	print_statistics(timer,cpu_usage,mem_usage, number_of_times, "Reachability Analysis and CE Search");

	// printing the first initial polytope in the init_poly file
	polytope::ptr init_poly = (*init_state.begin())->getInitialSet();
	init_poly->print2file("./init_poly",user_options.get_first_plot_dimension(),user_options.get_second_plot_dimension());

	std::list<symbolic_states::ptr>::iterator it;

	/** Choosing from the output format and showing results	 */
	plottime.start();
	show(Symbolic_states_list, user_options);
	plottime.stop();
	print_statistics(plottime,"Plotting");


	return 0;
}
