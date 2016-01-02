/*
 * NavigationBenchmark.cpp
 *
 *  Created on: 25-Nov-2014
 *      Author: amit
 */
//INCORRECT MODEL ... MODEL WITH ONLY 2 DIMENSION
#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/NavigationBenchmark.h"



void SetNavigationBenchMark(hybrid_automata& Hybrid_Automata,
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
	//Input Polytope I as a point(x1,x2) (0.5,1.5) in the grid of cells
	row = 4;
	col = 2;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;

	boundValueI.resize(row);

	/*boundValueI[0] = 0.5;		//(0.5,1.5)		start_location=1
	boundValueI[1] = -0.5;
	boundValueI[2] = 1.5;
	boundValueI[3] = -1.5;*/

	boundValueI[0] = 1.3;		//(1.3,0.7)		start_location=3
	boundValueI[1] = -1.3;
	boundValueI[2] = 0.7;
	boundValueI[3] = -0.7;


	/*boundValueI[0] = 1.5;		//(1.5,2.5)		start_location=5
	boundValueI[1] = -1.5;
	boundValueI[2] = 2.5;
	boundValueI[3] = -2.5;*/
	/*boundValueI[0] = 1.9;		//(1.9,2.5)		start_location=5
	boundValueI[1] = -1.9;
	boundValueI[2] = 2.5;
	boundValueI[3] = -2.5;*/




	/*boundValueI[0] = 2.5;		//(2.5,1.5)		start_location=6
	boundValueI[1] = -2.5;
	boundValueI[2] = 1.5;
	boundValueI[3] = -1.5;*/

	boundSignI = 1;
	initial_polytope_I = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));
	//initial_polytope_I.setPolytope(ConstraintsMatrixI, boundValueI, boundSignI);

	/*	*************** Common Parameter Initialization *******************
	 * Common Parameter for all Locations or transition
	 * such as Matrix A, Matrix B , Transition_dynamics such as Matrix R and vector w;
	 */
	row = 2;
	col = 2;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = -1.2;
	Amatrix(0, 1) = 0.1;
	Amatrix(1, 0) = 0.1;
	Amatrix(1, 1) = -1.2;

	Bmatrix.resize(row, col);
	Bmatrix = Amatrix;

	math::matrix<double> R;	//Transition Dynamics
	R.resize(row, col);
	R(0, 0) = 1;
	R(0, 1) = 0;
	R(1, 0) = 0;
	R(1, 1) = 1;

	std::vector<double> w(row);
	w[0] = 0;
	w[1] = 0;

	Assign assignment;
	assignment.Map = R;
	assignment.b = w;

// ***********************************************************

	/*	*************** Initialization of all transition *******************
	 *  List of transition are t1, t2, ... , t20 including transition towards the Locations labelled "A" and "B"
	 *  where Label "A" is the "Final location" to be reached and "B" the "Bad location" to be avoided.
	 */
	row = 4;
	col = 2;
	gaurdConstraintsMatrix.resize(row, col);//this matrix will be common for all transition except the gaurdBoundValue.
	gaurdConstraintsMatrix(0, 0) = 1;
	gaurdConstraintsMatrix(0, 1) = 0;
	gaurdConstraintsMatrix(1, 0) = -1;
	gaurdConstraintsMatrix(1, 1) = 0;
	gaurdConstraintsMatrix(2, 0) = 0;
	gaurdConstraintsMatrix(2, 1) = 1;
	gaurdConstraintsMatrix(3, 0) = 0;
	gaurdConstraintsMatrix(3, 1) = -1;

	gaurdBoundSign = 1;

	gaurdBoundValue.resize(row);//gaurd is:: V_d[sin(loc_name * pi/4), cos(loc_name * pi/4)]
	gaurdBoundValue[0] = 1;		// y==2 and 0<=x<=1
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;

	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t1(1, "1 to Bad", 1, 9, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 1;			// x==1 and 1<=y<=2
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t2(2, "1 to 4", 1, 4, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 1;			// y==1 and 0<=x<=1
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t3(3, "1 to 2", 1, 2, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 1;			// y==1 and 0<=x<=1
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t4(4, "2 to 1", 2, 1, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 1;			// x==1 and 0<=y<=1
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t5(5, "2 to 3", 2, 3, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;			// y==1 and 1<=x<=2
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t6(6, "3 to 4", 3, 4, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 1;			// x==1 and 0<=y<=1
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t7(7, "3 to 2", 3, 2, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;			// x==2 and 0<=y<=1
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = 0;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t8(8, "3 to A", 3, 8, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 1;			// x==1 and 1<=y<=2
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t9(9, "4 to 1", 4, 1, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;			// y==2 and 1<=x<=2
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t10(10, "4 to 5", 4, 5, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;		// x==2 and 1<=y<=2
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t11(11, "4 to 6", 4, 6, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;			// y==1 and 1<=x<=2
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t12(12, "4 to 3", 4, 3, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;			// y==2 and 1<=x<=2
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t13(13, "5 to 4", 5, 4, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;			// x==2 and 2<=y<=3
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t14(14, "5 to 7", 5, 7, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 1;			// x==1 and 2<=y<=3
	gaurdBoundValue[1] = -1;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t15(15, "5 to Bad", 5, 9, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 3;			// y==2 and 2<=x<=3
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t16(16, "6 to 7", 6, 7, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;			// x==2 and 1<=y<=2
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t17(17, "6 to 4", 6, 4, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 3;			// y==1 and 2<=x<=3
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 1;
	gaurdBoundValue[3] = -1;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t18(18, "6 to A", 6, 8, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 3;			// y==2 and 2<=x<=3
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 2;
	gaurdBoundValue[3] = -2;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t19(19, "7 to 6", 7, 6, gaurd_polytope, assignment);

	gaurdBoundValue[0] = 2;			// x==2 and 2<=y<=3
	gaurdBoundValue[1] = -2;
	gaurdBoundValue[2] = 3;
	gaurdBoundValue[3] = -2;
	//gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,gaurdBoundSign);
	gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue, gaurdBoundSign));
	transition t20(20, "7 to 5", 4, 5, gaurd_polytope, assignment);

// ******************* Transition initialized **************************

	/*	*************** Initialization of all Locations *******************
	 *  List of Locations are l1, l2, ... , l7 and Locations labelled "A" as l8("Final State") and
	 *  Locations labelled "B" as l9("Bad State")
	 *  where Label "A" is the "Final location" to be reached and "B" the "Bad location" to be avoided.
	 */// U polytope
	row = 4;
	col = 2;
	ConstraintsMatrixV.resize(row, col);//Common for all polytope u except the boundValueV.
	ConstraintsMatrixV(0, 0) = 1;
	ConstraintsMatrixV(0, 1) = 0;
	ConstraintsMatrixV(1, 0) = -1;
	ConstraintsMatrixV(1, 1) = 0;
	ConstraintsMatrixV(2, 0) = 0;
	ConstraintsMatrixV(2, 1) = 1;
	ConstraintsMatrixV(3, 0) = 0;
	ConstraintsMatrixV(3, 1) = -1;
	boundSignV = 1;

	invariantConstraintsMatrix.resize(row, col);//Common for all polytope except the invariantBoundValue.
	invariantConstraintsMatrix(0, 0) = 1;
	invariantConstraintsMatrix(0, 1) = 0;
	invariantConstraintsMatrix(1, 0) = -1;
	invariantConstraintsMatrix(1, 1) = 0;
	invariantConstraintsMatrix(2, 0) = 0;
	invariantConstraintsMatrix(2, 1) = 1;
	invariantConstraintsMatrix(3, 0) = 0;
	invariantConstraintsMatrix(3, 1) = -1;
	invariantBoundSign = 1;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 1;		//0<=x<=1 and 1<=y<=2
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 2;
	invariantBoundValue[3] = -1;

	boundValueV.resize(row);
	boundValueV[0] = 0;				//x==0 and y=1		-Vd = -(0,-1)
	boundValueV[1] = 0;
	boundValueV[2] = 1;
	boundValueV[3] = -1;

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;
	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));
	std::list<transition> Out_Going_Trans_fromLoc1;
	Out_Going_Trans_fromLoc1.push_back(t1);
	Out_Going_Trans_fromLoc1.push_back(t2);
	Out_Going_Trans_fromLoc1.push_back(t3);

	location l1(1, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc1);
//Location ID=1 completed

	invariantBoundValue[0] = 1;		//0<=x<=1 and 0<=y<=1
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 1;
	invariantBoundValue[3] = 0;

	boundValueV[0] = -1;				//x==-1 and y==0		-(1,0)
	boundValueV[1] = 1;
	boundValueV[2] = 0;
	boundValueV[3] = 0;

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;
	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));
	std::list<transition> Out_Going_Trans_fromLoc2;
	Out_Going_Trans_fromLoc2.push_back(t4);
	Out_Going_Trans_fromLoc2.push_back(t5);

	location l2(2, "2", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc2);
//Location ID=2 completed

	invariantBoundValue[0] = 2;		//1<=x<=2 and 0<=y<=1
	invariantBoundValue[1] = -1;
	invariantBoundValue[2] = 1;
	invariantBoundValue[3] = 0;

	boundValueV[0] = -1;				//x==-1 and y==0		-(1,0)
	boundValueV[1] = 1;
	boundValueV[2] = 0;
	boundValueV[3] = 0;

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;
	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));
	std::list<transition> Out_Going_Trans_fromLoc3;
	Out_Going_Trans_fromLoc3.push_back(t6);
	Out_Going_Trans_fromLoc3.push_back(t7);
	Out_Going_Trans_fromLoc3.push_back(t8);

	location l3(3, "2", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc3);
//Location ID=3 completed

	invariantBoundValue[0] = 2;		//1<=x<=2 and 1<=y<=2
	invariantBoundValue[1] = -1;
	invariantBoundValue[2] = 2;
	invariantBoundValue[3] = -1;

	boundValueV[0] = -0.70711;	//x==-0.70711 and y==0.70711		-(0.70711,-0.70711)
	boundValueV[1] = 0.70711;
	boundValueV[2] = 0.70711;
	boundValueV[3] = -0.70711;

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;
	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));
	std::list<transition> Out_Going_Trans_fromLoc4;
	Out_Going_Trans_fromLoc4.push_back(t9);
	Out_Going_Trans_fromLoc4.push_back(t10);
	Out_Going_Trans_fromLoc4.push_back(t11);
	Out_Going_Trans_fromLoc4.push_back(t12);

	location l4(4, "3", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc4);
//Location ID=4 completed

	invariantBoundValue[0] = 2;		//1<=x<=2 and 2<=y<=3
	invariantBoundValue[1] = -1;
	invariantBoundValue[2] = 3;
	invariantBoundValue[3] = -2;

	boundValueV[0] = -1;				//x==-1 and y==0		-(1,0)
	boundValueV[1] = 1;
	boundValueV[2] = 0;
	boundValueV[3] = 0;

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;
	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));
	std::list<transition> Out_Going_Trans_fromLoc5;
	Out_Going_Trans_fromLoc5.push_back(t13);
	Out_Going_Trans_fromLoc5.push_back(t14);
	Out_Going_Trans_fromLoc5.push_back(t15);

	location l5(5, "2", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc5);
//Location ID=5 completed

	invariantBoundValue[0] = 3;		//2<=x<=3 and 1<=y<=2
	invariantBoundValue[1] = -2;
	invariantBoundValue[2] = 2;
	invariantBoundValue[3] = -1;

	boundValueV[0] = 0;				//x==0 and y==1		-(0,-1)
	boundValueV[1] = 0;
	boundValueV[2] = 1;
	boundValueV[3] = -1;

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;
	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));
	std::list<transition> Out_Going_Trans_fromLoc6;
	Out_Going_Trans_fromLoc6.push_back(t16);
	Out_Going_Trans_fromLoc6.push_back(t17);
	Out_Going_Trans_fromLoc6.push_back(t18);

	location l6(6, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc6);
//Location ID=6 completed

	invariantBoundValue[0] = 3;		//2<=x<=3 and 2<=y<=3
	invariantBoundValue[1] = -2;
	invariantBoundValue[2] = 3;
	invariantBoundValue[3] = -2;

	boundValueV[0] = 0;				//x==0 and y==1		-(0,-1)
	boundValueV[1] = 0;
	boundValueV[2] = 1;
	boundValueV[3] = -1;

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;
	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));
	std::list<transition> Out_Going_Trans_fromLoc7;
	Out_Going_Trans_fromLoc7.push_back(t19);
	Out_Going_Trans_fromLoc7.push_back(t20);

	location l7(7, "4", system_dynamics, invariant, true,
			Out_Going_Trans_fromLoc7);
//Location ID=7 completed

//	************ No dynamics available for location=8/9    ************
//	either the values are zeros or NULL but they will not be processed as the Name is FINAL/GOOD/BAD/UNSAFE

	invariantBoundValue[0] = 0;
	invariantBoundValue[1] = 0;
	invariantBoundValue[2] = 0;
	invariantBoundValue[3] = 0;

	boundValueV[0] = 0;
	boundValueV[1] = 0;
	boundValueV[2] = 0;
	boundValueV[3] = 0;

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;
	//system_dynamics.U.setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
	//invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));
	std::list<transition> Out_Going_Trans_fromLoc8, Out_Going_Trans_fromLoc9;

	location l8(8, "FINAL", system_dynamics, invariant, false, Out_Going_Trans_fromLoc8);
	location l9(9, "BAD", system_dynamics, invariant, false,
			Out_Going_Trans_fromLoc9);
//Location ID=8 and ID=9 completed ************

	//	*************** Locations Initialized *******************

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

	discrete_set d_set;
	//d_set.insert_element(1);		//the initial Location ID = 1
	d_set.insert_element(3);		//the initial Location ID = 3
	//d_set.insert_element(5);		//the initial Location ID = 5
	//d_set.insert_element(6);		//the initial Location ID = 6
	initial_symbolic_state.setDiscreteSet(d_set);
	initial_symbolic_state.setContinuousSet(initial_polytope_I);

}
