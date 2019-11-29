
#include <iostream>
#include <fstream>
#include "boost/timer/timer.hpp"
#include "utilities/cpu_utilities/cpu_utilities.h"	//cpu usage functions
#include "utilities/memory_utilities/memory_usage.h" //memory usage functions
#include "utilities/statistics.h"
#include "core/math/uni_sphere.h"
#include "application/sf_directions.h"
#include "application/DataStructureDirections.h"
#include "core/continuous/Polytope/Polytope.h"
#include "core/math/matrix.h"
#include <boost/numeric/ublas/matrix.hpp>
#include "utilities/Template_Polyhedra.h"
#include "utilities/Post_Assignment.h"
#include "utilities/dump_abstractCE_list.h"
#include <list>
#include <utility>
#include <iterator>
#include "benchmarks/BouncingBall.h"
#include "benchmarks/TimedBouncingBall.h"
#include "benchmarks/Helicopter_model/HelicopterModel28Dim.h"
#include "benchmarks/FiveDimSys.h"
#include "benchmarks/Navigation_Benchmark/NavigationBenchmark.h"
#include "benchmarks/Rotation_Circle.h"
#include "benchmarks/Rotation_Circle_FourLocation.h"
#include "benchmarks/Rotation_Circle_One_Location.h"

//**************** Hybrid Automata Definition ***********************
#include "core/Reachability/reachability.h"

#include "core/HybridAutomata/Hybrid_Automata.h"
#include "core/HybridAutomata/Transition.h"
#include "core/HybridAutomata/Location.h"
#include "core/symbolic_states/symbolic_states.h"
#include "core/symbolic_states/initial_state.h"
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
#include "io/load_model.h"
#include "benchmarks/user_model/user_model.h"

#include "io/io_utility.h"
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

	// ----Trajectory Simulation
	if (boost::iequals(user_options.getEngine(),"simu")==true) {
		std::cout<<"Running simulation engine ... \n";
		simulationCaller(reach_parameters, Hybrid_Automata, init_state, user_options);
		return 0; //Only Trajectory Simulation is done
	}

// ----Section below consists of Reachability Analysis including counter-example generation.
	std::list<symbolic_states::ptr> Symbolic_states_list;

	boost::timer::cpu_timer timer, plottime;
	unsigned int number_of_times = 1;	//For reporting average

	timer.start();
	init_cpu_usage(); //initializing the CPU Usage utility to start recording usages
	for (unsigned int i = 1; i <= number_of_times; i++) { //Running in a loop of number_of_times to compute the average result

		// Calls the reachability computation routine.
		reachabilityCaller(Hybrid_Automata, init_state, reach_parameters,
				user_options, lp_solver_type_choosen, Solver_GLPK_Gurobi_GPU, forbidden_set,
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
