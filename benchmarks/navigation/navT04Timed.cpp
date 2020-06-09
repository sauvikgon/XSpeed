// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav04/navT04_Timed.xml
// Command Line arguments: -tool xspeed "" -output /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav04/navT04_Timed.cpp -input /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav04/navT04_Timed.xml /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav04/nav04-pdb.cfg


#include <benchmarks/navigation/navT04Timed.h>
void setnavT04_Timedmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
invariantBoundValue[1] = 1.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_0;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(1,"null",1,26,guard_polytope,assignment));

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
invariantBoundValue[0] = -1.0;
invariantBoundValue[1] = 2.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_1;

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

t = transition::ptr(new transition(2,"null",2,1,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_2;

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

t = transition::ptr(new transition(3,"null",3,2,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_3;

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

t = transition::ptr(new transition(4,"null",4,3,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_4;

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

t = transition::ptr(new transition(5,"null",5,4,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_5;

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

t = transition::ptr(new transition(6,"null",6,5,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_6;

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

t = transition::ptr(new transition(7,"null",7,6,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_7;

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

t = transition::ptr(new transition(8,"null",8,7,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_8;

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

t = transition::ptr(new transition(9,"null",9,8,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_9;

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

t = transition::ptr(new transition(10,"null",10,9,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_10;

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

t = transition::ptr(new transition(11,"null",11,10,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_11;

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

t = transition::ptr(new transition(12,"null",12,11,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_12;

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

t = transition::ptr(new transition(13,"null",13,12,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_13;

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

t = transition::ptr(new transition(14,"null",14,13,guard_polytope,assignment));

Out_Going_Trans_fromloc_13.push_back(t);
l = location::ptr(new location(14, "loc_13", system_dynamics, invariant, true, Out_Going_Trans_fromloc_13));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_14;

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

t = transition::ptr(new transition(15,"null",15,14,guard_polytope,assignment));

Out_Going_Trans_fromloc_14.push_back(t);
l = location::ptr(new location(15, "loc_14", system_dynamics, invariant, true, Out_Going_Trans_fromloc_14));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_15;

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

t = transition::ptr(new transition(16,"null",16,15,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_16;

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

t = transition::ptr(new transition(17,"null",17,16,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_17;

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

t = transition::ptr(new transition(18,"null",18,17,guard_polytope,assignment));

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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_18;

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

t = transition::ptr(new transition(19,"null",19,18,guard_polytope,assignment));

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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_19;

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

t = transition::ptr(new transition(20,"null",20,19,guard_polytope,assignment));

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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_20;

// The transition label is null

// Original guard: x1 <= 20 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(21,"null",21,20,guard_polytope,assignment));

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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_21;

// The transition label is null

// Original guard: x1 <= 21 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(22,"null",22,21,guard_polytope,assignment));

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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_22;

// The transition label is null

// Original guard: x1 <= 22 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 22.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(23,"null",23,22,guard_polytope,assignment));

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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_23;

// The transition label is null

// Original guard: x1 <= 23 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 23.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(24,"null",24,23,guard_polytope,assignment));

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_24;

// The transition label is null

// Original guard: x1 <= 24 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 24.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(25,"null",25,24,guard_polytope,assignment));

Out_Going_Trans_fromloc_24.push_back(t);
l = location::ptr(new location(25, "loc_24", system_dynamics, invariant, true, Out_Going_Trans_fromloc_24));

Hybrid_Automata.addInitialLocation(l);
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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_25;

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

t = transition::ptr(new transition(26,"null",26,27,guard_polytope,assignment));

Out_Going_Trans_fromloc_25.push_back(t);
l = location::ptr(new location(26, "loc_25", system_dynamics, invariant, true, Out_Going_Trans_fromloc_25));
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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_50;

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

t = transition::ptr(new transition(27,"null",27,28,guard_polytope,assignment));

Out_Going_Trans_fromloc_50.push_back(t);
l = location::ptr(new location(27, "loc_50", system_dynamics, invariant, true, Out_Going_Trans_fromloc_50));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_75

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_75;

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

t = transition::ptr(new transition(28,"null",28,52,guard_polytope,assignment));

Out_Going_Trans_fromloc_75.push_back(t);
l = location::ptr(new location(28, "loc_75", system_dynamics, invariant, true, Out_Going_Trans_fromloc_75));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_77

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_77;

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

t = transition::ptr(new transition(29,"null",29,53,guard_polytope,assignment));

Out_Going_Trans_fromloc_77.push_back(t);
l = location::ptr(new location(29, "loc_77", system_dynamics, invariant, true, Out_Going_Trans_fromloc_77));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_78;

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

t = transition::ptr(new transition(30,"null",30,29,guard_polytope,assignment));

Out_Going_Trans_fromloc_78.push_back(t);
l = location::ptr(new location(30, "loc_78", system_dynamics, invariant, true, Out_Going_Trans_fromloc_78));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_79

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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_79;

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

t = transition::ptr(new transition(31,"null",31,30,guard_polytope,assignment));

Out_Going_Trans_fromloc_79.push_back(t);
l = location::ptr(new location(31, "loc_79", system_dynamics, invariant, true, Out_Going_Trans_fromloc_79));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_80;

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

t = transition::ptr(new transition(32,"null",32,31,guard_polytope,assignment));

Out_Going_Trans_fromloc_80.push_back(t);
l = location::ptr(new location(32, "loc_80", system_dynamics, invariant, true, Out_Going_Trans_fromloc_80));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_81;

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

t = transition::ptr(new transition(33,"null",33,32,guard_polytope,assignment));

Out_Going_Trans_fromloc_81.push_back(t);
l = location::ptr(new location(33, "loc_81", system_dynamics, invariant, true, Out_Going_Trans_fromloc_81));
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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_82;

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

t = transition::ptr(new transition(34,"null",34,33,guard_polytope,assignment));

Out_Going_Trans_fromloc_82.push_back(t);
l = location::ptr(new location(34, "loc_82", system_dynamics, invariant, true, Out_Going_Trans_fromloc_82));
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
invariantBoundValue[0] = -8.0;
invariantBoundValue[1] = 9.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_83;

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

t = transition::ptr(new transition(35,"null",35,34,guard_polytope,assignment));

Out_Going_Trans_fromloc_83.push_back(t);
l = location::ptr(new location(35, "loc_83", system_dynamics, invariant, true, Out_Going_Trans_fromloc_83));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_84;

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

t = transition::ptr(new transition(36,"null",36,35,guard_polytope,assignment));

Out_Going_Trans_fromloc_84.push_back(t);
l = location::ptr(new location(36, "loc_84", system_dynamics, invariant, true, Out_Going_Trans_fromloc_84));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_85;

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

t = transition::ptr(new transition(37,"null",37,36,guard_polytope,assignment));

Out_Going_Trans_fromloc_85.push_back(t);
l = location::ptr(new location(37, "loc_85", system_dynamics, invariant, true, Out_Going_Trans_fromloc_85));
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


std::list<transition::ptr> Out_Going_Trans_fromloc_86;

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

t = transition::ptr(new transition(38,"null",38,37,guard_polytope,assignment));

Out_Going_Trans_fromloc_86.push_back(t);
l = location::ptr(new location(38, "loc_86", system_dynamics, invariant, true, Out_Going_Trans_fromloc_86));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_87;

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

t = transition::ptr(new transition(39,"null",39,38,guard_polytope,assignment));

Out_Going_Trans_fromloc_87.push_back(t);
l = location::ptr(new location(39, "loc_87", system_dynamics, invariant, true, Out_Going_Trans_fromloc_87));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_88

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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_88;

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

t = transition::ptr(new transition(40,"null",40,39,guard_polytope,assignment));

Out_Going_Trans_fromloc_88.push_back(t);
l = location::ptr(new location(40, "loc_88", system_dynamics, invariant, true, Out_Going_Trans_fromloc_88));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_89

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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_89;

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

t = transition::ptr(new transition(41,"null",41,40,guard_polytope,assignment));

Out_Going_Trans_fromloc_89.push_back(t);
l = location::ptr(new location(41, "loc_89", system_dynamics, invariant, true, Out_Going_Trans_fromloc_89));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_90;

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

t = transition::ptr(new transition(42,"null",42,41,guard_polytope,assignment));

Out_Going_Trans_fromloc_90.push_back(t);
l = location::ptr(new location(42, "loc_90", system_dynamics, invariant, true, Out_Going_Trans_fromloc_90));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_91

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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_91;

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

t = transition::ptr(new transition(43,"null",43,42,guard_polytope,assignment));

Out_Going_Trans_fromloc_91.push_back(t);
l = location::ptr(new location(43, "loc_91", system_dynamics, invariant, true, Out_Going_Trans_fromloc_91));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_92;

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

t = transition::ptr(new transition(44,"null",44,43,guard_polytope,assignment));

Out_Going_Trans_fromloc_92.push_back(t);
l = location::ptr(new location(44, "loc_92", system_dynamics, invariant, true, Out_Going_Trans_fromloc_92));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_93

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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_93;

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

t = transition::ptr(new transition(45,"null",45,44,guard_polytope,assignment));

Out_Going_Trans_fromloc_93.push_back(t);
l = location::ptr(new location(45, "loc_93", system_dynamics, invariant, true, Out_Going_Trans_fromloc_93));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_94

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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_94;

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

t = transition::ptr(new transition(46,"null",46,45,guard_polytope,assignment));

Out_Going_Trans_fromloc_94.push_back(t);
l = location::ptr(new location(46, "loc_94", system_dynamics, invariant, true, Out_Going_Trans_fromloc_94));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_95

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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_95;

// The transition label is null

// Original guard: x1 <= 20 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(47,"null",47,46,guard_polytope,assignment));

Out_Going_Trans_fromloc_95.push_back(t);
l = location::ptr(new location(47, "loc_95", system_dynamics, invariant, true, Out_Going_Trans_fromloc_95));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_96

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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_96;

// The transition label is null

// Original guard: x1 <= 21 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(48,"null",48,47,guard_polytope,assignment));

Out_Going_Trans_fromloc_96.push_back(t);
l = location::ptr(new location(48, "loc_96", system_dynamics, invariant, true, Out_Going_Trans_fromloc_96));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_97

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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_97;

// The transition label is null

// Original guard: x1 <= 22 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 22.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(49,"null",49,48,guard_polytope,assignment));

Out_Going_Trans_fromloc_97.push_back(t);
l = location::ptr(new location(49, "loc_97", system_dynamics, invariant, true, Out_Going_Trans_fromloc_97));
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_98;

// The transition label is null

// Original guard: x1 <= 23 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 23.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(50,"null",50,49,guard_polytope,assignment));

Out_Going_Trans_fromloc_98.push_back(t);
l = location::ptr(new location(50, "loc_98", system_dynamics, invariant, true, Out_Going_Trans_fromloc_98));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_99

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_99;

// The transition label is null

// Original guard: x1 <= 24 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 24.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(51,"null",51,50,guard_polytope,assignment));

Out_Going_Trans_fromloc_99.push_back(t);
l = location::ptr(new location(51, "loc_99", system_dynamics, invariant, true, Out_Going_Trans_fromloc_99));
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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_100;

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

t = transition::ptr(new transition(52,"null",52,55,guard_polytope,assignment));

Out_Going_Trans_fromloc_100.push_back(t);
l = location::ptr(new location(52, "loc_100", system_dynamics, invariant, true, Out_Going_Trans_fromloc_100));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_102

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_102;

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

t = transition::ptr(new transition(53,"null",53,56,guard_polytope,assignment));

Out_Going_Trans_fromloc_102.push_back(t);
l = location::ptr(new location(53, "loc_102", system_dynamics, invariant, true, Out_Going_Trans_fromloc_102));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_124

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_124;

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

t = transition::ptr(new transition(54,"null",54,51,guard_polytope,assignment));

Out_Going_Trans_fromloc_124.push_back(t);
l = location::ptr(new location(54, "loc_124", system_dynamics, invariant, true, Out_Going_Trans_fromloc_124));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_125

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_125;

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

t = transition::ptr(new transition(55,"null",55,76,guard_polytope,assignment));

Out_Going_Trans_fromloc_125.push_back(t);
l = location::ptr(new location(55, "loc_125", system_dynamics, invariant, true, Out_Going_Trans_fromloc_125));
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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_127;

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

t = transition::ptr(new transition(56,"null",56,77,guard_polytope,assignment));

Out_Going_Trans_fromloc_127.push_back(t);
l = location::ptr(new location(56, "loc_127", system_dynamics, invariant, true, Out_Going_Trans_fromloc_127));
Hybrid_Automata.addLocation(l);

navT04_Timed_module1(Hybrid_Automata,init_state_list,reach_parameters);
navT04_Timed_module2(Hybrid_Automata,init_state_list,reach_parameters);
navT04_Timed_module3(Hybrid_Automata,init_state_list,reach_parameters);
navT04_Timed_module4(Hybrid_Automata,init_state_list,reach_parameters);

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
boundValueI[0]=25;
boundValueI[1]=-24;
boundValueI[2]=1;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =25;

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

void navT04_Timed_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_129;

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

t = transition::ptr(new transition(57,"null",57,58,guard_polytope,assignment));

Out_Going_Trans_fromloc_129.push_back(t);
l = location::ptr(new location(57, "loc_129", system_dynamics, invariant, true, Out_Going_Trans_fromloc_129));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_130;

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

t = transition::ptr(new transition(58,"null",58,59,guard_polytope,assignment));

Out_Going_Trans_fromloc_130.push_back(t);
l = location::ptr(new location(58, "loc_130", system_dynamics, invariant, true, Out_Going_Trans_fromloc_130));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_131

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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_131;

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

t = transition::ptr(new transition(59,"null",59,60,guard_polytope,assignment));

Out_Going_Trans_fromloc_131.push_back(t);
l = location::ptr(new location(59, "loc_131", system_dynamics, invariant, true, Out_Going_Trans_fromloc_131));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_132;

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

t = transition::ptr(new transition(60,"null",60,61,guard_polytope,assignment));

Out_Going_Trans_fromloc_132.push_back(t);
l = location::ptr(new location(60, "loc_132", system_dynamics, invariant, true, Out_Going_Trans_fromloc_132));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_133

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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_133;

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

t = transition::ptr(new transition(61,"null",61,62,guard_polytope,assignment));

Out_Going_Trans_fromloc_133.push_back(t);
l = location::ptr(new location(61, "loc_133", system_dynamics, invariant, true, Out_Going_Trans_fromloc_133));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_134

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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_134;

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

t = transition::ptr(new transition(62,"null",62,63,guard_polytope,assignment));

Out_Going_Trans_fromloc_134.push_back(t);
l = location::ptr(new location(62, "loc_134", system_dynamics, invariant, true, Out_Going_Trans_fromloc_134));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_135

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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_135;

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

t = transition::ptr(new transition(63,"null",63,64,guard_polytope,assignment));

Out_Going_Trans_fromloc_135.push_back(t);
l = location::ptr(new location(63, "loc_135", system_dynamics, invariant, true, Out_Going_Trans_fromloc_135));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_136

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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_136;

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

t = transition::ptr(new transition(64,"null",64,65,guard_polytope,assignment));

Out_Going_Trans_fromloc_136.push_back(t);
l = location::ptr(new location(64, "loc_136", system_dynamics, invariant, true, Out_Going_Trans_fromloc_136));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_137;

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

t = transition::ptr(new transition(65,"null",65,66,guard_polytope,assignment));

Out_Going_Trans_fromloc_137.push_back(t);
l = location::ptr(new location(65, "loc_137", system_dynamics, invariant, true, Out_Going_Trans_fromloc_137));
Hybrid_Automata.addLocation(l);


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
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_138;

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

t = transition::ptr(new transition(66,"null",66,67,guard_polytope,assignment));

Out_Going_Trans_fromloc_138.push_back(t);
l = location::ptr(new location(66, "loc_138", system_dynamics, invariant, true, Out_Going_Trans_fromloc_138));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_139;

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

t = transition::ptr(new transition(67,"null",67,68,guard_polytope,assignment));

Out_Going_Trans_fromloc_139.push_back(t);
l = location::ptr(new location(67, "loc_139", system_dynamics, invariant, true, Out_Going_Trans_fromloc_139));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_140;

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

t = transition::ptr(new transition(68,"null",68,69,guard_polytope,assignment));

Out_Going_Trans_fromloc_140.push_back(t);
l = location::ptr(new location(68, "loc_140", system_dynamics, invariant, true, Out_Going_Trans_fromloc_140));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_141;

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

t = transition::ptr(new transition(69,"null",69,70,guard_polytope,assignment));

Out_Going_Trans_fromloc_141.push_back(t);
l = location::ptr(new location(69, "loc_141", system_dynamics, invariant, true, Out_Going_Trans_fromloc_141));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_142

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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_142;

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

t = transition::ptr(new transition(70,"null",70,71,guard_polytope,assignment));

Out_Going_Trans_fromloc_142.push_back(t);
l = location::ptr(new location(70, "loc_142", system_dynamics, invariant, true, Out_Going_Trans_fromloc_142));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_143

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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_143;

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

t = transition::ptr(new transition(71,"null",71,72,guard_polytope,assignment));

Out_Going_Trans_fromloc_143.push_back(t);
l = location::ptr(new location(71, "loc_143", system_dynamics, invariant, true, Out_Going_Trans_fromloc_143));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_144

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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_144;

// The transition label is null

// Original guard: x1 >= 20 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(72,"null",72,73,guard_polytope,assignment));

Out_Going_Trans_fromloc_144.push_back(t);
l = location::ptr(new location(72, "loc_144", system_dynamics, invariant, true, Out_Going_Trans_fromloc_144));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_145

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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_145;

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

t = transition::ptr(new transition(73,"null",73,79,guard_polytope,assignment));

Out_Going_Trans_fromloc_145.push_back(t);
l = location::ptr(new location(73, "loc_145", system_dynamics, invariant, true, Out_Going_Trans_fromloc_145));
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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_147;


l = location::ptr(new location(74, "loc_147", system_dynamics, invariant, true, Out_Going_Trans_fromloc_147));
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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_149;

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

t = transition::ptr(new transition(74,"null",75,54,guard_polytope,assignment));

Out_Going_Trans_fromloc_149.push_back(t);
l = location::ptr(new location(75, "loc_149", system_dynamics, invariant, true, Out_Going_Trans_fromloc_149));
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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_150;

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

t = transition::ptr(new transition(75,"null",76,82,guard_polytope,assignment));

Out_Going_Trans_fromloc_150.push_back(t);
l = location::ptr(new location(76, "loc_150", system_dynamics, invariant, true, Out_Going_Trans_fromloc_150));
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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_152;

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

t = transition::ptr(new transition(76,"null",77,83,guard_polytope,assignment));

Out_Going_Trans_fromloc_152.push_back(t);
l = location::ptr(new location(77, "loc_152", system_dynamics, invariant, true, Out_Going_Trans_fromloc_152));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_154

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
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_154;

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

t = transition::ptr(new transition(77,"null",78,57,guard_polytope,assignment));

Out_Going_Trans_fromloc_154.push_back(t);
l = location::ptr(new location(78, "loc_154", system_dynamics, invariant, true, Out_Going_Trans_fromloc_154));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_170

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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_170;

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

t = transition::ptr(new transition(78,"null",79,96,guard_polytope,assignment));

Out_Going_Trans_fromloc_170.push_back(t);
l = location::ptr(new location(79, "loc_170", system_dynamics, invariant, true, Out_Going_Trans_fromloc_170));
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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_172;

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

t = transition::ptr(new transition(79,"null",80,74,guard_polytope,assignment));

Out_Going_Trans_fromloc_172.push_back(t);
l = location::ptr(new location(80, "loc_172", system_dynamics, invariant, true, Out_Going_Trans_fromloc_172));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_174

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_174;

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

t = transition::ptr(new transition(80,"null",81,75,guard_polytope,assignment));

Out_Going_Trans_fromloc_174.push_back(t);
l = location::ptr(new location(81, "loc_174", system_dynamics, invariant, true, Out_Going_Trans_fromloc_174));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_175

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_175;

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

t = transition::ptr(new transition(81,"null",82,99,guard_polytope,assignment));

Out_Going_Trans_fromloc_175.push_back(t);
l = location::ptr(new location(82, "loc_175", system_dynamics, invariant, true, Out_Going_Trans_fromloc_175));
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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_177;

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

t = transition::ptr(new transition(82,"null",83,100,guard_polytope,assignment));

Out_Going_Trans_fromloc_177.push_back(t);
l = location::ptr(new location(83, "loc_177", system_dynamics, invariant, true, Out_Going_Trans_fromloc_177));
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
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_179;

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

t = transition::ptr(new transition(83,"null",84,78,guard_polytope,assignment));

Out_Going_Trans_fromloc_179.push_back(t);
l = location::ptr(new location(84, "loc_179", system_dynamics, invariant, true, Out_Going_Trans_fromloc_179));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_184

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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_184;

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

t = transition::ptr(new transition(84,"null",85,105,guard_polytope,assignment));

Out_Going_Trans_fromloc_184.push_back(t);
l = location::ptr(new location(85, "loc_184", system_dynamics, invariant, true, Out_Going_Trans_fromloc_184));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_185

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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_185;

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

t = transition::ptr(new transition(85,"null",86,85,guard_polytope,assignment));

Out_Going_Trans_fromloc_185.push_back(t);
l = location::ptr(new location(86, "loc_185", system_dynamics, invariant, true, Out_Going_Trans_fromloc_185));
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_186;

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

t = transition::ptr(new transition(86,"null",87,86,guard_polytope,assignment));

Out_Going_Trans_fromloc_186.push_back(t);
l = location::ptr(new location(87, "loc_186", system_dynamics, invariant, true, Out_Going_Trans_fromloc_186));
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_187;

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

t = transition::ptr(new transition(87,"null",88,87,guard_polytope,assignment));

Out_Going_Trans_fromloc_187.push_back(t);
l = location::ptr(new location(88, "loc_187", system_dynamics, invariant, true, Out_Going_Trans_fromloc_187));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_188

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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_188;

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

t = transition::ptr(new transition(88,"null",89,88,guard_polytope,assignment));

Out_Going_Trans_fromloc_188.push_back(t);
l = location::ptr(new location(89, "loc_188", system_dynamics, invariant, true, Out_Going_Trans_fromloc_188));
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_189;

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

t = transition::ptr(new transition(89,"null",90,89,guard_polytope,assignment));

Out_Going_Trans_fromloc_189.push_back(t);
l = location::ptr(new location(90, "loc_189", system_dynamics, invariant, true, Out_Going_Trans_fromloc_189));
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_190;

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

t = transition::ptr(new transition(90,"null",91,90,guard_polytope,assignment));

Out_Going_Trans_fromloc_190.push_back(t);
l = location::ptr(new location(91, "loc_190", system_dynamics, invariant, true, Out_Going_Trans_fromloc_190));
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
invariantBoundValue[0] = -16.0;
invariantBoundValue[1] = 17.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_191;

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

t = transition::ptr(new transition(91,"null",92,91,guard_polytope,assignment));

Out_Going_Trans_fromloc_191.push_back(t);
l = location::ptr(new location(92, "loc_191", system_dynamics, invariant, true, Out_Going_Trans_fromloc_191));
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_192;

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

t = transition::ptr(new transition(92,"null",93,92,guard_polytope,assignment));

Out_Going_Trans_fromloc_192.push_back(t);
l = location::ptr(new location(93, "loc_192", system_dynamics, invariant, true, Out_Going_Trans_fromloc_192));
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_193;

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

t = transition::ptr(new transition(93,"null",94,93,guard_polytope,assignment));

Out_Going_Trans_fromloc_193.push_back(t);
l = location::ptr(new location(94, "loc_193", system_dynamics, invariant, true, Out_Going_Trans_fromloc_193));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_194;

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

t = transition::ptr(new transition(94,"null",95,94,guard_polytope,assignment));

Out_Going_Trans_fromloc_194.push_back(t);
l = location::ptr(new location(95, "loc_194", system_dynamics, invariant, true, Out_Going_Trans_fromloc_194));
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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_195;

// The transition label is null

// Original guard: x1 <= 20 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(95,"null",96,95,guard_polytope,assignment));

Out_Going_Trans_fromloc_195.push_back(t);
l = location::ptr(new location(96, "loc_195", system_dynamics, invariant, true, Out_Going_Trans_fromloc_195));
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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_197;

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

t = transition::ptr(new transition(96,"null",97,80,guard_polytope,assignment));

Out_Going_Trans_fromloc_197.push_back(t);
l = location::ptr(new location(97, "loc_197", system_dynamics, invariant, true, Out_Going_Trans_fromloc_197));
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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_199;

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

t = transition::ptr(new transition(97,"null",98,81,guard_polytope,assignment));

Out_Going_Trans_fromloc_199.push_back(t);
l = location::ptr(new location(98, "loc_199", system_dynamics, invariant, true, Out_Going_Trans_fromloc_199));
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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_200;

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

t = transition::ptr(new transition(98,"null",99,108,guard_polytope,assignment));

Out_Going_Trans_fromloc_200.push_back(t);
l = location::ptr(new location(99, "loc_200", system_dynamics, invariant, true, Out_Going_Trans_fromloc_200));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_202

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_202;

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

t = transition::ptr(new transition(99,"null",100,109,guard_polytope,assignment));

Out_Going_Trans_fromloc_202.push_back(t);
l = location::ptr(new location(100, "loc_202", system_dynamics, invariant, true, Out_Going_Trans_fromloc_202));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_204

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
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_204;

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

t = transition::ptr(new transition(100,"null",101,84,guard_polytope,assignment));

Out_Going_Trans_fromloc_204.push_back(t);
l = location::ptr(new location(101, "loc_204", system_dynamics, invariant, true, Out_Going_Trans_fromloc_204));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_205

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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_205;

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

t = transition::ptr(new transition(101,"null",102,101,guard_polytope,assignment));

Out_Going_Trans_fromloc_205.push_back(t);
l = location::ptr(new location(102, "loc_205", system_dynamics, invariant, true, Out_Going_Trans_fromloc_205));
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_206;

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

t = transition::ptr(new transition(102,"null",103,102,guard_polytope,assignment));

Out_Going_Trans_fromloc_206.push_back(t);
l = location::ptr(new location(103, "loc_206", system_dynamics, invariant, true, Out_Going_Trans_fromloc_206));
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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_207;

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

t = transition::ptr(new transition(103,"null",104,103,guard_polytope,assignment));

Out_Going_Trans_fromloc_207.push_back(t);
l = location::ptr(new location(104, "loc_207", system_dynamics, invariant, true, Out_Going_Trans_fromloc_207));
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_209;

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

t = transition::ptr(new transition(104,"null",105,111,guard_polytope,assignment));

Out_Going_Trans_fromloc_209.push_back(t);
l = location::ptr(new location(105, "loc_209", system_dynamics, invariant, true, Out_Going_Trans_fromloc_209));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_222

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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_222;

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

t = transition::ptr(new transition(105,"null",106,97,guard_polytope,assignment));

Out_Going_Trans_fromloc_222.push_back(t);
l = location::ptr(new location(106, "loc_222", system_dynamics, invariant, true, Out_Going_Trans_fromloc_222));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_224

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_224;

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

t = transition::ptr(new transition(106,"null",107,98,guard_polytope,assignment));

Out_Going_Trans_fromloc_224.push_back(t);
l = location::ptr(new location(107, "loc_224", system_dynamics, invariant, true, Out_Going_Trans_fromloc_224));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_225

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_225;

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

t = transition::ptr(new transition(107,"null",108,124,guard_polytope,assignment));

Out_Going_Trans_fromloc_225.push_back(t);
l = location::ptr(new location(108, "loc_225", system_dynamics, invariant, true, Out_Going_Trans_fromloc_225));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_227

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_227;

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

t = transition::ptr(new transition(108,"null",109,125,guard_polytope,assignment));

Out_Going_Trans_fromloc_227.push_back(t);
l = location::ptr(new location(109, "loc_227", system_dynamics, invariant, true, Out_Going_Trans_fromloc_227));
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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_232;

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

t = transition::ptr(new transition(109,"null",110,104,guard_polytope,assignment));

Out_Going_Trans_fromloc_232.push_back(t);
l = location::ptr(new location(110, "loc_232", system_dynamics, invariant, true, Out_Going_Trans_fromloc_232));
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
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_234;

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

t = transition::ptr(new transition(110,"null",111,112,guard_polytope,assignment));

Out_Going_Trans_fromloc_234.push_back(t);
l = location::ptr(new location(111, "loc_234", system_dynamics, invariant, true, Out_Going_Trans_fromloc_234));
Hybrid_Automata.addLocation(l);

}

void navT04_Timed_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_235;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(111,"null",112,113,guard_polytope,assignment));

Out_Going_Trans_fromloc_235.push_back(t);
l = location::ptr(new location(112, "loc_235", system_dynamics, invariant, true, Out_Going_Trans_fromloc_235));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_236

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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_236;

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

t = transition::ptr(new transition(112,"null",113,128,guard_polytope,assignment));

Out_Going_Trans_fromloc_236.push_back(t);
l = location::ptr(new location(113, "loc_236", system_dynamics, invariant, true, Out_Going_Trans_fromloc_236));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_238

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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_238;

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

t = transition::ptr(new transition(113,"null",114,129,guard_polytope,assignment));

Out_Going_Trans_fromloc_238.push_back(t);
l = location::ptr(new location(114, "loc_238", system_dynamics, invariant, true, Out_Going_Trans_fromloc_238));
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_239;

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

t = transition::ptr(new transition(114,"null",115,114,guard_polytope,assignment));

Out_Going_Trans_fromloc_239.push_back(t);
l = location::ptr(new location(115, "loc_239", system_dynamics, invariant, true, Out_Going_Trans_fromloc_239));
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_240;

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

t = transition::ptr(new transition(115,"null",116,115,guard_polytope,assignment));

Out_Going_Trans_fromloc_240.push_back(t);
l = location::ptr(new location(116, "loc_240", system_dynamics, invariant, true, Out_Going_Trans_fromloc_240));
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_241;

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

t = transition::ptr(new transition(116,"null",117,116,guard_polytope,assignment));

Out_Going_Trans_fromloc_241.push_back(t);
l = location::ptr(new location(117, "loc_241", system_dynamics, invariant, true, Out_Going_Trans_fromloc_241));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_242

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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_242;

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

t = transition::ptr(new transition(117,"null",118,117,guard_polytope,assignment));

Out_Going_Trans_fromloc_242.push_back(t);
l = location::ptr(new location(118, "loc_242", system_dynamics, invariant, true, Out_Going_Trans_fromloc_242));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_243

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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_243;

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

t = transition::ptr(new transition(118,"null",119,120,guard_polytope,assignment));

Out_Going_Trans_fromloc_243.push_back(t);
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

t = transition::ptr(new transition(119,"null",119,118,guard_polytope,assignment));

Out_Going_Trans_fromloc_243.push_back(t);
l = location::ptr(new location(119, "loc_243", system_dynamics, invariant, true, Out_Going_Trans_fromloc_243));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_244

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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_244;

// The transition label is null

// Original guard: x1 >= 20 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
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

Out_Going_Trans_fromloc_244.push_back(t);
l = location::ptr(new location(120, "loc_244", system_dynamics, invariant, true, Out_Going_Trans_fromloc_244));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_245

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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_245;


l = location::ptr(new location(121, "loc_245", system_dynamics, invariant, true, Out_Going_Trans_fromloc_245));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_247

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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_247;

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

t = transition::ptr(new transition(121,"null",122,106,guard_polytope,assignment));

Out_Going_Trans_fromloc_247.push_back(t);
l = location::ptr(new location(122, "loc_247", system_dynamics, invariant, true, Out_Going_Trans_fromloc_247));
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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_249;

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

t = transition::ptr(new transition(122,"null",123,107,guard_polytope,assignment));

Out_Going_Trans_fromloc_249.push_back(t);
l = location::ptr(new location(123, "loc_249", system_dynamics, invariant, true, Out_Going_Trans_fromloc_249));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_250

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_250;

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

t = transition::ptr(new transition(123,"null",124,133,guard_polytope,assignment));

Out_Going_Trans_fromloc_250.push_back(t);
l = location::ptr(new location(124, "loc_250", system_dynamics, invariant, true, Out_Going_Trans_fromloc_250));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_252

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_252;

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

t = transition::ptr(new transition(124,"null",125,134,guard_polytope,assignment));

Out_Going_Trans_fromloc_252.push_back(t);
l = location::ptr(new location(125, "loc_252", system_dynamics, invariant, true, Out_Going_Trans_fromloc_252));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_254

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
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_254;


l = location::ptr(new location(126, "loc_254", system_dynamics, invariant, true, Out_Going_Trans_fromloc_254));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_257

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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_257;

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

t = transition::ptr(new transition(125,"null",127,110,guard_polytope,assignment));

Out_Going_Trans_fromloc_257.push_back(t);
l = location::ptr(new location(127, "loc_257", system_dynamics, invariant, true, Out_Going_Trans_fromloc_257));
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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_261;

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

t = transition::ptr(new transition(126,"null",128,138,guard_polytope,assignment));

Out_Going_Trans_fromloc_261.push_back(t);
l = location::ptr(new location(128, "loc_261", system_dynamics, invariant, true, Out_Going_Trans_fromloc_261));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_263

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
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_263;


l = location::ptr(new location(129, "loc_263", system_dynamics, invariant, true, Out_Going_Trans_fromloc_263));
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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_268;

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

t = transition::ptr(new transition(127,"null",130,119,guard_polytope,assignment));

Out_Going_Trans_fromloc_268.push_back(t);
l = location::ptr(new location(130, "loc_268", system_dynamics, invariant, true, Out_Going_Trans_fromloc_268));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_272

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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_272;

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

t = transition::ptr(new transition(128,"null",131,122,guard_polytope,assignment));

Out_Going_Trans_fromloc_272.push_back(t);
l = location::ptr(new location(131, "loc_272", system_dynamics, invariant, true, Out_Going_Trans_fromloc_272));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_274

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_274;

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

t = transition::ptr(new transition(129,"null",132,123,guard_polytope,assignment));

Out_Going_Trans_fromloc_274.push_back(t);
l = location::ptr(new location(132, "loc_274", system_dynamics, invariant, true, Out_Going_Trans_fromloc_274));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_275

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_275;

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

t = transition::ptr(new transition(130,"null",133,141,guard_polytope,assignment));

Out_Going_Trans_fromloc_275.push_back(t);
l = location::ptr(new location(133, "loc_275", system_dynamics, invariant, true, Out_Going_Trans_fromloc_275));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_277

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_277;

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

t = transition::ptr(new transition(131,"null",134,142,guard_polytope,assignment));

Out_Going_Trans_fromloc_277.push_back(t);
l = location::ptr(new location(134, "loc_277", system_dynamics, invariant, true, Out_Going_Trans_fromloc_277));
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
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_279;

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

t = transition::ptr(new transition(132,"null",135,126,guard_polytope,assignment));

Out_Going_Trans_fromloc_279.push_back(t);
l = location::ptr(new location(135, "loc_279", system_dynamics, invariant, true, Out_Going_Trans_fromloc_279));
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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_282;

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

t = transition::ptr(new transition(133,"null",136,127,guard_polytope,assignment));

Out_Going_Trans_fromloc_282.push_back(t);
l = location::ptr(new location(136, "loc_282", system_dynamics, invariant, true, Out_Going_Trans_fromloc_282));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_293

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
invariantBoundValue[0] = -18.0;
invariantBoundValue[1] = 19.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_293;

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

t = transition::ptr(new transition(134,"null",137,130,guard_polytope,assignment));

Out_Going_Trans_fromloc_293.push_back(t);
l = location::ptr(new location(137, "loc_293", system_dynamics, invariant, true, Out_Going_Trans_fromloc_293));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_296

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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_296;

// The transition label is null

// Original guard: x1 >= 22 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -22.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(135,"null",138,139,guard_polytope,assignment));

Out_Going_Trans_fromloc_296.push_back(t);
l = location::ptr(new location(138, "loc_296", system_dynamics, invariant, true, Out_Going_Trans_fromloc_296));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_297

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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_297;

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

t = transition::ptr(new transition(136,"null",139,131,guard_polytope,assignment));

Out_Going_Trans_fromloc_297.push_back(t);
l = location::ptr(new location(139, "loc_297", system_dynamics, invariant, true, Out_Going_Trans_fromloc_297));
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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_299;

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

t = transition::ptr(new transition(137,"null",140,132,guard_polytope,assignment));

Out_Going_Trans_fromloc_299.push_back(t);
l = location::ptr(new location(140, "loc_299", system_dynamics, invariant, true, Out_Going_Trans_fromloc_299));
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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_300;

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

t = transition::ptr(new transition(138,"null",141,157,guard_polytope,assignment));

Out_Going_Trans_fromloc_300.push_back(t);
l = location::ptr(new location(141, "loc_300", system_dynamics, invariant, true, Out_Going_Trans_fromloc_300));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_302

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_302;

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

t = transition::ptr(new transition(139,"null",142,158,guard_polytope,assignment));

Out_Going_Trans_fromloc_302.push_back(t);
l = location::ptr(new location(142, "loc_302", system_dynamics, invariant, true, Out_Going_Trans_fromloc_302));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_304

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_304;

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

t = transition::ptr(new transition(140,"null",143,159,guard_polytope,assignment));

Out_Going_Trans_fromloc_304.push_back(t);
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

t = transition::ptr(new transition(141,"null",143,135,guard_polytope,assignment));

Out_Going_Trans_fromloc_304.push_back(t);
l = location::ptr(new location(143, "loc_304", system_dynamics, invariant, true, Out_Going_Trans_fromloc_304));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_305

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_305;

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

t = transition::ptr(new transition(142,"null",144,143,guard_polytope,assignment));

Out_Going_Trans_fromloc_305.push_back(t);
l = location::ptr(new location(144, "loc_305", system_dynamics, invariant, true, Out_Going_Trans_fromloc_305));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_306

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_306;

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

t = transition::ptr(new transition(143,"null",145,144,guard_polytope,assignment));

Out_Going_Trans_fromloc_306.push_back(t);
l = location::ptr(new location(145, "loc_306", system_dynamics, invariant, true, Out_Going_Trans_fromloc_306));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_307

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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_307;

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

t = transition::ptr(new transition(144,"null",146,136,guard_polytope,assignment));

Out_Going_Trans_fromloc_307.push_back(t);
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

t = transition::ptr(new transition(145,"null",146,145,guard_polytope,assignment));

Out_Going_Trans_fromloc_307.push_back(t);
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

t = transition::ptr(new transition(146,"null",146,147,guard_polytope,assignment));

Out_Going_Trans_fromloc_307.push_back(t);
l = location::ptr(new location(146, "loc_307", system_dynamics, invariant, true, Out_Going_Trans_fromloc_307));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_308

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_308;

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

t = transition::ptr(new transition(147,"null",147,148,guard_polytope,assignment));

Out_Going_Trans_fromloc_308.push_back(t);
l = location::ptr(new location(147, "loc_308", system_dynamics, invariant, true, Out_Going_Trans_fromloc_308));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_309

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
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_309;

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

t = transition::ptr(new transition(148,"null",148,161,guard_polytope,assignment));

Out_Going_Trans_fromloc_309.push_back(t);
l = location::ptr(new location(148, "loc_309", system_dynamics, invariant, true, Out_Going_Trans_fromloc_309));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_312

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_312;


l = location::ptr(new location(149, "loc_312", system_dynamics, invariant, true, Out_Going_Trans_fromloc_312));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_313

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_313;

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

t = transition::ptr(new transition(149,"null",150,149,guard_polytope,assignment));

Out_Going_Trans_fromloc_313.push_back(t);
l = location::ptr(new location(150, "loc_313", system_dynamics, invariant, true, Out_Going_Trans_fromloc_313));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_314

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_314;

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

t = transition::ptr(new transition(150,"null",151,150,guard_polytope,assignment));

Out_Going_Trans_fromloc_314.push_back(t);
l = location::ptr(new location(151, "loc_314", system_dynamics, invariant, true, Out_Going_Trans_fromloc_314));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_315

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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_315;

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

t = transition::ptr(new transition(151,"null",152,151,guard_polytope,assignment));

Out_Going_Trans_fromloc_315.push_back(t);
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

t = transition::ptr(new transition(152,"null",152,153,guard_polytope,assignment));

Out_Going_Trans_fromloc_315.push_back(t);
l = location::ptr(new location(152, "loc_315", system_dynamics, invariant, true, Out_Going_Trans_fromloc_315));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_316

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_316;

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

t = transition::ptr(new transition(153,"null",153,154,guard_polytope,assignment));

Out_Going_Trans_fromloc_316.push_back(t);
l = location::ptr(new location(153, "loc_316", system_dynamics, invariant, true, Out_Going_Trans_fromloc_316));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_317

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_317;

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

t = transition::ptr(new transition(154,"null",154,155,guard_polytope,assignment));

Out_Going_Trans_fromloc_317.push_back(t);
l = location::ptr(new location(154, "loc_317", system_dynamics, invariant, true, Out_Going_Trans_fromloc_317));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_318

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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_318;

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

t = transition::ptr(new transition(155,"null",155,137,guard_polytope,assignment));

Out_Going_Trans_fromloc_318.push_back(t);
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

t = transition::ptr(new transition(156,"null",155,163,guard_polytope,assignment));

Out_Going_Trans_fromloc_318.push_back(t);
l = location::ptr(new location(155, "loc_318", system_dynamics, invariant, true, Out_Going_Trans_fromloc_318));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_324

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_324;

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

t = transition::ptr(new transition(157,"null",156,140,guard_polytope,assignment));

Out_Going_Trans_fromloc_324.push_back(t);
l = location::ptr(new location(156, "loc_324", system_dynamics, invariant, true, Out_Going_Trans_fromloc_324));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_325

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_325;

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

t = transition::ptr(new transition(158,"null",157,165,guard_polytope,assignment));

Out_Going_Trans_fromloc_325.push_back(t);
l = location::ptr(new location(157, "loc_325", system_dynamics, invariant, true, Out_Going_Trans_fromloc_325));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_327

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_327;

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

t = transition::ptr(new transition(159,"null",158,166,guard_polytope,assignment));

Out_Going_Trans_fromloc_327.push_back(t);
l = location::ptr(new location(158, "loc_327", system_dynamics, invariant, true, Out_Going_Trans_fromloc_327));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_329

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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_329;

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

t = transition::ptr(new transition(160,"null",159,167,guard_polytope,assignment));

Out_Going_Trans_fromloc_329.push_back(t);
l = location::ptr(new location(159, "loc_329", system_dynamics, invariant, true, Out_Going_Trans_fromloc_329));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_332

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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_332;

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

t = transition::ptr(new transition(161,"null",160,146,guard_polytope,assignment));

Out_Going_Trans_fromloc_332.push_back(t);
l = location::ptr(new location(160, "loc_332", system_dynamics, invariant, true, Out_Going_Trans_fromloc_332));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_334

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


std::list<transition::ptr> Out_Going_Trans_fromloc_334;

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

t = transition::ptr(new transition(162,"null",161,169,guard_polytope,assignment));

Out_Going_Trans_fromloc_334.push_back(t);
l = location::ptr(new location(161, "loc_334", system_dynamics, invariant, true, Out_Going_Trans_fromloc_334));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_340

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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_340;

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

t = transition::ptr(new transition(163,"null",162,152,guard_polytope,assignment));

Out_Going_Trans_fromloc_340.push_back(t);
l = location::ptr(new location(162, "loc_340", system_dynamics, invariant, true, Out_Going_Trans_fromloc_340));
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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_343;

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

t = transition::ptr(new transition(164,"null",163,174,guard_polytope,assignment));

Out_Going_Trans_fromloc_343.push_back(t);
l = location::ptr(new location(163, "loc_343", system_dynamics, invariant, true, Out_Going_Trans_fromloc_343));
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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_349;

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

t = transition::ptr(new transition(165,"null",164,156,guard_polytope,assignment));

Out_Going_Trans_fromloc_349.push_back(t);
l = location::ptr(new location(164, "loc_349", system_dynamics, invariant, true, Out_Going_Trans_fromloc_349));
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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_350;

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

t = transition::ptr(new transition(166,"null",165,176,guard_polytope,assignment));

Out_Going_Trans_fromloc_350.push_back(t);
l = location::ptr(new location(165, "loc_350", system_dynamics, invariant, true, Out_Going_Trans_fromloc_350));
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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_352;

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

t = transition::ptr(new transition(167,"null",166,177,guard_polytope,assignment));

Out_Going_Trans_fromloc_352.push_back(t);
l = location::ptr(new location(166, "loc_352", system_dynamics, invariant, true, Out_Going_Trans_fromloc_352));
Hybrid_Automata.addLocation(l);

}

void navT04_Timed_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_354

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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_354;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(168,"null",167,178,guard_polytope,assignment));

Out_Going_Trans_fromloc_354.push_back(t);
l = location::ptr(new location(167, "loc_354", system_dynamics, invariant, true, Out_Going_Trans_fromloc_354));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_357

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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_357;

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

t = transition::ptr(new transition(169,"null",168,160,guard_polytope,assignment));

Out_Going_Trans_fromloc_357.push_back(t);
l = location::ptr(new location(168, "loc_357", system_dynamics, invariant, true, Out_Going_Trans_fromloc_357));
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
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_359;

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

t = transition::ptr(new transition(170,"null",169,180,guard_polytope,assignment));

Out_Going_Trans_fromloc_359.push_back(t);
l = location::ptr(new location(169, "loc_359", system_dynamics, invariant, true, Out_Going_Trans_fromloc_359));
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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_361;


l = location::ptr(new location(170, "loc_361", system_dynamics, invariant, true, Out_Going_Trans_fromloc_361));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_362

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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_362;

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

t = transition::ptr(new transition(171,"null",171,170,guard_polytope,assignment));

Out_Going_Trans_fromloc_362.push_back(t);
l = location::ptr(new location(171, "loc_362", system_dynamics, invariant, true, Out_Going_Trans_fromloc_362));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_363

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
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_363;

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

t = transition::ptr(new transition(172,"null",172,171,guard_polytope,assignment));

Out_Going_Trans_fromloc_363.push_back(t);
l = location::ptr(new location(172, "loc_363", system_dynamics, invariant, true, Out_Going_Trans_fromloc_363));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_365

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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_365;

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

t = transition::ptr(new transition(173,"null",173,162,guard_polytope,assignment));

Out_Going_Trans_fromloc_365.push_back(t);
l = location::ptr(new location(173, "loc_365", system_dynamics, invariant, true, Out_Going_Trans_fromloc_365));
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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_368;

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

t = transition::ptr(new transition(174,"null",174,183,guard_polytope,assignment));

Out_Going_Trans_fromloc_368.push_back(t);
l = location::ptr(new location(174, "loc_368", system_dynamics, invariant, true, Out_Going_Trans_fromloc_368));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_374

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_374;

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

t = transition::ptr(new transition(175,"null",175,164,guard_polytope,assignment));

Out_Going_Trans_fromloc_374.push_back(t);
l = location::ptr(new location(175, "loc_374", system_dynamics, invariant, true, Out_Going_Trans_fromloc_374));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_375

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_375;

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

t = transition::ptr(new transition(176,"null",176,185,guard_polytope,assignment));

Out_Going_Trans_fromloc_375.push_back(t);
l = location::ptr(new location(176, "loc_375", system_dynamics, invariant, true, Out_Going_Trans_fromloc_375));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_377

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_377;

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

t = transition::ptr(new transition(177,"null",177,186,guard_polytope,assignment));

Out_Going_Trans_fromloc_377.push_back(t);
l = location::ptr(new location(177, "loc_377", system_dynamics, invariant, true, Out_Going_Trans_fromloc_377));
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
invariantBoundValue[0] = -4.0;
invariantBoundValue[1] = 5.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_379;


l = location::ptr(new location(178, "loc_379", system_dynamics, invariant, true, Out_Going_Trans_fromloc_379));
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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_382;

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

t = transition::ptr(new transition(178,"null",179,168,guard_polytope,assignment));

Out_Going_Trans_fromloc_382.push_back(t);
l = location::ptr(new location(179, "loc_382", system_dynamics, invariant, true, Out_Going_Trans_fromloc_382));
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
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_384;

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

t = transition::ptr(new transition(179,"null",180,188,guard_polytope,assignment));

Out_Going_Trans_fromloc_384.push_back(t);
l = location::ptr(new location(180, "loc_384", system_dynamics, invariant, true, Out_Going_Trans_fromloc_384));
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
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_388;

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

t = transition::ptr(new transition(180,"null",181,172,guard_polytope,assignment));

Out_Going_Trans_fromloc_388.push_back(t);
l = location::ptr(new location(181, "loc_388", system_dynamics, invariant, true, Out_Going_Trans_fromloc_388));
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_390;

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

t = transition::ptr(new transition(181,"null",182,173,guard_polytope,assignment));

Out_Going_Trans_fromloc_390.push_back(t);
l = location::ptr(new location(182, "loc_390", system_dynamics, invariant, true, Out_Going_Trans_fromloc_390));
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
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_393;

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

t = transition::ptr(new transition(182,"null",183,194,guard_polytope,assignment));

Out_Going_Trans_fromloc_393.push_back(t);
l = location::ptr(new location(183, "loc_393", system_dynamics, invariant, true, Out_Going_Trans_fromloc_393));
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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_399;

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

t = transition::ptr(new transition(183,"null",184,175,guard_polytope,assignment));

Out_Going_Trans_fromloc_399.push_back(t);
l = location::ptr(new location(184, "loc_399", system_dynamics, invariant, true, Out_Going_Trans_fromloc_399));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_400

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_400;

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

t = transition::ptr(new transition(184,"null",185,196,guard_polytope,assignment));

Out_Going_Trans_fromloc_400.push_back(t);
l = location::ptr(new location(185, "loc_400", system_dynamics, invariant, true, Out_Going_Trans_fromloc_400));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_402

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_402;

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

t = transition::ptr(new transition(185,"null",186,197,guard_polytope,assignment));

Out_Going_Trans_fromloc_402.push_back(t);
l = location::ptr(new location(186, "loc_402", system_dynamics, invariant, true, Out_Going_Trans_fromloc_402));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_407

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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_407;

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

t = transition::ptr(new transition(186,"null",187,179,guard_polytope,assignment));

Out_Going_Trans_fromloc_407.push_back(t);
l = location::ptr(new location(187, "loc_407", system_dynamics, invariant, true, Out_Going_Trans_fromloc_407));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_409

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
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_409;

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

t = transition::ptr(new transition(187,"null",188,189,guard_polytope,assignment));

Out_Going_Trans_fromloc_409.push_back(t);
l = location::ptr(new location(188, "loc_409", system_dynamics, invariant, true, Out_Going_Trans_fromloc_409));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_410

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
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_410;

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

t = transition::ptr(new transition(188,"null",189,190,guard_polytope,assignment));

Out_Going_Trans_fromloc_410.push_back(t);
l = location::ptr(new location(189, "loc_410", system_dynamics, invariant, true, Out_Going_Trans_fromloc_410));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_411

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
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_411;

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

t = transition::ptr(new transition(189,"null",190,191,guard_polytope,assignment));

Out_Going_Trans_fromloc_411.push_back(t);
l = location::ptr(new location(190, "loc_411", system_dynamics, invariant, true, Out_Going_Trans_fromloc_411));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_412

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
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_412;

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

t = transition::ptr(new transition(190,"null",191,192,guard_polytope,assignment));

Out_Going_Trans_fromloc_412.push_back(t);
l = location::ptr(new location(191, "loc_412", system_dynamics, invariant, true, Out_Going_Trans_fromloc_412));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_413

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
invariantBoundValue[0] = -13.0;
invariantBoundValue[1] = 14.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_413;

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

t = transition::ptr(new transition(191,"null",192,181,guard_polytope,assignment));

Out_Going_Trans_fromloc_413.push_back(t);
l = location::ptr(new location(192, "loc_413", system_dynamics, invariant, true, Out_Going_Trans_fromloc_413));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_415

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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_415;

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

t = transition::ptr(new transition(192,"null",193,182,guard_polytope,assignment));

Out_Going_Trans_fromloc_415.push_back(t);
l = location::ptr(new location(193, "loc_415", system_dynamics, invariant, true, Out_Going_Trans_fromloc_415));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_418

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
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_418;


l = location::ptr(new location(194, "loc_418", system_dynamics, invariant, true, Out_Going_Trans_fromloc_418));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_424

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_424;

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

t = transition::ptr(new transition(193,"null",195,184,guard_polytope,assignment));

Out_Going_Trans_fromloc_424.push_back(t);
l = location::ptr(new location(195, "loc_424", system_dynamics, invariant, true, Out_Going_Trans_fromloc_424));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_425

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_425;

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

t = transition::ptr(new transition(194,"null",196,203,guard_polytope,assignment));

Out_Going_Trans_fromloc_425.push_back(t);
l = location::ptr(new location(196, "loc_425", system_dynamics, invariant, true, Out_Going_Trans_fromloc_425));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_427

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_427;

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

t = transition::ptr(new transition(195,"null",197,204,guard_polytope,assignment));

Out_Going_Trans_fromloc_427.push_back(t);
l = location::ptr(new location(197, "loc_427", system_dynamics, invariant, true, Out_Going_Trans_fromloc_427));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_430

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
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_430;

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

t = transition::ptr(new transition(196,"null",198,199,guard_polytope,assignment));

Out_Going_Trans_fromloc_430.push_back(t);
l = location::ptr(new location(198, "loc_430", system_dynamics, invariant, true, Out_Going_Trans_fromloc_430));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_431

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


std::list<transition::ptr> Out_Going_Trans_fromloc_431;

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

t = transition::ptr(new transition(197,"null",199,200,guard_polytope,assignment));

Out_Going_Trans_fromloc_431.push_back(t);
l = location::ptr(new location(199, "loc_431", system_dynamics, invariant, true, Out_Going_Trans_fromloc_431));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_432

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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_432;

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

t = transition::ptr(new transition(198,"null",200,187,guard_polytope,assignment));

Out_Going_Trans_fromloc_432.push_back(t);
l = location::ptr(new location(200, "loc_432", system_dynamics, invariant, true, Out_Going_Trans_fromloc_432));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_440

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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_440;

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

t = transition::ptr(new transition(199,"null",201,193,guard_polytope,assignment));

Out_Going_Trans_fromloc_440.push_back(t);
l = location::ptr(new location(201, "loc_440", system_dynamics, invariant, true, Out_Going_Trans_fromloc_440));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_449

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_449;

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

t = transition::ptr(new transition(200,"null",202,195,guard_polytope,assignment));

Out_Going_Trans_fromloc_449.push_back(t);
l = location::ptr(new location(202, "loc_449", system_dynamics, invariant, true, Out_Going_Trans_fromloc_449));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_450

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_450;

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

t = transition::ptr(new transition(201,"null",203,217,guard_polytope,assignment));

Out_Going_Trans_fromloc_450.push_back(t);
l = location::ptr(new location(203, "loc_450", system_dynamics, invariant, true, Out_Going_Trans_fromloc_450));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_452

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_452;

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

t = transition::ptr(new transition(202,"null",204,218,guard_polytope,assignment));

Out_Going_Trans_fromloc_452.push_back(t);
l = location::ptr(new location(204, "loc_452", system_dynamics, invariant, true, Out_Going_Trans_fromloc_452));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_455

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
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_455;

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

t = transition::ptr(new transition(203,"null",205,198,guard_polytope,assignment));

Out_Going_Trans_fromloc_455.push_back(t);
l = location::ptr(new location(205, "loc_455", system_dynamics, invariant, true, Out_Going_Trans_fromloc_455));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_459

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_459;

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

t = transition::ptr(new transition(204,"null",206,207,guard_polytope,assignment));

Out_Going_Trans_fromloc_459.push_back(t);
l = location::ptr(new location(206, "loc_459", system_dynamics, invariant, true, Out_Going_Trans_fromloc_459));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_460

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_460;

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

t = transition::ptr(new transition(205,"null",207,208,guard_polytope,assignment));

Out_Going_Trans_fromloc_460.push_back(t);
l = location::ptr(new location(207, "loc_460", system_dynamics, invariant, true, Out_Going_Trans_fromloc_460));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_461

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_461;

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

t = transition::ptr(new transition(206,"null",208,209,guard_polytope,assignment));

Out_Going_Trans_fromloc_461.push_back(t);
l = location::ptr(new location(208, "loc_461", system_dynamics, invariant, true, Out_Going_Trans_fromloc_461));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_462

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_462;

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

t = transition::ptr(new transition(207,"null",209,210,guard_polytope,assignment));

Out_Going_Trans_fromloc_462.push_back(t);
l = location::ptr(new location(209, "loc_462", system_dynamics, invariant, true, Out_Going_Trans_fromloc_462));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_463

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_463;

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

t = transition::ptr(new transition(208,"null",210,211,guard_polytope,assignment));

Out_Going_Trans_fromloc_463.push_back(t);
l = location::ptr(new location(210, "loc_463", system_dynamics, invariant, true, Out_Going_Trans_fromloc_463));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_464

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_464;

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

t = transition::ptr(new transition(209,"null",211,212,guard_polytope,assignment));

Out_Going_Trans_fromloc_464.push_back(t);
l = location::ptr(new location(211, "loc_464", system_dynamics, invariant, true, Out_Going_Trans_fromloc_464));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_465

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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_465;

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

t = transition::ptr(new transition(210,"null",212,201,guard_polytope,assignment));

Out_Going_Trans_fromloc_465.push_back(t);
l = location::ptr(new location(212, "loc_465", system_dynamics, invariant, true, Out_Going_Trans_fromloc_465));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_467

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_467;

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

t = transition::ptr(new transition(211,"null",213,214,guard_polytope,assignment));

Out_Going_Trans_fromloc_467.push_back(t);
l = location::ptr(new location(213, "loc_467", system_dynamics, invariant, true, Out_Going_Trans_fromloc_467));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_468

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_468;

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

t = transition::ptr(new transition(212,"null",214,215,guard_polytope,assignment));

Out_Going_Trans_fromloc_468.push_back(t);
l = location::ptr(new location(214, "loc_468", system_dynamics, invariant, true, Out_Going_Trans_fromloc_468));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_469

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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_469;


l = location::ptr(new location(215, "loc_469", system_dynamics, invariant, true, Out_Going_Trans_fromloc_469));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_474

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_474;

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

t = transition::ptr(new transition(213,"null",216,202,guard_polytope,assignment));

Out_Going_Trans_fromloc_474.push_back(t);
l = location::ptr(new location(216, "loc_474", system_dynamics, invariant, true, Out_Going_Trans_fromloc_474));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_475

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_475;

// The transition label is null

// Original guard: x2 >= 20 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(214,"null",217,223,guard_polytope,assignment));

Out_Going_Trans_fromloc_475.push_back(t);
l = location::ptr(new location(217, "loc_475", system_dynamics, invariant, true, Out_Going_Trans_fromloc_475));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_477

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_477;

// The transition label is null

// Original guard: x2 >= 20 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(215,"null",218,224,guard_polytope,assignment));

Out_Going_Trans_fromloc_477.push_back(t);
l = location::ptr(new location(218, "loc_477", system_dynamics, invariant, true, Out_Going_Trans_fromloc_477));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_480

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
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_480;

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

t = transition::ptr(new transition(216,"null",219,205,guard_polytope,assignment));

Out_Going_Trans_fromloc_480.push_back(t);
l = location::ptr(new location(219, "loc_480", system_dynamics, invariant, true, Out_Going_Trans_fromloc_480));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_484

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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_484;

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

t = transition::ptr(new transition(217,"null",220,206,guard_polytope,assignment));

Out_Going_Trans_fromloc_484.push_back(t);
l = location::ptr(new location(220, "loc_484", system_dynamics, invariant, true, Out_Going_Trans_fromloc_484));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_492

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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_492;

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

t = transition::ptr(new transition(218,"null",221,213,guard_polytope,assignment));

Out_Going_Trans_fromloc_492.push_back(t);
l = location::ptr(new location(221, "loc_492", system_dynamics, invariant, true, Out_Going_Trans_fromloc_492));
Hybrid_Automata.addLocation(l);

}

void navT04_Timed_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc_499

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_499;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(219,"null",222,216,guard_polytope,assignment));

Out_Going_Trans_fromloc_499.push_back(t);
l = location::ptr(new location(222, "loc_499", system_dynamics, invariant, true, Out_Going_Trans_fromloc_499));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_500

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_500;

// The transition label is null

// Original guard: x2 >= 21 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(220,"null",223,229,guard_polytope,assignment));

Out_Going_Trans_fromloc_500.push_back(t);
l = location::ptr(new location(223, "loc_500", system_dynamics, invariant, true, Out_Going_Trans_fromloc_500));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_502

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_502;

// The transition label is null

// Original guard: x2 >= 21 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(221,"null",224,230,guard_polytope,assignment));

Out_Going_Trans_fromloc_502.push_back(t);
l = location::ptr(new location(224, "loc_502", system_dynamics, invariant, true, Out_Going_Trans_fromloc_502));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_505

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
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_505;

// The transition label is null

// Original guard: x2 <= 20 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(222,"null",225,219,guard_polytope,assignment));

Out_Going_Trans_fromloc_505.push_back(t);
l = location::ptr(new location(225, "loc_505", system_dynamics, invariant, true, Out_Going_Trans_fromloc_505));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_509

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
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_509;

// The transition label is null

// Original guard: x2 <= 20 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(223,"null",226,220,guard_polytope,assignment));

Out_Going_Trans_fromloc_509.push_back(t);
l = location::ptr(new location(226, "loc_509", system_dynamics, invariant, true, Out_Going_Trans_fromloc_509));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_517

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
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_517;

// The transition label is null

// Original guard: x2 <= 20 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(224,"null",227,221,guard_polytope,assignment));

Out_Going_Trans_fromloc_517.push_back(t);
l = location::ptr(new location(227, "loc_517", system_dynamics, invariant, true, Out_Going_Trans_fromloc_517));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_524

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_524;

// The transition label is null

// Original guard: x2 <= 20 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(225,"null",228,222,guard_polytope,assignment));

Out_Going_Trans_fromloc_524.push_back(t);
l = location::ptr(new location(228, "loc_524", system_dynamics, invariant, true, Out_Going_Trans_fromloc_524));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_525

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_525;

// The transition label is null

// Original guard: x2 >= 22 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -22.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(226,"null",229,246,guard_polytope,assignment));

Out_Going_Trans_fromloc_525.push_back(t);
l = location::ptr(new location(229, "loc_525", system_dynamics, invariant, true, Out_Going_Trans_fromloc_525));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_527

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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_527;

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

t = transition::ptr(new transition(227,"null",230,231,guard_polytope,assignment));

Out_Going_Trans_fromloc_527.push_back(t);
l = location::ptr(new location(230, "loc_527", system_dynamics, invariant, true, Out_Going_Trans_fromloc_527));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_528

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_528;

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

t = transition::ptr(new transition(228,"null",231,232,guard_polytope,assignment));

Out_Going_Trans_fromloc_528.push_back(t);
l = location::ptr(new location(231, "loc_528", system_dynamics, invariant, true, Out_Going_Trans_fromloc_528));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_529

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_529;

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

t = transition::ptr(new transition(229,"null",232,233,guard_polytope,assignment));

Out_Going_Trans_fromloc_529.push_back(t);
l = location::ptr(new location(232, "loc_529", system_dynamics, invariant, true, Out_Going_Trans_fromloc_529));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_530

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
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_530;

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

t = transition::ptr(new transition(230,"null",233,234,guard_polytope,assignment));

Out_Going_Trans_fromloc_530.push_back(t);
// The transition label is null

// Original guard: x2 <= 21 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(231,"null",233,225,guard_polytope,assignment));

Out_Going_Trans_fromloc_530.push_back(t);
l = location::ptr(new location(233, "loc_530", system_dynamics, invariant, true, Out_Going_Trans_fromloc_530));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_531

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_531;

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

t = transition::ptr(new transition(232,"null",234,235,guard_polytope,assignment));

Out_Going_Trans_fromloc_531.push_back(t);
l = location::ptr(new location(234, "loc_531", system_dynamics, invariant, true, Out_Going_Trans_fromloc_531));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_532

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_532;

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

t = transition::ptr(new transition(233,"null",235,236,guard_polytope,assignment));

Out_Going_Trans_fromloc_532.push_back(t);
l = location::ptr(new location(235, "loc_532", system_dynamics, invariant, true, Out_Going_Trans_fromloc_532));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_533

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_533;

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

t = transition::ptr(new transition(234,"null",236,237,guard_polytope,assignment));

Out_Going_Trans_fromloc_533.push_back(t);
l = location::ptr(new location(236, "loc_533", system_dynamics, invariant, true, Out_Going_Trans_fromloc_533));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_534

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_534;

// The transition label is null

// Original guard: x2 <= 21 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(235,"null",237,226,guard_polytope,assignment));

Out_Going_Trans_fromloc_534.push_back(t);
l = location::ptr(new location(237, "loc_534", system_dynamics, invariant, true, Out_Going_Trans_fromloc_534));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_536

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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_536;

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

t = transition::ptr(new transition(236,"null",238,239,guard_polytope,assignment));

Out_Going_Trans_fromloc_536.push_back(t);
l = location::ptr(new location(238, "loc_536", system_dynamics, invariant, true, Out_Going_Trans_fromloc_536));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_537

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_537;

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

t = transition::ptr(new transition(237,"null",239,240,guard_polytope,assignment));

Out_Going_Trans_fromloc_537.push_back(t);
l = location::ptr(new location(239, "loc_537", system_dynamics, invariant, true, Out_Going_Trans_fromloc_537));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_538

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_538;

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

t = transition::ptr(new transition(238,"null",240,241,guard_polytope,assignment));

Out_Going_Trans_fromloc_538.push_back(t);
l = location::ptr(new location(240, "loc_538", system_dynamics, invariant, true, Out_Going_Trans_fromloc_538));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_539

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_539;

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

t = transition::ptr(new transition(239,"null",241,242,guard_polytope,assignment));

Out_Going_Trans_fromloc_539.push_back(t);
l = location::ptr(new location(241, "loc_539", system_dynamics, invariant, true, Out_Going_Trans_fromloc_539));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_540

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_540;

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

t = transition::ptr(new transition(240,"null",242,243,guard_polytope,assignment));

Out_Going_Trans_fromloc_540.push_back(t);
l = location::ptr(new location(242, "loc_540", system_dynamics, invariant, true, Out_Going_Trans_fromloc_540));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_541

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_541;

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

t = transition::ptr(new transition(241,"null",243,244,guard_polytope,assignment));

Out_Going_Trans_fromloc_541.push_back(t);
l = location::ptr(new location(243, "loc_541", system_dynamics, invariant, true, Out_Going_Trans_fromloc_541));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_542

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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_542;

// The transition label is null

// Original guard: x2 <= 21 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(242,"null",244,227,guard_polytope,assignment));

Out_Going_Trans_fromloc_542.push_back(t);
l = location::ptr(new location(244, "loc_542", system_dynamics, invariant, true, Out_Going_Trans_fromloc_542));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_549

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_549;

// The transition label is null

// Original guard: x2 <= 21 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(243,"null",245,228,guard_polytope,assignment));

Out_Going_Trans_fromloc_549.push_back(t);
l = location::ptr(new location(245, "loc_549", system_dynamics, invariant, true, Out_Going_Trans_fromloc_549));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_550

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -22.0;
invariantBoundValue[3] = 23.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_550;

// The transition label is null

// Original guard: x2 >= 23 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -23.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(244,"null",246,249,guard_polytope,assignment));

Out_Going_Trans_fromloc_550.push_back(t);
l = location::ptr(new location(246, "loc_550", system_dynamics, invariant, true, Out_Going_Trans_fromloc_550));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_561

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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -22.0;
invariantBoundValue[3] = 23.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_561;

// The transition label is null

// Original guard: x2 <= 22 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 22.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(245,"null",247,238,guard_polytope,assignment));

Out_Going_Trans_fromloc_561.push_back(t);
l = location::ptr(new location(247, "loc_561", system_dynamics, invariant, true, Out_Going_Trans_fromloc_561));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_574

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -22.0;
invariantBoundValue[3] = 23.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_574;

// The transition label is null

// Original guard: x2 <= 22 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 22.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(246,"null",248,245,guard_polytope,assignment));

Out_Going_Trans_fromloc_574.push_back(t);
l = location::ptr(new location(248, "loc_574", system_dynamics, invariant, true, Out_Going_Trans_fromloc_574));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_575

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_575;

// The transition label is null

// Original guard: x2 >= 24 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -24.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(247,"null",249,252,guard_polytope,assignment));

Out_Going_Trans_fromloc_575.push_back(t);
l = location::ptr(new location(249, "loc_575", system_dynamics, invariant, true, Out_Going_Trans_fromloc_575));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_586

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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_586;

// The transition label is null

// Original guard: x2 <= 23 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 23.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(248,"null",250,247,guard_polytope,assignment));

Out_Going_Trans_fromloc_586.push_back(t);
l = location::ptr(new location(250, "loc_586", system_dynamics, invariant, true, Out_Going_Trans_fromloc_586));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_599

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_599;

// The transition label is null

// Original guard: x2 <= 23 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 23.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(249,"null",251,248,guard_polytope,assignment));

Out_Going_Trans_fromloc_599.push_back(t);
l = location::ptr(new location(251, "loc_599", system_dynamics, invariant, true, Out_Going_Trans_fromloc_599));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_600

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
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_600;

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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(250,"null",252,253,guard_polytope,assignment));

Out_Going_Trans_fromloc_600.push_back(t);
l = location::ptr(new location(252, "loc_600", system_dynamics, invariant, true, Out_Going_Trans_fromloc_600));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_601

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_601;

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

t = transition::ptr(new transition(251,"null",253,254,guard_polytope,assignment));

Out_Going_Trans_fromloc_601.push_back(t);
l = location::ptr(new location(253, "loc_601", system_dynamics, invariant, true, Out_Going_Trans_fromloc_601));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_602

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_602;

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

t = transition::ptr(new transition(252,"null",254,255,guard_polytope,assignment));

Out_Going_Trans_fromloc_602.push_back(t);
l = location::ptr(new location(254, "loc_602", system_dynamics, invariant, true, Out_Going_Trans_fromloc_602));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_603

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_603;

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

t = transition::ptr(new transition(253,"null",255,256,guard_polytope,assignment));

Out_Going_Trans_fromloc_603.push_back(t);
l = location::ptr(new location(255, "loc_603", system_dynamics, invariant, true, Out_Going_Trans_fromloc_603));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_604

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_604;

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

t = transition::ptr(new transition(254,"null",256,257,guard_polytope,assignment));

Out_Going_Trans_fromloc_604.push_back(t);
l = location::ptr(new location(256, "loc_604", system_dynamics, invariant, true, Out_Going_Trans_fromloc_604));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_605

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_605;

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

t = transition::ptr(new transition(255,"null",257,258,guard_polytope,assignment));

Out_Going_Trans_fromloc_605.push_back(t);
l = location::ptr(new location(257, "loc_605", system_dynamics, invariant, true, Out_Going_Trans_fromloc_605));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_606

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_606;

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

t = transition::ptr(new transition(256,"null",258,259,guard_polytope,assignment));

Out_Going_Trans_fromloc_606.push_back(t);
l = location::ptr(new location(258, "loc_606", system_dynamics, invariant, true, Out_Going_Trans_fromloc_606));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_607

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_607;

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

t = transition::ptr(new transition(257,"null",259,260,guard_polytope,assignment));

Out_Going_Trans_fromloc_607.push_back(t);
l = location::ptr(new location(259, "loc_607", system_dynamics, invariant, true, Out_Going_Trans_fromloc_607));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_608

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_608;

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

t = transition::ptr(new transition(258,"null",260,261,guard_polytope,assignment));

Out_Going_Trans_fromloc_608.push_back(t);
l = location::ptr(new location(260, "loc_608", system_dynamics, invariant, true, Out_Going_Trans_fromloc_608));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_609

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_609;

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

t = transition::ptr(new transition(259,"null",261,262,guard_polytope,assignment));

Out_Going_Trans_fromloc_609.push_back(t);
l = location::ptr(new location(261, "loc_609", system_dynamics, invariant, true, Out_Going_Trans_fromloc_609));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_610

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_610;

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

t = transition::ptr(new transition(260,"null",262,263,guard_polytope,assignment));

Out_Going_Trans_fromloc_610.push_back(t);
l = location::ptr(new location(262, "loc_610", system_dynamics, invariant, true, Out_Going_Trans_fromloc_610));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_611

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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_611;

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

t = transition::ptr(new transition(261,"null",263,264,guard_polytope,assignment));

Out_Going_Trans_fromloc_611.push_back(t);
// The transition label is null

// Original guard: x2 <= 24 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 24.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(262,"null",263,250,guard_polytope,assignment));

Out_Going_Trans_fromloc_611.push_back(t);
l = location::ptr(new location(263, "loc_611", system_dynamics, invariant, true, Out_Going_Trans_fromloc_611));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_612

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_612;

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

t = transition::ptr(new transition(263,"null",264,265,guard_polytope,assignment));

Out_Going_Trans_fromloc_612.push_back(t);
l = location::ptr(new location(264, "loc_612", system_dynamics, invariant, true, Out_Going_Trans_fromloc_612));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_613

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_613;

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

t = transition::ptr(new transition(264,"null",265,266,guard_polytope,assignment));

Out_Going_Trans_fromloc_613.push_back(t);
l = location::ptr(new location(265, "loc_613", system_dynamics, invariant, true, Out_Going_Trans_fromloc_613));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_614

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_614;

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

t = transition::ptr(new transition(265,"null",266,267,guard_polytope,assignment));

Out_Going_Trans_fromloc_614.push_back(t);
l = location::ptr(new location(266, "loc_614", system_dynamics, invariant, true, Out_Going_Trans_fromloc_614));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_615

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_615;

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

t = transition::ptr(new transition(266,"null",267,268,guard_polytope,assignment));

Out_Going_Trans_fromloc_615.push_back(t);
l = location::ptr(new location(267, "loc_615", system_dynamics, invariant, true, Out_Going_Trans_fromloc_615));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_616

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_616;

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

t = transition::ptr(new transition(267,"null",268,269,guard_polytope,assignment));

Out_Going_Trans_fromloc_616.push_back(t);
l = location::ptr(new location(268, "loc_616", system_dynamics, invariant, true, Out_Going_Trans_fromloc_616));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_617

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_617;

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

t = transition::ptr(new transition(268,"null",269,270,guard_polytope,assignment));

Out_Going_Trans_fromloc_617.push_back(t);
l = location::ptr(new location(269, "loc_617", system_dynamics, invariant, true, Out_Going_Trans_fromloc_617));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_618

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_618;

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

t = transition::ptr(new transition(269,"null",270,271,guard_polytope,assignment));

Out_Going_Trans_fromloc_618.push_back(t);
l = location::ptr(new location(270, "loc_618", system_dynamics, invariant, true, Out_Going_Trans_fromloc_618));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_619

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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_619;

// The transition label is null

// Original guard: x1 >= 20 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -20.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(270,"null",271,272,guard_polytope,assignment));

Out_Going_Trans_fromloc_619.push_back(t);
l = location::ptr(new location(271, "loc_619", system_dynamics, invariant, true, Out_Going_Trans_fromloc_619));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_620

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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_620;

// The transition label is null

// Original guard: x1 >= 21 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -21.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(271,"null",272,273,guard_polytope,assignment));

Out_Going_Trans_fromloc_620.push_back(t);
l = location::ptr(new location(272, "loc_620", system_dynamics, invariant, true, Out_Going_Trans_fromloc_620));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_621

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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_621;

// The transition label is null

// Original guard: x1 >= 22 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -22.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(272,"null",273,274,guard_polytope,assignment));

Out_Going_Trans_fromloc_621.push_back(t);
l = location::ptr(new location(273, "loc_621", system_dynamics, invariant, true, Out_Going_Trans_fromloc_621));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_622

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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_622;

// The transition label is null

// Original guard: x1 >= 23 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -23.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(273,"null",274,275,guard_polytope,assignment));

Out_Going_Trans_fromloc_622.push_back(t);
l = location::ptr(new location(274, "loc_622", system_dynamics, invariant, true, Out_Going_Trans_fromloc_622));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_623

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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_623;

// The transition label is null

// Original guard: x1 >= 24 - 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -24.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(274,"null",275,276,guard_polytope,assignment));

Out_Going_Trans_fromloc_623.push_back(t);
l = location::ptr(new location(275, "loc_623", system_dynamics, invariant, true, Out_Going_Trans_fromloc_623));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_624

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
invariantBoundValue[0] = -24.0;
invariantBoundValue[1] = 25.0;
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_624;

// The transition label is null

// Original guard: x2 <= 24 + 0

row = 1;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = 24.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 5;
col = 5;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(275,"null",276,251,guard_polytope,assignment));

Out_Going_Trans_fromloc_624.push_back(t);
l = location::ptr(new location(276, "loc_624", system_dynamics, invariant, true, Out_Going_Trans_fromloc_624));
Hybrid_Automata.addLocation(l);

}

