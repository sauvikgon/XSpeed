// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: Arch-Competition/TakeReading/HBMC/benchmark/fisher_star/fisher_star_3u.xml
// Command Line arguments: -t xspeed "" -o ./user_model.cpp -i Arch-Competition/TakeReading/HBMC/benchmark/fisher_star/fisher_star_3u.xml Arch-Competition/TakeReading/HBMC/benchmark/fisher_star/fisher_star_3u.cfg

#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/fisher_star.h"

void setFisher_Star(hybrid_automata& Hybrid_Automata,
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

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  s1_s1_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.5;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s1_s1_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "test_0_1", 1, 33, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s1_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(2, "test_0_2", 1, 7, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(3, "test_0_3", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s1_s0.push_back(t);
	l = location::ptr(
			new location(1, "s1_s1_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s1_s1_s0));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s1_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.5;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s1_s2_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(4, "test_0_1", 2, 34, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s2_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(5, "test_0_2", 2, 8, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(6, "set_3_3", 2, 4, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s2_s0.push_back(t);
	l = location::ptr(
			new location(2, "s1_s1_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s1_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s1_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s1_s3_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(7, "test_0_1", 3, 35, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s3_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(8, "test_0_2", 3, 9, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s3_s0.push_back(t);
	l = location::ptr(
			new location(3, "s1_s1_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s1_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s1_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s1_s3_s3;

	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(9, "test_3_3", 4, 6, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s3_s3.push_back(t);
	l = location::ptr(
			new location(4, "s1_s1_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s1_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s1_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s1_s4_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(10, "test_0_1", 5, 37, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s4_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(11, "test_0_2", 5, 11, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(12, "set_0_3", 5, 1, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s4_s0.push_back(t);
	l = location::ptr(
			new location(5, "s1_s1_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s1_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s1_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s1_s4_s3;

	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(13, "set_0_3", 6, 1, guard_polytope, assignment));

	Out_Going_Trans_froms1_s1_s4_s3.push_back(t);
	l = location::ptr(
			new location(6, "s1_s1_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s1_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s2_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s2_s1_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(14, "test_0_1", 7, 39, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s1_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(15, "set_2_2", 7, 14, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(16, "test_0_3", 7, 8, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s1_s0.push_back(t);
	l = location::ptr(
			new location(7, "s1_s2_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s2_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s2_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.1;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s2_s2_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(17, "test_0_1", 8, 40, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s2_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(18, "set_2_2", 8, 16, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(19, "set_3_3", 8, 10, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s2_s0.push_back(t);
	l = location::ptr(
			new location(8, "s1_s2_s2_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms1_s2_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s2_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s2_s3_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(20, "test_0_1", 9, 41, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s3_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(21, "set_2_2", 9, 18, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s3_s0.push_back(t);
	l = location::ptr(
			new location(9, "s1_s2_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s2_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s2_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s2_s3_s3;

	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(22, "set_2_2", 10, 18, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(23, "test_3_3", 10, 12, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s3_s3.push_back(t);
	l = location::ptr(
			new location(10, "s1_s2_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s2_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s2_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s2_s4_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(24, "test_0_1", 11, 43, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s4_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(25, "set_2_2", 11, 21, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(26, "set_0_3", 11, 7, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s4_s0.push_back(t);
	l = location::ptr(
			new location(11, "s1_s2_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s2_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s2_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s2_s4_s3;

	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(27, "set_2_2", 12, 21, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(28, "set_0_3", 12, 7, guard_polytope, assignment));

	Out_Going_Trans_froms1_s2_s4_s3.push_back(t);
	l = location::ptr(
			new location(12, "s1_s2_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s2_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s1_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(29, "test_0_1", 13, 45, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(30, "test_0_3", 13, 15, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s1_s0.push_back(t);
	l = location::ptr(
			new location(13, "s1_s3_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s1_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s1_s2;

	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(31, "test_2_2", 14, 24, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s1_s2.push_back(t);
	l = location::ptr(
			new location(14, "s1_s3_s1_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s1_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s2_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(32, "test_0_1", 15, 47, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(33, "set_3_3", 15, 19, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s2_s0.push_back(t);
	l = location::ptr(
			new location(15, "s1_s3_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s2_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s2_s2;

	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(34, "test_2_2", 16, 26, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s2_s2.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(35, "set_3_3", 16, 19, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s2_s2.push_back(t);
	l = location::ptr(
			new location(16, "s1_s3_s2_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s2_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s3_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(36, "test_0_1", 17, 49, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s3_s0.push_back(t);
	l = location::ptr(
			new location(17, "s1_s3_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s3_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s3_s2;

	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(37, "test_2_2", 18, 28, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s3_s2.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(38, "test_not_3_3", 18, 14, guard_polytope,
					assignment));

	Out_Going_Trans_froms1_s3_s3_s2.push_back(t);
	l = location::ptr(
			new location(18, "s1_s3_s3_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s3_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s3_s3;

	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(39, "test_not_2_2", 19, 4, guard_polytope,
					assignment));

	Out_Going_Trans_froms1_s3_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(40, "test_3_3", 19, 22, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s3_s3.push_back(t);
	l = location::ptr(
			new location(19, "s1_s3_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s4_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(41, "test_0_1", 20, 52, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(42, "set_0_3", 20, 13, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s4_s0.push_back(t);
	l = location::ptr(
			new location(20, "s1_s3_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s4_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s4_s2;

	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(43, "test_2_2", 21, 31, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s4_s2.push_back(t);
	l = location::ptr(
			new location(21, "s1_s3_s4_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s4_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s3_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s3_s4_s3;

	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(44, "test_not_2_2", 22, 6, guard_polytope,
					assignment));

	Out_Going_Trans_froms1_s3_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(45, "set_0_3", 22, 13, guard_polytope, assignment));

	Out_Going_Trans_froms1_s3_s4_s3.push_back(t);
	l = location::ptr(
			new location(22, "s1_s3_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s3_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s1_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(46, "test_0_1", 23, 55, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s1_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(47, "set_0_2", 23, 1, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(48, "test_0_3", 23, 25, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s1_s0.push_back(t);
	l = location::ptr(
			new location(23, "s1_s4_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s1_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s1_s2;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(49, "set_0_2", 24, 1, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s1_s2.push_back(t);
	l = location::ptr(
			new location(24, "s1_s4_s1_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s1_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s2_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(50, "test_0_1", 25, 57, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s2_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(51, "set_0_2", 25, 2, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(52, "set_3_3", 25, 29, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s2_s0.push_back(t);
	l = location::ptr(
			new location(25, "s1_s4_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s2_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s2_s2;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(53, "set_0_2", 26, 2, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s2_s2.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(54, "set_3_3", 26, 29, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s2_s2.push_back(t);
	l = location::ptr(
			new location(26, "s1_s4_s2_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s2_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s3_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(55, "test_0_1", 27, 59, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s3_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(56, "set_0_2", 27, 3, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s3_s0.push_back(t);
	l = location::ptr(
			new location(27, "s1_s4_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s3_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s3_s2;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(57, "set_0_2", 28, 3, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s3_s2.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(58, "test_not_3_3", 28, 24, guard_polytope,
					assignment));

	Out_Going_Trans_froms1_s4_s3_s2.push_back(t);
	l = location::ptr(
			new location(28, "s1_s4_s3_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s3_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s3_s3;

	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(59, "test_3_3", 29, 32, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s3_s3.push_back(t);
	l = location::ptr(
			new location(29, "s1_s4_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s4_s0;

	// The transition label is test_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(60, "test_0_1", 30, 62, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s4_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(61, "set_0_2", 30, 5, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(62, "set_0_3", 30, 23, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s4_s0.push_back(t);
	l = location::ptr(
			new location(30, "s1_s4_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s4_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s4_s2;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(63, "set_0_2", 31, 5, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s4_s2.push_back(t);
	l = location::ptr(
			new location(31, "s1_s4_s4_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s4_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s1_s4_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.5;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms1_s4_s4_s3;

	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(64, "set_0_3", 32, 23, guard_polytope, assignment));

	Out_Going_Trans_froms1_s4_s4_s3.push_back(t);
	l = location::ptr(
			new location(32, "s1_s4_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms1_s4_s4_s3));
	Hybrid_Automata.addLocation(l);

	FStarModule1(Hybrid_Automata, init_state_list, reach_parameters);
	FStarModule2(Hybrid_Automata, init_state_list, reach_parameters);
	FStarModule3(Hybrid_Automata, init_state_list, reach_parameters);
	FStarModule4(Hybrid_Automata, init_state_list, reach_parameters);

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

	Hybrid_Automata.insert_to_map("process1_x", 0);
	Hybrid_Automata.insert_to_map("process2_x", 1);
	Hybrid_Automata.insert_to_map("process3_x", 2);
	Hybrid_Automata.insert_to_map("sv_x", 3);


}

void FStarModule1(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  s2_s1_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.5;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s1_s1_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(65, "set_1_1", 33, 66, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s1_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(66, "test_0_2", 33, 39, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(67, "test_0_3", 33, 34, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s1_s0.push_back(t);
	l = location::ptr(
			new location(33, "s2_s1_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s1_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s1_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.5;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s1_s2_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(68, "set_1_1", 34, 68, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s2_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(69, "test_0_2", 34, 40, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(70, "set_3_3", 34, 36, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s2_s0.push_back(t);
	l = location::ptr(
			new location(34, "s2_s1_s2_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s1_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s1_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s1_s3_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(71, "set_1_1", 35, 70, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s3_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(72, "test_0_2", 35, 41, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s3_s0.push_back(t);
	l = location::ptr(
			new location(35, "s2_s1_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s1_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s1_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s1_s3_s3;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(73, "set_1_1", 36, 70, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(74, "test_3_3", 36, 38, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s3_s3.push_back(t);
	l = location::ptr(
			new location(36, "s2_s1_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s1_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s1_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s1_s4_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(75, "set_1_1", 37, 73, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s4_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(76, "test_0_2", 37, 43, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(77, "set_0_3", 37, 33, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s4_s0.push_back(t);
	l = location::ptr(
			new location(37, "s2_s1_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s1_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s1_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s1_s4_s3;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(78, "set_1_1", 38, 73, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(79, "set_0_3", 38, 33, guard_polytope, assignment));

	Out_Going_Trans_froms2_s1_s4_s3.push_back(t);
	l = location::ptr(
			new location(38, "s2_s1_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s1_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s2_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s2_s1_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(80, "set_1_1", 39, 76, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s1_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(81, "set_2_2", 39, 46, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(82, "test_0_3", 39, 40, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s1_s0.push_back(t);
	l = location::ptr(
			new location(39, "s2_s2_s1_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s2_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s2_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.1;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 3;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 1.0;
	invariantConstraintsMatrix(2, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s2_s2_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(83, "set_1_1", 40, 78, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s2_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(84, "set_2_2", 40, 48, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(85, "set_3_3", 40, 42, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s2_s0.push_back(t);
	l = location::ptr(
			new location(40, "s2_s2_s2_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s2_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s2_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s2_s3_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(86, "set_1_1", 41, 80, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s3_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(87, "set_2_2", 41, 50, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s3_s0.push_back(t);
	l = location::ptr(
			new location(41, "s2_s2_s3_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s2_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s2_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s2_s3_s3;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(88, "set_1_1", 42, 80, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s3_s3.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(89, "set_2_2", 42, 50, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(90, "test_3_3", 42, 44, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s3_s3.push_back(t);
	l = location::ptr(
			new location(42, "s2_s2_s3_s3", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s2_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s2_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s2_s4_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(91, "set_1_1", 43, 83, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s4_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(92, "set_2_2", 43, 53, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(93, "set_0_3", 43, 39, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s4_s0.push_back(t);
	l = location::ptr(
			new location(43, "s2_s2_s4_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s2_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s2_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s2_s4_s3;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(94, "set_1_1", 44, 83, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s4_s3.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(95, "set_2_2", 44, 53, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(96, "set_0_3", 44, 39, guard_polytope, assignment));

	Out_Going_Trans_froms2_s2_s4_s3.push_back(t);
	l = location::ptr(
			new location(44, "s2_s2_s4_s3", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s2_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s1_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(97, "set_1_1", 45, 86, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(98, "test_0_3", 45, 47, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s1_s0.push_back(t);
	l = location::ptr(
			new location(45, "s2_s3_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s3_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s1_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s1_s2;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(99, "set_1_1", 46, 86, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s1_s2.push_back(t);
	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(100, "test_2_2", 46, 56, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s3_s1_s2.push_back(t);
	l = location::ptr(
			new location(46, "s2_s3_s1_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s3_s1_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s2_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(101, "set_1_1", 47, 89, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(102, "set_3_3", 47, 51, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s2_s0.push_back(t);
	l = location::ptr(
			new location(47, "s2_s3_s2_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s3_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s2_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s2_s2;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(103, "set_1_1", 48, 89, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s2_s2.push_back(t);
	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(104, "test_2_2", 48, 58, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s3_s2_s2.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(105, "set_3_3", 48, 51, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s2_s2.push_back(t);
	l = location::ptr(
			new location(48, "s2_s3_s2_s2", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s3_s2_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s3_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(106, "set_1_1", 49, 91, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s3_s0.push_back(t);
	l = location::ptr(
			new location(49, "s2_s3_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s3_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s3_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s3_s2;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(107, "set_1_1", 50, 91, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s3_s2.push_back(t);
	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(108, "test_2_2", 50, 60, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s3_s3_s2.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(109, "test_not_3_3", 50, 46, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s3_s3_s2.push_back(t);
	l = location::ptr(
			new location(50, "s2_s3_s3_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s3_s3_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s3_s3;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(110, "set_1_1", 51, 91, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s3_s3.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(111, "test_not_2_2", 51, 36, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s3_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(112, "test_3_3", 51, 54, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s3_s3_s3.push_back(t);
	l = location::ptr(
			new location(51, "s2_s3_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s3_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s4_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(113, "set_1_1", 52, 94, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(114, "set_0_3", 52, 45, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s4_s0.push_back(t);
	l = location::ptr(
			new location(52, "s2_s3_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s3_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s4_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s4_s2;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(115, "set_1_1", 53, 94, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s4_s2.push_back(t);
	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(116, "test_2_2", 53, 63, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s3_s4_s2.push_back(t);
	l = location::ptr(
			new location(53, "s2_s3_s4_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s3_s4_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s3_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s3_s4_s3;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(117, "set_1_1", 54, 94, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s4_s3.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(118, "test_not_2_2", 54, 38, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s3_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(119, "set_0_3", 54, 45, guard_polytope, assignment));

	Out_Going_Trans_froms2_s3_s4_s3.push_back(t);
	l = location::ptr(
			new location(54, "s2_s3_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s3_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s1_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(120, "set_1_1", 55, 98, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s1_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(121, "set_0_2", 55, 33, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(122, "test_0_3", 55, 57, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s1_s0.push_back(t);
	l = location::ptr(
			new location(55, "s2_s4_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s4_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s1_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s1_s2;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(123, "set_1_1", 56, 98, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s1_s2.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(124, "set_0_2", 56, 33, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s1_s2.push_back(t);
	l = location::ptr(
			new location(56, "s2_s4_s1_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s4_s1_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s2_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(125, "set_1_1", 57, 101, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s2_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(126, "set_0_2", 57, 34, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(127, "set_3_3", 57, 61, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s2_s0.push_back(t);
	l = location::ptr(
			new location(57, "s2_s4_s2_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s4_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s2_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s2_s2;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(128, "set_1_1", 58, 101, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s2_s2.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(129, "set_0_2", 58, 34, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s2_s2.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(130, "set_3_3", 58, 61, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s2_s2.push_back(t);
	l = location::ptr(
			new location(58, "s2_s4_s2_s2", system_dynamics, invariant, true,
					Out_Going_Trans_froms2_s4_s2_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s3_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(131, "set_1_1", 59, 103, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s3_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(132, "set_0_2", 59, 35, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s3_s0.push_back(t);
	l = location::ptr(
			new location(59, "s2_s4_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s4_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s3_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s3_s2;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(133, "set_1_1", 60, 103, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s3_s2.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(134, "set_0_2", 60, 35, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s3_s2.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(135, "test_not_3_3", 60, 56, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s3_s2.push_back(t);
	l = location::ptr(
			new location(60, "s2_s4_s3_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s4_s3_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s3_s3;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(136, "set_1_1", 61, 103, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(137, "test_3_3", 61, 64, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s3_s3.push_back(t);
	l = location::ptr(
			new location(61, "s2_s4_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s4_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s4_s0;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(138, "set_1_1", 62, 106, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s4_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(139, "set_0_2", 62, 37, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(140, "set_0_3", 62, 55, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s4_s0.push_back(t);
	l = location::ptr(
			new location(62, "s2_s4_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s4_s4_s0));
	Hybrid_Automata.addLocation(l);

}

void FStarModule2(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  s2_s4_s4_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s4_s2;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(141, "set_1_1", 63, 106, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s4_s2.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(142, "set_0_2", 63, 37, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s4_s2.push_back(t);
	l = location::ptr(
			new location(63, "s2_s4_s4_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s4_s4_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s2_s4_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.1;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms2_s4_s4_s3;

	// The transition label is set_1_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(143, "set_1_1", 64, 106, guard_polytope,
					assignment));

	Out_Going_Trans_froms2_s4_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(144, "set_0_3", 64, 55, guard_polytope, assignment));

	Out_Going_Trans_froms2_s4_s4_s3.push_back(t);
	l = location::ptr(
			new location(64, "s2_s4_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms2_s4_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s1_s0;

	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(145, "test_0_2", 65, 75, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(146, "test_0_3", 65, 67, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s1_s0.push_back(t);
	l = location::ptr(
			new location(65, "s3_s1_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s1_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s1_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(147, "test_1_1", 66, 110, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s1_s1.push_back(t);
	l = location::ptr(
			new location(66, "s3_s1_s1_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s1_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s2_s0;

	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(148, "test_0_2", 67, 77, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(149, "set_3_3", 67, 71, guard_polytope, assignment));

	Out_Going_Trans_froms3_s1_s2_s0.push_back(t);
	l = location::ptr(
			new location(67, "s3_s1_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s2_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s2_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(150, "test_1_1", 68, 112, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s2_s1.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(151, "set_3_3", 68, 71, guard_polytope, assignment));

	Out_Going_Trans_froms3_s1_s2_s1.push_back(t);
	l = location::ptr(
			new location(68, "s3_s1_s2_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s2_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s3_s0;

	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(152, "test_0_2", 69, 79, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s3_s0.push_back(t);
	l = location::ptr(
			new location(69, "s3_s1_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s3_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s3_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(153, "test_1_1", 70, 114, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s3_s1.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(154, "test_not_3_3", 70, 66, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s3_s1.push_back(t);
	l = location::ptr(
			new location(70, "s3_s1_s3_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s3_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s3_s3;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(155, "test_not_1_1", 71, 4, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(156, "test_3_3", 71, 74, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s3_s3.push_back(t);
	l = location::ptr(
			new location(71, "s3_s1_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s4_s0;

	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(157, "test_0_2", 72, 82, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(158, "set_0_3", 72, 65, guard_polytope, assignment));

	Out_Going_Trans_froms3_s1_s4_s0.push_back(t);
	l = location::ptr(
			new location(72, "s3_s1_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s4_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s4_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(159, "test_1_1", 73, 117, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s4_s1.push_back(t);
	l = location::ptr(
			new location(73, "s3_s1_s4_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s4_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s1_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s1_s4_s3;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(160, "test_not_1_1", 74, 6, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s1_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(161, "set_0_3", 74, 65, guard_polytope, assignment));

	Out_Going_Trans_froms3_s1_s4_s3.push_back(t);
	l = location::ptr(
			new location(74, "s3_s1_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s1_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s1_s0;

	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(162, "set_2_2", 75, 87, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(163, "test_0_3", 75, 77, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s1_s0.push_back(t);
	l = location::ptr(
			new location(75, "s3_s2_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s2_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s1_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s1_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(164, "test_1_1", 76, 120, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s1_s1.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(165, "set_2_2", 76, 87, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s1_s1.push_back(t);
	l = location::ptr(
			new location(76, "s3_s2_s1_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s2_s1_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s2_s0;

	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(166, "set_2_2", 77, 90, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(167, "set_3_3", 77, 81, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s2_s0.push_back(t);
	l = location::ptr(
			new location(77, "s3_s2_s2_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms3_s2_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s2_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s2_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(168, "test_1_1", 78, 122, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s2_s1.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(169, "set_2_2", 78, 90, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s2_s1.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(170, "set_3_3", 78, 81, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s2_s1.push_back(t);
	l = location::ptr(
			new location(78, "s3_s2_s2_s1", system_dynamics, invariant, true,
					Out_Going_Trans_froms3_s2_s2_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s3_s0;

	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(171, "set_2_2", 79, 92, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s3_s0.push_back(t);
	l = location::ptr(
			new location(79, "s3_s2_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s2_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s3_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s3_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(172, "test_1_1", 80, 124, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s3_s1.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(173, "set_2_2", 80, 92, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s3_s1.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(174, "test_not_3_3", 80, 76, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s3_s1.push_back(t);
	l = location::ptr(
			new location(80, "s3_s2_s3_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s2_s3_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s3_s3;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(175, "test_not_1_1", 81, 10, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s3_s3.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(176, "set_2_2", 81, 92, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(177, "test_3_3", 81, 84, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s3_s3.push_back(t);
	l = location::ptr(
			new location(81, "s3_s2_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s2_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s4_s0;

	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(178, "set_2_2", 82, 95, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(179, "set_0_3", 82, 75, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s4_s0.push_back(t);
	l = location::ptr(
			new location(82, "s3_s2_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s2_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s4_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s4_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(180, "test_1_1", 83, 127, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s4_s1.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(181, "set_2_2", 83, 95, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s4_s1.push_back(t);
	l = location::ptr(
			new location(83, "s3_s2_s4_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s2_s4_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s2_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s2_s4_s3;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(182, "test_not_1_1", 84, 12, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s2_s4_s3.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(183, "set_2_2", 84, 95, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(184, "set_0_3", 84, 75, guard_polytope, assignment));

	Out_Going_Trans_froms3_s2_s4_s3.push_back(t);
	l = location::ptr(
			new location(84, "s3_s2_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s2_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s1_s0;

	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(185, "test_0_3", 85, 88, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s1_s0.push_back(t);
	l = location::ptr(
			new location(85, "s3_s3_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s1_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s1_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(186, "test_1_1", 86, 130, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s1_s1.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(187, "test_not_2_2", 86, 66, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s1_s1.push_back(t);
	l = location::ptr(
			new location(86, "s3_s3_s1_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s1_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s1_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s1_s2;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(188, "test_not_1_1", 87, 14, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s1_s2.push_back(t);
	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(189, "test_2_2", 87, 99, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s1_s2.push_back(t);
	l = location::ptr(
			new location(87, "s3_s3_s1_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s1_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s2_s0;

	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(190, "set_3_3", 88, 93, guard_polytope, assignment));

	Out_Going_Trans_froms3_s3_s2_s0.push_back(t);
	l = location::ptr(
			new location(88, "s3_s3_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s2_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s2_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(191, "test_1_1", 89, 133, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s2_s1.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(192, "test_not_2_2", 89, 68, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s2_s1.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(193, "set_3_3", 89, 93, guard_polytope, assignment));

	Out_Going_Trans_froms3_s3_s2_s1.push_back(t);
	l = location::ptr(
			new location(89, "s3_s3_s2_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s2_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s2_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s2_s2;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(194, "test_not_1_1", 90, 16, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s2_s2.push_back(t);
	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(195, "test_2_2", 90, 102, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s2_s2.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(196, "set_3_3", 90, 93, guard_polytope, assignment));

	Out_Going_Trans_froms3_s3_s2_s2.push_back(t);
	l = location::ptr(
			new location(90, "s3_s3_s2_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s2_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s3_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s3_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(197, "test_1_1", 91, 135, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s1.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(198, "test_not_2_2", 91, 70, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s1.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(199, "test_not_3_3", 91, 86, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s1.push_back(t);
	l = location::ptr(
			new location(91, "s3_s3_s3_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s3_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s3_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s3_s2;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(200, "test_not_1_1", 92, 18, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s2.push_back(t);
	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(201, "test_2_2", 92, 104, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s2.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(202, "test_not_3_3", 92, 87, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s2.push_back(t);
	l = location::ptr(
			new location(92, "s3_s3_s3_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s3_s2));
	Hybrid_Automata.addLocation(l);

}

void FStarModule3(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  s3_s3_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s3_s3;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
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
			new transition(203, "test_not_1_1", 93, 19, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s3.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(204, "test_not_2_2", 93, 71, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(205, "test_3_3", 93, 96, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s3_s3.push_back(t);
	l = location::ptr(
			new location(93, "s3_s3_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s4_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s4_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(206, "test_1_1", 94, 138, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s4_s1.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(207, "test_not_2_2", 94, 73, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s4_s1.push_back(t);
	l = location::ptr(
			new location(94, "s3_s3_s4_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s4_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s4_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s4_s2;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(208, "test_not_1_1", 95, 21, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s4_s2.push_back(t);
	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(209, "test_2_2", 95, 107, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s4_s2.push_back(t);
	l = location::ptr(
			new location(95, "s3_s3_s4_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s4_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s3_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s3_s4_s3;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(210, "test_not_1_1", 96, 22, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s4_s3.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(211, "test_not_2_2", 96, 74, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s3_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(212, "set_0_3", 96, 85, guard_polytope, assignment));

	Out_Going_Trans_froms3_s3_s4_s3.push_back(t);
	l = location::ptr(
			new location(96, "s3_s3_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s3_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s1_s0;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(213, "set_0_2", 97, 65, guard_polytope, assignment));

	Out_Going_Trans_froms3_s4_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(214, "test_0_3", 97, 100, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s1_s0.push_back(t);
	l = location::ptr(
			new location(97, "s3_s4_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s1_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s1_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(215, "test_1_1", 98, 142, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s1_s1.push_back(t);
	l = location::ptr(
			new location(98, "s3_s4_s1_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s1_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s1_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s1_s2;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(216, "test_not_1_1", 99, 24, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s1_s2.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(217, "set_0_2", 99, 65, guard_polytope, assignment));

	Out_Going_Trans_froms3_s4_s1_s2.push_back(t);
	l = location::ptr(
			new location(99, "s3_s4_s1_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s1_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s2_s0;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(218, "set_0_2", 100, 67, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(219, "set_3_3", 100, 105, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s2_s0.push_back(t);
	l = location::ptr(
			new location(100, "s3_s4_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s2_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s2_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(220, "test_1_1", 101, 145, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s2_s1.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(221, "set_3_3", 101, 105, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s2_s1.push_back(t);
	l = location::ptr(
			new location(101, "s3_s4_s2_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s2_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s2_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s2_s2;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(222, "test_not_1_1", 102, 26, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s2_s2.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(223, "set_0_2", 102, 67, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s2_s2.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(224, "set_3_3", 102, 105, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s2_s2.push_back(t);
	l = location::ptr(
			new location(102, "s3_s4_s2_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s2_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s3_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s3_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(225, "test_1_1", 103, 147, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s3_s1.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(226, "test_not_3_3", 103, 98, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s3_s1.push_back(t);
	l = location::ptr(
			new location(103, "s3_s4_s3_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s3_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s3_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s3_s2;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(227, "test_not_1_1", 104, 28, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s3_s2.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(228, "set_0_2", 104, 69, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s3_s2.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(229, "test_not_3_3", 104, 99, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s3_s2.push_back(t);
	l = location::ptr(
			new location(104, "s3_s4_s3_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s3_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s3_s3;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(230, "test_not_1_1", 105, 29, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(231, "test_3_3", 105, 108, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s3_s3.push_back(t);
	l = location::ptr(
			new location(105, "s3_s4_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s4_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s4_s1;

	// The transition label is test_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(232, "test_1_1", 106, 150, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s4_s1.push_back(t);
	l = location::ptr(
			new location(106, "s3_s4_s4_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s4_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s4_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s4_s2;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(233, "test_not_1_1", 107, 31, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s4_s2.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(234, "set_0_2", 107, 72, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s4_s2.push_back(t);
	l = location::ptr(
			new location(107, "s3_s4_s4_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s4_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s3_s4_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 1.8;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms3_s4_s4_s3;

	// The transition label is test_not_1_1

	// Original guard: process1_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(235, "test_not_1_1", 108, 32, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(236, "set_0_3", 108, 97, guard_polytope,
					assignment));

	Out_Going_Trans_froms3_s4_s4_s3.push_back(t);
	l = location::ptr(
			new location(108, "s3_s4_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms3_s4_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s1_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(237, "set_0_1", 109, 1, guard_polytope, assignment));

	Out_Going_Trans_froms4_s1_s1_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(238, "test_0_2", 109, 119, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(239, "test_0_3", 109, 111, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s1_s0.push_back(t);
	l = location::ptr(
			new location(109, "s4_s1_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s1_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s1_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(240, "set_0_1", 110, 1, guard_polytope, assignment));

	Out_Going_Trans_froms4_s1_s1_s1.push_back(t);
	l = location::ptr(
			new location(110, "s4_s1_s1_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s1_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s2_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(241, "set_0_1", 111, 2, guard_polytope, assignment));

	Out_Going_Trans_froms4_s1_s2_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(242, "test_0_2", 111, 121, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(243, "set_3_3", 111, 115, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s2_s0.push_back(t);
	l = location::ptr(
			new location(111, "s4_s1_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s2_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s2_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(244, "set_0_1", 112, 2, guard_polytope, assignment));

	Out_Going_Trans_froms4_s1_s2_s1.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(245, "set_3_3", 112, 115, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s2_s1.push_back(t);
	l = location::ptr(
			new location(112, "s4_s1_s2_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s2_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s3_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(246, "set_0_1", 113, 3, guard_polytope, assignment));

	Out_Going_Trans_froms4_s1_s3_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(247, "test_0_2", 113, 123, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s3_s0.push_back(t);
	l = location::ptr(
			new location(113, "s4_s1_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s3_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s3_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(248, "set_0_1", 114, 3, guard_polytope, assignment));

	Out_Going_Trans_froms4_s1_s3_s1.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(249, "test_not_3_3", 114, 110, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s3_s1.push_back(t);
	l = location::ptr(
			new location(114, "s4_s1_s3_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s3_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s3_s3;

	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(250, "test_3_3", 115, 118, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s3_s3.push_back(t);
	l = location::ptr(
			new location(115, "s4_s1_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s4_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(251, "set_0_1", 116, 5, guard_polytope, assignment));

	Out_Going_Trans_froms4_s1_s4_s0.push_back(t);
	// The transition label is test_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(252, "test_0_2", 116, 126, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(253, "set_0_3", 116, 109, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s4_s0.push_back(t);
	l = location::ptr(
			new location(116, "s4_s1_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s4_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s4_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(254, "set_0_1", 117, 5, guard_polytope, assignment));

	Out_Going_Trans_froms4_s1_s4_s1.push_back(t);
	l = location::ptr(
			new location(117, "s4_s1_s4_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s4_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s1_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.5;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s1_s4_s3;

	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(255, "set_0_3", 118, 109, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s1_s4_s3.push_back(t);
	l = location::ptr(
			new location(118, "s4_s1_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s1_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s1_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(256, "set_0_1", 119, 7, guard_polytope, assignment));

	Out_Going_Trans_froms4_s2_s1_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(257, "set_2_2", 119, 131, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(258, "test_0_3", 119, 121, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s1_s0.push_back(t);
	l = location::ptr(
			new location(119, "s4_s2_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s2_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s1_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s1_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(259, "set_0_1", 120, 7, guard_polytope, assignment));

	Out_Going_Trans_froms4_s2_s1_s1.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(260, "set_2_2", 120, 131, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s1_s1.push_back(t);
	l = location::ptr(
			new location(120, "s4_s2_s1_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s2_s1_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s2_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(261, "set_0_1", 121, 8, guard_polytope, assignment));

	Out_Going_Trans_froms4_s2_s2_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(262, "set_2_2", 121, 134, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(263, "set_3_3", 121, 125, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s2_s0.push_back(t);
	l = location::ptr(
			new location(121, "s4_s2_s2_s0", system_dynamics, invariant, true,
					Out_Going_Trans_froms4_s2_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s2_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 2;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;
	invariantConstraintsMatrix(1, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariantBoundValue[1] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s2_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(264, "set_0_1", 122, 8, guard_polytope, assignment));

	Out_Going_Trans_froms4_s2_s2_s1.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(265, "set_2_2", 122, 134, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s2_s1.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(266, "set_3_3", 122, 125, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s2_s1.push_back(t);
	l = location::ptr(
			new location(122, "s4_s2_s2_s1", system_dynamics, invariant, true,
					Out_Going_Trans_froms4_s2_s2_s1));
	Hybrid_Automata.addLocation(l);

}

void FStarModule4(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  s4_s2_s3_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s3_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

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
			new transition(267, "set_0_1", 123, 9, guard_polytope, assignment));

	Out_Going_Trans_froms4_s2_s3_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(268, "set_2_2", 123, 136, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s3_s0.push_back(t);
	l = location::ptr(
			new location(123, "s4_s2_s3_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s2_s3_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s3_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s3_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(269, "set_0_1", 124, 9, guard_polytope, assignment));

	Out_Going_Trans_froms4_s2_s3_s1.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(270, "set_2_2", 124, 136, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s3_s1.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(271, "test_not_3_3", 124, 120, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s3_s1.push_back(t);
	l = location::ptr(
			new location(124, "s4_s2_s3_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s2_s3_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s3_s3;

	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(272, "set_2_2", 125, 136, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(273, "test_3_3", 125, 128, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s3_s3.push_back(t);
	l = location::ptr(
			new location(125, "s4_s2_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s2_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s4_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s4_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(274, "set_0_1", 126, 11, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s4_s0.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(275, "set_2_2", 126, 139, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s4_s0.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(276, "set_0_3", 126, 119, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s4_s0.push_back(t);
	l = location::ptr(
			new location(126, "s4_s2_s4_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s2_s4_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s4_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s4_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(277, "set_0_1", 127, 11, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s4_s1.push_back(t);
	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(278, "set_2_2", 127, 139, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s4_s1.push_back(t);
	l = location::ptr(
			new location(127, "s4_s2_s4_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s2_s4_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s2_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.1;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 1) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s2_s4_s3;

	// The transition label is set_2_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(279, "set_2_2", 128, 139, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(280, "set_0_3", 128, 119, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s2_s4_s3.push_back(t);
	l = location::ptr(
			new location(128, "s4_s2_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s2_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s1_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(281, "set_0_1", 129, 13, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(282, "test_0_3", 129, 132, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s1_s0.push_back(t);
	l = location::ptr(
			new location(129, "s4_s3_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s1_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s1_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(283, "set_0_1", 130, 13, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s1_s1.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(284, "test_not_2_2", 130, 110, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s1_s1.push_back(t);
	l = location::ptr(
			new location(130, "s4_s3_s1_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s1_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s1_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s1_s2;

	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(285, "test_2_2", 131, 143, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s1_s2.push_back(t);
	l = location::ptr(
			new location(131, "s4_s3_s1_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s1_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s2_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(286, "set_0_1", 132, 15, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(287, "set_3_3", 132, 137, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s2_s0.push_back(t);
	l = location::ptr(
			new location(132, "s4_s3_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s2_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s2_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(288, "set_0_1", 133, 15, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s2_s1.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(289, "test_not_2_2", 133, 112, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s2_s1.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(290, "set_3_3", 133, 137, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s2_s1.push_back(t);
	l = location::ptr(
			new location(133, "s4_s3_s2_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s2_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s2_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s2_s2;

	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(291, "test_2_2", 134, 146, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s2_s2.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(292, "set_3_3", 134, 137, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s2_s2.push_back(t);
	l = location::ptr(
			new location(134, "s4_s3_s2_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s2_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s3_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s3_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(293, "set_0_1", 135, 17, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s3_s1.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(294, "test_not_2_2", 135, 114, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s3_s1.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(295, "test_not_3_3", 135, 130, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s3_s1.push_back(t);
	l = location::ptr(
			new location(135, "s4_s3_s3_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s3_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s3_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s3_s2;

	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(296, "test_2_2", 136, 148, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s3_s2.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(297, "test_not_3_3", 136, 131, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s3_s2.push_back(t);
	l = location::ptr(
			new location(136, "s4_s3_s3_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s3_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s3_s3;

	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(298, "test_not_2_2", 137, 115, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s3_s3.push_back(t);
	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(299, "test_3_3", 137, 140, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s3_s3.push_back(t);
	l = location::ptr(
			new location(137, "s4_s3_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s4_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s4_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(300, "set_0_1", 138, 20, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s4_s1.push_back(t);
	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(301, "test_not_2_2", 138, 117, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s4_s1.push_back(t);
	l = location::ptr(
			new location(138, "s4_s3_s4_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s4_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s4_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s4_s2;

	// The transition label is test_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(302, "test_2_2", 139, 151, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s4_s2.push_back(t);
	l = location::ptr(
			new location(139, "s4_s3_s4_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s4_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s3_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 1.8;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s3_s4_s3;

	// The transition label is test_not_2_2

	// Original guard: process2_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(303, "test_not_2_2", 140, 118, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s4_s3.push_back(t);
	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(304, "set_0_3", 140, 129, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s3_s4_s3.push_back(t);
	l = location::ptr(
			new location(140, "s4_s3_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s3_s4_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s1_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s1_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(305, "set_0_1", 141, 23, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s1_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(306, "set_0_2", 141, 109, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s1_s0.push_back(t);
	// The transition label is test_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(307, "test_0_3", 141, 144, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s1_s0.push_back(t);
	l = location::ptr(
			new location(141, "s4_s4_s1_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s1_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s1_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s1_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(308, "set_0_1", 142, 23, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s1_s1.push_back(t);
	l = location::ptr(
			new location(142, "s4_s4_s1_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s1_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s1_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 1.5;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s1_s2;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(309, "set_0_2", 143, 109, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s1_s2.push_back(t);
	l = location::ptr(
			new location(143, "s4_s4_s1_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s1_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s2_s0

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s2_s0;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(310, "set_0_1", 144, 25, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s2_s0.push_back(t);
	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(311, "set_0_2", 144, 111, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s2_s0.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(312, "set_3_3", 144, 149, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s2_s0.push_back(t);
	l = location::ptr(
			new location(144, "s4_s4_s2_s0", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s2_s0));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s2_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s2_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(313, "set_0_1", 145, 25, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s2_s1.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(314, "set_3_3", 145, 149, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s2_s1.push_back(t);
	l = location::ptr(
			new location(145, "s4_s4_s2_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s2_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s2_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 2.1;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	row = 1;
	col = 4;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 2) = 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariantBoundValue[0] = 1.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s2_s2;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(315, "set_0_2", 146, 111, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s2_s2.push_back(t);
	// The transition label is set_3_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(316, "set_3_3", 146, 149, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s2_s2.push_back(t);
	l = location::ptr(
			new location(146, "s4_s4_s2_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s2_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s3_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s3_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(317, "set_0_1", 147, 27, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s3_s1.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(318, "test_not_3_3", 147, 142, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s3_s1.push_back(t);
	l = location::ptr(
			new location(147, "s4_s4_s3_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s3_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s3_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s3_s2;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(319, "set_0_2", 148, 113, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s3_s2.push_back(t);
	// The transition label is test_not_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(320, "test_not_3_3", 148, 143, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s3_s2.push_back(t);
	l = location::ptr(
			new location(148, "s4_s4_s3_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s3_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s3_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 1.8;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s3_s3;

	// The transition label is test_3_3

	// Original guard: process3_x > 3

	row = 1;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -3.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(321, "test_3_3", 149, 152, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s3_s3.push_back(t);
	l = location::ptr(
			new location(149, "s4_s4_s3_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s3_s3));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s4_s1

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s4_s1;

	// The transition label is set_0_1

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(322, "set_0_1", 150, 30, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s4_s1.push_back(t);
	l = location::ptr(
			new location(150, "s4_s4_s4_s1", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s4_s1));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s4_s2

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s4_s2;

	// The transition label is set_0_2

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(323, "set_0_2", 151, 116, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s4_s2.push_back(t);
	l = location::ptr(
			new location(151, "s4_s4_s4_s2", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s4_s2));
	Hybrid_Automata.addLocation(l);

	// The mode name is  s4_s4_s4_s3

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[0] = 2.2;
	C[1] = 2.2;
	C[2] = 2.2;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

	std::list<transition::ptr> Out_Going_Trans_froms4_s4_s4_s3;

	// The transition label is set_0_3

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope->setIsUniverse(true);

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(324, "set_0_3", 152, 141, guard_polytope,
					assignment));

	Out_Going_Trans_froms4_s4_s4_s3.push_back(t);
	l = location::ptr(
			new location(152, "s4_s4_s4_s3", system_dynamics, invariant, false,
					Out_Going_Trans_froms4_s4_s4_s3));
	Hybrid_Automata.addLocation(l);

}
