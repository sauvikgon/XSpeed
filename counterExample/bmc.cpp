/*
 * bmc.cpp
 *
 *  Created on: 14-Sep-2020
 *      Author: rajarshi
 */

#include <counterExample/bmc.h>

bmc::bmc() {
	// TODO Auto-generated constructor stub
}

bmc::~bmc() {
	// TODO Auto-generated destructor stub
}

bmc::bmc(hybrid_automata* ha_ptr, forbidden_states& forbidden, unsigned int k){
	this->ha = ha_ptr;
	this->forbidden_s = forbidden;
	this->k = k;
}

/*
 * Initializes the z3 solver with bounded ha encoding.
 */
void bmc::init_solver(unsigned int forbidden_loc_id)
{
	location::ptr source_ptr = ha->getInitialLocation();
	int u = source_ptr->getLocId();
	unsigned int v = forbidden_loc_id;
	unsigned int k = this->k;
	auto list_locations = ha->getAllLocations();

	// INIT Step
	z3::expr exp1 = c.bool_const("exp1");
	string arr = "v" + to_string(u)+"_"+ "0";
	unsigned int l = arr.length();
	char array[l];
	for (unsigned int i = 0 ; i < l; i++)
		array[i] = char(arr[i]);
	z3::expr x = c.bool_const(array);
	exp1 = x;
	for(auto it = list_locations.begin(); it != list_locations.end(); it++)
	{
		arr = "v" + to_string(it->first)+"_"+ "0";
		l = arr.length();
		char array1[l];
		for (unsigned int i = 0 ; i < l; i++)
			array1[i] = char(arr[i]);
		if (it->first != u)
		{
			z3::expr x1 = c.bool_const(array1);
			exp1 = (exp1 && !(x1));
		}
	}
	this->sol.add(exp1);

	// NEXT Step

	z3::expr exp2 = c.bool_const("exp2");
	z3::expr exp22 = c.bool_const("exp22");
	if(k == 0)
	{
		for (unsigned int i =0; i <= k; i++)
		{

			for (auto it = list_locations.begin(); it != list_locations.end(); it++)
			{
				auto neighbor_nodes = it->second->getOutGoingTransitions();
				arr = "v"+ to_string(it->first)+"_"+ to_string(i);
				l = arr.length();
				char array2[l];
				for (unsigned int j = 0 ; j < l; j++)
					array2[j] = char(arr[j]);
				z3::expr x2 = c.bool_const(array2);
				exp2 = x2;
				z3::expr exp2a = c.bool_const("exp2a");
				unsigned int count = 1;
				for (auto it2 = neighbor_nodes.begin(); it2 != neighbor_nodes.end(); it2++)
				{
					transition::ptr trans_ptr = *(it2);
					unsigned int loc_id = trans_ptr->getDestinationLocationId();
					arr = "v" + to_string(loc_id) +"_"+ to_string(i+1);
					l = arr.length();
					char array2[l];
					for (unsigned int j = 0 ; j < l; j++)
						array2[j] = char(arr[j]);
					z3::expr x2 = c.bool_const(array2);
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
				this->sol.add(exp22);
			}
		}
	}
	if(k >= 1)
	{
		for (unsigned int i =0; i <= k-1; i++)
		{
			for (auto it = list_locations.begin(); it != list_locations.end(); it++)
			{
				auto neighbor_nodes = it->second->getOutGoingTransitions();
				arr = "v"+ to_string(it->first)+"_"+ to_string(i);
				l = arr.length();
				char array2[l];
				for (unsigned int j = 0 ; j < l; j++)
					array2[j] = char(arr[j]);
				z3::expr x2 = c.bool_const(array2);
				exp2 = x2;
				z3::expr exp2a = c.bool_const("exp2a");
				unsigned int count = 1;
				for (auto it2 = neighbor_nodes.begin(); it2 != neighbor_nodes.end(); it2++)
				{
					transition::ptr trans_ptr = *(it2);
					unsigned int loc_id = trans_ptr->getDestinationLocationId();
					arr = "v" + to_string(loc_id) +"_"+ to_string(i+1);
					l = arr.length();
					char array2[l];
					for (unsigned int j = 0 ; j < l; j++)
						array2[j] = char(arr[j]);
					z3::expr x2 = c.bool_const(array2);
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
				this->sol.add(exp22);
			}
		}
	}

	//EXCLUDE
	z3::expr exp3 = c.bool_const("exp3");
	z3::expr exp33 = c.bool_const("exp33");
	for (unsigned int i =0; i <= k; i++)
	{
		for(auto it1 = list_locations.begin(); it1 != list_locations.end(); it1++)
		{
			string arr = "v" + to_string(it1->first)+"_" + to_string(i);
			unsigned int l = arr.length();
			char array[l];
			for (unsigned int ii = 0 ; ii < l; ii++)
				array[ii] = char(arr[ii]);
			z3::expr x = c.bool_const(array);
			exp3 = x;
			z3::expr exp31 = c.bool_const("exp31");
			unsigned int count = 0;
			for(auto it2 = list_locations.begin(); it2 != list_locations.end(); it2++)
			{
				arr = "v" + to_string(it2->first)+"_"+ to_string(i);
				l = arr.length();
				char array1[l];
				for (unsigned int ii = 0 ; ii < l; ii++)
					array1[ii] = char(arr[ii]);
				if (it2->first != it1->first)
				{
					z3::expr x1 = c.bool_const(array1);
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
	arr = "v" + to_string(v)+"_" + to_string(k);
	l = arr.length();
	char array13[l];
	for (unsigned int i = 0 ; i < l; i++)
		array13[i] = char(arr[i]);
	z3::expr x13 = c.bool_const(array13);
	exp4 = x13;
	this->sol.add(exp4);

	//Returning the path vector to checkfeasibility()
	path p;
	if (this->sol.check() == z3::sat)
	{
		p.resize(k);
		z3::model m = this->sol.get_model();
		for (unsigned int i = 0; i <= k; i++)
		{
			for (auto it = list_locations.begin(); it != list_locations.end(); it++)
			{
				arr = "v" + to_string(it->first)+"_" + to_string(i);
				l = arr.length();
				char array14[l];
				for (unsigned int i = 0 ; i < l; i++)
					array14[i] = char(arr[i]);
				z3::expr expp = c.bool_const(array14);
				if(m.eval(expp))
				{
					p.at(i) = it->first;
					break;
				}
			}
		}
		//return p;
	}

	else
	{
		p.resize(1);
		p.at(0) = list_locations.begin()->first;
		//return p;
	}
}
/*
 *
 */
path bmc::getNextPath()
{
	
}

/*
 * Performs symbolic reachability analysis on a given path p
 * and return the result as a list of symbolic states.
 */
region bmc::getPathRegion(path p){
	region r;
	return r;
}

void bmc::update_encoding(path p){

}

bool bmc::isSafe(){

	// iterate over the forbidden states
	for(unsigned int i=0;i<forbidden_s.size();i++){
		forbidden forbid_s = forbidden_s[i];
		unsigned int forbid_loc_id = forbid_s.first;
		init_solver(forbid_loc_id); // initialize the ha_encoding for this forbidden location

		path p = getNextPath();
		while(p.size()!=0){ // A path is returned above
			// do something smart
			update_encoding(p); // update the encoding such that no path containing p is returned further.
			p = getNextPath();
		}
	}
	return true; // no counterexample trajectory could be found. Hence returning safe.
}
