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
#include <set>
#include <utility>

#include "core_system/math/matrix.h"


// converts the vector v into a unit vector
std::vector<double> normalize_vector(std::vector<double> v);

//returns a vector which is the bisector of vector u and v
std::vector<double> bisect_vector(std::vector<double> u, std::vector<double> v);

bool isEqual_Vectors(std::vector<double> u, std::vector<double> v);

math::matrix<double> matrix_vertices(std::set<std::pair<double, double> > set_vertices);

//sorting the 2d vertices
math::matrix<double> sort_vertices(std::set<std::pair<double, double> > set_vertices);


#endif /* VECTOR_OPERATIONS_H_ */
