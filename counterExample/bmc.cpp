/*
 * bmc.cpp
 *
 *  Created on: 14-Sep-2020
 *      Author: rajarshi
 */

#include <counterExample/bmc.h>


bmc::~bmc() {
	// TODO Auto-generated destructor stub
} 
bmc::bmc(const hybrid_automata::ptr haPtr,  const std::list<initial_state::ptr>& init,
		const forbidden_states& forbidden, const ReachabilityParameters& r_params,
		const userOptions& user_ops) : ha_ptr(haPtr), init(init), forbidden_s(forbidden),
				reach_params(r_params), user_ops(user_ops), c(), ha_encoding(c), sol(c){
	this->k = user_ops.get_bfs_level();
}

/*
 * Initializes the z3 solver with bounded ha encoding. 
 * It generates all the z3 constraints for bound k1 and add these constraints to the SAT solver.
 */
void bmc::init_solver(unsigned int forbidden_loc_id, unsigned int k1)
{
	location::ptr source_ptr = ha_ptr->getInitialLocation();
	int u = source_ptr->getLocId();
	unsigned int v = forbidden_loc_id;
	auto list_locations = ha_ptr->getAllLocations();

	// Initial clause
	z3::expr exp1 = c.bool_const("exp1");
	string arr = "v" + to_string(u)+"_"+ "0";
	z3::expr x = c.bool_const(arr.c_str());
	exp1 = x;
	for(auto it = list_locations.begin(); it != list_locations.end(); it++)
	{
		arr = "v" + to_string(it->first)+"_"+ "0";
		if (it->first != u)
		{
			z3::expr x1 = c.bool_const(arr.c_str());
			exp1 = (exp1 && !(x1));
		}
	}
	this->sol.add(exp1);

	//Movement clause
	z3::expr exp2 = c.bool_const("exp2");
	z3::expr exp22 = c.bool_const("exp22");
	if(k1 == 0)
	{
		for (unsigned int i =0; i <= k1; i++)
		{

			for (auto it = list_locations.begin(); it != list_locations.end(); it++)
			{
				auto neighbor_nodes = it->second->getOutGoingTransitions();
				arr = "v"+ to_string(it->first)+"_"+ to_string(i);
				z3::expr x2 = c.bool_const(arr.c_str());
				bool outGoingTransition = false;
				exp2 = x2;
				z3::expr exp2a = c.bool_const("exp2a");
				unsigned int count = 1;
				for (auto it2 = neighbor_nodes.begin(); it2 != neighbor_nodes.end(); it2++)
				{
					outGoingTransition = true;
					transition::ptr trans_ptr = *(it2);
					unsigned int loc_id = trans_ptr->getDestinationLocationId();
					arr = "v" + to_string(loc_id) +"_"+ to_string(i+1);
					z3::expr x2 = c.bool_const(arr.c_str());
					if(count == 1)
					{
						exp2a = x2;
					}
					if(count >= 2)
					{
						exp2a = (exp2a || x2);
					}
					count++;
				}
				exp22 = implies(exp2, exp2a);
				if(outGoingTransition)
					this->sol.add(exp22);
				if(!outGoingTransition)
				{
					z3:: expr exp2b = c.bool_val(false);
					this->sol.add(implies(exp2, exp2b));
				}
			}
		}
	}
	if(k1 >= 1)
	{
		for (unsigned int i =0; i <= k1-1; i++)
		{
			for (auto it = list_locations.begin(); it != list_locations.end(); it++)
			{
				auto neighbor_nodes = it->second->getOutGoingTransitions();
				arr = "v"+ to_string(it->first)+"_"+ to_string(i);
				z3::expr x2 = c.bool_const(arr.c_str());
				exp2 = x2;
				z3::expr exp2a = c.bool_const("exp2a");
				bool outGoingTransition = false;
				unsigned int count = 1;
				for (auto it2 = neighbor_nodes.begin(); it2 != neighbor_nodes.end(); it2++)
				{
					outGoingTransition = true;
					transition::ptr trans_ptr = *(it2);
					unsigned int loc_id = trans_ptr->getDestinationLocationId();
					arr = "v" + to_string(loc_id) +"_"+ to_string(i+1);
					z3::expr x2 = c.bool_const(arr.c_str());
					if(count == 1)
					{
						exp2a = x2;
					}
					if(count >= 2)
					{
						exp2a = (exp2a || x2);
					}
					count++;
				}
				exp22 = implies(exp2, exp2a);
				if(outGoingTransition)
					this->sol.add(exp22);
				if(!outGoingTransition)
				{
					z3:: expr exp2b = c.bool_val(false);
					this->sol.add(implies(exp2, exp2b));
				}
			}
		}
	}

	//Exclusivity clause
	z3::expr exp3 = c.bool_const("exp3");
	z3::expr exp33 = c.bool_const("exp33");
	for (unsigned int i =0; i <= k1; i++)
	{
		for(auto it1 = list_locations.begin(); it1 != list_locations.end(); it1++)
		{
			string arr = "v" + to_string(it1->first)+"_" + to_string(i);
			z3::expr x = c.bool_const(arr.c_str());
			exp3 = x;
			z3::expr exp31 = c.bool_const("exp31");
			unsigned int count = 0;
			for(auto it2 = list_locations.begin(); it2 != list_locations.end(); it2++)
			{
				arr = "v" + to_string(it2->first)+"_"+ to_string(i);
				if (it2->first != it1->first)
				{
					z3::expr x1 = c.bool_const(arr.c_str());
					if(count == 0)
					{
						exp31 = !(x1);
					}
					if(count >= 1)
					{
						exp31 = (exp31 && !(x1));
					}
					count++;
				}
			}
			exp33 = implies(exp3, exp31);
			this->sol.add(exp33);
		}
	}						//End of Exclude Constraint.

	//Destination clause
	z3::expr exp4 = c.bool_const("exp4");
	arr = "v" + to_string(v)+"_" + to_string(k1);
	z3::expr x13 = c.bool_const(arr.c_str());
	exp4 = x13;
	this->sol.add(exp4);


      //path purning -all retrieved paths are stored in the p_array data structure(DS). Negates each path from DS and adds them to the solver
	for (unsigned int i = 0; i < p_array.size(); i++)
	{
		z3::expr exp5 = c.bool_const("exp5");
		for (unsigned int j = 0; j < p_array.at(i).size(); j++)
		{
			string arr = "v" + to_string(p_array.at(i).at(j))+"_" + to_string(j);
			z3::expr x = c.bool_const(arr.c_str());
			if (j == 0)
				exp5 = x;
			else if (j == p_array.at(i).size() - 1)
				exp5 = implies(exp5, !(x));
			else
				exp5 = (exp5 && x);
		}
		this->sol.add(exp5);
	}

}

/*
 *  This function encodes the path p as Negation clause of p and add it to SAT solver, 
 *  so that path p or extension of p is not returned further.
 */
void bmc::update_encoding(path p){

	z3::expr exp5 = c.bool_const("exp5");
	string arr = "v" + to_string(p[0])+"_" + to_string(0);
	z3::expr x13 = c.bool_const(arr.c_str());
	exp5 = !(x13);
	for (unsigned int i = 1; i < p.size(); i++)
	{
		arr = "v" + to_string(p[i])+"_" + to_string(i);
		z3::expr x14 = c.bool_const(arr.c_str());
		exp5 = (exp5 || !(x14));
	}	
	this->sol.add(exp5);
}



/*
 * Call SAT solver to check all z3 constraints are satisfied or not. 
 *If SAT,it generates a path from the truthvalue of the model and return the path. 
 */
path bmc::getNextPath(unsigned int k1)
{
	path p;
	auto list_locations = ha_ptr->getAllLocations();

	if (this->sol.check() == z3::sat)
	{
		p.resize(k1+1);
		z3::model m = this->sol.get_model();

		for (unsigned int i = 0; i <= k1; i++)
		{
			for (auto it = list_locations.begin(); it != list_locations.end(); it++)
			{
				string loc = "v" + to_string(it->first) + "_" + to_string(i);
				z3::expr expp = c.bool_const(loc.c_str());
				if(m.eval(expp).is_true())
				{
					p.at(i) = it->first;
					break;
				}
			}
		}
	}
	else
		p.clear();
	return p;
}

/*
 * check a polytope is superset or not using ppl libraries and return true if the first polytope is superset.
 *
 */
bool bmc::containmentChecking(polytope::ptr oldNextInit, polytope::ptr nextInit)
{
	auto matrix_nextInit = nextInit->getCoeffMatrix();
	std::vector<double> vector_nextInit = nextInit->getColumnVector();
	unsigned int row = matrix_nextInit.size1();
	//unsigned int colom = matrix_nextInit.size2(); 

	auto matrix_oldNextInit = oldNextInit->getCoeffMatrix();
	std::vector<double> vector_oldNextInit = oldNextInit->getColumnVector();
	unsigned int row1 = matrix_oldNextInit.size1();
	//unsigned int colom1 = matrix_oldNextInit.size2();
	
	NNC_Polyhedron oldNextInit_poly(ha_ptr->map_size());
	NNC_Polyhedron nextInit_poly(ha_ptr->map_size());

	for(int i = 0; i < row; i++)
	{
		Variable x(0);
		Linear_Expression e = 0*x;
		for(int j = 0; j < ha_ptr->map_size(); j++)
		{
			
			Variable v(j);
			e += matrix_nextInit(i,j)*v;
		}
		Constraint_System c(e <= vector_nextInit.at(i));
					
		nextInit_poly.add_constraints(c);
	} 
	for(int i = 0; i < row1; i++)
	{
		Variable x(0);
		Linear_Expression e = 0*x;
		for(int j = 0; j < ha_ptr->map_size(); j++)
		{
			
			Variable v(j);
			e += matrix_oldNextInit(i,j)*v;
		}
		Constraint_System c(e <= vector_oldNextInit.at(i));
					
		oldNextInit_poly.add_constraints(c);
	} 
	return(oldNextInit_poly.contains(nextInit_poly));	

} 


/*
 * Performs symbolic reachability analysis on a given path p
 * and returns the result as a list of symbolic states.
 * the feasible flag is set false if the path is found not infeasible
 * in the ha dynamics. If the path is feasible, call generate_counterexample
 * routine to get a concreteCE.
 * 
 */

region bmc::getPathReachability(path& p, bool& feasible, forbidden forbid_s, std::list<abstractCE::ptr>& symbolic_ce_list){

	region reach_region;

	assert(p.size()>=1); // The given path must not be empty

	assert(init.size()==1); // Implementation assumption

	template_polyhedra::ptr flowpipe = template_polyhedra::ptr(new template_polyhedra());
	initial_state::ptr ini= *(init.begin());

	polytope::const_ptr init_poly = ini->getInitialSet();
	reach_region.clear();

	path smallest_inf_path;
	smallest_inf_path.push_back(p[0]);

	//Amit
	initial_state::ptr U;
	U = ini;
	symbolic_states::ptr symb_previous;
	
	polytope::ptr nextInit;

	for(unsigned int i=0;i<p.size();i++)
	{
		unsigned int locId = p[i];
		if(i == p.size()-1) { //The last location is the forbidden Location 
			feasible = true;
			polytope::const_ptr forbid_loc_inv = ha_ptr->getLocation(locId)->getInvariant();
			auto current_location = ha_ptr->getLocation(locId);
			flowpipe = postC_fbinterpol(reach_params.Iterations, current_location->getSystemDynamics(), init_poly, reach_params,
				current_location->getInvariant(), current_location->getInvariantExist());

			//creates symbolic state for forbidden location.
			polytope::const_ptr initial_polytope = U->getInitialSet();
			discrete_set d;
			d.insert_element(locId);
			symbolic_states::ptr symb = symbolic_states::ptr(new symbolic_states(d,flowpipe));
			reach_region.push_back(symb);
			symb->setInitialPolytope(initial_polytope);
			symb->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
			symb->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID
			symb_previous = symb; 
			abstractCE::ptr abst_ce = abstractCE::ptr(new abstractCE());
			bool safety_violation = false;
			safety_violation = createAbstractCE(forbid_s, i, locId, flowpipe, symb_previous, symbolic_ce_list, abst_ce);
			if (safety_violation) {	//Safety violation found with the over-approximated flowpipe with the forbidden set
				abst_ce->setUserOptions(user_ops);
				bool continue_search = reach_for_CE.gen_counter_example(abst_ce,user_ops.getCEProc());
				if (continue_search == false) {
					cout<<"Concrete Counter Example Found Successfully!!"<<endl;
					return reach_region;
				}
				else //When path is feasiable but can't find CE, then go to the solver to check another path
				{
					std::cout<<"can't find CE"<<endl;
					//std::cout << "Time to search CE:" << reach_for_CE.get_ce_search_time() / (double) 1000 << std::endl;
					feasible = false;
				}
					
			}
			break;
		}
		polytope::const_ptr initial_polytope = U->getInitialSet();
		auto current_location = ha_ptr->getLocation(locId);
		initialSetInLocation = make_pair(locId,init_poly); // Initial set in locId. 
		auto it = flowForInit.find(initialSetInLocation);
		if(it == flowForInit.cend())
			flowpipe = postC_fbinterpol(reach_params.Iterations, current_location->getSystemDynamics(), init_poly, reach_params,
				current_location->getInvariant(), current_location->getInvariantExist());
		else 
			flowpipe = (*it).second;   // If Inittial set for locId is already computed.
	
		flowForInit.insert({initialSetInLocation, flowpipe});	// store flow for specific intial set.		
		transition::ptr path_transition = nullptr;
		unsigned int nextLocId;
		auto out_transitions = current_location->getOutGoingTransitions();
		for(std::list<transition::ptr>::const_iterator it = out_transitions.begin();it!=out_transitions.end();it++)
		{
			nextLocId = (*it)->getDestinationLocationId();
			if(nextLocId == p[i+1])
			{
				smallest_inf_path.push_back(nextLocId);
				path_transition = *it;
				break;
			}
		}
		discrete_set d;
		d.insert_element(locId);
		symbolic_states::ptr symb = symbolic_states::ptr(new symbolic_states(d,flowpipe));
		reach_region.push_back(symb);
		symb->setInitialPolytope(initial_polytope);
		symb->setParentPtrSymbolicState(U->getParentPtrSymbolicState()); //keeps track of parent pointer to symbolic_states
		symb->setTransitionId(U->getTransitionId()); //keeps track of originating transition_ID
		symb_previous = symb;

		unsigned int transId = path_transition->getTransitionId();
		polytope::ptr shift_polytope;
		flowWithTrans_id = make_pair(flowpipe, transId); // make a pair flow with out going trans_id.
		auto iterator = nextInitForFlowWithT_id.find(flowWithTrans_id);
		// Found a initial set for a specific flow with outgoing transition. 
		if (iterator != nextInitForFlowWithT_id.cend())
		{
			nextInit = (*iterator).second.second;
			init_poly = nextInit;  // skip the computation of next intial set.
			initial_state::ptr newState = initial_state::ptr(new initial_state(nextLocId, nextInit));  //shift_polytope
			newState->setTransitionId(path_transition->getTransitionId()); // keeps track of the transition_ID
			newState->setParentPtrSymbolicState(symb);
			U = newState;
			continue;
		}
		else
		{
			assert(path_transition!=nullptr);

			auto next_location = ha_ptr->getLocation(nextLocId);

			polytope::const_ptr trans_guard = path_transition->getGuard();

			std::string postd_aggregation = user_ops.getSetAggregation();
			std::list<polytope::ptr> polys;
			polytope::const_ptr inv = current_location->getInvariant();

			bool aggregation=true; // set aggregation is set to true by default.

			if (boost::iequals(postd_aggregation,"thull") || boost::iequals(postd_aggregation,"chull")){
				aggregation=true;

			} else if (boost::iequals(postd_aggregation,"none")){
				aggregation=false;
			}

			assert(trans_guard!=nullptr);

			if (!trans_guard->getIsEmpty()){

				if(boost::iequals(postd_aggregation,"thull") || boost::iequals(postd_aggregation,"none")){
					polys = flowpipe->flowpipe_intersectionSequential(aggregation, trans_guard, 1);
				}
				else if(boost::iequals(postd_aggregation,"chull")){
					polys = flowpipe->postD_chull(trans_guard, inv, 1);
				}

			} else { // empty guard
				DEBUG_MSG("bmc::getPathRegion: Guard Set is empty. It means that the guard condition is unsatisfiable. \n");
				exit(0);
			}
			// apply transition map
			assert(polys.size()<=1);
			

			if (polys.size() == 0){
				feasible = false;
				break;
			}

			// Intersect with guard
			polytope::ptr g_flowpipe_intersect;
			polytope::ptr hull_poly = *(polys.begin());

			if(boost::iequals(postd_aggregation,"thull") || boost::iequals(postd_aggregation,"none")){

				if(!trans_guard->getIsUniverse()){
					g_flowpipe_intersect = hull_poly->GetPolytope_Intersection(trans_guard);
				} else{
					g_flowpipe_intersect = hull_poly;
				}
			}
			else // chull aggregation. no need to intersect with guard.
				g_flowpipe_intersect = hull_poly;

			Assign& t_map = path_transition->getAssignT();
			

			if (t_map.Map.isInvertible()) {
				shift_polytope = post_assign_exact(g_flowpipe_intersect, t_map.Map, t_map.b);
			} else {
				shift_polytope = post_assign_approx_deterministic(g_flowpipe_intersect,
						t_map.Map, t_map.b, reach_params.Directions,1);
			}
			// The newShifted must satisfy the destination location invariant
			if (next_location->getInvariant()!=NULL) { // ASSUMPTION IS THAT NULL INV=> UNIVERSE INV
				shift_polytope = shift_polytope->GetPolytope_Intersection(next_location->getInvariant());
			}

			if(shift_polytope->getIsEmpty()){
				feasible = false;
				break; // test for other initial regions
			}


			init_poly = shift_polytope;  // set initial set for the next location.
			nextInit = shift_polytope;
		
		
			int destination_locID = path_transition->getDestinationLocationId();
			initial_state::ptr newState = initial_state::ptr(new initial_state(destination_locID, nextInit));
			newState->setTransitionId(path_transition->getTransitionId()); // keeps track of the transition_ID
			newState->setParentPtrSymbolicState(symb);
			U = newState;
	
			polytope::ptr oldNextInit;
			for(auto it = nextInitForFlowWithT_id.cbegin(); it != nextInitForFlowWithT_id.cend(); ++it)
			{
				if((*it).second.first == nextLocId)
				{
					//std::cout<<"\033[31mInit stored in location id:"<<nextLocId<<"\033[0m"<<endl;
					oldNextInit = (*it).second.second;
					bool contain = containmentChecking(oldNextInit,nextInit); // checking oldNextInit is superset or not using ppl.
					if(contain)
					{
						nextInit = oldNextInit;  //taking superset...
						std::cout<<"\033[32mfound superset\033[0m"<<endl;
					}
					else
						std::cout<<"\033[31msuperset not found \033[0m"<<endl;
				}
			}
			// store initial set of the next location for flow with incoming trans-id.
			flowWithTrans_id = make_pair(flowpipe, transId);
			nextInitialIn_nextLoc = make_pair(nextLocId,nextInit);
			nextInitForFlowWithT_id.insert({flowWithTrans_id, nextInitialIn_nextLoc}); 

		}		
		

	}
	p = smallest_inf_path;
	
	return reach_region;


}

bool bmc::createAbstractCE(forbidden forbidden_set, unsigned int i, unsigned int current_locId,
		template_polyhedra::ptr reach_region, symbolic_states::ptr S,
		std::list<abstractCE::ptr> &symbolic_ce_list, abstractCE::ptr abst_ce) {

	bool safety_violation = false;
	int locID = current_locId;
	/*Debug:
	std::cout << "forbidden_set.loc = " << forbidden_set.first << std::endl;
	std::cout << "current.loc = " << locID << std::endl; */
	std::list < symbolic_states::ptr > list_sym_states;
	std::list < transition::ptr > list_transitions; // list of transitions leading to the unsafe set



	if (forbidden_set.first==-1 || locID == forbidden_set.first) { // forbidden locID matches. loc id of -1 means any location
		polytope::ptr forbid_poly = forbidden_set.second;
		std::list <template_polyhedra::ptr > forbid_intersects;
		forbid_intersects.push_back(reach_region);
		//forbid_intersects = reach_region->polys_intersectionSequential(forbid_poly, 1);
		//std::cout<<"intersect:"<<forbid_intersects.size()<<endl;
		
		if (forbid_intersects.size() != 0) {
			safety_violation = true;
			symbolic_states::ptr symb_state_in_abst_ce; // This is a pointer to the current symbolic state in the abstract ce.
			symb_state_in_abst_ce = S;
			int symbolic_ce_length = 0;
			do {
				unsigned int locationID2=0;
				discrete_set ds, ds2;
				int transID = symb_state_in_abst_ce->getTransitionId();
				list_sym_states.push_front(symb_state_in_abst_ce); //pushing the unsafe symbolic_state first
				if (symb_state_in_abst_ce->getParentPtrSymbolicState() != NULL) { //searching only if not NULL
					symb_state_in_abst_ce = symb_state_in_abst_ce->getParentPtrSymbolicState();
					ds2 = symb_state_in_abst_ce->getDiscreteSet();
					for (std::set<int>::iterator it = ds2.getDiscreteElements().begin(); it != ds2.getDiscreteElements().end(); ++it)
						locationID2 = (*it);
					location::const_ptr object_location;
					object_location = ha_ptr->getLocation(locationID2);
					transition::ptr temp = object_location->getTransition(transID);
					list_transitions.push_front(temp); //pushing the transition in the stack
				}
				symbolic_ce_length++;
			} while (symb_state_in_abst_ce->getParentPtrSymbolicState()!= NULL);
			if ((symbolic_ce_length >= 1) && (symb_state_in_abst_ce->getParentPtrSymbolicState()== NULL)) { //root is missed
				list_sym_states.push_front(symb_state_in_abst_ce); //1) pushing this new symb state at the beginning
			}

			abst_ce->set_length(symbolic_ce_length);
			abst_ce->set_sym_states(list_sym_states);
			abst_ce->set_transitions(list_transitions);
			abst_ce->set_automaton(&(*ha_ptr));
			abst_ce->set_forbid_poly(forbidden_set.second);
			symbolic_ce_list.push_back(abst_ce); // This abstract counter-example path is added to the list of all such identified paths.
		}
	}
	return safety_violation;
}



unsigned int bmc::safe(){
	int cnt = 0;
	region r;
	std::list<abstractCE::ptr> symbolic_ce_list;
	reach_for_CE.setReachParameter(*(ha_ptr), init, reach_params, 1, forbidden_s, user_ops);
	// iterate over the forbidden states
	for(unsigned int i=0;i<forbidden_s.size();i++){
		forbidden forbid_s = forbidden_s[i];
		unsigned int forbid_loc_id = forbid_s.first;
		for (unsigned int k1 = 0; k1 <= k; k1++)
		{
			init_solver(forbid_loc_id, k1); // initialize the ha_encoding for this forbidden location
			path p = getNextPath(k1);
			while(p.size()!=0){ // A path is returned above
				cnt++;
				/*//debug
				std::cout << "The path p is "<< std::endl;
				for(unsigned int i=0;i<p.size();i++){
					std::cout << p[i] << " " ;
				}
				std::cout << std::endl; */ 
				bool feasible = false;
				r = getPathReachability(p,feasible, forbid_s, symbolic_ce_list);
				//debug
				/* std::cout << "The smallest infeasible path is:\n";
				for(unsigned int i=0;i<p.size();i++){
					std::cout << p[i] << " " ;
				}
				std::cout << std::endl; */
				p_array.resize(p_array.size()+1);
				p_array.push_back(p);
				if(!feasible)
					update_encoding(p); // update the encoding such that no path containing p is returned further.
				else{
					print_bmc_ce_statistics(reach_for_CE, symbolic_ce_list, user_ops, "Safety Analysis");
					std::cout<< "\nTotal paths visited by our Algorithm: "<<cnt<<endl;
					show(r, user_ops);
					return 0; // the model is unsafe
				}
				p = getNextPath(k1);		
			}
			this->sol.reset();
		}
	}
	print_bmc_ce_statistics(reach_for_CE, symbolic_ce_list, user_ops, "Safety Analysis");
	std::cout<< "\nTotal paths visited by our Algorithm: "<<cnt<<endl;
	show(r, user_ops);
	if(symbolic_ce_list.size()==0 && reach_for_CE.get_counter_examples().size()==0)
	{
		return 1; //model is safe
	}
	if(symbolic_ce_list.size()>0 && reach_for_CE.get_counter_examples().size()==0)
	{
		return 2; // model is unknown
	}
}
