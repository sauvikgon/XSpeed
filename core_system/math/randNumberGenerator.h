/*
 * randNumberGenerator.h
 *
 *  Created on: 15-Dec-2017
 *      Author: rajarshi
 */

#ifndef RANDNUMBERGENERATOR_H_
#define RANDNUMBERGENERATOR_H_

#include <random>
#include <cmath>

class randNumberGenerator
{

	 std::default_random_engine generator;
	 std::uniform_real_distribution<double> distribution;

public:
	 randNumberGenerator(){
		 generator = std::default_random_engine();
		 distribution = std::uniform_real_distribution<double>();
	 }
	 ~randNumberGenerator(){};
	/*
	 * Generator uniformly distributed random number within the interval: [min, max].
	 * Generates numrands numbers in an array
	 * Return the array result containing the random numbers.
	 */
	std::vector<double> getRands(double min, double max, unsigned int n);

};


#endif /* RANDNUMBERGENERATOR_H_ */

