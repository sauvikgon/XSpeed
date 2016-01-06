/*
 * vector_operations.cpp
 *
 *  Created on: 30-Nov-2015
 *      Author: amit
 */
#include <math.h>
#include "vector_operations.h"

// converts the vector v into a unit vector
std::vector<double> normalize_vector(std::vector<double> v) {
	std::vector<double> normal_vector(v.size());

	double vector_magitude = 0, vector_sum = 0.0;

	for (int i = 0; i < v.size(); i++) {
		vector_sum = vector_sum + v[i] * v[i];
	}
	vector_magitude = sqrt(vector_sum);
	if (vector_magitude != 0) {
		for (int i = 0; i < v.size(); i++) {
			normal_vector[i] = v[i] / vector_magitude;
		}
	}
	return normal_vector;
}

//returns a vector which is the bisector of vector u and v
std::vector<double> bisect_vector(std::vector<double> u,
		std::vector<double> v) {
	std::vector<double> z(u.size());

	assert(u.size() == v.size());	//checking if u and v are of same dimension
	for (int i=0;i<u.size();i++){
		z[i] = (u[i] + v[i])/2;
	}
	return z;
}
