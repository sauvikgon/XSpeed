/*
 * lp_solver.cpp
 *
 *  Created on: 11-Feb-2015
 *      Author: amit
 */

// **** change the file name of glpk_lp_solver to avoid conflict with lp_solver.cpp *********
#include "core_system/math/lp_solver/lp_solver.h"
#include "core_system/math/lp_solver/All_Solver_Definition.h"

int lp_solver::lp_solver_count = 0;
lp_solver::lp_solver(int solver_type) {

	lp_solver_count++; //one instance of either glpk or gurobi object is created

	lp_solver_type = solver_type;

	if (lp_solver_type == GLPK_SOLVER) {
		glpk_lp_problem = glpk_lp_solver::glpk_ptr(new glpk_lp_solver());
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		gurobi_lp_problem = gurobi_lp_solver::gurobi_ptr(
				new gurobi_lp_solver());
	}
*/
	if (lp_solver_type == SIMPLEX_CPU_SOLVER) {
		simplex_cpu_lp_problem = Simplex_CPU::simplex_ptr(new Simplex_CPU());
	}

	// ******* More can be added later  **************
}
lp_solver::~lp_solver() {
	;
}

void lp_solver::setMin_Or_Max(int Min_Or_Max) {

	if (lp_solver_type == GLPK_SOLVER) {
		glpk_lp_problem->setMin_Or_Max(Min_Or_Max);
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		gurobi_lp_problem->setMin_Or_Max(Min_Or_Max);
	} */
	// ******* More can be added later  **************
}

void lp_solver::setConstraints(math::matrix<double> coeff_constraints,
		std::vector<double> bounds, int bound_signs) {

	if (lp_solver_type == GLPK_SOLVER) {
		glpk_lp_problem->setConstraints(coeff_constraints, bounds, bound_signs);
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		gurobi_lp_problem->setConstraints(coeff_constraints, bounds,
				bound_signs);
	} */
	if (lp_solver_type == SIMPLEX_CPU_SOLVER) {
		simplex_cpu_lp_problem->setConstratint_CPU(coeff_constraints, bounds);
	}

	// ******* More can be added later  **************
}

double lp_solver::Compute_LLP(std::vector<double> coeff_function) {
	double res = 0.0;
	if (lp_solver_type == GLPK_SOLVER) {
		res = glpk_lp_problem->Compute_LLP(coeff_function);
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		res = gurobi_lp_problem->Compute_LPP(coeff_function);
	} */
	if (lp_solver_type == SIMPLEX_CPU_SOLVER) {
		res = simplex_cpu_lp_problem->ComputeLP_CPU(coeff_function);
	}
	return res;
}
/**
 * Return the support vector,i.e., the maximimizing/minimizing
 * vector for the given objection function
 */
std::vector<double> lp_solver::get_sv() {
	std::vector<double> Maximum_point;
	if (lp_solver_type == GLPK_SOLVER) {
		Maximum_point = glpk_lp_problem->getMaximizing_Variables();
	}
	/*
	if (lp_solver_type == GUROBI_SOLVER) {
	//	Maximum_point = gurobi_lp_problem->getMaximizing_Variables();
	}*/
	if (lp_solver_type == SIMPLEX_CPU_SOLVER) {
		//Maximum_point = simplex_cpu_lp_problem->getMaximizing_Variables();
	}
	return Maximum_point;
}

int lp_solver::getMin_Or_Max() {
	int res = 2;
	if (lp_solver_type == GLPK_SOLVER) {
		res = glpk_lp_problem->getMin_Or_Max();
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		res = gurobi_lp_problem->getMin_Or_Max();
	} */
	return res;

}

void lp_solver::setIteration_Limit(int limits) {
	if (lp_solver_type == GLPK_SOLVER) {
		glpk_lp_problem->setIteration_Limit(limits);
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		gurobi_lp_problem->setIteration_Limit(limits);
	}*/
}

void lp_solver::setInitial_SimplexControlParameters() {
	if (lp_solver_type == GLPK_SOLVER) {
		glpk_lp_problem->setInitial_SimplexControlParameters();
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		gurobi_lp_problem->setInitial_SimplexControlParameters();
	} */
}

unsigned int lp_solver::getStatus() {
	unsigned int status = 5, glpk_status = 5, gurobi_status = 2;
	if (lp_solver_type == GLPK_SOLVER) {
		glpk_status = glpk_lp_problem->getStatus();
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		gurobi_status = gurobi_lp_problem->getStatus();
	} */

	// ******* I have to return a uniform meaning for the status returned by Gurobi and GLPK  *****
	/*
	 * Meaning					Common_Retun_Code 	GLPK_Code	Gurobi_Code
	 * Solution is Undefined			1				1
	 * Solution is feasible				2				2
	 * Solution is Infeasible			3				3			3
	 * no feasible Solution Exists		4				4
	 * Solution is Optimal				5				5			2
	 * Solution is unbounded			6				6			5
	 */

	if (lp_solver_type == GLPK_SOLVER) {
		status = glpk_status;
	}
	/*
	if (lp_solver_type == GUROBI_SOLVER) {
		if (gurobi_status == 3) {
			status = 3; //	Solution is Infeasible
		}
		if (gurobi_status == 2) {
			status = 5; //Solution is Optimal
		}
		if (gurobi_status == 5) {
			status = 6; //solution is unbounded
		}
	} */
	return status;
}
unsigned int lp_solver::TestConstraints() {
	//unsigned int status=0;
	unsigned int status = 5, glpk_status = 5, gurobi_status = 2;

	if (lp_solver_type == GLPK_SOLVER) {
		glpk_status = glpk_lp_problem->TestConstraints();
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		gurobi_status = gurobi_lp_problem->TestConstraints();
	} */

	// ******* I have to return a uniform meaning for the status returned by Gurobi and GLPK  *****
	if (lp_solver_type == GLPK_SOLVER) {
		status = glpk_status;
	}
/*
	if (lp_solver_type == GUROBI_SOLVER) {
		if (gurobi_status == 3) {
			status = 3; //	Solution is Infeasible
		}
		if (gurobi_status == 2) {
			status = 5; //Solution is Optimal
		}
		if (gurobi_status == 5) {
			status = 6; //solution is unbounded
		}
	} */
	return status;
}

void lp_solver::free_environment_glpk_lp_solver() {
	if (lp_solver_type == GLPK_SOLVER) {
		glpk_lp_problem->free_environment_glpk_lp_solver();
	}
	if (lp_solver_type == GUROBI_SOLVER) {
		//gurobi_lp_problem->need to be created;
	}
}

int lp_solver::getLP_Solver_Type() {
	return lp_solver_type;
}

