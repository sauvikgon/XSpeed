/*
 * TimedBouncingBall.cpp
 *
 *  Created on: 25-Nov-2014
 *      Author: amit
 */

#include <benchmarks/timedBouncingBall.h>

//Hyst Generated output
void SetTimedBouncingBall(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	polytope::ptr initial_polytope_I;

	polytope::ptr invariant;

	polytope::ptr guard_polytope;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, A, B;

	std::vector<double> boundValueI, boundValueV, invariantBoundValue,
			guardBoundValue;

	int boundSignI, invariantBoundSign, guardBoundSign;

	size_type row, col;

// The mode name is  always_running

	row = 3;
	col = 3;
	A.resize(row, col);
	A.clear();
	A(0, 1) = 1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = A;

	system_dynamics.isEmptyMatrixB = false;
	A.matrix_Identity(row,B);
	system_dynamics.MatrixB = B;

	// set the U polytope matrix
	row = 6;
	col = 3;
	ConstraintsMatrixV.resize(row,col);
	ConstraintsMatrixV.clear();
	
	for(unsigned int i=0,j=0;i<row-1;i+=2,j++){
		ConstraintsMatrixV(i,j)=1;
		ConstraintsMatrixV(i+1,j)=-1;	
	}

	boundValueV.resize(row,0);

	boundValueV[2]= -1; // acceleration due to gravity.
	boundValueV[3]= 1;
	boundValueV[4]= 1;
	boundValueV[5]= -1;
	
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, 1));
	row = 2;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(1, 0) = 0.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 0.0;
	invariantBoundValue[1] = 0.0;
	invariantBoundSign = 1;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue, invariantBoundSign));

	row = 6;
	col = 3;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(0, 2) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(1, 2) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(2, 2) = 0;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(3, 2) = 0;
	ConstraintsMatrixI(4, 0) = 0;
	ConstraintsMatrixI(4, 1) = 0;
	ConstraintsMatrixI(4, 2) = 1;
	ConstraintsMatrixI(5, 0) = 0;
	ConstraintsMatrixI(5, 1) = 0;
	ConstraintsMatrixI(5, 2) = -1;
	boundValueI.resize(row);
	boundValueI[0] = 10.2;
	boundValueI[1] = -10;
	boundValueI[2] = 0;
	boundValueI[3] = 0;
	boundValueI[4] = 0;
	boundValueI[5] = 0;
	boundSignI = 1;

// The transition label ishop

// Original guard: x <= ball_eps & v < 0

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = 1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(1, 0) = 0.0;
	guardConstraintsMatrix(1, 1) = 1.0;
	guardConstraintsMatrix(1, 2) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = 0.0;  //Value for eps set to 0
	guardBoundValue[1] = 0.0;
	guardBoundSign = 1;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

// The transition label is   hop

	math::matrix<double> R0;
	row = 3;
	col = 3;
	R0.resize(row, col);
	R0(0, 0) = 1.0;
	R0(0, 1) = 0.0;
	R0(0, 2) = 0.0;

	R0(1, 0) = 0.0;
	R0(1, 1) = -0.75;	//value of c
	R0(1, 2) = 0.0;

	R0(2, 0) = 0.0;
	R0(2, 1) = 0.0;
	R0(2, 2) = 1.0;
	std::vector<double> w0(row);
	w0[0] = 0.0;
	w0[1] = 0.0;
	w0[2] = 0.0;

	Assign assignment;
	assignment.Map = R0;
	assignment.b = w0;

	initial_polytope_I = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	transition::ptr t1 = transition::ptr(
			new transition(1, "hop", 1, 1, guard_polytope, assignment));

	std::list<transition::ptr> Out_Going_Trans_fromalways_running;

	Out_Going_Trans_fromalways_running.push_back(t1);
	location::ptr l1 = location::ptr(
			new location(1, "always_running", system_dynamics, invariant, true, Out_Going_Trans_fromalways_running));

	int dim = initial_polytope_I->getSystemDimension();
	Hybrid_Automata.addInitialLocation(l1);
	Hybrid_Automata.addLocation(l1);
	Hybrid_Automata.setDimension(dim);

	Hybrid_Automata.insert_to_map("x", 0);
	Hybrid_Automata.insert_to_map("v", 1);
	Hybrid_Automata.insert_to_map("t", 2);

	unsigned int initial_location_id = 1; //the initial Location ID
	symbolic_states::ptr S; //null_pointer as there is no instantiation
	int transition_id = 0; //initial location no transition taken yet
	initial_state::ptr I = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I, S,
					transition_id));

	init_state_list.push_back(I);
}

