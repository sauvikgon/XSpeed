/*
 * fwr.cpp
 *
 *  Created on: 05-Dec-2016
 *      Author: amit
 */

#include "benchmarks/Arch_Benchmarks/fwr.h"

void setfwr(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  D1_on

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1, 2) = 1.0;
	Amatrix(2, 1) = -98596.0;
	Amatrix(3, 2) = 0.001;
	Amatrix(3, 3) = -0.0010001;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromD1_on;

	// The transition label ishop

	// Original guard: Vin <= Vo

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "hop", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromD1_on.push_back(t);
	// The transition label ishop

	// Original guard: Vin <= Vo & -Vin <= Vo

	row = 2;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(0, 3) = -1.0;
	guardConstraintsMatrix(1, 2) = -1.0;
	guardConstraintsMatrix(1, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(2, "hop", 1, 3, guard_polytope, assignment));

	Out_Going_Trans_fromD1_on.push_back(t);
	l = location::ptr(
			new location(1, "D1_on", system_dynamics, invariant, true,
					Out_Going_Trans_fromD1_on));

	Hybrid_Automata.addInitialLocation(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  D2_on

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1, 2) = 1.0;
	Amatrix(2, 1) = -98596.0;
	Amatrix(3, 2) = -0.001;
	Amatrix(3, 3) = -0.0010001;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromD2_on;

	// The transition label ishop

	// Original guard: Vin >= Vo

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(0, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(3, "hop", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromD2_on.push_back(t);
	// The transition label ishop

	// Original guard: Vin <= Vo & -Vin <= Vo

	row = 2;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(0, 3) = -1.0;
	guardConstraintsMatrix(1, 2) = -1.0;
	guardConstraintsMatrix(1, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(4, "hop", 2, 3, guard_polytope, assignment));

	Out_Going_Trans_fromD2_on.push_back(t);
	l = location::ptr(
			new location(2, "D2_on", system_dynamics, invariant, true,
					Out_Going_Trans_fromD2_on));
	Hybrid_Automata.addLocation(l);

	// The mode name is  both_off

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1, 2) = 1.0;
	Amatrix(2, 1) = -98596.0;
	Amatrix(3, 3) = -1.0000000000000001E-7;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 3) = 1.0;
	invariantConstraintsMatrix(3, 3) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromboth_off;

	// The transition label ishop

	// Original guard: Vin >= Vo & -Vin <= Vo

	row = 2;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(0, 3) = 1.0;
	guardConstraintsMatrix(1, 2) = -1.0;
	guardConstraintsMatrix(1, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(5, "hop", 3, 1, guard_polytope, assignment));

	Out_Going_Trans_fromboth_off.push_back(t);
	// The transition label ishop

	// Original guard: Vin <= Vo & -Vin >= Vo

	row = 2;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(0, 3) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(6, "hop", 3, 2, guard_polytope, assignment));

	Out_Going_Trans_fromboth_off.push_back(t);
	l = location::ptr(
			new location(3, "both_off", system_dynamics, invariant, true,
					Out_Going_Trans_fromboth_off));
	Hybrid_Automata.addLocation(l);

	row = 8;
	col = 4;
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
	boundValueI.resize(row);
	boundValueI.assign(row, 0);
	boundValueI[2] = -0.012738853503184714;
	boundValueI[3] = 0.012738853503184714;
	boundValueI[4] = 4;
	boundValueI[5] = -4;
	boundValueI[6] = 4;
	boundValueI[7] = -4;

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

	Hybrid_Automata.insert_to_map("t", 0);
	Hybrid_Automata.insert_to_map("x0", 1);
	Hybrid_Automata.insert_to_map("Vin", 2);
	Hybrid_Automata.insert_to_map("Vo", 3);

}
