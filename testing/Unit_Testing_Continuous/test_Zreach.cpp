#include <sstream>
#include <iostream>
//#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev

using namespace std;

SUITE(continuous_reach_TestSuite) {
struct ReachExamples {
	ReachExamples() {

	}

	~ReachExamples() {
		/* some teardown */
	}
	/*
	 * Variable declaration
	 */
};

TEST_FIXTURE(ReachExamples, Reach_BBall_Xposition_and_Yvelocity_Test) {
	//this tester is obsolete now
}

}

