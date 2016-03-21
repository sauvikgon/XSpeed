/*
 * reachability.h
 *
 *  Created on: 23-Feb-2016
 *      Author: amit
 */

#ifndef REACHABILITY_H_
#define REACHABILITY_H_

#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/initial_state.h"
#include "application/DataStructureDirections.h"
#include "counterExample/abstractCE.h"
#include <utility>	//for std::pair
#include <set>
//***************** From Sequential BFS *****************************
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "counterExample/abstract_symbolic_state.h"
#include "InputOutput/io_utility.h"

//#include "core_system/PWL/pwl.h"
#include "core_system/PWL/pwlist.h"
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/symbolic_states/symbolic_states_utility.h"

#include "Utilities/testPolytopePlotting.h"
#include "Utilities/Post_Assignment.h"
#include <boost/lexical_cast.hpp>
#include "core_system/Reachability/reachabilitySequential.h"
#include "core_system/Reachability/reachParallelExplore.h"
#include "core_system/Reachability/reachabilityParallel_Process.h"
#include "core_system/Reachability/NewApproach/SameDirections_Avoid_SuppFunction.h"
#include "Utilities/computeInitialPolytope.h"
#include "core_system/math/gurobi_lp_solver/gurobi_lp_solver.h"
#include "application/All_PP_Definition.h"
//#include "core_system/Reachability/reachabilitySequential_GPU_MatrixVector_Multiply.cuh"
#include "core_system/Reachability/GPU_Reach/reach_Sequential_GPU.h"
#include "boost/timer/timer.hpp"
#include "counterExample/abstractCE.h"
#include <omp.h>
#include "LockAvoidanceUtility.h"
#include "reachDataStructure.h"
#include <vector>
#include "application/sf_directions.h"
#include "application/sf_utility.h"
//***************** End Sequential BFS *****************************

using namespace std;

class reachability {

public:
	reachability(){
	//	cout<< "Calling from reachability Class\n";
	}
	void setReachParameter(hybrid_automata& H, initial_state::ptr& I,
			ReachabilityParameters& reach_parameters, int bound,
			unsigned int Algorithm_Type, unsigned int Total_Partition,
			int lp_solver_type_choosen, unsigned int number_of_streams,
			int Solver_GLPK_Gurobi_GPU,
			std::pair<int, polytope::ptr> forbidden_set);

	//Sequential Breadth First Search for Discrete Jumps
	std::list<symbolic_states::ptr> computeSeqentialBFSReach(
			abstractCE::ptr& ce);

	//1)  Parallel Breadth First Search for Discrete Jumps with critical section for adding newSymbolicState
	std::list<symbolic_states::ptr> computeParallelBFSReach(
			abstractCE::ptr& ce);

	//2)  Lock Avoidance for adding newSymbolicState:: Parallel Breadth First Search for Discrete Jumps
	//separate Read and Write Queue (pwlist.WaitingList)
		std::list<symbolic_states::ptr> computeParallelBFSReachLockAvoid(
				abstractCE::ptr& ce);

	/*
	 * Both 1) and 2) method resulted in same performance as Work-Load for flowpipe computation is uneven
	 * So 3) will aggregrate all flowpipe computation work into one BIG task and will run that in parallel by multi-core CPU or GPU
	 */
		std::list<symbolic_states::ptr> computeParallelLoadBalanceReach(
						abstractCE::ptr& ce);


private:
	hybrid_automata H; //todo:: have to change it to boost::ptr
	initial_state::ptr I;
	ReachabilityParameters reach_parameters;

	int bound;
	unsigned int Algorithm_Type;
	unsigned int Total_Partition;
	int lp_solver_type_choosen;
	unsigned int number_of_streams;
	int Solver_GLPK_Gurobi_GPU;
	std::pair<int, polytope::ptr> forbidden_set;

	void parallelReachSelection(location::ptr current_location, polytope::ptr continuous_initial_polytope,
			ReachabilityParameters& reach_parameters, std::vector<symbolic_states::ptr>& S, unsigned int id);

	void sequentialReachSelection(location::ptr current_location, polytope::ptr continuous_initial_polytope,
				template_polyhedra::ptr& reach_region);

	/*Returns True, if safety has been violated on the current computed Symbolic States and sets/creates the counterExample class
	Returns False, if safety not violated and the object of counterExample class remains NULL pointer */
	bool safetyVerify(symbolic_states::ptr& computedSymStates, std::list<symbolic_states::ptr>& Reachability_Region, abstractCE::ptr& ce);

	void preLoadBalanceReachCompute(ReachabilityParameters& ReachParameters, Dynamics& SystemDynamics,
			supportFunctionProvider::ptr Initial, polytope::ptr invariant, bool isInvariantExist, math::matrix<float>& List_dir_X0,
			math::matrix<float>& List_dir_U, unsigned int& newIteration);

	/*Performs the task of computing support functions on the specified polytopes for the given directions
	and returns the results of support function computation on the same data-structure as be symbolic-state basis
	SEQUENTIAL*/
	void computeBIG_Task(std::vector<LoadBalanceData>& LoadBalanceDS);
	template_polyhedra::ptr substitute_in_ReachAlgorithm(LoadBalanceData& LoadBalanceDS);

	/*
	 * Performs the task of computing support functions in parallel using the approach of task_scheduling
	 */
	void computeBIG_Task_parallel(std::vector<LoadBalanceData>& LoadBalanceDS);//NOT FEASIBLE TO PARALLELIZE

	void parallelBIG_Task(std::vector<LoadBalanceData>& LoadBalanceDS);

	void parallelLoadBalance_Task(std::vector<LoadBalanceData>& LoadBalanceDS);

	double boxLPSolver(polytope::ptr poly, std::vector<double> dir);

	double LPSolver(polytope::ptr poly, std::vector<double> dirs);

	int compute_chunk_size(unsigned int countTotal_X);
};

#endif /* REACHABILITY_H_ */
