#include "benchmarks/Arch_Benchmarks/setNav3u.h"

void setNav3u(hybrid_automata& Hybrid_Automata,
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

// The mode name is  L000

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL000;

// The transition label is d1

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "d1", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromL000.push_back(t);
// The transition label is d2

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(2, "d2", 1, 4, guard_polytope, assignment));

	Out_Going_Trans_fromL000.push_back(t);
// The transition label is d3

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(3, "d3", 1, 10, guard_polytope, assignment));

	Out_Going_Trans_fromL000.push_back(t);
	l = location::ptr(
			new location(1, "L000", system_dynamics, invariant, true,
					Out_Going_Trans_fromL000));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);

// The mode name is  L001

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL001;

// The transition label is d4

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(4, "d4", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromL001.push_back(t);
// The transition label is d5

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(5, "d5", 2, 3, guard_polytope, assignment));

	Out_Going_Trans_fromL001.push_back(t);
// The transition label is d6

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(6, "d6", 2, 5, guard_polytope, assignment));

	Out_Going_Trans_fromL001.push_back(t);
// The transition label is d7

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(7, "d7", 2, 11, guard_polytope, assignment));

	Out_Going_Trans_fromL001.push_back(t);
	l = location::ptr(
			new location(2, "L001", system_dynamics, invariant, true,
					Out_Going_Trans_fromL001));
	Hybrid_Automata.addLocation(l);

// The mode name is  L002

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL002;

// The transition label is d8

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(8, "d8", 3, 2, guard_polytope, assignment));

	Out_Going_Trans_fromL002.push_back(t);
// The transition label is d9

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(9, "d9", 3, 6, guard_polytope, assignment));

	Out_Going_Trans_fromL002.push_back(t);
// The transition label is d10

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(10, "d10", 3, 12, guard_polytope, assignment));

	Out_Going_Trans_fromL002.push_back(t);
	l = location::ptr(
			new location(3, "L002", system_dynamics, invariant, true,
					Out_Going_Trans_fromL002));
	Hybrid_Automata.addLocation(l);

// The mode name is  L010

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL010;

// The transition label is d11

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(11, "d11", 4, 5, guard_polytope, assignment));

	Out_Going_Trans_fromL010.push_back(t);
// The transition label is d12

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(12, "d12", 4, 1, guard_polytope, assignment));

	Out_Going_Trans_fromL010.push_back(t);
// The transition label is d13

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(13, "d13", 4, 7, guard_polytope, assignment));

	Out_Going_Trans_fromL010.push_back(t);
// The transition label is d14

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(14, "d14", 4, 13, guard_polytope, assignment));

	Out_Going_Trans_fromL010.push_back(t);
	l = location::ptr(
			new location(4, "L010", system_dynamics, invariant, true,
					Out_Going_Trans_fromL010));
	Hybrid_Automata.addLocation(l);

// The mode name is  L011

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL011;

// The transition label is d15

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(15, "d15", 5, 4, guard_polytope, assignment));

	Out_Going_Trans_fromL011.push_back(t);
// The transition label is d16

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(16, "d16", 5, 6, guard_polytope, assignment));

	Out_Going_Trans_fromL011.push_back(t);
// The transition label is d17

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(17, "d17", 5, 2, guard_polytope, assignment));

	Out_Going_Trans_fromL011.push_back(t);
// The transition label is d18

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(18, "d18", 5, 8, guard_polytope, assignment));

	Out_Going_Trans_fromL011.push_back(t);
// The transition label is d19

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(19, "d19", 5, 14, guard_polytope, assignment));

	Out_Going_Trans_fromL011.push_back(t);
	l = location::ptr(
			new location(5, "L011", system_dynamics, invariant, true,
					Out_Going_Trans_fromL011));
	Hybrid_Automata.addLocation(l);

// The mode name is  L012

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL012;

// The transition label is d20

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(20, "d20", 6, 5, guard_polytope, assignment));

	Out_Going_Trans_fromL012.push_back(t);
// The transition label is d21

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(21, "d21", 6, 3, guard_polytope, assignment));

	Out_Going_Trans_fromL012.push_back(t);
// The transition label is d22

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(22, "d22", 6, 9, guard_polytope, assignment));

	Out_Going_Trans_fromL012.push_back(t);
// The transition label is d23

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(23, "d23", 6, 15, guard_polytope, assignment));

	Out_Going_Trans_fromL012.push_back(t);
	l = location::ptr(
			new location(6, "L012", system_dynamics, invariant, true,
					Out_Going_Trans_fromL012));
	Hybrid_Automata.addLocation(l);

// The mode name is  L020

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL020;

// The transition label is d24

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(24, "d24", 7, 8, guard_polytope, assignment));

	Out_Going_Trans_fromL020.push_back(t);
// The transition label is d25

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(25, "d25", 7, 4, guard_polytope, assignment));

	Out_Going_Trans_fromL020.push_back(t);
// The transition label is d26

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(26, "d26", 7, 16, guard_polytope, assignment));

	Out_Going_Trans_fromL020.push_back(t);
	l = location::ptr(
			new location(7, "L020", system_dynamics, invariant, true,
					Out_Going_Trans_fromL020));
	Hybrid_Automata.addLocation(l);

	NAVmodule1(Hybrid_Automata, init_state_list, reach_parameters);
	NAVmodule2(Hybrid_Automata, init_state_list, reach_parameters);
	NAVmodule3(Hybrid_Automata, init_state_list, reach_parameters);
	NAVmodule4(Hybrid_Automata, init_state_list, reach_parameters);

	row = 6;
	col = 3;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI.clear();
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(4, 2) = 1;
	ConstraintsMatrixI(5, 2) = -1;
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

}

void NAVmodule1(hybrid_automata& Hybrid_Automata,
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

// The mode name is  L021

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL021;

// The transition label is d27

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(27, "d27", 8, 7, guard_polytope, assignment));

	Out_Going_Trans_fromL021.push_back(t);
// The transition label is d28

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(28, "d28", 8, 9, guard_polytope, assignment));

	Out_Going_Trans_fromL021.push_back(t);
// The transition label is d29

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(29, "d29", 8, 5, guard_polytope, assignment));

	Out_Going_Trans_fromL021.push_back(t);
// The transition label is d30

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(30, "d30", 8, 17, guard_polytope, assignment));

	Out_Going_Trans_fromL021.push_back(t);
	l = location::ptr(
			new location(8, "L021", system_dynamics, invariant, true,
					Out_Going_Trans_fromL021));
	Hybrid_Automata.addLocation(l);

// The mode name is  L022

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL022;

// The transition label is d31

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(31, "d31", 9, 8, guard_polytope, assignment));

	Out_Going_Trans_fromL022.push_back(t);
// The transition label is d32

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(32, "d32", 9, 6, guard_polytope, assignment));

	Out_Going_Trans_fromL022.push_back(t);
// The transition label is d33

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(33, "d33", 9, 18, guard_polytope, assignment));

	Out_Going_Trans_fromL022.push_back(t);
	l = location::ptr(
			new location(9, "L022", system_dynamics, invariant, true,
					Out_Going_Trans_fromL022));
	Hybrid_Automata.addLocation(l);

// The mode name is  L100

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL100;

// The transition label is d34

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(34, "d34", 10, 11, guard_polytope, assignment));

	Out_Going_Trans_fromL100.push_back(t);
// The transition label is d35

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(35, "d35", 10, 13, guard_polytope, assignment));

	Out_Going_Trans_fromL100.push_back(t);
// The transition label is d36

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(36, "d36", 10, 1, guard_polytope, assignment));

	Out_Going_Trans_fromL100.push_back(t);
// The transition label is d37

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(37, "d37", 10, 19, guard_polytope, assignment));

	Out_Going_Trans_fromL100.push_back(t);
	l = location::ptr(
			new location(10, "L100", system_dynamics, invariant, true,
					Out_Going_Trans_fromL100));
	Hybrid_Automata.addLocation(l);

// The mode name is  L101

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL101;

// The transition label is d38

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(38, "d38", 11, 10, guard_polytope, assignment));

	Out_Going_Trans_fromL101.push_back(t);
// The transition label is d39

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(39, "d39", 11, 12, guard_polytope, assignment));

	Out_Going_Trans_fromL101.push_back(t);
// The transition label is d40

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(40, "d40", 11, 14, guard_polytope, assignment));

	Out_Going_Trans_fromL101.push_back(t);
// The transition label is d41

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(41, "d41", 11, 2, guard_polytope, assignment));

	Out_Going_Trans_fromL101.push_back(t);
// The transition label is d42

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(42, "d42", 11, 20, guard_polytope, assignment));

	Out_Going_Trans_fromL101.push_back(t);
	l = location::ptr(
			new location(11, "L101", system_dynamics, invariant, true,
					Out_Going_Trans_fromL101));
	Hybrid_Automata.addLocation(l);

// The mode name is  L102

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL102;

// The transition label is d43

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(43, "d43", 12, 11, guard_polytope, assignment));

	Out_Going_Trans_fromL102.push_back(t);
// The transition label is d44

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(44, "d44", 12, 15, guard_polytope, assignment));

	Out_Going_Trans_fromL102.push_back(t);
// The transition label is d45

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(45, "d45", 12, 3, guard_polytope, assignment));

	Out_Going_Trans_fromL102.push_back(t);
// The transition label is d46

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(46, "d46", 12, 21, guard_polytope, assignment));

	Out_Going_Trans_fromL102.push_back(t);
	l = location::ptr(
			new location(12, "L102", system_dynamics, invariant, true,
					Out_Going_Trans_fromL102));
	Hybrid_Automata.addLocation(l);

}

void NAVmodule2(hybrid_automata& Hybrid_Automata,
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

// The mode name is  L110

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL110;

// The transition label is d47

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(47, "d47", 13, 14, guard_polytope, assignment));

	Out_Going_Trans_fromL110.push_back(t);
// The transition label is d48

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(48, "d48", 13, 10, guard_polytope, assignment));

	Out_Going_Trans_fromL110.push_back(t);
// The transition label is d49

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(49, "d49", 13, 16, guard_polytope, assignment));

	Out_Going_Trans_fromL110.push_back(t);
// The transition label is d50

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(50, "d50", 13, 4, guard_polytope, assignment));

	Out_Going_Trans_fromL110.push_back(t);
// The transition label is d51

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(51, "d51", 13, 22, guard_polytope, assignment));

	Out_Going_Trans_fromL110.push_back(t);
	l = location::ptr(
			new location(13, "L110", system_dynamics, invariant, true,
					Out_Going_Trans_fromL110));
	Hybrid_Automata.addLocation(l);

// The mode name is  L111

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL111;

// The transition label is d52

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(52, "d52", 14, 13, guard_polytope, assignment));

	Out_Going_Trans_fromL111.push_back(t);
// The transition label is d53

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(53, "d53", 14, 15, guard_polytope, assignment));

	Out_Going_Trans_fromL111.push_back(t);
// The transition label is d54

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(54, "d54", 14, 11, guard_polytope, assignment));

	Out_Going_Trans_fromL111.push_back(t);
// The transition label is d55

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(55, "d55", 14, 17, guard_polytope, assignment));

	Out_Going_Trans_fromL111.push_back(t);
// The transition label is d56

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(56, "d56", 14, 5, guard_polytope, assignment));

	Out_Going_Trans_fromL111.push_back(t);
// The transition label is d57

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(57, "d57", 14, 23, guard_polytope, assignment));

	Out_Going_Trans_fromL111.push_back(t);
	l = location::ptr(
			new location(14, "L111", system_dynamics, invariant, true,
					Out_Going_Trans_fromL111));
	Hybrid_Automata.addLocation(l);

// The mode name is  L112

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL112;

// The transition label is d58

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(58, "d58", 15, 14, guard_polytope, assignment));

	Out_Going_Trans_fromL112.push_back(t);
// The transition label is d59

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(59, "d59", 15, 12, guard_polytope, assignment));

	Out_Going_Trans_fromL112.push_back(t);
// The transition label is d60

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(60, "d60", 15, 18, guard_polytope, assignment));

	Out_Going_Trans_fromL112.push_back(t);
// The transition label is d61

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(61, "d61", 15, 6, guard_polytope, assignment));

	Out_Going_Trans_fromL112.push_back(t);
// The transition label is d62

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(62, "d62", 15, 24, guard_polytope, assignment));

	Out_Going_Trans_fromL112.push_back(t);
	l = location::ptr(
			new location(15, "L112", system_dynamics, invariant, true,
					Out_Going_Trans_fromL112));
	Hybrid_Automata.addLocation(l);

// The mode name is  L120

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL120;

// The transition label is d63

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(63, "d63", 16, 17, guard_polytope, assignment));

	Out_Going_Trans_fromL120.push_back(t);
// The transition label is d64

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(64, "d64", 16, 13, guard_polytope, assignment));

	Out_Going_Trans_fromL120.push_back(t);
// The transition label is d65

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(65, "d65", 16, 7, guard_polytope, assignment));

	Out_Going_Trans_fromL120.push_back(t);
// The transition label is d66

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(66, "d66", 16, 25, guard_polytope, assignment));

	Out_Going_Trans_fromL120.push_back(t);
	l = location::ptr(
			new location(16, "L120", system_dynamics, invariant, true,
					Out_Going_Trans_fromL120));
	Hybrid_Automata.addLocation(l);

// The mode name is  L121

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL121;

// The transition label is d67

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(67, "d67", 17, 16, guard_polytope, assignment));

	Out_Going_Trans_fromL121.push_back(t);
// The transition label is d68

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(68, "d68", 17, 18, guard_polytope, assignment));

	Out_Going_Trans_fromL121.push_back(t);
// The transition label is d69

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(69, "d69", 17, 14, guard_polytope, assignment));

	Out_Going_Trans_fromL121.push_back(t);
// The transition label is d70

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(70, "d70", 17, 8, guard_polytope, assignment));

	Out_Going_Trans_fromL121.push_back(t);
// The transition label is d71

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(71, "d71", 17, 26, guard_polytope, assignment));

	Out_Going_Trans_fromL121.push_back(t);
	l = location::ptr(
			new location(17, "L121", system_dynamics, invariant, true,
					Out_Going_Trans_fromL121));
	Hybrid_Automata.addLocation(l);

}

void NAVmodule3(hybrid_automata& Hybrid_Automata,
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

// The mode name is  L122

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL122;

// The transition label is d72

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(72, "d72", 18, 17, guard_polytope, assignment));

	Out_Going_Trans_fromL122.push_back(t);
// The transition label is d73

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(73, "d73", 18, 15, guard_polytope, assignment));

	Out_Going_Trans_fromL122.push_back(t);
// The transition label is d74

// Original guard: x3 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(74, "d74", 18, 9, guard_polytope, assignment));

	Out_Going_Trans_fromL122.push_back(t);
// The transition label is d75

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(75, "d75", 18, 27, guard_polytope, assignment));

	Out_Going_Trans_fromL122.push_back(t);
	l = location::ptr(
			new location(18, "L122", system_dynamics, invariant, true,
					Out_Going_Trans_fromL122));
	Hybrid_Automata.addLocation(l);

// The mode name is  L200

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL200;

// The transition label is d76

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(76, "d76", 19, 20, guard_polytope, assignment));

	Out_Going_Trans_fromL200.push_back(t);
// The transition label is d77

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(77, "d77", 19, 22, guard_polytope, assignment));

	Out_Going_Trans_fromL200.push_back(t);
// The transition label is d78

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(78, "d78", 19, 10, guard_polytope, assignment));

	Out_Going_Trans_fromL200.push_back(t);
	l = location::ptr(
			new location(19, "L200", system_dynamics, invariant, true,
					Out_Going_Trans_fromL200));
	Hybrid_Automata.addLocation(l);

// The mode name is  L201

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL201;

// The transition label is d79

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(79, "d79", 20, 19, guard_polytope, assignment));

	Out_Going_Trans_fromL201.push_back(t);
// The transition label is d80

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(80, "d80", 20, 21, guard_polytope, assignment));

	Out_Going_Trans_fromL201.push_back(t);
// The transition label is d81

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(81, "d81", 20, 23, guard_polytope, assignment));

	Out_Going_Trans_fromL201.push_back(t);
// The transition label is d82

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(82, "d82", 20, 11, guard_polytope, assignment));

	Out_Going_Trans_fromL201.push_back(t);
	l = location::ptr(
			new location(20, "L201", system_dynamics, invariant, true,
					Out_Going_Trans_fromL201));
	Hybrid_Automata.addLocation(l);

// The mode name is  L202

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[3] = 1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL202;

// The transition label is d83

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(83, "d83", 21, 20, guard_polytope, assignment));

	Out_Going_Trans_fromL202.push_back(t);
// The transition label is d84

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(84, "d84", 21, 24, guard_polytope, assignment));

	Out_Going_Trans_fromL202.push_back(t);
// The transition label is d85

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(85, "d85", 21, 12, guard_polytope, assignment));

	Out_Going_Trans_fromL202.push_back(t);
	l = location::ptr(
			new location(21, "L202", system_dynamics, invariant, true,
					Out_Going_Trans_fromL202));
	Hybrid_Automata.addLocation(l);

// The mode name is  L210

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL210;

// The transition label is d86

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(86, "d86", 22, 23, guard_polytope, assignment));

	Out_Going_Trans_fromL210.push_back(t);
// The transition label is d87

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(87, "d87", 22, 19, guard_polytope, assignment));

	Out_Going_Trans_fromL210.push_back(t);
// The transition label is d88

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(88, "d88", 22, 25, guard_polytope, assignment));

	Out_Going_Trans_fromL210.push_back(t);
// The transition label is d89

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(89, "d89", 22, 13, guard_polytope, assignment));

	Out_Going_Trans_fromL210.push_back(t);
	l = location::ptr(
			new location(22, "L210", system_dynamics, invariant, true,
					Out_Going_Trans_fromL210));
	Hybrid_Automata.addLocation(l);

}

void NAVmodule4(hybrid_automata& Hybrid_Automata,
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

// The mode name is  L211

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL211;

// The transition label is d90

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(90, "d90", 23, 22, guard_polytope, assignment));

	Out_Going_Trans_fromL211.push_back(t);
// The transition label is d91

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(91, "d91", 23, 24, guard_polytope, assignment));

	Out_Going_Trans_fromL211.push_back(t);
// The transition label is d92

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(92, "d92", 23, 20, guard_polytope, assignment));

	Out_Going_Trans_fromL211.push_back(t);
// The transition label is d93

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(93, "d93", 23, 26, guard_polytope, assignment));

	Out_Going_Trans_fromL211.push_back(t);
// The transition label is d94

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(94, "d94", 23, 14, guard_polytope, assignment));

	Out_Going_Trans_fromL211.push_back(t);
	l = location::ptr(
			new location(23, "L211", system_dynamics, invariant, true,
					Out_Going_Trans_fromL211));
	Hybrid_Automata.addLocation(l);

// The mode name is  L212

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL212;

// The transition label is d95

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(95, "d95", 24, 23, guard_polytope, assignment));

	Out_Going_Trans_fromL212.push_back(t);
// The transition label is d96

// Original guard: x2 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(96, "d96", 24, 21, guard_polytope, assignment));

	Out_Going_Trans_fromL212.push_back(t);
// The transition label is d97

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(97, "d97", 24, 27, guard_polytope, assignment));

	Out_Going_Trans_fromL212.push_back(t);
// The transition label is d98

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(98, "d98", 24, 15, guard_polytope, assignment));

	Out_Going_Trans_fromL212.push_back(t);
	l = location::ptr(
			new location(24, "L212", system_dynamics, invariant, true,
					Out_Going_Trans_fromL212));
	Hybrid_Automata.addLocation(l);

// The mode name is  L220

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 0.8;
	C[1] = 1.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL220;

// The transition label is d99

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(99, "d99", 25, 26, guard_polytope, assignment));

	Out_Going_Trans_fromL220.push_back(t);
// The transition label is d100

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(100, "d100", 25, 22, guard_polytope, assignment));

	Out_Going_Trans_fromL220.push_back(t);
// The transition label is d101

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(101, "d101", 25, 16, guard_polytope, assignment));

	Out_Going_Trans_fromL220.push_back(t);
	l = location::ptr(
			new location(25, "L220", system_dynamics, invariant, true,
					Out_Going_Trans_fromL220));
	Hybrid_Automata.addLocation(l);

// The mode name is  L221

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.6;
	C[1] = 0.9;
	C[2] = 0.7;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL221;

// The transition label is d102

// Original guard: x1 = 1

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(102, "d102", 26, 25, guard_polytope, assignment));

	Out_Going_Trans_fromL221.push_back(t);
// The transition label is d103

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(103, "d103", 26, 27, guard_polytope, assignment));

	Out_Going_Trans_fromL221.push_back(t);
// The transition label is d104

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(104, "d104", 26, 23, guard_polytope, assignment));

	Out_Going_Trans_fromL221.push_back(t);
// The transition label is d105

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(105, "d105", 26, 17, guard_polytope, assignment));

	Out_Going_Trans_fromL221.push_back(t);
	l = location::ptr(
			new location(26, "L221", system_dynamics, invariant, true,
					Out_Going_Trans_fromL221));
	Hybrid_Automata.addLocation(l);

// The mode name is  L222

	row = 3;
	col = 3;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.2;
	C[1] = 1.3;
	C[2] = 0.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 3;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 2) = -1.0;
	invariantConstraintsMatrix(5, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromL222;

// The transition label is d106

// Original guard: x1 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(106, "d106", 27, 26, guard_polytope, assignment));

	Out_Going_Trans_fromL222.push_back(t);
// The transition label is d107

// Original guard: x2 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(107, "d107", 27, 24, guard_polytope, assignment));

	Out_Going_Trans_fromL222.push_back(t);
// The transition label is d108

// Original guard: x3 = 2

	row = 2;
	col = 3;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 2) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 3;
	col = 3;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(108, "d108", 27, 18, guard_polytope, assignment));

	Out_Going_Trans_fromL222.push_back(t);
	l = location::ptr(
			new location(27, "BAD", system_dynamics, invariant, true,
					Out_Going_Trans_fromL222));
	Hybrid_Automata.addLocation(l);

}

