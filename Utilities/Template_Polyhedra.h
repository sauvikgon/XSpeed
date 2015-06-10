/*
 * Template_Polytope.h
 *
 *  Created on: 10-July-2014
 *      Author: amit
 */

#ifndef TEMPLATE_POLYHEDRA_H_
#define TEMPLATE_POLYHEDRA_H_

#include "core_system/math/matrix.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include <list>
#include <vector>

using namespace std;
/*
 * Combination of the matrices All_Directions and Matrix_SupportFunction consists of all the reachable set of only one flow-pipe.
 * getPolytope :
 *
 *
 */

class template_polyhedra {
public:
	template_polyhedra();
	template_polyhedra(math::matrix<double> matrix_support_function,
			math::matrix<double> template_directions);
/*
	template_polyhedra(math::matrix<double> matrix_support_function,
				math::matrix<double> all_directions, math::matrix<double> template_directions, math::matrix<double> invariant_directions);
*/
	template_polyhedra(math::matrix<double> matrix_support_function,
					math::matrix<double> matrix_invariant_bounds, math::matrix<double> template_directions, math::matrix<double> invariant_directions);
	/*const math::matrix<double>& getAllDirections() const;
	void setAllDirections(math::matrix<double>& allDirections);*/
	const math::matrix<double>& getMatrixSupportFunction() const;
	void setMatrixSupportFunction(math::matrix<double>& matrixSupportFunction);
	const math::matrix<double>& getTemplateDirections() const;
	void setTemplateDirections(math::matrix<double>& template_Directions);
	const math::matrix<double>& getInvariantDirections() const;
	void setInvariantDirections(math::matrix<double>& invariant_Directions);

	const math::matrix<double>& getMatrix_InvariantBound() const;
	void setMatrix_InvariantBound(math::matrix<double>& matrix_invariantBound);



	/*
	 * Returns a single polytope set Omega(i) where i represent the Iteration number or the Column number of the Matrix_SupportFunction.
	 * Note:: the Index of i begins from 0 to i-1 just like the concept of Array.
	 */
	polytope getPolytope(unsigned int Iterations_Number);

	/*
	 * From the calling template_polyhedra or the entire reachable set of a single trajectory of a continuous system,
	 * a subset of the reachable set is returned which intersects with the guard region.
	 * Thus it returns a template_polyhedra consisting of a subset of the reachable set which intersects with the guard region.
	 * As there could be multiple intersected region, so it returns a list of intersected region, each
	 * elements of the list is a intersected region.
	 */
	const std::list<template_polyhedra> polys_intersection(polytope::ptr gaurd, int lp_solver_type_choosen);	//, int & point_of_intersection);
	/*
	 * Returns a new Polytope which is the common intersected Region between the templated_polyhedra and the guard_polytope
	 * polytope getIntersectedRegion(polytope gaurd);
	 */

	/*
	 * From the calling TEMPLATE_POLYHEDRA a SINGLE POLYTOPE is returned.
	 * Thus, it is a BIGGER approximation (Bigger Convex Set of a set of Convex Sets) region of the calling
	 * TEMPLATE_POLYHEDRA and returning a SINGLE POLYTOPE.
	 */
	const polytope::ptr getTemplate_approx(int lp_solver_type_choosen);

	/*
	 *	Returns the union of the template_polyhedra Tpoly and the calling template_polyhedra object
	 *	Description :
	 *		: Appending all the matrixSupportFunction of Tpoly with the matrixSupportFunction of the calling object
	 *		: Appending should be done column by column from Tpoly onto the calling object
	 */
	template_polyhedra union_TemplatePolytope(template_polyhedra& Tpoly);

	unsigned int getTotalIterations() const;
	//unsigned int getTotalDirections() const;
	unsigned int getTotalTemplateDirections() const;
	unsigned int getTotalInvariantDirections() const;

	std::vector<double> getInvariantBoundValue(int iterations_number);
	void resize_matrix_SupportFunction(int dir_nums,
			int iterations_before_intersection);
private:
	/*polytope*/
	math::matrix<double> Matrix_SupportFunction;	//Note if it has invariants_dirs then Matrix_SupportFunction will also have bound_value
	math::matrix<double> template_Directions;	//only the template directions

/* This  (Matrix_InvariantBound,invariant_Directions) will be replaced with my structure idea later */
	math::matrix<double> Matrix_InvariantBound;	//Note now Matrix_SupportFunction will NOT have the bound_value
//	math::matrix<double> All_Directions;//Number of Rows or facets of the Convex Set/Polytoe including the invariants(template_dirs + invariant_dirs)
	math::matrix<double> invariant_Directions;	//only the invariant directions


	//unsigned int total_Directions;	//Number of rows or the number of faces/constraints of the Convex Set/Polytoe Omega's
	unsigned int total_template_Directions;	//total number of template directions
	unsigned int total_invariant_Directions;	//total number of invariant directions
	unsigned int total_iterations;	//Number of Columns or the number of Convex Set/Polytoe Omega's
	void setTotalIterations(unsigned int totalIterations);
	//void setTotalDirections(unsigned int totalDirections);
	void setTotalTemplateDirections(unsigned int total_template_directions);
	void setTotalInvariantDirections(unsigned int total_invariant_directions);

};

#endif /* TEMPLATE_POLYHEDRA_H_ */
