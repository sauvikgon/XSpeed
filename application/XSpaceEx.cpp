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

/*
 #include "core_system/Reachability/reachabilitySequential.h"
 #include "core_system/Reachability/reachabilityParallel_Process.h"
 #include "core_system/Reachability/reachabilityParallel_Iterations.h"
 */
#include "core_system/math/uni_sphere.h"	//for obtaining uniformly distributed directions
#include "application/sf_directions.h"
#include "application/DataStructureDirections.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"
#include <boost/numeric/ublas/matrix.hpp>
#include "Utilities/Template_Polyhedra.h"
#include "Utilities/Post_Assignment.h"
#include <list>
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
#include "core_system/Reachability/reachability_HybridAutomata.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/HybridAutomata/Transition.h"
#include "core_system/HybridAutomata/Location.h"
#include "core_system/symbolic_states/symbolic_states.h"
//**************** Hybrid Automata Definition ***********************
#include "application/All_PP_Definition.h"

//#include "math/lp_gurobi_simplex.h"
//#include <boost/tokenizer.hpp>

symbolic_states initial_symbolic_states;
//**************** Hybrid Automata Definition ***********************

ReachabilityParameters reach_parameters;
int dir_nums, iterations, transition_iterations;
int dim;
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
		unsigned int directions_type_or_size, unsigned int transition_size) {
	size_type row, col;

	transition_iterations = transition_size; //Number of iterations for transition of the Hybrid system
	iterations = iterations_size; 			// number of iterations
	reach_parameters.TimeBound = time_bound;		//Total Time Interval

	reach_parameters.Iterations = iterations;	// number of iterations
	reach_parameters.time_step = reach_parameters.TimeBound
			/ reach_parameters.Iterations;

//Assigning the Model of the Hybrid System
//	(1,2,3,4,5,6,7) = (BBALL, TBBALL, HELICOPTER, FIVEDIMSYS, NAVIGATION, CIRCLE, CIRCLE_FOUR_LOC)
	HybridSystem_Model_Type = model_type;

//Assigning the Type of Directions
	Directions_Type = directions_type_or_size;	//(1,2,>2) = (BOX, OCT, UNIFORM)
	Uniform_Directions_Size = directions_type_or_size;//total number of UNIFORM directions

//Assigning the Model of the Hybrid System and the Dimension of the System as it is needed for setting the Number of Directions
	if (HybridSystem_Model_Type == BBALL) {
		//dim = 2;//Number of Dimension for the Current Working System for Bouncing Ball

		//Setting the initial parameters for Bouncing Ball Model
		//	std::cout << "\nRunning :: Model of A Bouncing Ball\n";
		//SetBouncingBall_Parameters(reach_parameters, initial_polytope_I, system_dynamics, invariant,gaurd_polytope, AssignRw);
		SetBouncingBall_Parameters(Hybrid_Automata, initial_symbolic_states,
				reach_parameters);
	}
	if (HybridSystem_Model_Type == TBBALL) {
		//dim = 3;//Number of Dimension for the Current Working System for Bouncing Ball
		//	std::cout << "\nRunning :: Model of A Timed Bouncing Ball\n";

		//Setting the initial parameters for Bouncing Ball Model
		/*	SetTimedBouncingBall_Parameters(reach_parameters, initial_polytope_I,
		 system_dynamics, invariant, gaurd_polytope, AssignRw);*/

		SetTimedBouncingBall_Parameters(Hybrid_Automata,
				initial_symbolic_states, reach_parameters);
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
		SetHelicopter_Parameters3(Hybrid_Automata, initial_symbolic_states,
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
		setSysParams(Hybrid_Automata, initial_symbolic_states,
				reach_parameters);
		//	std::cout << "\nParameter Assignment Completed!!!\n";
	}

	if (HybridSystem_Model_Type == NAVIGATION) {
		//dim = 2;
		//	std::cout << "\nRunning :: Benchmark Model of A Navigation\n";
		//Setting the initial parameters for Bouncing Ball Model
		//SetNavigationBenchMark(Hybrid_Automata, initial_symbolic_states,reach_parameters);//only 2 Variable

		//SetNavigationBenchMark4Var(Hybrid_Automata, initial_symbolic_states,reach_parameters);//Paper's Model
		//SetNavigationModel2(Hybrid_Automata, initial_symbolic_states,reach_parameters);	//My own testing Model NAV2
		SetNavigationModel4(Hybrid_Automata, initial_symbolic_states,
				reach_parameters);	//Model NAV04
		//	cout<<"\nTesting 2 b\n";
	}

	if (HybridSystem_Model_Type == CIRCLE) {
		//dim = 2;
		//std::cout << "\nRunning :: Model of A CIRCLE 2 Dimensional Systems\n";
		SetRotationCircle_Parameters(Hybrid_Automata, initial_symbolic_states,
				reach_parameters);
	}
	if (HybridSystem_Model_Type == CIRCLE_FOUR_LOC) {
		//dim = 2;
		std::cout
				<< "\nRunning :: Model of A CIRCLE with Four Locations 2-Dimensional Systems\n";
		SetRotationCircle4Location_Parameters(Hybrid_Automata,
				initial_symbolic_states, reach_parameters);
	}

	if (HybridSystem_Model_Type == CIRCLE_ONE_LOC) {
		//dim = 2;
		std::cout
				<< "\nRunning :: Model of A CIRCLE with ONE Location 2-Dimensional Systems\n";
		SetRotationCircleOneLocation_Parameters(Hybrid_Automata,
				initial_symbolic_states, reach_parameters);
	}

	dim = initial_symbolic_states.getContinuousSet()->getSystemDimension();

//Assigning the Number of Directions and Generating the Template Directions from the above given dimension of the model
	std::vector<std::vector<double> > newDirections;

	if (Directions_Type == BOX) {
		dir_nums = 2 * dim;		//Axis Directions
		newDirections = generate_axis_directions(dim);
	}
	if (Directions_Type == OCT) {
		dir_nums = 2 * dim * dim; 	// Octagonal directions
		newDirections = get_octagonal_directions(dim);
	}

	if (Directions_Type > 2) {
		dir_nums = Uniform_Directions_Size;	// ASSIGN HERE Number of Vectors/Directions for UNIform spear algorithm
		newDirections = math::uni_sphere(dir_nums, dim, 100, 0.0005);
	}
//	dir_nums = dir_nums + 2; //Directions increased by 2 for invariant's direction :: Note : some improvement has to be done here later to avoid repeated Direction
	get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here****** Temporary solution
	row = dir_nums;
	col = dim;
	reach_parameters.Directions.resize(row, col);

	/*Real_Directions(0, 0) = 0.731;
	 Real_Directions(0, 1) = -0.682;
	 Real_Directions(1, 0) = -0.731;
	 Real_Directions(1, 1) = -0.682;
	 Real_Directions(2, 0) = -0.682;
	 Real_Directions(2, 1) = 0.731;
	 Real_Directions(3, 0) = 0.682;
	 Real_Directions(3, 1) = 0.731;*/

	reach_parameters.Directions = Real_Directions; //Direct Assignment
}

int main(int argc, char *argv[]) {
	//cout<<"Started from here\n";
	double time_bound;
	unsigned int model_type, iterations_size, directions_type_or_size;
	int transition_size;
	int Algorithm_Type, DiscreteAlgorithm;
	int number_of_times = 10;		//Make this 1 for Memory Profiling
	unsigned int number_of_streams = 1;
	int lp_solver_type_choosen = 1;	//	1 for GLPK and 2 for Gurobi
	int Solver_GLPK_Gurobi_GPU;	//if Algorithm == 11 then (1 for GLPK; 2 for Gurobi; 3 for GPU)
	unsigned int Total_Partition; //for Parallel Iterations Algorithm :: number of partitions/threads

	if (argc == 1) { //No argument or Running directly from the Eclipse Editor
		//(1,2,3,4,5,6,7,8) = (BBALL, TBBALL, HELICOPTER, FIVEDIMSYS, NAVIGATION, CIRCLE,CIRCLE_FOUR_LOCATION, CIRCLE_ONE_LOC)
		model_type = 5;
		directions_type_or_size = 1;	//(1,2,>2) = (BOX, OCT, UNIFORM)
		iterations_size = 500;	//number of iterations
		time_bound = 10;	//This is Local Time Horizon
		transition_size = 1; //Number of iterations for transition of the Hybrid system
		//Algorithms-Value(1,2,3,4,5,6,7,8,9,10,11)
		//(SEQ,PAR_OMP,PAR_PROCESS,PAR_ITER,PAR_ITER_DIR,PAR_BY_PARTS,PAR_BY_PARTS_ITERS,SAME_DIRS, GPU_MULTI_SEQ,GPU_SF)
		Algorithm_Type = 1;
		DiscreteAlgorithm = 1;	// 12 for PBFS or any other values for sequential discrete jump
		Total_Partition = 16; //maximum value = iterations_size (so that each partition will have at least 1 omega to be computed)
		number_of_streams = 1;	//Number of streams in GPU(division)
		lp_solver_type_choosen = 1;	//For the entire Tool
		number_of_times = 1;		//Make this 1 for Memory Profiling
		Solver_GLPK_Gurobi_GPU = 1;	//if Algorithm == 11 then (1 for GLPK; 2 for Gurobi; 3 for GPU)
		//	cout << "\nRunning Testing 1\n";
	}

	if (argc > 1) {
		/*
		 std::cout << "argc = "<<argc<<std::endl;
		 std::cout << "argv[1] = "<<argv[1]<<std::endl;
		 std::cout << "argv[2] = "<<argv[2]<<std::endl;
		 std::cout << "argv[3] = "<<argv[3]<<std::endl;
		 std::cout << "argv[4] = "<<argv[4]<<std::endl;
		 std::cout << "argv[5] = "<<argv[5]<<std::endl;
		 std::cout << "argv[6] = "<<argv[6]<<std::endl;
		 std::cout << "argv[7] = "<<argv[7]<<std::endl;
		 */

		if (argc != 12) {		//1(ApplicationName) + 10 (Input Arguments)
			std::cout << "\nInsufficient Number of Arguments!!!\n";
			std::cout << "Correct Usages/Syntax:\n";
			std::cout
					<< "./XspaceEx Model_Type Directions_Type_Size Iterations_Size Time_Bound Transition_Size Algorithm_Type Total_Partition Total_GPU_Streams Averaging Solver_GLPK_Gurobi_GPU Discrete_Algorithm\n";
			std::cout
					<< "\n1. Model_Type :(1,2,3,4,5,6) = (BBALL, TBBALL, HELICOPTER, FIVEDIMSYS, NAVIGATION, CIRCLE)\n";
			std::cout
					<< "\n2. Directions_Type_Size :(1,2,>2) = (BOX, OCT, UNIFORM)\n";
			std::cout
					<< "\n3. Iterations_Size :Number of iterations per Location of the Hybrid system\n";
			std::cout << "\n4. Time_Bound :Total Time Bound for Computation\n";
			std::cout
					<< "\n5. Transition_Size :Number of jumps or transitions of the Hybrid system\n";
			std::cout
					<< "\n6. Algorithm_Type :(1,2,3,4) = (SEQ, PAR_OMP, PAR_PROCESS, PAR_ITER)\n";
			std::cout
					<< "\n7. Total_Partition :Total number of partitions required for Parallel_Iteration_Algorithm\n";
			std::cout
					<< "\n8. Total_GPU_Streams :Total number of GPU Streams or partitions\n";
			std::cout
					<< "\n9. Averaging :Total number of times you want to run the algorithm to average the readings\n";
			std::cout
					<< "\n10. Solver_GLPK_Gurobi_GPU :If Algorithm==11 then (Solver = 1 for GLPK; = 2 for Gurobi; = 3 for GPU)\n";
			std::cout
					<< "\n11. Discrete_Algorithm: 12 for Parallel BFS for Discrete Jumps, otherwise sequential\n";
			std::cout << endl;
			return 0;

		} else {
			unsigned int num;
			num = boost::lexical_cast<unsigned int>(argv[1]);
			model_type = num;
			directions_type_or_size = boost::lexical_cast<unsigned int>(
					argv[2]);
			iterations_size = boost::lexical_cast<unsigned int>(argv[3]);
			double val = boost::lexical_cast<double>(argv[4]);
			time_bound = val;
			transition_size = boost::lexical_cast<unsigned int>(argv[5]);
			Algorithm_Type = boost::lexical_cast<unsigned int>(argv[6]);
			Total_Partition = boost::lexical_cast<unsigned int>(argv[7]);
			number_of_streams = boost::lexical_cast<unsigned int>(argv[8]);
			number_of_times = boost::lexical_cast<unsigned int>(argv[9]);
			Solver_GLPK_Gurobi_GPU = boost::lexical_cast<unsigned int>(
					argv[10]);
			DiscreteAlgorithm = boost::lexical_cast<unsigned int>(argv[11]);
		}

	}

	/*(int iterations_size, double time_bound, unsigned int model_type,
	 unsigned int directions_type_or_size, unsigned int transition_size, unsigned int algorithm)*/
	initialize(iterations_size, time_bound, model_type, directions_type_or_size,
			transition_size);	//Initialising the variables
//	cout<<"Initialisation of reachability problem complete\n";
	/*
	 size_type row;
	 size_type col;
	 */
//cout<<"\nTesting 2\n";
	std::list<template_polyhedra> reachability_sfm;

	//List/Array of Reachability Region/FlowPipe of all transitions.
	//to be changed into a single variable instead of list.

	double Avg_wall_clock = 0.0, Avg_user_clock = 0.0, Avg_system_clock = 0.0;

//	long total_mem_used=0;

	boost::timer::cpu_timer tt1;

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

	for (int i = 1; i <= number_of_times; i++) { //Running in a loop of number_of_times to compute the average result
		tt1.start();
//cout<<"\nTesting 3\n";
		//cout<<"\n Before reach call\n";
		if (DiscreteAlgorithm != PBFS) {//Sequential Search implemented for Discrete Jumps
			reachability_sfm = reach(Hybrid_Automata, initial_symbolic_states,
					reach_parameters, transition_iterations, Algorithm_Type,
					Total_Partition, lp_solver_type_choosen, number_of_streams,
					Solver_GLPK_Gurobi_GPU);
		} else {//Parallel Breadth First Search implemented for Discrete Jumps
			reachability_sfm = reach_pbfs(Hybrid_Automata,
					initial_symbolic_states, reach_parameters,
					transition_iterations, Algorithm_Type, Total_Partition,
					lp_solver_type_choosen, number_of_streams,
					Solver_GLPK_Gurobi_GPU);
		}
//cout<<"\nTesting 4\n";
		tt1.stop();

		double wall_clock, user_clock, system_clock;
		wall_clock = tt1.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		user_clock = tt1.elapsed().user / 1000000;
		system_clock = tt1.elapsed().system / 1000000;
		if (Algorithm_Type == 11) {
			//11 is GPU:: First execution of GPU includes warm-up time, so this time should not be included for averaging
			if (i == 1) {	//first run for averaging
				continue;	//do not include time here
			}
			Avg_wall_clock = Avg_wall_clock + wall_clock;
			Avg_user_clock = Avg_user_clock + user_clock;
			Avg_system_clock = Avg_system_clock + system_clock;
		} else {	//Average all runs
			Avg_wall_clock = Avg_wall_clock + wall_clock;
			Avg_user_clock = Avg_user_clock + user_clock;
			Avg_system_clock = Avg_system_clock + system_clock;
		}
	}
//	total_mem_used = getCurrentProcess_PhysicalMemoryUsed();
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

	std::cout << std::fixed;	//to assign precision on the std::output stream
	std::cout.precision(7);			//cout << setprecision(17);
	double return_Time = Avg_wall_clock / (double) 1000;

	if (argc == 1) {//No argument or Running directly from the Eclipse Editor

		//----Disabling the console Output to Generate the Data using Shell Script
		std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << return_Time
				<< std::endl;

		std::cout << "\nBoost Time taken:User  (in Seconds) = "
				<< Avg_user_clock / (double) 1000 << std::endl;
		std::cout << "\nBoost Time taken:System  (in Seconds) = "
				<< Avg_system_clock / (double) 1000 << std::endl;

		cout << endl << "Number of Vectors = " << dir_nums;
		cout << endl << "Number of Iteration = " << iterations << endl;
	}		//endif of argc == 1

//	cout << endl << "Memory Usages = " << total_mem_used / number_of_times << " KB\n";

	/*
	 * This part of code is for Plotting the Reachability Region in MatLab
	 */
	// ************************************************************************************************************
	int Totaldirs;
	std::ofstream MatLabFile_TemplateDirections,
			MatLabFile_InvariantsDirections;
	MatLabFile_TemplateDirections.open(
			"/home/amit/matlabTest/ProjectOutput/DirectionsMatrix.txt");
	MatLabFile_InvariantsDirections.open(
			"/home/amit/matlabTest/ProjectOutput/InvariantDirectionsMatrix.txt");

	//file for making matrix 'A' for MatLab output function con2vert(A,b) to be executed from plotoutput.m
	//Need to create
	//1) Files for SupportFunctionMatrix(ie to obtain each column for vector b) with Configurations_details
	//2) Files for Template_Directions and Invariant_directions with Configurations_details such as (state#,nos of invariants)

	//  ***************** This was Commented  ****************************
	/*
	 if (reach_parameters.Directions.size1()
	 < reach_parameters.TotalDirections.size1()) {//if invariant exist. Computing
	 Totaldirs = reach_parameters.TotalDirections.size1();
	 std::list<template_polyhedra>::iterator it;
	 //for (it=reachability_sfm.begin();	it !=reachability_sfm.end();it++){
	 it = reachability_sfm.begin();//first flowpipe
	 math::matrix<double> reach_directions;
	 reach_directions = (*it).getAllDirections();
	 //	cout << "Total Dirs = " << reach_directions.size1() << endl;
	 for (int i = 0; i < Totaldirs; i++) {
	 for (int j = 0; j < dim; j++) {
	 MatLabfile << reach_parameters.TotalDirections(i, j) << " ";
	 }
	 MatLabfile << std::endl;
	 for (unsigned int i = 0; i < reach_directions.size1(); i++) {
	 for (unsigned int j = 0; j < reach_directions.size2(); j++) {
	 //	MatLabfile << reach_parameters.TotalDirections(i, j) << " ";
	 MatLabfile << reach_directions(i, j) << " ";
	 }
	 MatLabfile << std::endl;
	 }
	 } else {
	 Totaldirs = dir_nums;
	 for (int i = 0; i < dir_nums; i++) {
	 for (int j = 0; j < dim; j++) {
	 MatLabfile << reach_parameters.Directions(i, j) << " ";
	 }
	 MatLabfile << std::endl;
	 }
	 }
	 }*/
//  ***************** This was Commented  ****************************
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
//cout<<"\nTesting 6a\n";

	//Populating the Invariants_Directions :: copying all invariants directions from the reachRegion or the reachability flow-pipe
	//returned from the reach Algorithm in the form of template_polyhedra list.
	//Traverse through each of the list and extract invariant_directions.
	std::list<template_polyhedra>::iterator it;
	std::ofstream MatLabFileConfiguration, MatLabFileInvariantBoundValues;
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
//cout<<"\nTesting 6b\n";

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

//	cout<<"\nTesting 6c\n";

	time_file_operation.stop();
	double wall_clock_file_operation, user_clock_file_operation,
			system_clock_file_operation;
	wall_clock_file_operation = time_file_operation.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	user_clock_file_operation = time_file_operation.elapsed().user / 1000000;
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
	} else {
		std::cout << return_Time; //running from command Line for output generation
	}				//endif of argc == 1

// ************************************************************************************************************
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

	return 0;//returning only the Wall time taken to execute the Hybrid System
}

