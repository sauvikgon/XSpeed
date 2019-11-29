/*
 * TPBFS.h
 *
 *  Created on: 28-Oct-2016
 *      Author: amit
 */

#ifndef TPBFS_H_
#define TPBFS_H_

#include "reachability.h"
#include "application/sf_directions.h"

class tpbfs : public reachability{
public:
	/*
		 * Here we also apply Load Balancing algorithm for POST_D computation
		 */
		std::list<symbolic_states::ptr> LoadBalanceAll(std::list<abstractCE::ptr>& ce);

private:

	template_polyhedra::ptr substitute_in_ReachAlgorithm(
			LoadBalanceData& LoadBalanceDS, unsigned int numCoreAvail,
			LoadBalanceDataSF& LoadBalanceData_sf, unsigned int id);

		void parallelLoadBalance_Task(std::vector<LoadBalanceData>& LoadBalanceDS, LoadBalanceDataSF& LoadBalanceData_sf);

		/*void preLoadBalanceReachCompute(ReachabilityParameters& ReachParameters, Dynamics& SystemDynamics,
				supportFunctionProvider::ptr Initial, polytope::ptr invariant, bool isInvariantExist, math::matrix<float>& List_dir_X0,
				math::matrix<float>& List_dir_U, unsigned int& newIteration);*/
		void preLoadBalanceReachCompute(LoadBalanceData& LoadBalanceDS, unsigned int numCoresAvail);


		/*
		 * Load Balanced PostD computation:: checking Intersection with guard in parallel
		 */
		void loadBalancedPostD(std::vector<LoadBalanceData_PostD>& loadBalPostD);


		/*
		 * Checking Intersection region within the sfm
		 */
		void intersectionRangeDetection(std::vector<LoadBalanceData_PostD>& loadBalPostD);

		/*
		 * From each Intersected region generated by intersectionRangeDetection() for each guard of each symbolic_state/sfm
		 * template Approximation is performed and returns the polytopes as results
		 */
		void templateApproximation(bool aggregation, std::vector<LoadBalanceData_PostD>& loadBalPostD);


		/*
		 * Function that takes a polytope and returns a template_polyhedra with direction and invariant_direction
		 */
		template_polyhedra::ptr polytopeTo_templatepolyhedra(LoadBalanceData data);

};


#endif /* TPBFS_H_ */
