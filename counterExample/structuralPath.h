/*
 * structuralPath.h
 *
 *  Created on: 23-Aug-2018
 *      Author: Rajarshi
 */

#ifndef STRUCTURALPATH_H_
#define STRUCTURALPATH_H_

/**
 * This routine returns all structurally possible paths in the HA from a source
 * to a target location, having a length at-most a given depth. Many of these
 * paths may not be feasible with the HA semantics.
 */

#include <boost/shared_ptr.hpp>
#include "../core/HybridAutomata/Location.h"
#include "../core/HybridAutomata/Transition.h"

class structuralPath
{

	std::list<location::ptr> path_locations; // the list containing the locations of the path, in order
	std::list<transition::ptr> path_transitions; // the list containing the transitions of the path, in order

public:

	typedef boost::shared_ptr<structuralPath> ptr;

	structuralPath(){};
	structuralPath(std::list<location::ptr> path_locs, std::list<transition::ptr> path_trans){
		this->path_locations = path_locs;
		this->path_transitions = path_trans;
	}

	~structuralPath(){};
	/**
	 * Returns the length of the abstract path which is defined as the number of locations it contains.
	 */
	unsigned int get_length(){return path_locations.size();}

	/**
	 * Returns the list of locations in the structural HA path
	 */
	std::list<location::ptr> get_path_locations(){return this->path_locations;};

	/**
	 * Returns the list of transitions in the structural HA path
	 */
	std::list<transition::ptr> get_path_transitions() { return this->path_transitions;};

	/**
	 * searches a concrete counter example in the structural path. The initial and the forbidden regions are passed as
	 * parameters to the method.
	 */
//	concreteCE::ptr get_ce_trajectory(symbolic_states::ptr init_symb_state, symbolic_states::ptr forbidden_state);

};



#endif /* STRUCTURALPATHS_H_ */
