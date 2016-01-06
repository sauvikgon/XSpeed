/*
 * invariantCheck.cpp
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */
#include "invariantBoundaryCheck.h"

unsigned int InvariantBoundaryCheck(Dynamics& SystemDynamics, supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, polytope::ptr invariant,	int lp_solver_type_choosen) {

	unsigned int shm_NewTotalIteration = ReachParameters.Iterations; //Shared Variable for resize iterations number on crossing with invariant
	//int numVectors = ReachParameters.Directions.size1();
	int dimension = Initial->getSystemDimension();
	int Min_Or_Max = 2;
	//int numberOfInvDirections = ReachParameters.InvariantDirections.size1();
	//int numberOfInvariants = numberOfInvDirections / 2;
	int numberOfInvariants = invariant->getColumnVector().size();	//total number of Invariant's constraints
//	cout<<"\nNumber of Invariants = "<< numberOfInvariants<<endl;
//	cout<<"\nInvariants = "<< endl;
/*
	for (int i=0;i<numberOfInvariants;i++)
		for (int j=0;j<invariant->getCoeffMatrix().size2();j++)
		cout<<invariant->getCoeffMatrix()(i,j) <<"\t";
*/

	std::vector<int> boundaryIterations(numberOfInvariants, shm_NewTotalIteration); // size(dimension_size,initial_value)

	int foundStart = 0, intersection_start, intersection_end;

//#pragma omp parallel for
	for (int eachInvariantDirection = 0;
			eachInvariantDirection < numberOfInvariants;
			eachInvariantDirection++) {

		double zIInitial, zI = 0.0, zV = 0.0;
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
			/*rVariable[i] = ReachParameters.InvariantDirections(
					2 * eachInvariantDirection, i);	//First vector positive
			rVariable_minus[i] = ReachParameters.InvariantDirections(
							2 * eachInvariantDirection + 1, i);	//Second vector negative*/
			rVariable[i] = invariant->getCoeffMatrix()(eachInvariantDirection,
								i);	//First vector positive
			rVariable_minus[i] = -1
					* invariant->getCoeffMatrix()(eachInvariantDirection, i); //Second vector negative of First vector
		}
/*
		for (int xx=0;xx<dimension;xx++)
			cout<< rVariable[xx]<<"\t";
*/


		// ******** Lamda Computation for each invariant's directions/constraints **********
			double invariant_SupportFunction;
			int type=lp_solver_type_choosen;
			lp_solver lpSolver(type);

			lpSolver.setMin_Or_Max(2);
			if (!invariant->getIsEmpty() && !invariant->getIsUniverse()) { //set glpk constraints If not an empty polytope
				lpSolver.setConstraints(invariant->getCoeffMatrix(),
						invariant->getColumnVector(), invariant->getInEqualitySign());
				invariant_SupportFunction = invariant->computeSupportFunction(
						rVariable, lpSolver);
			//	std::cout << "Invariant SupportFunction = " << invariant_SupportFunction<< endl;
			}

			// **********************XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX******************


		lp_solver s_per_thread_I(type), s_per_thread_U(type);
// *********************** For Positive Direction ***********************************
		s_per_thread_I.setMin_Or_Max(2);
		if (!Initial->getIsEmpty()) //set glpk constraints If not an empty polytope
			s_per_thread_I.setConstraints(ReachParameters.X0->getCoeffMatrix(),
					ReachParameters.X0->getColumnVector(), ReachParameters.X0->getInEqualitySign());

		s_per_thread_U.setMin_Or_Max(2);
		if (SystemDynamics.U->getIsEmpty()) {	//empty polytope
			//Polytope is empty so no glpk object constraints to be set
		} else {
			s_per_thread_U.setConstraints(SystemDynamics.U->getCoeffMatrix(),
					SystemDynamics.U->getColumnVector(),
					SystemDynamics.U->getInEqualitySign());
		}
//  *****************************************************************************************
		lp_solver s_per_thread_I_minus(type), s_per_thread_U_minus(type);
// *********************** For Negative Direction ***********************************
		s_per_thread_I_minus.setMin_Or_Max(2);
				if (!Initial->getIsEmpty()) //set glpk constraints If not an empty polytope
					s_per_thread_I_minus.setConstraints(ReachParameters.X0->getCoeffMatrix(),
							ReachParameters.X0->getColumnVector(), ReachParameters.X0->getInEqualitySign());

				s_per_thread_U_minus.setMin_Or_Max(2);
				if (SystemDynamics.U->getIsEmpty()) {	//empty polytope
					//Polytope is empty so no glpk object constraints to be set
				} else {
					s_per_thread_U_minus.setConstraints(SystemDynamics.U->getCoeffMatrix(),
							SystemDynamics.U->getColumnVector(),
							SystemDynamics.U->getInEqualitySign());
				}
//  *****************************************************************************************

		unsigned int loopIteration = 0;
		sVariable = 0.0; 		//initialize s0
		sVariable_min = 0.0;
		//cout<<"Testing Location Omega\n";
		zIInitial = Omega_Support(ReachParameters, rVariable, Initial,
				SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
		//	cout<<"z_I_Initial = "<<zIInitial <<endl;
		math::matrix<double> phi_trans;
		phi_trans = ReachParameters.phi_trans;

		//cout<<"\tAmit = "<<zIInitial <<"\n";
//		zValue(eachInvariantDirection, loopIteration) = zIInitial;			//Y0 = pI(r0)
		/*
		 * zIInitial = Omega_Support(time_tou, rVariable_minus, Initial, SystemDynamics, Min_Or_Max);
		 * zValue(eachVector+1,loopIteration) = zIInitial;	//i should store this also
		 */

		loopIteration++;
		while (loopIteration < shm_NewTotalIteration) {	//iterationNum		changed 27 July 2014 for invariant
			// **************** For Positive Direction ***********
			phi_trans.mult_vector(rVariable, r1Variable);
			zV = W_Support(ReachParameters, SystemDynamics, rVariable,
					s_per_thread_U, Min_Or_Max);
			//		cout<<"zV = "<<zV <<"\t";
			s1Variable = sVariable + zV;
			zI = Omega_Support(ReachParameters, r1Variable, Initial,
					SystemDynamics, s_per_thread_I, s_per_thread_U, Min_Or_Max);
			//		cout<<"Actual Omega's Max = "<<zI <<"\t";
			double TempOmega;
			double TempOmega_min;
			TempOmega = zI + s1Variable;	//Y1
			//zValue(eachVector, loopIteration) = TempOmega;	//Y1
			// **************** Positive Direction ***********

			// **************** For Negative Direction ***********
			phi_trans.mult_vector(rVariable_minus, r1Variable_minus);
			zV_min = W_Support(ReachParameters, SystemDynamics, rVariable_minus,
					s_per_thread_U_minus, Min_Or_Max);
			s1Variable_min = sVariable_min + zV_min;
			zI_min = Omega_Support(ReachParameters, r1Variable_minus, Initial,
					SystemDynamics, s_per_thread_I_minus, s_per_thread_U_minus, Min_Or_Max);
			//	cout<<"Actual Omega's Min = "<<zI_min <<"\t";
			TempOmega_min = zI_min + s1Variable_min;	//Y1
			//		cout<<"TempOmega = "<<TempOmega <<"\t";
			//		cout<<"TempOmega_min = "<<TempOmega_min <<"\t";
			//zValue(eachVector+1,loopIteration) = TempOmega_min;	//i should store this also
			//cout<<"TempOmega = "<<TempOmega <<"\t";
			// **************** Negative Direction ***********

			if (((-1 * TempOmega_min) < invariant_SupportFunction) && (invariant_SupportFunction < TempOmega)) {	//Should have been correct
			//if (((-1 * TempOmega_min) < invariant_SupportFunction) && (invariant_SupportFunction < TempOmega)) {
						intersection_start = loopIteration;	//Partially inside the region
				//		zValue(eachInvariantDirection, loopIteration) =	invariant_SupportFunction;//Replace with Invariant boundary
				//	cout<<"\nINTERSECTION_start = "<<intersection_start <<endl;
				//	cout <<"\nTempOmega_Min = "<<-1*TempOmega_min<<"and TempOmega = "<<TempOmega<<endl;
				//	foundStart = 1;
				//}
			}
			if ((-1 * TempOmega_min) > invariant_SupportFunction) {  // Should have been correct
			//if ( ((-1 * TempOmega_min) < invariant_SupportFunction) && (TempOmega < invariant_SupportFunction)) {
				intersection_end = loopIteration;
				//cout << "\nIntersection_End = " << intersection_end << endl;
				//cout <<"\nTempOmega_Min = "<<-1*TempOmega_min<<"and TempOmega = "<<TempOmega<<endl;
				//newTotalIteration = loopIteration - 1;
				//boundaryIterations[eachInvariantDirection] = loopIteration - 1;	 //New iterations limit
				boundaryIterations[eachInvariantDirection] = loopIteration;	 //Made Changes here due to circle
				break;//no need to compute reachable set anymore due to out of invariant boundary
			}

			rVariable = CopyVector(r1Variable);	//source to destination		//Also works   rVariable=r1Variable
			sVariable = s1Variable;
			rVariable_minus = CopyVector(r1Variable_minus);
			sVariable_min = s1Variable_min;

			loopIteration++;	//for the next Omega-iteration or Time-bound

		}	//end of while for each vector
		//	cout<<"\nloopIteration = "<<loopIteration<<endl;
	//	eachInvariantDirection++;	//for the next vector
	}	//end of parallel for each Iterations or Time-Bound
// At the end of the For-Loop or all invariant_Directions we have boundaryIterations vector with the different limit to stop iterations
// The Minimum(boundaryIterations) will be the final Boundary Limit for the number of iterations
	unsigned int min_Total_Iteration;
	min_Total_Iteration = *min_element(boundaryIterations.begin(),boundaryIterations.end());
//	cout<<"\nmin_Total_Iteration = "<<min_Total_Iteration<<endl;
	return min_Total_Iteration;
}




