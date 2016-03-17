//============================================================================
// Name        : MyProject_SF.cpp
// Author      : Amit Gurung
// Version     :
// Copyright   : (C) 2014
// Description : Trying to implement Support Function
//============================================================================

#include <iostream>
#include <fstream>
//#include <cstdlib>

#include "boost/timer/timer.hpp"


#include "InputOutput/cpu_utilities/cpu_utilities.h"	//cpu usage functions
#include "InputOutput/memory_utilities/memory_usages.h" //memory usage functions

#include "core_system/math/uni_sphere.h"	//for obtaining uniformly distributed directions
#include "application/sf_directions.h"
#include "application/DataStructureDirections.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"
#include <boost/numeric/ublas/matrix.hpp>
#include "Utilities/Template_Polyhedra.h"
#include "Utilities/Post_Assignment.h"
#include <list>
#include <utility>	//for std::pair
#include <iterator>
#include "Hybrid_Model_Parameters_Design/BouncingBall.h"
#include "Hybrid_Model_Parameters_Design/TimedBouncingBall.h"
/*
 #include "Hybrid_Model_Parameters_Design/Helicopter_model/Helicopter.h"
 #include "Hybrid_Model_Parameters_Design/Helicopter_model/HelicopterModel2.h"
 #include "Hybrid_Model_Parameters_Design/Helicopter_model/HelicopterModel28PolytopeU.h"
 #include "Hybrid_Model_Parameters_Design/Helicopter_model/HelicopterModel29DimPolytopeU.h"
 */
#include "Hybrid_Model_Parameters_Design/Helicopter_model/HelicopterModel28Dim.h"
#include "Hybrid_Model_Parameters_Design/FiveDimSys.h"
//#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark.h"
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark4Var.h"
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
//#include "math/lp_gurobi_simplex.h"
//#include <boost/tokenizer.hpp>

// *********** Command Line Boost Program Options ********
#include <boost/program_options/config.hpp>

#include "boost/program_options.hpp"
#include <boost/config.hpp>
#include <boost/program_options/detail/config_file.hpp>

#include <boost/program_options/parsers.hpp>
// *********** Command Line Boost Program Options ********
#include "plotter_utility.h"
// *********** User Selected Model ***************
#include "Hybrid_Model_Parameters_Design/user_model/user_model.h"

#include "InputOutput/io_utility.h"
// *******counter example **************/
#include "counterExample/concreteCE.h"

namespace po = boost::program_options;
using namespace std;

//symbolic_states initial_symbolic_states;
initial_state::ptr init_state;
//**************** Hybrid Automata Definition ***********************

ReachabilityParameters reach_parameters;
int dir_nums, transition_iterations;
int dims;
std::vector<std::vector<double> > directions; //List of all directions

math::matrix<double> Real_Directions; //List of all directions

//**************** Hybrid Automata Definition ***********************
hybrid_automata Hybrid_Automata;
//**************** Hybrid Automata Definition ***********************
typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

polytope initial_polytope_I, invariant, gaurd_polytope(true);
unsigned int HybridSystem_Model_Type;
unsigned int Directions_Type;
unsigned int Uniform_Directions_Size;

void initialize(int iterations_size, double time_bound, unsigned int model_type,
		unsigned int directions_type_or_size, unsigned int transition_size, const std::string& bad_state,
		std::pair<int, polytope::ptr>& forbidden_set) {
	size_type row, col;

	transition_iterations = transition_size; //Number of iterations for transition of the Hybrid system

	reach_parameters.TimeBound = time_bound; //Total Time Interval
	reach_parameters.Iterations = iterations_size; // number of iterations
	reach_parameters.time_step = reach_parameters.TimeBound
			/ reach_parameters.Iterations;

//Assigning the Model of the Hybrid System
//	(1,2,3,4,5,6,7) = (BBALL, TBBALL, HELICOPTER, FIVEDIMSYS, NAVIGATION, CIRCLE, CIRCLE_FOUR_LOC)
	HybridSystem_Model_Type = model_type;

//Assigning the Type of Directions
	Directions_Type = directions_type_or_size; //(1,2,>2) = (BOX, OCT, UNIFORM)
	Uniform_Directions_Size = directions_type_or_size; //total number of UNIFORM directions

//Assigning the Model of the Hybrid System and the Dimension of the System as it is needed for setting the Number of Directions
	if (HybridSystem_Model_Type == BBALL) {
		//dim = 2;//Number of Dimension for the Current Working System for Bouncing Ball

		//Setting the initial parameters for Bouncing Ball Model
		//	std::cout << "\nRunning :: Model of A Bouncing Ball\n";
		//SetBouncingBall_Parameters(reach_parameters, initial_polytope_I, system_dynamics, invariant,gaurd_polytope, AssignRw);
		SetBouncingBall_Parameters(Hybrid_Automata, init_state,
				reach_parameters);
	}
	if (HybridSystem_Model_Type == TBBALL) {
		//dim = 3;//Number of Dimension for the Current Working System for Bouncing Ball
		//	std::cout << "\nRunning :: Model of A Timed Bouncing Ball\n";

		//Setting the initial parameters for Bouncing Ball Model
		/*	SetTimedBouncingBall_Parameters(reach_parameters, initial_polytope_I,
		 system_dynamics, invariant, gaurd_polytope, AssignRw);*/

		SetTimedBouncingBall_ParametersHystOutput(Hybrid_Automata, init_state,reach_parameters);
		//SetTimedBouncingBall_Parameters(Hybrid_Automata, init_state,
		//		reach_parameters);
		//	cout<<"\nTesting 2 b\n";
	}
	if (HybridSystem_Model_Type == HELICOPTER) {
		//	//dim=35;	//Trying with 35 variables x1 to x28, u1 to u6 and t Number of Dimension for the Helicopter Model
		//dim = 29; 	// Trying with 29 variables x1 to x28 are Helicopter & Controller Variables and t is the clock/time/InvariantTimeBound

		//dim = 28;// Trying with 28 variables x1 to x28 Number of Dimension for the Helicopter Model

		//	std::cout << "\nRunning :: Model of A Controlled Helicopter\n";
		//Setting the initial parameters for Helicopter Model
		//	SetHelicopter_Parameters(reach_parameters, initial_polytope_I, system_dynamics, invariant,
		//			gaurd_polytope);

		//	SetHelicopter_Parameters2(reach_parameters, initial_polytope_I, system_dynamics, invariant,
		//				gaurd_polytope);	//29 variables including t
		/*SetHelicopter_Parameters3(reach_parameters, initial_polytope_I, system_dynamics, invariant,
		 gaurd_polytope);	//28 variables with empty polytope U*/
		SetHelicopter_Parameters3(Hybrid_Automata, init_state,
				reach_parameters);

		//	SetHelicopter_Parameters4(reach_parameters, initial_polytope_I, system_dynamics, invariant,
		//				gaurd_polytope);	//28 variables and polytope U not empty
		//	SetHelicopter_Parameters5(reach_parameters, initial_polytope_I,
		//			system_dynamics, invariant, gaurd_polytope);//29 variables and polytope U non-empty (Output Not correctly plotted: just bar)
	}
	if (HybridSystem_Model_Type == FIVEDIMSYS) {
		//dim = 5;
		//	std::cout << "\nRunning :: Model of A Five Dimensional Systems\n";
		//setSysParams(reach_parameters, initial_polytope_I, system_dynamics, invariant);
		setSysParams(Hybrid_Automata, init_state, reach_parameters);
		//	std::cout << "\nParameter Assignment Completed!!!\n";
	}

	if (HybridSystem_Model_Type == NAVIGATION_1) {
		//dim = 2;
		//	std::cout << "\nRunning :: Benchmark Model of A Navigation\n";
		//Setting the initial parameters for Bouncing Ball Model
		//SetNavigationBenchMark(Hybrid_Automata, initial_symbolic_states,reach_parameters);//only 2 Variable
		SetNavigationBenchMark4Var(Hybrid_Automata, init_state,
				reach_parameters); //Paper's Model
		//	cout<<"\nTesting 2 b\n";
	}

	if (HybridSystem_Model_Type == NAVIGATION_2) {
		//	std::cout << "\nRunning :: Benchmark Model of A Navigation\n";
		//Setting the initial parameters for Bouncing Ball Model
		SetNavigationModel2(Hybrid_Automata, init_state, reach_parameters); //My own testing Model NAV2
		//	cout<<"\nTesting 2 b\n";
	}

	if (HybridSystem_Model_Type == NAVIGATION_3) {
		//dim = 2;
		//	std::cout << "\nRunning :: Benchmark Model of A Navigation\n";
		//Setting the initial parameters for Bouncing Ball Model
		//SetNavigationBenchMark(Hybrid_Automata, initial_symbolic_states,reach_parameters);//only 2 Variable

		SetNavigationModel4(Hybrid_Automata, init_state, reach_parameters); //Model NAV04

		//	cout<<"\nTesting 2 b\n";
	}
	if (HybridSystem_Model_Type == NAVIGATION_4) {
		//dim = 2;
		//	std::cout << "\nRunning :: Benchmark Model of A Navigation\n";
		//Setting the initial parameters for Bouncing Ball Model
		//SetNavigationBenchMark(Hybrid_Automata, initial_symbolic_states,reach_parameters);//only 2 Variable

		SetNavigationModel5by5(Hybrid_Automata, init_state, reach_parameters); //My own testing Model NAV_5by5

		//	cout<<"\nTesting 2 b\n";
	}

	if (HybridSystem_Model_Type == CIRCLE_ONE_LOC) {
		//dim = 2;
		std::cout
				<< "\nRunning :: Model of A CIRCLE with ONE Location 2-Dimensional Systems\n";
		SetRotationCircleOneLocation_Parameters(Hybrid_Automata, init_state,
				reach_parameters);
	}
	if (HybridSystem_Model_Type == CIRCLE_TWO_LOC) {
		//dim = 2;
		std::cout
				<< "\nRunning :: Model of A CIRCLE with TWO Locations 2-Dimensional Systems\n";
		SetRotationCircle_Parameters(Hybrid_Automata, init_state,
				reach_parameters);
	}
	if (HybridSystem_Model_Type == CIRCLE_FOUR_LOC) {
		//dim = 2;
		std::cout
				<< "\nRunning :: Model of A CIRCLE with Four Locations 2-Dimensional Systems\n";
		SetRotationCircle4Location_Parameters(Hybrid_Automata, init_state,
				reach_parameters);
	}

	dims = init_state->getInitialSet()->getSystemDimension();

//Assigning the Number of Directions and Generating the Template Directions from the above given dimension of the model
//todo:: needs to decide that is this the right place to include Invariant direction
	//and also Redundant invariant directional constraints to be removed

	std::vector<std::vector<double> > newDirections;

	if (Directions_Type == BOX) {
		dir_nums = 2 * dims; //Axis Directions
		newDirections = generate_axis_directions(dims);
		//repeated code:: to avoid outside if-block
		get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here:: Temporary solution
		row = dir_nums;
		col = dims;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	if (Directions_Type == OCT) {
		dir_nums = 2 * dims * dims; // Octagonal directions
		newDirections = get_octagonal_directions(dims);
		//repeated code:: to avoid outside if-block
		get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here:: Temporary solution
		row = dir_nums;
		col = dims;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	if (Directions_Type > 2) {
		dir_nums = Uniform_Directions_Size; // ASSIGN HERE Number of Vectors/Directions for UNIform spear algorithm
		newDirections = math::uni_sphere(dir_nums, dims, 100, 0.0005);
		//repeated code:: to avoid outside if-block
		get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here:: Temporary solution
		row = dir_nums;
		col = dims;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	/* The variable to dimension id map it set at this point */
	if(!bad_state.empty())
		string_to_poly(bad_state,forbidden_set);
}

bool isNumber(const string& s) {
	bool hitDecimal = 0;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '.' && !hitDecimal) // 2 '.' in string mean invalid
			hitDecimal = 1; // first hit here, we forgive and skip
		else if (!isdigit(c))
			return 0; // not ., not
	}
	return 1;
}

int main(int argc, char *argv[]) {

	char ch;

	std::ifstream infile(
			"/home/amit/cuda-workspace/XSpeed/src/sys_files/system_var.txt");
	while (!infile.eof()) {
		infile.get(ch); //reading only a single character from the file
		break;
	}
	infile.close();
	// -----------------

	//cout<<"Started from here\n";
	std::pair<int, polytope::ptr> forbidden_set; //(locID1,Polytope1)}
	std::string bad_state; // string to capture the bad state description given by the user
	abstractCE::ptr ce;	//object of class counter_example

	double time_bound;
	unsigned int iterations_size;
	unsigned int model_type = 0, directions_type_or_size = 0; //set to default
	int transition_size;
	int Algorithm_Type, DiscreteAlgorithm = 0;
	int number_of_times = 1; //Make this 1 for Memory Profiling
	unsigned int number_of_streams = 1;
	int lp_solver_type_choosen = 1; //	1 for GLPK and 2 for Gurobi
	int Solver_GLPK_Gurobi_GPU = 3; //if Algorithm == 11 then (1 for GLPK; 2 for Gurobi; 3 for GPU)
	unsigned int Total_Partition; //for Parallel Iterations Algorithm :: number of partitions/threads
	int hey = 0;
	bool isConfigFileAssigned = false;
	int output_var_X = 0, output_var_Y = 1;
	po::options_description desc("XSpeed options");
	po::variables_map vm;

	if (argc == 1) { //No argument:: When Running directly from the Eclipse Editor
		//(1,2,3,4,5,6,7,8) = (BBALL, TBBALL, HELICOPTER, FIVEDIMSYS, NAVIGATION, CIRCLE,CIRCLE_FOUR_LOCATION, CIRCLE_ONE_LOC)
		model_type = 4;
		directions_type_or_size = 1; //(1,2,>2) = (BOX, OCT, UNIFORM)
		iterations_size = 100; //number of iterations
		time_bound = 10; //This is Local Time Horizon
		transition_size = 3; //Number of iterations for transition of the Hybrid system
		//Algorithms-Value(1,2,3,4,5,6,7,8,9,10,11)
		//(SEQ,PAR_OMP,PAR_PROCESS,PAR_ITER,PAR_ITER_DIR,PAR_BY_PARTS,PAR_BY_PARTS_ITERS,SAME_DIRS, GPU_MULTI_SEQ,GPU_SF)
		Algorithm_Type = 1;
		DiscreteAlgorithm = 1; // 12 for PBFS or any other values for sequential discrete jump
		Total_Partition = 16; //maximum value = iterations_size (so that each partition will have at least 1 omega to be computed)
		number_of_streams = 1; //Number of streams in GPU(division)
		lp_solver_type_choosen = 1; //For the entire Tool
		number_of_times = 1; //Make this 1 for Memory Profiling
		Solver_GLPK_Gurobi_GPU = 3; //if Algorithm == 11 then (1 for GLPK; 2 for Gurobi; 3 for GPU)
		//	cout << "\nRunning Testing 1\n";
		hey = 1;
	}

	desc.add_options()("help", "produce help message")("model",
			po::value<int>()->default_value(1),
			"set model for reachability analysis\n"
					"1.  Bouncing Ball Model (Set to default) \n"
					"2.  Timed Bouncing Ball Model\n"
					"3.  28-Dimensional Helicopter Controller Model\n"
					"4.  Five dimensional Benchmark Model \n"
					"5.  Navigation Benchmark Model-NAV01 (3 X 3)\n"
					"6.  Navigation Benchmark Model-NAV02 (3 X 3)\n"
					"7.  Navigation Benchmark Model-NAV03 (3 X 3)\n"
					"8.  Navigation Benchmark Model-NAV04 (5 X 5)\n"
					"9.  Circle with only ONE location model \n"
					"10. Circle with TWO locations model \n"
					"11. Circle with FOUR locations model \n")("directions",
			po::value<int>()->default_value(1),
			"Set the directions for template polyhedra:\n"
					"1. Box Directions (Set to default)\n"
					"2. Octagonal Directions \n"
					"n. 'n' uniform Directions \n")("time-horizon",
			po::value<double>(),
			"Set the Time horizon for the flowpipe computation per Location(Local time).")(
			"time-step", po::value<double>(),
			"Set the sampling time for the flowpipe computation.")(
			"transition-size", po::value<int>(),
			"Set the maximum number of Jumps(Breadth-Level transition) for the reachability algorithm.")(
			"algorithm", po::value<int>()->default_value(1),
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
	//("number-of-readings", po::value<int>()->default_value(1),"Total number of times to run the algorithm to average the readings.")
	//("mc","Enable Multi-core Acceleration. Multi-core acceleration is OFF by default.")
	("time-slice", po::value<int>(),
			"Set the maximum number of Time Sliced(or partitions)")("pbfs",
			"Enable Parallel Breadth First Exploration of Hybrid Automata Locations. PBFS is OFF by default")

	("forbidden,F", po::value<std::string>(),
			"forbidden location_ID and forbidden set/region within that location") //better to be handled by hyst
	("output-variable,v", po::value<std::string>(),
			"projecting variables's index(starts with 1) i.e., 'x,y' where x & y are integer constants") //better to be handled by hyst

	("include-path,I", po::value<std::string>(), "include file path")(
			"model-file,m", po::value<std::string>(), "include model file")(
			"config-file,c", po::value<std::string>(),
			"include configuration file")("output-file,o",
			po::value<std::string>(),
			"output file name for redirecting the outputs");

	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (argc > 1) { // Boost Options to be filled-up
		if (vm.count("help")) {
			cout << desc << "\n";
			return 1; //Just displaying the Help options and terminating the Project
		}
		std::string include_path = "", model_filename = "",
				config_filename = ""; //default set to empty
		if (vm.count("include-path")) {
			include_path = vm["include-path"].as<std::string>();
			std::cout << "Include Path is: " << include_path << "\n";
		}

		if (vm.count("config-file")) {
			config_filename = vm["config-file"].as<std::string>();
			std::cout << "Configuration file is: " << config_filename << "\n";
		}
		if (vm.count("model-file")) {
			model_filename = vm["model-file"].as<std::string>();
			std::cout << "Model file is: " << model_filename << "\n";
		}

		if (vm.count("model-file") && vm.count("config-file")) {
			//std::cout << "\nI will entere!!\n";
			isConfigFileAssigned = true;
			if (ch == '0') { //encountered for the 1st time so need to generate .ccp file
				//std::cout << "\nI may not entere!!\n";
				//file with File_Path is given to hyst commandLine to generate the .cpp file
				//in the required folder and then compile the file copy the .obj and .d file into the
				//required(Debug/Release) folder and then make all the file(Linking) again
				//after 'make' the executable file has to be re-run to witness the change

				std::string cmdStr, replacingFile, SingleSpace = " ",
						projLocation, java_exeFile;
				projLocation = "/home/amit/cuda-workspace/";
				//todo:: proper path to be handled from the relative/current installed location of the software
				replacingFile =
						"XSpeed/src/Hybrid_Model_Parameters_Design/user_model/user_model.cpp";

				java_exeFile = "/usr/bin/java -jar";

				cmdStr.append(java_exeFile);
				cmdStr.append(SingleSpace);
				cmdStr.append(projLocation);
				cmdStr.append("XSpeed/src/sys_files/hyst.jar -xspeed -o");
				//cmdStr.append("");
				cmdStr.append(SingleSpace);
				cmdStr.append(projLocation);
				cmdStr.append(replacingFile);
				cmdStr.append(SingleSpace);
				cmdStr.append(include_path);
				cmdStr.append(model_filename);
				cmdStr.append(SingleSpace);
				cmdStr.append(include_path);
				cmdStr.append(config_filename);

				const char *st, *st2, *st3, *st4, *st5;
				st = cmdStr.c_str();
				system(st); //calling hyst interface to generate the file

				std::cout
						<< "\n\nGenerating Hybrid Automata Model for XSpeed!!! ....\n";
				std::cout << "This may take some time please wait!!! ....\n\n";

				std::string cmdStr2, compile_CmdStr, outputFile_debug,
						outputFile_release, dependenciesFile;
				/*
				 outputFile_debug =
				 "XSpeed/Debug/src/Hybrid_Model_Parameters_Design/user_model/user_model.o";
				 outputFile_release =
				 "XSpeed/Release/src/Hybrid_Model_Parameters_Design/user_model/user_model.o";
				 //	dependenciesFile ="XSpeed/src/Hybrid_Model_Parameters_Design/user_model/user_model.d";
				 //todo :: generate and copy .d */
				std::string cmdStr4, debug_loc, release_loc, cmd_option;

				system("make clean");
				//system("make clean > /tmp/MakeClean_output_file.txt");

				debug_loc = "XSpeed/Debug/";
				release_loc = "XSpeed/Release/";
				cmd_option = "make -C";
				//cmdStr4.append(projLocation);
				int debug_or_release = 1;
				if (debug_or_release) { //1 for Debug selected
					//cmdStr4.append(debug_loc);
					cmdStr4.append(cmd_option);
					cmdStr4.append(SingleSpace);
					cmdStr4.append(projLocation);
					cmdStr4.append(debug_loc);
				} else { //1 for Debug selected
					//cmdStr4.append(release_loc);
					cmdStr4.append(cmd_option);
					cmdStr4.append(SingleSpace);
					cmdStr4.append(projLocation);
					cmdStr4.append(release_loc);
				}
				//cmdStr4.append(" > /tmp/MakeBuild_output_file.txt");
				st4 = cmdStr4.c_str();
				system(st4);

				std::ofstream outfile;
				outfile.open(
						"/home/amit/cuda-workspace/XSpeed/src/sys_files/system_var.txt");
				outfile << 1;
				outfile.close();

				std::string cmdStr5;
				cmdStr5.append(projLocation);
				if (debug_or_release) { //1 for Debug selected
					cmdStr5.append(debug_loc);
				} else { //1 for Debug selected
					cmdStr5.append(release_loc);
				}
				cmdStr5.append("./XSpeed"); //project executable file
				cmdStr5.append(SingleSpace);

				std::string str_argv = "";
				for (int c = 1; c < argc; c++) {
					if (c != 1) {
						str_argv.append(SingleSpace);
					}
					str_argv.append(argv[c]);
				}
				cmdStr5.append(str_argv);
				std::cout << "\ncmdStr5 = " << cmdStr5 << std::endl;
				st5 = cmdStr5.c_str();
				system(st5); //re-run the project
				std::cout << "This Main parent process to be stopped!!!\n";
				return 0; //stop the 1st recursive executable
			}

			//hyst generated code to be used
			user_model(Hybrid_Automata, init_state, reach_parameters,
					transition_iterations);

			// --------- Setting configuration parameters ---------
			time_bound = reach_parameters.TimeBound;
			iterations_size = reach_parameters.Iterations;
			//	model_type = 0; //set to default
			//	directions_type_or_size = 0;	//set to default
			transition_size = transition_iterations;
			// --------- Setting configuration parameters ---------

			std::ofstream outfile;
			outfile.open(
					"/home/amit/cuda-workspace/XSpeed/src/sys_files/system_var.txt");
			outfile << 0;
			outfile.close();
		}

		if (vm.count("output-variable")) {
			std::string VarStr;
			std::vector<int> all_args(2);//always 2 variable as plotting variables
			VarStr = vm["output-variable"].as<std::string>();
		//	std::cout << "\nAll output variables = " << VarStr << std::endl;

			typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
			boost::char_separator<char> sep(", ");
			tokenizer tokens(VarStr, sep);
			int index = 0;
			for (tokenizer::iterator tok_iter = tokens.begin();
					tok_iter != tokens.end(); ++tok_iter) {
			//	std::cout << "<" << (*tok_iter) << ">" << "\n";
				all_args[index] = boost::lexical_cast<int>(
						(std::string) (*tok_iter));
				index++;
			}
			output_var_X = all_args[0] - 1;	//Assuming user's input start with index 1
			output_var_Y = all_args[1] - 1;	//Assuming user's input start with index 1
		}

		if (vm.count("forbidden") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			bad_state = vm["forbidden"].as<std::string>();
/*
std::string allStr;
			allStr = vm["forbidden"].as<std::string>();
			std::cout << "\nAll forbidden arguments\n";

			math::matrix<double> coeff;
			std::vector<double> colVector;

			std::list<std::string> all_args;

			typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
			boost::char_separator<char> sep("& ");
			tokenizer tokens(allStr, sep);
			for (tokenizer::iterator tok_iter = tokens.begin();
					tok_iter != tokens.end(); ++tok_iter) {
				//std::cout << "<" << *tok_iter << ">" << std::endl;
				all_args.push_back((std::string) *tok_iter);
			}

			std::pair<int, polytope::ptr> forbid_pair;
			int pair_started = -1;
			bool polytope_created = false;
			int constraints_count = 0;
			std::list<std::vector<double> > list_of_bounds;
			for (std::list<std::string>::iterator it = all_args.begin();
					it != all_args.end(); it++) {
				std::string eachStr = (*it);
				//		std::cout << "eachStr = " << eachStr << std::endl;
				boost::char_separator<char> sep_symbol("="); //handles = or ==
				tokenizer each_tokens(eachStr, sep_symbol);
				bool is_loc = false;

				if (each_tokens.begin().current_token().compare("loc") == 0) { //check the 1st token if "loc"
					//std::cout<<"each_tokens.begin().current_token() = "<<each_tokens.begin().current_token()<<"  amit\n";
					pair_started = 1;
					for (tokenizer::iterator tok_it = each_tokens.begin();
							tok_it != each_tokens.end(); tok_it++) {
						if (is_loc) { //2nd token
							std::cout << "Loc=" << *tok_it << "\n";
							forbid_pair.first = boost::lexical_cast<int>(
									(std::string) (*tok_it));
							pair_started = 0;
						}
						if (each_tokens.begin().current_token().compare("loc")
								== 0) { //1st token
							is_loc = true;
							if (polytope_created) { //previous polytope created but not stored in pair
								//forbid_pair.second = poly;
								//first store the polytope
								//false reset all previous coeff's values
								coeff.resize(2 * list_of_bounds.size(),
										list_of_bounds.size()); //assuming simple-case of bounded input
								for (int i = 0; i < coeff.size2(); i++) { // both till col
									for (int j = 0; j < coeff.size2(); j++) { // both till col
										if (i == j) {
											coeff(2 * i, j) = -1;
											coeff(2 * i + 1, j) = 1;
										} else {
											coeff(2 * i, j) = 0;
											coeff(2 * i + 1, j) = 0;
										}
									}
								}
								int res = 2 * list_of_bounds.size();
								colVector.resize(res);
								int col_index = 0;
								for (std::list<std::vector<double> >::iterator it =
										list_of_bounds.begin();
										it != list_of_bounds.end(); it++) {
									std::vector<double> v = (*it);
									colVector[col_index] = v[0];
									col_index++;
									colVector[col_index] = v[1];
									col_index++;
								}
								//std::cout << "coeff = " << coeff << std::endl;
								std::cout << "colVector = ";
								for (int i = 0; i < colVector.size(); i++) {
									std::cout << colVector[i] << "\t";
								}
								polytope::ptr forbidden_polytope;
								forbidden_polytope = polytope::ptr(
										new polytope(coeff, colVector, 1));
								forbid_pair.second = forbidden_polytope; //todo currently unable to handle negative bounds

								forbidden_set.insert(forbid_pair);

								polytope_created = false; //store here the polytope
								constraints_count = 0;
								list_of_bounds.clear(); //removes all previous elements from the list

							}
						}
					}
				} else { //Always user's first input is loc=locID. So forbid_pair.first is populated 1st
					pair_started = 0; //this token is a constraint string and not a loc=locID
					//New Parser for parsing each constraints
					std::vector<double> bounds(2); //every constraints will have left and right value
					//int tmp=0;
					while (pair_started != 1) { //parse and create Polytope p for forbid_pair.second
						std::string constraint_Str = eachStr;
						boost::char_separator<char> sep_symbol("<="); //handles < or <= (or even error input =<
						tokenizer each_tokens(constraint_Str, sep_symbol);
						//tmp++;
						// bounds.resize(tmp);
						int index_val = 0;
						for (tokenizer::iterator tok_it = each_tokens.begin();
								tok_it != each_tokens.end(); tok_it++) {
							if (isNumber((std::string) *tok_it)) { //tokens
								//std::cout << "tok_it = " << *tok_it << "\n";
								bounds[index_val] = boost::lexical_cast<double>(
										(std::string) (*tok_it));
								index_val++;
								//bounds.push_back(boost::lexical_cast<int>((*tok_it))); //forbid_pair.first = boost::lexical_cast<int>((*tok_it));
							}
						}
						bounds[0] = -1 * bounds[0]; //n<=x1 so n converted to -n
						list_of_bounds.push_back(bounds);
						polytope_created = true; //constraint(s) parsed
						pair_started = 1; //end of a constraint to exit from while-loop
					} //end of a constraint
				}
				constraints_count++; //number of constraints count
			} //End of all forbidden string

			if (polytope_created) {
				//constraints count can be obtained from 'constraints_count' or list_of_bounds.size()

				coeff.resize(2 * list_of_bounds.size(), list_of_bounds.size()); //assuming simple-case of bounded input
				for (int i = 0; i < coeff.size2(); i++) { // both till col
					for (int j = 0; j < coeff.size2(); j++) { // both till col
						if (i == j) {
							coeff(2 * i, j) = -1;
							coeff(2 * i + 1, j) = 1;
						} else {
							coeff(2 * i, j) = 0;
							coeff(2 * i + 1, j) = 0;
						}
					}
				}
				int res = 2 * list_of_bounds.size();
				colVector.resize(res);
				int col_index = 0;
				for (std::list<std::vector<double> >::iterator it =
						list_of_bounds.begin(); it != list_of_bounds.end();
						it++) {
					std::vector<double> v = (*it);
					colVector[col_index] = v[0];
					col_index++;
					colVector[col_index] = v[1];
					col_index++;
				}
				std::cout << "coeff = " << coeff << std::endl;
				std::cout << "colVector = ";
				for (int i = 0; i < colVector.size(); i++) {
					std::cout << colVector[i] << "\t";
				}
				polytope::ptr forbidden_polytope;
				forbidden_polytope = polytope::ptr(
						new polytope(coeff, colVector, 1));
				forbid_pair.second = forbidden_polytope;
				forbidden_set.insert(forbid_pair);
				polytope_created = false;
			}*/
		}

		if (vm.count("model") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			int model = vm["model"].as<int>();
			if (model == 1) {
				//std::cout<< "Running Reachability Analysis on Bouncing Ball model\n";
			} else if (model == 2) {
				//std::cout<< "Running Reachability Analysis on Timed-Bouncing Ball model\n";
			} else if (model == 3) {
				//std::cout<< "Running Reachability Analysis on Helicopter Controller model\n";
			} else if (model == 4) {
				//std::cout<< "Running Reachability Analysis on Five-Dimensional Benchmark model\n";
			} else if (model == 5) {
				//std::cout<< "Running Reachability Analysis on Navigation Benchmark- Nav01 (3 X 3)\n";
			} else if (model == 6) {
				//std::cout << "Running Reachability Analysis on Navigation Benchmark- Nav02 (3 X 3)\n";
			} else if (model == 7) {
				//std::cout << "Running Reachability Analysis on Navigation Benchmark- Nav03 (3 X 3)\n";
			} else if (model == 8) {
				//std::cout << "Running Reachability Analysis on Navigation Benchmark- Nav04 (5 X 5)\n";
			} else if (model == 9) {
				//std::cout << "Running Reachability Analysis on Circle with only ONE location \n";
			} else if (model == 10) {
				//std::cout << "Running Reachability Analysis on Circle with TWO locations\n";
			} else if (model == 11) {
				//std::cout << "Running Reachability Analysis on Circle with FOUR locations\n";
			} else {
				std::cout << "Invalid Model option specified\n";
				return 0;
			}
			model_type = model;
		}
		if (vm.count("directions") && isConfigFileAssigned == false) { //Compulsory Options but set to 1 by default
			int d = vm["directions"].as<int>();
			if (d == 1) {
				//directions_type_or_size = d;
				//std::cout << "\nDirection = " << directions_type_or_size;
			} else if (d == 2) {
				//directions_type_or_size = d;
				//std::cout << "\nDirection = " << directions_type_or_size;
			} else if (d > 2) {
				//directions_type_or_size = d;
				//std::cout << "\nDirection = " << directions_type_or_size;
			} else { //for 0 or negative directions
				std::cout << "Invalid Directions option specified\n";
				return 0;
			}
			directions_type_or_size = d;
		}
		if (vm.count("time-horizon") && isConfigFileAssigned == false) { //Compulsory Options
			double time_horizon = vm["time-horizon"].as<double>();
			if (time_horizon > 0) {
				time_bound = time_horizon;
				//std::cout << "\ntime_bound = " << time_bound;
			} else { //for 0 or negative time-bound
				std::cout << "Invalid time-horizon option specified\n";
				return 0;
			}
		} else if (isConfigFileAssigned == false) {
			std::cout << "Missing time-horizon option\n";
			return 0;
		}
		if (vm.count("time-step") && isConfigFileAssigned == false) { //Compulsory Options
			double sampling_time = vm["time-step"].as<double>();
			if (sampling_time > 0) {
				iterations_size = (unsigned int) time_bound / sampling_time; //return Integer Value
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
			int jump_size = vm["transition-size"].as<int>();
			if (jump_size >= 0) {
				transition_size = jump_size;
				//	std::cout << "\ntransition_size = " << transition_size;
			} else { //for negative jump-size
				std::cout << "Invalid transition-size option specified\n";
				return 0;
			}
		} else if (isConfigFileAssigned == false) {
			std::cout << "Missing transition-size option\n";
			return 0;
		}

		if (vm.count("gpu")) {
			Algorithm_Type = 11; //GPU_SF algorithm is selected
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
			int algorithm = vm["algorithm"].as<int>();
			if (algorithm == 1) {
				//std::cout << "Running Sequential Algorithm\n";
			} else if (algorithm == 2) {
				//std::cout<< "Running Parallel Algorithm using Multi-core acceleration\n";
			} else if (algorithm == 3) {
				//std::cout << "Running Parallel Algorithm: NOT to be Used\n";
			} else if (algorithm == 4) { //PAR_ITER
				//std::cout<< "Running Time-Slice Algorithm using Multi-core acceleration\n";
			} else if (algorithm == 11) { //PAR_ITER
				//std::cout<< "Running Flowpipe(PostC operation) computation on GPU\n";
			} else {
				std::cout << "Invalid algorithm option specified\n";
				return 0;
			}
			Algorithm_Type = algorithm;
			//cout << "algorithm =  "<<Algorithm_Type;
		}
		if (Algorithm_Type == 4) { //this argument will be set only if algorithm==time-slice or PAR_ITER
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
		/*if (vm.count("number-of-readings")) {
		 int avg = vm["number-of-readings"].as<int>();	//by default 1
		 if (avg >= 1) {
		 number_of_times = avg;
		 } else {	//for 0 or negative number-of-readings
		 std::cout << "Invalid number-of-readings option specified\n";
		 return 0;
		 }
		 }*/

		if (vm.count("pbfs")) {
			DiscreteAlgorithm = 12; //parallel Breadth First Search
			//std::cout<< "Running Reachability Analysis with parallel Breadth First Search using Multi-core acceleration\n";
		}

	} //ALL COMMAND-LINE OPTIONS are set completely

	// Initialize the model with the parameters given by the user

	initialize(iterations_size, time_bound, model_type, directions_type_or_size,
			transition_size, bad_state, forbidden_set);
	forbidden_set.second->print2file("./f_poly",2,0);
	std::list<symbolic_states::ptr> Symbolic_states_list;

	double Avg_wall_clock = 0.0, Avg_user_clock = 0.0, Avg_system_clock = 0.0;
	double Avg_cpu_use=0.0;
	long total_mem_used=0;
	double cpu_usage;
	boost::timer::cpu_timer tt1;
	number_of_times = 1;	//Taking Average of 5 readings
	for (int i = 1; i <= number_of_times; i++) { //Running in a loop of number_of_times to compute the average result
		init_cpu_usage();	//initializing the CPU Usage utility to start recording usages
		tt1.start();
		reachability reach;
		reach.setReachParameter(Hybrid_Automata, init_state,
				reach_parameters, transition_iterations, Algorithm_Type,
				Total_Partition, lp_solver_type_choosen, number_of_streams,
				Solver_GLPK_Gurobi_GPU, forbidden_set);
//cout<<"\nTesting 3\n";
		//cout<<"\n Before reach call\n";
		if (DiscreteAlgorithm != PBFS) { //Sequential Search implemented for Discrete Jumps
			std::cout << "\nRunning Sequential BFS\n";
			Symbolic_states_list = reach.computeSeqentialBFSReach(ce);
			/*Symbolic_states_list = reach(Hybrid_Automata, init_state,
					reach_parameters, transition_iterations, Algorithm_Type,
					Total_Partition, lp_solver_type_choosen, number_of_streams,
					Solver_GLPK_Gurobi_GPU, forbidden_set, ce);*/
		} else { //Parallel Breadth First Search implemented for Discrete Jumps
			std::cout << "\nRunning Parallel BFS\n";
			//Symbolic_states_list = reach.computeParallelBFSReach(ce);
			//Symbolic_states_list = reach.computeParallelBFSReachLockAvoid(ce);
			Symbolic_states_list = reach.computeParallelLoadBalanceReach(ce);

			/*Symbolic_states_list = reach_pbfs(Hybrid_Automata, init_state,
					reach_parameters, transition_iterations, Algorithm_Type,
					Total_Partition, lp_solver_type_choosen, number_of_streams,
					Solver_GLPK_Gurobi_GPU, forbidden_set, ce);*/
		}
//cout<<"\nTesting 4\n";
		tt1.stop();
		cpu_usage = getCurrent_ProcessCPU_usage();
		Avg_cpu_use = Avg_cpu_use  + cpu_usage;
		//todo:: if the size of transition is greater than it can compute there is segmentation fault

		double wall_clock, user_clock, system_clock;
		wall_clock = tt1.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		user_clock = tt1.elapsed().user / 1000000;
		system_clock = tt1.elapsed().system / 1000000;

		if (Algorithm_Type == 11) {
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
	/*std::cout<<"\nSize = "<<reachability_sfm.size()<<"\n";
	 std::cout<<"\nSize max_size = "<<reachability_sfm.max_size()<<"\n";*/

	if (Algorithm_Type == 11) {
		Avg_wall_clock = Avg_wall_clock / (number_of_times - 1);
		Avg_user_clock = Avg_user_clock / (number_of_times - 1);
		Avg_system_clock = Avg_system_clock / (number_of_times - 1);
	} else {
		Avg_wall_clock = Avg_wall_clock / number_of_times;
		Avg_user_clock = Avg_user_clock / number_of_times;
		Avg_system_clock = Avg_system_clock / number_of_times;
	}

	std::cout << std::fixed; //to assign precision on the std::output stream
	std::cout.precision(7); //cout << setprecision(17);
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
		cout << endl << "Number of Vectors = "
				<< reach_parameters.Directions.size1();
		cout << endl << "Number of Iteration = " << iterations_size << endl;

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
		cout << endl << "Number of Iteration = " << iterations_size << endl;
	} 
cout << endl << "Memory Usages = " << (double)(total_mem_used / 1024.0) / number_of_times << " MB\n";

		std::list<symbolic_states::ptr>::iterator it;
		/*
		 * Generating Vertices as output which can be plotted using gnuplot utilites
		 */
		std::ofstream outFile;
		int x = output_var_X, y = output_var_Y; // todo::take user's input for the plotting variables
		math::matrix<double> vertices_list;
		std::string fileName, fullPath, fileWithPath;
		const char *stFileNameWithPath;
		//cout << endl << "Working here 2\n";
		if (vm.count("include-path")) {
			fullPath = vm["include-path"].as<std::string>();
			std::cout << "Include Path is: " << fullPath << "\n";
		} else {
			fullPath = "./"; //default file path
		}
		//cout << endl << "Working here 3\n";
		fileWithPath.append(fullPath);

		if (vm.count("output-file")) {
			fileName = vm["output-file"].as<std::string>();
			std::cout << "fileName is: " << fileName << "\n";
		} else {
			fileName = "out.txt";
		}

		fileWithPath.append(fileName);

		std::cout << "fileWithPath is: " << fileWithPath << "\n";
		stFileNameWithPath = fileWithPath.c_str();
		outFile.open(stFileNameWithPath);
		//outFile.open("/home/amit/cuda-workspace/XSpeed/Debug/outFile.txt");

		//have to call the list of symbolic_states and compose polytope p(matrix A and vector b)
		//and call the polytope->function get_2dVertices
		for (it = Symbolic_states_list.begin();
				it != Symbolic_states_list.end(); it++) {
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
				vertices_list = p->get_2dVertices(x, y); //
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
		/*
		 * This part of code is for Plotting the Reachability Region in MatLab
		 */
		// ************************************************************************************************************
		int Totaldirs;
		std::ofstream MatLabFile_TemplateDirections, MatLabFile_InvariantsDirections;
		MatLabFile_TemplateDirections.open("/home/amit/matlabTest/ProjectOutput/DirectionsMatrix.txt");
		MatLabFile_InvariantsDirections.open("/home/amit/matlabTest/ProjectOutput/InvariantDirectionsMatrix.txt");

//  ***************** This was Commented  ****************************
		boost::timer::cpu_timer time_file_operation;
		time_file_operation.start(); //Started recording the MatLab File Generation time
//	XXXX---------------------------------------------------------XXXXX
		//Populating the Template_Directions :: simply copy from Template_Directions from reach_parameter structure
		for (int i = 0; i < reach_parameters.Directions.size1(); i++) {
			for (int j = 0; j < reach_parameters.Directions.size2(); j++) {
				MatLabFile_TemplateDirections
						<< reach_parameters.Directions(i, j) << " ";
			}
			MatLabFile_TemplateDirections << std::endl;
		}
//	XXXX---------------------------------------------------------XXXXX
		//Populating the Invariants_Directions :: copying all invariants directions from the reachRegion or the reachability flow-pipe
		//returned from the reach Algorithm in the form of template_polyhedra list.
		//Traverse through each of the list and extract invariant_directions.

		std::ofstream MatLabFileConfiguration;
//	std::ofstream MatLabFileInvariantBoundValues;
		MatLabFileConfiguration.open(
				"/home/amit/matlabTest/ProjectOutput/State_Iterations_Invariants.txt");
//	MatLabFileInvariantBoundValues.open("/home/amit/matlabTest/ProjectOutput/Invariants_BoundValue.txt");
		int number_of_invariants = 0, inv_size = 0, state_number = 0,
				state_iterations = 0;
//	XXXX---------------------------------------------------------XXXXX
		for (it = Symbolic_states_list.begin();
				it != Symbolic_states_list.end(); it++) {
			math::matrix<double> invariant_directions, invariant_bound_values;
			invariant_directions =
					(*it)->getContinuousSetptr()->getInvariantDirections(); //invariant_directions
			invariant_bound_values =
					(*it)->getContinuousSetptr()->getMatrix_InvariantBound(); //invariant_bound_matrix

			state_number++; //Each state has a Flow-pipe, (state_number begins from 1 to n)
			state_iterations =
					(*it)->getContinuousSetptr()->getMatrixSupportFunction().size2(); //total number of columns of SFM is iterations in each state

			number_of_invariants = invariant_directions.size1(); //ASSUMING SAME NUMBER OF INVARIANTS FOR ALL LOCATIONS

			MatLabFileConfiguration << state_number << " " << state_iterations;
			if (invariant_directions.size1() >= 1) { //or  invariant_directions.size1() != 0
				for (unsigned int i = 0; i < invariant_directions.size1();
						i++) {
					for (unsigned int j = 0; j < invariant_directions.size2();
							j++) {
						MatLabFile_InvariantsDirections
								<< invariant_directions(i, j) << " ";
					}
					MatLabFile_InvariantsDirections << std::endl;
				}
			}
			MatLabFileConfiguration << " " << number_of_invariants << std::endl;
		}
//	XXXX---------------------------------------------------------XXXXX

		MatLabFileConfiguration.close();
		MatLabFile_InvariantsDirections.close();
		MatLabFile_TemplateDirections.close();
		std::list<symbolic_states::ptr>::iterator i_sfm;
		std::ofstream MatLabFileSupportFunctionMatrix;
		Totaldirs = reach_parameters.Directions.size1(); // + number_of_invariants;	//if no invariants Totaldirs = dir_nums
		MatLabFileSupportFunctionMatrix.open(
				"/home/amit/matlabTest/ProjectOutput/SupportFunctionMatrix.txt");
//	XXXX---------------------------------------------------------XXXXX
		//Only SupportFunctionMatrix of FlowPipe
		for (int i = 0; i < Totaldirs; i++) { //i==row_number
			for (i_sfm = Symbolic_states_list.begin(); i_sfm != Symbolic_states_list.end(); i_sfm++) {
				//Each sysmbolic_state or each Location
				for (unsigned int k = 0; k < (*i_sfm)->getContinuousSetptr()->getMatrixSupportFunction().size2(); k++) { //k==col_number
					MatLabFileSupportFunctionMatrix << (*i_sfm)->getContinuousSetptr()->getMatrixSupportFunction()(i, k) << " ";
				}
			}
			MatLabFileSupportFunctionMatrix << endl;
		}
	//	cout<<"Testing Aa5\n";
//	XXXX---------------------------------------------------------XXXXX

//	XXXX---------------------------------------------------------XXXXX

		typedef std::vector<std::pair<double, double> > Intervals;

		std::list<std::pair<int, Intervals> > location_interval_outputs;
//	XXXX---------------------------------------------------------XXXXX
//Now adding invariantBoundMatrix of Flowpipe into the file
//ASSUMING SAME NUMBER OF INVARIANTS FOR ALL LOCATIONS
		for (int i = 0; i < number_of_invariants; i++) {
			for (it = Symbolic_states_list.begin();
					it != Symbolic_states_list.end(); it++) {
				for (unsigned int k = 0; k < (*it)->getContinuousSetptr()->getMatrix_InvariantBound().size2(); k++) {
					MatLabFileSupportFunctionMatrix << (*it)->getContinuousSetptr()->getMatrix_InvariantBound()(i, k) << " ";
				}
			}
			MatLabFileSupportFunctionMatrix << std::endl;
		}
//	XXXX---------------------------------------------------------XXXXX
		MatLabFileSupportFunctionMatrix.close();

//	cout<<"\nTesting 6c\n";

		time_file_operation.stop();
		double wall_clock_file_operation, user_clock_file_operation,
				system_clock_file_operation;
		wall_clock_file_operation = time_file_operation.elapsed().wall
				/ 1000000; //convert nanoseconds to milliseconds
		user_clock_file_operation = time_file_operation.elapsed().user
				/ 1000000;
		system_clock_file_operation = time_file_operation.elapsed().system
				/ 1000000;
		if (argc == 1) { //No argument or Running directly from the Eclipse Editor
			std::cout
					<< "\nTime taken for generating Output File to be executed in MATLAB!!!\n";
			std::cout << "\nBoost Time taken:Wall  (in Seconds) = "
					<< wall_clock_file_operation / (double) 1000 << std::endl;
			std::cout << "\nBoost Time taken:User  (in Seconds) = "
					<< user_clock_file_operation / (double) 1000 << std::endl;
			std::cout << "\nBoost Time taken:System  (in Seconds) = "
					<< system_clock_file_operation / (double) 1000 << std::endl;
		}
//	}


	if (ce != NULL) {
		cout << "******** Saftey Property Violated ********\n";
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
		//cout << "Length = " << ce->get_length() << "\n";
		for (it_trans = list_transition.begin();
				it_trans != list_transition.end(); it_trans++) {
			transID[index] = (*it_trans)->getTransitionId();
			index++;
			//cout << "Trans_ID = " << (*it_trans)->getTransitionId() << "\n";
		}
		index = 0;
		cout << "  *****Starts***** \n";
		for (it_sym_state = list_sym_states.begin();
				it_sym_state != list_sym_states.end(); it_sym_state++) {

			ds = (*it_sym_state)->getDiscreteSet();
			for (std::set<int>::iterator it = ds.getDiscreteElements().begin();
					it != ds.getDiscreteElements().end(); ++it)
				locationID = (*it);

			if (index == ce->get_length())
				cout << "(" << locationID << " , --)\n";
			else
				cout << "(" << locationID << " , " << transID[index] << ")\n";
			index++;
		}
		cout << "  *****Ends*****\n";
		ce->plot(output_var_X,output_var_Y);
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

// ************************************************************************************************************

/*
 location l = Hybrid_Automata.getInitial_Location();
 for (std::list<transitions>::iterator t =
 l.getOut_Going_Transitions().begin();
 t != l.getOut_Going_Transitions().end(); t++) { // get each destination_location_id and push into the pwl.waiting_list
 polytope::ptr gaurd_polytope;
 gaurd_polytope = (*t).getGaurd();
 std::vector<double> dir(4);
 dir[0] = 0;
 dir[1] = 0;
 dir[2] = 0;
 dir[3] = 1;
 lp_solver s(1), U(1);
 s.setMin_Or_Max(2);
 s.setConstraints(gaurd_polytope->getCoeffMatrix(),
 gaurd_polytope->getColumnVector(),
 gaurd_polytope->getInEqualitySign());
 double res = s.Compute_LLP(dir);
 std::cout << "Hello = " << res << std::endl;
 }
 */

//	cout<<"\ncompute beta = " <<reach_parameters.result_beta<<endl;
/*lp_gurobi_simplex problem;
 std::vector<double> direction;
 direction.resize(2);	//Down Direction
 direction[0] = 0;
 direction[1] = -1;
 problem.setMin_Or_Max(2);
 problem.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 double status = problem.Compute_LPP(direction);
 cout<<"Amit = "<<status<<endl;*/

/*
 boost::timer::cpu_timer time_file_operation;
 time_file_operation.start();//Started recording the MatLab File Generation time
 //Populating the Template_Directions :: simply copy from Template_Directions from reach_parameter structure
 for (int i = 0; i < dir_nums; i++) {
 for (int j = 0; j < dim; j++) {
 MatLabFile_TemplateDirections << reach_parameters.Directions(i, j)
 << " ";
 }
 MatLabFile_TemplateDirections << std::endl;
 }
 //Populating the Invariants_Directions :: copying all invariants directions from the reachRegion or the reachability flow-pipe
 //returned from the reach Algorithm in the form of template_polyhedra list.
 //Traverse through each of the list and extract invariant_directions.
 std::list<template_polyhedra>::iterator it;
 std::ofstream MatLabFileConfiguration;
 std::ofstream MatLabFileInvariantBoundValues;
 MatLabFileConfiguration.open(
 "/home/amit/matlabTest/ProjectOutput/State_Iterations_Invariants.txt");
 MatLabFileInvariantBoundValues.open(
 "/home/amit/matlabTest/ProjectOutput/Invariants_BoundValue.txt");
 int number_of_invariants = 0, inv_size = 0, state_number = 0,
 state_iterations = 0;
 for (it = reachability_sfm.begin(); it != reachability_sfm.end(); it++) {
 math::matrix<double> invariant_directions, invariant_bound_values;
 invariant_directions = (*it).getInvariantDirections();//invariant_directions
 invariant_bound_values = (*it).getMatrix_InvariantBound();//invariant_bound_matrix

 state_number++;	//Each state has a Flow-pipe, (state_number begins from 1 to n)
 state_iterations = (*it).getMatrixSupportFunction().size2();//total number of columns of SFM is iterations in each state

 MatLabFileConfiguration << state_number << " " << state_iterations;
 if (invariant_directions.size1() >= 1) { //or  invariant_directions.size1() != 0
 inv_size = invariant_directions.size1(); //number of invariants of the state
 if (inv_size > number_of_invariants) {
 number_of_invariants = inv_size;
 }
 for (unsigned int i = 0; i < invariant_directions.size1(); i++) {
 for (unsigned int j = 0; j < invariant_directions.size2();
 j++) {
 MatLabFile_InvariantsDirections
 << invariant_directions(i, j) << " ";
 }
 for (unsigned int k = 0; k < invariant_bound_values.size2();
 k++) {
 MatLabFileInvariantBoundValues
 << invariant_bound_values(i, k) << " ";
 }
 MatLabFile_InvariantsDirections << std::endl;
 MatLabFileInvariantBoundValues << std::endl;
 }
 }
 MatLabFileConfiguration << " " << number_of_invariants << std::endl;
 }
 MatLabFileConfiguration.close();
 MatLabFile_InvariantsDirections.close();
 MatLabFileInvariantBoundValues.close();
 MatLabFile_TemplateDirections.close();
 std::list<template_polyhedra>::iterator i_sfm;
 std::ofstream MatLabFileSupportFunctionMatrix;
 Totaldirs = dir_nums; // + number_of_invariants;	//if no invariants Totaldirs = dir_nums
 MatLabFileSupportFunctionMatrix.open(
 "/home/amit/matlabTest/ProjectOutput/SupportFunctionMatrix.txt");

 for (int i = 0; i < Totaldirs; i++) {
 for (i_sfm = reachability_sfm.begin(); i_sfm != reachability_sfm.end();
 i_sfm++) {
 for (unsigned int k = 0;
 k < (*i_sfm).getMatrixSupportFunction().size2(); k++) {
 MatLabFileSupportFunctionMatrix
 << (*i_sfm).getMatrixSupportFunction()(i, k) << " ";
 }
 }
 MatLabFileSupportFunctionMatrix << endl;
 }
 MatLabFileSupportFunctionMatrix.close();



 */

