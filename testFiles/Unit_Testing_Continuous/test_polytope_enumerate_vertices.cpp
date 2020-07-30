/*
 * test_polytope.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>

#include "core/continuous/polytope/polytope.h"
#include "core/math/matrix.h"
#include "utilities/vectorOperations.h"
#include "UnitTest++/UnitTest++.h"

//#include "Utilities/StandardVector.h"

using namespace std;

SUITE(polytope_function_TestSuite) {
	struct Polytope_func_test {
		Polytope_func_test() {
		}
		~Polytope_func_test() { /* some teardown */
		}

		typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
		size_type row, col;
		int boundSignI;
		std::vector<double> boundValueI;
		math::matrix<double> ConstraintsMatrixI;
		std::vector<double> direction;
		stringstream out, proper;
	};

	/*
	 TEST_FIXTURE(Polytope_func_test, enumerate_2dVertices) {
	 std::cout << "\nRunning Polytope enumerate_2dVertices function\n";
	 std::set<std::pair<double, double> > All_vertices;

	 row = 4;
	 col = 2;
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
	 boundValueI[0] = 10;
	 boundValueI[1] = -2;
	 boundValueI[2] = 5;
	 boundValueI[3] = -3;

	 boundSignI = 1;
	 polytope P(ConstraintsMatrixI, boundValueI, boundSignI);

	 All_vertices = P.enumerate_2dVertices(0, 1);	//variable 0,1 ie x,y
	 std::set<std::pair<double, double> >::iterator it;
	 std::cout << "\nvertices are ...\n";
	 for (it = All_vertices.begin(); it != All_vertices.end(); ++it) {
	 std::pair<double, double> point;
	 point = (*it);
	 cout << "(" << point.first << ", " << point.second << ")\n";
	 }
	 }*/

	TEST_FIXTURE(Polytope_func_test, enumerate_2dVertices_test2) {

		//Running Polytope enumerate_2dVertices function test2
		std::set<std::pair<double, double> > All_vertices;

		row = 4;
		col = 2;
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
		boundValueI[1] = 4;
		boundValueI[2] = 2;
		boundValueI[3] = 2;

		boundSignI = 1;
		polytope P(ConstraintsMatrixI, boundValueI, boundSignI);

		All_vertices = P.enumerate_2dVertices(0, 1); //variable 0,1 ie x,y
		std::set<std::pair<double, double> >::iterator it;
		math::matrix<double> my_vertices;
		float output7[7][2];
		// My Sorted Vertices with closed vertex are

		my_vertices = sort_vertices(All_vertices);
		for (int i = 0; i < my_vertices.size1(); i++)
		{
			for (int j = 0; j < my_vertices.size2(); j++)
			{
				output7[i][j]=my_vertices(i, j);
			}
		}
		out <<my_vertices;
		const float res7[7][2]={{-4,-2},{4,-2},{4,0},{4,2},{-4,2},{-4,0},{-4,-2}};
		CHECK_ARRAY2D_CLOSE(res7, output7, 7, 2, 0.0);
	}

	/*
	 TEST_FIXTURE(Polytope_func_test, enumerate_2dVertices_test3) {

	 std::cout << "\nRunning Polytope enumerate_2dVertices function test -2\n";
	 std::set<std::pair<double, double> > All_vertices;

	 row = 5;
	 col = 2;
	 ConstraintsMatrixI.resize(row, col);
	 ConstraintsMatrixI(0, 0) = 4;
	 ConstraintsMatrixI(0, 1) = -1;
	 ConstraintsMatrixI(1, 0) = 2;
	 ConstraintsMatrixI(1, 1) = 1;
	 ConstraintsMatrixI(2, 0) = -5;
	 ConstraintsMatrixI(2, 1) = 2;
	 ConstraintsMatrixI(3, 0) = -1;
	 ConstraintsMatrixI(3, 1) = 0;
	 ConstraintsMatrixI(4, 0) = 0;
	 ConstraintsMatrixI(4, 1) = -1;

	 boundValueI.resize(5);
	 boundValueI[0] = 8;
	 boundValueI[1] = 10;
	 boundValueI[2] = 2;
	 boundValueI[3] = 0;
	 boundValueI[4] = 0;

	 boundSignI = 1;
	 polytope P(ConstraintsMatrixI, boundValueI, boundSignI);

	 All_vertices = P.enumerate_2dVertices(0, 1);	//variable 0,1 ie x,y
	 std::set<std::pair<double, double> >::iterator it;
	 std::cout << "\nvertices are ...\n";
	 for (it = All_vertices.begin(); it != All_vertices.end(); ++it) {
	 std::pair<double, double> point;
	 point = (*it);
	 cout << "(" << point.first << ", " << point.second << ")\n";
	 }
	 }
	 */
}

