/*
 * fwr.cpp
 *
 *  Created on: 05-Dec-2016
 *      Author: amit
 */

#include <benchmarks/archBenchmarks/heart.h>

void setheart(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  low0_s0_q0_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 3) = -0.3;
	Amatrix(4, 3) = 0.05;
	Amatrix(4, 4) = -1.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 3) = 1.0;
	invariantConstraintsMatrix(2, 3) = -1.0;
	invariantConstraintsMatrix(3, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 10.0;
	invariantBoundValue[1] = 20.0;
	invariantBoundValue[3] = 20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromlow0_s0_q0_loc1;

	// The transition label isnull

	// Original guard: st >= 10

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -10.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);
	w[1] = 131.0;

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "null", 1, 5, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q0_loc1.push_back(t);
	// The transition label isnull

	// Original guard: cell1_vh >= 20 & v <= 20

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guardBoundValue[1] = 20.0;
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
			new transition(2, "null", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q0_loc1.push_back(t);
	l = location::ptr(
			new location(1, "low0_s0_q0_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromlow0_s0_q0_loc1));

	Hybrid_Automata.addInitialLocation(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  low0_s0_q1_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 2) = 1.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 3) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 10.0;
	invariantBoundValue[1] = 20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromlow0_s0_q1_loc1;

	// The transition label isnull

	// Original guard: st >= 10

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -10.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);
	w[1] = 131.0;

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(3, "null", 2, 6, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q1_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v >= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
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
			new transition(4, "null", 2, 3, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q1_loc1.push_back(t);
	// The transition label isnull

	// Original guard: cell1_vh <= 0 & v <= 20

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 20.0;
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
			new transition(5, "null", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q1_loc1.push_back(t);
	l = location::ptr(
			new location(2, "low0_s0_q1_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromlow0_s0_q1_loc1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  low0_s0_q2_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 3) = 200.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 3;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 3) = -1.0;
	invariantConstraintsMatrix(2, 3) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 10.0;
	invariantBoundValue[1] = -20.0;
	invariantBoundValue[2] = 138.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromlow0_s0_q2_loc1;

	// The transition label isnull

	// Original guard: st >= 10

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -10.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);
	w[1] = 131.0;

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(6, "null", 3, 7, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q2_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v >= 138

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -138.0;
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
			new transition(7, "null", 3, 4, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q2_loc1.push_back(t);
	l = location::ptr(
			new location(3, "low0_s0_q2_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromlow0_s0_q2_loc1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  low0_s0_q3_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 5) = -0.6;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	C[3] = -3.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 3) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 10.0;
	invariantBoundValue[1] = -20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromlow0_s0_q3_loc1;

	// The transition label isnull

	// Original guard: st >= 10

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -10.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);
	w[1] = 131.0;

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(8, "null", 4, 8, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q3_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v <= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 20.0;
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
			new transition(9, "null", 4, 1, guard_polytope, assignment));

	Out_Going_Trans_fromlow0_s0_q3_loc1.push_back(t);
	l = location::ptr(
			new location(4, "low0_s0_q3_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromlow0_s0_q3_loc1));
	Hybrid_Automata.addLocation(l);

	module1(Hybrid_Automata, init_state_list, reach_parameters);
	module2(Hybrid_Automata, init_state_list, reach_parameters);
	module3(Hybrid_Automata, init_state_list, reach_parameters);
	module4(Hybrid_Automata, init_state_list, reach_parameters);

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

	Hybrid_Automata.insert_to_map("st", 0);
	Hybrid_Automata.insert_to_map("h", 1);
	Hybrid_Automata.insert_to_map("cell1_vh", 2);
	Hybrid_Automata.insert_to_map("v", 3);
	Hybrid_Automata.insert_to_map("cell1_thetaOut", 4);
	Hybrid_Automata.insert_to_map("cell1_theta", 5);


}

void module1(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  high_s0_q0_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 3) = -0.3;
	Amatrix(4, 3) = 0.05;
	Amatrix(4, 4) = -1.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 7;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 0) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 3) = 1.0;
	invariantConstraintsMatrix(5, 3) = -1.0;
	invariantConstraintsMatrix(6, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 20.0;
	invariantBoundValue[1] = -10.0;
	invariantBoundValue[2] = -131.0;
	invariantBoundValue[3] = 131.0;
	invariantBoundValue[4] = 20.0;
	invariantBoundValue[6] = 20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromhigh_s0_q0_loc1;

	// The transition label isnull

	// Original guard: st >= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(10, "null", 5, 9, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q0_loc1.push_back(t);
	// The transition label isnull

	// Original guard: cell1_vh >= 20 & v <= 20

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guardBoundValue[1] = 20.0;
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
			new transition(11, "null", 5, 6, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q0_loc1.push_back(t);
	l = location::ptr(
			new location(5, "high_s0_q0_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromhigh_s0_q0_loc1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  high_s0_q1_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 2) = 1.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 5;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 0) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 3) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 20.0;
	invariantBoundValue[1] = -10.0;
	invariantBoundValue[2] = -131.0;
	invariantBoundValue[3] = 131.0;
	invariantBoundValue[4] = 20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromhigh_s0_q1_loc1;

	// The transition label isnull

	// Original guard: st >= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(12, "null", 6, 10, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q1_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v >= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
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
			new transition(13, "null", 6, 7, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q1_loc1.push_back(t);
	// The transition label isnull

	// Original guard: cell1_vh <= 0 & v <= 20

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 20.0;
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
			new transition(14, "null", 6, 5, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q1_loc1.push_back(t);
	l = location::ptr(
			new location(6, "high_s0_q1_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromhigh_s0_q1_loc1));
	Hybrid_Automata.addLocation(l);

}

void module2(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  high_s0_q2_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 3) = 200.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 0) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 3) = -1.0;
	invariantConstraintsMatrix(5, 3) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 20.0;
	invariantBoundValue[1] = -10.0;
	invariantBoundValue[2] = -131.0;
	invariantBoundValue[3] = 131.0;
	invariantBoundValue[4] = -20.0;
	invariantBoundValue[5] = 138.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromhigh_s0_q2_loc1;

	// The transition label isnull

	// Original guard: st >= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(15, "null", 7, 11, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q2_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v >= 138

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -138.0;
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
			new transition(16, "null", 7, 8, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q2_loc1.push_back(t);
	l = location::ptr(
			new location(7, "high_s0_q2_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromhigh_s0_q2_loc1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  high_s0_q3_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 5) = -0.6;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	C[3] = -3.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 5;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 0) = -1.0;
	invariantConstraintsMatrix(2, 1) = -1.0;
	invariantConstraintsMatrix(3, 1) = 1.0;
	invariantConstraintsMatrix(4, 3) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 20.0;
	invariantBoundValue[1] = -10.0;
	invariantBoundValue[2] = -131.0;
	invariantBoundValue[3] = 131.0;
	invariantBoundValue[4] = -20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromhigh_s0_q3_loc1;

	// The transition label isnull

	// Original guard: st >= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(17, "null", 8, 12, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q3_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v <= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 20.0;
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
			new transition(18, "null", 8, 5, guard_polytope, assignment));

	Out_Going_Trans_fromhigh_s0_q3_loc1.push_back(t);
	l = location::ptr(
			new location(8, "high_s0_q3_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromhigh_s0_q3_loc1));
	Hybrid_Automata.addLocation(l);

}

void module3(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  low1_s0_q0_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 3) = -0.3;
	Amatrix(4, 3) = 0.05;
	Amatrix(4, 4) = -1.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 5;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 3) = 1.0;
	invariantConstraintsMatrix(3, 3) = -1.0;
	invariantConstraintsMatrix(4, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -20.0;
	invariantBoundValue[1] = 1500.0;
	invariantBoundValue[2] = 20.0;
	invariantBoundValue[4] = 20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromlow1_s0_q0_loc1;

	// The transition label isnull

	// Original guard: st >= 1500

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1500.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(19, "null", 9, 1, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q0_loc1.push_back(t);
	// The transition label isnull

	// Original guard: cell1_vh >= 20 & v <= 20

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
	guardBoundValue[1] = 20.0;
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
			new transition(20, "null", 9, 10, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q0_loc1.push_back(t);
	l = location::ptr(
			new location(9, "low1_s0_q0_loc1", system_dynamics, invariant, true,
					Out_Going_Trans_fromlow1_s0_q0_loc1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  low1_s0_q1_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 2) = 1.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 3;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 3) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -20.0;
	invariantBoundValue[1] = 1500.0;
	invariantBoundValue[2] = 20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromlow1_s0_q1_loc1;

	// The transition label isnull

	// Original guard: st >= 1500

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1500.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(21, "null", 10, 2, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q1_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v >= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -20.0;
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
			new transition(22, "null", 10, 11, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q1_loc1.push_back(t);
	// The transition label isnull

	// Original guard: cell1_vh <= 0 & v <= 20

	row = 2;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = 1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = 20.0;
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
			new transition(23, "null", 10, 9, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q1_loc1.push_back(t);
	l = location::ptr(
			new location(10, "low1_s0_q1_loc1", system_dynamics, invariant,
					true, Out_Going_Trans_fromlow1_s0_q1_loc1));
	Hybrid_Automata.addLocation(l);

}

void module4(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  low1_s0_q2_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 3) = 200.0;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 4;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 3) = -1.0;
	invariantConstraintsMatrix(3, 3) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -20.0;
	invariantBoundValue[1] = 1500.0;
	invariantBoundValue[2] = -20.0;
	invariantBoundValue[3] = 138.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromlow1_s0_q2_loc1;

	// The transition label isnull

	// Original guard: st >= 1500

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1500.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(24, "null", 11, 3, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q2_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v >= 138

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -138.0;
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
			new transition(25, "null", 11, 12, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q2_loc1.push_back(t);
	l = location::ptr(
			new location(11, "low1_s0_q2_loc1", system_dynamics, invariant,
					true, Out_Going_Trans_fromlow1_s0_q2_loc1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  low1_s0_q3_loc1

	row = 6;
	col = 6;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(2, 1) = 100.0;
	Amatrix(2, 2) = -100.0;
	Amatrix(2, 3) = -100.0;
	Amatrix(3, 5) = -0.6;
	Amatrix(5, 4) = 1.0;
	Amatrix(5, 5) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.0;
	C[3] = -3.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 3;
	col = 6;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;
	invariantConstraintsMatrix(1, 0) = 1.0;
	invariantConstraintsMatrix(2, 3) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = -20.0;
	invariantBoundValue[1] = 1500.0;
	invariantBoundValue[2] = -20.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromlow1_s0_q3_loc1;

	// The transition label isnull

	// Original guard: st >= 1500

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -1500.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 6;
	col = 6;
	R.resize(row, col);
	R.clear();
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(26, "null", 12, 4, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q3_loc1.push_back(t);
	// The transition label isnull

	// Original guard: v <= 20

	row = 1;
	col = 6;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = 20.0;
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
			new transition(27, "null", 12, 9, guard_polytope, assignment));

	Out_Going_Trans_fromlow1_s0_q3_loc1.push_back(t);
	l = location::ptr(
			new location(12, "low1_s0_q3_loc1", system_dynamics, invariant,
					true, Out_Going_Trans_fromlow1_s0_q3_loc1));
	Hybrid_Automata.addLocation(l);

}
