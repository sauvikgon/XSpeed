/*
 * Location.h
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <application/structures.h>
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/transition.h>


class location {
private:
	int loc_id;
	string Name;
	Dynamics System_Dynamics;
	polytope::ptr Invariant;
	bool InvariantExist;		//True If invariant exists otherwise False
	std::list<transition::ptr> Out_Going_Transitions;
public:
	typedef boost::shared_ptr<location> ptr;
	location();
	location(int Loc_ID, string Name, Dynamics System_Dynamics, polytope::ptr Invariant,  bool inv_exists, std::list<transition::ptr> Out_Going_Trans);
	Dynamics& getSystemDynamics();
	void setSystemDynamics(const Dynamics& d);
	polytope::ptr getInvariant();
	void setInvariant(polytope::ptr invariant);
	const string& getName() const;
	void setName(const string& Name);

	void addOutGoingTransition(transition::ptr t);

	transition::ptr getTransition(int trans_id);	//returns a specific transition for a given trans_id

	std::list<transition::ptr>& getOutGoingTransitions();
	int getLocId() const;
	void setLocId(int locId);
	bool getInvariantExist() const;
	void setInvariantExist(bool invariantExist);
};

#endif /* LOCATION_H_ */
