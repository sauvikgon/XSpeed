/*
 * reachabilitySequential.cpp
 *
 *  Created on: 24-Nov-2014
 *      Author: amit
 */


#include "core_system/Reachability/reachabilitySequential.h"


//Reachability Algorithm after optimization of the duplicate support function computation
template_polyhedra::ptr reachabilitySequential(unsigned int boundedTotIteration, Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant, bool InvariantExist, int lp_solver_type_choosen) {

	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant


	math::matrix<double> MatrixValue; //Shared Matrix for all child thread
	size_type row = numVectors, col = shm_NewTotalIteration;
	if (InvariantExist == true) { //if invariant exist. Computing
		shm_NewTotalIteration = boundedTotIteration;

	} //End of Invariant Directions

	if (shm_NewTotalIteration < 1) {
		template_polyhedra::ptr poly_emptyp;
		return poly_emptyp;
	}

	col = shm_NewTotalIteration; //if invariant exists, col will be resized
	MatrixValue.resize(row, col);
	int solver_type = lp_solver_type_choosen;
	lp_solver s_per_thread_I(solver_type), s_per_thread_U(solver_type), s_per_thread_inv(solver_type);
	s_per_thread_I.setMin_Or_Max(2);

	if (!ReachParameters.X0->getIsEmpty()) //set glpk constraints If not an empty polytope
		s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
				ReachParameters.X0->getColumnVector(), ReachParameters.X0->getInEqualitySign());

	s_per_thread_U.setMin_Or_Max(2);

	if (SystemDynamics.U != NULL && !SystemDynamics.U->getIsEmpty()) { //empty polytope
		s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
				SystemDynamics.U->getColumnVector(),
				SystemDynamics.U->getInEqualitySign());
	}

	double res1, result, term2 = 0.0, result1, term1 = 0.0;
	std::vector<double> Btrans_dir, phi_trans_dir, phi_trans_dir1;
	math::matrix<double> B_trans, phi_tau_Transpose;
	if (!SystemDynamics.isEmptyMatrixA) //current_location's SystemDynamics's or ReachParameters
		phi_tau_Transpose = ReachParameters.phi_trans;
	if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
		B_trans = ReachParameters.B_trans;

	for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {
		double zIInitial = 0.0, zI = 0.0, zV = 0.0;
		double sVariable, s1Variable;
		std::vector<double> r1Variable(dimension), rVariable(dimension);
		for (int i = 0; i < dimension; i++) {
			rVariable[i] = ReachParameters.Directions(eachDirection, i);
		}
		unsigned int loopIteration = 0;
		double term3, term3a = 0.0, term3b = 0.0, res2, term3c = 0.0;
		sVariable = 0.0; //initialize s0
		//  **************    Omega Function   ********************
		res1 = Initial->computeSupportFunction(rVariable, s_per_thread_I);
		//cout<<"res1 = "<<res1 <<"\n";

		if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
			phi_tau_Transpose.mult_vector(rVariable, phi_trans_dir);
			term1 = Initial->computeSupportFunction(phi_trans_dir, s_per_thread_I);
		}else if (SystemDynamics.isEmptyMatrixA) { //if A is empty :: {tau.A}' reduces to zero so, e^{tau.A}' reduces to 1
													// so, 1 * rVariable give only rVariable
			term1 = Initial->computeSupportFunction(rVariable, s_per_thread_I);
		}//handling constant dynamics

		if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
			B_trans.mult_vector(rVariable, Btrans_dir);

		if (!SystemDynamics.isEmptyMatrixB && !SystemDynamics.U->getIsEmpty())
			term2 = ReachParameters.time_step * SystemDynamics.U->computeSupportFunction(Btrans_dir,s_per_thread_U);
		term3a = ReachParameters.result_alfa;
		term3b = (double) support_unitball_infnorm(rVariable);

		if (!SystemDynamics.isEmptyC) {
			term3c = ReachParameters.time_step * dot_product(SystemDynamics.C, rVariable); //Added +tau* sf_C(l) 8/11/2015
		}
		term3 = term3a * term3b;
		res2 = term1 + term2 + term3 + term3c; //term3c Added

		if (res1 > res2)
			zIInitial = res1;
		else
			zIInitial = res2;


		//  **************  Omega Function Over  ********************
		MatrixValue(eachDirection, loopIteration) = zIInitial;

		loopIteration++;
		for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
			double TempOmega;
			result1 = term2;
			double beta = ReachParameters.result_beta;

			double res_beta = beta * term3b; //Replacing term3b from previous step
			result = result1 + res_beta + term3c; //Added term3c
			zV = result;
			//  **************  W_Support Function Over  ********************
			s1Variable = sVariable + zV;
			//phi_tau_Transpose.mult_vector(rVariable, r1Variable);
			//r1Variable = phi_trans_dir;

			if (SystemDynamics.isEmptyMatrixA) { //Matrix A is empty for constant dynamics
				r1Variable = rVariable;
			} else {
				r1Variable = phi_trans_dir;
			}


			//  **************    Omega Function   ********************

			if (SystemDynamics.isEmptyMatrixA) { //Matrix A is empty for constant dynamics
				//res1 = res1; //A is empty than r1Variable is NOT computable and so is term1. Hence res1 is previous  res1
			} else {
				res1 = term1; //A is not empty than r1Variable is computable and so is term1
			}

			double term3, term3a, res2;
			if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
				phi_tau_Transpose.mult_vector(r1Variable, phi_trans_dir);
				term1 = Initial->computeSupportFunction(phi_trans_dir, s_per_thread_I);
			}

			if (!SystemDynamics.isEmptyMatrixB) { //current_location's SystemDynamics's or ReachParameters
				B_trans.mult_vector(r1Variable, Btrans_dir);
				term2 = ReachParameters.time_step
						* SystemDynamics.U->computeSupportFunction(Btrans_dir,s_per_thread_U);
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

			MatrixValue(eachDirection, loopIteration) = TempOmega; //Y1
			rVariable = CopyVector(r1Variable); //source to destination
			sVariable = s1Variable;
			loopIteration++; //for the next Omega-iteration or Time-bound
		} //end of while for each vector
	}

	//todo:: Redundant invariant directional constraints to be removed

	if (InvariantExist == true) { //if invariant exist. Computing
		math::matrix<double> inv_sfm;
		int num_inv = invariant->getColumnVector().size(); //number of Invariant's constraints
		inv_sfm.resize(num_inv, shm_NewTotalIteration);
		for (int eachInvDirection = 0; eachInvDirection < num_inv;
				eachInvDirection++) {
			for (unsigned int i = 0; i < shm_NewTotalIteration; i++) {
				inv_sfm(eachInvDirection, i) =
						invariant->getColumnVector()[eachInvDirection];
			}
		}
		return template_polyhedra::ptr( new template_polyhedra(MatrixValue, inv_sfm,
				ReachParameters.Directions, invariant->getCoeffMatrix()));
	} else {
		return template_polyhedra::ptr( new template_polyhedra(MatrixValue, ReachParameters.Directions));
	}
}


/*
 * Code AFTER optimising the support function computation
 * Same Code as above but with critical region in InvariantExist block
 *
 * @Amit: Modifying to match with the always updated Sequential algorithm.
 */
template_polyhedra::ptr reachabilitySequential_For_Parallel_Iterations(unsigned int boundedTotIteration,
		Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial, ReachabilityParameters& ReachParameters,
		polytope::ptr invariant, bool InvariantExist, int lp_solver_type_choosen) {

	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant

	math::matrix<double> MatrixValue; //Shared Matrix for all child thread
	size_type row = numVectors, col = shm_NewTotalIteration;
	MatrixValue.resize(row, col);

	if (InvariantExist == true) { //if invariant exist. Computing
		//shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial, ReachParameters, invariant, lp_solver_type_choosen);
		shm_NewTotalIteration = boundedTotIteration;
	} //End of Invariant Directions
	//cout<<"shm_NewTotalIteration = " <<shm_NewTotalIteration<<std::endl;
	if (shm_NewTotalIteration < 1) {
		template_polyhedra::ptr poly_emptyp=template_polyhedra::ptr(new template_polyhedra());
		return poly_emptyp;
	}
	int solver_type = lp_solver_type_choosen;

	lp_solver s_per_thread_I(solver_type), s_per_thread_U(solver_type),
			s_per_thread_inv(solver_type);
	s_per_thread_I.setMin_Or_Max(2);
	if (!ReachParameters.X0->getIsEmpty()) //set glpk constraints If not an empty polytope
		s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
				ReachParameters.X0->getColumnVector(), ReachParameters.X0->getInEqualitySign());

	s_per_thread_U.setMin_Or_Max(2);
	if (SystemDynamics.U != NULL && !SystemDynamics.U->getIsEmpty()) { //empty polytope
		s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
				SystemDynamics.U->getColumnVector(), SystemDynamics.U->getInEqualitySign());
	}
//	cout<<"OK 2 \n";
	double res1, result, term2=0.0, result1, term1=0.0;
	std::vector<double> Btrans_dir, phi_trans_dir, phi_trans_dir1;
	math::matrix<double> B_trans, phi_tau_Transpose;
	if (!SystemDynamics.isEmptyMatrixA) //current_location's SystemDynamics's or ReachParameters
		phi_tau_Transpose = ReachParameters.phi_trans;
	if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
		B_trans = ReachParameters.B_trans;

	for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {

		double zIInitial = 0.0, zI = 0.0, zV = 0.0;
		double sVariable, s1Variable;
		std::vector<double> r1Variable(dimension), rVariable(dimension);
		for (int i = 0; i < dimension; i++) {
			rVariable[i] = ReachParameters.Directions(eachDirection, i);
		}
		unsigned int loopIteration = 0;
		double term3, term3a = 0.0, term3b = 0.0, res2, term3c = 0.0;
		sVariable = 0.0; //initialize s0

		//  **************    Omega Function   ********************
		res1 = Initial->computeSupportFunction(rVariable, s_per_thread_I);

		if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
			phi_tau_Transpose.mult_vector(rVariable, phi_trans_dir);
			term1 = Initial->computeSupportFunction(phi_trans_dir, s_per_thread_I);
		}else if (SystemDynamics.isEmptyMatrixA) { //if A is empty :: {tau.A}' reduces to zero so, e^{tau.A}' reduces to 1
			term1 = Initial->computeSupportFunction(rVariable, s_per_thread_I);
		}//handling constant dynamics

		if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
			B_trans.mult_vector(rVariable, Btrans_dir);

		if (SystemDynamics.U != NULL && !SystemDynamics.U->getIsEmpty())
			term2 = ReachParameters.time_step * SystemDynamics.U->computeSupportFunction(Btrans_dir,s_per_thread_U);
		term3a = ReachParameters.result_alfa;
		term3b = (double) support_unitball_infnorm(rVariable);


		if (!SystemDynamics.isEmptyC) {
			term3c = ReachParameters.time_step * dot_product(SystemDynamics.C, rVariable); //Added +tau* sf_C(l) 8/11/2015
		}
		term3 = term3a * term3b;
		res2 = term1 + term2 + term3 + term3c;
		if (res1 > res2)
			zIInitial = res1;
		else
			zIInitial = res2;
		//  **************  Omega Function Over  ********************
		MatrixValue(eachDirection, loopIteration) = zIInitial;
		loopIteration++;

		for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
			double TempOmega;

			//  **************    W_Support Function   ********************
			result1 = term2;
			double beta = ReachParameters.result_beta;

			double res_beta = beta * term3b; //replace from previous steps UnitBall
			result = result1 + res_beta + term3c; //Added term3c
			zV = result;
			//  **************  W_Support Function Over  ********************
			s1Variable = sVariable + zV;


			if (SystemDynamics.isEmptyMatrixA) { //Matrix A is empty for constant dynamics
				r1Variable = rVariable;
			} else {
				r1Variable = phi_trans_dir;
			}
			//  **************    Omega Function   ********************
			if (SystemDynamics.isEmptyMatrixA) { //Matrix A is empty for constant dynamics
				//res1 = res1; //A is empty than r1Variable is NOT computable and so is term1. Hence res1 is previous  res1
			} else {
				res1 = term1; //A is not empty than r1Variable is computable and so is term1
			}


			double term3, term3a, res2;

			if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
				phi_tau_Transpose.mult_vector(r1Variable, phi_trans_dir);
				term1 = Initial->computeSupportFunction(phi_trans_dir, s_per_thread_I);
			}

			if (!SystemDynamics.isEmptyMatrixB) { //current_location's SystemDynamics's or ReachParameters
				B_trans.mult_vector(r1Variable, Btrans_dir);
				term2 = ReachParameters.time_step * SystemDynamics.U->computeSupportFunction(Btrans_dir,s_per_thread_U);
			}

			term3a = ReachParameters.result_alfa;
			term3b = support_unitball_infnorm(r1Variable);
			if (!SystemDynamics.isEmptyC) {
				term3c = ReachParameters.time_step * dot_product(SystemDynamics.C, r1Variable); //Added +tau* sf_C(l) 8/11/2015
			}
			term3 = term3a * term3b;
			res2 = term1 + term2 + term3 + term3c;
			if (res1 > res2)
				zI = res1;
			else
				zI = res2;
			//  **************  Omega Function Over  ********************

			TempOmega = zI + s1Variable; //Y1
			MatrixValue(eachDirection, loopIteration) = TempOmega; //Y1
			rVariable = CopyVector(r1Variable); //source to destination
			sVariable = s1Variable;
			loopIteration++; //for the next Omega-iteration or Time-bound
		} //end of for each iteration
	} //end of for all directions

	template_polyhedra::ptr tpolys;
	tpolys = template_polyhedra::ptr(new template_polyhedra());
#pragma omp critical
	{	/* This critical is used when we call the module PAR_ITER as we are updating the variable ReachParameters
	 and MatrixValue if this function is called from the module SEQ this #pragma will be ignored */
		//Todo:: Redundant invariant directional constraints to be removed
		if (InvariantExist == true) { //if invariant exist. Computing
			math::matrix<double> inv_sfm;
			int num_inv = invariant->getColumnVector().size(); //number of Invariant's constriants
			inv_sfm.resize(num_inv, shm_NewTotalIteration);
			for (int eachInvDirection = 0; eachInvDirection < num_inv; eachInvDirection++) {
				for (unsigned int i = 0; i < shm_NewTotalIteration; i++)
					inv_sfm(eachInvDirection, i) = invariant->getColumnVector()[eachInvDirection];
			}
			tpolys->setTemplateDirections(ReachParameters.Directions);
			tpolys->setMatrixSupportFunction(MatrixValue);
			tpolys->setInvariantDirections(invariant->getCoeffMatrix());
			tpolys->setMatrix_InvariantBound(inv_sfm);
			//return template_polyhedra(MatrixValue, inv_sfm,ReachParameters.Directions, invariant->getCoeffMatrix());
			//return template_polyhedra(MatrixValue, ReachParameters.TotalDirections);
		} else {
			tpolys->setTemplateDirections(ReachParameters.Directions);
			tpolys->setMatrixSupportFunction(MatrixValue);

		}
	} //end of the Critical Section
	return tpolys;
}
/**
 * This method computes the postC flowpipe using the forward approximation model in SpaceEx
 */
template_polyhedra::ptr reachForwardApprox(unsigned int boundedTotIteration, Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant, bool InvariantExist, int lp_solver_type_choosen) {

	std::cout << "Forward Approximation Model not yet implemented\n";
	template_polyhedra::ptr polys;
	return polys;

}
