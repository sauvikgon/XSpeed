#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "core_system/math/matrix.h"
#include "core_system/math/ourSimplex_lp_solver/simplex.h"
#include <omp.h>
#include "boost/timer/timer.hpp"

#include <string>
using namespace std;
using namespace math;

SUITE(templated_matrix_class_TestSuite3) {
struct simplex_class {
	simplex_class() {
	}
	~simplex_class() { /* some teardown */
	}

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	std::vector<double> obj_dir, r;
	std::vector<double> b;
	math::matrix<double> A;
	simplex<double> s;
	stringstream out, proper;
};

TEST_FIXTURE(simplex_class, solve_Test) {

	obj_dir.resize(3);

	row = 3;
	col = 3;
	A = math::matrix<double>(row, col);
	obj_dir[0] = 2;
	obj_dir[1] = -3;
	obj_dir[2] = 3;

	// create a matrix

	A(0, 0) = 1;
	A(0, 1) = 1;
	A(0, 2) = -1;
	A(1, 0) = -1;
	A(1, 1) = -1;
	A(1, 2) = 1;
	A(2, 0) = 1;
	A(2, 1) = -2;
	A(2, 2) = 2;

	b.resize(3);
	b[0] = 7;
	b[1] = -7;
	b[2] = 4;

	s = simplex<double>(A, b, obj_dir);
	//std::cout << "AMIT Here it is Running";
	s.process_lp();
	//s.display_state();
/*	r = s.solve();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "AMIT TEST OUR SIMPLEX OBJECTIVE VALUE = ";
	std::cout << s.get_obj_val();
	std::cout << std::endl;*/

}

}
