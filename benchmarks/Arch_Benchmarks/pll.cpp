#include "benchmarks/Arch_Benchmarks/pll.h"

void setpllConv(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  up_1

	row = 8;
	col = 8;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1, 1) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 404000.0;
	C[1] = 8.015873015873016E7;
	C[3] = 1.691204E8;
	C[4] = 1.6956E8;
	C[6] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 8;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 4) = -1.0;
	invariantConstraintsMatrix(1, 4) = 1.0;
	invariantConstraintsMatrix(2, 3) = -1.0;
	invariantConstraintsMatrix(3, 3) = 1.0;
	invariantConstraintsMatrix(4, 5) = -1.0;
	invariantConstraintsMatrix(5, 5) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 6.283;
	invariantBoundValue[2] = 2.527;
	invariantBoundValue[3] = 3.756;
	invariantBoundValue[4] = -2.0;
	invariantBoundValue[5] = 2.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromup_1;

	// The transition label isnull

	// Original guard: phi_v = 0

	row = 2;
	col = 8;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = -1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 8;
	col = 8;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 3.0;
	R(6, 6) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "null", 1, 4, guard_polytope, assignment));

	Out_Going_Trans_fromup_1.push_back(t);
	l = location::ptr(
			new location(1, "up_1", system_dynamics, invariant, true,
					Out_Going_Trans_fromup_1));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  both_0

	row = 8;
	col = 8;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1, 1) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[3] = 1.691204E8;
	C[4] = 1.6956E8;
	C[6] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 8;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 4) = -1.0;
	invariantConstraintsMatrix(1, 4) = 1.0;
	invariantConstraintsMatrix(2, 3) = -1.0;
	invariantConstraintsMatrix(3, 3) = 1.0;
	invariantConstraintsMatrix(4, 5) = -1.0;
	invariantConstraintsMatrix(5, 5) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 6.283;
	invariantBoundValue[2] = 2.527;
	invariantBoundValue[3] = 3.756;
	invariantBoundValue[4] = -1.0;
	invariantBoundValue[5] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromboth_0;

	// The transition label isnull

	// Original guard: phi_ref = 2 * 3.14

	row = 2;
	col = 8;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 4) = -1.0;
	guardConstraintsMatrix(1, 4) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -6.28;
	guardBoundValue[1] = 6.28;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 8;
	col = 8;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(5, 5) = 2.0;
	R(6, 6) = 1.0;
	R(7, 7) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(2, "null", 2, 1, guard_polytope, assignment));

	Out_Going_Trans_fromboth_0.push_back(t);
	// The transition label isnull

	// Original guard: phi_v = 2 * 3.14

	row = 2;
	col = 8;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 3) = -1.0;
	guardConstraintsMatrix(1, 3) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -6.28;
	guardBoundValue[1] = 6.28;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 8;
	col = 8;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 4.0;
	R(6, 6) = 1.0;
	R(7, 7) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(3, "null", 2, 3, guard_polytope, assignment));

	Out_Going_Trans_fromboth_0.push_back(t);
	l = location::ptr(
			new location(2, "both_0", system_dynamics, invariant, true,
					Out_Going_Trans_fromboth_0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  dn_1

	row = 8;
	col = 8;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1, 1) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = -404000.0;
	C[1] = -8.015873015873016E7;
	C[3] = 1.691204E8;
	C[4] = 1.6956E8;
	C[6] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 8;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 4) = -1.0;
	invariantConstraintsMatrix(1, 4) = 1.0;
	invariantConstraintsMatrix(2, 3) = -1.0;
	invariantConstraintsMatrix(3, 3) = 1.0;
	invariantConstraintsMatrix(4, 5) = -1.0;
	invariantConstraintsMatrix(5, 5) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 6.283;
	invariantBoundValue[2] = 2.527;
	invariantBoundValue[3] = 3.756;
	invariantBoundValue[4] = -4.0;
	invariantBoundValue[5] = 4.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromdn_1;

	// The transition label isnull

	// Original guard: phi_ref = 0

	row = 2;
	col = 8;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 4) = -1.0;
	guardConstraintsMatrix(1, 4) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 8;
	col = 8;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	R(4, 4) = 1.0;
	R(5, 5) = 1.0;
	R(6, 6) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(4, "null", 3, 4, guard_polytope, assignment));

	Out_Going_Trans_fromdn_1.push_back(t);
	l = location::ptr(
			new location(3, "dn_1", system_dynamics, invariant, true,
					Out_Going_Trans_fromdn_1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  both_1

	row = 8;
	col = 8;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1, 1) = -1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[3] = 1.691204E8;
	C[4] = 1.6956E8;
	C[6] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 6;
	col = 8;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 4) = -1.0;
	invariantConstraintsMatrix(1, 4) = 1.0;
	invariantConstraintsMatrix(2, 3) = -1.0;
	invariantConstraintsMatrix(3, 3) = 1.0;
	invariantConstraintsMatrix(4, 5) = -1.0;
	invariantConstraintsMatrix(5, 5) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[1] = 6.283;
	invariantBoundValue[2] = 2.527;
	invariantBoundValue[3] = 3.756;
	invariantBoundValue[4] = -3.0;
	invariantBoundValue[5] = 3.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromboth_1;

	// The transition label isnull

	// Original guard: t = 0.00000000005

	row = 2;
	col = 8;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 7) = -1.0;
	guardConstraintsMatrix(1, 7) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -5.0E-11;
	guardBoundValue[1] = 5.0E-11;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 8;
	col = 8;
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
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(5, "null", 4, 2, guard_polytope, assignment));

	Out_Going_Trans_fromboth_1.push_back(t);
	l = location::ptr(
			new location(4, "both_1", system_dynamics, invariant, true,
					Out_Going_Trans_fromboth_1));
	Hybrid_Automata.addLocation(l);

	row = 16;
	col = 8;
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
	boundValueI.resize(row);
	boundValueI.assign(row, 0);
	boundValueI[0] = 0.35;
	boundValueI[1] = -0.35;
	boundValueI[6] = -2.5120000000000005;
	boundValueI[7] = 2.5120000000000005;
	boundValueI[10] = 1;
	boundValueI[11] = -1;

	initial_polytope_I0 = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id = 2;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I0, S0,
					transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);

	Hybrid_Automata.insert_to_map("v_i", 0);
	Hybrid_Automata.insert_to_map("v_p1", 1);
	Hybrid_Automata.insert_to_map("v_p", 2);
	Hybrid_Automata.insert_to_map("phi_v", 3);
	Hybrid_Automata.insert_to_map("phi_ref", 4);
	Hybrid_Automata.insert_to_map("mode", 5);
	Hybrid_Automata.insert_to_map("gt", 6);
	Hybrid_Automata.insert_to_map("t", 7);

}
