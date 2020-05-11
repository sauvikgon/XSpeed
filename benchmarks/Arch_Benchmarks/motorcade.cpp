/*
 * motorcar.cpp
 *
 *  Created on: 09-Apr-2017
 *      Author: rajarshi
 */

#include "benchmarks/Arch_Benchmarks/motorcade.h"

void setMotorcade(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I0, forbid_polytope;
	location::ptr l;
	transition::ptr t;
	polytope::ptr invariant;

	polytope::ptr guard_polytope;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix,
			Bmatrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV, C, invariantBoundValue,
			guardBoundValue, boundValueF;

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1, boundSignV = 1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  v1

	row = 5;
	col = 5;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 8.0;
	C[1] = 8.5;
	C[2] = 9.0;
	C[3] = 9.5;
	C[4] = 10.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 8;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = -1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(4, 3) = 1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;
	invariantConstraintsMatrix(5, 3) = -1.0;
	invariantConstraintsMatrix(6, 3) = -1.0;
	invariantConstraintsMatrix(6, 4) = 1.0;
	invariantConstraintsMatrix(7, 3) = 1.0;
	invariantConstraintsMatrix(7, 4) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 10.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 10.0;
	invariantBoundValue[4] = -2.0;
	invariantBoundValue[5] = 10.0;
	invariantBoundValue[6] = -2.0;
	invariantBoundValue[7] = 10.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromv1;

	// The transition label is e1

	// Original guard: x_1 - x_2 <= 4

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = 1.0;
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 4.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "e1", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromv1.push_back(t);
	// The transition label is e4

	// Original guard: x_2 - x_3 <= 4

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = 1.0;
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 4.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(2, "e4", 1, 3, guard_polytope, assignment));

	Out_Going_Trans_fromv1.push_back(t);
	// The transition label is e7

	// Original guard: x_3 - x_4 <= 4

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 4.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(3, "e7", 1, 4, guard_polytope, assignment));

	Out_Going_Trans_fromv1.push_back(t);
	// The transition label is e10

	// Original guard: x_4 - x_5 <= 4

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = 1.0;
	guardConstraintsMatrix(0, 4) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 4.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(4, "e10", 1, 5, guard_polytope, assignment));

	Out_Going_Trans_fromv1.push_back(t);
	l = location::ptr(
			new location(1, "v1", system_dynamics, invariant, true,
					Out_Going_Trans_fromv1));

	Hybrid_Automata.addInitialLocation(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  v2

	row = 5;
	col = 5;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 12.0;
	C[1] = 10.0;
	C[2] = 8.0;
	C[3] = 9.0;
	C[4] = 10.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 8;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = -1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(4, 3) = 1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;
	invariantConstraintsMatrix(5, 3) = -1.0;
	invariantConstraintsMatrix(6, 3) = -1.0;
	invariantConstraintsMatrix(6, 4) = 1.0;
	invariantConstraintsMatrix(7, 3) = 1.0;
	invariantConstraintsMatrix(7, 4) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 10.0;
	invariantBoundValue[3] = 10.0;
	invariantBoundValue[5] = 10.0;
	invariantBoundValue[7] = 10.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromv2;

	// The transition label is e2

	// Original guard: x_1 - x_2 >= 4

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(5, "e2", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromv2.push_back(t);
	// The transition label is e3

	// Original guard: x_1 - x_2 <= 1

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = 1.0;
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(6, "e3", 2, 6, guard_polytope, assignment));

	Out_Going_Trans_fromv2.push_back(t);
	l = location::ptr(
			new location(2, "v2", system_dynamics, invariant, true,
					Out_Going_Trans_fromv2));
	Hybrid_Automata.addLocation(l);

	module1MotorCade(Hybrid_Automata, init_state_list, reach_parameters);
	module2MotorCade(Hybrid_Automata, init_state_list, reach_parameters);
	module3MotorCade(Hybrid_Automata, init_state_list, reach_parameters);
	module4MotorCade(Hybrid_Automata, init_state_list, reach_parameters);

	row = 10;
	col = 5;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI.clear();
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(4, 2) = 1;
	ConstraintsMatrixI(5, 2) = -1;
	ConstraintsMatrixI(6, 3) = 1;
	ConstraintsMatrixI(7, 3) = -1;
	ConstraintsMatrixI(8, 4) = 1;
	ConstraintsMatrixI(9, 4) = -1;
	boundValueI.resize(row);
	boundValueI.assign(row, 0);
	boundValueI[0] = 40;
	boundValueI[1] = -40;
	boundValueI[2] = 35;
	boundValueI[3] = -35;
	boundValueI[4] = 30;
	boundValueI[5] = -30;
	boundValueI[6] = 25;
	boundValueI[7] = -25;
	boundValueI[8] = 20;
	boundValueI[9] = -20;

	initial_polytope_I0 = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id = 1;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I0, S0,
					transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);

	Hybrid_Automata.insert_to_map("x_1", 0);
	Hybrid_Automata.insert_to_map("x_2", 1);
	Hybrid_Automata.insert_to_map("x_3", 2);
	Hybrid_Automata.insert_to_map("x_4", 3);
	Hybrid_Automata.insert_to_map("x_5", 4);

}

void module1MotorCade(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I0, forbid_polytope;
	location::ptr l;
	transition::ptr t;
	polytope::ptr invariant;

	polytope::ptr guard_polytope;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix,
			Bmatrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV, C, invariantBoundValue,
			guardBoundValue, boundValueF;

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1, boundSignV =
			1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  v3

	row = 5;
	col = 5;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 12.0;
	C[1] = 12.0;
	C[2] = 10.0;
	C[3] = 8.5;
	C[4] = 9.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 8;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = -1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(4, 3) = 1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;
	invariantConstraintsMatrix(5, 3) = -1.0;
	invariantConstraintsMatrix(6, 3) = -1.0;
	invariantConstraintsMatrix(6, 4) = 1.0;
	invariantConstraintsMatrix(7, 3) = 1.0;
	invariantConstraintsMatrix(7, 4) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 10.0;
	invariantBoundValue[3] = 10.0;
	invariantBoundValue[5] = 10.0;
	invariantBoundValue[7] = 10.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromv3;

	// The transition label is e5

	// Original guard: x_2 - x_3 >= 4

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(7, "e5", 3, 1, guard_polytope, assignment));

	Out_Going_Trans_fromv3.push_back(t);
	// The transition label is e6

	// Original guard: x_2 - x_3 <= 1

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = 1.0;
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(8, "e6", 3, 6, guard_polytope, assignment));

	Out_Going_Trans_fromv3.push_back(t);
	l = location::ptr(
			new location(3, "v3", system_dynamics, invariant, true,
					Out_Going_Trans_fromv3));
	Hybrid_Automata.addLocation(l);

}

void module2MotorCade(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I0, forbid_polytope;
	location::ptr l;
	transition::ptr t;
	polytope::ptr invariant;

	polytope::ptr guard_polytope;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix,
			Bmatrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV, C, invariantBoundValue,
			guardBoundValue, boundValueF;

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1, boundSignV =
			1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  v4

	row = 5;
	col = 5;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 12.0;
	C[1] = 12.0;
	C[2] = 12.0;
	C[3] = 10.0;
	C[4] = 9.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 8;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = -1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(4, 3) = 1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;
	invariantConstraintsMatrix(5, 3) = -1.0;
	invariantConstraintsMatrix(6, 3) = -1.0;
	invariantConstraintsMatrix(6, 4) = 1.0;
	invariantConstraintsMatrix(7, 3) = 1.0;
	invariantConstraintsMatrix(7, 4) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 10.0;
	invariantBoundValue[3] = 10.0;
	invariantBoundValue[5] = 10.0;
	invariantBoundValue[7] = 10.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromv4;

	// The transition label is e8

	// Original guard: x_3 - x_4 >= 4

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(9, "e8", 4, 1, guard_polytope, assignment));

	Out_Going_Trans_fromv4.push_back(t);
	// The transition label is e9

	// Original guard: x_3 - x_4 <= 1

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(10, "e9", 4, 6, guard_polytope, assignment));

	Out_Going_Trans_fromv4.push_back(t);
	l = location::ptr(
			new location(4, "v4", system_dynamics, invariant, true,
					Out_Going_Trans_fromv4));
	Hybrid_Automata.addLocation(l);

}

void module3MotorCade(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I0, forbid_polytope;
	location::ptr l;
	transition::ptr t;
	polytope::ptr invariant;

	polytope::ptr guard_polytope;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix,
			Bmatrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV, C, invariantBoundValue,
			guardBoundValue, boundValueF;

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1, boundSignV =
			1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  v5

	row = 5;
	col = 5;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 12.0;
	C[1] = 12.0;
	C[2] = 12.0;
	C[3] = 12.0;
	C[4] = 10.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 8;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = -1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(4, 3) = 1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;
	invariantConstraintsMatrix(5, 3) = -1.0;
	invariantConstraintsMatrix(6, 3) = -1.0;
	invariantConstraintsMatrix(6, 4) = 1.0;
	invariantConstraintsMatrix(7, 3) = 1.0;
	invariantConstraintsMatrix(7, 4) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 10.0;
	invariantBoundValue[3] = 10.0;
	invariantBoundValue[5] = 10.0;
	invariantBoundValue[7] = 10.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromv5;

	// The transition label is e11

	// Original guard: x_4 - x_5 >= 4

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(11, "e11", 5, 1, guard_polytope, assignment));

	Out_Going_Trans_fromv5.push_back(t);
	// The transition label is e12

	// Original guard: x_4 - x_5 <= 1

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = 1.0;
	guardConstraintsMatrix(0, 4) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(12, "e12", 5, 6, guard_polytope, assignment));

	Out_Going_Trans_fromv5.push_back(t);
	l = location::ptr(
			new location(5, "v5", system_dynamics, invariant, true,
					Out_Going_Trans_fromv5));
	Hybrid_Automata.addLocation(l);

}

void module4MotorCade(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I0, forbid_polytope;
	location::ptr l;
	transition::ptr t;
	polytope::ptr invariant;

	polytope::ptr guard_polytope;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix,
			Bmatrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV, C, invariantBoundValue,
			guardBoundValue, boundValueF;

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1, boundSignV =
			1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  GOOD

	row = 5;
	col = 5;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	system_dynamics.isEmptyC = true;

	std::list<transition::ptr> Out_Going_Trans_fromGOOD;

	l = location::ptr(
			new location(6, "BAD", system_dynamics, invariant, false,
					Out_Going_Trans_fromGOOD));
	Hybrid_Automata.addLocation(l);

}
