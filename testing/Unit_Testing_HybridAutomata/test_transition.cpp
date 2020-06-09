/*
 * test_Transition.cpp
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#include <string>
#include <sstream>
#include <iostream>

#include "../../core/HybridAutomata/Location.h"
#include "../../core/HybridAutomata/Transition.h"
#include "../../core/math/matrix.h"
#include "UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "application/DataStructureDirections.h"

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
		polytope::ptr u, Guard, GuardOut, Inv, outInv;
		math::matrix<double> ConstraintsMatrixI;
		int boundSignI;
		std::vector<double> boundValueI;
		std::list<transition::ptr> t;
		stringstream out, proper;
	};

	TEST_FIXTURE(ClassTransition , constructor1_transitions_Test) {

		transition tt;
	    //cout << "Just testing an Empty Label of the Transition = " << tt.getLabel() << "\t" << endl;
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
		Guard = polytope::ptr(new polytope(ConstraintsMatrixI,boundValueI,boundSignI));

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

		transition trans(10, name, srcLocID, destLocID, Guard, T);//creating object of location as loc

		out << trans.getLabel();
		proper << "Test Transition";
		CHECK_EQUAL(proper.str(), out.str());

		Tout = trans.getAssignT();
		float output2D[2][2];

		for (unsigned int i = 0; i < Tout.Map.size1(); i++) {
			for (unsigned int j = 0; j < Tout.Map.size2(); j++)
				output2D[i][j]=Tout.Map(i, j);
		}

		const float res1[2][2]={{7,7},{7,7}};

		CHECK_ARRAY2D_CLOSE(res1, output2D, 2, 2, 0.0);

		CHECK_ARRAY_EQUAL(b2, Tout.b, b2.size());


		GuardOut = trans.getGuard();
		int loc_src_id = trans.getSource_Location_Id();
		int loc_dst_id = trans.getDestination_Location_Id();

		unsigned int res = loc_src_id;
		unsigned int proper1 = 1;
		CHECK_EQUAL(proper1, res);

		unsigned int dis=loc_dst_id;
		unsigned int proper2 = 2;
		CHECK_EQUAL(proper2, dis);

		Dynamics outD, outDDest;
		outD = loc_src_out.getSystem_Dynamics();

		row = outD.MatrixA.size1();
		col = outD.MatrixA.size2();

		for (unsigned int i = 0; i < row; i++)
			for (unsigned int j = 0; j < col; j++)
					output2D[i][j] = outD.MatrixA(i,j);

		CHECK((row==0) && (col==0));

		outDDest = loc_dest_out.getSystem_Dynamics();
		row = outDDest.MatrixA.size1();
		col = outDDest.MatrixA.size2();

		CHECK((row==0) && (col==0));

	}

}
