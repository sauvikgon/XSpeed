
#include <iostream>
#include <fstream>
#include "boost/timer/timer.hpp"
#include "InputOutput/cpu_utilities/cpu_utilities.h"	//cpu usage functions
#include "InputOutput/memory_utilities/memory_usages.h" //memory usage functions
#include "core_system/math/uni_sphere.h"
#include "application/sf_directions.h"
#include "application/DataStructureDirections.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"
#include <boost/numeric/ublas/matrix.hpp>
#include "Utilities/Template_Polyhedra.h"
#include "Utilities/Post_Assignment.h"
#include "Utilities/dump_abstractCE_list.h"
#include <list>
#include <utility>
#include <iterator>
#include "Hybrid_Model_Parameters_Design/BouncingBall.h"
#include "Hybrid_Model_Parameters_Design/TimedBouncingBall.h"
#include "Hybrid_Model_Parameters_Design/Helicopter_model/HelicopterModel28Dim.h"
#include "Hybrid_Model_Parameters_Design/FiveDimSys.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle_FourLocation.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle_One_Location.h"

//**************** Hybrid Automata Definition ***********************
#include "core_system/Reachability/reachability.h"

#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/HybridAutomata/Transition.h"
#include "core_system/HybridAutomata/Location.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"
//**************** Hybrid Automata Definition ***********************
#include "application/All_PP_Definition.h"

// *********** Command Line Boost Program Options ********
#include <boost/program_options/config.hpp>
#include <boost/program_options/options_description.hpp>

#include "boost/program_options.hpp"
#include <boost/config.hpp>
#include <boost/program_options/detail/config_file.hpp>

#include <boost/program_options/parsers.hpp>
// *********** Command Line Boost Program Options ********
#include "plotter_utility.h"
// *********** User Selected Model ***************
#include "Hybrid_Model_Parameters_Design/load_model.h"
#include "Hybrid_Model_Parameters_Design/user_model/user_model.h"

#include "InputOutput/io_utility.h"
// *******counter example **************/
#include "counterExample/concreteCE.h"
#include "counterExample/WoFC_counter_example.h"



#include "application/reachabilityCaller.h"
#include "application/readCommandLine.h"
#include "application/simulationCaller.h"

namespace po = boost::program_options;

std::list<initial_state::ptr> init_state;
//**************** Hybrid Automata Definition ***********************
ReachabilityParameters reach_parameters;
//**************** Hybrid Automata Definition ***********************
hybrid_automata Hybrid_Automata;
//**************** Hybrid Automata Definition ***********************
int dir_nums, transition_iterations;
int dims;
std::vector<std::vector<double> > directions; //List of all directions
math::matrix<double> Real_Directions; //List of all directions
typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

polytope initial_polytope_I, invariant, gaurd_polytope(true);
unsigned int HybridSystem_Model_Type;
unsigned int Directions_Type;
unsigned int Uniform_Directions_Size;

	std::pair<int, polytope::ptr> forbidden_set; //(locID1,Polytope1)}
	std::string bad_state; // string to capture the bad state description given by the user
	std::list<abstractCE::ptr> ce_candidates; //object of class counter_example
	userOptions user_options;
	//int number_of_times = 1; //Make this 1 for Memory Profiling
//	unsigned int number_of_streams = 1;
//	unsigned int Total_Partition; //for Parallel Iterations Algorithm :: number of partitions/threads
	int lp_solver_type_choosen = 1; //	1 for GLPK and 2 for Gurobi
	int Solver_GLPK_Gurobi_GPU = 3; //if Algorithm == 11 then (1 for GLPK; 2 for Gurobi; 3 for GPU)
	std::ofstream outFile;
	math::matrix<double> vertices_list;
	po::options_description desc("XSpeed options");
	po::variables_map vm;
	const char *stFileNameWithPath;

int main(int argc, char *argv[]) {

	try{
		readCommandLine(argc, argv,user_options,Hybrid_Automata,init_state,reach_parameters,forbidden_set);
	}catch(...){
		std::cout<<"\nTerminating XSpeed, caused due to error in command-line inputs.\n";
		std::cout << "Try XSpeed --help to see the command-line options\n";
		exit(0);
	}

// ----Section for Trajectory Simulation
	if (boost::iequals(user_options.getEngine(),"simu")==true) {
		std::cout<<"Trajectory simulation ... !!!\n";
		simulationCaller(reach_parameters, Hybrid_Automata, init_state, user_options);
		return 0; //Only Trajectory Simulation is done
	}

	std::cout << std::fixed; //to assign precision on the std::output stream
	std::cout.precision(7);

// ----Section for Running WoFC.

int	 runWoFC = 0;	// To run WoFC, remember to give a valid loc id for the forbidden set (and not -1, unlike FC algo)
	if (runWoFC) {

		std::list<initial_state::ptr>::iterator iit;
		iit = init_state.begin();

		bool found_CE = runWoFC_counter_example(Hybrid_Automata, init_state, forbidden_set, user_options);

		// printing the first initial polytope in the init_poly file
		polytope::ptr init_poly = (*init_state.begin())->getInitialSet();
		init_poly->print2file("./init_poly",user_options.get_first_plot_dimension(),user_options.get_second_plot_dimension());

//		if (forbidden_set.second != NULL){
//			//std::cout<<"Forbiddend Set is a Polytope and not NULL"<<std::endl;
//			polytope::ptr badpoly = forbidden_set.second;
//			badpoly->print2file("./bad_poly",user_options.get_first_plot_dimension(),user_options.get_second_plot_dimension());
//			//Todo:: note that forbidden set is not in use in the Algorithm WoFC, so the output bad_trace may not intersect with the bad_set.
//		} else {
//			location::ptr badLocation;
//			badLocation = Hybrid_Automata.getLocation(destLoc);
//			polytope::ptr loc_inv = badLocation->getInvariant();
//			loc_inv->print2file("./bad_poly",user_options.get_first_plot_dimension(),user_options.get_second_plot_dimension());
//			//Todo:: note that if the invariant does not have constraints on the plot_dimensions, then "print2file()" may throw exception
//		}
		if (found_CE) {
			string cmdStr1;
			cmdStr1.append("graph -TX -BC -W 0.008 bad_trace.o -s -m 3 bad_poly -s -m 2 init_poly");
			system(cmdStr1.c_str());

		}
		return 0;
	}

// ----Section below consists of Reachability Analysis including counter-example generation.
	std::list<symbolic_states::ptr> Symbolic_states_list;

	double Avg_wall_clock = 0.0, Avg_user_clock = 0.0, Avg_system_clock = 0.0;
	double Avg_cpu_use = 0.0;
	long total_mem_used = 0;
	double cpu_usage;
	boost::timer::cpu_timer tt1, plottime;
	unsigned int number_of_times = 1;	//Taking Average of 5 readings

	for (unsigned int i = 1; i <= number_of_times; i++) { //Running in a loop of number_of_times to compute the average result
		init_cpu_usage(); //initializing the CPU Usage utility to start recording usages
		tt1.start();

		// Calls the reachability computation routine.
		reachabilityCaller(Hybrid_Automata, init_state, reach_parameters,
				user_options, lp_solver_type_choosen, Solver_GLPK_Gurobi_GPU, forbidden_set,
				Symbolic_states_list, ce_candidates);
		tt1.stop();

		// printing the first initial polytope in the init_poly file
		polytope::ptr init_poly = (*init_state.begin())->getInitialSet();
		init_poly->print2file("./init_poly",user_options.get_first_plot_dimension(),user_options.get_second_plot_dimension());

		//------
		cpu_usage = getCurrent_ProcessCPU_usage();
		Avg_cpu_use = Avg_cpu_use + cpu_usage;
		//todo:: if the size of transition is greater than it can compute there is segmentation fault

		double wall_clock, user_clock, system_clock;
		wall_clock = tt1.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		user_clock = tt1.elapsed().user / 1000000;
		system_clock = tt1.elapsed().system / 1000000;

		if (user_options.get_algorithm() == 6) {	//GPU_SF
			//11 is GPU:: First execution of GPU includes warm-up time, so this time should not be included for averaging
			if (i == 1) { //first run for averaging
				continue; //do not include time here
			}
			Avg_wall_clock = Avg_wall_clock + wall_clock;
			Avg_user_clock = Avg_user_clock + user_clock;
			Avg_system_clock = Avg_system_clock + system_clock;
		} else { //Average all runs
			Avg_wall_clock = Avg_wall_clock + wall_clock;
			Avg_user_clock = Avg_user_clock + user_clock;
			Avg_system_clock = Avg_system_clock + system_clock;
		}
	}
	Avg_cpu_use = Avg_cpu_use / number_of_times;
	total_mem_used = getCurrentProcess_PhysicalMemoryUsed();

	if (user_options.get_algorithm() == 6) {	//GPU_SF
		Avg_wall_clock = Avg_wall_clock / (number_of_times - 1);
		Avg_user_clock = Avg_user_clock / (number_of_times - 1);
		Avg_system_clock = Avg_system_clock / (number_of_times - 1);
	} else {
		Avg_wall_clock = Avg_wall_clock / number_of_times;
		Avg_user_clock = Avg_user_clock / number_of_times;
		Avg_system_clock = Avg_system_clock / number_of_times;
	}

//	std::cout << std::fixed; //to assign precision on the std::output stream
//	std::cout.precision(7);


	double return_Time = Avg_wall_clock / (double) 1000;


	std::cout << "-------------Performance and Memory Statistics-----------: " << std::endl;
	std::cout << "\nCPU Usage:(%) = " << Avg_cpu_use << std::endl;
	std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << return_Time
			<< std::endl;
	std::cout << "\nBoost Time taken:User  (in Seconds) = "
			<< Avg_user_clock / (double) 1000 << std::endl;
	std::cout << "\nBoost Time taken:System  (in Seconds) = "
			<< Avg_system_clock / (double) 1000 << std::endl;
	cout << endl << "Number of Vectors = "
			<< reach_parameters.Directions.size1();

	cout << endl << "Memory Usages = "
			<< (double) (total_mem_used / 1024.0) / number_of_times << " MB\n";

	// Recording the analysis time in a statistics for reporting in a paper
	std::ofstream myfile;
	if(CE_ALGO_TYPE ==1) //CE with FC
		myfile.open("statistics_FC.txt",ios::out | ios::app);
	else if(CE_ALGO_TYPE == 2) // CE with WoFC on RA given absCEs
		myfile.open("statistics_WoFC.txt",ios::out | ios::app);
	else {}


	myfile << "Flowpipe construction time (user time in secs) " << Avg_user_clock / (double) 1000 - ce_search_time/(double) 1000 << "; ";
	myfile << "Falsification time (user time in secs) " << Avg_user_clock / (double) 1000 << std::endl << std::endl;
	myfile.close();

	std::list<symbolic_states::ptr>::iterator it;

	/** Choosing from the output format options	 */
	plottime.start();
	if(user_options.getOutputFormatType().compare("GEN")==0) {
		//Vertex-Enumeration using old algorithm of recursively searching in quadrants But Faster than HoughTransformation
		vertex_generator(Symbolic_states_list,user_options); //Generating Vertices using recursive-quadrant-search algorithm, can be plotted using GNU plotutil
		//SFM_for_MatLab(Symbolic_states_list,user_options); //Generating Matrices (dir and SFM) as file output, which can be used in MatLab by ESP algorithm

		//Our paper's Algorithm but slower than vertex_generator()
		//vertex_generator_HoughTransformation(Symbolic_states_list,user_options); //Generating Vertices using Sequential sampling of Hough Space, can be plotted using GNU plotutil

		/* Running gnuplotutil to plot output */
		string cmdStr1;
		cmdStr1.append("graph -TX -BC ");
		cmdStr1.append(user_options.getOutFilename().c_str());
		system(cmdStr1.c_str());
	} else if(user_options.getOutputFormatType().compare("INTV")==0) {
		print_all_intervals(Symbolic_states_list);
	}
	plottime.stop();

	double wall_clockPlot;
	wall_clockPlot = plottime.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double plotTime = wall_clockPlot / (double) 1000;	//convert milliseconds to Seconds
	std::cout << "\nBoost Wall Time for Plotting (in Seconds) = " << plotTime << std::endl;

	return 0;
}
