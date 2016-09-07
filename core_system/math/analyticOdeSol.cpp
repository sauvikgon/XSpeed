/*
 * analyticOdeSol.cpp
 *
 *  Created on: 06-Sep-2016
 *      Author: rajarshi
 */

#include "analyticODESol.h"
#include <vector>
#include "core_system/math/matrix.h"

std::vector<double> ODESol(std::vector<double> x0, Dynamics& D, double time)
{
	unsigned int dim = D.MatrixA.size2();

	assert(D.MatrixA.size1() == D.MatrixA.size2());
	assert(x0.size() == D.MatrixA.size2());

	math::matrix<double> expAt(dim,dim);
	math::matrix<double> A(D.MatrixA);

	A.scalar_multiply(time);
	A.matrix_exponentiation(expAt);

	std::vector<double> res1(dim), res2(dim), res3(dim);

	expAt.mult_vector(x0,res1);

	math::matrix<double> AInv(dim,dim);
	A.inverse(AInv);
	std::vector<double> minusV(dim);

	for(unsigned int i=0;i<dim;i++)
		minusV[i] = (-1)*D.C[i];

	AInv.mult_vector(minusV,res2);

	math::matrix<double> mult(dim,dim);

	AInv.multiply(expAt,mult);
	mult.mult_vector(D.C,res3);


	for(unsigned int i=0;i<res1.size();i++){
		res1[i] = res1[i] + res2[i] + res3[i];
	}
//	std::cout << "Analytical Solution of ODE:";
//	for(unsigned int i=0;i<5;i++)
//		std::cout << res1[i] << " " << std::endl;
	return res1;
}


