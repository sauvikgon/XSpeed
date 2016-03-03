/*
 * test_StandardVector.cpp
 *
 *  Created on: 25-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include <string>
#include <vector>
#include "Utilities/StandardVector.h"
#include "boost/lexical_cast.hpp"

using namespace std;

SUITE(StandardVector_TestSuite) {
struct ExampleStandardVector {
	ExampleStandardVector() {


	}
	~ExampleStandardVector() { /* some teardown */
	}


	std::vector<double> direction;
	stringstream out1, proper;
};

TEST_FIXTURE(ExampleStandardVector, Vector_Join_Test) {

	std::vector<double> v1(4), v2(4), v3, v3_res(8);
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;
	v1[3] = 4;

	v2[0] = 7;
	v2[1] = 8;
	v2[2] = 9;
	v2[3] = 10;

	v3_res[0] = 1;
	v3_res[1] = 2;
	v3_res[2] = 3;
	v3_res[3] = 4;
	v3_res[4] = 7;
	v3_res[5] = 8;
	v3_res[6] = 9;
	v3_res[7] = 10;

	v3 = vector_join(v1, v2);

	CHECK_ARRAY_EQUAL(v3_res,v3,v3.size());

}

TEST_FIXTURE(ExampleStandardVector, Vector_Add_Test) {

	std::vector<double> v1(4), v2(4), v3, v3_res(8);
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;
	v1[3] = 4;

	v2[0] = 7;
	v2[1] = 8;
	v2[2] = 9;
	v2[3] = 10;

	v3_res[0] = 8;
	v3_res[1] = 10;
	v3_res[2] = 12;
	v3_res[3] = 14;

	v3 = vector_add(v1, v2);

	CHECK_ARRAY_EQUAL(v3_res,v3,v3.size());
}

}
