/*
 * HybridAutomata.cpp
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#include "Hybrid_Automata.h"

using namespace std;

hybrid_automata::hybrid_automata() {
	dimension = 0;
}
hybrid_automata::hybrid_automata(std::map<int, location::ptr>& list_locs, location::ptr init_loc,
		int dim) {
	list_locations = list_locs;	//assigning a map to another map
	initial_loc = init_loc;
	dimension = dim;
}

location::ptr& hybrid_automata::getInitial_Location() {
	return initial_loc;
}

void hybrid_automata::addInitial_Location(location::ptr& initLoc) {
	initial_loc = initLoc;
}

location::ptr hybrid_automata::getLocation(int Loc_Id){
	//iterate through the transition and find for given input Name that match with the source_location
	assert(list_locations.count(Loc_Id)!=0);
	location::ptr l;
	l = list_locations[Loc_Id];
//	std::cout<<"\ntest 3\n";
	return l;
}

int hybrid_automata::getDimension() const {
	return dimension;
}

void hybrid_automata::setDimension(int dim) {
	this->dimension = dim;
}

void hybrid_automata::addMapped_Locations_List(std::map<int, location::ptr>& mapped_location_list){
	list_locations = mapped_location_list;
}
void hybrid_automata::addLocation(location::ptr& loc){
	int key = loc->getLocId();
	list_locations[key] = loc;	//storing the loc with the proper loc_id as the key
}


std::list<structuralPath::ptr> hybrid_automata::get_structural_paths(unsigned int forbidden_loc_id, unsigned int depth)
{
	std::list<structuralPath::ptr> path_list; // It is empty here.


//	std::list<initial_state::ptr>::iterator iit;
//	iit = init_state.begin();
//	int srcLoc = (*iit)->getLocationId();
	unsigned int srcLoc = getInitial_Location()->getLocId();
	unsigned int destLoc = forbidden_loc_id;
	//unsigned int depthBound = 5;	// < then depthBound
	path_list = findAllPaths(srcLoc, destLoc, depth);
	//std::cout<<"Test 1: locs size ="<<(*path_list.begin())->get_path_locations().size()<<std::endl;
/*
ToDo:: Uncomment this block-comment to print all the solution paths
	for (std::list<structuralPath::ptr>::iterator it = path_list.begin();
			it != path_list.end(); it++) {
		std::cout << "\nSolution Paths are: ";
		//structuralPath::ptr sp;
		std::list<location::ptr> listLocs;
		std::list<transition::ptr> listTrans;
		//sp = (*it);
		listLocs = (*it)->get_path_locations();
		listTrans = (*it)->get_path_transitions();
		for (std::list<location::ptr>::iterator iit = listLocs.begin();
				iit != listLocs.end(); iit++) {
			std::cout << (*iit)->getName() << "  ,  ";
		}
		std::cout << "    Transitions Paths are: ";
		for (std::list<transition::ptr>::iterator iit = listTrans.begin();
				iit != listTrans.end(); iit++) {
			//std::cout<<(*iit)->getLabel()<<"  ,  ";
			std::cout << (*iit)->getTransitionId() << "  ,  ";
		}
	}
	std::cout<<endl;
*/


	//for(unsigned int i)
	return path_list;
}


void hybrid_automata::printpath(vector<int>& path) {
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
			continue;	//avoiding traversing further from here: bad location not repeated
		}
		// traverse to all the nodes connected to
		// current node and push new path to queue
		location::ptr lastLoc = getLocation(last); //Note:: todo take care if last does not exist (if error occurs)
		std::list<transition::ptr> allOutTrans = lastLoc->getOut_Going_Transitions();
		std::list<transition::ptr>::iterator it;
		for (it = allOutTrans.begin(); it != allOutTrans.end(); it++) {
			// if (isNotVisited(g[last][i], path)) {    //enable this if to avoid Cycle
			vector<int> newpath(pathDS.first);	//copy constructor
			newpath.push_back((*it)->getDestination_Location_Id());
			vector<transition::ptr> newtrans(pathDS.second);	//copy constructor
			newtrans.push_back((*it));
			int depthExplored = newpath.size();    //Size of the path
			if (depthExplored == depthBound)
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
