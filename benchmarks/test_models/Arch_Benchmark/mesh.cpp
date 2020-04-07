/*
 * fwr.cpp
 *
 *  Created on: 05-Dec-2016
 *      Author: amit
 */

#include "../../../benchmarks/test_models/Arch_Benchmark/mesh.h"

void setmesh(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  running_out

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 1.0;
	Amatrix(4, 3) = 1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	C[1] = 0.888888888888889;
	C[3] = 4.032258064516129;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 2) = -1.0;
	invariantConstraintsMatrix(1, 5) = 0.02;
	invariantConstraintsMatrix(2, 2) = 1.0;
	invariantConstraintsMatrix(2, 5) = -0.02;
	invariantConstraintsMatrix(3, 4) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 0.504;
	invariantBoundValue[1] = 0.01;
	invariantBoundValue[2] = 0.01;
	invariantBoundValue[3] = -0.013764624913971095;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromrunning_out;

	// The transition label isnull

	// Original guard: Sy >= 2 * 0.01 * n + 0.01 & Vy >= 0

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(0, 5) = 0.02;
	guardConstraintsMatrix(1, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -0.01;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);
	w[5] = 1.0;

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "null", 1, 1, guard_polytope, assignment));

	Out_Going_Trans_fromrunning_out.push_back(t);
	// The transition label isnull

	// Original guard: Sy <= 2 * 0.01 * n - 0.01 & Vy <= 0

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(0, 5) = -0.02;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -0.01;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);
	w[5] = -1.0;

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(2, "null", 1, 1, guard_polytope, assignment));

	Out_Going_Trans_fromrunning_out.push_back(t);
	// The transition label isnull

	// Original guard: Sx >= -0.01 / 0.7265 & Vx >= 0

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 4) = -1.0;
	guardConstraintsMatrix(1, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 0.013764624913971095;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(3, "null", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromrunning_out.push_back(t);
	l = location::ptr(
			new location(1, "running_out", system_dynamics, invariant, true,
					Out_Going_Trans_fromrunning_out));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  running_in

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 1.0;
	Amatrix(4, 3) = 1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	C[1] = 0.888888888888889;
	C[3] = 4.032258064516129;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;
	invariantConstraintsMatrix(1, 4) = 0.7265;
	invariantConstraintsMatrix(1, 5) = -0.02;
	invariantConstraintsMatrix(2, 2) = -1.0;
	invariantConstraintsMatrix(2, 4) = 0.7265;
	invariantConstraintsMatrix(2, 5) = 0.02;
	invariantConstraintsMatrix(3, 4) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 0.504;
	invariantBoundValue[3] = 0.013764624913971095;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromrunning_in;

	// The transition label isnull

	// Original guard: Sx <= -0.01 / 0.7265 & Vx <= 0

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 4) = 1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -0.013764624913971095;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(4, "null", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromrunning_in.push_back(t);
	// The transition label isnull

	// Original guard: 0.7265 * Sx + Sy - 2 * 0.01 * n >= 0 & Vx * 0.5878 + Vy * 0.809 >= 0

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(0, 4) = -0.7265;
	guardConstraintsMatrix(0, 5) = 0.02;
	guardConstraintsMatrix(1, 1) = -0.809;
	guardConstraintsMatrix(1, 3) = -0.5878;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = -0.14368932038834956;
	R(1, 3) = -0.8309772342698044;
	R(2, 2) = 1.0;
	R(3, 1) = -1.040924361697559;
	R(3, 3) = 0.24368932038834953;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(5, "null", 2, 2, guard_polytope, assignment));

	Out_Going_Trans_fromrunning_in.push_back(t);
	// The transition label isnull

	// Original guard: -0.7265 * Sx + Sy - 2 * 0.01 * n <= 0 & Vx * 0.5878 - Vy * 0.809 >= 0

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(0, 4) = -0.7265;
	guardConstraintsMatrix(0, 5) = -0.02;
	guardConstraintsMatrix(1, 1) = 0.809;
	guardConstraintsMatrix(1, 3) = -0.5878;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = -0.14368932038834956;
	R(1, 3) = 0.8309772342698044;
	R(2, 2) = 1.0;
	R(3, 1) = 1.040924361697559;
	R(3, 3) = 0.24368932038834953;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(6, "null", 2, 2, guard_polytope, assignment));

	Out_Going_Trans_fromrunning_in.push_back(t);
	l = location::ptr(
			new location(2, "running_in", system_dynamics, invariant, true,
					Out_Going_Trans_fromrunning_in));
	Hybrid_Automata.addLocation(l);

	row = 12;
	col = 6;
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
	boundValueI.resize(row);
	boundValueI.assign(row, 0);
	boundValueI[2] = 0.08;
	boundValueI[3] = -0.08;
	boundValueI[6] = 0.5;
	boundValueI[7] = -0.5;
	boundValueI[8] = -0.02;	//Sx=-0.02    //-0.02<=Sx<=-0.03
	boundValueI[9] = 0.03;	//Sx=-0.02    //changed to a set instead of a point -0.02

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
	Hybrid_Automata.insert_to_map("Vy", 1);
	Hybrid_Automata.insert_to_map("Sy", 2);
	Hybrid_Automata.insert_to_map("Vx", 3);
	Hybrid_Automata.insert_to_map("Sx", 4);
	Hybrid_Automata.insert_to_map("n", 5);

}
