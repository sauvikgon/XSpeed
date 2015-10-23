#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include "core_system/math/matrix.h"
#include "core_system/math/ourSimplex_lp_solver/simplex.h"
#include <omp.h>
#include "boost/timer/timer.hpp"

#include <string>
using namespace std;
using namespace math;

SUITE(templated_matrix_class_TestSuite) {
struct simplex_class {
	simplex_class() {
		// create a direction
		obj_dir.resize(2);
		obj_dir[0] = 4;
		obj_dir[1] = 6;

		// create a matrix
		row = 3;
		col = 2;
		A = math::matrix<double>(row, col);
		A(0, 0) = -1;
		A(0, 1) = 1;
		A(1, 0) = 1;
		A(1, 1) = 1;
		A(2, 0) = 2;
		A(2, 1) = 5;

		b.resize(3);
		b[0] = 11;
		b[1] = 27;
		b[2] = 90;

		s = simplex<double>(A, b, obj_dir);	//input in standard form (Ax<=b)

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


//	With Positive bound value
		 obj_dir.resize(row);
		 row = 3;	col = 3;
		 A = math::matrix<double>(row, col);
		 obj_dir[0] = 3;
		 obj_dir[1] = 1;
		 obj_dir[2] = 2;

		 // create a matrix
		 A(0, 0) = 1;	A(0, 1) = 1;	 A(0, 2) = 3;
		 A(1, 0) = 2;	A(1, 1) = 2;	 A(1, 2) = 5;
		 A(2, 0) = 4;	A(2, 1) = 1;	 A(2, 2) = 2;

		 b.resize(row);
		 b[0]=30;
		 b[1]=24;
		 b[2]=36;



/*
// With Negative bound value
		row = 2;	col = 2;
		A = math::matrix<double>(row, col);
		obj_dir.resize(row);
		obj_dir[0] = 2;
		obj_dir[1] = -1;
		// create a matrix
		A(0, 0) = 2;	A(0, 1) = -1;
		A(1, 0) = 1;	A(1, 1) = -5;

		b.resize(row);
		b[0]=2;
		b[1]=-4;
*/




/*

//	With Negative bound value
			 row = 3;	col = 2;
			 obj_dir.resize(col);
			 obj_dir[0] = 1;
			 obj_dir[1] = 3;


			 // create a matrix
			 A = math::matrix<double>(row, col);
			 A(0, 0) = 1;	A(0, 1) = -1;
			 A(1, 0) = -1;	A(1, 1) = -1;
			 A(2, 0) = -1;	A(2, 1) = 4;

			 b.resize(row);
			 b[0]=8;
			 b[1]=-3;
			 b[2]=2;
*/




		 s = simplex<double>(A,b,obj_dir);
		 s.process_lp();
		 /*std::cout << "===============ooooooooooooooooooooooooooooooo=========\n";
		 std::cout << "output from simplex After Initialise Simplex Process Over\n";
		 s.display_state();
		 std::cout << "===============xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx=========\n";*/
		 r = s.solve();
		 out<<" ";
		 proper<< " ";
		 std::cout << "output from simplex = " << s.get_obj_val();
}


}
