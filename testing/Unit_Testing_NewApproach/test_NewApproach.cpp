/*
 * Test_NewApproach.cpp
 *
 *  Created on: 03-March-2015
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "core_system/math/matrix.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "application/sf_directions.h"
#include "core_system/Reachability/NewApproach/Partition_BoundingPolytope.h"

#include <vector>
#include <string>

using namespace std;

SUITE(NewApproach_TestSuite) {

struct NewApproach {
	NewApproach() {
		row = 4;
		col = 2;
		ConstraintsMatrixI.resize(row, col);
		ConstraintsMatrixI(0, 0) = -1;
		ConstraintsMatrixI(0, 1) = -1;
		ConstraintsMatrixI(1, 0) = 1;
		ConstraintsMatrixI(1, 1) = 1;
		ConstraintsMatrixI(2, 0) = 1;
		ConstraintsMatrixI(2, 1) = -1;
		ConstraintsMatrixI(3, 0) = -1;
		ConstraintsMatrixI(3, 1) = 1;

		boundValueI.resize(row);
		boundValueI[0] = -5;
		boundValueI[1] = 13;
		boundValueI[2] = 5;
		boundValueI[3] = 5;

		/*ConstraintsMatrixI.resize(row, col);
		 ConstraintsMatrixI(0, 0) = -1;
		 ConstraintsMatrixI(0, 1) = 0;
		 ConstraintsMatrixI(1, 0) = 1;
		 ConstraintsMatrixI(1, 1) = 0;
		 ConstraintsMatrixI(2, 0) = 0;
		 ConstraintsMatrixI(2, 1) = -1;
		 ConstraintsMatrixI(3, 0) = 0;
		 ConstraintsMatrixI(3, 1) = 1;

		 boundValueI.resize(row);
		 boundValueI[0] = 3;
		 boundValueI[1] = 4;
		 boundValueI[2] = -5;
		 boundValueI[3] = 6;*/
		boundSignI = 1;

		p = polytope::ptr(
				new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	}
	~NewApproach() { /* some teardown */
	}
	math::matrix<double> ConstraintsMatrixI;
	std::vector<double> boundValueI;
	int boundSignI;
	polytope::ptr p;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
};

TEST_FIXTURE(NewApproach, Partition_BoundingPolytope_Test) {
	/*
	 std::list<polytope::ptr> polys;

	 unsigned int N = 2;	//number of variables to be partitioned
	 unsigned int part = 2;	//number of partition size
	 polys = Partition_BoundingPolytope(p, N, part);

	 for (std::list<polytope::ptr>::iterator i = polys.begin(); i != polys.end();
	 i++) {
	 cout << "\nCoeff1 = " << (*i)->getCoeffMatrix() << endl;
	 cout << "\nBoundvalue1 = " << endl;
	 for (unsigned int j = 0; j < (*i)->getColumnVector().size(); j++) {
	 cout << (*i)->getColumnVector()[j] << endl;
	 }
	 }
	 */
}

}
