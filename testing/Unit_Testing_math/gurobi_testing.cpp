
#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"

#include "core_system/math/gurobi_lp_solver/gurobi_lp_solver.h"
#include "core_system/math/glpk_lp_solver/glpk_lp_solver.h"
#include "core_system/math/matrix.h"
#include "core_system/math/uni_sphere.h"	//for obtaining uniformly distributed directions

#include "boost/timer/timer.hpp"
#include <omp.h>

using namespace std;

SUITE(gurobi_lp_solver_TestSuite) {
struct Example_Gurobi_LPSolver {
	Example_Gurobi_LPSolver() {

		/*
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
		 */
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
		boundValueI[0] = 2;
		boundValueI[1] = 2;
		boundValueI[2] = 2;
		boundValueI[3] = 6;

		boundSignI = 1;

	}
	~Example_Gurobi_LPSolver() { /* some teardown */
	}
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignI, boundSignV;
	std::vector<double> boundValueI, boundValueV;
	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV;
	std::vector<double> direction;
	stringstream out, proper;
};


 TEST_FIXTURE(Example_Gurobi_LPSolver, lp_solver_TestConstraints_Test) {

 unsigned int status;
 gurobi_lp_solver lp;
 lp.setMin_Or_Max(2);	//2 for GLP_MAX
 //lp.setMin_Or_Max(1);	//1 for GLP_MIN
 lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 status = lp.TestConstraints();
 cout << "\n\n\nStatus = " << status << endl;
 out << status;
 proper << "2";		//for gurobi
 CHECK_EQUAL(proper.str(), out.str());
 }
/*

 TEST_FIXTURE(Example_Gurobi_LPSolver, lp_solver_1stQuadrant_Test1) {

 row = 4;
 col = 2;
// cout << "\nAmit 1\n";
 ConstraintsMatrixI.resize(row, col);
 ConstraintsMatrixI(0, 0) = 1.0;
 ConstraintsMatrixI(0, 1) = 0.0;
 ConstraintsMatrixI(1, 0) = -1.0;
 ConstraintsMatrixI(1, 1) = 0.0;
 ConstraintsMatrixI(2, 0) = 0.0;
 ConstraintsMatrixI(2, 1) = 1.0;
 ConstraintsMatrixI(3, 0) = 0.0;
 ConstraintsMatrixI(3, 1) = -1.0;

 boundValueI.resize(4);
 boundValueI[0] = 2.0;
 boundValueI[1] = 3.0;
 boundValueI[2] = 2.0;
 boundValueI[3] = 6.0;

 boundSignI = 1;

 direction.resize(2);
 direction[0] = -1.0;
 direction[1] = 0.0;
 //cout << "\nAmit 2\n";
 double status;
 gurobi_lp_solver lp;
 lp.setMin_Or_Max(2);	//2 for GLP_MAX


 lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 cout << "\nAmit 3\n";
 status = lp.Compute_LPP(direction);
 cout << "\n\n\nMaximum in Left direction= " << status << endl;
 out << status;
 proper << "3";
 CHECK_EQUAL(proper.str(), out.str());

 int st = lp.getStatus();
 cout << "\n\nStatus is = " << st << endl;


 glpk_lp_solver lp2;
 lp2.setMin_Or_Max(2);
 lp2.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 cout << "\n\Result is = " << lp2.Compute_LLP(direction) << endl;
 cout << "\n\nStatus is = " << lp2.getStatus() << endl;
}
*/

 TEST_FIXTURE(Example_Gurobi_LPSolver, lp_solver_1stQuadrant_Test1) {

 row = 5;
 col = 2;
// cout << "\nAmit 1\n";
 ConstraintsMatrixI.resize(row, col);
 ConstraintsMatrixI(0, 0) = -1.0;
 ConstraintsMatrixI(0, 1) = 0.0;
 ConstraintsMatrixI(1, 0) = 1.0;
 ConstraintsMatrixI(1, 1) = 0.0;
 ConstraintsMatrixI(2, 0) = 0.0;
 ConstraintsMatrixI(2, 1) = -1.0;
 ConstraintsMatrixI(3, 0) = 0.0;
 ConstraintsMatrixI(3, 1) = 1.0;
 ConstraintsMatrixI(4, 0) = 0.0;
 ConstraintsMatrixI(4, 1) = 1.0;

 boundValueI.resize(5);
 boundValueI[0] = -1.0;
 boundValueI[1] = 2.0;
 boundValueI[2] = -1.0;
 boundValueI[3] = 3.0;
 boundValueI[4] = 2.0;

 boundSignI = 1;

 direction.resize(2);
 direction[0] = 0.0;
 direction[1] = 1.0;
 //cout << "\nAmit 2\n";
 double status;
 gurobi_lp_solver lp;
 lp.setMin_Or_Max(2);	//2 for GLP_MAX


 lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 cout << "\nAmit 3\n";
 status = lp.Compute_LPP(direction);
 cout << "\n\n\nMaximum in Up direction= " << status << endl;

 glpk_lp_solver lp2;
 lp2.setMin_Or_Max(2);
 lp2.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 cout << "\n\Result is = " << lp2.Compute_LLP(direction) << endl;

}





}



