/*
 * reachabilitySequential.cpp
 *
 *  Created on: 24-Nov-2014
 *      Author: amit
 */


#include <core/continuous/approxModel/approxModel.h>
#include <core/continuous/approxModel/fbInterpol.h>
#include <core/reachability/postCSequential.h>

//postC algorithm after optimization of the duplicate support function computation
template_polyhedra::ptr postC_sf(unsigned int boundedTotIteration, Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant, bool InvariantExist, int lp_solver_type) {

	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
	
	size_type row = numVectors, col = shm_NewTotalIteration;
	if (InvariantExist == true) { //if invariant exist.
		shm_NewTotalIteration = boundedTotIteration;

	} //End of Invariant Directions

	if (shm_NewTotalIteration < 1) {
		template_polyhedra::ptr poly_emptyp;
		return poly_emptyp;
	}

	col = shm_NewTotalIteration; //if invariant exists, col will be resized
	math::matrix<double> MatrixValue(row,col); //Shared Matrix for all child thread(row, col);
	
	int solver_type = lp_solver_type;
	lp_solver s_per_thread_I(solver_type), s_per_thread_U(solver_type), s_per_thread_inv(solver_type);
	s_per_thread_I.setMin_Or_Max(2);

	double result_alfa = compute_alfa(ReachParameters.time_step,
				SystemDynamics,
				Initial, lp_solver_type); //2 glpk object created here

	double result_beta = compute_beta(SystemDynamics, ReachParameters.time_step, lp_solver_type); // NO glpk object created here

	ReachParameters.result_alfa = result_alfa;
	ReachParameters.result_beta = result_beta;
	
	// Intialised the transformation and its transpose matrix
	math::matrix<double> phi_matrix, phi_trans;

	if (!SystemDynamics.isEmptyMatrixA) { //if A not Empty
		SystemDynamics.MatrixA.matrix_exponentiation(
				phi_matrix, ReachParameters.time_step);
		phi_matrix.transpose(phi_trans);
		ReachParameters.phi_trans = phi_trans;
	}
	math::matrix<double> B_trans;
	// transpose to be done once and stored in the structure of parameters
	if (!SystemDynamics.isEmptyMatrixB) { //if B not Empty
		SystemDynamics.MatrixB.transpose(B_trans);
		ReachParameters.B_trans = B_trans;
	}

	if (!ReachParameters.X0->getIsEmpty()) //set glpk constraints If not an empty polytope
		s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
				ReachParameters.X0->getColumnVector(), ReachParameters.X0->getInEqualitySign());

	s_per_thread_U.setMin_Or_Max(2);

	if (SystemDynamics.U != NULL && !SystemDynamics.U->getIsEmpty()) { //empty polytope
		s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
				SystemDynamics.U->getColumnVector(),
				SystemDynamics.U->getInEqualitySign());
	}
	/*Including a check of model correctness*/
	
	if(!SystemDynamics.U->getIsEmpty() && SystemDynamics.isEmptyMatrixB)
	{
		std::cout << "B matrix is mandatory when input set U is NOT EMPTY" << std::endl;
		exit(0);
	}
 
	double res1, result, term2 = 0.0, result1, term1 = 0.0;
	std::vector<double> Btrans_dir, phi_trans_dir, phi_trans_dir1;
	
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
			phi_trans.mult_vector(rVariable, phi_trans_dir);
			term1 = Initial->computeSupportFunction(phi_trans_dir, s_per_thread_I);
		}else if (SystemDynamics.isEmptyMatrixA) { 
			term1 = Initial->computeSupportFunction(rVariable, s_per_thread_I);
		}//handling constant dynamics

		if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
			B_trans.mult_vector(rVariable, Btrans_dir); 

		if (!SystemDynamics.isEmptyMatrixB && !SystemDynamics.U->getIsEmpty())
			term2 = ReachParameters.time_step * SystemDynamics.U->computeSupportFunction(Btrans_dir,s_per_thread_U);
		term3a = ReachParameters.result_alfa;
		term3b = (double) support_unitball_infnorm(rVariable);

		term3 = term3a * term3b;
		res2 = term1 + term2 + term3;

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

			if (SystemDynamics.isEmptyMatrixA) { 
				r1Variable = rVariable;
			} else {
				r1Variable = phi_trans_dir;
			}

			//  **************    Omega Function   ********************
			res1 = term1; 

			double term3, term3a, res2;
			if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
				phi_trans.mult_vector(r1Variable, phi_trans_dir);
				term1 = Initial->computeSupportFunction(phi_trans_dir, s_per_thread_I);
			}

			if (!SystemDynamics.isEmptyMatrixB) { //current_location's SystemDynamics's or ReachParameters
				B_trans.mult_vector(r1Variable, Btrans_dir);
				term2 = ReachParameters.time_step
						* SystemDynamics.U->computeSupportFunction(Btrans_dir,s_per_thread_U);
			}

			term3a = ReachParameters.result_alfa;
			term3b = support_unitball_infnorm(r1Variable);
	
			term3 = term3a * term3b;
			res2 = term1 + term2 + term3;

			if (res1 > res2)
				zI = res1;
			else
				zI = res2;

			//  **************  Omega Function Over  ********************
			TempOmega = zI + s1Variable; //Y1

			MatrixValue(eachDirection, loopIteration) = TempOmega; //Y1
			rVariable = r1Variable; //source to destination
			sVariable = s1Variable;
			loopIteration++; //for the next Omega-iteration or Time-bound
		} //end of while for each vector
	}

	//todo:: Redundant invariant directional constraints to be removed

	if (InvariantExist == true) {
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
		polytope::ptr invariant, bool InvariantExist, int lp_solver_type) {

	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant

	math::matrix<double> MatrixValue; //Shared Matrix for all child thread
	size_type row = numVectors, col = shm_NewTotalIteration;
	MatrixValue.resize(row, col);

	if (InvariantExist == true) { //if invariant exist. Computing
		//shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial, ReachParameters, invariant, lp_solver_type);
		shm_NewTotalIteration = boundedTotIteration;
	} //End of Invariant Directions

	if (shm_NewTotalIteration < 1) {
		template_polyhedra::ptr poly_emptyp=template_polyhedra::ptr(new template_polyhedra());
		return poly_emptyp;
	}
	int solver_type = lp_solver_type;

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
			rVariable = r1Variable; //source to destination
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
 * This method computes the postC flowpipe using the approximation model
 * of forward-backward interpolation in SpaceEx. This is the fixed time-step
 * algorithm.
 */

template_polyhedra::ptr postC_fbinterpol(unsigned int boundedTotIteration, Dynamics& SystemDynamics, polytope::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant, bool InvariantExist, int lp_solver_type) {

	
	unsigned int num_directions = ReachParameters.Directions.size1();
	unsigned int dimension = Initial->getSystemDimension();
	unsigned int num_iters = ReachParameters.Iterations;
	math::matrix<double> SFM(num_directions, num_iters); // The data structure to store the template polytopes

	approx_model::ptr fbinterpol_model = approx_model::ptr(new fb_interpol(SystemDynamics.MatrixA, Initial, SystemDynamics.U, SystemDynamics.MatrixB, ReachParameters.time_step, num_iters) );

	for (unsigned int eachDirection = 0; eachDirection < num_directions; eachDirection++){
		std::vector<double> direction(dimension);

		for (unsigned int i = 0; i < dimension; i++) {
			direction[i] = ReachParameters.Directions(eachDirection, i);
		}
		for(unsigned int iters = 0; iters < num_iters; iters++)
		{
			// Do some more logic to change the Omega to match with the iters
			double res = fbinterpol_model->omega_support(direction,iters);
			SFM(eachDirection,iters) = res;
		}
	}

	unsigned int total_iters = ReachParameters.Iterations;

	if (InvariantExist == true) { //if invariant exist. Computing
		math::matrix<double> inv_sfm;
		unsigned int num_inv_constr = invariant->getColumnVector().size(); //number of Invariant's constraints
		inv_sfm.resize(num_inv_constr, total_iters);
		for (unsigned int eachInvDirection = 0; eachInvDirection < num_inv_constr;eachInvDirection++) {
			for (unsigned int i = 0; i < total_iters; i++) {
				inv_sfm(eachInvDirection, i) =
						invariant->getColumnVector()[eachInvDirection];
			}
		}
		
		return template_polyhedra::ptr( new template_polyhedra(SFM, inv_sfm, ReachParameters.Directions, invariant->getCoeffMatrix()));
	} else {
		return template_polyhedra::ptr( new template_polyhedra(SFM, ReachParameters.Directions));
	}

}
