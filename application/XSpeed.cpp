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
	    ("model", po::value<int>()->default_value(1),
	    		"set model for reachability analysis\n"
	    		"1. Bouncing Ball Model \n"
	    		"2. Timed Bouncing Ball Model\n"
	    		"3. Helicopter Controller Model\n"
	    		"4. Navigation Benchmark Model (3 X 3)\n"
	    		"5. Five dimensional Benchmark Model \n")

		("gpu", "Enable GPU Acceleration. GPU acceleration is OFF by default")
		("mc", "Enable Multi-core Acceleration. Multi-core acceleration is OFF by default")
		("time-slice", po::value<int>()->default_value(1), "Enable Time Sliced Reachability")
		("pbfs", "Enable Parallel Breadth First Exploration of Hybrid Automata Locations. PBFS is OFF by default")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if (vm.count("help")) {
	    cout << desc << "\n";
	    return 1;
	}
	if(vm.count("model")){
		int m = vm["model"].as<int>();
		if(m == 1){
			std::cout << "Running Reachability Analysis on Bouncing Ball model\n";
		}
		else if(m==2){
			std::cout << "Running Reachability Analysis on Timed-Bouncing Ball model\n";
		}
		else if(m==3){
			std::cout << "Running Reachability Analysis on Helicopter Controller model\n";
		}
		else if(m==4){
			std::cout << "Running Reachability Analysis on Navigation Benchmark (3 X 3)\n";
		}
		else if(m==5){
			std::cout << "Running Reachability Analysis on Five-Dimensional Benchmark model\n";
		}
		else{
			std::cout << "Invalid Model option specified\n";
			return 0;
		}
	}

	if(vm.count("gpu") && vm.count("mc")){
		std::cout << "Running Reachability Analysis with GPU and Multi-core acceleration\n";
		return 0;
	}

	if(vm.count("gpu")){
		std::cout << "Running Reachability Analysis with GPU acceleration\n";
		return 0;
	}

	if(vm.count("mc")){
		std::cout << "Running Reachability Analysis with Multi-core acceleration\n";
		return 0;
	}
	if(vm.count("pbfs")){
		std::cout << "Running Reachability Analysis with parallel Breadth First Search using Multi-core acceleration\n";
		return 0;
	}
	if(vm.count("time-slice")){
		std::cout << "Running Timed sliced Flowpipe Computation with " << vm["time-slice"].as<int>() <<" time slices\n";
		return 0;
	}
	return 0;//returning only the Wall time taken to execute the Hybrid System
}

