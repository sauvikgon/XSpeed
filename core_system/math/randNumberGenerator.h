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

/*
 * Generator uniformly distributed random number within the interval: [min, max].
 * Generates numrands numbers in an array
 * Return the array result containing the random numbers.
 */
void randNumberGenerator(double min, double max, int numrands, double* res);


#endif /* RANDNUMBERGENERATOR_H_ */

