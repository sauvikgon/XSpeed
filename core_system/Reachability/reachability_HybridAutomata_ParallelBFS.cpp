/*
 * reachability_HybridAutomata.cpp
 *
 *  Created on: 24-Nov-2014
 *      Author: amit
 */

#include "core_system/Reachability/reachability_HybridAutomata_ParallelBFS.h"

using namespace std;
//bound is the maximum number of transitions or jumps permitted.
//reach_parameters includes the different parameters needed in the computation of reachability.
//I is the initial symbolic state

/**
 * TODO: Have to optimize invariant_boundary_check() for support function computation
 */

void ReachFunction(unsigned int Algorithm_Type, location current_location,
		polytope::ptr continuous_initial_polytope,
		ReachabilityParameters& reach_parameters, int lp_solver_type_choosen,
		unsigned int Total_Partition, unsigned int number_of_streams,
		int Solver_GLPK_Gurobi_GPU, std::vector<symbolic_states::ptr>& S,
		unsigned int id) {

	template_polyhedra::ptr reach_region;

	if (Algorithm_Type == SEQ) { //Continuous Sequential Algorithm
	//	cout << "\nRunning Sequntial\n";
		//		std::cout<<"\nBefore entering reachability Sequential = " << gurobi_lp_solver::gurobi_lp_count;
		//		std::cout<<"\nBefore entering reachability Sequential = " << lp_solver::lp_solver_count;
//			int a;			std::cin>>a;
		boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();

		reach_region = reachabilitySequential(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
		S[id]->setContinuousSetptr(reach_region);

		AllReach_time.stop();
		double wall_clock1;
		wall_clock1 = AllReach_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nFlowPipe Time:Wall(Seconds) = "<< return_Time1 << std::endl;
	}

	if (Algorithm_Type == PAR_OMP) {
		//Parallel implementation using OMP parallel			//	double wall_timer = omp_get_wtime();
		//cout << "\nRunning Parallel Using OMP Thread\n";
		boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();

		reach_region = reachabilityParallel(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
		AllReach_time.stop();
		S[id]->setContinuousSetptr(reach_region);
		double wall_clock1;
		wall_clock1 = AllReach_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nFlowpipe Time:Wall(Seconds) = "<< return_Time1 << std::endl;
		//	std::cout << "Time seen from mop wall timer: "<< omp_get_wtime() - wall_timer << std::endl;
	}
/*
	if (Algorithm_Type == GPU_SF) { //computing all support function in GPU
		cout << "\nRunning GPU Sequential\n";
		boost::timer::cpu_timer AllReachGPU_time;
		AllReachGPU_time.start();
		reachabilitySequential_GPU(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen,
				number_of_streams, Solver_GLPK_Gurobi_GPU, reach_region);
		S[id]->setContinuousSetptr(reach_region);

		AllReachGPU_time.stop();
		double wall_clock1;
		wall_clock1 = AllReachGPU_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nAllReach_time: Boost Time:Wall(Seconds) = "
				<< return_Time1 << std::endl;

	} */

	if (Algorithm_Type == PAR_ITER) { //Continuous Parallel Algorithm parallelizing the Iterations :: to be debugged (compute initial polytope(s))
		cout
				<< "\nRunning Parallel-over-Iterations(PARTITIONS/Time-Sliced) Using OMP Thread\n";
		bool invertible;
		if (!current_location.getSystem_Dynamics().isEmptyMatrixA) {

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
			S[id]->setContinuousSetptr(reach_region);
			//		std::cout << "Finished computing reachable states\n";
		} else {
			std::cout << "\nFlow Dynamics Matrix A does not exists!!!\n";
			template_polyhedra::ptr poly_emptyp;
			reach_region = poly_emptyp; //returning an empty reach_region for this location
			S[id]->setContinuousSetptr(reach_region);

		}
	}

//Continuous Parallel Algorithm ::by set partitioning
	if (Algorithm_Type == PAR_BY_PARTS) {
		reach_region = reachabilityPartitions(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
		S[id]->setContinuousSetptr(reach_region);
	} //NO IMPROVEMENT SEEN with two partitions have to try for more partitions
	  //tried with more partitions but not much improvement seen

	if (Algorithm_Type == SAME_DIRS) { //Continuous Sequential Algorithm avoiding supp. func. computation
		reach_region = reachabilitySameDirection(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
		S[id]->setContinuousSetptr(reach_region);
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
		if (!current_location.getSystem_Dynamics().isEmptyMatrixA) {
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
			S[id]->setContinuousSetptr(reach_region);
		} else {
			std::cout << "\nFlow Dynamics Matrix A does not exists!!!\n";
			template_polyhedra::ptr poly_emptyp;
			reach_region = poly_emptyp; //returning an empty reach_region for this location
			S[id]->setContinuousSetptr(reach_region);
		}
	}

	/*	 if (Algorithm_Type == GPU_MULTI_SEQ) {
	 //Continuous Sequential Algorithm mixed with Cublas Multiplication
	 cout << "\nRunning Mixed CPU - GPU Sequntial\n";
	 reach_region = reachabilitySequential_GPU_MatrixVector_Multiply(
	 current_location.getSystem_Dynamics(),
	 continuous_initial_polytope, reach_parameters,
	 current_location.getInvariant(),
	 current_location.isInvariantExists(),
	 lp_solver_type_choosen);
	 } // Performance degraded
	 */
	if (Algorithm_Type == PAR_PROCESS) { //Continuous Parallel Algorithm parallelizing the Directions
		//Parallel implementation using Process Creation
//			 cout << "\nRunning Parallel Using Process Creation\n";
		reach_region = reachabilityParallel_Process(
				current_location.getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location.getInvariant(),
				current_location.isInvariantExists(), lp_solver_type_choosen);
		S[id]->setContinuousSetptr(reach_region);
//		 cout << "\nContinuous Reachability Parallel Using Process Creation COMPLETTED!!!\n";
	} //to be removed from the Project

}

std::list<symbolic_states::ptr> reach_pbfs(hybrid_automata& H,
		initial_state::ptr& I, ReachabilityParameters& reach_parameters,
		int bound, unsigned int Algorithm_Type, unsigned int Total_Partition,
		int lp_solver_type_choosen, unsigned int number_of_streams,
		int Solver_GLPK_Gurobi_GPU, std::pair<int, polytope::ptr> forbidden_set,
		abstractCE::ptr& ce) {

	std::list<symbolic_states::ptr> Reachability_Region;
//	template_polyhedra::ptr reach_region;

	pwlist pw_list;
	pw_list.WaitingList_insert(I);
	int number_times = 0;
	unsigned int iter_max = 0;

	bool stop_loop = false;

	bool saftey_violated = false;

	while (!pw_list.isEmpty_WaitingList()) {

		//To avoid write-contention for reach_region, Vector/List of reach_region_list created for each threads
		// write in its respective index. So need a unique ID for each thread which can be obtained from
		// the size of the PWList at each iteration

		unsigned int count = pw_list.getWaitingListSize(); //get the size of PWList
		iter_max = iter_max + count;
		cout << "\nCount = " << count << "\n";
		//vector<template_polyhedra::ptr> reach_region_list(count); //each thread write's flowpipe on separate index
		std::vector<symbolic_states::ptr> S(count);

		//Create a sublist of initial_state and work with it inside the parallel region(each thread accesses uniquely)
		//vector<symbolic_states> list_U(count); //SubList for parallel
		vector<initial_state::ptr> list_U(count); //SubList for parallel

		for (int i = 0; i < count; i++) {
			list_U[i] = pw_list.WaitingList_delete_front();
			pw_list.PassedList_insert(list_U[i]);
		} //All initial_state have been deleted	//	cout<<"\nIdentifed pwList Done";
// ********************************* BFS Starts **********************************************************

//Threads or OMP can be used here

		omp_set_dynamic(0);	//handles dynamic adjustment of the number of threads within a team
		omp_set_nested(2);	//enable nested parallelism
		//omp_set_num_threads(10);
		omp_set_max_active_levels(2);
#pragma omp parallel for  num_threads(2)
		for (unsigned int id = 0; id < count; id++) {
			/*if (id==0){
				std::cout<<"\nMax Thread in Outer Lavel = "<< omp_get_num_threads();
				std::cout<<"\nMax Active Levels = "<<omp_get_max_active_levels();
			}
			std::cout<<"\n Outer threadID = "<<omp_get_thread_num()<<"\n";*/
			//there will be different current_location, continuous_initial_polytope, reach_parameters
			initial_state::ptr U; //local
			//	symbolic_states::ptr S = symbolic_states::ptr(new symbolic_states());
			U = list_U[id]; //independent symbolic state to work with
			discrete_set discrete_state; //local
			polytope::ptr continuous_initial_polytope; //local
			ReachabilityParameters reach_parameter_local; //local

			int location_id = U->getLocationId();
			discrete_state.insert_element(location_id);
			continuous_initial_polytope = U->getInitialSet();
			reach_parameter_local = reach_parameters;
			reach_parameter_local.X0 = continuous_initial_polytope;
//create an instance of Symbolic_states S
			S[id] = symbolic_states::ptr(new symbolic_states());

			S[id]->setDiscreteSet(discrete_state);
			S[id]->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
			S[id]->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID

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
			if (!current_location.getSystem_Dynamics().isEmptyMatrixA) { //if A not Empty
				current_location.getSystem_Dynamics().MatrixA.matrix_exponentiation(
						phi_matrix, reach_parameter_local.time_step);
				phi_matrix.transpose(phi_trans);
				reach_parameter_local.phi_trans = phi_trans;
			}
			math::matrix<double> B_trans;
			if (!current_location.getSystem_Dynamics().isEmptyMatrixB) { //if B not Empty
				current_location.getSystem_Dynamics().MatrixB.transpose(
						B_trans);
				reach_parameter_local.B_trans = B_trans;
			}
			// ******************* Computing Parameters Done *******************************

			//  ********************* FlowPipe or Reach Computation *************************
			ReachFunction(Algorithm_Type, current_location,
					continuous_initial_polytope, reach_parameter_local,
					lp_solver_type_choosen, Total_Partition, number_of_streams,
					Solver_GLPK_Gurobi_GPU, S, id);
			// Returns the Flow_Pipe in reach_region_list[id]
			//  ********************* FlowPipe or Reach Computation Done ********************

			//  ************** Check to see if Computed FlowPipe is Empty  **********
			template_polyhedra::ptr t_poly = S[id]->getContinuousSetptr();

			if (t_poly->getTotalIterations() != 0 && number_times < bound) { //computed reach_region is empty && optimize computation
			//cout << "\nLoc ID = " << current_location.getLocId() << " Location Name = " << name << "\n";

				for (std::list<transition::ptr>::iterator t =
						current_location.getOut_Going_Transitions().begin();
						t != current_location.getOut_Going_Transitions().end();
						t++) { // get each destination_location_id and push into the pwl.waiting_list
					int transition_id = (*t)->getTransitionId();
					if (transition_id == -1) { //Indicates empty transition or no transition exists
						break; //out from transition for-loop as there is no transition for this location
					}
					location current_destination;
					Assign current_assignment;
					polytope::ptr gaurd_polytope;
					std::list<template_polyhedra> intersected_polyhedra;
					polytope::ptr intersectedRegion; //created two objects here
					discrete_set ds;
					current_destination = H.getLocation(
							(*t)->getDestination_Location_Id());
					string locName = current_destination.getName();
					//	cout << "\nNext Loc ID = " << current_destination.getLocId() << " Location Name = " << locName << "\n";
					if ((locName.compare("BAD") == 0)
							|| (locName.compare("GOOD") == 0)
							|| (locName.compare("FINAL") == 0)
							|| (locName.compare("UNSAFE") == 0)) {
						continue; //do not push into the waitingList
					}
					gaurd_polytope = (*t)->getGaurd();
					current_assignment = (*t)->getAssignT();


					boost::timer::cpu_timer t100;
					t100.start();


					//this intersected_polyhedra will have invariant direction added in it
					string trans_name = (*t)->getLabel();
					intersected_polyhedra = t_poly->polys_intersectionParallel(
							gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
//			std::cout << "Before calling getTemplate_approx\n";
					t100.stop();
					double clock100;
					clock100 = t100.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
					double return100 = clock100 / (double) 1000;
					std::cout << "\nIntersection Time:Wall(Seconds) = "<< return100 << std::endl;




					int destination_locID = (*t)->getDestination_Location_Id();
					ds.insert_element(destination_locID);
					for (std::list<template_polyhedra>::iterator i =
							intersected_polyhedra.begin();
							i != intersected_polyhedra.end(); i++) {
						//	cout << "\nNumber of Intersections #1\n";
						intersectedRegion = (*i).getTemplate_approx(
								lp_solver_type_choosen);
						//Returns a single over-approximated polytope from the list of intersected polytopes
						polytope::ptr newShiftedPolytope, newPolytope; //created an object here
						newPolytope =
								intersectedRegion->GetPolytope_Intersection(
										gaurd_polytope); //Retuns only the intersected region as a single newpolytope. ****** with added directions

						newShiftedPolytope = post_assign_exact(newPolytope,
								current_assignment.Map, current_assignment.b); //initial_polytope_I = post_assign_exact(newPolytope, R, w);

						initial_state::ptr newState = initial_state::ptr(
								new initial_state(destination_locID,
										newShiftedPolytope));
						newState->setTransitionId(transition_id); // keeps track of the transition_ID
						newState->setParentPtrSymbolicState(S[id]);

#pragma omp critical
						{
							/*
							 * Todo:: we insert all the symbolic_states into the pwlist for computing FlowPipe iff 1) and 2) holds
							 * Step 1) the new current_destination.getLocID() is NOT in the Passed List and
							 * Step 2) the "New Initial Polytope" or "the newShiftedPolytope" is NOT contained in the FlowPipe of LocationID of step 1
							 *  as the FlowPipe in the same location will be same if the newShiftedPolytope is IN FlowPipe
							 *  But if Step 1 holds and Step 2 does not then it will be inserted in pwlist even if the LocationID is in Passed List
							 */
							pw_list.WaitingList_insert(newState); //RACE CONDITION HERE

						}
					} //end of multiple intersected region with guard
					  //cout<<"Size = "<< pwlist.getWaitingList().size()<<endl;
				} //end of multiple transaction
				  //Here we have again populated the pwlist for next-round's parallel process
			} // End-if  ******* Check for Empty FlowPipe Done *********
		} //END of parallel FOR-LOOP

//:: Can be optimize if we can count number_times inside the parallel loop per breadth then we can avoid transaction and intersection
//:: computation for next transition if number_times exceeds bound ....
		number_times++; //One Level or one Breadth Search over
		//cout << "\nnumber_times = " << number_times << "  Bound = " << bound << "\n";
		// ************************* BFS Ends *************************************

		//Creating a list of objects of "Reachability Set"/Symbolic_states
		for (unsigned int index = 0; index < count; index++) {

			template_polyhedra::ptr t_poly = S[index]->getContinuousSetptr();
			if (t_poly->getTotalIterations() != 0) //computed reach_region is NOT empty
				Reachability_Region.push_back(S[index]);

			//  ******************************** Safety Verification section ********************************
			std::list<symbolic_states::ptr> list_sym_states;

			std::list<abstract_symbolic_state::ptr> list_abstract_sym_states;
			polytope::ptr abs_flowpipe;	//bounding_box Polytope
			polytope::ptr polyI; // initial polytope of the abstract flowpipe.

			std::list<transition::ptr> list_transitions;

			if (t_poly->getTotalIterations() != 0) { //flowpipe exists
				//so perform intersection with forbidden set provided locID matches

				int locID;
				discrete_set ds;
				ds = S[index]->getDiscreteSet();
				for (std::set<int>::iterator it =
						ds.getDiscreteElements().begin();
						it != ds.getDiscreteElements().end(); ++it)
					locID = (*it); //Assuming only a single element exist in the discrete_set
				/*location current_location;
				 current_location = H.getLocation(locID);*/

				//int forbid_locID = current_location.getLocId();
				int forbid_locID = locID;
				if (forbid_locID == forbidden_set.first) { //forbidden locID matches
					polytope::ptr forbid_poly = forbidden_set.second;
					//check intersection with flowpipe/reach_region
					//GeneratePolytopePlotter(forbid_poly);
					std::list<template_polyhedra> forbid_intersects;
					forbid_intersects = t_poly->polys_intersectionParallel(
							forbid_poly, lp_solver_type_choosen);
					if (forbid_intersects.size() == 0) {
						std::cout
								<< "\nThe model does NOT violates SAFETY property!!!\n";
					} else {
						std::cout
								<< "\nThe model violates SAFETY property!!!\n";
						symbolic_states::ptr current_forbidden_state;
						current_forbidden_state = S[index];

						std::cout << "\nReverse Path Trace =>\n";
						int cc = 0;
						do {
							int locationID, locationID2;
							discrete_set ds, ds2;
							ds = current_forbidden_state->getDiscreteSet();

							abs_flowpipe =
									convertBounding_Box(
											current_forbidden_state->getContinuousSetptr());
							polyI = current_forbidden_state->getInitial_ContinousSetptr();
							// Here create a new abstract_symbolic_state
							abstract_symbolic_state::ptr curr_abs_sym_state = abstract_symbolic_state::ptr(
																new abstract_symbolic_state(ds,abs_flowpipe,polyI));

							// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********

							for (std::set<int>::iterator it =
									ds.getDiscreteElements().begin();
									it != ds.getDiscreteElements().end();
									++it)
								locationID = (*it); //Assuming only a single element exist in the discrete_set

							int transID =
									current_forbidden_state->getTransitionId();	//a)
							//   **********************************************************
							//todo::create an object of abstractCE[1)list_of_symbolic_states 2)list_of_transition and 3) length]
							//1) ******************** list_of_symbolic_states ********************
							list_sym_states.push_front(
									current_forbidden_state);//pushing the bad symbolic_state first(at the top)
							list_abstract_sym_states.push_front(
									curr_abs_sym_state);
							//2) list_of_transition
							//a) current sym_state only have trans_ID but to retrieve this transition I have to
							//b) get the parent to this sym_state using getParentPtrSymbolicState and then in
							//c) that sym_state get the discrete state and then get its loc_ID.
							//d) Now from the class hybrid_automata get an object of the class location
							//e) Now for this location's object get the transition with transID as transition_ID from
							// the data member out_going_transitions.
							//3) length: number of transitions
							//   **********************************************************

							if (cc != 0) {
								std::cout << " --> ";
							}
							std::cout << "(" << locationID << ", "
									<< transID << ")";
							current_forbidden_state =
									searchSymbolic_state(
											Reachability_Region,
											current_forbidden_state->getParentPtrSymbolicState()); //b)

							//2) ******************* list_transitions ********************
							ds2 = current_forbidden_state->getDiscreteSet();//c)
							for (std::set<int>::iterator it =
									ds2.getDiscreteElements().begin();
									it != ds2.getDiscreteElements().end();
									++it)
								locationID2 = (*it); //c)
							location object_location;
							object_location = H.getLocation(locationID2);//d)
							transition::ptr temp =
									object_location.getTransition(transID);	//e)
							list_transitions.push_front(temp);//pushing the transition in the stack
							//2) ******************* list_transitions Ends ********************
							cc++;
						} while (current_forbidden_state->getParentPtrSymbolicState()
								!= NULL);

						if ((cc >= 1)
								&& (current_forbidden_state->getParentPtrSymbolicState()
										== NULL)) { //root is missed
							int locationID, locationID2;
							discrete_set ds, ds2;
							ds = current_forbidden_state->getDiscreteSet();

							abs_flowpipe =
									convertBounding_Box(
											current_forbidden_state->getContinuousSetptr());
							polyI = current_forbidden_state->getInitial_ContinousSetptr();
							// Here create a new abstract_symbolic_state
							abstract_symbolic_state::ptr curr_abs_sym_state = abstract_symbolic_state::ptr(
																new abstract_symbolic_state(ds,abs_flowpipe,polyI));

							// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********

							for (std::set<int>::iterator it =
									ds.getDiscreteElements().begin();
									it != ds.getDiscreteElements().end();
									++it)
							locationID = (*it); //Assuming only a single element exist in the discrete_set
							int transID =
									current_forbidden_state->getTransitionId();
							list_sym_states.push_front(
									current_forbidden_state); //1) pushing the initial/root bad symbolic_state at the top
							list_abstract_sym_states.push_front(
									curr_abs_sym_state);

							std::cout << " -->  (" << locationID << ", "
									<< transID << ")\n";

						}

						saftey_violated = true;
						/*ce = abstractCE::ptr(new abstractCE());
						ce->set_length(cc);
						//ce->set_sym_states(list_sym_states);
						ce->set_sym_states(list_abstract_sym_states);

						ce->set_transitions(list_transitions);
						hybrid_automata::ptr h = hybrid_automata::ptr(new hybrid_automata(H));
						ce->set_automaton(h);
						ce->set_forbid_poly(forbid_poly); */
						break;
					}
				}
			} //computed flowpipe is not empty
			if (saftey_violated) {
				break; //no need to compute rest of the locations
			}
			//  ******************************** Safety Verification section ********************************
		} //end-for pushing all computed flowpipe
		if (number_times > bound) //check to see how many jumps have been made(i.e., number of discrete transitions made)
			break;
	} //end of while loop checking waiting_list != empty
	cout
			<< "\n ***************************************************************************\n";
	cout << "\nMaximum Iterations Completed = " << iter_max << "\n";
	cout
			<< "\n ***************************************************************************\n";

	return Reachability_Region;
}
