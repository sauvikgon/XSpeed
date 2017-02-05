/*
 * lp_solver.h
 *
 *  Created on: 11-Feb-2015
 *      Author: amit
 */

// **** change the file name of glpk_lp_solver to avoid conflict with lp_solver.h *********
#ifndef LP_SOLVER_H_
#define LP_SOLVER_H_


#include "core_system/math/glpk_lp_solver/glpk_lp_solver.h"
#include "core_system/math/lp_solver/All_Solver_Definition.h"
//#include "core_system/math/gurobi_lp_solver/gurobi_lp_solver.h"
#include "core_system/math/Simplex_CPU/simplex_CPU.h"

// have to include the path :: /opt/gurobi600/linux64/include
#include <boost/shared_ptr.hpp>

class lp_solver {
public:
	typedef boost::shared_ptr<lp_solver> lp_solver_ptr;
	lp_solver();	//default constructor with type of lp_solver as glpk
	lp_solver(int solver_type);	//constructor decide the type of lp_solver to be created glpk/gurobi/par_simplex/Gimplex/etc
	~lp_solver();
	//  ****** Main Functions **********
	void setConstraints(math::matrix<double> coeff_constraints,
			std::vector<double> bounds, int bound_signs);
	/**
	 * Adds the variables and constraints of the polytope to the current LP problem.
	 * Note that this function is different from just adding constraints since joining
	 * a polytope implies adding its variables as new variables and also adding constraints
	 * on these new variables given as parameters.
	 */
	void join_poly_constraints(math::matrix<double> coeff_constraints, std::vector<double> bounds, int bound_signs);
	/**
	 * Adds n new variables to the lp problem with lower bound as 0
	 */
	void add_variables(int n);
	/**
	 * Adds a new constrain with the problem, in the ax <= b form
	 * len is the number of non-zero entries in the constraint
	 * ind is the array of column indices of the coefficient in the lp coeff matrix
	 * val is the corresponding array of values of the coefficient matrix
	 */
	void add_new_constraint(int len, int ind[], double val[]);
	/*
	 * Gets the optimal value of the variable, after solving the lp, having the index passed as parameter
	 */
	double get_col_val(int i);
	void setMin_Or_Max(int Min_Or_Max);

	/**
	 * Sets the coefficient of the objective function
	 */
	void set_obj_coeff(unsigned int j, double val);

	/*
	 * Returns the coefficient of the column variable with index j
	 */
	double get_obj_coeff(unsigned int j);
	/**
	 * Solve the LP w.r.t the objective function thas is set already
	 */
	double solve();
	double Compute_LLP(std::vector<double> coeff_function);

	//returns the vector/point that gives the maximum value
	std::vector<double> get_sv();
	//  ****** Extra Functions **********
	int getMin_Or_Max();
	void setIteration_Limit(int limits);
	void setInitial_SimplexControlParameters();	//reset to default parameters
	unsigned int getStatus();
	unsigned int TestConstraints();
	/*
	 * deletes the LP problem
	 */
	void delete_prob();
	void free_environment_glpk_lp_solver();

	int getLP_Solver_Type();

	//   ******** Will be handled later due to absence in gurobi **********
	void displayMaxVariables();
	void free_glpk_lp_solver();
	static int lp_solver_count;

private:
	int lp_solver_type;		//typename glpk_lp_solver::glpk_ptr glpk_lp_problem;

	glpk_lp_solver::glpk_ptr glpk_lp_problem;
//	gurobi_lp_solver::gurobi_ptr gurobi_lp_problem;
	Simplex_CPU::simplex_ptr simplex_cpu_lp_problem;

	//   *********  More Definition of lp solvers can be added when required  ********
};

#endif /* LP_SOLVER_H_ */
