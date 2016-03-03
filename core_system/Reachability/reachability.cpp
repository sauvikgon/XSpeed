#include "reachability.h"

using namespace std;

void reachability::setReachParameter(hybrid_automata& h, initial_state::ptr& i,
		ReachabilityParameters& reach_param, int bound_limit,
		unsigned int algorithm_type, unsigned int total_partition,
		int lp_solver_type, unsigned int streams_size,
		int solver_GLPK_Gurobi_for_GPU,
		std::set<std::pair<int, polytope::ptr> > forbidden) {
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
std::list<symbolic_states::ptr> reachability::computeSeqentialBFSReach(
		abstractCE::ptr& ce) {
	//	std::cout<<"Algorithm_Type = "<<Algorithm_Type<<std::endl;
	//std::list<template_polyhedra> Reachability_Region;

	std::list<symbolic_states::ptr> Reachability_Region;
	template_polyhedra::ptr reach_region;

	int number_times = 0, BreadthLevel = 0, previous_level = -1;
	std::list<int> queue; // data structure to keep track of the number of transitions
	discrete_set discrete_state;

	pwlist pw_list; //list of initial_state
	pw_list.WaitingList_insert(I);

	queue.push_back(BreadthLevel); //insert at REAR, first Location
	bool starting_location = true;
	bool saftey_violated = false;
	//	cout<<"\nTesting 2 a\n";
	polytope::ptr continuous_initial_polytope;

	while (!pw_list.isEmpty_WaitingList()) {
		//symbolic_states U;
		symbolic_states::ptr S = symbolic_states::ptr(new symbolic_states()); //required to be pushed into the Reachability_Region
		initial_state::ptr U;

		//		cout<<"\nTesting 2 a 1\n";
		U = pw_list.WaitingList_delete_front();
		int levelDeleted = queue.front(); //get FRONT element
		queue.pop_front(); //delete from FRONT
		if (levelDeleted > bound)
			break; //stopping due to number of transitions exceeds

		int location_id;
		//		cout<<"\nTesting 2 a 2\n";
		//discrete_state = U.getDiscreteSet();
		location_id = U->getLocationId();
		discrete_state.insert_element(location_id); //creating discrete_state

		//continuous_initial_polytope = U.getInitial_ContinousSetptr();
		continuous_initial_polytope = U->getInitialSet();
		reach_parameters.X0 = continuous_initial_polytope;

		S->setDiscreteSet(discrete_state);
		S->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
		S->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID

		//	cout<<"\nTesting 2 a 3\n";
		pw_list.PassedList_insert(U); // confirm from sir why do we need this (space issue)

		/*	We don't need this now
		 for (std::set<int>::iterator it =
		 discrete_state.getDiscreteElements().begin();
		 it != discrete_state.getDiscreteElements().end(); ++it)
		 location_id = (*it); //have to modify later for multiple elements of the set:: Now assumed only one element
		 */

		location::ptr current_location;

		current_location = H.getLocation(location_id);
		string name = current_location->getName();
		//cout << "\nLocation ID = "<<location_id<<", Location Name = " << name << "\n";
		if ((name.compare("GOOD") == 0) || (name.compare("BAD") == 0)
				|| (name.compare("UNSAFE") == 0)
				|| (name.compare("FINAL") == 0))
			continue; //do not compute the continuous reachability algorithm
		//TODO --stop-location locID to stop [now only input options to be created]
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
		 */
		//	GeneratePolytopePlotter(continuous_initial_polytope);
		/*
		 * Computation of compute_alfa depends on initial set. For algorithm PAR_BY_PARTS where the
		 * initial set in divided into parts. Compute_alfa should be computed for each initial sets.
		 * */
		//	cout<<"\nTesting 2 c\n";
		double result_alfa = compute_alfa(reach_parameters.time_step,
				current_location->getSystem_Dynamics(),
				continuous_initial_polytope, lp_solver_type_choosen); //2 glpk object created here

		//	cout << "\nReach_Parameters.time_step = " << reach_parameters.time_step << endl;
	//	cout << "\n1st Compute Alfa = " << result_alfa << endl;
		//	cout<<"\nTesting 2 c\n";
		double result_beta = compute_beta(current_location->getSystem_Dynamics(),
				reach_parameters.time_step, lp_solver_type_choosen); // NO glpk object created here
	//	cout << "\n1st Compute Beta = " << result_beta << endl;
		reach_parameters.result_alfa = result_alfa;
		reach_parameters.result_beta = result_beta;
		//	cout<<"\nTesting 2 d\n";
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
		//	for (int number_times = 1; number_times <= bound; number_times++) {	//Bound for loop in Hybrid AutomataGeneratePolytopePlotter(continuous_initial_polytope);
		//GeneratePolytopePlotter(continuous_initial_polytope);

		sequentialReachSelection(current_location, continuous_initial_polytope,reach_region);

		std::cout << "\nFlowpipe computed\n";

		//	*********************************************** Reach or Flowpipe Computed **************************************************************************
		if (previous_level != levelDeleted) {
			previous_level = levelDeleted;
			BreadthLevel++;
		}
		if (reach_region->getTotalIterations() != 0) {

			S->setContinuousSetptr(reach_region);

			Reachability_Region.push_back(S);
		}
		//  ******************************** Safety Verification section ********************************
		std::list<symbolic_states::ptr> list_sym_states;

		std::list<abstract_symbolic_state::ptr> list_abstract_sym_states;
		polytope::ptr Conti_Set; //bounding_box Polytope
		std::list<transition::ptr> list_transitions;

		if (reach_region->getTotalIterations() != 0) { //flowpipe exists
			//so perform intersection with forbidden set provided locID matches
			for (std::set<std::pair<int, polytope::ptr> >::iterator it =
					forbidden_set.begin(); it != forbidden_set.end(); it++) {
				int forbid_locID = current_location->getLocId();
				if (forbid_locID == (*it).first) { //forbidden locID matches
					polytope::ptr forbid_poly = (*it).second;
					std::list<template_polyhedra> forbid_intersects;
					forbid_intersects =
							reach_region->polys_intersectionSequential(
									forbid_poly, lp_solver_type_choosen);

					if (forbid_intersects.size() == 0) {
						std::cout
								<< "\nThe model does NOT violates SAFETY property!!!\n";
					} else {
						std::cout
								<< "\nThe model violates SAFETY property!!!\n";

						symbolic_states::ptr current_forbidden_state;
						current_forbidden_state = S;
						abstract_symbolic_state::ptr curr_abs_sym_state;
						curr_abs_sym_state = abstract_symbolic_state::ptr(
								new abstract_symbolic_state());

						std::cout << "\nReverse Path Trace =>\n";
						int cc = 0;
						do {
							int locationID, locationID2;
							discrete_set ds, ds2;
							ds = current_forbidden_state->getDiscreteSet();
							//insert discrete_set in the abstract_symbolic_state
							curr_abs_sym_state->setDiscreteSet(
									current_forbidden_state->getDiscreteSet());
							// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********
							Conti_Set =
									convertBounding_Box(
											current_forbidden_state->getContinuousSetptr());
							curr_abs_sym_state->setContinuousSet(Conti_Set);
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
							std::cout << "(" << locationID << ", " << transID
									<< ")";
							if (current_forbidden_state->getParentPtrSymbolicState() != NULL) { //searching only if not NULL
							//cout<<"check if parentPtr not NULL\n";
								current_forbidden_state =
										searchSymbolic_state(
												Reachability_Region,
												current_forbidden_state->getParentPtrSymbolicState()); //b)
								//2) ******************* list_transitions ********************
								ds2 = current_forbidden_state->getDiscreteSet(); //c)
								for (std::set<int>::iterator it =
										ds2.getDiscreteElements().begin();
										it != ds2.getDiscreteElements().end();
										++it)
									locationID2 = (*it); //c)

								location::ptr object_location;
								object_location = H.getLocation(locationID2); //d)
								/*std::list<transition::ptr> AllOutGoingTrans;
								 AllOutGoingTrans = object_location.getOut_Going_Transitions();*/
								transition::ptr temp =
										object_location->getTransition(transID); //e)
								list_transitions.push_front(temp); //pushing the transition in the stack
								//2) ******************* list_transitions Ends ********************
							}
							cc++;
						} while (current_forbidden_state->getParentPtrSymbolicState()
								!= NULL);

						if ((cc >= 1)
								&& (current_forbidden_state->getParentPtrSymbolicState()
										== NULL)) { //root is missed
							int locationID;
							discrete_set ds;
							ds = current_forbidden_state->getDiscreteSet();

							curr_abs_sym_state->setDiscreteSet(
									current_forbidden_state->getDiscreteSet());
							Conti_Set =
									convertBounding_Box(
											current_forbidden_state->getContinuousSetptr());
							curr_abs_sym_state->setContinuousSet(Conti_Set);

							for (std::set<int>::iterator it =
									ds.getDiscreteElements().begin();
									it != ds.getDiscreteElements().end(); ++it)
								locationID = (*it); //Assuming only a single element exist in the discrete_set

							int transID =
									current_forbidden_state->getTransitionId();

							list_sym_states.push_front(current_forbidden_state); //1) pushing the initial/root bad symbolic_state at the top
							list_abstract_sym_states.push_front(
									curr_abs_sym_state);
							std::cout << " -->  (" << locationID << ", "
									<< transID << ")\n";
						}
						saftey_violated = true;

						ce = abstractCE::ptr(new abstractCE());
						ce->set_length(cc);
						ce->set_sym_states(list_abstract_sym_states);
						//todo :: detected issue here with  "list_abstract_sym_states"
						/*for (std::list<abstract_symbolic_state::ptr>::iterator it = list_abstract_sym_states.begin();
						 it != list_abstract_sym_states.end(); it++) {
						 std::vector<double> bb;
						 bb = (*it)->getContinuousSet()->getColumnVector();
						 for (int i = 0; i < bb.size(); i++) {
						 cout << bb[i] << "\t";
						 }
						 }*/
						ce->set_transitions(list_transitions);
						break;
					}
				}
			} //end of all forbidden_state check
		} //computed flowpipe is not empty
		if (saftey_violated) {
			break; //no need to compute rest of the locations
		}
		//  ******************************** Safety Verification section Ends********************************

		//  ************** Check to see if Computed FlowPipe is Empty  **********
		if (reach_region->getTotalIterations() != 0 && BreadthLevel <= bound) { //computed reach_region is empty && optimize transition BreadthLevel-wise
		/*	polytope::ptr test = polytope::ptr(	new polytope(reach_region.getPolytope(61).getCoeffMatrix(),
		 reach_region.getPolytope(61).getColumnVector(), 1));
		 GeneratePolytopePlotter(test);	 */
			//	cout << "\nLoc ID = " << current_location.getLocId() << " Location Name = " << name << "\n";
			for (std::list<transition::ptr>::iterator t =
					current_location->getOut_Going_Transitions().begin();
					t != current_location->getOut_Going_Transitions().end();
					t++) { // get each destination_location_id and push into the pwl.waiting_list
				int transition_id = (*t)->getTransitionId();
				if (transition_id == -1) //Indicates empty transition or no transition exists
					break; //out from transition for-loop as there is no transition for this location
				location::ptr current_destination;
				Assign current_assignment;
				polytope::ptr gaurd_polytope;
				std::list<template_polyhedra> intersected_polyhedra;
				polytope::ptr intersectedRegion; //created two objects here
				discrete_set ds;

				//	std::cout<<"\nOut_Going_Transition's Destination_Location_ID = "<< (*t).getDestination_Location_Id()<<"\n";
				//	std::cout<<"\nOut_Going_Transition's Label = "<< (*t).getLabel()<<"\n";
				current_destination = H.getLocation(
						(*t)->getDestination_Location_Id());
				//				std::cout<<"\nTest location insde = "<<current_destination.getName()<<"\n";
				string locName = current_destination->getName();
				//cout << "\nNext Loc ID = " << current_destination.getLocId() << " Location Name = " << locName << "\n";
				if ((locName.compare("BAD") == 0)
						|| (locName.compare("GOOD") == 0)
						|| (locName.compare("FINAL") == 0)
						|| (locName.compare("UNSAFE") == 0))
					continue; //do not push into the waitingList

				gaurd_polytope = (*t)->getGaurd(); //	GeneratePolytopePlotter(gaurd_polytope);
				current_assignment = (*t)->getAssignT();

				//	std::cout << "Before calling Templet_polys\n";
				//cout<<reach_region.getMatrixSupportFunction().size2()<<"AmitJi\n";
				//this intersected_polyhedra will have invariant direction added in it
				string trans_name = (*t)->getLabel(); //	cout<<"Trans Name = "<<trans_name<<endl;

				boost::timer::cpu_timer t100;
				t100.start();
				//if (Algorithm_Type == 2) {
				if (0) {
					intersected_polyhedra =
							reach_region->polys_intersectionParallel(
									gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
				} else {
					intersected_polyhedra =
							reach_region->polys_intersectionSequential(
									gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
				}
				t100.stop();
				double clock100;
				clock100 = t100.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
				double return100 = clock100 / (double) 1000;
				std::cout << "\nIntersection Time:Wall(Seconds) = " << return100
						<< std::endl;

				// *** interesected_polyhedra included with invariant_directions also ******

				//	cout<<"size = "<< intersected_polyhedra.getMatrixSupportFunction().size1();
				//returns the list of polytopes that intersects with the gaurd_polytope
				//unsigned int iterations_before_intersection = intersection_start_point - 1;
				//Templet_polys.resize_matrix_SupportFunction(dir_nums, iterations_before_intersection);
				//			std::cout << "Before calling getTemplate_approx\n";
				int destination_locID = (*t)->getDestination_Location_Id();
				ds.insert_element(destination_locID);
				//std::cout<< "\nNumber of intersection with Flowpipe and guard = "<< intersected_polyhedra.size();
				for (std::list<template_polyhedra>::iterator i =
						intersected_polyhedra.begin();
						i != intersected_polyhedra.end(); i++) {
					intersectedRegion = (*i).getTemplate_approx(
							lp_solver_type_choosen);
					//Returns a single over-approximated polytope from the list of intersected polytopes
					//	GeneratePolytopePlotter(intersectedRegion);
					polytope::ptr newShiftedPolytope, newPolytope; //created an object here
					newPolytope = intersectedRegion->GetPolytope_Intersection(
							gaurd_polytope); //Retuns the intersected region as a single newpolytope. **** with added directions
					newShiftedPolytope = post_assign_exact(newPolytope,
							current_assignment.Map, current_assignment.b); //initial_polytope_I = post_assign_exact(newPolytope, R, w);
					//symbolic_states::ptr newState = symbolic_states::ptr( new symbolic_states(ds, newShiftedPolytope));

					//symbolic_states newState(ds, newShiftedPolytope);
					initial_state::ptr newState = initial_state::ptr(
							new initial_state(destination_locID,
									newShiftedPolytope));
					newState->setTransitionId(transition_id); // keeps track of the transition_ID
					newState->setParentPtrSymbolicState(S);

					pw_list.WaitingList_insert(newState);
					queue.push_back(BreadthLevel); //insert at REAR first Location
				} //end of multiple intersected region with guard
				  //	cout<<"Size = "<< pwlist.getWaitingList().size()<<endl;
			} //end of multiple transaction
		} //end-if of flowpipe computation not empty

	} //end of while loop checking waiting_list != empty
	return Reachability_Region;
}

void reachability::sequentialReachSelection(location::ptr current_location,
		polytope::ptr continuous_initial_polytope,
		template_polyhedra::ptr& reach_region) {

	if (Algorithm_Type == SEQ) { //Continuous Sequential Algorithm
		cout << "\nRunning Sequntial\n";
		//		std::cout<<"\nBefore entering reachability Sequential = " << gurobi_lp_solver::gurobi_lp_count;
		//		std::cout<<"\nBefore entering reachability Sequential = " << lp_solver::lp_solver_count;
//			int a;			std::cin>>a;
		boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();
		reach_region = reachabilitySequential(
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
	}

	if (Algorithm_Type == PAR_OMP) {
		//Parallel implementation using OMP parallel			//	double wall_timer = omp_get_wtime();
		//	cout << "\nRunning Parallel Using OMP Thread\n";
		boost::timer::cpu_timer AllReach_time;
		AllReach_time.start();
		reach_region = reachabilityParallel(
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

	if (Algorithm_Type == GPU_SF) { //computing all support function in GPU
		cout << "\nRunning GPU Sequential\n";
		boost::timer::cpu_timer AllReachGPU_time;
		AllReachGPU_time.start();

		reachabilitySequential_GPU(current_location->getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(),
				current_location->isInvariantExists(), lp_solver_type_choosen,
				number_of_streams, Solver_GLPK_Gurobi_GPU, reach_region);

		std::cout << "Out from GPU_reach\n";
		AllReachGPU_time.stop();
		double wall_clock1;
		wall_clock1 = AllReachGPU_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		double return_Time1 = wall_clock1 / (double) 1000;
		std::cout << "\nAllReach_time: Boost Time:Wall(Seconds) = "
				<< return_Time1 << std::endl;

	}

	if (Algorithm_Type == PAR_ITER) { //Continuous Parallel Algorithm parallelizing the Iterations :: to be debugged (compute initial polytope(s))
		cout
				<< "\nRunning Parallel-over-Iterations(PARTITIONS/Time-Sliced) Using OMP Thread\n";
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
			reach_region = reachParallelExplore(
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location->getInvariant(),
					current_location->isInvariantExists(), NCores, PAR_ITER,
					lp_solver_type_choosen);
			//		std::cout << "Finished computing reachable states\n";
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
			reach_region = reachParallelExplore(
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
		abstractCE::ptr& ce) {

	std::list<symbolic_states::ptr> Reachability_Region;
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
		//iter_max = iter_max + count;
		//	cout << "\nCount = " << count << "\n";
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

		//	omp_set_dynamic(0);	//handles dynamic adjustment of the number of threads within a team
		omp_set_nested(1); //enable nested parallelism
		//omp_set_num_threads(10);
		//omp_set_max_active_levels(2);
#pragma omp parallel for // num_threads(2)
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
					|| (name.compare("UNSAFE") == 0)
					|| (name.compare("FINAL") == 0))
				continue; //do not compute the continuous reachability algorithm

			// ******************* Computing Parameters *******************************
			//current_location:: parameters alfa, beta and phi_trans have to be re-computed
			//cout<<"\nBefore Compute Alfa";
			double result_alfa = compute_alfa(reach_parameter_local.time_step,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, lp_solver_type_choosen); //2 glpk object created here
			//cout<<"\nCompute Alfa Done";
			double result_beta = compute_beta(
					current_location->getSystem_Dynamics(),
					reach_parameter_local.time_step, lp_solver_type_choosen); // NO glpk object created here
			//			cout<<"\nCompute Beta Done";
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

			//  ********************* FlowPipe or Reach Computation *************************
			parallelReachSelection(current_location,
					continuous_initial_polytope, reach_parameter_local, S, id);
			// Returns the Flow_Pipe in reach_region_list[id]
			//  ********************* FlowPipe or Reach Computation Done ********************

			//  ************** Check to see if Computed FlowPipe is Empty  **********
			template_polyhedra::ptr t_poly = S[id]->getContinuousSetptr();

			if (t_poly->getTotalIterations() != 0 && number_times < bound) { //computed reach_region is empty && optimize computation
			//cout << "\nLoc ID = " << current_location.getLocId() << " Location Name = " << name << "\n";

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
					std::list<template_polyhedra> intersected_polyhedra;
					polytope::ptr intersectedRegion; //created two objects here
					discrete_set ds;
					current_destination = H.getLocation(
							(*t)->getDestination_Location_Id());
					string locName = current_destination->getName();
					//	cout << "\nNext Loc ID = " << current_destination.getLocId() << " Location Name = " << locName << "\n";

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
						//std::cout << "Before calling post_assign_exact\n";
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
		bool foundUnSafe = false;
		for (unsigned int index = 0; index < count; index++) {

			if (S[index]->getContinuousSetptr()->getTotalIterations() != 0) //computed reach_region is NOT empty
				Reachability_Region.push_back(S[index]);
			//  ******************************** Safety Verification section ********************************
			saftey_violated = safetyVerify(S[index], Reachability_Region, ce);
			if (saftey_violated) {
				foundUnSafe = true; //have to insert all flowpipe of same breadth even if foundUnSafe=true for some flowpipe, So not breaking
			}
			//  ******************************** Safety Verification section ********************************
		} //end-for pushing all computed flowpipe
		if (foundUnSafe) {
			break; //no need to compute rest of the locations
		}
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

//Lock Avoidance:: Parallel Breadth First Search for Discrete Jumps
//separate Read and Write Queue (pwlist.WaitingList)
std::list<symbolic_states::ptr> reachability::computeParallelBFSReachLockAvoid(
		abstractCE::ptr& ce) {

	std::list<symbolic_states::ptr> Reachability_Region;
	//	template_polyhedra::ptr reach_region;

	//Shared Read and Write Queue(pwList)
	int t = 0; //0 for Read and 1 for Write
	std::vector<std::vector<pwlist::ptr> > Qpw_list(2); // QpwList[0] for read and QpwList[1] for write
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
	while (!isEmpty_Qpw_list(Qpw_list[t])) {

		//To avoid write-contention for reach_region, Vector/List of reach_region_list created for each threads
		// write in its respective index. So need a unique ID for each thread which can be obtained from
		// the size of the PWList at each iteration
		//	cout << "Test 5\n";
		unsigned int count = getSize_Qpw_list(Qpw_list[t]); //get the size of PWList
		//iter_max = iter_max + count;
		//	cout << "\nCount = " << count << "\n";
		//vector<template_polyhedra::ptr> reach_region_list(count); //each thread write's flowpipe on separate index
		std::vector<symbolic_states::ptr> S(count);

		//Create a sublist of initial_state and work with it inside the parallel region(each thread accesses uniquely)
		//vector<symbolic_states> list_U(count); //SubList for parallel
		vector<initial_state::ptr> list_U(count); //SubList for parallel
		//	cout << "Test 6\n";
		list_U = getAllpw_list(Qpw_list[t], count, allPassedList); //All initial_state have been deleted
		//	cout<<"Identifed pwList Done\n";

		Qpw_list[1 - t].resize(count); //resize to accommodate
		for (int i = 0; i < count; i++) {
			Qpw_list[1 - t][i] = pwlist::ptr(new pwlist()); //have to instantiate it
		}
		// ********************************* BFS Starts **********************************************************
		//	cout << "Test 7\n";
		//	omp_set_dynamic(0);	//handles dynamic adjustment of the number of threads within a team
		omp_set_nested(1); //enable nested parallelism
		//omp_set_num_threads(10);
		//omp_set_max_active_levels(2);
#pragma omp parallel for // num_threads(2)
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
					|| (name.compare("UNSAFE") == 0)
					|| (name.compare("FINAL") == 0))
				continue; //do not compute the continuous reachability algorithm

			// ******************* Computing Parameters *******************************
			//current_location:: parameters alfa, beta and phi_trans have to be re-computed
			//cout<<"\nBefore Compute Alfa";
			double result_alfa = compute_alfa(reach_parameter_local.time_step,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, lp_solver_type_choosen); //2 glpk object created here
			//cout<<"\nCompute Alfa Done";
			double result_beta = compute_beta(
					current_location->getSystem_Dynamics(),
					reach_parameter_local.time_step, lp_solver_type_choosen); // NO glpk object created here
			//			cout<<"\nCompute Beta Done";
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

			//  ********************* FlowPipe or Reach Computation *************************
			parallelReachSelection(current_location,continuous_initial_polytope, reach_parameter_local, S, id);
			// Returns the Flow_Pipe in reach_region_list[id]
			//  ********************* FlowPipe or Reach Computation Done ********************

			//  ************** Check to see if Computed FlowPipe is Empty  **********
			template_polyhedra::ptr t_poly = S[id]->getContinuousSetptr();

			if (t_poly->getTotalIterations() != 0 && number_times < bound) { //computed reach_region is empty && optimize computation
			//cout << "\nLoc ID = " << current_location.getLocId() << " Location Name = " << name << "\n";
				for (std::list<transition::ptr>::iterator trans =
						current_location->getOut_Going_Transitions().begin();
						trans != current_location->getOut_Going_Transitions().end();
						trans++) { // get each destination_location_id and push into the pwl.waiting_list
					int transition_id = (*trans)->getTransitionId();
					if (transition_id == -1) { //Indicates empty transition or no transition exists
						break; //out from transition for-loop as there is no transition for this location
					}
					location::ptr current_destination;
					Assign current_assignment;
					polytope::ptr gaurd_polytope;
					std::list<template_polyhedra> intersected_polyhedra;
					polytope::ptr intersectedRegion; //created two objects here
					discrete_set ds;
					current_destination = H.getLocation(
							(*trans)->getDestination_Location_Id());
					string locName = current_destination->getName();
					//	cout << "\nNext Loc ID = " << current_destination.getLocId() << " Location Name = " << locName << "\n";

					gaurd_polytope = (*trans)->getGaurd();
					current_assignment = (*trans)->getAssignT();

					boost::timer::cpu_timer t100;
					//this intersected_polyhedra will have invariant direction added in it
					string trans_name = (*trans)->getLabel();
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
					int destination_locID =
							(*trans)->getDestination_Location_Id();
					ds.insert_element(destination_locID);
					for (std::list<template_polyhedra>::iterator it =
							intersected_polyhedra.begin();
							it != intersected_polyhedra.end(); it++) {
						//cout << "\nNumber of Intersections #1\n";
						intersectedRegion = (*it).getTemplate_approx(
								lp_solver_type_choosen);
						//Returns a single over-approximated polytope from the list of intersected polytopes
						polytope::ptr newShiftedPolytope, newPolytope; //created an object here
						newPolytope =
								intersectedRegion->GetPolytope_Intersection(
										gaurd_polytope); //Retuns only the intersected region as a single newpolytope. ****** with added directions
						//std::cout << "Before calling post_assign_exact\n";
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
							Qpw_list[1 - t][id]->WaitingList_insert(newState); //RACE CONDITION HERE

						}
					} //end of multiple intersected region with guard
					  //cout<<"Size = "<< pwlist.getWaitingList().size()<<endl;
				} //end of multiple transaction
				  //Here we have again populated the pwlist for next-round's parallel process
			} // End-if  ******* Check for Empty FlowPipe Done *********
		} //END of parallel FOR-LOOP
		t = 1 - t; //Switching Read/Write options for Qpw_list[1-t]
		//:: Can be optimize if we can count number_times inside the parallel loop per breadth then we can avoid transaction and intersection
		//:: computation for next transition if number_times exceeds bound ....
		number_times++; //One Level or one Breadth Search over
		//cout << "\nnumber_times = " << number_times << "  Bound = " << bound << "\n";
		// ************************* BFS Ends *************************************

		//Creating a list of objects of "Reachability Set"/Symbolic_states
		bool foundUnSafe = false;
		for (unsigned int index = 0; index < count; index++) {

			if (S[index]->getContinuousSetptr()->getTotalIterations() != 0) //computed reach_region is NOT empty
				Reachability_Region.push_back(S[index]);
			//  ******************************** Safety Verification section ********************************
			saftey_violated = safetyVerify(S[index], Reachability_Region, ce);
			if (saftey_violated) {
				foundUnSafe = true; //have to insert all flowpipe of same breadth even if foundUnSafe=true for some flowpipe, So not breaking
			}
			//  ******************************** Safety Verification section ********************************
		} //end-for pushing all computed flowpipe
		if (foundUnSafe) {
			break; //no need to compute rest of the locations
		}
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

/**
 * TODO: Have to optimize invariant_boundary_check() for support function computation
 */

void reachability::parallelReachSelection(location::ptr current_location,
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

		reach_region = reachabilitySequential(
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

		reach_region = reachabilityParallel(
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

	if (Algorithm_Type == GPU_SF) { //computing all support function in GPU
		cout << "\nRunning GPU Sequential\n";
		boost::timer::cpu_timer AllReachGPU_time;
		AllReachGPU_time.start();
		reachabilitySequential_GPU(current_location->getSystem_Dynamics(),
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
	}

	if (Algorithm_Type == PAR_ITER) { //Continuous Parallel Algorithm parallelizing the Iterations :: to be debugged (compute initial polytope(s))
		cout
				<< "\nRunning Parallel-over-Iterations(PARTITIONS/Time-Sliced) Using OMP Thread\n";
		bool invertible;
		if (!current_location->getSystem_Dynamics().isEmptyMatrixA) {
			math::matrix<double> A_inv(
					current_location->getSystem_Dynamics().MatrixA.size1(),
					current_location->getSystem_Dynamics().MatrixA.size2());
			invertible = current_location->getSystem_Dynamics().MatrixA.inverse(A_inv); //size of A_inv must be declared else error
			if (!invertible)
				std::cout << "\nDynamics Matrix A is not invertible\n"; //later can give option to stop or select different algorithm
			else
				reach_parameters.A_inv = A_inv;
			int NCores = Total_Partition; //Number of Partitions (number of threads)
			reach_region = reachParallelExplore(
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location->getInvariant(),
					current_location->isInvariantExists(), NCores, PAR_ITER,
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
			reach_region = reachParallelExplore(
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
std::list<symbolic_states::ptr> reachability::computeParallelLoadBalanceReach(
		abstractCE::ptr& ce) {

	std::list<symbolic_states::ptr> Reachability_Region; //	template_polyhedra::ptr reach_region;
	int t = 0; //0 for Read and 1 for Write
	std::vector<std::vector<pwlist::ptr> > Qpw_list(2); // QpwList[0] for read and QpwList[1] for write 	//cout << "Test 1\n";
	Qpw_list[t].resize(1); //resize for the first symbolic_state 	//cout << "Test 2\n";
	Qpw_list[t][0] = pwlist::ptr(new pwlist()); //have to instantiate it
	Qpw_list[t][0]->WaitingList_insert(I); //cout << "Test 3\n";
	pwlist::ptr allPassedList; //so we create a permanent pwlist for storing only the passedList;
	allPassedList = pwlist::ptr(new pwlist()); //have to instantiate it
	int number_times = 0;
	unsigned int iter_max = 1;
	bool saftey_violated = false; //cout << "Test 4\n";
	while (!isEmpty_Qpw_list(Qpw_list[t])) { //	cout << "Test 5\n";
		unsigned int count = getSize_Qpw_list(Qpw_list[t]); //get the size of PWList
	//	cout << "\nCount = " << count << "\n";
		std::vector<symbolic_states::ptr> S(count);
		vector<initial_state::ptr> list_U(count); //SubList for parallel		//	cout << "Test 6\n";
		list_U = getAllpw_list(Qpw_list[t], count, allPassedList); //All initial_state have been deleted //cout<<"Identifed pwList Done\n";
		//cout<<"list_U = "<<list_U.size();
		Qpw_list[1 - t].resize(count); //resize to accommodate
		for (int i = 0; i < count; i++) {
			Qpw_list[1 - t][i] = pwlist::ptr(new pwlist()); //have to instantiate it
		}
		// ********************************* BFS Starts **********************************************************
	//	cout << "Test 7\n";
// ***************** DIRECTION and BIG_Task CREATION:: per breadth-level *****************

		std::vector<LoadBalanceData> LoadBalanceDS(count);
// ***************** DIRECTION and BIG_Task CREATION *****************
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
					|| (name.compare("UNSAFE") == 0)
					|| (name.compare("FINAL") == 0))
				continue; //do not compute the continuous reachability algorithm
			// ******************* Computing Parameters ************************ //current_location:: parameters alfa, beta and phi_trans
			//cout<<"\nBefore Compute Alfa";
			double result_alfa = compute_alfa(reach_parameter_local.time_step,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, lp_solver_type_choosen); //cout<<"\nCompute Alfa Done";
			cout<<"\nCompute alfa  = " << result_alfa;
			double result_beta = compute_beta(
					current_location->getSystem_Dynamics(),
					reach_parameter_local.time_step, lp_solver_type_choosen); // NO glpk object created here
			cout<<"\nCompute Beta  = " << result_beta;
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
// *************** POST_C computation ********** in 3 steps ***************
			bool U_empty = false;
			if (current_location->getSystem_Dynamics().U->getIsEmpty()) { //polytope U can be empty set
				U_empty = true;
			}
			math::matrix<float> listX0, listU;
			unsigned int newIteration; //required in substitute_in_ReachAlgorithm(...)
	//		cout << "Test 8\n";
			preLoadBalanceReachCompute(reach_parameter_local,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope,
					current_location->getInvariant(),
					current_location->isInvariantExists(), listX0, listU,
					newIteration); // Step 1
		//	cout << "Test 9\n";
			LoadBalanceDS[id].List_dir_X0 = listX0;
			LoadBalanceDS[id].List_dir_U = listU;
			LoadBalanceDS[id].X0 = continuous_initial_polytope;
			LoadBalanceDS[id].U = current_location->getSystem_Dynamics().U;
			LoadBalanceDS[id].current_location = current_location;
			LoadBalanceDS[id].symState_ID = id;
			LoadBalanceDS[id].newIteration = newIteration;
			LoadBalanceDS[id].reach_param = reach_parameter_local;
		} //END of count FOR-LOOP
	//	cout << "Test 10\n";
	//	cout<<"LoadBalanceDS size = "<<LoadBalanceDS.size()<<"\n";
		computeBIG_Task(LoadBalanceDS);	// Step 2
	//	cout << "Test 11\n";
		for (unsigned int id = 0; id < count; id++) {
			template_polyhedra::ptr reach_region;
			reach_region = substitute_in_ReachAlgorithm(LoadBalanceDS[id]);	// Step 3
			S[id]->setContinuousSetptr(reach_region);
		}
//  ********************* POST_C computation Done ********************

//#pragma omp parallel for
		for (unsigned int id = 0; id < count; id++) {
//  ************************************** POST_D computation Begins **********************************************************
			template_polyhedra::ptr t_poly = S[id]->getContinuousSetptr();
			if (t_poly->getTotalIterations() != 0 && number_times < bound) { //computed reach_region is empty && optimize computation
			//cout << "\nLoc ID = " << current_location.getLocId() << " Location Name = " << name << "\n";
				for (std::list<transition::ptr>::iterator trans =
						LoadBalanceDS[id].current_location->getOut_Going_Transitions().begin();
						trans
								!= LoadBalanceDS[id].current_location->getOut_Going_Transitions().end();
						trans++) { // get each destination_location_id and push into the pwl.waiting_list
					int transition_id = (*trans)->getTransitionId();
					if (transition_id == -1) { //Indicates empty transition or no transition exists
						break; //out from transition for-loop as there is no transition for this location
					}
					location::ptr current_destination;
					Assign current_assignment;
					polytope::ptr gaurd_polytope;
					std::list<template_polyhedra> intersected_polyhedra;
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
					//	intersected_polyhedra = t_poly->polys_intersectionParallel(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
					t100.start();
					intersected_polyhedra =
							t_poly->polys_intersectionSequential(gaurd_polytope,
									lp_solver_type_choosen); //, intersection_start_point);
					t100.stop();
					if (intersected_polyhedra.size() > 0) { //there is intersection so new symbolic state will be inserted into the waitingList
						//std::cout << "Intersected = " < intersected_polyhedra.size() << std::endl;
//#pragma omp critical	{
						iter_max++; //	}
					}
					//todo Handle this later as In SpaceEx model we did not specified BAD or GOOD
					if ((locName.compare("BAD") == 0)
							|| (locName.compare("GOOD") == 0)
							|| (locName.compare("FINAL") == 0)
							|| (locName.compare("UNSAFE") == 0)) {
						continue; //do not push into the waitingList
					} //	std::cout << "Before calling getTemplate_approx\n";
					double clock100;
					clock100 = t100.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
					double return100 = clock100 / (double) 1000;
					std::cout << "\nIntersection Time:Wall(Seconds) = "
							<< return100 << std::endl;
					int destination_locID =
							(*trans)->getDestination_Location_Id();
					ds.insert_element(destination_locID);
					for (std::list<template_polyhedra>::iterator it =
							intersected_polyhedra.begin();
							it != intersected_polyhedra.end(); it++) {
						//cout << "\nNumber of Intersections #1\n";
						intersectedRegion = (*it).getTemplate_approx(
								lp_solver_type_choosen);
						//Returns a single over-approximated polytope from the list of intersected polytopes
						polytope::ptr newShiftedPolytope, newPolytope; //created an object here
						newPolytope =
								intersectedRegion->GetPolytope_Intersection(
										gaurd_polytope); //Retuns only the intersected region as a single newpolytope. ****** with added directions
						//std::cout << "Before calling post_assign_exact\n";
						newShiftedPolytope = post_assign_exact(newPolytope,
								current_assignment.Map, current_assignment.b); //initial_polytope_I = post_assign_exact(newPolytope, R, w);
						initial_state::ptr newState = initial_state::ptr(
								new initial_state(destination_locID,
										newShiftedPolytope));
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
					  //cout<<"Size = "<< pwlist.getWaitingList().size()<<endl;
				} //end of multiple transaction
				  //Here we have again populated the pwlist for next-round's parallel process
			} // End-if
//  ************************************** POST_D computation Ends **********************************************************
		}	//parallel for-loop

		t = 1 - t; //Switching Read/Write options for Qpw_list[1-t]
		number_times++; //One Level or one Breadth Search over
		//cout << "\nnumber_times = " << number_times << "  Bound = " << bound << "\n";
		// ************************* BFS Ends *************************************
		bool foundUnSafe = false;
		for (unsigned int index = 0; index < count; index++) {
			if (S[index]->getContinuousSetptr()->getTotalIterations() != 0) //computed reach_region is NOT empty
				Reachability_Region.push_back(S[index]);
			//  ************************* Safety Verification Begins *****************
			saftey_violated = safetyVerify(S[index], Reachability_Region, ce);
			if (saftey_violated) {
				foundUnSafe = true; //have to insert all flowpipe of same breadth even if foundUnSafe=true for some flowpipe, So not breaking
			}
			//  ************************* Safety Verification Ends *******************
		} //end-for pushing all computed flowpipe
		if (foundUnSafe) {
			break; //no need to compute rest of the locations
		}
		if (number_times > bound) //check to see how many jumps have been made(i.e., number of discrete transitions made)
			break;
	} //end of while loop checking waiting_list != empty
	cout << "\n **********************************************************\n";
	cout << "   *** Maximum Iterations Completed = " << iter_max << "  ***\n";
	cout << "\n **********************************************************\n";

	return Reachability_Region;
}

bool reachability::safetyVerify(symbolic_states::ptr& computedSymStates,
		std::list<symbolic_states::ptr>& Reachability_Region,
		abstractCE::ptr& ce) {

	std::list<symbolic_states::ptr> list_sym_states;
	std::list<abstract_symbolic_state::ptr> list_abstract_sym_states;
	polytope::ptr Conti_Set; //bounding_box Polytope
	bool saftey_violated = false;
	std::list<transition::ptr> list_transitions;

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

		for (std::set<std::pair<int, polytope::ptr> >::iterator it =
				forbidden_set.begin(); it != forbidden_set.end(); it++) {
			//int forbid_locID = current_location.getLocId();
			int forbid_locID = locID;
			if (forbid_locID == (*it).first) { //forbidden locID matches
				polytope::ptr forbid_poly = (*it).second;
				//check intersection with flowpipe/reach_region
				//GeneratePolytopePlotter(forbid_poly);
				std::list<template_polyhedra> forbid_intersects;
				//forbid_intersects = computedSymStates->getContinuousSetptr()->polys_intersectionParallel(forbid_poly, lp_solver_type_choosen);

				forbid_intersects =
						computedSymStates->getContinuousSetptr()->polys_intersectionSequential(
								forbid_poly, lp_solver_type_choosen); //TODO:: CHECK RUNNING BOTH PARALLEL AND SEQUENTIAL

				if (forbid_intersects.size() == 0) {
					std::cout
							<< "\nThe model does NOT violates SAFETY property!!!\n";
				} else {
					std::cout << "\nThe model violates SAFETY property!!!\n";
					symbolic_states::ptr current_forbidden_state;
					current_forbidden_state = computedSymStates;

					// Here create a new abstract_symbolic_state
					abstract_symbolic_state::ptr curr_abs_sym_state;
					curr_abs_sym_state = abstract_symbolic_state::ptr(
							new abstract_symbolic_state());

					std::cout << "\nReverse Path Trace =>\n";
					int cc = 0;
					do {
						int locationID, locationID2;
						discrete_set ds, ds2;
						ds = current_forbidden_state->getDiscreteSet();

						//insert discrete_set in the abstract_symbolic_state
						curr_abs_sym_state->setDiscreteSet(
								current_forbidden_state->getDiscreteSet());

						// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********

						Conti_Set = convertBounding_Box(
								current_forbidden_state->getContinuousSetptr());
						curr_abs_sym_state->setContinuousSet(Conti_Set);
						// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********

						for (std::set<int>::iterator it =
								ds.getDiscreteElements().begin();
								it != ds.getDiscreteElements().end(); ++it)
							locationID = (*it); //Assuming only a single element exist in the discrete_set

						int transID =
								current_forbidden_state->getTransitionId(); //a)
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
						std::cout << "(" << locationID << ", " << transID
								<< ")";
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
						transition::ptr temp = object_location->getTransition(transID); //e)
						list_transitions.push_front(temp); //pushing the transition in the stack
						//2) ******************* list_transitions Ends ********************
						cc++;
					} while (current_forbidden_state->getParentPtrSymbolicState()
							!= NULL);

					if ((cc >= 1)
							&& (current_forbidden_state->getParentPtrSymbolicState()
									== NULL)) { //root is missed
						int locationID;
						discrete_set ds;
						ds = current_forbidden_state->getDiscreteSet();

						curr_abs_sym_state->setDiscreteSet(
								current_forbidden_state->getDiscreteSet());
						Conti_Set = convertBounding_Box(
								current_forbidden_state->getContinuousSetptr());
						curr_abs_sym_state->setContinuousSet(Conti_Set);

						for (std::set<int>::iterator it =
								ds.getDiscreteElements().begin();
								it != ds.getDiscreteElements().end(); ++it)
							locationID = (*it); //Assuming only a single element exist in the discrete_set

						int transID =
								current_forbidden_state->getTransitionId();
						list_sym_states.push_front(current_forbidden_state); //1) pushing the initial/root bad symbolic_state at the top
						list_abstract_sym_states.push_front(curr_abs_sym_state);

						std::cout << " -->  (" << locationID << ", " << transID
								<< ")\n";
					}
					saftey_violated = true;
					ce = abstractCE::ptr(new abstractCE());
					ce->set_length(cc);
					//ce->set_sym_states(list_sym_states);
					ce->set_sym_states(list_abstract_sym_states);
					ce->set_transitions(list_transitions);
					break;
				}
			}
		} //end of all forbidden_state check
	} //computed flowpipe is not empty
	return saftey_violated;
}

void reachability::preLoadBalanceReachCompute(ReachabilityParameters& ReachParameters, Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial, polytope::ptr invariant, bool isInvariantExist, math::matrix<float>& List_dir_X0,
		math::matrix<float>& List_dir_U, unsigned int& newIteration) {

	unsigned int NewTotalIteration = ReachParameters.Iterations;
	//cout <<"Before NewTotalIteration = " <<NewTotalIteration<<"\n";
	bool U_empty = false;
	if (isInvariantExist == true) { //if invariant exist. Computing
		NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial, ReachParameters, invariant, lp_solver_type_choosen);
		//std::cout << "NewTotalIteration = " << NewTotalIteration << std::endl;
	} //End of Invariant Directions
	newIteration = NewTotalIteration;
	if (NewTotalIteration <= 1) {
		return;
	}
	if (SystemDynamics.U->getIsEmpty()) { //polytope U can be empty set
		U_empty = true;
	}
	int Solver = Solver_GLPK_Gurobi_GPU; //1 for CPU solver(GLPK); //2 for CPU solver(Gurobi); //3 for GPU solver(Gimplex)
//  ************* Generation of Directions Begins ***************
	unsigned int numVectors = ReachParameters.Directions.size1();
	unsigned int totalDirList1 = numVectors * (NewTotalIteration + 1); //1 extra for loop1
	math::matrix<float> List_for_X0(totalDirList1,
			ReachParameters.Directions.size2());
	unsigned int totalDirList2 = numVectors * NewTotalIteration; //'n' dirs for each 'n' loops
	math::matrix<float> List_for_U(totalDirList2,
			ReachParameters.Directions.size2());
	/*std::cout << "\nNumber of Directions/LPs for X0 = " << totalDirList1;
	 if (!U_empty) {
	 std::cout << "\nNumber of Directions/LPs for U = " << totalDirList2;
	 }*/

	boost::timer::cpu_timer DirectionsGenerate_time;
	DirectionsGenerate_time.start();
	getDirectionList_X0_and_U(ReachParameters, NewTotalIteration, List_for_X0,
			List_for_U, U_empty, SystemDynamics); //Optimized into a single function the 2 Tasks
	DirectionsGenerate_time.stop();
	double wall_clock1;
	wall_clock1 = DirectionsGenerate_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double return_Time1 = wall_clock1 / (double) 1000;
	std::cout<< "\nDirections Generation(parallel): Boost Time taken:Wall  (in Seconds) = "<< return_Time1 << std::endl;
//  ************* Generation of Directions Ends ***************
	List_for_X0.matrix_copy(List_dir_X0);
	List_for_U.matrix_copy(List_dir_U);
}

void reachability::computeBIG_Task(
		std::vector<LoadBalanceData>& LoadBalanceDS) {
	for (int i = 0; i < LoadBalanceDS.size(); i++) { //for each symbolic-states
		assert(i==LoadBalanceDS[i].symState_ID);
		int dimension = LoadBalanceDS[i].List_dir_X0.size2();
		lp_solver lp(this->lp_solver_type_choosen), lp_U(this->lp_solver_type_choosen);
		lp.setMin_Or_Max(2);	//2 for Maximization
		//cout << "Testing A1\n";
		lp.setConstraints(LoadBalanceDS[i].reach_param.X0->getCoeffMatrix(),LoadBalanceDS[i].reach_param.X0->getColumnVector(),LoadBalanceDS[i].reach_param.X0->getInEqualitySign());
		//cout << "Testing A2\n";
		lp_U.setMin_Or_Max(2);
		bool U_empty;
		U_empty = LoadBalanceDS[i].current_location->getSystem_Dynamics().U->getIsEmpty();
		if (!U_empty) {
			LoadBalanceDS[i].sf_U.resize(LoadBalanceDS[i].List_dir_U.size1());
			lp_U.setConstraints(LoadBalanceDS[i].U->getCoeffMatrix(),LoadBalanceDS[i].U->getColumnVector(),LoadBalanceDS[i].U->getInEqualitySign());
			for (unsigned int j = 0; j < LoadBalanceDS[i].List_dir_U.size1();
					j++) {//for all directions ** Can be done in loop **** A ******
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
		LoadBalanceDS[i].sf_dotProduct.resize(LoadBalanceDS[i].List_dir_X0.size1());
		LoadBalanceDS[i].sf_UnitBall.resize(LoadBalanceDS[i].List_dir_X0.size1());
//#pragma omp parallel for
		for (unsigned int j = 0; j < LoadBalanceDS[i].List_dir_X0.size1(); j++) {	//for all directions  ****** A ******
			std::vector<double> dirs(dimension);
			for (int index = 0; index < dimension; index++) {
				dirs[index] = LoadBalanceDS[i].List_dir_X0(j, index);
			}
			//cout << "Testing A4\n";
			LoadBalanceDS[i].sf_X0[j] = lp.Compute_LLP(dirs);
			//cout << "Testing A5\n";
			// ******DotProduction and Support Function of UnitBall  *******
			LoadBalanceDS[i].sf_dotProduct[j] = dot_product(LoadBalanceDS[i].current_location->getSystem_Dynamics().C,dirs);
			LoadBalanceDS[i].sf_UnitBall[j] = support_unitball_infnorm(dirs);
		}
	}	//end-for each symbolic-states
}

template_polyhedra::ptr reachability::substitute_in_ReachAlgorithm(
		LoadBalanceData& LoadBalanceDS) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	template_polyhedra::ptr reachableRegion;//template_polyhedra::ptr reachRegion;

	//std::cout << "\n Running BIG_Task Reach Algorithm " << std::endl;

	boost::timer::cpu_timer reachLoop_time;
	reachLoop_time.start();
	unsigned int numVectors = LoadBalanceDS.reach_param.Directions.size1();	//size2 or the dimension will be some for all sym_state
	int num_inv = LoadBalanceDS.current_location->getInvariant()->getColumnVector().size(); //number of Invariant's constriants
	math::matrix<double> inv_directions;
	inv_directions = LoadBalanceDS.current_location->getInvariant()->getCoeffMatrix();
	std::vector<double> inv_bounds(num_inv);
	inv_bounds = LoadBalanceDS.current_location->getInvariant()->getColumnVector();

	if (LoadBalanceDS.newIteration <= 1) {
		template_polyhedra::ptr poly_emptyp;
		return poly_emptyp;
	}
	int dimension = LoadBalanceDS.X0->getSystemDimension();
	int Min_Or_Max = 2;
	size_type row = numVectors, col = LoadBalanceDS.newIteration;
	math::matrix<double> MatrixValue(row, col);

//#pragma omp parallel for
	for (unsigned int eachDirection = 0; eachDirection < numVectors;
			eachDirection++) {
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
/*
			if (loopIteration == 1) {
				term3b = (double) LoadBalanceDS.sf_UnitBall[index_X0 - 2]; //Compute here		//needed 1
				if (!LoadBalanceDS.current_location->getSystem_Dynamics().isEmptyC) {
					term3c = LoadBalanceDS.reach_param.time_step * LoadBalanceDS.sf_dotProduct[index_X0 - 2];
				}
			} else {
				term3b = (double) LoadBalanceDS.sf_UnitBall[index_X0 - 1];
				if (!LoadBalanceDS.current_location->getSystem_Dynamics().isEmptyC) {
					term3c = LoadBalanceDS.reach_param.time_step * LoadBalanceDS.sf_dotProduct[index_X0 - 1];
				}
			}
*/
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
	reachLoop_time.stop();
	double wall_clock;
	wall_clock = reachLoop_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	double reach_Time = wall_clock / (double) 1000;
	std::cout << "\nFinal Reach Loop Time:Wall  (in Seconds) = " << reach_Time << std::endl;

	//std::cout<<"working 2ab"<<std::endl;
	if (LoadBalanceDS.current_location->isInvariantExists() == true) { //if invariant exist. Computing
		//std::cout<<"Invariant Exists Test inside 1a\n";
		math::matrix<double> inv_sfm;
//		std::cout<<"num_inv = "<<num_inv <<"\n";
//		std::cout<<"working"<<std::endl;
		inv_sfm.resize(num_inv, LoadBalanceDS.newIteration);
		for (int eachInvDirection = 0; eachInvDirection < num_inv; eachInvDirection++) {
			//std::cout<<"working"<<std::endl;
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
	return reachableRegion;

}
