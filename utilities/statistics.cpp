/*
 * statistics.cpp
 *
 *  Created on: 29-Nov-2019
 *      Author: rajarshi
 */

#include <iostream>
#include "statistics.h"
#include "utilities/cpu_utilities/cpu_utilities.h"
#include "utilities/memory_utilities/memory_usage.h"


void print_statistics(boost::timer::cpu_timer timer, double cpu_usage, long mem_usage, unsigned int num_exps, std::string msg)
{
	double Avg_cpu_usage;
	double wall_clock, user_clock, system_clock;

	wall_clock = timer.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	user_clock = timer.elapsed().user / 1000000;
	system_clock = timer.elapsed().system / 1000000;

	Avg_cpu_usage = cpu_usage / num_exps;

	double Avg_wall_clock = wall_clock / num_exps;
	double Avg_user_clock = user_clock / num_exps;
	double Avg_system_clock = system_clock / num_exps;

	std::cout << "\n-----Statistics for " << msg << "-----------" << std::endl;
	std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << Avg_wall_clock / (double) 1000 << std::endl;
	std::cout << "\nBoost Time taken:User  (in Seconds) = " << Avg_user_clock / (double) 1000 << std::endl;
	std::cout << "\nBoost Time taken:System  (in Seconds) = " << Avg_system_clock / (double) 1000 << std::endl;
	std::cout << "\nCPU Usage:(%) = " << Avg_cpu_usage << std::endl;
	std::cout << "Memory Usages = " << (double) (mem_usage / 1024.0) / num_exps << " MB\n";

}
void print_statistics(boost::timer::cpu_timer timer, std::string msg)
{

	double wall_clock, user_clock, system_clock;

	wall_clock = timer.elapsed().wall / 1000000; //convert nanoseconds to milliseconds
	user_clock = timer.elapsed().user / 1000000;
	system_clock = timer.elapsed().system / 1000000;

	double Avg_wall_clock = wall_clock;
	double Avg_user_clock = user_clock;
	double Avg_system_clock = system_clock;

	std::cout << "\n-----Statistics for " << msg << "-----------" << std::endl;
	std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << Avg_wall_clock / (double) 1000 << std::endl;
	std::cout << "\nBoost Time taken:User  (in Seconds) = " << Avg_user_clock / (double) 1000 << std::endl;
	std::cout << "\nBoost Time taken:System  (in Seconds) = " << Avg_system_clock / (double) 1000 << std::endl;
	std::cout << std::endl;
}
void print_ce_statistics(reachability& reachObj, std::list<abstractCE::ptr>& ce_candidates, userOptions& user_options, std::string msg)
{
	std::cout << "\n\n-----Statistics for " << msg << "-----------" << std::endl;
	std::cout << "number of abstract ce-paths found for exploration: " << ce_candidates.size() << std::endl;
	std::list<concreteCE::ptr> ce_list = reachObj.get_counter_examples();
	std::cout << "Number of concrete ce trajectories found: " << ce_list.size() << std::endl;

	std::cout << "Number of refinements performed when searching: " << reachObj.get_refinements() << std::endl;
	std::cout << "Time to search concrete counter-example(s) from the abstract path(s) (user time in ms):" << reachObj.get_ce_search_time() << std::endl;
	std::cout << std::endl;
	unsigned int ce_search_time = reachObj.get_ce_search_time();

	// plot the first counter-example trajectory in the list.
	if(ce_list.size() !=0){
		concreteCE::ptr first_ce = *(ce_list.begin());
		std::string tracefile = "./bad_trace.o";
		first_ce->plot_ce(tracefile,user_options.get_first_plot_dimension(),user_options.get_second_plot_dimension());
	}
}

