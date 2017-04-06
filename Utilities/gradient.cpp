/*
 * gradient.cpp
 *
 *  Created on: 18-Aug-2016
 *      Author: rajarshi
 */

#include <Utilities/gradient.h>

/*
 * Computes derivative of distance of a vector to a polytope w.r.t the vector.
 * The definition of point to polytope distance is as defined in the
 * polytope.cpp class implementation
 */
std::vector<double> dist_grad(std::vector<double> trace_end_pt, polytope::ptr I)
{
	if(I->getIsUniverse() || I->getIsEmpty())
		return std::vector<double>(trace_end_pt.size(),0);

	std::vector<double> grad(trace_end_pt.size(),0 );

	math::matrix<double> C = I->getCoeffMatrix();
	std::vector<double> b = I->getColumnVector();

	assert(trace_end_pt.size() == C.size2());
	assert(I->getInEqualitySign() == 1);

	double facet_distance = 0;
	double coef_sq_sum = 0;
	double dist = 0;
	for(unsigned int i=0;i<C.size1();i++){
		for(unsigned int j=0;j<C.size2();j++){
			facet_distance += trace_end_pt[j]*C(i,j);
			coef_sq_sum += C(i,j)*C(i,j);
		}
		double denom = coef_sq_sum;
		facet_distance -=b[i];
		if(facet_distance > 0){
			for(unsigned int k=0;k<grad.size();k++){
				grad[k] += C(i,k)/denom;
			}
			dist += facet_distance/coef_sq_sum;
		}
		coef_sq_sum = 0;
		facet_distance = 0;
	}
	// modified gradient after squaring the distance of point to poly
	for(unsigned int i=0;i<grad.size();i++){
		grad[i] = grad[i] * 2 * dist;
	}
	return grad;
}

struct myparam{
	double *array;
	unsigned int size;
	polytope::ptr I;
	unsigned int x_index;
};

double f(double x, void *p)
{
	myparam* param = (struct myparam *) (p);
	std::vector<double> y(param->size);
	for(unsigned int i=0;i<y.size();i++)
	{
		y[i] = param->array[i];
	}
	double val;
	polytope::ptr polyI = param->I;
	y[param->x_index] = x;
	val = polyI->point_distance(y);
	return val;
}
/*
 * Computes derivative of vector (x) to polytope distance d w.r.t x.
 * The derivative is computed numerically using the gsl library.
 */

std::vector<double> dist_grad_numeric(std::vector<double> x, polytope::ptr I)
{
	if(I->getIsUniverse() || I->getIsEmpty())
		return std::vector<double>(x.size(),0);

	std::vector<double> grad(x.size(),0 );
	double h = 1e-12;
	gsl_function F;

	double res, abs_err;
	double array_x[x.size()];
	for(unsigned int j=0;j<x.size();j++)
		array_x[j] = x[j];

	myparam p;
	p.array = &array_x[0];
	p.size = x.size();
	p.I = I;

	for(unsigned int k=0;k<x.size();k++){
		p.x_index = k;
		F.function = f;
		F.params = &p;
		gsl_deriv_central(&F,x[k],h, &res, &abs_err);
		grad[k] = res;
	}

	return grad;
}
