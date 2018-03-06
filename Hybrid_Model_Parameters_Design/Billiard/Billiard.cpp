/*
 * Billiard.cpp
 *
 *  Created on: 15-Feb-2018
 *      Author: amit
 */

#include "Billiard.h"

void SetBilliardModel(hybrid_automata& Hybrid_Automata,
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

	// The mode name is  board

	row = 4;
	col = 4;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 2) = 1.0;
	Amatrix(1, 3) = 1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[2] = 0.9;
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
	invariantBoundValue[1] = 10.0;
	invariantBoundValue[3] = 10.0;
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));

	std::list<transition::ptr> Out_Going_Trans_fromboard;

	// The transition label is wall_y1

	// Original guard: 0.1 <= x & x <= 9.9 & 10 <= y & y <= 10

	row = 4;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -0.1;
	guardBoundValue[1] = -10.0;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 1) = -1.0;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "wall_y1", 1, 1, guard_polytope, assignment));

	Out_Going_Trans_fromboard.push_back(t);
	// The transition label is wall_x2

	// Original guard: 10 <= x & x <= 10 & 0.1 <= y & y <= 9.9

	row = 4;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -10.0;
	guardBoundValue[1] = -0.1;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 0) = -1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(2, "wall_x2", 1, 1, guard_polytope, assignment));

	Out_Going_Trans_fromboard.push_back(t);
	// The transition label is wall_y2

	// Original guard: 0.1 <= x & x <= 9.9 & 0 <= y & y <= 0

	row = 4;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -0.1;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = 1.0;
	R(3, 3) = -1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(3, "wall_y2", 1, 1, guard_polytope, assignment));

	Out_Going_Trans_fromboard.push_back(t);
	// The transition label is wall_x1

	// Original guard: 0 <= x & x <= 0 & 0.1 <= y & y <= 9.9

	row = 4;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = -0.1;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	R(2, 2) = -1.0;
	R(3, 3) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(4, "wall_x1", 1, 1, guard_polytope, assignment));

	Out_Going_Trans_fromboard.push_back(t);
	// The transition label is t1

	// Original guard: 0 <= x & x <= 0.1 & 0 <= y & y <= 0.1

	row = 4;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 1) = -1.0;

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
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(5, "t1", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromboard.push_back(t);
	// The transition label is t2

	// Original guard: 0 <= x & x <= 0.1 & 9.9 <= y & y <= 10

	row = 4;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[1] = -9.9;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(6, "t2", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromboard.push_back(t);
	// The transition label is t3

	// Original guard: 9.9 <= x & x <= 10 & 9.9 <= y & y <= 10

	row = 4;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -9.9;
	guardBoundValue[1] = -9.9;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(7, "t3", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromboard.push_back(t);
	// The transition label is t4

	// Original guard: 9.9 <= x & x <= 10 & 0 <= y & y <= 0.1

	row = 4;
	col = 4;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = -1.0;
	guardConstraintsMatrix(1, 1) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guardBoundValue[0] = -9.9;
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 4;
	col = 4;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = 1.0;
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(8, "t4", 1, 2, guard_polytope, assignment));

	Out_Going_Trans_fromboard.push_back(t);
	l = location::ptr(
			new location(1, "board", system_dynamics, invariant, true,
					Out_Going_Trans_fromboard));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);

	// The mode name is  GOOD

	row = 4;
	col = 4;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	system_dynamics.isEmptyC = true;

	std::list<transition::ptr> Out_Going_Trans_fromGOOD;

	l = location::ptr(
			new location(2, "GOOD", system_dynamics, invariant, false,
					Out_Going_Trans_fromGOOD));
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
	/*boundValueI[0] = 5;
	boundValueI[1] = -5;
	boundValueI[2] = 5;
	boundValueI[3] = -5;
	boundValueI[4] = 0.2;
	boundValueI[5] = -0.2;
	boundValueI[6] = 1;
	boundValueI[7] = -1;*/
	boundValueI[0] = 5.1;
	boundValueI[1] = -5;
	boundValueI[2] = 5.1;
	boundValueI[3] = -5;
	boundValueI[4] = 1;
	boundValueI[5] = -1;
	boundValueI[6] = 1;
	boundValueI[7] = -1;


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

	Hybrid_Automata.insert_to_map("x", 0);
	Hybrid_Automata.insert_to_map("y", 1);
	Hybrid_Automata.insert_to_map("Vx", 2);
	Hybrid_Automata.insert_to_map("Vy", 3);

	std::cout << "Model Parsing Successful!!" << std::endl;

	// ************* Section required for setting Reach Parameters & User Options *************
	/*	unsigned int Directions_Type = 2;
	 unsigned int iter_max = 3;
	 double time_horizon = 10.0;
	 double sampling_time = 0.01;
	 std::vector<std::string> output_variables;
	 output_variables.push_back("x");
	 output_variables.push_back("y");

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
