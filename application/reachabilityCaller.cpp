#include "application/reachabilityCaller.h"

void reachabilityCaller(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters, userOptions& user_options,
		int lp_solver_type, std::vector<forbidden> forbidden_states,
		std::list<symbolic_states::ptr>& Symbolic_states_list,
		std::list<abstractCE::ptr>& ce_candidates) {

	 	 //Sequential PostC and PostD
		if ((user_options.get_algorithm() == SEQ_SF)
			|| (user_options.get_algorithm() == PAR_SF)
			|| (user_options.get_algorithm() == TIME_SLICE)
			|| (user_options.get_algorithm() == FB_INTERPOL) ) {

		//sequential BFS exploration of the HA graph is executed for these options.

		reachability reach_SEQ_BFS;
		//user_options.get_algorithm decides the algorithm for postC, either seq-sf-based, par-sf-sampling, time-slice in PostC,
		//postC with forward approximation model. PostD is sequential
		reach_SEQ_BFS.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type, forbidden_states, user_options);

		// The appropriate algorithm is selected within the following function
		Symbolic_states_list = reach_SEQ_BFS.computeSeqBFS(ce_candidates);
		print_ce_statistics(reach_SEQ_BFS, ce_candidates, user_options, "Safety Analysis");

	} else if (user_options.get_algorithm() == AGJH_BFS) { //Adaptation of Gerard J. Holzmann's algorithm (Seq PostC and PBFS)
		agjh reach_AGJH;
		reach_AGJH.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type, forbidden_states, user_options);
		std::cout << "\nRunning an adaptation of Gerard J. Holzmann's algorithm in SPIN model checker\n";
		Symbolic_states_list = reach_AGJH.AGJH(ce_candidates); // Holzmann's algorithm adaptation without lock for containment checking

	} else if (user_options.get_algorithm() == TPBFS) { // TPBFS -- Task parallel BFS (Load Balancing Algorithm)
		tpbfs reach;
		reach.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type,
				forbidden_states, user_options);
		std::cout<< "\nRunning the task parallel BFS algorithm (TPBFS) for an effective load balancing .\n";
		Symbolic_states_list = reach.LoadBalanceAll(
				ce_candidates);
	} else if (user_options.get_algorithm() == ASYNC_BFS) { // AsyncBFS -- Asynchronous parallel BFS (Does not synchronize like in BFS Algorithm)
		AsyncBFS reach;
		reach.setReachParameter(Hybrid_Automata, init_state, reach_parameters,
				lp_solver_type, forbidden_states, user_options);
		std::cout<< "\nRunning an asynchronous parallel BFS algorithm (Async BFS) to avoid synchronization overhead.\n";
		Symbolic_states_list = reach.reachComputeAsynBFS(ce_candidates);
	}
}
