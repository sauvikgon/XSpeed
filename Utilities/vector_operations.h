/*
 * vector_operations.h
 *
 *  Created on: 30-Nov-2015
 *      Author: amit
 */

#ifndef VECTOR_OPERATIONS_H_
#define VECTOR_OPERATIONS_H_

#include <vector>
#include <assert.h>

// converts the vector v into a unit vector
std::vector<double> normalize_vector(std::vector<double> v);

//returns a vector which is the bisector of vector u and v
std::vector<double> bisect_vector(std::vector<double> u, std::vector<double> v);


#endif /* VECTOR_OPERATIONS_H_ */
