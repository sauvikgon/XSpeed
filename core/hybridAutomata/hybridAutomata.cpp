/*
 * HybridAutomata.cpp
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#include <core/hybridAutomata/hybridAutomata.h>

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

	unsigned int srcLoc = getInitial_Location()->getLocId();
	unsigned int destLoc = forbidden_loc_id;
	path_list = findAllPaths(srcLoc, destLoc, depth);

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
			//Disable instruction continue to avoid repeated bad location (applicable for discrete systems)
			//continue;	//avoiding traversing further from here: bad location not repeated (applicable for hybrid systems)
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
