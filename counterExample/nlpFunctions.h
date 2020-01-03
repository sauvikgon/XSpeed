/*
 * nlpFunctions.h
 *
 *  Header file with the required functions to call NLP solver: NLOPT
 *  Created on: 25-Sep-2016
 *      Author: rajarshi
 */

#ifndef NLP_FUNC_H
#define NLP_FUNC_H


#include "../core/math/matrix.h"
#include "../application/DataStructureDirections.h"

#define VALIDATION


struct polyConstraints {
	std::vector<double> a;
	double b;
	unsigned int sstate_index;
};

struct boundConstriant {
	double bound;
	unsigned int var_index;
	bool is_ge; // to mark if bound is a >= constraint
};

/**
 * Objective function for splicing with HA constraints only. (Sriram et. al.)
 */
double myobjfunc1(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

/**
 * Objective function for splicing with Flowpipe constraints
 *  only. (Sergiy's Idea)
 */
double myobjfunc2(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

/**
 * Objective function for splicing with iterative NLP-LP. (Goran's Idea)
 */
double myobjfunc3(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

double myconstraint(const std::vector<double> &x, std::vector<double> &grad, void *data);

double myBoundConstraint(const std::vector<double> &x, std::vector<double> &grad, void *data);


double myobjfuncOnDwellTime(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

double myobjfuncOnStateVars(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

//Object function for splicing with Iterative LP-NLP
double myobjfuncIterativeNLP(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);


std::vector<double> firstprinciple(std::vector<double> x, Dynamics D, double time, double delta_h);

#endif /* nlpFunctions.h */
