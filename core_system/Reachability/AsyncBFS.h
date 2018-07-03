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
#include "reachDataStructure.h"
#include <atomic>  //used for std::atomic<int> data type
#include <iostream>  //used for std::atomic<int> data type


using namespace std;

/*
 * We apply a parallel BFS Algorithm with the absence of breadth-level synchronization.
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

/*
 * All these function below are normal functions and not members of the class AsyncBFS
 */
void AsyncBFS_recursiveFunc(LocklessDS L[], initial_state::ptr s, int level, AsyncBFSData& reachData, long& totalSymStates, int& levelCompleted);


/*
 *	This functions utilities has been implemented due to fast and ease of implementation.
 *	Later Todo:: Thread class can be created that can inherit the reachability class and do the reach-computation task.
 */

/**
 * Computes postC given a sym state s.
 */
template_polyhedra::ptr postC(initial_state::ptr s, AsyncBFSData myData);

/**
 * computes postD from a template polyhedra computed by postC. The unsafe flag is set if rechability to unsafe state is detected.
 */
std::list<initial_state::ptr> postD(symbolic_states::ptr symb, LocklessDS L[], AsyncBFSData reachData, bool& unsafe);

/*
 * Returns True if the newShiftedPolytope is containted in the symbolic_states denoted by Reachability_Region in the location
 * represented by locationID as destination_locID
 * Otherwise returns False
 * This interface is NOT threadSafe but it has exact computed result AND SEQUENTIAL algorithm has no issue with threadSafety
 */
//bool isContained(int locID, polytope::ptr poly, std::list<symbolic_states::ptr> Reachability_Region, int lp_solver_type_choosen);

/*
 * This is thread-safe but uses template_Hull of poly an over-approximated technique
 */
//bool AsyncBFS_isContained(int locID, polytope::ptr poly, LocklessDS L[], int totalLocations, int lp_solver_type_choosen);
bool AsyncBFS_isContained(int locID, polytope::ptr poly, LocklessDS L[], int lp_solver_type_choosen);

void initializeLocklessDS(LocklessDS L[], int ha_size);
void printLocklessDS(LocklessDS L[], int ha_size);

void lock(LocklessDS L[], int locID);
void unlock(LocklessDS L[], int locID);

#endif /* ASYNCBFS_H_ */
