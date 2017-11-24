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


#include "application/reachabilityCaller.h"
#include "application/readCommandLine.h"


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
		readCommandLine(argc, argv,user_options,Hybrid_Automata,init_state,reach_parameters);
	}catch(...){
		std::cout<<"\nTerminating XSpeed, caused due to error in command-line inputs.\n";
		std::cout << "Try XSpeed --help to see the command-line options\n";
		exit(0);
	}

	// Parse the forbidden state string to make a polytope
	if (!user_options.get_forbidden_set().empty()) {
		string_to_poly(user_options.get_forbidden_set(), forbidden_set);
	}

	std::list<symbolic_states::ptr> Symbolic_states_list;

	double Avg_wall_clock = 0.0, Avg_user_clock = 0.0, Avg_system_clock = 0.0;
	double Avg_cpu_use = 0.0;
	long total_mem_used = 0;
	double cpu_usage;
	boost::timer::cpu_timer tt1;
	unsigned int number_of_times = 1;	//Taking Average of 5 readings

	for (unsigned int i = 1; i <= number_of_times; i++) { //Running in a loop of number_of_times to compute the average result
		init_cpu_usage(); //initializing the CPU Usage utility to start recording usages
		tt1.start();

		//unsigned int transition_iters = user_options.get_bfs_level();

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

	std::cout << std::fixed; //to assign precision on the std::output stream
	std::cout.precision(7);


	double return_Time = Avg_wall_clock / (double) 1000;

	if (argc > 1) { //running from command Line for output generation
		//std::cout << return_Time; //running from command Line for output generation
		//----Disabling the console Output to Generate the Data using Shell Script

		std::cout << "\nCPU Usage:(%) = " << Avg_cpu_use << std::endl;
		std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << return_Time
				<< std::endl;
		std::cout << "\nBoost Time taken:User  (in Seconds) = "
				<< Avg_user_clock / (double) 1000 << std::endl;
		std::cout << "\nBoost Time taken:System  (in Seconds) = "
				<< Avg_system_clock / (double) 1000 << std::endl;
		cout << endl << "Number of Vectors = "
				<< reach_parameters.Directions.size1();

	}
	if (argc == 1) { //No argument or Running directly from the Eclipse Editor

		//----Disabling the console Output to Generate the Data using Shell Script
		std::cout << "\nCPU Usage:(%) = " << Avg_cpu_use << std::endl;
		std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << return_Time
				<< std::endl;
		std::cout << "\nBoost Time taken:User  (in Seconds) = "
				<< Avg_user_clock / (double) 1000 << std::endl;
		std::cout << "\nBoost Time taken:System  (in Seconds) = "
				<< Avg_system_clock / (double) 1000 << std::endl;
		cout << endl << "Number of Vectors = "
				<< reach_parameters.Directions.size1();
	}
	cout << endl << "Memory Usages = "
			<< (double) (total_mem_used / 1024.0) / number_of_times << " MB\n";

	std::list<symbolic_states::ptr>::iterator it;
	/** Choosing from the output format options	 */
	if(user_options.getOutputFormatType().compare("GEN")==0) {
		//Vertex-Enumeration using old algorithm of recursively searching in quadrants
		vertex_generator(Symbolic_states_list,user_options); //Generating Vertices as output which can be plotted using gnuplot utilites
		SFM_for_MatLab(Symbolic_states_list,user_options); //Generating Vertices as output which can be plotted using gnuplot utilites
		//Sequential sampling of Hough Space

		/* Running gnuplotutil to plot output */
		string cmdStr1;
		cmdStr1.append("graph -TX -BC ");
		cmdStr1.append(user_options.getOutFilename().c_str());
		system(cmdStr1.c_str());
	} else if(user_options.getOutputFormatType().compare("INTV")==0) {
		print_all_intervals(Symbolic_states_list);
	}

	/*
	 * counterExample utility. Plot the location sequence of every abstract CE in a file
	 */
	dump_abstractCE_list(ce_candidates);
	// create a template abstract ce to filter
	std::vector<unsigned int> template_seq(0);
	//template_seq = {3,4,2,1,3,4,2,1,3,4};

	// create a filter template here

	/** End of debug */
	bool real_ce = false;
	double error_tol = 1e-6; // splicing error tolerance

	tt1.start(); // start time
	for (std::list<abstractCE::ptr>::iterator it = ce_candidates.begin(); it!=ce_candidates.end();it++) {

		abstractCE::ptr abs_ce = *(it);
		concreteCE::ptr ce;
		// add a filter function to search for concrete ce only in a specific abstract trace
		bool search_ce = abs_ce->filter(template_seq);
		if(search_ce){
			//tt1.start(); // start time
			ce = abs_ce->get_validated_CE(error_tol);
			//tt1.stop(); //stop time
		}
		else continue;

		if(ce->is_empty()){
			std::cout << "Cannot Splice Trajectories with Accepted Error Tolerance\n";
			std::cout << "Looking for Other Abstract CE to Unsafe Set\n";
			continue;
		} else {
			ce->set_automaton(abs_ce->get_automaton());
			std::string tracefile = "./bad_trace.o";
			ce->plot_ce(tracefile,
					user_options.get_first_plot_dimension(),
					user_options.get_second_plot_dimension());
			real_ce = true;
			break;
		}
	}
	tt1.stop(); //stop time

	//timers
	double user_clock;
	user_clock = tt1.elapsed().user / 1000000;
	//--end of timers
	if (!real_ce) {
		std::cout << "******** No Violation of Safety Property ********\n";
		std::cout << "Time to search concrete counter-examples (milliseconds):" << user_clock << std::endl;
	} else {
		std::cout << "******** Detected Violation of Safety Property  ********\n";
		std::cout << "Counter Example Trace Plotted in the file bad_trace.o\n";
		std::cout << "Time to search counter-example (milliseconds):" << user_clock << std::endl;
	}

	cout << "\n******** Summary of XSpeed ********\n";
	return 0; //returning only the Wall time taken to execute the Hybrid System
}
