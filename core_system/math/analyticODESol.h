/*
 * analyticODESol.h
 *
 *  Created on: 06-Sep-2016
 *      Author: rajarshi
 */

#ifndef ANALYTICODESOL_H_
#define ANALYTICODESOL_H_

#include <vector>
#include "application/DataStructureDirections.h"

/*
 * Returns the solution of an ODE of the form X' = A*X+b at some time
 */
std::vector<double> ODESol(std::vector<double> x0, const Dynamics& D, double time);
math::matrix<double> ODESol_homogenous_coeff(const Dynamics& D, double time);
std::vector<double> ODESol_inhomogenous(const Dynamics& D, double time);

/*
 * compute the expression A^-1 (e^At - I) alternatively as a sub-matrix of the exp(M), as shown in the SpaceEx paper, page 8, phi_1.
 */
math::matrix<double> time_slice_component(math::matrix<double>& A, double time);

#endif /* ANALYTICODESOL_H_ */
