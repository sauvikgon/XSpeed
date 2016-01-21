/*
 * reachParallelExplore.cpp
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */

#include "core_system/Reachability/reachParallelExplore.h"
#include "core_system/Reachability/reachabilitySequential.h"
#include "core_system/Reachability/NewApproach/Partition_BoundingPolytope.h"
#include "Utilities/invariantBoundaryCheck.h"
#include "application/sf_utility.h"
#include "Utilities/testPolytopePlotting.h"
#include "Utilities/Template_Polyhedra.h"
#include "application/All_PP_Definition.h"

/*
 * Called from Parallel_Iterations with different initial sets
 */
const template_polyhedra::ptr reachParallelExplore(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool invariantExists, int CORES, unsigned int Algorithm_Type,
		int lp_solver_type_choosen) {
	double T = ReachParameters.TimeBound;
	//double original_time_step = ReachParameters.time_step;
	unsigned int original_Iterations = ReachParameters.Iterations;
	double newTimeBound = T / CORES;

	ReachParameters.TimeBound = newTimeBound; //correct one.
	//ReachParameters.TimeBound = 1;
	ReachParameters.Iterations = ReachParameters.TimeBound
			/ ReachParameters.time_step; //required in Invarian_Boundary_Check
//	cout << "partition_iterations" << ReachParameters.Iterations << "\n";
			//ReachParameters.time_step = newTimeBound/ partition_iterations;	//computed for 1st partition
	template_polyhedra::ptr reachability_region;
	//std::list<polytope::ptr> initial_polys_list;
//omp_set_nested(1);		//Enabling the Nested Loop in OpenMP Programming
	//std::cout<<"omp_get_nested() = "<<omp_get_nested()<<std::endl;

//use g++ -fopenmp for compiling #pragma omp
#pragma omp parallel for
	for (int i = 0; i < CORES; i++) { //for (double i = 0; i < T; i += newTimeBound) {

		template_polyhedra::ptr Tpoly;
		math::matrix<double> phi, phi_trans, A_inv_phi, y_matrix, y_trans;
		double START_TIME = i * newTimeBound; //first iteration START_TIME = i = 0 which make beta = 0
		//	std::cout << "\nStart_Time = " << START_TIME << "\n";
		SystemDynamics.MatrixA.matrix_exponentiation(phi, START_TIME); //if MatrixA is empty will not perform this function
		phi.transpose(phi_trans); //phi_trans computed

		math::matrix<double> A_inv; //(SystemDynamics.MatrixA.size1(),SystemDynamics.MatrixA.size2());
		A_inv = ReachParameters.A_inv;
		A_inv.multiply(phi, A_inv_phi);
		A_inv_phi.minus(A_inv, y_matrix);
		y_matrix.transpose(y_trans);
//(phi_trans . X0 + y_trans . U)
		//	std::cout << "\ncomputing initial object\n";
		supportFunctionProvider::ptr Initial = transMinkPoly::ptr(
				new transMinkPoly(ReachParameters.X0, SystemDynamics.U,
						phi_trans, y_trans, 1, 0));
		//Calling Sequential algorithm here and later can mix with parallel for direction
		if (Algorithm_Type == PAR_ITER) {
			//	std::cout << "\nFrom Parallel Only Iterations BEFORE\n";
			Tpoly = reachabilitySequential_For_Parallel_Iterations(
					SystemDynamics, Initial, ReachParameters, invariant,
					invariantExists, lp_solver_type_choosen);
			//	std::cout << "\nFrom Parallel Only Iterations AFTER\n";
		}

		if (Algorithm_Type == PAR_ITER_DIR) {
			Tpoly = reachabilityParallel_For_Parallel_Iter_Dir(SystemDynamics,
					Initial, ReachParameters, invariant, invariantExists,
					lp_solver_type_choosen);
			//	std::cout << "\nFrom Parallel over Iterations and Directions\n";
		}
#pragma omp critical
		//	if (i != 0)
		reachability_region = reachability_region->union_TemplatePolytope(Tpoly);
	} //end of pragma for loop

	//this may not be required if Average_number_of_times = 1 otherwise must.
	ReachParameters.Iterations = original_Iterations;
	ReachParameters.TimeBound = T; //restore the original timebound for next transition or location
	//GenerateInitialPolytopePlotter(initial_polys_list);
	return reachability_region;
}

/*
 //Implementation of reachability parallel using OMP approach  -- Before Optimizing support function computation
 *
 const template_polyhedra reachabilityParallel(Dynamics& SystemDynamics,
 supportFunctionProvider::ptr Initial,
 ReachabilityParameters& ReachParameters, polytope::ptr invariant,
 bool isInvariantExist, int lp_solver_type_choosen) {
 //typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

 //omp_set_num_threads(numVectors);
 //#pragma omp parallel
 //int tid;
 int numVectors = ReachParameters.Directions.size1();
 int dimension = Initial->getSystemDimension();
 unsigned int shm_NewTotalIteration = ReachParameters.Iterations;//Shared Variable for resize iterations number on crossing with invariant
 int Min_Or_Max = 2;

 math::matrix<double> MatrixValue;	//Shared Matrix for all child thread
 //size_type row = numVectors, col = shm_NewTotalIteration;
 boost::numeric::ublas::matrix<double>::size_type row = numVectors, col =
 shm_NewTotalIteration;

 if (isInvariantExist == true) {	//if invariant exist. Computing
 shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
 ReachParameters, invariant, lp_solver_type_choosen);
 //	cout <<"\nInvariant Exists!!!\n";
 }	//End of Invariant Directions
 col = shm_NewTotalIteration;
 MatrixValue.resize(row, col);

 //omp_set_nested(1);
 int type = lp_solver_type_choosen;
 #pragma omp parallel for
 for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {
 lp_solver s_per_thread_I(type), s_per_thread_U(type), s_per_thread_inv(
 type);
 s_per_thread_I.setMin_Or_Max(2);
 if (!Initial->getIsEmpty()) {//set glpk constraints If not an empty polytope
 s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
 ReachParameters.X0->getColumnVector(),
 ReachParameters.X0->getInEqualitySign());
 }
 s_per_thread_U.setMin_Or_Max(2);
 if (SystemDynamics.U->getIsEmpty()) {	//empty polytope
 //Polytope is empty so no glpk object constraints to be set
 } else {
 s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
 SystemDynamics.U->getColumnVector(),
 SystemDynamics.U->getInEqualitySign());
 }
 double zIInitial = 0.0, zI = 0.0, zV = 0.0;
 double sVariable, s1Variable;
 std::vector<double> r1Variable;	//now single dimension
 r1Variable.resize(dimension);
 std::vector<double> rVariable;
 rVariable.resize(dimension);
 for (int i = 0; i < dimension; i++) {
 rVariable[i] = ReachParameters.Directions(eachDirection, i);
 }
 unsigned int loopIteration = 0;
 sVariable = 0.0; 		//initialize s0
 zIInitial = Omega_Support(ReachParameters, rVariable, Initial,
 SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
 MatrixValue(eachDirection, loopIteration) = zIInitial;
 loopIteration++;
 for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
 double TempOmega;
 //		std::cout<<"\tHello = "<<loopIteration;
 ReachParameters.phi_trans.mult_vector(rVariable, r1Variable);
 * Precompute beta and send it as parameter
 zV = W_Support(ReachParameters, SystemDynamics, rVariable,
 s_per_thread_U, Min_Or_Max);
 //cout<<"zV= "<<zV<<"\t";
 s1Variable = sVariable + zV;
 zI = Omega_Support(ReachParameters, r1Variable, Initial,
 SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
 //	cout<<"zi= "<<zI<<"\t";
 TempOmega = zI + s1Variable; 		//Y1
 MatrixValue(eachDirection, loopIteration) = TempOmega; 		//Y1
 //	std::cout<<TempOmega<<"\t";
 rVariable = CopyVector(r1Variable);		//source to destination
 sVariable = s1Variable;
 loopIteration++;	//for the next Omega-iteration or Time-bound
 }	//end of while for each vector
 //cout<<endl;
 }	//end of pragma omp parallel for

 if (isInvariantExist == true) {		//if invariant exist. Computing
 math::matrix<double> inv_sfm;
 int num_inv = invariant->getColumnVector().size();//number of Invariant's constriants
 inv_sfm.resize(num_inv, shm_NewTotalIteration);
 for (int eachInvDirection = 0; eachInvDirection < num_inv;
 eachInvDirection++) {
 for (unsigned int i = 0; i < shm_NewTotalIteration; i++) {
 inv_sfm(eachInvDirection, i) =
 invariant->getColumnVector()[eachInvDirection];
 }
 }
 //cout<<"\nAmit"<<MatrixValue.size2()<<"\n";
 return template_polyhedra(MatrixValue, inv_sfm,
 ReachParameters.Directions, invariant->getCoeffMatrix());
 //return template_polyhedra(MatrixValue, ReachParameters.TotalDirections, ReachParameters.Directions, invariant->getCoeffMatrix());
 //return template_polyhedra(MatrixValue, ReachParameters.TotalDirections);
 } else {
 MatrixValue.resize(numVectors, shm_NewTotalIteration, true);//but writing or resizing only upto the NewTotalIteration
 return template_polyhedra(MatrixValue, ReachParameters.Directions);
 }
 }
 */

//Optimizing Supp_Func Computation:: Implementation of parallel reachability using OMP approach
const template_polyhedra::ptr reachabilityParallel(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen) {
	//typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	//omp_set_num_threads(numVectors);
	//#pragma omp parallel
	//int tid;
	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
	int Min_Or_Max = 2;

	math::matrix<double> MatrixValue; //Shared Matrix for all child thread
	//size_type row = numVectors, col = shm_NewTotalIteration;
	boost::numeric::ublas::matrix<double>::size_type row = numVectors, col =
			shm_NewTotalIteration;

	if (isInvariantExist == true) { //if invariant exist. Computing
		shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
				ReachParameters, invariant, lp_solver_type_choosen);
		//	cout <<"\nInvariant Exists!!!\n";
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

//omp_set_nested(1);
	int type = lp_solver_type_choosen;
#pragma omp parallel for
	for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {

		double res1, result, term2, result1, term1;
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
		if (SystemDynamics.U->getIsEmpty()) { //empty polytope
			//Polytope is empty so no glpk object constraints to be set
		} else {
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
			//	B_trans.mult_vector(rVariable, Btrans_dir);
			//res1 = ReachParameters.time_step * SystemDynamics.U->computeSupportFunction(Btrans_dir,	s_per_thread_U, s_per_thread_U, Min_Or_Max);
			result1 = term2; //replacement--optimizing
			double beta = ReachParameters.result_beta;
			//double res_beta = beta	* (double) support_unitball_infnorm(rVariable);
			double res_beta = beta * term3b; //replace from Previous step UnitBall
			result = result1 + res_beta + term3c; //Added term3c
			zV = result;
			//  **************  W_Support Function Over  ********************
			s1Variable = sVariable + zV;
			//phi_tau_Transpose.mult_vector(rVariable, r1Variable);
			r1Variable = phi_trans_dir; //replacement--optimizing

			//  **************    Omega Function   ********************
			//res1 = Initial->computeSupportFunction(r1Variable, s_per_thread_I, s_per_thread_U, Min_Or_Max);
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
	if (isInvariantExist == true) { //if invariant exist. Computing
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
		//cout<<"\nAmit"<<MatrixValue.size2()<<"\n";
		return template_polyhedra::ptr(
				new template_polyhedra(MatrixValue, inv_sfm,
						ReachParameters.Directions,
						invariant->getCoeffMatrix()));
		//return template_polyhedra(MatrixValue, ReachParameters.TotalDirections, ReachParameters.Directions, invariant->getCoeffMatrix());
		//return template_polyhedra(MatrixValue, ReachParameters.TotalDirections);
	} else {
		MatrixValue.resize(numVectors, shm_NewTotalIteration, true); //but writing or resizing only upto the NewTotalIteration
		return template_polyhedra::ptr(
				new template_polyhedra(MatrixValue, ReachParameters.Directions));
	}
}

/*
 * Same Code as Above but Called from Nested OMP Parallel FOR
 *
 * todo needs to implement + C of the equation Ax + Bu + C
 */
const template_polyhedra::ptr reachabilityParallel_For_Parallel_Iter_Dir(
		Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen) {
	//typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
	int Min_Or_Max = 2;

	math::matrix<double> MatrixValue; //Shared Matrix for all child thread
	//size_type row = numVectors, col = shm_NewTotalIteration;
	boost::numeric::ublas::matrix<double>::size_type row = numVectors, col =
			shm_NewTotalIteration;
	MatrixValue.resize(row, col);

	if (isInvariantExist == true) { //if invariant exist. Computing
		shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
				ReachParameters, invariant, lp_solver_type_choosen);
	} //End of Invariant Directions
//omp_set_nested(4);
	int type = lp_solver_type_choosen;
#pragma omp parallel for
	for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {
		//std::cout<<"\nNumber of Threads = "<<omp_get_num_threads()<<endl;
		//	std::cout<<"\nThread ID / Each Direction = "<<eachDirection<<endl;
		lp_solver s_per_thread_I(type), s_per_thread_U(type), s_per_thread_inv(
				type);

		s_per_thread_I.setMin_Or_Max(2);
		if (!Initial->getIsEmpty()) { //set glpk constraints If not an empty polytope
			s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
					ReachParameters.X0->getColumnVector(),
					ReachParameters.X0->getInEqualitySign());
		}
		s_per_thread_U.setMin_Or_Max(2);
		if (!SystemDynamics.U->getIsEmpty()) { //empty polytope
			s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
					SystemDynamics.U->getColumnVector(),
					SystemDynamics.U->getInEqualitySign());
		}
		double zIInitial = 0.0, zI = 0.0, zV = 0.0;
		double sVariable, s1Variable;
		//std::cout<<"omp_get_max_active_levels() = "<<omp_get_max_active_levels()<<std::endl;
		//std::cout<<"omp_get_thread_limit() = "<<omp_get_thread_limit()<<std::endl;
		std::vector<double> r1Variable; //now single dimension
		r1Variable.resize(dimension);
		std::vector<double> rVariable;
		rVariable.resize(dimension);
		for (int i = 0; i < dimension; i++) {
			rVariable[i] = ReachParameters.Directions(eachDirection, i);
		}
		unsigned int loopIteration = 0;
		sVariable = 0.0; //initialize s0
		zIInitial = Omega_Support(ReachParameters, rVariable, Initial,
				SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
		MatrixValue(eachDirection, loopIteration) = zIInitial;
		loopIteration++;
		for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
			double TempOmega;
			//		std::cout<<"\tHello = "<<loopIteration;
			ReachParameters.phi_trans.mult_vector(rVariable, r1Variable);
			zV = W_Support(ReachParameters, SystemDynamics, rVariable,
					s_per_thread_U, Min_Or_Max); //cout<<"zV= "<<zV<<"\t";
			s1Variable = sVariable + zV;
			zI = Omega_Support(ReachParameters, r1Variable, Initial,
					SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
			//	cout<<"zi= "<<zI<<"\t";
			TempOmega = zI + s1Variable; //Y1
			MatrixValue(eachDirection, loopIteration) = TempOmega; //Y1
			rVariable = CopyVector(r1Variable); //source to destination
			sVariable = s1Variable;
			loopIteration++; //for the next Omega-iteration or Time-bound
		} //end of while for each vector
		  //cout<<endl;
	} //end of pragma omp parallel for
	  //cout<<"Outside Parallel\n";
	/*
	 * Appending invariant directions and invariant constraints/bounds(alfa)
	 * Goal : To truncate the reachable region within the Invariant region
	 */
	//todo:: Redundant invariant directional constraints to be removed
	if (isInvariantExist == true) { //if invariant exist. Computing
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
		return template_polyhedra::ptr (new template_polyhedra(MatrixValue, inv_sfm,
				ReachParameters.Directions, invariant->getCoeffMatrix()));
		//return template_polyhedra(MatrixValue, ReachParameters.TotalDirections,ReachParameters.Directions, invariant->getCoeffMatrix());
		//return template_polyhedra(MatrixValue, ReachParameters.TotalDirections);
	} else {
		//MatrixValue.resize(numVectors, shm_NewTotalIteration, true);//but writing or resizing only upto the NewTotalIteration
		return template_polyhedra::ptr (new template_polyhedra(MatrixValue, ReachParameters.Directions));
	}

}

/*
 * Implementation of reachability for each partitions can be made parallel using OMP approach
 * Algorithm type = PAR_BY_PARTS
 */

const template_polyhedra::ptr reachabilityPartitions(Dynamics& SystemDynamics,
		polytope::ptr Initial, ReachabilityParameters& ReachParameters,
		polytope::ptr invariant, bool isInvariantExist,
		int lp_solver_type_choosen) {

	std::list<polytope::ptr> polys;
	template_polyhedra::ptr reachability_region;
	unsigned int nVar = 4; //number of variables to partition
	unsigned int p = 2; //number of partitions for each variables(eg 2 for 2 equal halfs or 3 equal halfs,etc
	polys = Partition_BoundingPolytope(Initial, nVar, p);
	cout << "Partitions size = " << polys.size() << endl;
	polytope::ptr initial_set;
	template_polyhedra::ptr Tpoly;
//#pragma omp parallel for
	for (std::list<polytope::ptr>::iterator i = polys.begin(); i != polys.end();
			i++) {
		initial_set = (*i);
		ReachParameters.X0 = initial_set;

		double result_alfa = compute_alfa(ReachParameters.time_step,
				SystemDynamics, initial_set, lp_solver_type_choosen);
		cout << "\ncompute alfa = " << result_alfa << endl;
		ReachParameters.result_alfa = result_alfa;

		Tpoly = reachabilitySequential(SystemDynamics, initial_set,
				ReachParameters, invariant, isInvariantExist,
				lp_solver_type_choosen);

#pragma omp critical
		{
			reachability_region = reachability_region->union_TemplatePolytope(
					Tpoly);
		} //end of pragma for loop
	}
	return reachability_region;
	//No IMPROVEMENT WHERE SEEN BY THIS APPROACH
}

/*
 * Implementation of reachability for each partitions of initial set executed in
 * different partitions of iterations. Also can be made parallel using OMP approach
 * Algorithm type = PAR_BY_PARTS_PAR_ITERS
 */

const template_polyhedra::ptr reachabilityPartitions_par_iters(
		Dynamics& SystemDynamics, polytope::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int partitions_size,
		int lp_solver_type_choosen) {

	std::list<polytope::ptr> polys;
	template_polyhedra::ptr reachability_region;
	unsigned int nVar = 1;
	unsigned int p = 2; //number of partitions for each variables(eg 2 for 2 equal halfs or 3 equal halfs,etc
	polys = Partition_BoundingPolytope(Initial, nVar, p);

	polytope::ptr initial_set;
	template_polyhedra::ptr Tpoly;

	cout << "Partition Done" << endl;
	for (std::list<polytope::ptr>::iterator i = polys.begin(); i != polys.end();
			i++) {
		initial_set = (*i);
		ReachParameters.X0 = initial_set;

		/*Tpoly = reachabilitySequential(SystemDynamics, initial_set,
		 ReachParameters, invariant, isInvariantExist,
		 lp_solver_type_choosen);*/

		Tpoly = reachParallelExplore(SystemDynamics, initial_set,
				ReachParameters, invariant, isInvariantExist, partitions_size,
				PAR_ITER, lp_solver_type_choosen);

		cout << "First round Done" << endl;
#pragma omp critical
		{
			reachability_region = reachability_region->union_TemplatePolytope(
					Tpoly);
		} //end of pragma for loop
	}
	return reachability_region;
}
