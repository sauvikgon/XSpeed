/*
 * test_polytope.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"

#include "application/DataStructureDirections.h"
#include "core_system/HybridAutomata/Location.h"

using namespace std;

SUITE(Location_TestSuite) {
struct ClassLocation {
	ClassLocation() {
		nn = "Hello testing";

		size_type row = 2;
		size_type col = 2;
		D.MatrixA.resize(row, col);
		D.MatrixA(0, 0) = 1;
		D.MatrixA(0, 1) = 2;
		D.MatrixA(1, 0) = 3;
		D.MatrixA(1, 1) = 4;

		D.MatrixB.resize(row, col);
		D.MatrixB(0, 0) = 5;
		D.MatrixB(0, 1) = 6;
		D.MatrixB(1, 0) = 7;
		D.MatrixB(1, 1) = 8;

		row = 6;
		col = 2;
		ConstraintsMatrixI.resize(row, col);
		ConstraintsMatrixI(0, 0) = -1;
		ConstraintsMatrixI(0, 1) = 0;
		ConstraintsMatrixI(1, 0) = 0;
		ConstraintsMatrixI(1, 1) = 1;
		ConstraintsMatrixI(2, 0) = 1;
		ConstraintsMatrixI(2, 1) = 1;
		ConstraintsMatrixI(3, 0) = 1;
		ConstraintsMatrixI(3, 1) = 0;
		ConstraintsMatrixI(4, 0) = 0;
		ConstraintsMatrixI(4, 1) = -1;
		ConstraintsMatrixI(5, 0) = -1;
		ConstraintsMatrixI(5, 1) = -1;

		boundValueI.resize(6);

		boundValueI[0] = -1;
		boundValueI[1] = 7;
		boundValueI[2] = 9;
		boundValueI[3] = 3;
		boundValueI[4] = -5;
		boundValueI[5] = -7;

		boundSignI = 1;

		D.U->setCoeffMatrix(ConstraintsMatrixI);
		D.U->setColumnVector(boundValueI);
		D.U->setInEqualitySign(boundSignI);

		Inv.setCoeffMatrix(ConstraintsMatrixI);
		Inv.setColumnVector(boundValueI);
		Inv.setInEqualitySign(boundSignI);
	}
	~ClassLocation() { /* some teardown */
	}
	string nn;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	Dynamics D, outD;
	polytope Inv, outInv;
	math::matrix<double> ConstraintsMatrixI;
	int boundSignI;
	std::vector<double> boundValueI;

	stringstream out, proper;
};
TEST_FIXTURE(ClassLocation, constructor1_location_Test) {

	location ll;
	cout << "Just testing and Empty Name = " << ll.getName() << "\t" << endl;
	//proper << "7";
	//CHECK_EQUAL(proper.str(), out.str());
}
TEST_FIXTURE(ClassLocation, constructor2_location_Test) {
//location(string Name, Dynamics System_Dynamics, polytope Invariant);
	cout << "\n\n\nRuning From Module Hybrid Automata" << endl;
	cout << "*********************************************" << endl;

	location loc(nn, D, Inv);	//creating object of location as loc

	cout << "Name = " << loc.getName() << endl;
	outD = loc.getSystem_Dynamics();
	cout << "Dynamic matrixA :" << endl;
	for (unsigned int i = 0; i < outD.MatrixA.size1(); i++) {
		for (unsigned int j = 0; j < outD.MatrixA.size2(); j++)
			cout << outD.MatrixA(i,j) << "\t";
		cout << endl;
	}
	std::vector<double> direction(2, 0.0);
	direction[0] = 1;
	direction[1] = 0;

	double sf1 = outD.U.computeSupportFunction(direction, 2);
	cout << "Support Function = " << sf1 << endl;

	outInv = loc.getInvariant();

	double sf2 = outInv.computeSupportFunction(direction, 2);

	cout << "This should also return the same Support Function Result =" << sf2
			<< endl;
	out << sf2;
	proper << "3";
	CHECK_EQUAL(proper.str(), out.str());
}

}

