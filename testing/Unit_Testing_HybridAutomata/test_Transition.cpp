/*
 * test_Transition.cpp
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#include <string>
#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "application/DataStructureDirections.h"
#include "core_system/HybridAutomata/Transition.h"
#include "core_system/HybridAutomata/Location.h"
#include "core_system/math/matrix.h"

using namespace std;
using namespace math;

SUITE(Transition_TestSuite) {
	struct ClassTransition {
		ClassTransition() {

		}
		~ClassTransition() { /* some teardown */
		}
		string nn;
		typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
		Dynamics D, outD;
		polytope::ptr u, Gaurd, GaurdOut, Inv, outInv;
		math::matrix<double> ConstraintsMatrixI;
		int boundSignI;
		std::vector<double> boundValueI;
		std::list<transition::ptr> t;
		stringstream out, proper;
	};

	TEST_FIXTURE(ClassTransition , constructor1_transitions_Test) {

		transition tt;
	//	cout << "Just testing an Empty Label of the Transition = " << tt.getLabel() << "\t" << endl;
		out << tt.getLabel();
		proper << "";
		CHECK_EQUAL(proper.str(), out.str());
	}

	TEST_FIXTURE(ClassTransition , constructor2_transitions_Test) {

		nn = "Welcome";
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

		u = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));
		D.U = u;
		Inv = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

		int srcLocID=1,destLocID=2;

		location loc_src(srcLocID, nn, D, Inv, true, t), loc_dest(destLocID, "Good Bye", D, Inv, true, t), loc_src_out, loc_dest_out;
		Gaurd = polytope::ptr(new polytope(ConstraintsMatrixI,boundValueI,boundSignI));

		string name = "Test Transition";
		math::matrix<double> m(2, 2);
		m(0, 0) = 7;
		m(0, 1) = 7;
		m(1, 0) = 7;
		m(1, 1) = 7;
		std::vector<double> b(2, 99.0), b2(2, 99.0);//assigning with 99 as all values
		Assign T, Tout;
		T.Map = m;
		T.b = b;

		transition trans(10, name, srcLocID, destLocID, Gaurd, T);//creating object of location as loc
		/*std::cout << "Printing Output from Transition Test Suite" << std::endl;
		std::cout << "**********************************************" << std::endl;
		std::cout << "Label = " << trans.getLabel() << std::endl;*/

		out << trans.getLabel();
		proper << "Test Transition";
		CHECK_EQUAL(proper.str(), out.str());

		Tout = trans.getAssignT();
		/*std::cout << "Printing Assign_T::Matrix Map = ";
		for (unsigned int i = 0; i < Tout.Map.size1(); i++) {
			for (unsigned int j = 0; j < Tout.Map.size2(); j++)
				std::cout << Tout.Map(i, j) << "\t";
			std::cout << std::endl;
		}*/
//		std::cout << "Printing Assign_T::matrix Map = " << Tout.Map << std::endl;
		out << "";
		out << Tout.Map;
		proper <<"[2,2]((7,7),(7,7))";

		CHECK_EQUAL(proper.str(), out.str());

/*		cout << "Printing Assign_T::Vector b =   ";
		for (unsigned int i = 0; i < Tout.b.size(); i++)
			std::cout << Tout.b[i] << "\t";
		cout << endl;*/

		CHECK_ARRAY_EQUAL(b2, Tout.b, b2.size());


		GaurdOut = trans.getGaurd();
		int loc_src_id = trans.getSource_Location_Id();
		int loc_dst_id = trans.getDestination_Location_Id();

		out << loc_src_id;
		proper << "1";
		CHECK_EQUAL(proper.str(), out.str());

		out << loc_dst_id;
		proper << "2";
		CHECK_EQUAL(proper.str(), out.str());

		Dynamics outD, outDDest;
	//	std::cout << "Name From Source Location= " << loc_src_out.getName() << std::endl;
		outD = loc_src_out.getSystem_Dynamics();
	/*	std::cout << "Dynamic matrixA From Source Location : " << std::endl;
		for (unsigned int i = 0; i < outD.MatrixA.size1(); i++) {
			for (unsigned int j = 0; j < outD.MatrixA.size2(); j++)
				std::cout << outD.MatrixA(i,j) << "\t";
			std::cout << std::endl;
		}*/
		out<<"";
		out << outD.MatrixA;
		proper <<"[0,0]()";
		CHECK_EQUAL(proper.str(), out.str());

/*
		std::cout << endl << "**********************************************" << std::endl;
		std::cout << "Name From Destination Location= " << loc_dest_out.getName() << std::endl;
*/
		outDDest = loc_dest_out.getSystem_Dynamics();
/*		cout << "Dynamic matrixA From Destination Location : " << std::endl;
		for (unsigned int i = 0; i < outDDest.MatrixA.size1(); i++) {
			for (unsigned int j = 0; j < outDDest.MatrixA.size2(); j++)
				std::cout << outDDest.MatrixA(i,j) << "\t";
			std::cout << std::endl;
		}
		std::cout << outDDest.MatrixA << std::endl;
*/		out<<"";
		out << outD.MatrixA;
		proper <<"[0,0]()";
		CHECK_EQUAL(proper.str(), out.str());

		/*
		 out << sf2;
		 proper << "3";
		 CHECK_EQUAL(proper.str(), out.str());
		 */

	}

}

