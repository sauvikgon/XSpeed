/*
 * test_matrix.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>

#include "UnitTest++.h"
#include "core_system/math/2d_geometry.h"
#include <string>
using namespace std;

SUITE(2d_geometry_TestSuite) {
struct geometry_2d {
	geometry_2d() {
	}
	~geometry_2d() { /* some teardown */
	}

	typedef std::pair<double, double> point;
	point p1, p2, p3;
	stringstream out, proper, out1, proper1;
};

TEST_FIXTURE(geometry_2d, is_collinear_Test) {
	//std::cout << "\nTesting collinear points\n";
	p1.first = 2;
	p1.second = 3;

	p2.first = 6;
	p2.second = 3;

	p3.first = 10;
	p3.second = 3;
	bool flag;
	flag = is_collinear(p1, p2, p3);
	if (flag)
		out << "true";
	else
		out << "flase";

	proper << "true";
	CHECK_EQUAL(proper.str(), out.str());

	//std::cout << "Result is " << flag << std::endl;
}

TEST_FIXTURE(geometry_2d, non_collinear_Test) {
	//std::cout << "\nTesting Non-collinear points\n";
	p1.first = 2;
	p1.second = 6;

	p2.first = 6;
	p2.second = 8;

	p3.first = 10;
	p3.second = 6;
	bool flag;
	flag = is_collinear(p1, p2, p3);
	if (flag)
		out1 << "true";
	else
		out1 << "false";

	proper1 << "false";
	CHECK_EQUAL(proper1.str(), out1.str());

//	std::cout << "Result is " << flag << std::endl;
}

TEST_FIXTURE(geometry_2d, is_collinear_Test2) {
//	std::cout << "\nTesting collinear points Test-2\n";
	p1.first = 4;
	p1.second = 4;

	p2.first = 4;
	p2.second = 8;

	p3.first = 4;
	p3.second = 12;
	out << "";
	proper << "";

	bool flag;
	flag = is_collinear(p1, p2, p3);
	if (flag)
		out << "true";
	else
		out << "false";

	proper << "true";
	CHECK_EQUAL(proper.str(), out.str());

//	std::cout << "Result is " << flag << std::endl;
}

TEST_FIXTURE(geometry_2d, angle_uv) {
	//std::cout << "\nReturn angle between u and v\n";
	std::vector<double> dir1(2, 0), dir2(2, 0);

	dir1[0] = 1;
	dir2[1] = 1;
	double ang;
	ang = angle_uv(dir1, dir2);

	out << "";
	out << ang;
	proper << "";
	proper << "90";
//	std::cout << "Result is Angle = " << ang << std::endl;	//90 degree

	CHECK_EQUAL(proper.str(), out.str());
}

TEST_FIXTURE(geometry_2d, angle_uv_test2) {
//	std::cout << "\nReturn angle between u and v\n";
	std::vector<double> dir1(2, 0), dir2(2, 0);

	dir1[0] = 1;

	dir2[0] = 1;
	dir2[1] = 1;
	double ang;
	ang = angle_uv(dir1, dir2);
	out << "";
	out << ang;
	proper << "";
	proper << "45";

//	std::cout << "Result is Angle = " << ang << std::endl;	//45 degree

	CHECK_EQUAL(proper.str(), out.str());
}
}

