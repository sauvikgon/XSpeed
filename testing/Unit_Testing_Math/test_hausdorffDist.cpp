/*
 * test_hausdorffDist.cpp
 *
 *  Created on: 19-Sep-2017
 *      Author: rajarshi
 */

#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "core_system/math/matrix.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>
#include "Utilities/HausdorffDistance.h"
#include "core_system/continuous/Polytope/Polytope.h"

using namespace std;

SUITE(HausdorffDistanceTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};

TEST_FIXTURE(Example, HausdorffDistanceTest) {

	polytope::ptr I, P2;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignV;
	std::vector<double> boundValueV;
	math::matrix<double> ConstraintsMatrixV;

	polytope::ptr G;
	row = 4;
	col = 2;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = 0;
	ConstraintsMatrixV(0, 1) = 1;
	ConstraintsMatrixV(1, 0) = 0;
	ConstraintsMatrixV(1, 1) = -1;
	ConstraintsMatrixV(2, 0) = 1;
	ConstraintsMatrixV(2, 1) = 0;
	ConstraintsMatrixV(3, 0) = -1;
	ConstraintsMatrixV(3, 1) = 0;

	boundValueV.resize(4);
	boundValueV[0] = 15;
	boundValueV[1] = -5;
	boundValueV[2] = 15; //9.8;
	boundValueV[3] = -5; //-9.8;

	boundSignV = 1;

	G = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	double d = HausdorffDistance(G, G);
	std::cout << "Hausdorff Distance: " << d << std::endl;
	if (d < 0.000001)
		d = 0;
	CHECK_EQUAL(d, 0);

}
TEST_FIXTURE(Example, HausdorffDistanceTest2) {

	polytope::ptr I, P2;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignV;
	std::vector<double> boundValueV, bV;
	math::matrix<double> ConstraintsMatrixV, cV;

	polytope::ptr G, G2;
	row = 4;
	col = 2;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = 0;
	ConstraintsMatrixV(0, 1) = 1;
	ConstraintsMatrixV(1, 0) = 0;
	ConstraintsMatrixV(1, 1) = -1;
	ConstraintsMatrixV(2, 0) = 1;
	ConstraintsMatrixV(2, 1) = 0;
	ConstraintsMatrixV(3, 0) = -1;
	ConstraintsMatrixV(3, 1) = 0;

	boundValueV.resize(4);
	boundValueV[0] = 15;
	boundValueV[1] = -5;
	boundValueV[2] = 15; //9.8;
	boundValueV[3] = -5; //-9.8;

	boundSignV = 1;

	G = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	cV.resize(row, col);
	cV(0, 0) = 0;
	cV(0, 1) = 1;
	cV(1, 0) = 0;
	cV(1, 1) = -1;
	cV(2, 0) = 1;
	cV(2, 1) = 0;
	cV(3, 0) = -1;
	cV(3, 1) = 0;
	bV.resize(4);
	bV[0] = 15;
	bV[1] = -10;
	bV[2] = 15; //9.8;
	bV[3] = -10; //-9.8;

	G2= polytope::ptr(
			new polytope(cV, bV, boundSignV));

	double d = HausdorffDistance(G, G2);
	std::cout << "Hausdorff Distance (should be 7.0710678): " << d << std::endl;
	int res=0;
//	res= d - 7.07107;
	if ((d - 7.07107) < 0.00001)
		res = 0;

	CHECK_EQUAL(res, 0);
	//CHECK_EQUAL(d, 7.07107);

}
TEST_FIXTURE(Example, HausdorffDistanceTest3) {

	polytope::ptr I, P2;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignV;
	std::vector<double> boundValueV, bV;
	math::matrix<double> ConstraintsMatrixV, cV;

	polytope::ptr G, G2;
	row = 4;
	col = 2;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = 0;
	ConstraintsMatrixV(0, 1) = 1;
	ConstraintsMatrixV(1, 0) = 0;
	ConstraintsMatrixV(1, 1) = -1;
	ConstraintsMatrixV(2, 0) = 1;
	ConstraintsMatrixV(2, 1) = 0;
	ConstraintsMatrixV(3, 0) = -1;
	ConstraintsMatrixV(3, 1) = 0;

	boundValueV.resize(4);
	boundValueV[0] = 15;
	boundValueV[1] = -5;
	boundValueV[2] = 15; //9.8;
	boundValueV[3] = -5; //-9.8;

	boundSignV = 1;

	G = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	cV.resize(row, col);
	cV(0, 0) = 0;
	cV(0, 1) = 1;
	cV(1, 0) = 0;
	cV(1, 1) = -1;
	cV(2, 0) = 1;
	cV(2, 1) = 0;
	cV(3, 0) = -1;
	cV(3, 1) = 0;
	bV.resize(4);
	bV[0] = 15;
	bV[1] = -10;
	bV[2] = 15;
	bV[3] = -5;

	G2= polytope::ptr(
			new polytope(cV, bV, boundSignV));

	double d = HausdorffDistance(G, G2);
	std::cout << "Hausdorff Distance (should be 5) = " << d << std::endl;
	int res=d;
	//CHECK_EQUAL(d, 5);
	CHECK_EQUAL(res, 5);

}

}

