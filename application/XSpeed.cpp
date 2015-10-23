/*
 * XSpeed.cpp
 *
 *  Created on: 23-Oct-2015
 *      Author: ray
 */

#include "boost/program_options.hpp"
#include <boost/config.hpp>
#include <boost/program_options/detail/config_file.hpp>
#include <boost/program_options/parsers.hpp>

namespace po = boost::program_options;

using namespace std;

int main(int argc, char *argv[]) {

	po::options_description desc("XSpeed options");
	desc.add_options()
	    ("help", "produce help message")
	    ("model", po::value<int>(), "set model for reachability analysis")
		("gpu", "Enable GPU Acceleration")
		("mc", "Enable Multi-core Acceleration")
		("time-slice", po::value<int>(), "Enable Time Sliced Reachability")
		("pbfs", "Enable Parallel Breadth First Exploration of Hybrid Automata Locations")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (vm.count("help")) {
	    cout << desc << "\n";
	    return 1;
	}

	return 0;//returning only the Wall time taken to execute the Hybrid System
}

