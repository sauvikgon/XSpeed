/*
 * fwr.cpp
 *
 *  Created on: 05-Dec-2016
 *      Author: amit
 */

#include "Hybrid_Model_Parameters_Design/test_models/Arch_Benchmark/platoon.h"

void setplatoon(hybrid_automata& Hybrid_Automata,
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

	math::matrix<double> ConstraintsMatrixI , ConstraintsMatrixV, invariantConstraintsMatrix , guardConstraintsMatrix , Amatrix , Bmatrix,forbiddenMatrixI;

	std::vector<double> boundValueI,boundValueV , C , invariantBoundValue , guardBoundValue, boundValueF;

	int boundSignI=1, invariantBoundSign=1, guardBoundSign=1, boundSignV=1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  communication_communication_loc1

	row = 11;
	col = 11;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1 , 2) = 1.0;
	Amatrix(2 , 3) = -1.0;
	Amatrix(3 , 1) = 1.605;
	Amatrix(3 , 2) = 4.868;
	Amatrix(3 , 3) = -3.5754;
	Amatrix(3 , 4) = -0.8198;
	Amatrix(3 , 5) = 0.427;
	Amatrix(3 , 6) = -0.045;
	Amatrix(3 , 7) = -0.1942;
	Amatrix(3 , 8) = 0.3626;
	Amatrix(3 , 9) = -0.0946;
	Amatrix(4 , 5) = 1.0;
	Amatrix(5 , 3) = 1.0;
	Amatrix(5 , 6) = -1.0;
	Amatrix(6 , 1) = 0.8718;
	Amatrix(6 , 2) = 3.814;
	Amatrix(6 , 3) = -0.0754;
	Amatrix(6 , 4) = 1.1936;
	Amatrix(6 , 5) = 3.6258;
	Amatrix(6 , 6) = -3.2396;
	Amatrix(6 , 7) = -0.595;
	Amatrix(6 , 8) = 0.1294;
	Amatrix(6 , 9) = -0.0796;
	Amatrix(7 , 8) = 1.0;
	Amatrix(8 , 6) = 1.0;
	Amatrix(8 , 9) = -1.0;
	Amatrix(9 , 1) = 0.7132;
	Amatrix(9 , 2) = 3.573;
	Amatrix(9 , 3) = -0.0964;
	Amatrix(9 , 4) = 0.8472;
	Amatrix(9 , 5) = 3.2568;
	Amatrix(9 , 6) = -0.0876;
	Amatrix(9 , 7) = 1.2726;
	Amatrix(9 , 8) = 3.072;
	Amatrix(9 , 9) = -3.1356;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	col = 1;
	Bmatrix.resize(row, col);
	Bmatrix.clear();
	Bmatrix(2 , 0) = 1.0;
	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	C.resize(row );
	C.assign(row,0);
	C[0] = 1.0;
	C[10] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 2;
	col = 11;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= 1.0;
	invariantConstraintsMatrix(1,10)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 20.0;
	invariantBoundValue[1] = 20.0;
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


	std::list<transition::ptr> Out_Going_Trans_fromcommunication_communication_loc1;

	// The transition label is breaking

	// Original guard: break_pattern_t >= 0

	row = 1;
	col = 11;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 11;
	col = 11;
	R.resize(row, col);
	R.clear();
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

	Out_Going_Trans_fromcommunication_communication_loc1.push_back(t);
	l = location::ptr(new location(1, "communication_communication_loc1", system_dynamics, invariant, true, Out_Going_Trans_fromcommunication_communication_loc1));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);


	// The mode name is  no_communication_no_communication_loc1

	row = 11;
	col = 11;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1 , 2) = 1.0;
	Amatrix(2 , 3) = -1.0;
	Amatrix(3 , 1) = 1.605;
	Amatrix(3 , 2) = 4.868;
	Amatrix(3 , 3) = -3.5754;
	Amatrix(4 , 5) = 1.0;
	Amatrix(5 , 3) = 1.0;
	Amatrix(5 , 6) = -1.0;
	Amatrix(6 , 4) = 1.1936;
	Amatrix(6 , 5) = 3.6258;
	Amatrix(6 , 6) = -3.2396;
	Amatrix(7 , 8) = 1.0;
	Amatrix(8 , 6) = 1.0;
	Amatrix(8 , 9) = -1.0;
	Amatrix(9 , 1) = 0.7132;
	Amatrix(9 , 2) = 3.573;
	Amatrix(9 , 3) = -0.0964;
	Amatrix(9 , 4) = 0.8472;
	Amatrix(9 , 5) = 3.2568;
	Amatrix(9 , 6) = -0.0876;
	Amatrix(9 , 7) = 1.2726;
	Amatrix(9 , 8) = 3.072;
	Amatrix(9 , 9) = -3.1356;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	col = 1;
	Bmatrix.resize(row, col);
	Bmatrix.clear();
	Bmatrix(2 , 0) = 1.0;
	system_dynamics.isEmptyMatrixB = false;
	system_dynamics.MatrixB = Bmatrix;

	C.resize(row );
	C.assign(row,0);
	C[0] = 1.0;
	C[10] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 2;
	col = 11;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= 1.0;
	invariantConstraintsMatrix(1,10)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 20.0;
	invariantBoundValue[1] = 20.0;
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


	std::list<transition::ptr> Out_Going_Trans_fromno_communication_no_communication_loc1;

	// The transition label is restoring

	guard_polytope = polytope::ptr(new polytope());
	guard_polytope -> setIsUniverse(true);


	row = 11;
	col = 11;
	R.resize(row, col);
	R.clear();
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

	Out_Going_Trans_fromno_communication_no_communication_loc1.push_back(t);
	l = location::ptr(new location(2, "no_communication_no_communication_loc1", system_dynamics, invariant, true, Out_Going_Trans_fromno_communication_no_communication_loc1));
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



	Hybrid_Automata.insert_to_map("break_pattern_t",0);
	Hybrid_Automata.insert_to_map("e1",1);
	Hybrid_Automata.insert_to_map("v1",2);
	Hybrid_Automata.insert_to_map("a1",3);
	Hybrid_Automata.insert_to_map("e2",4);
	Hybrid_Automata.insert_to_map("v2",5);
	Hybrid_Automata.insert_to_map("a2",6);
	Hybrid_Automata.insert_to_map("e3",7);
	Hybrid_Automata.insert_to_map("v3",8);
	Hybrid_Automata.insert_to_map("a3",9);
	Hybrid_Automata.insert_to_map("t",10);


}
