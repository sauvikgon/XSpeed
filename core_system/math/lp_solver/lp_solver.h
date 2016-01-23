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
	lp_solver(int solver_type);	//constructor decide the type of lp_solver to be created glpk/gurobi/par_simplex/Gimplex/etc
	~lp_solver();
	//  ****** Main Functions **********
	void setConstraints(math::matrix<double> coeff_constraints,
			std::vector<double> bounds, int bound_signs);
	void setMin_Or_Max(int Min_Or_Max);
	double Compute_LLP(std::vector<double> coeff_function);

	//returns the vector/point that gives the maximum value
	std::vector<double> get_sv();
	//  ****** Extra Functions **********
	int getMin_Or_Max();
	void setIteration_Limit(int limits);
	void setInitial_SimplexControlParameters();	//reset to default parameters
	unsigned int getStatus();
	unsigned int TestConstraints();
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
