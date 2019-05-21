#include "application/reachabilityCaller.h"

unsigned int ce_search_time;

void reachabilityCaller(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters, userOptions& user_options,
		int lp_solver_type_choosen, int Solver_GLPK_Gurobi_GPU, std::pair<int, polytope::ptr> forbidden_set,
		std::list<symbolic_states::ptr>& Symbolic_states_list,
		std::list<abstractCE::ptr>& ce_candidates) {

	/*
	 * For algorithm (Seq-SF, Par-SF and Time-Slice) only the Algorithm-Type/user_options.get_algorithm decides to execute
	 */
	 //Sequential PostC and PostD


	if ((user_options.get_algorithm() == SEQ_SF)
			|| (user_options.get_algorithm() == PAR_SF)
			|| (user_options.get_algorithm() == TIME_SLICE) || (user_options.get_algorithm() == GPU_SF)
			|| (user_options.get_algorithm() == FORWARD) ) {

		//sequential reachability algorithm;

		reachability reach_SEQ_BFS;
		//user_options.get_algorithm decides the algorithm for postC, either seq-sf-based, par-sf-sampling, time-slice in PostC,
		//GPU-based postC or postC with forward approximation model. PostD is sequential
		reach_SEQ_BFS.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type_choosen, Solver_GLPK_Gurobi_GPU, forbidden_set, user_options);

		// The right algorithm is selected within the following function
		Symbolic_states_list = reach_SEQ_BFS.computeSequentialBFSReach(ce_candidates);

		std::cout << "-----Safety Analysis Statistics-----\n" << std::endl;
		std::cout << "number of abstract ce-paths found for exploration: " << ce_candidates.size() << std::endl;
		std::list<concreteCE::ptr> ce_list = reach_SEQ_BFS.get_counter_examples();
		std::cout << "Number of concrete ce trajectories found: " << ce_list.size() << std::endl;

		std::cout << "Number of refinements performed when searching: " << reach_SEQ_BFS.get_refinements() << std::endl;
		std::cout << "Time to search concrete counter-example(s) from the abstract path(s) (user time in ms):" << reach_SEQ_BFS.get_ce_search_time() << std::endl;

		// recording statistics in a file to include in the paper
		std::ofstream myfile;
		if(CE_ALGO_TYPE == 1){
			myfile.open("statistics_FC.txt",ios::out | ios::app);
			//std::cout << "Printing statistics in file statistics_FC1.txt" << std::endl;
		}
		else if (CE_ALGO_TYPE == 2){
			myfile.open("statistics_WoFC.txt",ios::out | ios::app);
			//std::cout << "Printing statistics in file statistics_WoFC1.txt" << std::endl;
		}
		else{}


		ce_search_time = reach_SEQ_BFS.get_ce_search_time();

		//unsigned int ce_len; // The length of the shortest CE for noting in the paper in --CE first

		// plot the first counter-example trajectory in the list.
		if(ce_list.size() !=0){
			concreteCE::ptr first_ce = *(ce_list.begin());
			std::string tracefile = "./bad_trace.o";
			first_ce->plot_ce(tracefile,user_options.get_first_plot_dimension(),user_options.get_second_plot_dimension());
		}

		myfile << "model number: " << user_options.get_model() << ", #Paths = "
				<< ce_candidates.size() << ", #CEs = " << ce_list.size()
				<< ", #Refs = " << reach_SEQ_BFS.get_refinements()
				<< ", Cumulative time to search CEs (in secs) = "
				<< reach_SEQ_BFS.get_ce_search_time() / 1000
				<< ", Av.Time to search a CE (in secs) = " << reach_SEQ_BFS.get_ce_search_time() / (1000 * ce_list.size())
				<< ", CE algo used (1=FC, 2=WoFC) = " << CE_ALGO_TYPE
				<< std::endl;
		myfile.close();



	} else if (user_options.get_algorithm() == AGJH_BFS) { //Adaptation of Gerard J. Holzmann's algorithm (Seq PostC and PBFS)
		agjh reach_AGJH;
		reach_AGJH.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type_choosen,
				Solver_GLPK_Gurobi_GPU, forbidden_set, user_options);
		std::cout << "\nRunning an adaptation of Gerard J. Holzmann's algorithm in SPIN model checker\n";
		Symbolic_states_list = reach_AGJH.AGJH(ce_candidates); // Holzmann algorithm adaptation without lock for containment check

	} else if (user_options.get_algorithm() == TPBFS) { // TPBFS -- Task parallel BFS (Load Balancing Algorithm)
		tpbfs reach;
		reach.setReachParameter(Hybrid_Automata, init_state, reach_parameters, lp_solver_type_choosen,
				Solver_GLPK_Gurobi_GPU, forbidden_set, user_options);
		std::cout<< "\nRunning the task parallel BFS algorithm (TPBFS) for an effective load balancing .\n";
		Symbolic_states_list = reach.LoadBalanceAll(
				ce_candidates);
	} else if (user_options.get_algorithm() == ASYNC_BFS) { // AsyncBFS -- Asynchronous parallel BFS (Does not synchronize like in BFS Algorithm)
		AsyncBFS reach;
		reach.setReachParameter(Hybrid_Automata, init_state, reach_parameters,
				lp_solver_type_choosen, Solver_GLPK_Gurobi_GPU, forbidden_set, user_options);
		std::cout<< "\nRunning an asynchronous parallel BFS algorithm (Async BFS) to avoid synchronization overhead.\n";
		Symbolic_states_list = reach.reachComputeAsynBFS(ce_candidates);
	}
}

