/*
 * test_polytope.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"

#include "Utilities/StandardVector.h"
#include "fstream"

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

		val = k->max_norm(1, k->getSystemDimension());
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
		out<< "";
		out << sf;
		proper << "";
		proper << "7";
		CHECK_EQUAL(proper.str(), out.str());

		direction[0] = 1;
		direction[1] = 0;
		sf = I->computeSupportFunction(direction, lp);
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

	TEST_FIXTURE(ExamplePolytope, pointDistaceTest) {

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

		std::vector<double> v(2,0);
		v[0] = 11; v[1] = 16;

		double distance = P2->point_distance(v);
//		std::cout << "distance of point to polytope:" << distance << std::endl;
		out << distance;
		proper << "0";

		v[0] = 13;
		v[1] = 16;
		distance = P2->point_distance(v);
//		std::cout << "distance of point to polytope:" << distance << std::endl;
		out << ""; proper << "";

		out << distance;
		proper << "1";
		CHECK_EQUAL(proper.str(), out.str());

		// check monotonocity of distance from polytope
		std::ofstream myfile;
		myfile.open("./monotoneDistance");
		for(unsigned int i=0;i<50;i++)
		{
			v[0] = i;
			myfile << v[0] << "  " << P2->point_distance(v) << std::endl;
		}
		myfile.close();

		// tester to check point to polytope distance, when polytope is a line
		// P{ x=10 & 15 <= y <=18
		boundValueP[0] = -10;
		boundValueP[1] = 10;
		boundValueP[2] = 18;
		boundValueP[3] = -15;

		P2 = polytope::ptr(new polytope(ConstraintsMatrixP, boundValueP, boundSignP));

		v[0] = 10;
		v[1] = 16;
		distance = P2->point_distance(v);
//		std::cout << "The distance of the point from the line =  " << distance << std::endl;
		out << "";proper << "";

		out << distance;
		proper << "0";
		CHECK_EQUAL(proper.str(), out.str());

		v[0] = 10;
		v[1] = 16;
		distance = P2->point_distance(v);
//		std::cout << "The distance of the point from the line =  " << distance << std::endl;
		out << "";proper << "";

		out << distance;
		proper << "0";
		CHECK_EQUAL(proper.str(), out.str());

		v[0] = 11;
		v[1] = 16;
		distance = P2->point_distance(v);
//		std::cout << "The distance of the point from the line =  " << distance << std::endl;
		out << ""; proper << "";

		out << distance;
		proper << "1";
		CHECK_EQUAL(proper.str(), out.str());

		row = 6;
		col = 3;
		ConstraintsMatrixP.resize(row, col);
		ConstraintsMatrixP(0, 0) = -1;
		ConstraintsMatrixP(0, 1) = 0;
		ConstraintsMatrixP(0, 2) = 0;
		ConstraintsMatrixP(1, 0) = 1;
		ConstraintsMatrixP(1, 1) = 0;
		ConstraintsMatrixP(1, 2) = 0;
		ConstraintsMatrixP(2, 0) = 0;
		ConstraintsMatrixP(2, 1) = 1;
		ConstraintsMatrixP(2, 2) = 0;
		ConstraintsMatrixP(3, 0) = 0;
		ConstraintsMatrixP(3, 1) = -1;
		ConstraintsMatrixP(3, 2) = 0;
		ConstraintsMatrixP(4, 0) = 0;
		ConstraintsMatrixP(4, 1) = 0;
		ConstraintsMatrixP(4, 2) = -1;
		ConstraintsMatrixP(5, 0) = 0;
		ConstraintsMatrixP(5, 1) = 0;
		ConstraintsMatrixP(5, 2) = 1;

		boundValueP.resize(6);

		boundValueP[0] = -10;
		boundValueP[1] = 10;
		boundValueP[2] = 18;
		boundValueP[3] = -15;
		boundValueP[4] = -5;
		boundValueP[5] = 100;

		boundSignP = 1;

		P2 = polytope::ptr(new polytope(ConstraintsMatrixP, boundValueP, boundSignP));

		v.resize(3);
		v[0] = 10;
		v[1] = 16;
		v[2] = 50;
		distance = P2->point_distance(v);

//		std::cout << "The distance of the point from the line =  " << distance << std::endl;

		out << ""; proper << "";

		out << distance;
		proper << "0";
		CHECK_EQUAL(proper.str(), out.str());


		// test case to test the distance function when the polytope is a line.

		// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

		row = 8;
		col = 4;

		math::matrix<double> guardConstraintsMatrix;
		guardConstraintsMatrix.resize(row, col);
		guardConstraintsMatrix(0, 0) = -1.0;
		guardConstraintsMatrix(0, 1) = 0.0;
		guardConstraintsMatrix(0, 2) = 0.0;
		guardConstraintsMatrix(0, 3) = 0.0;
		guardConstraintsMatrix(1, 0) = 1.0;
		guardConstraintsMatrix(1, 1) = 0.0;
		guardConstraintsMatrix(1, 2) = 0.0;
		guardConstraintsMatrix(1, 3) = 0.0;
		guardConstraintsMatrix(2, 0) = 0.0;
		guardConstraintsMatrix(2, 1) = -1.0;
		guardConstraintsMatrix(2, 2) = 0.0;
		guardConstraintsMatrix(2, 3) = 0.0;
		guardConstraintsMatrix(3, 0) = 0.0;
		guardConstraintsMatrix(3, 1) = 1.0;
		guardConstraintsMatrix(3, 2) = 0.0;
		guardConstraintsMatrix(3, 3) = 0.0;
		guardConstraintsMatrix(4, 0) = 0.0;
		guardConstraintsMatrix(4, 1) = 0.0;
		guardConstraintsMatrix(4, 2) = -1.0;
		guardConstraintsMatrix(4, 3) = 0.0;
		guardConstraintsMatrix(5, 0) = 0.0;
		guardConstraintsMatrix(5, 1) = 0.0;
		guardConstraintsMatrix(5, 2) = 1.0;
		guardConstraintsMatrix(5, 3) = 0.0;
		guardConstraintsMatrix(6, 0) = 0.0;
		guardConstraintsMatrix(6, 1) = 0.0;
		guardConstraintsMatrix(6, 2) = 0.0;
		guardConstraintsMatrix(6, 3) = -1.0;
		guardConstraintsMatrix(7, 0) = 0.0;
		guardConstraintsMatrix(7, 1) = 0.0;
		guardConstraintsMatrix(7, 2) = 0.0;
		guardConstraintsMatrix(7, 3) = 1.0;

		std::vector<double> bound;
		bound.resize(row);
		bound[0] = -1.0;
		bound[1] = 1.0;
		bound[2] = -1.0;
		bound[3] = 2.0;
		bound[4] = 1000.0;
		bound[5] = 1000.0;
		bound[6] = 1000.0;
		bound[7] = 1000.0;
		polytope::ptr linePolytope = polytope::ptr(
				new polytope(guardConstraintsMatrix, bound,
						boundSignP));

		v.resize(col);
		v[0]=1;
		v[1]=1.5;
		v[2]=0;
		v[3]=0;

		distance = linePolytope->point_distance(v);
		// std::cout << "distance of a point on the line, from the line = " << distance <<  std::endl;

		out << ""; proper << "";
		out << distance;
		proper << "0";
		CHECK_EQUAL(proper.str(), out.str());
	}
}

