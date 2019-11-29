/*
 * directionalApproxError.h
 *
 *  Created on: 14-Oct-2017
 *      Author: amit
 */

#ifndef DIRECTIONALAPPROXERROR_H_
#define DIRECTIONALAPPROXERROR_H_

#include "application/sf_utility.h"
#include <nlopt.hpp>
#include <math.h>
#include <vector>
#include <cassert>
#include "../core/continuous/Polytope/Polytope.h"

extern nlopt::opt optProb1;

/*
 * Utility to compute Directional Approximation Error: \epsilon_[X,X'] = max_{\ell \in \Reals^n} abs { \rho_X (\ell)  - \rho_X' (\ell) }
 * where X is the exact given convex set whose vertices is to be enumerated and X' is the convex set with vertices (v1,v2, ... ,vn) computed using
 * our vertex enumeration by planar projection algorithm.
 * The above result converge to Hausdorff Distance between X and X'
 *
 * \epsilon_[X,X'] (\ell) = max_{\ell \in \Reals^n} abs { \rho_X (\ell)  - \rho_X' (\ell) }
 * or
 * max abs { \rho_X (\ell)  - \rho_X' (\ell) }
 * subject to:
 * ||\ell||_2 = 1 (unit direction)
 * i.e.,
 * x^2 + y^2 = 1
 *
 */



/**
 * Structure to hold linear constraints
 */
struct polyConstraints {
	std::vector<double> a;
	double b;
};

// Need to pass list of vertices to the NLP objective function. Making a struct for that
struct nlp_VertexData
{
	std::list<std::vector<double> > v_list;
};


void printErrorStatus(int status);

double LinearHalfSpaceConstraint(const std::vector<double> &x, std::vector<double> &grad, void *data);

double myMainObjFunc(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data);

double myobjfuncProb1(const std::vector<double> &x, std::vector<double> &grad,
		void *my_func_data);

double UnitSphereConstraint(const std::vector<double> &x, std::vector<double> &grad,
		void *data);

double getSolution(polytope::ptr X, std::list<std::vector<double> > X2);

double ApproxError(polytope::ptr X1, std::list<std::vector<double> > X2);


#endif /* DIRECTIONALAPPROXERROR_H_ */
