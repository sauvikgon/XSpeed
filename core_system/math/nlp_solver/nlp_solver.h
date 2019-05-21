/*
 * nlp_solver.h
 *
 *  Created on: 06-Oct-2017
 *      Author: amit
 */

#ifndef NLP_SOLVER_H_
#define NLP_SOLVER_H_


#include "core_system/continuous/Polytope/Polytope.h"
#include <nlopt.hpp>
#include <math.h>
#include <vector>
#include <cassert>

//extern nlopt::opt minopt;
//extern int count;

/**
 * Structure to hold linear constraints
 */
struct polyConstraints {
	std::vector<double> a;
	double b;
};

// Need to pass polytope to the NLP objective function. Making a struct for that
struct nlp_data
{
	polytope::ptr consPoly;
};

/**
 * Objective function of internal minimize NLP
 */
double myObjFunc(const std::vector<double> &y, std::vector<double> &grad, void *my_func_data);

/*
 * Setting the constraints to NLP
 */
double myLinearConstraint(const std::vector<double> &x, std::vector<double> &grad, void *data);

/**
 * Computes the Housdorff Distance between two polytopes
 */
double computeNLP(polytope::ptr Y, std::vector<double>& x);

void printStatus(nlopt::result status);


#endif /* NLP_SOLVER_H_ */
