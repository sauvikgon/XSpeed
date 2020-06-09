/*
 * spacecraft.cpp
 *
 *  Created on: 05-Jul-2018
 *      Author: rajarshi
 */


// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/rajarshi/Archcomp18/spacecraft/SpaceEx/4D/model_noPass_hyst_4D.xml
// Command Line arguments: -t xspeed "" -o ./user_model.cpp -i /home/rajarshi/Archcomp18/spacecraft/SpaceEx/4D/model_noPass_hyst_4D.xml /home/rajarshi/Archcomp18/spacecraft/SpaceEx/4D/arch18.cfg


#include <benchmarks/archBenchmarks/spacecraft/spacecraft.h>

void setSpacecraft(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters){


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

	std::vector<double> boundValueI, boundValueV, invariantBoundValue , guardBoundValue, boundValueF;

	int boundSignI=1, invariantBoundSign=1, guardBoundSign=1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  P2

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 4) = 1.0;
	Amatrix(3 , 1) = -0.057599765881773;
	Amatrix(3 , 2) = 2.00959896519766E-4;
	Amatrix(3 , 3) = -2.89995083970656;
	Amatrix(3 , 4) = 0.00877200894463775;
	Amatrix(4 , 1) = -1.74031357370456E-4;
	Amatrix(4 , 2) = -0.0665123984901026;
	Amatrix(4 , 3) = -0.00875351105536225;
	Amatrix(4 , 4) = -2.90300269286856;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	/* B matrix set as identity matrix */

	system_dynamics.isEmptyMatrixB = false;
	Amatrix.matrix_Identity(row, Bmatrix);
	system_dynamics.MatrixB = Bmatrix;

	// set the U polytope matrix
	row = 10;
	col = 5;
	ConstraintsMatrixV.resize(row,col);
	ConstraintsMatrixV.clear();
	ConstraintsMatrixV(0,0)=1;

	for(unsigned int i=0,j=0;i<row-1;i+=2,j++){
		ConstraintsMatrixV(i,j)=1;
		ConstraintsMatrixV(i+1,j)=-1;	
	}

	boundValueV.resize(row,0);

	boundValueV[0]=1;
	boundValueV[1]=-1;
	
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, 1));

	row = 1;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -100.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));


	std::list<transition::ptr> Out_Going_Trans_fromP2;

	// The transition label is P2P3

	// Original guard: y >= -100 & x >= -100 & y <= 100 & x <= 100 & x+y >=-141.1 &
	// y-x<=141.1 & x+y<=141.1 & y-x>=-141.1

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,2) = -1.0;
	guardConstraintsMatrix(1,1) = -1.0;
	guardConstraintsMatrix(2,2) = 1.0;
	guardConstraintsMatrix(3,1) = 1.0;
	guardConstraintsMatrix(4,1) = -1.0;
	guardConstraintsMatrix(4,2) = -1.0;
	guardConstraintsMatrix(5,1) = -1.0;
	guardConstraintsMatrix(5,2) = 1.0;
	guardConstraintsMatrix(6,1) = 1.0;
	guardConstraintsMatrix(6,2) = 1.0;
	guardConstraintsMatrix(7,1) = 1.0;
	guardConstraintsMatrix(7,2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = 100.0;
	guardBoundValue[1] = 100.0;
	guardBoundValue[2] = 100.0;
	guardBoundValue[3] = 100.0;
	guardBoundValue[4] = 141.1;
	guardBoundValue[5] = 141.1;
	guardBoundValue[6] = 141.1;
	guardBoundValue[7] = 141.1;

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

	t = transition::ptr(new transition(1,"P2P3",1,2,guard_polytope,assignment));

	Out_Going_Trans_fromP2.push_back(t);
	l =location::ptr(new location(1, "P2", system_dynamics, invariant, false, Out_Going_Trans_fromP2));

	Hybrid_Automata.addInitialLocation(l);
	Hybrid_Automata.addLocation(l);


	// The mode name is  P3

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 4) = 1.0;
	Amatrix(3 , 1) = -0.575999943070835;
	Amatrix(3 , 2) = 2.62486079431672E-4;
	Amatrix(3 , 3) = -19.2299795908647;
	Amatrix(3 , 4) = 0.00876275931760007;
	Amatrix(4 , 1) = -2.62486080737868E-4;
	Amatrix(4 , 2) = -0.575999940191886;
	Amatrix(4 , 3) = -0.00876276068239993;
	Amatrix(4 , 4) = -19.2299765959399;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	/* B matrix set as identity matrix*/

	system_dynamics.isEmptyMatrixB = false;
	Amatrix.matrix_Identity(row, Bmatrix);
	system_dynamics.MatrixB = Bmatrix;

	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, 1));

	row = 8;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,2)= -1.0;
	invariantConstraintsMatrix(1,1)= -1.0;
	invariantConstraintsMatrix(1,2)= -1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(3,1)= -1.0;
	invariantConstraintsMatrix(3,2)= 1.0;
	invariantConstraintsMatrix(4,2)= 1.0;
	invariantConstraintsMatrix(5,1)= 1.0;
	invariantConstraintsMatrix(5,2)= 1.0;
	invariantConstraintsMatrix(6,1)= 1.0;
	invariantConstraintsMatrix(7,1)= 1.0;
	invariantConstraintsMatrix(7,2)= -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 100.0;
	invariantBoundValue[1] = 141.1;
	invariantBoundValue[2] = 100.0;
	invariantBoundValue[3] = 141.1;
	invariantBoundValue[4] = 100.0;
	invariantBoundValue[5] = 141.1;
	invariantBoundValue[6] = 100.0;
	invariantBoundValue[7] = 141.1;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

	system_dynamics.U = polytope::ptr(new polytope(true));


	std::list<transition::ptr> Out_Going_Trans_fromP3;


	l = location::ptr(new location(2, "P3", system_dynamics, invariant, true, Out_Going_Trans_fromP3));
	Hybrid_Automata.addLocation(l);


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
	boundValueI[2]=-875;
	boundValueI[3]=925;
	boundValueI[4]=-375;
	boundValueI[5]=425;


	initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id =1;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);


	Hybrid_Automata.insert_to_map("t",0);
	Hybrid_Automata.insert_to_map("x",1);
	Hybrid_Automata.insert_to_map("y",2);
	Hybrid_Automata.insert_to_map("vx",3);
	Hybrid_Automata.insert_to_map("vy",4);

}
/* Model with transition to mission abort mode. */

void setSpacecraftAbort(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters){


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

	std::vector<double> boundValueI,boundValueV, invariantBoundValue , guardBoundValue, boundValueF;

	int boundSignI=1, invariantBoundSign=1, guardBoundSign=1, boundSignV=1;

	Assign assignment;
	math::matrix<double> R;

	// The mode name is  P2

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 4) = 1.0;
	Amatrix(3 , 1) = -0.057599765881773;
	Amatrix(3 , 2) = 2.00959896519766E-4;
	Amatrix(3 , 3) = -2.89995083970656;
	Amatrix(3 , 4) = 0.00877200894463775;
	Amatrix(4 , 1) = -1.74031357370456E-4;
	Amatrix(4 , 2) = -0.0665123984901026;
	Amatrix(4 , 3) = -0.00875351105536225;
	Amatrix(4 , 4) = -2.90300269286856;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	/* B matrix set as identity matrix */

	system_dynamics.isEmptyMatrixB = false;
	Amatrix.matrix_Identity(row, Bmatrix);
	system_dynamics.MatrixB = Bmatrix;

	// set the U polytope matrix
	row = 10;
	col = 5;
	ConstraintsMatrixV.resize(row,col);
	ConstraintsMatrixV.clear();
	ConstraintsMatrixV(0,0)=1;

	for(unsigned int i=0,j=0;i<row-1;i+=2,j++){
		ConstraintsMatrixV(i,j)=1;
		ConstraintsMatrixV(i+1,j)=-1;	
	}

	boundValueV.resize(row,0);

	boundValueV[0]=1;
	boundValueV[1]=-1;
	
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, 1));
	
	row = 2;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= 1.0;
	invariantConstraintsMatrix(1,1)= 1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 125.0;
	invariantBoundValue[1] = -100.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));


	std::list<transition::ptr> Out_Going_Trans_fromP2;

	// The transition label is P2P3

	// Original guard: y >= -100 & x >= -100 & y <= 100 & x <= 100 & x+y >=-141.1 &
	// y-x<=141.1 & x+y<=141.1 & y-x>=-141.1

	row = 8;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,2) = -1.0;
	guardConstraintsMatrix(1,1) = -1.0;
	guardConstraintsMatrix(2,2) = 1.0;
	guardConstraintsMatrix(3,1) = 1.0;
	guardConstraintsMatrix(4,1) = -1.0;
	guardConstraintsMatrix(4,2) = -1.0;
	guardConstraintsMatrix(5,1) = -1.0;
	guardConstraintsMatrix(5,2) = 1.0;
	guardConstraintsMatrix(6,1) = 1.0;
	guardConstraintsMatrix(6,2) = 1.0;
	guardConstraintsMatrix(7,1) = 1.0;
	guardConstraintsMatrix(7,2) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = 100.0;
	guardBoundValue[1] = 100.0;
	guardBoundValue[2] = 100.0;
	guardBoundValue[3] = 100.0;
	guardBoundValue[4] = 141.1;
	guardBoundValue[5] = 141.1;
	guardBoundValue[6] = 141.1;
	guardBoundValue[7] = 141.1;

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

	t = transition::ptr(new transition(1,"P2P3",1,2,guard_polytope,assignment));

	Out_Going_Trans_fromP2.push_back(t);
	// The transition label is P2Pass

	// Original guard: t >= 120

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -120.0;
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

	t = transition::ptr(new transition(2,"P2Pass",1,3,guard_polytope,assignment));

	Out_Going_Trans_fromP2.push_back(t);
	l = location::ptr(new location(1, "P2", system_dynamics, invariant, true, Out_Going_Trans_fromP2));

	Hybrid_Automata.addInitialLocation(l);
	Hybrid_Automata.addLocation(l);


	// The mode name is  P3

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 4) = 1.0;
	Amatrix(3 , 1) = -0.575999943070835;
	Amatrix(3 , 2) = 2.62486079431672E-4;
	Amatrix(3 , 3) = -19.2299795908647;
	Amatrix(3 , 4) = 0.00876275931760007;
	Amatrix(4 , 1) = -2.62486080737868E-4;
	Amatrix(4 , 2) = -0.575999940191886;
	Amatrix(4 , 3) = -0.00876276068239993;
	Amatrix(4 , 4) = -19.2299765959399;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	/* B matrix set as identity matrix */

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, 1));
	
	row = 9;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= 1.0;
	invariantConstraintsMatrix(1,2)= -1.0;
	invariantConstraintsMatrix(2,1)= -1.0;
	invariantConstraintsMatrix(2,2)= -1.0;
	invariantConstraintsMatrix(3,1)= -1.0;
	invariantConstraintsMatrix(4,1)= -1.0;
	invariantConstraintsMatrix(4,2)= 1.0;
	invariantConstraintsMatrix(5,2)= 1.0;
	invariantConstraintsMatrix(6,1)= 1.0;
	invariantConstraintsMatrix(6,2)= 1.0;
	invariantConstraintsMatrix(7,1)= 1.0;
	invariantConstraintsMatrix(8,1)= 1.0;
	invariantConstraintsMatrix(8,2)= -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = 125.0;
	invariantBoundValue[1] = 100.0;
	invariantBoundValue[2] = 141.1;
	invariantBoundValue[3] = 100.0;
	invariantBoundValue[4] = 141.1;
	invariantBoundValue[5] = 100.0;
	invariantBoundValue[6] = 141.1;
	invariantBoundValue[7] = 100.0;
	invariantBoundValue[8] = 141.1;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));


	std::list<transition::ptr> Out_Going_Trans_fromP3;

	// The transition label is P3Pass

	// Original guard: t >= 120

	row = 1;
	col = 5;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0,0) = -1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row,0);
	guardBoundValue[0] = -120.0;
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

	t = transition::ptr(new transition(3,"P3Pass",2,3,guard_polytope,assignment));

	Out_Going_Trans_fromP3.push_back(t);
	l = location::ptr(new location(2, "P3", system_dynamics, invariant, true, Out_Going_Trans_fromP3));
	Hybrid_Automata.addLocation(l);


	// The mode name is  Passive

	row = 5;
	col = 5;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(1 , 3) = 1.0;
	Amatrix(2 , 4) = 1.0;
	Amatrix(3 , 1) = 5.75894721132E-5;
	Amatrix(3 , 4) = 0.00876276;
	Amatrix(4 , 3) = -0.00876276;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	/* B matrix set as identity matrix */

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, 1));

	row = 1;
	col = 5;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0,0)= -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row,0);
	invariantBoundValue[0] = -120.0;
	invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));


	std::list<transition::ptr> Out_Going_Trans_fromPassive;


	l =location::ptr(new location(3, "Passive", system_dynamics, invariant, false, Out_Going_Trans_fromPassive));
	Hybrid_Automata.addLocation(l);


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
	boundValueI[2]=-875;
	boundValueI[3]=920;
	boundValueI[4]=-375;
	boundValueI[5]=425;


	initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id =1;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);

	Hybrid_Automata.insert_to_map("t",0);
	Hybrid_Automata.insert_to_map("x",1);
	Hybrid_Automata.insert_to_map("y",2);
	Hybrid_Automata.insert_to_map("vx",3);
	Hybrid_Automata.insert_to_map("vy",4);
}
