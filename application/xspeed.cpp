/**
 * The main file of XSpeed.
 * @Author: Rajarshi
 */

#include <core/continuous/polytope/polytope.h>
#include <iostream>
#include <fstream>
#include "application/readCommandLine.h"
#include <application/themeSelector.h>

int main(int argc, char *argv[]) {

	themeSelector tool_theme;

	// parse input and user options
	try{
		readCommandLine(argc, argv, tool_theme.getUserOps(), tool_theme.getInit(),
				tool_theme.getReachParams(), tool_theme.getForbidden());
	}catch(std::exception& e){
		std::cout << "Exception:" << e.what() << std::endl;
		std::cout << "\nTerminating XSpeed, caused due to error in command-line inputs.\n";
		std::cout << "Try XSpeed --help to see the command-line options\n";
		exit(0);
	}
	// call the appropriate analysis engine
	tool_theme.select();

	return 0;
}
