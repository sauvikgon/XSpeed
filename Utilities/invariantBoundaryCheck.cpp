/*
 * invariantCheck.cpp
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */
#include "invariantBoundaryCheck.h"

unsigned int InvariantBoundaryCheck(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		int lp_solver_type_choosen) {

	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
	int dimension = Initial->getSystemDimension();
	int Min_Or_Max = 2;
	int numberOfInvariants = invariant->getColumnVector().size(); //total number of Invariant's constraints
	std::vector<int> boundaryIterations(numberOfInvariants,
			shm_NewTotalIteration); // size(dimension_size,initial_value)
	int foundStart = 0, intersection_start, intersection_end;

// *************************** For Positive ************************************
	double res1, term2 = 0.0, result1, term1 = 0.0, result;
	std::vector<double> Btrans_dir, phi_trans_dir, phi_trans_dir1;

// *************************** For Negative ************************************
	double res1_minus, term2_minus = 0.0, result1_minus, term1_minus = 0.0,
			result_minus;
	std::vector<double> Btrans_dir_minus, phi_trans_dir_minus,
			phi_trans_dir1_minus;

	math::matrix<double> B_trans, phi_tau_Transpose;
	if (!SystemDynamics.isEmptyMatrixA) //current_location's SystemDynamics's or ReachParameters
		phi_tau_Transpose = ReachParameters.phi_trans;
	if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
		B_trans = ReachParameters.B_trans;

//#pragma omp parallel for
	for (int eachInvariantDirection = 0;
			eachInvariantDirection < numberOfInvariants;
			eachInvariantDirection++) {

		double zIInitial, zIInitial_minus, zI = 0.0, zV = 0.0;
		double zI_min = 0.0, zV_min = 0.0;
		double sVariable, s1Variable;
		double sVariable_min, s1Variable_min; //For Minimization of First Vector only

		std::vector<double> r1Variable, r1Variable_minus;
		r1Variable.resize(dimension);
		r1Variable_minus.resize(dimension);

		std::vector<double> rVariable, rVariable_minus;
		rVariable.resize(dimension);
		rVariable_minus.resize(dimension);
		//	cout<<"Invariant Number = "<<eachInvariantDirection<<endl;
		for (int i = 0; i < dimension; i++) {
			rVariable[i] = invariant->getCoeffMatrix()(eachInvariantDirection,
					i); //First vector positive
			rVariable_minus[i] = -1
					* invariant->getCoeffMatrix()(eachInvariantDirection, i); //Second vector negative of First vector
		}
		// ******** Lamda Computation for each invariant's directions/constraints **********
		double invariant_SupportFunction;
		int type = lp_solver_type_choosen;
		lp_solver lpSolver(type), lp_U_dummy(type);

		lpSolver.setMin_Or_Max(2);
		if (!invariant->getIsEmpty() && !invariant->getIsUniverse()) { //set glpk constraints If not an empty polytope
			lpSolver.setConstraints(invariant->getCoeffMatrix(),
					invariant->getColumnVector(),
					invariant->getInEqualitySign());
			invariant_SupportFunction = invariant->computeSupportFunction(
					rVariable, lpSolver, lp_U_dummy, 2);
			//	std::cout << "\neachInvariantDirection = "<<eachInvariantDirection<<" Invariant SupportFunction = " << invariant_SupportFunction << endl;
		}
		// **********************XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX******************

		lp_solver s_per_thread_I(type), s_per_thread_U(type);
// ************************************************ For Positive Direction Starts ************************************************
		s_per_thread_I.setMin_Or_Max(2);
		if (!Initial->getIsEmpty()) //set glpk constraints If not an empty polytope
			s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
					ReachParameters.X0->getColumnVector(),
					ReachParameters.X0->getInEqualitySign());

		s_per_thread_U.setMin_Or_Max(2);
		if (SystemDynamics.U->getIsEmpty()) { //empty polytope
			//Polytope is empty so no glpk object constraints to be set
		} else {
			s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
					SystemDynamics.U->getColumnVector(),
					SystemDynamics.U->getInEqualitySign());
		}
// ************************************************   Positive Direction Ends *******************************************
		lp_solver s_per_thread_I_minus(type), s_per_thread_U_minus(type);
// ******************************************* For Negative Direction Starts *******************************************
		s_per_thread_I_minus.setMin_Or_Max(2);
		if (!Initial->getIsEmpty()) //set glpk constraints If not an empty polytope
			s_per_thread_I_minus.setConstraints(
					ReachParameters.X0->getCoeffMatrix(),
					ReachParameters.X0->getColumnVector(),
					ReachParameters.X0->getInEqualitySign());

		s_per_thread_U_minus.setMin_Or_Max(2);
		if (SystemDynamics.U->getIsEmpty()) { //empty polytope
			//Polytope is empty so no glpk object constraints to be set
		} else {
			s_per_thread_U_minus.setConstraints(
					SystemDynamics.U->getCoeffMatrix(),
					SystemDynamics.U->getColumnVector(),
					SystemDynamics.U->getInEqualitySign());
		}
// ******************************************* Negative Direction Ends *******************************************
		unsigned int loopIteration = 0;
		sVariable = 0.0; //initialize s0
		sVariable_min = 0.0;

		// ************************************************  For Positive Direction Starts *******************************************
		//zIInitial = Omega_Support(ReachParameters, rVariable, Initial,SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
		double term3, term3a, term3b, res2, term3c = 0.0;
		//  **************    Omega Function   ********************
		res1 = Initial->computeSupportFunction(rVariable, s_per_thread_I,
				s_per_thread_U, Min_Or_Max);
		if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
			phi_tau_Transpose.mult_vector(rVariable, phi_trans_dir);
			term1 = Initial->computeSupportFunction(phi_trans_dir,
					s_per_thread_I, s_per_thread_U, Min_Or_Max);
		}
		if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
			B_trans.mult_vector(rVariable, Btrans_dir);
		if (!SystemDynamics.isEmptyMatrixB && !SystemDynamics.U->getIsEmpty())
			term2 = ReachParameters.time_step
					* SystemDynamics.U->computeSupportFunction(Btrans_dir,
							s_per_thread_U, s_per_thread_I, Min_Or_Max);
		term3a = ReachParameters.result_alfa;
		term3b = (double) support_unitball_infnorm(rVariable);
		if (!SystemDynamics.isEmptyC) {
			term3c = ReachParameters.time_step
					* dot_product(SystemDynamics.C, rVariable); //Added +tau* sf_C(l) 8/11/2015
		}
		term3 = term3a * term3b;
		res2 = term1 + term2 + term3 + term3c; //term3c Added
		if (res1 > res2)
			zIInitial = res1;
		else
			zIInitial = res2;
		//  **************  Omega Function Over  ********************
		// ************************************************   Positive Direction Ends *******************************************

		// ******************************************* For Negative Direction Starts *******************************************
		//zIInitial = Omega_Support(ReachParameters, rVariable_minus, Initial,SystemDynamics, s_per_thread_I_minus, s_per_thread_U_minus, Min_Or_Max);
		double term3_minus, term3a_minus, term3b_minus, res2_minus,
				term3c_minus = 0.0;
		//  **************    Omega Function   ********************
		res1_minus = Initial->computeSupportFunction(rVariable_minus,
				s_per_thread_I_minus, s_per_thread_U_minus, Min_Or_Max);
		if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
			phi_tau_Transpose.mult_vector(rVariable_minus, phi_trans_dir_minus);
			term1_minus = Initial->computeSupportFunction(phi_trans_dir_minus,
					s_per_thread_I_minus, s_per_thread_U_minus, Min_Or_Max);
		}
		if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
			B_trans.mult_vector(rVariable_minus, Btrans_dir_minus);
		if (!SystemDynamics.isEmptyMatrixB && !SystemDynamics.U->getIsEmpty())
			term2_minus = ReachParameters.time_step
					* SystemDynamics.U->computeSupportFunction(Btrans_dir_minus,
							s_per_thread_U_minus, s_per_thread_I_minus,
							Min_Or_Max);
		term3a_minus = ReachParameters.result_alfa;
		term3b_minus = (double) support_unitball_infnorm(rVariable_minus);
		if (!SystemDynamics.isEmptyC) {
			term3c_minus = ReachParameters.time_step
					* dot_product(SystemDynamics.C, rVariable_minus); //Added +tau* sf_C(l) 8/11/2015
		}
		term3_minus = term3a_minus * term3b_minus;
		res2_minus = term1_minus + term2_minus + term3_minus + term3c_minus;
		if (res1_minus > res2_minus)
			zIInitial_minus = res1_minus;
		else
			zIInitial_minus = res2_minus;
		//  **************  Omega Function Over  ********************
		// ******************************************* Negative Direction Ends *******************************************

		loopIteration++;
		for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
// ************************************************  For Positive Direction Starts *******************************************
			double TempOmega, term3, term3a, res2, beta, res_beta;
			//	zV = W_Support(ReachParameters, SystemDynamics, rVariable,s_per_thread_U, Min_Or_Max);
			//  **************    W_Support Function   ********************
			result1 = term2;
			beta = ReachParameters.result_beta;
			res_beta = beta * term3b; //Replacing term3b from previous step
			result = result1 + res_beta + term3c; //Added term3c
			zV = result;
			//  **************  W_Support Function Over  ********************
			s1Variable = sVariable + zV;
			r1Variable = phi_trans_dir;
			//zI = Omega_Support(ReachParameters, r1Variable, Initial,SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
			//  **************    Omega Function   ********************
			res1 = term1;
			if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
				phi_tau_Transpose.mult_vector(r1Variable, phi_trans_dir);
				term1 = Initial->computeSupportFunction(phi_trans_dir,
						s_per_thread_I, s_per_thread_U, Min_Or_Max);
			}
			if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
				B_trans.mult_vector(r1Variable, Btrans_dir);
				term2 = ReachParameters.time_step
						* SystemDynamics.U->computeSupportFunction(Btrans_dir,
								s_per_thread_U, s_per_thread_I, Min_Or_Max);
			}
			term3a = ReachParameters.result_alfa;
			term3b = support_unitball_infnorm(r1Variable);
			if (!SystemDynamics.isEmptyC) {
				term3c = ReachParameters.time_step
						* dot_product(SystemDynamics.C, r1Variable); //Added +tau* sf_C(l) 8/11/2015
			}
			term3 = term3a * term3b;
			res2 = term1 + term2 + term3 + term3c;
			if (res1 > res2)
				zI = res1;
			else
				zI = res2;
			//  **************  Omega Function Over  ********************

			TempOmega = zI + s1Variable; //Y1
// ************************************************   Positive Direction Ends *******************************************

// ************************************************  For Negative Direction Starts *******************************************
			double TempOmega_min, term3_minus, term3a_minus, res2_minus,
					beta_minus, res_beta_minus;
			//	zV = W_Support(ReachParameters, SystemDynamics, rVariable,s_per_thread_U, Min_Or_Max);
			//  **************    W_Support Function   ********************
			result1_minus = term2_minus;
			beta_minus = ReachParameters.result_beta;
			res_beta_minus = beta_minus * term3b_minus; //Replacing term3b from previous step
			result_minus = result1_minus + res_beta + term3c_minus;
			;
			zV_min = result_minus;
			//  **************  W_Support Function Over  ********************
			s1Variable_min = sVariable_min + zV_min;
			r1Variable_minus = phi_trans_dir_minus;
			//zI = Omega_Support(ReachParameters, r1Variable, Initial,SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
			//  **************    Omega Function   ********************
			res1_minus = term1_minus;
			if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
				phi_tau_Transpose.mult_vector(r1Variable_minus,
						phi_trans_dir_minus);
				term1_minus = Initial->computeSupportFunction(
						phi_trans_dir_minus, s_per_thread_I_minus,
						s_per_thread_U_minus, Min_Or_Max);
			}
			if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
				B_trans.mult_vector(r1Variable_minus, Btrans_dir_minus);
				term2_minus = ReachParameters.time_step
						* SystemDynamics.U->computeSupportFunction(
								Btrans_dir_minus, s_per_thread_U_minus,
								s_per_thread_I_minus, Min_Or_Max);
			}
			term3a_minus = ReachParameters.result_alfa;
			term3b_minus = support_unitball_infnorm(r1Variable_minus);
			if (!SystemDynamics.isEmptyC) {
				term3c_minus = ReachParameters.time_step
						* dot_product(SystemDynamics.C, rVariable_minus); //Added +tau* sf_C(l) 8/11/2015
			}
			term3_minus = term3a_minus * term3b_minus;
			res2_minus = term1_minus + term2_minus + term3_minus + term3c_minus;
			if (res1_minus > res2_minus)
				zI_min = res1_minus;
			else
				zI_min = res2_minus;
			//  **************  Omega Function Over  ********************
			TempOmega_min = zI_min + s1Variable_min; //Y1
			// ************************************************   Negative Direction Ends *******************************************

// ******************************************* Intersection Detection Section Starts *******************************************
			if (((-1 * TempOmega_min) < invariant_SupportFunction)
					&& (invariant_SupportFunction < TempOmega)) { //Should have been correct
				intersection_start = loopIteration; //Partially inside the region
				//	cout<<"\nINTERSECTION_start = "<<intersection_start <<endl;
				//}
			}
			if ((-1 * TempOmega_min) > invariant_SupportFunction) { // Should have been correct
				//if ( ((-1 * TempOmega_min) < invariant_SupportFunction) && (TempOmega < invariant_SupportFunction)) {
				intersection_end = loopIteration;
				//cout << "\nIntersection_End = " << intersection_end << endl;
				boundaryIterations[eachInvariantDirection] = loopIteration; //Made Changes here due to circle
				break; //no need to compute reachable set anymore due to out of invariant boundary
			}
// ******************************************* Intersection Detection Section Ends *******************************************
			rVariable = CopyVector(r1Variable); //source to destination		//Also works   rVariable=r1Variable
			sVariable = s1Variable;
			rVariable_minus = CopyVector(r1Variable_minus);
			sVariable_min = s1Variable_min;

			loopIteration++; //for the next Omega-iteration or Time-bound
		} //end of iterations
	} //end of parallel for each Iterations or Time-Bound
// At the end of the For-Loop or all invariant_Directions we have boundaryIterations vector with the different limit to stop iterations
// The Minimum(boundaryIterations) will be the final Boundary Limit for the number of iterations
	unsigned int min_Total_Iteration;
	min_Total_Iteration = *min_element(boundaryIterations.begin(),
			boundaryIterations.end());
//	cout<<"\nmin_Total_Iteration = "<<min_Total_Iteration<<endl;
	return min_Total_Iteration;
}

