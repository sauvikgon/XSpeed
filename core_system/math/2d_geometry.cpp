/*
 * 2d_geometry.cpp
 *
 *  Created on: 30-Nov-2015
 *      Author: amit
 */


#include "2d_geometry.h"

bool is_collinear(point p1, point p2, point p3) {
	double x1, y1, x2, y2, x3, y3;
	x1 = p1.first;
	y1 = p1.second;

	x2 = p2.first;
	y2 = p2.second;

	x3 = p3.first;
	y3 = p3.second;

	return math::numeric::is_colinear(x1, y1, x2, y2, x3, y3);
}
