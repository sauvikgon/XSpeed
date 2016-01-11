/*
 * test_polytope.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
//#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"

#include "Utilities/StandardVector.h"

using namespace std;

SUITE(sf_utility_TestSuite) {
	struct ExamplePolytope {
		ExamplePolytope() {
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

			direction.resize(2);
			direction[0] = 0;
			direction[1] = 1;

			I = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

			P2 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

		}
		~ExamplePolytope() { /* some teardown */
		}
		polytope::ptr I, P2;
		typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
		size_type row, col;
		int boundSignI, boundSignP, boundSignV;
		std::vector<double> boundValueI, boundValueP, boundValueV;
		math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixP,
		ConstraintsMatrixV;
		std::vector<double> direction;
		double val;
		stringstream out, proper;
	};
	TEST_FIXTURE(ExamplePolytope, polytope_max_norm_Test) {
		double res;

		res = I->max_norm(1, I->getSystemDimension()); //temp solu
		out << res;
//	std::cout << res;
		proper << "7";
		CHECK_EQUAL(proper.str(), out.str());

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
		boundValueV[0] = -10;
		boundValueV[1] = 10;
		boundValueV[2] = 0;//9.8;
		boundValueV[3] = 0;//-9.8;

		boundSignV = 1;

		G = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

		val = G->max_norm(1, G->getSystemDimension());//temp solu

		//cout << "Out = " << val << endl;
		out << val;
		proper << "10";
		CHECK_EQUAL(proper.str(), out.str());

		polytope::ptr k;
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
		boundValueV[0] = 2;
		boundValueV[1] = 2;
		boundValueV[2] = 2;
		boundValueV[3] = -6;

		k = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

		val = k->max_norm(1, k->getSystemDimension());//temp solu
//	cout << endl << "Raj Gurung Over" << val << endl;
		out<< "";
		out << val;
		proper << "";
		proper << "2";
		CHECK_EQUAL(proper.str(), out.str());

	}
	TEST_FIXTURE(ExamplePolytope, polytope_Compute_SF_Test) {
		double sf;

		lp_solver lp(1);
		lp.setMin_Or_Max(2);
		lp.setConstraints(I->getCoeffMatrix(), I->getColumnVector(), I->getInEqualitySign());

		sf = I->computeSupportFunction(direction, lp);
		//std::cout << sf;
		out<< "";
		out << sf;
		proper << "";
		proper << "7";
		CHECK_EQUAL(proper.str(), out.str());

		direction[0] = 1;
		direction[1] = 0;
		sf = I->computeSupportFunction(direction, lp);
		//std::cout << sf;
		out<< "";
		out << sf;
		proper << "";
		proper << "3";
		CHECK_EQUAL(proper.str(), out.str());

		polytope::ptr k;
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
		boundValueV[0] = 2;
		boundValueV[1] = 2;
		boundValueV[2] = 6;
		boundValueV[3] = -2;

		boundSignV = 1;

		stringstream out1, proper1;
	//	cout<<"\n\n\nHello Amit my output from here \n\n\n";
		k = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
		lp_solver lp2(1);
		lp2.setMin_Or_Max(2);
		lp2.setConstraints(k->getCoeffMatrix(), k->getColumnVector(), k->getInEqualitySign());

		direction[0] = 1;
		direction[1] = 0;

		sf = k->computeSupportFunction(direction, lp2);
	//	std::cout << sf<<endl;
		out1 << sf;
		proper1 << "2";
		CHECK_EQUAL(proper1.str(), out1.str());

		direction[0] = -1;
		direction[1] = 0;
		stringstream out2, proper2;
		sf = k->computeSupportFunction(direction, lp2);
	//	std::cout << sf;
		out2 << sf;
		proper2 << "2";
		CHECK_EQUAL(proper2.str(), out2.str());

		direction[0] = 0;
		direction[1] = -1;
		sf = k->computeSupportFunction(direction, lp2);
		stringstream out3, proper3;

//		std::cout << sf;
		out3 << sf;
		proper3 << "-2";
		CHECK_EQUAL(proper3.str(), out3.str());

		direction[0] = 0;
		direction[1] = -1;

		sf = k->computeSupportFunction(direction, lp2);
//		std::cout << sf;
		stringstream out4, proper4;
		out4 << sf;
		proper4 << "-2";
		CHECK_EQUAL(proper4.str(), out4.str());

		polytope::ptr quad3;
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
		boundValueV[0] = 3;
		boundValueV[1] = -2;
		boundValueV[2] = -2;
		boundValueV[3] = 4;

		boundSignV = 1;

		quad3 = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
		stringstream out5, proper5;

		lp_solver lp3(1);
		lp3.setMin_Or_Max(2);
		lp3.setConstraints(quad3->getCoeffMatrix(), quad3->getColumnVector(), quad3->getInEqualitySign());

		direction[0] = 0;
		direction[1] = -1;
		sf = quad3->computeSupportFunction(direction, lp3);
	//	std::cout << sf;
		out5 << sf;
		proper5 << "4";
		CHECK_EQUAL(proper5.str(), out5.str());
	}
	TEST_FIXTURE(ExamplePolytope, polytope_intersection_Test) {

		bool flag;
		flag = I->check_polytope_intersection(P2, 1);
		//cout << "Same polytope so Intersecting = "<<flag;
		out << flag;
		proper << "1";
		CHECK_EQUAL(proper.str(), out.str());
	}

	TEST_FIXTURE(ExamplePolytope, NOTintersectingPolytopes_Test) {

		bool flag;

		row = 4;
		col = 2;
		ConstraintsMatrixP.resize(row, col);
		ConstraintsMatrixP(0, 0) = -1;
		ConstraintsMatrixP(0, 1) = 0;
		ConstraintsMatrixP(1, 0) = 1;
		ConstraintsMatrixP(1, 1) = 0;
		ConstraintsMatrixP(2, 0) = 0;
		ConstraintsMatrixP(2, 1) = 1;
		ConstraintsMatrixP(3, 0) = 0;
		ConstraintsMatrixP(3, 1) = -1;

		boundValueP.resize(4);

		boundValueP[0] = -10;
		boundValueP[1] = 12;
		boundValueP[2] = 18;
		boundValueP[3] = -15;

		boundSignP = 1;

		P2 = polytope::ptr(new polytope(ConstraintsMatrixP, boundValueP, boundSignP));
		flag = I->check_polytope_intersection(P2,1);
	//	cout << "Result should be false ie Not intersection = " <<flag<< endl;
		out << flag;
		proper << "0";
		CHECK_EQUAL(proper.str(), out.str());
	}
}
