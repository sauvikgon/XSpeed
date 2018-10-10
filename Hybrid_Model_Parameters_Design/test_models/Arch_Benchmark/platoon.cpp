/*
 * fwr.cpp
 *
 *  Created on: 05-Dec-2016
 *      Author: amit
 */

#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/platoon.h"

void setplatoon(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters)

	{

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I0, forbid_polytope;
	location::ptr l;
	transition::ptr t;
	polytope::ptr invariant;

	polytope::ptr guard_polytope;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI , ConstraintsMatrixV, invariantConstraintsMatrix , guardConstraintsMatrix , Amatrix , Bmatrix,forbiddenMatrixI;

	std::vector<double> boundValueI,boundValueV , C , invariantBoundValue , guardBoundValue, boundValueF;

	int boundSignI=1, invariantBoundSign=1, guardBoundSign=1, boundSignV=1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  communication_communication

	row = 11;
	col = 11;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 1) = 1.0;
	Amatrix(1 , 2) = -1.0;
	Amatrix(2 , 0) = 1.605;
	Amatrix(2 , 1) = 4.868;
	Amatrix(2 , 2) = -3.5754;
	Amatrix(2 , 3) = -0.8198;
	Amatrix(2 , 4) = 0.427;
	Amatrix(2 , 5) = -0.045;
	Amatrix(2 , 6) = -0.1942;
	Amatrix(2 , 7) = 0.3626;
	Amatrix(2 , 8) = -0.0946;
	Amatrix(3 , 4) = 1.0;
	Amatrix(4 , 2) = 1.0;
	Amatrix(4 , 5) = -1.0;
	Amatrix(5 , 0) = 0.8718;
	Amatrix(5 , 1) = 3.814;
	Amatrix(5 , 2) = -0.0754;
	Amatrix(5 , 3) = 1.1936;
	Amatrix(5 , 4) = 3.6258;
	Amatrix(5 , 5) = -3.2396;
	Amatrix(5 , 6) = -0.595;
	Amatrix(5 , 7) = 0.1294;
	Amatrix(5 , 8) = -0.0796;
	Amatrix(6 , 7) = 1.0;
	Amatrix(7 , 5) = 1.0;
	Amatrix(7 , 8) = -1.0;
	Amatrix(8 , 0) = 0.7132;
	Amatrix(8 , 1) = 3.573;
	Amatrix(8 , 2) = -0.0964;
	Amatrix(8 , 3) = 0.8472;
	Amatrix(8 , 4) = 3.2568;
	Amatrix(8 , 5) = -0.0876;
	Amatrix(8 , 6) = 1.2726;
	Amatrix(8 , 7) = 3.072;
	Amatrix(8 , 8) = -3.1356;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	col = 1;
	Bmatrix.resize(row, col);
	Bmatrix.clear();
	Bmatrix(1 , 0) = 1.0;
	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	C.resize(row );
	C.assign(row,0);
	C[9] = 1.0;
	C[10] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 3;
	col = 11;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,9)= -1.0;
	invariantConstraintsMatrix(1,9)= 1.0;
	invariantConstraintsMatrix(2,10)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[1] = 20.0;
	invariantBoundValue[2] = 5.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	row = 2;
	col = 1;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0,0)= -1.0;
	ConstraintsMatrixV(1,0)= 1.0;

	boundValueV.resize(row);
	boundValueV[0] = 9.0;
	boundValueV[1] = 1.0;
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


	std::list<transition::ptr> Out_Going_Trans_fromcommunication_communication;

	// The transition label is breaking

	// Original guard: down_patt_1_t >= 5

	row = 1;
	col = 11;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,10) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -5.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 11;
	col = 11;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	R(5,5) =  1.0;
	R(6,6) =  1.0;
	R(7,7) =  1.0;
	R(8,8) =  1.0;
	R(9,9) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(1,"breaking",1,2,guard_polytope,assignment));

	Out_Going_Trans_fromcommunication_communication.push_back(t);
	l = location::ptr(new location(1, "communication_communication", system_dynamics, invariant, true, Out_Going_Trans_fromcommunication_communication));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);


	// The mode name is  no_communication_no_communication

	row = 11;
	col = 11;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 1) = 1.0;
	Amatrix(1 , 2) = -1.0;
	Amatrix(2 , 0) = 1.605;
	Amatrix(2 , 1) = 4.868;
	Amatrix(2 , 2) = -3.5754;
	Amatrix(3 , 4) = 1.0;
	Amatrix(4 , 2) = 1.0;
	Amatrix(4 , 5) = -1.0;
	Amatrix(5 , 3) = 1.1936;
	Amatrix(5 , 4) = 3.6258;
	Amatrix(5 , 5) = -3.2396;
	Amatrix(6 , 7) = 1.0;
	Amatrix(7 , 5) = 1.0;
	Amatrix(7 , 8) = -1.0;
	Amatrix(8 , 0) = 0.7132;
	Amatrix(8 , 1) = 3.573;
	Amatrix(8 , 2) = -0.0964;
	Amatrix(8 , 3) = 0.8472;
	Amatrix(8 , 4) = 3.2568;
	Amatrix(8 , 5) = -0.0876;
	Amatrix(8 , 6) = 1.2726;
	Amatrix(8 , 7) = 3.072;
	Amatrix(8 , 8) = -3.1356;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	col = 1;
	Bmatrix.resize(row, col);
	Bmatrix.clear();
	Bmatrix(1 , 0) = 1.0;
	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	C.resize(row );
	C.assign(row,0);
	C[9] = 1.0;
	C[10] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 2;
	col = 11;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,9)= 1.0;
	invariantConstraintsMatrix(1,10)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 20.0;
	invariantBoundValue[1] = 5.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	row = 2;
	col = 1;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0,0)= -1.0;
	ConstraintsMatrixV(1,0)= 1.0;

	boundValueV.resize(row);
	boundValueV[0] = 9.0;
	boundValueV[1] = 1.0;
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


	std::list<transition::ptr> Out_Going_Trans_fromno_communication_no_communication;

	// The transition label is restoring

	// Original guard: down_patt_1_t >= 5

	row = 1;
	col = 11;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,10) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -5.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 11;
	col = 11;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	R(5,5) =  1.0;
	R(6,6) =  1.0;
	R(7,7) =  1.0;
	R(8,8) =  1.0;
	R(9,9) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(2,"restoring",2,1,guard_polytope,assignment));

	Out_Going_Trans_fromno_communication_no_communication.push_back(t);
	l = location::ptr(new location(2, "no_communication_no_communication", system_dynamics, invariant, true, Out_Going_Trans_fromno_communication_no_communication));
	Hybrid_Automata.addLocation(l);


	row = 22;
	col = 11;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI.clear();
	ConstraintsMatrixI(0 , 0) = 1;
	ConstraintsMatrixI(1 , 0) = -1;
	ConstraintsMatrixI(2 , 1) = 1;
	ConstraintsMatrixI(3 , 1) = -1;
	ConstraintsMatrixI(4 , 2) = 1;
	ConstraintsMatrixI(5 , 2) = -1;
	ConstraintsMatrixI(6 , 3) = 1;
	ConstraintsMatrixI(7 , 3) = -1;
	ConstraintsMatrixI(8 , 4) = 1;
	ConstraintsMatrixI(9 , 4) = -1;
	ConstraintsMatrixI(10 , 5) = 1;
	ConstraintsMatrixI(11 , 5) = -1;
	ConstraintsMatrixI(12 , 6) = 1;
	ConstraintsMatrixI(13 , 6) = -1;
	ConstraintsMatrixI(14 , 7) = 1;
	ConstraintsMatrixI(15 , 7) = -1;
	ConstraintsMatrixI(16 , 8) = 1;
	ConstraintsMatrixI(17 , 8) = -1;
	ConstraintsMatrixI(18 , 9) = 1;
	ConstraintsMatrixI(19 , 9) = -1;
	ConstraintsMatrixI(20 , 10) = 1;
	ConstraintsMatrixI(21 , 10) = -1;
	boundValueI.resize(row );
	boundValueI.assign(row,0);


	initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id =1;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);



	Hybrid_Automata.insert_to_map("e1",0);
	Hybrid_Automata.insert_to_map("v1",1);
	Hybrid_Automata.insert_to_map("a1",2);
	Hybrid_Automata.insert_to_map("e2",3);
	Hybrid_Automata.insert_to_map("v2",4);
	Hybrid_Automata.insert_to_map("a2",5);
	Hybrid_Automata.insert_to_map("e3",6);
	Hybrid_Automata.insert_to_map("v3",7);
	Hybrid_Automata.insert_to_map("a3",8);
	Hybrid_Automata.insert_to_map("t",9);
	Hybrid_Automata.insert_to_map("down_patt_1_t",10);

	// ************* Section required for setting Reach Parameters & User Options *************
	unsigned int Directions_Type = 1;
	unsigned int iter_max = 1000;
	double time_horizon = 5.0;
	double sampling_time = 1.0E-4;
	std::vector<std::string> output_variables;
	output_variables.push_back("t");
	output_variables.push_back("e1");


	int x1 = Hybrid_Automata.get_index(output_variables[0]);
	int x2 = Hybrid_Automata.get_index(output_variables[1]);

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
	reach_parameters.Directions = Real_Directions;
}

/**
 * @Rajarshi:
 *
 * In this model, the transition from the communicating(cc) to non-communicating (nc) mode can occur
 * non-deterministically in the time interval interval [10,20]. The transition from nc to cc can
 * occur non-deterministically in the time interval [0,20]. The time is reset to 0 at the transitions.
 *
 */
void setplatoon_ndt(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters)
{
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


		unsigned int dim;
		size_type row, col;

		polytope::ptr initial_polytope_I0, forbid_polytope;
		location::ptr l;
		transition::ptr t;
		polytope::ptr invariant;

		polytope::ptr guard_polytope;

		Dynamics system_dynamics;

		math::matrix<double> ConstraintsMatrixI , ConstraintsMatrixV, invariantConstraintsMatrix , guardConstraintsMatrix , Amatrix , Bmatrix,forbiddenMatrixI;

		std::vector<double> boundValueI,boundValueV , C , invariantBoundValue , guardBoundValue, boundValueF;

		int boundSignI=1, invariantBoundSign=1, guardBoundSign=1, boundSignV=1;

		Assign assignment;
		math::matrix<double> R;

		// The mode name is  communication_communication

		row = 10;
		col = 10;
		Amatrix.resize(row, col);
		Amatrix.clear();
		Amatrix(0 , 1) = 1.0;
		Amatrix(1 , 2) = -1.0;
		Amatrix(2 , 0) = 1.605;
		Amatrix(2 , 1) = 4.868;
		Amatrix(2 , 2) = -3.5754;
		Amatrix(2 , 3) = -0.8198;
		Amatrix(2 , 4) = 0.427;
		Amatrix(2 , 5) = -0.045;
		Amatrix(2 , 6) = -0.1942;
		Amatrix(2 , 7) = 0.3626;
		Amatrix(2 , 8) = -0.0946;
		Amatrix(3 , 4) = 1.0;
		Amatrix(4 , 2) = 1.0;
		Amatrix(4 , 5) = -1.0;
		Amatrix(5 , 0) = 0.8718;
		Amatrix(5 , 1) = 3.814;
		Amatrix(5 , 2) = -0.0754;
		Amatrix(5 , 3) = 1.1936;
		Amatrix(5 , 4) = 3.6258;
		Amatrix(5 , 5) = -3.2396;
		Amatrix(5 , 6) = -0.595;
		Amatrix(5 , 7) = 0.1294;
		Amatrix(5 , 8) = -0.0796;
		Amatrix(6 , 7) = 1.0;
		Amatrix(7 , 5) = 1.0;
		Amatrix(7 , 8) = -1.0;
		Amatrix(8 , 0) = 0.7132;
		Amatrix(8 , 1) = 3.573;
		Amatrix(8 , 2) = -0.0964;
		Amatrix(8 , 3) = 0.8472;
		Amatrix(8 , 4) = 3.2568;
		Amatrix(8 , 5) = -0.0876;
		Amatrix(8 , 6) = 1.2726;
		Amatrix(8 , 7) = 3.072;
		Amatrix(8 , 8) = -3.1356;
		system_dynamics.isEmptyMatrixA = false;
		system_dynamics.MatrixA = Amatrix;

		col = 1;
		Bmatrix.resize(row, col);
		Bmatrix.clear();
		Bmatrix(1 , 0) = 1.0;
		system_dynamics.isEmptyMatrixB = false;
		system_dynamics.MatrixB = Bmatrix;

		C.resize(row );
		C.assign(row,0);
		C[9] = 1.0;
//		C[10] = 1.0;
		system_dynamics.isEmptyC = false;
		system_dynamics.C = C;


		row = 1;
		col = 10;
		invariantConstraintsMatrix.resize(row, col);
		invariantConstraintsMatrix.clear();
		invariantConstraintsMatrix(0,9)= -1.0;

		invariantBoundValue.resize(row);
		invariantBoundValue.assign(row,0);
		invariantBoundValue[0] = 0;
		invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

		row = 2;
		col = 1;
		ConstraintsMatrixV.resize(row, col);
		ConstraintsMatrixV(0,0)= -1.0;
		ConstraintsMatrixV(1,0)= 1.0;

		boundValueV.resize(row);
		boundValueV[0] = 9.0;
		boundValueV[1] = 1.0;
		system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


		std::list<transition::ptr> Out_Going_Trans_fromcommunication_communication;

		// The transition label is breaking

		// Original guard: down_patt_1_t >= 10

		row = 1;
		col = 11;


		guardConstraintsMatrix.resize(row, col);
		guardConstraintsMatrix.clear();
		guardConstraintsMatrix(0,10) = -1.0;


		guardBoundValue.resize(row);
		guardBoundValue.assign(row,0);
		guardBoundValue[0] = -10.0;

		guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


		// reset map that sets down_patt_1_t to 0.
		row = 10;
		col = 10;
		R.resize(row, col);
		R.clear();
		R(0,0) =  1.0;
		R(1,1) =  1.0;
		R(2,2) =  1.0;
		R(3,3) =  1.0;
		R(4,4) =  1.0;
		R(5,5) =  1.0;
		R(6,6) =  1.0;
		R(7,7) =  1.0;
		R(8,8) =  1.0;
		std::vector<double> w(row);
		w.assign(row,0);


		assignment.Map = R;
		assignment.b = w;

		t = transition::ptr(new transition(1,"breaking",1,2,guard_polytope,assignment));

		Out_Going_Trans_fromcommunication_communication.push_back(t);
		l = location::ptr(new location(1, "communication_communication", system_dynamics, invariant, true, Out_Going_Trans_fromcommunication_communication));

		Hybrid_Automata.addInitial_Location(l);
		Hybrid_Automata.addLocation(l);


		// The mode name is no_communication_no_communication

		row = 10;
		col = 10;
		Amatrix.resize(row, col);
		Amatrix.clear();
		Amatrix(0 , 1) = 1.0;
		Amatrix(1 , 2) = -1.0;
		Amatrix(2 , 0) = 1.605;
		Amatrix(2 , 1) = 4.868;
		Amatrix(2 , 2) = -3.5754;
		Amatrix(3 , 4) = 1.0;
		Amatrix(4 , 2) = 1.0;
		Amatrix(4 , 5) = -1.0;
		Amatrix(5 , 3) = 1.1936;
		Amatrix(5 , 4) = 3.6258;
		Amatrix(5 , 5) = -3.2396;
		Amatrix(6 , 7) = 1.0;
		Amatrix(7 , 5) = 1.0;
		Amatrix(7 , 8) = -1.0;
		Amatrix(8 , 0) = 0.7132;
		Amatrix(8 , 1) = 3.573;
		Amatrix(8 , 2) = -0.0964;
		Amatrix(8 , 3) = 0.8472;
		Amatrix(8 , 4) = 3.2568;
		Amatrix(8 , 5) = -0.0876;
		Amatrix(8 , 6) = 1.2726;
		Amatrix(8 , 7) = 3.072;
		Amatrix(8 , 8) = -3.1356;
		system_dynamics.isEmptyMatrixA = false;
		system_dynamics.MatrixA = Amatrix;

		col = 1;
		Bmatrix.resize(row, col);
		Bmatrix.clear();
		Bmatrix(1 , 0) = 1.0;
		system_dynamics.isEmptyMatrixB = false;
		system_dynamics.MatrixB = Bmatrix;

		C.resize(row );
		C.assign(row,0);
		C[9] = 1.0;
//		C[10] = 1.0;
		system_dynamics.isEmptyC = false;
		system_dynamics.C = C;


		row = 1;
		col = 10;
		invariantConstraintsMatrix.resize(row, col);
		invariantConstraintsMatrix.clear();
		invariantConstraintsMatrix(0,9)= -1.0;

		invariantBoundValue.resize(row);
		invariantBoundValue.assign(row,0);
		invariantBoundValue[0] = 0;
		invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

		row = 2;
		col = 1;
		ConstraintsMatrixV.resize(row, col);
		ConstraintsMatrixV(0,0)= -1.0;
		ConstraintsMatrixV(1,0)= 1.0;

		boundValueV.resize(row);
		boundValueV[0] = 9.0;
		boundValueV[1] = 1.0;
		system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


		std::list<transition::ptr> Out_Going_Trans_fromno_communication_no_communication;

		// The transition label is restoring

		// Original guard: down_patt_1_t >= 10

		row = 1;
		col = 11;


		guardConstraintsMatrix.resize(row, col);
		guardConstraintsMatrix.clear();
		guardConstraintsMatrix(0,10) = -1.0;


		guardBoundValue.resize(row);
		guardBoundValue.assign(row,0);
		guardBoundValue[0] = 0;

		guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


		// down_patt_1_t is reset to 0
		row = 10;
		col = 10;
		R.resize(row, col);
		R.clear();
		R(0,0) =  1.0;
		R(1,1) =  1.0;
		R(2,2) =  1.0;
		R(3,3) =  1.0;
		R(4,4) =  1.0;
		R(5,5) =  1.0;
		R(6,6) =  1.0;
		R(7,7) =  1.0;
		R(8,8) =  1.0;
		w.assign(row,0);


		assignment.Map = R;
		assignment.b = w;

		t = transition::ptr(new transition(2,"restoring",2,1,guard_polytope,assignment));

		Out_Going_Trans_fromno_communication_no_communication.push_back(t);
		l = location::ptr(new location(2, "no_communication_no_communication", system_dynamics, invariant, true, Out_Going_Trans_fromno_communication_no_communication));
		Hybrid_Automata.addLocation(l);


		row = 20;
		col = 10;
		ConstraintsMatrixI.resize(row, col);
		ConstraintsMatrixI.clear();
		ConstraintsMatrixI(0 , 0) = 1;
		ConstraintsMatrixI(1 , 0) = -1;
		ConstraintsMatrixI(2 , 1) = 1;
		ConstraintsMatrixI(3 , 1) = -1;
		ConstraintsMatrixI(4 , 2) = 1;
		ConstraintsMatrixI(5 , 2) = -1;
		ConstraintsMatrixI(6 , 3) = 1;
		ConstraintsMatrixI(7 , 3) = -1;
		ConstraintsMatrixI(8 , 4) = 1;
		ConstraintsMatrixI(9 , 4) = -1;
		ConstraintsMatrixI(10 , 5) = 1;
		ConstraintsMatrixI(11 , 5) = -1;
		ConstraintsMatrixI(12 , 6) = 1;
		ConstraintsMatrixI(13 , 6) = -1;
		ConstraintsMatrixI(14 , 7) = 1;
		ConstraintsMatrixI(15 , 7) = -1;
		ConstraintsMatrixI(16 , 8) = 1;
		ConstraintsMatrixI(17 , 8) = -1;
		ConstraintsMatrixI(18 , 9) = 1;
		ConstraintsMatrixI(19 , 9) = -1;
		boundValueI.resize(row );
		boundValueI.assign(row,0);


		initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

		dim = initial_polytope_I0->getSystemDimension();
		int transition_id = 0;
		unsigned int initial_location_id =1;

		symbolic_states::ptr S0;

		initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

		init_state_list.push_back(I0);
		Hybrid_Automata.setDimension(dim);



		Hybrid_Automata.insert_to_map("e1",0);
		Hybrid_Automata.insert_to_map("v1",1);
		Hybrid_Automata.insert_to_map("a1",2);
		Hybrid_Automata.insert_to_map("e2",3);
		Hybrid_Automata.insert_to_map("v2",4);
		Hybrid_Automata.insert_to_map("a2",5);
		Hybrid_Automata.insert_to_map("e3",6);
		Hybrid_Automata.insert_to_map("v3",7);
		Hybrid_Automata.insert_to_map("a3",8);
//		Hybrid_Automata.insert_to_map("t",9);
		Hybrid_Automata.insert_to_map("down_patt_1_t",9);

}

/**
 * The transition from communication to the non-communication mode can take place
 * non-deterministically between any time in the interval 0-20.
 *
 * NOTE: XSpeed fails to reach fixed point in this model.
 *
 */
void setplatoon_na(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters)
{
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


		unsigned int dim;
		size_type row, col;

		polytope::ptr initial_polytope_I0, forbid_polytope;
		location::ptr l;
		transition::ptr t;
		polytope::ptr invariant;

		polytope::ptr guard_polytope;

		Dynamics system_dynamics;

		math::matrix<double> ConstraintsMatrixI , ConstraintsMatrixV, invariantConstraintsMatrix , guardConstraintsMatrix , Amatrix , Bmatrix,forbiddenMatrixI;

		std::vector<double> boundValueI,boundValueV , C , invariantBoundValue , guardBoundValue, boundValueF;

		int boundSignI=1, invariantBoundSign=1, guardBoundSign=1, boundSignV=1;

		Assign assignment;
		math::matrix<double> R;

		// The mode name is  communication_communication

		row = 11;
		col = 11;
		Amatrix.resize(row, col);
		Amatrix.clear();
		Amatrix(0 , 1) = 1.0;
		Amatrix(1 , 2) = -1.0;
		Amatrix(2 , 0) = 1.605;
		Amatrix(2 , 1) = 4.868;
		Amatrix(2 , 2) = -3.5754;
		Amatrix(2 , 3) = -0.8198;
		Amatrix(2 , 4) = 0.427;
		Amatrix(2 , 5) = -0.045;
		Amatrix(2 , 6) = -0.1942;
		Amatrix(2 , 7) = 0.3626;
		Amatrix(2 , 8) = -0.0946;
		Amatrix(3 , 4) = 1.0;
		Amatrix(4 , 2) = 1.0;
		Amatrix(4 , 5) = -1.0;
		Amatrix(5 , 0) = 0.8718;
		Amatrix(5 , 1) = 3.814;
		Amatrix(5 , 2) = -0.0754;
		Amatrix(5 , 3) = 1.1936;
		Amatrix(5 , 4) = 3.6258;
		Amatrix(5 , 5) = -3.2396;
		Amatrix(5 , 6) = -0.595;
		Amatrix(5 , 7) = 0.1294;
		Amatrix(5 , 8) = -0.0796;
		Amatrix(6 , 7) = 1.0;
		Amatrix(7 , 5) = 1.0;
		Amatrix(7 , 8) = -1.0;
		Amatrix(8 , 0) = 0.7132;
		Amatrix(8 , 1) = 3.573;
		Amatrix(8 , 2) = -0.0964;
		Amatrix(8 , 3) = 0.8472;
		Amatrix(8 , 4) = 3.2568;
		Amatrix(8 , 5) = -0.0876;
		Amatrix(8 , 6) = 1.2726;
		Amatrix(8 , 7) = 3.072;
		Amatrix(8 , 8) = -3.1356;
		system_dynamics.isEmptyMatrixA = false;
		system_dynamics.MatrixA = Amatrix;

		col = 1;
		Bmatrix.resize(row, col);
		Bmatrix.clear();
		Bmatrix(1 , 0) = 1.0;
		system_dynamics.isEmptyMatrixB = false;
		system_dynamics.MatrixB = Bmatrix;

		C.resize(row );
		C.assign(row,0);
		C[9] = 1.0;
		C[10] = 1.0;
		system_dynamics.isEmptyC = false;
		system_dynamics.C = C;


		row = 2;
		col = 11;
		invariantConstraintsMatrix.resize(row, col);
		invariantConstraintsMatrix.clear();
		invariantConstraintsMatrix(0,9)= 1.0;
		invariantConstraintsMatrix(1,10)= 1.0;

		invariantBoundValue.resize(row);
		invariantBoundValue.assign(row,0);
		invariantBoundValue[0] = 20;
		invariantBoundValue[1] = 20;
		invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

		row = 2;
		col = 1;
		ConstraintsMatrixV.resize(row, col);
		ConstraintsMatrixV(0,0)= -1.0;
		ConstraintsMatrixV(1,0)= 1.0;

		boundValueV.resize(row);
		boundValueV[0] = 9.0;
		boundValueV[1] = 1.0;
		system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


		std::list<transition::ptr> Out_Going_Trans_fromcommunication_communication;

		// The transition label is breaking

		// guard: t >= 0. This means switching can take place arbitrarily at any moment in time.

		row = 1;
		col = 11;

		guardConstraintsMatrix.resize(row, col);
		guardConstraintsMatrix.clear();
		guardConstraintsMatrix(0,9) = -1.0;

		guardBoundValue.resize(row);
		guardBoundValue.assign(row,0);
		guardBoundValue[0] = 0;

		guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


		// Reset map
		row = 11;
		col = 11;
		R.resize(row, col);
		R.clear();
		R(0,0) =  1.0;
		R(1,1) =  1.0;
		R(2,2) =  1.0;
		R(3,3) =  1.0;
		R(4,4) =  1.0;
		R(5,5) =  1.0;
		R(6,6) =  1.0;
		R(7,7) =  1.0;
		R(8,8) =  1.0;
		R(9,9) =  1.0;
		R(10,10) =  1.0;
		std::vector<double> w(row);
		w.assign(row,0);


		assignment.Map = R;
		assignment.b = w;

		t = transition::ptr(new transition(1,"breaking",1,2,guard_polytope,assignment));

		Out_Going_Trans_fromcommunication_communication.push_back(t);
		l = location::ptr(new location(1, "communication_communication", system_dynamics, invariant, true, Out_Going_Trans_fromcommunication_communication));

		Hybrid_Automata.addInitial_Location(l);
		Hybrid_Automata.addLocation(l);


		// The mode name is no_communication_no_communication

		row = 11;
		col = 11;
		Amatrix.resize(row, col);
		Amatrix.clear();
		Amatrix(0 , 1) = 1.0;
		Amatrix(1 , 2) = -1.0;
		Amatrix(2 , 0) = 1.605;
		Amatrix(2 , 1) = 4.868;
		Amatrix(2 , 2) = -3.5754;
		Amatrix(3 , 4) = 1.0;
		Amatrix(4 , 2) = 1.0;
		Amatrix(4 , 5) = -1.0;
		Amatrix(5 , 3) = 1.1936;
		Amatrix(5 , 4) = 3.6258;
		Amatrix(5 , 5) = -3.2396;
		Amatrix(6 , 7) = 1.0;
		Amatrix(7 , 5) = 1.0;
		Amatrix(7 , 8) = -1.0;
		Amatrix(8 , 0) = 0.7132;
		Amatrix(8 , 1) = 3.573;
		Amatrix(8 , 2) = -0.0964;
		Amatrix(8 , 3) = 0.8472;
		Amatrix(8 , 4) = 3.2568;
		Amatrix(8 , 5) = -0.0876;
		Amatrix(8 , 6) = 1.2726;
		Amatrix(8 , 7) = 3.072;
		Amatrix(8 , 8) = -3.1356;
		system_dynamics.isEmptyMatrixA = false;
		system_dynamics.MatrixA = Amatrix;

		col = 1;
		Bmatrix.resize(row, col);
		Bmatrix.clear();
		Bmatrix(1 , 0) = 1.0;
		system_dynamics.isEmptyMatrixB = false;
		system_dynamics.MatrixB = Bmatrix;

		C.resize(row );
		C.assign(row,0);
		C[9] = 1.0;
		C[10] = 1.0;
		system_dynamics.isEmptyC = false;
		system_dynamics.C = C;


		row = 2;
		col = 11;
		invariantConstraintsMatrix.resize(row, col);
		invariantConstraintsMatrix.clear();
		invariantConstraintsMatrix(0,9)= 1.0;
		invariantConstraintsMatrix(1,10)= 1.0;

		invariantBoundValue.resize(row);
		invariantBoundValue.assign(row,0);
		invariantBoundValue[0] = 20;
		invariantBoundValue[1] = 20;
		invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

		row = 2;
		col = 1;
		ConstraintsMatrixV.resize(row, col);
		ConstraintsMatrixV(0,0)= -1.0;
		ConstraintsMatrixV(1,0)= 1.0;

		boundValueV.resize(row);
		boundValueV[0] = 9.0;
		boundValueV[1] = 1.0;
		system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


		std::list<transition::ptr> Out_Going_Trans_fromno_communication_no_communication;

		// The transition label is restoring

		// guard: down_patt_1_t >= 0

		row = 1;
		col = 11;

		guardConstraintsMatrix.resize(row, col);
		guardConstraintsMatrix.clear();
		guardConstraintsMatrix(0,10) = -1.0;


		guardBoundValue.resize(row);
		guardBoundValue.assign(row,0);
		guardBoundValue[0] = 0;

		guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


		// Reset
		row = 11;
		col = 11;
		R.resize(row, col);
		R.clear();
		R(0,0) =  1.0;
		R(1,1) =  1.0;
		R(2,2) =  1.0;
		R(3,3) =  1.0;
		R(4,4) =  1.0;
		R(5,5) =  1.0;
		R(6,6) =  1.0;
		R(7,7) =  1.0;
		R(8,8) =  1.0;
		R(9,9) =  1.0;
		R(10,10) =  1.0;
		w.assign(row,0);


		assignment.Map = R;
		assignment.b = w;

		t = transition::ptr(new transition(2,"restoring",2,1,guard_polytope,assignment));

		Out_Going_Trans_fromno_communication_no_communication.push_back(t);
		l = location::ptr(new location(2, "no_communication_no_communication", system_dynamics, invariant, true, Out_Going_Trans_fromno_communication_no_communication));
		Hybrid_Automata.addLocation(l);


		row = 22;
		col = 11;
		ConstraintsMatrixI.resize(row, col);
		ConstraintsMatrixI.clear();
		ConstraintsMatrixI(0 , 0) = 1;
		ConstraintsMatrixI(1 , 0) = -1;
		ConstraintsMatrixI(2 , 1) = 1;
		ConstraintsMatrixI(3 , 1) = -1;
		ConstraintsMatrixI(4 , 2) = 1;
		ConstraintsMatrixI(5 , 2) = -1;
		ConstraintsMatrixI(6 , 3) = 1;
		ConstraintsMatrixI(7 , 3) = -1;
		ConstraintsMatrixI(8 , 4) = 1;
		ConstraintsMatrixI(9 , 4) = -1;
		ConstraintsMatrixI(10 , 5) = 1;
		ConstraintsMatrixI(11 , 5) = -1;
		ConstraintsMatrixI(12 , 6) = 1;
		ConstraintsMatrixI(13 , 6) = -1;
		ConstraintsMatrixI(14 , 7) = 1;
		ConstraintsMatrixI(15 , 7) = -1;
		ConstraintsMatrixI(16 , 8) = 1;
		ConstraintsMatrixI(17 , 8) = -1;
		ConstraintsMatrixI(18 , 9) = 1;
		ConstraintsMatrixI(19 , 9) = -1;
		ConstraintsMatrixI(20 , 10) = 1;
		ConstraintsMatrixI(21 , 10) = -1;
		boundValueI.resize(row );
		boundValueI.assign(row,0);


		initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

		dim = initial_polytope_I0->getSystemDimension();
		int transition_id = 0;
		unsigned int initial_location_id =1;

		symbolic_states::ptr S0;

		initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

		init_state_list.push_back(I0);
		Hybrid_Automata.setDimension(dim);



		Hybrid_Automata.insert_to_map("e1",0);
		Hybrid_Automata.insert_to_map("v1",1);
		Hybrid_Automata.insert_to_map("a1",2);
		Hybrid_Automata.insert_to_map("e2",3);
		Hybrid_Automata.insert_to_map("v2",4);
		Hybrid_Automata.insert_to_map("a2",5);
		Hybrid_Automata.insert_to_map("e3",6);
		Hybrid_Automata.insert_to_map("v3",7);
		Hybrid_Automata.insert_to_map("a3",8);
		Hybrid_Automata.insert_to_map("t",9);
		Hybrid_Automata.insert_to_map("down_patt_1_t",10);

		// ************* Section required for setting Reach Parameters & User Options *************
		unsigned int Directions_Type = 1;
		unsigned int iter_max = 1000;
		double time_horizon = 5.0;
		double sampling_time = 1.0E-4;
		std::vector<std::string> output_variables;
		output_variables.push_back("t");
		output_variables.push_back("e1");


		int x1 = Hybrid_Automata.get_index(output_variables[0]);
		int x2 = Hybrid_Automata.get_index(output_variables[1]);

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
		reach_parameters.Directions = Real_Directions;

}
void setplatoon_const_input(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters)
{

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I0, forbid_polytope;
	location::ptr l;
	transition::ptr t;
	polytope::ptr invariant;

	polytope::ptr guard_polytope;

	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI , ConstraintsMatrixV, invariantConstraintsMatrix , guardConstraintsMatrix , Amatrix , Bmatrix,forbiddenMatrixI;

	std::vector<double> boundValueI,boundValueV , C , invariantBoundValue , guardBoundValue, boundValueF;

	int boundSignI=1, invariantBoundSign=1, guardBoundSign=1, boundSignV=1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  communication_communication

	row = 11;
	col = 11;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 1) = 1.0;
	Amatrix(1 , 2) = -1.0;
	Amatrix(2 , 0) = 1.605;
	Amatrix(2 , 1) = 4.868;
	Amatrix(2 , 2) = -3.5754;
	Amatrix(2 , 3) = -0.8198;
	Amatrix(2 , 4) = 0.427;
	Amatrix(2 , 5) = -0.045;
	Amatrix(2 , 6) = -0.1942;
	Amatrix(2 , 7) = 0.3626;
	Amatrix(2 , 8) = -0.0946;
	Amatrix(3 , 4) = 1.0;
	Amatrix(4 , 2) = 1.0;
	Amatrix(4 , 5) = -1.0;
	Amatrix(5 , 0) = 0.8718;
	Amatrix(5 , 1) = 3.814;
	Amatrix(5 , 2) = -0.0754;
	Amatrix(5 , 3) = 1.1936;
	Amatrix(5 , 4) = 3.6258;
	Amatrix(5 , 5) = -3.2396;
	Amatrix(5 , 6) = -0.595;
	Amatrix(5 , 7) = 0.1294;
	Amatrix(5 , 8) = -0.0796;
	Amatrix(6 , 7) = 1.0;
	Amatrix(7 , 5) = 1.0;
	Amatrix(7 , 8) = -1.0;
	Amatrix(8 , 0) = 0.7132;
	Amatrix(8 , 1) = 3.573;
	Amatrix(8 , 2) = -0.0964;
	Amatrix(8 , 3) = 0.8472;
	Amatrix(8 , 4) = 3.2568;
	Amatrix(8 , 5) = -0.0876;
	Amatrix(8 , 6) = 1.2726;
	Amatrix(8 , 7) = 3.072;
	Amatrix(8 , 8) = -3.1356;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[9] = 1.0;
	C[10] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 3;
	col = 11;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,9)= -1.0;
	invariantConstraintsMatrix(1,9)= 1.0;
	invariantConstraintsMatrix(2,10)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[1] = 20.0;
	invariantBoundValue[2] = 5.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	row = 2;
	col = 1;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0,0)= -1.0;
	ConstraintsMatrixV(1,0)= 1.0;

	boundValueV.resize(row);
	boundValueV[0] = -1.0;
	boundValueV[1] = 1.0;
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


	std::list<transition::ptr> Out_Going_Trans_fromcommunication_communication;

	// The transition label is breaking

	// Original guard: down_patt_1_t >= 5

	row = 1;
	col = 11;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,10) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -5.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 11;
	col = 11;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	R(5,5) =  1.0;
	R(6,6) =  1.0;
	R(7,7) =  1.0;
	R(8,8) =  1.0;
	R(9,9) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(1,"breaking",1,2,guard_polytope,assignment));

	Out_Going_Trans_fromcommunication_communication.push_back(t);
	l = location::ptr(new location(1, "communication_communication", system_dynamics, invariant, true, Out_Going_Trans_fromcommunication_communication));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);


	// The mode name is  no_communication_no_communication

	row = 11;
	col = 11;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 1) = 1.0;
	Amatrix(1 , 2) = -1.0;
	Amatrix(2 , 0) = 1.605;
	Amatrix(2 , 1) = 4.868;
	Amatrix(2 , 2) = -3.5754;
	Amatrix(3 , 4) = 1.0;
	Amatrix(4 , 2) = 1.0;
	Amatrix(4 , 5) = -1.0;
	Amatrix(5 , 3) = 1.1936;
	Amatrix(5 , 4) = 3.6258;
	Amatrix(5 , 5) = -3.2396;
	Amatrix(6 , 7) = 1.0;
	Amatrix(7 , 5) = 1.0;
	Amatrix(7 , 8) = -1.0;
	Amatrix(8 , 0) = 0.7132;
	Amatrix(8 , 1) = 3.573;
	Amatrix(8 , 2) = -0.0964;
	Amatrix(8 , 3) = 0.8472;
	Amatrix(8 , 4) = 3.2568;
	Amatrix(8 , 5) = -0.0876;
	Amatrix(8 , 6) = 1.2726;
	Amatrix(8 , 7) = 3.072;
	Amatrix(8 , 8) = -3.1356;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;


	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[9] = 1.0;
	C[10] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 2;
	col = 11;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,9)= 1.0;
	invariantConstraintsMatrix(1,10)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 20.0;
	invariantBoundValue[1] = 5.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	row = 2;
	col = 1;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0,0)= -1.0;
	ConstraintsMatrixV(1,0)= 1.0;

	boundValueV.resize(row);
	boundValueV[0] = -1.0;
	boundValueV[1] = 1.0;
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


	std::list<transition::ptr> Out_Going_Trans_fromno_communication_no_communication;

	// The transition label is restoring

	// Original guard: down_patt_1_t >= 5

	row = 1;
	col = 11;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,10) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -5.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 11;
	col = 11;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	R(5,5) =  1.0;
	R(6,6) =  1.0;
	R(7,7) =  1.0;
	R(8,8) =  1.0;
	R(9,9) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(2,"restoring",2,1,guard_polytope,assignment));

	Out_Going_Trans_fromno_communication_no_communication.push_back(t);
	l = location::ptr(new location(2, "no_communication_no_communication", system_dynamics, invariant, true, Out_Going_Trans_fromno_communication_no_communication));
	Hybrid_Automata.addLocation(l);


	row = 22;
	col = 11;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI.clear();
	ConstraintsMatrixI(0 , 0) = 1;
	ConstraintsMatrixI(1 , 0) = -1;
	ConstraintsMatrixI(2 , 1) = 1;
	ConstraintsMatrixI(3 , 1) = -1;
	ConstraintsMatrixI(4 , 2) = 1;
	ConstraintsMatrixI(5 , 2) = -1;
	ConstraintsMatrixI(6 , 3) = 1;
	ConstraintsMatrixI(7 , 3) = -1;
	ConstraintsMatrixI(8 , 4) = 1;
	ConstraintsMatrixI(9 , 4) = -1;
	ConstraintsMatrixI(10 , 5) = 1;
	ConstraintsMatrixI(11 , 5) = -1;
	ConstraintsMatrixI(12 , 6) = 1;
	ConstraintsMatrixI(13 , 6) = -1;
	ConstraintsMatrixI(14 , 7) = 1;
	ConstraintsMatrixI(15 , 7) = -1;
	ConstraintsMatrixI(16 , 8) = 1;
	ConstraintsMatrixI(17 , 8) = -1;
	ConstraintsMatrixI(18 , 9) = 1;
	ConstraintsMatrixI(19 , 9) = -1;
	ConstraintsMatrixI(20 , 10) = 1;
	ConstraintsMatrixI(21 , 10) = -1;
	boundValueI.resize(row );
	boundValueI.assign(row,0);


	initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id =1;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);



	Hybrid_Automata.insert_to_map("e1",0);
	Hybrid_Automata.insert_to_map("v1",1);
	Hybrid_Automata.insert_to_map("a1",2);
	Hybrid_Automata.insert_to_map("e2",3);
	Hybrid_Automata.insert_to_map("v2",4);
	Hybrid_Automata.insert_to_map("a2",5);
	Hybrid_Automata.insert_to_map("e3",6);
	Hybrid_Automata.insert_to_map("v3",7);
	Hybrid_Automata.insert_to_map("a3",8);
	Hybrid_Automata.insert_to_map("t",9);
	Hybrid_Automata.insert_to_map("down_patt_1_t",10);

	// ************* Section required for setting Reach Parameters & User Options *************
	unsigned int Directions_Type = 1;
	unsigned int iter_max = 1000;
	double time_horizon = 5.0;
	double sampling_time = 1.0E-4;
	std::vector<std::string> output_variables;
	output_variables.push_back("t");
	output_variables.push_back("e1");


	int x1 = Hybrid_Automata.get_index(output_variables[0]);
	int x2 = Hybrid_Automata.get_index(output_variables[1]);

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
	reach_parameters.Directions = Real_Directions;
}
