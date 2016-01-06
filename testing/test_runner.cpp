//============================================================================
// Name        : test_runner.cpp
// Author      : Goran Frehse
// Version     :
// Copyright   : (C) 2008
// Description : Hello World in C++, Ansi-style
//============================================================================

//unsigned int VERBOSE_LEVEL=600011;
//unsigned int line_number=0;

#include <iostream>
//#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "unitTest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
//#include "DebugOutputReporter.h"
#include <sys/ptrace.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

int main() {

	std::cout << "testers called\n";
	return UnitTest::RunAllTests();
}
