/*
 * WoFC_counter_example.cpp
 *
 *  Created on: 02-Oct-2018
 *      Author: amit
 */

#include "WoFC_counter_example.h"

bool runWoFC_counter_example(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr> init_state, std::pair<int, polytope::ptr> forbidden_set, userOptions& user_options) {

	unsigned int destLoc = forbidden_set.first;			// The location id of the forbidden symbolic state
	unsigned int depthBound = user_options.get_bfs_level() + 1;//trans 0 is the first flowpipe. Thus, depthBound should be +1





	/* Get all structural discrete paths in the HA here*/
	boost::timer::cpu_timer timePaths;
	//std::cout<<"destLoc= " << destLoc<<"    depth bound = "<<depthBound<<std::endl;
	timePaths.start();
	std::list<structuralPath::ptr> allPaths = Hybrid_Automata.get_structural_paths(destLoc, depthBound);
	timePaths.stop();
	//std::cout<<"allPaths = "<<allPaths.size()<<"\n";
			//double wall_clock_timePaths_nanosec, wall_clock_timePaths_millisec, wall_clock_timePaths_sec;
	double user_clock_timePaths_nanosec, user_clock_timePaths_millisec, usertime_Paths_sec;
	user_clock_timePaths_millisec = timePaths.elapsed().user / (double) 1000000; //convert nanoseconds to milliseconds
	usertime_Paths_sec = user_clock_timePaths_millisec / (double) 1000;

	polytope::ptr initialSet = (*init_state.begin())->getInitialSet();

	double traj_splicing_time=0;	//global reference variable

	unsigned int refinements=0;
	std::list<concreteCE::ptr> ce_list; // the list of concrete counter-examples in the HA.
	unsigned int total_absPath_searched =0;
	for (std::list<structuralPath::ptr>::iterator it = allPaths.begin(); it != allPaths.end(); it++) {
		unsigned int symbolic_ce_length = (*it)->get_path_locations().size();

		abstractCE::ptr abst_ce = abstractCE::ptr(new abstractCE());
		abst_ce->set_length(symbolic_ce_length);

		std::list<symbolic_states::ptr> list_sym_states;
		std::list<location::ptr> locs_path = (*it)->get_path_locations();

		unsigned int path_index = 0; // This is an index to the location on the path during a traversal.

		for (std::list<location::ptr>::iterator itloc = locs_path.begin();
				itloc != locs_path.end(); itloc++, path_index++) {
			symbolic_states::ptr sym_states = symbolic_states::ptr(new symbolic_states());
			if(path_index==0)
				sym_states->setInitialPolytope(initialSet);	//only for the first one.
			else{
				polytope::ptr empty_poly = polytope::ptr(new polytope(true)); // creates an empty polytope
				sym_states->setInitialPolytope(empty_poly);
			}
			discrete_set discrete_state;
			discrete_state.insert_element((*itloc)->getLocId()); //creating discrete_state
			sym_states->setDiscreteSet(discrete_state);
			list_sym_states.push_back(sym_states);
		}

		abst_ce->set_sym_states(list_sym_states);

		abst_ce->set_transitions((*it)->get_path_transitions());
		hybrid_automata::ptr ha = hybrid_automata::ptr( new hybrid_automata(Hybrid_Automata));
		abst_ce->set_automaton(ha);
		abst_ce->set_forbid_poly(forbidden_set.second);

		std::cout << "CE_ALGO_TYPE "<< 2 << std::endl;
		bool continue_search = gen_counter_example_WoFC(abst_ce, user_options, traj_splicing_time, refinements, ce_list);
		total_absPath_searched++;
		std::cout << "Abstract Graph Path(s) Searched so far = "<< total_absPath_searched << std::endl;
		if (continue_search == false) { // This status says to Stop searching for further abstract paths
			//Can be  here
			break; //trying out only a single/first path
		}
	}


	//This section to be placed in "Can be  here"

	//std::cout << "############# Safety Property is Violated #################\n";
	std::cout << "-----Safety Analysis Statistics-----\n" << std::endl;
	std::cout << "number of abstract ce-paths found for exploration: " << allPaths.size() << std::endl;
	//std::list<concreteCE::ptr> ce_list = reach_SEQ_BFS.get_counter_examples();
	std::cout << "Number of concrete ce trajectories found: " << ce_list.size() << std::endl;

	std::cout << "Number of refinements performed when searching: " << refinements << std::endl;
	double ce_search_time_sec = traj_splicing_time / (double) 1000;
	std::cout << "Time to search concrete counter-example(s) from the abstract path(s) (in sec):" << ce_search_time_sec << std::endl;

	std::cout << "Number of Graph paths = " << allPaths.size()<<endl;
	std::cout << "Total time to search all structural paths (in secs) = " << usertime_Paths_sec <<endl;
	std::cout << "Total time to Falsify (in secs) = " << (ce_search_time_sec + usertime_Paths_sec) <<endl;

	// recording statistics in a file to include in the paper
	std::ofstream myfile;
	myfile.open("statistics_WoFC.txt",ios::out | ios::app);
	myfile << "New Table 4 data (using HA structural paths with Exp-Graph): \n";

	myfile << "model number: " << user_options.get_model() << "; #Paths = " << allPaths.size()
			<< "; Time to search all structural paths (in secs):" << usertime_Paths_sec
			<< "; #CEs = " << ce_list.size() << ", #Refs = " << refinements
			<< ", Total Time to search concrete CEs (in secs) = " << ce_search_time_sec << std::endl;
	myfile.close();



}


bool gen_counter_example_WoFC(abstractCE::ptr abs_path,
		userOptions& user_options, double& WoFC_traj_splicing_time,
		unsigned int& refinements, std::list<concreteCE::ptr>& ce_list) {
	double splicing_error_tol = 1e-6; // A parameter particular to counter-example searching


	unsigned int algo_type = 2; // A parameter particular to mentioning the type of ce search algorithm to use 1 (FC) uses the method using flowpipe constraints and 2 uses the method using flowpipe constraints (WoFC)
	string ce_path = user_options.get_ce_path();
	boost::timer::cpu_timer clock; // clocks the time taken to splice a trajectory

	if(WoFC_traj_splicing_time > 3600000){
		std::cout << "Seach for CE TIMED-OUT (>1hrs)\n";
		return false;
	}
	if(ce_path.compare("all") == 0) // if all paths are to be searched for ce, then return true in order to collect more paths.
	{
		clock.start();
		concreteCE::ptr ce = abs_path->get_validated_CE(splicing_error_tol,	algo_type);
		clock.stop();
		WoFC_traj_splicing_time += clock.elapsed().user /1000000;

		if(!ce->is_empty())
			ce_list.push_back(ce);

		refinements += ce->get_refinements(); // add the number of refinements performed for this ce object (even if it is empty)
		return true; // In order to continue searching for further paths during BFS.
	}
	if(ce_path.compare("first") == 0) // Stop the BFS search once a concrete ce has been found
	{
		clock.start();
		concreteCE::ptr ce = abs_path->get_validated_CE(splicing_error_tol,algo_type);
		clock.stop();
		WoFC_traj_splicing_time += clock.elapsed().user / 1000000;

		refinements += ce->get_refinements();
		if(!ce->is_empty()){
			ce_list.push_back(ce);
			return false; 		// In order to terminate the BFS.
		}
		else
			return true; // continue for searching the first concrete trajectory
	}
	// We assume that if the path specified is not "all" and not "first" then it must be a comma separated description of a path

	// create a path template to filter search
	std::vector<unsigned int> path_filter(0);
	path_filter = path_parser(ce_path);

	bool search_ce = abs_path->filter(path_filter); // search_ce is true when the abstract path matched with the user requested path

	if(search_ce){

		clock.start();
		concreteCE::ptr ce = abs_path->get_validated_CE(splicing_error_tol,algo_type);
		clock.stop();
		WoFC_traj_splicing_time += clock.elapsed().user /1000000;

		if(ce->is_empty())
			std::cout << "Cannot find a counter-example trajectory in the specified path\n";
		else
			ce_list.push_back(ce);
		refinements = ce->get_refinements();

		return false;	// In order to terminate the BFS.
	}
	else{ // The user specified path is not this abstract path in abs_path. Hence search for other abstract paths during BFS.
		return true;  // In order to continue searching for further paths during BFS.
	}

}
