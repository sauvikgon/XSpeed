/*
 * 2d_geometry.h
 *
 *  Created on: 30-Nov-2015
 *      Author: amit
 */

#ifndef GEOMETRY_2D_H_
#define GEOMETRY_2D_H_

#include "core_system/math/numeric/basic_geometry.h"

typedef std::pair<double, double> point;

bool is_collinear(point p1, point p2, point p3);

#endif /* GEOMETRY_2D_H_ */
