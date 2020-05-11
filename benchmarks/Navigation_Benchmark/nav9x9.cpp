// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/Models-HybridSystems/Flora/Navigation Model/Model_Nav09_9x9/Nav09.xml
// Command Line arguments: -tool xspeed "" -verbose -output "/home/movies/MyData/Models-HybridSystems/Flora/Navigation Model/Model_Nav09_9x9/nav09-NEW-Optimize-Conversion.cpp" -input "/home/movies/MyData/Models-HybridSystems/Flora/Navigation Model/Model_Nav09_9x9/Nav09.xml" "/home/movies/MyData/Models-HybridSystems/Flora/Navigation Model/Model_Nav09_9x9/nav09.cfg"

#include "../../benchmarks/Navigation_Benchmark/NavigationBenchmark.h"

void SetNavigationModel9by9(hybrid_automata& Hybrid_Automata,
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

// The mode name is  loc9

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc9;

// The transition label ist24

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(1, "t24", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromloc9.push_back(t);
// The transition label ist25

// Original guard: x1 = 1 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(2, "t25", 1, 10, guard_polytope, assignment));

	Out_Going_Trans_fromloc9.push_back(t);
	l = location::ptr(
			new location(1, "loc9", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc9));

	Hybrid_Automata.addLocation(l);

// The mode name is  loc8

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc8;

// The transition label ist23

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(3, "t23", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromloc8.push_back(t);
// The transition label ist21

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(4, "t21", 2, 3, guard_polytope, assignment));

	Out_Going_Trans_fromloc8.push_back(t);
// The transition label ist22

// Original guard: x1 = 1 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(5, "t22", 2, 11, guard_polytope, assignment));

	Out_Going_Trans_fromloc8.push_back(t);
	l = location::ptr(
			new location(2, "loc8", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc8));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc7

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc7;

// The transition label ist20

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(6, "t20", 3, 2, guard_polytope, assignment));

	Out_Going_Trans_fromloc7.push_back(t);
// The transition label ist18

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(7, "t18", 3, 4, guard_polytope, assignment));

	Out_Going_Trans_fromloc7.push_back(t);
// The transition label ist19

// Original guard: x1 = 1 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(8, "t19", 3, 12, guard_polytope, assignment));

	Out_Going_Trans_fromloc7.push_back(t);
	l = location::ptr(
			new location(3, "loc7", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc7));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc6

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc6;

// The transition label ist17

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(9, "t17", 4, 3, guard_polytope, assignment));

	Out_Going_Trans_fromloc6.push_back(t);
// The transition label ist15

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -5.0;
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
			new transition(10, "t15", 4, 5, guard_polytope, assignment));

	Out_Going_Trans_fromloc6.push_back(t);
// The transition label ist16

// Original guard: x1 = 1 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(11, "t16", 4, 13, guard_polytope, assignment));

	Out_Going_Trans_fromloc6.push_back(t);
	l = location::ptr(
			new location(4, "loc6", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc6));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc5

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc5;

// The transition label ist14

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -5.0;
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
			new transition(12, "t14", 5, 4, guard_polytope, assignment));

	Out_Going_Trans_fromloc5.push_back(t);
// The transition label ist12

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(13, "t12", 5, 6, guard_polytope, assignment));

	Out_Going_Trans_fromloc5.push_back(t);
// The transition label ist13

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
			new transition(14, "t13", 5, 14, guard_polytope, assignment));

	Out_Going_Trans_fromloc5.push_back(t);
	l = location::ptr(
			new location(5, "loc5", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc5));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc4

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc4;

// The transition label ist11

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(15, "t11", 6, 5, guard_polytope, assignment));

	Out_Going_Trans_fromloc4.push_back(t);
// The transition label ist9

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(16, "t9", 6, 7, guard_polytope, assignment));

	Out_Going_Trans_fromloc4.push_back(t);
// The transition label ist10

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
			new transition(17, "t10", 6, 15, guard_polytope, assignment));

	Out_Going_Trans_fromloc4.push_back(t);
	l = location::ptr(
			new location(6, "loc4", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc4));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc3

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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

// The transition label ist8

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(18, "t8", 7, 6, guard_polytope, assignment));

	Out_Going_Trans_fromloc3.push_back(t);
// The transition label ist6

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(19, "t6", 7, 8, guard_polytope, assignment));

	Out_Going_Trans_fromloc3.push_back(t);
// The transition label ist7

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
			new transition(20, "t7", 7, 16, guard_polytope, assignment));

	Out_Going_Trans_fromloc3.push_back(t);
	l = location::ptr(
			new location(7, "loc3", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc3));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc2

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.20208;
	C[3] = 1.20208;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc2;

// The transition label ist5

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(21, "t5", 8, 7, guard_polytope, assignment));

	Out_Going_Trans_fromloc2.push_back(t);
// The transition label ist3

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(22, "t3", 8, 9, guard_polytope, assignment));

	Out_Going_Trans_fromloc2.push_back(t);
// The transition label ist4

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
			new transition(23, "t4", 8, 17, guard_polytope, assignment));

	Out_Going_Trans_fromloc2.push_back(t);
	l = location::ptr(
			new location(8, "loc2", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc2));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc1

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.20208;
	C[3] = 1.20208;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc1;

// The transition label ist2

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(24, "t2", 9, 8, guard_polytope, assignment));

	Out_Going_Trans_fromloc1.push_back(t);
// The transition label ist1

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
			new transition(25, "t1", 9, 18, guard_polytope, assignment));

	Out_Going_Trans_fromloc1.push_back(t);
	l = location::ptr(
			new location(9, "loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc1));

	Hybrid_Automata.addInitialLocation(l);
	Hybrid_Automata.addLocation(l);

// The mode name is  loc18

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.20208;
	C[3] = 1.20208;
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
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc18;

// The transition label ist57

// Original guard: x1 = 1 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(26, "t57", 10, 1, guard_polytope, assignment));

	Out_Going_Trans_fromloc18.push_back(t);
// The transition label ist58

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(27, "t58", 10, 11, guard_polytope, assignment));

	Out_Going_Trans_fromloc18.push_back(t);
// The transition label ist59

// Original guard: x1 = 2 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(28, "t59", 10, 19, guard_polytope, assignment));

	Out_Going_Trans_fromloc18.push_back(t);
	l = location::ptr(
			new location(10, "loc18", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc18));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc17

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.20208;
	C[3] = 1.20208;
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
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc17;

// The transition label ist53

// Original guard: x1 = 1 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(29, "t53", 11, 2, guard_polytope, assignment));

	Out_Going_Trans_fromloc17.push_back(t);
// The transition label ist56

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(30, "t56", 11, 10, guard_polytope, assignment));

	Out_Going_Trans_fromloc17.push_back(t);
// The transition label ist54

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(31, "t54", 11, 12, guard_polytope, assignment));

	Out_Going_Trans_fromloc17.push_back(t);
// The transition label ist55

// Original guard: x1 = 2 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(32, "t55", 11, 20, guard_polytope, assignment));

	Out_Going_Trans_fromloc17.push_back(t);
	l = location::ptr(
			new location(11, "loc17", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc17));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc16

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.20208;
	C[3] = 1.20208;
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
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc16;

// The transition label ist49

// Original guard: x1 = 1 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(33, "t49", 12, 3, guard_polytope, assignment));

	Out_Going_Trans_fromloc16.push_back(t);
// The transition label ist52

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(34, "t52", 12, 11, guard_polytope, assignment));

	Out_Going_Trans_fromloc16.push_back(t);
// The transition label ist50

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(35, "t50", 12, 13, guard_polytope, assignment));

	Out_Going_Trans_fromloc16.push_back(t);
// The transition label ist51

// Original guard: x1 = 2 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(36, "t51", 12, 21, guard_polytope, assignment));

	Out_Going_Trans_fromloc16.push_back(t);
	l = location::ptr(
			new location(12, "loc16", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc16));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc15

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc15;

// The transition label ist45

// Original guard: x1 = 1 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(37, "t45", 13, 4, guard_polytope, assignment));

	Out_Going_Trans_fromloc15.push_back(t);
// The transition label ist48

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(38, "t48", 13, 12, guard_polytope, assignment));

	Out_Going_Trans_fromloc15.push_back(t);
// The transition label ist46

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -5.0;
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
			new transition(39, "t46", 13, 14, guard_polytope, assignment));

	Out_Going_Trans_fromloc15.push_back(t);
// The transition label ist47

// Original guard: x1 = 2 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(40, "t47", 13, 22, guard_polytope, assignment));

	Out_Going_Trans_fromloc15.push_back(t);
	l = location::ptr(
			new location(13, "loc15", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc15));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc14

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc14;

// The transition label ist41

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
			new transition(41, "t41", 14, 5, guard_polytope, assignment));

	Out_Going_Trans_fromloc14.push_back(t);
// The transition label ist44

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -5.0;
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
			new transition(42, "t44", 14, 13, guard_polytope, assignment));

	Out_Going_Trans_fromloc14.push_back(t);
// The transition label ist42

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(43, "t42", 14, 15, guard_polytope, assignment));

	Out_Going_Trans_fromloc14.push_back(t);
// The transition label ist43

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
			new transition(44, "t43", 14, 23, guard_polytope, assignment));

	Out_Going_Trans_fromloc14.push_back(t);
	l = location::ptr(
			new location(14, "loc14", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc14));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc13

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc13;

// The transition label ist37

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
			new transition(45, "t37", 15, 6, guard_polytope, assignment));

	Out_Going_Trans_fromloc13.push_back(t);
// The transition label ist40

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(46, "t40", 15, 14, guard_polytope, assignment));

	Out_Going_Trans_fromloc13.push_back(t);
// The transition label ist38

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(47, "t38", 15, 16, guard_polytope, assignment));

	Out_Going_Trans_fromloc13.push_back(t);
// The transition label ist39

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
			new transition(48, "t39", 15, 24, guard_polytope, assignment));

	Out_Going_Trans_fromloc13.push_back(t);
	l = location::ptr(
			new location(15, "loc13", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc13));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc12

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc12;

// The transition label ist33

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
			new transition(49, "t33", 16, 7, guard_polytope, assignment));

	Out_Going_Trans_fromloc12.push_back(t);
// The transition label ist36

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(50, "t36", 16, 15, guard_polytope, assignment));

	Out_Going_Trans_fromloc12.push_back(t);
// The transition label ist34

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(51, "t34", 16, 17, guard_polytope, assignment));

	Out_Going_Trans_fromloc12.push_back(t);
// The transition label ist35

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
			new transition(52, "t35", 16, 25, guard_polytope, assignment));

	Out_Going_Trans_fromloc12.push_back(t);
	l = location::ptr(
			new location(16, "loc12", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc12));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc11

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.20208;
	C[3] = 1.20208;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc11;

// The transition label ist29

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
			new transition(53, "t29", 17, 8, guard_polytope, assignment));

	Out_Going_Trans_fromloc11.push_back(t);
// The transition label ist32

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(54, "t32", 17, 16, guard_polytope, assignment));

	Out_Going_Trans_fromloc11.push_back(t);
// The transition label ist30

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(55, "t30", 17, 18, guard_polytope, assignment));

	Out_Going_Trans_fromloc11.push_back(t);
// The transition label ist31

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
			new transition(56, "t31", 17, 26, guard_polytope, assignment));

	Out_Going_Trans_fromloc11.push_back(t);
	l = location::ptr(
			new location(17, "loc11", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc11));
	Hybrid_Automata.addLocation(l);

	NavModule1(Hybrid_Automata, init_state_list, reach_parameters);
	NavModule2(Hybrid_Automata, init_state_list, reach_parameters);
	NavModule3(Hybrid_Automata, init_state_list, reach_parameters);
	NavModule4(Hybrid_Automata, init_state_list, reach_parameters);

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
	boundValueI[0] = 0.8;
	boundValueI[1] = -0.4;
	boundValueI[2] = 0.8;
	boundValueI[3] = -0.2;
	boundValueI[4] = 0.5;
	boundValueI[5] = -0.5;
	boundValueI[6] = 0.5;
	boundValueI[7] = -0.5;

	initial_polytope_I0 = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id = 9;

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

	/*
	 // ************* Section required for setting Reach Parameters & User Options *************
	 unsigned int Directions_Type = 1;
	 unsigned int iter_max = 105563;
	 double time_horizon = 10.0;
	 double sampling_time = 0.1;
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
	 reach_parameters.Iterations = (unsigned int) op.get_timeHorizon()/ op.get_timeStep();
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

void NavModule1(hybrid_automata& Hybrid_Automata,
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

// The mode name is  loc10

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.20208;
	C[3] = 1.20208;
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
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc10;

// The transition label ist26

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
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(57, "t26", 18, 9, guard_polytope, assignment));

	Out_Going_Trans_fromloc10.push_back(t);
// The transition label ist28

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(58, "t28", 18, 17, guard_polytope, assignment));

	Out_Going_Trans_fromloc10.push_back(t);
// The transition label ist27

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
			new transition(59, "t27", 18, 27, guard_polytope, assignment));

	Out_Going_Trans_fromloc10.push_back(t);
	l = location::ptr(
			new location(18, "loc10", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc10));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc27

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc27;

// The transition label ist91

// Original guard: x1 = 2 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(60, "t91", 19, 10, guard_polytope, assignment));

	Out_Going_Trans_fromloc27.push_back(t);
// The transition label ist92

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(61, "t92", 19, 20, guard_polytope, assignment));

	Out_Going_Trans_fromloc27.push_back(t);
// The transition label ist93

// Original guard: x1 = 3 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(62, "t93", 19, 28, guard_polytope, assignment));

	Out_Going_Trans_fromloc27.push_back(t);
	l = location::ptr(
			new location(19, "loc27", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc27));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc26

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc26;

// The transition label ist87

// Original guard: x1 = 2 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(63, "t87", 20, 11, guard_polytope, assignment));

	Out_Going_Trans_fromloc26.push_back(t);
// The transition label ist90

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(64, "t90", 20, 19, guard_polytope, assignment));

	Out_Going_Trans_fromloc26.push_back(t);
// The transition label ist88

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(65, "t88", 20, 21, guard_polytope, assignment));

	Out_Going_Trans_fromloc26.push_back(t);
// The transition label ist89

// Original guard: x1 = 3 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(66, "t89", 20, 29, guard_polytope, assignment));

	Out_Going_Trans_fromloc26.push_back(t);
	l = location::ptr(
			new location(20, "loc26", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc26));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc25

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc25;

// The transition label ist83

// Original guard: x1 = 2 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(67, "t83", 21, 12, guard_polytope, assignment));

	Out_Going_Trans_fromloc25.push_back(t);
// The transition label ist86

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(68, "t86", 21, 20, guard_polytope, assignment));

	Out_Going_Trans_fromloc25.push_back(t);
// The transition label ist84

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(69, "t84", 21, 22, guard_polytope, assignment));

	Out_Going_Trans_fromloc25.push_back(t);
// The transition label ist85

// Original guard: x1 = 3 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(70, "t85", 21, 30, guard_polytope, assignment));

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
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc24;

// The transition label ist79

// Original guard: x1 = 2 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(71, "t79", 22, 13, guard_polytope, assignment));

	Out_Going_Trans_fromloc24.push_back(t);
// The transition label ist82

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(72, "t82", 22, 21, guard_polytope, assignment));

	Out_Going_Trans_fromloc24.push_back(t);
// The transition label ist80

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -5.0;
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
			new transition(73, "t80", 22, 23, guard_polytope, assignment));

	Out_Going_Trans_fromloc24.push_back(t);
// The transition label ist81

// Original guard: x1 = 3 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(74, "t81", 22, 31, guard_polytope, assignment));

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
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc23;

// The transition label ist75

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
			new transition(75, "t75", 23, 14, guard_polytope, assignment));

	Out_Going_Trans_fromloc23.push_back(t);
// The transition label ist78

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -5.0;
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
			new transition(76, "t78", 23, 22, guard_polytope, assignment));

	Out_Going_Trans_fromloc23.push_back(t);
// The transition label ist76

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(77, "t76", 23, 24, guard_polytope, assignment));

	Out_Going_Trans_fromloc23.push_back(t);
// The transition label ist77

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
			new transition(78, "t77", 23, 32, guard_polytope, assignment));

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
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc22;

// The transition label ist71

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
			new transition(79, "t71", 24, 15, guard_polytope, assignment));

	Out_Going_Trans_fromloc22.push_back(t);
// The transition label ist74

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(80, "t74", 24, 23, guard_polytope, assignment));

	Out_Going_Trans_fromloc22.push_back(t);
// The transition label ist72

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(81, "t72", 24, 25, guard_polytope, assignment));

	Out_Going_Trans_fromloc22.push_back(t);
// The transition label ist73

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
			new transition(82, "t73", 24, 33, guard_polytope, assignment));

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
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc21;

// The transition label ist67

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
			new transition(83, "t67", 25, 16, guard_polytope, assignment));

	Out_Going_Trans_fromloc21.push_back(t);
// The transition label ist70

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(84, "t70", 25, 24, guard_polytope, assignment));

	Out_Going_Trans_fromloc21.push_back(t);
// The transition label ist68

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(85, "t68", 25, 26, guard_polytope, assignment));

	Out_Going_Trans_fromloc21.push_back(t);
// The transition label ist69

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
			new transition(86, "t69", 25, 34, guard_polytope, assignment));

	Out_Going_Trans_fromloc21.push_back(t);
	l = location::ptr(
			new location(25, "loc21", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc21));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc20

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc20;

// The transition label ist63

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
			new transition(87, "t63", 26, 17, guard_polytope, assignment));

	Out_Going_Trans_fromloc20.push_back(t);
// The transition label ist66

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(88, "t66", 26, 25, guard_polytope, assignment));

	Out_Going_Trans_fromloc20.push_back(t);
// The transition label ist64

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(89, "t64", 26, 27, guard_polytope, assignment));

	Out_Going_Trans_fromloc20.push_back(t);
// The transition label ist65

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
			new transition(90, "t65", 26, 35, guard_polytope, assignment));

	Out_Going_Trans_fromloc20.push_back(t);
	l = location::ptr(
			new location(26, "loc20", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc20));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc19

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc19;

// The transition label ist60

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
			new transition(91, "t60", 27, 18, guard_polytope, assignment));

	Out_Going_Trans_fromloc19.push_back(t);
// The transition label ist62

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(92, "t62", 27, 26, guard_polytope, assignment));

	Out_Going_Trans_fromloc19.push_back(t);
// The transition label ist61

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
			new transition(93, "t61", 27, 36, guard_polytope, assignment));

	Out_Going_Trans_fromloc19.push_back(t);
	l = location::ptr(
			new location(27, "loc19", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc19));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc36

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc36;

// The transition label ist125

// Original guard: x1 = 3 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(94, "t125", 28, 19, guard_polytope, assignment));

	Out_Going_Trans_fromloc36.push_back(t);
// The transition label ist126

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(95, "t126", 28, 29, guard_polytope, assignment));

	Out_Going_Trans_fromloc36.push_back(t);
// The transition label ist127

// Original guard: x1 = 4 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(96, "t127", 28, 37, guard_polytope, assignment));

	Out_Going_Trans_fromloc36.push_back(t);
	l = location::ptr(
			new location(28, "loc36", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc36));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc35

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc35;

// The transition label ist121

// Original guard: x1 = 3 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(97, "t121", 29, 20, guard_polytope, assignment));

	Out_Going_Trans_fromloc35.push_back(t);
// The transition label ist124

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(98, "t124", 29, 28, guard_polytope, assignment));

	Out_Going_Trans_fromloc35.push_back(t);
// The transition label ist122

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(99, "t122", 29, 30, guard_polytope, assignment));

	Out_Going_Trans_fromloc35.push_back(t);
// The transition label ist123

// Original guard: x1 = 4 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(100, "t123", 29, 38, guard_polytope, assignment));

	Out_Going_Trans_fromloc35.push_back(t);
	l = location::ptr(
			new location(29, "loc35", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc35));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc34

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc34;

// The transition label ist117

// Original guard: x1 = 3 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(101, "t117", 30, 21, guard_polytope, assignment));

	Out_Going_Trans_fromloc34.push_back(t);
// The transition label ist118

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(102, "t118", 30, 31, guard_polytope, assignment));

	Out_Going_Trans_fromloc34.push_back(t);
// The transition label ist119

// Original guard: x1 = 4 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(103, "t119", 30, 39, guard_polytope, assignment));

	Out_Going_Trans_fromloc34.push_back(t);
// The transition label ist120

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(104, "t120", 30, 29, guard_polytope, assignment));

	Out_Going_Trans_fromloc34.push_back(t);
	l = location::ptr(
			new location(30, "loc34", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc34));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc33

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc33;

// The transition label ist113

// Original guard: x1 = 3 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(105, "t113", 31, 22, guard_polytope, assignment));

	Out_Going_Trans_fromloc33.push_back(t);
// The transition label ist116

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(106, "t116", 31, 30, guard_polytope, assignment));

	Out_Going_Trans_fromloc33.push_back(t);
// The transition label ist114

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -5.0;
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
			new transition(107, "t114", 31, 32, guard_polytope, assignment));

	Out_Going_Trans_fromloc33.push_back(t);
// The transition label ist115

// Original guard: x1 = 4 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(108, "t115", 31, 40, guard_polytope, assignment));

	Out_Going_Trans_fromloc33.push_back(t);
	l = location::ptr(
			new location(31, "loc33", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc33));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc32

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc32;

// The transition label ist109

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
			new transition(109, "t109", 32, 23, guard_polytope, assignment));

	Out_Going_Trans_fromloc32.push_back(t);
// The transition label ist112

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -5.0;
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
			new transition(110, "t112", 32, 31, guard_polytope, assignment));

	Out_Going_Trans_fromloc32.push_back(t);
// The transition label ist110

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(111, "t110", 32, 33, guard_polytope, assignment));

	Out_Going_Trans_fromloc32.push_back(t);
// The transition label ist111

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
			new transition(112, "t111", 32, 41, guard_polytope, assignment));

	Out_Going_Trans_fromloc32.push_back(t);
	l = location::ptr(
			new location(32, "loc32", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc32));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc31

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc31;

// The transition label ist105

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
			new transition(113, "t105", 33, 24, guard_polytope, assignment));

	Out_Going_Trans_fromloc31.push_back(t);
// The transition label ist108

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(114, "t108", 33, 32, guard_polytope, assignment));

	Out_Going_Trans_fromloc31.push_back(t);
// The transition label ist106

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(115, "t106", 33, 34, guard_polytope, assignment));

	Out_Going_Trans_fromloc31.push_back(t);
// The transition label ist107

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
			new transition(116, "t107", 33, 42, guard_polytope, assignment));

	Out_Going_Trans_fromloc31.push_back(t);
	l = location::ptr(
			new location(33, "loc31", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc31));
	Hybrid_Automata.addLocation(l);

}

void NavModule2(hybrid_automata& Hybrid_Automata,
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

// The mode name is  loc30

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc30;

// The transition label ist101

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
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(117, "t101", 34, 25, guard_polytope, assignment));

	Out_Going_Trans_fromloc30.push_back(t);
// The transition label ist104

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(118, "t104", 34, 33, guard_polytope, assignment));

	Out_Going_Trans_fromloc30.push_back(t);
// The transition label ist102

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(119, "t102", 34, 35, guard_polytope, assignment));

	Out_Going_Trans_fromloc30.push_back(t);
// The transition label ist103

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
			new transition(120, "t103", 34, 43, guard_polytope, assignment));

	Out_Going_Trans_fromloc30.push_back(t);
	l = location::ptr(
			new location(34, "loc30", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc30));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc29

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc29;

// The transition label ist97

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
			new transition(121, "t97", 35, 26, guard_polytope, assignment));

	Out_Going_Trans_fromloc29.push_back(t);
// The transition label ist100

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(122, "t100", 35, 34, guard_polytope, assignment));

	Out_Going_Trans_fromloc29.push_back(t);
// The transition label ist98

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(123, "t98", 35, 36, guard_polytope, assignment));

	Out_Going_Trans_fromloc29.push_back(t);
// The transition label ist99

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
			new transition(124, "t99", 35, 44, guard_polytope, assignment));

	Out_Going_Trans_fromloc29.push_back(t);
	l = location::ptr(
			new location(35, "loc29", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc29));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc28

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc28;

// The transition label ist94

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
			new transition(125, "t94", 36, 27, guard_polytope, assignment));

	Out_Going_Trans_fromloc28.push_back(t);
// The transition label ist96

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(126, "t96", 36, 35, guard_polytope, assignment));

	Out_Going_Trans_fromloc28.push_back(t);
// The transition label ist95

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
			new transition(127, "t95", 36, 45, guard_polytope, assignment));

	Out_Going_Trans_fromloc28.push_back(t);
	l = location::ptr(
			new location(36, "loc28", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc28));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc45

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc45;

// The transition label ist159

// Original guard: x1 = 4 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(128, "t159", 37, 28, guard_polytope, assignment));

	Out_Going_Trans_fromloc45.push_back(t);
// The transition label ist160

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(129, "t160", 37, 38, guard_polytope, assignment));

	Out_Going_Trans_fromloc45.push_back(t);
// The transition label ist161

// Original guard: x1 = 5 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(130, "t161", 37, 46, guard_polytope, assignment));

	Out_Going_Trans_fromloc45.push_back(t);
	l = location::ptr(
			new location(37, "loc45", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc45));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc44

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc44;

// The transition label ist155

// Original guard: x1 = 4 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(131, "t155", 38, 29, guard_polytope, assignment));

	Out_Going_Trans_fromloc44.push_back(t);
// The transition label ist158

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(132, "t158", 38, 37, guard_polytope, assignment));

	Out_Going_Trans_fromloc44.push_back(t);
// The transition label ist156

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(133, "t156", 38, 39, guard_polytope, assignment));

	Out_Going_Trans_fromloc44.push_back(t);
// The transition label ist157

// Original guard: x1 = 5 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(134, "t157", 38, 47, guard_polytope, assignment));

	Out_Going_Trans_fromloc44.push_back(t);
	l = location::ptr(
			new location(38, "loc44", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc44));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc43

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc43;

// The transition label ist151

// Original guard: x1 = 4 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(135, "t151", 39, 30, guard_polytope, assignment));

	Out_Going_Trans_fromloc43.push_back(t);
// The transition label ist154

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(136, "t154", 39, 38, guard_polytope, assignment));

	Out_Going_Trans_fromloc43.push_back(t);
// The transition label ist152

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(137, "t152", 39, 40, guard_polytope, assignment));

	Out_Going_Trans_fromloc43.push_back(t);
// The transition label ist153

// Original guard: x1 = 5 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(138, "t153", 39, 48, guard_polytope, assignment));

	Out_Going_Trans_fromloc43.push_back(t);
	l = location::ptr(
			new location(39, "loc43", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc43));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc42

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc42;

// The transition label ist147

// Original guard: x1 = 4 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(139, "t147", 40, 31, guard_polytope, assignment));

	Out_Going_Trans_fromloc42.push_back(t);
// The transition label ist150

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(140, "t150", 40, 39, guard_polytope, assignment));

	Out_Going_Trans_fromloc42.push_back(t);
// The transition label ist148

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -5.0;
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
			new transition(141, "t148", 40, 41, guard_polytope, assignment));

	Out_Going_Trans_fromloc42.push_back(t);
// The transition label ist149

// Original guard: x1 = 5 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(142, "t149", 40, 49, guard_polytope, assignment));

	Out_Going_Trans_fromloc42.push_back(t);
	l = location::ptr(
			new location(40, "loc42", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc42));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc41

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc41;

// The transition label ist143

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
			new transition(143, "t143", 41, 32, guard_polytope, assignment));

	Out_Going_Trans_fromloc41.push_back(t);
// The transition label ist146

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -5.0;
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
			new transition(144, "t146", 41, 40, guard_polytope, assignment));

	Out_Going_Trans_fromloc41.push_back(t);
// The transition label ist144

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(145, "t144", 41, 42, guard_polytope, assignment));

	Out_Going_Trans_fromloc41.push_back(t);
// The transition label ist145

// Original guard: x1 = 5 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(146, "t145", 41, 50, guard_polytope, assignment));

	Out_Going_Trans_fromloc41.push_back(t);
	l = location::ptr(
			new location(41, "loc41", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc41));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc40

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc40;

// The transition label ist139

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
			new transition(147, "t139", 42, 33, guard_polytope, assignment));

	Out_Going_Trans_fromloc40.push_back(t);
// The transition label ist142

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(148, "t142", 42, 41, guard_polytope, assignment));

	Out_Going_Trans_fromloc40.push_back(t);
// The transition label ist140

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(149, "t140", 42, 43, guard_polytope, assignment));

	Out_Going_Trans_fromloc40.push_back(t);
// The transition label ist141

// Original guard: x1 = 5 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(150, "t141", 42, 51, guard_polytope, assignment));

	Out_Going_Trans_fromloc40.push_back(t);
	l = location::ptr(
			new location(42, "loc40", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc40));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc39

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc39;

// The transition label ist135

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
			new transition(151, "t135", 43, 34, guard_polytope, assignment));

	Out_Going_Trans_fromloc39.push_back(t);
// The transition label ist138

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(152, "t138", 43, 42, guard_polytope, assignment));

	Out_Going_Trans_fromloc39.push_back(t);
// The transition label ist136

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(153, "t136", 43, 44, guard_polytope, assignment));

	Out_Going_Trans_fromloc39.push_back(t);
// The transition label ist137

// Original guard: x1 = 5 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(154, "t137", 43, 52, guard_polytope, assignment));

	Out_Going_Trans_fromloc39.push_back(t);
	l = location::ptr(
			new location(43, "loc39", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc39));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc38

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc38;

// The transition label ist131

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
			new transition(155, "t131", 44, 35, guard_polytope, assignment));

	Out_Going_Trans_fromloc38.push_back(t);
// The transition label ist134

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(156, "t134", 44, 43, guard_polytope, assignment));

	Out_Going_Trans_fromloc38.push_back(t);
// The transition label ist132

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(157, "t132", 44, 45, guard_polytope, assignment));

	Out_Going_Trans_fromloc38.push_back(t);
// The transition label ist133

// Original guard: x1 = 5 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(158, "t133", 44, 53, guard_polytope, assignment));

	Out_Going_Trans_fromloc38.push_back(t);
	l = location::ptr(
			new location(44, "loc38", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc38));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc37

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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

	std::list<transition::ptr> Out_Going_Trans_fromloc37;

// The transition label ist128

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
			new transition(159, "t128", 45, 36, guard_polytope, assignment));

	Out_Going_Trans_fromloc37.push_back(t);
// The transition label ist130

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
			new transition(160, "t130", 45, 44, guard_polytope, assignment));

	Out_Going_Trans_fromloc37.push_back(t);
// The transition label ist129

// Original guard: x1 = 5 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(161, "t129", 45, 54, guard_polytope, assignment));

	Out_Going_Trans_fromloc37.push_back(t);
	l = location::ptr(
			new location(45, "loc37", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc37));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc54

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -1.202;
	C[3] = -1.202;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc54;

// The transition label ist193

// Original guard: x1 = 5 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(162, "t193", 46, 37, guard_polytope, assignment));

	Out_Going_Trans_fromloc54.push_back(t);
// The transition label ist194

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(163, "t194", 46, 47, guard_polytope, assignment));

	Out_Going_Trans_fromloc54.push_back(t);
// The transition label ist195

// Original guard: x1 = 6 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(164, "t195", 46, 55, guard_polytope, assignment));

	Out_Going_Trans_fromloc54.push_back(t);
	l = location::ptr(
			new location(46, "loc54", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc54));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc53

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -1.202;
	C[3] = -1.202;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc53;

// The transition label ist189

// Original guard: x1 = 5 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(165, "t189", 47, 38, guard_polytope, assignment));

	Out_Going_Trans_fromloc53.push_back(t);
// The transition label ist192

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(166, "t192", 47, 46, guard_polytope, assignment));

	Out_Going_Trans_fromloc53.push_back(t);
// The transition label ist190

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(167, "t190", 47, 48, guard_polytope, assignment));

	Out_Going_Trans_fromloc53.push_back(t);
// The transition label ist191

// Original guard: x1 = 6 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(168, "t191", 47, 56, guard_polytope, assignment));

	Out_Going_Trans_fromloc53.push_back(t);
	l = location::ptr(
			new location(47, "loc53", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc53));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc52

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -1.202;
	C[3] = -1.202;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc52;

// The transition label ist185

// Original guard: x1 = 5 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(169, "t185", 48, 39, guard_polytope, assignment));

	Out_Going_Trans_fromloc52.push_back(t);
// The transition label ist188

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(170, "t188", 48, 47, guard_polytope, assignment));

	Out_Going_Trans_fromloc52.push_back(t);
// The transition label ist186

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(171, "t186", 48, 49, guard_polytope, assignment));

	Out_Going_Trans_fromloc52.push_back(t);
// The transition label ist187

// Original guard: x1 = 6 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(172, "t187", 48, 57, guard_polytope, assignment));

	Out_Going_Trans_fromloc52.push_back(t);
	l = location::ptr(
			new location(48, "loc52", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc52));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc51

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc51;

// The transition label ist181

// Original guard: x1 = 5 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(173, "t181", 49, 40, guard_polytope, assignment));

	Out_Going_Trans_fromloc51.push_back(t);
// The transition label ist184

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(174, "t184", 49, 48, guard_polytope, assignment));

	Out_Going_Trans_fromloc51.push_back(t);
// The transition label ist182

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -5.0;
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
			new transition(175, "t182", 49, 50, guard_polytope, assignment));

	Out_Going_Trans_fromloc51.push_back(t);
// The transition label ist183

// Original guard: x1 = 6 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(176, "t183", 49, 58, guard_polytope, assignment));

	Out_Going_Trans_fromloc51.push_back(t);
	l = location::ptr(
			new location(49, "loc51", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc51));
	Hybrid_Automata.addLocation(l);

}

void NavModule3(hybrid_automata& Hybrid_Automata,
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

// The mode name is  loc50

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc50;

// The transition label ist177

// Original guard: x1 = 5 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(177, "t177", 50, 41, guard_polytope, assignment));

	Out_Going_Trans_fromloc50.push_back(t);
// The transition label ist180

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -5.0;
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
			new transition(178, "t180", 50, 49, guard_polytope, assignment));

	Out_Going_Trans_fromloc50.push_back(t);
// The transition label ist178

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
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
			new transition(179, "t178", 50, 51, guard_polytope, assignment));

	Out_Going_Trans_fromloc50.push_back(t);
// The transition label ist179

// Original guard: x1 = 6 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(180, "t179", 50, 59, guard_polytope, assignment));

	Out_Going_Trans_fromloc50.push_back(t);
	l = location::ptr(
			new location(50, "loc50", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc50));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc49

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc49;

// The transition label ist173

// Original guard: x1 = 5 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(181, "t173", 51, 42, guard_polytope, assignment));

	Out_Going_Trans_fromloc49.push_back(t);
// The transition label ist176

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
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
			new transition(182, "t176", 51, 50, guard_polytope, assignment));

	Out_Going_Trans_fromloc49.push_back(t);
// The transition label ist174

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
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
			new transition(183, "t174", 51, 52, guard_polytope, assignment));

	Out_Going_Trans_fromloc49.push_back(t);
// The transition label ist175

// Original guard: x1 = 6 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(184, "t175", 51, 60, guard_polytope, assignment));

	Out_Going_Trans_fromloc49.push_back(t);
	l = location::ptr(
			new location(51, "loc49", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc49));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc48

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc48;

// The transition label ist169

// Original guard: x1 = 5 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(185, "t169", 52, 43, guard_polytope, assignment));

	Out_Going_Trans_fromloc48.push_back(t);
// The transition label ist172

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
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
			new transition(186, "t172", 52, 51, guard_polytope, assignment));

	Out_Going_Trans_fromloc48.push_back(t);
// The transition label ist170

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
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
			new transition(187, "t170", 52, 53, guard_polytope, assignment));

	Out_Going_Trans_fromloc48.push_back(t);
// The transition label ist171

// Original guard: x1 = 6 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(188, "t171", 52, 61, guard_polytope, assignment));

	Out_Going_Trans_fromloc48.push_back(t);
	l = location::ptr(
			new location(52, "loc48", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc48));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc47

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc47;

// The transition label ist165

// Original guard: x1 = 5 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(189, "t165", 53, 44, guard_polytope, assignment));

	Out_Going_Trans_fromloc47.push_back(t);
// The transition label ist168

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
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
			new transition(190, "t168", 53, 52, guard_polytope, assignment));

	Out_Going_Trans_fromloc47.push_back(t);
// The transition label ist166

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
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
			new transition(191, "t166", 53, 54, guard_polytope, assignment));

	Out_Going_Trans_fromloc47.push_back(t);
// The transition label ist167

// Original guard: x1 = 6 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(192, "t167", 53, 62, guard_polytope, assignment));

	Out_Going_Trans_fromloc47.push_back(t);
	l = location::ptr(
			new location(53, "loc47", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc47));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc46

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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
	invariantBoundValue[0] = -5.0;
	invariantBoundValue[1] = 6.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc46;

// The transition label ist162

// Original guard: x1 = 5 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
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
			new transition(193, "t162", 54, 45, guard_polytope, assignment));

	Out_Going_Trans_fromloc46.push_back(t);
// The transition label ist164

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 6.0;
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
			new transition(194, "t164", 54, 53, guard_polytope, assignment));

	Out_Going_Trans_fromloc46.push_back(t);
// The transition label ist163

// Original guard: x1 = 6 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(195, "t163", 54, 63, guard_polytope, assignment));

	Out_Going_Trans_fromloc46.push_back(t);
	l = location::ptr(
			new location(54, "loc46", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc46));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc63

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc63;

// The transition label ist227

// Original guard: x1 = 6 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(196, "t227", 55, 46, guard_polytope, assignment));

	Out_Going_Trans_fromloc63.push_back(t);
// The transition label ist228

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(197, "t228", 55, 56, guard_polytope, assignment));

	Out_Going_Trans_fromloc63.push_back(t);
// The transition label ist229

// Original guard: x1 = 7 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(198, "t229", 55, 64, guard_polytope, assignment));

	Out_Going_Trans_fromloc63.push_back(t);
	l = location::ptr(
			new location(55, "loc63", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc63));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc62

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -1.5;
	C[3] = -0.5;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc62;

// The transition label ist223

// Original guard: x1 = 6 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(199, "t223", 56, 47, guard_polytope, assignment));

	Out_Going_Trans_fromloc62.push_back(t);
// The transition label ist226

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(200, "t226", 56, 55, guard_polytope, assignment));

	Out_Going_Trans_fromloc62.push_back(t);
// The transition label ist224

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(201, "t224", 56, 57, guard_polytope, assignment));

	Out_Going_Trans_fromloc62.push_back(t);
// The transition label ist225

// Original guard: x1 = 7 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(202, "t225", 56, 65, guard_polytope, assignment));

	Out_Going_Trans_fromloc62.push_back(t);
	l = location::ptr(
			new location(56, "loc62", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc62));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc61

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc61;

// The transition label ist219

// Original guard: x1 = 6 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(203, "t219", 57, 48, guard_polytope, assignment));

	Out_Going_Trans_fromloc61.push_back(t);
// The transition label ist222

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(204, "t222", 57, 56, guard_polytope, assignment));

	Out_Going_Trans_fromloc61.push_back(t);
// The transition label ist220

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(205, "t220", 57, 58, guard_polytope, assignment));

	Out_Going_Trans_fromloc61.push_back(t);
// The transition label ist221

// Original guard: x1 = 7 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(206, "t221", 57, 66, guard_polytope, assignment));

	Out_Going_Trans_fromloc61.push_back(t);
	l = location::ptr(
			new location(57, "loc61", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc61));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc60

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc60;

// The transition label ist215

// Original guard: x1 = 6 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(207, "t215", 58, 49, guard_polytope, assignment));

	Out_Going_Trans_fromloc60.push_back(t);
// The transition label ist218

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(208, "t218", 58, 57, guard_polytope, assignment));

	Out_Going_Trans_fromloc60.push_back(t);
// The transition label ist216

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -5.0;
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
			new transition(209, "t216", 58, 59, guard_polytope, assignment));

	Out_Going_Trans_fromloc60.push_back(t);
// The transition label ist217

// Original guard: x1 = 7 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(210, "t217", 58, 67, guard_polytope, assignment));

	Out_Going_Trans_fromloc60.push_back(t);
	l = location::ptr(
			new location(58, "loc60", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc60));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc59

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc59;

// The transition label ist211

// Original guard: x1 = 6 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(211, "t211", 59, 50, guard_polytope, assignment));

	Out_Going_Trans_fromloc59.push_back(t);
// The transition label ist214

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -5.0;
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
			new transition(212, "t214", 59, 58, guard_polytope, assignment));

	Out_Going_Trans_fromloc59.push_back(t);
// The transition label ist212

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
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
			new transition(213, "t212", 59, 60, guard_polytope, assignment));

	Out_Going_Trans_fromloc59.push_back(t);
// The transition label ist213

// Original guard: x1 = 7 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(214, "t213", 59, 68, guard_polytope, assignment));

	Out_Going_Trans_fromloc59.push_back(t);
	l = location::ptr(
			new location(59, "loc59", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc59));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc58

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc58;

// The transition label ist207

// Original guard: x1 = 6 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(215, "t207", 60, 51, guard_polytope, assignment));

	Out_Going_Trans_fromloc58.push_back(t);
// The transition label ist210

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
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
			new transition(216, "t210", 60, 59, guard_polytope, assignment));

	Out_Going_Trans_fromloc58.push_back(t);
// The transition label ist208

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
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
			new transition(217, "t208", 60, 61, guard_polytope, assignment));

	Out_Going_Trans_fromloc58.push_back(t);
// The transition label ist209

// Original guard: x1 = 7 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(218, "t209", 60, 69, guard_polytope, assignment));

	Out_Going_Trans_fromloc58.push_back(t);
	l = location::ptr(
			new location(60, "loc58", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc58));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc57

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc57;

// The transition label ist203

// Original guard: x1 = 6 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(219, "t203", 61, 52, guard_polytope, assignment));

	Out_Going_Trans_fromloc57.push_back(t);
// The transition label ist206

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
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
			new transition(220, "t206", 61, 60, guard_polytope, assignment));

	Out_Going_Trans_fromloc57.push_back(t);
// The transition label ist204

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
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
			new transition(221, "t204", 61, 62, guard_polytope, assignment));

	Out_Going_Trans_fromloc57.push_back(t);
// The transition label ist205

// Original guard: x1 = 7 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(222, "t205", 61, 70, guard_polytope, assignment));

	Out_Going_Trans_fromloc57.push_back(t);
	l = location::ptr(
			new location(61, "loc57", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc57));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc56

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9192;
	C[3] = -0.495;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc56;

// The transition label ist199

// Original guard: x1 = 6 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(223, "t199", 62, 53, guard_polytope, assignment));

	Out_Going_Trans_fromloc56.push_back(t);
// The transition label ist202

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
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
			new transition(224, "t202", 62, 61, guard_polytope, assignment));

	Out_Going_Trans_fromloc56.push_back(t);
// The transition label ist200

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
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
			new transition(225, "t200", 62, 63, guard_polytope, assignment));

	Out_Going_Trans_fromloc56.push_back(t);
// The transition label ist201

// Original guard: x1 = 7 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(226, "t201", 62, 71, guard_polytope, assignment));

	Out_Going_Trans_fromloc56.push_back(t);
	l = location::ptr(
			new location(62, "loc56", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc56));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc55

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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
	invariantBoundValue[0] = -6.0;
	invariantBoundValue[1] = 7.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc55;

// The transition label ist196

// Original guard: x1 = 6 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 6.0;
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
			new transition(227, "t196", 63, 54, guard_polytope, assignment));

	Out_Going_Trans_fromloc55.push_back(t);
// The transition label ist198

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -6.0;
	guardBoundValue[1] = 7.0;
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
			new transition(228, "t198", 63, 62, guard_polytope, assignment));

	Out_Going_Trans_fromloc55.push_back(t);
// The transition label ist197

// Original guard: x1 = 7 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(229, "t197", 63, 72, guard_polytope, assignment));

	Out_Going_Trans_fromloc55.push_back(t);
	l = location::ptr(
			new location(63, "loc55", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc55));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc72

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc72;

// The transition label ist253

// Original guard: x1 = 7 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(230, "t253", 64, 55, guard_polytope, assignment));

	Out_Going_Trans_fromloc72.push_back(t);
// The transition label ist254

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(231, "t254", 64, 65, guard_polytope, assignment));

	Out_Going_Trans_fromloc72.push_back(t);
// The transition label ist255

// Original guard: x1 = 8 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(232, "t255", 64, 73, guard_polytope, assignment));

	Out_Going_Trans_fromloc72.push_back(t);
	l = location::ptr(
			new location(64, "loc72", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc72));
	Hybrid_Automata.addLocation(l);

// The mode name is  BAD

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromBAD;

	l = location::ptr(
			new location(65, "BAD", system_dynamics, invariant, true,
					Out_Going_Trans_fromBAD));
	Hybrid_Automata.addLocation(l);

}

void NavModule4(hybrid_automata& Hybrid_Automata,
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

// The mode name is  loc70

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc70;

// The transition label ist249

// Original guard: x1 = 7 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(233, "t249", 66, 57, guard_polytope, assignment));

	Out_Going_Trans_fromloc70.push_back(t);
// The transition label ist252

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(234, "t252", 66, 65, guard_polytope, assignment));

	Out_Going_Trans_fromloc70.push_back(t);
// The transition label ist250

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(235, "t250", 66, 67, guard_polytope, assignment));

	Out_Going_Trans_fromloc70.push_back(t);
// The transition label ist251

// Original guard: x1 = 8 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(236, "t251", 66, 75, guard_polytope, assignment));

	Out_Going_Trans_fromloc70.push_back(t);
	l = location::ptr(
			new location(66, "loc70", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc70));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc69

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc69;

// The transition label ist245

// Original guard: x1 = 7 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(237, "t245", 67, 58, guard_polytope, assignment));

	Out_Going_Trans_fromloc69.push_back(t);
// The transition label ist248

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(238, "t248", 67, 66, guard_polytope, assignment));

	Out_Going_Trans_fromloc69.push_back(t);
// The transition label ist246

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -5.0;
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
			new transition(239, "t246", 67, 68, guard_polytope, assignment));

	Out_Going_Trans_fromloc69.push_back(t);
// The transition label ist247

// Original guard: x1 = 8 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(240, "t247", 67, 76, guard_polytope, assignment));

	Out_Going_Trans_fromloc69.push_back(t);
	l = location::ptr(
			new location(67, "loc69", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc69));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc68

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc68;

// The transition label ist241

// Original guard: x1 = 7 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(241, "t241", 68, 59, guard_polytope, assignment));

	Out_Going_Trans_fromloc68.push_back(t);
// The transition label ist244

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -5.0;
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
			new transition(242, "t244", 68, 67, guard_polytope, assignment));

	Out_Going_Trans_fromloc68.push_back(t);
// The transition label ist242

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
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
			new transition(243, "t242", 68, 69, guard_polytope, assignment));

	Out_Going_Trans_fromloc68.push_back(t);
// The transition label ist243

// Original guard: x1 = 8 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(244, "t243", 68, 77, guard_polytope, assignment));

	Out_Going_Trans_fromloc68.push_back(t);
	l = location::ptr(
			new location(68, "loc68", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc68));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc67

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc67;

// The transition label ist237

// Original guard: x1 = 7 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(245, "t237", 69, 60, guard_polytope, assignment));

	Out_Going_Trans_fromloc67.push_back(t);
// The transition label ist240

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
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
			new transition(246, "t240", 69, 68, guard_polytope, assignment));

	Out_Going_Trans_fromloc67.push_back(t);
// The transition label ist238

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
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
			new transition(247, "t238", 69, 70, guard_polytope, assignment));

	Out_Going_Trans_fromloc67.push_back(t);
// The transition label ist239

// Original guard: x1 = 8 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(248, "t239", 69, 78, guard_polytope, assignment));

	Out_Going_Trans_fromloc67.push_back(t);
	l = location::ptr(
			new location(69, "loc67", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc67));
	Hybrid_Automata.addLocation(l);

// The mode name is  GOOD

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromGOOD;

	l = location::ptr(
			new location(70, "GOOD", system_dynamics, invariant, true,
					Out_Going_Trans_fromGOOD));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc65

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc65;

// The transition label ist233

// Original guard: x1 = 7 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(249, "t233", 71, 62, guard_polytope, assignment));

	Out_Going_Trans_fromloc65.push_back(t);
// The transition label ist234

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
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
			new transition(250, "t234", 71, 72, guard_polytope, assignment));

	Out_Going_Trans_fromloc65.push_back(t);
// The transition label ist236

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
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
			new transition(251, "t236", 71, 70, guard_polytope, assignment));

	Out_Going_Trans_fromloc65.push_back(t);
// The transition label ist235

// Original guard: x1 = 8 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(252, "t235", 71, 80, guard_polytope, assignment));

	Out_Going_Trans_fromloc65.push_back(t);
	l = location::ptr(
			new location(71, "loc65", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc65));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc64

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[0] = -7.0;
	invariantBoundValue[1] = 8.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc64;

// The transition label ist230

// Original guard: x1 = 7 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 7.0;
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
			new transition(253, "t230", 72, 63, guard_polytope, assignment));

	Out_Going_Trans_fromloc64.push_back(t);
// The transition label ist232

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -7.0;
	guardBoundValue[1] = 8.0;
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
			new transition(254, "t232", 72, 71, guard_polytope, assignment));

	Out_Going_Trans_fromloc64.push_back(t);
// The transition label ist231

// Original guard: x1 = 8 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(255, "t231", 72, 81, guard_polytope, assignment));

	Out_Going_Trans_fromloc64.push_back(t);
	l = location::ptr(
			new location(72, "loc64", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc64));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc81

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[2] = -8.0;
	invariantBoundValue[3] = 9.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc81;

// The transition label ist279

// Original guard: x1 = 8 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 9.0;
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
			new transition(256, "t279", 73, 64, guard_polytope, assignment));

	Out_Going_Trans_fromloc81.push_back(t);
// The transition label ist280

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(257, "t280", 73, 74, guard_polytope, assignment));

	Out_Going_Trans_fromloc81.push_back(t);
	l = location::ptr(
			new location(73, "loc81", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc81));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc80

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 1.5;
	C[3] = 0.5;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[2] = -7.0;
	invariantBoundValue[3] = 8.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc80;

// The transition label ist276

// Original guard: x1 = 8 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 8.0;
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
			new transition(258, "t276", 74, 65, guard_polytope, assignment));

	Out_Going_Trans_fromloc80.push_back(t);
// The transition label ist278

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
	guardBoundValue[2] = -8.0;
	guardBoundValue[3] = 8.0;
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
			new transition(259, "t278", 74, 73, guard_polytope, assignment));

	Out_Going_Trans_fromloc80.push_back(t);
// The transition label ist277

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(260, "t277", 74, 75, guard_polytope, assignment));

	Out_Going_Trans_fromloc80.push_back(t);
	l = location::ptr(
			new location(74, "loc80", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc80));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc79

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -0.2;
	C[3] = -1.2;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[2] = -6.0;
	invariantBoundValue[3] = 7.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc79;

// The transition label ist273

// Original guard: x1 = 8 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 7.0;
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
			new transition(261, "t273", 75, 66, guard_polytope, assignment));

	Out_Going_Trans_fromloc79.push_back(t);
// The transition label ist275

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
	guardBoundValue[2] = -7.0;
	guardBoundValue[3] = 7.0;
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
			new transition(262, "t275", 75, 74, guard_polytope, assignment));

	Out_Going_Trans_fromloc79.push_back(t);
// The transition label ist274

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(263, "t274", 75, 76, guard_polytope, assignment));

	Out_Going_Trans_fromloc79.push_back(t);
	l = location::ptr(
			new location(75, "loc79", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc79));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc78

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -1.202;
	C[3] = -1.202;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[2] = -5.0;
	invariantBoundValue[3] = 6.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc78;

// The transition label ist270

// Original guard: x1 = 8 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
	guardBoundValue[2] = -5.0;
	guardBoundValue[3] = 6.0;
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
			new transition(264, "t270", 76, 67, guard_polytope, assignment));

	Out_Going_Trans_fromloc78.push_back(t);
// The transition label ist272

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
	guardBoundValue[2] = -6.0;
	guardBoundValue[3] = 6.0;
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
			new transition(265, "t272", 76, 75, guard_polytope, assignment));

	Out_Going_Trans_fromloc78.push_back(t);
// The transition label ist271

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
	guardBoundValue[2] = -5.0;
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
			new transition(266, "t271", 76, 77, guard_polytope, assignment));

	Out_Going_Trans_fromloc78.push_back(t);
	l = location::ptr(
			new location(76, "loc78", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc78));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc77

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -1.202;
	C[3] = -1.202;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc77;

// The transition label ist267

// Original guard: x1 = 8 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(267, "t267", 77, 68, guard_polytope, assignment));

	Out_Going_Trans_fromloc77.push_back(t);
// The transition label ist269

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
	guardBoundValue[2] = -5.0;
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
			new transition(268, "t269", 77, 76, guard_polytope, assignment));

	Out_Going_Trans_fromloc77.push_back(t);
// The transition label ist268

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
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
			new transition(269, "t268", 77, 78, guard_polytope, assignment));

	Out_Going_Trans_fromloc77.push_back(t);
	l = location::ptr(
			new location(77, "loc77", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc77));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc76

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -1.5;
	C[3] = -0.5;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc76;

// The transition label ist264

// Original guard: x1 = 8 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(270, "t264", 78, 69, guard_polytope, assignment));

	Out_Going_Trans_fromloc76.push_back(t);
// The transition label ist266

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
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
			new transition(271, "t266", 78, 77, guard_polytope, assignment));

	Out_Going_Trans_fromloc76.push_back(t);
// The transition label ist265

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
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
			new transition(272, "t265", 78, 79, guard_polytope, assignment));

	Out_Going_Trans_fromloc76.push_back(t);
	l = location::ptr(
			new location(78, "loc76", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc76));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc75

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = -1.5;
	C[3] = -0.5;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc75;

// The transition label ist261

// Original guard: x1 = 8 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(273, "t261", 79, 70, guard_polytope, assignment));

	Out_Going_Trans_fromloc75.push_back(t);
// The transition label ist263

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
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
			new transition(274, "t263", 79, 78, guard_polytope, assignment));

	Out_Going_Trans_fromloc75.push_back(t);
// The transition label ist262

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
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
			new transition(275, "t262", 79, 80, guard_polytope, assignment));

	Out_Going_Trans_fromloc75.push_back(t);
	l = location::ptr(
			new location(79, "loc75", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc75));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc74

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc74;

// The transition label ist258

// Original guard: x1 = 8 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(276, "t258", 80, 71, guard_polytope, assignment));

	Out_Going_Trans_fromloc74.push_back(t);
// The transition label ist260

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
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
			new transition(277, "t260", 80, 79, guard_polytope, assignment));

	Out_Going_Trans_fromloc74.push_back(t);
// The transition label ist259

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
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
			new transition(278, "t259", 80, 81, guard_polytope, assignment));

	Out_Going_Trans_fromloc74.push_back(t);
	l = location::ptr(
			new location(80, "loc74", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc74));
	Hybrid_Automata.addLocation(l);

// The mode name is  loc73

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(2, 2) = -1.5;
	Amatrix(2, 3) = -0.2;
	Amatrix(3, 2) = -0.5;
	Amatrix(3, 3) = -1.2;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.2;
	C[3] = 1.2;
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
	invariantBoundValue[0] = -8.0;
	invariantBoundValue[1] = 9.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc73;

// The transition label ist256

// Original guard: x1 = 8 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 8.0;
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
			new transition(279, "t256", 81, 72, guard_polytope, assignment));

	Out_Going_Trans_fromloc73.push_back(t);
// The transition label ist257

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

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
	guardBoundValue[0] = -8.0;
	guardBoundValue[1] = 9.0;
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
			new transition(280, "t257", 81, 80, guard_polytope, assignment));

	Out_Going_Trans_fromloc73.push_back(t);
	l = location::ptr(
			new location(81, "loc73", system_dynamics, invariant, true,
					Out_Going_Trans_fromloc73));
	Hybrid_Automata.addLocation(l);

}

