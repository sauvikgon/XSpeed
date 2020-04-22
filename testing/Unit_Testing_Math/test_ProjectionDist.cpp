/*
 * test_hausdorffDist.cpp
 *
 *  Created on: 19-Sep-2017
 *      Author: rajarshi
 */

#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>

#include "../../core/continuous/Polytope/polytope.h"
#include "../../core/math/matrix.h"
#include "../../utilities/directionalApproxError.h"

using namespace std;

SUITE(ApproxErrorTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};

TEST_FIXTURE(Example, ApproxErrorTest1) {

	polytope::ptr I, P2;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignV;
	std::vector<double> boundValueV;
	math::matrix<double> ConstraintsMatrixV;

	polytope::ptr box;
	row = 4;
	col = 2;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = 1;
	ConstraintsMatrixV(0, 1) = 0;
	ConstraintsMatrixV(1, 0) = -1;
	ConstraintsMatrixV(1, 1) = 0;
	ConstraintsMatrixV(2, 0) = 0;
	ConstraintsMatrixV(2, 1) = 1;
	ConstraintsMatrixV(3, 0) = 0;
	ConstraintsMatrixV(3, 1) = -1;

	boundValueV.resize(4);
	boundValueV[0] = 5;
	boundValueV[1] = 0;
	boundValueV[2] = 5;
	boundValueV[3] = 0;

	boundSignV = 1;

	box = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	std::list<std::vector<double> > X2;
	std::vector<double> v(2);
	v[0] = 0; v[1] = 0;
	X2.push_back(v);

	v[0] = 5; v[1] = 0;
	X2.push_back(v);

	v[0] = 5; v[1] = 5;
	X2.push_back(v);

	v[0] = 0; v[1] = 5;
	X2.push_back(v);

	double d = ApproxError(box, X2);
	if (d < 0.000001)
		d = 0;
	CHECK_EQUAL(d, 0);

}

TEST_FIXTURE(Example, ApproxErrorTest2) {

	polytope::ptr I, P2;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignV;
	std::vector<double> boundValueV;
	math::matrix<double> ConstraintsMatrixV;

	polytope::ptr box;
	row = 4;
	col = 2;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = 1;
	ConstraintsMatrixV(0, 1) = 0;
	ConstraintsMatrixV(1, 0) = -1;
	ConstraintsMatrixV(1, 1) = 0;
	ConstraintsMatrixV(2, 0) = 0;
	ConstraintsMatrixV(2, 1) = 1;
	ConstraintsMatrixV(3, 0) = 0;
	ConstraintsMatrixV(3, 1) = -1;

	boundValueV.resize(4);
	boundValueV[0] = 5;
	boundValueV[1] = 0;
	boundValueV[2] = 5;
	boundValueV[3] = 0;

	boundSignV = 1;

	box = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	std::list<std::vector<double> > X2;
	std::vector<double> v(2);
	v[0] = 0; v[1] = 0;
	X2.push_back(v);

	v[0] = 5; v[1] = 0;
	X2.push_back(v);
//
//	v[0] = 5; v[1] = 5;
//	X2.push_back(v);

	v[0] = 0; v[1] = 5;
	X2.push_back(v);

	double d = ApproxError(box, X2);
	if ((d - 3.5355) < 0.0001)
		d = 0;
	CHECK_EQUAL(d, 0);

}


}
