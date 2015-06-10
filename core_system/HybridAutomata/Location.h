/*
 * Location.h
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <string>
#include <list>
#include "application/DataStructureDirections.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Transition.h"



class location {
private:
	int loc_id;
	string Name;
	Dynamics System_Dynamics;
	polytope::ptr Invariant;
	bool InvariantExists;		//True If invariant exists otherwise False
	std::list<transitions> Out_Going_Transitions;
public:
	location();
	location(int Loc_ID, string Name, Dynamics System_Dynamics, polytope::ptr Invariant,  bool inv_exists, std::list<transitions> Out_Going_Trans);
	Dynamics& getSystem_Dynamics();
	void setSystem_Dynamics(const Dynamics& d);
	polytope::ptr getInvariant();
	void setInvariant(polytope::ptr invariant);
	const string& getName() const;
	void setName(const string& Name);
	void add_Out_Going_Transitions(transitions& t);
	std::list<transitions>& getOut_Going_Transitions();
	int getLocId() const;
	void setLocId(int locId);
	bool isInvariantExists() const;
	void setInvariantExists(bool invariantExists);
};

#endif /* LOCATION_H_ */
