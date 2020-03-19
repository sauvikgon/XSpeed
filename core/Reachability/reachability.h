/*
 * reachability.h
 *
 *  Created on: 23-Feb-2016
 *      Author: amit
 */

#ifndef REACHABILITY_H_
#define REACHABILITY_H_

#include "application/DataStructureDirections.h"
#include "counterExample/abstractCE.h"
#include <utility>
#include <set>
//***************** From Sequential BFS *****************************
#include "counterExample/abstract_symbolic_state.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include "application/All_PP_Definition.h"

#include "boost/timer/timer.hpp"
#include "counterExample/abstractCE.h"
#include <omp.h>
#include <vector>

#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/PWL/pwlist.h"
#include "../../core/Reachability/LockAvoidanceUtility.h"
#include "../../core/Reachability/reachabilitySequential.h"
#include "../../core/Reachability/reachDataStructure.h"
#include "../../core/Reachability/reachPostCParallel.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"
#include "../../core/symbolic_states/symbolic_states_utility.h"
#include "../../io/io_utility.h"
#include "../../utilities/computeInitialPolytope.h"
#include "../../utilities/Post_Assignment.h"
#include "../../utilities/testPolytopePlotting.h"
#include "../../utilities/Template_Polyhedra.h"
#include "application/sf_utility.h"

// macro to choose algo_type of ce search.
// 1 enables search of ce to forbidden region using flowpipe constraints (FC).
// 2 enables the same with implicit HA constraints, requiring no flowpipe construction (WoFC).
// 3 gen_concreteCE_iterative 	: Updated by Rajarshi & Amit. Algorithm using iterative call to LP-NLP
// 4 gen_concreteCE_Simulation : Amit:- Algorithm that use LP formulation for initial start-point followed by Simulation for falsification
// 5 gen_concreteCE_LPobj: trajectory splicing with NLP using dwell-time only as vars. The objective function is the soln
// 	 of a LP formed for splicing with fixed-dwell and varying starts.
// 6 gen_concreteCE_Opt: trajectory splicing with NLP that returns a time minimal ce. (Not Functional)

#define CE_ALGO_TYPE  1

using namespace std;

class reachability {
public:
	/*void setReachParameter(hybrid_automata& H, std::list<initial_state::ptr>& I,
			ReachabilityParameters& reach_parameters, int bound,
			unsigned int Algorithm_Type, unsigned int Total_Partition,
			int lp_solver_type, unsigned int number_of_streams,
			int Solver_GLPK_Gurobi_GPU,
			std::pair<int, polytope::ptr> forbidden_set);*/

	void setReachParameter(hybrid_automata& h, std::list<initial_state::ptr>& i, ReachabilityParameters& reach_param,
			int lp_solver_type, std::pair<int, polytope::ptr> forbidden, userOptions& user_options);

	/*
	 * Get counter-example trajectories found during reachability analysis
	 */
	std::list<concreteCE::ptr> get_counter_examples() { // making it inline
		return ce_list;
	}

	/*
	 * Get the number of refinements performed during the search of a counter-example.
	 * This parameter has meaning only when the counter-example search is enabled with reachability analysis.
	 */

	unsigned int get_refinements(){
		return refinements; // This is set to appropriate value by the gen_counter_examples() method.
	}

	/**
	 * Returns the time to search counter-example(s) during reachability analysis
	 */
	float get_ce_search_time(){
		return this->traj_splicing_time;
	}

	//bound is the maximum number of transitions or jumps permitted.
	//reach_parameters includes the different parameters needed in the computation of reachability.
	//I is the initial symbolic state
	//Although this interface can be pushed in a separate sequential class but it can also be used to call par_SF and time_slice algorithms.

	std::list<symbolic_states::ptr> computeSeqBFS(std::list<abstractCE::ptr>& ce_candidates);

	//1)  Parallel Breadth First Search for Discrete Jumps with critical section for adding newSymbolicState
	std::list<symbolic_states::ptr> computeParBFS( std::list<abstractCE::ptr>& ce_candidates);

	//2)  Lock Avoidance for adding newSymbolicState:: Parallel Breadth First Search for Discrete Jumps
	//separate Read and Write Queue (pwlist.WaitingList)
	std::list<symbolic_states::ptr> computeParLockFreeBFS(std::list<abstractCE::ptr>& ce_candidates);

	/*
	 * List of private variables now converted into public due to class inheritance framework
	 */
	std::list<initial_state::ptr> I; //converted to a list of initial state
	unsigned int bound;
	ReachabilityParameters reach_parameters;
	hybrid_automata H; //todo:: have to change it to boost::ptr
	int lp_solver_type;
	std::pair<int, polytope::ptr> forbidden_set;
	bool ce_flag; // The flag to switch ON/OFF the CE generation functionality.
	std::string ce_path; // This string can be either "all", "first" or "1,3,4,15,16" type. The last string is a comma separated list of locations to represent a path.

	void seqReachSelection(unsigned int NewTotalIteration, location::ptr current_location, polytope::ptr continuous_initial_polytope,
					template_polyhedra::ptr& reach_region);

/*
 * Returns True if the newShiftedPolytope is containted in the symbolic_states denoted by Reachability_Region in the location
 * represented by locationID as destination_locID
 * Otherwise returns False
 * This interface is NOT threadSafe but it has exact computed result AND SEQUENTIAL algorithm has no issue with threadSafety
 */
//	bool isContained(int destination_locID, polytope::ptr newShiftedPolytope, std::list<symbolic_states::ptr> Reachability_Region, int lp_solver_type);

	/*
	 * Uses the templated (an over-approximated) newShiftedPolytope to check for containment in the Omegas of the flowpipe
	 * This interface is threadSafe however it is over-approximated result
	 */
	bool templated_isContained(int destination_locID, polytope::ptr newShiftedPolytope, std::list<symbolic_states::ptr> Reachability_Region, int lp_solver_type);

	/*
	 * This is thread-safe but uses template_Hull over-approximated technique.
	 * This is locking on the reach set
	 */
	bool isContained_withLock(int destination_locID, polytope::ptr newShiftedPolytope, std::list<symbolic_states::ptr>& PASSED, int lp_solver_type);

	const std::string& getSetAggregation() const;
	void setSetAggregation(const std::string& setAggregation);
	const userOptions& getUserOp() const;
	void setUserOp(const userOptions& userOp);

private:
	//initial_state::ptr I;
	unsigned int Algorithm_Type;
	unsigned int Total_Partition;
	unsigned int number_of_streams;
	unsigned int refinements; // The number of refinements during the search of counter-example trajectories. This has meaning only when the counter-example generation function is enabled.
	float traj_splicing_time; // The time taken to concretize/splice abstract path(s)
	unsigned int ce_search_algo_type; // the type of search algorithm to use in order to search for a counter-example. Options are FC and WoFC

	std::string set_aggregation; // The aggregation options thull (default) and none
	std::list<concreteCE::ptr> ce_list; // the list of concrete counter-examples in the HA.


	//defining here userOptions for easy access
	userOptions user_op; //user options


	void parReachSelection(unsigned int NewTotalIteration, location::ptr current_location, polytope::ptr continuous_initial_polytope,
			ReachabilityParameters& reach_parameters, std::vector<symbolic_states::ptr>& S, unsigned int id);

	/*
	 * Manages the counter-example searching during reachability with BFS. The return status indicates whether the BFS should continue
	 * to search for further abstract paths or whether to stop. A return value of true indicates the BFS to stop. A false indicates that
	 * the BFS should continue to further explore for newer abstract counterexamples.
	 */
	bool gen_counter_example(abstractCE::ptr abs_ce_path, unsigned int ce_search_algo_type);

	/**
	 * A search for counter-example during BFS.
	 */
	bool safetyVerify(symbolic_states::ptr& computedSymStates, std::list<symbolic_states::ptr>& Reachability_Region, std::list<abstractCE::ptr>& symbolic_ce_list);

	/*Performs the task of computing support functions on the specified polytopes for the given directions
		and returns the results of support function computation on the same data-structure as be symbolic-state basis
		SEQUENTIAL*/
	void computeBIG_Task(std::vector<LoadBalanceData>& LoadBalanceDS);

	/*
	 * Performs the task of computing support functions in parallel using the approach of task_scheduling
	 */
	void parallelBIG_Task(std::vector<LoadBalanceData>& LoadBalanceDS);

	double boxLPSolver(polytope::ptr poly, std::vector<double> dir);
	double LPSolver(polytope::ptr poly, std::vector<double> dirs);

};

#endif /* REACHABILITY_H_ */
