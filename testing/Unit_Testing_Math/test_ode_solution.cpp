#include "UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "counterExample/simulation.h"
#include "application/DataStructureDirections.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>
#include "../../core/math/analyticODESol.h"
#include "../../core/math/matrix.h"

using namespace std;

SUITE(ODE_AnalyticSolutionTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};
TEST_FIXTURE(Example, solutionTest) {

	Dynamics dyn;
	math::matrix<double> Amatrix(5,5);
	Amatrix(0, 0) = -4.8082;
	Amatrix(0, 1) = -4.0336;
	Amatrix(0, 2) = 1.5610;
	Amatrix(0, 3) = -1.9059;
	Amatrix(0, 4) = -0.7299;

	Amatrix(1, 0) = -1.4137;
	Amatrix(1, 1) = -7.2405;
	Amatrix(1, 2) = -1.4615;
	Amatrix(1, 3) = -3.4139;
	Amatrix(1, 4) = 4.4378;

	Amatrix(2, 0) = 7.1423;
	Amatrix(2, 1) = 12.4581;
	Amatrix(2, 2) = 0.3480;
	Amatrix(2, 3) = 8.6344;
	Amatrix(2, 4) = -6.9834;

	Amatrix(3, 0) = -0.0349;
	Amatrix(3, 1) = 2.3922;
	Amatrix(3, 2) = 0.8171;
	Amatrix(3, 3) = 0.0909;
	Amatrix(3, 4) = -3.5798;

	Amatrix(4, 0) = -6.6104;
	Amatrix(4, 1) = -14.5070;
	Amatrix(4, 2) = 1.1341;
	Amatrix(4, 3) = -7.1915;
	Amatrix(4, 4) = 1.6098;
	dyn.MatrixA =Amatrix;
	dyn.isEmptyMatrixA = false;

	dyn.isEmptyMatrixB = true;

	std::vector<double> v(5);
	v[0]=0.01;
	v[1]=0.01;
	v[2]=0.01;
	v[3]=0.01;
	v[4]=0.01;

	dyn.C = v;

	simulation::ptr sim = simulation::ptr(new simulation(5,100,dyn));
	sim->insert_to_map("x1",0);
	sim->insert_to_map("x2",1);
	sim->insert_to_map("x3",2);
	sim->insert_to_map("x4",3);
	sim->insert_to_map("t",4);

	std::vector<double> x0(5), final_numeric(5), final_analytic(5);
	x0[0] = 1.01; x0[3] = 0.01;
	x0[1] = 0.1;  x0[4] = 0.01;
	x0[2] = 0.1;

	double sim_time = 5.3;
	final_numeric = sim->simulate(x0,sim_time);

	final_analytic = ODESol(x0,dyn,sim_time);

	CHECK_ARRAY_CLOSE(final_numeric, final_analytic, 5, 0.1);

	// another test
	math::matrix<double> Amatrix1(4,4);
	Amatrix1(0, 0) = 0;
	Amatrix1(0, 1) = 0;
	Amatrix1(0, 2) = 1;
	Amatrix1(0, 3) = 0;

	Amatrix1(1, 0) = 0;
	Amatrix1(1, 1) = 0;
	Amatrix1(1, 2) = 0;
	Amatrix1(1, 3) = 1;

	Amatrix1(2, 0) = 0;
	Amatrix1(2, 1) = 0;
	Amatrix1(2, 2) = 0.3480;
	Amatrix1(2, 3) = 8.6344;

	Amatrix1(3, 0) = 0;
	Amatrix1(3, 1) = 0;
	Amatrix1(3, 2) = 0.8171;
	Amatrix1(3, 3) = 0.0909;


	dyn.MatrixA =Amatrix1;
	dyn.isEmptyMatrixA = false;

	dyn.isEmptyMatrixB = true;

	std::vector<double> v1(4);
	v1[0]=0.01;
	v1[1]=0.01;
	v1[2]=0.01;
	v1[3]=0.01;

	dyn.C = v1;

	sim = simulation::ptr(new simulation(4,100,dyn));
	sim->insert_to_map("x1",0);
	sim->insert_to_map("x2",1);
	sim->insert_to_map("v1",2);
	sim->insert_to_map("v2",3);

	std::vector<double> x(4);
	x[0] = 1.01; x[3] = 0.01;
	x[1] = 0.1;
	x[2] = 0.1;

	sim_time = 5.3;
	final_numeric = sim->simulate(x,sim_time);
	final_analytic = ODESol(x,dyn,sim_time);

	for(unsigned int i=0;i<4;i++)
	{
		if(fabs(final_numeric[i] - final_analytic[i])<=2)
			continue;
		else
			std::cout << "FAILED Comparison\n";
	}
	CHECK_ARRAY_CLOSE(final_numeric, final_analytic, 4, 2);
}

}
