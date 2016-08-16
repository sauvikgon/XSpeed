#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "core_system/math/matrix.h"
#include "counterExample/simulation.h"
#include "application/DataStructureDirections.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>

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

	std::vector<double> x0(5), final(5);
	x0[0] = 1.01; x0[3] = 0.01;
	x0[1] = 0.1;  x0[4] = 0.01;
	x0[2] = 0.1;

	double sim_time = 5.3;
	final = sim->simulate(x0,sim_time);
	std::cout << "Numerical Solution of ODE:";
	for(unsigned int i=0;i<5;i++)
		std::cout << final[i] << " " << std::endl;

	// analytic solution

	math::matrix<double> expAt(5,5);
	math::matrix<double> A(Amatrix);

	Amatrix.scalar_multiply(sim_time);
	Amatrix.matrix_exponentiation(expAt);

	std::vector<double> res1(5), res2(5), res3(5);

	expAt.mult_vector(x0,res1);

	math::matrix<double> AInv(5,5);
	A.inverse(AInv);
	std::vector<double> minusV(5);
	for(unsigned int i=0;i<5;i++)
		minusV[i] = (-1)*v[i];

	AInv.mult_vector(minusV,res2);
	math::matrix<double> mult(5,5);
	AInv.multiply(expAt,mult);
	mult.mult_vector(v,res3);


	for(unsigned int i=0;i<res1.size();i++){
		res1[i] = res1[i] + res2[i] + res3[i];
	}
	std::cout << "Analytical Solution of ODE:";
	for(unsigned int i=0;i<5;i++)
		std::cout << res1[i] << " " << std::endl;

//	expected << "0.544242";
//	test << minf;
//	CHECK_EQUAL(expected.str(), test.str());
}

}
