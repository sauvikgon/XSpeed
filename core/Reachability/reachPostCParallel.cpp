/*
 * reachParallelExplore.cpp
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */

#include "../../core/Reachability/reachPostCParallel.h"


//Parallel sf sampling  using OMP
const template_polyhedra::ptr reachParallelSampling(unsigned int boundedTotIteration, Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial, ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool InvariantExist, int lp_solver_type_choosen) {

	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant

	math::matrix<double> MatrixValue; //Shared Matrix for all child thread

	boost::numeric::ublas::matrix<double>::size_type row = numVectors, col =
			shm_NewTotalIteration;

	if (InvariantExist == true) { //if invariant exist. Computing
		shm_NewTotalIteration = boundedTotIteration;

	} //End of Invariant Directions
	if (shm_NewTotalIteration == 1) {
		template_polyhedra::ptr poly_emptyp;
		return poly_emptyp;
	}

	col = shm_NewTotalIteration;
	MatrixValue.resize(row, col);

	math::matrix<double> B_trans, phi_tau_Transpose;
	phi_tau_Transpose = ReachParameters.phi_trans;
	B_trans = ReachParameters.B_trans;

	int type = lp_solver_type_choosen;

#pragma omp parallel for
	for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {


		double res1, result, term2=0.0, result1, term1=0;
		std::vector<double> Btrans_dir, phi_trans_dir, phi_trans_dir1;

		lp_solver s_per_thread_I(type), s_per_thread_U(type), s_per_thread_inv(
				type);
		s_per_thread_I.setMin_Or_Max(2);
		if (!Initial->getIsEmpty()) { //set glpk constraints If not an empty polytope
			s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
					ReachParameters.X0->getColumnVector(),
					ReachParameters.X0->getInEqualitySign());
		}
		s_per_thread_U.setMin_Or_Max(2);
		if (SystemDynamics.U != NULL && !SystemDynamics.U->getIsEmpty()) { //empty polytope

			s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
					SystemDynamics.U->getColumnVector(),
					SystemDynamics.U->getInEqualitySign());
		}

		double zIInitial = 0.0, zI = 0.0, zV = 0.0;
		double sVariable, s1Variable;
		std::vector<double> r1Variable(dimension), rVariable(dimension);
		for (int i = 0; i < dimension; i++) {
			rVariable[i] = ReachParameters.Directions(eachDirection, i);
		}
		unsigned int loopIteration = 0;
		double term3, term3a, term3b, res2, term3c = 0.0;
		sVariable = 0.0; //initialize s0
		//  **************    Omega Function   ********************
		res1 = Initial->computeSupportFunction(rVariable, s_per_thread_I);
		if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
			phi_tau_Transpose.mult_vector(rVariable, phi_trans_dir);
			term1 = Initial->computeSupportFunction(phi_trans_dir, s_per_thread_I);
		}

		if (!SystemDynamics.isEmptyMatrixB) //current_location's SystemDynamics's or ReachParameters
			B_trans.mult_vector(rVariable, Btrans_dir);

		if (!SystemDynamics.isEmptyMatrixB && !SystemDynamics.U->getIsEmpty())
			term2 = ReachParameters.time_step
					* SystemDynamics.U->computeSupportFunction(Btrans_dir, s_per_thread_U);
		term3a = ReachParameters.result_alfa;
		term3b = support_unitball_infnorm(rVariable);
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

		MatrixValue(eachDirection, loopIteration) = zIInitial;
		loopIteration++;

		for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
			double TempOmega;

			//  **************    W_Support Function   ********************

			result1 = term2; //replacement--optimizing
			double beta = ReachParameters.result_beta;

			double res_beta = beta * term3b; //replace from Previous step UnitBall
			result = result1 + res_beta + term3c; //Added term3c
			zV = result;
			//  **************  W_Support Function Over  ********************
			s1Variable = sVariable + zV;

			r1Variable = phi_trans_dir; //replacement--optimizing

			//  **************    Omega Function   ********************

			res1 = term1; //replacement--optimizing
			double term3, term3a, res2;


			if (!SystemDynamics.isEmptyMatrixA) { //current_location's SystemDynamics's or ReachParameters
				phi_tau_Transpose.mult_vector(r1Variable, phi_trans_dir);
				term1 = Initial->computeSupportFunction(phi_trans_dir, s_per_thread_I);
			}

			if (!SystemDynamics.isEmptyMatrixB) { //current_location's SystemDynamics's or ReachParameters
				B_trans.mult_vector(r1Variable, Btrans_dir);
				term2 = ReachParameters.time_step
						* SystemDynamics.U->computeSupportFunction(Btrans_dir, s_per_thread_U);
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
	} //end of pragma omp parallel for


	//todo:: Redundant invariant directional constraints to be removed
	if (InvariantExist == true) { //if invariant exist. Computing
		math::matrix<double> inv_sfm;
		int num_inv = invariant->getColumnVector().size(); //number of Invariant's constriants
		inv_sfm.resize(num_inv, shm_NewTotalIteration);
		for (int eachInvDirection = 0; eachInvDirection < num_inv;
				eachInvDirection++) {
			for (unsigned int i = 0; i < shm_NewTotalIteration; i++) {
				inv_sfm(eachInvDirection, i) =
						invariant->getColumnVector()[eachInvDirection];
			}
		}

		return template_polyhedra::ptr(
				new template_polyhedra(MatrixValue, inv_sfm,
						ReachParameters.Directions,
						invariant->getCoeffMatrix()));
	} else {
		MatrixValue.resize(numVectors, shm_NewTotalIteration, true); //but writing or resizing only upto the NewTotalIteration
		return template_polyhedra::ptr(
				new template_polyhedra(MatrixValue, ReachParameters.Directions));
	}
}

const template_polyhedra::ptr reachTimeSlice(unsigned int NewTotalIteration, Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant, bool invariantExist, int CORES,
		unsigned int Algorithm_Type, int lp_solver_type_choosen) {
	double T = ReachParameters.TimeBound;
	//double original_time_step = ReachParameters.time_step;

	// ******** New Change after boundaryCheckOutside ***************
	if (invariantExist)	//if invariant exist than NewTotalIteration will be greater than 0
		ReachParameters.Iterations = NewTotalIteration; //Actual number of iteration after boundary check evaluation
	// ******** New Change ***************
	unsigned int original_Iterations = ReachParameters.Iterations;
	//double newTimeBound = T / CORES;
	double newTimeHorizon = NewTotalIteration * ReachParameters.time_step; //@amit new reachable Time horizon after invariant check

	double newTimeBound = newTimeHorizon / CORES; //@Amit debugging ... Modify to take the new reachable TimeBound


	ReachParameters.TimeBound = newTimeBound; //correct one.	//ReachParameters.TimeBound = 1;

	// ******** New Change after boundaryCheckOutside ***************

	ReachParameters.Iterations = ReachParameters.Iterations / CORES; //required in Invarian_Boundary_Check
	//Todo::: please handle when the value of this expression is in Fraction
	// ******** New Change ***************
	template_polyhedra::ptr reachability_region;
	reachability_region = template_polyhedra::ptr(new template_polyhedra());

#pragma omp parallel for
	for (int i = 0; i < CORES; i++) { //for (double i = 0; i < T; i += newTimeBound) {

		template_polyhedra::ptr Tpoly=template_polyhedra::ptr(new template_polyhedra());
		math::matrix<double> phi, phi_trans, A_inv_phi, y_matrix, y_trans;
		double START_TIME = i * newTimeBound; //first iteration START_TIME = i = 0 which make beta = 0
		//std::cout<<"i and START_TIME are = "<<i<< "    "<< START_TIME<<"\n";
		SystemDynamics.MatrixA.matrix_exponentiation(phi, START_TIME); //if MatrixA is empty will not perform this function
		phi.transpose(phi_trans); //phi_trans computed

		if (SystemDynamics.MatrixA.isInvertible()){ //if A inverse exist
			math::matrix<double> A_inv(SystemDynamics.MatrixA.size1(), SystemDynamics.MatrixA.size2());
			A_inv.multiply(phi, A_inv_phi);
			A_inv_phi.minus(A_inv, y_matrix);

		}else {
			y_matrix = time_slice_component(SystemDynamics.MatrixA, START_TIME);
		}
		y_matrix.transpose(y_trans);

		polytope::ptr u;
		if (SystemDynamics.U==NULL)
			u=polytope::ptr(new polytope(true));
		else
			u = SystemDynamics.U;

		supportFunctionProvider::ptr Initial;
		if (!SystemDynamics.isEmptyC){
			Initial= transMinkPoly::ptr(new transMinkPoly(ReachParameters.X0, u,SystemDynamics.C ,phi_trans, y_trans, 1, 0));
		}else{
			Initial= transMinkPoly::ptr(new transMinkPoly(ReachParameters.X0, u,phi_trans, y_trans, 1, 0));
		}

		//Calling Sequential algorithm here and later can mix with parallel for direction
		if (Algorithm_Type == TIME_SLICE) {

			Tpoly = reachabilitySequential_For_Parallel_Iterations(ReachParameters.Iterations, SystemDynamics, Initial, ReachParameters, invariant,
					invariantExist, lp_solver_type_choosen);

		}


#pragma omp critical
		{

			reachability_region = reachability_region->union_TemplatePolytope(Tpoly);
		}

	} //end of pragma for loop
		ReachParameters.Iterations = original_Iterations;
	ReachParameters.TimeBound = T; //restore the original timebound for next transition or location
	return reachability_region;
}











