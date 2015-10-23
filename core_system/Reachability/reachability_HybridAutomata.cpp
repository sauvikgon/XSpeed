/*
 * reachability_HybridAutomata.cpp
 *
 *  Created on: 24-Nov-2014
 *      Author: amit
 */

#include "core_system/Reachability/reachability_HybridAutomata.h"

//bound is the maximum number of transitions or jumps permitted.
//reach_parameters includes the different parameters needed in the computation of reachability.
//I is the initial symbolic state

/**
 * TODO: Reach needs to be optimized; Like populating the parameters outside the loop
 * once which remains the same throught the computation, for example, directions.
 *
 * Have to optimize invariant_boundary_check() for support function computation
 */

std::list<template_polyhedra> reach(hybrid_automata& H, symbolic_states& I,
		ReachabilityParameters& reach_parameters, int bound,
		unsigned int Algorithm_Type, unsigned int Total_Partition,
		int lp_solver_type_choosen, unsigned int number_of_streams,
		int Solver_GLPK_Gurobi_GPU) {
//	std::cout<<"Algorithm_Type = "<<Algorithm_Type<<std::endl;
	std::list<template_polyhedra> Reachability_Region;
	template_polyhedra reach_region;
	pwl pwlist;
	discrete_set discrete_state;

	pwlist.WaitingList_insert(I);
	int number_times = 0;
//	cout<<"\nTesting 2 a\n";

	polytope::ptr continuous_initial_polytope;

	while (!pwlist.WaitingList_isEmpty()) {
		symbolic_states U;
//		cout<<"\nTesting 2 a 1\n";
		U = pwlist.WaitingList_delete_front();
//		cout<<"\nTesting 2 a 2\n";
		discrete_state = U.getDiscreteSet();
		continuous_initial_polytope = U.getContinuousSet();
		reach_parameters.X0 = continuous_initial_polytope;

//		cout<<"\nTesting 2 a 3\n";
		pwlist.PassedList_insert(U);
		int location_id;
//		cout<<"\nTesting 2 a 4\n";

		for (std::set<int>::iterator it =
				discrete_state.getDiscreteElements().begin();
				it != discrete_state.getDiscreteElements().end(); ++it)
			location_id = (*it); //have to modify later for multiple elements of the set:: Now assumed only one element
//		cout<<"\nTesting 2 a 5\n";
		/*if (location_id == 1)
		 cout<<"\nOne\n";*/
		//string name = boost::lexical_cast<string>(location_id);	//convert integer to string
		//cout<<"\nTesting 2 a 6\n";
		location current_location;
		/*if (name == "1")
		 cout<<"\nString 1 \n";*/
//			cout<<"\nTesting 2 a 7 \n";
		current_location = H.getLocation(location_id);
		string name = current_location.getName();
		//	cout << "\nLocation Name = " << name << "\n";
		if ((name.compare("GOOD") == 0) || (name.compare("BAD") == 0)
				|| (name.compare("UNSAFE") == 0)
				|| (name.compare("FINAL") == 0))
			continue; //do not compute the continuous reachability algorithm

		//current_location = H.getLocation(name);
		//	cout<<"\nTesting 2 a 8 \n";
		//Convert string to number
		//int value = boost::lexical_cast<int>(str);

		// ******************* Computing Parameters *******************************
		//In this current_location the parameters will change for eg., alfa, beta and phi_trans  have to be re-computed
		/*
		 * Computing the parameters to avoid multiple computation in the child process
		 * Items Required :: time_step, phi_trans , B_trans, compute_alfa,compute_beta
		 */
//			cout<<"\nTesting 2 b\n";
		//	GeneratePolytopePlotter(continuous_initial_polytope);
		/*
		 * Computation of compute_alfa depends on initial set. For algorithm PAR_BY_PARTS where the
		 * initial set in divided into parts. Compute_alfa should be computed for each initial sets.
		 * */
		double result_alfa = compute_alfa(reach_parameters.time_step,
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, lp_solver_type_choosen); //2 glpk object created here

		//	cout << "\nReach_Parameters.time_step = " << reach_parameters.time_step << endl;
		//			cout << "\n1st Compute Alfa = " << result_alfa << endl;
		//	cout<<"\nTesting 2 c\n";
		double result_beta = compute_beta(current_location.getSystem_Dynamics(),
				reach_parameters.time_step, lp_solver_type_choosen); // NO glpk object created here
		//		cout << "\n1st Compute Beta = " << result_beta << endl;
		reach_parameters.result_alfa = result_alfa;
		reach_parameters.result_beta = result_beta;
		//	cout<<"\nTesting 2 d\n";
		// Intialised the transformation and its transpose matrix
		math::matrix<double> phi_matrix, phi_trans;

		current_location.getSystem_Dynamics().MatrixA.matrix_exponentiation(
				phi_matrix, reach_parameters.time_step);
		phi_matrix.transpose(phi_trans);
		reach_parameters.phi_trans = phi_trans;
		math::matrix<double> B_trans;
		// transpose to be done once and stored in the structure of parameters */
		current_location.getSystem_Dynamics().MatrixB.transpose(B_trans);
		reach_parameters.B_trans = B_trans;

		//--------------------------

		/*		// ***** ********************* ********************* ********************* ********************* *********************
		 // *****   this part will be needed Only if we executed our new ImprovedReachSequentialwithDelete algorithm ***
		 // ***** this part is also used to perform parallel algorithm for Iterations by partition
		 // *****  this part should be done after 	reach_parameters.phi_trans is computed
		 std::vector<D> NewDirections;//all directions for Improved Algorithm with Structure_variables : flag,Row and Col
		 unsigned int total_Iterated_Direction;
		 total_Iterated_Direction = reach_parameters.Directions.size1()
		 * reach_parameters.Iterations;
		 NewDirections.resize(total_Iterated_Direction);
		 NewDirections = get_directions(reach_parameters);//requires only directions,iterations,matrix_A

		 reach_parameters.AdvanceTransposeDirection = NewDirections;

		 */
//		std::cout<<"Invariant matrix \n"<<current_location.getInvariant()->getCoeffMatrix()<<"\n";
		/*for (int i=0;i<reach_parameters.Directions.size1();i++)
		 {
		 for (int j=0;j<reach_parameters.Iterations;j++)
		 {
		 std::cout<<"Each Direction :";
		 int pos = i * reach_parameters.Iterations + j;
		 std::cout<<"(";
		 for (int d=0;d<reach_parameters.Directions.size2();d++)
		 std::cout<<reach_parameters.AdvanceTransposeDirection[pos].v[d]<<",";
		 //std::cout<<NewDirections[pos].v[d]<<",";
		 std::cout<<")";
		 }
		 std::cout<<"\n";
		 }*/
		// ***** ********************* ********************* ********************* ********************* *********************
		// ******************* Computing Parameters *******************************
		//	for (int number_times = 1; number_times <= bound; number_times++) {	//Bound for loop in Hybrid AutomataGeneratePolytopePlotter(continuous_initial_polytope);
//GeneratePolytopePlotter(continuous_initial_polytope);
		if (Algorithm_Type == SEQ) { //Continuous Sequential Algorithm
			cout << "\nRunning Sequntial\n";
			//		std::cout<<"\nBefore entering reachability Sequential = " << gurobi_lp_solver::gurobi_lp_count;
			//		std::cout<<"\nBefore entering reachability Sequential = " << lp_solver::lp_solver_count;
//			int a;			std::cin>>a;
			boost::timer::cpu_timer AllReach_time;
			AllReach_time.start();
			reach_region = reachabilitySequential(
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location.getInvariant(),
					current_location.isInvariantExists(),
					lp_solver_type_choosen);
			AllReach_time.stop();
			double wall_clock1;
			wall_clock1 = AllReach_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
			double return_Time1 = wall_clock1 / (double) 1000;
			std::cout << "\nAllReach_time: Boost Time:Wall(Seconds) = "
					<< return_Time1 << std::endl;
		}

		if (Algorithm_Type == PAR_OMP) {
			//Parallel implementation using OMP parallel			//	double wall_timer = omp_get_wtime();
			cout << "\nRunning Parallel Using OMP Thread\n";
			reach_region = reachabilityParallel(
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location.getInvariant(),
					current_location.isInvariantExists(),
					lp_solver_type_choosen);
			//	std::cout << "Parallel Done\n";
			//	std::cout << "Time seen from mop wall timer: "<< omp_get_wtime() - wall_timer << std::endl;
		}
		/*
		if (Algorithm_Type == GPU_SF) { //computing all support function in GPU
			cout << "\nRunning GPU Sequential\n";
			boost::timer::cpu_timer AllReachGPU_time;
			AllReachGPU_time.start();
			reach_region = reachabilitySequential_GPU(
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location.getInvariant(),
					current_location.isInvariantExists(),
					lp_solver_type_choosen, number_of_streams,
					Solver_GLPK_Gurobi_GPU);
			AllReachGPU_time.stop();
			double wall_clock1;
			wall_clock1 = AllReachGPU_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
			double return_Time1 = wall_clock1 / (double) 1000;
			std::cout << "\nAllReach_time: Boost Time:Wall(Seconds) = "
					<< return_Time1 << std::endl;


		} */

		if (Algorithm_Type == PAR_ITER) { //Continuous Parallel Algorithm parallelizing the Iterations :: to be debugged (compute initial polytope(s))
			cout
					<< "\nRunning Parallel-over-Iterations(PARTITIONS) Using OMP Thread\n";
			bool invertible;
			math::matrix<double> A_inv(
					current_location.getSystem_Dynamics().MatrixA.size1(),
					current_location.getSystem_Dynamics().MatrixA.size2());
			invertible = current_location.getSystem_Dynamics().MatrixA.inverse(
					A_inv); //size of A_inv must be declared else error
			if (!invertible)
				std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
			else
				reach_parameters.A_inv = A_inv;

			int NCores = Total_Partition; //Number of Partitions (number of threads)
			reach_region = reachParallelExplore(
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location.getInvariant(),
					current_location.isInvariantExists(), NCores, PAR_ITER,
					lp_solver_type_choosen);
			//		std::cout << "Finished computing reachable states\n";
		}

//Continuous Parallel Algorithm ::by set partitioning
		if (Algorithm_Type == PAR_BY_PARTS) {
			reach_region = reachabilityPartitions(
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location.getInvariant(),
					current_location.isInvariantExists(),
					lp_solver_type_choosen);
		} //NO IMPROVEMENT SEEN with two partitions have to try for more partitions
		  //tried with more partitions but not much improvement seen

		if (Algorithm_Type == SAME_DIRS) { //Continuous Sequential Algorithm avoiding supp. func. computation
			reach_region = reachabilitySameDirection(
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location.getInvariant(),
					current_location.isInvariantExists(),
					lp_solver_type_choosen);
		} //Improvement in performance seen upto 1.3 to 1.5 times compare to sequential algorithm

		if (Algorithm_Type == PAR_BY_PARTS_ITERS) {
			cout << "Algorithm not yet implemented!!!!\n";
			/*	int Cores = Total_Partition;//Number of Partitions (number of threads)
			 reach_region = reachabilityPartitions_par_iters(
			 current_location.getSystem_Dynamics(),
			 continuous_initial_polytope, reach_parameters,
			 current_location.getInvariant(),
			 current_location.isInvariantExists(), Cores,
			 lp_solver_type_choosen);*/
		}

		if (Algorithm_Type == PAR_ITER_DIR) {
			//using OMP:: Parallel implementation with a combination of Iterations and Directions
			//	cout << "\nRunning Parallel Using combination of Iterations and Directions\n";
			bool invertible;
			math::matrix<double> A_inv(
					current_location.getSystem_Dynamics().MatrixA.size1(),
					current_location.getSystem_Dynamics().MatrixA.size2());
			invertible = current_location.getSystem_Dynamics().MatrixA.inverse(
					A_inv); //size of A_inv must be declared else error
			if (!invertible)
				std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
			else
				reach_parameters.A_inv = A_inv;

			int NCores = Total_Partition; //Number of Partitions (number of threads)
			reach_region = reachParallelExplore(
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location.getInvariant(),
					current_location.isInvariantExists(), NCores, PAR_ITER_DIR,
					lp_solver_type_choosen);
		}

		if (Algorithm_Type == GPU_MULTI_SEQ) {
			//Continuous Sequential Algorithm mixed with Cublas Multiplication
			cout << "\nRunning Mixed CPU - GPU Sequntial\n";
			/*	reach_region = reachabilitySequential_GPU_MatrixVector_Multiply(
			 current_location.getSystem_Dynamics(),
			 continuous_initial_polytope, reach_parameters,
			 current_location.getInvariant(),
			 current_location.isInvariantExists(),
			 lp_solver_type_choosen);*/
		}	// Performance degraded

		if (Algorithm_Type == PAR_PROCESS) { //Continuous Parallel Algorithm parallelizing the Directions
			//Parallel implementation using Process Creation
//			 cout << "\nRunning Parallel Using Process Creation\n";
			reach_region = reachabilityParallel_Process(
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location.getInvariant(),
					current_location.isInvariantExists(),
					lp_solver_type_choosen);
//		 cout << "\nContinuous Reachability Parallel Using Process Creation COMPLETTED!!!\n";
		}	//to be removed from the Project

		//Creating a list of objects of "reachability set" for each transition; also used FOR PLOTTING IN MATLAB
		if (reach_region.getTotalIterations() == 0) { //computed reach_region is empty
			//	cout << "Doing continue\n";
			continue;//going back to next symbolic set without counting transistion time.
		}

		Reachability_Region.push_back(reach_region);

		polytope::ptr test = polytope::ptr(
				new polytope(reach_region.getPolytope(61).getCoeffMatrix(),
						reach_region.getPolytope(61).getColumnVector(), 1));
		GeneratePolytopePlotter(test);


//			std::cout<<"\nOutside Continuous Reachability Algorithm\n";
		/*std::cout<<"\nLocation's transition's Label = "<<current_location.getAdjTransitions().front().getLabel()<<"\n";
		 std::cout<<"\nLocation's transition's destination_location's Name = "<<current_location.getAdjTransitions().front().getDestination().getName()<<"\n";
		 std::cout<<"\nLocation's transition's source_location's Name = "<<current_location.getAdjTransitions().front().getSource().getName()<<"\n";
		 */
		//cout << "\nLocation Name = " << name << "\n";
		for (std::list<transitions>::iterator t =
				current_location.getOut_Going_Transitions().begin();
				t != current_location.getOut_Going_Transitions().end(); t++) { // get each destination_location_id and push into the pwl.waiting_list
			if ((*t).getTransitionId() == -1) //Indicates empty transition or no transition exists
				break; //out from transition for-loop as there is no transition for this location
			location current_destination;
			Assign current_assignment;
			polytope::ptr gaurd_polytope;
			std::list<template_polyhedra> intersected_polyhedra;
			polytope::ptr intersectedRegion; //created two objects here
			discrete_set ds;

			//	std::cout<<"\nOut_Going_Transition's Destination_Location_ID = "<< (*t).getDestination_Location_Id()<<"\n";
			//	std::cout<<"\nOut_Going_Transition's Label = "<< (*t).getLabel()<<"\n";
			current_destination = H.getLocation(
					(*t).getDestination_Location_Id());
			//				std::cout<<"\nTest location insde = "<<current_destination.getName()<<"\n";
			string locName = current_destination.getName();
			//	cout<<"Next trans Location name = "<< locName <<endl;
			if ((locName.compare("BAD") == 0) || (locName.compare("GOOD") == 0)
					|| (locName.compare("FINAL") == 0)
					|| (locName.compare("UNSAFE") == 0))
				continue; //do not push into the waitingList

			gaurd_polytope = (*t).getGaurd();
			current_assignment = (*t).getAssignT();
//	GeneratePolytopePlotter(gaurd_polytope);
			/*//std::cout<<"Assignment matrix R \n"<<current_assignment.Map<<"\n";
			 for (int i=0;i<current_assignment.b.size();i++)
			 std::cout<<current_assignment.b[i]<<"\n";*/
//			std::cout<<"Gaurd matrix \n"<<gaurd_polytope->getCoeffMatrix()<<"\n";
			/*
			 for (int i=0;i<gaurd_polytope.getCoeffMatrix().size1();i++){
			 for (int j=0;j<gaurd_polytope.getCoeffMatrix().size2();j++)
			 std::cout<<gaurd_polytope.getCoeffMatrix()(i,j)<<"\t";
			 std::cout<<"\n";
			 }
			 */
			//	std::cout << "Before calling Templet_polys\n";
			//cout<<reach_region.getMatrixSupportFunction().size2()<<"AmitJi\n";
			//this intersected_polyhedra will have invariant direction added in it
			string trans_name = (*t).getLabel();
//	cout<<"Trans Name = "<<trans_name<<endl;
			intersected_polyhedra = reach_region.polys_intersection(
					gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
//	cout<<"Trans Name = "<<trans_name<<endl;
			/*cout<<endl<<intersected_polyhedra.getTemplateDirections()<<endl;
			 cout<<endl<<intersected_polyhedra.getMatrixSupportFunction()<<endl;*/

			//	cout<<"size = "<< intersected_polyhedra.getMatrixSupportFunction().size1();
			//returns the list of polytopes that intersects with the gaurd_polytope
			//unsigned int iterations_before_intersection = intersection_start_point - 1;
			//Templet_polys.resize_matrix_SupportFunction(dir_nums, iterations_before_intersection);
//			std::cout << "Before calling getTemplate_approx\n";
			int element = (*t).getDestination_Location_Id();
			ds.insert_element(element);
			std::cout << "\nNumber of intersection with Flowpipe and guard = "
					<< intersected_polyhedra.size();
			for (std::list<template_polyhedra>::iterator i =
					intersected_polyhedra.begin();
					i != intersected_polyhedra.end(); i++) {
				//	cout<<"\nLoop\n";
				/*cout<<(*i).getTemplateDirections()<<endl;
				 cout<<(*i).getMatrixSupportFunction()<<endl;*/
				intersectedRegion = (*i).getTemplate_approx(
						lp_solver_type_choosen);
//	GeneratePolytopePlotter(intersectedRegion);
				//Returns a single over-approximated polytope from the list of intersected polytopes
				//			std::cout << "Before calling getPolytope_Intersection\n";
				//	GeneratePolytopePlotter(intersectedRegion);
				polytope::ptr newShiftedPolytope, newPolytope; //created an object here
				newPolytope = intersectedRegion->GetPolytope_Intersection(
						gaurd_polytope, lp_solver_type_choosen); //Retuns only the intersected region as a single newpolytope. ****** with added directions
				//	GeneratePolytopePlotter(newPolytope);
				//			std::cout << "Before calling post_assign_exact\n";

				/*cout<<newPolytope->getCoeffMatrix()<<endl;
				 for (int x=0;x<newPolytope->getCoeffMatrix().size1();x++)
				 cout<<newPolytope->getColumnVector()[x]<<"\t";*/

				newShiftedPolytope = post_assign_exact(newPolytope,
						current_assignment.Map, current_assignment.b); //initial_polytope_I = post_assign_exact(newPolytope, R, w);
				//cout<<"assignment R = "<<current_assignment.Map<<"\n";
				//	GeneratePolytopePlotter(newShiftedPolytope);
				//	std::cout << "test amit 1\n";

				/*cout<<newShiftedPolytope->getCoeffMatrix()<<endl;
				 for (int x=0;x<newShiftedPolytope->getCoeffMatrix().size1();x++)
				 cout<<newShiftedPolytope->getColumnVector()[x]<<"\t";*/

				symbolic_states newState(ds, newShiftedPolytope);
				pwlist.WaitingList_insert(newState);
				//	std::cout << "Going Back to Loop\n";
			} //end of multiple intersected region with guard
			  //	cout<<"Size = "<< pwlist.getWaitingList().size()<<endl;
		} //end of multiple transaction
		  //	cout << "\nLocation Name 3 = " << name << "\n";
		number_times++;
		if (number_times >= bound)//check to see how many jumps have been made(i.e., number of discrete transitions made)
			break;
		//}	//end-of Number of transition's Loop
	} //end of while loop checking waiting_list != empty
	return Reachability_Region;
}

/**
 * TODO: Have to optimize invariant_boundary_check() for support function computation
 */

void ReachFunction(unsigned int Algorithm_Type, location current_location,
		polytope::ptr continuous_initial_polytope,
		ReachabilityParameters& reach_parameters, int lp_solver_type_choosen,
		unsigned int Total_Partition, unsigned int number_of_streams,
		int Solver_GLPK_Gurobi_GPU, std::vector<template_polyhedra>& reach_region,
		unsigned int id) {

	if (Algorithm_Type == SEQ) { //Continuous Sequential Algorithm
		cout << "\nRunning Sequntial\n";
		//		std::cout<<"\nBefore entering reachability Sequential = " << gurobi_lp_solver::gurobi_lp_count;
		//		std::cout<<"\nBefore entering reachability Sequential = " << lp_solver::lp_solver_count;
//			int a;			std::cin>>a;
		boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();
		reach_region[id] = reachabilitySequential(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
		AllReach_time.stop();
		double wall_clock1;
		wall_clock1 = AllReach_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nAllReach_time: Boost Time:Wall(Seconds) = "
				<< return_Time1 << std::endl;
	}

	if (Algorithm_Type == PAR_OMP) {
		//Parallel implementation using OMP parallel			//	double wall_timer = omp_get_wtime();
		cout << "\nRunning Parallel Using OMP Thread\n";
		reach_region[id] = reachabilityParallel(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
		//	std::cout << "Parallel Done\n";
		//	std::cout << "Time seen from mop wall timer: "<< omp_get_wtime() - wall_timer << std::endl;
	}
	/*
	if (Algorithm_Type == GPU_SF) { //computing all support function in GPU
		cout << "\nRunning GPU Sequential\n";
		boost::timer::cpu_timer AllReachGPU_time;
		AllReachGPU_time.start();
		reach_region[id] = reachabilitySequential_GPU(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen,
				number_of_streams, Solver_GLPK_Gurobi_GPU);
		AllReachGPU_time.stop();
		double wall_clock1;
		wall_clock1 = AllReachGPU_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nAllReach_time: Boost Time:Wall(Seconds) = "
				<< return_Time1 << std::endl;

	} */

	if (Algorithm_Type == PAR_ITER) { //Continuous Parallel Algorithm parallelizing the Iterations :: to be debugged (compute initial polytope(s))
		cout
				<< "\nRunning Parallel-over-Iterations(PARTITIONS) Using OMP Thread\n";
		bool invertible;
		math::matrix<double> A_inv(
				current_location.getSystem_Dynamics().MatrixA.size1(),
				current_location.getSystem_Dynamics().MatrixA.size2());
		invertible = current_location.getSystem_Dynamics().MatrixA.inverse(
				A_inv); //size of A_inv must be declared else error
		if (!invertible)
			std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
		else
			reach_parameters.A_inv = A_inv;

		int NCores = Total_Partition; //Number of Partitions (number of threads)
		reach_region[id] = reachParallelExplore(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), NCores, PAR_ITER,
				lp_solver_type_choosen);
		//		std::cout << "Finished computing reachable states\n";
	}

//Continuous Parallel Algorithm ::by set partitioning
	if (Algorithm_Type == PAR_BY_PARTS) {
		reach_region[id] = reachabilityPartitions(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
	} //NO IMPROVEMENT SEEN with two partitions have to try for more partitions
	  //tried with more partitions but not much improvement seen

	if (Algorithm_Type == SAME_DIRS) { //Continuous Sequential Algorithm avoiding supp. func. computation
		reach_region[id] = reachabilitySameDirection(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
	} //Improvement in performance seen upto 1.3 to 1.5 times compare to sequential algorithm

	if (Algorithm_Type == PAR_BY_PARTS_ITERS) {
		cout << "Algorithm not yet implemented!!!!\n";
		/*	int Cores = Total_Partition;//Number of Partitions (number of threads)
		 reach_region = reachabilityPartitions_par_iters(
		 current_location.getSystem_Dynamics(),
		 continuous_initial_polytope, reach_parameters,
		 current_location.getInvariant(),
		 current_location.isInvariantExists(), Cores,
		 lp_solver_type_choosen);*/
	}

	if (Algorithm_Type == PAR_ITER_DIR) {
		//using OMP:: Parallel implementation with a combination of Iterations and Directions
		//	cout << "\nRunning Parallel Using combination of Iterations and Directions\n";
		bool invertible;
		math::matrix<double> A_inv(
				current_location.getSystem_Dynamics().MatrixA.size1(),
				current_location.getSystem_Dynamics().MatrixA.size2());
		invertible = current_location.getSystem_Dynamics().MatrixA.inverse(
				A_inv); //size of A_inv must be declared else error
		if (!invertible)
			std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
		else
			reach_parameters.A_inv = A_inv;

		int NCores = Total_Partition; //Number of Partitions (number of threads)
		reach_region[id] = reachParallelExplore(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), NCores, PAR_ITER_DIR,
				lp_solver_type_choosen);
	}
    /*
	if (Algorithm_Type == GPU_MULTI_SEQ) {
		//Continuous Sequential Algorithm mixed with Cublas Multiplication
		cout << "\nRunning Mixed CPU - GPU Sequntial\n";
		//	reach_region = reachabilitySequential_GPU_MatrixVector_Multiply(
		// current_location.getSystem_Dynamics(),
		// continuous_initial_polytope, reach_parameters,
		// current_location.getInvariant(),
		// current_location.isInvariantExists(),
		// lp_solver_type_choosen);
	}	 Performance degraded
 	*/
	if (Algorithm_Type == PAR_PROCESS) { //Continuous Parallel Algorithm parallelizing the Directions
		//Parallel implementation using Process Creation
//			 cout << "\nRunning Parallel Using Process Creation\n";
		reach_region[id] = reachabilityParallel_Process(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
//		 cout << "\nContinuous Reachability Parallel Using Process Creation COMPLETTED!!!\n";
	}	//to be removed from the Project

}

std::list<template_polyhedra> reach_pbfs(hybrid_automata& H, symbolic_states& I,
		ReachabilityParameters& reach_parameters, int bound,
		unsigned int Algorithm_Type, unsigned int Total_Partition,
		int lp_solver_type_choosen, unsigned int number_of_streams,
		int Solver_GLPK_Gurobi_GPU) {

	std::list<template_polyhedra> Reachability_Region;

	pwl pwlist;
	pwlist.WaitingList_insert(I);
	int number_times = 0;
	bool stop_loop = false;
	while (!pwlist.WaitingList_isEmpty()) {

		//To avoid write-contention for reach_region, Vector/List of reach_region_list created for each threads
		// write in its respective index. So need a unique ID for each thread which can be obtained from
		// the size of the PWList at each iteration

		unsigned int count = pwlist.get_waiting_list_size();//get the size of PWList
		cout << "\nCount = " << count << "\n";
		std::vector<template_polyhedra> reach_region_list(count);//each thread write's flowpipe on separate index

		//Create a sublist of symbolic_states and work with it inside the parallel region(each thread accesses uniquely)
		std::vector<symbolic_states> list_U(count);	//SubList for parallel
		for (int i = 0; i < count; i++) {
			list_U[i] = pwlist.WaitingList_delete_front();
			pwlist.PassedList_insert(list_U[i]);
		}	//All symbolic_states have been deleted	//	cout<<"\nIdentifed pwList Done";
// ********************************* BFS Starts **********************************************************
//Threads or OMP can be used here
#pragma omp parallel for
		for (unsigned int id = 0; id < count; id++) {
			//there will be different current_location, continuous_initial_polytope, reach_parameters
			symbolic_states U;	//local
			U = list_U[id];	//independent symbolic state to work with
			discrete_set discrete_state;	//local
			polytope::ptr continuous_initial_polytope;	//local
			ReachabilityParameters reach_parameter_local;	//local

			discrete_state = U.getDiscreteSet();
			continuous_initial_polytope = U.getContinuousSet();
			reach_parameter_local = reach_parameters;
			reach_parameter_local.X0 = continuous_initial_polytope;//	cout<<"\nInside for Loop";
			int location_id;
			for (std::set<int>::iterator it =
					discrete_state.getDiscreteElements().begin();
					it != discrete_state.getDiscreteElements().end(); ++it)
				location_id = (*it); //have to modify later for multiple elements of the set:: Now assumed only one element
			location current_location;
			current_location = H.getLocation(location_id);
			string name = current_location.getName();
			if ((name.compare("GOOD") == 0) || (name.compare("BAD") == 0)
					|| (name.compare("UNSAFE") == 0)
					|| (name.compare("FINAL") == 0))
				continue; //do not compute the continuous reachability algorithm

			// ******************* Computing Parameters *******************************
			//current_location:: parameters alfa, beta and phi_trans have to be re-computed
			//cout<<"\nBefore Compute Alfa";
			double result_alfa = compute_alfa(reach_parameter_local.time_step,
					current_location.getSystem_Dynamics(),
					continuous_initial_polytope, lp_solver_type_choosen); //2 glpk object created here
//cout<<"\nCompute Alfa Done";
			double result_beta = compute_beta(
					current_location.getSystem_Dynamics(),
					reach_parameter_local.time_step, lp_solver_type_choosen); // NO glpk object created here
//			cout<<"\nCompute Beta Done";
			reach_parameter_local.result_alfa = result_alfa;
			reach_parameter_local.result_beta = result_beta;

			math::matrix<double> phi_matrix, phi_trans;
			current_location.getSystem_Dynamics().MatrixA.matrix_exponentiation(
					phi_matrix, reach_parameter_local.time_step);
			phi_matrix.transpose(phi_trans);
			reach_parameter_local.phi_trans = phi_trans;
			math::matrix<double> B_trans;
			current_location.getSystem_Dynamics().MatrixB.transpose(B_trans);
			reach_parameter_local.B_trans = B_trans;
			// ******************* Computing Parameters Done *******************************
			//  ********************* FlowPipe or Reach Computation *************************
			ReachFunction(Algorithm_Type, current_location,
					continuous_initial_polytope, reach_parameter_local,
					lp_solver_type_choosen, Total_Partition, number_of_streams,
					Solver_GLPK_Gurobi_GPU, reach_region_list, id);
			// Returns the Flow_Pipe in reach_region_list[id]
			//  ********************* FlowPipe or Reach Computation Done ********************
//  ************** Check to see if Computed FlowPipe is Empty  **********
			if (reach_region_list[id].getTotalIterations() != 0) { //computed reach_region is empty
				cout <<"\nLoc ID = "<<current_location.getLocId() <<" Location Name = " << name << "\n";

				for (std::list<transitions>::iterator t =
						current_location.getOut_Going_Transitions().begin();
						t != current_location.getOut_Going_Transitions().end();
						t++) { // get each destination_location_id and push into the pwl.waiting_list
					if ((*t).getTransitionId() == -1) { //Indicates empty transition or no transition exists
						break; //out from transition for-loop as there is no transition for this location
					}
					location current_destination;
					Assign current_assignment;
					polytope::ptr gaurd_polytope;
					std::list<template_polyhedra> intersected_polyhedra;
					polytope::ptr intersectedRegion; //created two objects here
					discrete_set ds;
					current_destination = H.getLocation(
							(*t).getDestination_Location_Id());
					string locName = current_destination.getName();
					cout <<"\nNext Loc ID = "<<current_destination.getLocId()<< " Location Name = " << locName << "\n";
					if ((locName.compare("BAD") == 0)
							|| (locName.compare("GOOD") == 0)
							|| (locName.compare("FINAL") == 0)
							|| (locName.compare("UNSAFE") == 0)) {
						continue; //do not push into the waitingList
					}
					gaurd_polytope = (*t).getGaurd();
					current_assignment = (*t).getAssignT();

					//this intersected_polyhedra will have invariant direction added in it
					string trans_name = (*t).getLabel();
					intersected_polyhedra =
							reach_region_list[id].polys_intersection(
									gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
//			std::cout << "Before calling getTemplate_approx\n";
					int element = (*t).getDestination_Location_Id();
					ds.insert_element(element);
					for (std::list<template_polyhedra>::iterator i =
							intersected_polyhedra.begin();
							i != intersected_polyhedra.end(); i++) {
						cout<<"\nNumber of Intersections #1\n";
						intersectedRegion = (*i).getTemplate_approx(
								lp_solver_type_choosen);
						//Returns a single over-approximated polytope from the list of intersected polytopes
						polytope::ptr newShiftedPolytope, newPolytope; //created an object here
						newPolytope =
								intersectedRegion->GetPolytope_Intersection(
										gaurd_polytope, lp_solver_type_choosen); //Retuns only the intersected region as a single newpolytope. ****** with added directions
						//std::cout << "Before calling post_assign_exact\n";
						newShiftedPolytope = post_assign_exact(newPolytope,
								current_assignment.Map, current_assignment.b); //initial_polytope_I = post_assign_exact(newPolytope, R, w);
						symbolic_states newState(ds, newShiftedPolytope);
#pragma omp critical
						{
//
// Todo:: we insert all the symbolic_states into the pwlist for computing FlowPipe iff 1) and 2) holds
// Step 1) the new current_destination.getLocID() is NOT in the Passed List and
// Step 2) the "New Initial Polytope" or "the newShiftedPolytope" is NOT contained in the FlowPipe of LocationID of step 1
//  as the FlowPipe in the same location will be same if the newShiftedPolytope is IN FlowPipe
//  But if Step 1 holds and Step 2 does not then it will be inserted in pwlist even if the LocationID is in Passed List
//
							pwlist.WaitingList_insert(newState); //RACE CONDITION HERE
						}
					} //end of multiple intersected region with guard
					  //cout<<"Size = "<< pwlist.getWaitingList().size()<<endl;
				} //end of multiple transaction
				  //Here we have again populated the pwlist for next-round's parallel process
			} // End-if  ******* Check for Empty FlowPipe Done *********
#pragma omp critical
			{
				number_times++;	//RACE CONDITION HERE
				cout << "\nnumber_times = " << number_times << "\n";
			//	cout << "\nBound = " << bound << "\n";
			}
			if (number_times >= bound) { //check to see how many jumps have been made(i.e., number of discrete transitions made)
				stop_loop = true;
				//break;	//So all threads does this in common
			}
		} //END of parallel FOR-LOOP
		  // ************************* BFS Ends *************************************
//Here i need to join threads and get there computed flowpipe(i.e., reach_region)
//Creating a list of objects of "Reachability Set" for each transition
		for (unsigned int index = 0; index < count; index++) {
			if (reach_region_list[index].getTotalIterations() != 0) //computed reach_region is NOT empty
				Reachability_Region.push_back(reach_region_list[index]);
		}

		if (stop_loop)	//Number of jump over
			break;
	} //end of while loop checking waiting_list != empty
	return Reachability_Region;
}
