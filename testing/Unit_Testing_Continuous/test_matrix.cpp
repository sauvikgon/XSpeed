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

SUITE(templated_matrix_class_TestSuite) {
struct templated_matrix_class {
	templated_matrix_class() {
		// create a direction
		dir.resize(2);
		dir[0] = -1;
		dir[1] = 2;

		// create a matrix
		row = 2;
		col = 2;
		m = math::matrix<double>(row, col);
		m(0, 0) = 1;
		m(0, 1) = 2;
		m(1, 0) = 3;
		m(1, 1) = 4;

		m2 = math::matrix<double>(row, col);
		m2(0, 0) = 2;
		m2(0, 1) = 4;
		m2(1, 0) = 6;
		m2(1, 1) = 8;

		res.resize(2);

	}
	~templated_matrix_class() { /* some teardown */
	}

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	std::vector<double> dir;
	std::vector<double> res;
	math::matrix<double> m;
	math::matrix<double> m2;
	stringstream out, proper;
};

TEST_FIXTURE(templated_matrix_class, transpose_Test) {
	math::matrix<double> res = math::matrix<double>();
	m.transpose(res);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cout << res(i, j) << "\t";
		cout << endl;
	}
	//out << val;
	//proper << "4";
	//CHECK_EQUAL(proper.str(),out.str());
}
TEST_FIXTURE(templated_matrix_class, inf_norm_Test) {
	//math::matrix<double> res = math::matrix<double>();
	double val = m.norm_inf();

	out << val;
	proper << "4";
	CHECK_EQUAL(proper.str(), out.str());

	m(0, 0) = 0;
	m(0, 1) = -1;
	m(1, 0) = 0;
	m(1, 1) = 0;
	out << "";
	proper << "";
	out << m.norm_inf();
	proper << "1";
	CHECK_EQUAL(proper.str(), out.str());
}
TEST_FIXTURE(templated_matrix_class, mult_vector_Test) {
	m.mult_vector(dir, res);
	cout << "\nResult = ";
	for (int i = 0; i < 2; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	/*
	 proper << "3 5";
	 CHECK_EQUAL(proper.str(),out.str());*/
}
TEST_FIXTURE(templated_matrix_class, exponentiationTest) {
	math::matrix<double> res = math::matrix<double>();
	m(0, 0) = 0;
	m(0, 1) = -1;
	m(1, 0) = 0;
	m(1, 1) = 0;
	m.matrix_exponentiation(res);
	std::cout << "tester matrix expo output\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			std::cout << res(i, j) << "\t";
		cout << endl;
	}
	//51.9690   74.7366
	// 112.1048  164.0738
	//	proper << "[3,0,-1,2,3,-6]";
	//	CHECK_EQUAL(proper.str(),out.str());
}
TEST_FIXTURE(templated_matrix_class, tau_exponentiationTest) {
	math::matrix<double> res = math::matrix<double>();
	double tau = 2;
	m.matrix_exponentiation(res, tau);

	//m2.matrix_exponentiation(res);

	cout << "\nResult of m = exp(m,tau) = \n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			std::cout << res(i, j) << "\t";
		cout << endl;
	}
	cout << "Result Over\n ";

	/*		11079.1	16146.3
	 24219.4	35298.5*/
	//	proper << "[3,0,-1,2,3,-6]";
	//	CHECK_EQUAL(proper.str(),out.str());
}
TEST_FIXTURE(templated_matrix_class, matrix_copy_Test) {
	//math::matrix<double> res = math::matrix<double>();
	row = 2;
	col = 2;
	math::matrix<double> m(row, col), dest;
	m(0, 0) = 1;
	m(0, 1) = 2;
	m(1, 0) = 3;
	m(1, 1) = 4;
	m.matrix_copy(dest);
	cout << "\nResult of Matrix_Copy function = \n";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << dest(i, j) << "\t";
		}
		cout << endl;
	}
	cout << "Result Over\n ";

	/*	out<<"good";
	 proper << "bad";
	 CHECK_EQUAL(proper.str(),out.str());*/

}
TEST_FIXTURE(templated_matrix_class, matrix_join_Test) {
	//math::matrix<double> res = math::matrix<double>();
	row = 2;
	col = 2;
	math::matrix<double> mat1(row, col);
	math::matrix<double> amit2(row, col);
	math::matrix<double> joined_matrix;
	mat1(0, 0) = 1;
	mat1(0, 1) = 2;
	mat1(1, 0) = 3;
	mat1(1, 1) = 4;

	amit2(0, 0) = 55;
	amit2(0, 1) = 66;
	amit2(1, 0) = 77;
	amit2(1, 1) = 88;

	mat1.matrix_join(amit2, joined_matrix);

	cout << "\nResult of Matrix_Join function = \n";
	for (unsigned int i = 0; i < joined_matrix.size1(); i++) {
		for (unsigned int j = 0; j < joined_matrix.size2(); j++)
			std::cout << joined_matrix(i, j) << "\t";
		cout << endl;
	}
	cout << "Result Over\n ";
	/*
	 out<<"good";
	 proper << "bad";
	 CHECK_EQUAL(proper.str(),out.str());
	 */
}

TEST_FIXTURE(templated_matrix_class, matrix_inverse_Test) {
	//math::matrix<double> res = math::matrix<double>();
	row = 2;
	col = 2;
	math::matrix<double> input(row, col);
	math::matrix<double> invMat(row, col);
/*
	input(0, 0) = 4;
	input(0, 1) = 3;
	input(1, 0) = 2;
	input(1, 1) = 1;
*/
	input(0, 0) = -0.6;
	input(0, 1) = 0;
	input(1, 0) = 0;
	input(1, 1) = 1;


	bool NonSingular = input.inverse(invMat);//Return Ture if Inverse Exists else False
	if (NonSingular) {
		cout << "\nResult of Matrix_Inverse function = \n";
		for (unsigned int i = 0; i < invMat.size1(); i++) {
			for (unsigned int j = 0; j < invMat.size2(); j++)
				std::cout << invMat(i, j) << "\t";
			cout << endl;
		}
	} else
		cout << "It is a Singular Matrix!!!\n";

	cout << "Result Over\n ";







}
TEST_FIXTURE(templated_matrix_class, matrix_Multiply_Test) {
	//math::matrix<double> res = math::matrix<double>();
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

	m1.multiply(m2, output);

	cout << "\nResult of Matrix_Multiply \n";
	for (unsigned int i = 0; i < output.size1(); i++) {
		for (unsigned int j = 0; j < output.size2(); j++)
			std::cout << output(i, j) << "\t";
		cout << endl;
	}
	cout << "Result Over\n ";
}

}
