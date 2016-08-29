#include "reachability.h"
#include "InputOutput/cpu_utilities/cpu_utilities.h"
#include "Utilities/flow_cost_estimate.h"
#include <ctime>

using namespace std;
#define CORE 8

void reachability::setReachParameter(hybrid_automata& h, initial_state::ptr& i,
		ReachabilityParameters& reach_param, int bound_limit,
		unsigned int algorithm_type, unsigned int total_partition,
		int lp_solver_type, unsigned int streams_size,
		int solver_GLPK_Gurobi_for_GPU,
		std::pair<int, polytope::ptr> forbidden) {
	H = h;
	I = i;
	reach_parameters = reach_param;
	bound = bound_limit;
	Algorithm_Type = algorithm_type;
	Total_Partition = total_partition;
	lp_solver_type_choosen = lp_solver_type;
	number_of_streams = streams_size;
	Solver_GLPK_Gurobi_GPU = solver_GLPK_Gurobi_for_GPU; //todo:: used for comparing GLPK solver vs GPU. Can be removed
	forbidden_set = forbidden;
}

//bound is the maximum number of transitions or jumps permitted.
//reach_parameters includes the different parameters needed in the computation of reachability.
//I is the initial symbolic state
std::list<symbolic_states::ptr> reachability::computeSeqentialBFSReach(std::list<abstractCE::ptr>& ce_candidates) {
	//	std::cout<<"Algorithm_Type = "<<Algorithm_Type<<std::endl;
	//std::list<template_polyhedra> Reachability_Region;

	std::list < symbolic_states::ptr > Reachability_Region;
	template_polyhedra::ptr reach_region;

	int number_times = 0, BreadthLevel = 0, previous_level = -1;
	std::list<int> queue; // data structure to keep track of the number of transitions
	//discrete_set discrete_state;

	pwlist pw_list; //list of initial_state
	pw_list.WaitingList_insert(I);

	queue.push_back(BreadthLevel); //insert at REAR, first Location
	bool starting_location = true;
	bool saftey_violated = false;

	polytope::ptr continuous_initial_polytope;

	unsigned int num_flowpipe_computed=0;	//keeping track of number of flowpipe computed
	while (!pw_list.isEmpty_WaitingList()) {

		symbolic_states::ptr S = symbolic_states::ptr(new symbolic_states()); //required to be pushed into the Reachability_Region
		initial_state::ptr U;

		U = pw_list.WaitingList_delete_front();
		int levelDeleted = queue.front(); //get FRONT element
		queue.pop_front(); //delete from FRONT
		if (levelDeleted > bound)
			break; //stopping due to number of transitions exceeds the bound

		int location_id;
		//		cout<<"\nTesting 2 a 2\n";
		//discrete_state = U.getDiscreteSet();
		location_id = U->getLocationId();
		//std::cout<<"location_id from U = "<<location_id<<std::endl;
		discrete_set discrete_state;
		discrete_state.insert_element(location_id); //creating discrete_state

		//continuous_initial_polytope = U.getInitial_ContinousSetptr();
		continuous_initial_polytope = U->getInitialSet();
		reach_parameters.X0 = continuous_initial_polytope;

		S->setDiscreteSet(discrete_state);
		S->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
		S->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID


		pw_list.PassedList_insert(U);

		location::ptr current_location;

		current_location = H.getLocation(location_id);
		string name = current_location->getName();
		//cout << "\nLocation ID = "<<location_id<<", Location Name = " << name << "\n";
		if ((name.compare("GOOD") == 0) || (name.compare("BAD") == 0)
				|| (name.compare("UNSAFE") == 0)
				|| (name.compare("FINAL") == 0))
			continue; //do not compute the continuous reachability algorithm
		bool foundSkippingLocation = false;
		for (int StopLoc = 0; StopLoc < reach_parameters.Stop_locID.size();
				StopLoc++) {
			if (location_id == reach_parameters.Stop_locID[StopLoc]) {
				foundSkippingLocation = true;
			}
		}
		if (foundSkippingLocation) //do not compute the continuous reachability algorithm
			continue;

		// ******************* Computing Parameters *******************************
		//In this current_location the parameters will change for eg., alfa, beta and phi_trans  have to be re-computed
		/*
		 * Computing the parameters to avoid multiple computation in the child process
		 * Items Required :: time_step, phi_trans , B_trans, compute_alfa,compute_beta
		 * Computation of compute_alfa depends on initial set. For algorithm PAR_BY_PARTS where the
		 * initial set in divided into parts. Compute_alfa should be computed for each initial sets.
		 * */
		//	cout<<"\nTesting 2 c\n";
		double result_alfa = compute_alfa(reach_parameters.time_step,
				current_location->getSystem_Dynamics(),
				continuous_initial_polytope, lp_solver_type_choosen); //2 glpk object created here

		double result_beta = compute_beta(current_location->getSystem_Dynamics(),
				reach_parameters.time_step, lp_solver_type_choosen); // NO glpk object created here

		reach_parameters.result_alfa = result_alfa;
		reach_parameters.result_beta = result_beta;
		// Intialised the transformation and its transpose matrix
		math::matrix<double> phi_matrix, phi_trans;

		if (!current_location->getSystem_Dynamics().isEmptyMatrixA) { //if A not Empty
			current_location->getSystem_Dynamics().MatrixA.matrix_exponentiation(
					phi_matrix, reach_parameters.time_step);
			phi_matrix.transpose(phi_trans);
			reach_parameters.phi_trans = phi_trans;
		}
		math::matrix<double> B_trans;
		// transpose to be done once and stored in the structure of parameters
		if (!current_location->getSystem_Dynamics().isEmptyMatrixB) { //if B not Empty
			current_location->getSystem_Dynamics().MatrixB.transpose(B_trans);
			reach_parameters.B_trans = B_trans;
		}

		// ******************* Computing Parameters *******************************


		unsigned int NewTotalIteration = reach_parameters.Iterations;

		// ************ Compute flowpipe_cost:: estimation Starts **********************************

		if (current_location->isInvariantExists()){

			if (current_location->getSystem_Dynamics().isEmptyMatrixB==true && current_location->getSystem_Dynamics().isEmptyC==true){
				//Approach of Coarse-time-step and Fine-time-step
				jumpInvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope, reach_parameters,
					current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
				cout<<"Running Approach of Coarse-time-step and Fine-time-step\n";
			}else{
				//Approach of Sequential invariant check will work for all case
				InvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope,
					reach_parameters, current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
			}

		}
		// ************ Compute flowpipe_cost:: estimation Ends **********************************


		sequentialReachSelection(NewTotalIteration, current_location, continuous_initial_polytope, reach_region);
		num_flowpipe_computed++;//computed one Flowpipe

		//	*********************************************** Reach or Flowpipe Computed ************************************
		if (previous_level != levelDeleted) {
			previous_level = levelDeleted;
			BreadthLevel++;
		}
		if (reach_region->getTotalIterations() != 0) {
			S->setContinuousSetptr(reach_region);
			Reachability_Region.push_back(S);
		}
		//  ******************************** Safety Verification section ********************************
		std::list < symbolic_states::ptr > list_sym_states;
		std::list < abstract_symbolic_state::ptr > list_abstract_sym_states;
		polytope::ptr abs_flowpipe; //bounding_box Polytope
		polytope::ptr polyI; //initial polytope of the abstract flowpipe
		std::list < transition::ptr > list_transitions;
		if (reach_region->getTotalIterations() != 0 && forbidden_set.second != NULL) { //flowpipe exists
				//so perform intersection with forbidden set provided locID matches
			int locID = current_location->getLocId();
			cout<<"Running Safety Check for Loc = "<<locID<<std::endl;

			if (locID == forbidden_set.first) { //forbidden locID matches
				polytope::ptr forbid_poly = forbidden_set.second;
				std::list < template_polyhedra::ptr > forbid_intersects;
				forbid_intersects = reach_region->polys_intersectionSequential(forbid_poly, lp_solver_type_choosen);
				if (forbid_intersects.size() == 0) {
					std::cout << "\nThe model does NOT violates SAFETY property!!!\n";
				} else {
					std::cout << "\nThe model violates SAFETY property!!!\n";
					symbolic_states::ptr current_forbidden_state;
					current_forbidden_state = S;
					std::cout << "\nReverse Path Trace =>\n";
					int cc = 0;
					do {
						int locationID, locationID2;
						discrete_set ds, ds2;
						ds = current_forbidden_state->getDiscreteSet();
						//insert discrete_set in the abstract_symbolic_state
						// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********
						abs_flowpipe = convertBounding_Box(
								current_forbidden_state->getContinuousSetptr());
						// The below gets the first polytope from the SFM. Could be made even better
						// by taking the exact initial set X0.

						polyI = current_forbidden_state->getInitial_ContinousSetptr();

						// Here create a new abstract_symbolic_state
						abstract_symbolic_state::ptr curr_abs_sym_state;
						curr_abs_sym_state = abstract_symbolic_state::ptr(
								new abstract_symbolic_state(ds, abs_flowpipe,
										polyI));

						// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********
						for (std::set<int>::iterator it =
								ds.getDiscreteElements().begin();
								it != ds.getDiscreteElements().end(); ++it)
							locationID = (*it); //Assuming only a single element exist in the discrete_set
						int transID =
								current_forbidden_state->getTransitionId(); //a)
						//   **********************************************************
						//create an object of abstractCE[1)list_of_symbolic_states 2)list_of_transition and 3) length]
						//1) ******************** list_of_symbolic_states ********************
						list_sym_states.push_front(current_forbidden_state); //pushing the bad symbolic_state first(at the top)
						list_abstract_sym_states.push_front(curr_abs_sym_state);
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
						std::cout << "(" << locationID << ", " << transID << ")";
						if (current_forbidden_state->getParentPtrSymbolicState() != NULL) { //searching only if not NULL
							//cout<<"check if parentPtr not NULL\n";
							current_forbidden_state = searchSymbolic_state(Reachability_Region,
											current_forbidden_state->getParentPtrSymbolicState()); //b)
							//2) ******************* list_transitions ********************
							ds2 = current_forbidden_state->getDiscreteSet(); //c)
							for (std::set<int>::iterator it =
									ds2.getDiscreteElements().begin();
									it != ds2.getDiscreteElements().end(); ++it)
								locationID2 = (*it); //c)

							location::ptr object_location;
							object_location = H.getLocation(locationID2); //d)

							transition::ptr temp =
									object_location->getTransition(transID); //e)
							list_transitions.push_front(temp); //pushing the transition in the stack
							//2) ******************* list_transitions Ends ********************
						}
						cc++;
					} while (current_forbidden_state->getParentPtrSymbolicState()!= NULL);

					if ((cc >= 1) && (current_forbidden_state->getParentPtrSymbolicState()== NULL)) { //root is missed
						int locationID;
						discrete_set ds;
						ds = current_forbidden_state->getDiscreteSet();
						abs_flowpipe = convertBounding_Box(
								current_forbidden_state->getContinuousSetptr());
						// The below gets the first polytope from the SFM. Could be made even better
						// by taking the exact initial set X0.

						polyI = current_forbidden_state->getInitial_ContinousSetptr();

						// Create a new abstract_symbolic_state
						abstract_symbolic_state::ptr curr_abs_sym_state;

						curr_abs_sym_state = abstract_symbolic_state::ptr(new abstract_symbolic_state(ds, abs_flowpipe, polyI));

						for (std::set<int>::iterator it =
								ds.getDiscreteElements().begin();
								it != ds.getDiscreteElements().end(); ++it)
							locationID = (*it); //Assuming only a single element exist in the discrete_set

						int transID =
								current_forbidden_state->getTransitionId();
						list_sym_states.push_front(current_forbidden_state); //1) pushing the initial/root bad symbolic_state at the top
						list_abstract_sym_states.push_front(curr_abs_sym_state);
						std::cout << " -->  (" << locationID << ", " << transID << ")\n";
					}
					saftey_violated = true;
					abstractCE::ptr ce = abstractCE::ptr(new abstractCE());
					ce->set_length(cc);
					ce->set_sym_states(list_abstract_sym_states);
					ce->set_transitions(list_transitions);
					hybrid_automata::ptr ha = hybrid_automata::ptr(
							new hybrid_automata(H));
					ce->set_automaton(ha);
					ce->set_forbid_poly(forbidden_set.second);
					ce_candidates.push_back(ce); // ce added to the abstract ce candidates list.
				} // end of condition when forbidden state intersects with the flowpipe set
			} //end of condition when forbidden state loc id matches with flowpipe loc id
		} //computed flowpipe is not empty

//		if (saftey_violated) {
//			break; //no need to compute rest of the locations
//		}
		//  ******************************** Safety Verification section Ends********************************

		//  ******* ---POST_D Begins--- ******* Check to see if Computed FlowPipe is Empty  **********
		if (reach_region->getTotalIterations() != 0 && BreadthLevel <= bound) {
			//computed reach_region is empty and optimize transition BreadthLevel-wise
			for (std::list<transition::ptr>::iterator t = current_location->getOut_Going_Transitions().begin();
					t != current_location->getOut_Going_Transitions().end(); t++) {
				// get each destination_location_id and push into the pwl.waiting_list
				int transition_id = (*t)->getTransitionId();
				location::ptr current_destination;
				Assign current_assignment;
				polytope::ptr gaurd_polytope;

				polytope::ptr intersectedRegion; //created two objects here
				discrete_set ds;

				current_destination = H.getLocation((*t)->getDestination_Location_Id());

				string locName = current_destination->getName();

				gaurd_polytope = (*t)->getGaurd(); //	GeneratePolytopePlotter(gaurd_polytope);

				std::list<polytope::ptr> polys;
				polys = reach_region->flowpipe_intersectionSequential(gaurd_polytope, lp_solver_type_choosen);

				//Todo to make is even procedure with Sequential procedure.... so intersection is done first and then decide to skip this loc
				if ((locName.compare("BAD") == 0) || (locName.compare("GOOD") == 0)
						|| (locName.compare("FINAL") == 0) || (locName.compare("UNSAFE") == 0))
					continue; //do not push into the waitingList

				current_assignment = (*t)->getAssignT();
				// *** interesected_polyhedra included with invariant_directions also ******
				int destination_locID = (*t)->getDestination_Location_Id();
				ds.insert_element(destination_locID);
				for (std::list<polytope::ptr>::iterator i = polys.begin(); i != polys.end(); i++) {

					//intersectedRegion = (*i)->getTemplate_approx(lp_solver_type_choosen);
					intersectedRegion = (*i);

					//Returns a single over-approximated polytope from the list of intersected polytopes
					//	GeneratePolytopePlotter(intersectedRegion);
					polytope::ptr newShiftedPolytope, newPolytope; //created an object here
					newPolytope = intersectedRegion->GetPolytope_Intersection(gaurd_polytope);
					//Returns the intersected region as a single newpolytope.
					newShiftedPolytope = post_assign_exact(newPolytope, current_assignment.Map, current_assignment.b);


					initial_state::ptr newState = initial_state::ptr(new initial_state(destination_locID, newShiftedPolytope));
					newState->setTransitionId(transition_id); // keeps track of the transition_ID
					newState->setParentPtrSymbolicState(S);
					pw_list.WaitingList_insert(newState);
					queue.push_back(BreadthLevel); //insert at REAR first Location
				}
			} //end of multiple transaction
		}
	} //end of while loop checking waiting_list != empty

	cout << "\n ***************************************************************************\n";
	cout << "\nMaximum Iterations Completed = " << num_flowpipe_computed << "\n";
	cout << "\n ***************************************************************************\n";

	return Reachability_Region;
}

void reachability::sequentialReachSelection(unsigned int NewTotalIteration, location::ptr current_location,
		polytope::ptr continuous_initial_polytope,
		template_polyhedra::ptr& reach_region) {

	if (Algorithm_Type == SEQ) { //Continuous Sequential Algorithm
		//cout << "\nRunning Sequntial\n";
		//		std::cout<<"\nBefore entering reachability Sequential = " << gurobi_lp_solver::gurobi_lp_count;
		//		std::cout<<"\nBefore entering reachability Sequential = " << lp_solver::lp_solver_count;
//			int a;			std::cin>>a;
		/*boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();*/
		reach_region = reachabilitySequential(NewTotalIteration, current_location->getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters, current_location->getInvariant(),
				current_location->isInvariantExists(), lp_solver_type_choosen);
		/*AllReach_time.stop();
		double wall_clock1;
		wall_clock1 = AllReach_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nFlowpipe:Time:Wall(Seconds) = " << return_Time1 << std::endl;*/
	}

	if (Algorithm_Type == PAR_OMP) {
		//Parallel implementation using OMP parallel			//	double wall_timer = omp_get_wtime();
		//	cout << "\nRunning Parallel Using OMP Thread\n";
		boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();
		reach_region = reachabilityParallel(NewTotalIteration,
				current_location->getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(),
				current_location->isInvariantExists(), lp_solver_type_choosen);
		AllReach_time.stop();
		double wall_clock1;
		wall_clock1 = AllReach_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nFlowpipe:Time:Wall(Seconds) = " << return_Time1
				<< std::endl;
		//	std::cout << "Parallel Done\n";
		//	std::cout << "Time seen from mop wall timer: "<< omp_get_wtime() - wall_timer << std::endl;
	}

/*	if (Algorithm_Type == GPU_SF) { //computing all support function in GPU
		cout << "\nRunning GPU Sequential\n";
		boost::timer::cpu_timer AllReachGPU_time;
		AllReachGPU_time.start();
		reachabilitySequential_GPU(NewTotalIteration, current_location->getSystem_Dynamics(), continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(), current_location->isInvariantExists(),
				lp_solver_type_choosen, number_of_streams, Solver_GLPK_Gurobi_GPU, reach_region);
		std::cout << "Out from GPU_reach\n";
		AllReachGPU_time.stop();
		double wall_clock1;
		wall_clock1 = AllReachGPU_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nAllReach_time: Boost Time:Wall(Seconds) = " << return_Time1 << std::endl;

	}*/

	if (Algorithm_Type == PAR_ITER) { //Continuous Parallel Algorithm parallelizing the Iterations :: to be debugged (compute initial polytope(s))
		cout << "\nRunning Parallel-over-Iterations(PARTITIONS/Time-Sliced) Using OMP Thread\n";
		bool invertible;
		if (!current_location->getSystem_Dynamics().isEmptyMatrixA) {
			math::matrix<double> A_inv(current_location->getSystem_Dynamics().MatrixA.size1(),
					current_location->getSystem_Dynamics().MatrixA.size2());
			invertible = current_location->getSystem_Dynamics().MatrixA.inverse(A_inv); //size of A_inv must be declared else error
			if (!invertible)
				std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
			else
				reach_parameters.A_inv = A_inv;
			int NCores = Total_Partition; //Number of Partitions (number of threads)
			reach_region = reachParallelExplore(NewTotalIteration, current_location->getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters, current_location->getInvariant(),
					current_location->isInvariantExists(), NCores, PAR_ITER, lp_solver_type_choosen);
			std::cout << "Finished computing reachable states\n";
		} else {
			std::cout << "\nFlow Dynamics Matrix A does not exists!!!\n";
			template_polyhedra::ptr poly_emptyp;
			reach_region = poly_emptyp; //returning an empty reach_region for this location

		}
	}

	if (Algorithm_Type == PAR_ITER_DIR) {
		//using OMP:: Parallel implementation with a combination of Iterations and Directions
		//	cout << "\nRunning Parallel Using combination of Iterations and Directions\n";
		bool invertible;
		if (!current_location->getSystem_Dynamics().isEmptyMatrixA) {
			math::matrix<double> A_inv(
					current_location->getSystem_Dynamics().MatrixA.size1(),
					current_location->getSystem_Dynamics().MatrixA.size2());
			invertible = current_location->getSystem_Dynamics().MatrixA.inverse(
					A_inv); //size of A_inv must be declared else error
			if (!invertible)
				std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
			else
				reach_parameters.A_inv = A_inv;

			int NCores = Total_Partition; //Number of Partitions (number of threads)
			reach_region = reachParallelExplore(NewTotalIteration,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location->getInvariant(),
					current_location->isInvariantExists(), NCores, PAR_ITER_DIR,
					lp_solver_type_choosen);
		} else {
			std::cout << "\nFlow Dynamics Matrix A does not exists!!!\n";
			template_polyhedra::ptr poly_emptyp;
			reach_region = poly_emptyp; //returning an empty reach_region for this location
		}
	}
}

//bound is the maximum number of transitions or jumps permitted.
//reach_parameters includes the different parameters needed in the computation of reachability.
//I is the initial symbolic state

std::list<symbolic_states::ptr> reachability::computeParallelBFSReach(
		std::list<abstractCE::ptr>& ce_candidates) {

	std::list < symbolic_states::ptr > Reachability_Region;
	//	template_polyhedra::ptr reach_region;

	pwlist pw_list;
	pw_list.WaitingList_insert(I);
	int number_times = 0;
	unsigned int iter_max = 1;

	bool stop_loop = false;

	bool saftey_violated = false;

	while (!pw_list.isEmpty_WaitingList()) {

		//To avoid write-contention for reach_region, Vector/List of reach_region_list created for each threads
		// write in its respective index. So need a unique ID for each thread which can be obtained from
		// the size of the PWList at each iteration

		unsigned int count = pw_list.getWaitingListSize(); //get the size of PWList
		std::vector < symbolic_states::ptr > S(count);

		//Create a sublist of initial_state and work with it inside the parallel region(each thread accesses uniquely)

		vector < initial_state::ptr > list_U(count); //SubList for parallel

		for (int i = 0; i < count; i++) {
			list_U[i] = pw_list.WaitingList_delete_front();
			pw_list.PassedList_insert(list_U[i]);
		}
		//All initial_state have been deleted
		// ********************************* BFS Starts **********************************************************

		omp_set_nested(1); //enable nested parallelism
#pragma omp parallel for // num_threads(2)
		for (unsigned int id = 0; id < count; id++) {
			initial_state::ptr U; //local
			U = list_U[id]; //independent symbolic state to work with
			discrete_set discrete_state; //local
			polytope::ptr continuous_initial_polytope; //local
			ReachabilityParameters reach_parameter_local; //local

			int location_id = U->getLocationId();
			discrete_state.insert_element(location_id);
			continuous_initial_polytope = U->getInitialSet();
			reach_parameter_local = reach_parameters;
			reach_parameter_local.X0 = continuous_initial_polytope; //	cout<<"\nInside for Loop";
			//create an instance of Symbolic_states S
			S[id] = symbolic_states::ptr(new symbolic_states());

			S[id]->setDiscreteSet(discrete_state);
			S[id]->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
			S[id]->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID


			location::ptr current_location;
			current_location = H.getLocation(location_id);
			string name = current_location->getName();
			if ((name.compare("GOOD") == 0) || (name.compare("BAD") == 0)
					|| (name.compare("UNSAFE") == 0)
					|| (name.compare("FINAL") == 0))
				continue; //do not compute the continuous reachability algorithm

			// ******************* Computing Parameters *******************************
			double result_alfa = compute_alfa(reach_parameter_local.time_step,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, lp_solver_type_choosen); //2 glpk object created here

			double result_beta = compute_beta(
					current_location->getSystem_Dynamics(),
					reach_parameter_local.time_step, lp_solver_type_choosen); // NO glpk object created here

			reach_parameter_local.result_alfa = result_alfa;
			reach_parameter_local.result_beta = result_beta;

			math::matrix<double> phi_matrix, phi_trans;
			if (!current_location->getSystem_Dynamics().isEmptyMatrixA) { //if A not Empty
				current_location->getSystem_Dynamics().MatrixA.matrix_exponentiation(
						phi_matrix, reach_parameter_local.time_step);
				phi_matrix.transpose(phi_trans);
				reach_parameter_local.phi_trans = phi_trans;
			}
			math::matrix<double> B_trans;
			if (!current_location->getSystem_Dynamics().isEmptyMatrixB) { //if B not Empty
				current_location->getSystem_Dynamics().MatrixB.transpose(
						B_trans);
				reach_parameter_local.B_trans = B_trans;
			}
			// ******************* Computing Parameters Done *******************************
			unsigned int NewTotalIteration;
			if (current_location->isInvariantExists()) {
				InvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope,
						reach_parameter_local, current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
				std::cout << "NewTotalIteration = " << NewTotalIteration << std::endl;
			}
			//  ********************* FlowPipe or Reach Computation *************************
			parallelReachSelection(NewTotalIteration, current_location, continuous_initial_polytope, reach_parameter_local, S, id);
			// Returns the Flow_Pipe in reach_region_list[id]
			//  ********************* FlowPipe or Reach Computation Done ********************

			//  ************** Check to see if Computed FlowPipe is Empty  **********
			template_polyhedra::ptr t_poly = S[id]->getContinuousSetptr();

			if (t_poly->getTotalIterations() != 0 && number_times < bound) { //computed reach_region is empty && optimize computation

				for (std::list<transition::ptr>::iterator t =
						current_location->getOut_Going_Transitions().begin();
						t != current_location->getOut_Going_Transitions().end();
						t++) { // get each destination_location_id and push into the pwl.waiting_list
					int transition_id = (*t)->getTransitionId();
					if (transition_id == -1) { //Indicates empty transition or no transition exists
						break; //out from transition for-loop as there is no transition for this location
					}
					location::ptr current_destination;
					Assign current_assignment;
					polytope::ptr gaurd_polytope;
					std::list < template_polyhedra::ptr > intersected_polyhedra;
					polytope::ptr intersectedRegion; //created two objects here
					discrete_set ds;
					current_destination = H.getLocation(
							(*t)->getDestination_Location_Id());
					string locName = current_destination->getName();

					gaurd_polytope = (*t)->getGaurd();
					current_assignment = (*t)->getAssignT();

					boost::timer::cpu_timer t100;
					//this intersected_polyhedra will have invariant direction added in it
					string trans_name = (*t)->getLabel();
					//	intersected_polyhedra = t_poly->polys_intersectionParallel(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
					t100.start();
					intersected_polyhedra =
							t_poly->polys_intersectionSequential(gaurd_polytope,
									lp_solver_type_choosen); //, intersection_start_point);
					t100.stop();
					if (intersected_polyhedra.size() > 0) { //there is intersection so new symbolic state will be inserted into the waitingList
						//std::cout << "Intersected = " < intersected_polyhedra.size() << std::endl;
#pragma omp critical
						{
							iter_max++; //
						}
					}
					//todo Handle this later as In SpaceEx model we did not specified BAD or GOOD
					if ((locName.compare("BAD") == 0)
							|| (locName.compare("GOOD") == 0)
							|| (locName.compare("FINAL") == 0)
							|| (locName.compare("UNSAFE") == 0)) {
						continue; //do not push into the waitingList
					}
					//			std::cout << "Before calling getTemplate_approx\n";
					double clock100;
					clock100 = t100.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
					double return100 = clock100 / (double) 1000;
					std::cout << "\nIntersection Time:Wall(Seconds) = "
							<< return100 << std::endl;

					int destination_locID = (*t)->getDestination_Location_Id();
					ds.insert_element(destination_locID);
					for (std::list<template_polyhedra::ptr>::iterator i =
							intersected_polyhedra.begin();
							i != intersected_polyhedra.end(); i++) {

						intersectedRegion = (*i)->getTemplate_approx(
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
					}
				} //end of multiple transaction
				  //Here we have again populated the pwlist for next-round's parallel process
			} // End-if  ******* Check for Empty FlowPipe Done *********
		} //END of parallel FOR-LOOP

		//:: Can be optimized if we can count number_times inside the parallel loop per breadth then we can avoid transaction and intersection
		//:: computation for next transition if number_times exceeds bound ....
		number_times++; //One Level or one Breadth Search over

		// ************************* BFS Ends *************************************

		//Creating a list of objects of "Reachability Set"/Symbolic_states
		bool foundUnSafe = false;
		for (unsigned int index = 0; index < count; index++) {

			if (S[index]->getContinuousSetptr()->getTotalIterations() != 0) //computed reach_region is NOT empty
				Reachability_Region.push_back(S[index]);
			//  ******************************** Safety Verification section ********************************
			saftey_violated = safetyVerify(S[index], Reachability_Region, ce_candidates);
			if (saftey_violated) {
				foundUnSafe = true; //have to insert all flowpipe of same breadth even if foundUnSafe=true for some flowpipe, So not breaking
			}
			//  ******************************** Safety Verification section ********************************
		} //end-for pushing all computed flowpipe
//		if (foundUnSafe) {
//			break; //no need to compute rest of the locations
//		}
		if (number_times > bound) //check to see how many jumps have been made(i.e., number of discrete transitions made)
			break;
	} //end of while loop checking waiting_list != empty
	cout << "\n ***************************************************************************\n";
	cout << "\nMaximum Iterations Completed = " << iter_max << "\n";
	cout << "\n ***************************************************************************\n";

	return Reachability_Region;

}

//Lock Avoidance:: Parallel Breadth First Search for Discrete Jumps
//separate Read and Write Queue (pwlist.WaitingList)
std::list<symbolic_states::ptr> reachability::computeParallelBFSReachLockAvoid(std::list<abstractCE::ptr>& ce_candidates) {

	std::list < symbolic_states::ptr > Reachability_Region;
	//	template_polyhedra::ptr reach_region;

	//Shared Read and Write Queue(pwList)
	int t = 0; //0 for Read and 1 for Write
	std::vector < std::vector<pwlist::ptr> > Qpw_list(2); // QpwList[0] for read and QpwList[1] for write
	//pwlist pw_list;	//Shared Queue(pwList)
	//cout << "Test 1\n";
	Qpw_list[t].resize(1); //resize for the first symbolic_state
	//cout << "Test 2\n";
	Qpw_list[t][0] = pwlist::ptr(new pwlist()); //have to instantiate it
	Qpw_list[t][0]->WaitingList_insert(I);
	//cout << "Test 3\n";
//Since Qpw_list is a temporary working list is it switches between Read and Write so we can not maintain the passedList in it.
	pwlist::ptr allPassedList; //so we create a permanent pwlist for storing only the passedList;
	allPassedList = pwlist::ptr(new pwlist()); //have to instantiate it
	int number_times = 0;
	unsigned int iter_max = 1;

	bool stop_loop = false;

	bool saftey_violated = false;
	//cout << "Test 4\n";
	while (!isEmpty_Qpw_list(Qpw_list[t]) && (number_times <= bound)) {
cout<<"Breadth - Level === "<<number_times<<"\n";
		//To avoid write-contention for reach_region, Vector/List of reach_region_list created for each threads
		// write in its respective index. So need a unique ID for each thread which can be obtained from
		// the size of the PWList at each iteration
		//	cout << "Test 5\n";
		unsigned int count = getSize_Qpw_list(Qpw_list[t]); //get the size of PWList
		//iter_max = iter_max + count;
		//	cout << "\nCount = " << count << "\n";
		//vector<template_polyhedra::ptr> reach_region_list(count); //each thread write's flowpipe on separate index
		std::vector < symbolic_states::ptr > S(count);

		std::vector <location::ptr> list_currLocation(count);	//Data structure required to separate PostD from PostC
		std::vector <int> list_invBounaryValue(count);	//Data structure required to separate invCheck from PostC
		std::vector <LoadBalanceData> SymDataStruct(count);


		//Create a sublist of initial_state and work with it inside the parallel region(each thread accesses uniquely)
		//vector<symbolic_states> list_U(count); //SubList for parallel
		vector < initial_state::ptr > list_U(count); //SubList for parallel
		//	cout << "Test 6\n";
		list_U = getAllpw_list(Qpw_list, t, count, allPassedList); //All initial_state have been deleted
		//for (int i=0;i<Qpw_list[t].size();i++)
			Qpw_list[t].resize(0);
		cout<<"Qpw_list[t].size() = "<<Qpw_list[t].size()<<std::endl;

		Qpw_list[1 - t].resize(count); //resize to accommodate
		for (int i = 0; i < count; i++) {
			Qpw_list[1 - t][i] = pwlist::ptr(new pwlist()); //have to instantiate it
		}
		// ********************************* BFS Starts **********************************************************
		//	cout << "Test 7\n";
		omp_set_dynamic(0);	//handles dynamic adjustment of the number of threads within a team
		omp_set_nested(1); //enable nested parallelism
		//omp_set_num_threads(10);
		//omp_set_max_active_levels(2);

		boost::timer::cpu_timer t705;
		t705.start();
#pragma omp parallel for  num_threads(count)
		for (unsigned int id = 0; id < count; id++) {
			boost::timer::cpu_timer t702;
			t702.start();
			if (id==0){
			 std::cout<<"\nMax Thread in Outer Level = "<< omp_get_num_threads();
			 //std::cout<<"\nMax Active Levels = "<<omp_get_max_active_levels();
			 }
			 //std::cout<<"\n Outer threadID = "<<omp_get_thread_num()<<"\n";
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
			reach_parameter_local.X0 = continuous_initial_polytope; //	cout<<"\nInside for Loop";
			//create an instance of Symbolic_states S
			S[id] = symbolic_states::ptr(new symbolic_states());

			S[id]->setDiscreteSet(discrete_state);
			S[id]->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
			S[id]->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID

			/*
			 for (std::set<int>::iterator it =
			 discrete_state.getDiscreteElements().begin();
			 it != discrete_state.getDiscreteElements().end(); ++it)
			 location_id = (*it); //have to modify later for multiple elements of the set:: Now assumed only one element
			 */
			location::ptr current_location;
			current_location = H.getLocation(location_id);
			string name = current_location->getName();
			if ((name.compare("GOOD") == 0) || (name.compare("BAD") == 0)
					|| (name.compare("UNSAFE") == 0) || (name.compare("FINAL") == 0))
				continue; //do not compute the continuous reachability algorithm

			// ******************* Computing Parameters *******************************
			//current_location:: parameters alfa, beta and phi_trans have to be re-computed
			//cout<<"\nBefore Compute Alfa";
			double result_alfa = compute_alfa(reach_parameter_local.time_step,
					current_location->getSystem_Dynamics(), continuous_initial_polytope, lp_solver_type_choosen); //2 glpk object created here
			//cout<<"\nCompute Alfa Done";
			double result_beta = compute_beta(current_location->getSystem_Dynamics(), reach_parameter_local.time_step, lp_solver_type_choosen); // NO glpk object created here
			//			cout<<"\nCompute Beta Done";
			reach_parameter_local.result_alfa = result_alfa;
			reach_parameter_local.result_beta = result_beta;

			math::matrix<double> phi_matrix, phi_trans;
			if (!current_location->getSystem_Dynamics().isEmptyMatrixA) { //if A not Empty
				current_location->getSystem_Dynamics().MatrixA.matrix_exponentiation(phi_matrix, reach_parameter_local.time_step);
				phi_matrix.transpose(phi_trans);
				reach_parameter_local.phi_trans = phi_trans;
			}
			math::matrix<double> B_trans;
			if (!current_location->getSystem_Dynamics().isEmptyMatrixB) { //if B not Empty
				current_location->getSystem_Dynamics().MatrixB.transpose(B_trans);
				reach_parameter_local.B_trans = B_trans;
			}

			t702.stop();
			double clock702;
			clock702 = t702.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
			double return702 = clock702 / (double) 1000;
			std::cout << "\nReachParameters computation Time:Wall(Seconds) = "<< return702 << std::endl;

			SymDataStruct[id].X0 = continuous_initial_polytope;
			SymDataStruct[id].current_location = current_location;
			SymDataStruct[id].reach_param = reach_parameter_local;
			// ******************* Computing Parameters Done *******************************
			boost::timer::cpu_timer boundCheck;
			boundCheck.start();
			unsigned int NewTotalIteration;
			if (current_location->isInvariantExists()){
				InvariantBoundaryCheck(SymDataStruct[id].current_location->getSystem_Dynamics(), continuous_initial_polytope,
						SymDataStruct[id].reach_param, SymDataStruct[id].current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
				std::cout << "NewTotalIteration = " << NewTotalIteration << std::endl;
				//list_invBounaryValue[id] = NewTotalIteration;
			}
			boundCheck.stop();
			double wall_clockboundcheck;
			wall_clockboundcheck = boundCheck.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
			double return_TimeBC = wall_clockboundcheck / (double) 1000;
			std::cout<< "\nBoundary Check for Iterations Number Time taken:Wall  (in Seconds) = " << return_TimeBC << std::endl;

			SymDataStruct[id].newIteration = NewTotalIteration;
		}


		boost::timer::cpu_timer t3;
		double cpu_usage;
		init_cpu_usage();
		t3.start();
#pragma omp parallel for  num_threads(count)
		for (unsigned int id = 0; id < count; id++) {
		/*if (shm_NewTotalIteration <= 1) {
				template_polyhedra::ptr poly_emptyp;
				return poly_emptyp;
			}*/
			//  ********************* FlowPipe or Reach Computation *************************

			parallelReachSelection(SymDataStruct[id].newIteration, SymDataStruct[id].current_location,
					SymDataStruct[id].X0, SymDataStruct[id].reach_param, S, id);

			//parallelReachSelection(NewTotalIteration, current_location, continuous_initial_polytope, reach_parameter_local, S, id);
			// Returns the Flow_Pipe in reach_region_list[id]
		//	list_currLocation[id] = current_location;

			/*double res= return702 + return3;
			std::cout << "****************************************************************************\n";
			std::cout << "\nEach Computation (ReachParameter + Flow-pipe) Time:Wall(Seconds) = " << res << std::endl;
			std::cout << "****************************************************************************\n";*/
		}
		t3.stop();
		cpu_usage = getCurrent_ProcessCPU_usage();
		std::cout << "\nCPU Usage:(%) = " << cpu_usage<< std::endl;
		double clock3;
		clock3 = t3.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return3 = clock3 / (double) 1000;
		std::cout << "\nFlow-pipe Computed Time:Wall(Seconds) = " << return3 << std::endl;

		//  ********************* POST_C computation Done ********************
		t705.stop();
		double clock705;
		clock705 = t705.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return705 = clock705 / (double) 1000;
		std::cout << "\nFlow-pipe Computation Done Time:Wall(Seconds) = " << return705 << std::endl;
		std::cout << "****************************************************************************\n";


		/*number_times++; //One Level or one Breadth Search over
		if (number_times > bound) {
			break; //check to see how many jumps have been made(i.e., number of discrete transitions made)
		}*/
//  ************************************** POST_D computation Begins **********************************************************

		omp_set_dynamic(0);	//handles dynamic adjustment of the number of threads within a team
		omp_set_nested(1); //enable nested parallelism
		boost::timer::cpu_timer t72;
		t72.start();
#pragma omp parallel for // num_threads(2)
		for (unsigned int id = 0; id < count; id++) {

			location::ptr current_location;
			//current_location = list_currLocation[id];
			current_location = SymDataStruct[id].current_location;

			/*Removed from here as kept in the WHILE-loop condition
			 * if (number_times > bound) //check to see how many jumps have been made(i.e., number of discrete transitions made)
				break;	//try to remove from here as this may not work in #pragma omp parallel for
			*/

			//  ************** Check to see if Computed FlowPipe is Empty  **********
			template_polyhedra::ptr t_poly = S[id]->getContinuousSetptr();

			if (t_poly->getTotalIterations() != 0 && number_times < bound) { //computed reach_region is empty && optimize computation
			//cout << "\nLoc ID = " << current_location.getLocId() << " Location Name = " << name << "\n";
				for (std::list<transition::ptr>::iterator trans = current_location->getOut_Going_Transitions().begin();
						trans != current_location->getOut_Going_Transitions().end(); trans++) { // get each destination_location_id and push into the pwl.waiting_list
					int transition_id = (*trans)->getTransitionId();
					if (transition_id == -1) { //Indicates empty transition or no transition exists
						break; //out from transition for-loop as there is no transition for this location
					}
					location::ptr current_destination;
					Assign current_assignment;
					polytope::ptr gaurd_polytope;
					std::list < template_polyhedra::ptr > intersected_polyhedra;
					polytope::ptr intersectedRegion; //created two objects here
					discrete_set ds;
					current_destination = H.getLocation((*trans)->getDestination_Location_Id());
					string locName = current_destination->getName();
					//	cout << "\nNext Loc ID = " << current_destination.getLocId() << " Location Name = " << locName << "\n";

					gaurd_polytope = (*trans)->getGaurd();
					current_assignment = (*trans)->getAssignT();

					boost::timer::cpu_timer t100;
					//this intersected_polyhedra will have invariant direction added in it
					string trans_name = (*trans)->getLabel();
					t100.start();
					intersected_polyhedra = t_poly->polys_intersectionParallel(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
					//intersected_polyhedra = t_poly->polys_intersectionSequential(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
					t100.stop();
					if (intersected_polyhedra.size() > 0) { //there is intersection so new symbolic state will be inserted into the waitingList
						//std::cout << "Intersected = " < intersected_polyhedra.size() << std::endl;
#pragma omp critical
						{
							iter_max++; //
						}
					}
					// Handle this later as In SpaceEx model we did not specified BAD or GOOD
					if ((locName.compare("BAD") == 0) || (locName.compare("GOOD") == 0)
							|| (locName.compare("FINAL") == 0) || (locName.compare("UNSAFE") == 0)) {
						continue; //do not push into the waitingList
					}
					//			std::cout << "Before calling getTemplate_approx\n";
					double clock100;
					clock100 = t100.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
					double return100 = clock100 / (double) 1000;
					std::cout << "\nIntersection Time:Wall(Seconds) = " << return100 << std::endl;
					int destination_locID = (*trans)->getDestination_Location_Id();
					ds.insert_element(destination_locID);
					for (std::list<template_polyhedra::ptr>::iterator it = intersected_polyhedra.begin(); it != intersected_polyhedra.end(); it++) {
						//cout << "\nNumber of Intersections #1\n";
						intersectedRegion = (*it)->getTemplate_approx(lp_solver_type_choosen);
						//Returns a single over-approximated polytope from the list of intersected polytopes
						polytope::ptr newShiftedPolytope, newPolytope; //created an object here
						newPolytope = intersectedRegion->GetPolytope_Intersection(
										gaurd_polytope); //Retuns only the intersected region as a single newpolytope. ****** with added directions
						//std::cout << "Before calling post_assign_exact\n";
						newShiftedPolytope = post_assign_exact(newPolytope, current_assignment.Map, current_assignment.b); //initial_polytope_I = post_assign_exact(newPolytope, R, w);
						initial_state::ptr newState = initial_state::ptr(new initial_state(destination_locID,newShiftedPolytope));
						newState->setTransitionId(transition_id); // keeps track of the transition_ID
						newState->setParentPtrSymbolicState(S[id]);
//#pragma omp critical
//					{
						/*
						 * Todo:: we insert all the symbolic_states into the pwlist for computing FlowPipe iff 1) and 2) holds
						 * Step 1) the new current_destination.getLocID() is NOT in the Passed List and
						 * Step 2) the "New Initial Polytope" or "the newShiftedPolytope" is NOT contained in the FlowPipe of LocationID of step 1
						 *  as the FlowPipe in the same location will be same if the newShiftedPolytope is IN FlowPipe
						 *  But if Step 1 holds and Step 2 does not then it will be inserted in pwlist even if the LocationID is in Passed List
						 */
						Qpw_list[1 - t][id]->WaitingList_insert(newState); //RACE CONDITION HERE

	//				}
					} //end of multiple intersected region with guard
					  //cout<<"Size = "<< pwlist.getWaitingList().size()<<endl;
				} //end of multiple transaction
				  //Here we have again populated the pwlist for next-round's parallel process
			} // End-if  ******* Check for Empty FlowPipe Done *********
		} //END of parallel FOR-LOOP
		//  ************************************** POST_D computation Ends **********************************************************
		t72.stop();
		double clock72;
		clock72 = t72.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return72 = clock72 / (double) 1000;
		std::cout << "\nDiscrete Post_D computation Time:Wall(Seconds) = " << return72 << std::endl;

//  ********** Safety Verification Should be after Flowpipe computation but due to omp-parallel-for NOT POSSIBLE to use break*************
		//Creating a list of objects of "Reachability Set"/Symbolic_states
		bool foundUnSafe = false;
		//Having is sequential to avoid critical section moreover this time is very very small
		for (unsigned int index = 0; index < count; index++) {
			if (S[index]->getContinuousSetptr()->getTotalIterations() != 0) //computed reach_region is NOT empty
				Reachability_Region.push_back(S[index]);
		}
#pragma omp parallel for
		for (unsigned int index = 0; index < count; index++) {
			//  ******************************** Safety Verification section ********************************
			saftey_violated = safetyVerify(S[index], Reachability_Region, ce_candidates);
#pragma omp critical
		{
			if (saftey_violated) {
				foundUnSafe = true; //have to insert all flowpipe of same breadth even if foundUnSafe=true for some flowpipe, So not breaking
			}
		}
			//  ******************************** Safety Verification section ********************************
		} //end-for pushing all computed flowpipe
//		if (foundUnSafe) {
//			break; // removed from inner-loop does not work in #pragma omp parallel for
//		}

		t = 1 - t; //Switching Read/Write options for Qpw_list[1-t]
//:: Can be optimize if we can count number_times inside the parallel loop per breadth then we can avoid transaction and intersection
//:: computation for next transition if number_times exceeds bound ....
		number_times++; //One Level or one Breadth Search over
		//cout << "\nnumber_times = " << number_times << "  Bound = " << bound << "\n";
		// ************************* BFS Ends *************************************
	} //end of while loop checking waiting_list != empty
	cout
			<< "\n ***************************************************************************\n";
	cout << "\nMaximum Iterations Completed = " << iter_max << "\n";
	cout
			<< "\n ***************************************************************************\n";

	return Reachability_Region;
}

/*** TODO: Have to optimize invariant_boundary_check() for support function computation ***/

void reachability::parallelReachSelection(unsigned int NewTotalIteration, location::ptr current_location,
		polytope::ptr continuous_initial_polytope,
		ReachabilityParameters& reach_parameters,
		std::vector<symbolic_states::ptr>& S, unsigned int id) {

	template_polyhedra::ptr reach_region;

	if (Algorithm_Type == SEQ) { //Continuous Sequential Algorithm
		//	cout << "\nRunning Sequntial\n";
		//		std::cout<<"\nBefore entering reachability Sequential = " << gurobi_lp_solver::gurobi_lp_count;
		//		std::cout<<"\nBefore entering reachability Sequential = " << lp_solver::lp_solver_count;
//			int a;			std::cin>>a;
		boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();

		reach_region = reachabilitySequential(NewTotalIteration,
				current_location->getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(),
				current_location->isInvariantExists(), lp_solver_type_choosen);
		S[id]->setContinuousSetptr(reach_region);

		AllReach_time.stop();
		double wall_clock1;
		wall_clock1 = AllReach_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nFlowPipe Time:Wall(Seconds) = " << return_Time1
				<< std::endl;
	}

	if (Algorithm_Type == PAR_OMP) {
		//Parallel implementation using OMP parallel			//	double wall_timer = omp_get_wtime();
		//cout << "\nRunning Parallel Using OMP Thread\n";
		boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();

		reach_region = reachabilityParallel(NewTotalIteration,
				current_location->getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(),
				current_location->isInvariantExists(), lp_solver_type_choosen);
		AllReach_time.stop();
		S[id]->setContinuousSetptr(reach_region);
		double wall_clock1;
		wall_clock1 = AllReach_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nFlowpipe Time:Wall(Seconds) = " << return_Time1
				<< std::endl;
		//	std::cout << "Time seen from mop wall timer: "<< omp_get_wtime() - wall_timer << std::endl;
	}

/*	if (Algorithm_Type == GPU_SF) { //computing all support function in GPU
		cout << "\nRunning GPU Sequential\n";
		boost::timer::cpu_timer AllReachGPU_time;
		AllReachGPU_time.start();
		reachabilitySequential_GPU(NewTotalIteration, current_location->getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(),
				current_location->isInvariantExists(), lp_solver_type_choosen,
				number_of_streams, Solver_GLPK_Gurobi_GPU, reach_region);
		S[id]->setContinuousSetptr(reach_region);

		AllReachGPU_time.stop();
		double wall_clock1;
		wall_clock1 = AllReachGPU_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nAllReach_time: Boost Time:Wall(Seconds) = "
				<< return_Time1 << std::endl;
	}*/

	if (Algorithm_Type == PAR_ITER) { //Continuous Parallel Algorithm parallelizing the Iterations :: to be debugged (compute initial polytope(s))
		cout
				<< "\nRunning Parallel-over-Iterations(PARTITIONS/Time-Sliced) Using OMP Thread\n";
		bool invertible;
		if (!current_location->getSystem_Dynamics().isEmptyMatrixA) {
			math::matrix<double> A_inv(current_location->getSystem_Dynamics().MatrixA.size1(),
					current_location->getSystem_Dynamics().MatrixA.size2());
			invertible = current_location->getSystem_Dynamics().MatrixA.inverse(A_inv); //size of A_inv must be declared else error
			if (!invertible)
				std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
			else
				reach_parameters.A_inv = A_inv;
			int NCores = Total_Partition; //Number of Partitions (number of threads)
			reach_region = reachParallelExplore(NewTotalIteration, current_location->getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters, current_location->getInvariant(),
					current_location->isInvariantExists(), NCores, PAR_ITER, lp_solver_type_choosen);
			S[id]->setContinuousSetptr(reach_region);
			//		std::cout << "Finished computing reachable states\n";
		} else {
			std::cout << "\nFlow Dynamics Matrix A does not exists!!!\n";
			template_polyhedra::ptr poly_emptyp;
			reach_region = poly_emptyp; //returning an empty reach_region for this location
			S[id]->setContinuousSetptr(reach_region);
		}
	}

	if (Algorithm_Type == PAR_ITER_DIR) {
		//using OMP:: Parallel implementation with a combination of Iterations and Directions
		//	cout << "\nRunning Parallel Using combination of Iterations and Directions\n";
		bool invertible;
		if (!current_location->getSystem_Dynamics().isEmptyMatrixA) {
			math::matrix<double> A_inv(
					current_location->getSystem_Dynamics().MatrixA.size1(),
					current_location->getSystem_Dynamics().MatrixA.size2());
			invertible = current_location->getSystem_Dynamics().MatrixA.inverse(
					A_inv); //size of A_inv must be declared else error
			if (!invertible)
				std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
			else
				reach_parameters.A_inv = A_inv;

			int NCores = Total_Partition; //Number of Partitions (number of threads)
			reach_region = reachParallelExplore(NewTotalIteration,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location->getInvariant(),
					current_location->isInvariantExists(), NCores, PAR_ITER_DIR,
					lp_solver_type_choosen);
			S[id]->setContinuousSetptr(reach_region);
		} else {
			std::cout << "\nFlow Dynamics Matrix A does not exists!!!\n";
			template_polyhedra::ptr poly_emptyp;
			reach_region = poly_emptyp; //returning an empty reach_region for this location
			S[id]->setContinuousSetptr(reach_region);
		}
	}
}

//Aggregrate All Flowpipe computation work into one BIG task and will run that in parallel either by multi-core CPU or GPU
std::list<symbolic_states::ptr> reachability::computeParallelLoadBalanceReach(std::list<abstractCE::ptr>& ce_candidates) {

	std::list < symbolic_states::ptr > Reachability_Region; //	template_polyhedra::ptr reach_region;
	int t = 0; //0 for Read and 1 for Write
	std::vector < std::vector<pwlist::ptr> > Qpw_list(2); // QpwList[0] for read and QpwList[1] for write 	//cout << "Test 1\n";
	Qpw_list[t].resize(1); //resize for the first symbolic_state 	//cout << "Test 2\n";
	Qpw_list[t][0] = pwlist::ptr(new pwlist()); //have to instantiate it
	Qpw_list[t][0]->WaitingList_insert(I); //cout << "Test 3\n";
	pwlist::ptr allPassedList; //so we create a permanent pwlist for storing only the passedList;
	allPassedList = pwlist::ptr(new pwlist()); //have to instantiate it
	int number_times = 0;
	bool levelcompleted = false;
	unsigned int iter_max = 1;
	int numCores = omp_get_num_procs(); //get the number of cores
	/*boost::timer::cpu_timer t70;
	t70.start();*/

	while (!isEmpty_Qpw_list(Qpw_list[t]) && (number_times <= bound)) { //	cout << "Test 5\n";
	//	cout<<"Breadth - Level === "<<number_times<<"\n";
//		boost::timer::cpu_timer t73;
//		t73.start();
		unsigned int count = getSize_Qpw_list(Qpw_list[t]); //get the size of PWList
			cout << "\nCount = " << count << "\n";
		std::vector < symbolic_states::ptr > S(count);
		vector < initial_state::ptr > list_U(count); //SubList for parallel		//	cout << "Test 6\n";
		list_U = getAllpw_list(Qpw_list, t, count, allPassedList); //All initial_state have been deleted //cout<<"Identifed pwList Done\n";
		//cout<<"list_U = "<<list_U.size();

		Qpw_list[t].resize(0);
		//cout<<"Qpw_list[t].size() = "<<Qpw_list[t].size()<<std::endl;

		Qpw_list[1 - t].resize(count); //resize to accommodate
		for (int i = 0; i < count; i++) {
			Qpw_list[1 - t][i] = pwlist::ptr(new pwlist()); //have to instantiate it
		}
//		t73.stop();
//		double clock73;
//		clock73 = t73.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
//		double return73 = clock73 / (double) 1000;
//		std::cout << "\nHow Much queue delete  Time:Wall(Seconds) = "<< return73 << std::endl;

		// ********************************* BFS Starts **********************************************************
		//	cout << "Test 7\n";
// ***************** DIRECTION and BIG_Task CREATION:: per breadth-level *****************
		/*boost::timer::cpu_timer t705;
		t705.start();*/
		std::vector < LoadBalanceData > LoadBalanceDS(count);
// ***************** DIRECTION and BIG_Task CREATION *****************

		//omp_set_nested(1);	//enables nested parallelization
		/*boost::timer::cpu_timer t702;
		t702.start();*/
#pragma omp parallel for // num_threads(count)
		for (unsigned int id = 0; id < count; id++) {
			initial_state::ptr U; //local
			U = list_U[id]; //independent symbolic state to work with
			discrete_set discrete_state; //local
			polytope::ptr continuous_initial_polytope; //local
			ReachabilityParameters reach_parameter_local; //local
			int location_id = U->getLocationId();
			discrete_state.insert_element(location_id);
			continuous_initial_polytope = U->getInitialSet();
			reach_parameter_local = reach_parameters;
			reach_parameter_local.X0 = continuous_initial_polytope; //	cout<<"\nInside for Loop";
			S[id] = symbolic_states::ptr(new symbolic_states());
			S[id]->setDiscreteSet(discrete_state);
			S[id]->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
			S[id]->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID
			location::ptr current_location;
			current_location = H.getLocation(location_id);
			string name = current_location->getName();
			//	cout<<"Location Name = "<< name<<"\n";
			if ((name.compare("GOOD") == 0) || (name.compare("BAD") == 0)
					|| (name.compare("UNSAFE") == 0) || (name.compare("FINAL") == 0))
				continue; //do not compute the continuous reachability algorithm
			// ******************* Computing Parameters ************************ //current_location:: parameters alfa, beta and phi_trans
			//cout<<"\nBefore Compute Alfa";
			double result_alfa = compute_alfa(reach_parameter_local.time_step,
					current_location->getSystem_Dynamics(), continuous_initial_polytope, lp_solver_type_choosen); //cout<<"\nCompute Alfa Done";
			//cout<<"\nCompute alfa  = " << result_alfa;
			double result_beta = compute_beta(current_location->getSystem_Dynamics(),
					reach_parameter_local.time_step, lp_solver_type_choosen); // NO glpk object created here
			//	cout<<"\nCompute Beta  = " << result_beta;
			reach_parameter_local.result_alfa = result_alfa;
			reach_parameter_local.result_beta = result_beta;
			math::matrix<double> phi_matrix, phi_trans;
			if (!current_location->getSystem_Dynamics().isEmptyMatrixA) { //if A not Empty
				current_location->getSystem_Dynamics().MatrixA.matrix_exponentiation(phi_matrix, reach_parameter_local.time_step);
				phi_matrix.transpose(phi_trans);
				reach_parameter_local.phi_trans = phi_trans;
			}
			math::matrix<double> B_trans;
			if (!current_location->getSystem_Dynamics().isEmptyMatrixB) { //if B not Empty
				current_location->getSystem_Dynamics().MatrixB.transpose(B_trans);
				reach_parameter_local.B_trans = B_trans;
			}
			// ******************* Computing Parameters Done *******************************
// *************** POST_C computation ********** in 3 steps ***************
			bool U_empty = false;
			if (current_location->getSystem_Dynamics().U->getIsEmpty()) { //polytope U can be empty set
				U_empty = true;
			}
			LoadBalanceDS[id].X0 = continuous_initial_polytope;
			LoadBalanceDS[id].U = current_location->getSystem_Dynamics().U;
			LoadBalanceDS[id].current_location = current_location;
			LoadBalanceDS[id].symState_ID = id;
			LoadBalanceDS[id].reach_param = reach_parameter_local;
		}	//END of count FOR-LOOP  -- reach parameters computed

#pragma omp parallel for // num_threads(count)
		for (unsigned int id = 0; id < count; id++) { //separate parameters assignment with Invariant check and preLoadBalanceReachCompute task
			unsigned int NewTotalIteration;
			if (LoadBalanceDS[id].current_location->isInvariantExists()) {
				InvariantBoundaryCheck(LoadBalanceDS[id].current_location->getSystem_Dynamics(), LoadBalanceDS[id].X0,
						LoadBalanceDS[id].reach_param, LoadBalanceDS[id].current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
				LoadBalanceDS[id].newIteration = NewTotalIteration; //Important to take care
			}else
				LoadBalanceDS[id].newIteration = LoadBalanceDS[id].reach_param.Iterations; //Important to take care

			std::cout << "NewTotalIteration = " << NewTotalIteration << std::endl;
		}	//END of count FOR-LOOP  -- invariant boundary check done
		/*boundCheck.stop();
		double wall_clockboundcheck;
		wall_clockboundcheck = boundCheck.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_TimeBC = wall_clockboundcheck / (double) 1000;
		std::cout<< "\nBoundary Check for Iterations Number Time taken:Wall  (in Seconds) = " << return_TimeBC << std::endl;*/

//		double cpu_usage; //including the directionComputation + SF_computation + substitute_Algo
//		init_cpu_usage();//initializing the CPU Usage utility to start recording usages

	//	omp_set_dynamic(0);	//handles dynamic adjustment of the number of threads within a team
	//	omp_set_nested(1); //enable nested parallelism
		int numCoreAvail = 1;
		if (numCores >= count)
			numCoreAvail = numCores - count;

		/*boost::timer::cpu_timer t2;
		t2.start();*/
#pragma omp parallel for //num_threads(count)
		for (unsigned int id = 0; id < count; id++) {
			math::matrix<float> listX0, listU;
			//	cout << "Test 8\n";
			//Generation of Directions which can be a nested parallelism
			preLoadBalanceReachCompute(LoadBalanceDS[id],numCoreAvail);	// Step 1
			//	cout << "Test 9\n";
			//Todo:: if newIteration is <= 1 than do not store this flow-pipe details in LoadBalanceDS
			// and accordingly reduce count or handle while computing LPsolver
		} //END of count FOR-LOOP
		parallelLoadBalance_Task(LoadBalanceDS);
		omp_set_nested(1); //enable nested parallelism

#pragma omp parallel for // num_threads(count)
		for (unsigned int id = 0; id < count; id++) {
			S[id]->setContinuousSetptr(substitute_in_ReachAlgorithm(LoadBalanceDS[id], numCoreAvail)); // Step 3
		}
		/*t107.stop();
		cpu_usage = getCurrent_ProcessCPU_usage();
		std::cout << "\nCPU Usage:(%) = " << cpu_usage<< std::endl;
		double clock107;
		clock107 = t107.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return107 = clock107 / (double) 1000;
		std::cout << "\nReach substitution Time:Wall(Seconds) = " << return107 << std::endl;*/

//  ********************* POST_C computation Done ********************
		/*t705.stop();
		double clock705;
		clock705 = t705.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return705 = clock705 / (double) 1000;
		std::cout << "\nFlow-pipe Computation Done Time:Wall(Seconds) = " << return705 << std::endl;
	std::cout << "****************************************************************************\n";
	double res = return702+return2+return3+return107;
	std::cout << "\nComputation Done (ReachParameters + Directions + Flow-pipe + Substitute) Time:Wall(Seconds) = " << res << std::endl;
	std::cout << "****************************************************************************\n";*/

		bool foundUnSafe = false;
/*		boost::timer::cpu_timer t71;
	t71.start();*/
	//this being a simple task of only pushing pointer into the "Reachability_Region" so separated from inside
	//the omp parallel region to avoid having it inside the critical region
		for (unsigned int index = 0; index < count; index++) {
			if (S[index]->getContinuousSetptr()->getTotalIterations() != 0) { //computed reach_region is NOT empty
				Reachability_Region.push_back(S[index]);
			}
		}

		number_times++; //One Level or one Breadth Search over

		if (number_times > bound) {
			levelcompleted = true; //check to see how many jumps have been made(i.e., number of discrete transitions made)
		}
		if (levelcompleted || foundUnSafe) { //any true
			break; //OUT FROM WHILE LOOP 	//no need to compute rest of the locations
		}

#pragma omp parallel for // num_threads(count)
		for (int id = 0; id < count; id++) {
//  ************************************** POST_D computation Begins **********************************************************
			template_polyhedra::ptr t_poly = S[id]->getContinuousSetptr();
			if (t_poly->getTotalIterations() != 0) { //computed reach_region is empty && optimize computation

				for (std::list<transition::ptr>::iterator trans =LoadBalanceDS[id].current_location->getOut_Going_Transitions().begin();
						trans!= LoadBalanceDS[id].current_location->getOut_Going_Transitions().end(); trans++) { // get each destination_location_id and push into the pwl.waiting_list
					int transition_id = (*trans)->getTransitionId();
					location::ptr current_destination;
					Assign current_assignment;
					polytope::ptr gaurd_polytope;
					//std::list < template_polyhedra::ptr > intersected_polyhedra;
					polytope::ptr intersectedRegion; //created two objects here
					discrete_set ds;
					current_destination = H.getLocation((*trans)->getDestination_Location_Id());
					string locName = current_destination->getName();
					//	cout << "\nNext Loc ID = " << current_destination.getLocId() << " Location Name = " << locName << "\n";
					gaurd_polytope = (*trans)->getGaurd();
					current_assignment = (*trans)->getAssignT();
					boost::timer::cpu_timer t100;
					//this intersected_polyhedra will have invariant direction added in it
					string trans_name = (*trans)->getLabel();
					/*t100.start();
					cout<<"id = "<<id<<"\n";*/
					std::list<polytope::ptr> polys;
					//intersected_polyhedra = t_poly->polys_intersectionParallel(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
					polys = t_poly->flowpipe_intersectionSequential(gaurd_polytope, lp_solver_type_choosen);
					//intersected_polyhedra =t_poly->polys_intersectionSequential(gaurd_polytope,lp_solver_type_choosen); //, intersection_start_point);

					/*t100.stop();
					double clock100;
					clock100 = t100.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
					double return100 = clock100 / (double) 1000;
					std::cout << "\nIntersection Time:Wall(Seconds) = " << return100 << std::endl;*/
					std::cout << "Intersected = " <<polys.size() << std::endl;

					if (polys.size() > 0) { //there is intersection so new symbolic state will be inserted into the waitingList
#pragma omp critical
						{
							iter_max += polys.size();
						}
					}
					// Handle this later as In SpaceEx model we did not specified BAD or GOOD
					if ((locName.compare("BAD") == 0) || (locName.compare("GOOD") == 0) || (locName.compare("FINAL") == 0)
							|| (locName.compare("UNSAFE") == 0)) {
						continue; //do not push into the waitingList
					} //	std::cout << "Before calling getTemplate_approx\n";

					int destination_locID = (*trans)->getDestination_Location_Id();
					ds.insert_element(destination_locID);

				//	cout << "\nNumber of Intersections = "<<intersected_polyhedra.size()<<std::endl;
				/*	boost::timer::cpu_timer t74;
					t74.start();*/
					for (std::list<polytope::ptr>::iterator it = polys.begin(); it != polys.end(); it++) {
						//cout << "\nNumber of Intersections #1\n";

						//intersectedRegion = (*it)->getTemplate_approx(lp_solver_type_choosen);
						intersectedRegion = (*it);
						//Returns a single over-approximated polytope from the list of intersected polytopes
						polytope::ptr newShiftedPolytope, newPolytope; //created an object here
						newPolytope = intersectedRegion->GetPolytope_Intersection(gaurd_polytope); //Retuns only the intersected region as a single newpolytope. ****** with added directions
						//std::cout << "Before calling post_assign_exact\n";
						newShiftedPolytope = post_assign_exact(newPolytope, current_assignment.Map, current_assignment.b); //initial_polytope_I = post_assign_exact(newPolytope, R, w);

						initial_state::ptr newState = initial_state::ptr(new initial_state(destination_locID, newShiftedPolytope));
						newState->setTransitionId(transition_id); // keeps track of the transition_ID
						newState->setParentPtrSymbolicState(S[id]);
//#pragma omp critical
//					{
	/*
	 * Todo:: we insert all the symbolic_states into the pwlist for computing FlowPipe iff 1) and 2) holds
	 * Step 1) the new current_destination.getLocID() is NOT in the Passed List and
	 * Step 2) the "New Initial Polytope" or "the newShiftedPolytope" is NOT contained in the FlowPipe of LocationID of step 1
	 *  as the FlowPipe in the same location will be same if the newShiftedPolytope is IN FlowPipe
	 *  But if Step 1 holds and Step 2 does not then it will be inserted in pwlist even if the LocationID is in Passed List
	 */
						Qpw_list[1 - t][id]->WaitingList_insert(newState); //RACE CONDITION HERE
						//					}
					} //end of multiple intersected region with guard
					/*t74.stop();
					double clock74;
					clock74 = t74.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
					double return74 = clock74 / (double) 1000;
					std::cout << "\nQueue Push Time:Wall(Seconds) = "<< return74 << std::endl;*/
					//cout<<""
					//cout<<"Size = "<< pwlist.getWaitingList().size()<<endl;
				} //end of multiple transaction
				  //Here we have again populated the pwlist for next-round's parallel process
			} // End-if
//  ************************************** POST_D computation Ends **********************************************************
		} //parallel for-loop
		/*t72.stop();
		double clock72;
		clock72 = t72.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return72 = clock72 / (double) 1000;
		std::cout << "\nDiscrete Post_D computation Time:Wall(Seconds) = " << return72 << std::endl;*/
		t = 1 - t; //Switching Read/Write options for Qpw_list[1-t]
		// ************************* BFS Ends *************************************
	} //end of while loop checking waiting_list != empty
	/*t70.stop();
	double clock70;
	clock70 = t70.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double return70 = clock70 / (double) 1000;
	std::cout << "\n pbfs Completed Time:Wall(Seconds) = " << return70 << std::endl;*/
	cout << "\n **********************************************************\n";
	cout << "   *** Maximum Iterations Completed = " << iter_max << "  ***\n";
	cout << "\n **********************************************************\n";

	return Reachability_Region;
}



/*
 * Aggregrate All Flowpipe computation work into one BIG task and will run that in parallel either by multi-core CPU or GPU
 * Also the Post_D is done in the same manner
 */
std::list<symbolic_states::ptr> reachability::LoadBalanceAll(std::list<abstractCE::ptr>& ce_candidates) {

	std::list < symbolic_states::ptr > Reachability_Region; //	template_polyhedra::ptr reach_region;
	int t = 0; //0 for Read and 1 for Write
	std::vector < std::vector<pwlist::ptr> > Qpw_list(2); // QpwList[0] for read and QpwList[1] for write 	//cout << "Test 1\n";
	Qpw_list[t].resize(1); //resize for the first symbolic_state 	//cout << "Test 2\n";
	Qpw_list[t][0] = pwlist::ptr(new pwlist()); //have to instantiate it
	Qpw_list[t][0]->WaitingList_insert(I); //cout << "Test 3\n";
	pwlist::ptr allPassedList; //so we create a permanent pwlist for storing only the passedList;
	allPassedList = pwlist::ptr(new pwlist()); //have to instantiate it
	int number_times = 0;
	bool levelcompleted = false;
	unsigned int iter_max = 1;
	int numCores = omp_get_num_procs(); //get the number of cores
	/*boost::timer::cpu_timer t70;
	t70.start();*/

	while (!isEmpty_Qpw_list(Qpw_list[t]) && (number_times <= bound)) { //	cout << "Test 5\n";
	//	cout<<"Breadth - Level === "<<number_times<<"\n";
//		boost::timer::cpu_timer t73;
//		t73.start();
		unsigned int count = getSize_Qpw_list(Qpw_list[t]); //get the size of PWList
		cout << "\nNumber of Flowpipes to be Computed (per Breadths) = " << count << "\n";
		std::vector < symbolic_states::ptr > S(count);
		vector < initial_state::ptr > list_U(count); //SubList for parallel		//	cout << "Test 6\n";
		list_U = getAllpw_list(Qpw_list, t, count, allPassedList); //All initial_state have been deleted //cout<<"Identifed pwList Done\n";
		//cout<<"list_U = "<<list_U.size();

		Qpw_list[t].resize(0);
		//cout<<"Qpw_list[t].size() = "<<Qpw_list[t].size()<<std::endl;

		Qpw_list[1 - t].resize(count); //resize to accommodate
		for (int i = 0; i < count; i++) {
			Qpw_list[1 - t][i] = pwlist::ptr(new pwlist()); //have to instantiate it
		}
//		t73.stop();
//		double clock73;
//		clock73 = t73.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
//		double return73 = clock73 / (double) 1000;
//		std::cout << "\nHow Much queue delete  Time:Wall(Seconds) = "<< return73 << std::endl;

		// ********************************* BFS Starts **********************************************************
		//	cout << "Test 7\n";
// ***************** DIRECTION and BIG_Task CREATION:: per breadth-level *****************
		/*boost::timer::cpu_timer t705;
		t705.start();*/
		std::vector < LoadBalanceData > LoadBalanceDS(count);
// ***************** DIRECTION and BIG_Task CREATION *****************

		//omp_set_nested(1);	//enables nested parallelization
		/*boost::timer::cpu_timer t702;
		t702.start();*/
#pragma omp parallel for // num_threads(count)
		for (unsigned int id = 0; id < count; id++) {
			initial_state::ptr U; //local
			U = list_U[id]; //independent symbolic state to work with
			discrete_set discrete_state; //local
			polytope::ptr continuous_initial_polytope; //local
			ReachabilityParameters reach_parameter_local; //local
			int location_id = U->getLocationId();
			discrete_state.insert_element(location_id);
			continuous_initial_polytope = U->getInitialSet();
			reach_parameter_local = reach_parameters;
			reach_parameter_local.X0 = continuous_initial_polytope; //	cout<<"\nInside for Loop";
			S[id] = symbolic_states::ptr(new symbolic_states());
			S[id]->setDiscreteSet(discrete_state);
			S[id]->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
			S[id]->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID
			location::ptr current_location;
			current_location = H.getLocation(location_id);
			string name = current_location->getName();
			//	cout<<"Location Name = "<< name<<"\n";
			if ((name.compare("GOOD") == 0) || (name.compare("BAD") == 0)
					|| (name.compare("UNSAFE") == 0) || (name.compare("FINAL") == 0))
				continue; //do not compute the continuous reachability algorithm
			// ******************* Computing Parameters ************************ //current_location:: parameters alfa, beta and phi_trans
			//cout<<"\nBefore Compute Alfa";
			double result_alfa = compute_alfa(reach_parameter_local.time_step,
					current_location->getSystem_Dynamics(), continuous_initial_polytope, lp_solver_type_choosen); //cout<<"\nCompute Alfa Done";
			//cout<<"\nCompute alfa  = " << result_alfa;
			double result_beta = compute_beta(current_location->getSystem_Dynamics(),
					reach_parameter_local.time_step, lp_solver_type_choosen); // NO glpk object created here
			//	cout<<"\nCompute Beta  = " << result_beta;
			reach_parameter_local.result_alfa = result_alfa;
			reach_parameter_local.result_beta = result_beta;
			math::matrix<double> phi_matrix, phi_trans;
			if (!current_location->getSystem_Dynamics().isEmptyMatrixA) { //if A not Empty
				current_location->getSystem_Dynamics().MatrixA.matrix_exponentiation(phi_matrix, reach_parameter_local.time_step);
				phi_matrix.transpose(phi_trans);
				reach_parameter_local.phi_trans = phi_trans;
			}
			math::matrix<double> B_trans;
			if (!current_location->getSystem_Dynamics().isEmptyMatrixB) { //if B not Empty
				current_location->getSystem_Dynamics().MatrixB.transpose(B_trans);
				reach_parameter_local.B_trans = B_trans;
			}
			// ******************* Computing Parameters Done *******************************
// *************** POST_C computation ********** in 3 steps ***************
			bool U_empty = false;
			if (current_location->getSystem_Dynamics().U->getIsEmpty()) { //polytope U can be empty set
				U_empty = true;
			}
			LoadBalanceDS[id].X0 = continuous_initial_polytope;
			LoadBalanceDS[id].U = current_location->getSystem_Dynamics().U;
			LoadBalanceDS[id].current_location = current_location;
			LoadBalanceDS[id].symState_ID = id;
			LoadBalanceDS[id].reach_param = reach_parameter_local;
		}	//END of count FOR-LOOP  -- reach parameters computed

#pragma omp parallel for // num_threads(count)
		for (unsigned int id = 0; id < count; id++) { //separate parameters assignment with Invariant check and preLoadBalanceReachCompute task
			unsigned int NewTotalIteration;

			if (LoadBalanceDS[id].current_location->isInvariantExists()) {

				if (LoadBalanceDS[id].current_location->getSystem_Dynamics().isEmptyMatrixB == true
						&& LoadBalanceDS[id].current_location->getSystem_Dynamics().isEmptyC == true) {
					//Approach of Coarse-time-step and Fine-time-step
					jumpInvariantBoundaryCheck(
							LoadBalanceDS[id].current_location->getSystem_Dynamics(),
							LoadBalanceDS[id].X0, LoadBalanceDS[id].reach_param,
							LoadBalanceDS[id].current_location->getInvariant(),
							lp_solver_type_choosen, NewTotalIteration);
				} else {
					//Approach of Sequential invariant check will work for all case
					InvariantBoundaryCheck(
							LoadBalanceDS[id].current_location->getSystem_Dynamics(),
							LoadBalanceDS[id].X0, LoadBalanceDS[id].reach_param,
							LoadBalanceDS[id].current_location->getInvariant(),
							lp_solver_type_choosen, NewTotalIteration);
				}
				LoadBalanceDS[id].newIteration = NewTotalIteration; //Important to take care
				//cout<<"Invariant setting Done\n";
			}else
				LoadBalanceDS[id].newIteration = LoadBalanceDS[id].reach_param.Iterations; //Important to take care
			//std::cout << "NewTotalIteration = " << NewTotalIteration << std::endl;
		}	//END of count FOR-LOOP  -- invariant boundary check done

		int numCoreAvail = 1;
		if (numCores >= count)
			numCoreAvail = numCores - count;

		#pragma omp parallel for //num_threads(count)
		for (unsigned int id = 0; id < count; id++) {
			math::matrix<float> listX0, listU;
			//Generation of Directions which can be a nested parallelism
			preLoadBalanceReachCompute(LoadBalanceDS[id],numCoreAvail);	// Step 1
			//Todo:: if newIteration is <= 1 than do not store this flow-pipe details in LoadBalanceDS
			// and accordingly reduce count or handle while computing LPsolver
		} //END of count FOR-LOOP

		parallelLoadBalance_Task(LoadBalanceDS);//So an appropriate combination of parallel with sequential GLPK object is used.
		omp_set_nested(1); //enable nested parallelism

#pragma omp parallel for // num_threads(count)
		for (unsigned int id = 0; id < count; id++) {
			S[id]->setContinuousSetptr(substitute_in_ReachAlgorithm(LoadBalanceDS[id], numCoreAvail)); // Step 3
		}

//  ********************* POST_C computation Done ********************

		bool foundUnSafe = false;
		for (unsigned int index = 0; index < count; index++) {
			if (S[index]->getContinuousSetptr()->getTotalIterations() != 0) { //computed reach_region is NOT empty
				Reachability_Region.push_back(S[index]);
			}
		}
		number_times++; //One Level or one Breadth Search over

		if (number_times > bound) {
			levelcompleted = true; //check to see how many jumps have been made(i.e., number of discrete transitions made)
		}
		if (levelcompleted || foundUnSafe) { //any true
			break; //OUT FROM WHILE LOOP 	//no need to compute rest of the locations
		}
std::vector<LoadBalanceData_PostD> loadBalPostD(count);
//  ***************** Load Balanced POST_D computation Begins::Has 3 Steps ***********************************
//Step--1 :: Pre-Load Balancing Task to populate guard, assign, etc in Data Structure
//cout<<"done 1\n";
#pragma omp parallel for // num_threads(count)
		for (int id = 0; id < count; id++) {
			if (S[id]->getContinuousSetptr()->getTotalIterations() != 0) {	//if flowpipe not Empty
				loadBalPostD[id].sfm = S[id]->getContinuousSetptr();
				int transition_size = LoadBalanceDS[id].current_location->getOut_Going_Transitions().size();
				loadBalPostD[id].trans_size = transition_size;
				//cout<<"transition_size = "<<transition_size <<"\n";
				loadBalPostD[id].guard_list.resize(transition_size);
				loadBalPostD[id].assign_list.resize(transition_size);
				loadBalPostD[id].dest_locID.resize(transition_size);
				loadBalPostD[id].trans_ID.resize(transition_size);
				loadBalPostD[id].range_list.resize(transition_size);
				loadBalPostD[id].bool_arr.resize(transition_size, 0);//initially only rows are known

				loadBalPostD[id].polys_list.resize(transition_size);
				int index=0; // for guard_list, assign_list if they are vector
				for (std::list<transition::ptr>::iterator trans =LoadBalanceDS[id].current_location->getOut_Going_Transitions().begin();
					trans!= LoadBalanceDS[id].current_location->getOut_Going_Transitions().end(); trans++) { // get each destination_location_id and push into the pwl.waiting_list
					loadBalPostD[id].guard_list[index] = (*trans)->getGaurd();
					loadBalPostD[id].assign_list[index] = (*trans)->getAssignT();
					loadBalPostD[id].dest_locID[index] = (*trans)->getDestination_Location_Id();
					index++;
				}	//each transition
			} else {//EndIf of flowpipe not Empty
				cout<<"This condition Also MET!!!\n";
			}
		}
	//	cout<<"done 2\n";
//Step--2 :: First Loading Balancing computation Task
		loadBalancedPostD(loadBalPostD);	//returns array of booleans with true or FALSE based on intersected or NOT
	//	cout<<"done 3\n";
//Step--3 :: Second Task to detect sequentially
		intersectionRangeDetection(loadBalPostD);	//returns list of range pair indicating Start and End as SFM's columnIndex
	//	cout<<"done 4\n";
//Step--4 :: Third Task to perform Template_Approximation
		templateApproximation(loadBalPostD);
	//	cout<<"done 5\n";
//Step--5 :: Finally creating new symbolic states to push in the Qpw_list[1-t]
#pragma omp parallel for
		for (int id = 0; id < count; id++) {

			for (int trans=0;trans<loadBalPostD[id].trans_size;trans++){
				std::list<polytope::ptr> polys;
				polys = loadBalPostD[id].polys_list[trans];
				#pragma omp critical
				{
					iter_max += polys.size();
				}
				string locName = H.getLocation(loadBalPostD[id].dest_locID[trans])->getName();
				if ((locName.compare("BAD") == 0) || (locName.compare("GOOD") == 0) || (locName.compare("FINAL") == 0)
						|| (locName.compare("UNSAFE") == 0)) {
			/*		#pragma omp critical
					{
						iter_max = iter_max - 1;
					}*/
					continue; //do not push into the waitingList
				}
				polytope::ptr intersectedRegion;
				for (std::list<polytope::ptr>::iterator it = polys.begin(); it != polys.end(); it++) {
					intersectedRegion = (*it);
					polytope::ptr newShiftedPolytope, newPolytope; //created an object here
					newPolytope = intersectedRegion->GetPolytope_Intersection(loadBalPostD[id].guard_list[trans]); //Retuns only the intersected region as a single newpolytope. ****** with added directions
					newShiftedPolytope = post_assign_exact(newPolytope, loadBalPostD[id].assign_list[trans].Map,
							loadBalPostD[id].assign_list[trans].b); //initial_polytope_I = post_assign_exact(newPolytope, R, w);
					initial_state::ptr newState = initial_state::ptr(new initial_state(loadBalPostD[id].dest_locID[trans], newShiftedPolytope));
					newState->setTransitionId(loadBalPostD[id].trans_ID[trans]); // keeps track of the transition_ID
					newState->setParentPtrSymbolicState(S[id]);

					Qpw_list[1 - t][id]->WaitingList_insert(newState); //False RACE CONDITION HERE
				} //end of multiple intersected region with guard
			}//end of for each guard or transitions
		}//end of for parallel

//  ************************************** POST_D computation Ends **********************************************************



		t = 1 - t; //Switching Read/Write options for Qpw_list[1-t]
		// ************************* BFS Ends *************************************
	} //end of while loop checking waiting_list != empty
	cout << "\n **********************************************************\n";
	cout << "   *** Maximum Iterations Completed = " << iter_max << "  ***\n";
	cout << "\n **********************************************************\n";

	return Reachability_Region;
}


void reachability::loadBalancedPostD(std::vector<LoadBalanceData_PostD>& loadBalPostD){

	unsigned int Total_Length = 0;
	for (int i = 0; i < loadBalPostD.size(); i++) { //for each symbolic-states
		unsigned int sfm_len = loadBalPostD[i].sfm->getTotalIterations();	//length of each sfm
		Total_Length += sfm_len;
		loadBalPostD[i].bool_arr.resize(loadBalPostD[i].trans_size, sfm_len);	//resize(rows,col)
	}	//total_length Obtainted and bool_arrary resized
//cout<<"Total_Length = "<<Total_Length<<"\n";
#pragma omp parallel for
	for (unsigned int i = 0; i < Total_Length; i++) {
		int sfmIndex;
		unsigned int sfmColIndex;
		search_sfmIndex_colIndex(i, loadBalPostD, sfmIndex, sfmColIndex);
		polytope::ptr p;
		p = loadBalPostD[sfmIndex].sfm->getPolytope(sfmColIndex);
		std::vector<double> constraint_bound_values(loadBalPostD[sfmIndex].sfm->getInvariantDirections().size1());
		constraint_bound_values = loadBalPostD[sfmIndex].sfm->getInvariantBoundValue(sfmColIndex);
		p->setMoreConstraints(loadBalPostD[sfmIndex].sfm->getInvariantDirections(),constraint_bound_values);
		for (int trans = 0; trans < loadBalPostD[sfmIndex].trans_size; trans++) {
			loadBalPostD[sfmIndex].bool_arr(trans, sfmColIndex) = p->check_polytope_intersection(loadBalPostD[sfmIndex].guard_list[trans], lp_solver_type_choosen);//result of intersection
		}
	} //end of parallel-loop :: we have the list of intersected polys
}


/*
 * Detecting the range of sfm that are intersected with the guard
 */
void reachability::intersectionRangeDetection(std::vector<LoadBalanceData_PostD>& loadBalPostD) {
	int count = loadBalPostD.size();
	//cout<<"Is this same count = "<<count<<"\n";
#pragma omp parallel for
	for (int id = 0; id < count; id++) {
		for (int trans = 0; trans < loadBalPostD[id].trans_size; trans++) {
			std::list<std::pair<unsigned int, unsigned int> > intersected_range;
			bool is_intersected = false, intersection_started = false, intersection_ended = false;
			int foundIntersection = 0;
			std::pair<unsigned int, unsigned int> inte_range;
			for (unsigned int i = 0; i < loadBalPostD[id].sfm->getTotalIterations(); i++) { //sequential reading of an boolean_array that tells intersected polys
				is_intersected = loadBalPostD[id].bool_arr(trans, i);
				if (is_intersected == true) { //if intersects create a new template_polyhedra subset
					intersection_started = true;
					if (foundIntersection == 0) { //Intersection start
						foundIntersection++; //intersection_start = i;	//Intersection started at this position of 'i'
						inte_range.first = i; //	cout << "\nIntersection Found at = " << i << endl;
					}
				}
				if (intersection_started == true && is_intersected == false) {
					intersection_ended = true;
					inte_range.second = i;
					foundIntersection = 0;
				}
				if (intersection_ended == true && intersection_started == true) {
					intersected_range.push_back(inte_range);
					intersection_started = false;
					intersection_ended = false; //cout << "\nIntersection Ended at = " << i << "\n";
				}
			}
			if (intersection_started == true && intersection_ended == false) {
				inte_range.second = loadBalPostD[id].sfm->getTotalIterations() - 1;
				intersected_range.push_back(inte_range); //	cout << "\nIntersection did not End = " << i2 << "\n";
			}
			loadBalPostD[id].range_list[trans] = intersected_range;	//todo:: Verify resize problem
		}	//end of each transition or guard
	}	//end of FOR each sfm in parallel
}

void reachability::templateApproximation(std::vector<LoadBalanceData_PostD>& loadBalPostD){
int count = loadBalPostD.size();

#pragma omp parallel for
	for (int id=0;id<count;id++){
		for (int trans = 0; trans < loadBalPostD[id].trans_size; trans++) {
			std::list<std::pair<unsigned int, unsigned int> > range_list;
			//range_list = loadBalPostD[id].polys_list[trans];
			range_list = loadBalPostD[id].range_list[trans];
			std::list<polytope::ptr> polys;
			unsigned int poly_dir_size = loadBalPostD[id].sfm->getTotalTemplateDirections()
							+ loadBalPostD[id].sfm->getTotalInvariantDirections();
			std::vector<double> colVector(poly_dir_size);
			for (std::list<std::pair<unsigned int, unsigned int> >::iterator range_it = range_list.begin();
					range_it != range_list.end(); range_it++) {
				unsigned int start = (*range_it).first, end=(*range_it).second;
			//	cout << "first = " << start << "  second = " << end << std::endl;
				for (unsigned int eachTemplateDir=0;eachTemplateDir<loadBalPostD[id].sfm->getTotalTemplateDirections();	eachTemplateDir++){
					double Max_sf=loadBalPostD[id].sfm->getMatrixSupportFunction()(eachTemplateDir,start);
					for (int i = start+1; i <= end; i++) {
						double sf=loadBalPostD[id].sfm->getMatrixSupportFunction()(eachTemplateDir,i);
						if (sf > Max_sf)
							Max_sf = sf;
					}//end of each intersected region
					colVector[eachTemplateDir] = Max_sf;
				}//end of each template direction ALSO HAVE TO PERFORM INVARIANT DIRECTION
				unsigned int total_dir = loadBalPostD[id].sfm->getTotalTemplateDirections();
				for (unsigned int eachInvDir=0;eachInvDir<loadBalPostD[id].sfm->getTotalInvariantDirections();eachInvDir++){
					double Max_sf=loadBalPostD[id].sfm->getMatrix_InvariantBound()(eachInvDir,start);
					for (int i = start + 1; i <= end; i++) {
						double sf = loadBalPostD[id].sfm->getMatrix_InvariantBound()(eachInvDir, i);
						if (sf > Max_sf)
							Max_sf = sf;
					} //end of each intersected region
					colVector[total_dir + eachInvDir] = Max_sf;
				}
				math::matrix<double> allDirs;
				//Debug
				math::matrix<double> test;
				test =loadBalPostD[id].sfm->getTemplateDirections();
				//-----
				test.matrix_join(loadBalPostD[id].sfm->getInvariantDirections(), allDirs);
				polytope::ptr p = polytope::ptr(new polytope(allDirs,colVector,1));
				polys.push_back(p);
			}//end of multiple intersected region
			loadBalPostD[id].polys_list[trans]= polys;
		}
	}//end for each parallel

}



bool reachability::safetyVerify(symbolic_states::ptr& computedSymStates,
		std::list<symbolic_states::ptr>& Reachability_Region,
		std::list<abstractCE::ptr>& ce_candidates) {

	std::list < symbolic_states::ptr > list_sym_states;
	std::list < abstract_symbolic_state::ptr > list_abstract_sym_states;
	polytope::ptr abs_flowpipe; //bounding_box Polytope
	polytope::ptr polyI; // initial polytope of the abstract flowpipe.
	bool saftey_violated = false;
	std::list < transition::ptr > list_transitions;

	if (computedSymStates->getContinuousSetptr()->getTotalIterations() != 0) { //flowpipe exists
		//so perform intersection with forbidden set provided locID matches
		int locID;
		discrete_set ds;
		ds = computedSymStates->getDiscreteSet();
		for (std::set<int>::iterator it = ds.getDiscreteElements().begin();
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
			std::list < template_polyhedra::ptr > forbid_intersects;
			//forbid_intersects = computedSymStates->getContinuousSetptr()->polys_intersectionParallel(forbid_poly, lp_solver_type_choosen);

			forbid_intersects = computedSymStates->getContinuousSetptr()->polys_intersectionSequential(
							forbid_poly, lp_solver_type_choosen); //TODO:: CHECK RUNNING BOTH PARALLEL AND SEQUENTIAL

			if (forbid_intersects.size() == 0) {
				std::cout << "\nThe model does NOT violates SAFETY property!!!\n";
			} else {
				std::cout << "\nThe model violates SAFETY property!!!\n";
				symbolic_states::ptr current_forbidden_state;
				current_forbidden_state = computedSymStates;
			//				abstract_symbolic_state::ptr curr_abs_sym_state;
			//				curr_abs_sym_state = abstract_symbolic_state::ptr(new abstract_symbolic_state());
				std::cout << "\nReverse Path Trace =>\n";
				int cc = 0;
				do {
					int locationID, locationID2;
					discrete_set ds, ds2;
					ds = current_forbidden_state->getDiscreteSet();

					abs_flowpipe = convertBounding_Box(
							current_forbidden_state->getContinuousSetptr());
					polyI =
							current_forbidden_state->getInitial_ContinousSetptr();
					// Here create a new abstract_symbolic_state
					abstract_symbolic_state::ptr curr_abs_sym_state =
							abstract_symbolic_state::ptr(
									new abstract_symbolic_state(ds,
											abs_flowpipe, polyI));

					// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********

					for (std::set<int>::iterator it =
							ds.getDiscreteElements().begin();
							it != ds.getDiscreteElements().end(); ++it)
						locationID = (*it); //Assuming only a single element exist in the discrete_set

					int transID = current_forbidden_state->getTransitionId(); //a)
					//   **********************************************************
					//todo::create an object of abstractCE[1)list_of_symbolic_states 2)list_of_transition and 3) length]
					//1) ******************** list_of_symbolic_states ********************
					list_sym_states.push_front(current_forbidden_state); //pushing the bad symbolic_state first(at the top)
					list_abstract_sym_states.push_front(curr_abs_sym_state);
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
					std::cout << "(" << locationID << ", " << transID << ")";
					current_forbidden_state =
							searchSymbolic_state(Reachability_Region,
									current_forbidden_state->getParentPtrSymbolicState()); //b)

					//2) ******************* list_transitions ********************
					ds2 = current_forbidden_state->getDiscreteSet(); //c)
					for (std::set<int>::iterator it =
							ds2.getDiscreteElements().begin();
							it != ds2.getDiscreteElements().end(); ++it)
						locationID2 = (*it); //c)
					location::ptr object_location;
					object_location = H.getLocation(locationID2); //d)
					transition::ptr temp = object_location->getTransition(
							transID); //e)
					list_transitions.push_front(temp); //pushing the transition in the stack
					//2) ******************* list_transitions Ends ********************
					cc++;
				} while (current_forbidden_state->getParentPtrSymbolicState()
						!= NULL);

				if ((cc >= 1)
						&& (current_forbidden_state->getParentPtrSymbolicState()
								== NULL)) { //root is missed
					ds = current_forbidden_state->getDiscreteSet();

					int locationID, locationID2;
					discrete_set ds, ds2;
					ds = current_forbidden_state->getDiscreteSet();

					abs_flowpipe = convertBounding_Box(
							current_forbidden_state->getContinuousSetptr());
					polyI =
							current_forbidden_state->getInitial_ContinousSetptr();
					// Here create a new abstract_symbolic_state
					abstract_symbolic_state::ptr curr_abs_sym_state =
							abstract_symbolic_state::ptr(
									new abstract_symbolic_state(ds,
											abs_flowpipe, polyI));

					// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********

					for (std::set<int>::iterator it =
							ds.getDiscreteElements().begin();
							it != ds.getDiscreteElements().end(); ++it)
						locationID = (*it); //Assuming only a single element exist in the discrete_set

					int transID = current_forbidden_state->getTransitionId();
					list_sym_states.push_front(current_forbidden_state); //1) pushing the initial/root bad symbolic_state at the top
					list_abstract_sym_states.push_front(curr_abs_sym_state);

					std::cout << " -->  (" << locationID << ", " << transID
							<< ")\n";
				}
				saftey_violated = true;
#pragma omp critical
				{
					abstractCE::ptr ce = abstractCE::ptr(new abstractCE());
					ce->set_length(cc);
					ce->set_sym_states(list_abstract_sym_states);
					ce->set_transitions(list_transitions);
					hybrid_automata::ptr h = hybrid_automata::ptr(
							new hybrid_automata(H));
					ce->set_automaton(h);
					ce->set_forbid_poly(forbid_poly);
					ce_candidates.push_back(ce); // ce added to the candidates list
				}
			} // end of condition when forbidden state intersects with the flowpipe set
		} //end of condition when forbidden state loc id matches with flowpipe loc id
	} //computed flowpipe is not empty
	return saftey_violated;
}

void reachability::preLoadBalanceReachCompute(LoadBalanceData& LoadBalanceDS, int numCoresAvail){

unsigned int NewTotalIteration;

//	unsigned int NewTotalIteration = ReachParameters.Iterations;
//	cout <<"Before NewTotalIteration = " <<NewTotalIteration<<"\n";
	bool U_empty = false;

	NewTotalIteration = LoadBalanceDS.newIteration;
	if (NewTotalIteration <= 1) {
		return;
	}
	if (LoadBalanceDS.current_location->getSystem_Dynamics().U->getIsEmpty()) { //polytope U can be empty set
		U_empty = true;
	}
	int Solver = Solver_GLPK_Gurobi_GPU; //1 for CPU solver(GLPK); //2 for CPU solver(Gurobi); //3 for GPU solver(Gimplex)
//  ************* Generation of Directions Begins ***************
	unsigned int numVectors = LoadBalanceDS.reach_param.Directions.size1();
	unsigned int totalDirList1 = numVectors * (NewTotalIteration + 1); //1 extra for loop1
	math::matrix<float> List_for_X0(totalDirList1, LoadBalanceDS.reach_param.Directions.size2());
	unsigned int totalDirList2 = numVectors * NewTotalIteration; //'n' dirs for each 'n' loops
	math::matrix<float> List_for_U(totalDirList2, LoadBalanceDS.reach_param.Directions.size2());

	/*boost::timer::cpu_timer DirectionsGenerate_time;
	DirectionsGenerate_time.start();*/
	getDirectionList_X0_and_U(numCoresAvail, LoadBalanceDS.reach_param, NewTotalIteration, List_for_X0,
			List_for_U, U_empty, LoadBalanceDS.current_location->getSystem_Dynamics()); //Optimized into a single function the 2 Tasks
	/*DirectionsGenerate_time.stop();
	double wall_clock1;
	wall_clock1 = DirectionsGenerate_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double return_Time1 = wall_clock1 / (double) 1000;
	std::cout<< "\nDirections Generation: Boost Time taken:Wall  (in Seconds) = " << return_Time1 << std::endl;*/
//  ************* Generation of Directions Ends ***************
	/*boost::timer::cpu_timer dirCopy_time; //just to verify the Time take
	dirCopy_time.start();*/

	LoadBalanceDS.List_dir_X0 = List_for_X0;
	LoadBalanceDS.List_dir_U = List_for_U;

	/*dirCopy_time.stop();
	double wall_clock2;
	wall_clock2 = dirCopy_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double return_Time2 = wall_clock2 / (double) 1000;
	std::cout << "\nDirections copy: Boost Time taken:Wall  (in Seconds) = "<< return_Time2 << std::endl;*/

}

void reachability::computeBIG_Task(std::vector<LoadBalanceData>& LoadBalanceDS) {
	for (int i = 0; i < LoadBalanceDS.size(); i++) { //for each symbolic-states
		assert(i == LoadBalanceDS[i].symState_ID);
		int dimension = LoadBalanceDS[i].List_dir_X0.size2();
		lp_solver lp(this->lp_solver_type_choosen), lp_U(
				this->lp_solver_type_choosen);
		lp.setMin_Or_Max(2); //2 for Maximization
		//cout << "Testing A1\n";
		lp.setConstraints(LoadBalanceDS[i].reach_param.X0->getCoeffMatrix(),
				LoadBalanceDS[i].reach_param.X0->getColumnVector(),
				LoadBalanceDS[i].reach_param.X0->getInEqualitySign());
		//cout << "Testing A2\n";
		lp_U.setMin_Or_Max(2);
		bool U_empty;
		U_empty =
				LoadBalanceDS[i].current_location->getSystem_Dynamics().U->getIsEmpty();
		if (!U_empty) {
			LoadBalanceDS[i].sf_U.resize(LoadBalanceDS[i].List_dir_U.size1());
			lp_U.setConstraints(LoadBalanceDS[i].U->getCoeffMatrix(),
					LoadBalanceDS[i].U->getColumnVector(),
					LoadBalanceDS[i].U->getInEqualitySign());
			for (unsigned int j = 0; j < LoadBalanceDS[i].List_dir_U.size1();
					j++) { //for all directions ** Can be done in loop **** A ******
				std::vector<double> dirs(dimension);
				for (int index = 0; index < dimension; index++) {
					dirs[index] = LoadBalanceDS[i].List_dir_U(j, index);
				}
				LoadBalanceDS[i].sf_U[j] = lp_U.Compute_LLP(dirs);
			}
		}
		//cout << "Testing A3\n";
		//unsigned int tot_dirs = LoadBalanceDS[i].List_dir_X0.size1();
		LoadBalanceDS[i].sf_X0.resize(LoadBalanceDS[i].List_dir_X0.size1());
		LoadBalanceDS[i].sf_dotProduct.resize(
				LoadBalanceDS[i].List_dir_X0.size1());
		LoadBalanceDS[i].sf_UnitBall.resize(
				LoadBalanceDS[i].List_dir_X0.size1());
//#pragma omp parallel for
		for (unsigned int j = 0; j < LoadBalanceDS[i].List_dir_X0.size1();
				j++) { //for all directions  ****** A ******
			std::vector<double> dirs(dimension);
			for (int index = 0; index < dimension; index++) {
				dirs[index] = LoadBalanceDS[i].List_dir_X0(j, index);
			}
			//cout << "Testing A4\n";
			LoadBalanceDS[i].sf_X0[j] = lp.Compute_LLP(dirs);
			//cout << "Testing A5\n";
			// ******DotProduction and Support Function of UnitBall  *******
			LoadBalanceDS[i].sf_dotProduct[j] = dot_product(LoadBalanceDS[i].current_location->getSystem_Dynamics().C, dirs);
			LoadBalanceDS[i].sf_UnitBall[j] = support_unitball_infnorm(dirs);
		}
	} //end-for each symbolic-states
}

//can be parallelized to task-based approach
void reachability::parallelBIG_Task(std::vector<LoadBalanceData>& LoadBalanceDS) {

	int dimension = LoadBalanceDS[0].List_dir_X0.size2();
	unsigned int countTotal_X = 0, countTotal_U = 0;
	//cout <<"erro 1\n";
	for (int i = 0; i < LoadBalanceDS.size(); i++) { //for each symbolic-states
		countTotal_X = countTotal_X + LoadBalanceDS[i].List_dir_X0.size1();
	//	cout<<"   = "<<LoadBalanceDS[i].List_dir_X0.size1()<<std::endl;
		countTotal_U = countTotal_U + LoadBalanceDS[i].List_dir_U.size1();
		// *********** resize all result vector  *********************
		LoadBalanceDS[i].sf_X0.resize(LoadBalanceDS[i].List_dir_X0.size1()); // resize
		LoadBalanceDS[i].sf_U.resize(LoadBalanceDS[i].List_dir_U.size1()); // resize
		LoadBalanceDS[i].sf_UnitBall.resize(LoadBalanceDS[i].List_dir_X0.size1()); // resize
		LoadBalanceDS[i].sf_dotProduct.resize(LoadBalanceDS[i].List_dir_X0.size1()); // resize
	} //getCountTotal(LoadBalanceDS, countTotal_X, countTotal_U);
	//cout << "countTotal_X = " << countTotal_X << std::endl;
//cout <<"erro 2\n";
/*	std::ofstream myfile,myfile2;
	myfile.open("./sf_X.txt");
	myfile2.open("./dir_X.txt");*/
//#pragma omp parallel for
	for (int i = 0; i < countTotal_X; i++) {
		int index;
		unsigned int j;
		//cout <<"erro 3\n";
		search_SymState_dirsX0Index(i, LoadBalanceDS, index, j);
		//	cout <<"erro index = "<<index <<"  j = "<<j<<"\n";
		std::vector<double> dirs(dimension);
		for (int ind = 0; ind < dimension; ind++) {
			dirs[ind] = LoadBalanceDS[index].List_dir_X0(j, ind);
		//	myfile2<<dirs[ind]<< "\t";
		}
		//myfile2<< "\n";
		LoadBalanceDS[index].sf_X0[j] = LPSolver(LoadBalanceDS[index].X0, dirs);
	//	myfile <<"i = "<<i<<"   ";
	//	myfile <<LoadBalanceDS[index].sf_X0[j]<<"\n";
		//LoadBalanceDS[index].sf_X0[j] = boxLPSolver(LoadBalanceDS[index].X0, dirs);
		// ******DotProduction and Support Function of UnitBall  *******
		if (!LoadBalanceDS[index].current_location->getSystem_Dynamics().isEmptyC) {
			LoadBalanceDS[index].sf_dotProduct[j] = dot_product(LoadBalanceDS[index].current_location->getSystem_Dynamics().C,dirs);
		}
		LoadBalanceDS[index].sf_UnitBall[j] = support_unitball_infnorm(dirs);
		// ******DotProduction and Support Function of UnitBall  *******
	}
	//myfile.close();
	//myfile2.close();
	//cout <<"erro 3\n";
	bool U_empty;
	U_empty = LoadBalanceDS[0].current_location->getSystem_Dynamics().U->getIsEmpty();
	//todo:: assuming all symbolic states has same setup for polytope U
	if (!U_empty) {
		cout<<"polytope U is NOT empty!!!!\n";
#pragma omp parallel for
		for (int i = 0; i < countTotal_U; i++) {
			int index;
			unsigned int j;
			search_SymState_dirsUIndex(i, LoadBalanceDS, index, j);
			std::vector<double> dirs(dimension);
			for (int ind = 0; ind < dimension; ind++) {
				dirs[ind] = LoadBalanceDS[index].List_dir_U(j, ind);
			}
			LoadBalanceDS[index].sf_U[j] = LPSolver(LoadBalanceDS[index].U, dirs);
		}
	}
}

void reachability::parallelLoadBalance_Task(std::vector<LoadBalanceData>& LoadBalanceDS) {
//cout<<"Inside parallelLoadBalance_Task\n";
	int numCores = omp_get_num_procs(); //get the number of cores
//	cout<<"numCores = "<<numCores<<std::endl;
//	int numSymStates = LoadBalanceDS.size(); //get the number of symbolic states i.e. number of polytopes X0
//	cout<<"numSymStates = "<<numSymStates<<std::endl;
	unsigned int seq_LP;
	int size, chunk_size;
	/*if (numCores > numSymStates)
		size = numCores;
	else
		size = numSymStates;*/
	int dimension = LoadBalanceDS[0].List_dir_X0.size2();
	unsigned int countTotal_X = 0, countTotal_U = 0;
	for (int i = 0; i < LoadBalanceDS.size(); i++) { //for each symbolic-states
		countTotal_X += LoadBalanceDS[i].List_dir_X0.size1();
		//cout<<"   = "<<LoadBalanceDS[i].List_dir_X0.size1()<<std::endl;
		countTotal_U += LoadBalanceDS[i].List_dir_U.size1();
		// *********** resize all result vector  *********************
		LoadBalanceDS[i].sf_X0.resize(LoadBalanceDS[i].List_dir_X0.size1()); // resize
		LoadBalanceDS[i].sf_U.resize(LoadBalanceDS[i].List_dir_U.size1()); // resize
		LoadBalanceDS[i].sf_UnitBall.resize(LoadBalanceDS[i].List_dir_X0.size1()); // resize
		LoadBalanceDS[i].sf_dotProduct.resize(LoadBalanceDS[i].List_dir_X0.size1()); // resize
	} //getCountTotal(LoadBalanceDS, countTotal_X, countTotal_U);
// ************* Chunk_approach for polytope X ******************************
	//cout << "countTotal_X = " << countTotal_X << std::endl;
	/*if (countTotal_X <= size) {
		chunk_size = (int)countTotal_X;	//todo:: may be do it sequential
	} else
		chunk_size = compute_chunk_size(countTotal_X);//todo: find an appropriate number of chunk-size based on the size of countTotal_X*/
	if (countTotal_X < numCores)
		chunk_size = 1;
	else
		chunk_size = numCores;
	seq_LP =(unsigned int) (countTotal_X / chunk_size); //Last group/partition may not be equal if result is fraction
	//cout<<"  chunk_size = "<<chunk_size <<"  seq_LP = "<<seq_LP<<std::endl;

#pragma omp parallel for
	for (int i = 0; i < chunk_size; i++) { //number of partition for load balancing
		unsigned int j; //index for sequential inner-loop
		unsigned int lb = i * seq_LP, ub = (i * seq_LP + seq_LP);
		if (i == (chunk_size - 1))	//handling the Last group/partition
			ub = countTotal_X;
		j = lb;
		int index, oldIndex; //index of symbolic_state
		unsigned int  indexDir; //indices of symbolic_state and direction within that symbolic state
		search_SymState_dirsX0Index(j, LoadBalanceDS, index, indexDir);
		while (j < ub) {
			oldIndex = index;	//previously computed
			lp_solver lp(this->lp_solver_type_choosen); //1 for using GLPK solver
			lp.setMin_Or_Max(2); //Maximizing
			lp.setConstraints(LoadBalanceDS[index].X0->getCoeffMatrix(), LoadBalanceDS[index].X0->getColumnVector(),
					LoadBalanceDS[index].X0->getInEqualitySign());
			//for (;(j < ub) && (oldIndex == index);){
			while (j < ub){
				std::vector<double> dir(dimension);
				for (int ind = 0; ind < dimension; ind++) {
					dir[ind] = LoadBalanceDS[index].List_dir_X0(indexDir, ind);
				}
				LoadBalanceDS[index].sf_X0[indexDir] = lp.Compute_LLP(dir);	//support function of X0
			//	cout<<LoadBalanceDS[index].sf_X0[indexDir]<<"\t";
				// ******DotProduction and Support Function of UnitBall  *******
				//TODO: MAKE DECISION TO KEEP IT OUTSIDE AT ONE LOOP-VALUE LIKE BEFORE
				if (!LoadBalanceDS[index].current_location->getSystem_Dynamics().isEmptyC) {
					LoadBalanceDS[index].sf_dotProduct[indexDir] = dot_product(LoadBalanceDS[index].current_location->getSystem_Dynamics().C,dir);
				}
				LoadBalanceDS[index].sf_UnitBall[indexDir] = support_unitball_infnorm(dir);
				// ******DotProduction and Support Function of UnitBall  *******
				//cout<<j<<"\t";
				j++;//next LP problem
				search_SymState_dirsX0Index(j, LoadBalanceDS, index, indexDir);
				if (oldIndex != index){
					break;	//change of symbolic_state or polytope X0
				}
			}	//end-for	//cout<<"\n";
		}//end-while	//cout<<"\n\n";
	}//end of parallel
// ************* Chunk_approach for polytope X ******************************
	bool U_empty;
	U_empty = LoadBalanceDS[0].current_location->getSystem_Dynamics().U->getIsEmpty();//assuming all symbolic states has same setup for polytope U
	if (!U_empty) {
// ************* Chunk_approach for polytope U ******************************
	//	cout<<"polytope U is NOT empty!!!!\n";
		if (countTotal_X <= numCores)
			chunk_size = 1;
		else
			chunk_size = numCores;
		seq_LP =(unsigned int) (countTotal_U / chunk_size); //Last group/partition may not be equal if result is fraction
#pragma omp parallel for
		for (int i = 0; i < chunk_size; i++) { //number of partition for load balancing
			unsigned int j; //index for sequential inner-loop
			unsigned int lb = i * seq_LP, ub = (i * seq_LP + seq_LP);
			if (i == (chunk_size - 1))	//handling the Last group/partition
				ub = countTotal_U;
			j = lb;
			int index, oldIndex; //index of symbolic_state
			unsigned int  indexDir; //indices of symbolic_state and direction within that symbolic state
			search_SymState_dirsUIndex(j, LoadBalanceDS, index, indexDir);
			while (j < ub) {
				oldIndex = index;	//previously computed
				lp_solver lp(this->lp_solver_type_choosen); //1 for using GLPK solver
				lp.setMin_Or_Max(2); //Maximizing
				lp.setConstraints(LoadBalanceDS[index].U->getCoeffMatrix(), LoadBalanceDS[index].U->getColumnVector(),
						LoadBalanceDS[index].U->getInEqualitySign());
				while (j < ub){
					std::vector<double> dir(dimension);
					for (int ind = 0; ind < dimension; ind++) {
						dir[ind] = LoadBalanceDS[index].List_dir_U(indexDir, ind);
					}
					LoadBalanceDS[index].sf_U[indexDir] = lp.Compute_LLP(dir);	//support function of U
					//cout<<j<<"\t";
					j++;//next LP problem
					search_SymState_dirsUIndex(j, LoadBalanceDS, index, indexDir);
					if (oldIndex != index){
						break;	//change of symbolic_state or polytope X0
					}
				}	//end-for
			} //end-while
		} //end of parallel
// ************* Chunk_approach for polytope U ******************************
	} //end-if of empty check
}


double reachability::LPSolver(polytope::ptr poly, std::vector<double> dirs) {
	double res;
	if (poly->getIsEmpty())
		res = 0.0;
	else {
		lp_solver lp(this->lp_solver_type_choosen);
		lp.setMin_Or_Max(2); //for maximizing
		lp.setConstraints(poly->getCoeffMatrix(), poly->getColumnVector(), poly->getInEqualitySign());
		res = lp.Compute_LLP(dirs);
	}
	return res;
}

/*
 * A hyperbox LP solver
 */

double reachability::boxLPSolver(polytope::ptr poly, std::vector<double> dir) {
	double res = 0.0;
	math::matrix<double> M = poly->getCoeffMatrix();
	math::vector<double> b = poly->getColumnVector();
	double lb, ub;
	for (unsigned int i = 0; i < dir.size(); i++) {
		if (dir[i] < 0) {
			//iterate over the ith component of each row of M
			for (unsigned int row = 0; row < M.size1(); row++) {
				if (M(row, i) == -1) { // lower bound constraint
					lb = -1 * b[row];
					break;
				}
			}
			res += dir[i] * lb;
		} else {
			//iterate over the ith component of each row of M
			for (unsigned int row = 0; row < M.size1(); row++) {
				if (M(row, i) == 1) { // lower bound constraint
					ub = b[row];
					break;
				}
			}
			res += dir[i] * ub;
		}
	}
	return res;
}
template_polyhedra::ptr reachability::substitute_in_ReachAlgorithm(
		LoadBalanceData& LoadBalanceDS, int numCoreAvail) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	template_polyhedra::ptr reachableRegion; //template_polyhedra::ptr reachRegion;

	//std::cout << "\n Running BIG_Task Reach Algorithm " << std::endl;

/*	boost::timer::cpu_timer reachLoop_time;
	reachLoop_time.start();*/
	unsigned int numVectors = LoadBalanceDS.reach_param.Directions.size1(); //size2 or the dimension will be some for all sym_state
	int num_inv =
			LoadBalanceDS.current_location->getInvariant()->getColumnVector().size(); //number of Invariant's constriants
	math::matrix<double> inv_directions;
	inv_directions =
			LoadBalanceDS.current_location->getInvariant()->getCoeffMatrix();
	std::vector<double> inv_bounds(num_inv);
	inv_bounds =
			LoadBalanceDS.current_location->getInvariant()->getColumnVector();

	if (LoadBalanceDS.newIteration <= 1) {
		template_polyhedra::ptr poly_emptyp;
		return poly_emptyp;
	}
	int dimension = LoadBalanceDS.X0->getSystemDimension();
	int Min_Or_Max = 2;
	size_type row = numVectors, col = LoadBalanceDS.newIteration;
	math::matrix<double> MatrixValue(row, col);

	int cores;
	if (numVectors >= numCoreAvail)
		cores = numVectors;
	else
		cores = numCoreAvail;
//	omp_set_dynamic(0);	//handles dynamic adjustment of the number of threads within a team

//#pragma omp parallel for num_threads(cores)
	for (unsigned int eachDirection = 0; eachDirection < numVectors; eachDirection++) {
		unsigned int index_X0, index_U; //making the index suitable for parallelizing
		//unsigned int index; 	//index = eachDirection * NewTotalIteration;
		//here i have a list of result of Supp_fun_Of_UnitBall_infinity_norm
		if (eachDirection == 0) { //only starting loop begins with 0
			index_X0 = eachDirection * LoadBalanceDS.newIteration;
		} else { //
			index_X0 = eachDirection * LoadBalanceDS.newIteration + eachDirection; //only X0(list_X0) has 2 directions for first-iteration
		}
		bool U_empty =
				LoadBalanceDS.current_location->getSystem_Dynamics().U->getIsEmpty();
		if (!U_empty) {
			index_U = eachDirection * LoadBalanceDS.newIteration;
		}
		double res1, result1;
		double term1, term2, term3, term3a, term3b, res2, term3c = 0.0;
		double zIInitial = 0.0, zI = 0.0, zV = 0.0;
		double sVariable = 0.0, s1Variable; //initialize s0
		std::vector<double> rVariable(dimension), r1Variable(dimension);
		unsigned int loopIteration = 0;
		//	std::cout<<"Testing 1\n";
		//  ************** Omega Function   ********************
		res1 = LoadBalanceDS.sf_X0[index_X0]; //X0->SF(direction)			//	0
		//	std::cout<<"Testing 2\n";
		//term3b = support_unitball_infnorm(Direction_List[index].direction);
		term3b = (double) LoadBalanceDS.sf_UnitBall[index_X0]; //  needed  0
		//cout<<"term3b = "<<term3b<<"\n";
		if (!LoadBalanceDS.current_location->getSystem_Dynamics().isEmptyC) {
			term3c = LoadBalanceDS.reach_param.time_step * LoadBalanceDS.sf_dotProduct[index_X0];
			//	cout<<"dot_product(SystemDynamics.C, rVariable) = "<<LoadBalanceDS.sf_dotProduct[index_X0]<<"\n";
		}
		//	std::cout<<"Testing 3\n";
		index_X0++; //	made 1
		term1 = LoadBalanceDS.sf_X0[index_X0]; //X0->SF(phi_trans_dir)		//  1
		//	std::cout<<"Testing 4\n";
		index_X0++; //	made 2
		if (!U_empty) {
			term2 = LoadBalanceDS.reach_param.time_step * LoadBalanceDS.sf_U[index_U]; //U->SF(Btrans_dir)
			index_U++;
		} else
			term2 = 0;

		term3a = LoadBalanceDS.reach_param.result_alfa; //compute_alfa(ReachParameters.time_step,system_dynamics,Initial_X0);
		term3 = term3a * term3b;
		res2 = term1 + term2 + term3 + term3c; //term3c Added
		//zIInitial = (res1 > res2 ? res1:res2);
		if (res1 > res2)
			zIInitial = res1;
		else
			zIInitial = res2;
		//  ************** Omega Function   ********************
		MatrixValue(eachDirection, loopIteration) = zIInitial; //		index++;
		//	cout<<"zIInitial = "<< zIInitial<<std::endl;
		loopIteration++;
		for (; loopIteration < LoadBalanceDS.newIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
			//  ************** W_Support Function   ********************
			double result, res_sup;
			if (!U_empty) {
				/*	res1 = LoadBalanceDS.reach_param.time_step * LoadBalanceDS.sf_U[index_U - 1]; //replace previous value
				 //index_U++;
				 } else {
				 res1 = 0;*/
				result1 = term2;
			}
			double beta = LoadBalanceDS.reach_param.result_beta;
			//res_sup = (double) support_unitball_infnorm(Direction_List[index].direction);
			//res_sup = (double) supp_func_UnitBall[d_index];  d_index++;	//Should replace from previous computation
			//res_sup = term3b; //replaced from previous steps
			/*if (loopIteration == 1) // needed  0 again here
			 res_sup = supp_func_UnitBall[index_X0 - 2]; //Should replace from previous computation*/

			//double res_beta = beta * res_sup;
			double res_beta = beta * term3b;

			result = result1 + res_beta + term3c; //Added term3c
			zV = result;
			//  ************** W_Support Function   ********************
			s1Variable = sVariable + zV;
			//  ************** Omega Function   ********************
			//double res1;
			//res1 = LoadBalanceDS.sf_X0[index_X0 - 1]; ////replace previous value....  X0->SF(direction)		//	(2 -1)=1
			res1 = term1; ////replace

			term3b = (double) LoadBalanceDS.sf_UnitBall[index_X0 - 1]; //Compute here	//needed 1
			//	cout<<"term3b = "<<term3b<<"\n";
			if (!LoadBalanceDS.current_location->getSystem_Dynamics().isEmptyC) {
				term3c = LoadBalanceDS.reach_param.time_step * LoadBalanceDS.sf_dotProduct[index_X0 - 1];
				//	cout<<"dot_product(SystemDynamics.C, r1Variable) = "<<LoadBalanceDS.sf_dotProduct[index_X0 - 1]<<"\n";
			}
			double term3, term3a, res2;
			term1 = LoadBalanceDS.sf_X0[index_X0]; //X0->SF(phi_trans_dir)		//	2
			index_X0++; // 	made 3
			if (!U_empty) {
				term2 = LoadBalanceDS.reach_param.time_step * LoadBalanceDS.sf_U[index_U]; //U->SF(Btrans_dir)
				index_U++;
			} else {
				term2 = 0;
			}
			term3a = LoadBalanceDS.reach_param.result_alfa; //compute_alfa(ReachParameters.time_step,system_dynamics,Initial_X0);
			term3 = term3a * term3b;
			res2 = term1 + term2 + term3 + term3c;
			//zIInitial = (res1 > res2 ? res1:res2);
			if (res1 > res2)
				zI = res1;
			else
				zI = res2;
			//  ************** Omega Function   ********************
			double TempOmega;
			TempOmega = zI + s1Variable; //Y1
			//	cout<<"TempOmega = "<< TempOmega<<std::endl;
			MatrixValue(eachDirection, loopIteration) = TempOmega; //Y1
			sVariable = s1Variable; //	index++;
			loopIteration++; //for the next Omega-iteration or Time-bound
		} //end of all Iterations of each vector/direction
	} //end of for each vector/directions

	//std::cout<<"working 2ab"<<std::endl;
	std::cout << std::fixed; //to assign precision on the std::output stream
	std::cout.precision(10); //cout << setprecision(17);
	/*boost::timer::cpu_timer invSet;
	invSet.start();*/
	if (LoadBalanceDS.current_location->isInvariantExists() == true) { //if invariant exist. Computing
		//std::cout<<"Invariant Exists Test inside 1a\n";
		math::matrix<double> inv_sfm;
//		std::cout<<"num_inv = "<<num_inv <<"\n";
//		std::cout<<"working"<<std::endl;
		inv_sfm.resize(num_inv, LoadBalanceDS.newIteration);
		for (int eachInvDirection = 0; eachInvDirection < num_inv; eachInvDirection++) {
			//std::cout<<"working"<<std::endl;
//#pragma omp parallel for //num_threads(cores)
			for (unsigned int i = 0; i < LoadBalanceDS.newIteration; i++) {
				//inv_sfm(eachInvDirection, i) = invariant->getColumnVector()[eachInvDirection];
				inv_sfm(eachInvDirection, i) = inv_bounds[eachInvDirection];
				//cout<<"inv_bounds[eachInvDirection] = "<< inv_bounds[eachInvDirection]<<"\n";
				//inv_sfm(eachInvDirection, i) = LoadBalanceDS.current_location->getInvariant()->getColumnVector()[eachInvDirection];
				//cout<<"inv_bounds[eachInvDirection] = "<< inv_sfm(eachInvDirection, i)<<"\n";
			}
		}
		//	std::cout<<"working a2"<<std::endl;
		reachableRegion = template_polyhedra::ptr(new template_polyhedra());
		//	std::cout<<"reachRegion size = "<<reachableRegion->getTotalIterations()<<std::endl;
		//	std::cout<<"working 2b"<<std::endl;
		reachableRegion->setTemplateDirections(LoadBalanceDS.reach_param.Directions);
		//	std::cout<<"LoadBalanceDS.reach_param.Directions = "<<LoadBalanceDS.reach_param.Directions<<std::endl;
		reachableRegion->setMatrix_InvariantBound(inv_sfm);
		//std::cout<<"working 3"<<std::endl;
		reachableRegion->setInvariantDirections(inv_directions);
		//std::cout<<"working 4"<<std::endl;
		reachableRegion->setMatrixSupportFunction(MatrixValue);
		//return template_polyhedra::ptr( new template_polyhedra(MatrixValue, inv_sfm, ReachParameters.Directions, inv_directions));
	} else {
		//	std::cout<<"Invariant does not Exists!!!\n";
		reachableRegion = template_polyhedra::ptr(new template_polyhedra());
		reachableRegion->setMatrixSupportFunction(MatrixValue);
		reachableRegion->setTemplateDirections(LoadBalanceDS.reach_param.Directions);
		//	return template_polyhedra::ptr(	new template_polyhedra(MatrixValue, ReachParameters.Directions));
	}
	/*invSet.stop();
	double wall_clock_invSet;
	wall_clock_invSet = invSet.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double invSet_Time = wall_clock_invSet / (double) 1000;
	std::cout << "\nInvariantSet Time:Wall  (in Seconds) = " << invSet_Time<< std::endl;*/
/*	reachLoop_time.stop();
	double wall_clock;
	wall_clock = reachLoop_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double reach_Time = wall_clock / (double) 1000;
	std::cout << "\nFinal Reach Loop Time:Wall  (in Seconds) = " << reach_Time<< std::endl;*/

	return reachableRegion;

}
// Golzman algorithm adaption

std::list<symbolic_states::ptr> reachability::ParallelBFS_GH()
{
	std::list < symbolic_states::ptr > Reachability_Region; //	template_polyhedra::ptr reach_region;
	int t = 0; //0 for Read and 1 for Write
	int N = CORE; // Number of cores in the machine
	std::list<initial_state::ptr> Wlist[2][N][N];
	for(unsigned int i=0;i<2;i++){
		for(unsigned int j=0;j<N;j++){
			for(unsigned int k=0;k<N;k++){
				std::list<initial_state::ptr> l;
				Wlist[i][j][k] = l;
			}
		}
	}
	Wlist[t][0][0].push_back(this->I);
	std::list<symbolic_states::ptr> PASSED;
	unsigned int level = 0;
	bool done;
	//srand(time(NULL));
	int count=1;	//for initial symbolic state
	unsigned int previousBreadth=1;
	cout << "\nNumber of Flowpipes to be Computed (per Breadths) = " << count<< "\n";
	do {
		done = true;
#pragma omp parallel for
		for(unsigned int i=0;i<N;i++){
			for(unsigned int q=0;q<N;q++){
				for(std::list<initial_state::ptr>::iterator it = Wlist[t][i][q].begin(); it!=Wlist[t][i][q].end();it++){
					initial_state::ptr s = (*it);
					template_polyhedra::ptr R;
					R = postC(s);
					symbolic_states::ptr R1 = symbolic_states::ptr(new symbolic_states());
					R1->setContinuousSetptr(R);
					discrete_set d;
					d.insert_element(s->getLocationId());
					R1->setDiscreteSet(d);
#pragma omp critical
				{
					PASSED.push_back(R1);
				}
					//----end of postC on s

				//Currently removed the Safety Check Section from here

					std::list<initial_state::ptr> R2;
					if (level < bound){	//Check level to avoid last PostD computation
						R2 = postD(R1);
#pragma omp critical
					{
					 count = count + R2.size();
					}
						//cout <<"postD size = " <<R2.size()<<std::endl;
						std::vector<int> ArrCores(N);	//If this is done only once outside time saved but race-condition?
						for (int id=0;id<N;id++){
							ArrCores[id] = id;	//sequential insertion into the array
						}
						int startVal=0;
						std::random_shuffle(ArrCores.begin(), ArrCores.end());
						for(std::list<initial_state::ptr>::iterator its = R2.begin();its != R2.end();its++){
							initial_state::ptr next_s = (*its);
							/* generate a random number between 1 and N: */
							int w_rand = ArrCores[startVal];	//ArrCores.pop_back();	//Removes from the back
							startVal++;	//sequentially traversing the shuffed arrary
							if (startVal==N) //traversing reached end this occurs if sym_states more than the available cores
								startVal = 0; //so start traversing again from the beginning of the shuffed arrary.
							//std::cout << "Selected Core = " << w_rand << std::endl;
							Wlist[1-t][w_rand][i].push_back(next_s);
						}
					}	//end of level check
					// call postD with res of prev step
				}
					Wlist[t][i][q].clear();
			}
		}
		// barrier synchronization
		for(unsigned int i=0;i<N;i++){
			for(unsigned int j=0;j<N;j++){
				if(!Wlist[1-t][i][j].empty()){
					done = false;
					break;
				}
			}
			if(!done)
				break;
		}
		unsigned int temp = count - previousBreadth;
		if (level < bound){
			cout << "\nNumber of Flowpipes to be Computed (per Breadths) = " << temp << "\n";
		}
		previousBreadth = count;

		level++;
		t = 1 - t;
	}while(level<=bound && !done);
cout<<"******************************************************************\n";
cout <<"Maximum number of Symbolic states Passed = " <<count<<"\n";
cout<<"******************************************************************\n";
	return PASSED;

}

template_polyhedra::ptr reachability::postC(initial_state::ptr s){
	int location_id;

	discrete_set d;
	location_id = s->getLocationId();
	d.insert_element(location_id); //creating discrete_state

	//continuous_initial_polytope = U.getInitial_ContinousSetptr();
	polytope::ptr continuous_initial_polytope;
	continuous_initial_polytope = s->getInitialSet();

	ReachabilityParameters reach_parameters; //local
	//cout<<"No error 111!!!!\n";
	reach_parameters = this->reach_parameters;
//	cout<<"No error 2222!!!!\n";
	reach_parameters.X0 = continuous_initial_polytope;
	symbolic_states::ptr S;

	location::ptr current_location;

	current_location = H.getLocation(location_id);
	string name = current_location->getName();

	double result_alfa = compute_alfa(reach_parameters.time_step,
			current_location->getSystem_Dynamics(), continuous_initial_polytope,
			lp_solver_type_choosen); //2 glpk object created here
	double result_beta = compute_beta(current_location->getSystem_Dynamics(),
			reach_parameters.time_step, lp_solver_type_choosen); // NO glpk object created here

	reach_parameters.result_alfa = result_alfa;
	reach_parameters.result_beta = result_beta;
	math::matrix<double> phi_matrix, phi_trans;

	if (!current_location->getSystem_Dynamics().isEmptyMatrixA) { //if A not Empty
		current_location->getSystem_Dynamics().MatrixA.matrix_exponentiation(
				phi_matrix, reach_parameters.time_step);
		phi_matrix.transpose(phi_trans);
		reach_parameters.phi_trans = phi_trans;
	}
	math::matrix<double> B_trans;
	// transpose to be done once and stored in the structure of parameters
	if (!current_location->getSystem_Dynamics().isEmptyMatrixB) { //if B not Empty
		current_location->getSystem_Dynamics().MatrixB.transpose(B_trans);
		reach_parameters.B_trans = B_trans;
	}

	// ******************* Computing Parameters *******************************

	unsigned int NewTotalIteration = reach_parameters.Iterations;
	if (current_location->isInvariantExists()) {

		if (current_location->getSystem_Dynamics().isEmptyMatrixB==true && current_location->getSystem_Dynamics().isEmptyC==true){
			//Approach of Coarse-time-step and Fine-time-step
			jumpInvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope, reach_parameters,
									current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
		}else{
			//Approach of Sequential invariant check will work for all case
			InvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope,
					 reach_parameters, current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
		}

		/*jumpInvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope, reach_parameters,
						current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);*/

		/*quickInvariantBoundaryCheck(current_location->getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(), lp_solver_type_choosen,
				NewTotalIteration);*/
	}

	template_polyhedra::ptr reach_region;
//	std::cout << "NewTotalIteration = " << NewTotalIteration << std::endl;

	//parallelReachSelection(NewTotalIteration, current_location, continuous_initial_polytope, reach_parameters, reach_region, id);
	reach_region = reachabilitySequential(NewTotalIteration,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location->getInvariant(),
					current_location->isInvariantExists(), lp_solver_type_choosen);
	/*sequentialReachSelection(NewTotalIteration, current_location,
			continuous_initial_polytope, reach_region);*/

	return reach_region;
}
std::list<initial_state::ptr> reachability::postD(symbolic_states::ptr symb)
{
	template_polyhedra::ptr reach_region= symb->getContinuousSetptr();
	int locId = *(symb->getDiscreteSet().getDiscreteElements().begin());

	location::ptr current_location = H.getLocation(locId);
	std::list<initial_state::ptr> res;

	if (reach_region->getTotalIterations() != 0) { //computed reach_region is empty && optimize transition BreadthLevel-wise
	//	cout<<"1\n";
		for (std::list<transition::ptr>::iterator t = current_location->getOut_Going_Transitions().begin();
				t != current_location->getOut_Going_Transitions().end(); t++) { // get each destination_location_id and push into the pwl.waiting_list
			int transition_id = (*t)->getTransitionId();

			location::ptr current_destination;
			Assign current_assignment;
			polytope::ptr gaurd_polytope;
			//std::list < template_polyhedra::ptr > intersected_polyhedra;
			polytope::ptr intersectedRegion;//created two objects here
			discrete_set ds;
			current_destination = H.getLocation((*t)->getDestination_Location_Id());

			string locName = current_destination->getName();
			gaurd_polytope = (*t)->getGaurd();//	GeneratePolytopePlotter(gaurd_polytope);

		//cout<<"2\n";
			std::list<polytope::ptr> polys;
			//intersected_polyhedra = reach_region->polys_intersectionSequential(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
			polys = reach_region->flowpipe_intersectionSequential(gaurd_polytope, lp_solver_type_choosen);


		//cout<<"3\n";
			//Todo to make is even procedure with Sequential procedure.... so intersection is done first and then decide to skip this loc
			if ((locName.compare("BAD") == 0) || (locName.compare("GOOD") == 0)
					|| (locName.compare("FINAL") == 0) || (locName.compare("UNSAFE") == 0))
			continue;//do not push into the waitingList

			current_assignment = (*t)->getAssignT();
			// *** interesected_polyhedra included with invariant_directions also ******
		//	cout<<"size = "<< intersected_polyhedra.size();

			int destination_locID = (*t)->getDestination_Location_Id();
			ds.insert_element(destination_locID);

			for (std::list<polytope::ptr>::iterator i = polys.begin(); i != polys.end(); i++) {
				intersectedRegion = (*i);
				//intersectedRegion = (*i)->getTemplate_approx(lp_solver_type_choosen);
				//Returns a single over-approximated polytope from the list of intersected polytopes
				//	GeneratePolytopePlotter(intersectedRegion);
				polytope::ptr newShiftedPolytope, newPolytope;//created an object here
				newPolytope = intersectedRegion->GetPolytope_Intersection(gaurd_polytope);//Retuns the intersected region as a single newpolytope. **** with added directions
				newShiftedPolytope = post_assign_exact(newPolytope, current_assignment.Map, current_assignment.b);//initial_polytope_I = post_assign_exact(newPolytope, R, w);

				//	newShiftedPolytope->print2file(newInitSet,0,1); //printing the New Initial Set
				initial_state::ptr newState = initial_state::ptr(new initial_state(destination_locID, newShiftedPolytope));
				newState->setTransitionId(transition_id);// keeps track of the transition_ID
				res.push_back(newState);
			} //end of multiple intersected region with guard

		} //end of multiple transaction
	} //end-if of flowpipe computation not empty
	return res;

} //end of while loop checking waiting_list != empty

