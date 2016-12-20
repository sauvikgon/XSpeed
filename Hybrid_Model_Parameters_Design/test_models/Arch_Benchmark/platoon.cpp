/*
 * fwr.cpp
 *
 *  Created on: 05-Dec-2016
 *      Author: amit
 */

#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/platoon.h"

void setplatoon(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  elf

	row = 10;
	col = 10;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 1) = 1.0;
	Amatrix(1, 2) = -1.0;
	Amatrix(2, 0) = 1.605;
	Amatrix(2, 1) = 4.868;
	Amatrix(2, 2) = -3.5754;
	Amatrix(2, 3) = -0.8198;
	Amatrix(2, 4) = 0.427;
	Amatrix(2, 5) = -0.045;
	Amatrix(2, 6) = -0.1942;
	Amatrix(2, 7) = 0.3626;
	Amatrix(2, 8) = -0.0946;
	Amatrix(3, 4) = 1.0;
	Amatrix(4, 2) = 1.0;
	Amatrix(4, 5) = -1.0;
	Amatrix(5, 0) = 0.8718;
	Amatrix(5, 1) = 3.814;
	Amatrix(5, 2) = -0.0754;
	Amatrix(5, 3) = 1.1936;
	Amatrix(5, 4) = 3.6258;
	Amatrix(5, 5) = -3.2396;
	Amatrix(5, 6) = -0.595;
	Amatrix(5, 7) = 0.1294;
	Amatrix(5, 8) = -0.0796;
	Amatrix(6, 7) = 1.0;
	Amatrix(7, 5) = 1.0;
	Amatrix(7, 8) = -1.0;
	Amatrix(8, 0) = 0.7132;
	Amatrix(8, 1) = 3.573;
	Amatrix(8, 2) = -0.0964;
	Amatrix(8, 3) = 0.8472;
	Amatrix(8, 4) = 3.2568;
	Amatrix(8, 5) = -0.0876;
	Amatrix(8, 6) = 1.2726;
	Amatrix(8, 7) = 3.072;
	Amatrix(8, 8) = -3.1356;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	col = 1;
	Bmatrix.resize(row, col);
	Bmatrix.clear();
	Bmatrix(1, 0) = 1.0;
	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	C.resize(row);
	C.assign(row, 0);
	C[9] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 10;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 9) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	row = 2;
	col = 1;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = -1.0;
	ConstraintsMatrixV(1, 0) = 1.0;

	boundValueV.resize(row);
	boundValueV[0] = 9.0;
	boundValueV[1] = 1.0;
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	std::list<transition::ptr> Out_Going_Trans_fromelf;

	// The transition label isnull

	// Original guard: t >= 20

	row = 1;
	col = 10;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 9) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 10;
	col = 10;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	R(6, 6) = 1.0;
	R(7, 7) = 1.0;
	R(8, 8) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "null", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromelf.push_back(t);
	l = location::ptr(
			new location(1, "elf", system_dynamics, invariant, true,
					Out_Going_Trans_fromelf));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  dreizehn

	row = 10;
	col = 10;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 1) = 1.0;
	Amatrix(1, 2) = -1.0;
	Amatrix(2, 0) = 1.605;
	Amatrix(2, 1) = 4.868;
	Amatrix(2, 2) = -3.5754;
	Amatrix(3, 4) = 1.0;
	Amatrix(4, 2) = 1.0;
	Amatrix(4, 5) = -1.0;
	Amatrix(5, 3) = 1.1936;
	Amatrix(5, 4) = 3.6258;
	Amatrix(5, 5) = -3.2396;
	Amatrix(6, 7) = 1.0;
	Amatrix(7, 5) = 1.0;
	Amatrix(7, 8) = -1.0;
	Amatrix(8, 0) = 0.7132;
	Amatrix(8, 1) = 3.573;
	Amatrix(8, 2) = -0.0964;
	Amatrix(8, 3) = 0.8472;
	Amatrix(8, 4) = 3.2568;
	Amatrix(8, 5) = -0.0876;
	Amatrix(8, 6) = 1.2726;
	Amatrix(8, 7) = 3.072;
	Amatrix(8, 8) = -3.1356;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	col = 1;
	Bmatrix.resize(row, col);
	Bmatrix.clear();
	Bmatrix(1, 0) = 1.0;
	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	C.resize(row);
	C.assign(row, 0);
	C[9] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 10;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 9) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	row = 2;
	col = 1;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = -1.0;
	ConstraintsMatrixV(1, 0) = 1.0;

	boundValueV.resize(row);
	boundValueV[0] = 9.0;
	boundValueV[1] = 1.0;
	system_dynamics.U = polytope::ptr(
			new polytope(ConstraintsMatrixV, boundValueV, boundSignV));

	std::list<transition::ptr> Out_Going_Trans_fromdreizehn;

	// The transition label isnull

	// Original guard: t >= 20

	row = 1;
	col = 10;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 9) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 10;
	col = 10;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	R(6, 6) = 1.0;
	R(7, 7) = 1.0;
	R(8, 8) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(2, "null", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromdreizehn.push_back(t);
	l = location::ptr(
			new location(2, "dreizehn", system_dynamics, invariant, true,
					Out_Going_Trans_fromdreizehn));
	Hybrid_Automata.addLocation(l);

	row = 20;
	col = 10;
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
	ConstraintsMatrixI(10, 5) = 1;
	ConstraintsMatrixI(11, 5) = -1;
	ConstraintsMatrixI(12, 6) = 1;
	ConstraintsMatrixI(13, 6) = -1;
	ConstraintsMatrixI(14, 7) = 1;
	ConstraintsMatrixI(15, 7) = -1;
	ConstraintsMatrixI(16, 8) = 1;
	ConstraintsMatrixI(17, 8) = -1;
	ConstraintsMatrixI(18, 9) = 1;
	ConstraintsMatrixI(19, 9) = -1;
	boundValueI.resize(row);
	boundValueI.assign(row, 0);

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

	Hybrid_Automata.insert_to_map("x1", 0);
	Hybrid_Automata.insert_to_map("x2", 1);
	Hybrid_Automata.insert_to_map("x3", 2);
	Hybrid_Automata.insert_to_map("x4", 3);
	Hybrid_Automata.insert_to_map("x5", 4);
	Hybrid_Automata.insert_to_map("x6", 5);
	Hybrid_Automata.insert_to_map("x7", 6);
	Hybrid_Automata.insert_to_map("x8", 7);
	Hybrid_Automata.insert_to_map("x9", 8);
	Hybrid_Automata.insert_to_map("t", 9);

}
