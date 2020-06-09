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
#include "../../core/math/nlp_solver/nlp_solver.h"
#include "../../utilities/dbg_msg_logger.h"


using namespace std;

SUITE(NLPSoverTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};

TEST_FIXTURE(Example, NLPSoverTest) {

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
/*
	ConstraintsMatrixV(0, 0) = 0;
	ConstraintsMatrixV(0, 1) = 1;
	ConstraintsMatrixV(1, 0) = 0;
	ConstraintsMatrixV(1, 1) = -1;
	ConstraintsMatrixV(2, 0) = 1;
	ConstraintsMatrixV(2, 1) = 0;
	ConstraintsMatrixV(3, 0) = -1;
	ConstraintsMatrixV(3, 1) = 0;
*/
	ConstraintsMatrixV(0, 0) = 1;
	ConstraintsMatrixV(0, 1) = 0;
	ConstraintsMatrixV(1, 0) = -1;
	ConstraintsMatrixV(1, 1) = 0;
	ConstraintsMatrixV(2, 0) = 0;
	ConstraintsMatrixV(2, 1) = 1;
	ConstraintsMatrixV(3, 0) = 0;
	ConstraintsMatrixV(3, 1) = -1;

	boundValueV.resize(4);
	boundValueV[0] = 15;
	boundValueV[1] = -5;
	boundValueV[2] = 15;//9.8;
	boundValueV[3] = -5;//-9.8;

	boundSignV = 1;

	G = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	std::vector<double> objfunc(col);
	objfunc[0] = 1;
    objfunc[1] = 0;

	double d = computeNLP(G, objfunc);
	DEBUG_MSG("Support function of a polytope computed from NLP: " << d << std::endl) ;

	CHECK_EQUAL(d,15);

}

}
