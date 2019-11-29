/*
 * setNav2u.cpp
 *
 *  Created on: 28-Jun-2018
 *      Author: rajarshi
 */



// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/rajarshi/ArchComp2018/HBMC/benchmarks/Navigation/NAV_2_2.xml
// Command Line arguments: -t xspeed "" -o ./user_model.cpp -i /home/rajarshi/ArchComp2018/HBMC/benchmarks/Navigation/NAV_2_2.xml /home/rajarshi/ArchComp2018/HBMC/benchmarks/Navigation/NAV_2_2.cfg


#include "../../../benchmarks/test_models/Arch_Benchmark/setNav2u.h"

void setNav2u(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  L00

row = 2;
col = 2;
system_dynamics.isEmptyMatrixA = true;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = 0.6;
C[1] = 1.2;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 2;
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


std::list<transition::ptr> Out_Going_Trans_fromL00;

// The transition label is d1

// Original guard: x1 = 1

row = 2;
col = 2;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

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

t = transition::ptr(new transition(1,"d1",1,2,guard_polytope,assignment));

Out_Going_Trans_fromL00.push_back(t);
// The transition label is d2

// Original guard: x2 = 2

row = 2;
col = 2;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,1) = 1.0;

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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(2,"d2",1,3,guard_polytope,assignment));

Out_Going_Trans_fromL00.push_back(t);
l = location::ptr(new location(1, "L00", system_dynamics, invariant, true, Out_Going_Trans_fromL00));

Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);


// The mode name is  L01

row = 2;
col = 2;
system_dynamics.isEmptyMatrixA = true;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = -0.5;
C[1] = -1.1;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 2;
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


std::list<transition::ptr> Out_Going_Trans_fromL01;

// The transition label is d3

// Original guard: x1 = 1

row = 2;
col = 2;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(3,"d3",2,1,guard_polytope,assignment));

Out_Going_Trans_fromL01.push_back(t);
// The transition label is d4

// Original guard: x2 = 2

row = 2;
col = 2;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,1) = 1.0;

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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(4,"d4",2,4,guard_polytope,assignment));

Out_Going_Trans_fromL01.push_back(t);
l = location::ptr(new location(2, "L01", system_dynamics, invariant, true, Out_Going_Trans_fromL01));
Hybrid_Automata.addLocation(l);


// The mode name is  L10

row = 2;
col = 2;
system_dynamics.isEmptyMatrixA = true;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = 0.6;
C[1] = 1.2;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 2;
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


std::list<transition::ptr> Out_Going_Trans_fromL10;

// The transition label is d5

// Original guard: x1 = 1

row = 2;
col = 2;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(5,"d5",3,4,guard_polytope,assignment));

Out_Going_Trans_fromL10.push_back(t);
// The transition label is d6

// Original guard: x2 = 1

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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(6,"d6",3,1,guard_polytope,assignment));

Out_Going_Trans_fromL10.push_back(t);
l = location::ptr(new location(3, "L10", system_dynamics, invariant, true, Out_Going_Trans_fromL10));
Hybrid_Automata.addLocation(l);


// The mode name is  L11

row = 2;
col = 2;
system_dynamics.isEmptyMatrixA = true;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = -0.5;
C[1] = -1.1;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 2;
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


std::list<transition::ptr> Out_Going_Trans_fromL11;

// The transition label is d7

// Original guard: x1 = 1

row = 2;
col = 2;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(7,"d7",4,3,guard_polytope,assignment));

Out_Going_Trans_fromL11.push_back(t);
// The transition label is d8

// Original guard: x2 = 1

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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(8,"d8",4,2,guard_polytope,assignment));

Out_Going_Trans_fromL11.push_back(t);
l = location::ptr(new location(4, "BAD", system_dynamics, invariant, true, Out_Going_Trans_fromL11));
Hybrid_Automata.addLocation(l);


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

}
