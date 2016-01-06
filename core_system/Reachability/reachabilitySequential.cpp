/*
 * reachabilitySequential.cpp
 *
 *  Created on: 24-Nov-2014
 *      Author: amit
 */

#include "core_system/Reachability/reachabilitySequential.h"
//#include "Utilities/testPolytopePlotting.h"
/*

 //Un-optimized reachability algorithm
 template_polyhedra reachabilitySequential_UnOptimized(Dynamics& SystemDynamics,
 supportFunctionProvider::ptr Initial,
 ReachabilityParameters& ReachParameters, polytope::ptr invariant,
 bool isInvariantExist, int lp_solver_type_choosen) {

 int numVectors = ReachParameters.Directions.size1();
 int dimension = Initial->getSystemDimension();
 unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
 int Min_Or_Max = 2;

 math::matrix<double> MatrixValue;	//Shared Matrix for all child thread
 size_type row = numVectors, col = shm_NewTotalIteration;
 if (isInvariantExist == true) {	//if invariant exist. Computing

 //		 * Computing support function for polytope for the pair of invairant's direction
 //		 * to determine the iteration's number at which the polytope is completely outside the invariant's region
 //		 * and setting the newIteration number as the value obtained here.

 shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
 ReachParameters, invariant, lp_solver_type_choosen);
 //	cout <<"\nInvariant Exists!!!\n";
 }	//End of Invariant Directions

 if (shm_NewTotalIteration == 1) {
 template_polyhedra poly_emptyp;
 return poly_emptyp;
 }

 col = shm_NewTotalIteration;	//if invariant exist col will be resized
 MatrixValue.resize(row, col);

 //	cout <<"\nInvariant DOES NOT Exists!!!\n";
 //std::cout<<"\nCrossing Iteration = "<< shm_NewTotalIteration << std::endl;
 int solver_type = lp_solver_type_choosen;
 lp_solver s_per_thread_I(solver_type), s_per_thread_U(solver_type),
 s_per_thread_inv(solver_type);
 //	glpk_lp_solver s_per_thread_I, s_per_thread_U, s_per_thread_inv;

 s_per_thread_I.setMin_Or_Max(2);
 if (!ReachParameters.X0->getIsEmpty()) //set glpk constraints If not an empty polytope
 s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
 ReachParameters.X0->getColumnVector(),
 ReachParameters.X0->getInEqualitySign());

 s_per_thread_U.setMin_Or_Max(2);
 if (SystemDynamics.U->getIsEmpty()) {	//empty polytope
 //Polytope is empty so no glpk object constraints to be set
 } else {
 s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
 SystemDynamics.U->getColumnVector(),
 SystemDynamics.U->getInEqualitySign());
 }

 //GeneratePolytopePlotter(ReachParameters.X0);

 //cout<<"count = "<<lp_solver::lp_solver_count<<endl;
 //int a; cin>>a;
 for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {

 double zIInitial = 0.0, zI = 0.0, zV = 0.0;
 double sVariable, s1Variable;
 //	std::cout<<"\nCheck 1"<<endl;
 std::vector<double> r1Variable;	//now single dimension
 r1Variable.resize(dimension);
 std::vector<double> rVariable;
 rVariable.resize(dimension);
 //	cout<<"(";
 for (int i = 0; i < dimension; i++) {
 rVariable[i] = ReachParameters.Directions(eachDirection, i);
 //	cout<<ReachParameters.Directions(eachDirection, i)<<" , ";
 }
 //	cout<<")"<<endl;
 unsigned int loopIteration = 0;
 sVariable = 0.0; 		//initialize s0
 //	cout<<"\nOmega_Support(EachDirection) = "<<eachDirection<<endl;
 zIInitial = Omega_Support(ReachParameters, rVariable, Initial,
 SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
 //		cout<<"count = "<<lp_solver::lp_solver_count<<endl;
 //		int aa; cin>>aa;
 //cout<<"Above Only Initial output\n";
 MatrixValue(eachDirection, loopIteration) = zIInitial;
 //	std::cout<<"\n SFM = "<<zIInitial<<"\t";
 //std::cout<<"\nOmega Support Matrix Value= "<<MatrixValue(eachDirection, loopIteration)<<endl;
 //sf_vals[loopIteration] = zIInitial; 		//Y0 = pI(r0)
 loopIteration++;
 //while (loopIteration < shm_NewTotalIteration) { //Now stopping condition is only "shm_NewTotalIteration"
 for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
 double TempOmega;
 //		std::cout<<"\tHello = "<<loopIteration;
 ReachParameters.phi_trans.mult_vector(rVariable, r1Variable);
 zV = W_Support(ReachParameters, SystemDynamics, rVariable,
 s_per_thread_U, Min_Or_Max);
 //		cout<<"zV= "<<zV<<"\t";
 s1Variable = sVariable + zV;
 zI = Omega_Support(ReachParameters, r1Variable, Initial,
 SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
 //		cout<<"zi= "<<zI<<"\t";
 TempOmega = zI + s1Variable; 		//Y1
 MatrixValue(eachDirection, loopIteration) = TempOmega; 		//Y1
 //	std::cout<<TempOmega<<"\t";
 rVariable = CopyVector(r1Variable);		//source to destination
 sVariable = s1Variable;
 loopIteration++;	//for the next Omega-iteration or Time-bound

 }	//end of while for each vector

 //cout<<endl;
 }

 if (isInvariantExist == true) {		//if invariant exist. Computing
 math::matrix<double> inv_sfm;
 //ReachParameters.TotalDirections = ReachParameters.Directions;
 //int lastDirs = ReachParameters.TotalDirections.size1() - 1;	//total number of rows (0 to rows-1)
 int num_inv = invariant->getColumnVector().size(); //number of Invariant's constriants
 inv_sfm.resize(num_inv, shm_NewTotalIteration);

 //int newDirectionSize = lastDirs + 1 + num_inv;
 //ReachParameters.TotalDirections.resize(newDirectionSize, dimension,true);
 //MatrixValue.resize(newDirectionSize, shm_NewTotalIteration, true);//Matrix resized
 for (int eachInvDirection = 0; eachInvDirection < num_inv;
 eachInvDirection++) {
 //for (int i = 0; i < dimension; i++) {
 //	ReachParameters.TotalDirections(lastDirs + eachInvDirection + 1,
 //			i) = invariant->getCoeffMatrix()(eachInvDirection, i);
 //}
 for (unsigned int i = 0; i < shm_NewTotalIteration; i++) {
 //MatrixValue(lastDirs + eachInvDirection + 1, i) = invariant->getColumnVector()[eachInvDirection];
 inv_sfm(eachInvDirection, i) =
 invariant->getColumnVector()[eachInvDirection];
 }
 }
 //cout<<"\nAmit"<<MatrixValue.size2()<<"\n";
 return template_polyhedra(MatrixValue, inv_sfm,
 ReachParameters.Directions, invariant->getCoeffMatrix());
 //return template_polyhedra(MatrixValue, ReachParameters.TotalDirections,ReachParameters.Directions,invariant->getCoeffMatrix());
 //return template_polyhedra(MatrixValue, ReachParameters.TotalDirections);
 } else {
 return template_polyhedra(MatrixValue, ReachParameters.Directions);
 }
 }
 */

//Reachability Algorithm after optimization of the duplicate support function computation
template_polyhedra::ptr reachabilitySequential(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen) {

	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
	int Min_Or_Max = 2;

	math::matrix<double> MatrixValue; //Shared Matrix for all child thread
	size_type row = numVectors, col = shm_NewTotalIteration;
//	cout << "\nBefore calling InvariantBoundaryCheck"<< "\n";
	if (isInvariantExist == true) { //if invariant exist. Computing
		shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
				ReachParameters, invariant, lp_solver_type_choosen);
		shm_NewTotalIteration = shm_NewTotalIteration - 1;//because Omega_0 is computed in all cases which is 1 extra
	} //End of Invariant Directions
	cout << "\nNew shm_NewTotalIteration = " << shm_NewTotalIteration << "\n";
	if (shm_NewTotalIteration < 1) {
		template_polyhedra::ptr poly_emptyp;
		return poly_emptyp;
	}

	col = shm_NewTotalIteration; //if invariant exist col will be resized
	MatrixValue.resize(row, col);
	int solver_type = lp_solver_type_choosen;
	lp_solver s_per_thread_I(solver_type), s_per_thread_U(solver_type),
			s_per_thread_inv(solver_type);
	s_per_thread_I.setMin_Or_Max(2);
	if (!ReachParameters.X0->getIsEmpty()) //set glpk constraints If not an empty polytope
		s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
				ReachParameters.X0->getColumnVector(),
				ReachParameters.X0->getInEqualitySign());

	s_per_thread_U.setMin_Or_Max(2);
	if (!SystemDynamics.U->getIsEmpty()) { //empty polytope
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
					* SystemDynamics.U->computeSupportFunction(Btrans_dir,s_per_thread_U);
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
		MatrixValue(eachDirection, loopIteration) = zIInitial;
		loopIteration++;
		for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
			double TempOmega;
			//  **************    W_Support Function   ********************
			//	std::vector<double> trans_dir;
			//	B_trans.mult_vector(rVariable, Btrans_dir);
			//res1 = ReachParameters.time_step * SystemDynamics.U->computeSupportFunction(Btrans_dir,	s_per_thread_U, s_per_thread_U, Min_Or_Max);
			result1 = term2;
			double beta = ReachParameters.result_beta;
			//double res_beta = beta * (double) support_unitball_infnorm(rVariable);
			double res_beta = beta * term3b; //Replacing term3b from previous step
			result = result1 + res_beta + term3c; //Added term3c
			zV = result;
			//  **************  W_Support Function Over  ********************
			s1Variable = sVariable + zV;
			//phi_tau_Transpose.mult_vector(rVariable, r1Variable);
			r1Variable = phi_trans_dir;
			//  **************    Omega Function   ********************
			//res1 = Initial->computeSupportFunction(r1Variable, s_per_thread_I, s_per_thread_U, Min_Or_Max);
			res1 = term1;
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
	if (isInvariantExist == true) { //if invariant exist. Computing
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
 * Code BEFORE optimising the support function computation
 * Same Code as above but with critical region in InvariantExist block
 */
/*

 template_polyhedra reachabilitySequential_For_Parallel_Iterations(
 Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
 ReachabilityParameters& ReachParameters, polytope::ptr invariant,
 bool isInvariantExist, int lp_solver_type_choosen) {
 int numVectors = ReachParameters.Directions.size1();
 int dimension = Initial->getSystemDimension();
 unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
 int Min_Or_Max = 2;

 math::matrix<double> MatrixValue; //Shared Matrix for all child thread
 size_type row = numVectors, col = shm_NewTotalIteration;
 MatrixValue.resize(row, col);

 if (isInvariantExist == true) { //if invariant exist. Computing

 shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
 ReachParameters, invariant, lp_solver_type_choosen);
 //	cout <<"\nInvariant Exists!!!\n";
 } //End of Invariant Directions
 int solver_type = lp_solver_type_choosen;

 for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {
 //	std::cout<<"\nThread ID / Each Direction = "<<eachDirection<<endl;
 //int tid = omp_get_thread_num();		//tid is the number of Vectors/Directions

 lp_solver s_per_thread_I(solver_type), s_per_thread_U(solver_type),
 s_per_thread_inv(solver_type);

 s_per_thread_I.setMin_Or_Max(2);
 if (!ReachParameters.X0->getIsEmpty()) //set glpk constraints If not an empty polytope
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

 double zIInitial = 0.0, zI = 0.0, zV = 0.0;
 double sVariable, s1Variable;
 //	std::cout<<"\nCheck 1"<<endl;
 std::vector<double> r1Variable; //now single dimension
 r1Variable.resize(dimension);
 std::vector<double> rVariable;
 rVariable.resize(dimension);
 //	cout<<"(";
 for (int i = 0; i < dimension; i++) {
 rVariable[i] = ReachParameters.Directions(eachDirection, i);
 //	cout<<ReachParameters.Directions(eachDirection, i)<<" , ";
 }
 //	cout<<")"<<endl;
 unsigned int loopIteration = 0;
 sVariable = 0.0; //initialize s0
 //	cout<<"\nOmega_Support(EachDirection) = "<<eachDirection<<endl;
 zIInitial = Omega_Support(ReachParameters, rVariable, Initial,
 SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
 //cout<<"Above Only Initial output\n";
 MatrixValue(eachDirection, loopIteration) = zIInitial;
 //	std::cout<<"\n SFM = "<<zIInitial<<"\t";
 //std::cout<<"\nOmega Support Matrix Value= "<<MatrixValue(eachDirection, loopIteration)<<endl;
 //sf_vals[loopIteration] = zIInitial; 		//Y0 = pI(r0)
 loopIteration++;
 //while (loopIteration < shm_NewTotalIteration) { //Now stopping condition is only "shm_NewTotalIteration"
 for (; loopIteration < shm_NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"
 double TempOmega;
 //		std::cout<<"\tHello = "<<loopIteration;
 ReachParameters.phi_trans.mult_vector(rVariable, r1Variable);
 * Precompute beta and send it as parameter
 zV = W_Support(ReachParameters, SystemDynamics, rVariable,
 s_per_thread_U, Min_Or_Max);
 //		cout<<"zV= "<<zV<<"\t";
 s1Variable = sVariable + zV;
 zI = Omega_Support(ReachParameters, r1Variable, Initial,
 SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
 //		cout<<"zi= "<<zI<<"\t";
 TempOmega = zI + s1Variable; //Y1
 MatrixValue(eachDirection, loopIteration) = TempOmega; //Y1
 //	std::cout<<TempOmega<<"\t";
 rVariable = CopyVector(r1Variable); //source to destination
 sVariable = s1Variable;
 loopIteration++; //for the next Omega-iteration or Time-bound
 } //end of while for each vector
 //cout<<endl;
 }

 template_polyhedra tpolys;
 #pragma omp critical
 {//this critical is used when we call the module PAR_ITER as we are updating the variable ReachParameters
 //and MatrixValue if this function is called from the module SEQ this #pragma will be ignored
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
 tpolys.setTemplateDirections(ReachParameters.Directions);
 tpolys.setMatrixSupportFunction(MatrixValue);
 tpolys.setInvariantDirections(invariant->getCoeffMatrix());
 tpolys.setMatrix_InvariantBound(inv_sfm);
 //return template_polyhedra(MatrixValue, inv_sfm,ReachParameters.Directions, invariant->getCoeffMatrix());
 //return template_polyhedra(MatrixValue, ReachParameters.TotalDirections);
 } else {
 tpolys.setTemplateDirections(ReachParameters.Directions);
 tpolys.setMatrixSupportFunction(MatrixValue);
 //return template_polyhedra(MatrixValue, ReachParameters.Directions);
 }
 } //end of the Critical Section
 return tpolys;
 }
 */

/*
 * Code AFTER optimising the support function computation
 * Same Code as above but with critical region in InvariantExist block
 */
template_polyhedra::ptr reachabilitySequential_For_Parallel_Iterations(
		Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen) {

	int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
	int Min_Or_Max = 2;

	math::matrix<double> MatrixValue; //Shared Matrix for all child thread
	size_type row = numVectors, col = shm_NewTotalIteration;
	MatrixValue.resize(row, col);

	if (isInvariantExist == true) { //if invariant exist. Computing
		shm_NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
				ReachParameters, invariant, lp_solver_type_choosen);
	} //End of Invariant Directions
	if (shm_NewTotalIteration == 1) {
		template_polyhedra::ptr poly_emptyp;
		return poly_emptyp;
	}

	int solver_type = lp_solver_type_choosen;

	lp_solver s_per_thread_I(solver_type), s_per_thread_U(solver_type),
			s_per_thread_inv(solver_type);
	s_per_thread_I.setMin_Or_Max(2);
	if (!ReachParameters.X0->getIsEmpty()) //set glpk constraints If not an empty polytope
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

	double res1, result, term2, result1, term1;
	std::vector<double> Btrans_dir, phi_trans_dir, phi_trans_dir1;
	math::matrix<double> B_trans, phi_tau_Transpose;
	phi_tau_Transpose = ReachParameters.phi_trans;
	B_trans = ReachParameters.B_trans;

	for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {

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
					* SystemDynamics.U->computeSupportFunction(Btrans_dir,s_per_thread_U);

		term3a = ReachParameters.result_alfa;
		term3b = support_unitball_infnorm(rVariable);
		if (!SystemDynamics.isEmptyC) {
			term3c = ReachParameters.time_step
					* dot_product(SystemDynamics.C, rVariable); //Added +tau* sf_C(l) 8/11/2015
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
			//	std::vector<double> trans_dir;
			//	B_trans.mult_vector(rVariable, Btrans_dir);
			//res1 = ReachParameters.time_step * SystemDynamics.U->computeSupportFunction(Btrans_dir,	s_per_thread_U, s_per_thread_U, Min_Or_Max);
			result1 = term2;
			double beta = ReachParameters.result_beta;
			//double res_beta = beta	* (double) support_unitball_infnorm(rVariable);
			double res_beta = beta * term3b; //replace from previous steps UnitBall
			result = result1 + res_beta + term3c; //Added term3c
			zV = result;
			//  **************  W_Support Function Over  ********************
			s1Variable = sVariable + zV;

			//phi_tau_Transpose.mult_vector(rVariable, r1Variable);
			r1Variable = phi_trans_dir; //replacement

			//  **************    Omega Function   ********************
			//res1 = Initial->computeSupportFunction(r1Variable, s_per_thread_I, s_per_thread_U, Min_Or_Max);
			res1 = term1; //replacement

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
		} //end of for each iteration
	} //end of for all directions

	template_polyhedra::ptr tpolys;
#pragma omp critical
	{/*this critical is used when we call the module PAR_ITER as we are updating the variable ReachParameters
	 and MatrixValue if this function is called from the module SEQ this #pragma will be ignored*/
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
			tpolys->setTemplateDirections(ReachParameters.Directions);
			tpolys->setMatrixSupportFunction(MatrixValue);
			tpolys->setInvariantDirections(invariant->getCoeffMatrix());
			tpolys->setMatrix_InvariantBound(inv_sfm);
			//return template_polyhedra(MatrixValue, inv_sfm,ReachParameters.Directions, invariant->getCoeffMatrix());
			//return template_polyhedra(MatrixValue, ReachParameters.TotalDirections);
		} else {
			tpolys->setTemplateDirections(ReachParameters.Directions);
			tpolys->setMatrixSupportFunction(MatrixValue);
			//return template_polyhedra(MatrixValue, ReachParameters.Directions);
		}
	} //end of the Critical Section
	return tpolys;
}
