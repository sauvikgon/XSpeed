/*
 * test_lp_gurobi_simplex.cpp
 *
 *  Created on: 11-Jul-2014
 *      Author: amit
 */
#include <string>
#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "boost/timer/timer.hpp"
#include "core_system/math/matrix.h"
#include "core_system/math/uni_sphere.h"
#include "core_system/math/gurobi_lp_solver/gurobi_lp_solver.h"
#include "core_system/math/glpk_lp_solver/glpk_lp_solver.h"

#include <boost/lexical_cast.hpp>

//#include <gurobi_c++.h>
#include <omp.h>

#include <float.h>
//#define TuneOutput 0

using namespace std;

SUITE(Gurobi_TestSuite) {
struct ExampleGurobi_Simplex {
	ExampleGurobi_Simplex() {

		/* This matrix is in Slack Form */
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
		direction[0] = 1.0;
		direction[1] = 20.0;
		direction[2] = 0.0;

	}
	~ExampleGurobi_Simplex() { /* some teardown */
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
 * GRB_LESS_EQUAL, GRB_EQUAL, or GRB_GREATER_EQUAL
 * InEqualitySign :	The in equalities sign of the bound values 'b'. Possible values are
 * 					0 :	for  Ax = b (b Equals to)		FOR FUTURE USE IF ANY
 * 					1 :	for  Ax <= b (b is Greater Than or Equals to)
 * 					2 :	for  Ax >= b (b is Less Than or Equals to)
 */
/*if (boundSignI == 0)
 sense = GRB_EQUAL;
 else if (boundSignI == 1)
 sense = GRB_LESS_EQUAL;
 else if (boundSignI == 2)
 sense = GRB_GREATER_EQUAL;
 */

/*
 TEST_FIXTURE(ExampleGurobi_Simplex, gurobi_just_Test) {

 std::cout << "Calling Sequential Testing for GUROBI SIMPLEX" << endl;
 std::cout << "**************************************" << endl;
 try{
 GRBEnv env = GRBEnv();

 long int number_of_times = 50;


 boost::timer::cpu_timer tt1;

 tt1.start();
 // #pragma omp parallel for
 for (int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result

 GRBModel model = GRBModel(env);

 model.getEnv().set(GRB_IntParam_OutputFlag, 0);	//To Disable Ouput of Gurobi
 //	env.set("TuneOutput", 0);

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
 boundValueI[0] = 10.2;
 boundValueI[1] = -10;
 boundValueI[2] = 0;
 boundValueI[3] = 0;

 boundSignI = 1;

 direction.resize(2);	//Down Direction
 direction[0] = -1.0;
 direction[1] = 20.0;
 //direction[2] = 0.0;

 unsigned int number_of_variables = ConstraintsMatrixI.size2();
 unsigned int number_of_constraints = ConstraintsMatrixI.size1();

 //double status, arr[number_of_times];

 GRBLinExpr lhsExpr;
 GRBVar variables[number_of_variables];
 char sense;
 //Creating Variables
 for (unsigned int i = 0; i < number_of_variables; i++){
 string varName = "X" + boost::lexical_cast<std::string>(i);
 variables[i] = model.addVar(DBL_MIN, DBL_MAX, 0.0, GRB_CONTINUOUS,
 varName);
 }
 // Integrate new variables
 model.update();
 // Add constraints
 for (unsigned int i = 0; i < number_of_constraints; i++) {
 lhsExpr = 0.0;
 for (unsigned int j = 0; j < number_of_variables; j++) {
 lhsExpr += ConstraintsMatrixI(i, j) * variables[j];
 }

 sense = GRB_LESS_EQUAL;
 model.addConstr(lhsExpr, sense, boundValueI[i], "new");
 }

 GRBLinExpr ObjExpr = 0.0;
 GRBVar *vars;	//[number_of_variables];
 vars = model.getVars();

 for (unsigned int i = 0; i < number_of_variables; i++) {
 ObjExpr += direction[i] * vars[i];
 }

 model.setObjective(ObjExpr, GRB_MAXIMIZE);

 model.optimize();

 std::cout << "Objective Result = " << model.get(GRB_DoubleAttr_ObjVal)
 << std::endl;

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

 std::cout << "\GUROBI TESTING :: Total Number of ITERATIONS = "
 << number_of_times << endl << endl;


 } catch(GRBException &e) {
 cout << "Error code = " << e.getErrorCode() << endl;
 cout << e.getMessage() << endl;
 } catch (...) {
 cout << "Exception during optimization" << endl;
 }

 }

 */

/*
 TEST_FIXTURE(ExampleGurobi_Simplex, Gurobi_LP_Simplex_Test) {

 double status = 0.0;
 int index = 0;

 std::cout << "Testing for GUROBI SIMPLEX" << endl;
 std::cout << "**************************************" << endl;
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
 boundValueI[0] = 10.2;
 boundValueI[1] = -10;
 boundValueI[2] = 0;
 boundValueI[3] = 0;

 long int number_of_times = 300000;
 //	GRBEnv env = GRBEnv();		//creating a single global env variable

 std::vector<std::vector<double> > directions;
 directions = math::uni_sphere(60, 2, 100, 0.0005);

 std::vector<double > d(2);
 //d[0] = -1;
 //d[1] = 0;

 d[0] = -20;
 d[1] = 1;
 boost::timer::cpu_timer tt1;


 //std::cout << "\nThread Limit = " << omp_get_thread_limit() << endl;
 //lp_gurobi_simplex problem;
 //problem.setMin_Or_Max(2);
 //problem.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 //
 //#pragma omp parallel for
 tt1.start();
 for (long int i = 0; i < number_of_times; i++) {//Running in a loop of number_of_times to compute the average result
 lp_gurobi_simplex problem;
 problem.setMin_Or_Max(2);
 problem.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);

 status = problem.Compute_LPP(directions[index]);
 //status = problem.Compute_LPP(d);
 //	std::cout << "i=" << i << " Result = " << status << endl;
 index++;
 if (index == 60)
 index = 0;
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
 std::cout << "GUROBI TESTING :: Total Number of ITERATIONS = "
 << number_of_times << endl << endl;


 // Adding glpk solver test
 std::cout << "results from glpk\n";


 //	glpk_lp_solver lp;
 //	lp.setMin_Or_Max(2);	//2 for GLP_MAX
 //	lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);

 index = 0;
 tt1.start();
 for (long int i = 0; i < number_of_times; i++) {	//Running in a loop of number_of_times to compute the average result
 glpk_lp_solver lp;
 lp.setMin_Or_Max(2);	//2 for GLP_MAX
 lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);

 status = lp.Compute_LLP(directions[index]);
 //status = lp.Compute_LLP(d);

 //	std::cout<< "i="<<i<<" Result = "<<status<<endl;
 index++;
 if (index==60)
 index=0;
 }

 tt1.stop();


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
 std::cout << "GLPK TESTING :: Total Number of ITERATIONS = "
 << number_of_times << endl << endl;



 }

 */

/*

 TEST_FIXTURE(ExampleGurobi_Simplex, Gurobi_LP_Simplex_Test) {

 double status =0.0;

 std::cout << "Testing for GUROBI SIMPLEX" << endl;
 std::cout << "**************************************" << endl;
 row = 4;
 col = 2;
 cout << "\nAmit 1\n";
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
 cout << "\nAmit 2\n";
 //double status;

 lp_gurobi_simplex problem;
 problem.setMin_Or_Max(2);
 problem.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 status = problem.Compute_LPP(direction);
 std::cout<< " Result = "<<status<<endl;	//proper << "3";


 direction.resize(2);
 direction[0] = 0;
 direction[1] = -1;

 lp_gurobi_simplex problem2;
 problem2.setMin_Or_Max(2);
 problem2.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 status = problem2.Compute_LPP(direction);
 std::cout<< " Result = "<<status<<endl;	//	proper2 << "6";


 direction[0] = 1;
 direction[1] = 0;
 problem.setMin_Or_Max(2);
 problem.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
 status = problem.Compute_LPP(direction);
 std::cout<< " Result = "<<status<<endl;	//proper3 << "2";

 }
 */

TEST_FIXTURE(ExampleGurobi_Simplex, Gurobi_LP_Simplex_Test) {

	double status = 0.0;

//	std::cout << "Testing for GUROBI SIMPLEX" << endl;
//	std::cout << "**************************************" << endl;
	/*
	 row = 4;
	 col = 2;
	 //cout << "\nAmit 1\n";
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
	 direction[0] = 1.0;
	 direction[1] = 0.0;

	 lp_gurobi_simplex problem;
	 problem.setMin_Or_Max(1);
	 problem.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	 status = problem.Compute_LPP(direction);
	 std::cout<< " Maximize (l) = "<<status<<endl;	//proper << "3";

	 */

	row = 6;
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
	ConstraintsMatrixI(2, 2) = 0;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(3, 2) = 0;
	ConstraintsMatrixI(4, 0) = 0;
	ConstraintsMatrixI(4, 1) = 0;
	ConstraintsMatrixI(4, 2) = 1;
	ConstraintsMatrixI(5, 0) = 0;
	ConstraintsMatrixI(5, 1) = 0;
	ConstraintsMatrixI(5, 2) = -1;

	boundValueI.resize(row);
	boundValueI[0] = 10.2;
	boundValueI[1] = -10;
	boundValueI[2] = 0;
	boundValueI[3] = 0;
	boundValueI[4] = 0;
	boundValueI[5] = 0;

	gurobi_lp_solver problem2;
	problem2.setMin_Or_Max(1);

	direction.resize(col);
	direction[0] = 1.0;
	direction[1] = 0.0;
	direction[2] = 0.0;

	problem2.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);
	double test = problem2.Compute_LPP(direction);
//	std::cout << " Maximize (l) = " << test << endl;	//proper << "3";

//cout<<"Tesitng  - Minimize (-l) = "<<-1 * status<<endl;	//proper << "3";

	out << "";
	out << test;
	proper << "";
	proper << "10";

	CHECK_EQUAL(proper.str(),out.str());

	/*
	 glpk_lp_solver lp;
	 lp.setMin_Or_Max(1);	//2 for GLP_MAX
	 lp.setConstraints(ConstraintsMatrixI, boundValueI, boundSignI);

	 double status1 = lp.Compute_LLP(direction);
	 std::cout << " Maximize (l) = " << status1 << endl;	//proper << "3";
	 */

}

}
