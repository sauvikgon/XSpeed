/*
 * io_utility.h
 *
 *  Created on: 19-Jan-2016
 *      Author: amit
 */

#ifndef IO_UTILITY_H_
#define IO_UTILITY_H_

#include <vector>
#include <list>
#include <utility>

#include "../core/continuous/Polytope/polytope.h"
#include "application/userOptions.h"
#include <fstream>

#include <iostream>

#include "../core/math/2d_geometry.h"
#include "../core/math/glpk_lp_solver/glpk_lp_solver.h"
#include "../core/math/point/point.h"
#include "../core/symbolic_states/initial_state.h"
#include "../core/symbolic_states/symbolic_states.h"
#include "../utilities/vector_operations.h"
#include "../utilities/vector_operations.h"




typedef std::vector<std::pair<double, double> > Intervals;

/**
 * Outputs the result in Interval form, for the system var with dimension d
 */
void interval_generator(std::list<symbolic_states::ptr>& symbolic_states_list, unsigned int d);

/*
 * Outputs the result in vertex enumerated form
 */
void vertex_generator(std::list<symbolic_states::ptr>& symbolic_states_list, userOptions user_ops);

/**
 * Computes the template hull of the template polyhedra, by merging the polytopes between the start and end columns, including them.
 */
polytope::ptr get_template_hull(template_polyhedra::ptr sfm, unsigned int start, unsigned int end);

/**
 *	Outputs the bounds on all system dimension.
 */
void print_all_intervals(std::list<symbolic_states::ptr>& symbolic_states_list);

std::list<MyPoint::ptr> enumBySequentialSampling(math::matrix<double>& A, std::vector<double>& b, int dim1, int dim2, double delta);

/*
 * Outputs the result in vertex enumerated form using our new algorithm using Hough Transformation
 */
void vertex_generator_HoughTransformation(std::list<symbolic_states::ptr>& symbolic_states_list, userOptions user_ops);

void SFM_for_MatLab(std::list<symbolic_states::ptr>& symbolic_states_list, userOptions user_options);

/**
 * The top-level output method where selection of the algorithm to output result
 * takes place.
 */
void show(std::list<symbolic_states::ptr>& symbolic_states_list, userOptions user_options);

#endif /* IO_UTILITY_H_ */

