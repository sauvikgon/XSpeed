/*
 * concreteCE.h
 *
 *  Created on: 20-Jan-2016
 *      Author: rajarshi
 */

#ifndef CONCRETECE_H_
#define CONCRETECE_H_

#include <list>
#include <utility>
#include <fstream>
#include <boost/shared_ptr.hpp>
#include <vector>
#include "counterExample/simulation.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"


struct violating_CE;

class concreteCE {

public:
	typedef boost::shared_ptr<concreteCE> ptr;
	/**
	 * A sample stores the initial vector and the dwell time of a trajectory
	 * within a location
	 */
	typedef unsigned int loc_id;
	typedef unsigned int trans_id;

	typedef std::pair<std::vector<double>, double> sample;
	/**
	 * A sample and a location id defines a trajectory segment of a counter-example
	 * within a location.
	 */
	typedef std::pair<loc_id, sample> traj_segment;
	/**
	 * A trajectory is a concatenation of the trajectory
	 * segments in the list
	 */
	typedef std::list<traj_segment> trajectory;

	/**
	 * Returns the segment of the trajectory parameterized by
	 * its position in the list.
	 */
	const traj_segment get_segment(unsigned int i) const;
	/**
	 * Returns the transition id  parameterized by
	 * its position in the counter example.
	 */
	const trans_id getTransitionId(unsigned int i) const;

	/**
	 * Setter method to initialize the hybrid automaton
	 */
	void set_automaton(hybrid_automata::ptr h)
	{
		ha = h;
	}
	/**
	 * Getter method to initialize the hybrid automaton
	 */
	hybrid_automata::ptr get_automaton(hybrid_automata::ptr h)
	{
		return ha;
	}
	void push_back(traj_segment t_seg){
		T.push_back(t_seg);
	}
	bool is_empty(){
		if(T.size() == 0)
			return true;
		else
			return false;
	}
	/**
	 * Plots the counter example trajectory to a file passed as parameter.
	 */
	void plot_ce(std::string filename, unsigned int x1, unsigned int x2);

	/*
	 * Validates the trajectory for invariant satisfaction.
	 * Returns the violating CE if non-valid, otherwise returns the
	 * violating_CE with the flag element of the object as true.
	 */
	violating_CE validate();

	concreteCE();
	virtual ~concreteCE();
private:
	trajectory T;
	/**
	 * The list of transitions taken in the counter example.
	 * The order of the transitions are corresponding to the order of trajectory
	 * segments, meaning the i-th transition in the list is taken to jump from the
	 * i-th trajectory segment to the next segment.
	 */
	std::list<trans_id> jumps;
	/**
	 * pointer to the hybrid automaton to which this counter example refer
	 */
	hybrid_automata::ptr ha;

};

/*
 * Structure to hold the information about the violating concreteCE
 */

struct violating_CE
{
	bool flag;
	concreteCE::traj_segment t;
};
#endif /* CONCRETECE_H_ */
