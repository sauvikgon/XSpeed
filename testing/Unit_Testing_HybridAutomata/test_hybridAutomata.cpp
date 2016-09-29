/*
 * test_HybridAutomata.cpp
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#include <string>
#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include <list>
#include <iterator>

#include "application/DataStructureDirections.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/HybridAutomata/Location.h"
#include "core_system/HybridAutomata/Transition.h"
#include "core_system/math/matrix.h"

using namespace std;
using namespace math;

SUITE(HybridAutomata_TestSuite) {
	struct ClassHybridAutomata {
		ClassHybridAutomata() {
			nn = "Hello Welcome";

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
			std::list<transition> Out_Going_Trans;

			u = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));
			D.U = u;

			Inv = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

		}
		~ClassHybridAutomata() { /* some teardown */
		}
		string nn;
		typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
		Dynamics D, outD;
		polytope::ptr Gaurd, GaurdOut, Inv, outInv;
		math::matrix<double> ConstraintsMatrixI;
		int boundSignI;
		std::vector<double> boundValueI;

		stringstream out, proper;
	};

	TEST_FIXTURE(ClassHybridAutomata , constructor1_HybridAutomata_Test) {

		hybrid_automata ha;
		//	cout << "Just testing the Empty Hybrid Automata's Dimension = "<< ha.getDimension() << "\t" << endl;
		out<<ha.getDimension();
		proper<<"0";
		CHECK_EQUAL(proper.str(), out.str());

	}
	TEST_FIXTURE(ClassHybridAutomata , constructor2_HybridAutomata_Test) {

		std::list<transition::ptr> all_trans;
		Gaurd = polytope::ptr(new polytope(ConstraintsMatrixI,boundValueI,boundSignI));

		int dimen = 2;

		string label1 = "Transition1";
		string label2 = "Transition2";

		math::matrix<double> m(2, 2);
		m(0, 0) = 7;
		m(0, 1) = 7;
		m(1, 0) = 7;
		m(1, 1) = 7;
		std::vector<double> b(2, 99.0); //assigning with 99 as all values
		Assign T, Tout;
		T.Map = m;
		T.b = b;

		int srcLocID=1, destLocID=2;

		transition::ptr trans1 = transition::ptr(new transition(1, label1, srcLocID, destLocID, Gaurd, T));//creating object of location as loc
		transition::ptr trans2 = transition::ptr(new transition(2, label2, srcLocID, destLocID, Gaurd, T));//creating object of location as loc
		all_trans.push_back(trans1);
		all_trans.push_back(trans2);

		location::ptr loc = location::ptr(new location(11, nn, D, Inv, true, all_trans));
		location::ptr loc_src = location::ptr(new location(12, "WelCome", D, Inv, true, all_trans));
		location::ptr loc_dest = location::ptr(new location(13, "GoodBye", D, Inv, true, all_trans));
		location::ptr outLoc;

		hybrid_automata ha;

		ha.addInitial_Location(loc);
		ha.addLocation(loc);
		ha.addLocation(loc_src);
		ha.addLocation(loc_dest);
		ha.setDimension(dimen);

		//	cout << "Dimension from Object H A = " << ha.getDimension() << endl;
		out << ha.getDimension();
		proper<< "2";
		CHECK_EQUAL(proper.str(), out.str());

		outLoc = ha.getLocation(11);
		out << outLoc->getName();
		proper << "Hello Welcome";
		CHECK_EQUAL(proper.str(), out.str());

		outLoc = ha.getLocation(13);
		out << outLoc->getName();
		proper << "GoodBye";
		CHECK_EQUAL(proper.str(), out.str());

	}

}

