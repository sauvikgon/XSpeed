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

bmc::bmc(const hybrid_automata& ha, const std::list<initial_state::ptr>& init,
		const forbidden_states& forbidden, const ReachabilityParameters& r_params,
		const userOptions& user_ops) : ha(ha), init(init), forbidden_s(forbidden),
				reach_params(r_params), user_ops(user_ops), c(), ha_encoding(c), sol(c){
	this->k = user_ops.get_bfs_level();
}

/*
 * Initializes the z3 solver with bounded ha encoding.
 */
void bmc::init_solver(unsigned int forbidden_loc_id, unsigned int k1)
{
	location::ptr source_ptr = ha.getInitialLocation();
	int u = source_ptr->getLocId();
	unsigned int v = forbidden_loc_id;
	auto list_locations = ha.getAllLocations();

	// INIT Step
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

	// NEXT Step

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

	//EXCLUDE
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

	//TARGET
	z3::expr exp4 = c.bool_const("exp4");
	arr = "v" + to_string(v)+"_" + to_string(k1);
	z3::expr x13 = c.bool_const(arr.c_str());
	exp4 = x13;
	this->sol.add(exp4);

}
/*
 *
 */
path bmc::getNextPath(unsigned int k1)
{
	path p;
	auto list_locations = ha.getAllLocations();

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
 * Performs symbolic reachability analysis on a given path p
 * and returns the result as a list of symbolic states.
 * the feasible flag is set false if the path is found not reachable
 * in the ha dynamics.
 */
region bmc::getPathRegion(path p, bool& feasible){

	region reach_region;
	feasible = false;
	//debug
	std::cout << "The path p is "<< std::endl;
	for(unsigned int i=0;i<p.size();i++){
		std::cout << p[i] << " " ;
	}
	std::cout << std::endl;
	return reach_region;

	//--
	for(auto it = init.begin(); it!=init.end();it++){
		template_polyhedra::ptr flowpipe;
		initial_state::ptr ini= *it;
		polytope::const_ptr init_poly = ini->getInitialSet();

		for(unsigned int i=0;i<p.size();i++){

			unsigned int locId = p[i];
			auto current_location = ha.getLocation(locId);
			flowpipe = postC_fbinterpol(reach_params.Iterations, current_location->getSystemDynamics(), init_poly, reach_params,
					current_location->getInvariant(), current_location->getInvariantExist());

			discrete_set d;
			d.insert_element(locId);
			symbolic_states::ptr symb = symbolic_states::ptr(new symbolic_states(d,flowpipe));
			reach_region.push_back(symb);

			if(i == p.size()-1){
				feasible = true;
				break;
			}
			// apply postD on this flowpipe
			transition::ptr path_transition = NULL;
			unsigned int nextLocId;
			auto out_transitions = current_location->getOutGoingTransitions();
			for(std::list<transition::ptr>::const_iterator it = out_transitions.begin();
					it!=out_transitions.end();it++){
				nextLocId = (*it)->getDestinationLocationId();
				if(nextLocId == p[i+1]){
					path_transition = *it;
					break;
				}
			}

			assert(path_transition!=NULL);
			auto next_location = ha.getLocation(nextLocId);

			polytope::ptr trans_guard = path_transition->getGuard();
			std::string postd_aggregation = user_ops.getSetAggregation();
			std::list<polytope::ptr> polys;
			polytope::const_ptr inv = current_location->getInvariant();

			bool aggregation=true; // set aggregation is set to true by default.

			if (boost::iequals(postd_aggregation,"thull") || boost::iequals(postd_aggregation,"chull")){
				aggregation=true;

			} else if (boost::iequals(postd_aggregation,"none")){
				aggregation=false;
			}

			if (!trans_guard->getIsEmpty()){

				if(boost::iequals(postd_aggregation,"thull") || boost::iequals(postd_aggregation,"none")){
					polys = flowpipe->flowpipe_intersectionSequential(aggregation, trans_guard, 1);
				}
				else if(boost::iequals(postd_aggregation,"chull")){
					polys = flowpipe->postD_chull(trans_guard, inv, 1);
				}

			} else{ // empty guard
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

				polytope::const_ptr trans_g_const = polytope::const_ptr(trans_guard.get());
				if(!trans_guard->getIsUniverse()){
					g_flowpipe_intersect = hull_poly->GetPolytope_Intersection(trans_g_const);
				} else{
					g_flowpipe_intersect = hull_poly;
				}
			}
			else // chull aggregation. no need to intersect with guard.
				g_flowpipe_intersect = hull_poly;

			Assign& t_map = path_transition->getAssignT();
			polytope::ptr shift_polytope;

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

			init_poly = polytope::const_ptr(shift_polytope.get());
		}

		if(feasible)
			break;
	}
	return reach_region;
}

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

bool bmc::safe(){
	int cnt = 0;
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
				//debug
				std::cout << "The path p is "<< std::endl;
				for(unsigned int i=0;i<p.size();i++){
					std::cout << p[i] << " " ;
				}
				std::cout << std::endl;
				update_encoding(p);
				//bool feasible = false;
				//region r = getPathRegion(p,feasible);
			//	show(r, user_ops);
			//	exit(0);
	
			//	if(!feasible)
			//		update_encoding(p); // update the encoding such that no path containing p is returned further.
			//	else{
					// search for a concrete ce trajectory using the path region r
					//print the path region
	
			//	}
				p = getNextPath(k1);
		
			}
			this->sol.reset();
		}
	}
	std::cout << "Total paths = " << cnt << std::endl;
	return true; // no counterexample trajectory could be found. Hence returning safe.
}
