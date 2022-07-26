/* AsyncBFS.cpp
 *
 *  Created on: 12-Jan-2017
 *      Author: amit
 */

#include <core/reachability/asyncBFS.h>
#include <utilities/flowpipeCluster.h>

using namespace std;

//std::mutex mu;
std::recursive_mutex mu;

std::list<symbolic_states::ptr> AsyncBFS::reachComputeAsynBFS(std::list<abstractCE::ptr>& ce){



	LocklessDS L[H->getTotalLocations()];	//Creating an array of Lockless data structure of size total number of locations


	initializeLocklessDS(L,H->getTotalLocations()); //initialize all flags to unlocked initially

	printLocklessDS(L, H->getTotalLocations());

	std::list<symbolic_states::ptr> PASSED;	//List of all flowpipes computed


	//Reachability Computation Started
	AsyncBFSData reachData;
	// ****************** Duplicating the Data *************
	reachData.bound = bound;
	reachData.H = H;
	reachData.reach_parameters = reach_parameters;
	reachData.lp_solver_type = lp_solver_type;
	reachData.set_aggregation = this->getSetAggregation();
	// ****************** End of Duplicating the Data *************

	int level=0;
	long totalSymStates=0;
	int levelCompleted=0;

	std::vector<std::thread> workers;
	for (std::list<initial_state::ptr>::iterator i = I.begin(); i != I.end(); i++) {
		initial_state::ptr s;	//A symbolic state
		s =*(i);	//	initialState_index++; //next initial state
		workers.push_back(std::thread(AsyncBFS_recursiveFunc, &L[0], s, level, std::ref(reachData),std::ref(totalSymStates),std::ref(levelCompleted)));	//thread called
	}
	for (unsigned int i=0;i<workers.size();i++){

		workers[i].join();
	}

	if (levelCompleted< (int)bound){
		std::cout<<"\n\nFound Fixed-point after "<<levelCompleted -1 <<" jumps!!!\n";
	}

	std::cout<<"\n******************************************************************\n";
	std::cout <<"Maximum number of Symbolic states Passed = " <<totalSymStates<<"\n";
	std::cout<<"******************************************************************\n";


	/*******This may or may not be expensive have to verify, If possible avoid recording time for this operation*********** */

	for (int i=0;i<H->getTotalLocations();i++){
		PASSED.insert(PASSED.end(),L[i].PASSED.begin(),L[i].PASSED.end());
	}

	return PASSED;
}



void AsyncBFS_recursiveFunc(LocklessDS L[], initial_state::ptr s, int level, AsyncBFSData& reachData, long& totalSymStates, int& levelCompleted) {
//std::list<symbolic_states::ptr>& PASSED
	//std::cout<<"Printing From Thread\n";
	template_polyhedra::ptr R;
	R = postC(s, reachData);
	symbolic_states::ptr R1 = symbolic_states::ptr(new symbolic_states());

	R1->setParentPtrSymbolicState(s->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states

	R1->setContinuousSetptr(R);
	discrete_set d;
	d.insert_element(s->getLocationId());
	R1->setDiscreteSet(d);
	int locID = s->getLocationId();
	//#pragma omp critical
	//				{
	lock(L,locID); //mu.lock(); after this function lock is obtained successfully
	totalSymStates++;	//for each symbolic states when processed (ie postC)
	//PASSED.push_back(R1);	//todo::try mutex for locking this shared resource
	L[locID - 1].PASSED.push_back(R1);
	unlock(L,locID); //mu.unlock();
	std::cout<<"Jump "<<level<<"..."<<totalSymStates<<" Symbolic States Passed ..."<<std::endl;
	//				}
	//----end of postC on s
	//todo:: Currently removed the Safety Check Section from here
	std::list<initial_state::ptr> R2;
	//ToDo:: this shared level can not be use to check... as if one branch has move ahead it increase level and with this
	//increased value some other previous branch may not spun child threads.
	bool unsafe = false;
	if (level < reachData.bound) {	//Check level to avoid last PostD computation
//		std::cout<<"reachData.bound ="<<reachData.bound<<" and level="<<level<<std::endl;
		R2 = postD(R1, L, reachData, unsafe);
		if(unsafe){
			std::cout << "system is unsafe\n";
			exit(0);
		}
		std::vector<std::thread> RecursiveWorkers;
		level++;// ***** increased locally and send this for all recursive thread ****
		mu.lock();
		levelCompleted++;	//increased locally and also passed back and forth in all threads
		mu.unlock();
		for (std::list<initial_state::ptr>::iterator i = R2.begin(); i != R2.end(); i++) {
			initial_state::ptr s;	//A symbolic state
			s =*(i);	//	initialState_index++; //next initial state
			RecursiveWorkers.push_back(std::thread(AsyncBFS_recursiveFunc, &L[0], s, level, std::ref(reachData),std::ref(totalSymStates),std::ref(levelCompleted)));	//thread called
		}
		 for (unsigned int i=0;i<RecursiveWorkers.size();i++){
			RecursiveWorkers[i].join();
		}
	}
	return ; //return from this thread:: This has no effect in performance
}


template_polyhedra::ptr postC(initial_state::ptr s, AsyncBFSData myData){
	int location_id;

	discrete_set d;
	location_id = s->getLocationId();
	d.insert_element(location_id); //creating discrete_state

	//continuous_initial_polytope = U.getInitial_ContinousSetptr();
	polytope::const_ptr continuous_initial_polytope;
	continuous_initial_polytope = s->getInitialSet();

	ReachabilityParameters reach_parameters; //local

	reach_parameters = myData.reach_parameters;
// 	cout<<"No error 2222!!!!\n";
	reach_parameters.X0 = continuous_initial_polytope;
	symbolic_states::ptr S;

	location::const_ptr current_location;

	current_location = myData.H->getLocation(location_id);
	string name = current_location->getName();

	double result_alfa = compute_alfa(reach_parameters.time_step,
			current_location->getSystemDynamics(), continuous_initial_polytope,
			myData.lp_solver_type); //2 glpk object created here
	double result_beta = compute_beta(current_location->getSystemDynamics(),
			reach_parameters.time_step, myData.lp_solver_type); // NO glpk object created here

	reach_parameters.result_alfa = result_alfa;
	reach_parameters.result_beta = result_beta;
	math::matrix<double> phi_matrix, phi_trans;

	if (!current_location->getSystemDynamics().isEmptyMatrixA) { //if A not Empty
		current_location->getSystemDynamics().MatrixA.matrix_exponentiation(phi_matrix, reach_parameters.time_step);
		phi_matrix.transpose(phi_trans);
		reach_parameters.phi_trans = phi_trans;
	}
	math::matrix<double> B_trans;
	// transpose to be done once and stored in the structure of parameters
	if (!current_location->getSystemDynamics().isEmptyMatrixB) { //if B not Empty
		current_location->getSystemDynamics().MatrixB.transpose(B_trans);
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
		 *
		 * ToDo:: This jumpInvariantBoundaryCheck() need to be modified for check Omega crossing all Invariant's boundary
		 * 	at the same time instead of checking each invariant for the whole time horizon as implemented in InvariantBoundaryCheckNewLPSolver()
		 * 	For submitting the reading in STT Journal we did not included jumpInvariantBoundaryCheck() for eg in TTEthernet benchmark.
		 */
//		if (current_location->getSystemDynamics().isEmptyMatrixA==true && current_location->getSystemDynamics().isEmptyMatrixB==true && current_location->getSystemDynamics().isEmptyC==false){
//			//Approach of Coarse-time-step and Fine-time-step
//			jumpInvariantBoundaryCheck(current_location->getSystemDynamics(), continuous_initial_polytope, reach_parameters,
//				current_location->getInvariant(), myData.lp_solver_type, NewTotalIteration);
//		}else{
			//Approach of Sequential invariant check will work for all case
			//InvariantBoundaryCheck(current_location->getSystemDynamics(), continuous_initial_polytope,
			//	reach_parameters, current_location->getInvariant(), myData.lp_solver_type, NewTotalIteration);//Old implementation
			InvariantBoundaryCheckNewLPSolver(current_location->getSystemDynamics(), continuous_initial_polytope,
				reach_parameters, current_location->getInvariant(), myData.lp_solver_type, NewTotalIteration);
//		}

		/*jumpInvariantBoundaryCheck(current_location->getSystemDynamics(), continuous_initial_polytope, reach_parameters,
						current_location->getInvariant(), lp_solver_type, NewTotalIteration);*/

		/*quickInvariantBoundaryCheck(current_location->getSystemDynamics(),
				continuous_initial_polytope, reach_parameters,
				current_location->getInvariant(), lp_solver_type,
				NewTotalIteration);*/
	}

	template_polyhedra::ptr reach_region;
//	std::cout << "NewTotalIteration = " << NewTotalIteration << std::endl;

	//parallelReachSelection(NewTotalIteration, current_location, continuous_initial_polytope, reach_parameters, reach_region, id);
	reach_region = postC_sf(NewTotalIteration,
					current_location->getSystemDynamics(),
					continuous_initial_polytope, reach_parameters,
					current_location->getInvariant(),
					current_location->getInvariantExist(), myData.lp_solver_type);
	/*sequentialReachSelection(NewTotalIteration, current_location,
			continuous_initial_polytope, reach_region);*/

	return reach_region;
}

std::list<initial_state::ptr> postD(symbolic_states::ptr symb, LocklessDS L[], AsyncBFSData myData, bool& unsafe)
{
	template_polyhedra::ptr reach_region= symb->getContinuousSetptr();
	int locId = *(symb->getDiscreteSet().getDiscreteElements().begin());

	location::const_ptr current_location = myData.H->getLocation(locId);
	std::list<initial_state::ptr> res;

	if (reach_region->getTotalIterations() != 0) { //computed reach_region is empty && optimize transition BreadthLevel-wise

		for (std::list<transition::ptr>::const_iterator t = current_location->getOutGoingTransitions().begin();
				t != current_location->getOutGoingTransitions().end(); t++) { // get each destination_location_id and push into the pwl.waiting_list
			int transition_id = (*t)->getTransitionId();

			location::const_ptr current_destination;
			Assign current_assignment;
			polytope::const_ptr guard_polytope;
			//std::list < template_polyhedra::ptr > intersected_polyhedra;
			polytope::ptr intersectedRegion;//created two objects here
			discrete_set ds;
			current_destination = myData.H->getLocation((*t)->getDestinationLocationId());

			string locName = current_destination->getName();
			guard_polytope = (*t)->getGuard();//	GeneratePolytopePlotter(guard_polytope);

			bool aggregation=true;//ON indicate TRUE, so a single/more (if clustering) template-hulls are taken
			//OFF indicate for each Omega(a convex set in flowpipe) a new symbolic state is created and pushed in the Wlist
			if (boost::iequals(myData.set_aggregation,"thull")){
				aggregation=true;
				//std::cout<<"set-aggregation=thull\n";
			} else if (boost::iequals(myData.set_aggregation,"none")){
				aggregation=false;
				//std::cout<<"set-aggregation=none\n";
			}


			std::list<polytope::ptr> polys;
			//intersected_polyhedra = reach_region->polys_intersectionSequential(guard_polytope, lp_solver_type); //, intersection_start_point);
			//polys = reach_region->flowpipe_intersectionSequential(guard_polytope, myData.lp_solver_type);

			//intersected_polyhedra = reach_region->polys_intersectionSequential(guard_polytope, lp_solver_type); //, intersection_start_point);
			//polys = reach_region->flowpipe_intersectionSequential(guard_polytope, lp_solver_type);
			guard_polytope = (*t)->getGuard(); //	GeneratePolytopePlotter(guard_polytope);
			//	std::cout<<"Before flowpipe Guard intersection\n";
			if (!guard_polytope->getIsUniverse() && !guard_polytope->getIsEmpty())	//Todo guard and invariants in the model: True is universal and False is unsatisfiable/empty
			{
				// Returns the template hull of the polytopes that intersect with the guard
				polys = reach_region->flowpipe_intersectionSequential(aggregation, guard_polytope, myData.lp_solver_type);
			}
			else if (guard_polytope->getIsUniverse()) {	//the guard polytope is universal
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
						/*int cluster = 100; // Sets the percentage of clustering to 0 ie no clustering applied
						polys = flowpipe_cluster(reach_region, cluster);
						std::cout << "Inside Universe Guard intersection with flowpipe routine\n";
						std::cout << "Number of polytopes after clustering:" << polys.size() << std::endl;*/
						polys = reach_region->flowpipe_intersectionSequential(aggregation, guard_polytope, myData.lp_solver_type);
					}
				}
				else{ // empty guard
					std::cout << "Empty guard condition\n";
					continue;
				}
		//cout<<"3\n";
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
				continue;//do not push into the waitingList
			}


			current_assignment = (*t)->getAssignT();
			// *** interesected_polyhedra included with invariant_directions also ******
		//	cout<<"size = "<< intersected_polyhedra.size();

			int destination_locID = (*t)->getDestinationLocationId();
			ds.insert_element(destination_locID);

			for (std::list<polytope::ptr>::iterator i = polys.begin(); i != polys.end(); i++) {
				intersectedRegion = (*i);
				//intersectedRegion = (*i)->getTemplate_approx(lp_solver_type);
				//Returns a single over-approximated polytope from the list of intersected polytopes
				//	GeneratePolytopePlotter(intersectedRegion);
				polytope::ptr newShiftedPolytope, newPolytope;//created an object here
				newPolytope = intersectedRegion->GetPolytope_Intersection(guard_polytope);//Retuns the intersected region as a single newpolytope. **** with added directions
				//newShiftedPolytope = post_assign_exact(newPolytope, current_assignment.Map, current_assignment.b);//initial_polytope_I = post_assign_exact(newPolytope, R, w);

				math::matrix<double> test(current_assignment.Map.size1(),
						current_assignment.Map.size2());
				if (current_assignment.Map.inverse(test))	//invertible?
				{
					//std::cout << "Exact Post Assignment\n";
					newShiftedPolytope = post_assign_exact(newPolytope,
							current_assignment.Map, current_assignment.b);
				} else {
					//std::cout << "Approximate Post Assignment\n";
					newShiftedPolytope = post_assign_approx_deterministic(
							newPolytope, current_assignment.Map,
							current_assignment.b, myData.reach_parameters.Directions,
							myData.lp_solver_type);
				}
				// @Amit: the newShifted satisfy the destination location invariant
				if (myData.H->getLocation(destination_locID)->getInvariant() != NULL)
					newShiftedPolytope = newShiftedPolytope->GetPolytope_Intersection(myData.H->getLocation(destination_locID)->getInvariant());
				/*
				 * Now perform containment check similar to sequential algorithm.
				 */

				int is_ContainmentCheckRequired = 1;	//1 will enable Containment Check and Make Slow; 0 will disable so Fast
				if (is_ContainmentCheckRequired){	//Containtment Checking required
					bool isContain=false;
					polytope::ptr newPoly = polytope::ptr(new polytope()); 	//std::cout<<"Before templatedHull\n";
					newShiftedPolytope->templatedDirectionHull(myData.reach_parameters.Directions, newPoly, myData.lp_solver_type);
					//isContain = AsyncBFS_isContained(destination_locID, newPoly, L, myData.H.getTotalLocations(), myData.lp_solver_type);//over-approximated but threadSafe
					isContain = AsyncBFS_isContained(destination_locID, newPoly, L, myData.lp_solver_type);//over-approximated but threadSafe
					if (!isContain){	//if true has newInitialset is inside the flowpipe so do not insert into WaitingList
						initial_state::ptr newState = initial_state::ptr(new initial_state(destination_locID, newShiftedPolytope));
						newState->setTransitionId(transition_id); // keeps track of the transition_ID
						newState->setParentPtrSymbolicState(symb);
						res.push_back(newState);
					}
				}else{	//Containtment Checking NOT Formed
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


/*
 * This is thread-safe but uses template_Hull of poly an over-approximated technique
 */

//bool AsyncBFS_isContained(int locID, polytope::ptr poly, LocklessDS L[], int totalLocations, int lp_solver_type) {
bool AsyncBFS_isContained(int locID, polytope::ptr poly, LocklessDS L[], int lp_solver_type) {
	bool contained = false;
	//std::cout<<"Number of Flowpipes passed so far = "<<Reachability_Region.size()<<"\n";
	//int ha_size = totalLocations;// no need to search in all locations only on locID
	//for (int l=1;l<=ha_size;l++){// no need to search in all locations only on locID

	std::list<symbolic_states::ptr> PASSED = L[locID-1].PASSED; //get only the passed list with locationID = locID
	//Todo:: acquire lock and then do containment check
	lock(L,locID);	//After this function, lock is obtained successfully
	for (std::list <symbolic_states::ptr>::iterator it = PASSED.begin(); it !=PASSED.end();it++){
		discrete_set ds;
		ds = (*it)->getDiscreteSet();
		int locationID=0;
		for (std::set<int>::iterator i = ds.getDiscreteElements().begin();i != ds.getDiscreteElements().end(); ++i)
			locationID = (*i);
		if (locationID == locID){	//found Location matching so perform containment check with the flowpipe
			template_polyhedra::ptr flowpipe;
			flowpipe = (*it)->getContinuousSetptr();
			//std::cout<<"Number of Omegas in the Flowpipe = "<<flowpipe->getTotalIterations()<<"\n";
			bool intersects=false;
			for (unsigned int i = 0; i < flowpipe->getMatrixSupportFunction().size2(); i++) {
				//std::cout<<"\n Inner thread Template_polyhedra omp_get_num_threads() = "<< omp_get_num_threads()<<"\n";
				polytope::ptr p;
				p = flowpipe->getPolytope(i);
				intersects = p->check_polytope_intersection(poly); //result of intersection
				if (intersects){
					//todo:: if Contained in a union of Omegas
					//std::cout<<"Intersected = "<<intersects<<std::endl;		//Good testing
					contained = p->contains(poly, lp_solver_type);//	Our simple polytope Containment Check
					if (contained){
						//std::cout<<"\n\nFound Fixed-point!!!\n";
						break;	//No need to check the rest if contained in a single Omega
					}
				}
			}
		}
	}
	//}
	unlock(L,locID); //unlock after containment check
return contained;
}

void initializeLocklessDS(LocklessDS L[], int ha_size){

	for (int i=1;i<=ha_size;i++){
		L[i-1].locID = i;
		L[i-1].flag = 0;
	}
}

void printLocklessDS(LocklessDS L[], int ha_size){
	for (int i=1;i<=ha_size;i++){
		std::cout<<"LocID = "<<L[i-1].locID <<" flag = "<<L[i-1].flag<<std::endl;
	}
}

/* This is version without using CAS.
void lock(LocklessDS L[], int locID){
	if (L[locID-1].flag == 0){
		L[locID-1].flag = 1; //indicate it is locked
	} else {
		while (L[locID-1].flag != 0)
			;
	}
} */

/* * Here flag is set using CAS. Otherwise use spinloop */
void lock(LocklessDS L[], int locID){

	//first argument is the test-value and the second argument is the new-modified-value
	//Returns second arg if success else first.
/*
	while (!(L[locID-1].flag.compare_exchange_strong(L[locID-1].flag, 1, std::memory_order_release)))
		;
*/

	while (!(std::atomic_exchange_explicit(&L[locID-1].flag, 1, std::memory_order_acquire)))
		;

	/*while(std::atomic_exchange_explicit(&lock, true, std::memory_order_acquire))
	             ; // spin until acquired*/

}

void unlock(LocklessDS L[], int locID){
	L[locID-1].flag = 0;	//unlock is simple, simply set locID's flag to 0
}
