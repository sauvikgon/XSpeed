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
#include <boost/shared_ptr.hpp>
#include "core_system/HybridAutomata/Location.h"


using namespace std;

class hybrid_automata : public var_to_index_map {
	std::map<int, location::ptr> list_locations;		//mapping a list of locations based on the key=loc_id
	location::ptr initial_loc;
	int dimension;
public:
	typedef boost::shared_ptr<hybrid_automata> ptr;
	hybrid_automata();
	hybrid_automata(std::map<int, location::ptr>& list_locs, location::ptr init_loc,
			int dim);
	void addInitial_Location(location::ptr& initLoc);
	location::ptr& getInitial_Location();

	//returns the location from the list of locations with location_ID as the input parameter
	location::ptr getLocation(int Loc_ID);

	void addMapped_Locations_List(std::map<int, location::ptr>& mapped_location_list);

	void addLocation(location::ptr& loc);	//inserts location into its correctly mapped key
	int getDimension() const;
	void setDimension(int dimension);

	/**
	 * Return the list of all paths in the HA of length at-most depth.
	 * Many of these paths may not be actually feasible with the HA semantics.
	 * This routine only returns all structurally possible  paths in the HA
	 * having a length at-most depth.
	 */
	//std::list<abstractCE::ptr> get_structural_paths(unsigned int depth);

	/*
	 * Returns the total number of Locations in the hybrid automata with ID = 1 to returned size
	 */
	int getTotalLocations(){
		return list_locations.size();
	}
};

#endif /* HYBRID_AUTOMATA_H_ */
