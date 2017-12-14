/*
 * test_randNumberGenerator.cpp
 *
 *  Created on: 15-Dec-2017
 *      Author: rajarshi
 */

#include <iostream>
#include "UnitTest++.h"
#include "core_system/math/randNumberGenerator.h"

SUITE(randon_number_generator_TestSuite) {
struct randGen {
	randGen() {

	}
	~randGen() { /* some teardown */
	}
};

TEST_FIXTURE(randGen, randNumberGeneratorTest) {

	double random[10];
	randNumberGenerator(0,20,10,random);
	std::cout << "Printing the uniformly distributed random numbers:\n";

	for(unsigned int i=0;i<10;i++)
	{
		std::cout << random[i] << std::endl;
	}
}

}
