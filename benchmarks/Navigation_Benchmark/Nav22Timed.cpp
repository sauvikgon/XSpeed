// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/shyam/Shyam/Hyst-XSpeed/tests/unit/models/NavBenchXML/nav22x22/22timed.xml
// Command Line arguments: -tool xspeed "" -verbose -output /home/shyam/Shyam/Hyst-XSpeed/tests/unit/models/NavBenchXML/nav22x22/22.cpp -input /home/shyam/Shyam/Hyst-XSpeed/tests/unit/models/NavBenchXML/nav22x22/22timed.xml /home/shyam/Shyam/Hyst-XSpeed/tests/unit/models/NavBenchXML/nav22x22/22.cfg

#include "../../benchmarks/Navigation_Benchmark/Nav22Timed.h"

void setNav22Timed(hybrid_automata& Hybrid_Automata,std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters)
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

// The mode name is  loc_0

row = 5;
col = 5;
system_dynamics.isEmptyMatrixA = true;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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


l = location::ptr(new location(1, "loc_0", system_dynamics, invariant, true, Out_Going_Trans_fromloc_0));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_1

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(1,"null",2,1,guard_polytope,assignment));

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

t = transition::ptr(new transition(2,"null",2,3,guard_polytope,assignment));

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

t = transition::ptr(new transition(3,"null",2,17,guard_polytope,assignment));

Out_Going_Trans_fromloc_1.push_back(t);
l = location::ptr(new location(2, "loc_1", system_dynamics, invariant, true, Out_Going_Trans_fromloc_1));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_2

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(4,"null",3,2,guard_polytope,assignment));

Out_Going_Trans_fromloc_2.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(5,"null",3,4,guard_polytope,assignment));

Out_Going_Trans_fromloc_2.push_back(t);
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

t = transition::ptr(new transition(6,"null",3,18,guard_polytope,assignment));

Out_Going_Trans_fromloc_2.push_back(t);
l = location::ptr(new location(3, "loc_2", system_dynamics, invariant, true, Out_Going_Trans_fromloc_2));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_3

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_3;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(7,"null",4,3,guard_polytope,assignment));

Out_Going_Trans_fromloc_3.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(8,"null",4,5,guard_polytope,assignment));

Out_Going_Trans_fromloc_3.push_back(t);
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

t = transition::ptr(new transition(9,"null",4,19,guard_polytope,assignment));

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
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_4;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(10,"null",5,4,guard_polytope,assignment));

Out_Going_Trans_fromloc_4.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(11,"null",5,6,guard_polytope,assignment));

Out_Going_Trans_fromloc_4.push_back(t);
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

t = transition::ptr(new transition(12,"null",5,20,guard_polytope,assignment));

Out_Going_Trans_fromloc_4.push_back(t);
l = location::ptr(new location(5, "loc_4", system_dynamics, invariant, true, Out_Going_Trans_fromloc_4));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_5

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_5;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(13,"null",6,5,guard_polytope,assignment));

Out_Going_Trans_fromloc_5.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(14,"null",6,7,guard_polytope,assignment));

Out_Going_Trans_fromloc_5.push_back(t);
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

t = transition::ptr(new transition(15,"null",6,21,guard_polytope,assignment));

Out_Going_Trans_fromloc_5.push_back(t);
l = location::ptr(new location(6, "loc_5", system_dynamics, invariant, true, Out_Going_Trans_fromloc_5));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_6

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_6;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(16,"null",7,6,guard_polytope,assignment));

Out_Going_Trans_fromloc_6.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(17,"null",7,8,guard_polytope,assignment));

Out_Going_Trans_fromloc_6.push_back(t);
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

t = transition::ptr(new transition(18,"null",7,22,guard_polytope,assignment));

Out_Going_Trans_fromloc_6.push_back(t);
l = location::ptr(new location(7, "loc_6", system_dynamics, invariant, true, Out_Going_Trans_fromloc_6));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_7

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_7;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(19,"null",8,7,guard_polytope,assignment));

Out_Going_Trans_fromloc_7.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(20,"null",8,9,guard_polytope,assignment));

Out_Going_Trans_fromloc_7.push_back(t);
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

t = transition::ptr(new transition(21,"null",8,23,guard_polytope,assignment));

Out_Going_Trans_fromloc_7.push_back(t);
l = location::ptr(new location(8, "loc_7", system_dynamics, invariant, true, Out_Going_Trans_fromloc_7));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_8

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_8;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(22,"null",9,8,guard_polytope,assignment));

Out_Going_Trans_fromloc_8.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(23,"null",9,10,guard_polytope,assignment));

Out_Going_Trans_fromloc_8.push_back(t);
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

t = transition::ptr(new transition(24,"null",9,24,guard_polytope,assignment));

Out_Going_Trans_fromloc_8.push_back(t);
l = location::ptr(new location(9, "loc_8", system_dynamics, invariant, true, Out_Going_Trans_fromloc_8));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_9

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_9;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(25,"null",10,9,guard_polytope,assignment));

Out_Going_Trans_fromloc_9.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(26,"null",10,11,guard_polytope,assignment));

Out_Going_Trans_fromloc_9.push_back(t);
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

t = transition::ptr(new transition(27,"null",10,25,guard_polytope,assignment));

Out_Going_Trans_fromloc_9.push_back(t);
l = location::ptr(new location(10, "loc_9", system_dynamics, invariant, true, Out_Going_Trans_fromloc_9));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_10

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_10;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(28,"null",11,10,guard_polytope,assignment));

Out_Going_Trans_fromloc_10.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(29,"null",11,12,guard_polytope,assignment));

Out_Going_Trans_fromloc_10.push_back(t);
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

t = transition::ptr(new transition(30,"null",11,26,guard_polytope,assignment));

Out_Going_Trans_fromloc_10.push_back(t);
l = location::ptr(new location(11, "loc_10", system_dynamics, invariant, true, Out_Going_Trans_fromloc_10));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_11

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_11;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(31,"null",12,11,guard_polytope,assignment));

Out_Going_Trans_fromloc_11.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(32,"null",12,13,guard_polytope,assignment));

Out_Going_Trans_fromloc_11.push_back(t);
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

t = transition::ptr(new transition(33,"null",12,27,guard_polytope,assignment));

Out_Going_Trans_fromloc_11.push_back(t);
l = location::ptr(new location(12, "loc_11", system_dynamics, invariant, true, Out_Going_Trans_fromloc_11));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_12

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_12;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(34,"null",13,12,guard_polytope,assignment));

Out_Going_Trans_fromloc_12.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(35,"null",13,14,guard_polytope,assignment));

Out_Going_Trans_fromloc_12.push_back(t);
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

t = transition::ptr(new transition(36,"null",13,28,guard_polytope,assignment));

Out_Going_Trans_fromloc_12.push_back(t);
l = location::ptr(new location(13, "loc_12", system_dynamics, invariant, true, Out_Going_Trans_fromloc_12));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_13

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_13;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(37,"null",14,13,guard_polytope,assignment));

Out_Going_Trans_fromloc_13.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(38,"null",14,15,guard_polytope,assignment));

Out_Going_Trans_fromloc_13.push_back(t);
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

t = transition::ptr(new transition(39,"null",14,29,guard_polytope,assignment));

Out_Going_Trans_fromloc_13.push_back(t);
l = location::ptr(new location(14, "loc_13", system_dynamics, invariant, true, Out_Going_Trans_fromloc_13));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_14

row = 5;
col = 5;
system_dynamics.isEmptyMatrixA = true;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_14;


l = location::ptr(new location(15, "loc_14", system_dynamics, invariant, true, Out_Going_Trans_fromloc_14));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_15

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_15;

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

t = transition::ptr(new transition(40,"null",16,17,guard_polytope,assignment));

Out_Going_Trans_fromloc_15.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(41,"null",16,1,guard_polytope,assignment));

Out_Going_Trans_fromloc_15.push_back(t);
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

t = transition::ptr(new transition(42,"null",16,31,guard_polytope,assignment));

Out_Going_Trans_fromloc_15.push_back(t);
l = location::ptr(new location(16, "loc_15", system_dynamics, invariant, true, Out_Going_Trans_fromloc_15));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_16

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_16;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(43,"null",17,16,guard_polytope,assignment));

Out_Going_Trans_fromloc_16.push_back(t);
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

t = transition::ptr(new transition(44,"null",17,18,guard_polytope,assignment));

Out_Going_Trans_fromloc_16.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(45,"null",17,2,guard_polytope,assignment));

Out_Going_Trans_fromloc_16.push_back(t);
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

t = transition::ptr(new transition(46,"null",17,32,guard_polytope,assignment));

Out_Going_Trans_fromloc_16.push_back(t);
l = location::ptr(new location(17, "loc_16", system_dynamics, invariant, true, Out_Going_Trans_fromloc_16));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_17

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_17;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(47,"null",18,17,guard_polytope,assignment));

Out_Going_Trans_fromloc_17.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(48,"null",18,19,guard_polytope,assignment));

Out_Going_Trans_fromloc_17.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(49,"null",18,3,guard_polytope,assignment));

Out_Going_Trans_fromloc_17.push_back(t);
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

t = transition::ptr(new transition(50,"null",18,33,guard_polytope,assignment));

Out_Going_Trans_fromloc_17.push_back(t);
l = location::ptr(new location(18, "loc_17", system_dynamics, invariant, true, Out_Going_Trans_fromloc_17));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_18

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_18;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(51,"null",19,18,guard_polytope,assignment));

Out_Going_Trans_fromloc_18.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(52,"null",19,20,guard_polytope,assignment));

Out_Going_Trans_fromloc_18.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(53,"null",19,4,guard_polytope,assignment));

Out_Going_Trans_fromloc_18.push_back(t);
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

t = transition::ptr(new transition(54,"null",19,34,guard_polytope,assignment));

Out_Going_Trans_fromloc_18.push_back(t);
l = location::ptr(new location(19, "loc_18", system_dynamics, invariant, true, Out_Going_Trans_fromloc_18));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_19

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_19;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(55,"null",20,19,guard_polytope,assignment));

Out_Going_Trans_fromloc_19.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(56,"null",20,21,guard_polytope,assignment));

Out_Going_Trans_fromloc_19.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(57,"null",20,5,guard_polytope,assignment));

Out_Going_Trans_fromloc_19.push_back(t);
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

t = transition::ptr(new transition(58,"null",20,35,guard_polytope,assignment));

Out_Going_Trans_fromloc_19.push_back(t);
l = location::ptr(new location(20, "loc_19", system_dynamics, invariant, true, Out_Going_Trans_fromloc_19));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_20

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_20;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(59,"null",21,20,guard_polytope,assignment));

Out_Going_Trans_fromloc_20.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(60,"null",21,22,guard_polytope,assignment));

Out_Going_Trans_fromloc_20.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(61,"null",21,6,guard_polytope,assignment));

Out_Going_Trans_fromloc_20.push_back(t);
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

t = transition::ptr(new transition(62,"null",21,36,guard_polytope,assignment));

Out_Going_Trans_fromloc_20.push_back(t);
l = location::ptr(new location(21, "loc_20", system_dynamics, invariant, true, Out_Going_Trans_fromloc_20));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_21

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_21;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(63,"null",22,21,guard_polytope,assignment));

Out_Going_Trans_fromloc_21.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(64,"null",22,23,guard_polytope,assignment));

Out_Going_Trans_fromloc_21.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(65,"null",22,7,guard_polytope,assignment));

Out_Going_Trans_fromloc_21.push_back(t);
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

t = transition::ptr(new transition(66,"null",22,37,guard_polytope,assignment));

Out_Going_Trans_fromloc_21.push_back(t);
l = location::ptr(new location(22, "loc_21", system_dynamics, invariant, true, Out_Going_Trans_fromloc_21));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_22

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_22;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(67,"null",23,22,guard_polytope,assignment));

Out_Going_Trans_fromloc_22.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(68,"null",23,24,guard_polytope,assignment));

Out_Going_Trans_fromloc_22.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(69,"null",23,8,guard_polytope,assignment));

Out_Going_Trans_fromloc_22.push_back(t);
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

t = transition::ptr(new transition(70,"null",23,38,guard_polytope,assignment));

Out_Going_Trans_fromloc_22.push_back(t);
l = location::ptr(new location(23, "loc_22", system_dynamics, invariant, true, Out_Going_Trans_fromloc_22));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_23

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_23;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(71,"null",24,23,guard_polytope,assignment));

Out_Going_Trans_fromloc_23.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(72,"null",24,25,guard_polytope,assignment));

Out_Going_Trans_fromloc_23.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(73,"null",24,9,guard_polytope,assignment));

Out_Going_Trans_fromloc_23.push_back(t);
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

t = transition::ptr(new transition(74,"null",24,39,guard_polytope,assignment));

Out_Going_Trans_fromloc_23.push_back(t);
l = location::ptr(new location(24, "loc_23", system_dynamics, invariant, true, Out_Going_Trans_fromloc_23));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_24

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_24;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(75,"null",25,24,guard_polytope,assignment));

Out_Going_Trans_fromloc_24.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(76,"null",25,26,guard_polytope,assignment));

Out_Going_Trans_fromloc_24.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(77,"null",25,10,guard_polytope,assignment));

Out_Going_Trans_fromloc_24.push_back(t);
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

t = transition::ptr(new transition(78,"null",25,40,guard_polytope,assignment));

Out_Going_Trans_fromloc_24.push_back(t);
l = location::ptr(new location(25, "loc_24", system_dynamics, invariant, true, Out_Going_Trans_fromloc_24));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_25

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_25;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(79,"null",26,25,guard_polytope,assignment));

Out_Going_Trans_fromloc_25.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(80,"null",26,27,guard_polytope,assignment));

Out_Going_Trans_fromloc_25.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(81,"null",26,11,guard_polytope,assignment));

Out_Going_Trans_fromloc_25.push_back(t);
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

t = transition::ptr(new transition(82,"null",26,41,guard_polytope,assignment));

Out_Going_Trans_fromloc_25.push_back(t);
l = location::ptr(new location(26, "loc_25", system_dynamics, invariant, true, Out_Going_Trans_fromloc_25));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_26

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_26;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(83,"null",27,26,guard_polytope,assignment));

Out_Going_Trans_fromloc_26.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(84,"null",27,28,guard_polytope,assignment));

Out_Going_Trans_fromloc_26.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(85,"null",27,12,guard_polytope,assignment));

Out_Going_Trans_fromloc_26.push_back(t);
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

t = transition::ptr(new transition(86,"null",27,42,guard_polytope,assignment));

Out_Going_Trans_fromloc_26.push_back(t);
l = location::ptr(new location(27, "loc_26", system_dynamics, invariant, true, Out_Going_Trans_fromloc_26));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_27

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_27;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(87,"null",28,27,guard_polytope,assignment));

Out_Going_Trans_fromloc_27.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(88,"null",28,29,guard_polytope,assignment));

Out_Going_Trans_fromloc_27.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(89,"null",28,13,guard_polytope,assignment));

Out_Going_Trans_fromloc_27.push_back(t);
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

t = transition::ptr(new transition(90,"null",28,43,guard_polytope,assignment));

Out_Going_Trans_fromloc_27.push_back(t);
l = location::ptr(new location(28, "loc_27", system_dynamics, invariant, true, Out_Going_Trans_fromloc_27));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_28

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_28;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(91,"null",29,28,guard_polytope,assignment));

Out_Going_Trans_fromloc_28.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(92,"null",29,30,guard_polytope,assignment));

Out_Going_Trans_fromloc_28.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(93,"null",29,14,guard_polytope,assignment));

Out_Going_Trans_fromloc_28.push_back(t);
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

t = transition::ptr(new transition(94,"null",29,44,guard_polytope,assignment));

Out_Going_Trans_fromloc_28.push_back(t);
l = location::ptr(new location(29, "loc_28", system_dynamics, invariant, true, Out_Going_Trans_fromloc_28));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_29

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_29;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(95,"null",30,29,guard_polytope,assignment));

Out_Going_Trans_fromloc_29.push_back(t);
// The transition label is null

// Original guard: x2 <= 1 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(96,"null",30,15,guard_polytope,assignment));

Out_Going_Trans_fromloc_29.push_back(t);
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

t = transition::ptr(new transition(97,"null",30,45,guard_polytope,assignment));

Out_Going_Trans_fromloc_29.push_back(t);
l = location::ptr(new location(30, "loc_29", system_dynamics, invariant, true, Out_Going_Trans_fromloc_29));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_30

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_30;

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

t = transition::ptr(new transition(98,"null",31,32,guard_polytope,assignment));

Out_Going_Trans_fromloc_30.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(99,"null",31,16,guard_polytope,assignment));

Out_Going_Trans_fromloc_30.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(100,"null",31,46,guard_polytope,assignment));

Out_Going_Trans_fromloc_30.push_back(t);
l = location::ptr(new location(31, "loc_30", system_dynamics, invariant, true, Out_Going_Trans_fromloc_30));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_31

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_31;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(101,"null",32,31,guard_polytope,assignment));

Out_Going_Trans_fromloc_31.push_back(t);
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

t = transition::ptr(new transition(102,"null",32,33,guard_polytope,assignment));

Out_Going_Trans_fromloc_31.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(103,"null",32,17,guard_polytope,assignment));

Out_Going_Trans_fromloc_31.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(104,"null",32,47,guard_polytope,assignment));

Out_Going_Trans_fromloc_31.push_back(t);
l = location::ptr(new location(32, "loc_31", system_dynamics, invariant, true, Out_Going_Trans_fromloc_31));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_32

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_32;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(105,"null",33,32,guard_polytope,assignment));

Out_Going_Trans_fromloc_32.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(106,"null",33,34,guard_polytope,assignment));

Out_Going_Trans_fromloc_32.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(107,"null",33,18,guard_polytope,assignment));

Out_Going_Trans_fromloc_32.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(108,"null",33,48,guard_polytope,assignment));

Out_Going_Trans_fromloc_32.push_back(t);
l = location::ptr(new location(33, "loc_32", system_dynamics, invariant, true, Out_Going_Trans_fromloc_32));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_33

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_33;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(109,"null",34,33,guard_polytope,assignment));

Out_Going_Trans_fromloc_33.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(110,"null",34,35,guard_polytope,assignment));

Out_Going_Trans_fromloc_33.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(111,"null",34,19,guard_polytope,assignment));

Out_Going_Trans_fromloc_33.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(112,"null",34,49,guard_polytope,assignment));

Out_Going_Trans_fromloc_33.push_back(t);
l = location::ptr(new location(34, "loc_33", system_dynamics, invariant, true, Out_Going_Trans_fromloc_33));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_34

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_34;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(113,"null",35,34,guard_polytope,assignment));

Out_Going_Trans_fromloc_34.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(114,"null",35,36,guard_polytope,assignment));

Out_Going_Trans_fromloc_34.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(115,"null",35,20,guard_polytope,assignment));

Out_Going_Trans_fromloc_34.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(116,"null",35,50,guard_polytope,assignment));

Out_Going_Trans_fromloc_34.push_back(t);
l = location::ptr(new location(35, "loc_34", system_dynamics, invariant, true, Out_Going_Trans_fromloc_34));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_35

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_35;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(117,"null",36,35,guard_polytope,assignment));

Out_Going_Trans_fromloc_35.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(118,"null",36,37,guard_polytope,assignment));

Out_Going_Trans_fromloc_35.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(119,"null",36,21,guard_polytope,assignment));

Out_Going_Trans_fromloc_35.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(120,"null",36,51,guard_polytope,assignment));

Out_Going_Trans_fromloc_35.push_back(t);
l = location::ptr(new location(36, "loc_35", system_dynamics, invariant, true, Out_Going_Trans_fromloc_35));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_36

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_36;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(121,"null",37,36,guard_polytope,assignment));

Out_Going_Trans_fromloc_36.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(122,"null",37,38,guard_polytope,assignment));

Out_Going_Trans_fromloc_36.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(123,"null",37,22,guard_polytope,assignment));

Out_Going_Trans_fromloc_36.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(124,"null",37,52,guard_polytope,assignment));

Out_Going_Trans_fromloc_36.push_back(t);
l = location::ptr(new location(37, "loc_36", system_dynamics, invariant, true, Out_Going_Trans_fromloc_36));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_37

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_37;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(125,"null",38,37,guard_polytope,assignment));

Out_Going_Trans_fromloc_37.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(126,"null",38,39,guard_polytope,assignment));

Out_Going_Trans_fromloc_37.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(127,"null",38,23,guard_polytope,assignment));

Out_Going_Trans_fromloc_37.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(128,"null",38,53,guard_polytope,assignment));

Out_Going_Trans_fromloc_37.push_back(t);
l = location::ptr(new location(38, "loc_37", system_dynamics, invariant, true, Out_Going_Trans_fromloc_37));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_38

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_38;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(129,"null",39,38,guard_polytope,assignment));

Out_Going_Trans_fromloc_38.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(130,"null",39,40,guard_polytope,assignment));

Out_Going_Trans_fromloc_38.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(131,"null",39,24,guard_polytope,assignment));

Out_Going_Trans_fromloc_38.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(132,"null",39,54,guard_polytope,assignment));

Out_Going_Trans_fromloc_38.push_back(t);
l = location::ptr(new location(39, "loc_38", system_dynamics, invariant, true, Out_Going_Trans_fromloc_38));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_39

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_39;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(133,"null",40,39,guard_polytope,assignment));

Out_Going_Trans_fromloc_39.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(134,"null",40,41,guard_polytope,assignment));

Out_Going_Trans_fromloc_39.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(135,"null",40,25,guard_polytope,assignment));

Out_Going_Trans_fromloc_39.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(136,"null",40,55,guard_polytope,assignment));

Out_Going_Trans_fromloc_39.push_back(t);
l = location::ptr(new location(40, "loc_39", system_dynamics, invariant, true, Out_Going_Trans_fromloc_39));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_40

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_40;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(137,"null",41,40,guard_polytope,assignment));

Out_Going_Trans_fromloc_40.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(138,"null",41,42,guard_polytope,assignment));

Out_Going_Trans_fromloc_40.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(139,"null",41,26,guard_polytope,assignment));

Out_Going_Trans_fromloc_40.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(140,"null",41,56,guard_polytope,assignment));

Out_Going_Trans_fromloc_40.push_back(t);
l = location::ptr(new location(41, "loc_40", system_dynamics, invariant, true, Out_Going_Trans_fromloc_40));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_41

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_41;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(141,"null",42,41,guard_polytope,assignment));

Out_Going_Trans_fromloc_41.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(142,"null",42,43,guard_polytope,assignment));

Out_Going_Trans_fromloc_41.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(143,"null",42,27,guard_polytope,assignment));

Out_Going_Trans_fromloc_41.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(144,"null",42,57,guard_polytope,assignment));

Out_Going_Trans_fromloc_41.push_back(t);
l = location::ptr(new location(42, "loc_41", system_dynamics, invariant, true, Out_Going_Trans_fromloc_41));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_42

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_42;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(145,"null",43,42,guard_polytope,assignment));

Out_Going_Trans_fromloc_42.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(146,"null",43,44,guard_polytope,assignment));

Out_Going_Trans_fromloc_42.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(147,"null",43,28,guard_polytope,assignment));

Out_Going_Trans_fromloc_42.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(148,"null",43,58,guard_polytope,assignment));

Out_Going_Trans_fromloc_42.push_back(t);
l = location::ptr(new location(43, "loc_42", system_dynamics, invariant, true, Out_Going_Trans_fromloc_42));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_43

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_43;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(149,"null",44,43,guard_polytope,assignment));

Out_Going_Trans_fromloc_43.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(150,"null",44,45,guard_polytope,assignment));

Out_Going_Trans_fromloc_43.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(151,"null",44,29,guard_polytope,assignment));

Out_Going_Trans_fromloc_43.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(152,"null",44,59,guard_polytope,assignment));

Out_Going_Trans_fromloc_43.push_back(t);
l = location::ptr(new location(44, "loc_43", system_dynamics, invariant, true, Out_Going_Trans_fromloc_43));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_44

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_44;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(153,"null",45,44,guard_polytope,assignment));

Out_Going_Trans_fromloc_44.push_back(t);
// The transition label is null

// Original guard: x2 <= 2 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(154,"null",45,30,guard_polytope,assignment));

Out_Going_Trans_fromloc_44.push_back(t);
// The transition label is null

// Original guard: x2 >= 3 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(155,"null",45,60,guard_polytope,assignment));

Out_Going_Trans_fromloc_44.push_back(t);
l = location::ptr(new location(45, "loc_44", system_dynamics, invariant, true, Out_Going_Trans_fromloc_44));
Hybrid_Automata.addLocation(l);

nav22module1(Hybrid_Automata,init_state_list,reach_parameters);
nav22module2(Hybrid_Automata,init_state_list,reach_parameters);
nav22module3(Hybrid_Automata,init_state_list,reach_parameters);
nav22module4(Hybrid_Automata,init_state_list,reach_parameters);

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
boundValueI[0]=8;
boundValueI[1]=-7;
boundValueI[2]=8;
boundValueI[3]=-7;
boundValueI[4]=-0.1;
boundValueI[5]=0.4;
boundValueI[6]=-0.1;
boundValueI[7]=0.4;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =113;

symbolic_states::ptr S0;

initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

init_state_list.push_back(I0);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("x1",0);
Hybrid_Automata.insert_to_map("x2",1);
Hybrid_Automata.insert_to_map("v1",2);
Hybrid_Automata.insert_to_map("v2",3);
Hybrid_Automata.insert_to_map("t",4);

}

void nav22module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_45

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_45;

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

t = transition::ptr(new transition(156,"null",46,47,guard_polytope,assignment));

Out_Going_Trans_fromloc_45.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(157,"null",46,31,guard_polytope,assignment));

Out_Going_Trans_fromloc_45.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(158,"null",46,61,guard_polytope,assignment));

Out_Going_Trans_fromloc_45.push_back(t);
l = location::ptr(new location(46, "loc_45", system_dynamics, invariant, true, Out_Going_Trans_fromloc_45));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_46

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_46;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(159,"null",47,46,guard_polytope,assignment));

Out_Going_Trans_fromloc_46.push_back(t);
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

t = transition::ptr(new transition(160,"null",47,48,guard_polytope,assignment));

Out_Going_Trans_fromloc_46.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(161,"null",47,32,guard_polytope,assignment));

Out_Going_Trans_fromloc_46.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(162,"null",47,62,guard_polytope,assignment));

Out_Going_Trans_fromloc_46.push_back(t);
l = location::ptr(new location(47, "loc_46", system_dynamics, invariant, true, Out_Going_Trans_fromloc_46));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_47

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_47;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(163,"null",48,47,guard_polytope,assignment));

Out_Going_Trans_fromloc_47.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(164,"null",48,49,guard_polytope,assignment));

Out_Going_Trans_fromloc_47.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(165,"null",48,33,guard_polytope,assignment));

Out_Going_Trans_fromloc_47.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(166,"null",48,63,guard_polytope,assignment));

Out_Going_Trans_fromloc_47.push_back(t);
l = location::ptr(new location(48, "loc_47", system_dynamics, invariant, true, Out_Going_Trans_fromloc_47));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_48

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_48;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(167,"null",49,48,guard_polytope,assignment));

Out_Going_Trans_fromloc_48.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(168,"null",49,50,guard_polytope,assignment));

Out_Going_Trans_fromloc_48.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(169,"null",49,34,guard_polytope,assignment));

Out_Going_Trans_fromloc_48.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(170,"null",49,64,guard_polytope,assignment));

Out_Going_Trans_fromloc_48.push_back(t);
l = location::ptr(new location(49, "loc_48", system_dynamics, invariant, true, Out_Going_Trans_fromloc_48));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_49

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_49;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(171,"null",50,49,guard_polytope,assignment));

Out_Going_Trans_fromloc_49.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(172,"null",50,51,guard_polytope,assignment));

Out_Going_Trans_fromloc_49.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(173,"null",50,35,guard_polytope,assignment));

Out_Going_Trans_fromloc_49.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(174,"null",50,65,guard_polytope,assignment));

Out_Going_Trans_fromloc_49.push_back(t);
l = location::ptr(new location(50, "loc_49", system_dynamics, invariant, true, Out_Going_Trans_fromloc_49));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_50

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_50;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(175,"null",51,50,guard_polytope,assignment));

Out_Going_Trans_fromloc_50.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(176,"null",51,52,guard_polytope,assignment));

Out_Going_Trans_fromloc_50.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(177,"null",51,36,guard_polytope,assignment));

Out_Going_Trans_fromloc_50.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(178,"null",51,66,guard_polytope,assignment));

Out_Going_Trans_fromloc_50.push_back(t);
l = location::ptr(new location(51, "loc_50", system_dynamics, invariant, true, Out_Going_Trans_fromloc_50));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_51

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_51;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(179,"null",52,51,guard_polytope,assignment));

Out_Going_Trans_fromloc_51.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(180,"null",52,53,guard_polytope,assignment));

Out_Going_Trans_fromloc_51.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(181,"null",52,37,guard_polytope,assignment));

Out_Going_Trans_fromloc_51.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(182,"null",52,67,guard_polytope,assignment));

Out_Going_Trans_fromloc_51.push_back(t);
l = location::ptr(new location(52, "loc_51", system_dynamics, invariant, true, Out_Going_Trans_fromloc_51));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_52

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_52;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(183,"null",53,52,guard_polytope,assignment));

Out_Going_Trans_fromloc_52.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(184,"null",53,54,guard_polytope,assignment));

Out_Going_Trans_fromloc_52.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(185,"null",53,38,guard_polytope,assignment));

Out_Going_Trans_fromloc_52.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(186,"null",53,68,guard_polytope,assignment));

Out_Going_Trans_fromloc_52.push_back(t);
l = location::ptr(new location(53, "loc_52", system_dynamics, invariant, true, Out_Going_Trans_fromloc_52));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_53

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_53;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(187,"null",54,53,guard_polytope,assignment));

Out_Going_Trans_fromloc_53.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(188,"null",54,55,guard_polytope,assignment));

Out_Going_Trans_fromloc_53.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(189,"null",54,39,guard_polytope,assignment));

Out_Going_Trans_fromloc_53.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(190,"null",54,69,guard_polytope,assignment));

Out_Going_Trans_fromloc_53.push_back(t);
l = location::ptr(new location(54, "loc_53", system_dynamics, invariant, true, Out_Going_Trans_fromloc_53));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_54

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_54;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(191,"null",55,54,guard_polytope,assignment));

Out_Going_Trans_fromloc_54.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(192,"null",55,56,guard_polytope,assignment));

Out_Going_Trans_fromloc_54.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(193,"null",55,40,guard_polytope,assignment));

Out_Going_Trans_fromloc_54.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(194,"null",55,70,guard_polytope,assignment));

Out_Going_Trans_fromloc_54.push_back(t);
l = location::ptr(new location(55, "loc_54", system_dynamics, invariant, true, Out_Going_Trans_fromloc_54));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_55

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_55;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(195,"null",56,55,guard_polytope,assignment));

Out_Going_Trans_fromloc_55.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(196,"null",56,57,guard_polytope,assignment));

Out_Going_Trans_fromloc_55.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(197,"null",56,41,guard_polytope,assignment));

Out_Going_Trans_fromloc_55.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(198,"null",56,71,guard_polytope,assignment));

Out_Going_Trans_fromloc_55.push_back(t);
l = location::ptr(new location(56, "loc_55", system_dynamics, invariant, true, Out_Going_Trans_fromloc_55));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_56

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_56;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(199,"null",57,56,guard_polytope,assignment));

Out_Going_Trans_fromloc_56.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(200,"null",57,58,guard_polytope,assignment));

Out_Going_Trans_fromloc_56.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(201,"null",57,42,guard_polytope,assignment));

Out_Going_Trans_fromloc_56.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(202,"null",57,72,guard_polytope,assignment));

Out_Going_Trans_fromloc_56.push_back(t);
l = location::ptr(new location(57, "loc_56", system_dynamics, invariant, true, Out_Going_Trans_fromloc_56));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_57

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_57;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(203,"null",58,57,guard_polytope,assignment));

Out_Going_Trans_fromloc_57.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(204,"null",58,59,guard_polytope,assignment));

Out_Going_Trans_fromloc_57.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(205,"null",58,43,guard_polytope,assignment));

Out_Going_Trans_fromloc_57.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(206,"null",58,73,guard_polytope,assignment));

Out_Going_Trans_fromloc_57.push_back(t);
l = location::ptr(new location(58, "loc_57", system_dynamics, invariant, true, Out_Going_Trans_fromloc_57));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_58

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_58;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(207,"null",59,58,guard_polytope,assignment));

Out_Going_Trans_fromloc_58.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(208,"null",59,60,guard_polytope,assignment));

Out_Going_Trans_fromloc_58.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(209,"null",59,44,guard_polytope,assignment));

Out_Going_Trans_fromloc_58.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(210,"null",59,74,guard_polytope,assignment));

Out_Going_Trans_fromloc_58.push_back(t);
l = location::ptr(new location(59, "loc_58", system_dynamics, invariant, true, Out_Going_Trans_fromloc_58));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_59

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_59;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(211,"null",60,59,guard_polytope,assignment));

Out_Going_Trans_fromloc_59.push_back(t);
// The transition label is null

// Original guard: x2 <= 3 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(212,"null",60,45,guard_polytope,assignment));

Out_Going_Trans_fromloc_59.push_back(t);
// The transition label is null

// Original guard: x2 >= 4 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(213,"null",60,75,guard_polytope,assignment));

Out_Going_Trans_fromloc_59.push_back(t);
l = location::ptr(new location(60, "loc_59", system_dynamics, invariant, true, Out_Going_Trans_fromloc_59));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_60

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_60;

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

t = transition::ptr(new transition(214,"null",61,62,guard_polytope,assignment));

Out_Going_Trans_fromloc_60.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(215,"null",61,46,guard_polytope,assignment));

Out_Going_Trans_fromloc_60.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(216,"null",61,76,guard_polytope,assignment));

Out_Going_Trans_fromloc_60.push_back(t);
l = location::ptr(new location(61, "loc_60", system_dynamics, invariant, true, Out_Going_Trans_fromloc_60));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_61

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_61;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(217,"null",62,61,guard_polytope,assignment));

Out_Going_Trans_fromloc_61.push_back(t);
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

t = transition::ptr(new transition(218,"null",62,63,guard_polytope,assignment));

Out_Going_Trans_fromloc_61.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(219,"null",62,47,guard_polytope,assignment));

Out_Going_Trans_fromloc_61.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(220,"null",62,77,guard_polytope,assignment));

Out_Going_Trans_fromloc_61.push_back(t);
l = location::ptr(new location(62, "loc_61", system_dynamics, invariant, true, Out_Going_Trans_fromloc_61));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_62

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_62;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(221,"null",63,62,guard_polytope,assignment));

Out_Going_Trans_fromloc_62.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(222,"null",63,64,guard_polytope,assignment));

Out_Going_Trans_fromloc_62.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(223,"null",63,48,guard_polytope,assignment));

Out_Going_Trans_fromloc_62.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(224,"null",63,78,guard_polytope,assignment));

Out_Going_Trans_fromloc_62.push_back(t);
l = location::ptr(new location(63, "loc_62", system_dynamics, invariant, true, Out_Going_Trans_fromloc_62));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_63

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_63;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(225,"null",64,63,guard_polytope,assignment));

Out_Going_Trans_fromloc_63.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(226,"null",64,65,guard_polytope,assignment));

Out_Going_Trans_fromloc_63.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(227,"null",64,49,guard_polytope,assignment));

Out_Going_Trans_fromloc_63.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(228,"null",64,79,guard_polytope,assignment));

Out_Going_Trans_fromloc_63.push_back(t);
l = location::ptr(new location(64, "loc_63", system_dynamics, invariant, true, Out_Going_Trans_fromloc_63));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_64

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_64;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(229,"null",65,64,guard_polytope,assignment));

Out_Going_Trans_fromloc_64.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(230,"null",65,66,guard_polytope,assignment));

Out_Going_Trans_fromloc_64.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(231,"null",65,50,guard_polytope,assignment));

Out_Going_Trans_fromloc_64.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(232,"null",65,80,guard_polytope,assignment));

Out_Going_Trans_fromloc_64.push_back(t);
l = location::ptr(new location(65, "loc_64", system_dynamics, invariant, true, Out_Going_Trans_fromloc_64));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_65

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_65;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(233,"null",66,65,guard_polytope,assignment));

Out_Going_Trans_fromloc_65.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(234,"null",66,67,guard_polytope,assignment));

Out_Going_Trans_fromloc_65.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(235,"null",66,51,guard_polytope,assignment));

Out_Going_Trans_fromloc_65.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(236,"null",66,81,guard_polytope,assignment));

Out_Going_Trans_fromloc_65.push_back(t);
l = location::ptr(new location(66, "loc_65", system_dynamics, invariant, true, Out_Going_Trans_fromloc_65));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_66

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_66;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(237,"null",67,66,guard_polytope,assignment));

Out_Going_Trans_fromloc_66.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(238,"null",67,68,guard_polytope,assignment));

Out_Going_Trans_fromloc_66.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(239,"null",67,52,guard_polytope,assignment));

Out_Going_Trans_fromloc_66.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(240,"null",67,82,guard_polytope,assignment));

Out_Going_Trans_fromloc_66.push_back(t);
l = location::ptr(new location(67, "loc_66", system_dynamics, invariant, true, Out_Going_Trans_fromloc_66));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_67

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_67;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(241,"null",68,67,guard_polytope,assignment));

Out_Going_Trans_fromloc_67.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(242,"null",68,69,guard_polytope,assignment));

Out_Going_Trans_fromloc_67.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(243,"null",68,53,guard_polytope,assignment));

Out_Going_Trans_fromloc_67.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(244,"null",68,83,guard_polytope,assignment));

Out_Going_Trans_fromloc_67.push_back(t);
l = location::ptr(new location(68, "loc_67", system_dynamics, invariant, true, Out_Going_Trans_fromloc_67));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_68

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_68;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(245,"null",69,68,guard_polytope,assignment));

Out_Going_Trans_fromloc_68.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(246,"null",69,70,guard_polytope,assignment));

Out_Going_Trans_fromloc_68.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(247,"null",69,54,guard_polytope,assignment));

Out_Going_Trans_fromloc_68.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(248,"null",69,84,guard_polytope,assignment));

Out_Going_Trans_fromloc_68.push_back(t);
l = location::ptr(new location(69, "loc_68", system_dynamics, invariant, true, Out_Going_Trans_fromloc_68));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_69

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_69;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(249,"null",70,69,guard_polytope,assignment));

Out_Going_Trans_fromloc_69.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(250,"null",70,71,guard_polytope,assignment));

Out_Going_Trans_fromloc_69.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(251,"null",70,55,guard_polytope,assignment));

Out_Going_Trans_fromloc_69.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(252,"null",70,85,guard_polytope,assignment));

Out_Going_Trans_fromloc_69.push_back(t);
l = location::ptr(new location(70, "loc_69", system_dynamics, invariant, true, Out_Going_Trans_fromloc_69));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_70

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_70;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(253,"null",71,70,guard_polytope,assignment));

Out_Going_Trans_fromloc_70.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(254,"null",71,72,guard_polytope,assignment));

Out_Going_Trans_fromloc_70.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(255,"null",71,56,guard_polytope,assignment));

Out_Going_Trans_fromloc_70.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(256,"null",71,86,guard_polytope,assignment));

Out_Going_Trans_fromloc_70.push_back(t);
l = location::ptr(new location(71, "loc_70", system_dynamics, invariant, true, Out_Going_Trans_fromloc_70));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_71

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_71;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(257,"null",72,71,guard_polytope,assignment));

Out_Going_Trans_fromloc_71.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(258,"null",72,73,guard_polytope,assignment));

Out_Going_Trans_fromloc_71.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(259,"null",72,57,guard_polytope,assignment));

Out_Going_Trans_fromloc_71.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(260,"null",72,87,guard_polytope,assignment));

Out_Going_Trans_fromloc_71.push_back(t);
l = location::ptr(new location(72, "loc_71", system_dynamics, invariant, true, Out_Going_Trans_fromloc_71));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_72

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_72;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(261,"null",73,72,guard_polytope,assignment));

Out_Going_Trans_fromloc_72.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(262,"null",73,74,guard_polytope,assignment));

Out_Going_Trans_fromloc_72.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(263,"null",73,58,guard_polytope,assignment));

Out_Going_Trans_fromloc_72.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(264,"null",73,88,guard_polytope,assignment));

Out_Going_Trans_fromloc_72.push_back(t);
l = location::ptr(new location(73, "loc_72", system_dynamics, invariant, true, Out_Going_Trans_fromloc_72));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_73

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_73;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(265,"null",74,73,guard_polytope,assignment));

Out_Going_Trans_fromloc_73.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(266,"null",74,75,guard_polytope,assignment));

Out_Going_Trans_fromloc_73.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(267,"null",74,59,guard_polytope,assignment));

Out_Going_Trans_fromloc_73.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(268,"null",74,89,guard_polytope,assignment));

Out_Going_Trans_fromloc_73.push_back(t);
l = location::ptr(new location(74, "loc_73", system_dynamics, invariant, true, Out_Going_Trans_fromloc_73));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_74

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_74;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(269,"null",75,74,guard_polytope,assignment));

Out_Going_Trans_fromloc_74.push_back(t);
// The transition label is null

// Original guard: x2 <= 4 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(270,"null",75,60,guard_polytope,assignment));

Out_Going_Trans_fromloc_74.push_back(t);
// The transition label is null

// Original guard: x2 >= 5 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(271,"null",75,90,guard_polytope,assignment));

Out_Going_Trans_fromloc_74.push_back(t);
l = location::ptr(new location(75, "loc_74", system_dynamics, invariant, true, Out_Going_Trans_fromloc_74));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_75

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_75;

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

t = transition::ptr(new transition(272,"null",76,77,guard_polytope,assignment));

Out_Going_Trans_fromloc_75.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(273,"null",76,61,guard_polytope,assignment));

Out_Going_Trans_fromloc_75.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(274,"null",76,91,guard_polytope,assignment));

Out_Going_Trans_fromloc_75.push_back(t);
l = location::ptr(new location(76, "loc_75", system_dynamics, invariant, true, Out_Going_Trans_fromloc_75));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_76

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_76;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(275,"null",77,76,guard_polytope,assignment));

Out_Going_Trans_fromloc_76.push_back(t);
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

t = transition::ptr(new transition(276,"null",77,78,guard_polytope,assignment));

Out_Going_Trans_fromloc_76.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(277,"null",77,62,guard_polytope,assignment));

Out_Going_Trans_fromloc_76.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(278,"null",77,92,guard_polytope,assignment));

Out_Going_Trans_fromloc_76.push_back(t);
l = location::ptr(new location(77, "loc_76", system_dynamics, invariant, true, Out_Going_Trans_fromloc_76));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_77

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_77;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(279,"null",78,77,guard_polytope,assignment));

Out_Going_Trans_fromloc_77.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(280,"null",78,79,guard_polytope,assignment));

Out_Going_Trans_fromloc_77.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(281,"null",78,63,guard_polytope,assignment));

Out_Going_Trans_fromloc_77.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(282,"null",78,93,guard_polytope,assignment));

Out_Going_Trans_fromloc_77.push_back(t);
l = location::ptr(new location(78, "loc_77", system_dynamics, invariant, true, Out_Going_Trans_fromloc_77));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_78

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_78;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(283,"null",79,78,guard_polytope,assignment));

Out_Going_Trans_fromloc_78.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(284,"null",79,80,guard_polytope,assignment));

Out_Going_Trans_fromloc_78.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(285,"null",79,64,guard_polytope,assignment));

Out_Going_Trans_fromloc_78.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(286,"null",79,94,guard_polytope,assignment));

Out_Going_Trans_fromloc_78.push_back(t);
l = location::ptr(new location(79, "loc_78", system_dynamics, invariant, true, Out_Going_Trans_fromloc_78));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_79

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_79;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(287,"null",80,79,guard_polytope,assignment));

Out_Going_Trans_fromloc_79.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(288,"null",80,81,guard_polytope,assignment));

Out_Going_Trans_fromloc_79.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(289,"null",80,65,guard_polytope,assignment));

Out_Going_Trans_fromloc_79.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(290,"null",80,95,guard_polytope,assignment));

Out_Going_Trans_fromloc_79.push_back(t);
l = location::ptr(new location(80, "loc_79", system_dynamics, invariant, true, Out_Going_Trans_fromloc_79));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_80

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_80;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(291,"null",81,80,guard_polytope,assignment));

Out_Going_Trans_fromloc_80.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(292,"null",81,82,guard_polytope,assignment));

Out_Going_Trans_fromloc_80.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(293,"null",81,66,guard_polytope,assignment));

Out_Going_Trans_fromloc_80.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(294,"null",81,96,guard_polytope,assignment));

Out_Going_Trans_fromloc_80.push_back(t);
l = location::ptr(new location(81, "loc_80", system_dynamics, invariant, true, Out_Going_Trans_fromloc_80));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_81

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_81;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(295,"null",82,81,guard_polytope,assignment));

Out_Going_Trans_fromloc_81.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(296,"null",82,83,guard_polytope,assignment));

Out_Going_Trans_fromloc_81.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(297,"null",82,67,guard_polytope,assignment));

Out_Going_Trans_fromloc_81.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(298,"null",82,97,guard_polytope,assignment));

Out_Going_Trans_fromloc_81.push_back(t);
l = location::ptr(new location(82, "loc_81", system_dynamics, invariant, true, Out_Going_Trans_fromloc_81));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_82

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_82;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(299,"null",83,82,guard_polytope,assignment));

Out_Going_Trans_fromloc_82.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(300,"null",83,84,guard_polytope,assignment));

Out_Going_Trans_fromloc_82.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(301,"null",83,68,guard_polytope,assignment));

Out_Going_Trans_fromloc_82.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(302,"null",83,98,guard_polytope,assignment));

Out_Going_Trans_fromloc_82.push_back(t);
l = location::ptr(new location(83, "loc_82", system_dynamics, invariant, true, Out_Going_Trans_fromloc_82));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_83

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_83;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(303,"null",84,83,guard_polytope,assignment));

Out_Going_Trans_fromloc_83.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(304,"null",84,85,guard_polytope,assignment));

Out_Going_Trans_fromloc_83.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(305,"null",84,69,guard_polytope,assignment));

Out_Going_Trans_fromloc_83.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(306,"null",84,99,guard_polytope,assignment));

Out_Going_Trans_fromloc_83.push_back(t);
l = location::ptr(new location(84, "loc_83", system_dynamics, invariant, true, Out_Going_Trans_fromloc_83));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_84

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_84;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(307,"null",85,84,guard_polytope,assignment));

Out_Going_Trans_fromloc_84.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(308,"null",85,86,guard_polytope,assignment));

Out_Going_Trans_fromloc_84.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(309,"null",85,70,guard_polytope,assignment));

Out_Going_Trans_fromloc_84.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(310,"null",85,100,guard_polytope,assignment));

Out_Going_Trans_fromloc_84.push_back(t);
l = location::ptr(new location(85, "loc_84", system_dynamics, invariant, true, Out_Going_Trans_fromloc_84));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_85

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_85;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(311,"null",86,85,guard_polytope,assignment));

Out_Going_Trans_fromloc_85.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(312,"null",86,87,guard_polytope,assignment));

Out_Going_Trans_fromloc_85.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(313,"null",86,71,guard_polytope,assignment));

Out_Going_Trans_fromloc_85.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(314,"null",86,101,guard_polytope,assignment));

Out_Going_Trans_fromloc_85.push_back(t);
l = location::ptr(new location(86, "loc_85", system_dynamics, invariant, true, Out_Going_Trans_fromloc_85));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_86

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_86;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(315,"null",87,86,guard_polytope,assignment));

Out_Going_Trans_fromloc_86.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(316,"null",87,88,guard_polytope,assignment));

Out_Going_Trans_fromloc_86.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(317,"null",87,72,guard_polytope,assignment));

Out_Going_Trans_fromloc_86.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(318,"null",87,102,guard_polytope,assignment));

Out_Going_Trans_fromloc_86.push_back(t);
l = location::ptr(new location(87, "loc_86", system_dynamics, invariant, true, Out_Going_Trans_fromloc_86));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_87

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_87;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(319,"null",88,87,guard_polytope,assignment));

Out_Going_Trans_fromloc_87.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(320,"null",88,89,guard_polytope,assignment));

Out_Going_Trans_fromloc_87.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(321,"null",88,73,guard_polytope,assignment));

Out_Going_Trans_fromloc_87.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(322,"null",88,103,guard_polytope,assignment));

Out_Going_Trans_fromloc_87.push_back(t);
l = location::ptr(new location(88, "loc_87", system_dynamics, invariant, true, Out_Going_Trans_fromloc_87));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_88

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_88;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(323,"null",89,88,guard_polytope,assignment));

Out_Going_Trans_fromloc_88.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(324,"null",89,90,guard_polytope,assignment));

Out_Going_Trans_fromloc_88.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(325,"null",89,74,guard_polytope,assignment));

Out_Going_Trans_fromloc_88.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(326,"null",89,104,guard_polytope,assignment));

Out_Going_Trans_fromloc_88.push_back(t);
l = location::ptr(new location(89, "loc_88", system_dynamics, invariant, true, Out_Going_Trans_fromloc_88));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_89

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_89;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(327,"null",90,89,guard_polytope,assignment));

Out_Going_Trans_fromloc_89.push_back(t);
// The transition label is null

// Original guard: x2 <= 5 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(328,"null",90,75,guard_polytope,assignment));

Out_Going_Trans_fromloc_89.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(329,"null",90,105,guard_polytope,assignment));

Out_Going_Trans_fromloc_89.push_back(t);
l = location::ptr(new location(90, "loc_89", system_dynamics, invariant, true, Out_Going_Trans_fromloc_89));
Hybrid_Automata.addLocation(l);

}

void nav22module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_90

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_90;

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

t = transition::ptr(new transition(330,"null",91,92,guard_polytope,assignment));

Out_Going_Trans_fromloc_90.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(331,"null",91,76,guard_polytope,assignment));

Out_Going_Trans_fromloc_90.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(332,"null",91,106,guard_polytope,assignment));

Out_Going_Trans_fromloc_90.push_back(t);
l = location::ptr(new location(91, "loc_90", system_dynamics, invariant, true, Out_Going_Trans_fromloc_90));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_91

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_91;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(333,"null",92,91,guard_polytope,assignment));

Out_Going_Trans_fromloc_91.push_back(t);
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

t = transition::ptr(new transition(334,"null",92,93,guard_polytope,assignment));

Out_Going_Trans_fromloc_91.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(335,"null",92,77,guard_polytope,assignment));

Out_Going_Trans_fromloc_91.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(336,"null",92,107,guard_polytope,assignment));

Out_Going_Trans_fromloc_91.push_back(t);
l = location::ptr(new location(92, "loc_91", system_dynamics, invariant, true, Out_Going_Trans_fromloc_91));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_92

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_92;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(337,"null",93,92,guard_polytope,assignment));

Out_Going_Trans_fromloc_92.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(338,"null",93,94,guard_polytope,assignment));

Out_Going_Trans_fromloc_92.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(339,"null",93,78,guard_polytope,assignment));

Out_Going_Trans_fromloc_92.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(340,"null",93,108,guard_polytope,assignment));

Out_Going_Trans_fromloc_92.push_back(t);
l = location::ptr(new location(93, "loc_92", system_dynamics, invariant, true, Out_Going_Trans_fromloc_92));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_93

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_93;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(341,"null",94,93,guard_polytope,assignment));

Out_Going_Trans_fromloc_93.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(342,"null",94,95,guard_polytope,assignment));

Out_Going_Trans_fromloc_93.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(343,"null",94,79,guard_polytope,assignment));

Out_Going_Trans_fromloc_93.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(344,"null",94,109,guard_polytope,assignment));

Out_Going_Trans_fromloc_93.push_back(t);
l = location::ptr(new location(94, "loc_93", system_dynamics, invariant, true, Out_Going_Trans_fromloc_93));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_94

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_94;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(345,"null",95,94,guard_polytope,assignment));

Out_Going_Trans_fromloc_94.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(346,"null",95,96,guard_polytope,assignment));

Out_Going_Trans_fromloc_94.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(347,"null",95,80,guard_polytope,assignment));

Out_Going_Trans_fromloc_94.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(348,"null",95,110,guard_polytope,assignment));

Out_Going_Trans_fromloc_94.push_back(t);
l = location::ptr(new location(95, "loc_94", system_dynamics, invariant, true, Out_Going_Trans_fromloc_94));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_95

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_95;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(349,"null",96,95,guard_polytope,assignment));

Out_Going_Trans_fromloc_95.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(350,"null",96,97,guard_polytope,assignment));

Out_Going_Trans_fromloc_95.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(351,"null",96,81,guard_polytope,assignment));

Out_Going_Trans_fromloc_95.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(352,"null",96,111,guard_polytope,assignment));

Out_Going_Trans_fromloc_95.push_back(t);
l = location::ptr(new location(96, "loc_95", system_dynamics, invariant, true, Out_Going_Trans_fromloc_95));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_96

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_96;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(353,"null",97,96,guard_polytope,assignment));

Out_Going_Trans_fromloc_96.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(354,"null",97,98,guard_polytope,assignment));

Out_Going_Trans_fromloc_96.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(355,"null",97,82,guard_polytope,assignment));

Out_Going_Trans_fromloc_96.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(356,"null",97,112,guard_polytope,assignment));

Out_Going_Trans_fromloc_96.push_back(t);
l = location::ptr(new location(97, "loc_96", system_dynamics, invariant, true, Out_Going_Trans_fromloc_96));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_97

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_97;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(357,"null",98,97,guard_polytope,assignment));

Out_Going_Trans_fromloc_97.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(358,"null",98,99,guard_polytope,assignment));

Out_Going_Trans_fromloc_97.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(359,"null",98,83,guard_polytope,assignment));

Out_Going_Trans_fromloc_97.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(360,"null",98,113,guard_polytope,assignment));

Out_Going_Trans_fromloc_97.push_back(t);
l = location::ptr(new location(98, "loc_97", system_dynamics, invariant, true, Out_Going_Trans_fromloc_97));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_98

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_98;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(361,"null",99,98,guard_polytope,assignment));

Out_Going_Trans_fromloc_98.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(362,"null",99,100,guard_polytope,assignment));

Out_Going_Trans_fromloc_98.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(363,"null",99,84,guard_polytope,assignment));

Out_Going_Trans_fromloc_98.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(364,"null",99,114,guard_polytope,assignment));

Out_Going_Trans_fromloc_98.push_back(t);
l = location::ptr(new location(99, "loc_98", system_dynamics, invariant, true, Out_Going_Trans_fromloc_98));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_99

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_99;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(365,"null",100,99,guard_polytope,assignment));

Out_Going_Trans_fromloc_99.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(366,"null",100,101,guard_polytope,assignment));

Out_Going_Trans_fromloc_99.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(367,"null",100,85,guard_polytope,assignment));

Out_Going_Trans_fromloc_99.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(368,"null",100,115,guard_polytope,assignment));

Out_Going_Trans_fromloc_99.push_back(t);
l = location::ptr(new location(100, "loc_99", system_dynamics, invariant, true, Out_Going_Trans_fromloc_99));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_100

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_100;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(369,"null",101,100,guard_polytope,assignment));

Out_Going_Trans_fromloc_100.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(370,"null",101,102,guard_polytope,assignment));

Out_Going_Trans_fromloc_100.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(371,"null",101,86,guard_polytope,assignment));

Out_Going_Trans_fromloc_100.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(372,"null",101,116,guard_polytope,assignment));

Out_Going_Trans_fromloc_100.push_back(t);
l = location::ptr(new location(101, "loc_100", system_dynamics, invariant, true, Out_Going_Trans_fromloc_100));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_101

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_101;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(373,"null",102,101,guard_polytope,assignment));

Out_Going_Trans_fromloc_101.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(374,"null",102,103,guard_polytope,assignment));

Out_Going_Trans_fromloc_101.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(375,"null",102,87,guard_polytope,assignment));

Out_Going_Trans_fromloc_101.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(376,"null",102,117,guard_polytope,assignment));

Out_Going_Trans_fromloc_101.push_back(t);
l = location::ptr(new location(102, "loc_101", system_dynamics, invariant, true, Out_Going_Trans_fromloc_101));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_102

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_102;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(377,"null",103,102,guard_polytope,assignment));

Out_Going_Trans_fromloc_102.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(378,"null",103,104,guard_polytope,assignment));

Out_Going_Trans_fromloc_102.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(379,"null",103,88,guard_polytope,assignment));

Out_Going_Trans_fromloc_102.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(380,"null",103,118,guard_polytope,assignment));

Out_Going_Trans_fromloc_102.push_back(t);
l = location::ptr(new location(103, "loc_102", system_dynamics, invariant, true, Out_Going_Trans_fromloc_102));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_103

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_103;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(381,"null",104,103,guard_polytope,assignment));

Out_Going_Trans_fromloc_103.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(382,"null",104,105,guard_polytope,assignment));

Out_Going_Trans_fromloc_103.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(383,"null",104,89,guard_polytope,assignment));

Out_Going_Trans_fromloc_103.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(384,"null",104,119,guard_polytope,assignment));

Out_Going_Trans_fromloc_103.push_back(t);
l = location::ptr(new location(104, "loc_103", system_dynamics, invariant, true, Out_Going_Trans_fromloc_103));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_104

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_104;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(385,"null",105,104,guard_polytope,assignment));

Out_Going_Trans_fromloc_104.push_back(t);
// The transition label is null

// Original guard: x2 <= 6 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(386,"null",105,90,guard_polytope,assignment));

Out_Going_Trans_fromloc_104.push_back(t);
// The transition label is null

// Original guard: x2 >= 7 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(387,"null",105,120,guard_polytope,assignment));

Out_Going_Trans_fromloc_104.push_back(t);
l = location::ptr(new location(105, "loc_104", system_dynamics, invariant, true, Out_Going_Trans_fromloc_104));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_105

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_105;

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

t = transition::ptr(new transition(388,"null",106,107,guard_polytope,assignment));

Out_Going_Trans_fromloc_105.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(389,"null",106,91,guard_polytope,assignment));

Out_Going_Trans_fromloc_105.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(390,"null",106,121,guard_polytope,assignment));

Out_Going_Trans_fromloc_105.push_back(t);
l = location::ptr(new location(106, "loc_105", system_dynamics, invariant, true, Out_Going_Trans_fromloc_105));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_106

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_106;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(391,"null",107,106,guard_polytope,assignment));

Out_Going_Trans_fromloc_106.push_back(t);
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

t = transition::ptr(new transition(392,"null",107,108,guard_polytope,assignment));

Out_Going_Trans_fromloc_106.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(393,"null",107,92,guard_polytope,assignment));

Out_Going_Trans_fromloc_106.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(394,"null",107,122,guard_polytope,assignment));

Out_Going_Trans_fromloc_106.push_back(t);
l = location::ptr(new location(107, "loc_106", system_dynamics, invariant, true, Out_Going_Trans_fromloc_106));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_107

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_107;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(395,"null",108,107,guard_polytope,assignment));

Out_Going_Trans_fromloc_107.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(396,"null",108,109,guard_polytope,assignment));

Out_Going_Trans_fromloc_107.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(397,"null",108,93,guard_polytope,assignment));

Out_Going_Trans_fromloc_107.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(398,"null",108,123,guard_polytope,assignment));

Out_Going_Trans_fromloc_107.push_back(t);
l = location::ptr(new location(108, "loc_107", system_dynamics, invariant, true, Out_Going_Trans_fromloc_107));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_108

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_108;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(399,"null",109,108,guard_polytope,assignment));

Out_Going_Trans_fromloc_108.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(400,"null",109,110,guard_polytope,assignment));

Out_Going_Trans_fromloc_108.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(401,"null",109,94,guard_polytope,assignment));

Out_Going_Trans_fromloc_108.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(402,"null",109,124,guard_polytope,assignment));

Out_Going_Trans_fromloc_108.push_back(t);
l = location::ptr(new location(109, "loc_108", system_dynamics, invariant, true, Out_Going_Trans_fromloc_108));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_109

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_109;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(403,"null",110,109,guard_polytope,assignment));

Out_Going_Trans_fromloc_109.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(404,"null",110,111,guard_polytope,assignment));

Out_Going_Trans_fromloc_109.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(405,"null",110,95,guard_polytope,assignment));

Out_Going_Trans_fromloc_109.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(406,"null",110,125,guard_polytope,assignment));

Out_Going_Trans_fromloc_109.push_back(t);
l = location::ptr(new location(110, "loc_109", system_dynamics, invariant, true, Out_Going_Trans_fromloc_109));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_110

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_110;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(407,"null",111,110,guard_polytope,assignment));

Out_Going_Trans_fromloc_110.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(408,"null",111,112,guard_polytope,assignment));

Out_Going_Trans_fromloc_110.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(409,"null",111,96,guard_polytope,assignment));

Out_Going_Trans_fromloc_110.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(410,"null",111,126,guard_polytope,assignment));

Out_Going_Trans_fromloc_110.push_back(t);
l = location::ptr(new location(111, "loc_110", system_dynamics, invariant, true, Out_Going_Trans_fromloc_110));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_111

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_111;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(411,"null",112,111,guard_polytope,assignment));

Out_Going_Trans_fromloc_111.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(412,"null",112,113,guard_polytope,assignment));

Out_Going_Trans_fromloc_111.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(413,"null",112,97,guard_polytope,assignment));

Out_Going_Trans_fromloc_111.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(414,"null",112,127,guard_polytope,assignment));

Out_Going_Trans_fromloc_111.push_back(t);
l = location::ptr(new location(112, "loc_111", system_dynamics, invariant, true, Out_Going_Trans_fromloc_111));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_112

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_112;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(415,"null",113,112,guard_polytope,assignment));

Out_Going_Trans_fromloc_112.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(416,"null",113,114,guard_polytope,assignment));

Out_Going_Trans_fromloc_112.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(417,"null",113,98,guard_polytope,assignment));

Out_Going_Trans_fromloc_112.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(418,"null",113,128,guard_polytope,assignment));

Out_Going_Trans_fromloc_112.push_back(t);
l = location::ptr(new location(113, "loc_112", system_dynamics, invariant, true, Out_Going_Trans_fromloc_112));
Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);


// The mode name is  loc_113

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_113;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(419,"null",114,113,guard_polytope,assignment));

Out_Going_Trans_fromloc_113.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(420,"null",114,115,guard_polytope,assignment));

Out_Going_Trans_fromloc_113.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(421,"null",114,99,guard_polytope,assignment));

Out_Going_Trans_fromloc_113.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(422,"null",114,129,guard_polytope,assignment));

Out_Going_Trans_fromloc_113.push_back(t);
l = location::ptr(new location(114, "loc_113", system_dynamics, invariant, true, Out_Going_Trans_fromloc_113));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_114

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_114;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(423,"null",115,114,guard_polytope,assignment));

Out_Going_Trans_fromloc_114.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(424,"null",115,116,guard_polytope,assignment));

Out_Going_Trans_fromloc_114.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(425,"null",115,100,guard_polytope,assignment));

Out_Going_Trans_fromloc_114.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(426,"null",115,130,guard_polytope,assignment));

Out_Going_Trans_fromloc_114.push_back(t);
l = location::ptr(new location(115, "loc_114", system_dynamics, invariant, true, Out_Going_Trans_fromloc_114));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_115

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_115;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(427,"null",116,115,guard_polytope,assignment));

Out_Going_Trans_fromloc_115.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(428,"null",116,117,guard_polytope,assignment));

Out_Going_Trans_fromloc_115.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(429,"null",116,101,guard_polytope,assignment));

Out_Going_Trans_fromloc_115.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(430,"null",116,131,guard_polytope,assignment));

Out_Going_Trans_fromloc_115.push_back(t);
l = location::ptr(new location(116, "loc_115", system_dynamics, invariant, true, Out_Going_Trans_fromloc_115));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_116

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_116;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(431,"null",117,116,guard_polytope,assignment));

Out_Going_Trans_fromloc_116.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(432,"null",117,118,guard_polytope,assignment));

Out_Going_Trans_fromloc_116.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(433,"null",117,102,guard_polytope,assignment));

Out_Going_Trans_fromloc_116.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(434,"null",117,132,guard_polytope,assignment));

Out_Going_Trans_fromloc_116.push_back(t);
l = location::ptr(new location(117, "loc_116", system_dynamics, invariant, true, Out_Going_Trans_fromloc_116));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_117

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_117;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(435,"null",118,117,guard_polytope,assignment));

Out_Going_Trans_fromloc_117.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(436,"null",118,119,guard_polytope,assignment));

Out_Going_Trans_fromloc_117.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(437,"null",118,103,guard_polytope,assignment));

Out_Going_Trans_fromloc_117.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(438,"null",118,133,guard_polytope,assignment));

Out_Going_Trans_fromloc_117.push_back(t);
l = location::ptr(new location(118, "loc_117", system_dynamics, invariant, true, Out_Going_Trans_fromloc_117));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_118

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_118;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(439,"null",119,118,guard_polytope,assignment));

Out_Going_Trans_fromloc_118.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(440,"null",119,120,guard_polytope,assignment));

Out_Going_Trans_fromloc_118.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(441,"null",119,104,guard_polytope,assignment));

Out_Going_Trans_fromloc_118.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(442,"null",119,134,guard_polytope,assignment));

Out_Going_Trans_fromloc_118.push_back(t);
l = location::ptr(new location(119, "loc_118", system_dynamics, invariant, true, Out_Going_Trans_fromloc_118));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_119

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_119;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(443,"null",120,119,guard_polytope,assignment));

Out_Going_Trans_fromloc_119.push_back(t);
// The transition label is null

// Original guard: x2 <= 7 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(444,"null",120,105,guard_polytope,assignment));

Out_Going_Trans_fromloc_119.push_back(t);
// The transition label is null

// Original guard: x2 >= 8 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(445,"null",120,135,guard_polytope,assignment));

Out_Going_Trans_fromloc_119.push_back(t);
l = location::ptr(new location(120, "loc_119", system_dynamics, invariant, true, Out_Going_Trans_fromloc_119));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_120

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_120;

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

t = transition::ptr(new transition(446,"null",121,122,guard_polytope,assignment));

Out_Going_Trans_fromloc_120.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(447,"null",121,106,guard_polytope,assignment));

Out_Going_Trans_fromloc_120.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(448,"null",121,136,guard_polytope,assignment));

Out_Going_Trans_fromloc_120.push_back(t);
l = location::ptr(new location(121, "loc_120", system_dynamics, invariant, true, Out_Going_Trans_fromloc_120));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_121

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_121;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(449,"null",122,121,guard_polytope,assignment));

Out_Going_Trans_fromloc_121.push_back(t);
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

t = transition::ptr(new transition(450,"null",122,123,guard_polytope,assignment));

Out_Going_Trans_fromloc_121.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(451,"null",122,107,guard_polytope,assignment));

Out_Going_Trans_fromloc_121.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(452,"null",122,137,guard_polytope,assignment));

Out_Going_Trans_fromloc_121.push_back(t);
l = location::ptr(new location(122, "loc_121", system_dynamics, invariant, true, Out_Going_Trans_fromloc_121));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_122

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_122;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(453,"null",123,122,guard_polytope,assignment));

Out_Going_Trans_fromloc_122.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(454,"null",123,124,guard_polytope,assignment));

Out_Going_Trans_fromloc_122.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(455,"null",123,108,guard_polytope,assignment));

Out_Going_Trans_fromloc_122.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(456,"null",123,138,guard_polytope,assignment));

Out_Going_Trans_fromloc_122.push_back(t);
l = location::ptr(new location(123, "loc_122", system_dynamics, invariant, true, Out_Going_Trans_fromloc_122));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_123

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_123;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(457,"null",124,123,guard_polytope,assignment));

Out_Going_Trans_fromloc_123.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(458,"null",124,125,guard_polytope,assignment));

Out_Going_Trans_fromloc_123.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(459,"null",124,109,guard_polytope,assignment));

Out_Going_Trans_fromloc_123.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(460,"null",124,139,guard_polytope,assignment));

Out_Going_Trans_fromloc_123.push_back(t);
l = location::ptr(new location(124, "loc_123", system_dynamics, invariant, true, Out_Going_Trans_fromloc_123));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_124

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_124;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(461,"null",125,124,guard_polytope,assignment));

Out_Going_Trans_fromloc_124.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(462,"null",125,126,guard_polytope,assignment));

Out_Going_Trans_fromloc_124.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(463,"null",125,110,guard_polytope,assignment));

Out_Going_Trans_fromloc_124.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(464,"null",125,140,guard_polytope,assignment));

Out_Going_Trans_fromloc_124.push_back(t);
l = location::ptr(new location(125, "loc_124", system_dynamics, invariant, true, Out_Going_Trans_fromloc_124));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_125

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_125;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(465,"null",126,125,guard_polytope,assignment));

Out_Going_Trans_fromloc_125.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(466,"null",126,127,guard_polytope,assignment));

Out_Going_Trans_fromloc_125.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(467,"null",126,111,guard_polytope,assignment));

Out_Going_Trans_fromloc_125.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(468,"null",126,141,guard_polytope,assignment));

Out_Going_Trans_fromloc_125.push_back(t);
l = location::ptr(new location(126, "loc_125", system_dynamics, invariant, true, Out_Going_Trans_fromloc_125));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_126

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_126;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(469,"null",127,126,guard_polytope,assignment));

Out_Going_Trans_fromloc_126.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(470,"null",127,128,guard_polytope,assignment));

Out_Going_Trans_fromloc_126.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(471,"null",127,112,guard_polytope,assignment));

Out_Going_Trans_fromloc_126.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(472,"null",127,142,guard_polytope,assignment));

Out_Going_Trans_fromloc_126.push_back(t);
l = location::ptr(new location(127, "loc_126", system_dynamics, invariant, true, Out_Going_Trans_fromloc_126));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_127

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_127;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(473,"null",128,127,guard_polytope,assignment));

Out_Going_Trans_fromloc_127.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(474,"null",128,129,guard_polytope,assignment));

Out_Going_Trans_fromloc_127.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(475,"null",128,113,guard_polytope,assignment));

Out_Going_Trans_fromloc_127.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(476,"null",128,143,guard_polytope,assignment));

Out_Going_Trans_fromloc_127.push_back(t);
l = location::ptr(new location(128, "loc_127", system_dynamics, invariant, true, Out_Going_Trans_fromloc_127));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_128

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_128;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(477,"null",129,128,guard_polytope,assignment));

Out_Going_Trans_fromloc_128.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(478,"null",129,130,guard_polytope,assignment));

Out_Going_Trans_fromloc_128.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(479,"null",129,114,guard_polytope,assignment));

Out_Going_Trans_fromloc_128.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(480,"null",129,144,guard_polytope,assignment));

Out_Going_Trans_fromloc_128.push_back(t);
l = location::ptr(new location(129, "loc_128", system_dynamics, invariant, true, Out_Going_Trans_fromloc_128));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_129

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_129;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(481,"null",130,129,guard_polytope,assignment));

Out_Going_Trans_fromloc_129.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(482,"null",130,131,guard_polytope,assignment));

Out_Going_Trans_fromloc_129.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(483,"null",130,115,guard_polytope,assignment));

Out_Going_Trans_fromloc_129.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(484,"null",130,145,guard_polytope,assignment));

Out_Going_Trans_fromloc_129.push_back(t);
l = location::ptr(new location(130, "loc_129", system_dynamics, invariant, true, Out_Going_Trans_fromloc_129));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_130

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_130;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(485,"null",131,130,guard_polytope,assignment));

Out_Going_Trans_fromloc_130.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(486,"null",131,132,guard_polytope,assignment));

Out_Going_Trans_fromloc_130.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(487,"null",131,116,guard_polytope,assignment));

Out_Going_Trans_fromloc_130.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(488,"null",131,146,guard_polytope,assignment));

Out_Going_Trans_fromloc_130.push_back(t);
l = location::ptr(new location(131, "loc_130", system_dynamics, invariant, true, Out_Going_Trans_fromloc_130));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_131

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_131;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(489,"null",132,131,guard_polytope,assignment));

Out_Going_Trans_fromloc_131.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(490,"null",132,133,guard_polytope,assignment));

Out_Going_Trans_fromloc_131.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(491,"null",132,117,guard_polytope,assignment));

Out_Going_Trans_fromloc_131.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(492,"null",132,147,guard_polytope,assignment));

Out_Going_Trans_fromloc_131.push_back(t);
l = location::ptr(new location(132, "loc_131", system_dynamics, invariant, true, Out_Going_Trans_fromloc_131));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_132

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_132;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(493,"null",133,132,guard_polytope,assignment));

Out_Going_Trans_fromloc_132.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(494,"null",133,134,guard_polytope,assignment));

Out_Going_Trans_fromloc_132.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(495,"null",133,118,guard_polytope,assignment));

Out_Going_Trans_fromloc_132.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(496,"null",133,148,guard_polytope,assignment));

Out_Going_Trans_fromloc_132.push_back(t);
l = location::ptr(new location(133, "loc_132", system_dynamics, invariant, true, Out_Going_Trans_fromloc_132));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_133

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_133;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(497,"null",134,133,guard_polytope,assignment));

Out_Going_Trans_fromloc_133.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(498,"null",134,135,guard_polytope,assignment));

Out_Going_Trans_fromloc_133.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(499,"null",134,119,guard_polytope,assignment));

Out_Going_Trans_fromloc_133.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(500,"null",134,149,guard_polytope,assignment));

Out_Going_Trans_fromloc_133.push_back(t);
l = location::ptr(new location(134, "loc_133", system_dynamics, invariant, true, Out_Going_Trans_fromloc_133));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_134

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_134;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(501,"null",135,134,guard_polytope,assignment));

Out_Going_Trans_fromloc_134.push_back(t);
// The transition label is null

// Original guard: x2 <= 8 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(502,"null",135,120,guard_polytope,assignment));

Out_Going_Trans_fromloc_134.push_back(t);
// The transition label is null

// Original guard: x2 >= 9 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(503,"null",135,150,guard_polytope,assignment));

Out_Going_Trans_fromloc_134.push_back(t);
l = location::ptr(new location(135, "loc_134", system_dynamics, invariant, true, Out_Going_Trans_fromloc_134));
Hybrid_Automata.addLocation(l);

}

void nav22module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_135

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_135;

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

t = transition::ptr(new transition(504,"null",136,137,guard_polytope,assignment));

Out_Going_Trans_fromloc_135.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(505,"null",136,121,guard_polytope,assignment));

Out_Going_Trans_fromloc_135.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(506,"null",136,151,guard_polytope,assignment));

Out_Going_Trans_fromloc_135.push_back(t);
l = location::ptr(new location(136, "loc_135", system_dynamics, invariant, true, Out_Going_Trans_fromloc_135));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_136

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_136;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(507,"null",137,136,guard_polytope,assignment));

Out_Going_Trans_fromloc_136.push_back(t);
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

t = transition::ptr(new transition(508,"null",137,138,guard_polytope,assignment));

Out_Going_Trans_fromloc_136.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(509,"null",137,122,guard_polytope,assignment));

Out_Going_Trans_fromloc_136.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(510,"null",137,152,guard_polytope,assignment));

Out_Going_Trans_fromloc_136.push_back(t);
l = location::ptr(new location(137, "loc_136", system_dynamics, invariant, true, Out_Going_Trans_fromloc_136));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_137

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_137;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(511,"null",138,137,guard_polytope,assignment));

Out_Going_Trans_fromloc_137.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(512,"null",138,139,guard_polytope,assignment));

Out_Going_Trans_fromloc_137.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(513,"null",138,123,guard_polytope,assignment));

Out_Going_Trans_fromloc_137.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(514,"null",138,153,guard_polytope,assignment));

Out_Going_Trans_fromloc_137.push_back(t);
l = location::ptr(new location(138, "loc_137", system_dynamics, invariant, true, Out_Going_Trans_fromloc_137));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_138

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_138;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(515,"null",139,138,guard_polytope,assignment));

Out_Going_Trans_fromloc_138.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(516,"null",139,140,guard_polytope,assignment));

Out_Going_Trans_fromloc_138.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(517,"null",139,124,guard_polytope,assignment));

Out_Going_Trans_fromloc_138.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(518,"null",139,154,guard_polytope,assignment));

Out_Going_Trans_fromloc_138.push_back(t);
l = location::ptr(new location(139, "loc_138", system_dynamics, invariant, true, Out_Going_Trans_fromloc_138));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_139

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_139;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(519,"null",140,139,guard_polytope,assignment));

Out_Going_Trans_fromloc_139.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(520,"null",140,141,guard_polytope,assignment));

Out_Going_Trans_fromloc_139.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(521,"null",140,125,guard_polytope,assignment));

Out_Going_Trans_fromloc_139.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(522,"null",140,155,guard_polytope,assignment));

Out_Going_Trans_fromloc_139.push_back(t);
l = location::ptr(new location(140, "loc_139", system_dynamics, invariant, true, Out_Going_Trans_fromloc_139));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_140

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_140;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(523,"null",141,140,guard_polytope,assignment));

Out_Going_Trans_fromloc_140.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(524,"null",141,142,guard_polytope,assignment));

Out_Going_Trans_fromloc_140.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(525,"null",141,126,guard_polytope,assignment));

Out_Going_Trans_fromloc_140.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(526,"null",141,156,guard_polytope,assignment));

Out_Going_Trans_fromloc_140.push_back(t);
l = location::ptr(new location(141, "loc_140", system_dynamics, invariant, true, Out_Going_Trans_fromloc_140));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_141

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_141;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(527,"null",142,141,guard_polytope,assignment));

Out_Going_Trans_fromloc_141.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(528,"null",142,143,guard_polytope,assignment));

Out_Going_Trans_fromloc_141.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(529,"null",142,127,guard_polytope,assignment));

Out_Going_Trans_fromloc_141.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(530,"null",142,157,guard_polytope,assignment));

Out_Going_Trans_fromloc_141.push_back(t);
l = location::ptr(new location(142, "loc_141", system_dynamics, invariant, true, Out_Going_Trans_fromloc_141));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_142

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_142;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(531,"null",143,142,guard_polytope,assignment));

Out_Going_Trans_fromloc_142.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(532,"null",143,144,guard_polytope,assignment));

Out_Going_Trans_fromloc_142.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(533,"null",143,128,guard_polytope,assignment));

Out_Going_Trans_fromloc_142.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(534,"null",143,158,guard_polytope,assignment));

Out_Going_Trans_fromloc_142.push_back(t);
l = location::ptr(new location(143, "loc_142", system_dynamics, invariant, true, Out_Going_Trans_fromloc_142));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_143

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_143;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(535,"null",144,143,guard_polytope,assignment));

Out_Going_Trans_fromloc_143.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(536,"null",144,145,guard_polytope,assignment));

Out_Going_Trans_fromloc_143.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(537,"null",144,129,guard_polytope,assignment));

Out_Going_Trans_fromloc_143.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(538,"null",144,159,guard_polytope,assignment));

Out_Going_Trans_fromloc_143.push_back(t);
l = location::ptr(new location(144, "loc_143", system_dynamics, invariant, true, Out_Going_Trans_fromloc_143));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_144

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_144;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(539,"null",145,144,guard_polytope,assignment));

Out_Going_Trans_fromloc_144.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(540,"null",145,146,guard_polytope,assignment));

Out_Going_Trans_fromloc_144.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(541,"null",145,130,guard_polytope,assignment));

Out_Going_Trans_fromloc_144.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(542,"null",145,160,guard_polytope,assignment));

Out_Going_Trans_fromloc_144.push_back(t);
l = location::ptr(new location(145, "loc_144", system_dynamics, invariant, true, Out_Going_Trans_fromloc_144));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_145

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_145;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(543,"null",146,145,guard_polytope,assignment));

Out_Going_Trans_fromloc_145.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(544,"null",146,147,guard_polytope,assignment));

Out_Going_Trans_fromloc_145.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(545,"null",146,131,guard_polytope,assignment));

Out_Going_Trans_fromloc_145.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(546,"null",146,161,guard_polytope,assignment));

Out_Going_Trans_fromloc_145.push_back(t);
l = location::ptr(new location(146, "loc_145", system_dynamics, invariant, true, Out_Going_Trans_fromloc_145));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_146

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_146;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(547,"null",147,146,guard_polytope,assignment));

Out_Going_Trans_fromloc_146.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(548,"null",147,148,guard_polytope,assignment));

Out_Going_Trans_fromloc_146.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(549,"null",147,132,guard_polytope,assignment));

Out_Going_Trans_fromloc_146.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(550,"null",147,162,guard_polytope,assignment));

Out_Going_Trans_fromloc_146.push_back(t);
l = location::ptr(new location(147, "loc_146", system_dynamics, invariant, true, Out_Going_Trans_fromloc_146));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_147

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_147;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(551,"null",148,147,guard_polytope,assignment));

Out_Going_Trans_fromloc_147.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(552,"null",148,149,guard_polytope,assignment));

Out_Going_Trans_fromloc_147.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(553,"null",148,133,guard_polytope,assignment));

Out_Going_Trans_fromloc_147.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(554,"null",148,163,guard_polytope,assignment));

Out_Going_Trans_fromloc_147.push_back(t);
l = location::ptr(new location(148, "loc_147", system_dynamics, invariant, true, Out_Going_Trans_fromloc_147));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_148

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_148;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(555,"null",149,148,guard_polytope,assignment));

Out_Going_Trans_fromloc_148.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(556,"null",149,150,guard_polytope,assignment));

Out_Going_Trans_fromloc_148.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(557,"null",149,134,guard_polytope,assignment));

Out_Going_Trans_fromloc_148.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(558,"null",149,164,guard_polytope,assignment));

Out_Going_Trans_fromloc_148.push_back(t);
l = location::ptr(new location(149, "loc_148", system_dynamics, invariant, true, Out_Going_Trans_fromloc_148));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_149

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_149;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(559,"null",150,149,guard_polytope,assignment));

Out_Going_Trans_fromloc_149.push_back(t);
// The transition label is null

// Original guard: x2 <= 9 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(560,"null",150,135,guard_polytope,assignment));

Out_Going_Trans_fromloc_149.push_back(t);
// The transition label is null

// Original guard: x2 >= 10 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(561,"null",150,165,guard_polytope,assignment));

Out_Going_Trans_fromloc_149.push_back(t);
l = location::ptr(new location(150, "loc_149", system_dynamics, invariant, true, Out_Going_Trans_fromloc_149));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_150

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_150;

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

t = transition::ptr(new transition(562,"null",151,152,guard_polytope,assignment));

Out_Going_Trans_fromloc_150.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(563,"null",151,136,guard_polytope,assignment));

Out_Going_Trans_fromloc_150.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(564,"null",151,166,guard_polytope,assignment));

Out_Going_Trans_fromloc_150.push_back(t);
l = location::ptr(new location(151, "loc_150", system_dynamics, invariant, true, Out_Going_Trans_fromloc_150));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_151

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_151;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(565,"null",152,151,guard_polytope,assignment));

Out_Going_Trans_fromloc_151.push_back(t);
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

t = transition::ptr(new transition(566,"null",152,153,guard_polytope,assignment));

Out_Going_Trans_fromloc_151.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(567,"null",152,137,guard_polytope,assignment));

Out_Going_Trans_fromloc_151.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(568,"null",152,167,guard_polytope,assignment));

Out_Going_Trans_fromloc_151.push_back(t);
l = location::ptr(new location(152, "loc_151", system_dynamics, invariant, true, Out_Going_Trans_fromloc_151));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_152

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_152;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(569,"null",153,152,guard_polytope,assignment));

Out_Going_Trans_fromloc_152.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(570,"null",153,154,guard_polytope,assignment));

Out_Going_Trans_fromloc_152.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(571,"null",153,138,guard_polytope,assignment));

Out_Going_Trans_fromloc_152.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(572,"null",153,168,guard_polytope,assignment));

Out_Going_Trans_fromloc_152.push_back(t);
l = location::ptr(new location(153, "loc_152", system_dynamics, invariant, true, Out_Going_Trans_fromloc_152));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_153

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_153;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(573,"null",154,153,guard_polytope,assignment));

Out_Going_Trans_fromloc_153.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(574,"null",154,155,guard_polytope,assignment));

Out_Going_Trans_fromloc_153.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(575,"null",154,139,guard_polytope,assignment));

Out_Going_Trans_fromloc_153.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(576,"null",154,169,guard_polytope,assignment));

Out_Going_Trans_fromloc_153.push_back(t);
l = location::ptr(new location(154, "loc_153", system_dynamics, invariant, true, Out_Going_Trans_fromloc_153));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_154

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_154;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(577,"null",155,154,guard_polytope,assignment));

Out_Going_Trans_fromloc_154.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(578,"null",155,156,guard_polytope,assignment));

Out_Going_Trans_fromloc_154.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(579,"null",155,140,guard_polytope,assignment));

Out_Going_Trans_fromloc_154.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(580,"null",155,170,guard_polytope,assignment));

Out_Going_Trans_fromloc_154.push_back(t);
l = location::ptr(new location(155, "loc_154", system_dynamics, invariant, true, Out_Going_Trans_fromloc_154));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_155

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_155;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(581,"null",156,155,guard_polytope,assignment));

Out_Going_Trans_fromloc_155.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(582,"null",156,157,guard_polytope,assignment));

Out_Going_Trans_fromloc_155.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(583,"null",156,141,guard_polytope,assignment));

Out_Going_Trans_fromloc_155.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(584,"null",156,171,guard_polytope,assignment));

Out_Going_Trans_fromloc_155.push_back(t);
l = location::ptr(new location(156, "loc_155", system_dynamics, invariant, true, Out_Going_Trans_fromloc_155));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_156

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_156;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(585,"null",157,156,guard_polytope,assignment));

Out_Going_Trans_fromloc_156.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(586,"null",157,158,guard_polytope,assignment));

Out_Going_Trans_fromloc_156.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(587,"null",157,142,guard_polytope,assignment));

Out_Going_Trans_fromloc_156.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(588,"null",157,172,guard_polytope,assignment));

Out_Going_Trans_fromloc_156.push_back(t);
l = location::ptr(new location(157, "loc_156", system_dynamics, invariant, true, Out_Going_Trans_fromloc_156));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_157

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_157;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(589,"null",158,157,guard_polytope,assignment));

Out_Going_Trans_fromloc_157.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(590,"null",158,159,guard_polytope,assignment));

Out_Going_Trans_fromloc_157.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(591,"null",158,143,guard_polytope,assignment));

Out_Going_Trans_fromloc_157.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(592,"null",158,173,guard_polytope,assignment));

Out_Going_Trans_fromloc_157.push_back(t);
l = location::ptr(new location(158, "loc_157", system_dynamics, invariant, true, Out_Going_Trans_fromloc_157));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_158

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_158;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(593,"null",159,158,guard_polytope,assignment));

Out_Going_Trans_fromloc_158.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(594,"null",159,160,guard_polytope,assignment));

Out_Going_Trans_fromloc_158.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(595,"null",159,144,guard_polytope,assignment));

Out_Going_Trans_fromloc_158.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(596,"null",159,174,guard_polytope,assignment));

Out_Going_Trans_fromloc_158.push_back(t);
l = location::ptr(new location(159, "loc_158", system_dynamics, invariant, true, Out_Going_Trans_fromloc_158));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_159

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_159;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(597,"null",160,159,guard_polytope,assignment));

Out_Going_Trans_fromloc_159.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(598,"null",160,161,guard_polytope,assignment));

Out_Going_Trans_fromloc_159.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(599,"null",160,145,guard_polytope,assignment));

Out_Going_Trans_fromloc_159.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(600,"null",160,175,guard_polytope,assignment));

Out_Going_Trans_fromloc_159.push_back(t);
l = location::ptr(new location(160, "loc_159", system_dynamics, invariant, true, Out_Going_Trans_fromloc_159));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_160

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_160;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(601,"null",161,160,guard_polytope,assignment));

Out_Going_Trans_fromloc_160.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(602,"null",161,162,guard_polytope,assignment));

Out_Going_Trans_fromloc_160.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(603,"null",161,146,guard_polytope,assignment));

Out_Going_Trans_fromloc_160.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(604,"null",161,176,guard_polytope,assignment));

Out_Going_Trans_fromloc_160.push_back(t);
l = location::ptr(new location(161, "loc_160", system_dynamics, invariant, true, Out_Going_Trans_fromloc_160));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_161

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_161;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(605,"null",162,161,guard_polytope,assignment));

Out_Going_Trans_fromloc_161.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(606,"null",162,163,guard_polytope,assignment));

Out_Going_Trans_fromloc_161.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(607,"null",162,147,guard_polytope,assignment));

Out_Going_Trans_fromloc_161.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(608,"null",162,177,guard_polytope,assignment));

Out_Going_Trans_fromloc_161.push_back(t);
l = location::ptr(new location(162, "loc_161", system_dynamics, invariant, true, Out_Going_Trans_fromloc_161));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_162

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_162;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(609,"null",163,162,guard_polytope,assignment));

Out_Going_Trans_fromloc_162.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(610,"null",163,164,guard_polytope,assignment));

Out_Going_Trans_fromloc_162.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(611,"null",163,148,guard_polytope,assignment));

Out_Going_Trans_fromloc_162.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(612,"null",163,178,guard_polytope,assignment));

Out_Going_Trans_fromloc_162.push_back(t);
l = location::ptr(new location(163, "loc_162", system_dynamics, invariant, true, Out_Going_Trans_fromloc_162));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_163

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_163;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(613,"null",164,163,guard_polytope,assignment));

Out_Going_Trans_fromloc_163.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(614,"null",164,165,guard_polytope,assignment));

Out_Going_Trans_fromloc_163.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(615,"null",164,149,guard_polytope,assignment));

Out_Going_Trans_fromloc_163.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(616,"null",164,179,guard_polytope,assignment));

Out_Going_Trans_fromloc_163.push_back(t);
l = location::ptr(new location(164, "loc_163", system_dynamics, invariant, true, Out_Going_Trans_fromloc_163));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_164

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_164;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(617,"null",165,164,guard_polytope,assignment));

Out_Going_Trans_fromloc_164.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(618,"null",165,150,guard_polytope,assignment));

Out_Going_Trans_fromloc_164.push_back(t);
// The transition label is null

// Original guard: x2 >= 11 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(619,"null",165,180,guard_polytope,assignment));

Out_Going_Trans_fromloc_164.push_back(t);
l = location::ptr(new location(165, "loc_164", system_dynamics, invariant, true, Out_Going_Trans_fromloc_164));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_165

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_165;

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

t = transition::ptr(new transition(620,"null",166,167,guard_polytope,assignment));

Out_Going_Trans_fromloc_165.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(621,"null",166,151,guard_polytope,assignment));

Out_Going_Trans_fromloc_165.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(622,"null",166,181,guard_polytope,assignment));

Out_Going_Trans_fromloc_165.push_back(t);
l = location::ptr(new location(166, "loc_165", system_dynamics, invariant, true, Out_Going_Trans_fromloc_165));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_166

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_166;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(623,"null",167,166,guard_polytope,assignment));

Out_Going_Trans_fromloc_166.push_back(t);
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

t = transition::ptr(new transition(624,"null",167,168,guard_polytope,assignment));

Out_Going_Trans_fromloc_166.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(625,"null",167,152,guard_polytope,assignment));

Out_Going_Trans_fromloc_166.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(626,"null",167,182,guard_polytope,assignment));

Out_Going_Trans_fromloc_166.push_back(t);
l = location::ptr(new location(167, "loc_166", system_dynamics, invariant, true, Out_Going_Trans_fromloc_166));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_167

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_167;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(627,"null",168,167,guard_polytope,assignment));

Out_Going_Trans_fromloc_167.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(628,"null",168,169,guard_polytope,assignment));

Out_Going_Trans_fromloc_167.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(629,"null",168,153,guard_polytope,assignment));

Out_Going_Trans_fromloc_167.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(630,"null",168,183,guard_polytope,assignment));

Out_Going_Trans_fromloc_167.push_back(t);
l = location::ptr(new location(168, "loc_167", system_dynamics, invariant, true, Out_Going_Trans_fromloc_167));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_168

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_168;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(631,"null",169,168,guard_polytope,assignment));

Out_Going_Trans_fromloc_168.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(632,"null",169,170,guard_polytope,assignment));

Out_Going_Trans_fromloc_168.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(633,"null",169,154,guard_polytope,assignment));

Out_Going_Trans_fromloc_168.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(634,"null",169,184,guard_polytope,assignment));

Out_Going_Trans_fromloc_168.push_back(t);
l = location::ptr(new location(169, "loc_168", system_dynamics, invariant, true, Out_Going_Trans_fromloc_168));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_169

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_169;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(635,"null",170,169,guard_polytope,assignment));

Out_Going_Trans_fromloc_169.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(636,"null",170,171,guard_polytope,assignment));

Out_Going_Trans_fromloc_169.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(637,"null",170,155,guard_polytope,assignment));

Out_Going_Trans_fromloc_169.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(638,"null",170,185,guard_polytope,assignment));

Out_Going_Trans_fromloc_169.push_back(t);
l = location::ptr(new location(170, "loc_169", system_dynamics, invariant, true, Out_Going_Trans_fromloc_169));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_170

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_170;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(639,"null",171,170,guard_polytope,assignment));

Out_Going_Trans_fromloc_170.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(640,"null",171,172,guard_polytope,assignment));

Out_Going_Trans_fromloc_170.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(641,"null",171,156,guard_polytope,assignment));

Out_Going_Trans_fromloc_170.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(642,"null",171,186,guard_polytope,assignment));

Out_Going_Trans_fromloc_170.push_back(t);
l = location::ptr(new location(171, "loc_170", system_dynamics, invariant, true, Out_Going_Trans_fromloc_170));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_171

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_171;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(643,"null",172,171,guard_polytope,assignment));

Out_Going_Trans_fromloc_171.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(644,"null",172,173,guard_polytope,assignment));

Out_Going_Trans_fromloc_171.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(645,"null",172,157,guard_polytope,assignment));

Out_Going_Trans_fromloc_171.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(646,"null",172,187,guard_polytope,assignment));

Out_Going_Trans_fromloc_171.push_back(t);
l = location::ptr(new location(172, "loc_171", system_dynamics, invariant, true, Out_Going_Trans_fromloc_171));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_172

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_172;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(647,"null",173,172,guard_polytope,assignment));

Out_Going_Trans_fromloc_172.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(648,"null",173,174,guard_polytope,assignment));

Out_Going_Trans_fromloc_172.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(649,"null",173,158,guard_polytope,assignment));

Out_Going_Trans_fromloc_172.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(650,"null",173,188,guard_polytope,assignment));

Out_Going_Trans_fromloc_172.push_back(t);
l = location::ptr(new location(173, "loc_172", system_dynamics, invariant, true, Out_Going_Trans_fromloc_172));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_173

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_173;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(651,"null",174,173,guard_polytope,assignment));

Out_Going_Trans_fromloc_173.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(652,"null",174,175,guard_polytope,assignment));

Out_Going_Trans_fromloc_173.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(653,"null",174,159,guard_polytope,assignment));

Out_Going_Trans_fromloc_173.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(654,"null",174,189,guard_polytope,assignment));

Out_Going_Trans_fromloc_173.push_back(t);
l = location::ptr(new location(174, "loc_173", system_dynamics, invariant, true, Out_Going_Trans_fromloc_173));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_174

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_174;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(655,"null",175,174,guard_polytope,assignment));

Out_Going_Trans_fromloc_174.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(656,"null",175,176,guard_polytope,assignment));

Out_Going_Trans_fromloc_174.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(657,"null",175,160,guard_polytope,assignment));

Out_Going_Trans_fromloc_174.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(658,"null",175,190,guard_polytope,assignment));

Out_Going_Trans_fromloc_174.push_back(t);
l = location::ptr(new location(175, "loc_174", system_dynamics, invariant, true, Out_Going_Trans_fromloc_174));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_175

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_175;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(659,"null",176,175,guard_polytope,assignment));

Out_Going_Trans_fromloc_175.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(660,"null",176,177,guard_polytope,assignment));

Out_Going_Trans_fromloc_175.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(661,"null",176,161,guard_polytope,assignment));

Out_Going_Trans_fromloc_175.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(662,"null",176,191,guard_polytope,assignment));

Out_Going_Trans_fromloc_175.push_back(t);
l = location::ptr(new location(176, "loc_175", system_dynamics, invariant, true, Out_Going_Trans_fromloc_175));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_176

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_176;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(663,"null",177,176,guard_polytope,assignment));

Out_Going_Trans_fromloc_176.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(664,"null",177,178,guard_polytope,assignment));

Out_Going_Trans_fromloc_176.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(665,"null",177,162,guard_polytope,assignment));

Out_Going_Trans_fromloc_176.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(666,"null",177,192,guard_polytope,assignment));

Out_Going_Trans_fromloc_176.push_back(t);
l = location::ptr(new location(177, "loc_176", system_dynamics, invariant, true, Out_Going_Trans_fromloc_176));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_177

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_177;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(667,"null",178,177,guard_polytope,assignment));

Out_Going_Trans_fromloc_177.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(668,"null",178,179,guard_polytope,assignment));

Out_Going_Trans_fromloc_177.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(669,"null",178,163,guard_polytope,assignment));

Out_Going_Trans_fromloc_177.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(670,"null",178,193,guard_polytope,assignment));

Out_Going_Trans_fromloc_177.push_back(t);
l = location::ptr(new location(178, "loc_177", system_dynamics, invariant, true, Out_Going_Trans_fromloc_177));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_178

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_178;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(671,"null",179,178,guard_polytope,assignment));

Out_Going_Trans_fromloc_178.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(672,"null",179,180,guard_polytope,assignment));

Out_Going_Trans_fromloc_178.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(673,"null",179,164,guard_polytope,assignment));

Out_Going_Trans_fromloc_178.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(674,"null",179,194,guard_polytope,assignment));

Out_Going_Trans_fromloc_178.push_back(t);
l = location::ptr(new location(179, "loc_178", system_dynamics, invariant, true, Out_Going_Trans_fromloc_178));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_179

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_179;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(675,"null",180,179,guard_polytope,assignment));

Out_Going_Trans_fromloc_179.push_back(t);
// The transition label is null

// Original guard: x2 <= 11 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(676,"null",180,165,guard_polytope,assignment));

Out_Going_Trans_fromloc_179.push_back(t);
// The transition label is null

// Original guard: x2 >= 12 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(677,"null",180,195,guard_polytope,assignment));

Out_Going_Trans_fromloc_179.push_back(t);
l = location::ptr(new location(180, "loc_179", system_dynamics, invariant, true, Out_Going_Trans_fromloc_179));
Hybrid_Automata.addLocation(l);

}

void nav22module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_180

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_180;

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

t = transition::ptr(new transition(678,"null",181,182,guard_polytope,assignment));

Out_Going_Trans_fromloc_180.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(679,"null",181,166,guard_polytope,assignment));

Out_Going_Trans_fromloc_180.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(680,"null",181,196,guard_polytope,assignment));

Out_Going_Trans_fromloc_180.push_back(t);
l = location::ptr(new location(181, "loc_180", system_dynamics, invariant, true, Out_Going_Trans_fromloc_180));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_181

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_181;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(681,"null",182,181,guard_polytope,assignment));

Out_Going_Trans_fromloc_181.push_back(t);
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

t = transition::ptr(new transition(682,"null",182,183,guard_polytope,assignment));

Out_Going_Trans_fromloc_181.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(683,"null",182,167,guard_polytope,assignment));

Out_Going_Trans_fromloc_181.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(684,"null",182,197,guard_polytope,assignment));

Out_Going_Trans_fromloc_181.push_back(t);
l = location::ptr(new location(182, "loc_181", system_dynamics, invariant, true, Out_Going_Trans_fromloc_181));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_182

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.89999998;
C[3] = -0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_182;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(685,"null",183,182,guard_polytope,assignment));

Out_Going_Trans_fromloc_182.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(686,"null",183,184,guard_polytope,assignment));

Out_Going_Trans_fromloc_182.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(687,"null",183,168,guard_polytope,assignment));

Out_Going_Trans_fromloc_182.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(688,"null",183,198,guard_polytope,assignment));

Out_Going_Trans_fromloc_182.push_back(t);
l = location::ptr(new location(183, "loc_182", system_dynamics, invariant, true, Out_Going_Trans_fromloc_182));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_183

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_183;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(689,"null",184,183,guard_polytope,assignment));

Out_Going_Trans_fromloc_183.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(690,"null",184,185,guard_polytope,assignment));

Out_Going_Trans_fromloc_183.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(691,"null",184,169,guard_polytope,assignment));

Out_Going_Trans_fromloc_183.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(692,"null",184,199,guard_polytope,assignment));

Out_Going_Trans_fromloc_183.push_back(t);
l = location::ptr(new location(184, "loc_183", system_dynamics, invariant, true, Out_Going_Trans_fromloc_183));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_184

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_184;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(693,"null",185,184,guard_polytope,assignment));

Out_Going_Trans_fromloc_184.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(694,"null",185,186,guard_polytope,assignment));

Out_Going_Trans_fromloc_184.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(695,"null",185,170,guard_polytope,assignment));

Out_Going_Trans_fromloc_184.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(696,"null",185,200,guard_polytope,assignment));

Out_Going_Trans_fromloc_184.push_back(t);
l = location::ptr(new location(185, "loc_184", system_dynamics, invariant, true, Out_Going_Trans_fromloc_184));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_185

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_185;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(697,"null",186,185,guard_polytope,assignment));

Out_Going_Trans_fromloc_185.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(698,"null",186,187,guard_polytope,assignment));

Out_Going_Trans_fromloc_185.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(699,"null",186,171,guard_polytope,assignment));

Out_Going_Trans_fromloc_185.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(700,"null",186,201,guard_polytope,assignment));

Out_Going_Trans_fromloc_185.push_back(t);
l = location::ptr(new location(186, "loc_185", system_dynamics, invariant, true, Out_Going_Trans_fromloc_185));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_186

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_186;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(701,"null",187,186,guard_polytope,assignment));

Out_Going_Trans_fromloc_186.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(702,"null",187,188,guard_polytope,assignment));

Out_Going_Trans_fromloc_186.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(703,"null",187,172,guard_polytope,assignment));

Out_Going_Trans_fromloc_186.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(704,"null",187,202,guard_polytope,assignment));

Out_Going_Trans_fromloc_186.push_back(t);
l = location::ptr(new location(187, "loc_186", system_dynamics, invariant, true, Out_Going_Trans_fromloc_186));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_187

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_187;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(705,"null",188,187,guard_polytope,assignment));

Out_Going_Trans_fromloc_187.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(706,"null",188,189,guard_polytope,assignment));

Out_Going_Trans_fromloc_187.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(707,"null",188,173,guard_polytope,assignment));

Out_Going_Trans_fromloc_187.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(708,"null",188,203,guard_polytope,assignment));

Out_Going_Trans_fromloc_187.push_back(t);
l = location::ptr(new location(188, "loc_187", system_dynamics, invariant, true, Out_Going_Trans_fromloc_187));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_188

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_188;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(709,"null",189,188,guard_polytope,assignment));

Out_Going_Trans_fromloc_188.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(710,"null",189,190,guard_polytope,assignment));

Out_Going_Trans_fromloc_188.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(711,"null",189,174,guard_polytope,assignment));

Out_Going_Trans_fromloc_188.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(712,"null",189,204,guard_polytope,assignment));

Out_Going_Trans_fromloc_188.push_back(t);
l = location::ptr(new location(189, "loc_188", system_dynamics, invariant, true, Out_Going_Trans_fromloc_188));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_189

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_189;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(713,"null",190,189,guard_polytope,assignment));

Out_Going_Trans_fromloc_189.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(714,"null",190,191,guard_polytope,assignment));

Out_Going_Trans_fromloc_189.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(715,"null",190,175,guard_polytope,assignment));

Out_Going_Trans_fromloc_189.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(716,"null",190,205,guard_polytope,assignment));

Out_Going_Trans_fromloc_189.push_back(t);
l = location::ptr(new location(190, "loc_189", system_dynamics, invariant, true, Out_Going_Trans_fromloc_189));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_190

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_190;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(717,"null",191,190,guard_polytope,assignment));

Out_Going_Trans_fromloc_190.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(718,"null",191,192,guard_polytope,assignment));

Out_Going_Trans_fromloc_190.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(719,"null",191,176,guard_polytope,assignment));

Out_Going_Trans_fromloc_190.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(720,"null",191,206,guard_polytope,assignment));

Out_Going_Trans_fromloc_190.push_back(t);
l = location::ptr(new location(191, "loc_190", system_dynamics, invariant, true, Out_Going_Trans_fromloc_190));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_191

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_191;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(721,"null",192,191,guard_polytope,assignment));

Out_Going_Trans_fromloc_191.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(722,"null",192,193,guard_polytope,assignment));

Out_Going_Trans_fromloc_191.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(723,"null",192,177,guard_polytope,assignment));

Out_Going_Trans_fromloc_191.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(724,"null",192,207,guard_polytope,assignment));

Out_Going_Trans_fromloc_191.push_back(t);
l = location::ptr(new location(192, "loc_191", system_dynamics, invariant, true, Out_Going_Trans_fromloc_191));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_192

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_192;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(725,"null",193,192,guard_polytope,assignment));

Out_Going_Trans_fromloc_192.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(726,"null",193,194,guard_polytope,assignment));

Out_Going_Trans_fromloc_192.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(727,"null",193,178,guard_polytope,assignment));

Out_Going_Trans_fromloc_192.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(728,"null",193,208,guard_polytope,assignment));

Out_Going_Trans_fromloc_192.push_back(t);
l = location::ptr(new location(193, "loc_192", system_dynamics, invariant, true, Out_Going_Trans_fromloc_192));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_193

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_193;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(729,"null",194,193,guard_polytope,assignment));

Out_Going_Trans_fromloc_193.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(730,"null",194,195,guard_polytope,assignment));

Out_Going_Trans_fromloc_193.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(731,"null",194,179,guard_polytope,assignment));

Out_Going_Trans_fromloc_193.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(732,"null",194,209,guard_polytope,assignment));

Out_Going_Trans_fromloc_193.push_back(t);
l = location::ptr(new location(194, "loc_193", system_dynamics, invariant, true, Out_Going_Trans_fromloc_193));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_194

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_194;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(733,"null",195,194,guard_polytope,assignment));

Out_Going_Trans_fromloc_194.push_back(t);
// The transition label is null

// Original guard: x2 <= 12 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(734,"null",195,180,guard_polytope,assignment));

Out_Going_Trans_fromloc_194.push_back(t);
// The transition label is null

// Original guard: x2 >= 13 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(735,"null",195,210,guard_polytope,assignment));

Out_Going_Trans_fromloc_194.push_back(t);
l = location::ptr(new location(195, "loc_194", system_dynamics, invariant, true, Out_Going_Trans_fromloc_194));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_195

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_195;

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

t = transition::ptr(new transition(736,"null",196,197,guard_polytope,assignment));

Out_Going_Trans_fromloc_195.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(737,"null",196,181,guard_polytope,assignment));

Out_Going_Trans_fromloc_195.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(738,"null",196,211,guard_polytope,assignment));

Out_Going_Trans_fromloc_195.push_back(t);
l = location::ptr(new location(196, "loc_195", system_dynamics, invariant, true, Out_Going_Trans_fromloc_195));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_196

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.2828426978578645;
C[3] = 0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_196;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(739,"null",197,196,guard_polytope,assignment));

Out_Going_Trans_fromloc_196.push_back(t);
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

t = transition::ptr(new transition(740,"null",197,198,guard_polytope,assignment));

Out_Going_Trans_fromloc_196.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(741,"null",197,182,guard_polytope,assignment));

Out_Going_Trans_fromloc_196.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(742,"null",197,212,guard_polytope,assignment));

Out_Going_Trans_fromloc_196.push_back(t);
l = location::ptr(new location(197, "loc_196", system_dynamics, invariant, true, Out_Going_Trans_fromloc_196));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_197

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_197;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(743,"null",198,197,guard_polytope,assignment));

Out_Going_Trans_fromloc_197.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(744,"null",198,199,guard_polytope,assignment));

Out_Going_Trans_fromloc_197.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(745,"null",198,183,guard_polytope,assignment));

Out_Going_Trans_fromloc_197.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(746,"null",198,213,guard_polytope,assignment));

Out_Going_Trans_fromloc_197.push_back(t);
l = location::ptr(new location(198, "loc_197", system_dynamics, invariant, true, Out_Going_Trans_fromloc_197));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_198

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_198;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(747,"null",199,198,guard_polytope,assignment));

Out_Going_Trans_fromloc_198.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(748,"null",199,200,guard_polytope,assignment));

Out_Going_Trans_fromloc_198.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(749,"null",199,184,guard_polytope,assignment));

Out_Going_Trans_fromloc_198.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(750,"null",199,214,guard_polytope,assignment));

Out_Going_Trans_fromloc_198.push_back(t);
l = location::ptr(new location(199, "loc_198", system_dynamics, invariant, true, Out_Going_Trans_fromloc_198));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_199

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_199;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(751,"null",200,199,guard_polytope,assignment));

Out_Going_Trans_fromloc_199.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(752,"null",200,201,guard_polytope,assignment));

Out_Going_Trans_fromloc_199.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(753,"null",200,185,guard_polytope,assignment));

Out_Going_Trans_fromloc_199.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(754,"null",200,215,guard_polytope,assignment));

Out_Going_Trans_fromloc_199.push_back(t);
l = location::ptr(new location(200, "loc_199", system_dynamics, invariant, true, Out_Going_Trans_fromloc_199));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_200

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_200;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(755,"null",201,200,guard_polytope,assignment));

Out_Going_Trans_fromloc_200.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(756,"null",201,202,guard_polytope,assignment));

Out_Going_Trans_fromloc_200.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(757,"null",201,186,guard_polytope,assignment));

Out_Going_Trans_fromloc_200.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(758,"null",201,216,guard_polytope,assignment));

Out_Going_Trans_fromloc_200.push_back(t);
l = location::ptr(new location(201, "loc_200", system_dynamics, invariant, true, Out_Going_Trans_fromloc_200));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_201

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_201;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(759,"null",202,201,guard_polytope,assignment));

Out_Going_Trans_fromloc_201.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(760,"null",202,203,guard_polytope,assignment));

Out_Going_Trans_fromloc_201.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(761,"null",202,187,guard_polytope,assignment));

Out_Going_Trans_fromloc_201.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(762,"null",202,217,guard_polytope,assignment));

Out_Going_Trans_fromloc_201.push_back(t);
l = location::ptr(new location(202, "loc_201", system_dynamics, invariant, true, Out_Going_Trans_fromloc_201));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_202

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_202;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(763,"null",203,202,guard_polytope,assignment));

Out_Going_Trans_fromloc_202.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(764,"null",203,204,guard_polytope,assignment));

Out_Going_Trans_fromloc_202.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(765,"null",203,188,guard_polytope,assignment));

Out_Going_Trans_fromloc_202.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(766,"null",203,218,guard_polytope,assignment));

Out_Going_Trans_fromloc_202.push_back(t);
l = location::ptr(new location(203, "loc_202", system_dynamics, invariant, true, Out_Going_Trans_fromloc_202));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_203

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_203;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(767,"null",204,203,guard_polytope,assignment));

Out_Going_Trans_fromloc_203.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(768,"null",204,205,guard_polytope,assignment));

Out_Going_Trans_fromloc_203.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(769,"null",204,189,guard_polytope,assignment));

Out_Going_Trans_fromloc_203.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(770,"null",204,219,guard_polytope,assignment));

Out_Going_Trans_fromloc_203.push_back(t);
l = location::ptr(new location(204, "loc_203", system_dynamics, invariant, true, Out_Going_Trans_fromloc_203));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_204

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_204;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(771,"null",205,204,guard_polytope,assignment));

Out_Going_Trans_fromloc_204.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(772,"null",205,206,guard_polytope,assignment));

Out_Going_Trans_fromloc_204.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(773,"null",205,190,guard_polytope,assignment));

Out_Going_Trans_fromloc_204.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(774,"null",205,220,guard_polytope,assignment));

Out_Going_Trans_fromloc_204.push_back(t);
l = location::ptr(new location(205, "loc_204", system_dynamics, invariant, true, Out_Going_Trans_fromloc_204));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_205

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_205;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(775,"null",206,205,guard_polytope,assignment));

Out_Going_Trans_fromloc_205.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(776,"null",206,207,guard_polytope,assignment));

Out_Going_Trans_fromloc_205.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(777,"null",206,191,guard_polytope,assignment));

Out_Going_Trans_fromloc_205.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(778,"null",206,221,guard_polytope,assignment));

Out_Going_Trans_fromloc_205.push_back(t);
l = location::ptr(new location(206, "loc_205", system_dynamics, invariant, true, Out_Going_Trans_fromloc_205));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_206

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_206;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(779,"null",207,206,guard_polytope,assignment));

Out_Going_Trans_fromloc_206.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(780,"null",207,208,guard_polytope,assignment));

Out_Going_Trans_fromloc_206.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(781,"null",207,192,guard_polytope,assignment));

Out_Going_Trans_fromloc_206.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(782,"null",207,222,guard_polytope,assignment));

Out_Going_Trans_fromloc_206.push_back(t);
l = location::ptr(new location(207, "loc_206", system_dynamics, invariant, true, Out_Going_Trans_fromloc_206));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_207

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_207;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(783,"null",208,207,guard_polytope,assignment));

Out_Going_Trans_fromloc_207.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(784,"null",208,209,guard_polytope,assignment));

Out_Going_Trans_fromloc_207.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(785,"null",208,193,guard_polytope,assignment));

Out_Going_Trans_fromloc_207.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(786,"null",208,223,guard_polytope,assignment));

Out_Going_Trans_fromloc_207.push_back(t);
l = location::ptr(new location(208, "loc_207", system_dynamics, invariant, true, Out_Going_Trans_fromloc_207));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_208

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_208;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(787,"null",209,208,guard_polytope,assignment));

Out_Going_Trans_fromloc_208.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(788,"null",209,210,guard_polytope,assignment));

Out_Going_Trans_fromloc_208.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(789,"null",209,194,guard_polytope,assignment));

Out_Going_Trans_fromloc_208.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(790,"null",209,224,guard_polytope,assignment));

Out_Going_Trans_fromloc_208.push_back(t);
l = location::ptr(new location(209, "loc_208", system_dynamics, invariant, true, Out_Going_Trans_fromloc_208));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_209

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_209;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(791,"null",210,209,guard_polytope,assignment));

Out_Going_Trans_fromloc_209.push_back(t);
// The transition label is null

// Original guard: x2 <= 13 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(792,"null",210,195,guard_polytope,assignment));

Out_Going_Trans_fromloc_209.push_back(t);
// The transition label is null

// Original guard: x2 >= 14 - 0 & v2 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,3) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(793,"null",210,225,guard_polytope,assignment));

Out_Going_Trans_fromloc_209.push_back(t);
l = location::ptr(new location(210, "loc_209", system_dynamics, invariant, true, Out_Going_Trans_fromloc_209));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_210

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.9899494778578646;
C[3] = 0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_210;

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

t = transition::ptr(new transition(794,"null",211,212,guard_polytope,assignment));

Out_Going_Trans_fromloc_210.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(795,"null",211,196,guard_polytope,assignment));

Out_Going_Trans_fromloc_210.push_back(t);
l = location::ptr(new location(211, "loc_210", system_dynamics, invariant, true, Out_Going_Trans_fromloc_210));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_211

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_211;

// The transition label is null

// Original guard: x1 <= 1 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 1.0;
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

t = transition::ptr(new transition(796,"null",212,211,guard_polytope,assignment));

Out_Going_Trans_fromloc_211.push_back(t);
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

t = transition::ptr(new transition(797,"null",212,213,guard_polytope,assignment));

Out_Going_Trans_fromloc_211.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(798,"null",212,197,guard_polytope,assignment));

Out_Going_Trans_fromloc_211.push_back(t);
l = location::ptr(new location(212, "loc_211", system_dynamics, invariant, true, Out_Going_Trans_fromloc_211));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_212

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_212;

// The transition label is null

// Original guard: x1 <= 2 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 2.0;
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

t = transition::ptr(new transition(799,"null",213,212,guard_polytope,assignment));

Out_Going_Trans_fromloc_212.push_back(t);
// The transition label is null

// Original guard: x1 >= 3 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
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

t = transition::ptr(new transition(800,"null",213,214,guard_polytope,assignment));

Out_Going_Trans_fromloc_212.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(801,"null",213,198,guard_polytope,assignment));

Out_Going_Trans_fromloc_212.push_back(t);
l = location::ptr(new location(213, "loc_212", system_dynamics, invariant, true, Out_Going_Trans_fromloc_212));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_213

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.89999998;
C[3] = 0.1;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_213;

// The transition label is null

// Original guard: x1 <= 3 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 3.0;
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

t = transition::ptr(new transition(802,"null",214,213,guard_polytope,assignment));

Out_Going_Trans_fromloc_213.push_back(t);
// The transition label is null

// Original guard: x1 >= 4 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
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

t = transition::ptr(new transition(803,"null",214,215,guard_polytope,assignment));

Out_Going_Trans_fromloc_213.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(804,"null",214,199,guard_polytope,assignment));

Out_Going_Trans_fromloc_213.push_back(t);
l = location::ptr(new location(214, "loc_213", system_dynamics, invariant, true, Out_Going_Trans_fromloc_213));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_214

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_214;

// The transition label is null

// Original guard: x1 <= 4 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 4.0;
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

t = transition::ptr(new transition(805,"null",215,214,guard_polytope,assignment));

Out_Going_Trans_fromloc_214.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
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

t = transition::ptr(new transition(806,"null",215,216,guard_polytope,assignment));

Out_Going_Trans_fromloc_214.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(807,"null",215,200,guard_polytope,assignment));

Out_Going_Trans_fromloc_214.push_back(t);
l = location::ptr(new location(215, "loc_214", system_dynamics, invariant, true, Out_Going_Trans_fromloc_214));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_215

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_215;

// The transition label is null

// Original guard: x1 <= 5 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 5.0;
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

t = transition::ptr(new transition(808,"null",216,215,guard_polytope,assignment));

Out_Going_Trans_fromloc_215.push_back(t);
// The transition label is null

// Original guard: x1 >= 6 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
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

t = transition::ptr(new transition(809,"null",216,217,guard_polytope,assignment));

Out_Going_Trans_fromloc_215.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(810,"null",216,201,guard_polytope,assignment));

Out_Going_Trans_fromloc_215.push_back(t);
l = location::ptr(new location(216, "loc_215", system_dynamics, invariant, true, Out_Going_Trans_fromloc_215));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_216

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_216;

// The transition label is null

// Original guard: x1 <= 6 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 6.0;
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

t = transition::ptr(new transition(811,"null",217,216,guard_polytope,assignment));

Out_Going_Trans_fromloc_216.push_back(t);
// The transition label is null

// Original guard: x1 >= 7 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
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

t = transition::ptr(new transition(812,"null",217,218,guard_polytope,assignment));

Out_Going_Trans_fromloc_216.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(813,"null",217,202,guard_polytope,assignment));

Out_Going_Trans_fromloc_216.push_back(t);
l = location::ptr(new location(217, "loc_216", system_dynamics, invariant, true, Out_Going_Trans_fromloc_216));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_217

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_217;

// The transition label is null

// Original guard: x1 <= 7 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 7.0;
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

t = transition::ptr(new transition(814,"null",218,217,guard_polytope,assignment));

Out_Going_Trans_fromloc_217.push_back(t);
// The transition label is null

// Original guard: x1 >= 8 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
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

t = transition::ptr(new transition(815,"null",218,219,guard_polytope,assignment));

Out_Going_Trans_fromloc_217.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(816,"null",218,203,guard_polytope,assignment));

Out_Going_Trans_fromloc_217.push_back(t);
l = location::ptr(new location(218, "loc_217", system_dynamics, invariant, true, Out_Going_Trans_fromloc_217));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_218

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_218;

// The transition label is null

// Original guard: x1 <= 8 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 8.0;
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

t = transition::ptr(new transition(817,"null",219,218,guard_polytope,assignment));

Out_Going_Trans_fromloc_218.push_back(t);
// The transition label is null

// Original guard: x1 >= 9 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -9.0;
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

t = transition::ptr(new transition(818,"null",219,220,guard_polytope,assignment));

Out_Going_Trans_fromloc_218.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(819,"null",219,204,guard_polytope,assignment));

Out_Going_Trans_fromloc_218.push_back(t);
l = location::ptr(new location(219, "loc_218", system_dynamics, invariant, true, Out_Going_Trans_fromloc_218));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_219

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_219;

// The transition label is null

// Original guard: x1 <= 9 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 9.0;
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

t = transition::ptr(new transition(820,"null",220,219,guard_polytope,assignment));

Out_Going_Trans_fromloc_219.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -10.0;
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

t = transition::ptr(new transition(821,"null",220,221,guard_polytope,assignment));

Out_Going_Trans_fromloc_219.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(822,"null",220,205,guard_polytope,assignment));

Out_Going_Trans_fromloc_219.push_back(t);
l = location::ptr(new location(220, "loc_219", system_dynamics, invariant, true, Out_Going_Trans_fromloc_219));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_220

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_220;

// The transition label is null

// Original guard: x1 <= 10 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 10.0;
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

t = transition::ptr(new transition(823,"null",221,220,guard_polytope,assignment));

Out_Going_Trans_fromloc_220.push_back(t);
// The transition label is null

// Original guard: x1 >= 11 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -11.0;
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

t = transition::ptr(new transition(824,"null",221,222,guard_polytope,assignment));

Out_Going_Trans_fromloc_220.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(825,"null",221,206,guard_polytope,assignment));

Out_Going_Trans_fromloc_220.push_back(t);
l = location::ptr(new location(221, "loc_220", system_dynamics, invariant, true, Out_Going_Trans_fromloc_220));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_221

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_221;

// The transition label is null

// Original guard: x1 <= 11 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 11.0;
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

t = transition::ptr(new transition(826,"null",222,221,guard_polytope,assignment));

Out_Going_Trans_fromloc_221.push_back(t);
// The transition label is null

// Original guard: x1 >= 12 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -12.0;
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

t = transition::ptr(new transition(827,"null",222,223,guard_polytope,assignment));

Out_Going_Trans_fromloc_221.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(828,"null",222,207,guard_polytope,assignment));

Out_Going_Trans_fromloc_221.push_back(t);
l = location::ptr(new location(222, "loc_221", system_dynamics, invariant, true, Out_Going_Trans_fromloc_221));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_222

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.2828426978578645;
C[3] = -0.282842712;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -12.0;
invariantBoundValue[1] = 13.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_222;

// The transition label is null

// Original guard: x1 <= 12 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 12.0;
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

t = transition::ptr(new transition(829,"null",223,222,guard_polytope,assignment));

Out_Going_Trans_fromloc_222.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -13.0;
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

t = transition::ptr(new transition(830,"null",223,224,guard_polytope,assignment));

Out_Going_Trans_fromloc_222.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(831,"null",223,208,guard_polytope,assignment));

Out_Going_Trans_fromloc_222.push_back(t);
l = location::ptr(new location(223, "loc_222", system_dynamics, invariant, true, Out_Going_Trans_fromloc_222));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_223

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_223;

// The transition label is null

// Original guard: x1 <= 13 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 13.0;
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

t = transition::ptr(new transition(832,"null",224,223,guard_polytope,assignment));

Out_Going_Trans_fromloc_223.push_back(t);
// The transition label is null

// Original guard: x1 >= 14 - 0 & v1 >= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,2) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -14.0;
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

t = transition::ptr(new transition(833,"null",224,225,guard_polytope,assignment));

Out_Going_Trans_fromloc_223.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(834,"null",224,209,guard_polytope,assignment));

Out_Going_Trans_fromloc_223.push_back(t);
l = location::ptr(new location(224, "loc_223", system_dynamics, invariant, true, Out_Going_Trans_fromloc_223));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_224

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -0.89999998;
Amatrix(2 , 3) = -0.5;
Amatrix(3 , 2) = -0.1;
Amatrix(3 , 3) = -0.5;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.9899494778578646;
C[3] = -0.42426406800000005;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 8;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_224;

// The transition label is null

// Original guard: x1 <= 14 + 0 & v1 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,2) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(835,"null",225,224,guard_polytope,assignment));

Out_Going_Trans_fromloc_224.push_back(t);
// The transition label is null

// Original guard: x2 <= 14 + 0 & v2 <= 0

row = 2;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;
guardConstraintsMatrix(1,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 14.0;
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

t = transition::ptr(new transition(836,"null",225,210,guard_polytope,assignment));

Out_Going_Trans_fromloc_224.push_back(t);
l = location::ptr(new location(225, "loc_224", system_dynamics, invariant, true, Out_Going_Trans_fromloc_224));
Hybrid_Automata.addLocation(l);

}
