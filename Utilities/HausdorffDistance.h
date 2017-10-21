/*
 * HousdorffDistance.h
 *
 *  Created on: 19-Sep-2017
 *      Author: rajarshi
 */

#ifndef HAUSDORFFDISTANCE_H_
#define HAUSDORFFDISTANCE_H_

#include "core_system/continuous/Polytope/Polytope.h"
#include <nlopt.hpp>
#include <math.h>
#include <vector>
#include <cassert>

extern nlopt::opt minopt;

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
double myobjfunc3(const std::vector<double> &y, std::vector<double> &grad, void *my_func_data);

/**
 * Outer maximize objective function
 */
double myobjfunc1(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);


/**
 * Computes sup_{x \in X} inf_{y \in Y} dist(x,y), i.e., max of min distances between X and Y
 */
double getDistance(polytope::ptr X, polytope::ptr Y);

/*
 * Setting the constraints to NLP
 */
double myconstraintH(const std::vector<double> &x, std::vector<double> &grad, void *data);

/**
 * Computes the Housdorff Distance between two polytopes
 */
double HausdorffDistance(polytope::ptr X, polytope::ptr Y);

#endif /* HOUSDORFFDISTANCE_H_ */
