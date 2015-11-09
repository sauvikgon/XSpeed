/*
 * NavigationBenchmark.cpp
 *
 *  Created on: 25-Nov-2014
 *      Author: amit
 *
 *      The Grid of the Navigation model of 5 x 5 is labeled as below *
 *      	2 4 6 6 6
 *      	2 4 7 7 4
 *   		2 4 B 3 4
 *   		2 4 6 6 6
 *   		2 A 0 0 0
 */

#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark4Var.h"

/*
 * velocity x1 in the x-axis directions and velocity x2 in the y-coordinate directions
 * So the system has Four variables, (x,y) the positions and (x1,x2) the velocities.
 */

//converted ::  Input Polytope U into 4 Variables.
//		Balanced Flow Equations into 4x4 for A and B
//		Invariants converted to 4 Variables
//		Similarly Guard is also converted to 4 Variables
void SetNavigationModel5by5(hybrid_automata& Hybrid_Automata,
		symbolic_states& initial_symbolic_state,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	polytope::ptr initial_polytope_I, invariant, gaurd_polytope;
	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, gaurdConstraintsMatrix, Amatrix,
			Bmatrix;
	std::vector<double> boundValueI, boundValueV, invariantBoundValue,
			gaurdBoundValue;
	int boundSignI, invariantBoundSign, gaurdBoundSign, boundSignV;

	size_type row, col;

	//Polytope I Declaration in the form of Ax<=b
	//Input Polytope I as a point(x,y,x1,x2) (0.2 <=x<=0.6,0.1<=y<=0.5,x1==0,x2==0) in the grid of cells
	row = 8;
	col = 4;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(0, 2) = 0;
	ConstraintsMatrixI(0, 3) = 0;

	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(1, 2) = 0;
	ConstraintsMatrixI(1, 3) = 0;

	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(2, 2) = 0;
	ConstraintsMatrixI(2, 3) = 0;

	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(3, 2) = 0;
	ConstraintsMatrixI(3, 3) = 0;

	ConstraintsMatrixI(4, 0) = 0;
	ConstraintsMatrixI(4, 1) = 0;
	ConstraintsMatrixI(4, 2) = 1;
	ConstraintsMatrixI(4, 3) = 0;

	ConstraintsMatrixI(5, 0) = 0;
	ConstraintsMatrixI(5, 1) = 0;
	ConstraintsMatrixI(5, 2) = -1;
	ConstraintsMatrixI(5, 3) = 0;

	ConstraintsMatrixI(6, 0) = 0;
	ConstraintsMatrixI(6, 1) = 0;
	ConstraintsMatrixI(6, 2) = 0;
	ConstraintsMatrixI(6, 3) = 1;

	ConstraintsMatrixI(7, 0) = 0;
	ConstraintsMatrixI(7, 1) = 0;
	ConstraintsMatrixI(7, 2) = 0;
	ConstraintsMatrixI(7, 3) = -1;

	discrete_set d_set;

	//d_set.insert_element(6);		//the initial Location ID = 6

	boundValueI.resize(row);

	// ********************* start_location=19:: (3.5 <=x1<=3.5, 3.5<=x2<=3.5, 1<=v1<=1, 1<=v2<=1) ************************
	d_set.insert_element(19);	//the initial Location ID = 19
	boundValueI[0] = 3.5; // ************ :: (3.5<=x1<=3.5 & 3.5<=x2<=3.5 & 1<=v1<=1 & 0.1<=v2<=0.1) ************************
	boundValueI[1] = -3.5;
	boundValueI[2] = 3.5;
	boundValueI[3] = -3.5;
	boundValueI[4] = 1;
	boundValueI[5] = -1;
	boundValueI[6] = 0.1;
	boundValueI[7] = -0.1;

	boundSignI = 1;
	initial_polytope_I = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));
	//initial_polytope_I.setPolytope(ConstraintsMatrixI, boundValueI, boundSignI);

	/*	*************** Common Parameter Initialization *******************
	 * Common Parameter for all Locations or transitions
	 * such as Matrix A, Matrix B , Transition_dynamics such as Matrix R and vector w;
	 */
	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0;
	Amatrix(0, 1) = 0;
	Amatrix(0, 2) = 1;
	Amatrix(0, 3) = 0;

	Amatrix(1, 0) = 0;
	Amatrix(1, 1) = 0;
	Amatrix(1, 2) = 0;
	Amatrix(1, 3) = 1;

	Amatrix(2, 0) = 0;
	Amatrix(2, 1) = 0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;

	Amatrix(3, 0) = 0;
	Amatrix(3, 1) = 0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;

	row = 4;
	col = 4;
	Bmatrix.resize(row, col);
	Bmatrix(0, 0) = 0;
	Bmatrix(0, 1) = 0;
	Bmatrix(0, 2) = 0;
	Bmatrix(0, 3) = 0;

	Bmatrix(1, 0) = 0;
	Bmatrix(1, 1) = 0;
	Bmatrix(1, 2) = 0;
	Bmatrix(1, 3) = 0;

	Bmatrix(2, 0) = 0;
	Bmatrix(2, 1) = 0;
	Bmatrix(2, 2) = -0.8;
	Bmatrix(2, 3) = -0.2;

	Bmatrix(3, 0) = 0;
	Bmatrix(3, 1) = 0;
	Bmatrix(3, 2) = -0.1;
	Bmatrix(3, 3) = -0.8;

	//Bmatrix = Amatrix;

	math::matrix<double> R; //Transition Dynamics
	row = 4;
	col = 4;
	R.resize(row, col);
	R(0, 0) = 1;
	R(0, 1) = 0;
	R(0, 2) = 0;
	R(0, 3) = 0;

	R(1, 0) = 0;
	R(1, 1) = 1;
	R(1, 2) = 0;
	R(1, 3) = 0;

	R(2, 0) = 0;
	R(2, 1) = 0;
	R(2, 2) = 1;
	R(2, 3) = 0;

	R(3, 0) = 0;
	R(3, 1) = 0;
	R(3, 2) = 0;
	R(3, 3) = 1;

	std::vector<double> w(row);
	w[0] = 0;
	w[1] = 0;
	w[2] = 0;
	w[3] = 0;

	Assign assignment;
	assignment.Map = R;
	assignment.b = w;

// ***********************************************************

	/*	*************** Initialization of all Transitions *******************
	 *  List of Transitions are t1, t2, ... , t73 including transitions towards the Locations labelled "A" and "B"
	 *  where Label "A" is the "Final location" to be reached and "B" the "Bad location" to be avoided.
	 */
	row = 8;
	col = 4;
	gaurdConstraintsMatrix.resize(row, col); //this matrix will be common for all transition except the gaurdBoundValue.
	gaurdConstraintsMatrix(0, 0) = 1;
	gaurdConstraintsMatrix(0, 1) = 0;
	gaurdConstraintsMatrix(0, 2) = 0;
	gaurdConstraintsMatrix(0, 3) = 0;

	gaurdConstraintsMatrix(1, 0) = -1;
	gaurdConstraintsMatrix(1, 1) = 0;
	gaurdConstraintsMatrix(1, 2) = 0;
	gaurdConstraintsMatrix(1, 3) = 0;

	gaurdConstraintsMatrix(2, 0) = 0;
	gaurdConstraintsMatrix(2, 1) = 1;
	gaurdConstraintsMatrix(2, 2) = 0;
	gaurdConstraintsMatrix(2, 3) = 0;

	gaurdConstraintsMatrix(3, 0) = 0;
	gaurdConstraintsMatrix(3, 1) = -1;
	gaurdConstraintsMatrix(3, 2) = 0;
	gaurdConstraintsMatrix(3, 3) = 0;

	gaurdConstraintsMatrix(4, 0) = 0;
	gaurdConstraintsMatrix(4, 1) = 0;
	gaurdConstraintsMatrix(4, 2) = 1;
	gaurdConstraintsMatrix(4, 3) = 0;

	gaurdConstraintsMatrix(5, 0) = 0;
	gaurdConstraintsMatrix(5, 1) = 0;
	gaurdConstraintsMatrix(5, 2) = -1;
	gaurdConstraintsMatrix(5, 3) = 0;

	gaurdConstraintsMatrix(6, 0) = 0;
	gaurdConstraintsMatrix(6, 1) = 0;
	gaurdConstraintsMatrix(6, 2) = 0;
	gaurdConstraintsMatrix(6, 3) = 1;

	gaurdConstraintsMatrix(7, 0) = 0;
	gaurdConstraintsMatrix(7, 1) = 0;
	gaurdConstraintsMatrix(7, 2) = 0;
	gaurdConstraintsMatrix(7, 3) = -1;

	gaurdBoundSign = 1;
//  ************************* Transition: t1 ***************************************************
	gaurdBoundValue.resize(row); //gaurd is:: V_d[sin(loc_name * pi/4), cos(loc_name * pi/4)]
	gaurdBoundValue[0] = 1; // 0<=x<=1 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t1(1, "1 to 2", 1, 2, gaurd_polytope, assignment);
//  ************************* Transition: t1 End ************************************************
//  ************************* Transition: t2 ***************************************************
	gaurdBoundValue[0] = 1; // x1==1 and 4<=x2<=5 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 5;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t2(2, "1 to 10", 1, 10, gaurd_polytope, assignment);
//  ************************* Transition: t2 End ************************************************
//  ************************* Transition: t3 ***************************************************
	gaurdBoundValue[0] = 1; // 0<=x1<=1 and x2==4 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t3(3, "2 to 1", 2, 1, gaurd_polytope, assignment);
//  ************************* Transition: t3 End ************************************************
//  ************************* Transition: t4 ***************************************************
	gaurdBoundValue[0] = 1; // 0<=x1<=1 and x2==3 and   -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t4(4, "2 to 3", 2, 3, gaurd_polytope, assignment);
//  ************************* Transition: t4 End ************************************************
//  ************************* Transition: t5 ***************************************************
	gaurdBoundValue[0] = 1; // x==1 and 3<=x2<=4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1; //testing  0.95<=x<=1
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t5(5, "2 to 9", 2, 9, gaurd_polytope, assignment);
//  ************************* Transition: t5 End ************************************************
//  ************************* Transition: t6 ***************************************************
	gaurdBoundValue[0] = 1; // 0<=x1<=1 and x2==3 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t6(6, "3 to 2", 3, 2, gaurd_polytope, assignment);
//  ************************* Transition: t6 End ************************************************
//  ************************* Transition: t7 ***************************************************
	gaurdBoundValue[0] = 1; // 0<=x1<=1 and x2==2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t7(7, "3 to 4", 3, 4, gaurd_polytope, assignment);
//  ************************* Transition: t7 End ************************************************
//  ************************* Transition: t8 ***************************************************
	gaurdBoundValue[0] = 1; // x1==1 and 2<=x2<=3 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t8(8, "3 to 8", 3, 8, gaurd_polytope, assignment);
//  ************************* Transition: t8 End ************************************************
//  ************************* Transition: t9 ***************************************************
	gaurdBoundValue[0] = 1; // 0<=x1<=1 and x2==2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t9(9, "4 to 3", 4, 3, gaurd_polytope, assignment);
//  ************************* Transition: t9 End ************************************************
//  ************************* Transition: t10 ***************************************************
	gaurdBoundValue[0] = 1; // 0<=x1<=1 and x2==1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t10(10, "4 to 5", 4, 5, gaurd_polytope, assignment);
//  ************************* Transition: t10 End ************************************************
//  ************************* Transition: t11 ***************************************************
	gaurdBoundValue[0] = 1; // x1==1 and 1<=x2<=2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t11(11, "4 to 7", 4, 7, gaurd_polytope, assignment);
//  ************************* Transition: t11 End ************************************************
//  ************************* Transition: t12 ***************************************************
	gaurdBoundValue[0] = 1; // 0<=x1<=1 and x2==1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t12(12, "5 to 4", 5, 4, gaurd_polytope, assignment);
//  ************************* Transition: t12 End ************************************************
//  ************************* Transition: t13 ***************************************************
	gaurdBoundValue[0] = 1; // x1==1 and 0<=x2<=1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t13(13, "5 to 6", 5, 6, gaurd_polytope, assignment);
//  ************************* Transition: t13 End ************************************************
//  ************************* Transition: t14 ***************************************************
	gaurdBoundValue[0] = 2; // 1<=x1<=2 and x2==2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t14(14, "7 to 8", 7, 8, gaurd_polytope, assignment);
//  ************************* Transition: t14 End ************************************************
//  ************************* Transition: t15 ***************************************************
	gaurdBoundValue[0] = 1; // x1==1 and 1<=x2<=2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t15(15, "7 to 4", 7, 4, gaurd_polytope, assignment);
//  ************************* Transition: t15 End ************************************************
//  ************************* Transition: t16 ***************************************************
	gaurdBoundValue[0] = 2; // 1<=x1<=2 and x2==1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t16(16, "7 to A", 7, 6, gaurd_polytope, assignment);
//  ************************* Transition: t16 End ************************************************
//  ************************* Transition: t17 ***************************************************
	gaurdBoundValue[0] = 2; // x1==2 and 1<=x2<=2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t17(17, "7 to 12", 7, 12, gaurd_polytope, assignment);
//  ************************* Transition: t17 End ***********************************************
//  ************************* Transition: t18 ***************************************************
	gaurdBoundValue[0] = 2; //  1<=x1<=2 and x2==3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t18(18, "8 to 9", 8, 9, gaurd_polytope, assignment);
	//  ************************* Transition: t18 End ***********************************************
	//  ************************* Transition: t19 ***************************************************
	gaurdBoundValue[0] = 1; // x1==1 and 2<=x2<=3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t19(19, "8 to 3", 8, 3, gaurd_polytope, assignment);
//  ************************* Transition: t19 End ***********************************************
//  ************************* Transition: t20 ***************************************************
	gaurdBoundValue[0] = 2; //  1<=x1<=2 and x2==2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t20(20, "8 to 7", 8, 7, gaurd_polytope, assignment);
//  ************************* Transition: t20 End ***********************************************
//  ************************* Transition: t21 ***************************************************
	gaurdBoundValue[0] = 2; //  x1==2 and 2<=x2<=3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t21(21, "8 to B", 8, 13, gaurd_polytope, assignment);
//  ************************* Transition: t21 End ***********************************************
//  ************************* Transition: t22 ***************************************************
	gaurdBoundValue[0] = 2; //  1<=x1<=2 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t22(22, "9 to 10", 9, 10, gaurd_polytope, assignment);
//  ************************* Transition: t22 End ***********************************************
	//  ************************* Transition: t23 ***************************************************
	gaurdBoundValue[0] = 1; // x==1 and 3<=x2<=4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1; //testing  0.95<=x<=1
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t23(23, "9 to 2", 9, 2, gaurd_polytope, assignment);
	//  ************************* Transition: t23 End ************************************************
	//  ************************* Transition: t24 ***************************************************
	gaurdBoundValue[0] = 2; //  1<=x1<=2 and x2==3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t24(18, "9 to 8", 9, 8, gaurd_polytope, assignment);
	//  ************************* Transition: t24 End ***********************************************
	//  ************************* Transition: t25 ***************************************************
	gaurdBoundValue[0] = 2; // x==2 and 3<=x2<=4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2; //testing  0.95<=x<=1
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t25(25, "9 to 14", 9, 14, gaurd_polytope, assignment);
	//  ************************* Transition: t25 End ************************************************
	//  ************************* Transition: t26 ***************************************************
	gaurdBoundValue[0] = 1; // x1==1 and 4<=x2<=5 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 5;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t26(26, "10 to 1", 10, 1, gaurd_polytope, assignment);
	//  ************************* Transition: t26 End ************************************************
	//  ************************* Transition: t27 ***************************************************
	gaurdBoundValue[0] = 2; //  1<=x1<=2 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t27(27, "10 to 9", 10, 9, gaurd_polytope, assignment);
	//  ************************* Transition: t27 End ***********************************************
	//  ************************* Transition: t28 ***************************************************
	gaurdBoundValue[0] = 2; // x1==2 and 4<=x2<=5 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 5;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t28(28, "10 to 15", 10, 1, gaurd_polytope, assignment);
	//  ************************* Transition: t28 End ************************************************
	//  ************************* Transition: t29 ***************************************************
	gaurdBoundValue[0] = 3; //  2<=x1<=3 and x2==1 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t29(29, "11 to 12", 11, 12, gaurd_polytope, assignment);
	//  ************************* Transition: t29 End ***********************************************
	//  ************************* Transition: t30 ***************************************************
	gaurdBoundValue[0] = 2; // x1==2 and 0<=x2<=1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t30(30, "11 to A", 11, 6, gaurd_polytope, assignment);
	//  ************************* Transition: t30 End ************************************************
	//  ************************* Transition: t31 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 0<=x2<=1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t31(31, "11 to 16", 11, 16, gaurd_polytope, assignment);
	//  ************************* Transition: t31 End ************************************************
	//  ************************* Transition: t32 ***************************************************
	gaurdBoundValue[0] = 3; //  2<=x1<=3 and x2==2 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t32(32, "12 to B", 12, 13, gaurd_polytope, assignment);
	//  ************************* Transition: t32 End ***********************************************
	//  ************************* Transition: t33 ***************************************************
	gaurdBoundValue[0] = 2; // x1==2 and 1<=x2<=2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t33(33, "12 to 7", 12, 7, gaurd_polytope, assignment);
	//  ************************* Transition: t33 End ***********************************************
	//  ************************* Transition: t34 ***************************************************
	gaurdBoundValue[0] = 3; //  2<=x1<=3 and x2==1 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t34(34, "12 to 11", 12, 11, gaurd_polytope, assignment);
	//  ************************* Transition: t34 End ***********************************************
	//  ************************* Transition: t35 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 1<=x2<=2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t35(35, "12 to 17", 12, 17, gaurd_polytope, assignment);
	//  ************************* Transition: t35 End ************************************************
	//  ************************* Transition: t36 ***************************************************
	gaurdBoundValue[0] = 3; //  2<=x1<=3 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t36(36, "14 to 15", 14, 15, gaurd_polytope, assignment);
	//  ************************* Transition: t36 End ***********************************************
	//  ************************* Transition: t37 ***************************************************
	gaurdBoundValue[0] = 2; // x==2 and 3<=x2<=4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2; //testing  0.95<=x<=1
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t37(37, "14 to 9", 14, 9, gaurd_polytope, assignment);
	//  ************************* Transition: t37 End ************************************************
	//  ************************* Transition: t38 ***************************************************
	gaurdBoundValue[0] = 3; //  2=x1<=3 and x2==3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t38(38, "14 to B", 14, 13, gaurd_polytope, assignment);
	//  ************************* Transition: t38 End ***********************************************
	//  ************************* Transition: t39 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 3<=x2<=4 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t39(39, "14 to 19", 14, 19, gaurd_polytope, assignment);
	//  ************************* Transition: t39 End ************************************************
	//  ************************* Transition: t40 ***************************************************
	gaurdBoundValue[0] = 2; // x1==2 and 4<=x2<=5 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 5;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t40(40, "15 to 10", 15, 10, gaurd_polytope, assignment);
	//  ************************* Transition: t40 End ************************************************
	//  ************************* Transition: t41 ***************************************************
	gaurdBoundValue[0] = 3; //  2<=x1<=3 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t41(41, "15 to 14", 15, 14, gaurd_polytope, assignment);
	//  ************************* Transition: t41 End ***********************************************
	//  ************************* Transition: t42 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 4<=x2<=5 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 5;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t42(42, "15 to 20", 15, 20, gaurd_polytope, assignment);
	//  ************************* Transition: t42 End ************************************************
	//  ************************* Transition: t43 ***************************************************
	gaurdBoundValue[0] = 4; //  3<=x1<=4 and x2==1 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t43(43, "16 to 17", 16, 17, gaurd_polytope, assignment);
	//  ************************* Transition: t43 End ***********************************************
	//  ************************* Transition: t44 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 0<=x2<=1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t44(44, "16 to 11", 16, 11, gaurd_polytope, assignment);
	//  ************************* Transition: t44 End ************************************************
	//  ************************* Transition: t45 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 0<=x2<=1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t45(45, "16 to 21", 16, 21, gaurd_polytope, assignment);
	//  ************************* Transition: t45 End ************************************************
	//  ************************* Transition: t46 ***************************************************
	gaurdBoundValue[0] = 4; //  3<=x1<=4 and x2==2 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t46(46, "17 to 18", 17, 18, gaurd_polytope, assignment);
	//  ************************* Transition: t46 End ***********************************************
	//  ************************* Transition: t47 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 1<=x2<=2 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t47(47, "17 to 12", 17, 12, gaurd_polytope, assignment);
	//  ************************* Transition: t47 End ************************************************
	//  ************************* Transition: t48 ***************************************************
	gaurdBoundValue[0] = 4; //  3<=x1<=4 and x2==1 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t48(48, "17 to 16", 17, 16, gaurd_polytope, assignment);
	//  ************************* Transition: t48 End ***********************************************
	//  ************************* Transition: t49 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 1<=x2<=2 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t49(49, "17 to 22", 17, 22, gaurd_polytope, assignment);
	//  ************************* Transition: t49 End ************************************************
	//  ************************* Transition: t50 ***************************************************
	gaurdBoundValue[0] = 4; //  3<=x1<=4 and x2==3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t50(50, "18 to 19", 18, 19, gaurd_polytope, assignment);
	//  ************************* Transition: t50 End ***********************************************
	//  ************************* Transition: t51 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 2<=x2<=3 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t51(51, "18 to B", 18, 13, gaurd_polytope, assignment);
	//  ************************* Transition: t51 End ************************************************
	//  ************************* Transition: t52 ***************************************************
	gaurdBoundValue[0] = 4; //  3<=x1<=4 and x2==2 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t52(52, "18 to 17", 18, 17, gaurd_polytope, assignment);
	//  ************************* Transition: t52 End ***********************************************
	//  ************************* Transition: t53 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 2<=x2<=3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t53(53, "18 to 23", 18, 23, gaurd_polytope, assignment);
	//  ************************* Transition: t53 End ************************************************
	//  ************************* Transition: t54 ***************************************************
	gaurdBoundValue[0] = 4; //  3<=x1<=4 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t54(54, "19 to 20", 19, 20, gaurd_polytope, assignment);
	//  ************************* Transition: t54 End ***********************************************
	//  ************************* Transition: t55 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 3<=x2<=4 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t55(55, "19 to 14", 19, 14, gaurd_polytope, assignment);
	//  ************************* Transition: t55 End ************************************************
	//  ************************* Transition: t56 ***************************************************
	gaurdBoundValue[0] = 4; //  3<=x1<=4 and x2==3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t56(56, "19 to 18", 19, 18, gaurd_polytope, assignment);
	//  ************************* Transition: t56 End ***********************************************
	//  ************************* Transition: t57 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 3<=x2<=4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t57(57, "19 to 24", 19, 24, gaurd_polytope, assignment);
	//  ************************* Transition: t57 End ************************************************
	//  ************************* Transition: t58 ***************************************************
	gaurdBoundValue[0] = 3; // x1==3 and 4<=x2<=5 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 5;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t58(58, "20 to 15", 20, 15, gaurd_polytope, assignment);
	//  ************************* Transition: t58 End ************************************************
	//  ************************* Transition: t59 ***************************************************
	gaurdBoundValue[0] = 4; //  3<=x1<=4 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -3;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t59(59, "20 to 19", 20, 19, gaurd_polytope, assignment);
	//  ************************* Transition: t59 End ***********************************************
	//  ************************* Transition: t60 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 4<=x2<=5 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 5;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t60(60, "20 to 25", 20, 25, gaurd_polytope, assignment);
	//  ************************* Transition: t60 End ************************************************
	//  ************************* Transition: t61 ***************************************************
	gaurdBoundValue[0] = 5; //  4<=x1<=5 and x2==1 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t61(61, "21 to 22", 21, 22, gaurd_polytope, assignment);
	//  ************************* Transition: t61 End ***********************************************
	//  ************************* Transition: t62 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 0<=x2<=1 and  -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t62(62, "21 to 16", 21, 16, gaurd_polytope, assignment);
	//  ************************* Transition: t62 End ************************************************
	//  ************************* Transition: t63 ***************************************************
	gaurdBoundValue[0] = 5; //  4<=x1<=5 and x2==2 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t63(63, "22 to 23", 22, 23, gaurd_polytope, assignment);
	//  ************************* Transition: t63 End ***********************************************
	//  ************************* Transition: t64 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 1<=x2<=2 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t64(64, "22 to 17", 22, 17, gaurd_polytope, assignment);
	//  ************************* Transition: t64 End ************************************************
	//  ************************* Transition: t65 ***************************************************
	gaurdBoundValue[0] = 5; //  4<=x1<=5 and x2==1 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t65(65, "22 to 21", 22, 21, gaurd_polytope, assignment);
	//  ************************* Transition: t65 End ***********************************************
	//  ************************* Transition: t66 ***************************************************
	gaurdBoundValue[0] = 5; //  4<=x1<=5 and x2==3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t66(66, "23 to 24", 23, 24, gaurd_polytope, assignment);
	//  ************************* Transition: t66 End ***********************************************
	//  ************************* Transition: t67 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 2<=x2<=3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t67(67, "23 to 18", 23, 18, gaurd_polytope, assignment);
	//  ************************* Transition: t67 End ************************************************
	//  ************************* Transition: t68 ***************************************************
	gaurdBoundValue[0] = 5; //  4<=x1<=5 and x2==2 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t68(68, "23 to 23", 23, 22, gaurd_polytope, assignment);
	//  ************************* Transition: t68 End ***********************************************
	//  ************************* Transition: t69 ***************************************************
	gaurdBoundValue[0] = 5; //  4<=x1<=5 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t69(69, "24 to 25", 24, 25, gaurd_polytope, assignment);
	//  ************************* Transition: t69 End ***********************************************
	//  ************************* Transition: t70 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 3<=x2<=4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t70(70, "24 to 19", 24, 19, gaurd_polytope, assignment);
	//  ************************* Transition: t70 End ************************************************
	//  ************************* Transition: t71 ***************************************************
	gaurdBoundValue[0] = 5; //  4<=x1<=5 and x2==3 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -3;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t71(71, "24 to 23", 24, 23, gaurd_polytope, assignment);
	//  ************************* Transition: t71 End ***********************************************
	//  ************************* Transition: t72 ***************************************************
	gaurdBoundValue[0] = 4; // x1==4 and 4<=x2<=5 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 5;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t72(72, "25 to 20", 25, 20, gaurd_polytope, assignment);
	//  ************************* Transition: t72 End ************************************************
	//  ************************* Transition: t73 ***************************************************
	gaurdBoundValue[0] = 5; //  4<=x1<=5 and x2==4 and -1000<=v1<=1000 &  -1000<=v2<=1000
	gaurdBoundValue[1] = -4;
	gaurdBoundValue[2] = 4;
	gaurdBoundValue[3] = -4;
	gaurdBoundValue[4] = 1000;
	gaurdBoundValue[5] = 1000;
	gaurdBoundValue[6] = 1000;
	gaurdBoundValue[7] = 1000;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(
			new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
					gaurdBoundSign));
	transitions t73(73, "25 to 24", 25, 24, gaurd_polytope, assignment);
	//  ************************* Transition: t73 End ***********************************************
// *******************************************************************************************************
//	////// ********************* Transition Created and all Initialized **************************  //////
// *******************************************************************************************************

	/*	*************** Initialization of all Locations *******************
	 *  List of Locations are l1, l2, ... , l25 and Locations labelled "A" as l6("Final State") and
	 *  Locations labelled "B" as l13("Bad State")
	 *  where Label "A" is the "Final location" to be reached and "B" the "Bad location" to be avoided.
	 */// U polytope
	row = 8;
	col = 4;
	ConstraintsMatrixV.resize(row, col); //Common for all polytope u except the boundValueV.
	ConstraintsMatrixV(0, 0) = 1;
	ConstraintsMatrixV(0, 1) = 0;
	ConstraintsMatrixV(0, 2) = 0;
	ConstraintsMatrixV(0, 3) = 0;

	ConstraintsMatrixV(1, 0) = -1;
	ConstraintsMatrixV(1, 1) = 0;
	ConstraintsMatrixV(1, 2) = 0;
	ConstraintsMatrixV(1, 3) = 0;

	ConstraintsMatrixV(2, 0) = 0;
	ConstraintsMatrixV(2, 1) = 1;
	ConstraintsMatrixV(2, 2) = 0;
	ConstraintsMatrixV(2, 3) = 0;

	ConstraintsMatrixV(3, 0) = 0;
	ConstraintsMatrixV(3, 1) = -1;
	ConstraintsMatrixV(3, 2) = 0;
	ConstraintsMatrixV(3, 3) = 0;

	ConstraintsMatrixV(4, 0) = 0;
	ConstraintsMatrixV(4, 1) = 0;
	ConstraintsMatrixV(4, 2) = 1;
	ConstraintsMatrixV(4, 3) = 0;

	ConstraintsMatrixV(5, 0) = 0;
	ConstraintsMatrixV(5, 1) = 0;
	ConstraintsMatrixV(5, 2) = -1;
	ConstraintsMatrixV(5, 3) = 0;

	ConstraintsMatrixV(6, 0) = 0;
	ConstraintsMatrixV(6, 1) = 0;
	ConstraintsMatrixV(6, 2) = 0;
	ConstraintsMatrixV(6, 3) = 1;

	ConstraintsMatrixV(7, 0) = 0;
	ConstraintsMatrixV(7, 1) = 0;
	ConstraintsMatrixV(7, 2) = 0;
	ConstraintsMatrixV(7, 3) = -1;

	boundSignV = 1;
//cout<<"\nBefore Setting Invariants\n";
	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col); //Common for all polytope except the invariantBoundValue.
	invariantConstraintsMatrix(0, 0) = 1;
	invariantConstraintsMatrix(0, 1) = 0;
	invariantConstraintsMatrix(0, 2) = 0;
	invariantConstraintsMatrix(0, 3) = 0;

	invariantConstraintsMatrix(1, 0) = -1;
	invariantConstraintsMatrix(1, 1) = 0;
	invariantConstraintsMatrix(1, 2) = 0;
	invariantConstraintsMatrix(1, 3) = 0;

	invariantConstraintsMatrix(2, 0) = 0;
	invariantConstraintsMatrix(2, 1) = 1;
	invariantConstraintsMatrix(2, 2) = 0;
	invariantConstraintsMatrix(2, 3) = 0;

	invariantConstraintsMatrix(3, 0) = 0;
	invariantConstraintsMatrix(3, 1) = -1;
	invariantConstraintsMatrix(3, 2) = 0;
	invariantConstraintsMatrix(3, 3) = 0;

	invariantBoundSign = 1;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 1; //0<=x1<=1 and 4<=x2<=5
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 5;
	invariantBoundValue[3] = -4;
	row = 8;
	boundValueV.resize(row);
	boundValueV[0] = 0; //v1==1 and v2=0 => -Vd = -(1,0) u is (0,0,-1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = -1;
	boundValueV[5] = 1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc1;
	Out_Going_Trans_fromLoc1.push_back(t1);
	Out_Going_Trans_fromLoc1.push_back(t2);

	location l1(1, "2", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc1);
//  ************ Location ID=1 completed  ************
	row = 4;
	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 1; //0<=x1<=1 and 3<=x2<=4
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 4;
	invariantBoundValue[3] = -3;
	row = 8;
	boundValueV.resize(row);
	boundValueV[0] = 0; //v1==1 and v2=0 => -Vd = -(1,0) u is (0,0,-1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = -1;
	boundValueV[5] = 1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc2;
	Out_Going_Trans_fromLoc2.push_back(t3);
	Out_Going_Trans_fromLoc2.push_back(t4);
	Out_Going_Trans_fromLoc2.push_back(t5);

	location l2(2, "2", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc2);
//  ************ Location ID=2 completed  ************
	row = 4;
	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 1; //0<=x1<=1 and 2<=x2<=3
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 3;
	invariantBoundValue[3] = -2;
	row = 8;
	boundValueV.resize(row);
	boundValueV[0] = 0; //v1==1 and v2=0 => -Vd = -(1,0) u is (0,0,-1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = -1;
	boundValueV[5] = 1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc3;
	Out_Going_Trans_fromLoc3.push_back(t6);
	Out_Going_Trans_fromLoc3.push_back(t7);
	Out_Going_Trans_fromLoc3.push_back(t8);

	location l3(3, "2", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc3);
//  ************ Location ID=3 completed  ************
	row = 4;
	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 1; //0<=x1<=1 and 1<=x2<=2
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 2;
	invariantBoundValue[3] = -1;
	row = 8;
	boundValueV.resize(row);
	boundValueV[0] = 0; //v1==1 and v2=0 => -Vd = -(1,0) u is (0,0,-1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = -1;
	boundValueV[5] = 1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc4;
	Out_Going_Trans_fromLoc4.push_back(t9);
	Out_Going_Trans_fromLoc4.push_back(t10);
	Out_Going_Trans_fromLoc4.push_back(t11);

	location l4(4, "2", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc4);
//  ************ Location ID=4 completed  ************
	row = 4;
	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 1; //0<=x1<=1 and 0<=x2<=1
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 1;
	invariantBoundValue[3] = 0;
	row = 8;
	boundValueV.resize(row);
	boundValueV[0] = 0; //v1==1 and v2=0 => -Vd = -(1,0) u is (0,0,-1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = -1;
	boundValueV[5] = 1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc5;
	Out_Going_Trans_fromLoc5.push_back(t12);
	Out_Going_Trans_fromLoc5.push_back(t13);

	location l5(5, "2", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc5);
//  ************ Location ID=5 completed  ************

	//	************ No dynamics available for location=6/13    ************
	//	either the values are zeros or NULL but they will not be processed as the Name is FINAL/GOOD/BAD/UNSAFE

	invariantBoundValue[0] = 0;
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 0;
	invariantBoundValue[3] = 0;

	boundValueV[0] = 0; //v1==0 and v2=0 => -Vd = -(0,0) u is (0,0,0,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc6, Out_Going_Trans_fromLoc13;

	location l6(6, "FINAL", system_dynamics, invariant, false,
			Out_Going_Trans_fromLoc6);
	location l13(13, "BAD", system_dynamics, invariant, false,
			Out_Going_Trans_fromLoc13);

//  *********  Location ID=6 and ID=13 completed  *****************

	invariantBoundValue[0] = 2; //1<=x1<=2 and 1<=x2<=2
	invariantBoundValue[1] = -1;
	invariantBoundValue[2] = 2;
	invariantBoundValue[3] = -1;

	boundValueV[0] = 0; //v1==0 and v2=-1 => -Vd = -(0,-1) u is (0,0,0,1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = 1;
	boundValueV[7] = -1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc7;
	Out_Going_Trans_fromLoc7.push_back(t14);
	Out_Going_Trans_fromLoc7.push_back(t15);
	Out_Going_Trans_fromLoc7.push_back(t16);
	Out_Going_Trans_fromLoc7.push_back(t17);
	location l7(7, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc7);
	//  ************ Location ID=7 completed  ************

	invariantBoundValue[0] = 2; //1<=x1<=2 and 2<=x2<=3
	invariantBoundValue[1] = -1;
	invariantBoundValue[2] = 3;
	invariantBoundValue[3] = -2;

	boundValueV[0] = 0; //v1==0 and v2=-1 => -Vd = -(0,-1) u is (0,0,0,1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = 1;
	boundValueV[7] = -1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc8;
	Out_Going_Trans_fromLoc8.push_back(t18);
	Out_Going_Trans_fromLoc8.push_back(t19);
	Out_Going_Trans_fromLoc8.push_back(t20);
	Out_Going_Trans_fromLoc8.push_back(t21);
	location l8(8, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc8);
	//  ************ Location ID=8 completed  ************

	invariantBoundValue[0] = 2; //1<=x1<=2 and 3<=x2<=4
	invariantBoundValue[1] = -1;
	invariantBoundValue[2] = 4;
	invariantBoundValue[3] = -3;

	boundValueV[0] = 0; //v1==0 and v2=-1 => -Vd = -(0,-1) u is (0,0,0,1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = 1;
	boundValueV[7] = -1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc9;
	Out_Going_Trans_fromLoc9.push_back(t22);
	Out_Going_Trans_fromLoc9.push_back(t23);
	Out_Going_Trans_fromLoc9.push_back(t24);
	Out_Going_Trans_fromLoc9.push_back(t25);
	location l9(9, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc9);
	//  ************ Location ID=9 completed  ************

	invariantBoundValue[0] = 2; //1<=x1<=2 and 4<=x2<=5
	invariantBoundValue[1] = -1;
	invariantBoundValue[2] = 5;
	invariantBoundValue[3] = -4;

	boundValueV[0] = 0; //v1==0 and v2=-1 => -Vd = -(0,-1) u is (0,0,0,1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = 1;
	boundValueV[7] = -1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc10;
	Out_Going_Trans_fromLoc10.push_back(t26);
	Out_Going_Trans_fromLoc10.push_back(t27);
	Out_Going_Trans_fromLoc10.push_back(t28);
	location l10(10, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc10);
	//  ************ Location ID=10 completed  ************

	invariantBoundValue[0] = 3; //2<=x1<=3 and 0<=x2<=1
	invariantBoundValue[1] = -2;
	invariantBoundValue[2] = 1;
	invariantBoundValue[3] = 0;

	boundValueV[0] = 0; //v1==0 and v2=1 => -Vd = -(0,1) u is (0,0,0,-1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = -1;
	boundValueV[7] = 1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc11;
	Out_Going_Trans_fromLoc11.push_back(t29);
	Out_Going_Trans_fromLoc11.push_back(t30);
	Out_Going_Trans_fromLoc11.push_back(t31);
	location l11(11, "0", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc11);
	//  ************ Location ID=11 completed  ************

	invariantBoundValue[0] = 3; //2<=x1<=3 and 1<=x2<=2
	invariantBoundValue[1] = -2;
	invariantBoundValue[2] = 2;
	invariantBoundValue[3] = -1;

	boundValueV[0] = 0; //v1==-1 and v2=0 => -Vd = -(-1,0) u is (0,0,1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 1;
	boundValueV[5] = -1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc12;
	Out_Going_Trans_fromLoc12.push_back(t32);
	Out_Going_Trans_fromLoc12.push_back(t33);
	Out_Going_Trans_fromLoc12.push_back(t34);
	Out_Going_Trans_fromLoc12.push_back(t35);
	location l12(12, "6", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc12);
	//  ************ Location ID=12 completed  ************
	//  ************ Location ID=13 Done above  ************

	invariantBoundValue[0] = 3; //2<=x1<=3 and 3<=x2<=4
	invariantBoundValue[1] = -2;
	invariantBoundValue[2] = 4;
	invariantBoundValue[3] = -3;

	boundValueV[0] = 0; //v1=-0.70711 and v2=0.70711 => -Vd = -(-0.70711,0.70711) u is (0,0,0.70711,-0.70711)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0.70711;
	boundValueV[5] = -0.70711;
	boundValueV[6] = -0.70711;
	boundValueV[7] = 0.70711;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc14;
	Out_Going_Trans_fromLoc14.push_back(t36);
	Out_Going_Trans_fromLoc14.push_back(t37);
	Out_Going_Trans_fromLoc14.push_back(t38);
	Out_Going_Trans_fromLoc14.push_back(t39);
	location l14(14, "7", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc14);
	//  ************ Location ID=14 completed  ************

	invariantBoundValue[0] = 3; //2<=x1<=3 and 4<=x2<=5
	invariantBoundValue[1] = -2;
	invariantBoundValue[2] = 5;
	invariantBoundValue[3] = -4;

	boundValueV[0] = 0; //v1==-1 and v2=0 => -Vd = -(-1,0) u is (0,0,1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 1;
	boundValueV[5] = -1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc15;
	Out_Going_Trans_fromLoc15.push_back(t40);
	Out_Going_Trans_fromLoc15.push_back(t41);
	Out_Going_Trans_fromLoc15.push_back(t42);
	location l15(15, "6", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc15);
	//  ************ Location ID=15 completed  ************

	invariantBoundValue[0] = 4; //3<=x1<=4 and 0<=x2<=1
	invariantBoundValue[1] = -3;
	invariantBoundValue[2] = 1;
	invariantBoundValue[3] = 0;

	boundValueV[0] = 0; //v1==0 and v2=1 => -Vd = -(0,1) u is (0,0,0,-1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = -1;
	boundValueV[7] = 1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc16;
	Out_Going_Trans_fromLoc16.push_back(t43);
	Out_Going_Trans_fromLoc16.push_back(t44);
	Out_Going_Trans_fromLoc16.push_back(t45);
	location l16(16, "0", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc16);
	//  ************ Location ID=16 completed  ************

	invariantBoundValue[0] = 4; //3<=x1<=4 and 1<=x2<=2
	invariantBoundValue[1] = -3;
	invariantBoundValue[2] = 2;
	invariantBoundValue[3] = -1;

	boundValueV[0] = 0; //v1==-1 and v2=0 => -Vd = -(-1,0) u is (0,0,1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 1;
	boundValueV[5] = -1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc17;
	Out_Going_Trans_fromLoc17.push_back(t46);
	Out_Going_Trans_fromLoc17.push_back(t47);
	Out_Going_Trans_fromLoc17.push_back(t48);
	Out_Going_Trans_fromLoc17.push_back(t49);
	location l17(17, "6", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc17);
	//  ************ Location ID=17 completed  ************

	invariantBoundValue[0] = 4; //3<=x1<=4 and 2<=x2<=3
	invariantBoundValue[1] = -3;
	invariantBoundValue[2] = 3;
	invariantBoundValue[3] = -2;

	boundValueV[0] = 0; //v1=0.70711 and v2=-0.70711 => -Vd = -(0.70711, -0.70711) u is (0,0, -0.70711, 0.70711)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = -0.70711;
	boundValueV[5] = 0.70711;
	boundValueV[6] = 0.70711;
	boundValueV[7] = -0.70711;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc18;
	Out_Going_Trans_fromLoc18.push_back(t50);
	Out_Going_Trans_fromLoc18.push_back(t51);
	Out_Going_Trans_fromLoc18.push_back(t52);
	Out_Going_Trans_fromLoc18.push_back(t53);
	location l18(18, "3", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc18);
	//  ************ Location ID=18 completed  ************

	invariantBoundValue[0] = 4; //3<=x1<=4 and 3<=x2<=4
	invariantBoundValue[1] = -3;
	invariantBoundValue[2] = 4;
	invariantBoundValue[3] = -3;

	boundValueV[0] = 0; //v1=-0.70711 and v2=0.70711 => -Vd = -(-0.70711,0.70711) u is (0,0,0.70711,-0.70711)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0.70711;
	boundValueV[5] = -0.70711;
	boundValueV[6] = -0.70711;
	boundValueV[7] = 0.70711;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc19;
	Out_Going_Trans_fromLoc19.push_back(t54);
	Out_Going_Trans_fromLoc19.push_back(t55);
	Out_Going_Trans_fromLoc19.push_back(t56);
	Out_Going_Trans_fromLoc19.push_back(t57);
	location l19(19, "7", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc19);
	//  ************ Location ID=19 completed  ************

	invariantBoundValue[0] = 4; //3<=x1<=4 and 4<=x2<=5
	invariantBoundValue[1] = -3;
	invariantBoundValue[2] = 5;
	invariantBoundValue[3] = -4;

	boundValueV[0] = 0; //v1==-1 and v2=0 => -Vd = -(-1,0) u is (0,0,1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 1;
	boundValueV[5] = -1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc20;
	Out_Going_Trans_fromLoc20.push_back(t58);
	Out_Going_Trans_fromLoc20.push_back(t59);
	Out_Going_Trans_fromLoc20.push_back(t60);
	location l20(20, "6", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc20);
	//  ************ Location ID=20 completed  ************

	invariantBoundValue[0] = 4; //3<=x1<=4 and 0<=x2<=1
	invariantBoundValue[1] = -3;
	invariantBoundValue[2] = 1;
	invariantBoundValue[3] = 0;

	boundValueV[0] = 0; //v1==0 and v2=1 => -Vd = -(0,1) u is (0,0,0,-1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = -1;
	boundValueV[7] = 1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc21;
	Out_Going_Trans_fromLoc21.push_back(t61);
	Out_Going_Trans_fromLoc21.push_back(t62);
	location l21(21, "0", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc21);
	//  ************ Location ID=21 completed  ************

	invariantBoundValue[0] = 5; //4<=x1<=5 and 1<=x2<=2
	invariantBoundValue[1] = -4;
	invariantBoundValue[2] = 2;
	invariantBoundValue[3] = -1;

	boundValueV[0] = 0; //v1==-1 and v2=0 => -Vd = -(-1,0) u is (0,0,1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 1;
	boundValueV[5] = -1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc22;
	Out_Going_Trans_fromLoc22.push_back(t63);
	Out_Going_Trans_fromLoc22.push_back(t64);
	Out_Going_Trans_fromLoc22.push_back(t65);
	location l22(22, "6", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc22);
	//  ************ Location ID=22 completed  ************

	invariantBoundValue[0] = 5; //4<=x1<=5 and 2<=x2<=3
	invariantBoundValue[1] = -4;
	invariantBoundValue[2] = 3;
	invariantBoundValue[3] = -2;

	boundValueV[0] = 0; //v1==0 and v2=-1 => -Vd = -(0,-1) u is (0,0,0,1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = 1;
	boundValueV[7] = -1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;
		//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc23;
	Out_Going_Trans_fromLoc23.push_back(t66);
	Out_Going_Trans_fromLoc23.push_back(t67);
	Out_Going_Trans_fromLoc23.push_back(t68);
	location l23(23, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc23);
	//  ************ Location ID=23 completed  ************

	invariantBoundValue[0] = 5; //4<=x1<=5 and 3<=x2<=4
	invariantBoundValue[1] = -4;
	invariantBoundValue[2] = 4;
	invariantBoundValue[3] = -3;

	boundValueV[0] = 0; //v1==0 and v2=-1 => -Vd = -(0,-1) u is (0,0,0,1)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 0;
	boundValueV[5] = 0;
	boundValueV[6] = 1;
	boundValueV[7] = -1;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;

	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc24;
	Out_Going_Trans_fromLoc24.push_back(t69);
	Out_Going_Trans_fromLoc24.push_back(t70);
	Out_Going_Trans_fromLoc24.push_back(t71);
	location l24(24, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc24);
	//  ************ Location ID=24 completed  ************

	invariantBoundValue[0] = 5; //4<=x1<=5 and 4<=x2<=5
	invariantBoundValue[1] = -4;
	invariantBoundValue[2] = 5;
	invariantBoundValue[3] = -4;

	boundValueV[0] = 0; //v1==-1 and v2=0 => -Vd = -(-1,0) u is (0,0,1,0)
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;
	boundValueV[4] = 1;
	boundValueV[5] = -1;
	boundValueV[6] = 0;
	boundValueV[7] = 0;

	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.isEmptyC = true;

	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));
	std::list<transitions> Out_Going_Trans_fromLoc25;
	Out_Going_Trans_fromLoc25.push_back(t72);
	Out_Going_Trans_fromLoc25.push_back(t73);
	location l25(25, "6", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc25);
	//  ************ Location ID=25 completed  ************
// ******************************************************************************************
//	// ************************* Locations Created and Initialized **************************
// ******************************************************************************************

	//	*************** Initialization The Hybrid Automata *******************
	int dim = initial_polytope_I->getSystemDimension();
	Hybrid_Automata.setDimension(dim);
	Hybrid_Automata.addInitial_Location(l1);
	Hybrid_Automata.addLocation(l1);
	Hybrid_Automata.addLocation(l2);
	Hybrid_Automata.addLocation(l3);
	Hybrid_Automata.addLocation(l4);
	Hybrid_Automata.addLocation(l5);
	Hybrid_Automata.addLocation(l6);
	Hybrid_Automata.addLocation(l7);
	Hybrid_Automata.addLocation(l8);
	Hybrid_Automata.addLocation(l9);
	Hybrid_Automata.addLocation(l10);
	Hybrid_Automata.addLocation(l11);
	Hybrid_Automata.addLocation(l12);
	Hybrid_Automata.addLocation(l13);
	Hybrid_Automata.addLocation(l14);
	Hybrid_Automata.addLocation(l15);
	Hybrid_Automata.addLocation(l16);
	Hybrid_Automata.addLocation(l17);
	Hybrid_Automata.addLocation(l18);
	Hybrid_Automata.addLocation(l19);
	Hybrid_Automata.addLocation(l20);
	Hybrid_Automata.addLocation(l21);
	Hybrid_Automata.addLocation(l22);
	Hybrid_Automata.addLocation(l23);
	Hybrid_Automata.addLocation(l24);
	Hybrid_Automata.addLocation(l25);

	initial_symbolic_state.setDiscreteSet(d_set);
	initial_symbolic_state.setContinuousSet(initial_polytope_I);

}
