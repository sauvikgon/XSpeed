/*
 * Hybrid_Automata.h
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#ifndef HYBRID_AUTOMATA_H_
#define HYBRID_AUTOMATA_H_

#include <list>
#include <map>
//#include "Transition.h"
#include "Location.h"

using namespace std;

class hybrid_automata : public var_to_index_map {
	//std::list<location> list_locations;
	std::map<int, location> list_locations;		//mapping a list of locations based on the key=loc_id
	location initial_loc;
	int dimension;
public:

	hybrid_automata();
	hybrid_automata(std::map<int, location>& list_locs, location init_loc,
			int dim);
	void addInitial_Location(location& initLoc);
	location& getInitial_Location();

	//returns the location from the list of locations with location_ID as the input parameter
	location getLocation(int Loc_ID);

	void addMapped_Locations_List(std::map<int, location>& mapped_location_list);

	void addLocation(location& loc);	//inserts location into its correctly mapped key
	int getDimension() const;
	void setDimension(int dimension);
};

#endif /* HYBRID_AUTOMATA_H_ */
