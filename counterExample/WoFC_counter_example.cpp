/*
 * WoFC_counter_example.cpp
 *
 *  Created on: 02-Oct-2018
 *      Author: amit
 */

#include "WoFC_counter_example.h"

void runWoFC_counter_example(std::list<structuralPath::ptr>& allPaths,
		hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr> init_state, polytope::ptr forbidden_set, userOptions& user_options) {

	polytope::ptr initialSet = (*init_state.begin())->getInitialSet();

	for (std::list<structuralPath::ptr>::iterator it = allPaths.begin();
			it != allPaths.end(); it++) {
		unsigned int symbolic_ce_length = (*it)->get_path_locations().size();

		abstractCE::ptr abst_ce = abstractCE::ptr(new abstractCE());
		abst_ce->set_length(symbolic_ce_length);

		std::list<symbolic_states::ptr> list_sym_states;
		std::list<location::ptr> locs_path = (*it)->get_path_locations();
		for (std::list<location::ptr>::iterator itloc = locs_path.begin();
				itloc != locs_path.end(); itloc++) {
			symbolic_states::ptr sym_states = symbolic_states::ptr(
					new symbolic_states());

			sym_states->setInitialPolytope(initialSet);	//only for the

			discrete_set discrete_state;
			discrete_state.insert_element((*itloc)->getLocId()); //creating discrete_state
			sym_states->setDiscreteSet(discrete_state);
			list_sym_states.push_back(sym_states);
		}

		abst_ce->set_sym_states(list_sym_states);

		abst_ce->set_transitions((*it)->get_path_transitions());
		hybrid_automata::ptr ha = hybrid_automata::ptr(
				new hybrid_automata(Hybrid_Automata));
		abst_ce->set_automaton(ha);
		abst_ce->set_forbid_poly(forbidden_set);

		bool continue_search = gen_counter_example_WoFC(abst_ce, user_options);
		if (continue_search == false) { // This status says whether to continue searching for further abstract paths or to stop
			std::cout << "############# Safety Property is Violated #################\n";
		}
		//break; trying out only a single path
	}
}

bool gen_counter_example_WoFC(abstractCE::ptr abs_path,	userOptions& user_options) {
	double splicing_error_tol = 1e-6; // A parameter particular to counter-example searching
	unsigned int algo_type = 2; // A parameter particular to mentioning the type of ce search algorithm to use 1 (FC) uses the method using flowpipe constraints and 2 uses the method using flowpipe constraints (WFC)

	string ce_path = user_options.get_ce_path();
	std::list<concreteCE::ptr> ce_list; // the list of concrete counter-examples in the HA.
	unsigned int refinements; // The number of refinements during the search of counter-example trajectories. This has meaning only when the counter-example generation function is enabled.

	if (ce_path.compare("all") == 0) // if all paths are to be searched for ce, then return true in order to collect more paths.
	{
		concreteCE::ptr ce = abs_path->get_validated_CE(splicing_error_tol,	algo_type);
		if (!ce->is_empty())
			ce_list.push_back(ce);
		refinements += ce->get_refinements(); // add the number of refinements performed for this ce object (even if it is empty)
		return true; // In order to continue searching for further paths during BFS.
	}
	if (ce_path.compare("first") == 0) // Stop the BFS search once a concrete ce has been found
			{
		concreteCE::ptr ce = abs_path->get_validated_CE(splicing_error_tol,
				algo_type);
		refinements += ce->get_refinements();
		if (!ce->is_empty()) {
			ce_list.push_back(ce);
			return false; 		// In order to terminate the BFS.
		} else
			return true; // continue for searching the first concrete trajectory
	}
	// We assume that if the path specified is not "all" and not "first" then it must be a comma separated description of a path

	// create a path template to filter search
	std::vector<unsigned int> path_filter(0);
	path_filter = path_parser(ce_path);

	bool search_ce = abs_path->filter(path_filter); // search_ce is true when the abstract path matched with the user requested path

	if (search_ce) {

		boost::timer::cpu_timer timer;
		timer.start();
		concreteCE::ptr ce = abs_path->get_validated_CE(splicing_error_tol,
				algo_type);
		timer.stop();

		double wall_time, user_time, system_time;

		wall_time = timer.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
		user_time = timer.elapsed().user / 1000000;
		system_time = timer.elapsed().system / 1000000;

		std::cout
				<< "Time to search a concrete counter-example trajectory from the abstract path (user time in ms):"
				<< user_time << std::endl;

		if (ce->is_empty())
			std::cout
					<< "Cannot find a counter-example trajectory in the specified path\n";
		else
			ce_list.push_back(ce);
		refinements = ce->get_refinements();

		return false;	// In order to terminate the BFS.
	} else { // The user specified path is not this abstract path in abs_path. Hence search for other abstract paths during BFS.
		return true; // In order to continue searching for further paths during BFS.
	}
}
