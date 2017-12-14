/*
 * randNumberGenerator.cpp
 *
 *  Created on: 15-Dec-2017
 *      Author: rajarshi
 */

#include "randNumberGenerator.h"



/*
 * [Minf, Maxf] is the interval within which the function generated random number
 * of double data type.
 * numrands is the number of random numbers to be generated by the function.
 * Ruturns an array of random numbers in randarray
 */

void randNumberGenerator(double minf, double maxf, int numrands, double* res) {

	 std::default_random_engine generator;
	 std::uniform_real_distribution<double> distribution(minf,maxf);

	 for(unsigned int i=0;i<numrands;i++){

		 double number = distribution(generator);
		 res[i] = number;
	 }
}


