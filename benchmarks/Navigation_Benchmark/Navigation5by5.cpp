// Created by Hyst v1.2
// Hybrid Automaton in Xspeed
// Converted from file: /home/hazel/hazel/models/Benchmarks/Nav5t.xml
// Command Line arguments: -xspeed -o /home/hazel/hazel/models/Benchmarks/Nav5t.cpp /home/hazel/hazel/models/Benchmarks/Nav5t.xml /home/hazel/hazel/models/Benchmarks/Nav5.cfg

#include "../../benchmarks/Navigation_Benchmark/NavigationBenchmark.h"

void SetNavigationModel5by5Timed(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

// ************* Section required for Forbidden Inputs *************
	unsigned int Directions_Type = 1;
	unsigned int iter_max = 980;
	double time_horizon = 10.0;
	double sampling_time = 1.0E-4;
	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I, forbid_polytope;

	polytope::ptr invariant0, invariant1, invariant2, invariant3, invariant4,
			invariant5, invariant6, invariant7, invariant8, invariant9,
			invariant10, invariant11, invariant12, invariant13, invariant14,
			invariant15, invariant16, invariant17, invariant18, invariant19,
			invariant20, invariant21, invariant22, invariant23, invariant24;

	polytope::ptr guard_polytope0, guard_polytope1, guard_polytope2,
			guard_polytope3, guard_polytope4, guard_polytope5, guard_polytope6,
			guard_polytope7, guard_polytope8, guard_polytope9, guard_polytope10,
			guard_polytope11, guard_polytope12, guard_polytope13,
			guard_polytope14, guard_polytope15, guard_polytope16,
			guard_polytope17, guard_polytope18, guard_polytope19,
			guard_polytope20, guard_polytope21, guard_polytope22,
			guard_polytope23, guard_polytope24, guard_polytope25,
			guard_polytope26, guard_polytope27, guard_polytope28,
			guard_polytope29, guard_polytope30, guard_polytope31,
			guard_polytope32, guard_polytope33, guard_polytope34,
			guard_polytope35, guard_polytope36, guard_polytope37,
			guard_polytope38, guard_polytope39, guard_polytope40,
			guard_polytope41, guard_polytope42, guard_polytope43,
			guard_polytope44, guard_polytope45, guard_polytope46,
			guard_polytope47, guard_polytope48, guard_polytope49,
			guard_polytope50, guard_polytope51, guard_polytope52,
			guard_polytope53, guard_polytope54, guard_polytope55,
			guard_polytope56, guard_polytope57, guard_polytope58,
			guard_polytope59, guard_polytope60, guard_polytope61,
			guard_polytope62, guard_polytope63, guard_polytope64,
			guard_polytope65, guard_polytope66, guard_polytope67,
			guard_polytope68, guard_polytope69, guard_polytope70,
			guard_polytope71, guard_polytope72;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix,
			Bmatrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV, C, invariantBoundValue,
			guardBoundValue, boundValueF;

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1, boundSignV =
			1;

// The mode name is  loc3

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.8;
	C[3] = 0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -0.0;
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant0 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc3;

// The transition label ist6

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -0.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope0 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	math::matrix<double> R;
	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	std::vector<double> w(row);
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	Assign assignment;
	assignment.Map = R;
	assignment.b = w;

	transition::ptr t1 = transition::ptr(
			new transition(1, "t6", 1, 10, guard_polytope0, assignment));

	Out_Going_Trans_fromloc3.push_back(t1);
// The transition label ist8

// Original guard: x1 = 1 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope1 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t2 = transition::ptr(
			new transition(2, "t8", 1, 2, guard_polytope1, assignment));

	Out_Going_Trans_fromloc3.push_back(t2);
// The transition label ist7

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -0.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope2 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t3 = transition::ptr(
			new transition(3, "t7", 1, 4, guard_polytope2, assignment));

	Out_Going_Trans_fromloc3.push_back(t3);
	location::ptr l1 = location::ptr(
			new location(1, "loc3", system_dynamics, invariant0, true,
					Out_Going_Trans_fromloc3));

	Hybrid_Automata.addLocation(l1);

// The mode name is  loc8

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.2;
	C[3] = -0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant1 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc8;

// The transition label ist20

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope3 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t4 = transition::ptr(
			new transition(4, "t20", 2, 5, guard_polytope3, assignment));

	Out_Going_Trans_fromloc8.push_back(t4);
// The transition label ist21

// Original guard: x1 = 2 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope4 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t5 = transition::ptr(
			new transition(5, "t21", 2, 3, guard_polytope4, assignment));

	Out_Going_Trans_fromloc8.push_back(t5);
// The transition label ist19

// Original guard: x1 = 1 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope5 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t6 = transition::ptr(
			new transition(6, "t19", 2, 1, guard_polytope5, assignment));

	Out_Going_Trans_fromloc8.push_back(t6);
// The transition label ist18

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope6 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t7 = transition::ptr(
			new transition(7, "t18", 2, 13, guard_polytope6, assignment));

	Out_Going_Trans_fromloc8.push_back(t7);
	location::ptr l2 = location::ptr(
			new location(2, "loc8", system_dynamics, invariant1, true,
					Out_Going_Trans_fromloc8));
	Hybrid_Automata.addLocation(l2);

// The mode name is  BAD

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 1.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 0.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 1.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 0.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = 1.0;
	Amatrix(2, 3) = 0.0;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = 0.0;
	Amatrix(3, 3) = 1.0;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.0;
	C[3] = 0.0;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant2 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromBAD;

	location::ptr l3 = location::ptr(
			new location(3, "BAD", system_dynamics, invariant2, true,
					Out_Going_Trans_fromBAD));
	Hybrid_Automata.addLocation(l3);

// The mode name is  loc4

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.8;
	C[3] = 0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -0.0;
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant3 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc4;

// The transition label ist9

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -0.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope7 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t8 = transition::ptr(
			new transition(8, "t9", 4, 1, guard_polytope7, assignment));

	Out_Going_Trans_fromloc4.push_back(t8);
// The transition label ist11

// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope8 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t9 = transition::ptr(
			new transition(9, "t11", 4, 5, guard_polytope8, assignment));

	Out_Going_Trans_fromloc4.push_back(t9);
// The transition label ist10

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -0.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope9 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t10 = transition::ptr(
			new transition(10, "t10", 4, 9, guard_polytope9, assignment));

	Out_Going_Trans_fromloc4.push_back(t10);
	location::ptr l4 = location::ptr(
			new location(4, "loc4", system_dynamics, invariant3, true,
					Out_Going_Trans_fromloc4));
	Hybrid_Automata.addLocation(l4);

// The mode name is  loc7

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.2;
	C[3] = -0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant4 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc7;

// The transition label ist15

// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope10 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t11 = transition::ptr(
			new transition(11, "t15", 5, 4, guard_polytope10, assignment));

	Out_Going_Trans_fromloc7.push_back(t11);
// The transition label ist14

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope11 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t12 = transition::ptr(
			new transition(12, "t14", 5, 2, guard_polytope11, assignment));

	Out_Going_Trans_fromloc7.push_back(t12);
// The transition label ist17

// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope12 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t13 = transition::ptr(
			new transition(13, "t17", 5, 6, guard_polytope12, assignment));

	Out_Going_Trans_fromloc7.push_back(t13);
// The transition label ist16

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope13 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t14 = transition::ptr(
			new transition(14, "t16", 5, 7, guard_polytope13, assignment));

	Out_Going_Trans_fromloc7.push_back(t14);
	location::ptr l5 = location::ptr(
			new location(5, "loc7", system_dynamics, invariant4, true,
					Out_Going_Trans_fromloc7));
	Hybrid_Automata.addLocation(l5);

// The mode name is  loc12

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.8;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant5 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc12;

// The transition label ist32

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope14 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t15 = transition::ptr(
			new transition(15, "t32", 6, 3, guard_polytope14, assignment));

	Out_Going_Trans_fromloc12.push_back(t15);
// The transition label ist33

// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope15 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t16 = transition::ptr(
			new transition(16, "t33", 6, 5, guard_polytope15, assignment));

	Out_Going_Trans_fromloc12.push_back(t16);
// The transition label ist34

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope16 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t17 = transition::ptr(
			new transition(17, "t34", 6, 8, guard_polytope16, assignment));

	Out_Going_Trans_fromloc12.push_back(t17);
// The transition label ist35

// Original guard: x1 = 3 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope17 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t18 = transition::ptr(
			new transition(18, "t35", 6, 18, guard_polytope17, assignment));

	Out_Going_Trans_fromloc12.push_back(t18);
	location::ptr l6 = location::ptr(
			new location(6, "loc12", system_dynamics, invariant5, true,
					Out_Going_Trans_fromloc12));
	Hybrid_Automata.addLocation(l6);

// The mode name is  GOOD

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 1.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 0.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 1.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 0.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = 1.0;
	Amatrix(2, 3) = 0.0;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = 0.0;
	Amatrix(3, 3) = 1.0;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.0;
	C[3] = 0.0;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -0.0;
	invariantBoundValue[3] = 1.0;
	invariant6 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromGOOD;

	location::ptr l7 = location::ptr(
			new location(7, "GOOD", system_dynamics, invariant6, true,
					Out_Going_Trans_fromGOOD));
	Hybrid_Automata.addLocation(l7);

// The mode name is  loc11

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.2;
	C[3] = 0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -0.0;
	invariantBoundValue[3] = 1.0;
	invariant7 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc11;

// The transition label ist31

// Original guard: x1 = 3 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -0.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope18 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t19 = transition::ptr(
			new transition(19, "t31", 8, 20, guard_polytope18, assignment));

	Out_Going_Trans_fromloc11.push_back(t19);
// The transition label ist30

// Original guard: x1 = 2 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -0.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope19 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t20 = transition::ptr(
			new transition(20, "t30", 8, 7, guard_polytope19, assignment));

	Out_Going_Trans_fromloc11.push_back(t20);
// The transition label ist29

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope20 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t21 = transition::ptr(
			new transition(21, "t29", 8, 6, guard_polytope20, assignment));

	Out_Going_Trans_fromloc11.push_back(t21);
	location::ptr l8 = location::ptr(
			new location(8, "loc11", system_dynamics, invariant7, true,
					Out_Going_Trans_fromloc11));
	Hybrid_Automata.addLocation(l8);

// The mode name is  loc5

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.8;
	C[3] = 0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -0.0;
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -0.0;
	invariantBoundValue[3] = 1.0;
	invariant8 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc5;

// The transition label ist13

// Original guard: x1 = 1 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -0.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope21 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t22 = transition::ptr(
			new transition(22, "t13", 9, 7, guard_polytope21, assignment));

	Out_Going_Trans_fromloc5.push_back(t22);
// The transition label ist12

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -0.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope22 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t23 = transition::ptr(
			new transition(23, "t12", 9, 4, guard_polytope22, assignment));

	Out_Going_Trans_fromloc5.push_back(t23);
	location::ptr l9 = location::ptr(
			new location(9, "loc5", system_dynamics, invariant8, true,
					Out_Going_Trans_fromloc5));
	Hybrid_Automata.addLocation(l9);

// The mode name is  loc2

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.8;
	C[3] = 0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -0.0;
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant9 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc2;

// The transition label ist4

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -0.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope23 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t24 = transition::ptr(
			new transition(24, "t4", 10, 1, guard_polytope23, assignment));

	Out_Going_Trans_fromloc2.push_back(t24);
// The transition label ist3

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -0.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope24 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t25 = transition::ptr(
			new transition(25, "t3", 10, 11, guard_polytope24, assignment));

	Out_Going_Trans_fromloc2.push_back(t25);
// The transition label ist5

// Original guard: x1 = 1 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope25 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t26 = transition::ptr(
			new transition(26, "t5", 10, 13, guard_polytope25, assignment));

	Out_Going_Trans_fromloc2.push_back(t26);
	location::ptr l10 = location::ptr(
			new location(10, "loc2", system_dynamics, invariant9, true,
					Out_Going_Trans_fromloc2));
	Hybrid_Automata.addLocation(l10);

// The mode name is  loc1

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.8;
	C[3] = 0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -0.0;
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant10 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc1;

// The transition label ist1

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -0.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope26 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t27 = transition::ptr(
			new transition(27, "t1", 11, 10, guard_polytope26, assignment));

	Out_Going_Trans_fromloc1.push_back(t27);
// The transition label ist2

// Original guard: x1 = 1 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope27 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t28 = transition::ptr(
			new transition(28, "t2", 11, 12, guard_polytope27, assignment));

	Out_Going_Trans_fromloc1.push_back(t28);
	location::ptr l11 = location::ptr(
			new location(11, "loc1", system_dynamics, invariant10, true,
					Out_Going_Trans_fromloc1));
	Hybrid_Automata.addLocation(l11);

// The mode name is  loc10

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.2;
	C[3] = -0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant11 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc10;

// The transition label ist26

// Original guard: x1 = 1 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope28 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t29 = transition::ptr(
			new transition(29, "t26", 12, 11, guard_polytope28, assignment));

	Out_Going_Trans_fromloc10.push_back(t29);
// The transition label ist28

// Original guard: x1 = 2 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope29 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t30 = transition::ptr(
			new transition(30, "t28", 12, 14, guard_polytope29, assignment));

	Out_Going_Trans_fromloc10.push_back(t30);
// The transition label ist27

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope30 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t31 = transition::ptr(
			new transition(31, "t27", 12, 13, guard_polytope30, assignment));

	Out_Going_Trans_fromloc10.push_back(t31);
	location::ptr l12 = location::ptr(
			new location(12, "loc10", system_dynamics, invariant11, true,
					Out_Going_Trans_fromloc10));
	Hybrid_Automata.addLocation(l12);

// The mode name is  loc9

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.2;
	C[3] = -0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant12 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc9;

// The transition label ist23

// Original guard: x1 = 1 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope31 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t32 = transition::ptr(
			new transition(32, "t23", 13, 10, guard_polytope31, assignment));

	Out_Going_Trans_fromloc9.push_back(t32);
// The transition label ist22

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope32 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t33 = transition::ptr(
			new transition(33, "t22", 13, 12, guard_polytope32, assignment));

	Out_Going_Trans_fromloc9.push_back(t33);
// The transition label ist25

// Original guard: x1 = 2 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope33 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t34 = transition::ptr(
			new transition(34, "t25", 13, 15, guard_polytope33, assignment));

	Out_Going_Trans_fromloc9.push_back(t34);
// The transition label ist24

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope34 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t35 = transition::ptr(
			new transition(35, "t24", 13, 2, guard_polytope34, assignment));

	Out_Going_Trans_fromloc9.push_back(t35);
	location::ptr l13 = location::ptr(
			new location(13, "loc9", system_dynamics, invariant12, true,
					Out_Going_Trans_fromloc9));
	Hybrid_Automata.addLocation(l13);

// The mode name is  loc15

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.8;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant13 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc15;

// The transition label ist40

// Original guard: x1 = 2 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope35 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t36 = transition::ptr(
			new transition(36, "t40", 14, 12, guard_polytope35, assignment));

	Out_Going_Trans_fromloc15.push_back(t36);
// The transition label ist42

// Original guard: x1 = 3 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope36 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t37 = transition::ptr(
			new transition(37, "t42", 14, 16, guard_polytope36, assignment));

	Out_Going_Trans_fromloc15.push_back(t37);
// The transition label ist41

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope37 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t38 = transition::ptr(
			new transition(38, "t41", 14, 15, guard_polytope37, assignment));

	Out_Going_Trans_fromloc15.push_back(t38);
	location::ptr l14 = location::ptr(
			new location(14, "loc15", system_dynamics, invariant13, true,
					Out_Going_Trans_fromloc15));
	Hybrid_Automata.addLocation(l14);

// The mode name is  loc14

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.424266;
	C[3] = 0.494977;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant14 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc14;

// The transition label ist36

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope38 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t39 = transition::ptr(
			new transition(39, "t36", 15, 14, guard_polytope38, assignment));

	Out_Going_Trans_fromloc14.push_back(t39);
// The transition label ist37

// Original guard: x1 = 2 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope39 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t40 = transition::ptr(
			new transition(40, "t37", 15, 13, guard_polytope39, assignment));

	Out_Going_Trans_fromloc14.push_back(t40);
// The transition label ist39

// Original guard: x1 = 3 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope40 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t41 = transition::ptr(
			new transition(41, "t39", 15, 17, guard_polytope40, assignment));

	Out_Going_Trans_fromloc14.push_back(t41);
// The transition label ist38

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope41 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t42 = transition::ptr(
			new transition(42, "t38", 15, 3, guard_polytope41, assignment));

	Out_Going_Trans_fromloc14.push_back(t42);
	location::ptr l15 = location::ptr(
			new location(15, "loc14", system_dynamics, invariant14, true,
					Out_Going_Trans_fromloc14));
	Hybrid_Automata.addLocation(l15);

// The mode name is  loc20

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.8;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant15 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc20;

// The transition label ist58

// Original guard: x1 = 3 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope42 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t43 = transition::ptr(
			new transition(43, "t58", 16, 14, guard_polytope42, assignment));

	Out_Going_Trans_fromloc20.push_back(t43);
// The transition label ist60

// Original guard: x1 = 4 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope43 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t44 = transition::ptr(
			new transition(44, "t60", 16, 21, guard_polytope43, assignment));

	Out_Going_Trans_fromloc20.push_back(t44);
// The transition label ist59

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope44 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t45 = transition::ptr(
			new transition(45, "t59", 16, 17, guard_polytope44, assignment));

	Out_Going_Trans_fromloc20.push_back(t45);
	location::ptr l16 = location::ptr(
			new location(16, "loc20", system_dynamics, invariant15, true,
					Out_Going_Trans_fromloc20));
	Hybrid_Automata.addLocation(l16);

// The mode name is  loc19

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.424266;
	C[3] = 0.494977;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant16 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc19;

// The transition label ist55

// Original guard: x1 = 3 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope45 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t46 = transition::ptr(
			new transition(46, "t55", 17, 15, guard_polytope45, assignment));

	Out_Going_Trans_fromloc19.push_back(t46);
// The transition label ist57

// Original guard: x1 = 4 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope46 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t47 = transition::ptr(
			new transition(47, "t57", 17, 22, guard_polytope46, assignment));

	Out_Going_Trans_fromloc19.push_back(t47);
// The transition label ist54

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope47 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t48 = transition::ptr(
			new transition(48, "t54", 17, 16, guard_polytope47, assignment));

	Out_Going_Trans_fromloc19.push_back(t48);
// The transition label ist56

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope48 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t49 = transition::ptr(
			new transition(49, "t56", 17, 19, guard_polytope48, assignment));

	Out_Going_Trans_fromloc19.push_back(t49);
	location::ptr l17 = location::ptr(
			new location(17, "loc19", system_dynamics, invariant16, true,
					Out_Going_Trans_fromloc19));
	Hybrid_Automata.addLocation(l17);
	Hybrid_Automata.addInitialLocation(l17);

// The mode name is  loc17

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.8;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant17 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc17;

// The transition label ist46

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope49 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t50 = transition::ptr(
			new transition(50, "t46", 18, 19, guard_polytope49, assignment));

	Out_Going_Trans_fromloc17.push_back(t50);
// The transition label ist49

// Original guard: x1 = 4 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope50 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t51 = transition::ptr(
			new transition(51, "t49", 18, 24, guard_polytope50, assignment));

	Out_Going_Trans_fromloc17.push_back(t51);
// The transition label ist48

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope51 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t52 = transition::ptr(
			new transition(52, "t48", 18, 20, guard_polytope51, assignment));

	Out_Going_Trans_fromloc17.push_back(t52);
// The transition label ist47

// Original guard: x1 = 3 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope52 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t53 = transition::ptr(
			new transition(53, "t47", 18, 6, guard_polytope52, assignment));

	Out_Going_Trans_fromloc17.push_back(t53);
	location::ptr l18 = location::ptr(
			new location(18, "loc17", system_dynamics, invariant17, true,
					Out_Going_Trans_fromloc17));
	Hybrid_Automata.addLocation(l18);

// The mode name is  loc18

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.424266;
	C[3] = -0.494977;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant18 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc18;

// The transition label ist50

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope53 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t54 = transition::ptr(
			new transition(54, "t50", 19, 17, guard_polytope53, assignment));

	Out_Going_Trans_fromloc18.push_back(t54);
// The transition label ist51

// Original guard: x1 = 3 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope54 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t55 = transition::ptr(
			new transition(55, "t51", 19, 3, guard_polytope54, assignment));

	Out_Going_Trans_fromloc18.push_back(t55);
// The transition label ist53

// Original guard: x1 = 4 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope55 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t56 = transition::ptr(
			new transition(56, "t53", 19, 23, guard_polytope55, assignment));

	Out_Going_Trans_fromloc18.push_back(t56);
// The transition label ist52

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope56 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t57 = transition::ptr(
			new transition(57, "t52", 19, 18, guard_polytope56, assignment));

	Out_Going_Trans_fromloc18.push_back(t57);
	location::ptr l19 = location::ptr(
			new location(19, "loc18", system_dynamics, invariant18, true,
					Out_Going_Trans_fromloc18));
	Hybrid_Automata.addLocation(l19);

// The mode name is  loc16

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.2;
	C[3] = 0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -3.0;
	invariantBoundValue[1] = 4.0;
	invariantBoundValue[2] = -0.0;
	invariantBoundValue[3] = 1.0;
	invariant19 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc16;

// The transition label ist43

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope57 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t58 = transition::ptr(
			new transition(58, "t43", 20, 18, guard_polytope57, assignment));

	Out_Going_Trans_fromloc16.push_back(t58);
// The transition label ist45

// Original guard: x1 = 4 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -0.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope58 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t59 = transition::ptr(
			new transition(59, "t45", 20, 25, guard_polytope58, assignment));

	Out_Going_Trans_fromloc16.push_back(t59);
// The transition label ist44

// Original guard: x1 = 3 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -3.0;
	guardBoundValue[1] = 3.0;
	guardBoundValue[2] = -0.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope59 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t60 = transition::ptr(
			new transition(60, "t44", 20, 8, guard_polytope59, assignment));

	Out_Going_Trans_fromloc16.push_back(t60);
	location::ptr l20 = location::ptr(
			new location(20, "loc16", system_dynamics, invariant19, true,
					Out_Going_Trans_fromloc16));
	Hybrid_Automata.addLocation(l20);

// The mode name is  loc25

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.8;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -4.0;
	invariantBoundValue[3] = 5.0;
	invariant20 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc25;

// The transition label ist72

// Original guard: x1 = 4 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 5.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope60 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t61 = transition::ptr(
			new transition(61, "t72", 21, 16, guard_polytope60, assignment));

	Out_Going_Trans_fromloc25.push_back(t61);
// The transition label ist73

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope61 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t62 = transition::ptr(
			new transition(62, "t73", 21, 22, guard_polytope61, assignment));

	Out_Going_Trans_fromloc25.push_back(t62);
	location::ptr l21 = location::ptr(
			new location(21, "loc25", system_dynamics, invariant20, true,
					Out_Going_Trans_fromloc25));
	Hybrid_Automata.addLocation(l21);

// The mode name is  loc24

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.2;
	C[3] = -0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -3.0;
	invariantBoundValue[3] = 4.0;
	invariant21 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc24;

// The transition label ist70

// Original guard: x1 = 4 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope62 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t63 = transition::ptr(
			new transition(63, "t70", 22, 17, guard_polytope62, assignment));

	Out_Going_Trans_fromloc24.push_back(t63);
// The transition label ist69

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -4.0;
	guardBoundValue[3] = 4.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope63 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t64 = transition::ptr(
			new transition(64, "t69", 22, 21, guard_polytope63, assignment));

	Out_Going_Trans_fromloc24.push_back(t64);
// The transition label ist71

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope64 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t65 = transition::ptr(
			new transition(65, "t71", 22, 23, guard_polytope64, assignment));

	Out_Going_Trans_fromloc24.push_back(t65);
	location::ptr l22 = location::ptr(
			new location(22, "loc24", system_dynamics, invariant21, true,
					Out_Going_Trans_fromloc24));
	Hybrid_Automata.addLocation(l22);

// The mode name is  loc23

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.2;
	C[3] = -0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant22 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc23;

// The transition label ist66

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -3.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope65 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t66 = transition::ptr(
			new transition(66, "t66", 23, 22, guard_polytope65, assignment));

	Out_Going_Trans_fromloc23.push_back(t66);
// The transition label ist67

// Original guard: x1 = 4 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 3.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope66 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t67 = transition::ptr(
			new transition(67, "t67", 23, 19, guard_polytope66, assignment));

	Out_Going_Trans_fromloc23.push_back(t67);
// The transition label ist68

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope67 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t68 = transition::ptr(
			new transition(68, "t68", 23, 24, guard_polytope67, assignment));

	Out_Going_Trans_fromloc23.push_back(t68);
	location::ptr l23 = location::ptr(
			new location(23, "loc23", system_dynamics, invariant22, true,
					Out_Going_Trans_fromloc23));
	Hybrid_Automata.addLocation(l23);

// The mode name is  loc22

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = -0.8;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant23 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc22;

// The transition label ist63

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -2.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope68 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t69 = transition::ptr(
			new transition(69, "t63", 24, 23, guard_polytope68, assignment));

	Out_Going_Trans_fromloc22.push_back(t69);
// The transition label ist65

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope69 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t70 = transition::ptr(
			new transition(70, "t65", 24, 25, guard_polytope69, assignment));

	Out_Going_Trans_fromloc22.push_back(t70);
// The transition label ist64

// Original guard: x1 = 4 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 2.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope70 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t71 = transition::ptr(
			new transition(71, "t64", 24, 18, guard_polytope70, assignment));

	Out_Going_Trans_fromloc22.push_back(t71);
	location::ptr l24 = location::ptr(
			new location(24, "loc22", system_dynamics, invariant23, true,
					Out_Going_Trans_fromloc22));
	Hybrid_Automata.addLocation(l24);

// The mode name is  loc21

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0.0;
	Amatrix(0, 1) = 0.0;
	Amatrix(0, 2) = 1.0;
	Amatrix(0, 3) = 0.0;
	Amatrix(0, 4) = 0.0;
	Amatrix(1, 0) = 0.0;
	Amatrix(1, 1) = 0.0;
	Amatrix(1, 2) = 0.0;
	Amatrix(1, 3) = 1.0;
	Amatrix(1, 4) = 0.0;
	Amatrix(2, 0) = 0.0;
	Amatrix(2, 1) = 0.0;
	Amatrix(2, 2) = -0.8;
	Amatrix(2, 3) = -0.2;
	Amatrix(2, 4) = 0.0;
	Amatrix(3, 0) = 0.0;
	Amatrix(3, 1) = 0.0;
	Amatrix(3, 2) = -0.1;
	Amatrix(3, 3) = -0.8;
	Amatrix(3, 4) = 0.0;
	Amatrix(4, 0) = 0.0;
	Amatrix(4, 1) = 0.0;
	Amatrix(4, 2) = 0.0;
	Amatrix(4, 3) = 0.0;
	Amatrix(4, 4) = 0.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C[0] = 0.0;
	C[1] = 0.0;
	C[2] = 0.2;
	C[3] = 0.8;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(0, 1) = 0.0;
	invariantConstraintsMatrix(0, 2) = 0.0;
	invariantConstraintsMatrix(0, 3) = 0.0;
	invariantConstraintsMatrix(0, 4) = 0.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 0.0;
	invariantConstraintsMatrix(1, 2) = 0.0;
	invariantConstraintsMatrix(1, 3) = 0.0;
	invariantConstraintsMatrix(1, 4) = 0.0;
	invariantConstraintsMatrix(2, 0) = 0.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(2, 2) = 0.0;
	invariantConstraintsMatrix(2, 3) = 0.0;
	invariantConstraintsMatrix(2, 4) = 0.0;
	invariantConstraintsMatrix(3, 0) = 0.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(3, 2) = 0.0;
	invariantConstraintsMatrix(3, 3) = 0.0;
	invariantConstraintsMatrix(3, 4) = 0.0;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = -4.0;
	invariantBoundValue[1] = 5.0;
	invariantBoundValue[2] = -0.0;
	invariantBoundValue[3] = 1.0;
	invariant24 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromloc21;

// The transition label ist61

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 5.0;
	guardBoundValue[2] = -1.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope71 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t72 = transition::ptr(
			new transition(72, "t61", 25, 24, guard_polytope71, assignment));

	Out_Going_Trans_fromloc21.push_back(t72);
// The transition label ist62

// Original guard: x1 = 4 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(0, 1) = 0.0;
	guardConstraintsMatrix(0, 2) = 0.0;
	guardConstraintsMatrix(0, 3) = 0.0;
	guardConstraintsMatrix(0, 4) = 0.0;
	guardConstraintsMatrix(1, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 0.0;
	guardConstraintsMatrix(1, 2) = 0.0;
	guardConstraintsMatrix(1, 3) = 0.0;
	guardConstraintsMatrix(1, 4) = 0.0;
	guardConstraintsMatrix(2, 0) = 0.0;
	guardConstraintsMatrix(2, 1) = -1.0;
	guardConstraintsMatrix(2, 2) = 0.0;
	guardConstraintsMatrix(2, 3) = 0.0;
	guardConstraintsMatrix(2, 4) = 0.0;
	guardConstraintsMatrix(3, 0) = 0.0;
	guardConstraintsMatrix(3, 1) = 1.0;
	guardConstraintsMatrix(3, 2) = 0.0;
	guardConstraintsMatrix(3, 3) = 0.0;
	guardConstraintsMatrix(3, 4) = 0.0;
	guardConstraintsMatrix(4, 0) = 0.0;
	guardConstraintsMatrix(4, 1) = 0.0;
	guardConstraintsMatrix(4, 2) = -1.0;
	guardConstraintsMatrix(4, 3) = 0.0;
	guardConstraintsMatrix(4, 4) = 0.0;
	guardConstraintsMatrix(5, 0) = 0.0;
	guardConstraintsMatrix(5, 1) = 0.0;
	guardConstraintsMatrix(5, 2) = 1.0;
	guardConstraintsMatrix(5, 3) = 0.0;
	guardConstraintsMatrix(5, 4) = 0.0;
	guardConstraintsMatrix(6, 0) = 0.0;
	guardConstraintsMatrix(6, 1) = 0.0;
	guardConstraintsMatrix(6, 2) = 0.0;
	guardConstraintsMatrix(6, 3) = -1.0;
	guardConstraintsMatrix(6, 4) = 0.0;
	guardConstraintsMatrix(7, 0) = 0.0;
	guardConstraintsMatrix(7, 1) = 0.0;
	guardConstraintsMatrix(7, 2) = 0.0;
	guardConstraintsMatrix(7, 3) = 1.0;
	guardConstraintsMatrix(7, 4) = 0.0;

	guardBoundValue.resize(row);
	guardBoundValue[0] = -4.0;
	guardBoundValue[1] = 4.0;
	guardBoundValue[2] = -0.0;
	guardBoundValue[3] = 1.0;
	guardBoundValue[4] = 1000.0;
	guardBoundValue[5] = 1000.0;
	guardBoundValue[6] = 1000.0;
	guardBoundValue[7] = 1000.0;
	guard_polytope72 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 5;
	col = 5;
	R.resize(row, col);
	R(0, 0) = 1.0;
	R(0, 1) = 0.0;
	R(0, 2) = 0.0;
	R(0, 3) = 0.0;
	R(0, 4) = 0.0;
	R(1, 0) = 0.0;
	R(1, 1) = 1.0;
	R(1, 2) = 0.0;
	R(1, 3) = 0.0;
	R(1, 4) = 0.0;
	R(2, 0) = 0.0;
	R(2, 1) = 0.0;
	R(2, 2) = 1.0;
	R(2, 3) = 0.0;
	R(2, 4) = 0.0;
	R(3, 0) = 0.0;
	R(3, 1) = 0.0;
	R(3, 2) = 0.0;
	R(3, 3) = 1.0;
	R(3, 4) = 0.0;
	R(4, 0) = 0.0;
	R(4, 1) = 0.0;
	R(4, 2) = 0.0;
	R(4, 3) = 0.0;
	R(4, 4) = 1.0;
	w[0] = 0.0;
	w[1] = 0.0;
	w[2] = 0.0;
	w[3] = 0.0;
	w[4] = 0.0;

	assignment.Map = R;
	assignment.b = w;

	transition::ptr t73 = transition::ptr(
			new transition(73, "t62", 25, 20, guard_polytope72, assignment));

	Out_Going_Trans_fromloc21.push_back(t73);
	location::ptr l25 = location::ptr(
			new location(25, "loc21", system_dynamics, invariant24, true,
					Out_Going_Trans_fromloc21));
	Hybrid_Automata.addLocation(l25);

	row = 10;
	col = 5;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(0, 2) = 0;
	ConstraintsMatrixI(0, 3) = 0;
	ConstraintsMatrixI(0, 4) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(1, 2) = 0;
	ConstraintsMatrixI(1, 3) = 0;
	ConstraintsMatrixI(1, 4) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(2, 2) = 0;
	ConstraintsMatrixI(2, 3) = 0;
	ConstraintsMatrixI(2, 4) = 0;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(3, 2) = 0;
	ConstraintsMatrixI(3, 3) = 0;
	ConstraintsMatrixI(3, 4) = 0;
	ConstraintsMatrixI(4, 0) = 0;
	ConstraintsMatrixI(4, 1) = 0;
	ConstraintsMatrixI(4, 2) = 1;
	ConstraintsMatrixI(4, 3) = 0;
	ConstraintsMatrixI(4, 4) = 0;
	ConstraintsMatrixI(5, 0) = 0;
	ConstraintsMatrixI(5, 1) = 0;
	ConstraintsMatrixI(5, 2) = -1;
	ConstraintsMatrixI(5, 3) = 0;
	ConstraintsMatrixI(5, 4) = 0;
	ConstraintsMatrixI(6, 0) = 0;
	ConstraintsMatrixI(6, 1) = 0;
	ConstraintsMatrixI(6, 2) = 0;
	ConstraintsMatrixI(6, 3) = 1;
	ConstraintsMatrixI(6, 4) = 0;
	ConstraintsMatrixI(7, 0) = 0;
	ConstraintsMatrixI(7, 1) = 0;
	ConstraintsMatrixI(7, 2) = 0;
	ConstraintsMatrixI(7, 3) = -1;
	ConstraintsMatrixI(7, 4) = 0;
	ConstraintsMatrixI(8, 0) = 0;
	ConstraintsMatrixI(8, 1) = 0;
	ConstraintsMatrixI(8, 2) = 0;
	ConstraintsMatrixI(8, 3) = 0;
	ConstraintsMatrixI(8, 4) = 1;
	ConstraintsMatrixI(9, 0) = 0;
	ConstraintsMatrixI(9, 1) = 0;
	ConstraintsMatrixI(9, 2) = 0;
	ConstraintsMatrixI(9, 3) = 0;
	ConstraintsMatrixI(9, 4) = -1;

	boundValueI.resize(row);
	boundValueI[0] = 4;
	boundValueI[1] = -3.5;
	boundValueI[2] = 4;
	boundValueI[3] = -3.5;
	boundValueI[4] = 0.5;
	boundValueI[5] = 0.5;
	boundValueI[6] = 0.5;
	boundValueI[7] = 0.5;
	boundValueI[8] = 0;
	boundValueI[9] = 0;

	initial_polytope_I = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I->getSystemDimension();
	Hybrid_Automata.setDimension(dim);

	Hybrid_Automata.insert_to_map("x1", 0);
	Hybrid_Automata.insert_to_map("x2", 1);
	Hybrid_Automata.insert_to_map("v1", 2);
	Hybrid_Automata.insert_to_map("v2", 3);
	Hybrid_Automata.insert_to_map("t", 4);

	unsigned int initial_location_id = 17;
	symbolic_states::ptr S;
	int transition_id = 0;
	initial_state::ptr I = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I, S,
					transition_id));
	init_state.push_back(I);

}
