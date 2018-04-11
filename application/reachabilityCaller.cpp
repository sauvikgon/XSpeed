#include "application/reachabilityCaller.h"


void reachabilityCaller(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters, userOptions& user_options,
		int lp_solver_type_choosen, int Solver_GLPK_Gurobi_GPU, std::pair<int, polytope::ptr> forbidden_set,
		std::list<symbolic_states::ptr>& Symbolic_states_list,
		std::list<abstractCE::ptr>& ce_candidates) {

	/*
	 * For algorithm (Seq-SF, Par-SF and Time-Slice) only the Algorithm-Type/user_options.get_algorithm decides to execute
	 */


	if ((user_options.get_algorithm() == 1)
			|| (user_options.get_algorithm() == 2)
			|| (user_options.get_algorithm() == 3) || (user_options.get_algorithm() == 6) ) {

		//sequential reachability algorithm;

		reachability reach_SEQ_BFS;	//user_options.get_algorithm decides the algorithm for postC, either seq-sf-based, par-sf-based, time-slice or GPU-based algorithm. PostD is sequential
		reach_SEQ_BFS.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type_choosen, Solver_GLPK_Gurobi_GPU, forbidden_set, user_options);

		// The right algorithm is selected within the following function
		Symbolic_states_list = reach_SEQ_BFS.computeSequentialBFSReach(ce_candidates);

	} else if (user_options.get_algorithm() == 4) { //Adaptation of Gerard J. Holzmann's algorithm (Seq PostC and PBFS)
		agjh reach_AGJH;
		reach_AGJH.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type_choosen,
				Solver_GLPK_Gurobi_GPU, forbidden_set, user_options);
		std::cout << "\nRunning an adaptation of Gerard J. Holzmann's algorithm in SPIN model checker\n";
		Symbolic_states_list = reach_AGJH.AGJH(ce_candidates); // Holzmann algorithm adaptation without lock for containment check

	} else if (user_options.get_algorithm() == 5) { // TPBFS -- Task parallel BFS (Load Balancing Algorithm)
		tpbfs reach;
		reach.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type_choosen,
				Solver_GLPK_Gurobi_GPU, forbidden_set, user_options);
		std::cout<< "\nRunning the task parallel BFS algorithm (TPBFS) for an effective load balancing .\n";
		Symbolic_states_list = reach.LoadBalanceAll(
				ce_candidates);
	} else if (user_options.get_algorithm() == 7) { // AsyncBFS -- Asynchronous parallel BFS (Does not synchronize like in BFS Algorithm)
		AsyncBFS reach;
		reach.setReachParameter(Hybrid_Automata, init_state, reach_parameters,
				lp_solver_type_choosen, Solver_GLPK_Gurobi_GPU, forbidden_set, user_options);
		std::cout<< "\nRunning an asynchronous parallel BFS algorithm (Async BFS) to avoid synchronization overhead.\n";
		Symbolic_states_list = reach.reachComputeAsynBFS(ce_candidates);
	}
}

