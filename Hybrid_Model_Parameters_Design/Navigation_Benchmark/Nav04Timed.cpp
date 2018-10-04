/*
 * NavigationTimed3by3.cpp
 *
 *  Created on: 22-May-2016
 *      Author: rajarshi
 */

#include "Hybrid_Model_Parameters_Design/Navigation_Benchmark/Nav04Timed.h"

// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/rajarshi/Benchmarks/Nav-timed/04_timed.xml
// Command Line arguments: -tool xspeed "" -passes flatten "" -debug -output /home/rajarshi/Benchmarks/Nav-timed/Nav04.cpp -input /home/rajarshi/Benchmarks/Nav-timed/04_timed.xml /home/rajarshi/Benchmarks/benchmarks-parallelization/navigation/PDBconcrete/04.cfg

void set_nav04_timed(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {

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

	// The mode name is  loc_0

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 2) = 1.0;
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 2) = -1.20000005;
	Amatrix(2 , 3) = 0.1;
	Amatrix(3 , 2) = 0.1;
	Amatrix(3 , 3) = -1.20000005;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[2] = 0.7778174933553391;
	C[3] = 0.7778174933553391;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_0;

	// The transition label is null

	// Original guard: x1 >= 1 - 0 & v1 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;
	guardConstraintsMatrix(1,2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -1.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(1,"null",1,2,guard_polytope,assignment));

	Out_Going_Trans_fromloc_0.push_back(t);
	// The transition label is null

	// Original guard: x2 >= 1 - 0 & v2 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -1.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(2,"null",1,4,guard_polytope,assignment));

	Out_Going_Trans_fromloc_0.push_back(t);
	l = location::ptr(new location(1, "loc_0", system_dynamics, invariant, true, Out_Going_Trans_fromloc_0));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);


	// The mode name is  loc_1

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 2) = 1.0;
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 2) = -1.20000005;
	Amatrix(2 , 3) = 0.1;
	Amatrix(3 , 2) = 0.1;
	Amatrix(3 , 3) = -1.20000005;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[2] = 0.7778174933553391;
	C[3] = 0.7778174933553391;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_1;

	// The transition label is null

	// Original guard: x1 <= 1 + 0 & v1 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(3,"null",2,1,guard_polytope,assignment));

	Out_Going_Trans_fromloc_1.push_back(t);
	// The transition label is null

	// Original guard: x1 >= 2 - 0 & v1 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;
	guardConstraintsMatrix(1,2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -2.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(4,"null",2,3,guard_polytope,assignment));

	Out_Going_Trans_fromloc_1.push_back(t);
	// The transition label is null

	// Original guard: x2 >= 1 - 0 & v2 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -1.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(5,"null",2,5,guard_polytope,assignment));

	Out_Going_Trans_fromloc_1.push_back(t);
	l = location::ptr(new location(2, "loc_1", system_dynamics, invariant, true, Out_Going_Trans_fromloc_1));
	Hybrid_Automata.addLocation(l);


	// The mode name is  loc_2

	row = 5;
	col = 5;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[3] = 1.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_2;


	l = location::ptr(new location(3, "loc_2", system_dynamics, invariant, true, Out_Going_Trans_fromloc_2));
	Hybrid_Automata.addLocation(l);


	// The mode name is  loc_3

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 2) = 1.0;
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 2) = -1.20000005;
	Amatrix(2 , 3) = 0.1;
	Amatrix(3 , 2) = 0.1;
	Amatrix(3 , 3) = -1.20000005;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[2] = 1.20000005;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_3;

	// The transition label is null

	// Original guard: x1 >= 1 - 0 & v1 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;
	guardConstraintsMatrix(1,2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -1.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(6,"null",4,5,guard_polytope,assignment));

	Out_Going_Trans_fromloc_3.push_back(t);
	// The transition label is null

	// Original guard: x2 <= 1 + 0 & v2 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(7,"null",4,1,guard_polytope,assignment));

	Out_Going_Trans_fromloc_3.push_back(t);
	// The transition label is null

	// Original guard: x2 >= 2 - 0 & v2 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -2.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(8,"null",4,7,guard_polytope,assignment));

	Out_Going_Trans_fromloc_3.push_back(t);
	l = location::ptr(new location(4, "loc_3", system_dynamics, invariant, true, Out_Going_Trans_fromloc_3));
	Hybrid_Automata.addLocation(l);


	// The mode name is  loc_4

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 2) = 1.0;
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 2) = -1.20000005;
	Amatrix(2 , 3) = 0.1;
	Amatrix(3 , 2) = 0.1;
	Amatrix(3 , 3) = -1.20000005;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[2] = 1.20000005;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_4;

	// The transition label is null

	// Original guard: x1 <= 1 + 0 & v1 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(9,"null",5,4,guard_polytope,assignment));

	Out_Going_Trans_fromloc_4.push_back(t);
	// The transition label is null

	// Original guard: x1 >= 2 - 0 & v1 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;
	guardConstraintsMatrix(1,2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -2.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(10,"null",5,6,guard_polytope,assignment));

	Out_Going_Trans_fromloc_4.push_back(t);
	// The transition label is null

	// Original guard: x2 <= 1 + 0 & v2 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(11,"null",5,2,guard_polytope,assignment));

	Out_Going_Trans_fromloc_4.push_back(t);
	// The transition label is null

	// Original guard: x2 >= 2 - 0 & v2 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -2.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(12,"null",5,8,guard_polytope,assignment));

	Out_Going_Trans_fromloc_4.push_back(t);
	l = location::ptr(new location(5, "loc_4", system_dynamics, invariant, true, Out_Going_Trans_fromloc_4));
	Hybrid_Automata.addLocation(l);

	Nav04module1(Hybrid_Automata,init_state_list,reach_parameters);
	Nav04module2(Hybrid_Automata,init_state_list,reach_parameters);
	Nav04module3(Hybrid_Automata,init_state_list,reach_parameters);
	Nav04module4(Hybrid_Automata,init_state_list,reach_parameters);

	row = 10;
	col = 5;
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
	boundValueI.resize(row );
	boundValueI.assign(row,0);
	boundValueI[0]=1;
	boundValueI[2]=1;
	boundValueI[4]=0.5;
	boundValueI[5]=-0.1;
	boundValueI[6]=0.25;
	boundValueI[7]=-0.05;

	initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id =1;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);



	Hybrid_Automata.insert_to_map("x1",0);
	Hybrid_Automata.insert_to_map("x2",1);
	Hybrid_Automata.insert_to_map("v1",2);
	Hybrid_Automata.insert_to_map("v2",3);
	Hybrid_Automata.insert_to_map("t",4);

	// ************* Section required for setting Reach Parameters & User Options *************
	/*unsigned int Directions_Type = 1;
	unsigned int iter_max = 200;
	double time_horizon = 40.0;
	double sampling_time = 0.2;
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

	void Nav04module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

	// The mode name is  loc_5

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 2) = 1.0;
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 2) = -1.20000005;
	Amatrix(2 , 3) = 0.1;
	Amatrix(3 , 2) = 0.1;
	Amatrix(3 , 3) = -1.20000005;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[2] = 0.1;
	C[3] = -1.20000005;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -1.0;
	invariantBoundValue[3] = 2.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_5;

	// The transition label is null

	// Original guard: x1 <= 2 + 0 & v1 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(13,"null",6,5,guard_polytope,assignment));

	Out_Going_Trans_fromloc_5.push_back(t);
	// The transition label is null

	// Original guard: x2 <= 1 + 0 & v2 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(14,"null",6,3,guard_polytope,assignment));

	Out_Going_Trans_fromloc_5.push_back(t);
	// The transition label is null

	// Original guard: x2 >= 2 - 0 & v2 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,3) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -2.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(15,"null",6,9,guard_polytope,assignment));

	Out_Going_Trans_fromloc_5.push_back(t);
	l = location::ptr(new location(6, "loc_5", system_dynamics, invariant, true, Out_Going_Trans_fromloc_5));
	Hybrid_Automata.addLocation(l);

	}

	void Nav04module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

	// The mode name is  loc_6

	row = 5;
	col = 5;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[1] = 1.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_6;


	l = location::ptr(new location(7, "loc_6", system_dynamics, invariant, true, Out_Going_Trans_fromloc_6));
	Hybrid_Automata.addLocation(l);

	}

	void Nav04module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

	// The mode name is  loc_7

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 2) = 1.0;
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 2) = -1.20000005;
	Amatrix(2 , 3) = 0.1;
	Amatrix(3 , 2) = 0.1;
	Amatrix(3 , 3) = -1.20000005;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[2] = 1.20000005;
	C[3] = -0.1;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -1.0;
	invariantBoundValue[1] = 2.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_7;

	// The transition label is null

	// Original guard: x1 <= 1 + 0 & v1 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(16,"null",8,7,guard_polytope,assignment));

	Out_Going_Trans_fromloc_7.push_back(t);
	// The transition label is null

	// Original guard: x1 >= 2 - 0 & v1 >= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;
	guardConstraintsMatrix(1,2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -2.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(17,"null",8,9,guard_polytope,assignment));

	Out_Going_Trans_fromloc_7.push_back(t);
	// The transition label is null

	// Original guard: x2 <= 2 + 0 & v2 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(18,"null",8,5,guard_polytope,assignment));

	Out_Going_Trans_fromloc_7.push_back(t);
	l = location::ptr(new location(8, "loc_7", system_dynamics, invariant, true, Out_Going_Trans_fromloc_7));
	Hybrid_Automata.addLocation(l);

	}

	void Nav04module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

	// The mode name is  loc_8

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0 , 2) = 1.0;
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 2) = -1.20000005;
	Amatrix(2 , 3) = 0.1;
	Amatrix(3 , 2) = 0.1;
	Amatrix(3 , 3) = -1.20000005;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row );
	C.assign(row,0);
	C[2] = 0.1;
	C[3] = -1.20000005;
	C[4] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 4;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;
	invariantConstraintsMatrix(1,0)= 1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -2.0;
	invariantBoundValue[1] = 3.0;
	invariantBoundValue[2] = -2.0;
	invariantBoundValue[3] = 3.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromloc_8;

	// The transition label is null

	// Original guard: x1 <= 2 + 0 & v1 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(19,"null",9,8,guard_polytope,assignment));

	Out_Going_Trans_fromloc_8.push_back(t);
	// The transition label is null

	// Original guard: x2 <= 2 + 0 & v2 <= 0

	row = 2;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 5;
	col = 5;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	R(2,2) =  1.0;
	R(3,3) =  1.0;
	R(4,4) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(20,"null",9,6,guard_polytope,assignment));

	Out_Going_Trans_fromloc_8.push_back(t);
	l = location::ptr(new location(9, "loc_8", system_dynamics, invariant, true, Out_Going_Trans_fromloc_8));
	Hybrid_Automata.addLocation(l);

}



