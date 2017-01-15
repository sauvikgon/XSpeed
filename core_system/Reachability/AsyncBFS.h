/*
 * AsyncBFS.h
 *
 *  Created on: 12-Jan-2017
 *      Author: amit
 */

#ifndef ASYNCBFS_H_
#define ASYNCBFS_H_

#include <mutex>
#include <thread>
#include "reachability.h"

using namespace std;

/*
 * We apply a parallel BFS Alogrithm with the absence of breadth-level synchronization.
 * Thus we called this as the Asynchronous parallel BFS Algorithm.
 */
class AsyncBFS: public reachability {
public:
	std::list<symbolic_states::ptr> reachComputeAsynBFS(
			std::list<abstractCE::ptr>& ce);

private:
	/**
	 * Computes postC given a sym state s.
	 */

};

void AsyncBFS_recursiveFunc(std::list<symbolic_states::ptr>& PASSED,
		initial_state::ptr s, int level, AsyncBFSData& reachData,
		long& totalSymStates);

/*
 *	This functions utilities has been implemented due to fast and ease of implementation.
 *	Later Todo:: Thread class can be created that can inherit the reachability class and do the reach-computation task.
 */

/**
 * Computes postC given a sym state s.
 */
template_polyhedra::ptr postC(initial_state::ptr s, AsyncBFSData myData);

/**
 * computes postD from a template polyhedra computed by postC
 */
std::list<initial_state::ptr> postD(symbolic_states::ptr symb,
		std::list<symbolic_states::ptr> PASSED, AsyncBFSData reachData);

bool isContainted(int locID, polytope::ptr poly,
		std::list<symbolic_states::ptr> Reachability_Region,
		int lp_solver_type_choosen);

#endif /* ASYNCBFS_H_ */
