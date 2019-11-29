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

	std::cout << "-----------Statistics for " << msg << "-----------:" << std::endl;
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

	std::cout << "-----------Statistics for " << msg << "-----------:" << std::endl;
	std::cout << "\nBoost Time taken:Wall  (in Seconds) = " << Avg_wall_clock / (double) 1000 << std::endl;
	std::cout << "\nBoost Time taken:User  (in Seconds) = " << Avg_user_clock / (double) 1000 << std::endl;
	std::cout << "\nBoost Time taken:System  (in Seconds) = " << Avg_system_clock / (double) 1000 << std::endl;
}


