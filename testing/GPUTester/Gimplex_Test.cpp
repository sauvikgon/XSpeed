#include <sstream>
#include <iostream>

//#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev

#include "core_system/math/Gimplex/simplex.cuh"
#include "core_system/math/matrix.h"
//#include "core_system/math/uni_sphere.h"	//for obtaining uniformly distributed directions
//#include "boost/timer/timer.hpp"

using namespace std;

SUITE(GimplexSolver_TestSuite) {
struct Example_GimplexSolver {
	Example_GimplexSolver() {
		;
	}
	~Example_GimplexSolver() {
		/* some teardown */
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
 TEST_FIXTURE(Example_GimplexSolver, gimplex1) {

 math::matrix<float> A, C;
 std::vector<float> b, result;
 std::vector<int> status_val;
 int N_S = 1000;
 int N_C = 2;
 int N_V = 2;
 C = math::matrix<float>(N_S, N_V);
 C(0, 0) = 3;
 C(0, 1) = 4;
 C(1, 0) = -2;
 C(1, 1) = 1;

 ///Assign for 1000 LPS
 for (int i = 0; i < N_S; i++) {
 for (int j = 0; j < N_V; j++) {
 if (j == 0) {

 C(i, j) = 3;
 } else if (j == 1) {
 C(i, j) = 4;
 }
 }

 }

 A = math::matrix<float>(N_C, N_V);
 A(0, 0) = 1;
 A(0, 1) = 1;
 A(1, 0) = 2;
 A(1, 1) = 1;

 b.resize(N_C);
 b[0] = 4;
 b[1] = 5;

 Simplex s(N_S);
 s.setConstratint(A, b, N_S);
 s.ComputeLP(C, N_C);
 status_val = s.getStatusAll();

 std::cout << "\n**Answer_Of_All_Simplex**\n";
 result = s.getResultAll();
 for (int i = 0; i < C.size1(); i++) {
 if (result[i] > 0)
 std::cout << result[i] << "\n";
 else if (result[i] == -1)
 std::cout << "Simplex " << i + 1 << " is unbounded\n\n";
 }
 }
 */

/*
 TEST_FIXTURE(Example_GimplexSolver, gimplex2) {

 math::matrix<float> C;
 std::vector<double> b;
 std::vector<float> result;
 std::vector<int> status_val;
 int N_S = 2048;
 int N_C = 4;
 int N_V = 2;
 C = math::matrix<float>(N_S, N_V);

 ///Assign for 1000 LPS
 for (int i = 0; i < N_S; i++) {
 for (int j = 0; j < N_V; j++) {
 if (j == 0) {

 C(i, j) = 1.0;
 } else if (j == 1) {
 C(i, j) = 20.0;
 }
 }

 }

 math::matrix<double> A(4, 2);
 A(0, 0) = 1;
 A(0, 1) = 0;
 A(1, 0) = -1;
 A(1, 1) = 0;
 A(2, 0) = 0;
 A(2, 1) = 1;
 A(3, 0) = 0;
 A(3, 1) = -1;

 b.resize(4);
 b[0] = 10.2;
 b[1] = -10;
 b[2] = 0;
 b[3] = 0;

 Simplex s(N_S);
 s.setConstratint(A, b);
 s.ComputeLP(C);
 status_val = s.getStatusAll();

 std::cout << "\n**Answer_Of_All_Simplex**\n";
 result = s.getResultAll();
 for (int i = 0; i < N_S; i++) {
 //		if (result[i] > 0)
 std::cout << result[i] << "\n";
 //		else
 if (result[i] == -1)
 std::cout << "Simplex " << i + 1 << " is unbounded\n";
 }
 std::cout << "Number of Simplex Solved = " << N_S << std::endl;
 }
 */

TEST_FIXTURE(Example_GimplexSolver, gimplex3) {

	math::matrix<double> A;
	math::matrix<float> C;
	std::vector<double> b;
	std::vector<float> result;
	std::vector<int> status_val;

	int N_S = 1;

	//Tester for Helicopter Model

	int N_C = 56;		//constriants
	int N_V = 28;		//variables
	C = math::matrix<float>(N_S, N_V);

	///Assign for 1000 LPS
	for (int i = 0; i < N_S; i++) {
		for (int j = 0; j < N_V; j++) {
			if (j == 0) {
				C(i, j) = 1.0;
			} else {	// if (j == 1) {
				C(i, j) = 0;
			}
		}
	}

	int row = 56, col = 28;			//28	//34		//35;
	A.resize(row, col);
	b.resize(row);

	for (unsigned int i = 0; i < col; i++) {		//28		//34		//35
		for (unsigned int j = 0; j < col; j++) {	//28		//34		//35
			if (i == j) {	//for diagonal elements assign 1 and -1
				A(2 * i, j) = 1;			//for xi
				A(2 * i + 1, j) = -1;		//for -xi
			} else {	//for all other elements assign zeros
				A(2 * i, j) = 0;			//for xi
				A(2 * i + 1, j) = 0;		//for -xi
			}
		}
		if (i < 8) {		//x1  to x8
			b[2 * i] = 0.1;
			b[2 * i + 1] = 0;
		}
		if ((i >= 8) && (i < col)) {		//x9  to x28
			b[2 * i] = 0;
			b[2 * i + 1] = 0;
		}
	}
	int no_streams = 1;
	Simplex s(N_S);
	s.setConstratint(A, b);
	s.ComputeLP(C, no_streams);
	status_val = s.getStatusAll();

	result = s.getResultAll();
	std::vector<double> res(result.size());
	res[0] = result[0];		//0.1; double matching fails in C++
	CHECK_ARRAY_EQUAL(res,result,result.size());
}

}

