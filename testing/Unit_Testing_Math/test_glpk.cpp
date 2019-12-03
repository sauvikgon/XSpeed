/*
 * complete_simplex_tester_glpk.cpp
 *
 *  Created on: 12-Feb-2015
 *      Author: amit
 */
#include <sstream>
#include <iostream>
#include "UnitTest++.h"
#include "boost/timer/timer.hpp"
#include <omp.h>
#include "../../core/math/glpk_lp_solver/glpk_lp_solver.h"
#include "../../core/math/matrix.h"
#include "../../core/math/uni_sphere.h"	//for obtaining uniformly distributed directions

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


	res = lp.Compute_LLP(direction);

	out << "";
	out << res;
	proper << "";
	proper << "10.2";

	CHECK_EQUAL(proper.str(), out.str());
}

TEST_FIXTURE(Glpk_LPSolver, LP_ABS_FUNC_Test) {
	/**
	 * We test the standard procedure to convert a optimization
	 * with a modulus objective function as the objective to a linear
	 * objective function.
	 */
	row = 8;
	col = 4;
	math::matrix<double> A(row, col,0);

	/**
	 * The opt problem desciption is:
	 * min |x-y| s.t
	 * 2<=x<=5; 7<=y<=9
	 *
	 * The equivalent LP is:
	 * min p1 + p2 s.t.
	 * p1,p2>=0;
	 * p1 - p2 = x - y;
	 * 2<=x<=5; 7<=y<=9.
	 * Below shown is the LP formulation as a XSpeed glpk_lp_solver object
	 */
	A(0,0) = 1;
	A(1,0) = -1;
	A(2,1) = 1;
	A(3,1) = -1;
	A(4,2) = -1;
	A(5,3) = -1;
	A(6,0) = 1;
	A(6,1) = -1;
	A(6,2) = -1;
	A(6,3) = 1;
	A(7,0) = -1;
	A(7,1) = 1;
	A(7,2) = 1;
	A(7,3) = -1;

	std::vector<double> b(row,0);
	b[0] = 5;
	b[1] = -2;
	b[2] = 9;
	b[3] = -7;

	direction.resize(4);	// obj function vector
	direction[0] = 0;
	direction[1] = 0;
	direction[2] = 1.0;
	direction[3] = 1.0;

	boundSignI = 1;

	glpk_lp_solver lp;
	lp.setMin_Or_Max(1);	//1 for MIN
	lp.setConstraints(A, b, boundSignI);


	double res;

	res = lp.Compute_LLP(direction);

	CHECK_EQUAL(res, 2);

	/**
	 * The opt problem desciption is:
	 * min |x-y| s.t
	 * 0<=x<=3; 7<=y<=9
	 *
	 * The equivalent LP is:
	 * min p1 + p2 s.t.
	 * p1,p2>=0;
	 * p1 - p2 = x - y;
	 * 0<=x<=3; 7<=y<=9.
	 * Below shown is the LP formulation as a XSpeed glpk_lp_solver object
	 */
	A(0,0) = 1;
	A(1,0) = -1;
	A(2,1) = 1;
	A(3,1) = -1;
	A(4,2) = -1;
	A(5,3) = -1;
	A(6,0) = 1;
	A(6,1) = -1;
	A(6,2) = -1;
	A(6,3) = 1;
	A(7,0) = -1;
	A(7,1) = 1;
	A(7,2) = 1;
	A(7,3) = -1;

	std::vector<double> b1(row,0);
	b1[0] = 3;
	b1[1] = 0;
	b1[2] = 9;
	b1[3] = -7;

	direction.resize(4); // obj function vector
	direction[0] = 0;
	direction[1] = 0;
	direction[2] = 1.0;
	direction[3] = 1.0;

	boundSignI = 1;

	lp.setConstraints(A, b1, boundSignI);

	res = lp.Compute_LLP(direction);

	CHECK_EQUAL(res, 4);
}


TEST_FIXTURE(Glpk_LPSolver, LP_Embedding_Test) {
	/**
	 * We test the procedure to embed two optimization problems
	 * with a modulus objective function, as a single LP
	 */
	row = 16;
	col = 8;
	math::matrix<double> A(row, col,0);

	/**
	 * The opt problem desciption is:
	 * min |x-y| s.t
	 * 2<=x<=5; 7<=y<=9
	 *
	 * The equivalent LP is:
	 * min p1 + p2 s.t.
	 * p1,p2>=0;
	 * p1 - p2 = x - y;
	 * 2<=x<=5; 7<=y<=9.
	 * Below shown is the LP formulation as a XSpeed glpk_lp_solver object
	 */
	A(0,0) = 1;
	A(1,0) = -1;
	A(2,1) = 1;
	A(3,1) = -1;
	A(4,2) = -1;
	A(5,3) = -1;
	A(6,0) = 1;
	A(6,1) = -1;
	A(6,2) = -1;
	A(6,3) = 1;
	A(7,0) = -1;
	A(7,1) = 1;
	A(7,2) = 1;
	A(7,3) = -1;
	A(8,4) = 1;
	A(9,4) = -1;
	A(10,5) = 1;
	A(11,5) = -1;
	A(12,6) = -1;
	A(13,7) = -1;
	A(14,4) = 1;
	A(14,5) = -1;
	A(14,6) = -1;
	A(14,7) = 1;
	A(15,4) = -1;
	A(15,5) = 1;
	A(15,6) = 1;
	A(15,7) = -1;

	std::vector<double> b(row,0);
	b[0] = 5;
	b[1] = -2;
	b[2] = 9;
	b[3] = -7;
	b[8] = 3;
	b[9] = 0;
	b[10] = 9;
	b[11] = -7;

	direction.resize(8);	//Down Direction
	direction[0] = 0;
	direction[1] = 0;
	direction[2] = 1.0;
	direction[3] = 1.0;
	direction[4] = 0;
	direction[5] = 0;
	direction[6] = 1.0;
	direction[7] = 1.0;

	boundSignI = 1;

	glpk_lp_solver lp;
	lp.setMin_Or_Max(1);	//2 for GLP_MAX
	lp.setConstraints(A, b, boundSignI);

	double res;

	res = lp.Compute_LLP(direction);

	// We note that the solution of the LP formed by embedding two smaller dimensional
	// problems is the sum of the solution of the smaller LPs solved individually.
	// The solution here is 6, which is the sum of the solutions of the two smaller
	// LPs, 2 and 4 resp.
	CHECK_EQUAL(res, 6);
}

}
