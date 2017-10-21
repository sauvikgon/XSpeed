/* AsyncBFS.cpp
 *
 *  Created on: 12-Jan-2017
 *      Author: amit
 */

#include "core_system/Reachability/AsyncBFS.h"
#include "Utilities/flowpipe_cluster.h"

using namespace std;

//std::mutex mu;
std::recursive_mutex mu;

std::list<symbolic_states::ptr> AsyncBFS::reachComputeAsynBFS(std::list<abstractCE::ptr>& ce){

	std::list<symbolic_states::ptr> PASSED;	//List of all flowpipes computed

//	std::cout<<"Testing printing\n";

	//Reachability Computation Started
	AsyncBFSData reachData;
	// ****************** Duplicating the Data *************
	reachData.bound = bound;
	reachData.H = H;
	reachData.reach_parameters = reach_parameters;
	reachData.lp_solver_type_choosen = lp_solver_type_choosen;
	reachData.set_aggregation = this->getSetAggregation();
	// ****************** End of Duplicating the Data *************
// ******** Required Results *****************
	int level=0;
	long totalSymStates=0;
	int levelCompleted=0;
// ******** Required Results *****************
	std::vector<std::thread> workers;
	for (std::list<initial_state::ptr>::iterator i = I.begin(); i != I.end(); i++) {
		initial_state::ptr s;	//A symbolic state
		s =*(i);	//	initialState_index++; //next initial state
		workers.push_back(std::thread(AsyncBFS_recursiveFunc, std::ref(PASSED), s, level, std::ref(reachData),std::ref(totalSymStates),std::ref(levelCompleted)));	//thread called
	}
	for (int i=0;i<workers.size();i++){
		if (i==(workers.size() - 1)){	//increasing level only once
		  //std::cout<<"Breadth-Level "<<level<<" Processed"<<" and reachData.bound ="<<reachData.bound<<std::endl;
		  //std::cout<<"Breadth-Level "<<level<<" Processed... Symbolic states processed so far "<<totalSymStates<<" ..."<<std::endl;
		}
		workers[i].join();
	}

	if (levelCompleted< bound){
		std::cout<<"\n\nFound Fixed-point after "<<levelCompleted -1 <<" jumps!!!\n";
	}

	std::cout<<"\n******************************************************************\n";
	std::cout <<"Maximum number of Symbolic states Passed = " <<totalSymStates<<"\n";
	std::cout<<"******************************************************************\n";

	//Reachability Computation Over
	return PASSED;
}



void AsyncBFS_recursiveFunc(std::list<symbolic_states::ptr>& PASSED, initial_state::ptr s, int level, AsyncBFSData& reachData, long& totalSymStates, int& levelCompleted) {

	//std::cout<<"Printing From Thread\n";
	template_polyhedra::ptr R;
	R = postC(s, reachData);
	symbolic_states::ptr R1 = symbolic_states::ptr(new symbolic_states());

	R1->setParentPtrSymbolicState(s->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states

	R1->setContinuousSetptr(R);
	discrete_set d;
	d.insert_element(s->getLocationId());
	R1->setDiscreteSet(d);
	//#pragma omp critical
	//				{
	mu.lock();
	totalSymStates++;	//for each symbolic states when processed (ie postC)
	PASSED.push_back(R1);	//todo::try mutex for locking this shared resource
	mu.unlock();
	std::cout<<"Jump "<<level<<"..."<<totalSymStates<<" Symbolic States Passed ..."<<std::endl;
	//				}
	//----end of postC on s
	//todo:: Currently removed the Safety Check Section from here
	std::list<initial_state::ptr> R2;
	//ToDo:: this shared level can not be use to check... as if one branch has move ahead it increase level and with this
	//increased value some other previous branch may not spun child threads.
	if (level < reachData.bound) {	//Check level to avoid last PostD computation
//		std::cout<<"reachData.bound ="<<reachData.bound<<" and level="<<level<<std::endl;
		R2 = postD(R1, PASSED, reachData);
		std::vector<std::thread> RecursiveWorkers;
		level++;// ***** increased locally and send this for all recursive thread ****
		mu.lock();
		levelCompleted++;	//increased locally and also passed back and forth in all threads
		mu.unlock();
		for (std::list<initial_state::ptr>::iterator i = R2.begin(); i != R2.end(); i++) {
			initial_state::ptr s;	//A symbolic state
			s =*(i);	//	initialState_index++; //next initial state
			RecursiveWorkers.push_back(std::thread(AsyncBFS_recursiveFunc, std::ref(PASSED), s, level, std::ref(reachData),std::ref(totalSymStates),std::ref(levelCompleted)));	//thread called
		}
		 for (int i=0;i<RecursiveWorkers.size();i++){
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
//std::cout<<"Loc ID = "<<location_id <<std::endl;
	//continuous_initial_polytope = U.getInitial_ContinousSetptr();
	polytope::ptr continuous_initial_polytope;
	continuous_initial_polytope = s->getInitialSet();

	ReachabilityParameters reach_parameters; //local
	//cout<<"No error 111!!!!\n";
	reach_parameters = myData.reach_parameters;
// 	cout<<"No error 2222!!!!\n";
	reach_parameters.X0 = continuous_initial_polytope;
	symbolic_states::ptr S;

	location::ptr current_location;

	current_location = myData.H.getLocation(location_id);
	string name = current_location->getName();

	double result_alfa = compute_alfa(reach_parameters.time_step,
			current_location->getSystem_Dynamics(), continuous_initial_polytope,
			myData.lp_solver_type_choosen); //2 glpk object created here
	double result_beta = compute_beta(current_location->getSystem_Dynamics(),
			reach_parameters.time_step, myData.lp_solver_type_choosen); // NO glpk object created here

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
//		if (current_location->getSystem_Dynamics().isEmptyMatrixA==true && current_location->getSystem_Dynamics().isEmptyMatrixB==true && current_location->getSystem_Dynamics().isEmptyC==false){
//			//Approach of Coarse-time-step and Fine-time-step
//			jumpInvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope, reach_parameters,
//				current_location->getInvariant(), myData.lp_solver_type_choosen, NewTotalIteration);
//		}else{
			//Approach of Sequential invariant check will work for all case
			//InvariantBoundaryCheck(current_location->getSystem_Dynamics(), continuous_initial_polytope,
			//	reach_parameters, current_location->getInvariant(), myData.lp_solver_type_choosen, NewTotalIteration);//Old implementation
			InvariantBoundaryCheckNewLPSolver(current_location->getSystem_Dynamics(), continuous_initial_polytope,
				reach_parameters, current_location->getInvariant(), myData.lp_solver_type_choosen, NewTotalIteration);
//		}

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
					current_location->isInvariantExists(), myData.lp_solver_type_choosen);
	/*sequentialReachSelection(NewTotalIteration, current_location,
			continuous_initial_polytope, reach_region);*/

	return reach_region;
}

std::list<initial_state::ptr> postD(symbolic_states::ptr symb, std::list<symbolic_states::ptr> PASSED, AsyncBFSData myData)
{
	template_polyhedra::ptr reach_region= symb->getContinuousSetptr();
	int locId = *(symb->getDiscreteSet().getDiscreteElements().begin());

	location::ptr current_location = myData.H.getLocation(locId);
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
			current_destination = myData.H.getLocation((*t)->getDestination_Location_Id());

			string locName = current_destination->getName();
			gaurd_polytope = (*t)->getGaurd();//	GeneratePolytopePlotter(gaurd_polytope);

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
			//intersected_polyhedra = reach_region->polys_intersectionSequential(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
			//polys = reach_region->flowpipe_intersectionSequential(gaurd_polytope, myData.lp_solver_type_choosen);

			//intersected_polyhedra = reach_region->polys_intersectionSequential(gaurd_polytope, lp_solver_type_choosen); //, intersection_start_point);
			//polys = reach_region->flowpipe_intersectionSequential(gaurd_polytope, lp_solver_type_choosen);
			gaurd_polytope = (*t)->getGaurd(); //	GeneratePolytopePlotter(gaurd_polytope);
			//	std::cout<<"Before flowpipe Guard intersection\n";
			if (!gaurd_polytope->getIsUniverse() && !gaurd_polytope->getIsEmpty())	//Todo guard and invariants in the model: True is universal and False is unsatisfiable/empty
			{
				// Returns the template hull of the polytopes that intersect with the guard
				polys = reach_region->flowpipe_intersectionSequential(aggregation, gaurd_polytope, myData.lp_solver_type_choosen);
			}
			else if (gaurd_polytope->getIsUniverse()) {	//the guard polytope is universal
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
						polys = reach_region->flowpipe_intersectionSequential(aggregation, gaurd_polytope, myData.lp_solver_type_choosen);
					}
				}
				else{ // empty guard
					std::cout << "Empty guard condition\n";
					continue;
				}
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
							myData.lp_solver_type_choosen);
				}
				// @Amit: the newShifted satisfy the destination location invariant
				if (myData.H.getLocation(destination_locID)->getInvariant() != NULL)
					newShiftedPolytope = newShiftedPolytope->GetPolytope_Intersection(myData.H.getLocation(destination_locID)->getInvariant());
				/*
				 * Now perform containment check similar to sequential algorithm.
				 */

				int is_ContainmentCheckRequired = 1;	//1 will enable Containment Check and Make Slow; 0 will disable so Fast
				if (is_ContainmentCheckRequired){	//Containtment Checking required
					bool isContain=false;
					polytope::ptr newPoly = polytope::ptr(new polytope()); 	//std::cout<<"Before templatedHull\n";
					newShiftedPolytope->templatedDirectionHull(myData.reach_parameters.Directions, newPoly, myData.lp_solver_type_choosen);
					isContain = templated_isContained(destination_locID, newPoly, PASSED, myData.lp_solver_type_choosen);//over-approximated but threadSafe
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
bool templated_isContained(int locID, polytope::ptr poly,
		std::list<symbolic_states::ptr> Reachability_Region, int lp_solver_type_choosen) {
	bool contained = false;
	//std::cout<<"Number of Flowpipes passed so far = "<<Reachability_Region.size()<<"\n";

	for (std::list <symbolic_states::ptr>::iterator it = Reachability_Region.begin(); it !=Reachability_Region.end();it++){
		discrete_set ds;
		ds = (*it)->getDiscreteSet();
		int locationID;
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
				intersects = p->check_polytope_intersection(poly, lp_solver_type_choosen); //result of intersection
				if (intersects){
					//todo:: if Contained in a union of Omegas
					//std::cout<<"Intersected = "<<intersects<<std::endl;		//Good testing
					contained = p->contains(poly, lp_solver_type_choosen);//	Our simple polytope Containment Check
					if (contained){
						//std::cout<<"\n\nFound Fixed-point!!!\n";
						break;	//No need to check the rest if contained in a single Omega
					}
				}
			}
		}
	}
return contained;
}

/*
 * This is NOT ThreadSafe interface as it uses PPL library however it computes with exact shifted polytope
 */
/*

bool isContained(int locID, polytope::ptr poly, std::list<symbolic_states::ptr> Reachability_Region, int lp_solver_type_choosen){

	bool contained = false;
	//std::cout<<"Number of Flowpipes passed so far = "<<Reachability_Region.size()<<"\n";

	for (std::list <symbolic_states::ptr>::iterator it = Reachability_Region.begin(); it !=Reachability_Region.end();it++){
		discrete_set ds;
		ds = (*it)->getDiscreteSet();
		int locationID;
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

				std::vector<double> constraint_bound_values(flowpipe->getInvariantDirections().size1());
				constraint_bound_values = flowpipe->getInvariantBoundValue(i);
				p->setMoreConstraints(flowpipe->getInvariantDirections(), constraint_bound_values);

				intersects = p->check_polytope_intersection(poly, lp_solver_type_choosen); //result of intersection
				if (intersects){
					//todo:: if Contained in a union of Omegas
				//	std::cout<<"Intersected = "<<intersects<<std::endl;		//Good testing

					//contained = p->contains(poly, lp_solver_type_choosen);//	Our simple polytope Containment Check

					PPL_Polyhedron::ptr p1=PPL_Polyhedron::ptr(new PPL_Polyhedron(p->getCoeffMatrix(),p->getColumnVector(),p->getInEqualitySign()));
					PPL_Polyhedron::ptr p2=PPL_Polyhedron::ptr(new PPL_Polyhedron(poly->getCoeffMatrix(),poly->getColumnVector(),poly->getInEqualitySign()));

					contained = p1->is_contained(p2);
					if (contained){
					//	std::cout<<"\n\nFound Fixed-point!!!\n";
						break;	//No need to check the rest if contained in a single Omega
					}
				}
			}
		}
	}
return contained;
}
*/
