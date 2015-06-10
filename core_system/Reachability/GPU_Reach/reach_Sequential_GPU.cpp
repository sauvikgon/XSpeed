/*
 * reach_Sequential_GPU.cpp
 *
 *  Created on: 18-April-2015
 *      Author: amit
 */
#include "core_system/Reachability/GPU_Reach/reach_Sequential_GPU.h"
#include "core_system/math/Gimplex/simplex.cuh"
#include "core_system/math/Bulk_LP_Solver/bulk_LP_Solver.h"

/*
 * Before optimising the duplicate Support Function computation
 */
/*
 template_polyhedra reachabilitySequential_GPU(Dynamics& SystemDynamics,
 supportFunctionProvider::ptr Initial,
 ReachabilityParameters& ReachParameters, polytope::ptr invariant,
 bool isInvariantExist, int lp_solver_type_choosen) {

 typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
 unsigned int NewTotalIteration = ReachParameters.Iterations;
 if (isInvariantExist == true) { //if invariant exist. Computing
 NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
 ReachParameters, invariant, lp_solver_type_choosen);
 } //End of Invariant Directions
 if (NewTotalIteration == 1) {
 template_polyhedra poly_empty;
 return poly_empty; //NO need to proceed Algorithm further
 }

 std::vector<AllDirection> Direction_List;
 Direction_List = get_DirectionList(ReachParameters, NewTotalIteration);
 unsigned int numVectors = ReachParameters.Directions.size1();
 unsigned int totalDirList1 = numVectors * (2 * NewTotalIteration);
 math::matrix<float> List_for_X0(totalDirList1,
 ReachParameters.Directions.size2());
 unsigned int totalDirList2 = numVectors * ((2 * NewTotalIteration) - 1);
 math::matrix<float> List_for_U(totalDirList2,
 ReachParameters.Directions.size2());

 getDirectionList_X0_and_U(Direction_List, numVectors, NewTotalIteration,
 List_for_X0, List_for_U);

 int dimension = Initial->getSystemDimension();
 int Min_Or_Max = 2;
 size_type row = numVectors, col = NewTotalIteration;
 math::matrix<double> MatrixValue(row, col);

 // *********************** GPU computation  *********************
 //result obtained from GPU interface // OMP can also be tried and compared
 std::vector<float> supp_func_X0, supp_func_U;

 Simplex simplex_for_X0(totalDirList1), simplex_for_U(totalDirList2);
 bool U_empty = false;
 simplex_for_X0.setConstratint(ReachParameters.X0->getCoeffMatrix(),
 ReachParameters.X0->getColumnVector());
 if (!SystemDynamics.U->getIsEmpty()) {	//polytope U can be empty set
 simplex_for_U.setConstratint(SystemDynamics.U->getCoeffMatrix(),
 SystemDynamics.U->getColumnVector());
 } else {
 U_empty = true;
 }
 simplex_for_X0.ComputeLP(List_for_X0);
 if (!U_empty)
 simplex_for_U.ComputeLP(List_for_U);

 bulk_lp_solver simplex_for_X0(1), simplex_for_U(1); //1 for GLPK solver	2 for Gurobi
 bool U_empty = false;
 simplex_for_X0.setMaxMin(2);	//2 for Maximum
 simplex_for_X0.setConstratint(ReachParameters.X0->getCoeffMatrix(),
 ReachParameters.X0->getColumnVector());
 if (!SystemDynamics.U->getIsEmpty()) {	//polytope U can be empty set
 simplex_for_U.setMaxMin(2);	//2 for Maximum
 simplex_for_U.setConstratint(SystemDynamics.U->getCoeffMatrix(),
 SystemDynamics.U->getColumnVector());
 } else {
 U_empty = true;
 }
 simplex_for_X0.ComputeLP(List_for_X0);
 if (!U_empty)
 simplex_for_U.ComputeLP(List_for_U);

 supp_func_X0 = simplex_for_X0.getResultAll();
 supp_func_U = simplex_for_U.getResultAll();
 // *********************** GPU computation Over  *********************

 unsigned int index = 0, index_X0 = 0, index_U = 0; //indices upto totalDirList1 and totalDirList2
 double res1;

 for (unsigned int eachDirection = 0; eachDirection < numVectors;
 eachDirection++) {
 double zIInitial = 0.0, zI = 0.0, zV = 0.0;
 double sVariable = 0.0, s1Variable; //initialize s0
 std::vector<double> rVariable(dimension), r1Variable(dimension);
 unsigned int loopIteration = 0;
 //  ************** Omega Function   ********************

 res1 = supp_func_X0[index_X0]; //X0->SF(direction)
 index_X0++;

 double term1, term2, term3, term3a, term3b, res2;

 term1 = supp_func_X0[index_X0]; //X0->SF(phi_trans_dir)
 index_X0++;

 if (!U_empty) {
 term2 = ReachParameters.time_step * supp_func_U[index_U]; //U->SF(Btrans_dir)
 index_U++;
 } else
 term2 = 0;

 term3a = ReachParameters.result_alfa; //compute_alfa(ReachParameters.time_step,system_dynamics,Initial_X0);

 term3b = support_unitball_infnorm(Direction_List[index].direction);
 term3 = term3a * term3b;
 res2 = term1 + term2 + term3;
 //zIInitial = (res1 > res2 ? res1:res2);
 if (res1 > res2)
 zIInitial = res1;
 else
 zIInitial = res2;
 //  ************** Omega Function   ********************

 MatrixValue(eachDirection, loopIteration) = zIInitial;
 index++;
 loopIteration++;
 for (; loopIteration < NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"

 double TempOmega;
 //  ************** W_Support Function   ********************
 double result;
 if (!U_empty) {
 res1 = ReachParameters.time_step * supp_func_U[index_U]; //U->SF(Btrans_dir)
 index_U++;
 } else {
 res1 = 0;
 }
 double beta = ReachParameters.result_beta;
 double res_beta = beta
 * (double) support_unitball_infnorm(
 Direction_List[index - 1].direction);
 result = res1 + res_beta;
 zV = result;
 //  ************** W_Support Function   ********************
 s1Variable = sVariable + zV;
 //  ************** Omega Function   ********************
 //double res1;
 res1 = supp_func_X0[index_X0]; //X0->SF(direction)
 index_X0++;

 double term1, term2, term3, term3a, term3b, res2;

 term1 = supp_func_X0[index_X0]; //X0->SF(phi_trans_dir)
 index_X0++;
 if (!U_empty) {
 term2 = ReachParameters.time_step * supp_func_U[index_U]; //U->SF(Btrans_dir)
 index_U++;
 } else {
 term2 = 0;
 }
 term3a = ReachParameters.result_alfa; //compute_alfa(ReachParameters.time_step,system_dynamics,Initial_X0);

 term3b = support_unitball_infnorm(Direction_List[index].direction);
 term3 = term3a * term3b;
 res2 = term1 + term2 + term3;
 //zIInitial = (res1 > res2 ? res1:res2);
 if (res1 > res2)
 zI = res1;
 else
 zI = res2;
 //  ************** Omega Function   ********************

 TempOmega = zI + s1Variable; //Y1
 MatrixValue(eachDirection, loopIteration) = TempOmega; //Y1

 sVariable = s1Variable;
 index++;
 loopIteration++; //for the next Omega-iteration or Time-bound
 } //end of while for each vector
 }

 * Appending invariant directions and invariant constraints/bounds(alfa)
 ** Goal : To truncate the reachable region within the Invariant region
 if (isInvariantExist == true) { //if invariant exist. Computing
 math::matrix<double> inv_sfm;
 int num_inv = invariant->getColumnVector().size(); //number of Invariant's constriants
 inv_sfm.resize(num_inv, NewTotalIteration);
 for (int eachInvDirection = 0; eachInvDirection < num_inv;
 eachInvDirection++) {
 for (unsigned int i = 0; i < NewTotalIteration; i++) {
 inv_sfm(eachInvDirection, i) =
 invariant->getColumnVector()[eachInvDirection];
 }
 }
 return template_polyhedra(MatrixValue, inv_sfm,
 ReachParameters.Directions, invariant->getCoeffMatrix());
 } else {
 return template_polyhedra(MatrixValue, ReachParameters.Directions);
 }
 }
 */

std::vector<float> bulk_Solver(math::matrix<double> constraint_matrix,
		std::vector<double> boundValue, math::matrix<float> list_obj_funs) {

	unsigned int tot_lp = list_obj_funs.size1();
	std::cout << "Total LPs " << tot_lp << std::endl;
	unsigned int lp_block_size = 4004;	//4004; //183500; //input how many LPs you want to solve at a time ??????
	unsigned int number_of_blocks;
	if (tot_lp % lp_block_size == 0)
		number_of_blocks = tot_lp / lp_block_size;
	else
		number_of_blocks = (tot_lp / lp_block_size) + 1; //TODO:: this last block with less LPs must be taken care
	std::cout << "Total Blocks " << number_of_blocks << std::endl;

	std::list<block_lp> bulk_lps; //list of sub-division of LPs
	struct block_lp myLPList;
	myLPList.block_obj_coeff.resize(lp_block_size, list_obj_funs.size2());
	math::matrix<float> block_obj_coeff(lp_block_size, list_obj_funs.size2());
	unsigned int index = 0;
	for (unsigned int lp_number = 0; lp_number < tot_lp; lp_number++) {
		for (unsigned int i = 0; i < list_obj_funs.size2(); i++) {
			myLPList.block_obj_coeff(index, i) = list_obj_funs(lp_number, i);
		}
		index++;
		if (index == lp_block_size) {
			index = 0;
			bulk_lps.push_back(myLPList);
		}
	} //end of all LPs
	std::list<block_lp_result> bulk_result;
	struct block_lp_result eachBlock;
	eachBlock.results.resize(lp_block_size); //last block will be less

	for (std::list<block_lp>::iterator it = bulk_lps.begin();
			it != bulk_lps.end(); it++) {
		unsigned int bulk_lp_size = (*it).block_obj_coeff.size1();
		Simplex lp_problem(bulk_lp_size);	//GPU computation
		lp_problem.setConstratint(constraint_matrix, boundValue);
		lp_problem.ComputeLP((*it).block_obj_coeff);
		eachBlock.results = lp_problem.getResultAll();
		bulk_result.push_back(eachBlock);
	}

	//TODO::Now create a single std::vector of results
	std::vector<float> res(tot_lp);
	unsigned int index_res = 0;
	for (std::list<block_lp_result>::iterator it = bulk_result.begin();
			it != bulk_result.end(); it++) {
		unsigned int block_result_size = (*it).results.size();
		for (unsigned int i = 0; i < block_result_size; i++) {
			res[index_res] = (*it).results[i];
			index_res++;
		}
	}
	std::cout << "Result size = " << res.size() << std::endl;
	return res;
}

/*
 * After optimising the duplicate Support Function computation
 */

template_polyhedra reachabilitySequential_GPU(Dynamics& SystemDynamics,
		supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,
		bool isInvariantExist, int lp_solver_type_choosen) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	unsigned int NewTotalIteration = ReachParameters.Iterations;
	if (isInvariantExist == true) { //if invariant exist. Computing
		NewTotalIteration = InvariantBoundaryCheck(SystemDynamics, Initial,
				ReachParameters, invariant, lp_solver_type_choosen);
	} //End of Invariant Directions
	if (NewTotalIteration == 1) {
		template_polyhedra poly_empty;
		return poly_empty; //NO need to proceed Algorithm further
	}

	std::vector<AllDirection> Direction_List;
	Direction_List = get_DirectionList(ReachParameters, NewTotalIteration);
	unsigned int numVectors = ReachParameters.Directions.size1();
	unsigned int totalDirList1 = numVectors * (NewTotalIteration + 1); //1 extra for loop1
	math::matrix<float> List_for_X0(totalDirList1,
			ReachParameters.Directions.size2());
	unsigned int totalDirList2 = numVectors * NewTotalIteration; //'n' dirs for each 'n' loops
	math::matrix<float> List_for_U(totalDirList2,
			ReachParameters.Directions.size2());

	getDirectionList_X0_and_U(Direction_List, numVectors, NewTotalIteration,
			List_for_X0, List_for_U); //generates separate list for XO and U

	int dimension = Initial->getSystemDimension();
	int Min_Or_Max = 2;
	size_type row = numVectors, col = NewTotalIteration;
	math::matrix<double> MatrixValue(row, col);

	// *********************** GPU computation  *********************
	//result obtained from GPU interface // OMP can also be tried and compared
	std::vector<float> supp_func_X0, supp_func_U;

	/*	Simplex simplex_for_X0(totalDirList1), simplex_for_U(totalDirList2);
	 bool U_empty = false;
	 simplex_for_X0.setConstratint(ReachParameters.X0->getCoeffMatrix(),
	 ReachParameters.X0->getColumnVector());
	 if (!SystemDynamics.U->getIsEmpty()) { //polytope U can be empty set
	 simplex_for_U.setConstratint(SystemDynamics.U->getCoeffMatrix(),
	 SystemDynamics.U->getColumnVector());
	 } else {
	 U_empty = true;
	 }
	 simplex_for_X0.ComputeLP(List_for_X0);
	 if (!U_empty)
	 simplex_for_U.ComputeLP(List_for_U);

	 supp_func_X0 = simplex_for_X0.getResultAll();
	 supp_func_U = simplex_for_U.getResultAll();*/

	/*std::ofstream dir_file;
	 dir_file.open("/home/amit/Desktop/Binayak/DirectionsMatrix.txt");
	 for (unsigned int i = 0; i < List_for_X0.size1(); i++) {
	 for (unsigned int j = 0; j < List_for_X0.size2(); j++) {
	 dir_file << List_for_X0(i, j) << "  ";
	 }
	 dir_file << std::endl;
	 }
	 dir_file.close();

	 */
// ******** Calling BULK GPU Solver function Which takes care of Dividing into Bulks see the function defined here *******
	//  ****************** ///////////////////// ***************  //
	supp_func_X0 = bulk_Solver(ReachParameters.X0->getCoeffMatrix(),
			ReachParameters.X0->getColumnVector(), List_for_X0);
	bool U_empty = false;
	if (!SystemDynamics.U->getIsEmpty()) { //polytope U can be empty set
		supp_func_U = bulk_Solver(SystemDynamics.U->getCoeffMatrix(),
				SystemDynamics.U->getColumnVector(), List_for_U);
	} else {
		U_empty = true;
	}
	// ******** Calling BULK GPU Solver function ENDS*******

	/* *****************not in use********************
	 simplex_for_X0.bulkSolver(List_for_X0);
	 if (!U_empty)
	 simplex_for_U.bulkSolver(List_for_U);*/

	/*
	 supp_func_X0 = simplex_for_X0.bulkSolver(List_for_X0);
	 if (!U_empty){
	 supp_func_U = simplex_for_U.bulkSolver(List_for_U);
	 }*/
	// *****************not in use********************
	// *********************** GPU computation Over  *********************


// ******* CPU Simplex call :GLPK/Gurobi/Simplex_CPU  *************
/*
	// AMIT GURUNG
  bulk_lp_solver simplex_for_X0(5), simplex_for_U(5); //1 for GLPK solver	2 for Gurobi 5 for Simplex_CPU

	bool U_empty = false;
	simplex_for_X0.setMaxMin(2);	//2 for Maximum
	simplex_for_X0.setConstratint(ReachParameters.X0->getCoeffMatrix(),
			ReachParameters.X0->getColumnVector());
	if (!SystemDynamics.U->getIsEmpty()) {	//polytope U can be empty set
		simplex_for_U.setMaxMin(2);	//2 for Maximum
		simplex_for_U.setConstratint(SystemDynamics.U->getCoeffMatrix(),
				SystemDynamics.U->getColumnVector());
	} else {
		U_empty = true;
	}
	simplex_for_X0.ComputeLP(List_for_X0);
	if (!U_empty)
		simplex_for_U.ComputeLP(List_for_U);

	supp_func_X0 = simplex_for_X0.getResultAll();
	supp_func_U = simplex_for_U.getResultAll();
*/

// ******* CPU Simplex call :GLPK/Gurobi/Simplex_CPU  Ends *************


	unsigned int index = 0, index_X0 = 0, index_U = 0; //indices upto totalDirList1 and totalDirList2
	double res1;

	for (unsigned int eachDirection = 0; eachDirection < numVectors;
			eachDirection++) {
		double zIInitial = 0.0, zI = 0.0, zV = 0.0;
		double sVariable = 0.0, s1Variable; //initialize s0
		std::vector<double> rVariable(dimension), r1Variable(dimension);
		unsigned int loopIteration = 0;
		//  ************** Omega Function   ********************

		res1 = supp_func_X0[index_X0]; //X0->SF(direction)
		index_X0++;

		double term1, term2, term3, term3a, term3b, res2;

		term1 = supp_func_X0[index_X0]; //X0->SF(phi_trans_dir)
		index_X0++;

		if (!U_empty) {
			term2 = ReachParameters.time_step * supp_func_U[index_U]; //U->SF(Btrans_dir)
			index_U++;
		} else
			term2 = 0;

		term3a = ReachParameters.result_alfa; //compute_alfa(ReachParameters.time_step,system_dynamics,Initial_X0);

		term3b = support_unitball_infnorm(Direction_List[index].direction);
		term3 = term3a * term3b;
		res2 = term1 + term2 + term3;
		//zIInitial = (res1 > res2 ? res1:res2);
		if (res1 > res2)
			zIInitial = res1;
		else
			zIInitial = res2;
		//  ************** Omega Function   ********************

		MatrixValue(eachDirection, loopIteration) = zIInitial;
		index++;
		loopIteration++;
		for (; loopIteration < NewTotalIteration;) { //Now stopping condition is only "shm_NewTotalIteration"

			double TempOmega;
			//  ************** W_Support Function   ********************
			double result;
			if (!U_empty) {
				res1 = ReachParameters.time_step * supp_func_U[index_U - 1]; //replace previous value
				//index_U++;
			} else {
				res1 = 0;
			}
			double beta = ReachParameters.result_beta;
			double res_sup;
			if (loopIteration == 1) { //now in loop 2
				res_sup = (double) support_unitball_infnorm(
						Direction_List[index - 1].direction); //can access Direction_List[index - 1].direction
			} else if (loopIteration > 1) { //ie if now in loop 3 and above will not be able to access Direction_List[index - 1].direction
				res_sup = (double) support_unitball_infnorm(
						Direction_List[index - 2].direction); //can access Direction_List[index - 1].direction
			}
			double res_beta = beta * res_sup;
			result = res1 + res_beta;
			zV = result;
			//  ************** W_Support Function   ********************
			s1Variable = sVariable + zV;
			//  ************** Omega Function   ********************
			//double res1;
			res1 = supp_func_X0[index_X0 - 1]; ////replace previous value....  X0->SF(direction)
			//index_X0++;

			double term1, term2, term3, term3a, term3b, res2;

			term1 = supp_func_X0[index_X0]; //X0->SF(phi_trans_dir)
			index_X0++;
			if (!U_empty) {
				term2 = ReachParameters.time_step * supp_func_U[index_U]; //U->SF(Btrans_dir)
				index_U++;
			} else {
				term2 = 0;
			}
			term3a = ReachParameters.result_alfa; //compute_alfa(ReachParameters.time_step,system_dynamics,Initial_X0);

			term3b = support_unitball_infnorm(
					Direction_List[index - 1].Phi_trans_dir);
			term3 = term3a * term3b;
			res2 = term1 + term2 + term3;
			//zIInitial = (res1 > res2 ? res1:res2);
			if (res1 > res2)
				zI = res1;
			else
				zI = res2;
			//  ************** Omega Function   ********************

			TempOmega = zI + s1Variable; //Y1
			MatrixValue(eachDirection, loopIteration) = TempOmega; //Y1

			sVariable = s1Variable;
			index++;
			loopIteration++; //for the next Omega-iteration or Time-bound
		} //end of while for each vector
	}

	/** Appending invariant directions and invariant constraints/bounds(alfa)
	 ** Goal : To truncate the reachable region within the Invariant region	 */
	if (isInvariantExist == true) { //if invariant exist. Computing
		math::matrix<double> inv_sfm;
		int num_inv = invariant->getColumnVector().size(); //number of Invariant's constriants
		inv_sfm.resize(num_inv, NewTotalIteration);
		for (int eachInvDirection = 0; eachInvDirection < num_inv;
				eachInvDirection++) {
			for (unsigned int i = 0; i < NewTotalIteration; i++) {
				inv_sfm(eachInvDirection, i) =
						invariant->getColumnVector()[eachInvDirection];
			}
		}
		return template_polyhedra(MatrixValue, inv_sfm,
				ReachParameters.Directions, invariant->getCoeffMatrix());
	} else {
		return template_polyhedra(MatrixValue, ReachParameters.Directions);
	}
}

