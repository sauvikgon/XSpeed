/*
 * sf_directions.cpp
 *
 *  Created on: 14-Dec-2014
 *      Author: amit
 */

#include "application/sf_directions.h"

std::vector<std::vector<double> > generate_axis_directions(unsigned int N) {
	std::vector<std::vector<double> > directions;
	for (unsigned int i = 0; i < N; i++) {
		std::vector<double> d1(N, 0.0);
		d1[i] = 1;
		directions.push_back(d1);
		std::vector<double> d2(N, 0.0);
		d2[i] = -1;
		directions.push_back(d2);
	}
	return directions;
}

std::vector<std::vector<double> > get_octagonal_directions(unsigned int dim) {
	std::vector<std::vector<double> > mydirs;

	for (unsigned int i = 0; i < dim; i++) {
		for (unsigned int j = i; j < dim; j++) {
			if (i == j) {
				std::vector<double> v1(dim, 0);
				v1[i] = 1;
				mydirs.push_back(v1);
				std::vector<double> v2(dim, 0);
				v2[i] = -1;
				mydirs.push_back(v2);
			} else {

				std::vector<double> v1(dim, 0);
				v1[i] = 1;
				v1[j] = 1;
				mydirs.push_back(v1);

				std::vector<double> v2(dim, 0);
				v2[i] = 1;
				v2[j] = -1;
				mydirs.push_back(v2);

				std::vector<double> v3(dim, 0);
				v3[i] = -1;
				v3[j] = 1;
				mydirs.push_back(v3);

				std::vector<double> v4(dim, 0);
				v4[i] = -1;
				v4[j] = -1;
				mydirs.push_back(v4);
			}

		}
	}
	return mydirs;
}

//iters : required as the iteration size may change due to invariant check
std::vector<D> get_directions(ReachabilityParameters reach_parameter,
		unsigned int iters) {

	int facet_dimension = reach_parameter.Directions.size2(); //the dimension of the System
	unsigned int number_of_facet = reach_parameter.Directions.size1(); //number of directions

	std::vector<D> AllDirect;

	for (unsigned int eachDirection = 0; eachDirection < number_of_facet;
			eachDirection++) {
		std::vector<double> rVariable, r1Variable;
		r1Variable.resize(facet_dimension);
		rVariable.resize(facet_dimension);
		// ******* First direction of the iteration *******
		unsigned int loopIteration = 0;
		struct D newDirection1;
		newDirection1.v.resize(facet_dimension);
		for (int i = 0; i < facet_dimension; i++) {
			rVariable[i] = reach_parameter.Directions(eachDirection, i);
			newDirection1.v[i] = rVariable[i]; //initial direction of the iteration
		}
		//newDirection1.v = rVariable	//this might work
		newDirection1.flag_I = UNSOLVED; //UNSOLVED =0
		newDirection1.flag_V = UNSOLVED; //UNSOLVED =0
		newDirection1.C = loopIteration;
		newDirection1.R = eachDirection;
		AllDirect.push_back(newDirection1);
		//for (loopIteration = 1; loopIteration < reach_parameter.Iterations; loopIteration++) {
		for (loopIteration = 1; loopIteration < iters; loopIteration++) {
			reach_parameter.phi_trans.mult_vector(rVariable, r1Variable);
			struct D newDirection;
			newDirection.v.resize(facet_dimension);
			for (int x = 0; x < facet_dimension; x++) {
				newDirection.v[x] = r1Variable[x]; //initialize the directions
			}
			//newDirection.v = r1Variable;	//this might work
			newDirection.flag_I = UNSOLVED; //UNSOLVED =0
			newDirection.flag_V = UNSOLVED; //UNSOLVED =0
			newDirection.C = loopIteration;
			newDirection.R = eachDirection;
			AllDirect.push_back(newDirection);
			rVariable = CopyVector(r1Variable); //source to destination
			//rVariable = r1Variable;		//might work
		}
	}
	return AllDirect;
}

/*
 * Creates all the list of directions for computing support function using GPU
 */
/*
std::vector<AllDirection> get_DirectionList(
		ReachabilityParameters &ReachParameters, unsigned int newiters) {
	int numVectors = ReachParameters.Directions.size1();
	int dimension = ReachParameters.Directions.size2();
	unsigned int index = 0, total_dirs = numVectors * newiters;
	std::vector<AllDirection> Direction_List(total_dirs);
	math::matrix<double> B_trans, phi_tau_Transpose;
	B_trans = ReachParameters.B_trans;
	phi_tau_Transpose = ReachParameters.phi_trans;
	for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {
		std::vector<double> rVariable(dimension), r1Variable(dimension); //now single dimension
		for (int i = 0; i < dimension; i++) {
			rVariable[i] = ReachParameters.Directions(eachDirection, i);
		}
		unsigned int loopIteration = 0;
		// ********** Omega's Directions  **********************
		Direction_List[index].direction = rVariable;
		std::vector<double> phi_trans_dir, B_trans_dir;
		phi_tau_Transpose.mult_vector(rVariable, phi_trans_dir);
		Direction_List[index].Phi_trans_dir = phi_trans_dir;
		B_trans.mult_vector(rVariable, B_trans_dir);
		Direction_List[index].B_trans_dir = B_trans_dir;

		Direction_List[index].dir_no = eachDirection;
		Direction_List[index].loop_no = loopIteration;
		index++;
		// ********** Omega's Directions End **********************
		loopIteration++;
		for (; loopIteration < newiters;) { //Now stopping condition is only "shm_NewTotalIteration"
			ReachParameters.phi_trans.mult_vector(rVariable, r1Variable);
			// ********** W_Support's Directions  **********************
			std::vector<double> Btrans_dir;
			B_trans.mult_vector(rVariable, Btrans_dir);
			Direction_List[index].B_trans_dir_previous = Btrans_dir;
			// ********** W_Support's Directions End **********************
			// ********** Omega's Directions  **********************
			Direction_List[index].direction = r1Variable;
			std::vector<double> phi_trans_dir1, B_trans_dir1;
			phi_tau_Transpose.mult_vector(r1Variable, phi_trans_dir1);
			Direction_List[index].Phi_trans_dir = phi_trans_dir1;
			B_trans.mult_vector(r1Variable, B_trans_dir1);
			Direction_List[index].B_trans_dir = B_trans_dir1;

			Direction_List[index].dir_no = eachDirection;
			Direction_List[index].loop_no = loopIteration;
			index++;
			// ********** Omega's Directions End **********************
			rVariable = CopyVector(r1Variable); //source to destination
			loopIteration++; //for the next iteration
		} //end of iteration for each direction
	} //end of all directions
	return Direction_List;
}
*/
/*
 * Optimising the Computation within the Loop to avoid duplicate directions
 */
std::vector<AllDirection> get_DirectionList(
		ReachabilityParameters &ReachParameters, unsigned int newiters) {
	int numVectors = ReachParameters.Directions.size1();
	int dimension = ReachParameters.Directions.size2();
	unsigned int index = 0, total_dirs = numVectors * newiters;
	std::vector<AllDirection> Direction_List(total_dirs);
	math::matrix<double> B_trans, phi_tau_Transpose;
	B_trans = ReachParameters.B_trans;
	phi_tau_Transpose = ReachParameters.phi_trans;
	for (int eachDirection = 0; eachDirection < numVectors; eachDirection++) {
		std::vector<double> rVariable(dimension), r1Variable(dimension); //now single dimension
		for (int i = 0; i < dimension; i++) {
			rVariable[i] = ReachParameters.Directions(eachDirection, i);
		}
		unsigned int loopIteration = 0;
		// ********** Omega's Directions  **********************
		Direction_List[index].direction = rVariable;
		std::vector<double> phi_trans_dir, B_trans_dir;
		phi_tau_Transpose.mult_vector(rVariable, phi_trans_dir);
		Direction_List[index].Phi_trans_dir = phi_trans_dir;
		B_trans.mult_vector(rVariable, B_trans_dir);
		Direction_List[index].B_trans_dir = B_trans_dir;

		Direction_List[index].dir_no = eachDirection;
		Direction_List[index].loop_no = loopIteration;
		index++;
		// ********** Omega's Directions End **********************
		loopIteration++;
		for (; loopIteration < newiters;) { //Now stopping condition is only "shm_NewTotalIteration"
	//		ReachParameters.phi_trans.mult_vector(rVariable, r1Variable);	//replacement from previous step
			r1Variable = phi_trans_dir;	//direct replacement from previous computation
			// ********** W_Support's Directions  **********************
	//		std::vector<double> Btrans_dir;
	//		B_trans.mult_vector(rVariable, Btrans_dir);
	//		Direction_List[index].B_trans_dir_previous = Btrans_dir;	//replacement from previous step
			// ********** W_Support's Directions End **********************

			// ********** Omega's Directions  **********************
		//	Direction_List[index].direction = r1Variable;		//replacement from previous step
			std::vector<double> phi_trans_dir1, B_trans_dir1;
			phi_tau_Transpose.mult_vector(r1Variable, phi_trans_dir);
			Direction_List[index].Phi_trans_dir = phi_trans_dir;
			B_trans.mult_vector(r1Variable, B_trans_dir1);
			Direction_List[index].B_trans_dir = B_trans_dir1;

			Direction_List[index].dir_no = eachDirection;
			Direction_List[index].loop_no = loopIteration;
			index++;
			// ********** Omega's Directions End **********************
			rVariable = CopyVector(r1Variable); //source to destination
			loopIteration++; //for the next iteration
		} //end of iteration for each direction
	} //end of all directions
	return Direction_List;
}



//Computing list of all directions seperately for polytope X0 and U
/*
void getDirectionList_X0_and_U(std::vector<AllDirection> &directionList,
		unsigned int numDirections, unsigned int TotalIterations,
		math::matrix<float> &list_X0, math::matrix<float> &list_U) {
	unsigned int index = 0, loop = 0, index_X0 = 0, index_U = 0;
	unsigned int total_list_X0 = list_X0.size1(); //total number of directions for X0 is [ numDirs * 2 * iters ]
	unsigned int total_list_U = list_U.size1(); //total number of directions for U is [ numDirs * ((2 * iters)-1) ]
	std::vector<double> tempdir;

	for (unsigned int i = 0; i < numDirections; i++) {
		loop = 0;
		tempdir = directionList[index].direction; //need to verify
		for (unsigned int x = 0; x < list_X0.size2(); x++) { //dimension of direction
			list_X0(index_X0, x) = (float) tempdir[x];
		}
		index_X0++; //for next entry
		tempdir = directionList[index].Phi_trans_dir;
		for (unsigned int x = 0; x < list_X0.size2(); x++) { //dimension of direction
			list_X0(index_X0, x) = (float) tempdir[x];
		}
		index_X0++; //for next entry
		tempdir = directionList[index].B_trans_dir;
		for (unsigned int x = 0; x < list_U.size2(); x++) { //dimension of direction
			list_U(index_U, x) = (float) tempdir[x];
		}
		index_U++; //for next entry
		index++;
		loop++;
		for (; loop < TotalIterations;) {
			tempdir = directionList[index].B_trans_dir_previous;
			for (unsigned int x = 0; x < list_U.size2(); x++) { //dimension of direction
				list_U(index_U, x) = (float) tempdir[x];
			}
			index_U++; //for next entry

			tempdir = directionList[index].direction; //need to verify
			for (unsigned int x = 0; x < list_X0.size2(); x++) { //dimension of direction
				list_X0(index_X0, x) = (float) tempdir[x];
			}
			index_X0++; //for next entry
			tempdir = directionList[index].Phi_trans_dir;
			for (unsigned int x = 0; x < list_X0.size2(); x++) { //dimension of direction
				list_X0(index_X0, x) = (float) tempdir[x];
			}
			index_X0++; //for next entry
			tempdir = directionList[index].B_trans_dir;
			for (unsigned int x = 0; x < list_U.size2(); x++) { //dimension of direction
				list_U(index_U, x) = (float) tempdir[x];
			}
			index_U++; //for next entry
			index++;
			loop++;
		} //end of iterations
	} //end of all directions
//	if ((index_X0 == total_list_X0) && (index_U == total_list_U)) {
//		std::cout << "Directions for GPU computation correctly assigned\n";
//	}
}
*/

/*
 * Optimising the list of all direction for Polytope X0 and U after removing the duplicate.
 */
void getDirectionList_X0_and_U(std::vector<AllDirection> &directionList,
		unsigned int numDirections, unsigned int TotalIterations,
		math::matrix<float> &list_X0, math::matrix<float> &list_U) {
	unsigned int index = 0, loop = 0, index_X0 = 0, index_U = 0;
	unsigned int total_list_X0 = list_X0.size1(); //total number of directions for X0 is [ numDirs * (iters+1) ]
	unsigned int total_list_U = list_U.size1(); //total number of directions for U is [ numDirs * iters ]
	std::vector<double> tempdir;

	for (unsigned int i = 0; i < numDirections; i++) {
		loop = 0;
		tempdir = directionList[index].direction; //need to verify
		for (unsigned int x = 0; x < list_X0.size2(); x++) { //dimension of direction
			list_X0(index_X0, x) = (float) tempdir[x];
		}
		index_X0++; //for next entry
		tempdir = directionList[index].Phi_trans_dir;
		for (unsigned int x = 0; x < list_X0.size2(); x++) { //dimension of direction
			list_X0(index_X0, x) = (float) tempdir[x];
		}
		index_X0++; //for next entry
		tempdir = directionList[index].B_trans_dir;
		for (unsigned int x = 0; x < list_U.size2(); x++) { //dimension of direction
			list_U(index_U, x) = (float) tempdir[x];
		}
		index_U++; //for next entry
		index++;
		loop++;
		for (; loop < TotalIterations;) {
			tempdir = directionList[index].Phi_trans_dir;
			for (unsigned int x = 0; x < list_X0.size2(); x++) { //dimension of direction
				list_X0(index_X0, x) = (float) tempdir[x];
			}
			index_X0++; //for next entry
			tempdir = directionList[index].B_trans_dir;
			for (unsigned int x = 0; x < list_U.size2(); x++) { //dimension of direction
				list_U(index_U, x) = (float) tempdir[x];
			}
			index_U++; //for next entry
			index++;
			loop++;
		} //end of iterations
	} //end of all directions
	/*if ((index_X0 == total_list_X0) && (index_U == total_list_U)) {
		std::cout << "Directions for GPU computation correctly assigned\n";
	}*/
}
