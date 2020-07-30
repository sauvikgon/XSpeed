/*
 * complete_simplex_tester_glpk.cpp
 *
 *  Created on: 12-Feb-2015
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "boost/timer/timer.hpp"
#include <omp.h>
#include "core/math/glpkLpSolver/glpkLpSolver.h"
#include "core/math/matrix.h"
#include "core/math/uniSphere.h"

using namespace std;

SUITE(glpk_lp_solver_TestSuite) {
struct Example_glpk_LPSolver {
	Example_glpk_LPSolver() {

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
	~Example_glpk_LPSolver() { /* some teardown */
	}
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignI, boundSignV;
	std::vector<double> boundValueI, boundValueV;
	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV;
	std::vector<double> direction;
	stringstream out, proper;
};

TEST_FIXTURE(Example_glpk_LPSolver, lp_solver_TestConstraints_Test) {

	unsigned int status;
	glpk_lp_solver lp;
	lp.setMin_Or_Max(2);	//2 for GLP_MAX
	//lp.setMin_Or_Max(1);	//1 for GLP_MIN
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.TestConstraints();
//	cout << "\n\n\nStatus = " << status << endl;
	out << status;
	proper << "5";
	CHECK_EQUAL(proper.str(), out.str());
}

TEST_FIXTURE(Example_glpk_LPSolver, lp_solver_1stQuadrant_Test1) {

	row = 4;
	col = 2;
//	cout << "\nAmit 1\n";
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
//	cout << "\nAmit 2\n";
	double status;
	glpk_lp_solver lp;
	lp.setMin_Or_Max(2);	//2 for GLP_MAX

	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
//	cout << "\nAmit 3\n";
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMaximum in Left direction= " << status << endl;
	out << status;
	//std::cout << res;
	proper << "3";
	CHECK_EQUAL(proper.str(), out.str());

	lp.setMin_Or_Max(1);	//1 for GLP_MIN
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMinimum in Left direction(give right value)= " << status<< endl;
	stringstream out1, proper1;
	out1 << status;
	proper1 << "-2";
	CHECK_EQUAL(proper1.str(), out1.str());

	direction.resize(2);
	direction[0] = 0;
	direction[1] = -1;

	lp.setMin_Or_Max(2);	//2 for GLP_MAX
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMaximum in Down direction= " << status << endl;
	stringstream out2, proper2;
	out2 << status;
	proper2 << "6";
	CHECK_EQUAL(proper2.str(), out2.str());

	lp.setMin_Or_Max(1);	//2 for GLP_MAX
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	double test = lp.Compute_LLP(direction);
//	cout << "\n\n\nMinimum in Down direction  AMIT SHOULD BE -2  IS IT? = "<< test << endl;
	stringstream out7, proper7;
	out7 << test;
	proper7 << "-2";
	CHECK_EQUAL(proper7.str(), out7.str());

	direction[0] = 1;
	direction[1] = 0;

	lp.setMin_Or_Max(2);	//2 for GLP_MAX
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMaximum in Right direction= " << status << endl;
	stringstream out3, proper3;
	out3 << status;
	proper3 << "2";
	CHECK_EQUAL(proper3.str(), out3.str());

	lp.setMin_Or_Max(1);	//2 for GLP_Min
	lp.setInitial_SimplexControlParameters();
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMinimum in Right direction= " << status << endl;
	stringstream out5, proper5;
	out5 << status;
	proper5 << "-3";
//lp1.setMin_Or_Max(2);
//lp1.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);

//	status = lp1.Compute_LLP(direction);
//lp.setMin_Or_Max(1);	//1 for GLP_MIN
	CHECK_EQUAL(proper5.str(), out5.str());

	direction[0] = 0;
	direction[1] = 1;

	lp.setMin_Or_Max(2);	//2 for GLP_MAX
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMaximum in Up direction= " << status << endl;
	stringstream out4, proper4;
	out4 << status;
	proper4 << "2";
	CHECK_EQUAL(proper4.str(), out4.str());

	lp.setMin_Or_Max(1);	//2 for GLP_Min
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMinimum in Up direction= " << status << endl;
	stringstream out6, proper6;
	out6 << status;
	proper6 << "-6";
	CHECK_EQUAL(proper6.str(), out6.str());

}

TEST_FIXTURE(Example_glpk_LPSolver, lp_solver_1stQuadrant_Test2) {
	//Test region on the 1stQuadrant
	row = 4;
	col = 2;

	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = -1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(1, 0) = 1;
//lp1.setMin_Or_Max(2);
//lp1.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);

//	status = lp1.Compute_LLP(direction);
//lp.setMin_Or_Max(1);	//1 for GLP_MIN
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;

	boundValueI.resize(4);
	boundValueI[0] = -2;
	boundValueI[1] = 3;
	boundValueI[2] = 7;
	boundValueI[3] = -5;

	boundSignI = 1;

	direction.resize(2);	//Down Direction
	direction[0] = 0;
	direction[1] = -1;

	double status;
	glpk_lp_solver lp;
	lp.setMin_Or_Max(2);	//2 for GLP_MAX
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMaximum in Down direction= " << status << endl;
	stringstream out1, proper1;
	out1 << status;
	proper1 << "-5";
	CHECK_EQUAL(proper1.str(), out1.str());

	lp.setMin_Or_Max(1);	//2 for GLP_MAX
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMinimum in Down direction= " << status << endl;
	stringstream out3, proper3;
	out3 << status;
	proper3 << "-7";
	CHECK_EQUAL(proper3.str(), out3.str());

	direction[0] = -1;
	direction[1] = 0;

	lp.setMin_Or_Max(2);	//min
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMaximum in Left direction= " << status << endl;
	stringstream out2, proper2;
	out2 << status;
	proper2 << "-2";
	CHECK_EQUAL(proper2.str(), out2.str());

	lp.setMin_Or_Max(1);	//min
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMinimum in Left direction= " << status << endl;
	stringstream out4, proper4;
	out4 << status;
	proper4 << "-3";
	CHECK_EQUAL(proper4.str(), out4.str());

	direction[0] = 1;
	direction[1] = 0;

	lp.setMin_Or_Max(2);	//min
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMaximum in Right direction= " << status << endl;
	stringstream out5, proper5;
	out5 << status;
	proper5 << "3";
	CHECK_EQUAL(proper5.str(), out5.str());

	lp.setMin_Or_Max(1);	//min
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	status = lp.Compute_LLP(direction);
//	cout << "\n\n\nMinimum in Right direction= " << status << endl;
	stringstream out6, proper6;
	out6 << status;
	proper6 << "2";
	CHECK_EQUAL(proper6.str(), out6.str());
}

TEST_FIXTURE(Example_glpk_LPSolver, lp_solver_Testing3) {
	/*
	 //Test region on the 1stQuadrant
	 row = 4;
	 col = 2;

	 ConstraintsMatrixI.resize(row, col);
	 ConstraintsMatrixI(0, 0) = -1;
	 ConstraintsMatrixI(0, 1) = 0;
	 ConstraintsMatrixI(1, 0) = 1;
	 ConstraintsMatrixI(1, 1) = 0;
	 ConstraintsMatrixI(2, 0) = 0;
	 ConstraintsMatrixI(2, 1) = 1;
	 ConstraintsMatrixI(3, 0) = 0;
	 ConstraintsMatrixI(3, 1) = -1;

	 boundValueI.resize(4);
	 boundValueI[0] = -2;
	 boundValueI[1] = 3;
	 boundValueI[2] = 7;
	 boundValueI[3] = -5;

	 boundSignI = 1;

	 direction.resize(2);	//Down Direction
	 direction[0] = 0;
	 direction[1] = -1;
	 std::cout << "Calling Sequential Testing for glpk" << endl;
	 std::cout << "**************************************" << endl;
	 long int number_of_times = 10000;
	 double status, arr[number_of_times];

	 boost::timer::cpu_timer tt1;
	 tt1.start();
	 for (int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result
	 glpk_lp_solver lp;
	 lp.setMin_Or_Max(2);	//2 for GLP_MAX
	 lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	 status = lp.Compute_LLP(direction);
	 arr[i] = status;
	 }
	 tt1.stop();

	 double wall_clock, user_clock, system_clock;
	 wall_clock = tt1.elapsed().wall / 1000000;//convert nanoseconds to milliseconds
	 user_clock = tt1.elapsed().user / 1000000;
	 system_clock = tt1.elapsed().system / 1000000;

	 std::cout << std::fixed;	//to assign precision on the std::output stream
	 std::cout.precision(7);			//cout << setprecision(17);
	 std::cout << "\nBoost Time taken:Wall  (in Seconds) = "
	 << wall_clock / (double) 1000 << std::endl;
	 std::cout << "\nBoost Time taken:User  (in Seconds) = "
	 << user_clock / (double) 1000 << std::endl;
	 std::cout << "\nBoost Time taken:System  (in Seconds) = "
	 << system_clock / (double) 1000 << std::endl;

	 std::cout
	 << "\nglpk TESTING USING Sequential CALLS :: Total Number of ITERATIONS = "
	 << number_of_times << endl;
	 */

}

/*
 TEST_FIXTURE(Example_glpk_LPSolver, lp_solver_Test_OMP) {
 //Test region on the 1stQuadrant
 row = 4;
 col = 2;

 ConstraintsMatrixI.resize(row, col);
 ConstraintsMatrixI(0, 0) = -1;
 ConstraintsMatrixI(0, 1) = 0;
 ConstraintsMatrixI(1, 0) = 1;
 ConstraintsMatrixI(1, 1) = 0;
 ConstraintsMatrixI(2, 0) = 0;
 ConstraintsMatrixI(2, 1) = 1;
 ConstraintsMatrixI(3, 0) = 0;
 ConstraintsMatrixI(3, 1) = -1;

 boundValueI.resize(4);
 boundValueI[0] = -2;
 boundValueI[1] = 3;
 boundValueI[2] = 7;
 boundValueI[3] = -5;

 boundSignI = 1;

 direction.resize(2);	//Down Direction
 direction[0] = 0;
 direction[1] = -1;
 std::cout<<endl<<endl<<endl;
 std::cout<<"Calling OMP Testing for GLPK"<<endl;
 std::cout<<"**************************************"<<endl;

 long int number_of_times = 10000;
 double status, arr[number_of_times];

 boost::timer::cpu_timer tt1;
 tt1.start();
 #pragma omp parallel for
 for (int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result
 glpk_lp_solver lp;
 lp.setMin_Or_Max(2);	//2 for GLP_MAX
 lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 status = lp.Compute_LLP(direction);
 arr[i] = status;
 }
 tt1.stop();

 double wall_clock, user_clock, system_clock;
 wall_clock = tt1.elapsed().wall / 1000000;//convert nanoseconds to milliseconds
 user_clock = tt1.elapsed().user / 1000000;
 system_clock = tt1.elapsed().system / 1000000;

 std::cout << std::fixed;	//to assign precision on the std::output stream
 std::cout.precision(7);			//cout << setprecision(17);
 std::cout << "\nBoost Time taken:Wall  (in Seconds) = "
 << wall_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:User  (in Seconds) = "
 << user_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:System  (in Seconds) = "
 << system_clock / (double) 1000 << std::endl;

 std::cout
 << "\nGLPK TESTING USING OMP CALLS :: Total Number of ITERATIONS = "
 << number_of_times << endl;

 }*/

TEST_FIXTURE(Example_glpk_LPSolver, lp_solver_Testing4) {
	//Test region on the 1stQuadrant
	row = 4;
	col = 3;

	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(0, 2) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(1, 2) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(2, 2) = -1;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(3, 2) = 1;

	boundValueI.resize(4);
	boundValueI[0] = 10.2;
	boundValueI[1] = -10;
	boundValueI[2] = 0;
	boundValueI[3] = 0;

	boundSignI = 1;

	direction.resize(3);	//Down Direction
	direction[0] = 1;
	direction[1] = 0;
	direction[2] = 0;

	/*
	 std::cout << endl << endl << endl;
	 std::cout << "Testing for glpk with a Given Problem" << endl;
	 std::cout << "**************************************" << endl;
	 */

	glpk_lp_solver lp;
	lp.setMin_Or_Max(2);	//2 for GLP_MAX
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	double result = lp.Compute_LLP(direction);
//	std::cout << "\nResult of the Problem using glpk = " << result << endl;
	out << "";
	out << result;
	proper << "";
	proper << "10.2";

	CHECK_EQUAL(proper.str(), out.str());

}

/*

 TEST_FIXTURE(Example_glpk_LPSolver, lp_solver_Test_Sequential_ToCompareWithglpk) {
 //Test region on the 1stQuadrant

 row = 4;
 col = 3;

 ConstraintsMatrixI.resize(row, col);
 ConstraintsMatrixI(0, 0) = 1;
 ConstraintsMatrixI(0, 1) = 0;
 ConstraintsMatrixI(0, 2) = 0;
 ConstraintsMatrixI(1, 0) = -1;
 ConstraintsMatrixI(1, 1) = 0;
 ConstraintsMatrixI(1, 2) = 0;
 ConstraintsMatrixI(2, 0) = 0;
 ConstraintsMatrixI(2, 1) = 1;
 ConstraintsMatrixI(2, 2) = -1;
 ConstraintsMatrixI(3, 0) = 0;
 ConstraintsMatrixI(3, 1) = -1;
 ConstraintsMatrixI(3, 2) = 1;

 boundValueI.resize(4);
 boundValueI[0] = 10.2;
 boundValueI[1] = -10;
 boundValueI[2] = 0;
 boundValueI[3] = 0;

 boundSignI = 1;

 direction.resize(3);	//Down Direction
 direction[0] = 1;
 direction[1] = 0;
 direction[2] = 0;
 long int number_of_times = 60;//200000;	// with 500000 glpk fails to terminate

 std::vector< std::vector<double> > directions;
 //	std::vector< std::vector<double> > newDirections;
 directions = math::uni_sphere(60, 3, 100, 0.0005);
 //	for (int i = 0; i < dir_nums; i++)
 //		newDirections.push_back(directions[i]);

 std::cout << "Calling Testing for GLPK" << endl;
 std::cout << "**************************************" << endl;

 double status;
 int index=0;

 boost::timer::cpu_timer tt1;
 tt1.start();
 //#pragma omp parallel for
 for (long int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result
 glpk_lp_solver lp;
 lp.setMin_Or_Max(2);	//2 for GLP_MAX
 lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 status = lp.Compute_LLP(directions[index]);

 std::cout<< "i="<<i<<" Result = "<<status<<endl;
 index++;
 if (index==60)
 index=0;
 }
 tt1.stop();
 glpk_lp_solver::free_environment_glpk_lp_solver();
 double wall_clock, user_clock, system_clock;
 wall_clock = tt1.elapsed().wall / 1000000;//convert nanoseconds to milliseconds
 user_clock = tt1.elapsed().user / 1000000;
 system_clock = tt1.elapsed().system / 1000000;

 std::cout << std::fixed;	//to assign precision on the std::output stream
 std::cout.precision(7);			//cout << setprecision(17);
 std::cout << "\nBoost Time taken:Wall  (in Seconds) = "
 << wall_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:User  (in Seconds) = "
 << user_clock / (double) 1000 << std::endl;
 std::cout << "\nBoost Time taken:System  (in Seconds) = "
 << system_clock / (double) 1000 << std::endl;

 std::cout
 << "\nGLPK TESTING USING Sequential CALLS :: Total Number of ITERATIONS = "
 << number_of_times << endl;

 }
 */

TEST_FIXTURE(Example_glpk_LPSolver, lp_solver_Testing5) {

	row = 4;
	col = 3;

	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(0, 2) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(1, 2) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(2, 2) = -1;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(3, 2) = 1;

	boundValueI.resize(row);
	boundValueI[0] = 10.2;
	boundValueI[1] = -10;
	boundValueI[2] = 0;
	boundValueI[3] = 0;

	boundSignI = 1;

	direction.resize(col);	//Down Direction
	direction[0] = 1;
	direction[1] = 0;
	direction[2] = 0;

/*
	std::cout << endl << endl << endl;
	std::cout << "Testing for glpk with a Given Problem" << endl;
	std::cout << "**************************************" << endl;
*/

	glpk_lp_solver lp;
	lp.setMin_Or_Max(1);	//2 for GLP_MAX
	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	double result = lp.Compute_LLP(direction);
//	std::cout << "\nMaximize (l) = " << result << endl;

	out << "";
	out << result;
	proper << "";
	proper << "10";
	CHECK_EQUAL(proper.str(), out.str());


	glpk_lp_solver lp2;
	lp2.setMin_Or_Max(1);	//2 for GLP_MAX
	direction[0] = -1;
	direction[1] = 0;
	direction[2] = 0;
	lp2.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	double result2 = lp.Compute_LLP(direction);
//	std::cout << "\n  Maximize (-l) = " << result2 << endl;
//	std::cout << "\n - Minimize (-l) = " << -1 * result2 << endl;
	out << "";
	out << result2;
	proper << "";
	proper << "-10.2";
	CHECK_EQUAL(proper.str(), out.str());

}

}

