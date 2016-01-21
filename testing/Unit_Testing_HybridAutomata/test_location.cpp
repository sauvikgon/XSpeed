/*
 * test_polytope.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>

#include <list>
#include "UnitTest++/UnitTest++.h"
#include "application/DataStructureDirections.h"
#include "core_system/HybridAutomata/Location.h"

#include "core_system/HybridAutomata/Transition.h"

#include "core_system/math/lp_solver/lp_solver.h"

using namespace std;

SUITE(Location_TestSuite) {
	struct ClassLocation {
		ClassLocation() {

		}
		~ClassLocation() { /* some teardown */
		}
		std::string nn;
		typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
		Dynamics D, outD;
		polytope::ptr Inv, outInv;
		math::matrix<double> ConstraintsMatrixI;
		int boundSignI;
		std::vector<double> boundValueI;

		stringstream out, proper;
	};

	TEST_FIXTURE(ClassLocation, constructor1_location_Test) {

		location ll;
		//	cout << "Just testing and Empty Name = " << ll.getName() << "\t" << endl;
		out <<ll.getName();
		proper << "";
		CHECK_EQUAL(proper.str(), out.str());
	}

	TEST_FIXTURE(ClassLocation, constructor2_location_Test) {
//location(string Name, Dynamics System_Dynamics, polytope Invariant);
		/*	cout << "\n\n\nRuning From Module Hybrid Automata" << endl;
		 cout << "*********************************************" << endl;*/
		nn = "Hello Testing";

		size_type row = 2;
		size_type col = 2;

		D.isEmptyMatrixA = false;

		D.MatrixA.resize(row, col);
		D.MatrixA(0, 0) = 1;
		D.MatrixA(0, 1) = 2;
		D.MatrixA(1, 0) = 3;
		D.MatrixA(1, 1) = 4;

		D.isEmptyMatrixB = false;

		D.MatrixB.resize(row, col);
		D.MatrixB(0, 0) = 5;
		D.MatrixB(0, 1) = 6;
		D.MatrixB(1, 0) = 7;
		D.MatrixB(1, 1) = 8;

		D.isEmptyC = true;

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

		polytope::ptr u;
		std::list<transition::ptr> Out_Going_Trans;


		u = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));
		D.U = u;

		Inv = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

		location loc(1, nn, D, Inv, true, Out_Going_Trans); //creating object of location as loc
		//cout << "Name = " << loc.getName() << endl;
		out << "";
		out << loc.getName();
		proper << "Hello Testing";
		CHECK_EQUAL(proper.str(), out.str());

		outD = loc.getSystem_Dynamics();

		//	std::cout<< "\nMatrix A : "<< outD.MatrixA;
		out << "";
		out << outD.MatrixA;
		proper <<"[2,2]((1,2),(3,4))";

		CHECK_EQUAL(proper.str(), out.str());

		//	std::cout<< "\nMatrix B : "<< outD.MatrixB;

		out << outD.MatrixB;
		proper << "[2,2]((5,6),(7,8))";
		CHECK_EQUAL(proper.str(), out.str());

		std::vector<double> direction(2, 0.0);
		direction[0] = 1;
		direction[1] = 0;

		lp_solver lp(1);
		lp.setMin_Or_Max(2);
		lp.setConstraints(outD.U->getCoeffMatrix(), outD.U->getColumnVector(), outD.U->getInEqualitySign());
		double sf1 = outD.U->computeSupportFunction(direction, lp);
		//	cout << "Support Function = " << sf1 << endl;
		out << "";
		out << sf1;
		proper << "";
		proper << "3";
		CHECK_EQUAL(proper.str(), out.str());

		outInv = loc.getInvariant();

		lp_solver lp2(1);
		lp2.setMin_Or_Max(2);
		lp2.setConstraints(outInv->getCoeffMatrix(), outInv->getColumnVector(), outInv->getInEqualitySign());

		double sf2 = outInv->computeSupportFunction(direction, lp2);

		//	 cout << "This should also return the same Support Function Result =" << sf2 << endl;
		out << "";
		out << sf2;
		proper << "";
		proper << "3";
		CHECK_EQUAL(proper.str(), out.str());
	}
}

