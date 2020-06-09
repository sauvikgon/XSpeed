// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav02/navT02_Timed.xml
// Command Line arguments: -tool xspeed "" -output /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav02/navT02_Timed.cpp -input /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav02/navT02_Timed.xml /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav02/nav02-pdb.cfg


#include <benchmarks/navigation/navT02Timed.h>
void setnavT02_Timedmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = -0.49497473892893223;
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

// The transition label is null

// Original guard: x1 >= 1 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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
l = location::ptr(new location(1, "loc_0", system_dynamics, invariant, true, Out_Going_Trans_fromloc_0));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_1

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// Original guard: x1 >= 2 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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
l = location::ptr(new location(2, "loc_1", system_dynamics, invariant, true, Out_Going_Trans_fromloc_1));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_2

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// Original guard: x1 >= 3 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(3,"null",3,4,guard_polytope,assignment));

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
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// Original guard: x1 >= 4 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(4,"null",4,5,guard_polytope,assignment));

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
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// Original guard: x1 >= 5 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(5,"null",5,6,guard_polytope,assignment));

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
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// Original guard: x1 >= 6 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(6,"null",6,7,guard_polytope,assignment));

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
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// Original guard: x1 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(7,"null",7,8,guard_polytope,assignment));

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
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// Original guard: x1 >= 8 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(8,"null",8,9,guard_polytope,assignment));

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
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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

// Original guard: x2 >= 1 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(9,"null",9,23,guard_polytope,assignment));

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
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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

// Original guard: x2 >= 1 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(10,"null",10,24,guard_polytope,assignment));

Out_Going_Trans_fromloc_9.push_back(t);
l = location::ptr(new location(10, "loc_9", system_dynamics, invariant, true, Out_Going_Trans_fromloc_9));

Hybrid_Automata.addInitialLocation(l);
Hybrid_Automata.addLocation(l);


// The mode name is  loc_12

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = -0.49497473892893223;
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

// Original guard: x1 >= 13 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(11,"null",11,12,guard_polytope,assignment));

Out_Going_Trans_fromloc_12.push_back(t);
l = location::ptr(new location(11, "loc_12", system_dynamics, invariant, true, Out_Going_Trans_fromloc_12));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_13

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// Original guard: x1 >= 14 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(12,"null",12,13,guard_polytope,assignment));

Out_Going_Trans_fromloc_13.push_back(t);
l = location::ptr(new location(12, "loc_13", system_dynamics, invariant, true, Out_Going_Trans_fromloc_13));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_14

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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

// The transition label is null

// Original guard: x1 >= 15 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(13,"null",13,14,guard_polytope,assignment));

Out_Going_Trans_fromloc_14.push_back(t);
l = location::ptr(new location(13, "loc_14", system_dynamics, invariant, true, Out_Going_Trans_fromloc_14));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_15

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_15;

// The transition label is null

// Original guard: x1 >= 16 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -16.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(14,"null",14,15,guard_polytope,assignment));

Out_Going_Trans_fromloc_15.push_back(t);
l = location::ptr(new location(14, "loc_15", system_dynamics, invariant, true, Out_Going_Trans_fromloc_15));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_16

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_16;

// The transition label is null

// Original guard: x1 >= 17 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(15,"null",15,16,guard_polytope,assignment));

Out_Going_Trans_fromloc_16.push_back(t);
l = location::ptr(new location(15, "loc_16", system_dynamics, invariant, true, Out_Going_Trans_fromloc_16));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_17

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_17;

// The transition label is null

// Original guard: x1 >= 18 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(16,"null",16,17,guard_polytope,assignment));

Out_Going_Trans_fromloc_17.push_back(t);
l = location::ptr(new location(16, "loc_17", system_dynamics, invariant, true, Out_Going_Trans_fromloc_17));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_18

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_18;


l = location::ptr(new location(17, "loc_18", system_dynamics, invariant, true, Out_Going_Trans_fromloc_18));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_20

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_20;

// The transition label is null

// Original guard: x2 <= 1 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(17,"null",18,1,guard_polytope,assignment));

Out_Going_Trans_fromloc_20.push_back(t);
l = location::ptr(new location(18, "loc_20", system_dynamics, invariant, true, Out_Going_Trans_fromloc_20));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_24

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_24;


l = location::ptr(new location(19, "loc_24", system_dynamics, invariant, true, Out_Going_Trans_fromloc_24));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_25

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_25;

// The transition label is null

// Original guard: x1 <= 5 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(18,"null",20,19,guard_polytope,assignment));

Out_Going_Trans_fromloc_25.push_back(t);
l = location::ptr(new location(20, "loc_25", system_dynamics, invariant, true, Out_Going_Trans_fromloc_25));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_26

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_26;

// The transition label is null

// Original guard: x1 <= 6 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(19,"null",21,20,guard_polytope,assignment));

Out_Going_Trans_fromloc_26.push_back(t);
l = location::ptr(new location(21, "loc_26", system_dynamics, invariant, true, Out_Going_Trans_fromloc_26));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_27

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_27;

// The transition label is null

// Original guard: x1 <= 7 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(20,"null",22,21,guard_polytope,assignment));

Out_Going_Trans_fromloc_27.push_back(t);
l = location::ptr(new location(22, "loc_27", system_dynamics, invariant, true, Out_Going_Trans_fromloc_27));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_28

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_28;

// The transition label is null

// Original guard: x1 <= 8 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(21,"null",23,22,guard_polytope,assignment));

Out_Going_Trans_fromloc_28.push_back(t);
l = location::ptr(new location(23, "loc_28", system_dynamics, invariant, true, Out_Going_Trans_fromloc_28));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_29

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_29;

// The transition label is null

// Original guard: x2 >= 2 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(22,"null",24,39,guard_polytope,assignment));

Out_Going_Trans_fromloc_29.push_back(t);
l = location::ptr(new location(24, "loc_29", system_dynamics, invariant, true, Out_Going_Trans_fromloc_29));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_32

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = -0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_32;

// The transition label is null

// Original guard: x2 <= 1 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(23,"null",25,11,guard_polytope,assignment));

Out_Going_Trans_fromloc_32.push_back(t);
l = location::ptr(new location(25, "loc_32", system_dynamics, invariant, true, Out_Going_Trans_fromloc_32));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_33

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_33;

// The transition label is null

// Original guard: x1 <= 13 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(24,"null",26,25,guard_polytope,assignment));

Out_Going_Trans_fromloc_33.push_back(t);
l = location::ptr(new location(26, "loc_33", system_dynamics, invariant, true, Out_Going_Trans_fromloc_33));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_34

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_34;

// The transition label is null

// Original guard: x1 <= 14 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(25,"null",27,26,guard_polytope,assignment));

Out_Going_Trans_fromloc_34.push_back(t);
l = location::ptr(new location(27, "loc_34", system_dynamics, invariant, true, Out_Going_Trans_fromloc_34));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_35

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_35;

// The transition label is null

// Original guard: x1 <= 15 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(26,"null",28,27,guard_polytope,assignment));

Out_Going_Trans_fromloc_35.push_back(t);
l = location::ptr(new location(28, "loc_35", system_dynamics, invariant, true, Out_Going_Trans_fromloc_35));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_36

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_36;

// The transition label is null

// Original guard: x1 <= 16 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 16.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(27,"null",29,28,guard_polytope,assignment));

Out_Going_Trans_fromloc_36.push_back(t);
l = location::ptr(new location(29, "loc_36", system_dynamics, invariant, true, Out_Going_Trans_fromloc_36));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_37

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_37;

// The transition label is null

// Original guard: x1 <= 17 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(28,"null",30,29,guard_polytope,assignment));

Out_Going_Trans_fromloc_37.push_back(t);
l = location::ptr(new location(30, "loc_37", system_dynamics, invariant, true, Out_Going_Trans_fromloc_37));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_38

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_38;

// The transition label is null

// Original guard: x1 <= 18 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(29,"null",31,30,guard_polytope,assignment));

Out_Going_Trans_fromloc_38.push_back(t);
l = location::ptr(new location(31, "loc_38", system_dynamics, invariant, true, Out_Going_Trans_fromloc_38));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_39

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = -0.49497473892893223;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_39;

// The transition label is null

// Original guard: x1 <= 19 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 19.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(30,"null",32,31,guard_polytope,assignment));

Out_Going_Trans_fromloc_39.push_back(t);
l = location::ptr(new location(32, "loc_39", system_dynamics, invariant, true, Out_Going_Trans_fromloc_39));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_40

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_40;

// The transition label is null

// Original guard: x2 <= 2 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(31,"null",33,18,guard_polytope,assignment));

Out_Going_Trans_fromloc_40.push_back(t);
l = location::ptr(new location(33, "loc_40", system_dynamics, invariant, true, Out_Going_Trans_fromloc_40));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_44

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_44;

// The transition label is null

// Original guard: x2 >= 3 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(32,"null",34,51,guard_polytope,assignment));

Out_Going_Trans_fromloc_44.push_back(t);
l = location::ptr(new location(34, "loc_44", system_dynamics, invariant, true, Out_Going_Trans_fromloc_44));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_45

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_45;

// The transition label is null

// Original guard: x1 <= 5 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(33,"null",35,34,guard_polytope,assignment));

Out_Going_Trans_fromloc_45.push_back(t);
l = location::ptr(new location(35, "loc_45", system_dynamics, invariant, true, Out_Going_Trans_fromloc_45));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_46

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_46;

// The transition label is null

// Original guard: x1 <= 6 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(34,"null",36,35,guard_polytope,assignment));

Out_Going_Trans_fromloc_46.push_back(t);
l = location::ptr(new location(36, "loc_46", system_dynamics, invariant, true, Out_Going_Trans_fromloc_46));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_47

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_47;

// The transition label is null

// Original guard: x1 <= 7 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(35,"null",37,36,guard_polytope,assignment));

Out_Going_Trans_fromloc_47.push_back(t);
l = location::ptr(new location(37, "loc_47", system_dynamics, invariant, true, Out_Going_Trans_fromloc_47));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_48

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_48;

// The transition label is null

// Original guard: x1 <= 8 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(36,"null",38,37,guard_polytope,assignment));

Out_Going_Trans_fromloc_48.push_back(t);
l = location::ptr(new location(38, "loc_48", system_dynamics, invariant, true, Out_Going_Trans_fromloc_48));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_49

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_49;

// The transition label is null

// Original guard: x1 <= 9 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(37,"null",39,38,guard_polytope,assignment));

Out_Going_Trans_fromloc_49.push_back(t);
// The transition label is null

// Original guard: x1 >= 10 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(38,"null",39,40,guard_polytope,assignment));

Out_Going_Trans_fromloc_49.push_back(t);
l = location::ptr(new location(39, "loc_49", system_dynamics, invariant, true, Out_Going_Trans_fromloc_49));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_50

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_50;

// The transition label is null

// Original guard: x1 >= 11 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(39,"null",40,41,guard_polytope,assignment));

Out_Going_Trans_fromloc_50.push_back(t);
l = location::ptr(new location(40, "loc_50", system_dynamics, invariant, true, Out_Going_Trans_fromloc_50));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_51

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_51;

// The transition label is null

// Original guard: x1 >= 12 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(40,"null",41,42,guard_polytope,assignment));

Out_Going_Trans_fromloc_51.push_back(t);
l = location::ptr(new location(41, "loc_51", system_dynamics, invariant, true, Out_Going_Trans_fromloc_51));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_52

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_52;

// The transition label is null

// Original guard: x1 >= 13 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(41,"null",42,43,guard_polytope,assignment));

Out_Going_Trans_fromloc_52.push_back(t);
l = location::ptr(new location(42, "loc_52", system_dynamics, invariant, true, Out_Going_Trans_fromloc_52));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_53

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_53;

// The transition label is null

// Original guard: x1 >= 14 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(42,"null",43,44,guard_polytope,assignment));

Out_Going_Trans_fromloc_53.push_back(t);
l = location::ptr(new location(43, "loc_53", system_dynamics, invariant, true, Out_Going_Trans_fromloc_53));
Hybrid_Automata.addLocation(l);

navT02_Timed_module1(Hybrid_Automata,init_state_list,reach_parameters);
navT02_Timed_module2(Hybrid_Automata,init_state_list,reach_parameters);
navT02_Timed_module3(Hybrid_Automata,init_state_list,reach_parameters);
navT02_Timed_module4(Hybrid_Automata,init_state_list,reach_parameters);

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
boundValueI[0]=10;
boundValueI[1]=-9;
boundValueI[2]=1;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =10;

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

void navT02_Timed_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_54

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_54;

// The transition label is null

// Original guard: x1 >= 15 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

t = transition::ptr(new transition(43,"null",44,45,guard_polytope,assignment));

Out_Going_Trans_fromloc_54.push_back(t);
l = location::ptr(new location(44, "loc_54", system_dynamics, invariant, true, Out_Going_Trans_fromloc_54));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_55

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_55;

// The transition label is null

// Original guard: x1 >= 16 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -16.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(44,"null",45,46,guard_polytope,assignment));

Out_Going_Trans_fromloc_55.push_back(t);
l = location::ptr(new location(45, "loc_55", system_dynamics, invariant, true, Out_Going_Trans_fromloc_55));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_56

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_56;

// The transition label is null

// Original guard: x1 >= 17 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(45,"null",46,47,guard_polytope,assignment));

Out_Going_Trans_fromloc_56.push_back(t);
l = location::ptr(new location(46, "loc_56", system_dynamics, invariant, true, Out_Going_Trans_fromloc_56));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_57

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_57;

// The transition label is null

// Original guard: x1 >= 18 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(46,"null",47,48,guard_polytope,assignment));

Out_Going_Trans_fromloc_57.push_back(t);
l = location::ptr(new location(47, "loc_57", system_dynamics, invariant, true, Out_Going_Trans_fromloc_57));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_58

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_58;

// The transition label is null

// Original guard: x2 >= 3 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(47,"null",48,55,guard_polytope,assignment));

Out_Going_Trans_fromloc_58.push_back(t);
// The transition label is null

// Original guard: x1 >= 19 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -19.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(48,"null",48,49,guard_polytope,assignment));

Out_Going_Trans_fromloc_58.push_back(t);
l = location::ptr(new location(48, "loc_58", system_dynamics, invariant, true, Out_Going_Trans_fromloc_58));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_59

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_59;

// The transition label is null

// Original guard: x2 <= 2 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(49,"null",49,32,guard_polytope,assignment));

Out_Going_Trans_fromloc_59.push_back(t);
l = location::ptr(new location(49, "loc_59", system_dynamics, invariant, true, Out_Going_Trans_fromloc_59));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_60

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_60;

// The transition label is null

// Original guard: x2 <= 3 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(50,"null",50,33,guard_polytope,assignment));

Out_Going_Trans_fromloc_60.push_back(t);
l = location::ptr(new location(50, "loc_60", system_dynamics, invariant, true, Out_Going_Trans_fromloc_60));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_64

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_64;

// The transition label is null

// Original guard: x2 >= 4 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(51,"null",51,60,guard_polytope,assignment));

Out_Going_Trans_fromloc_64.push_back(t);
l = location::ptr(new location(51, "loc_64", system_dynamics, invariant, true, Out_Going_Trans_fromloc_64));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_70

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_70;

// The transition label is null

// Original guard: x2 >= 4 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(52,"null",52,64,guard_polytope,assignment));

Out_Going_Trans_fromloc_70.push_back(t);
l = location::ptr(new location(52, "loc_70", system_dynamics, invariant, true, Out_Going_Trans_fromloc_70));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_71

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_71;

// The transition label is null

// Original guard: x1 <= 11 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(53,"null",53,52,guard_polytope,assignment));

Out_Going_Trans_fromloc_71.push_back(t);
l = location::ptr(new location(53, "loc_71", system_dynamics, invariant, true, Out_Going_Trans_fromloc_71));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_72

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = -0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_72;

// The transition label is null

// Original guard: x1 <= 12 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(54,"null",54,53,guard_polytope,assignment));

Out_Going_Trans_fromloc_72.push_back(t);
l = location::ptr(new location(54, "loc_72", system_dynamics, invariant, true, Out_Going_Trans_fromloc_72));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_78

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_78;

// The transition label is null

// Original guard: x2 >= 4 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(55,"null",55,66,guard_polytope,assignment));

Out_Going_Trans_fromloc_78.push_back(t);
l = location::ptr(new location(55, "loc_78", system_dynamics, invariant, true, Out_Going_Trans_fromloc_78));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_80

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_80;

// The transition label is null

// Original guard: x2 <= 4 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(56,"null",56,50,guard_polytope,assignment));

Out_Going_Trans_fromloc_80.push_back(t);
l = location::ptr(new location(56, "loc_80", system_dynamics, invariant, true, Out_Going_Trans_fromloc_80));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_81

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_81;

// The transition label is null

// Original guard: x2 >= 5 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(57,"null",57,68,guard_polytope,assignment));

Out_Going_Trans_fromloc_81.push_back(t);
l = location::ptr(new location(57, "loc_81", system_dynamics, invariant, true, Out_Going_Trans_fromloc_81));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_82

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_82;

// The transition label is null

// Original guard: x1 <= 2 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(58,"null",58,57,guard_polytope,assignment));

Out_Going_Trans_fromloc_82.push_back(t);
l = location::ptr(new location(58, "loc_82", system_dynamics, invariant, true, Out_Going_Trans_fromloc_82));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_83

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_83;

// The transition label is null

// Original guard: x1 <= 3 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(59,"null",59,58,guard_polytope,assignment));

Out_Going_Trans_fromloc_83.push_back(t);
l = location::ptr(new location(59, "loc_83", system_dynamics, invariant, true, Out_Going_Trans_fromloc_83));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_84

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_84;

// The transition label is null

// Original guard: x1 <= 4 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(60,"null",60,59,guard_polytope,assignment));

Out_Going_Trans_fromloc_84.push_back(t);
// The transition label is null

// Original guard: x1 >= 5 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(61,"null",60,61,guard_polytope,assignment));

Out_Going_Trans_fromloc_84.push_back(t);
l = location::ptr(new location(60, "loc_84", system_dynamics, invariant, true, Out_Going_Trans_fromloc_84));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_85

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_85;

// The transition label is null

// Original guard: x1 >= 6 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(62,"null",61,62,guard_polytope,assignment));

Out_Going_Trans_fromloc_85.push_back(t);
l = location::ptr(new location(61, "loc_85", system_dynamics, invariant, true, Out_Going_Trans_fromloc_85));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_86

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_86;

// The transition label is null

// Original guard: x1 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(63,"null",62,63,guard_polytope,assignment));

Out_Going_Trans_fromloc_86.push_back(t);
l = location::ptr(new location(62, "loc_86", system_dynamics, invariant, true, Out_Going_Trans_fromloc_86));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_87

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_87;

// The transition label is null

// Original guard: x2 >= 5 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(64,"null",63,69,guard_polytope,assignment));

Out_Going_Trans_fromloc_87.push_back(t);
l = location::ptr(new location(63, "loc_87", system_dynamics, invariant, true, Out_Going_Trans_fromloc_87));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_90

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_90;

// The transition label is null

// Original guard: x2 >= 5 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(65,"null",64,70,guard_polytope,assignment));

Out_Going_Trans_fromloc_90.push_back(t);
l = location::ptr(new location(64, "loc_90", system_dynamics, invariant, true, Out_Going_Trans_fromloc_90));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_92

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_92;

// The transition label is null

// Original guard: x2 <= 4 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(66,"null",65,54,guard_polytope,assignment));

Out_Going_Trans_fromloc_92.push_back(t);
l = location::ptr(new location(65, "loc_92", system_dynamics, invariant, true, Out_Going_Trans_fromloc_92));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_98

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_98;

// The transition label is null

// Original guard: x2 >= 5 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(67,"null",66,77,guard_polytope,assignment));

Out_Going_Trans_fromloc_98.push_back(t);
l = location::ptr(new location(66, "loc_98", system_dynamics, invariant, true, Out_Going_Trans_fromloc_98));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_100

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_100;

// The transition label is null

// Original guard: x2 <= 5 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(68,"null",67,56,guard_polytope,assignment));

Out_Going_Trans_fromloc_100.push_back(t);
l = location::ptr(new location(67, "loc_100", system_dynamics, invariant, true, Out_Going_Trans_fromloc_100));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_101

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_101;

// The transition label is null

// Original guard: x2 >= 6 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(69,"null",68,79,guard_polytope,assignment));

Out_Going_Trans_fromloc_101.push_back(t);
l = location::ptr(new location(68, "loc_101", system_dynamics, invariant, true, Out_Going_Trans_fromloc_101));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_107

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_107;

// The transition label is null

// Original guard: x2 >= 6 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(70,"null",69,80,guard_polytope,assignment));

Out_Going_Trans_fromloc_107.push_back(t);
l = location::ptr(new location(69, "loc_107", system_dynamics, invariant, true, Out_Going_Trans_fromloc_107));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_110

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_110;

// The transition label is null

// Original guard: x2 >= 6 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(71,"null",70,82,guard_polytope,assignment));

Out_Going_Trans_fromloc_110.push_back(t);
l = location::ptr(new location(70, "loc_110", system_dynamics, invariant, true, Out_Going_Trans_fromloc_110));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_112

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = -0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_112;

// The transition label is null

// Original guard: x2 <= 5 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(72,"null",71,65,guard_polytope,assignment));

Out_Going_Trans_fromloc_112.push_back(t);
// The transition label is null

// Original guard: x2 >= 6 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(73,"null",71,83,guard_polytope,assignment));

Out_Going_Trans_fromloc_112.push_back(t);
l = location::ptr(new location(71, "loc_112", system_dynamics, invariant, true, Out_Going_Trans_fromloc_112));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_113

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_113;

// The transition label is null

// Original guard: x1 <= 13 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(74,"null",72,71,guard_polytope,assignment));

Out_Going_Trans_fromloc_113.push_back(t);
l = location::ptr(new location(72, "loc_113", system_dynamics, invariant, true, Out_Going_Trans_fromloc_113));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_114

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_114;

// The transition label is null

// Original guard: x1 <= 14 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(75,"null",73,72,guard_polytope,assignment));

Out_Going_Trans_fromloc_114.push_back(t);
l = location::ptr(new location(73, "loc_114", system_dynamics, invariant, true, Out_Going_Trans_fromloc_114));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_115

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_115;

// The transition label is null

// Original guard: x1 <= 15 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(76,"null",74,73,guard_polytope,assignment));

Out_Going_Trans_fromloc_115.push_back(t);
l = location::ptr(new location(74, "loc_115", system_dynamics, invariant, true, Out_Going_Trans_fromloc_115));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_116

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_116;

// The transition label is null

// Original guard: x1 <= 16 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 16.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(77,"null",75,74,guard_polytope,assignment));

Out_Going_Trans_fromloc_116.push_back(t);
l = location::ptr(new location(75, "loc_116", system_dynamics, invariant, true, Out_Going_Trans_fromloc_116));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_117

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_117;

// The transition label is null

// Original guard: x1 <= 17 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(78,"null",76,75,guard_polytope,assignment));

Out_Going_Trans_fromloc_117.push_back(t);
l = location::ptr(new location(76, "loc_117", system_dynamics, invariant, true, Out_Going_Trans_fromloc_117));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_118

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_118;

// The transition label is null

// Original guard: x1 <= 18 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(79,"null",77,76,guard_polytope,assignment));

Out_Going_Trans_fromloc_118.push_back(t);
l = location::ptr(new location(77, "loc_118", system_dynamics, invariant, true, Out_Going_Trans_fromloc_118));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_120

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_120;

// The transition label is null

// Original guard: x2 <= 6 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(80,"null",78,67,guard_polytope,assignment));

Out_Going_Trans_fromloc_120.push_back(t);
l = location::ptr(new location(78, "loc_120", system_dynamics, invariant, true, Out_Going_Trans_fromloc_120));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_121

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_121;

// The transition label is null

// Original guard: x2 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(81,"null",79,88,guard_polytope,assignment));

Out_Going_Trans_fromloc_121.push_back(t);
l = location::ptr(new location(79, "loc_121", system_dynamics, invariant, true, Out_Going_Trans_fromloc_121));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_127

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_127;

// The transition label is null

// Original guard: x2 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(82,"null",80,89,guard_polytope,assignment));

Out_Going_Trans_fromloc_127.push_back(t);
l = location::ptr(new location(80, "loc_127", system_dynamics, invariant, true, Out_Going_Trans_fromloc_127));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_129

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_129;


l = location::ptr(new location(81, "loc_129", system_dynamics, invariant, true, Out_Going_Trans_fromloc_129));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_130

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_130;

// The transition label is null

// Original guard: x2 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(83,"null",82,91,guard_polytope,assignment));

Out_Going_Trans_fromloc_130.push_back(t);
l = location::ptr(new location(82, "loc_130", system_dynamics, invariant, true, Out_Going_Trans_fromloc_130));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_132

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_132;

// The transition label is null

// Original guard: x2 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(84,"null",83,92,guard_polytope,assignment));

Out_Going_Trans_fromloc_132.push_back(t);
l = location::ptr(new location(83, "loc_132", system_dynamics, invariant, true, Out_Going_Trans_fromloc_132));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_137

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = -0.49497473892893223;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_137;

// The transition label is null

// Original guard: x1 >= 18 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(85,"null",84,85,guard_polytope,assignment));

Out_Going_Trans_fromloc_137.push_back(t);
l = location::ptr(new location(84, "loc_137", system_dynamics, invariant, true, Out_Going_Trans_fromloc_137));
Hybrid_Automata.addLocation(l);

}

void navT02_Timed_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_138

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_138;

// The transition label is null

// Original guard: x1 >= 19 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -19.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

t = transition::ptr(new transition(86,"null",85,86,guard_polytope,assignment));

Out_Going_Trans_fromloc_138.push_back(t);
l = location::ptr(new location(85, "loc_138", system_dynamics, invariant, true, Out_Going_Trans_fromloc_138));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_139

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_139;

// The transition label is null

// Original guard: x2 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(87,"null",86,94,guard_polytope,assignment));

Out_Going_Trans_fromloc_139.push_back(t);
l = location::ptr(new location(86, "loc_139", system_dynamics, invariant, true, Out_Going_Trans_fromloc_139));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_140

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_140;

// The transition label is null

// Original guard: x2 <= 7 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(88,"null",87,78,guard_polytope,assignment));

Out_Going_Trans_fromloc_140.push_back(t);
l = location::ptr(new location(87, "loc_140", system_dynamics, invariant, true, Out_Going_Trans_fromloc_140));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_141

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_141;

// The transition label is null

// Original guard: x2 >= 8 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(89,"null",88,96,guard_polytope,assignment));

Out_Going_Trans_fromloc_141.push_back(t);
l = location::ptr(new location(88, "loc_141", system_dynamics, invariant, true, Out_Going_Trans_fromloc_141));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_147

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_147;

// The transition label is null

// Original guard: x2 >= 8 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(90,"null",89,97,guard_polytope,assignment));

Out_Going_Trans_fromloc_147.push_back(t);
l = location::ptr(new location(89, "loc_147", system_dynamics, invariant, true, Out_Going_Trans_fromloc_147));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_149

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_149;

// The transition label is null

// Original guard: x2 <= 7 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(91,"null",90,81,guard_polytope,assignment));

Out_Going_Trans_fromloc_149.push_back(t);
l = location::ptr(new location(90, "loc_149", system_dynamics, invariant, true, Out_Going_Trans_fromloc_149));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_150

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_150;


l = location::ptr(new location(91, "loc_150", system_dynamics, invariant, true, Out_Going_Trans_fromloc_150));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_152

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_152;

// The transition label is null

// Original guard: x2 >= 8 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(92,"null",92,99,guard_polytope,assignment));

Out_Going_Trans_fromloc_152.push_back(t);
l = location::ptr(new location(92, "loc_152", system_dynamics, invariant, true, Out_Going_Trans_fromloc_152));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_157

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_157;

// The transition label is null

// Original guard: x2 <= 7 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(93,"null",93,84,guard_polytope,assignment));

Out_Going_Trans_fromloc_157.push_back(t);
l = location::ptr(new location(93, "loc_157", system_dynamics, invariant, true, Out_Going_Trans_fromloc_157));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_159

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_159;

// The transition label is null

// Original guard: x2 >= 8 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(94,"null",94,101,guard_polytope,assignment));

Out_Going_Trans_fromloc_159.push_back(t);
l = location::ptr(new location(94, "loc_159", system_dynamics, invariant, true, Out_Going_Trans_fromloc_159));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_160

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_160;

// The transition label is null

// Original guard: x2 <= 8 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(95,"null",95,87,guard_polytope,assignment));

Out_Going_Trans_fromloc_160.push_back(t);
l = location::ptr(new location(95, "loc_160", system_dynamics, invariant, true, Out_Going_Trans_fromloc_160));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_161

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_161;

// The transition label is null

// Original guard: x2 >= 9 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(96,"null",96,103,guard_polytope,assignment));

Out_Going_Trans_fromloc_161.push_back(t);
l = location::ptr(new location(96, "loc_161", system_dynamics, invariant, true, Out_Going_Trans_fromloc_161));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_167

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_167;

// The transition label is null

// Original guard: x2 >= 9 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(97,"null",97,105,guard_polytope,assignment));

Out_Going_Trans_fromloc_167.push_back(t);
l = location::ptr(new location(97, "loc_167", system_dynamics, invariant, true, Out_Going_Trans_fromloc_167));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_169

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_169;

// The transition label is null

// Original guard: x2 <= 8 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(98,"null",98,90,guard_polytope,assignment));

Out_Going_Trans_fromloc_169.push_back(t);
l = location::ptr(new location(98, "loc_169", system_dynamics, invariant, true, Out_Going_Trans_fromloc_169));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_172

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_172;

// The transition label is null

// Original guard: x2 >= 9 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(99,"null",99,109,guard_polytope,assignment));

Out_Going_Trans_fromloc_172.push_back(t);
l = location::ptr(new location(99, "loc_172", system_dynamics, invariant, true, Out_Going_Trans_fromloc_172));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_177

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_177;

// The transition label is null

// Original guard: x2 <= 8 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(100,"null",100,93,guard_polytope,assignment));

Out_Going_Trans_fromloc_177.push_back(t);
l = location::ptr(new location(100, "loc_177", system_dynamics, invariant, true, Out_Going_Trans_fromloc_177));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_179

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_179;

// The transition label is null

// Original guard: x2 >= 9 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(101,"null",101,115,guard_polytope,assignment));

Out_Going_Trans_fromloc_179.push_back(t);
l = location::ptr(new location(101, "loc_179", system_dynamics, invariant, true, Out_Going_Trans_fromloc_179));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_180

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_180;

// The transition label is null

// Original guard: x2 <= 9 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(102,"null",102,95,guard_polytope,assignment));

Out_Going_Trans_fromloc_180.push_back(t);
l = location::ptr(new location(102, "loc_180", system_dynamics, invariant, true, Out_Going_Trans_fromloc_180));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_181

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_181;

// The transition label is null

// Original guard: x2 >= 10 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(103,"null",103,117,guard_polytope,assignment));

Out_Going_Trans_fromloc_181.push_back(t);
l = location::ptr(new location(103, "loc_181", system_dynamics, invariant, true, Out_Going_Trans_fromloc_181));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_186

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_186;


l = location::ptr(new location(104, "loc_186", system_dynamics, invariant, true, Out_Going_Trans_fromloc_186));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_187

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_187;

// The transition label is null

// Original guard: x2 >= 10 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(104,"null",105,119,guard_polytope,assignment));

Out_Going_Trans_fromloc_187.push_back(t);
l = location::ptr(new location(105, "loc_187", system_dynamics, invariant, true, Out_Going_Trans_fromloc_187));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_189

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_189;

// The transition label is null

// Original guard: x2 <= 9 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(105,"null",106,98,guard_polytope,assignment));

Out_Going_Trans_fromloc_189.push_back(t);
l = location::ptr(new location(106, "loc_189", system_dynamics, invariant, true, Out_Going_Trans_fromloc_189));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_190

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_190;

// The transition label is null

// Original guard: x2 >= 10 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(106,"null",107,122,guard_polytope,assignment));

Out_Going_Trans_fromloc_190.push_back(t);
l = location::ptr(new location(107, "loc_190", system_dynamics, invariant, true, Out_Going_Trans_fromloc_190));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_191

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_191;

// The transition label is null

// Original guard: x1 <= 11 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(107,"null",108,107,guard_polytope,assignment));

Out_Going_Trans_fromloc_191.push_back(t);
l = location::ptr(new location(108, "loc_191", system_dynamics, invariant, true, Out_Going_Trans_fromloc_191));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_192

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_192;

// The transition label is null

// Original guard: x1 <= 12 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(108,"null",109,108,guard_polytope,assignment));

Out_Going_Trans_fromloc_192.push_back(t);
// The transition label is null

// Original guard: x1 >= 13 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(109,"null",109,110,guard_polytope,assignment));

Out_Going_Trans_fromloc_192.push_back(t);
l = location::ptr(new location(109, "loc_192", system_dynamics, invariant, true, Out_Going_Trans_fromloc_192));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_193

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_193;

// The transition label is null

// Original guard: x1 >= 14 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(110,"null",110,111,guard_polytope,assignment));

Out_Going_Trans_fromloc_193.push_back(t);
l = location::ptr(new location(110, "loc_193", system_dynamics, invariant, true, Out_Going_Trans_fromloc_193));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_194

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_194;

// The transition label is null

// Original guard: x1 >= 15 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(111,"null",111,112,guard_polytope,assignment));

Out_Going_Trans_fromloc_194.push_back(t);
l = location::ptr(new location(111, "loc_194", system_dynamics, invariant, true, Out_Going_Trans_fromloc_194));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_195

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_195;

// The transition label is null

// Original guard: x1 >= 16 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -16.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(112,"null",112,113,guard_polytope,assignment));

Out_Going_Trans_fromloc_195.push_back(t);
l = location::ptr(new location(112, "loc_195", system_dynamics, invariant, true, Out_Going_Trans_fromloc_195));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_196

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_196;

// The transition label is null

// Original guard: x1 >= 17 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(113,"null",113,114,guard_polytope,assignment));

Out_Going_Trans_fromloc_196.push_back(t);
l = location::ptr(new location(113, "loc_196", system_dynamics, invariant, true, Out_Going_Trans_fromloc_196));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_197

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = -0.49497473892893223;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_197;

// The transition label is null

// Original guard: x2 <= 9 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(114,"null",114,100,guard_polytope,assignment));

Out_Going_Trans_fromloc_197.push_back(t);
l = location::ptr(new location(114, "loc_197", system_dynamics, invariant, true, Out_Going_Trans_fromloc_197));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_199

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_199;

// The transition label is null

// Original guard: x2 >= 10 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(115,"null",115,123,guard_polytope,assignment));

Out_Going_Trans_fromloc_199.push_back(t);
l = location::ptr(new location(115, "loc_199", system_dynamics, invariant, true, Out_Going_Trans_fromloc_199));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_200

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_200;

// The transition label is null

// Original guard: x2 <= 10 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(116,"null",116,102,guard_polytope,assignment));

Out_Going_Trans_fromloc_200.push_back(t);
l = location::ptr(new location(116, "loc_200", system_dynamics, invariant, true, Out_Going_Trans_fromloc_200));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_201

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_201;

// The transition label is null

// Original guard: x2 >= 11 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(117,"null",117,125,guard_polytope,assignment));

Out_Going_Trans_fromloc_201.push_back(t);
l = location::ptr(new location(117, "loc_201", system_dynamics, invariant, true, Out_Going_Trans_fromloc_201));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_206

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_206;

// The transition label is null

// Original guard: x2 <= 10 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(118,"null",118,104,guard_polytope,assignment));

Out_Going_Trans_fromloc_206.push_back(t);
l = location::ptr(new location(118, "loc_206", system_dynamics, invariant, true, Out_Going_Trans_fromloc_206));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_207

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_207;

// The transition label is null

// Original guard: x1 >= 8 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(119,"null",119,120,guard_polytope,assignment));

Out_Going_Trans_fromloc_207.push_back(t);
l = location::ptr(new location(119, "loc_207", system_dynamics, invariant, true, Out_Going_Trans_fromloc_207));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_208

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_208;

// The transition label is null

// Original guard: x1 >= 9 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(120,"null",120,121,guard_polytope,assignment));

Out_Going_Trans_fromloc_208.push_back(t);
l = location::ptr(new location(120, "loc_208", system_dynamics, invariant, true, Out_Going_Trans_fromloc_208));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_209

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = -0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_209;

// The transition label is null

// Original guard: x2 >= 11 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(121,"null",121,127,guard_polytope,assignment));

Out_Going_Trans_fromloc_209.push_back(t);
// The transition label is null

// Original guard: x2 <= 10 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(122,"null",121,106,guard_polytope,assignment));

Out_Going_Trans_fromloc_209.push_back(t);
l = location::ptr(new location(121, "loc_209", system_dynamics, invariant, true, Out_Going_Trans_fromloc_209));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_210

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_210;

// The transition label is null

// Original guard: x2 >= 11 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(123,"null",122,128,guard_polytope,assignment));

Out_Going_Trans_fromloc_210.push_back(t);
l = location::ptr(new location(122, "loc_210", system_dynamics, invariant, true, Out_Going_Trans_fromloc_210));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_219

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_219;

// The transition label is null

// Original guard: x2 >= 11 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(124,"null",123,134,guard_polytope,assignment));

Out_Going_Trans_fromloc_219.push_back(t);
l = location::ptr(new location(123, "loc_219", system_dynamics, invariant, true, Out_Going_Trans_fromloc_219));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_220

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_220;

// The transition label is null

// Original guard: x2 <= 11 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(125,"null",124,116,guard_polytope,assignment));

Out_Going_Trans_fromloc_220.push_back(t);
l = location::ptr(new location(124, "loc_220", system_dynamics, invariant, true, Out_Going_Trans_fromloc_220));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_221

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_221;

// The transition label is null

// Original guard: x2 >= 12 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(126,"null",125,136,guard_polytope,assignment));

Out_Going_Trans_fromloc_221.push_back(t);
l = location::ptr(new location(125, "loc_221", system_dynamics, invariant, true, Out_Going_Trans_fromloc_221));
Hybrid_Automata.addLocation(l);

}

void navT02_Timed_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_226

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_226;

// The transition label is null

// Original guard: x2 <= 11 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(127,"null",126,118,guard_polytope,assignment));

Out_Going_Trans_fromloc_226.push_back(t);
l = location::ptr(new location(126, "loc_226", system_dynamics, invariant, true, Out_Going_Trans_fromloc_226));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_229

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_229;

// The transition label is null

// Original guard: x2 >= 12 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(128,"null",127,138,guard_polytope,assignment));

Out_Going_Trans_fromloc_229.push_back(t);
l = location::ptr(new location(127, "loc_229", system_dynamics, invariant, true, Out_Going_Trans_fromloc_229));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_230

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_230;

// The transition label is null

// Original guard: x1 >= 11 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(129,"null",128,129,guard_polytope,assignment));

Out_Going_Trans_fromloc_230.push_back(t);
l = location::ptr(new location(128, "loc_230", system_dynamics, invariant, true, Out_Going_Trans_fromloc_230));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_231

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_231;

// The transition label is null

// Original guard: x1 >= 12 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(130,"null",129,130,guard_polytope,assignment));

Out_Going_Trans_fromloc_231.push_back(t);
l = location::ptr(new location(129, "loc_231", system_dynamics, invariant, true, Out_Going_Trans_fromloc_231));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_232

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_232;

// The transition label is null

// Original guard: x1 >= 13 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(131,"null",130,131,guard_polytope,assignment));

Out_Going_Trans_fromloc_232.push_back(t);
l = location::ptr(new location(130, "loc_232", system_dynamics, invariant, true, Out_Going_Trans_fromloc_232));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_233

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_233;

// The transition label is null

// Original guard: x1 >= 14 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(132,"null",131,132,guard_polytope,assignment));

Out_Going_Trans_fromloc_233.push_back(t);
l = location::ptr(new location(131, "loc_233", system_dynamics, invariant, true, Out_Going_Trans_fromloc_233));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_234

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_234;

// The transition label is null

// Original guard: x1 >= 15 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(133,"null",132,133,guard_polytope,assignment));

Out_Going_Trans_fromloc_234.push_back(t);
l = location::ptr(new location(132, "loc_234", system_dynamics, invariant, true, Out_Going_Trans_fromloc_234));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_235

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_235;


l = location::ptr(new location(133, "loc_235", system_dynamics, invariant, true, Out_Going_Trans_fromloc_235));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_239

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_239;

// The transition label is null

// Original guard: x2 >= 12 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(134,"null",134,139,guard_polytope,assignment));

Out_Going_Trans_fromloc_239.push_back(t);
l = location::ptr(new location(134, "loc_239", system_dynamics, invariant, true, Out_Going_Trans_fromloc_239));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_240

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_240;

// The transition label is null

// Original guard: x2 <= 12 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(135,"null",135,124,guard_polytope,assignment));

Out_Going_Trans_fromloc_240.push_back(t);
l = location::ptr(new location(135, "loc_240", system_dynamics, invariant, true, Out_Going_Trans_fromloc_240));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_241

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_241;

// The transition label is null

// Original guard: x2 >= 13 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(136,"null",136,141,guard_polytope,assignment));

Out_Going_Trans_fromloc_241.push_back(t);
l = location::ptr(new location(136, "loc_241", system_dynamics, invariant, true, Out_Going_Trans_fromloc_241));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_246

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_246;

// The transition label is null

// Original guard: x2 <= 12 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(137,"null",137,126,guard_polytope,assignment));

Out_Going_Trans_fromloc_246.push_back(t);
l = location::ptr(new location(137, "loc_246", system_dynamics, invariant, true, Out_Going_Trans_fromloc_246));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_249

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_249;

// The transition label is null

// Original guard: x2 >= 13 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(138,"null",138,145,guard_polytope,assignment));

Out_Going_Trans_fromloc_249.push_back(t);
l = location::ptr(new location(138, "loc_249", system_dynamics, invariant, true, Out_Going_Trans_fromloc_249));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_259

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_259;

// The transition label is null

// Original guard: x2 >= 13 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(139,"null",139,146,guard_polytope,assignment));

Out_Going_Trans_fromloc_259.push_back(t);
l = location::ptr(new location(139, "loc_259", system_dynamics, invariant, true, Out_Going_Trans_fromloc_259));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_260

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_260;

// The transition label is null

// Original guard: x2 <= 13 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(140,"null",140,135,guard_polytope,assignment));

Out_Going_Trans_fromloc_260.push_back(t);
l = location::ptr(new location(140, "loc_260", system_dynamics, invariant, true, Out_Going_Trans_fromloc_260));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_261

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_261;

// The transition label is null

// Original guard: x2 >= 14 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(141,"null",141,148,guard_polytope,assignment));

Out_Going_Trans_fromloc_261.push_back(t);
l = location::ptr(new location(141, "loc_261", system_dynamics, invariant, true, Out_Going_Trans_fromloc_261));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_266

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = -0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_266;

// The transition label is null

// Original guard: x2 <= 13 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(142,"null",142,137,guard_polytope,assignment));

Out_Going_Trans_fromloc_266.push_back(t);
l = location::ptr(new location(142, "loc_266", system_dynamics, invariant, true, Out_Going_Trans_fromloc_266));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_267

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_267;

// The transition label is null

// Original guard: x1 <= 7 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(143,"null",143,142,guard_polytope,assignment));

Out_Going_Trans_fromloc_267.push_back(t);
l = location::ptr(new location(143, "loc_267", system_dynamics, invariant, true, Out_Going_Trans_fromloc_267));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_268

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_268;

// The transition label is null

// Original guard: x1 <= 8 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(144,"null",144,143,guard_polytope,assignment));

Out_Going_Trans_fromloc_268.push_back(t);
l = location::ptr(new location(144, "loc_268", system_dynamics, invariant, true, Out_Going_Trans_fromloc_268));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_269

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_269;

// The transition label is null

// Original guard: x1 <= 9 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(145,"null",145,144,guard_polytope,assignment));

Out_Going_Trans_fromloc_269.push_back(t);
l = location::ptr(new location(145, "loc_269", system_dynamics, invariant, true, Out_Going_Trans_fromloc_269));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_279

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_279;

// The transition label is null

// Original guard: x2 >= 14 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

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

t = transition::ptr(new transition(146,"null",146,155,guard_polytope,assignment));

Out_Going_Trans_fromloc_279.push_back(t);
l = location::ptr(new location(146, "loc_279", system_dynamics, invariant, true, Out_Going_Trans_fromloc_279));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_280

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_280;

// The transition label is null

// Original guard: x2 <= 14 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

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

t = transition::ptr(new transition(147,"null",147,140,guard_polytope,assignment));

Out_Going_Trans_fromloc_280.push_back(t);
l = location::ptr(new location(147, "loc_280", system_dynamics, invariant, true, Out_Going_Trans_fromloc_280));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_281

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_281;

// The transition label is null

// Original guard: x1 >= 2 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(148,"null",148,149,guard_polytope,assignment));

Out_Going_Trans_fromloc_281.push_back(t);
l = location::ptr(new location(148, "loc_281", system_dynamics, invariant, true, Out_Going_Trans_fromloc_281));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_282

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_282;

// The transition label is null

// Original guard: x1 >= 3 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(149,"null",149,150,guard_polytope,assignment));

Out_Going_Trans_fromloc_282.push_back(t);
l = location::ptr(new location(149, "loc_282", system_dynamics, invariant, true, Out_Going_Trans_fromloc_282));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_283

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_283;

// The transition label is null

// Original guard: x1 >= 4 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(150,"null",150,151,guard_polytope,assignment));

Out_Going_Trans_fromloc_283.push_back(t);
l = location::ptr(new location(150, "loc_283", system_dynamics, invariant, true, Out_Going_Trans_fromloc_283));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_284

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_284;

// The transition label is null

// Original guard: x1 >= 5 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(151,"null",151,152,guard_polytope,assignment));

Out_Going_Trans_fromloc_284.push_back(t);
l = location::ptr(new location(151, "loc_284", system_dynamics, invariant, true, Out_Going_Trans_fromloc_284));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_285

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_285;

// The transition label is null

// Original guard: x1 >= 6 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(152,"null",152,153,guard_polytope,assignment));

Out_Going_Trans_fromloc_285.push_back(t);
l = location::ptr(new location(152, "loc_285", system_dynamics, invariant, true, Out_Going_Trans_fromloc_285));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_286

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_286;

// The transition label is null

// Original guard: x1 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(153,"null",153,154,guard_polytope,assignment));

Out_Going_Trans_fromloc_286.push_back(t);
l = location::ptr(new location(153, "loc_286", system_dynamics, invariant, true, Out_Going_Trans_fromloc_286));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_287

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_287;


l = location::ptr(new location(154, "loc_287", system_dynamics, invariant, true, Out_Going_Trans_fromloc_287));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_299

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_299;

// The transition label is null

// Original guard: x2 >= 15 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(154,"null",155,157,guard_polytope,assignment));

Out_Going_Trans_fromloc_299.push_back(t);
l = location::ptr(new location(155, "loc_299", system_dynamics, invariant, true, Out_Going_Trans_fromloc_299));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_300

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_300;

// The transition label is null

// Original guard: x2 <= 15 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(155,"null",156,147,guard_polytope,assignment));

Out_Going_Trans_fromloc_300.push_back(t);
l = location::ptr(new location(156, "loc_300", system_dynamics, invariant, true, Out_Going_Trans_fromloc_300));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_319

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_319;

// The transition label is null

// Original guard: x2 >= 16 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -16.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(156,"null",157,163,guard_polytope,assignment));

Out_Going_Trans_fromloc_319.push_back(t);
l = location::ptr(new location(157, "loc_319", system_dynamics, invariant, true, Out_Going_Trans_fromloc_319));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_320

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = -0.49497473892893223;
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
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_320;

// The transition label is null

// Original guard: x2 <= 16 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 16.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(157,"null",158,156,guard_polytope,assignment));

Out_Going_Trans_fromloc_320.push_back(t);
l = location::ptr(new location(158, "loc_320", system_dynamics, invariant, true, Out_Going_Trans_fromloc_320));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_321

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_321;

// The transition label is null

// Original guard: x1 <= 1 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(158,"null",159,158,guard_polytope,assignment));

Out_Going_Trans_fromloc_321.push_back(t);
l = location::ptr(new location(159, "loc_321", system_dynamics, invariant, true, Out_Going_Trans_fromloc_321));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_336

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_336;

// The transition label is null

// Original guard: x2 >= 17 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(159,"null",160,177,guard_polytope,assignment));

Out_Going_Trans_fromloc_336.push_back(t);
l = location::ptr(new location(160, "loc_336", system_dynamics, invariant, true, Out_Going_Trans_fromloc_336));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_337

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_337;

// The transition label is null

// Original guard: x1 <= 17 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(160,"null",161,160,guard_polytope,assignment));

Out_Going_Trans_fromloc_337.push_back(t);
l = location::ptr(new location(161, "loc_337", system_dynamics, invariant, true, Out_Going_Trans_fromloc_337));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_338

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_338;

// The transition label is null

// Original guard: x1 <= 18 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(161,"null",162,161,guard_polytope,assignment));

Out_Going_Trans_fromloc_338.push_back(t);
l = location::ptr(new location(162, "loc_338", system_dynamics, invariant, true, Out_Going_Trans_fromloc_338));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_339

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_339;

// The transition label is null

// Original guard: x1 <= 19 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 19.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(162,"null",163,162,guard_polytope,assignment));

Out_Going_Trans_fromloc_339.push_back(t);
// The transition label is null

// Original guard: x2 >= 17 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(163,"null",163,178,guard_polytope,assignment));

Out_Going_Trans_fromloc_339.push_back(t);
l = location::ptr(new location(163, "loc_339", system_dynamics, invariant, true, Out_Going_Trans_fromloc_339));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_341

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = -0.49497473892893223;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_341;

// The transition label is null

// Original guard: x1 >= 2 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(164,"null",164,165,guard_polytope,assignment));

Out_Going_Trans_fromloc_341.push_back(t);
// The transition label is null

// Original guard: x2 <= 17 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 17.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(165,"null",164,159,guard_polytope,assignment));

Out_Going_Trans_fromloc_341.push_back(t);
l = location::ptr(new location(164, "loc_341", system_dynamics, invariant, true, Out_Going_Trans_fromloc_341));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_342

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_342;

// The transition label is null

// Original guard: x1 >= 3 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(166,"null",165,166,guard_polytope,assignment));

Out_Going_Trans_fromloc_342.push_back(t);
l = location::ptr(new location(165, "loc_342", system_dynamics, invariant, true, Out_Going_Trans_fromloc_342));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_343

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_343;

// The transition label is null

// Original guard: x1 >= 4 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(167,"null",166,167,guard_polytope,assignment));

Out_Going_Trans_fromloc_343.push_back(t);
l = location::ptr(new location(166, "loc_343", system_dynamics, invariant, true, Out_Going_Trans_fromloc_343));
Hybrid_Automata.addLocation(l);

}

void navT02_Timed_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_344

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_344;

// The transition label is null

// Original guard: x1 >= 5 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(168,"null",167,168,guard_polytope,assignment));

Out_Going_Trans_fromloc_344.push_back(t);
l = location::ptr(new location(167, "loc_344", system_dynamics, invariant, true, Out_Going_Trans_fromloc_344));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_345

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_345;

// The transition label is null

// Original guard: x1 >= 6 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(169,"null",168,169,guard_polytope,assignment));

Out_Going_Trans_fromloc_345.push_back(t);
l = location::ptr(new location(168, "loc_345", system_dynamics, invariant, true, Out_Going_Trans_fromloc_345));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_346

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_346;

// The transition label is null

// Original guard: x1 >= 7 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(170,"null",169,170,guard_polytope,assignment));

Out_Going_Trans_fromloc_346.push_back(t);
l = location::ptr(new location(169, "loc_346", system_dynamics, invariant, true, Out_Going_Trans_fromloc_346));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_347

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_347;

// The transition label is null

// Original guard: x1 >= 8 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(171,"null",170,171,guard_polytope,assignment));

Out_Going_Trans_fromloc_347.push_back(t);
l = location::ptr(new location(170, "loc_347", system_dynamics, invariant, true, Out_Going_Trans_fromloc_347));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_348

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_348;

// The transition label is null

// Original guard: x1 >= 9 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(172,"null",171,172,guard_polytope,assignment));

Out_Going_Trans_fromloc_348.push_back(t);
l = location::ptr(new location(171, "loc_348", system_dynamics, invariant, true, Out_Going_Trans_fromloc_348));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_349

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_349;

// The transition label is null

// Original guard: x1 >= 10 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(173,"null",172,173,guard_polytope,assignment));

Out_Going_Trans_fromloc_349.push_back(t);
l = location::ptr(new location(172, "loc_349", system_dynamics, invariant, true, Out_Going_Trans_fromloc_349));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_350

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_350;

// The transition label is null

// Original guard: x1 >= 11 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(174,"null",173,174,guard_polytope,assignment));

Out_Going_Trans_fromloc_350.push_back(t);
l = location::ptr(new location(173, "loc_350", system_dynamics, invariant, true, Out_Going_Trans_fromloc_350));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_351

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_351;

// The transition label is null

// Original guard: x1 >= 12 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(175,"null",174,175,guard_polytope,assignment));

Out_Going_Trans_fromloc_351.push_back(t);
l = location::ptr(new location(174, "loc_351", system_dynamics, invariant, true, Out_Going_Trans_fromloc_351));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_352

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 1.20000005;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_352;

// The transition label is null

// Original guard: x1 >= 13 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

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

t = transition::ptr(new transition(176,"null",175,176,guard_polytope,assignment));

Out_Going_Trans_fromloc_352.push_back(t);
l = location::ptr(new location(175, "loc_352", system_dynamics, invariant, true, Out_Going_Trans_fromloc_352));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_353

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = 0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_353;

// The transition label is null

// Original guard: x2 >= 18 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(177,"null",176,187,guard_polytope,assignment));

Out_Going_Trans_fromloc_353.push_back(t);
l = location::ptr(new location(176, "loc_353", system_dynamics, invariant, true, Out_Going_Trans_fromloc_353));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_356

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_356;

// The transition label is null

// Original guard: x2 >= 18 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(178,"null",177,188,guard_polytope,assignment));

Out_Going_Trans_fromloc_356.push_back(t);
l = location::ptr(new location(177, "loc_356", system_dynamics, invariant, true, Out_Going_Trans_fromloc_356));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_359

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_359;

// The transition label is null

// Original guard: x2 >= 18 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(179,"null",178,189,guard_polytope,assignment));

Out_Going_Trans_fromloc_359.push_back(t);
l = location::ptr(new location(178, "loc_359", system_dynamics, invariant, true, Out_Going_Trans_fromloc_359));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_361

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = -0.69999999;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_361;

// The transition label is null

// Original guard: x2 <= 18 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 18.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(180,"null",179,164,guard_polytope,assignment));

Out_Going_Trans_fromloc_361.push_back(t);
l = location::ptr(new location(179, "loc_361", system_dynamics, invariant, true, Out_Going_Trans_fromloc_361));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_366

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_366;


l = location::ptr(new location(180, "loc_366", system_dynamics, invariant, true, Out_Going_Trans_fromloc_366));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_367

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_367;

// The transition label is null

// Original guard: x1 <= 7 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(181,"null",181,180,guard_polytope,assignment));

Out_Going_Trans_fromloc_367.push_back(t);
l = location::ptr(new location(181, "loc_367", system_dynamics, invariant, true, Out_Going_Trans_fromloc_367));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_368

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_368;

// The transition label is null

// Original guard: x1 <= 8 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(182,"null",182,181,guard_polytope,assignment));

Out_Going_Trans_fromloc_368.push_back(t);
l = location::ptr(new location(182, "loc_368", system_dynamics, invariant, true, Out_Going_Trans_fromloc_368));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_369

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_369;

// The transition label is null

// Original guard: x1 <= 9 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(183,"null",183,182,guard_polytope,assignment));

Out_Going_Trans_fromloc_369.push_back(t);
l = location::ptr(new location(183, "loc_369", system_dynamics, invariant, true, Out_Going_Trans_fromloc_369));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_370

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_370;

// The transition label is null

// Original guard: x1 <= 10 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(184,"null",184,183,guard_polytope,assignment));

Out_Going_Trans_fromloc_370.push_back(t);
l = location::ptr(new location(184, "loc_370", system_dynamics, invariant, true, Out_Going_Trans_fromloc_370));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_371

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_371;

// The transition label is null

// Original guard: x1 <= 11 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(185,"null",185,184,guard_polytope,assignment));

Out_Going_Trans_fromloc_371.push_back(t);
l = location::ptr(new location(185, "loc_371", system_dynamics, invariant, true, Out_Going_Trans_fromloc_371));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_372

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_372;

// The transition label is null

// Original guard: x1 <= 12 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(186,"null",186,185,guard_polytope,assignment));

Out_Going_Trans_fromloc_372.push_back(t);
l = location::ptr(new location(186, "loc_372", system_dynamics, invariant, true, Out_Going_Trans_fromloc_372));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_373

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_373;

// The transition label is null

// Original guard: x1 <= 13 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(187,"null",187,186,guard_polytope,assignment));

Out_Going_Trans_fromloc_373.push_back(t);
l = location::ptr(new location(187, "loc_373", system_dynamics, invariant, true, Out_Going_Trans_fromloc_373));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_376

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_376;

// The transition label is null

// Original guard: x2 >= 19 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -19.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(188,"null",188,205,guard_polytope,assignment));

Out_Going_Trans_fromloc_376.push_back(t);
l = location::ptr(new location(188, "loc_376", system_dynamics, invariant, true, Out_Going_Trans_fromloc_376));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_379

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[3] = 0.69999999;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_379;

// The transition label is null

// Original guard: x2 >= 19 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -19.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(189,"null",189,207,guard_polytope,assignment));

Out_Going_Trans_fromloc_379.push_back(t);
l = location::ptr(new location(189, "loc_379", system_dynamics, invariant, true, Out_Going_Trans_fromloc_379));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_381

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = -0.49497473892893223;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_381;

// The transition label is null

// Original guard: x2 <= 19 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 19.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(190,"null",190,179,guard_polytope,assignment));

Out_Going_Trans_fromloc_381.push_back(t);
l = location::ptr(new location(190, "loc_381", system_dynamics, invariant, true, Out_Going_Trans_fromloc_381));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_382

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_382;

// The transition label is null

// Original guard: x1 <= 2 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(191,"null",191,190,guard_polytope,assignment));

Out_Going_Trans_fromloc_382.push_back(t);
l = location::ptr(new location(191, "loc_382", system_dynamics, invariant, true, Out_Going_Trans_fromloc_382));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_383

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_383;

// The transition label is null

// Original guard: x1 <= 3 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(192,"null",192,191,guard_polytope,assignment));

Out_Going_Trans_fromloc_383.push_back(t);
l = location::ptr(new location(192, "loc_383", system_dynamics, invariant, true, Out_Going_Trans_fromloc_383));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_384

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_384;

// The transition label is null

// Original guard: x1 <= 4 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(193,"null",193,192,guard_polytope,assignment));

Out_Going_Trans_fromloc_384.push_back(t);
l = location::ptr(new location(193, "loc_384", system_dynamics, invariant, true, Out_Going_Trans_fromloc_384));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_385

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_385;

// The transition label is null

// Original guard: x1 <= 5 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(194,"null",194,193,guard_polytope,assignment));

Out_Going_Trans_fromloc_385.push_back(t);
l = location::ptr(new location(194, "loc_385", system_dynamics, invariant, true, Out_Going_Trans_fromloc_385));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_386

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_386;

// The transition label is null

// Original guard: x1 <= 6 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(195,"null",195,194,guard_polytope,assignment));

Out_Going_Trans_fromloc_386.push_back(t);
l = location::ptr(new location(195, "loc_386", system_dynamics, invariant, true, Out_Going_Trans_fromloc_386));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_387

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_387;

// The transition label is null

// Original guard: x1 <= 7 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(196,"null",196,195,guard_polytope,assignment));

Out_Going_Trans_fromloc_387.push_back(t);
l = location::ptr(new location(196, "loc_387", system_dynamics, invariant, true, Out_Going_Trans_fromloc_387));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_388

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_388;

// The transition label is null

// Original guard: x1 <= 8 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(197,"null",197,196,guard_polytope,assignment));

Out_Going_Trans_fromloc_388.push_back(t);
l = location::ptr(new location(197, "loc_388", system_dynamics, invariant, true, Out_Going_Trans_fromloc_388));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_389

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_389;

// The transition label is null

// Original guard: x1 <= 9 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(198,"null",198,197,guard_polytope,assignment));

Out_Going_Trans_fromloc_389.push_back(t);
l = location::ptr(new location(198, "loc_389", system_dynamics, invariant, true, Out_Going_Trans_fromloc_389));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_390

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_390;

// The transition label is null

// Original guard: x1 <= 10 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(199,"null",199,198,guard_polytope,assignment));

Out_Going_Trans_fromloc_390.push_back(t);
l = location::ptr(new location(199, "loc_390", system_dynamics, invariant, true, Out_Going_Trans_fromloc_390));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_391

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_391;

// The transition label is null

// Original guard: x1 <= 11 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(200,"null",200,199,guard_polytope,assignment));

Out_Going_Trans_fromloc_391.push_back(t);
l = location::ptr(new location(200, "loc_391", system_dynamics, invariant, true, Out_Going_Trans_fromloc_391));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_392

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_392;

// The transition label is null

// Original guard: x1 <= 12 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(201,"null",201,200,guard_polytope,assignment));

Out_Going_Trans_fromloc_392.push_back(t);
l = location::ptr(new location(201, "loc_392", system_dynamics, invariant, true, Out_Going_Trans_fromloc_392));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_393

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_393;

// The transition label is null

// Original guard: x1 <= 13 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(202,"null",202,201,guard_polytope,assignment));

Out_Going_Trans_fromloc_393.push_back(t);
l = location::ptr(new location(202, "loc_393", system_dynamics, invariant, true, Out_Going_Trans_fromloc_393));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_394

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_394;

// The transition label is null

// Original guard: x1 <= 14 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

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

t = transition::ptr(new transition(203,"null",203,202,guard_polytope,assignment));

Out_Going_Trans_fromloc_394.push_back(t);
l = location::ptr(new location(203, "loc_394", system_dynamics, invariant, true, Out_Going_Trans_fromloc_394));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_395

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_395;

// The transition label is null

// Original guard: x1 <= 15 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 15.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(204,"null",204,203,guard_polytope,assignment));

Out_Going_Trans_fromloc_395.push_back(t);
l = location::ptr(new location(204, "loc_395", system_dynamics, invariant, true, Out_Going_Trans_fromloc_395));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_396

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_396;

// The transition label is null

// Original guard: x1 <= 16 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 16.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(205,"null",205,204,guard_polytope,assignment));

Out_Going_Trans_fromloc_396.push_back(t);
l = location::ptr(new location(205, "loc_396", system_dynamics, invariant, true, Out_Going_Trans_fromloc_396));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_398

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -1.20000005;
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_398;


l = location::ptr(new location(206, "loc_398", system_dynamics, invariant, true, Out_Going_Trans_fromloc_398));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_399

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.20000005;
Amatrix(3 , 3) = -0.69999999;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[2] = -0.8485281713553391;
C[3] = 0.49497473892893223;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_399;

// The transition label is null

// Original guard: x1 <= 19 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 19.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(206,"null",207,206,guard_polytope,assignment));

Out_Going_Trans_fromloc_399.push_back(t);
l = location::ptr(new location(207, "loc_399", system_dynamics, invariant, true, Out_Going_Trans_fromloc_399));
Hybrid_Automata.addLocation(l);

}

