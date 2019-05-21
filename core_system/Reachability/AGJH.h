/*
 * AGJH.h
 *
 *  Created on: 28-Oct-2016
 *      Author: amit
 */

#ifndef AGJH_H_
#define AGJH_H_

#include "reachability.h"

class agjh : public reachability{
public:
	/**
	 * Adaption of GH algorithm for parallel Breadth first search
	 */
	std::list<symbolic_states::ptr> ParallelBFS_GH(std::list<abstractCE::ptr>& ce_candidates);

	//Adapted Holzmann Algorithm with separate  postC and postD from the containment check to avoid locking on passed list
	std::list<symbolic_states::ptr> AGJH(std::list<abstractCE::ptr>& ce_candidates);
private:
	/**
	 * Computes postC from sym state s.
	 */
	template_polyhedra::ptr postC(initial_state::ptr s);

	/**
	 * computes postD from a template polyhedra computed by postC
	 */

	std::list<initial_state::ptr> postD(symbolic_states::ptr symb, std::list<symbolic_states::ptr> PASSED, bool& unsafe);

	bool checkSafety(template_polyhedra::ptr& reach_region, initial_state::ptr& s, symbolic_states::ptr& S, std::list<abstractCE::ptr>& ce_candidates);
};


#endif /* AGJH_H_ */
