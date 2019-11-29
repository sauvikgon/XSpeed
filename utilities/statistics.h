/*
 * statistics.h
 *
 *  Created on: 29-Nov-2019
 *      Author: rajarshi
 */

#ifndef __statistics_h
#define __statistics_h

/**
 * The first argument is the timer for executing an algorithm, storing the total time
 * to run for num_experiments number of times. This method is used to get the average
 * execution time for the algorithm and print the stats on the console.
 */
#include "boost/timer/timer.hpp"

void print_statistics(boost::timer::cpu_timer timer, double cpu_usage, long mem_usage, unsigned int num_exps, std::string msg);
void print_statistics(boost::timer::cpu_timer timer, std::string msg);

#endif
