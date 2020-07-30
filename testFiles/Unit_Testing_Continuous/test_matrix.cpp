/*
 * test_matrix.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include <string>

#include "core/continuous/polytope/polytope.h"
#include "core/math/matrix.h"

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
		math::matrix<double> mat_res = math::matrix<double>();
		m.transpose(mat_res);
		float output2[2][2];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				output2[i][j]=mat_res(i, j);
		}

		out << mat_res;
		const float res2[2][2]={{1,3},{2,4}};
		CHECK_ARRAY2D_CLOSE(res2, output2, 2, 2, 0.0);
	}
	TEST_FIXTURE(templated_matrix_class, inf_norm_Test) {
		//math::matrix<double> res = math::matrix<double>();
		double val = m.norm_inf();
		double res = 7;

		CHECK_EQUAL(val, res);

		m(0, 0) = 0;
		m(0, 1) = -1;
		m(1, 0) = 0;
		m(1, 1) = 0;

		double output = m.norm_inf();
		res = 1;
		CHECK_EQUAL(res, output);
	}
	TEST_FIXTURE(templated_matrix_class, mult_vector_Test) {
		m.mult_vector(dir, res);
		std::vector<double> r(2);
		r[0]=3;
		r[1]=5;
		CHECK_ARRAY_EQUAL(r, res, res.size());

	}
	TEST_FIXTURE(templated_matrix_class, exponentiationTest) {
		math::matrix<double> mat_res = math::matrix<double>();
		m(0, 0) = 0;
		m(0, 1) = -1;
		m(1, 0) = 0;
		m(1, 1) = 0;
		m.matrix_exponentiation(mat_res);
		float output1[2][2];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				output1[i][j]=mat_res(i, j);

		}
		out<< mat_res;
		const float res[2][2]={{1,-1},{0,1}};
		CHECK_ARRAY2D_CLOSE(res, output1, 2, 2, 0.0);

	}
	TEST_FIXTURE(templated_matrix_class, tau_exponentiationTest) {
		math::matrix<double> mat_res = math::matrix<double>();
		double tau = 2;
		m.matrix_exponentiation(mat_res, tau);

		double output[2][2];

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				output[i][j] = mat_res(i, j);

		const double res2d[2][2] = {{11079.1, 16146.3}, {24219.4, 35298.5}};


		CHECK_ARRAY2D_CLOSE(res2d,output,2,2,0.1);

	}
	TEST_FIXTURE(templated_matrix_class, matrix_copy_Test) {
		row = 2;
		col = 2;
		math::matrix<double> m(row, col), dest;
		m(0, 0) = 1;
		m(0, 1) = 2;
		m(1, 0) = 3;
		m(1, 1) = 4;
		m.matrix_copy(dest);
		float output2D[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				output2D[i][j]=dest(i, j);
			}
		}
		out<< dest;
		float res1[2][2]={{1,2},{3,4}};
		CHECK_ARRAY2D_CLOSE(res1, output2D, 2, 2, 0.0);

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
		float output3[4][2];
		for (unsigned int i = 0; i < joined_matrix.size1(); i++)
		{
			for (unsigned int j = 0; j < joined_matrix.size2(); j++)
				output3[i][j]=joined_matrix(i, j);

		}
		out<< joined_matrix;
		const float res4[4][2]={{1,2},{3,4},{55,66},{77,88}};
		CHECK_ARRAY2D_CLOSE(res4, output3, 4, 2, 0.0);
	}

	TEST_FIXTURE(templated_matrix_class, matrix_inverse_Test) {
		row = 2;
		col = 2;
		math::matrix<double> input(row, col);
		math::matrix<double> invMat(row, col);
		input(0, 0) = -0.6;
		input(0, 1) = 0;
		input(1, 0) = 0;
		input(1, 1) = 1;

		bool NonSingular = input.inverse(invMat); //Return Ture if Inverse Exists else False
		if (NonSingular)
			out << "Is NOT a Singular Matrix";
		else
			out << "Is a Singular Matrix";

		proper << "Is NOT a Singular Matrix";
		CHECK_EQUAL(proper.str(), out.str());
	}

	TEST_FIXTURE(templated_matrix_class, matrix_Multiply_Test) {

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
		float output5[3][3];
		// Result of Matrix_Multiply
		for (unsigned int i = 0; i < output.size1(); i++)
		{
			for (unsigned int j = 0; j < output.size2(); j++)
			 output5[i][j]=output(i, j);
		}
		out<< output;
		const float res5[3][3]={{8,14,14},{20,35,32},{32,56,50}};
		CHECK_ARRAY2D_CLOSE(res5, output5, 3, 3, 0.0);
	}
}
