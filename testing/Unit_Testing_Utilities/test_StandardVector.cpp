/*
 * test_StandardVector.cpp
 *
 *  Created on: 25-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include <vector>
#include "Utilities/StandardVector.h"

using namespace std;

SUITE(StandardVector_TestSuite) {
struct ExampleStandardVector {
	ExampleStandardVector() {


	}
	~ExampleStandardVector() { /* some teardown */
	}


	std::vector<double> direction;
	stringstream out, proper;
};

TEST_FIXTURE(ExampleStandardVector, Vector_Join_Test) {

	std::vector<double> v1(4), v2(4), v3;
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;
	v1[3] = 4;

	v2[0] = 7;
	v2[1] = 8;
	v2[2] = 9;
	v2[3] = 10;

	v3 = vector_join(v1, v2);
	cout << "\n\n\n";
	for (unsigned int i = 0; i < v3.size(); i++)
		cout << v3[i] << "\t";
	cout << "\n\n\n";
	/*out<<"amit";
	 proper << "true";
	 CHECK_EQUAL(proper.str(), out.str());*/
}

TEST_FIXTURE(ExampleStandardVector, Vector_Add_Test) {

	std::vector<double> v1(4), v2(4), v3;
	v1[0] = 1;
	v1[1] = 2;
	v1[2] = 3;
	v1[3] = 4;

	v2[0] = 7;
	v2[1] = 8;
	v2[2] = 9;
	v2[3] = 10;

	v3 = vector_add(v1, v2);
	cout << "\n\n\n";
	for (unsigned int i = 0; i < v3.size(); i++)
		cout << v3[i] << "\t";
	cout << "\n\n\n";
	/*out<<"amit";
	 proper << "true";
	 CHECK_EQUAL(proper.str(), out.str());*/
}

}
