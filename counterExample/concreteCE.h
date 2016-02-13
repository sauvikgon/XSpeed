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
#include <boost/shared_ptr.hpp>
#include <vector>
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

	void push_back(traj_segment t_seg){
		T.push_back(t_seg);
	}

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

};

#endif /* CONCRETECE_H_ */
