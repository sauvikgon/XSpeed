/*
 * test_randNumberGenerator.cpp
 *
 *  Created on: 15-Dec-2017
 *      Author: rajarshi
 */

#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include <vector>
#include "../../core/math/randNumberGenerator.h"

SUITE(randon_number_generator_TestSuite) {
struct randGen {
	randGen() {

	}
	~randGen() { /* some teardown */
	}
};

TEST_FIXTURE(randGen, randNumberGeneratorTest) {

	std::vector<double> random;
	randNumberGenerator randgen;
	random = randgen.getRands(10,20,10);

//	for(unsigned int i=0;i<10;i++)
//	{
//		std::cout << random[i] << std::endl;
//	}

}

}
