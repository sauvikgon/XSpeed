
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
#include <list>
#include <utility>
#include <iterator>
#include "Hybrid_Model_Parameters_Design/BouncingBall.h"
#include "Hybrid_Model_Parameters_Design/TimedBouncingBall.h"
#include "Hybrid_Model_Parameters_Design/Helicopter_model/HelicopterModel28Dim.h"
#include "Hybrid_Model_Parameters_Design/FiveDimSys.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark4Var.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle_FourLocation.h"
#include "Hybrid_Model_Parameters_Design/Rotation_Circle_One_Location.h"
#include "Hybrid_Model_Parameters_Design/user_model/user_model.h"

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

namespace po = boost::program_options;

initial_state::ptr init_state;
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


int main(int argc, char *argv[]) {

	std::pair<int, polytope::ptr> forbidden_set; //(locID1,Polytope1)}
	std::string bad_state; // string to capture the bad state description given by the user
	abstractCE::ptr ce;	//object of class counter_example
	userOptions user_options;

	//int number_of_times = 1; //Make this 1 for Memory Profiling
	unsigned int number_of_streams = 1;
	int lp_solver_type_choosen = 1; //	1 for GLPK and 2 for Gurobi
	int Solver_GLPK_Gurobi_GPU = 3; //if Algorithm == 11 then (1 for GLPK; 2 for Gurobi; 3 for GPU)
	unsigned int Total_Partition; //for Parallel Iterations Algorithm :: number of partitions/threads

	bool isConfigFileAssigned = false, isModelParsed = false;

	po::options_description desc("XSpeed options");
	po::variables_map vm;

	if (argc == 1) { //No argument:: When Running directly from the Eclipse Editor
		std::cout << "Missing arguments!\n";
		std::cout << "Try XSpeed --help to see the command-line options\n";
		exit(0);
	}

	desc.add_options()("help", "produce help message")
			("model", po::value<int>()->default_value(1),
			"set model for reachability analysis\n"
					"1.  Bouncing Ball Model: Variables{x,v} (Set to default)\n"
					"2.  Timed Bouncing Ball Model: Variables{x,v,t}\n"
					"3.  28-Dimensional Helicopter Controller Model: Variables{x1..x28}\n"
					"4.  Five dimensional Benchmark Model: Variables{x1..x5} \n"
					"5.  Navigation Benchmark Model-NAV01 (3 X 3): Variables{x1,x2,v1,v2}\n"
					"6.  Navigation Benchmark Model-NAV02 (3 X 3): Variables{x1,x2,v1,v2}\n"
					"7.  Navigation Benchmark Model-NAV03 (3 X 3): Variables{x1,x2,v1,v2}\n"
					"8.  Navigation Benchmark Model-NAV04 (5 X 5): Variables{x1,x2,v1,v2}\n"
					"9.  Navigation Benchmark Model-NAV05 (9 X 9): Variables{x1,x2,v1,v2}\n"
					"10. Circle with only ONE location model: Variables{x,y} \n"
					"11. Circle with TWO locations model: Variables{x,y} \n"
					"12. Circle with FOUR locations model: Variables{x,y} \n"
					"13. Oscillator model without any filters: Variables{x,y}\n"
					"14. Testing Model: Variables{x1,x2,t}\n"
					)
			("directions", po::value<int>()->default_value(1),

			"Set the directions for template polyhedra:\n"
					"1. Box Directions (Set to default)\n"
					"2. Octagonal Directions \n"
					"n. 'n' uniform Directions \n")
			("time-horizon", po::value<double>(),
			"Set the Time horizon for the flowpipe computation per Location(Local time).")(
			"time-step", po::value<double>(), "Set the sampling time for the flowpipe computation.")
			("transition-size", po::value<int>(),
			"Set the maximum number of Jumps(0 for no jump(breadth=1), 1 for first jump(breadth=2).")
			("algorithm", po::value<int>()->default_value(1),
					"set algorithm for Flowpipe computation\n"
					"1. Sequential Algorithm  (Set to default)\n"
					"2. Parallel Algorithm: Lazy evaluation of support function\n"
					"3. Parallel Algorithm: Process-- Not in Use\n"
					"4. Time-Slice Parallel Algorithm: Time Sliced Reachability selected\n"
					"11. Flowpipe(PostC) Computation done using GPU\n"
			/*"5. PAR_ITER_DIR Algorithm: Process-- Not in Use\n"
			 "6. PAR_BY_PARTS Algorithm: Process-- Not in Use\n"
			 "7. PAR_BY_PARTS_ITERS Algorithm: Process-- Not in Use\n"
			 "8. SAME_DIRS Algorithm: Process-- Not in Use\n"
			 "9. ALL_DIRS Algorithm: Process-- Not in Use\n"
			 "10. GPU_MULTI_SEQ Algorithm: Process-- Not in Use\n"
			 "11. GPU_SF Algorithm: Process-- GPU Acceleration\n" */)("gpu",
			"Enable GPU Acceleration. GPU acceleration is OFF by default.")(
			"number-of-streams", po::value<int>()->default_value(1),
			"Set the maximum number of GPU-streams (Set to 1 by default).")

	("time-slice", po::value<int>(),
			"Set the maximum number of Time Sliced(or partitions)")
	("pbfs", "Enable Parallel Breadth First Exploration of Hybrid Automata Locations. PBFS is OFF by default")

	("internal", "called internally when running hyst-xspeed model")

	("jumps", po::value<int>()->default_value(1), "set an algorithm for Discrete Jumps\n"
						"1. Sequential Breadth First Exploration of Locations. (Set to default)\n"
						"2. Parallel Breadth First Exploration of Locations, an adaptation of Gerard J. Holzmann\n"
						"3. Parallel Breadth First Exploration of Locations using Load Balancing Algorithm\n" )
	("forbidden,F", po::value<std::string>(), "forbidden location_ID and forbidden set/region within that location") //better to be handled by hyst
	("output-variable,v", po::value<std::string>(), "projecting variables for e.g., 'x,v' for Bouncing Ball") //better to be handled by hyst
	("include-path,I", po::value<std::string>(), "include file path")
	("model-file,m", po::value<std::string>(), "include model file")
	("config-file,c", po::value<std::string>(), "include configuration file")
	("internal", "called internally when running hyst-xspeed model")
	("output-file,o", po::value<std::string>(), "output file name for redirecting the outputs");



	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	std::vector<std::string> output_vars(2);	//stores the output/plotting variables

	std::ofstream outFile;
	math::matrix<double> vertices_list;
	const char *stFileNameWithPath;


	if (argc > 1) { // Boost Options to be filled-up
		if (vm.count("help")) {
			cout << desc << "\n";
			return 1; //Just displaying the Help options and terminating the Project
		}
		std::string include_path = "", model_filename = "",
				config_filename = ""; //default set to empty
		if (vm.count("include-path")) {
			include_path = vm["include-path"].as<std::string>();
			//std::cout << "Include Path is: " << include_path << "\n";
		}

		if (vm.count("config-file")) {

			user_options.set_configFile(vm["config-file"].as<std::string>());
			//std::cout << "Configuration file is: " << user_options.get_configFile() << "\n";
		}
		if (vm.count("model-file")) {

			user_options.set_modelFile(vm["model-file"].as<std::string>());
			//std::cout << "Model file is: " << user_options.get_modelFile() << "\n";
		}
// ********************** Setting for Output file **********************************
		std::string fileName, fullPath, fileWithPath;

		//cout << endl << "Working here 2\n";
		if (vm.count("include-path")) {
			fullPath = vm["include-path"].as<std::string>();
			//std::cout << "Include Path is: " << fullPath << "\n";
		} else {
			fullPath = "./"; //default file path
		}
		fileWithPath.append(fullPath);
		if (vm.count("output-file")) {
			fileName = vm["output-file"].as<std::string>();
			//std::cout << "fileName is: " << fileName << "\n";
		} else {
			fileName = "out.txt";
		}
		fileWithPath.append(fileName);
		//std::cout << "fileWithPath is: " << fileWithPath << "\n";
		stFileNameWithPath = fileWithPath.c_str();
		//std::cout << "fileWithPath is: " << fileWithPath << "\n";
		//std::cout << "stFileNameWithPath = " << stFileNameWithPath << "\n";
// ********************** Setting for Output file Done **********************************

		if (vm.count("model-file") && vm.count("config-file")) {
			std::cout << "Translating user model with Hyst\n";

			std::string cmdStr, replacingFile, SingleSpace = " ",
					projLocation, java_exeFile;

			//todo:: proper path to be handled from the relative/current installed location of the software
			replacingFile ="./user_model.cpp";

			java_exeFile = "java -jar";

			cmdStr.append(java_exeFile);
			cmdStr.append(SingleSpace);
			cmdStr.append("./bin/Hyst-XSpeed.jar -xspeed -o");
			//cmdStr.append("");
			cmdStr.append(SingleSpace);
			cmdStr.append(replacingFile);
			cmdStr.append(SingleSpace);
			cmdStr.append(include_path);
			cmdStr.append(user_options.get_modelFile());
			cmdStr.append(SingleSpace);
			cmdStr.append(include_path);
			cmdStr.append(user_options.get_configFile());

			const char *st, *st2, *st3, *st4, *st5;
			st = cmdStr.c_str();
			//std::cout <<"st = "<<st<<std::endl;
			system(st); //calling hyst interface to generate the XSpeed model file
			system("g++ -c -I./include/ user_model.cpp -o user_model.o");
			system("g++ -L./lib/ user_model.o -lXSpeed -lboost_timer -lboost_system -lboost_chrono -lboost_program_options -lgomp -lglpk -lsundials_cvode -lsundials_nvecserial -lnlopt -o ./XSpeed.o");
			//std::cout<<"file with path =" <<stFileNameWithPath<<std::endl;
			string cmdStr1;
			cmdStr1.append("./XSpeed.o --internal -o");
			cmdStr1.append(SingleSpace);
			cmdStr1.append(stFileNameWithPath);
			//std::cout<<"Command = "<<cmdStr1.c_str()<<"\n";
			//system("./XSpeed.o --internal");
			system(cmdStr1.c_str());
			exit(0);
		}

		if(vm.count("internal")){
			// calls the hyst-xspeed generated model
			//int iters = (int) user_options.get_timeHorizon()/ user_options.get_timeStep();

			//Todo:: have to take inputs for options such as user_options.get_flow_algorithm() == Algorithm_Type,
			//		time-slice, user_options.get_automata_exploration_algorithm()==jumps
			//     all related inputs for gpu such as number-of-streams

			user_model(Hybrid_Automata, init_state, reach_parameters, forbidden_set, user_options);

			isConfigFileAssigned = true;
			isModelParsed = true;
		}
		if (vm.count("output-variable")) {
			std::string VarStr;
			VarStr = vm["output-variable"].as<std::string>();

			typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
			boost::char_separator<char> sep(", ");
			tokenizer tokens(VarStr, sep);
			int index = 0;
			for (tokenizer::iterator tok_iter = tokens.begin();
					tok_iter != tokens.end(); ++tok_iter) {
				output_vars[index] = (std::string) (*tok_iter);
				//std::cout<<"Variables = "<<output_vars[index]<<"\n";

				index++;
			}
		}

		if (vm.count("forbidden") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			user_options.set_forbidden_state(vm["forbidden"].as<std::string>());
		}

		if (vm.count("model") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			user_options.set_model(vm["model"].as<int>());
			//if (user_options.get_model() < 1 || user_options.get_model() > 13) {
			//For testing model==14
			if (user_options.get_model() < 1 || user_options.get_model() > 14) {
				std::cout << "Invalid Model option specified\n";
				return 0;
			}
		}
		if (vm.count("directions") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			user_options.set_directionTemplate(vm["directions"].as<int>());
			if(user_options.get_directionTemplate()<=0){
				std::cout << "Invalid Directions option specified\n";
				return 0;
			}
		}
		if (vm.count("time-horizon") && isConfigFileAssigned == false) { //Compulsory Options
			user_options.set_timeHorizon(vm["time-horizon"].as<double>());
			if(user_options.get_timeHorizon()<=0){ //for 0 or negative time-bound
				std::cout << "Invalid time-horizon option specified, A positive non zero bound expected\n";
				return 0;
			}
		} else if (isConfigFileAssigned == false) {
			std::cout << "Missing time-horizon option\n";
			return 0;
		}
		if (vm.count("time-step") && isConfigFileAssigned == false) { //Compulsory Options
			user_options.set_timeStep(vm["time-step"].as<double>());
			if (user_options.get_timeStep() > 0) {
				unsigned int iterations_size = (unsigned int) user_options.get_timeHorizon() / user_options.get_timeStep();
				//std::cout << "\niterations_size = " << iterations_size;
			} else { //for 0 or negative sampling-time
				std::cout << "Invalid time-step option specified\n";
				return 0;
			}
		} else if (isConfigFileAssigned == false) {
			std::cout << "Missing time-step option\n";
			return 0;
		}
		if (vm.count("transition-size") && isConfigFileAssigned == false) { //Compulsory Options
			user_options.set_bfs_level(vm["transition-size"].as<int>());
			if (user_options.get_bfs_level() < 0){
				std::cout << "Invalid bfs level specified, a positive number expected\n";
				return 0;
			}
		} else if (isConfigFileAssigned == false) {
			std::cout << "Missing transition-size option\n";
			return 0;
		}

		if (vm.count("gpu")) {
			user_options.set_flow_algorithm(11); //GPU_SF algorithm is selected
		}
		if (vm.count("gpu")) { //if gpu enabled then
			if (vm.count("number-of-streams")) { //Compulsory Options but set 1 by default
				int no_streams = vm["number-of-streams"].as<int>(); //default value ==1
				if (no_streams >= 1) {
					number_of_streams = no_streams; //Number of GPU-Streams selected
				} else {
					std::cout << "Invalid number_of_streams option specified\n";
					return 0;
				}
			}
		}
		//Algorithm Preference is given to 1 to 4 even if gpu is enabled i.e., overwrite Algorithm_Type==gpu
		if (vm.count("algorithm")) {
			user_options.set_flow_algorithm(vm["algorithm"].as<int>());
			if(user_options.get_flow_algorithm()<0 || user_options.get_flow_algorithm()>11){
				std::cout << "Invalid algorithm option specified\n";
				return 0;
			}
		}
		if (user_options.get_flow_algorithm() == 4) { //this argument will be set only if algorithm==time-slice or PAR_ITER
			if (vm.count("time-slice")) { //Compulsory Options if algorithm-type==Time-Slice(4)
				int partition_size = vm["time-slice"].as<int>();
				if (partition_size > 0) {
					Total_Partition = partition_size;
				} else { //for 0 or negative time-slice
					std::cout << "Invalid time-slice option specified\n";
					return 0;
				}
			} else {
				std::cout << "Missing time-slice option\n";
				return 0;
			}
		}

		if (vm.count("jumps")) { //Compulsory Options but set to 1 by default
			int d = vm["jumps"].as<int>();
			if (d == 1) {
				user_options.set_automata_exploration_algorithm(12);//Sequential Breadth First Search
			} else if (d == 2) {
				user_options.set_automata_exploration_algorithm(13);
				//DiscreteAlgorithm = 13; //Parallel Breadth First Search using Gerard J. Holzmann
			} else if (d == 3) {
				user_options.set_automata_exploration_algorithm(14);
				//DiscreteAlgorithm = 14; //Parallel Breadth First Search using Load Balancing Algorithm
			} else { //for 0 or negative directions
				std::cout << "Invalid 'jumps' option specified!!!\n";
				return 0;
			}

		}
	} //ALL COMMAND-LINE OPTIONS are set completely


	//initialize(iterations_size, time_bound, model_type, directions_type_or_size,transition_size, bad_state, forbidden_set);

	// Initialize the model with the parameters given by the user

	if(!isModelParsed){
		load_model(init_state, Hybrid_Automata, user_options, reach_parameters, forbidden_set);

		user_options.set_first_plot_dimension(Hybrid_Automata.get_index(output_vars[0]));
		user_options.set_second_plot_dimension(Hybrid_Automata.get_index(output_vars[1]));
	}

	std::list<symbolic_states::ptr> Symbolic_states_list;

	double Avg_wall_clock = 0.0, Avg_user_clock = 0.0, Avg_system_clock = 0.0;
	double Avg_cpu_use=0.0;
	long total_mem_used=0;
	double cpu_usage;
	boost::timer::cpu_timer tt1;
	unsigned int number_of_times = 1;	//Taking Average of 5 readings
	for (int i = 1; i <= number_of_times; i++) { //Running in a loop of number_of_times to compute the average result
		init_cpu_usage();	//initializing the CPU Usage utility to start recording usages
		tt1.start();
		reachability reach;
		transition_iters = user_options.get_bfs_level();

		reach.setReachParameter(Hybrid_Automata, init_state,
				reach_parameters, transition_iters, user_options.get_flow_algorithm(),
				Total_Partition, lp_solver_type_choosen, number_of_streams,
				Solver_GLPK_Gurobi_GPU, forbidden_set);

		if (user_options.get_automata_exploration_algorithm() == BFS) { //Sequential Search implemented for Discrete Jumps

			std::cout << "\nRunning Sequential BFS\n";
			Symbolic_states_list = reach.computeSeqentialBFSReach(ce);
			/*Symbolic_states_list = reach(Hybrid_Automata, init_state,
					reach_parameters, transition_iterations, Algorithm_Type,
					Total_Partition, lp_solver_type_choosen, number_of_streams,
					Solver_GLPK_Gurobi_GPU, forbidden_set, ce);*/
		} else if (user_options.get_automata_exploration_algorithm() == PBFS_GJH) { //Parallel Breadth First Search implemented for Discrete Jumps
			std::cout << "\nRunning Parallel BFS using Adapted Gerard J. Holzmann's Algorithm.\n";
			//Symbolic_states_list = reach.computeParallelBFSReach(ce);
			//Symbolic_states_list = reach.computeParallelBFSReachLockAvoid(ce);	//without LOAD Balance Approach

			Symbolic_states_list = reach.ParallelBFS_GH();	// Golzman algorithm adaption

		} else if (user_options.get_automata_exploration_algorithm() == PBFS_LB) { //Parallel Breadth First Search implemented for Discrete Jumps
			std::cout << "\nRunning Parallel BFS using Load Balancing Algorithm.\n";
			//Symbolic_states_list = reach.computeParallelLoadBalanceReach(ce);	//Our LOAD Balance Approach
			Symbolic_states_list = reach.LoadBalanceAll(ce);
			/*Symbolic_states_list = reach_pbfs(Hybrid_Automata, init_state,
					reach_parameters, transition_iterations, Algorithm_Type,
					Total_Partition, lp_solver_type_choosen, number_of_streams,
					Solver_GLPK_Gurobi_GPU, forbidden_set, ce);*/
		}
		tt1.stop();
		cpu_usage = getCurrent_ProcessCPU_usage();
		Avg_cpu_use = Avg_cpu_use  + cpu_usage;
		//todo:: if the size of transition is greater than it can compute there is segmentation fault

		double wall_clock, user_clock, system_clock;
		wall_clock = tt1.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		user_clock = tt1.elapsed().user / 1000000;
		system_clock = tt1.elapsed().system / 1000000;

		if (user_options.get_flow_algorithm() == 11) {
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


	if (user_options.get_flow_algorithm() == 11) {
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

		std::cout << "\nCPU Usage:(%) = " << Avg_cpu_use<< std::endl;

		std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << return_Time
				<< std::endl;
		std::cout << "\nBoost Time taken:User  (in Seconds) = "
				<< Avg_user_clock / (double) 1000 << std::endl;
		std::cout << "\nBoost Time taken:System  (in Seconds) = "
				<< Avg_system_clock / (double) 1000 << std::endl;
		cout << endl << "Number of Vectors = " << reach_parameters.Directions.size1();


	}
	if (argc == 1) { //No argument or Running directly from the Eclipse Editor

		//----Disabling the console Output to Generate the Data using Shell Script
		std::cout << "\nCPU Usage:(%) = " << Avg_cpu_use<< std::endl;
		std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << return_Time
				<< std::endl;

		std::cout << "\nBoost Time taken:User  (in Seconds) = "
				<< Avg_user_clock / (double) 1000 << std::endl;
		std::cout << "\nBoost Time taken:System  (in Seconds) = "
				<< Avg_system_clock / (double) 1000 << std::endl;

		cout << endl << "Number of Vectors = "
				<< reach_parameters.Directions.size1();
	} 
	cout << endl << "Memory Usages = " << (double)(total_mem_used / 1024.0) / number_of_times << " MB\n";

std::list<symbolic_states::ptr>::iterator it;
	/*
	 * Generating Vertices as output which can be plotted using gnuplot utilites
	 */

// ********************** Setting for Output file **********************************
		std::string fileName1, fullPath1, fileWithPath1;
		fullPath1 = "./"; //default file path
		fileWithPath1.append(fullPath1);
		if (vm.count("output-file")) {
			fileName1 = vm["output-file"].as<std::string>();
			//std::cout << "fileName is: " << fileName1 << "\n";

		} else {
			fileName1 = "out.txt";
		}
		fileWithPath1.append(fileName1);
		//std::cout << "fileWithPath is: " << fileWithPath << "\n";
		stFileNameWithPath = fileWithPath1.c_str();
		//std::cout << "fileWithPath is: " << fileWithPath1 << "\n";
		std::cout << "FileName with Path = " << stFileNameWithPath << "\n";
// ********************** Setting for Output file Done **********************************



	outFile.open(stFileNameWithPath);

	for (it = Symbolic_states_list.begin(); it != Symbolic_states_list.end();
			it++) {
		template_polyhedra::ptr temp_polyhedra;
		temp_polyhedra = (*it)->getContinuousSetptr();

		math::matrix<double> A, template_directions, invariant_directions;
		math::matrix<double> big_b, sfm, invariant_bound_values;

		template_directions = temp_polyhedra->getTemplateDirections();
		invariant_directions = temp_polyhedra->getInvariantDirections(); //invariant_directions

		sfm = temp_polyhedra->getMatrixSupportFunction(); //total number of columns of SFM
		invariant_bound_values = temp_polyhedra->getMatrix_InvariantBound(); //invariant_bound_matrix

		if (invariant_directions.size1() == 0) { //indicate no invariants exists
			A = template_directions;
			big_b = sfm;
		} else {
			template_directions.matrix_join(invariant_directions, A); //creating matrix A
			sfm.matrix_join(invariant_bound_values, big_b);
		}
		std::vector<double> b(big_b.size1()); //rows of big_b
		for (int i = 0; i < big_b.size2(); i++) { //all the columns of new formed sfm
			for (int j = 0; j < big_b.size1(); j++) { //value of all the rows
				b[j] = big_b(j, i);
			} //creating vector 'b'

			polytope::ptr p = polytope::ptr(new polytope(A, b, 1));
			vertices_list = p->get_2dVertices(
					user_options.get_first_plot_dimension(),
					user_options.get_second_plot_dimension()); //
			//vertices_list = p->enumerate_2dVertices(x, y); //

			// ------------- Printing the vertices on the Output File -------------
			for (int i = 0; i < vertices_list.size1(); i++) {
				for (int j = 0; j < vertices_list.size2(); j++) {
					outFile << vertices_list(i, j) << " ";
				}
				outFile << std::endl;
			}
			outFile << std::endl; // 1 gap after each polytope plotted
			// ------------- Printing the vertices on the Output File -------------

		}
	}
	outFile.close();


	if (ce != NULL) {
		cout << "******** Safety Property Violated ********\n";
		std::list<abstract_symbolic_state::ptr> list_sym_states;
		std::list<transition::ptr> list_transition;
		list_sym_states = ce->get_CE_sym_states();
		list_transition = ce->get_CE_transitions();

		std::list<abstract_symbolic_state::ptr>::iterator it_sym_state;
		std::list<transition::ptr>::iterator it_trans;
		discrete_set ds;
		unsigned int locationID;
		cout << "(Location ID, Transition ID)\n";
		std::vector<int> transID(ce->get_length());	//making a vector of transition_ID so it can be printed
		int index = 0;
		ce->plot(user_options.get_first_plot_dimension(),
				user_options.get_second_plot_dimension());
		concreteCE::ptr bad_trace = ce->gen_concreteCE(0.1);
		bad_trace->set_automaton(ce->get_automaton());
		std::string tracefile = "./bad_trace.o";
		bad_trace->plot_ce(tracefile);

	} else {

		cout << "******** Does NOT Violate Safety Property ********\n";
	}

	cout << "\n******** Summary of XSpeed ********\n";
	return 0; //returning only the Wall time taken to execute the Hybrid System
}
