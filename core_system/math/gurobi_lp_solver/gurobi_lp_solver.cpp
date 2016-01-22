/*
 * lp_gurobi_simplex.hpp
 *
 *  Created on: 03-Sep-2014
 *      Author: amit
 */

#ifndef LP_GUROBI_SIMPLEX_HPP_
#define LP_GUROBI_SIMPLEX_HPP_

#include "core_system/math/gurobi_lp_solver/gurobi_lp_solver.h"
#include <climits>
#include <boost/lexical_cast.hpp>
#include <float.h>
#include "core_system/math/matrix.h"

using namespace std;
//lp_gurobi_simplex::env = GRBEnv();
int gurobi_lp_solver::gurobi_lp_count=0;

gurobi_lp_solver::gurobi_lp_solver() {

	try {
	//	std::cout<<"Hello Gurobi\n";
		gurobi_lp_count++;

		env = new GRBEnv("/home/amit/GurobiOutput.log");	//creating an output log file
		//env = new GRBEnv();
		//GRBEnv env = GRBEnv();
		model = new GRBModel(*env);
		//model->getEnv().set(GRB_IntParam_OutputFlag, 0); //0 to Disable/ 1 to Enable Output of Gurobi
		model->getEnv().set(GRB_IntParam_LogToConsole, 0);
		//model->getEnv().set(GRB_IntParam_OutputFlag, 1); //0 to Disable/ 1 to Enable Output of Gurobi
		//model->getEnv().set(GRB_IntParam_Threads, 0);	//by default 0- for all cores, nProcs for n cores
		//	std::cout<<"Hello 2\n";
		// GRBModel model1 = GRBModel(env);
		// model = new GRBModel(model1);

		number_of_variables = 0;
		number_of_constraints = 0;
		Minimize_Or_Maximize = GRB_MAXIMIZE;	// Default is set to maximize
		//	std::cout<<"Hello 3\n";
	} catch (GRBException &e) {
		cout << "Error code = " << e.getErrorCode() << "   " << e.getMessage()
				<< endl;
	} catch (...) {
		cout << "Exception during optimization" << endl;
	}
}
gurobi_lp_solver::~gurobi_lp_solver() {

	//delete [] variables;	//deleting/destroying all the variables of the Model

	model->terminate();	//terminating a Model
	delete model;		//deleting/destroying a Model
	delete env;
	// free env;
	// cout<<"\nBye Gurobi\n";
}

void gurobi_lp_solver::setConstraints(math::matrix<double> coeff_constraints,
		std::vector<double> bounds, int bound_signs) {
	try {
		number_of_variables = coeff_constraints.size2();
		number_of_constraints = coeff_constraints.size1();

		//double lb = -99999, ub = 99999; 	//DBL_MIN, DBL_MAX
		double lb,ub;
		GRBLinExpr lhsExpr;
		//GRBVar variables[number_of_variables];
		variables = new GRBVar[number_of_variables];
		char sense = GRB_LESS_EQUAL;	//initialise default to <=
// **************** Creating Variables ****************************
		for (unsigned int i = 0; i < number_of_variables; i++) {
			string varName = "X" + boost::lexical_cast<std::string>(i);
			//	std::cout<<"Variable Name = "<<varName<<"\t";
			variables[i] = model->addVar(-DBL_MAX, DBL_MAX, 0.0, GRB_CONTINUOUS, varName);
			//variables[i] = model->addVar(-GRB_INFINITY, GRB_INFINITY, 0.0, GRB_CONTINUOUS, varName);
		}
// **************** Integrate new variables ****************************
		model->update();

// **************** Add constraints ****************************
		for (unsigned int i = 0; i < number_of_constraints; i++) {
			lhsExpr = 0.0;
			for (unsigned int j = 0; j < number_of_variables; j++) {
				//cout<<"coeff_constraints(i, j) = "<< coeff_constraints(i, j) <<endl;
				lhsExpr += coeff_constraints(i, j) * variables[j];
				//cout<<"lhsExpr = "<< lhsExpr <<endl;
			}
			//	cout<<"\nlhsExpr = "<< lhsExpr <<endl;

			// * GRB_LESS_EQUAL, GRB_EQUAL, or GRB_GREATER_EQUAL
			// * InEqualitySign :	The in equalities sign of the bound values 'b'. Possible values are
			// * 					0 :	for  Ax = b (b Equals to)		FOR FUTURE USE IF ANY
			// * 					1 :	for  Ax <= b (b is Greater Than or Equals to)
			// * 					2 :	for  Ax >= b (b is Less Than or Equals to)

			if (bound_signs == 0)
				sense = GRB_EQUAL;
			else if (bound_signs == 1)
				sense = GRB_LESS_EQUAL;
			else if (bound_signs == 2)
				sense = GRB_GREATER_EQUAL;

			string constraintName = "C" + boost::lexical_cast<std::string>(i);
			//	std::cout << "Constraints Name = " << constraintName <<"\t";
			model->addConstr(lhsExpr, sense, bounds[i], constraintName);
		}
		//	cout << "\nAmit d\n";

	} catch (GRBException &e) {
		cout << "Error code = " << e.getErrorCode() << "   " << e.getMessage()
				<< endl;
	} catch (...) {
		cout << "Exception during optimization" << endl;
	}
}

double gurobi_lp_solver::Compute_LPP(std::vector<double> coeff_function) {
	double res;
	try {
		GRBLinExpr ObjExpr = 0.0;
		GRBVar *vars;	//[number_of_variables];
		vars = model->getVars();
		//	cout << "Checking 1" << "\t";
		for (unsigned int i = 0; i < number_of_variables; i++) {
			//if (coeff_function[i] >= 0)
			ObjExpr += coeff_function[i] * vars[i];
			//else{
			//ObjExpr -= coeff_function[i] * vars[i];
			//	cout<<"Minus is working";
			//}
			//	cout<<"Checking inside loop = "<<i<<"\t";
			//	cout<<"coeff_function[i] = "<<coeff_function[i]<<"\n";
			//ObjExpr += coeff_function[i] * vars[i];
		}
//		cout<<"\nObjExpr = "<< ObjExpr <<endl;

		//cout <<"Minimize_Or_Maximize = "<<Minimize_Or_Maximize<<endl;
		if (Minimize_Or_Maximize == 1)
			model->setObjective(ObjExpr, GRB_MINIMIZE);
		else
			model->setObjective(ObjExpr, GRB_MAXIMIZE);
//		cout << "\nPrinting Object Expression before Optimize call = "<< ObjExpr << "\n";
//	cout<<"\nChecking before Optimize call"<<"\n";
		model->optimize();
		Maximizing_Variables.resize(number_of_variables);
		for (unsigned int i = 0; i < number_of_variables; i++) {
			//cout << Maximizing_Variables[i] << "\t";
			//	cout<<"RAJ Name = "<< vars[i].get(GRB_StringAttr_VarName)<<"\t";cout<<vars[i].get(GRB_DoubleAttr_X)<<endl;
			Maximizing_Variables[i] = vars[i].get(GRB_DoubleAttr_X);
			//cout << Maximizing_Variables[i] << "\t";
		}

		res = model->get(GRB_DoubleAttr_ObjVal);

	} catch (GRBException &e) {
		cout << "Error code = " << e.getErrorCode() << "   " << e.getMessage()
				<< endl;
	} catch (...) {
		cout << "Exception during optimization" << endl;
	}
	return res;
}

/*
void gurobi_lp_solver::setObjective(std::vector<double> coeff_function) {

	try {
		GRBLinExpr ObjExpr = 0.0;
		GRBVar *vars;	//[number_of_variables];
		vars = model->getVars();
		for (unsigned int i = 0; i < number_of_variables; i++) {
			ObjExpr += coeff_function[i] * vars[i];
		}

		if (Minimize_Or_Maximize == 1)
			model->setObjective(ObjExpr, GRB_MINIMIZE);
		else
			model->setObjective(ObjExpr, GRB_MAXIMIZE);

	} catch (GRBException &e) {
		cout << "Error code = " << e.getErrorCode() << "   " << e.getMessage()
				<< endl;
	} catch (...) {
		cout << "Exception during optimization" << endl;
	}

}

double gurobi_lp_solver::Solve_LP() {
	double res;
	try {

		model->optimize();

		res = model->get(GRB_DoubleAttr_ObjVal);

	} catch (GRBException &e) {
		cout << "Error code = " << e.getErrorCode() << "   " << e.getMessage()
				<< endl;
	} catch (...) {
		cout << "Exception during optimization" << endl;
	}
	return res;
}
*/

void gurobi_lp_solver::setIteration_Limit(int limits) {
	model->getEnv().set(GRB_DoubleParam_IterationLimit, limits);//default is GRB_INFINITY
}

void gurobi_lp_solver::setMin_Or_Max(int Min_Or_Max) {
	Minimize_Or_Maximize = Min_Or_Max;
}
int gurobi_lp_solver::getMin_Or_Max() {
	return Minimize_Or_Maximize;
}

void gurobi_lp_solver::setInitial_SimplexControlParameters() {
	model->reset();
}
unsigned int gurobi_lp_solver::getStatus() {
	unsigned int status = 0;
	status = model->get(GRB_IntAttr_Status);
	return status;
}

unsigned int gurobi_lp_solver::TestConstraints() {
	GRBLinExpr ObjExpr = 0.0;
	GRBVar *vars;	//[number_of_variables];
	vars = model->getVars();

	for (unsigned int i = 0; i < number_of_variables; i++) {
		ObjExpr += 0.0 * vars[i];	//setting Object Function to zero
	}

	if (Minimize_Or_Maximize == 1)
		model->setObjective(ObjExpr, GRB_MINIMIZE);
	else
		model->setObjective(ObjExpr, GRB_MAXIMIZE);
//		cout << "\nPrinting Object Expression before Optimize call = "<< ObjExpr << "\n";
//	cout<<"\nChecking before Optimize call"<<"\n";
	model->optimize();
	return model->get(GRB_IntAttr_Status);
}

#endif /* LP_GUROBI_SIMPLEX_HPP_ */
