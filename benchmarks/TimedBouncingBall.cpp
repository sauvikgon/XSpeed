/*
 * TimedBouncingBall.cpp
 *
 *  Created on: 25-Nov-2014
 *      Author: amit
 */

#include "../benchmarks/TimedBouncingBall.h"

//Hyst Generated output
void SetTimedBouncingBall(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	polytope::ptr initial_polytope_I;

	polytope::ptr invariant0;

	polytope::ptr guard_polytope0;

	Dynamics system_dynamics0;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV0,
			invariantConstraintsMatrix0, guardConstraintsMatrix0, A0matrix,
			Bmatrix0;

	std::vector<double> boundValueI, boundValueV0, C0, invariantBoundValue0,
			guardBoundValue0;

	int boundSignI, invariantBoundSign, guardBoundSign;

	size_type row, col;

// The mode name is  always_running

	row = 3;
	col = 3;
	A0matrix.resize(row, col);
	A0matrix(0, 0) = 0.0;
	A0matrix(0, 1) = 1.0;
	A0matrix(0, 2) = 0.0;
	A0matrix(1, 0) = 0.0;
	A0matrix(1, 1) = 0.0;
	A0matrix(1, 2) = 0.0;
	A0matrix(2, 0) = 0.0;
	A0matrix(2, 1) = 0.0;
	A0matrix(2, 2) = 0.0;
	system_dynamics0.isEmptyMatrixA = false;
	system_dynamics0.MatrixA = A0matrix;

	system_dynamics0.isEmptyMatrixB = true;

	C0.resize(row);
	C0[0] = 0.0;
	C0[1] = -1;	//value of g: acceleration due to gravity
	C0[2] = 1;	//timed bball: Rate of change of time = 1
	system_dynamics0.isEmptyC = false;
	system_dynamics0.C = C0;

	row = 2;
	col = 3;
	invariantConstraintsMatrix0.resize(row, col);
	invariantConstraintsMatrix0(0, 0) = -1.0;
	invariantConstraintsMatrix0(0, 1) = 0.0;
	invariantConstraintsMatrix0(0, 2) = 0.0;
	invariantConstraintsMatrix0(1, 0) = 0.0;
	invariantConstraintsMatrix0(1, 1) = 0.0;
	invariantConstraintsMatrix0(1, 2) = -1.0;

	invariantBoundValue0.resize(row);
	invariantBoundValue0[0] = 0.0;
	invariantBoundValue0[1] = 0.0;
	invariantBoundSign = 1;
	invariant0 = polytope::ptr(
			new polytope(invariantConstraintsMatrix0, invariantBoundValue0,
					invariantBoundSign));

	system_dynamics0.U = polytope::ptr(new polytope(true));

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

	guardConstraintsMatrix0.resize(row, col);
	guardConstraintsMatrix0(0, 0) = 1.0;
	guardConstraintsMatrix0(0, 1) = 0.0;
	guardConstraintsMatrix0(0, 2) = 0.0;
	guardConstraintsMatrix0(1, 0) = 0.0;
	guardConstraintsMatrix0(1, 1) = 1.0;
	guardConstraintsMatrix0(1, 2) = 0.0;

	guardBoundValue0.resize(row);
	guardBoundValue0[0] = 0.0;  //Value for eps set to 0
	guardBoundValue0[1] = 0.0;
	guardBoundSign = 1;
	guard_polytope0 = polytope::ptr(
			new polytope(guardConstraintsMatrix0, guardBoundValue0,
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

	Assign assignment0;
	assignment0.Map = R0;
	assignment0.b = w0;

	initial_polytope_I = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	transition::ptr t1 = transition::ptr(
			new transition(1, "hop", 1, 1, guard_polytope0, assignment0));

	std::list<transition::ptr> Out_Going_Trans_fromalways_running;

	Out_Going_Trans_fromalways_running.push_back(t1);
	location::ptr l1 = location::ptr(
			new location(1, "always_running", system_dynamics0, invariant0,
					true, Out_Going_Trans_fromalways_running));

	int dim = initial_polytope_I->getSystemDimension();
	Hybrid_Automata.addInitial_Location(l1);
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


/*
 * Manually Testing multiple initial set
 */

void SetTimedBouncingBall_2initSet(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	polytope::ptr initial_polytope_I;

	polytope::ptr invariant0;

	polytope::ptr guard_polytope0;

	Dynamics system_dynamics0;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV0,
			invariantConstraintsMatrix0, guardConstraintsMatrix0, A0matrix,
			Bmatrix0;

	std::vector<double> boundValueI, boundValueV0, C0, invariantBoundValue0,
			guardBoundValue0;

	int boundSignI, invariantBoundSign, guardBoundSign;

	size_type row, col;

// The mode name is  always_running

	row = 3;
	col = 3;
	A0matrix.resize(row, col);
	A0matrix(0, 0) = 0.0;
	A0matrix(0, 1) = 1.0;
	A0matrix(0, 2) = 0.0;
	A0matrix(1, 0) = 0.0;
	A0matrix(1, 1) = 0.0;
	A0matrix(1, 2) = 0.0;
	A0matrix(2, 0) = 0.0;
	A0matrix(2, 1) = 0.0;
	A0matrix(2, 2) = 0.0;
	system_dynamics0.isEmptyMatrixA = false;
	system_dynamics0.MatrixA = A0matrix;

	system_dynamics0.isEmptyMatrixB = true;

	C0.resize(row);
	C0[0] = 0.0;
	C0[1] = -1.0;	// acceleraion due to gravity
	C0[2] = 1.0;
	system_dynamics0.isEmptyC = false;
	system_dynamics0.C = C0;

	row = 1;
	col = 3;
	invariantConstraintsMatrix0.resize(row, col);
	invariantConstraintsMatrix0(0, 0) = -1.0;
	invariantConstraintsMatrix0(0, 1) = 0.0;
	invariantConstraintsMatrix0(0, 2) = 0.0;

	invariantBoundValue0.resize(row);
	invariantBoundValue0[0] = -0.0;
	invariantBoundSign = 1;
	invariant0 = polytope::ptr(
			new polytope(invariantConstraintsMatrix0, invariantBoundValue0,
					invariantBoundSign));

	system_dynamics0.U = polytope::ptr(new polytope(true));

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

	guardConstraintsMatrix0.resize(row, col);
	guardConstraintsMatrix0(0, 0) = 1.0;
	guardConstraintsMatrix0(0, 1) = 0.0;
	guardConstraintsMatrix0(0, 2) = 0.0;
	guardConstraintsMatrix0(1, 0) = 0.0;
	guardConstraintsMatrix0(1, 1) = 1.0;
	guardConstraintsMatrix0(1, 2) = 0.0;

	guardBoundValue0.resize(row);
	guardBoundValue0[0] = 0.1;
	guardBoundValue0[1] = 0.0;
	guardBoundSign = 1;
	guard_polytope0 = polytope::ptr(
			new polytope(guardConstraintsMatrix0, guardBoundValue0,
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
	R0(1, 1) = -0.75;
	R0(1, 2) = 0.0;

	R0(2, 0) = 0.0;
	R0(2, 1) = 0.0;
	R0(2, 2) = 1.0;
	std::vector<double> w0(row);
	w0[0] = 0.0;
	w0[1] = 0.0;
	w0[2] = 0.0;

	Assign assignment0;
	assignment0.Map = R0;
	assignment0.b = w0;

	initial_polytope_I = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	transition::ptr t1 = transition::ptr(
			new transition(1, "hop", 1, 1, guard_polytope0, assignment0));

	std::list<transition::ptr> Out_Going_Trans_fromalways_running;

	Out_Going_Trans_fromalways_running.push_back(t1);
	location::ptr l1 = location::ptr(
			new location(1, "always_running", system_dynamics0, invariant0,
					true, Out_Going_Trans_fromalways_running));

	int dim = initial_polytope_I->getSystemDimension();
	Hybrid_Automata.addInitial_Location(l1);
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

	init_state_list.push_back(I);	//pushing 1st initial set object

	//2nd initial set

	symbolic_states::ptr S2; //null_pointer as there is no instantiation
	polytope::ptr initial_polytope_I2;
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
	boundValueI[0] = 15.2;
	boundValueI[1] = -15;
	boundValueI[2] = 0;
	boundValueI[3] = 0;
	boundValueI[4] = 0;
	boundValueI[5] = 0;
	boundSignI = 1;
	initial_polytope_I2 = polytope::ptr( new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	initial_state::ptr I2 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I2, S2, transition_id));
	init_state_list.push_back(I2); //pushing 2nd initial set object
}

