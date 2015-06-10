/*
 * Unit_Testing_Post_Assignment.cpp
 *
 *  Created on: 25-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include <vector>
#include "Utilities/StandardVector.h"
#include "math/matrix.h"
#include "MySrc/Polytope/Polytope.h"
#include "Utilities/Post_Assignment.h"

using namespace std;

SUITE(PostAssignment_TestSuite) {
struct ExamplePostAssignment {
	ExamplePostAssignment() {

	}
	~ExamplePostAssignment() { /* some teardown */
	}
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	math::matrix<double> ConstraintsMatrixI;
	std::vector<double> boundValueI;
	int boundSignI;

	std::vector<double> direction;
	stringstream out, proper;
};

TEST_FIXTURE(ExamplePostAssignment, post_assign_exact_Test) {

	math::matrix<double> R;	//Transition Dynamics
	row = 2;
	col = 2;
	R.resize(row, col);
	/*R(0, 0) = -0.6;
	R(0, 1) = 0;
	R(1, 0) = 0;
	R(1, 1) = 1;
*/
	R(0, 0) = 1;
	R(0, 1) = 0;
	R(1, 0) = 0;
	R(1, 1) = -0.6;

	std::vector<double> w(2);
	w[0] = 0;
	w[1] = 0;

	polytope newPolytope, newShiftedPolytope;
	size_type row = 4;
	size_type col = 2;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;

	boundValueI.resize(4);
	boundValueI[0] = 4;
	boundValueI[1] = -4;
	boundValueI[2] = -5;
	boundValueI[3] = 5;

	boundSignI = 1;
	newPolytope.setCoeffMatrix(ConstraintsMatrixI);
	newPolytope.setColumnVector(boundValueI);
	newPolytope.setInEqualitySign(boundSignI);
	//newShiftedPolytope = post_assign_exact(newPolytope, R, w);

	cout << "\nAmit here is A_dash Of newPolytope \n";
	for (int i = 0; i < newShiftedPolytope.getCoeffMatrix().size1(); i++) {
		for (int j = 0; j < newShiftedPolytope.getCoeffMatrix().size2(); j++)
			cout << newShiftedPolytope.getCoeffMatrix()(i, j) << "\t";
		cout << endl;
	}
	cout << "\nAmit here is bp of newShiftedPolytope \n";
	for (int j = 0; j < newShiftedPolytope.getColumnVector().size(); j++)
		cout << newShiftedPolytope.getColumnVector()[j] << "\t";
	cout << endl;

	/*out<<"amit";
	 proper << "true";
	 CHECK_EQUAL(proper.str(), out.str());*/
}

TEST_FIXTURE(ExamplePostAssignment, Vector_Add_Test) {

}

}
