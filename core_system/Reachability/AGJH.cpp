/*
 * AGJH.cpp
 *
 *  Created on: 28-Oct-2016
 *      Author: amit
 */

#include "AGJH.h"
#include "Utilities/flowpipe_cluster.h"

// Holzmann algorithm adaption
std::list<symbolic_states::ptr> agjh::ParallelBFS_GH(std::list<abstractCE::ptr>& ce_candidates){
	std::list < symbolic_states::ptr > Reachability_Region; //	template_polyhedra::ptr reach_region;
	int t = 0; //0 for Read and 1 for Write
	unsigned int N = omp_get_num_procs(); //get the number of cores // Number of cores in the machine
	//std::cout<<"Number of Cores = "<<N<<std::endl;
	std::list<initial_state::ptr> Wlist[2][N][N];
	for(unsigned int i=0;i<2;i++){
		for(unsigned int j=0;j<N;j++){
			for(unsigned int k=0;k<N;k++){
				std::list<initial_state::ptr> l;
				Wlist[i][j][k] = l;
			}
		}
	}
	int initialState_index = 0; // first initial state
	for (std::list<initial_state::ptr>::iterator i = I.begin(); i != I.end(); i++) {

		Wlist[t][initialState_index][0].push_back(*(i));

		initialState_index++; //next initial state
	}	//Wlist[t][0][0].push_back(this->I); //old implementation


	std::list<symbolic_states::ptr> PASSED;
	unsigned int level = 0;
	bool done, safetyViolated=false;
	//srand(time(NULL));

	int waiting_count=0;	//number of waiting symbolic state
	unsigned int passed_count=0; //total number of passed list
	//cout << "\nNumber of Flowpipes to be Computed (per Breadths) = " << count<< "\n";

	do {
		boost::timer::cpu_timer jump_time;
		jump_time.start();	//Start recording the entire time for jump
		done = true;
#pragma omp parallel for
		for(unsigned int i=0;i<N;i++){
			for(unsigned int q=0;q<N;q++){
				for(std::list<initial_state::ptr>::iterator it = Wlist[t][i][q].begin(); it!=Wlist[t][i][q].end();it++){
					initial_state::ptr s = (*it);
					template_polyhedra::ptr R;

					symbolic_states::ptr R1 = symbolic_states::ptr(new symbolic_states());

					discrete_set discrete_state;
					discrete_state.insert_element(s->getLocationId()); //creating discrete_state
					R1->setDiscreteSet(discrete_state);
					R1->setInitialPolytope(s->getInitialSet());
					R1->setTransitionId(s->getTransitionId()); //keeps track of originating transition_ID

					R = postC(s);

					R1->setParentPtrSymbolicState(s->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states

					R1->setContinuousSetptr(R);
					discrete_set d;
					d.insert_element(s->getLocationId());
					R1->setDiscreteSet(d);
#pragma omp critical
				{
					PASSED.push_back(R1);
					passed_count = passed_count + 1;
				}
					//----end of postC on s


				//Currently removed the Safety Check Section from here

				//  ******************************** Safety Verification section ********************************
//				safetyViolated = checkSafety(R, s, R1, ce_candidates); //R, s, R1 are all local variables per thread
				//  ******************************** Safety Verification section ********************************
				
					std::list<initial_state::ptr> R2;
					if (level < bound){	//Check level to avoid last PostD computation
					//	std::cout<<"Before PostD called\n";
						R2 = postD(R1, PASSED, safetyViolated);
						//--------New Safety Check for Arch-Competition
						if (safetyViolated){//Safety Violated For Motorcade-5 and Fisher_star model
							#pragma omp critical
							{
								done=true;
							}
							break; //no need to compute rest of the locations
						}
						//--------
#pragma omp critical
					{
						waiting_count = waiting_count + R2.size();
					}
						//cout <<"postD size = " <<R2.size()<<std::endl;
						std::vector<int> ArrCores(N);	//If this is done only once outside time saved but race-condition?
						for (unsigned int id=0;id<N;id++){
							ArrCores[id] = id;	//sequential insertion into the array
						}
						unsigned int startVal=0;
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
				}//for-loop no 3
					Wlist[t][i][q].clear();
					if (safetyViolated){	//Safety Violated For Motorcade-5 and Fisher_star model
						#pragma omp critical
						{
							done=true;
						}
					}

			}//for-loop no 2
			if (safetyViolated){	//Safety Violated For Motorcade-5 and Fisher_star model
				#pragma omp critical
				{
					done=true;
				}
			}
		}//for-loop no 1

		// barrier synchronization
		if (!safetyViolated){	//Safety Violated For Motorcade-5 and Fisher_star model
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
		}
		level++;
		t = 1 - t;

		jump_time.stop();
		/*
		 * Stop recording the entire time for the jump/iteration
		 * This time include time taken for flowpipe computation, "safety verification", postD computation and containment check
		*/
		double wall_clock;
		wall_clock = jump_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		wall_clock = wall_clock / (double) 1000;	//convert milliseconds to seconds

		std::cout << "\nJump " << level - 1 << "..."<< passed_count<< " Symbolic States Passed, " << waiting_count << " waiting ..."<< wall_clock <<" seconds";
		waiting_count = 0; //reset to 0 for next level waiting list

	}while(level<=bound && !done);

	if (level <= bound) {	//did not reach to the assigned bound
		std::cout << "\n\nFound Fix-point after " << level - 1 << " Jumps!!!\n";
	}
cout<<"\n******************************************************************\n";
cout <<"Maximum number of Symbolic states Passed = " <<passed_count<<"\n";
cout<<"******************************************************************\n";
	return PASSED;

}

//Adapted Holzmann Algorithm with separate  postC and postD from the containment check to avoid locking on passed list
std::list<symbolic_states::ptr> agjh::AGJH(std::list<abstractCE::ptr>& ce_candidates){
	std::list < symbolic_states::ptr > Reachability_Region; //	template_polyhedra::ptr reach_region;
	int t = 0; //0 for Read and 1 for Write
	unsigned int N = omp_get_num_procs(); //get the number of cores // Number of cores in the machine
	//std::cout<<"Number of Cores = "<<N<<std::endl;
	std::list<initial_state::ptr> Wlist[2][N][N];
	for(unsigned int i=0;i<2;i++){
		for(unsigned int j=0;j<N;j++){
			for(unsigned int k=0;k<N;k++){
				std::list<initial_state::ptr> l;
				Wlist[i][j][k] = l;
			}
		}
	}
	int initialState_index = 0; // first initial state
	for (std::list<initial_state::ptr>::iterator i = I.begin(); i != I.end(); i++) {

		Wlist[t][initialState_index][0].push_back(*(i));

		initialState_index++; //next initial state
	}	//Wlist[t][0][0].push_back(this->I); //old implementation


	std::list<symbolic_states::ptr> PASSED;
	unsigned int level = 0;
	bool done, safetyViolated=false;
	//srand(time(NULL));

	int waiting_count=0;	//number of waiting symbolic state
	unsigned int passed_count=0; //total number of passed list
	//cout << "\nNumber of Flowpipes to be Computed (per Breadths) = " << count<< "\n";

	do {
		boost::timer::cpu_timer jump_time;
		jump_time.start();	//Start recording the entire time for jump
		done = true;
		std::list<symbolic_states::ptr> R1PerBreadth[N][N];	//shared per breadth
#pragma omp parallel for
		for(unsigned int i=0;i<N;i++){
			for(unsigned int q=0;q<N;q++){
				for(std::list<initial_state::ptr>::iterator it = Wlist[t][i][q].begin(); it!=Wlist[t][i][q].end();it++){
					initial_state::ptr s = (*it);
					template_polyhedra::ptr R;

					symbolic_states::ptr R1 = symbolic_states::ptr(new symbolic_states());

					discrete_set discrete_state;
					discrete_state.insert_element(s->getLocationId()); //creating discrete_state
					R1->setDiscreteSet(discrete_state);
					R1->setInitialPolytope(s->getInitialSet());
					R1->setTransitionId(s->getTransitionId()); //keeps track of originating transition_ID

					R = postC(s);

					R1->setParentPtrSymbolicState(s->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states

					R1->setContinuousSetptr(R);
					discrete_set d;
					d.insert_element(s->getLocationId());
					R1->setDiscreteSet(d);
					R1PerBreadth[i][q].push_back(R1); //contention free
//#pragma omp critical
//				{
				//	PASSED.push_back(R1); // this loop can be outside to avoid lock using sequential push from R1PerBreadth
				//	passed_count = passed_count + 1;
//				}
					//----end of postC on s
				//Currently removed the Safety Check Section from here

				//  ******************************** Safety Verification section ********************************
//				safetyViolated = checkSafety(R, s, R1, ce_candidates); //R, s, R1 are all local variables per thread
				//  ******************************** Safety Verification section ********************************
				}
				Wlist[t][i][q].clear();
			}
		}
//Sequential to avoid locking on passed list
		for(unsigned int i=0;i<N;i++){
			for(unsigned int q=0;q<N;q++){
				for(std::list<symbolic_states::ptr>::iterator it = R1PerBreadth[i][q].begin(); it!=R1PerBreadth[i][q].end();it++){
						symbolic_states::ptr R1 = (*it);
					PASSED.push_back(R1);
					passed_count = passed_count + 1;
				}
			}
		}

#pragma omp parallel for
		for(unsigned int i=0;i<N;i++){
			for(unsigned int q=0;q<N;q++){
				std::list<initial_state::ptr> R2;
				if (level < bound){	//Check level to avoid last PostD computation
				//	std::cout<<"Before PostD called\n";
					for(std::list<symbolic_states::ptr>::iterator it = R1PerBreadth[i][q].begin(); it!=R1PerBreadth[i][q].end();it++){
						symbolic_states::ptr R1 = (*it);
						R2 = postD(R1, PASSED, safetyViolated);
						#pragma omp critical
						{
							waiting_count = waiting_count + R2.size();
						}
						//cout <<"postD size = " <<R2.size()<<std::endl;
						std::vector<int> ArrCores(N);	//If this is done only once outside time saved but race-condition?
						for (unsigned int id=0;id<N;id++){
							ArrCores[id] = id;	//sequential insertion into the array
						}
						unsigned int startVal=0;
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
					R1PerBreadth[i][q].clear();
				}//for-loop no 3
			}//for-loop no 2
		}//for-loop no 1

		// barrier synchronization
		if (!safetyViolated){	//Safety Violated For Motorcade-5 and Fisher_star model
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
		}
		level++;
		t = 1 - t;

		jump_time.stop();
		/*
		 * Stop recording the entire time for the jump/iteration
		 * This time include time taken for flowpipe computation, "safety verification", postD computation and containment check
		*/
		double wall_clock;
		wall_clock = jump_time.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		wall_clock = wall_clock / (double) 1000;	//convert milliseconds to seconds

		std::cout << "\nJump " << level - 1 << "..."<< passed_count<< " Symbolic States Passed, " << waiting_count << " waiting ..."<< wall_clock <<" seconds";
		waiting_count = 0; //reset to 0 for next level waiting list

	}while(level<=bound && !done);

	if (level <= bound) {	//did not reach to the assigned bound
		std::cout << "\n\nFound Fix-point after " << level - 1 << " Jumps!!!\n";
	}
cout<<"\n******************************************************************\n";
cout <<"Maximum number of Symbolic states Passed = " <<passed_count<<"\n";
cout<<"******************************************************************\n";
	return PASSED;

}

template_polyhedra::ptr agjh::postC(initial_state::ptr s){
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
	if (current_location->getInvariantExist()) {
		/*
		 * Apply this approach only when input-set U is a point set and dynamics is constant dynamics.
		 * That is we have to determine that Matrix A has constant dynamics (which at the moment not feasible) so avoid it
		 * and also avoid B (and poly U) for similar reason. However, C here is a constant vector.
		 *
		 * ToDo:: This jumpInvariantBoundaryCheck() need to be modified for check Omega crossing all Invariant's boundary
		 * 	at the same time instead of checking each invariant for the whole time horizon as implemented in InvariantBoundaryCheckNewLPSolver()
		 * 	For submitting the reading in STT Journal we did not included jumpInvariantBoundaryCheck() for eg in TTEthernet benchmark.

		 */
//		if (current_location->getSystem_Dynamics().isEmptyMatrixA==true && current_location->getSystem_Dynamics().isEmptyMatrixB==true && current_location->getSystem_Dynamics().isEmptyC==false){
//			//Approach of Coarse-time-step and Fine-time-step
//			//std::cout<<"Coarse-time-step and Fine-time-step Flowpipe \n";
//			jumpInvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope, reach_parameters,
//				current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
//		}else{
//			//Approach of Sequential invariant check will work for all case
			//InvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope,
			//	reach_parameters, current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);	//OLD implementation
			InvariantBoundaryCheckNewLPSolver(current_location->getSystem_Dynamics(), continuous_initial_polytope,
				reach_parameters, current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);
//		}

		/*jumpInvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope, reach_parameters,
						current_location->getInvariant(), lp_solver_type_choosen, NewTotalIteration);*/

		/*quickInvariantBoundaryCheck(current_location->getSystem_Dynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(), lp_solver_type_choosen,
				NewTotalIteration);*/
	}

	template_polyhedra::ptr reach_region;
	//std::cout << "NewTotalIteration = " << NewTotalIteration << std::endl;

	//parallelReachSelection(NewTotalIteration, current_location, continuous_initial_polytope, reach_parameters, reach_region, id);
	reach_region = reachabilitySequential(NewTotalIteration,
					current_location->getSystem_Dynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location->getInvariant(),
					current_location->getInvariantExist(), lp_solver_type_choosen);
	/*sequentialReachSelection(NewTotalIteration, current_location,
			continuous_initial_polytope, reach_region);*/

	return reach_region;
}
std::list<initial_state::ptr> agjh::postD(symbolic_states::ptr symb, std::list<symbolic_states::ptr> PASSED, bool& unsafe)
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

			std::list<polytope::ptr> polys;

			bool aggregation=true;//ON indicate TRUE, so a single/more (if clustering) template-hulls are taken
			//OFF indicate for each Omega(a convex set in flowpipe) a new symbolic state is created and pushed in the Wlist
			if (boost::iequals(this->getSetAggregation(),"thull")){
				aggregation=true;
			} else if (boost::iequals(this->getSetAggregation(),"none")){
				aggregation=false;
			}

			//intersected_polyhedra = reach_region->polys_intersectionSequential(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
			//polys = reach_region->flowpipe_intersectionSequential(gaurd_polytope, lp_solver_type_choosen);
			gaurd_polytope = (*t)->getGaurd(); //	GeneratePolytopePlotter(gaurd_polytope);
			//	std::cout<<"Before flowpipe Guard intersection\n";
			//std::cout<<"locName = "<<locName<<"   res.size="<<res.size()<<std::endl;//
			if (!gaurd_polytope->getIsUniverse() && !gaurd_polytope->getIsEmpty())	//Todo guard and invariants in the model: True is universal and False is unsatisfiable/empty
			{
				// Returns the template hull of the polytopes that intersect with the guard
				polys = reach_region->flowpipe_intersectionSequential(aggregation, gaurd_polytope, lp_solver_type_choosen);
			} else if (gaurd_polytope->getIsUniverse()) {	//the guard polytope is universal
				// This alternative introduces a large approximation at switchings
				//polys.push_back(flowpipse_cluster(reach_region,100));

					// Another alternative is to consider each omega in the flowpipe as a new symbolic state.
					// The cost of flowpipe computation shall increase but the precision is likely to be better.
					// A user may choose the clustering percent to tune the accuracy versus time overhead

					/* When the guard is universal, a special case arises when destination location has same dynamics as the current one
					 * and the transition assignment is an identity. *Take only the last polytope from the flowpipe and pass as the new
					 * symbolic state in the waiting list. The 'continuation' principle will ensure that no reachable state is missed.
					 */
					bool continuation = check_continuation(current_location, current_destination, *t);
					if(continuation){
						// get the last polytope from the plowpipe
						std::cout << "Continuation Condition Satisfied\n";
						unsigned int template_poly_size = reach_region->getTotalIterations();
						polys.push_back(reach_region->getPolytope(template_poly_size - 1)); // last polytope
					} else{ // Try clustering with user defined clustering percent

						polys = reach_region->flowpipe_intersectionSequential(aggregation, gaurd_polytope, lp_solver_type_choosen);

						/*int cluster = 100; // Sets the percentage of clustering to 100 ie only one cluster
						polys = flowpipe_cluster(reach_region, cluster);//std::cout << "Inside Universe Guard intersection with flowpipe routine\n";//std::cout << "Number of polytopes after clustering:" << polys.size() << std::endl;
						clusted = true;*/
					}
				}
				else{ // empty guard
					std::cout << "Empty guard condition\n";
					continue;
				}
			//std::cout<<"After flowpipe Guard intersection--res.size="<<res.size()<<std::endl;//
			//Todo to make is even procedure with Sequential procedure.... so intersection is done first and then decide to skip this loc
			if ((locName.compare("BAD") == 0) || (locName.compare("GOOD") == 0)
					|| (locName.compare("FINAL") == 0) || (locName.compare("UNSAFE") == 0)){
				//--Arch-Competition: Implemented for Motorcade_5 Benchmark
				if (polys.size()!=0){//Guard set intersected
					#pragma omp critical
					{
						//std::cout<<"polys.size() = "<<polys.size()<<"\n UnSafe Location Reached!!!\n";
						unsafe=true;
					}
					std::cout<< "locName = "<< locName << "  Reached" << res.size()<<std::endl;//
					return res;//Safety Violated. Returning sym_state list passed so far.
				}

				continue;//Guard set NOT intersected but these location not pushed in the waitingList
			}

			current_assignment = (*t)->getAssignT();
			// *** interesected_polyhedra included with invariant_directions also ******
		//cout<<"size = "<< intersected_polyhedra.size();

			int destination_locID = (*t)->getDestination_Location_Id();
			ds.insert_element(destination_locID);

			for (std::list<polytope::ptr>::iterator i = polys.begin(); i != polys.end(); i++) {
				intersectedRegion = (*i);
				//intersectedRegion = (*i)->getTemplate_approx(lp_solver_type_choosen);
				//Returns a single over-approximated polytope from the list of intersected polytopes
				//	GeneratePolytopePlotter(intersectedRegion);
				//std::cout<<"Before Guard intersected region called\n";
				polytope::ptr newShiftedPolytope, newPolytope;//created an object here
				if (gaurd_polytope == NULL){
					//std::cout<<"Guard is NULL"<<std::endl;//so do not perform intersection
					continue;
				}
				else
					newPolytope = intersectedRegion->GetPolytope_Intersection(gaurd_polytope);//Retuns the intersected region as a single newpolytope. **** with added directions
				//newShiftedPolytope = post_assign_exact(newPolytope, current_assignment.Map, current_assignment.b);//initial_polytope_I = post_assign_exact(newPolytope, R, w);

				math::matrix<double> test(current_assignment.Map.size1(),
						current_assignment.Map.size2());
				//std::cout<<"Before Assignment called\n";
				if (current_assignment.Map.inverse(test))	//invertible?
				{
					//std::cout << "Exact Post Assignment\n";
					newShiftedPolytope = post_assign_exact(newPolytope,
							current_assignment.Map, current_assignment.b);
				} else {
					//std::cout << "Approximate Post Assignment\n";
					newShiftedPolytope = post_assign_approx_deterministic(
							newPolytope, current_assignment.Map,
							current_assignment.b, reach_parameters.Directions,
							lp_solver_type_choosen);
				}
				//std::cout<<"Before Invariant intersection called\n";
				// @Amit: the newShifted satisfy the destination location invariant
				if (H.getLocation(destination_locID)->getInvariant() == NULL){
					//std::cout<<"Invariant is NULL"<<std::endl;//so do not perform intersection
					//so new shifted polytope will not change
				}else
					newShiftedPolytope = newShiftedPolytope->GetPolytope_Intersection(H.getLocation(destination_locID)->getInvariant());

				bool is_ContainmentCheckRequired = 0;	//1 will enable Containment Check and Make Slow; 0 will disable so Fast
				if (is_ContainmentCheckRequired){	//Containment Checking required
					bool isContain=false;

				//	std::cout<<"Before Containment check called\n";
					polytope::ptr newPoly = polytope::ptr(new polytope()); 	//std::cout<<"Before templatedHull\n";
					newShiftedPolytope->templatedDirectionHull(reach_parameters.Directions, newPoly, lp_solver_type_choosen);
					isContain = templated_isContained(destination_locID, newPoly, PASSED, lp_solver_type_choosen);//over-approximated but threadSafe
					//isContain = isContained_withLock(destination_locID, newPoly, PASSED, lp_solver_type_choosen);

					if (!isContain){	//if true has newInitialset is inside the flowpipe so do not insert into WaitingList
						initial_state::ptr newState = initial_state::ptr(new initial_state(destination_locID, newShiftedPolytope));
						newState->setTransitionId(transition_id); // keeps track of the transition_ID
						newState->setParentPtrSymbolicState(symb);
						res.push_back(newState);
					}

				}else{	//Containtment Checking NOT performed

					initial_state::ptr newState = initial_state::ptr(new initial_state(destination_locID, newShiftedPolytope));
					newState->setTransitionId(transition_id); // keeps track of the transition_ID
					newState->setParentPtrSymbolicState(symb);
					res.push_back(newState);
				}

			} //end of multiple intersected region with guard

		} //end of multiple transaction
	} //end-if of flowpipe computation not empty
	return res;

} //end of while loop checking waiting_list != empty

bool agjh::checkSafety(template_polyhedra::ptr& reach_region, initial_state::ptr& s, symbolic_states::ptr& S, std::list<abstractCE::ptr>& ce_candidates) {

	//  ******************************** Safety Verification section ********************************
		std::list < symbolic_states::ptr > list_sym_states;
		std::list < transition::ptr > list_transitions; // list of transitions leading to the unsafe set
		bool saftey_violated = false;


		if (reach_region->getTotalIterations() != 0 && forbidden_set.second != NULL) { //flowpipe exists
				//so perform intersection with forbidden set provided locID matches
			int locID =s->getLocationId();
			cout<<"Running Safety Check for Loc = "<<locID<<std::endl;
			if (forbidden_set.first==-1 || locID == forbidden_set.first) { //forbidden locID matches
				polytope::ptr forbid_poly = forbidden_set.second;
				std::list < template_polyhedra::ptr > forbid_intersects;
				forbid_intersects = reach_region->polys_intersectionSequential(forbid_poly, lp_solver_type_choosen);

				if (forbid_intersects.size() == 0) {
					//std::cout << "\nThe model does NOT violate SAFETY property!!!\n";
				} else {
					symbolic_states::ptr current_forbidden_state;
					current_forbidden_state = S;
					int cc = 0;
					do {
						int locationID2=0;
						discrete_set ds2;
						// ***********insert bounding_box_polytope as continuousSet in the abstract_symbolic_state***********
						int transID = current_forbidden_state->getTransitionId(); //a)
						list_sym_states.push_front(current_forbidden_state); //pushing the bad symbolic_state first(at the top)

						if (current_forbidden_state->getParentPtrSymbolicState() != NULL) { //searching only if not NULL

							//current_forbidden_state = searchSymbolic_state(Reachability_Region, current_forbidden_state->getParentPtrSymbolicState());
							current_forbidden_state = current_forbidden_state->getParentPtrSymbolicState();
							//2) ******************* list_transitions ********************
							ds2 = current_forbidden_state->getDiscreteSet();
							assert(ds2.getDiscreteElements().size()!=0); //

							for (std::set<int>::iterator it = ds2.getDiscreteElements().begin(); it != ds2.getDiscreteElements().end(); ++it)
								locationID2 = (*it);

							location::ptr object_location;

							object_location = H.getLocation(locationID2);
							transition::ptr temp = object_location->getTransition(transID); //e)
							list_transitions.push_front(temp); //pushing the transition in the stack
							//2) ******************* list_transitions Ends ********************
						}
						cc++;
					} while (current_forbidden_state->getParentPtrSymbolicState()!= NULL);
					if ((cc >= 1) && (current_forbidden_state->getParentPtrSymbolicState()== NULL)) { //root is missed
						list_sym_states.push_front(current_forbidden_state); //1) pushing the initial/root bad symbolic_state at the top
					}
					saftey_violated = true;

					abstractCE::ptr ce = abstractCE::ptr(new abstractCE());
					ce->set_length(cc);
					ce->set_sym_states(list_sym_states);
					ce->set_transitions(list_transitions);
					hybrid_automata::ptr ha = hybrid_automata::ptr(new hybrid_automata(H));
					ce->set_automaton(ha);
					ce->set_forbid_poly(forbidden_set.second);
#pragma omp critical
					{
						ce_candidates.push_back(ce); // ce added to the abstract ce candidates list.
					}
				} // end of condition when forbidden state intersects with the flowpipe set
			} //end of condition when forbidden state loc id matches with flowpipe loc id
		} //computed flowpipe is not empty

		//  ******************************** Safety Verification section Ends********************************
	return saftey_violated;
}


