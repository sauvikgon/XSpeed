/*
 * test_matrix.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include "core_system/math/matrix.h"
#include "core_system/continuous/Polytope/Polytope.h"

#include <string>
using namespace std;
using namespace math;

SUITE(matrix_class_TestSuite) {
struct matrix_class {
	matrix_class() {


	}
	~matrix_class() { /* some teardown */
	}

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	stringstream out, proper;
};



TEST_FIXTURE(matrix_class, minus_Test) {
	row = 3;
	col = 3;
	math::matrix<double> m1(row, col);
	math::matrix<double> m2(row, col);
	math::matrix<double> output(row, col);

	m1(0, 0) = 1;
	m1(0, 1) = 2;
	m1(0, 2) = 3;

	m1(1, 0) = 4;
	m1(1, 1) = 5;
	m1(1, 2) = 6;

	m1(2, 0) = 7;
	m1(2, 1) = 8;
	m1(2, 2) = 9;

	m2(0, 0) = 1;
	m2(0, 1) = 2;
	m2(0, 2) = 1;

	m2(1, 0) = 2;
	m2(1, 1) = 3;
	m2(1, 2) = 2;

	m2(2, 0) = 1;
	m2(2, 1) = 2;
	m2(2, 2) = 3;

	m1.minus(m2, output);

	cout << "\nResult of Matrix_Minus \n";
	for (unsigned int i = 0; i < output.size1(); i++) {
		for (unsigned int j = 0; j < output.size2(); j++)
			std::cout << output(i, j) << "\t";
		cout << endl;
	}
	cout << "Result Over\n ";
}

}
