/*
 * 2d_geometry.h
 *
 *  Created on: 30-Nov-2015
 *      Author: amit
 */

#ifndef GEOMETRY_2D_H_
#define GEOMETRY_2D_H_

#include "core_system/math/numeric/basic_geometry.h"
#include <vector>

typedef std::pair<double, double> point;

bool is_collinear(point p1, point p2, point p3);

//Returns angle between the vector u and v
double angle_uv(std::vector<double> u, std::vector<double> v);

#endif /* GEOMETRY_2D_H_ */
