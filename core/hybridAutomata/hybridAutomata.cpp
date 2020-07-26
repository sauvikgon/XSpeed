/*
 * HybridAutomata.cpp
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#include <core/hybridAutomata/hybridAutomata.h>
#include "z3++.h"
#include <fstream> 
#include <string>

using namespace std;
using namespace z3;

hybrid_automata::hybrid_automata() {
	dimension = 0;
}
hybrid_automata::hybrid_automata(std::map<int, location::ptr>& list_locs, location::ptr init_loc,
		int dim) {
	list_locations = list_locs;	//assigning a map to another map
	initial_loc = init_loc;
	dimension = dim;
}

location::ptr& hybrid_automata::getInitialLocation() {
	return initial_loc;
}

void hybrid_automata::addInitialLocation(location::ptr& initLoc) {
	initial_loc = initLoc;
}

void hybrid_automata::setInitialLoc(int loc_id)
{
	location::ptr init_loc_ptr = this->getLocation(loc_id);
	addInitialLocation(init_loc_ptr);
}

location::ptr hybrid_automata::getLocation(int Loc_Id){
	assert(list_locations.count(Loc_Id)!=0);
	location::ptr l;
	l = list_locations[Loc_Id];
	return l;
}

/* returns the location from the list of locations with locName */
location::ptr hybrid_automata::getLocation(string locName){

	std::map<int, location::ptr>::iterator locMapIter;

	for(locMapIter = list_locations.begin();locMapIter!=list_locations.end(); locMapIter++){
		std::pair<int, location::ptr> map_elem = *locMapIter;
		location::ptr l = this->getLocation(map_elem.first);
		string name = l->getName();
		if(locName.compare(name)==0)
			return l;
	}
	throw std::runtime_error("hybrid_automata: getLocation: No location with the asked location name\n");
}

int hybrid_automata::getDimension() const {
	return dimension;
}

void hybrid_automata::setDimension(int dim) {
	this->dimension = dim;
}

void hybrid_automata::addMappedLocationsList(std::map<int, location::ptr>& mapped_location_list){
	list_locations = mapped_location_list;
}
void hybrid_automata::addLocation(location::ptr& loc){
	int key = loc->getLocId();
	list_locations[key] = loc;	//storing the loc with the proper loc_id as the key
}

std::list<structuralPath::ptr> hybrid_automata::getStructuralPaths(unsigned int forbidden_loc_id, unsigned int depth)
{
	std::list<structuralPath::ptr> path_list; // It is empty here.

	unsigned int srcLoc = getInitialLocation()->getLocId();
	unsigned int destLoc = forbidden_loc_id;
	path_list = findAllPaths(srcLoc, destLoc, depth);

	return path_list;
}

void satEnumPaths(unsigned int forbidden_loc_id, unsigned int depth)
{

	location::ptr *source_ptr = getInitialLocation();
	int u = source_ptr->loc_id;
	int v = forbidden_loc_id;
	int k = depth;

	context c;

	// INIT Step

	expr exp1 = c.bool_const("exp1");
	string arr = "v" + to_string(u) + "0";
	int l = arr.length();
	char array[l];
	for (int i = 0 ; i < l; i++)
		array[i] = char(arr[i]);
	expr x = c.bool_const(array);
	exp1 = x;

	for(auto it = list_locations.begin(); it != list_locations.end(); it++)
	{
		arr = "v" + to_string(it->first) + "0";
		l = arr.length();
		char array1[l];
		for (int i = 0 ; i < l; i++)
			array1[i] = char(arr[i]);
		if (it->first != u)
		{
			expr x1 = c.bool_const(array1);
			exp1 = (exp1 && !(x1));
		}
	}
		
	// NEXT Step

	expr exp2 = c.bool_const("exp2");
	auto it = list_locations.begin();
	auto neighbor_nodes = it->second.getOutGoingTransitions();
	expr exp2a = c.bool_const("exp2a");
	arr = "v" + to_string(neighbor_nodes.begin()->destination_location_id) + to_string(1);
	l = arr.length();
	char array2[l];
	for (int i = 0 ; i < l; i++)
		array2[i] = char(arr[i]);
	expr x2 = c.bool_const(array2);
	exp2a = x2;
	for (auto it2 = neighbor_nodes.begin() + 1; it2 != neighbor_nodes.end(); it2++)
	{
		arr = "v" + to_string(it2->destination_location_id) + to_string(i+1);
		l = arr.length();
		char array3[l];
		for (int j = 0 ; j < l; j++)
			array3[j] = char(arr[j]);
		expr x3 = c.bool_const(array3);
		exp2a = (exp2a || x3);
	}
	arr = "v" + to_string(it1->first) + to_string(i);
	l = arr.length();
	char array4[l];
	for (int i = 0 ; i < l; i++)
		array4[i] = char(arr[i]);
	expr x4 = c.bool_const(array4);
	exp2 = implies(x4, exp2a);

	for (int i = 0; i < k; i++)
	{
		for (auto it1 = list_locations.begin() + 1; it1 != list_locations.end(); it1++)
		{
			auto neighbor_nodes = it1->second.getOutGoingTransitions();
			expr exp2b = c.bool_const("exp2b");
			arr = "v" + to_string(neighbor_nodes.begin()->destination_location_id) + to_string(i+1);
			l = arr.length();
			char array5[l];
			for (int j = 0 ; j < l; j++)
				array5[j] = char(arr[j]);
			expr x5 = c.bool_const(array5);
			exp2b = x5;
			for (auto it2 = neighbor_nodes.begin() + 1; it2 != neighbor_nodes.end(); it2++)
			{
				arr = "v" + to_string(it2->destination_location_id) + to_string(i+1);
				l = arr.length();
				char array6[l];
				for (int j = 0 ; j < l; j++)
					array6[j] = char(arr[j]);
				expr x6 = c.bool_const(array6);
				exp2b = (exp2b || x6);
			}
			arr = "v" + to_string(it1->first) + to_string(i);
			l = arr.length();
			char array7[l];
			for (int j = 0 ; j < l; j++)
				array7[j] = char(arr[j]);
			expr x7 = c.bool_const(array7);
			exp2 = (exp2 && implies(x7, exp2b));
		}
	}

	// EXCLUDE Step

	expr exp3 = c.bool_const("exp3");
	auto it = list_locations.begin();
	arr = "v" + to_string(it->first) + "0";
	l = arr.length();
	char array8[l];
	for (int i = 0 ; i < l; i++)
		array8[i] = char(arr[i]);
	expr x8 = c.bool_const(array8);
	exp3 = x8;

	for (auto it1 = list_locations.begin(); it1 != list_locations.end(); it1++)
	{
		expr exp3a = c.bool_const("exp3a");
		arr = "v" + to_string(it->first) + to_string(1);
		l = arr.length();
		char array9[l];
		for (int i = 0 ; i < l; i++)
			array9[i] = char(arr[i]);
		expr x9 = c.bool_const(array9);
		exp3a = !x9;
		
		for (auto it2 = list_locations.begin(); it2 != list_locations.end(); it2++)
		{
			if (it2->first != it1->first)
			{
				arr = "v" + to_string(it2->first) + to_string(1);
				l = arr.length();
				char array10[l];
				for (int j = 0 ; j < l; j++)
					array10[j] = char(arr[j]);
				expr x10 = c.bool_const(array10);
				exp3a = (exp3a && !(x10));
			}
		}
		exp3 = (exp3 && implies(x9, exp3a));
	}

	for (int i = 1; i < k; i++)
	{
		for (auto it1 = list_locations.begin(); it1 != list_locations.end(); it1++)
		{
			expr exp3b = c.bool_const("exp3b");
			arr = "v" + to_string(it->first) + to_string(i+1);
			l = arr.length();
			char array11[l];
			for (int j = 0 ; j < l; j++)
				array11[j] = char(arr[j]);
			expr x11 = c.bool_const(array11);
			exp3b = !x11;
			
			for (auto it2 = list_locations.begin(); it2 != list_locations.end(); it2++)
			{
				if (it2->first != it1->first)
				{
					arr = "v" + to_string(it2->first) + to_string(i+1);
					l = arr.length();
					char array12[l];
					for (int j = 0 ; j < l; j++)
						array12[j] = char(arr[j]);
					expr x12 = c.bool_const(array12);
					exp3b = (exp3b && !(x12));	
				}
			}
			exp3 = (exp3 && implies(x11, exp3b));
		}
	}

	// TARGET Step

	expr exp4 = c.bool_const("exp4");
	arr = "v" + to_string(v) + "0";
	l = arr.length();
	char array13[l];
	for (int i = 0 ; i < l; i++)
		array13[i] = char(arr[i]);
	expr x13 = c.bool_const(array13);
	exp4 = x13;

	for (int i = 1; i <= k; i++)
	{
		arr = "v" + to_string(v) + to_string(i);
		l = arr.length();
		char array14[l];
		for (int j = 0 ; j < l; j++)
			array14[j] = char(arr[j]);
		expr x14 = c.bool_const(array14);
		exp4 = (exp4 || x14);
	}

	solver s(c);
	s.add(exp1);
	s.add(exp2);
	s.add(exp3);
	s.add(exp4);

	// Writing the solution to a new file

	ofstream fout;
	fout.open("NewDataFile.txt");
	if (s.check() == unsat)
		fout<<"unsat";
	else
	{	
		model m = s.get_model();
		fout<<m<<"\n";
	}
	fout.close();
}

void hybrid_automata::printPath(vector<int>& path) {
	int size = path.size();
	for (int i = 0; i < size; i++)
		cout << path[i] << " ";
	cout << endl;
}

std::list<structuralPath::ptr> hybrid_automata::findAllPaths(int src, int dst, int depthBound) {
	std::list<structuralPath::ptr> allStructralPaths;

	std::pair<vector<int>, vector<transition::ptr> > pathDS;//pair of (vector of locIDs, vector of transIDs)
	queue<std::pair<vector<int>, vector<transition::ptr> > > q;

	// path vector to store the current path
	vector<int> path;
	path.push_back(src);
	pathDS.first = path;
	vector<transition::ptr> trans;
	pathDS.second = trans;
	q.push(pathDS);

	while (!q.empty()) {
		pathDS = q.front();
		q.pop();
		int last = pathDS.first[pathDS.first.size() - 1];
		if (last == dst) {
			//std::cout << " Solution path: ";
			//printpath(pathDS.first);
			std::list<location::ptr> path_locations;
			for (int i = 0; i < pathDS.first.size(); i++) {
				path_locations.push_back(getLocation(pathDS.first[i]));
			}
			std::list<transition::ptr> path_transitions;
			for (int i = 0; i < pathDS.second.size(); i++) {
				path_transitions.push_back(pathDS.second[i]);
			}
			structuralPath::ptr solutionPath = structuralPath::ptr(new structuralPath(path_locations, path_transitions));
			allStructralPaths.push_back(solutionPath);
			//Disable instruction continue to avoid repeated bad location (applicable for discrete systems)
			//continue;	//avoiding traversing further from here: bad location not repeated (applicable for hybrid systems)
		}
		// traverse to all the nodes connected to
		// current node and push new path to queue
		location::ptr lastLoc = getLocation(last); //Note:: todo take care if last does not exist (if error occurs)
		std::list<transition::ptr> allOutTrans = lastLoc->getOutGoingTransitions();
		std::list<transition::ptr>::iterator it;
		for (it = allOutTrans.begin(); it != allOutTrans.end(); it++) {
			// if (isNotVisited(g[last][i], path)) {    //enable this if to avoid Cycle
			vector<int> newpath(pathDS.first);	//copy constructor
			newpath.push_back((*it)->getDestinationLocationId());
			vector<transition::ptr> newtrans(pathDS.second);	//copy constructor
			newtrans.push_back((*it));
			int depthExplored = newpath.size();    //Size of the path
			if (depthExplored == (depthBound+1))	//Allows path of length depthBound but not (depthBound+1)
				break;
			std::pair<vector<int>, vector<transition::ptr> > new_pathDS;
			new_pathDS.first = newpath;
			new_pathDS.second = newtrans;
			q.push(new_pathDS);
			//}
		}
	}
	return allStructralPaths;
}
