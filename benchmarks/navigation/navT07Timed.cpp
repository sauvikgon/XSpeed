// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav07/navT07_Timed.xml
// Command Line arguments: -tool xspeed "" -output /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav07/navT07_Timed.cpp -input /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav07/navT07_Timed.xml /home/movies/MyData/tools/SpaceEX/spaceex_exe/removed_Ut/nav07/nav07-pdb.cfg

#include <benchmarks/navigation/navT07Timed.h>
void setnavT07_Timedmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_1;


l = location::ptr(new location(1, "loc_1", system_dynamics, invariant, true, Out_Going_Trans_fromloc_1));
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_3;


l = location::ptr(new location(2, "loc_3", system_dynamics, invariant, true, Out_Going_Trans_fromloc_3));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_5;


l = location::ptr(new location(3, "loc_5", system_dynamics, invariant, true, Out_Going_Trans_fromloc_5));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_7;


l = location::ptr(new location(4, "loc_7", system_dynamics, invariant, true, Out_Going_Trans_fromloc_7));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_9;


l = location::ptr(new location(5, "loc_9", system_dynamics, invariant, true, Out_Going_Trans_fromloc_9));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_11;


l = location::ptr(new location(6, "loc_11", system_dynamics, invariant, true, Out_Going_Trans_fromloc_11));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_13;


l = location::ptr(new location(7, "loc_13", system_dynamics, invariant, true, Out_Going_Trans_fromloc_13));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_15;


l = location::ptr(new location(8, "loc_15", system_dynamics, invariant, true, Out_Going_Trans_fromloc_15));
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
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_17;


l = location::ptr(new location(9, "loc_17", system_dynamics, invariant, true, Out_Going_Trans_fromloc_17));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_19;


l = location::ptr(new location(10, "loc_19", system_dynamics, invariant, true, Out_Going_Trans_fromloc_19));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_21;


l = location::ptr(new location(11, "loc_21", system_dynamics, invariant, true, Out_Going_Trans_fromloc_21));
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[3] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_23;


l = location::ptr(new location(12, "loc_23", system_dynamics, invariant, true, Out_Going_Trans_fromloc_23));
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_26;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(1,"null",13,1,guard_polytope,assignment));

Out_Going_Trans_fromloc_26.push_back(t);
l = location::ptr(new location(13, "loc_26", system_dynamics, invariant, true, Out_Going_Trans_fromloc_26));
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_28;

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

t = transition::ptr(new transition(2,"null",14,2,guard_polytope,assignment));

Out_Going_Trans_fromloc_28.push_back(t);
l = location::ptr(new location(14, "loc_28", system_dynamics, invariant, true, Out_Going_Trans_fromloc_28));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_30

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_30;

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

t = transition::ptr(new transition(3,"null",15,3,guard_polytope,assignment));

Out_Going_Trans_fromloc_30.push_back(t);
l = location::ptr(new location(15, "loc_30", system_dynamics, invariant, true, Out_Going_Trans_fromloc_30));
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

t = transition::ptr(new transition(4,"null",16,4,guard_polytope,assignment));

Out_Going_Trans_fromloc_32.push_back(t);
l = location::ptr(new location(16, "loc_32", system_dynamics, invariant, true, Out_Going_Trans_fromloc_32));
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_34;

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

t = transition::ptr(new transition(5,"null",17,5,guard_polytope,assignment));

Out_Going_Trans_fromloc_34.push_back(t);
l = location::ptr(new location(17, "loc_34", system_dynamics, invariant, true, Out_Going_Trans_fromloc_34));
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_36;

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

t = transition::ptr(new transition(6,"null",18,6,guard_polytope,assignment));

Out_Going_Trans_fromloc_36.push_back(t);
l = location::ptr(new location(18, "loc_36", system_dynamics, invariant, true, Out_Going_Trans_fromloc_36));
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_38;

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

t = transition::ptr(new transition(7,"null",19,7,guard_polytope,assignment));

Out_Going_Trans_fromloc_38.push_back(t);
l = location::ptr(new location(19, "loc_38", system_dynamics, invariant, true, Out_Going_Trans_fromloc_38));
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_40;

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

t = transition::ptr(new transition(8,"null",20,8,guard_polytope,assignment));

Out_Going_Trans_fromloc_40.push_back(t);
l = location::ptr(new location(20, "loc_40", system_dynamics, invariant, true, Out_Going_Trans_fromloc_40));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_42

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_42;

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

t = transition::ptr(new transition(9,"null",21,9,guard_polytope,assignment));

Out_Going_Trans_fromloc_42.push_back(t);
l = location::ptr(new location(21, "loc_42", system_dynamics, invariant, true, Out_Going_Trans_fromloc_42));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_44;

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

t = transition::ptr(new transition(10,"null",22,10,guard_polytope,assignment));

Out_Going_Trans_fromloc_44.push_back(t);
l = location::ptr(new location(22, "loc_44", system_dynamics, invariant, true, Out_Going_Trans_fromloc_44));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_46;

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

t = transition::ptr(new transition(11,"null",23,11,guard_polytope,assignment));

Out_Going_Trans_fromloc_46.push_back(t);
l = location::ptr(new location(23, "loc_46", system_dynamics, invariant, true, Out_Going_Trans_fromloc_46));
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_48;

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

t = transition::ptr(new transition(12,"null",24,12,guard_polytope,assignment));

Out_Going_Trans_fromloc_48.push_back(t);
l = location::ptr(new location(24, "loc_48", system_dynamics, invariant, true, Out_Going_Trans_fromloc_48));
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_51;

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

t = transition::ptr(new transition(13,"null",25,13,guard_polytope,assignment));

Out_Going_Trans_fromloc_51.push_back(t);
l = location::ptr(new location(25, "loc_51", system_dynamics, invariant, true, Out_Going_Trans_fromloc_51));
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_53;

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

t = transition::ptr(new transition(14,"null",26,14,guard_polytope,assignment));

Out_Going_Trans_fromloc_53.push_back(t);
l = location::ptr(new location(26, "loc_53", system_dynamics, invariant, true, Out_Going_Trans_fromloc_53));
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_55;

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

t = transition::ptr(new transition(15,"null",27,15,guard_polytope,assignment));

Out_Going_Trans_fromloc_55.push_back(t);
l = location::ptr(new location(27, "loc_55", system_dynamics, invariant, true, Out_Going_Trans_fromloc_55));
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_57;

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

t = transition::ptr(new transition(16,"null",28,16,guard_polytope,assignment));

Out_Going_Trans_fromloc_57.push_back(t);
l = location::ptr(new location(28, "loc_57", system_dynamics, invariant, true, Out_Going_Trans_fromloc_57));
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

t = transition::ptr(new transition(17,"null",29,17,guard_polytope,assignment));

Out_Going_Trans_fromloc_59.push_back(t);
l = location::ptr(new location(29, "loc_59", system_dynamics, invariant, true, Out_Going_Trans_fromloc_59));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_61

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_61;

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

t = transition::ptr(new transition(18,"null",30,18,guard_polytope,assignment));

Out_Going_Trans_fromloc_61.push_back(t);
l = location::ptr(new location(30, "loc_61", system_dynamics, invariant, true, Out_Going_Trans_fromloc_61));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_63

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_63;

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

t = transition::ptr(new transition(19,"null",31,19,guard_polytope,assignment));

Out_Going_Trans_fromloc_63.push_back(t);
l = location::ptr(new location(31, "loc_63", system_dynamics, invariant, true, Out_Going_Trans_fromloc_63));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_65

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_65;

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

t = transition::ptr(new transition(20,"null",32,20,guard_polytope,assignment));

Out_Going_Trans_fromloc_65.push_back(t);
l = location::ptr(new location(32, "loc_65", system_dynamics, invariant, true, Out_Going_Trans_fromloc_65));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_67

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_67;

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

t = transition::ptr(new transition(21,"null",33,21,guard_polytope,assignment));

Out_Going_Trans_fromloc_67.push_back(t);
l = location::ptr(new location(33, "loc_67", system_dynamics, invariant, true, Out_Going_Trans_fromloc_67));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_69

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_69;

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

t = transition::ptr(new transition(22,"null",34,22,guard_polytope,assignment));

Out_Going_Trans_fromloc_69.push_back(t);
l = location::ptr(new location(34, "loc_69", system_dynamics, invariant, true, Out_Going_Trans_fromloc_69));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_71;

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

t = transition::ptr(new transition(23,"null",35,23,guard_polytope,assignment));

Out_Going_Trans_fromloc_71.push_back(t);
l = location::ptr(new location(35, "loc_71", system_dynamics, invariant, true, Out_Going_Trans_fromloc_71));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_73

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_73;

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

t = transition::ptr(new transition(24,"null",36,24,guard_polytope,assignment));

Out_Going_Trans_fromloc_73.push_back(t);
l = location::ptr(new location(36, "loc_73", system_dynamics, invariant, true, Out_Going_Trans_fromloc_73));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_76

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_76;

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

t = transition::ptr(new transition(25,"null",37,25,guard_polytope,assignment));

Out_Going_Trans_fromloc_76.push_back(t);
l = location::ptr(new location(37, "loc_76", system_dynamics, invariant, true, Out_Going_Trans_fromloc_76));
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_78;

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

t = transition::ptr(new transition(26,"null",38,26,guard_polytope,assignment));

Out_Going_Trans_fromloc_78.push_back(t);
l = location::ptr(new location(38, "loc_78", system_dynamics, invariant, true, Out_Going_Trans_fromloc_78));
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
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_80;

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

t = transition::ptr(new transition(27,"null",39,27,guard_polytope,assignment));

Out_Going_Trans_fromloc_80.push_back(t);
l = location::ptr(new location(39, "loc_80", system_dynamics, invariant, true, Out_Going_Trans_fromloc_80));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_82;

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

t = transition::ptr(new transition(28,"null",40,28,guard_polytope,assignment));

Out_Going_Trans_fromloc_82.push_back(t);
l = location::ptr(new location(40, "loc_82", system_dynamics, invariant, true, Out_Going_Trans_fromloc_82));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_84;

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

t = transition::ptr(new transition(29,"null",41,29,guard_polytope,assignment));

Out_Going_Trans_fromloc_84.push_back(t);
l = location::ptr(new location(41, "loc_84", system_dynamics, invariant, true, Out_Going_Trans_fromloc_84));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_86;

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

t = transition::ptr(new transition(30,"null",42,30,guard_polytope,assignment));

Out_Going_Trans_fromloc_86.push_back(t);
l = location::ptr(new location(42, "loc_86", system_dynamics, invariant, true, Out_Going_Trans_fromloc_86));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_88;

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

t = transition::ptr(new transition(31,"null",43,31,guard_polytope,assignment));

Out_Going_Trans_fromloc_88.push_back(t);
l = location::ptr(new location(43, "loc_88", system_dynamics, invariant, true, Out_Going_Trans_fromloc_88));
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_90;

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

t = transition::ptr(new transition(32,"null",44,32,guard_polytope,assignment));

Out_Going_Trans_fromloc_90.push_back(t);
l = location::ptr(new location(44, "loc_90", system_dynamics, invariant, true, Out_Going_Trans_fromloc_90));
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_92;

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

t = transition::ptr(new transition(33,"null",45,33,guard_polytope,assignment));

Out_Going_Trans_fromloc_92.push_back(t);
l = location::ptr(new location(45, "loc_92", system_dynamics, invariant, true, Out_Going_Trans_fromloc_92));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_94;

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

t = transition::ptr(new transition(34,"null",46,34,guard_polytope,assignment));

Out_Going_Trans_fromloc_94.push_back(t);
l = location::ptr(new location(46, "loc_94", system_dynamics, invariant, true, Out_Going_Trans_fromloc_94));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_96;

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

t = transition::ptr(new transition(35,"null",47,35,guard_polytope,assignment));

Out_Going_Trans_fromloc_96.push_back(t);
l = location::ptr(new location(47, "loc_96", system_dynamics, invariant, true, Out_Going_Trans_fromloc_96));
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_98;

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

t = transition::ptr(new transition(36,"null",48,36,guard_polytope,assignment));

Out_Going_Trans_fromloc_98.push_back(t);
l = location::ptr(new location(48, "loc_98", system_dynamics, invariant, true, Out_Going_Trans_fromloc_98));
Hybrid_Automata.addLocation(l);

navT07_Timed_module1(Hybrid_Automata,init_state_list,reach_parameters);
navT07_Timed_module2(Hybrid_Automata,init_state_list,reach_parameters);
navT07_Timed_module3(Hybrid_Automata,init_state_list,reach_parameters);
navT07_Timed_module4(Hybrid_Automata,init_state_list,reach_parameters);

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
boundValueI[0]=13;
boundValueI[1]=-12;
boundValueI[2]=25;
boundValueI[3]=-24;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =228;

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

void navT07_Timed_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_101;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(37,"null",49,37,guard_polytope,assignment));

Out_Going_Trans_fromloc_101.push_back(t);
l = location::ptr(new location(49, "loc_101", system_dynamics, invariant, true, Out_Going_Trans_fromloc_101));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_103

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_103;

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

t = transition::ptr(new transition(38,"null",50,38,guard_polytope,assignment));

Out_Going_Trans_fromloc_103.push_back(t);
l = location::ptr(new location(50, "loc_103", system_dynamics, invariant, true, Out_Going_Trans_fromloc_103));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_105

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_105;

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

t = transition::ptr(new transition(39,"null",51,39,guard_polytope,assignment));

Out_Going_Trans_fromloc_105.push_back(t);
l = location::ptr(new location(51, "loc_105", system_dynamics, invariant, true, Out_Going_Trans_fromloc_105));
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_107;

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

t = transition::ptr(new transition(40,"null",52,40,guard_polytope,assignment));

Out_Going_Trans_fromloc_107.push_back(t);
l = location::ptr(new location(52, "loc_107", system_dynamics, invariant, true, Out_Going_Trans_fromloc_107));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_109

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_109;

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

t = transition::ptr(new transition(41,"null",53,41,guard_polytope,assignment));

Out_Going_Trans_fromloc_109.push_back(t);
l = location::ptr(new location(53, "loc_109", system_dynamics, invariant, true, Out_Going_Trans_fromloc_109));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_111

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_111;

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

t = transition::ptr(new transition(42,"null",54,42,guard_polytope,assignment));

Out_Going_Trans_fromloc_111.push_back(t);
l = location::ptr(new location(54, "loc_111", system_dynamics, invariant, true, Out_Going_Trans_fromloc_111));
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_113;

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

t = transition::ptr(new transition(43,"null",55,43,guard_polytope,assignment));

Out_Going_Trans_fromloc_113.push_back(t);
l = location::ptr(new location(55, "loc_113", system_dynamics, invariant, true, Out_Going_Trans_fromloc_113));
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_115;

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

t = transition::ptr(new transition(44,"null",56,44,guard_polytope,assignment));

Out_Going_Trans_fromloc_115.push_back(t);
l = location::ptr(new location(56, "loc_115", system_dynamics, invariant, true, Out_Going_Trans_fromloc_115));
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_117;

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

t = transition::ptr(new transition(45,"null",57,45,guard_polytope,assignment));

Out_Going_Trans_fromloc_117.push_back(t);
l = location::ptr(new location(57, "loc_117", system_dynamics, invariant, true, Out_Going_Trans_fromloc_117));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_119

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_119;

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

t = transition::ptr(new transition(46,"null",58,46,guard_polytope,assignment));

Out_Going_Trans_fromloc_119.push_back(t);
l = location::ptr(new location(58, "loc_119", system_dynamics, invariant, true, Out_Going_Trans_fromloc_119));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_121;

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

t = transition::ptr(new transition(47,"null",59,47,guard_polytope,assignment));

Out_Going_Trans_fromloc_121.push_back(t);
l = location::ptr(new location(59, "loc_121", system_dynamics, invariant, true, Out_Going_Trans_fromloc_121));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_123

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_123;

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

t = transition::ptr(new transition(48,"null",60,48,guard_polytope,assignment));

Out_Going_Trans_fromloc_123.push_back(t);
l = location::ptr(new location(60, "loc_123", system_dynamics, invariant, true, Out_Going_Trans_fromloc_123));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_126

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_126;

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

t = transition::ptr(new transition(49,"null",61,49,guard_polytope,assignment));

Out_Going_Trans_fromloc_126.push_back(t);
l = location::ptr(new location(61, "loc_126", system_dynamics, invariant, true, Out_Going_Trans_fromloc_126));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_128

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_128;

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

t = transition::ptr(new transition(50,"null",62,50,guard_polytope,assignment));

Out_Going_Trans_fromloc_128.push_back(t);
l = location::ptr(new location(62, "loc_128", system_dynamics, invariant, true, Out_Going_Trans_fromloc_128));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_130;

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

t = transition::ptr(new transition(51,"null",63,51,guard_polytope,assignment));

Out_Going_Trans_fromloc_130.push_back(t);
l = location::ptr(new location(63, "loc_130", system_dynamics, invariant, true, Out_Going_Trans_fromloc_130));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_132;

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

t = transition::ptr(new transition(52,"null",64,52,guard_polytope,assignment));

Out_Going_Trans_fromloc_132.push_back(t);
l = location::ptr(new location(64, "loc_132", system_dynamics, invariant, true, Out_Going_Trans_fromloc_132));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_134;

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

t = transition::ptr(new transition(53,"null",65,53,guard_polytope,assignment));

Out_Going_Trans_fromloc_134.push_back(t);
l = location::ptr(new location(65, "loc_134", system_dynamics, invariant, true, Out_Going_Trans_fromloc_134));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_136;

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

t = transition::ptr(new transition(54,"null",66,54,guard_polytope,assignment));

Out_Going_Trans_fromloc_136.push_back(t);
l = location::ptr(new location(66, "loc_136", system_dynamics, invariant, true, Out_Going_Trans_fromloc_136));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_138;

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

t = transition::ptr(new transition(55,"null",67,55,guard_polytope,assignment));

Out_Going_Trans_fromloc_138.push_back(t);
l = location::ptr(new location(67, "loc_138", system_dynamics, invariant, true, Out_Going_Trans_fromloc_138));
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
invariantBoundValue[0] = -15.0;
invariantBoundValue[1] = 16.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_140;

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

t = transition::ptr(new transition(56,"null",68,56,guard_polytope,assignment));

Out_Going_Trans_fromloc_140.push_back(t);
l = location::ptr(new location(68, "loc_140", system_dynamics, invariant, true, Out_Going_Trans_fromloc_140));
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_142;

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

t = transition::ptr(new transition(57,"null",69,57,guard_polytope,assignment));

Out_Going_Trans_fromloc_142.push_back(t);
l = location::ptr(new location(69, "loc_142", system_dynamics, invariant, true, Out_Going_Trans_fromloc_142));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_144;

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

t = transition::ptr(new transition(58,"null",70,58,guard_polytope,assignment));

Out_Going_Trans_fromloc_144.push_back(t);
l = location::ptr(new location(70, "loc_144", system_dynamics, invariant, true, Out_Going_Trans_fromloc_144));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_146

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_146;

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

t = transition::ptr(new transition(59,"null",71,59,guard_polytope,assignment));

Out_Going_Trans_fromloc_146.push_back(t);
l = location::ptr(new location(71, "loc_146", system_dynamics, invariant, true, Out_Going_Trans_fromloc_146));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_148

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_148;

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

t = transition::ptr(new transition(60,"null",72,60,guard_polytope,assignment));

Out_Going_Trans_fromloc_148.push_back(t);
l = location::ptr(new location(72, "loc_148", system_dynamics, invariant, true, Out_Going_Trans_fromloc_148));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_151

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_151;

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

t = transition::ptr(new transition(61,"null",73,61,guard_polytope,assignment));

Out_Going_Trans_fromloc_151.push_back(t);
l = location::ptr(new location(73, "loc_151", system_dynamics, invariant, true, Out_Going_Trans_fromloc_151));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_153

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_153;

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

t = transition::ptr(new transition(62,"null",74,62,guard_polytope,assignment));

Out_Going_Trans_fromloc_153.push_back(t);
l = location::ptr(new location(74, "loc_153", system_dynamics, invariant, true, Out_Going_Trans_fromloc_153));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_155

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_155;

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

t = transition::ptr(new transition(63,"null",75,63,guard_polytope,assignment));

Out_Going_Trans_fromloc_155.push_back(t);
l = location::ptr(new location(75, "loc_155", system_dynamics, invariant, true, Out_Going_Trans_fromloc_155));
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
invariantBoundValue[0] = -7.0;
invariantBoundValue[1] = 8.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_157;

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

t = transition::ptr(new transition(64,"null",76,64,guard_polytope,assignment));

Out_Going_Trans_fromloc_157.push_back(t);
l = location::ptr(new location(76, "loc_157", system_dynamics, invariant, true, Out_Going_Trans_fromloc_157));
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


std::list<transition::ptr> Out_Going_Trans_fromloc_159;

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

t = transition::ptr(new transition(65,"null",77,65,guard_polytope,assignment));

Out_Going_Trans_fromloc_159.push_back(t);
l = location::ptr(new location(77, "loc_159", system_dynamics, invariant, true, Out_Going_Trans_fromloc_159));
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_161;

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

t = transition::ptr(new transition(66,"null",78,66,guard_polytope,assignment));

Out_Going_Trans_fromloc_161.push_back(t);
l = location::ptr(new location(78, "loc_161", system_dynamics, invariant, true, Out_Going_Trans_fromloc_161));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_163

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_163;

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

t = transition::ptr(new transition(67,"null",79,67,guard_polytope,assignment));

Out_Going_Trans_fromloc_163.push_back(t);
l = location::ptr(new location(79, "loc_163", system_dynamics, invariant, true, Out_Going_Trans_fromloc_163));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_165

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_165;

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

t = transition::ptr(new transition(68,"null",80,68,guard_polytope,assignment));

Out_Going_Trans_fromloc_165.push_back(t);
l = location::ptr(new location(80, "loc_165", system_dynamics, invariant, true, Out_Going_Trans_fromloc_165));
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_167;

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

t = transition::ptr(new transition(69,"null",81,69,guard_polytope,assignment));

Out_Going_Trans_fromloc_167.push_back(t);
l = location::ptr(new location(81, "loc_167", system_dynamics, invariant, true, Out_Going_Trans_fromloc_167));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_169;

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

t = transition::ptr(new transition(70,"null",82,70,guard_polytope,assignment));

Out_Going_Trans_fromloc_169.push_back(t);
l = location::ptr(new location(82, "loc_169", system_dynamics, invariant, true, Out_Going_Trans_fromloc_169));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_171

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_171;

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

t = transition::ptr(new transition(71,"null",83,71,guard_polytope,assignment));

Out_Going_Trans_fromloc_171.push_back(t);
l = location::ptr(new location(83, "loc_171", system_dynamics, invariant, true, Out_Going_Trans_fromloc_171));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_173

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_173;

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

t = transition::ptr(new transition(72,"null",84,72,guard_polytope,assignment));

Out_Going_Trans_fromloc_173.push_back(t);
l = location::ptr(new location(84, "loc_173", system_dynamics, invariant, true, Out_Going_Trans_fromloc_173));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_176

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_176;

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

t = transition::ptr(new transition(73,"null",85,73,guard_polytope,assignment));

Out_Going_Trans_fromloc_176.push_back(t);
l = location::ptr(new location(85, "loc_176", system_dynamics, invariant, true, Out_Going_Trans_fromloc_176));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_178

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_178;

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

t = transition::ptr(new transition(74,"null",86,74,guard_polytope,assignment));

Out_Going_Trans_fromloc_178.push_back(t);
l = location::ptr(new location(86, "loc_178", system_dynamics, invariant, true, Out_Going_Trans_fromloc_178));
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
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_180;

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

t = transition::ptr(new transition(75,"null",87,75,guard_polytope,assignment));

Out_Going_Trans_fromloc_180.push_back(t);
l = location::ptr(new location(87, "loc_180", system_dynamics, invariant, true, Out_Going_Trans_fromloc_180));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_182

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_182;

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

t = transition::ptr(new transition(76,"null",88,76,guard_polytope,assignment));

Out_Going_Trans_fromloc_182.push_back(t);
l = location::ptr(new location(88, "loc_182", system_dynamics, invariant, true, Out_Going_Trans_fromloc_182));
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


std::list<transition::ptr> Out_Going_Trans_fromloc_184;

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

t = transition::ptr(new transition(77,"null",89,77,guard_polytope,assignment));

Out_Going_Trans_fromloc_184.push_back(t);
l = location::ptr(new location(89, "loc_184", system_dynamics, invariant, true, Out_Going_Trans_fromloc_184));
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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_186;

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

t = transition::ptr(new transition(78,"null",90,78,guard_polytope,assignment));

Out_Going_Trans_fromloc_186.push_back(t);
l = location::ptr(new location(90, "loc_186", system_dynamics, invariant, true, Out_Going_Trans_fromloc_186));
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_188;

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

t = transition::ptr(new transition(79,"null",91,79,guard_polytope,assignment));

Out_Going_Trans_fromloc_188.push_back(t);
l = location::ptr(new location(91, "loc_188", system_dynamics, invariant, true, Out_Going_Trans_fromloc_188));
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_190;

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

t = transition::ptr(new transition(80,"null",92,80,guard_polytope,assignment));

Out_Going_Trans_fromloc_190.push_back(t);
l = location::ptr(new location(92, "loc_190", system_dynamics, invariant, true, Out_Going_Trans_fromloc_190));
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


std::list<transition::ptr> Out_Going_Trans_fromloc_192;

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

t = transition::ptr(new transition(81,"null",93,81,guard_polytope,assignment));

Out_Going_Trans_fromloc_192.push_back(t);
l = location::ptr(new location(93, "loc_192", system_dynamics, invariant, true, Out_Going_Trans_fromloc_192));
Hybrid_Automata.addLocation(l);

}

void navT07_Timed_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_194;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(82,"null",94,82,guard_polytope,assignment));

Out_Going_Trans_fromloc_194.push_back(t);
l = location::ptr(new location(94, "loc_194", system_dynamics, invariant, true, Out_Going_Trans_fromloc_194));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_196;

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

t = transition::ptr(new transition(83,"null",95,83,guard_polytope,assignment));

Out_Going_Trans_fromloc_196.push_back(t);
l = location::ptr(new location(95, "loc_196", system_dynamics, invariant, true, Out_Going_Trans_fromloc_196));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_198

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_198;

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

t = transition::ptr(new transition(84,"null",96,84,guard_polytope,assignment));

Out_Going_Trans_fromloc_198.push_back(t);
l = location::ptr(new location(96, "loc_198", system_dynamics, invariant, true, Out_Going_Trans_fromloc_198));
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_201;

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

t = transition::ptr(new transition(85,"null",97,85,guard_polytope,assignment));

Out_Going_Trans_fromloc_201.push_back(t);
l = location::ptr(new location(97, "loc_201", system_dynamics, invariant, true, Out_Going_Trans_fromloc_201));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_203

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_203;

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

t = transition::ptr(new transition(86,"null",98,86,guard_polytope,assignment));

Out_Going_Trans_fromloc_203.push_back(t);
l = location::ptr(new location(98, "loc_203", system_dynamics, invariant, true, Out_Going_Trans_fromloc_203));
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_205;

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

t = transition::ptr(new transition(87,"null",99,87,guard_polytope,assignment));

Out_Going_Trans_fromloc_205.push_back(t);
l = location::ptr(new location(99, "loc_205", system_dynamics, invariant, true, Out_Going_Trans_fromloc_205));
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_207;

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

t = transition::ptr(new transition(88,"null",100,88,guard_polytope,assignment));

Out_Going_Trans_fromloc_207.push_back(t);
l = location::ptr(new location(100, "loc_207", system_dynamics, invariant, true, Out_Going_Trans_fromloc_207));
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


std::list<transition::ptr> Out_Going_Trans_fromloc_209;

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

t = transition::ptr(new transition(89,"null",101,89,guard_polytope,assignment));

Out_Going_Trans_fromloc_209.push_back(t);
l = location::ptr(new location(101, "loc_209", system_dynamics, invariant, true, Out_Going_Trans_fromloc_209));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_211

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_211;

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

t = transition::ptr(new transition(90,"null",102,90,guard_polytope,assignment));

Out_Going_Trans_fromloc_211.push_back(t);
l = location::ptr(new location(102, "loc_211", system_dynamics, invariant, true, Out_Going_Trans_fromloc_211));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_213

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_213;

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

t = transition::ptr(new transition(91,"null",103,91,guard_polytope,assignment));

Out_Going_Trans_fromloc_213.push_back(t);
l = location::ptr(new location(103, "loc_213", system_dynamics, invariant, true, Out_Going_Trans_fromloc_213));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_215

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_215;

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

t = transition::ptr(new transition(92,"null",104,92,guard_polytope,assignment));

Out_Going_Trans_fromloc_215.push_back(t);
l = location::ptr(new location(104, "loc_215", system_dynamics, invariant, true, Out_Going_Trans_fromloc_215));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_217

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_217;

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

t = transition::ptr(new transition(93,"null",105,93,guard_polytope,assignment));

Out_Going_Trans_fromloc_217.push_back(t);
l = location::ptr(new location(105, "loc_217", system_dynamics, invariant, true, Out_Going_Trans_fromloc_217));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_219;

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

t = transition::ptr(new transition(94,"null",106,94,guard_polytope,assignment));

Out_Going_Trans_fromloc_219.push_back(t);
l = location::ptr(new location(106, "loc_219", system_dynamics, invariant, true, Out_Going_Trans_fromloc_219));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_221;

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

t = transition::ptr(new transition(95,"null",107,95,guard_polytope,assignment));

Out_Going_Trans_fromloc_221.push_back(t);
l = location::ptr(new location(107, "loc_221", system_dynamics, invariant, true, Out_Going_Trans_fromloc_221));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_223

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_223;

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

t = transition::ptr(new transition(96,"null",108,96,guard_polytope,assignment));

Out_Going_Trans_fromloc_223.push_back(t);
l = location::ptr(new location(108, "loc_223", system_dynamics, invariant, true, Out_Going_Trans_fromloc_223));
Hybrid_Automata.addLocation(l);


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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_226;

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

t = transition::ptr(new transition(97,"null",109,97,guard_polytope,assignment));

Out_Going_Trans_fromloc_226.push_back(t);
l = location::ptr(new location(109, "loc_226", system_dynamics, invariant, true, Out_Going_Trans_fromloc_226));
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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_227;

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

t = transition::ptr(new transition(98,"null",110,109,guard_polytope,assignment));

Out_Going_Trans_fromloc_227.push_back(t);
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

t = transition::ptr(new transition(99,"null",110,111,guard_polytope,assignment));

Out_Going_Trans_fromloc_227.push_back(t);
l = location::ptr(new location(110, "loc_227", system_dynamics, invariant, true, Out_Going_Trans_fromloc_227));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_228

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_228;

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

t = transition::ptr(new transition(100,"null",111,98,guard_polytope,assignment));

Out_Going_Trans_fromloc_228.push_back(t);
l = location::ptr(new location(111, "loc_228", system_dynamics, invariant, true, Out_Going_Trans_fromloc_228));
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
invariantBoundValue[0] = -5.0;
invariantBoundValue[1] = 6.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_230;

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

t = transition::ptr(new transition(101,"null",112,99,guard_polytope,assignment));

Out_Going_Trans_fromloc_230.push_back(t);
l = location::ptr(new location(112, "loc_230", system_dynamics, invariant, true, Out_Going_Trans_fromloc_230));
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_231;

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

t = transition::ptr(new transition(102,"null",113,112,guard_polytope,assignment));

Out_Going_Trans_fromloc_231.push_back(t);
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

t = transition::ptr(new transition(103,"null",113,114,guard_polytope,assignment));

Out_Going_Trans_fromloc_231.push_back(t);
l = location::ptr(new location(113, "loc_231", system_dynamics, invariant, true, Out_Going_Trans_fromloc_231));
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

t = transition::ptr(new transition(104,"null",114,100,guard_polytope,assignment));

Out_Going_Trans_fromloc_232.push_back(t);
l = location::ptr(new location(114, "loc_232", system_dynamics, invariant, true, Out_Going_Trans_fromloc_232));
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
invariantBoundValue[0] = -9.0;
invariantBoundValue[1] = 10.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_234;

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

t = transition::ptr(new transition(105,"null",115,101,guard_polytope,assignment));

Out_Going_Trans_fromloc_234.push_back(t);
l = location::ptr(new location(115, "loc_234", system_dynamics, invariant, true, Out_Going_Trans_fromloc_234));
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
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_235;

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

t = transition::ptr(new transition(106,"null",116,115,guard_polytope,assignment));

Out_Going_Trans_fromloc_235.push_back(t);
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

t = transition::ptr(new transition(107,"null",116,117,guard_polytope,assignment));

Out_Going_Trans_fromloc_235.push_back(t);
l = location::ptr(new location(116, "loc_235", system_dynamics, invariant, true, Out_Going_Trans_fromloc_235));
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_236;

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

t = transition::ptr(new transition(108,"null",117,102,guard_polytope,assignment));

Out_Going_Trans_fromloc_236.push_back(t);
l = location::ptr(new location(117, "loc_236", system_dynamics, invariant, true, Out_Going_Trans_fromloc_236));
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_238;

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

t = transition::ptr(new transition(109,"null",118,103,guard_polytope,assignment));

Out_Going_Trans_fromloc_238.push_back(t);
l = location::ptr(new location(118, "loc_238", system_dynamics, invariant, true, Out_Going_Trans_fromloc_238));
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

t = transition::ptr(new transition(110,"null",119,118,guard_polytope,assignment));

Out_Going_Trans_fromloc_239.push_back(t);
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

t = transition::ptr(new transition(111,"null",119,120,guard_polytope,assignment));

Out_Going_Trans_fromloc_239.push_back(t);
l = location::ptr(new location(119, "loc_239", system_dynamics, invariant, true, Out_Going_Trans_fromloc_239));
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
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_240;

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

t = transition::ptr(new transition(112,"null",120,104,guard_polytope,assignment));

Out_Going_Trans_fromloc_240.push_back(t);
l = location::ptr(new location(120, "loc_240", system_dynamics, invariant, true, Out_Going_Trans_fromloc_240));
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
invariantBoundValue[0] = -17.0;
invariantBoundValue[1] = 18.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_242;

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

t = transition::ptr(new transition(113,"null",121,105,guard_polytope,assignment));

Out_Going_Trans_fromloc_242.push_back(t);
l = location::ptr(new location(121, "loc_242", system_dynamics, invariant, true, Out_Going_Trans_fromloc_242));
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

t = transition::ptr(new transition(114,"null",122,121,guard_polytope,assignment));

Out_Going_Trans_fromloc_243.push_back(t);
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

t = transition::ptr(new transition(115,"null",122,123,guard_polytope,assignment));

Out_Going_Trans_fromloc_243.push_back(t);
l = location::ptr(new location(122, "loc_243", system_dynamics, invariant, true, Out_Going_Trans_fromloc_243));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_244;

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

t = transition::ptr(new transition(116,"null",123,106,guard_polytope,assignment));

Out_Going_Trans_fromloc_244.push_back(t);
l = location::ptr(new location(123, "loc_244", system_dynamics, invariant, true, Out_Going_Trans_fromloc_244));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_246;

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

t = transition::ptr(new transition(117,"null",124,107,guard_polytope,assignment));

Out_Going_Trans_fromloc_246.push_back(t);
l = location::ptr(new location(124, "loc_246", system_dynamics, invariant, true, Out_Going_Trans_fromloc_246));
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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_247;

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

t = transition::ptr(new transition(118,"null",125,124,guard_polytope,assignment));

Out_Going_Trans_fromloc_247.push_back(t);
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

t = transition::ptr(new transition(119,"null",125,126,guard_polytope,assignment));

Out_Going_Trans_fromloc_247.push_back(t);
l = location::ptr(new location(125, "loc_247", system_dynamics, invariant, true, Out_Going_Trans_fromloc_247));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_248

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -23.0;
invariantBoundValue[1] = 24.0;
invariantBoundValue[2] = -9.0;
invariantBoundValue[3] = 10.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_248;

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

t = transition::ptr(new transition(120,"null",126,108,guard_polytope,assignment));

Out_Going_Trans_fromloc_248.push_back(t);
l = location::ptr(new location(126, "loc_248", system_dynamics, invariant, true, Out_Going_Trans_fromloc_248));
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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_252;

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

t = transition::ptr(new transition(121,"null",127,110,guard_polytope,assignment));

Out_Going_Trans_fromloc_252.push_back(t);
l = location::ptr(new location(127, "loc_252", system_dynamics, invariant, true, Out_Going_Trans_fromloc_252));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_256

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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


std::list<transition::ptr> Out_Going_Trans_fromloc_256;

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

t = transition::ptr(new transition(122,"null",128,113,guard_polytope,assignment));

Out_Going_Trans_fromloc_256.push_back(t);
l = location::ptr(new location(128, "loc_256", system_dynamics, invariant, true, Out_Going_Trans_fromloc_256));
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
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_260;

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

t = transition::ptr(new transition(123,"null",129,116,guard_polytope,assignment));

Out_Going_Trans_fromloc_260.push_back(t);
l = location::ptr(new location(129, "loc_260", system_dynamics, invariant, true, Out_Going_Trans_fromloc_260));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_264

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -10.0;
invariantBoundValue[3] = 11.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_264;

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

t = transition::ptr(new transition(124,"null",130,119,guard_polytope,assignment));

Out_Going_Trans_fromloc_264.push_back(t);
l = location::ptr(new location(130, "loc_264", system_dynamics, invariant, true, Out_Going_Trans_fromloc_264));
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

t = transition::ptr(new transition(125,"null",131,122,guard_polytope,assignment));

Out_Going_Trans_fromloc_268.push_back(t);
l = location::ptr(new location(131, "loc_268", system_dynamics, invariant, true, Out_Going_Trans_fromloc_268));
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

t = transition::ptr(new transition(126,"null",132,125,guard_polytope,assignment));

Out_Going_Trans_fromloc_272.push_back(t);
l = location::ptr(new location(132, "loc_272", system_dynamics, invariant, true, Out_Going_Trans_fromloc_272));
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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_277;

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

t = transition::ptr(new transition(127,"null",133,127,guard_polytope,assignment));

Out_Going_Trans_fromloc_277.push_back(t);
l = location::ptr(new location(133, "loc_277", system_dynamics, invariant, true, Out_Going_Trans_fromloc_277));
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


std::list<transition::ptr> Out_Going_Trans_fromloc_281;

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

t = transition::ptr(new transition(128,"null",134,128,guard_polytope,assignment));

Out_Going_Trans_fromloc_281.push_back(t);
l = location::ptr(new location(134, "loc_281", system_dynamics, invariant, true, Out_Going_Trans_fromloc_281));
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
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_285;

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

t = transition::ptr(new transition(129,"null",135,129,guard_polytope,assignment));

Out_Going_Trans_fromloc_285.push_back(t);
l = location::ptr(new location(135, "loc_285", system_dynamics, invariant, true, Out_Going_Trans_fromloc_285));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_289

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -11.0;
invariantBoundValue[3] = 12.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_289;

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

t = transition::ptr(new transition(130,"null",136,130,guard_polytope,assignment));

Out_Going_Trans_fromloc_289.push_back(t);
l = location::ptr(new location(136, "loc_289", system_dynamics, invariant, true, Out_Going_Trans_fromloc_289));
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

t = transition::ptr(new transition(131,"null",137,131,guard_polytope,assignment));

Out_Going_Trans_fromloc_293.push_back(t);
l = location::ptr(new location(137, "loc_293", system_dynamics, invariant, true, Out_Going_Trans_fromloc_293));
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

t = transition::ptr(new transition(132,"null",138,132,guard_polytope,assignment));

Out_Going_Trans_fromloc_297.push_back(t);
l = location::ptr(new location(138, "loc_297", system_dynamics, invariant, true, Out_Going_Trans_fromloc_297));
Hybrid_Automata.addLocation(l);

}

void navT07_Timed_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_302;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(133,"null",139,133,guard_polytope,assignment));

Out_Going_Trans_fromloc_302.push_back(t);
l = location::ptr(new location(139, "loc_302", system_dynamics, invariant, true, Out_Going_Trans_fromloc_302));
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


std::list<transition::ptr> Out_Going_Trans_fromloc_306;

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

t = transition::ptr(new transition(134,"null",140,134,guard_polytope,assignment));

Out_Going_Trans_fromloc_306.push_back(t);
l = location::ptr(new location(140, "loc_306", system_dynamics, invariant, true, Out_Going_Trans_fromloc_306));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_310

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_310;

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

t = transition::ptr(new transition(135,"null",141,135,guard_polytope,assignment));

Out_Going_Trans_fromloc_310.push_back(t);
l = location::ptr(new location(141, "loc_310", system_dynamics, invariant, true, Out_Going_Trans_fromloc_310));
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
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_314;

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

t = transition::ptr(new transition(136,"null",142,136,guard_polytope,assignment));

Out_Going_Trans_fromloc_314.push_back(t);
l = location::ptr(new location(142, "loc_314", system_dynamics, invariant, true, Out_Going_Trans_fromloc_314));
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

t = transition::ptr(new transition(137,"null",143,137,guard_polytope,assignment));

Out_Going_Trans_fromloc_318.push_back(t);
l = location::ptr(new location(143, "loc_318", system_dynamics, invariant, true, Out_Going_Trans_fromloc_318));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_322

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -12.0;
invariantBoundValue[3] = 13.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_322;

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

t = transition::ptr(new transition(138,"null",144,138,guard_polytope,assignment));

Out_Going_Trans_fromloc_322.push_back(t);
l = location::ptr(new location(144, "loc_322", system_dynamics, invariant, true, Out_Going_Trans_fromloc_322));
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
invariantBoundValue[0] = -2.0;
invariantBoundValue[1] = 3.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_327;

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

t = transition::ptr(new transition(139,"null",145,139,guard_polytope,assignment));

Out_Going_Trans_fromloc_327.push_back(t);
l = location::ptr(new location(145, "loc_327", system_dynamics, invariant, true, Out_Going_Trans_fromloc_327));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_328

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_328;

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

t = transition::ptr(new transition(140,"null",146,145,guard_polytope,assignment));

Out_Going_Trans_fromloc_328.push_back(t);
l = location::ptr(new location(146, "loc_328", system_dynamics, invariant, true, Out_Going_Trans_fromloc_328));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_330

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_330;

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

t = transition::ptr(new transition(141,"null",147,148,guard_polytope,assignment));

Out_Going_Trans_fromloc_330.push_back(t);
l = location::ptr(new location(147, "loc_330", system_dynamics, invariant, true, Out_Going_Trans_fromloc_330));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_331

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -6.0;
invariantBoundValue[1] = 7.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_331;

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

t = transition::ptr(new transition(142,"null",148,140,guard_polytope,assignment));

Out_Going_Trans_fromloc_331.push_back(t);
l = location::ptr(new location(148, "loc_331", system_dynamics, invariant, true, Out_Going_Trans_fromloc_331));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_335

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -10.0;
invariantBoundValue[1] = 11.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_335;

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

t = transition::ptr(new transition(143,"null",149,141,guard_polytope,assignment));

Out_Going_Trans_fromloc_335.push_back(t);
l = location::ptr(new location(149, "loc_335", system_dynamics, invariant, true, Out_Going_Trans_fromloc_335));
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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_336;

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

t = transition::ptr(new transition(144,"null",150,149,guard_polytope,assignment));

Out_Going_Trans_fromloc_336.push_back(t);
l = location::ptr(new location(150, "loc_336", system_dynamics, invariant, true, Out_Going_Trans_fromloc_336));
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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_338;

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

t = transition::ptr(new transition(145,"null",151,152,guard_polytope,assignment));

Out_Going_Trans_fromloc_338.push_back(t);
l = location::ptr(new location(151, "loc_338", system_dynamics, invariant, true, Out_Going_Trans_fromloc_338));
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
invariantBoundValue[0] = -14.0;
invariantBoundValue[1] = 15.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_339;

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

t = transition::ptr(new transition(146,"null",152,142,guard_polytope,assignment));

Out_Going_Trans_fromloc_339.push_back(t);
l = location::ptr(new location(152, "loc_339", system_dynamics, invariant, true, Out_Going_Trans_fromloc_339));
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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_343;

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

t = transition::ptr(new transition(147,"null",153,143,guard_polytope,assignment));

Out_Going_Trans_fromloc_343.push_back(t);
l = location::ptr(new location(153, "loc_343", system_dynamics, invariant, true, Out_Going_Trans_fromloc_343));
Hybrid_Automata.addLocation(l);


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
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_344;

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

t = transition::ptr(new transition(148,"null",154,153,guard_polytope,assignment));

Out_Going_Trans_fromloc_344.push_back(t);
l = location::ptr(new location(154, "loc_344", system_dynamics, invariant, true, Out_Going_Trans_fromloc_344));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_346;

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

t = transition::ptr(new transition(149,"null",155,156,guard_polytope,assignment));

Out_Going_Trans_fromloc_346.push_back(t);
l = location::ptr(new location(155, "loc_346", system_dynamics, invariant, true, Out_Going_Trans_fromloc_346));
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
invariantBoundValue[0] = -22.0;
invariantBoundValue[1] = 23.0;
invariantBoundValue[2] = -13.0;
invariantBoundValue[3] = 14.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_347;

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

t = transition::ptr(new transition(150,"null",156,144,guard_polytope,assignment));

Out_Going_Trans_fromloc_347.push_back(t);
l = location::ptr(new location(156, "loc_347", system_dynamics, invariant, true, Out_Going_Trans_fromloc_347));
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_353;

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

t = transition::ptr(new transition(151,"null",157,146,guard_polytope,assignment));

Out_Going_Trans_fromloc_353.push_back(t);
l = location::ptr(new location(157, "loc_353", system_dynamics, invariant, true, Out_Going_Trans_fromloc_353));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_355

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_355;

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

t = transition::ptr(new transition(152,"null",158,147,guard_polytope,assignment));

Out_Going_Trans_fromloc_355.push_back(t);
l = location::ptr(new location(158, "loc_355", system_dynamics, invariant, true, Out_Going_Trans_fromloc_355));
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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_361;

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

t = transition::ptr(new transition(153,"null",159,150,guard_polytope,assignment));

Out_Going_Trans_fromloc_361.push_back(t);
l = location::ptr(new location(159, "loc_361", system_dynamics, invariant, true, Out_Going_Trans_fromloc_361));
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
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_363;

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

t = transition::ptr(new transition(154,"null",160,151,guard_polytope,assignment));

Out_Going_Trans_fromloc_363.push_back(t);
l = location::ptr(new location(160, "loc_363", system_dynamics, invariant, true, Out_Going_Trans_fromloc_363));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_369;

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

t = transition::ptr(new transition(155,"null",161,154,guard_polytope,assignment));

Out_Going_Trans_fromloc_369.push_back(t);
l = location::ptr(new location(161, "loc_369", system_dynamics, invariant, true, Out_Going_Trans_fromloc_369));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -14.0;
invariantBoundValue[3] = 15.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_371;

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

t = transition::ptr(new transition(156,"null",162,155,guard_polytope,assignment));

Out_Going_Trans_fromloc_371.push_back(t);
l = location::ptr(new location(162, "loc_371", system_dynamics, invariant, true, Out_Going_Trans_fromloc_371));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_378

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_378;

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

t = transition::ptr(new transition(157,"null",163,157,guard_polytope,assignment));

Out_Going_Trans_fromloc_378.push_back(t);
l = location::ptr(new location(163, "loc_378", system_dynamics, invariant, true, Out_Going_Trans_fromloc_378));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_380

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_380;

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

t = transition::ptr(new transition(158,"null",164,158,guard_polytope,assignment));

Out_Going_Trans_fromloc_380.push_back(t);
l = location::ptr(new location(164, "loc_380", system_dynamics, invariant, true, Out_Going_Trans_fromloc_380));
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
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_386;

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

t = transition::ptr(new transition(159,"null",165,159,guard_polytope,assignment));

Out_Going_Trans_fromloc_386.push_back(t);
l = location::ptr(new location(165, "loc_386", system_dynamics, invariant, true, Out_Going_Trans_fromloc_386));
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

t = transition::ptr(new transition(160,"null",166,160,guard_polytope,assignment));

Out_Going_Trans_fromloc_388.push_back(t);
l = location::ptr(new location(166, "loc_388", system_dynamics, invariant, true, Out_Going_Trans_fromloc_388));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_394;

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

t = transition::ptr(new transition(161,"null",167,161,guard_polytope,assignment));

Out_Going_Trans_fromloc_394.push_back(t);
l = location::ptr(new location(167, "loc_394", system_dynamics, invariant, true, Out_Going_Trans_fromloc_394));
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -15.0;
invariantBoundValue[3] = 16.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_396;

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

t = transition::ptr(new transition(162,"null",168,162,guard_polytope,assignment));

Out_Going_Trans_fromloc_396.push_back(t);
l = location::ptr(new location(168, "loc_396", system_dynamics, invariant, true, Out_Going_Trans_fromloc_396));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_403

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_403;

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

t = transition::ptr(new transition(163,"null",169,163,guard_polytope,assignment));

Out_Going_Trans_fromloc_403.push_back(t);
l = location::ptr(new location(169, "loc_403", system_dynamics, invariant, true, Out_Going_Trans_fromloc_403));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_405

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_405;

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

t = transition::ptr(new transition(164,"null",170,164,guard_polytope,assignment));

Out_Going_Trans_fromloc_405.push_back(t);
l = location::ptr(new location(170, "loc_405", system_dynamics, invariant, true, Out_Going_Trans_fromloc_405));
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
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_411;

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

t = transition::ptr(new transition(165,"null",171,165,guard_polytope,assignment));

Out_Going_Trans_fromloc_411.push_back(t);
l = location::ptr(new location(171, "loc_411", system_dynamics, invariant, true, Out_Going_Trans_fromloc_411));
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

t = transition::ptr(new transition(166,"null",172,166,guard_polytope,assignment));

Out_Going_Trans_fromloc_413.push_back(t);
l = location::ptr(new location(172, "loc_413", system_dynamics, invariant, true, Out_Going_Trans_fromloc_413));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_419

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_419;

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

t = transition::ptr(new transition(167,"null",173,167,guard_polytope,assignment));

Out_Going_Trans_fromloc_419.push_back(t);
l = location::ptr(new location(173, "loc_419", system_dynamics, invariant, true, Out_Going_Trans_fromloc_419));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_421

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -16.0;
invariantBoundValue[3] = 17.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_421;

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

t = transition::ptr(new transition(168,"null",174,168,guard_polytope,assignment));

Out_Going_Trans_fromloc_421.push_back(t);
l = location::ptr(new location(174, "loc_421", system_dynamics, invariant, true, Out_Going_Trans_fromloc_421));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_428

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_428;

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

t = transition::ptr(new transition(169,"null",175,169,guard_polytope,assignment));

Out_Going_Trans_fromloc_428.push_back(t);
l = location::ptr(new location(175, "loc_428", system_dynamics, invariant, true, Out_Going_Trans_fromloc_428));
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_430;

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

t = transition::ptr(new transition(170,"null",176,170,guard_polytope,assignment));

Out_Going_Trans_fromloc_430.push_back(t);
l = location::ptr(new location(176, "loc_430", system_dynamics, invariant, true, Out_Going_Trans_fromloc_430));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_436

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_436;

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

t = transition::ptr(new transition(171,"null",177,171,guard_polytope,assignment));

Out_Going_Trans_fromloc_436.push_back(t);
l = location::ptr(new location(177, "loc_436", system_dynamics, invariant, true, Out_Going_Trans_fromloc_436));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_438

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_438;

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

t = transition::ptr(new transition(172,"null",178,172,guard_polytope,assignment));

Out_Going_Trans_fromloc_438.push_back(t);
l = location::ptr(new location(178, "loc_438", system_dynamics, invariant, true, Out_Going_Trans_fromloc_438));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_444

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_444;

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

t = transition::ptr(new transition(173,"null",179,173,guard_polytope,assignment));

Out_Going_Trans_fromloc_444.push_back(t);
l = location::ptr(new location(179, "loc_444", system_dynamics, invariant, true, Out_Going_Trans_fromloc_444));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_446

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -17.0;
invariantBoundValue[3] = 18.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_446;

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

t = transition::ptr(new transition(174,"null",180,174,guard_polytope,assignment));

Out_Going_Trans_fromloc_446.push_back(t);
l = location::ptr(new location(180, "loc_446", system_dynamics, invariant, true, Out_Going_Trans_fromloc_446));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_453

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_453;

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

t = transition::ptr(new transition(175,"null",181,175,guard_polytope,assignment));

Out_Going_Trans_fromloc_453.push_back(t);
l = location::ptr(new location(181, "loc_453", system_dynamics, invariant, true, Out_Going_Trans_fromloc_453));
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

t = transition::ptr(new transition(176,"null",182,176,guard_polytope,assignment));

Out_Going_Trans_fromloc_455.push_back(t);
l = location::ptr(new location(182, "loc_455", system_dynamics, invariant, true, Out_Going_Trans_fromloc_455));
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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_461;

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

t = transition::ptr(new transition(177,"null",183,177,guard_polytope,assignment));

Out_Going_Trans_fromloc_461.push_back(t);
l = location::ptr(new location(183, "loc_461", system_dynamics, invariant, true, Out_Going_Trans_fromloc_461));
Hybrid_Automata.addLocation(l);

}

void navT07_Timed_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_463;

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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(178,"null",184,178,guard_polytope,assignment));

Out_Going_Trans_fromloc_463.push_back(t);
l = location::ptr(new location(184, "loc_463", system_dynamics, invariant, true, Out_Going_Trans_fromloc_463));
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_469;

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

t = transition::ptr(new transition(179,"null",185,179,guard_polytope,assignment));

Out_Going_Trans_fromloc_469.push_back(t);
l = location::ptr(new location(185, "loc_469", system_dynamics, invariant, true, Out_Going_Trans_fromloc_469));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_471

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -18.0;
invariantBoundValue[3] = 19.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_471;

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

t = transition::ptr(new transition(180,"null",186,180,guard_polytope,assignment));

Out_Going_Trans_fromloc_471.push_back(t);
l = location::ptr(new location(186, "loc_471", system_dynamics, invariant, true, Out_Going_Trans_fromloc_471));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_478

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_478;

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

t = transition::ptr(new transition(181,"null",187,181,guard_polytope,assignment));

Out_Going_Trans_fromloc_478.push_back(t);
l = location::ptr(new location(187, "loc_478", system_dynamics, invariant, true, Out_Going_Trans_fromloc_478));
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

t = transition::ptr(new transition(182,"null",188,182,guard_polytope,assignment));

Out_Going_Trans_fromloc_480.push_back(t);
l = location::ptr(new location(188, "loc_480", system_dynamics, invariant, true, Out_Going_Trans_fromloc_480));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_486

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_486;

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

t = transition::ptr(new transition(183,"null",189,183,guard_polytope,assignment));

Out_Going_Trans_fromloc_486.push_back(t);
l = location::ptr(new location(189, "loc_486", system_dynamics, invariant, true, Out_Going_Trans_fromloc_486));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_488

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_488;

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

t = transition::ptr(new transition(184,"null",190,184,guard_polytope,assignment));

Out_Going_Trans_fromloc_488.push_back(t);
l = location::ptr(new location(190, "loc_488", system_dynamics, invariant, true, Out_Going_Trans_fromloc_488));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_494

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_494;

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

t = transition::ptr(new transition(185,"null",191,185,guard_polytope,assignment));

Out_Going_Trans_fromloc_494.push_back(t);
l = location::ptr(new location(191, "loc_494", system_dynamics, invariant, true, Out_Going_Trans_fromloc_494));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_496

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -19.0;
invariantBoundValue[3] = 20.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_496;

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

t = transition::ptr(new transition(186,"null",192,186,guard_polytope,assignment));

Out_Going_Trans_fromloc_496.push_back(t);
l = location::ptr(new location(192, "loc_496", system_dynamics, invariant, true, Out_Going_Trans_fromloc_496));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_503

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_503;

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

t = transition::ptr(new transition(187,"null",193,187,guard_polytope,assignment));

Out_Going_Trans_fromloc_503.push_back(t);
l = location::ptr(new location(193, "loc_503", system_dynamics, invariant, true, Out_Going_Trans_fromloc_503));
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

t = transition::ptr(new transition(188,"null",194,188,guard_polytope,assignment));

Out_Going_Trans_fromloc_505.push_back(t);
l = location::ptr(new location(194, "loc_505", system_dynamics, invariant, true, Out_Going_Trans_fromloc_505));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_511

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_511;

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

t = transition::ptr(new transition(189,"null",195,189,guard_polytope,assignment));

Out_Going_Trans_fromloc_511.push_back(t);
l = location::ptr(new location(195, "loc_511", system_dynamics, invariant, true, Out_Going_Trans_fromloc_511));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_513

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_513;

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

t = transition::ptr(new transition(190,"null",196,190,guard_polytope,assignment));

Out_Going_Trans_fromloc_513.push_back(t);
l = location::ptr(new location(196, "loc_513", system_dynamics, invariant, true, Out_Going_Trans_fromloc_513));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_519

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -19.0;
invariantBoundValue[1] = 20.0;
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_519;

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

t = transition::ptr(new transition(191,"null",197,191,guard_polytope,assignment));

Out_Going_Trans_fromloc_519.push_back(t);
l = location::ptr(new location(197, "loc_519", system_dynamics, invariant, true, Out_Going_Trans_fromloc_519));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_521

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -20.0;
invariantBoundValue[3] = 21.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_521;

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

t = transition::ptr(new transition(192,"null",198,192,guard_polytope,assignment));

Out_Going_Trans_fromloc_521.push_back(t);
l = location::ptr(new location(198, "loc_521", system_dynamics, invariant, true, Out_Going_Trans_fromloc_521));
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
invariantBoundValue[0] = -3.0;
invariantBoundValue[1] = 4.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_528;

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

t = transition::ptr(new transition(193,"null",199,193,guard_polytope,assignment));

Out_Going_Trans_fromloc_528.push_back(t);
l = location::ptr(new location(199, "loc_528", system_dynamics, invariant, true, Out_Going_Trans_fromloc_528));
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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_529;

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

t = transition::ptr(new transition(194,"null",200,199,guard_polytope,assignment));

Out_Going_Trans_fromloc_529.push_back(t);
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

t = transition::ptr(new transition(195,"null",200,201,guard_polytope,assignment));

Out_Going_Trans_fromloc_529.push_back(t);
l = location::ptr(new location(200, "loc_529", system_dynamics, invariant, true, Out_Going_Trans_fromloc_529));
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

t = transition::ptr(new transition(196,"null",201,194,guard_polytope,assignment));

Out_Going_Trans_fromloc_530.push_back(t);
l = location::ptr(new location(201, "loc_530", system_dynamics, invariant, true, Out_Going_Trans_fromloc_530));
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
invariantBoundValue[0] = -11.0;
invariantBoundValue[1] = 12.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_536;

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

t = transition::ptr(new transition(197,"null",202,195,guard_polytope,assignment));

Out_Going_Trans_fromloc_536.push_back(t);
l = location::ptr(new location(202, "loc_536", system_dynamics, invariant, true, Out_Going_Trans_fromloc_536));
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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_537;

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

t = transition::ptr(new transition(198,"null",203,202,guard_polytope,assignment));

Out_Going_Trans_fromloc_537.push_back(t);
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

t = transition::ptr(new transition(199,"null",203,204,guard_polytope,assignment));

Out_Going_Trans_fromloc_537.push_back(t);
l = location::ptr(new location(203, "loc_537", system_dynamics, invariant, true, Out_Going_Trans_fromloc_537));
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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_538;

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

t = transition::ptr(new transition(200,"null",204,196,guard_polytope,assignment));

Out_Going_Trans_fromloc_538.push_back(t);
l = location::ptr(new location(204, "loc_538", system_dynamics, invariant, true, Out_Going_Trans_fromloc_538));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_544

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_544;

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

t = transition::ptr(new transition(201,"null",205,197,guard_polytope,assignment));

Out_Going_Trans_fromloc_544.push_back(t);
l = location::ptr(new location(205, "loc_544", system_dynamics, invariant, true, Out_Going_Trans_fromloc_544));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_545

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_545;

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

t = transition::ptr(new transition(202,"null",206,205,guard_polytope,assignment));

Out_Going_Trans_fromloc_545.push_back(t);
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

t = transition::ptr(new transition(203,"null",206,207,guard_polytope,assignment));

Out_Going_Trans_fromloc_545.push_back(t);
l = location::ptr(new location(206, "loc_545", system_dynamics, invariant, true, Out_Going_Trans_fromloc_545));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_546

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -21.0;
invariantBoundValue[1] = 22.0;
invariantBoundValue[2] = -21.0;
invariantBoundValue[3] = 22.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_546;

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

t = transition::ptr(new transition(204,"null",207,198,guard_polytope,assignment));

Out_Going_Trans_fromloc_546.push_back(t);
l = location::ptr(new location(207, "loc_546", system_dynamics, invariant, true, Out_Going_Trans_fromloc_546));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_554

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -22.0;
invariantBoundValue[3] = 23.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_554;

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

t = transition::ptr(new transition(205,"null",208,200,guard_polytope,assignment));

Out_Going_Trans_fromloc_554.push_back(t);
l = location::ptr(new location(208, "loc_554", system_dynamics, invariant, true, Out_Going_Trans_fromloc_554));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_562

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -22.0;
invariantBoundValue[3] = 23.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_562;

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

t = transition::ptr(new transition(206,"null",209,203,guard_polytope,assignment));

Out_Going_Trans_fromloc_562.push_back(t);
l = location::ptr(new location(209, "loc_562", system_dynamics, invariant, true, Out_Going_Trans_fromloc_562));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_570

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -22.0;
invariantBoundValue[3] = 23.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_570;

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

t = transition::ptr(new transition(207,"null",210,206,guard_polytope,assignment));

Out_Going_Trans_fromloc_570.push_back(t);
l = location::ptr(new location(210, "loc_570", system_dynamics, invariant, true, Out_Going_Trans_fromloc_570));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_579

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_579;

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

t = transition::ptr(new transition(208,"null",211,208,guard_polytope,assignment));

Out_Going_Trans_fromloc_579.push_back(t);
l = location::ptr(new location(211, "loc_579", system_dynamics, invariant, true, Out_Going_Trans_fromloc_579));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_580

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_580;

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

t = transition::ptr(new transition(209,"null",212,211,guard_polytope,assignment));

Out_Going_Trans_fromloc_580.push_back(t);
l = location::ptr(new location(212, "loc_580", system_dynamics, invariant, true, Out_Going_Trans_fromloc_580));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_581

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_581;

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

t = transition::ptr(new transition(210,"null",213,212,guard_polytope,assignment));

Out_Going_Trans_fromloc_581.push_back(t);
l = location::ptr(new location(213, "loc_581", system_dynamics, invariant, true, Out_Going_Trans_fromloc_581));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_582

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_582;

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

t = transition::ptr(new transition(211,"null",214,213,guard_polytope,assignment));

Out_Going_Trans_fromloc_582.push_back(t);
l = location::ptr(new location(214, "loc_582", system_dynamics, invariant, true, Out_Going_Trans_fromloc_582));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_583

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_583;

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

t = transition::ptr(new transition(212,"null",215,214,guard_polytope,assignment));

Out_Going_Trans_fromloc_583.push_back(t);
l = location::ptr(new location(215, "loc_583", system_dynamics, invariant, true, Out_Going_Trans_fromloc_583));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_584

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_584;

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

t = transition::ptr(new transition(213,"null",216,215,guard_polytope,assignment));

Out_Going_Trans_fromloc_584.push_back(t);
l = location::ptr(new location(216, "loc_584", system_dynamics, invariant, true, Out_Going_Trans_fromloc_584));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_585

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_585;

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

t = transition::ptr(new transition(214,"null",217,216,guard_polytope,assignment));

Out_Going_Trans_fromloc_585.push_back(t);
l = location::ptr(new location(217, "loc_585", system_dynamics, invariant, true, Out_Going_Trans_fromloc_585));
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_586;

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

t = transition::ptr(new transition(215,"null",218,217,guard_polytope,assignment));

Out_Going_Trans_fromloc_586.push_back(t);
l = location::ptr(new location(218, "loc_586", system_dynamics, invariant, true, Out_Going_Trans_fromloc_586));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_587

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_587;

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

t = transition::ptr(new transition(216,"null",219,218,guard_polytope,assignment));

Out_Going_Trans_fromloc_587.push_back(t);
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

t = transition::ptr(new transition(217,"null",219,209,guard_polytope,assignment));

Out_Going_Trans_fromloc_587.push_back(t);
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

t = transition::ptr(new transition(218,"null",219,220,guard_polytope,assignment));

Out_Going_Trans_fromloc_587.push_back(t);
l = location::ptr(new location(219, "loc_587", system_dynamics, invariant, true, Out_Going_Trans_fromloc_587));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_588

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_588;

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

t = transition::ptr(new transition(219,"null",220,221,guard_polytope,assignment));

Out_Going_Trans_fromloc_588.push_back(t);
l = location::ptr(new location(220, "loc_588", system_dynamics, invariant, true, Out_Going_Trans_fromloc_588));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_589

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_589;

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

t = transition::ptr(new transition(220,"null",221,222,guard_polytope,assignment));

Out_Going_Trans_fromloc_589.push_back(t);
l = location::ptr(new location(221, "loc_589", system_dynamics, invariant, true, Out_Going_Trans_fromloc_589));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_590

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_590;

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

t = transition::ptr(new transition(221,"null",222,223,guard_polytope,assignment));

Out_Going_Trans_fromloc_590.push_back(t);
l = location::ptr(new location(222, "loc_590", system_dynamics, invariant, true, Out_Going_Trans_fromloc_590));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_591

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_591;

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

t = transition::ptr(new transition(222,"null",223,224,guard_polytope,assignment));

Out_Going_Trans_fromloc_591.push_back(t);
l = location::ptr(new location(223, "loc_591", system_dynamics, invariant, true, Out_Going_Trans_fromloc_591));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_592

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_592;

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

t = transition::ptr(new transition(223,"null",224,225,guard_polytope,assignment));

Out_Going_Trans_fromloc_592.push_back(t);
l = location::ptr(new location(224, "loc_592", system_dynamics, invariant, true, Out_Going_Trans_fromloc_592));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_593

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_593;

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

t = transition::ptr(new transition(224,"null",225,226,guard_polytope,assignment));

Out_Going_Trans_fromloc_593.push_back(t);
l = location::ptr(new location(225, "loc_593", system_dynamics, invariant, true, Out_Going_Trans_fromloc_593));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_594

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_594;

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

t = transition::ptr(new transition(225,"null",226,227,guard_polytope,assignment));

Out_Going_Trans_fromloc_594.push_back(t);
l = location::ptr(new location(226, "loc_594", system_dynamics, invariant, true, Out_Going_Trans_fromloc_594));
Hybrid_Automata.addLocation(l);


// The mode name is  loc_595

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
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
invariantBoundValue[0] = -20.0;
invariantBoundValue[1] = 21.0;
invariantBoundValue[2] = -23.0;
invariantBoundValue[3] = 24.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_595;

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

t = transition::ptr(new transition(226,"null",227,210,guard_polytope,assignment));

Out_Going_Trans_fromloc_595.push_back(t);
l = location::ptr(new location(227, "loc_595", system_dynamics, invariant, true, Out_Going_Trans_fromloc_595));
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
invariantBoundValue[2] = -24.0;
invariantBoundValue[3] = 25.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc_612;

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

t = transition::ptr(new transition(227,"null",228,219,guard_polytope,assignment));

Out_Going_Trans_fromloc_612.push_back(t);
l = location::ptr(new location(228, "loc_612", system_dynamics, invariant, true, Out_Going_Trans_fromloc_612));

Hybrid_Automata.addInitialLocation(l);
Hybrid_Automata.addLocation(l);

}

