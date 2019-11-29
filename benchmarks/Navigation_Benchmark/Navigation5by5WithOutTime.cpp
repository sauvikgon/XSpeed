// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/amit/Desktop/SpaceExFromWebsite/SpaceEx64bit/spaceex_exe/STTJournalReadings/Nav5x5/Nav5.xml
// Command Line arguments: -tool xspeed "" -verbose -output /home/amit/Desktop/SpaceExFromWebsite/SpaceEx64bit/spaceex_exe/STTJournalReadings/Nav5x5/nav5x5.cpp -input /home/amit/Desktop/SpaceExFromWebsite/SpaceEx64bit/spaceex_exe/STTJournalReadings/Nav5x5/Nav5.xml /home/amit/Desktop/SpaceExFromWebsite/SpaceEx64bit/spaceex_exe/STTJournalReadings/Nav5x5/nav5.cfg



#include "../../benchmarks/Navigation_Benchmark/Navigation5by5WithOutTime.h"

void SetNavigationNav5by5WithOutTime(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	std::cout << "putting this to recompile the course through make";
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

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  loc3

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.8;
	C[3] = 0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc3;

	// The transition label is t6

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(1, "t6", 1, 10, guard_polytope, assignment));

	Out_Going_Trans_fromloc3.push_back(t);
	// The transition label is t8

	// Original guard: x1 = 1 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(2, "t8", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromloc3.push_back(t);
	// The transition label is t7

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(3, "t7", 1, 4, guard_polytope, assignment));

	Out_Going_Trans_fromloc3.push_back(t);
	l = location::ptr(
			new location(1, "loc3", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc3));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc8

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc8;

	// The transition label is t20

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(4, "t20", 2, 5, guard_polytope, assignment));

	Out_Going_Trans_fromloc8.push_back(t);
	// The transition label is t21

	// Original guard: x1 = 2 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(5, "t21", 2, 3, guard_polytope, assignment));

	Out_Going_Trans_fromloc8.push_back(t);
	// The transition label is t19

	// Original guard: x1 = 1 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(6, "t19", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromloc8.push_back(t);
	// The transition label is t18

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(7, "t18", 2, 13, guard_polytope, assignment));

	Out_Going_Trans_fromloc8.push_back(t);
	l = location::ptr(
			new location(2, "loc8", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc8));
	Hybrid_Automata.addLocation(l);

	// The mode name is  BAD

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	system_dynamics.isEmptyC = true;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromBAD;

	l = location::ptr(
			new location(3, "BAD", system_dynamics, invariant, true,
					Out_Going_Trans_fromBAD));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc4

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.8;
	C[3] = 0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc4;

	// The transition label is t9

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(8, "t9", 4, 1, guard_polytope, assignment));

	Out_Going_Trans_fromloc4.push_back(t);
	// The transition label is t11

	// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(9, "t11", 4, 5, guard_polytope, assignment));

	Out_Going_Trans_fromloc4.push_back(t);
	// The transition label is t10

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(10, "t10", 4, 9, guard_polytope, assignment));

	Out_Going_Trans_fromloc4.push_back(t);
	l = location::ptr(
			new location(4, "loc4", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc4));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc7

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc7;

	// The transition label is t15

	// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(11, "t15", 5, 4, guard_polytope, assignment));

	Out_Going_Trans_fromloc7.push_back(t);
	// The transition label is t14

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(12, "t14", 5, 2, guard_polytope, assignment));

	Out_Going_Trans_fromloc7.push_back(t);
	// The transition label is t17

	// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(13, "t17", 5, 6, guard_polytope, assignment));

	Out_Going_Trans_fromloc7.push_back(t);
	// The transition label is t16

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(14, "t16", 5, 7, guard_polytope, assignment));

	Out_Going_Trans_fromloc7.push_back(t);
	l = location::ptr(
			new location(5, "loc7", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc7));
	Hybrid_Automata.addLocation(l);

	Nav5Module1(Hybrid_Automata, init_state_list, reach_parameters);
	Nav5Module2(Hybrid_Automata, init_state_list, reach_parameters);
	Nav5Module3(Hybrid_Automata, init_state_list, reach_parameters);
	Nav5Module4(Hybrid_Automata, init_state_list, reach_parameters);

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
	boundValueI[0] = 3.4;
	boundValueI[1] = -3.1;
	boundValueI[2] = 3.8;
	boundValueI[3] = -3.6;
	boundValueI[4] = 0.1;
	boundValueI[5] = -0.1;
	boundValueI[6] = 0.1;
	boundValueI[7] = -0.1;

	initial_polytope_I0 = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id = 17;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I0, S0,
					transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);

	Hybrid_Automata.insert_to_map("x1", 0);
	Hybrid_Automata.insert_to_map("x2", 1);
	Hybrid_Automata.insert_to_map("v1", 2);
	Hybrid_Automata.insert_to_map("v2", 3);

/*	// ************* Section required for setting Reach Parameters & User Options *************
	unsigned int Directions_Type = 1;
	unsigned int iter_max = 425;
	double time_horizon = 10.0;
	double sampling_time = 0.001;
	std::vector<std::string> output_variables;
	output_variables.push_back("x1");
	output_variables.push_back("x2");

	op.set_timeStep(sampling_time);
	op.set_timeHorizon(time_horizon);
	op.set_bfs_level(iter_max);
	op.set_directionTemplate(Directions_Type);

	int x1 = Hybrid_Automata.get_index(output_variables[0]);
	int x2 = Hybrid_Automata.get_index(output_variables[1]);
	op.set_first_plot_dimension(x1);
	op.set_second_plot_dimension(x2);
	reach_parameters.TimeBound = op.get_timeHorizon();
	reach_parameters.Iterations = (unsigned int) op.get_timeHorizon()
			/ op.get_timeStep();
	reach_parameters.time_step = op.get_timeStep();

	std::vector<std::vector<double> > newDirections;
	math::matrix<double> Real_Directions;
	unsigned int dir_nums;
	if (Directions_Type == BOX) {
		dir_nums = 2 * dim;
		newDirections = generate_axis_directions(dim);
	}
	if (Directions_Type == OCT) {
		dir_nums = 2 * dim * dim;
		newDirections = get_octagonal_directions(dim);
	}
	if (Directions_Type > 2) {
		dir_nums = Directions_Type;
		newDirections = math::uni_sphere(dir_nums, dim, 100, 0.0005);
	}
	get_ublas_matrix(newDirections, Real_Directions);
	row = dir_nums;
	col = dim;
	reach_parameters.Directions.resize(row, col);
	reach_parameters.Directions = Real_Directions;*/
}

void Nav5Module1(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters)  {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

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

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  loc12

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.8;
	C[3] = -0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc12;

	// The transition label is t32

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(15, "t32", 6, 3, guard_polytope, assignment));

	Out_Going_Trans_fromloc12.push_back(t);
	// The transition label is t33

	// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(16, "t33", 6, 5, guard_polytope, assignment));

	Out_Going_Trans_fromloc12.push_back(t);
	// The transition label is t34

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(17, "t34", 6, 8, guard_polytope, assignment));

	Out_Going_Trans_fromloc12.push_back(t);
	// The transition label is t35

	// Original guard: x1 = 3 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(18, "t35", 6, 18, guard_polytope, assignment));

	Out_Going_Trans_fromloc12.push_back(t);
	l = location::ptr(
			new location(6, "loc12", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc12));
	Hybrid_Automata.addLocation(l);

	// The mode name is  GOOD

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	system_dynamics.isEmptyC = true;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromGOOD;

	l = location::ptr(
			new location(7, "GOOD", system_dynamics, invariant, true,
					Out_Going_Trans_fromGOOD));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc11

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc11;

	// The transition label is t31

	// Original guard: x1 = 3 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(19, "t31", 8, 20, guard_polytope, assignment));

	Out_Going_Trans_fromloc11.push_back(t);
	// The transition label is t30

	// Original guard: x1 = 2 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(20, "t30", 8, 7, guard_polytope, assignment));

	Out_Going_Trans_fromloc11.push_back(t);
	// The transition label is t29

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(21, "t29", 8, 6, guard_polytope, assignment));

	Out_Going_Trans_fromloc11.push_back(t);
	l = location::ptr(
			new location(8, "loc11", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc11));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc5

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.8;
	C[3] = 0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc5;

	// The transition label is t13

	// Original guard: x1 = 1 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(22, "t13", 9, 7, guard_polytope, assignment));

	Out_Going_Trans_fromloc5.push_back(t);
	// The transition label is t12

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(23, "t12", 9, 4, guard_polytope, assignment));

	Out_Going_Trans_fromloc5.push_back(t);
	l = location::ptr(
			new location(9, "loc5", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc5));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc2

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.8;
	C[3] = 0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc2;

	// The transition label is t4

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(24, "t4", 10, 1, guard_polytope, assignment));

	Out_Going_Trans_fromloc2.push_back(t);
	// The transition label is t3

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(25, "t3", 10, 11, guard_polytope, assignment));

	Out_Going_Trans_fromloc2.push_back(t);
	// The transition label is t5

	// Original guard: x1 = 1 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(26, "t5", 10, 13, guard_polytope, assignment));

	Out_Going_Trans_fromloc2.push_back(t);
	l = location::ptr(
			new location(10, "loc2", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc2));
	Hybrid_Automata.addLocation(l);

}

void Nav5Module2(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  loc1

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.8;
	C[3] = 0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc1;

	// The transition label is t1

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(27, "t1", 11, 10, guard_polytope, assignment));

	Out_Going_Trans_fromloc1.push_back(t);
	// The transition label is t2

	// Original guard: x1 = 1 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(28, "t2", 11, 12, guard_polytope, assignment));

	Out_Going_Trans_fromloc1.push_back(t);
	l = location::ptr(
			new location(11, "loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc10

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc10;

	// The transition label is t26

	// Original guard: x1 = 1 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(29, "t26", 12, 11, guard_polytope, assignment));

	Out_Going_Trans_fromloc10.push_back(t);
	// The transition label is t28

	// Original guard: x1 = 2 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(30, "t28", 12, 14, guard_polytope, assignment));

	Out_Going_Trans_fromloc10.push_back(t);
	// The transition label is t27

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(31, "t27", 12, 13, guard_polytope, assignment));

	Out_Going_Trans_fromloc10.push_back(t);
	l = location::ptr(
			new location(12, "loc10", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc10));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc9

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc9;

	// The transition label is t23

	// Original guard: x1 = 1 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(32, "t23", 13, 10, guard_polytope, assignment));

	Out_Going_Trans_fromloc9.push_back(t);
	// The transition label is t22

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(33, "t22", 13, 12, guard_polytope, assignment));

	Out_Going_Trans_fromloc9.push_back(t);
	// The transition label is t25

	// Original guard: x1 = 2 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(34, "t25", 13, 15, guard_polytope, assignment));

	Out_Going_Trans_fromloc9.push_back(t);
	// The transition label is t24

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(35, "t24", 13, 2, guard_polytope, assignment));

	Out_Going_Trans_fromloc9.push_back(t);
	l = location::ptr(
			new location(13, "loc9", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc9));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc15

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.8;
	C[3] = -0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc15;

	// The transition label is t40

	// Original guard: x1 = 2 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(36, "t40", 14, 12, guard_polytope, assignment));

	Out_Going_Trans_fromloc15.push_back(t);
	// The transition label is t42

	// Original guard: x1 = 3 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(37, "t42", 14, 16, guard_polytope, assignment));

	Out_Going_Trans_fromloc15.push_back(t);
	// The transition label is t41

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(38, "t41", 14, 15, guard_polytope, assignment));

	Out_Going_Trans_fromloc15.push_back(t);
	l = location::ptr(
			new location(14, "loc15", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc15));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc14

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.424266;
	C[3] = 0.494977;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc14;

	// The transition label is t36

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(39, "t36", 15, 14, guard_polytope, assignment));

	Out_Going_Trans_fromloc14.push_back(t);
	// The transition label is t37

	// Original guard: x1 = 2 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(40, "t37", 15, 13, guard_polytope, assignment));

	Out_Going_Trans_fromloc14.push_back(t);
	// The transition label is t39

	// Original guard: x1 = 3 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(41, "t39", 15, 17, guard_polytope, assignment));

	Out_Going_Trans_fromloc14.push_back(t);
	// The transition label is t38

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(42, "t38", 15, 3, guard_polytope, assignment));

	Out_Going_Trans_fromloc14.push_back(t);
	l = location::ptr(
			new location(15, "loc14", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc14));
	Hybrid_Automata.addLocation(l);

}

void Nav5Module3(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

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

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  loc20

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.8;
	C[3] = -0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc20;

	// The transition label is t58

	// Original guard: x1 = 3 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(43, "t58", 16, 14, guard_polytope, assignment));

	Out_Going_Trans_fromloc20.push_back(t);
	// The transition label is t60

	// Original guard: x1 = 4 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(44, "t60", 16, 21, guard_polytope, assignment));

	Out_Going_Trans_fromloc20.push_back(t);
	// The transition label is t59

	// Original guard: 3 <= x1 & x1 <= 4 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(45, "t59", 16, 17, guard_polytope, assignment));

	Out_Going_Trans_fromloc20.push_back(t);
	l = location::ptr(
			new location(16, "loc20", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc20));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc19

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.424266;
	C[3] = 0.494977;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc19;

	// The transition label is t55

	// Original guard: x1 = 3 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(46, "t55", 17, 15, guard_polytope, assignment));

	Out_Going_Trans_fromloc19.push_back(t);
	// The transition label is t57

	// Original guard: x1 = 4 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(47, "t57", 17, 22, guard_polytope, assignment));

	Out_Going_Trans_fromloc19.push_back(t);
	// The transition label is t54

	// Original guard: 3 <= x1 & x1 <= 4 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(48, "t54", 17, 16, guard_polytope, assignment));

	Out_Going_Trans_fromloc19.push_back(t);
	// The transition label is t56

	// Original guard: 3 <= x1 & x1 <= 4 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(49, "t56", 17, 19, guard_polytope, assignment));

	Out_Going_Trans_fromloc19.push_back(t);
	l = location::ptr(
			new location(17, "loc19", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc19));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc17

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.8;
	C[3] = -0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc17;

	// The transition label is t46

	// Original guard: 3 <= x1 & x1 <= 4 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(50, "t46", 18, 19, guard_polytope, assignment));

	Out_Going_Trans_fromloc17.push_back(t);
	// The transition label is t49

	// Original guard: x1 = 4 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(51, "t49", 18, 24, guard_polytope, assignment));

	Out_Going_Trans_fromloc17.push_back(t);
	// The transition label is t48

	// Original guard: 3 <= x1 & x1 <= 4 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(52, "t48", 18, 20, guard_polytope, assignment));

	Out_Going_Trans_fromloc17.push_back(t);
	// The transition label is t47

	// Original guard: x1 = 3 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(53, "t47", 18, 6, guard_polytope, assignment));

	Out_Going_Trans_fromloc17.push_back(t);
	l = location::ptr(
			new location(18, "loc17", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc17));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc18

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.424266;
	C[3] = -0.494977;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc18;

	// The transition label is t50

	// Original guard: 3 <= x1 & x1 <= 4 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(54, "t50", 19, 17, guard_polytope, assignment));

	Out_Going_Trans_fromloc18.push_back(t);
	// The transition label is t51

	// Original guard: x1 = 3 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(55, "t51", 19, 3, guard_polytope, assignment));

	Out_Going_Trans_fromloc18.push_back(t);
	// The transition label is t53

	// Original guard: x1 = 4 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(56, "t53", 19, 23, guard_polytope, assignment));

	Out_Going_Trans_fromloc18.push_back(t);
	// The transition label is t52

	// Original guard: 3 <= x1 & x1 <= 4 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(57, "t52", 19, 18, guard_polytope, assignment));

	Out_Going_Trans_fromloc18.push_back(t);
	l = location::ptr(
			new location(19, "loc18", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc18));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc16

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc16;

	// The transition label is t43

	// Original guard: 3 <= x1 & x1 <= 4 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(58, "t43", 20, 18, guard_polytope, assignment));

	Out_Going_Trans_fromloc16.push_back(t);
	// The transition label is t45

	// Original guard: x1 = 4 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(59, "t45", 20, 25, guard_polytope, assignment));

	Out_Going_Trans_fromloc16.push_back(t);
	// The transition label is t44

	// Original guard: x1 = 3 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(60, "t44", 20, 8, guard_polytope, assignment));

	Out_Going_Trans_fromloc16.push_back(t);
	l = location::ptr(
			new location(20, "loc16", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc16));
	Hybrid_Automata.addLocation(l);

}

void Nav5Module4(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

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

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  loc25

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.8;
	C[3] = -0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc25;

	// The transition label is t72

	// Original guard: x1 = 4 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(61, "t72", 21, 16, guard_polytope, assignment));

	Out_Going_Trans_fromloc25.push_back(t);
	// The transition label is t73

	// Original guard: 4 <= x1 & x1 <= 5 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(62, "t73", 21, 22, guard_polytope, assignment));

	Out_Going_Trans_fromloc25.push_back(t);
	l = location::ptr(
			new location(21, "loc25", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc25));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc24

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc24;

	// The transition label is t70

	// Original guard: x1 = 4 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(63, "t70", 22, 17, guard_polytope, assignment));

	Out_Going_Trans_fromloc24.push_back(t);
	// The transition label is t69

	// Original guard: 4 <= x1 & x1 <= 5 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(64, "t69", 22, 21, guard_polytope, assignment));

	Out_Going_Trans_fromloc24.push_back(t);
	// The transition label is t71

	// Original guard: 4 <= x1 & x1 <= 5 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(65, "t71", 22, 23, guard_polytope, assignment));

	Out_Going_Trans_fromloc24.push_back(t);
	l = location::ptr(
			new location(22, "loc24", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc24));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc23

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc23;

	// The transition label is t66

	// Original guard: 4 <= x1 & x1 <= 5 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(66, "t66", 23, 22, guard_polytope, assignment));

	Out_Going_Trans_fromloc23.push_back(t);
	// The transition label is t67

	// Original guard: x1 = 4 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(67, "t67", 23, 19, guard_polytope, assignment));

	Out_Going_Trans_fromloc23.push_back(t);
	// The transition label is t68

	// Original guard: 4 <= x1 & x1 <= 5 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(68, "t68", 23, 24, guard_polytope, assignment));

	Out_Going_Trans_fromloc23.push_back(t);
	l = location::ptr(
			new location(23, "loc23", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc23));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc22

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.8;
	C[3] = -0.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc22;

	// The transition label is t63

	// Original guard: 4 <= x1 & x1 <= 5 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(69, "t63", 24, 23, guard_polytope, assignment));

	Out_Going_Trans_fromloc22.push_back(t);
	// The transition label is t65

	// Original guard: 4 <= x1 & x1 <= 5 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(70, "t65", 24, 25, guard_polytope, assignment));

	Out_Going_Trans_fromloc22.push_back(t);
	// The transition label is t64

	// Original guard: x1 = 4 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(71, "t64", 24, 18, guard_polytope, assignment));

	Out_Going_Trans_fromloc22.push_back(t);
	l = location::ptr(
			new location(24, "loc22", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc22));
	Hybrid_Automata.addLocation(l);

	// The mode name is  loc21

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc21;

	// The transition label is t61

	// Original guard: 4 <= x1 & x1 <= 5 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 9;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(72, "t61", 25, 24, guard_polytope, assignment));

	Out_Going_Trans_fromloc21.push_back(t);
	// The transition label is t62

	// Original guard: x1 = 4 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(7, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
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
			new transition(73, "t62", 25, 20, guard_polytope, assignment));

	Out_Going_Trans_fromloc21.push_back(t);
	l = location::ptr(
			new location(25, "loc21", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc21));
	Hybrid_Automata.addLocation(l);

}
