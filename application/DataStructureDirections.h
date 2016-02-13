/*
 * DataStructureDirections.h
 *
 *  Created on: 01-May-2014
 *      Author: gurung
 */

#ifndef DATASTRUCTUREDIRECTIONS_H_
#define DATASTRUCTUREDIRECTIONS_H_

#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.cpp"
#include "core_system/continuous/Polytope/Polytope.h"

/*
 * Data Structure required for our Algorithm to improve using the
 * concept of checking glp_optimal
 */
struct D {
	std::vector<double> v;		//the transposed directions
	bool flag_I;	//for Initial polytope i.e., polytope-I
	bool flag_V;	//for Input polytope i.e., polytope-V
	unsigned int R;
	unsigned int C;
};


/* Data Structure required for GPU_SF computation */
struct AllDirection {
	unsigned int dir_no;	//direction number
	unsigned int loop_no;	//loop/iteration number
	std::vector<double> B_trans_dir_previous;		//absence in Loop 1
	std::vector<double> direction;					// common in all loop
	std::vector<double> direction1;					// common in all loop
	std::vector<double> Phi_trans_dir;				// common in all loop
	std::vector<double> B_trans_dir;				// common in all loop
};

/*
 * Parameters to be passed in Reachability Algorithm
 *	Directions : is a Matrix consisting of directions of 'n'-variables.
 *	TimeBound : Total time bound or interval (in terms of Units and not Seconds)
 *	Iterations : Number of Iterations to be computed
 *
 */
struct ReachabilityParameters {
//	bool InvariantExists;		//True If invariant exists otherwise False
	math::matrix<double> Directions;		//List of Template Directions
	//math::matrix<double> InvariantDirections;	//List of Invariant's directions and its negative directions
	math::matrix<double> TotalDirections;		//Directions Template + Invariant Directions(excluding negative of invairants)
//	std::vector<D> AdvanceTransposeDirection;	//All transposed directions
	double TimeBound;
	unsigned int Iterations;
	double time_step; // TimeBound/Iterations
	// the transformation matrix = transpose (exp(A*time_step)) stored as parameter as no better choice of placing this.
	math::matrix<double> phi_trans;
	math::matrix<double> B_trans;// transpose of the matrix B of Dynamics's polytope : placed here for above reason
	math::matrix<double> A_inv;		//inverse of the matrix A
	double result_alfa;		// placed here for the same above reason
	double result_beta;		// placed here for the same above reason
	polytope::ptr X0;  // The polytope representing the initial set
	std::vector<int> Stop_locID;	//List of Locations for which Flowpipe need not be computed
};

struct Dynamics {
	math::matrix<double> MatrixA;
	bool isEmptyMatrixA;	//True if empty, otherwise False
	/** The transformation matrix of the input convex set U */
	math::matrix<double> MatrixB;	//polytope U will determine if MatrixB is empty
	bool isEmptyMatrixB;	//True if empty otherwise False
	polytope::ptr U;
	std::vector<double> C;
	bool isEmptyC;	//True if empty otherwise False

};
struct TransitionDynamics {			//May not be used
	math::matrix<double> Map;	//Assignment mapping
	std::vector<double> w;		//vector w belongs to W
};


struct Optimize_Omega_Support{
	std::vector<double> dir1;
	//std::vector<double> dir2;	//similar directions
	double supp_X0;
	double phi_trans_supp_X0;
	double Btrans_supp_U;
	double input_epsilon;
	double computed_epsilon;	//should be <= input_epsilon
};

#endif /* DATASTRUCTUREDIRECTIONS_H_ */
