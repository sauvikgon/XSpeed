#include "UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "core_system/math/matrix.h"
#include "counterExample/simulation.h"
#include "application/DataStructureDirections.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <cmath>

using namespace std;

SUITE(SimulationTestSuite) {
struct Example {
	Example() {
	}

	stringstream expected, test;
	~Example() { /* some teardown */
	}

};

TEST_FIXTURE(Example, ContinuousSimulationTest) {

	Dynamics dyn;
	math::matrix<double> Amatrix(3,3);
	Amatrix(0, 0) = 0;
	Amatrix(0, 1) = 1;
	Amatrix(0, 2) = 0;
	Amatrix(1, 0) = 0;
	Amatrix(1, 1) = 0;
	Amatrix(1, 2) = 0;
	Amatrix(2, 0) = 0;
	Amatrix(2, 1) = 0;
	Amatrix(2, 2) = 0;

	dyn.MatrixA =Amatrix;
	dyn.isEmptyMatrixA = false;

	dyn.isEmptyMatrixB = true;

	std::vector<double> v(3);
	v[0]=0;
	v[1]=-9.8;
	v[2] = 1;

	dyn.C = v;

	simulation::ptr sim = simulation::ptr(new simulation(3,100,dyn));

	sim->insert_to_map("x",0);
	sim->insert_to_map("v",1);
	sim->insert_to_map("t",2);

	std::vector<double> x0(3);
	x0[0] = 10.1; x0[1] = 0; x0[2]=0;

	double sim_time = 5;

	sim->set_outfile("kamalTest.out");
	sim->set_out_dimension(2,0);
	sim->simulate(x0,sim_time);

}

}
