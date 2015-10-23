/*
 * complete_simplex_tester_glpk.cpp
 *
 *  Created on: 12-Feb-2015
 *      Author: amit
 */
#include <sstream>
#include <iostream>
//#include "UnitTest++/UnitTest++.h"
#include "UnitTest++/UnitTest++.h"

#include "core_system/math/glpk_lp_solver/glpk_lp_solver.h"
#include "core_system/math/matrix.h"
#include "core_system/math/uni_sphere.h"	//for obtaining uniformly distributed directions
#include "boost/timer/timer.hpp"
#include <omp.h>

using namespace std;

SUITE(glpk_TestSuite) {
struct Glpk_LPSolver {
	Glpk_LPSolver() {

	}
	~Glpk_LPSolver() { /* some teardown */
	}
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignI;
	std::vector<double> direction;
	stringstream out, proper;
};

TEST_FIXTURE(Glpk_LPSolver, CPU_LP_Test) {

	std::vector<double> b;
	std::vector<int> status_val;


	int N_S = 1000;
	int N_C = 2;
	int N_V = 2;

	row = 4;
	col = 2;
	math::matrix<double> A(row, col);
	A(0, 0) = 1;
	A(0, 1) = 0;
	A(1, 0) = -1;
	A(1, 1) = 0;
	A(2, 0) = 0;
	A(2, 1) = 1;
	A(3, 0) = 0;
	A(3, 1) = -1;

	b.resize(row);
	b[0] = 10.2;
	b[1] = -10;
	b[2] = 0;
	b[3] = 0;

	direction.resize(2);	//Down Direction
	direction[0] = 1.0;
	direction[1] = 20.0;

	boundSignI = 1;

	glpk_lp_solver lp;
	lp.setMin_Or_Max(2);	//2 for GLP_MAX
	lp.setConstraints(A, b, boundSignI);

	double res;

	std::cout << "\n**Answer_Of_All_Simplex GLPK**\n";
	for (int i = 0; i < N_S; i++) {
		res = lp.Compute_LLP(direction);
		cout << res << "\n";
	}

	/*
	 math::matrix<double> A;
	 std::vector<double> b;
	 std::vector<int> status_val;
	 int N_S = 1000;
	 int N_C = 2;
	 int N_V = 2;

	 A = math::matrix<double>(N_C, N_V);
	 A(0, 0) = 1;
	 A(0, 1) = 1;
	 A(1, 0) = 2;
	 A(1, 1) = 1;

	 b.resize(N_C);
	 b[0] = 4;
	 b[1] = 5;

	 boundSignI = 1;

	 glpk_lp_solver lp;
	 lp.setMin_Or_Max(2);	//2 for GLP_MAX
	 lp.setConstraints(A, b, boundSignI);

	 double res;
	 direction.resize(2);
	 direction[0]=3;
	 direction[1]=4;
	 std::cout << "\n**Answer_Of_All_Simplex GLPK**\n";
	 for (int i=0;i<N_S;i++){
	 res = lp.Compute_LLP(direction);
	 cout <<res<<"\n";
	 }
	 */
}

}

