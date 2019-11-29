/*
 * watertank_controller.cpp
 *
 *  Created on: 27-Jun-2018
 *      Author: rajarshi
 */


// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/shyam/Shyam/Hyst-XSpeed/tests/unit/models/water_tank/water_tank_controller.xml
// Command Line arguments: -tool xspeed "" -verbose -output /home/shyam/Shyam/Hyst-XSpeed/tests/unit/models/water_tank_controller.cpp -input /home/shyam/Shyam/Hyst-XSpeed/tests/unit/models/water_tank/water_tank_controller.xml /home/shyam/Shyam/Hyst-XSpeed/tests/unit/models/water_tank/water_tank_controller.cfg

#include "../../benchmarks/Watertank_Controller/watertank_controller.h"


void set_watertank_controller(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters){


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

	// The mode name is  v0

	row = 2;
	col = 2;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	system_dynamics.isEmptyC = true;


	std::list<transition::ptr> Out_Going_Trans_fromv0;

	// The transition label is e0

	// Original guard: y = 1

	row = 2;
	col = 2;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -1.0;
	guardBoundValue[1] = 1.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 2;
	col = 2;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(1,"e0",1,2,guard_polytope,assignment));

	Out_Going_Trans_fromv0.push_back(t);
	l =location::ptr(new location(1, "v0", system_dynamics, invariant, false, Out_Going_Trans_fromv0));

	Hybrid_Automata.addInitial_Location(l);
	Hybrid_Automata.addLocation(l);


	// The mode name is  v1

	row = 2;
	col = 2;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row );
	C.assign(row,0);
	C[0] = 1.0;
	C[1] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 2;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 10.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromv1;

	// The transition label is e1

	// Original guard: y = 10

	row = 2;
	col = 2;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -10.0;
	guardBoundValue[1] = 10.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 2;
	col = 2;
	R.resize(row, col);
	R.clear();
	w.assign(row,0);
	w[1] = 10.0;


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(2,"e1",2,3,guard_polytope,assignment));

	Out_Going_Trans_fromv1.push_back(t);
	// The transition label is e5

	// Original guard: y = 0

	row = 2;
	col = 2;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 2;
	col = 2;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(3,"e5",2,6,guard_polytope,assignment));

	Out_Going_Trans_fromv1.push_back(t);
	l = location::ptr(new location(2, "v1", system_dynamics, invariant, true, Out_Going_Trans_fromv1));
	Hybrid_Automata.addLocation(l);

	WT_module1(Hybrid_Automata,init_state_list,reach_parameters);
	WT_module2(Hybrid_Automata,init_state_list,reach_parameters);
	WT_module3(Hybrid_Automata,init_state_list,reach_parameters);
	WT_module4(Hybrid_Automata,init_state_list,reach_parameters);

	row = 4;
	col = 2;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI.clear();
	ConstraintsMatrixI(0 , 0) = 1;
	ConstraintsMatrixI(1 , 0) = -1;
	ConstraintsMatrixI(2 , 1) = 1;
	ConstraintsMatrixI(3 , 1) = -1;
	boundValueI.resize(row );
	boundValueI.assign(row,0);
	boundValueI[2]=1;
	boundValueI[3]=-1;


	initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id =1;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);



	Hybrid_Automata.insert_to_map("x",0);
	Hybrid_Automata.insert_to_map("y",1);

	}

	void WT_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

	// The mode name is  v2

	row = 2;
	col = 2;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row );
	C.assign(row,0);
	C[0] = 1.0;
	C[1] = 1.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 2;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 2.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromv2;

	// The transition label is e2

	// Original guard: x = 2

	row = 2;
	col = 2;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;
	guardConstraintsMatrix(1,0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 2;
	col = 2;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(4,"e2",3,4,guard_polytope,assignment));

	Out_Going_Trans_fromv2.push_back(t);
	l = location::ptr(new location(3, "v2", system_dynamics, invariant, true, Out_Going_Trans_fromv2));
	Hybrid_Automata.addLocation(l);

	}

	void WT_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

	// The mode name is  v3

	row = 2;
	col = 2;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row );
	C.assign(row,0);
	C[0] = 1.0;
	C[1] = -2.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 2;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,1)= -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -5.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromv3;

	// The transition label is e3

	// Original guard: y = 5

	row = 2;
	col = 2;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,1) = -1.0;
	guardConstraintsMatrix(1,1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -5.0;
	guardBoundValue[1] = 5.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 2;
	col = 2;
	R.resize(row, col);
	R.clear();
	R(1,1) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(5,"e3",4,5,guard_polytope,assignment));

	Out_Going_Trans_fromv3.push_back(t);
	l = location::ptr(new location(4, "v3", system_dynamics, invariant, true, Out_Going_Trans_fromv3));
	Hybrid_Automata.addLocation(l);

	}

	void WT_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

	// The mode name is  v4

	row = 2;
	col = 2;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	C.resize(row );
	C.assign(row,0);
	C[0] = 1.0;
	C[1] = -2.0;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;


	row = 2;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 2.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromv4;

	// The transition label is e4

	// Original guard: x = 2

	row = 2;
	col = 2;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;
	guardConstraintsMatrix(1,0) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -2.0;
	guardBoundValue[1] = 2.0;
	guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


	row = 2;
	col = 2;
	R.resize(row, col);
	R.clear();
	R(0,0) =  1.0;
	R(1,1) =  1.0;
	std::vector<double> w(row);
	w.assign(row,0);


	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(new transition(6,"e4",5,2,guard_polytope,assignment));

	Out_Going_Trans_fromv4.push_back(t);
	l = location::ptr(new location(5, "v4", system_dynamics, invariant, true, Out_Going_Trans_fromv4));
	Hybrid_Automata.addLocation(l);

	}

	void WT_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

	// The mode name is  v5

	row = 2;
	col = 2;
	system_dynamics.isEmptyMatrixA = true;

	system_dynamics.isEmptyMatrixB = true;
	system_dynamics.U = polytope::ptr(new polytope(true));

	system_dynamics.isEmptyC = true;


	std::list<transition::ptr> Out_Going_Trans_fromv5;


	l =location::ptr(new location(6, "v5", system_dynamics, invariant, false, Out_Going_Trans_fromv5));
	Hybrid_Automata.addLocation(l);

}
