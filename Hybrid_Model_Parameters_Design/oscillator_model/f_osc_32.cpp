// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/shyam/Downloads/Benchmarks/FlatFilteredOscillator/f_osc_32.xml
// Command Line arguments: -tool xspeed "" -verbose -output /home/shyam/Downloads/Benchmarks/FlatFilteredOscillator/f_osc_32.cpp -input /home/shyam/Downloads/Benchmarks/FlatFilteredOscillator/f_osc_32.xml /home/shyam/Downloads/Benchmarks/FlatFilteredOscillator/f_osc_32.cfg


#include "f_osc_32.h"
void setf_osc_32model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc2

row = 35;
col = 35;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -2.0;
Amatrix(1 , 1) = -1.0;
Amatrix(2 , 0) = 5.0;
Amatrix(2 , 2) = -5.0;
Amatrix(3 , 2) = 5.0;
Amatrix(3 , 3) = -5.0;
Amatrix(4 , 3) = 5.0;
Amatrix(4 , 4) = -5.0;
Amatrix(5 , 4) = 5.0;
Amatrix(5 , 5) = -5.0;
Amatrix(6 , 5) = 5.0;
Amatrix(6 , 6) = -5.0;
Amatrix(7 , 6) = 5.0;
Amatrix(7 , 7) = -5.0;
Amatrix(8 , 7) = 5.0;
Amatrix(8 , 8) = -5.0;
Amatrix(9 , 8) = 5.0;
Amatrix(9 , 9) = -5.0;
Amatrix(10 , 9) = 5.0;
Amatrix(10 , 10) = -5.0;
Amatrix(11 , 10) = 5.0;
Amatrix(11 , 11) = -5.0;
Amatrix(12 , 11) = 5.0;
Amatrix(12 , 12) = -5.0;
Amatrix(13 , 12) = 5.0;
Amatrix(13 , 13) = -5.0;
Amatrix(14 , 13) = 5.0;
Amatrix(14 , 14) = -5.0;
Amatrix(15 , 14) = 5.0;
Amatrix(15 , 15) = -5.0;
Amatrix(16 , 15) = 5.0;
Amatrix(16 , 16) = -5.0;
Amatrix(17 , 16) = 5.0;
Amatrix(17 , 17) = -5.0;
Amatrix(18 , 17) = 5.0;
Amatrix(18 , 18) = -5.0;
Amatrix(19 , 18) = 5.0;
Amatrix(19 , 19) = -5.0;
Amatrix(20 , 19) = 5.0;
Amatrix(20 , 20) = -5.0;
Amatrix(21 , 20) = 5.0;
Amatrix(21 , 21) = -5.0;
Amatrix(22 , 21) = 5.0;
Amatrix(22 , 22) = -5.0;
Amatrix(23 , 22) = 5.0;
Amatrix(23 , 23) = -5.0;
Amatrix(24 , 23) = 5.0;
Amatrix(24 , 24) = -5.0;
Amatrix(25 , 24) = 5.0;
Amatrix(25 , 25) = -5.0;
Amatrix(26 , 25) = 5.0;
Amatrix(26 , 26) = -5.0;
Amatrix(27 , 26) = 5.0;
Amatrix(27 , 27) = -5.0;
Amatrix(28 , 27) = 5.0;
Amatrix(28 , 28) = -5.0;
Amatrix(29 , 28) = 5.0;
Amatrix(29 , 29) = -5.0;
Amatrix(30 , 29) = 5.0;
Amatrix(30 , 30) = -5.0;
Amatrix(31 , 30) = 5.0;
Amatrix(31 , 31) = -5.0;
Amatrix(32 , 31) = 5.0;
Amatrix(32 , 32) = -5.0;
Amatrix(33 , 32) = 5.0;
Amatrix(33 , 33) = -5.0;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = 1.4;
C[1] = -0.7;
C[34] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 35;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= 1.0;
invariantConstraintsMatrix(1,0)= -0.714286;
invariantConstraintsMatrix(1,1)= -1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc2;

// The transition label is null

// Original guard: x = 0 & 0.714286 * x + y >= 0

row = 3;
col = 35;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,0) = -0.714286;
guardConstraintsMatrix(2,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 35;
col = 35;
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
R(11,11) =  1.0;
R(12,12) =  1.0;
R(13,13) =  1.0;
R(14,14) =  1.0;
R(15,15) =  1.0;
R(16,16) =  1.0;
R(17,17) =  1.0;
R(18,18) =  1.0;
R(19,19) =  1.0;
R(20,20) =  1.0;
R(21,21) =  1.0;
R(22,22) =  1.0;
R(23,23) =  1.0;
R(24,24) =  1.0;
R(25,25) =  1.0;
R(26,26) =  1.0;
R(27,27) =  1.0;
R(28,28) =  1.0;
R(29,29) =  1.0;
R(30,30) =  1.0;
R(31,31) =  1.0;
R(32,32) =  1.0;
R(33,33) =  1.0;
R(34,34) =  1.0;
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(1,"null",1,3,guard_polytope,assignment));

Out_Going_Trans_fromloc2.push_back(t);
l = location::ptr(new location(1, "loc2", system_dynamics, invariant, true, Out_Going_Trans_fromloc2));
Hybrid_Automata.addLocation(l);


// The mode name is  loc1

row = 35;
col = 35;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -2.0;
Amatrix(1 , 1) = -1.0;
Amatrix(2 , 0) = 5.0;
Amatrix(2 , 2) = -5.0;
Amatrix(3 , 2) = 5.0;
Amatrix(3 , 3) = -5.0;
Amatrix(4 , 3) = 5.0;
Amatrix(4 , 4) = -5.0;
Amatrix(5 , 4) = 5.0;
Amatrix(5 , 5) = -5.0;
Amatrix(6 , 5) = 5.0;
Amatrix(6 , 6) = -5.0;
Amatrix(7 , 6) = 5.0;
Amatrix(7 , 7) = -5.0;
Amatrix(8 , 7) = 5.0;
Amatrix(8 , 8) = -5.0;
Amatrix(9 , 8) = 5.0;
Amatrix(9 , 9) = -5.0;
Amatrix(10 , 9) = 5.0;
Amatrix(10 , 10) = -5.0;
Amatrix(11 , 10) = 5.0;
Amatrix(11 , 11) = -5.0;
Amatrix(12 , 11) = 5.0;
Amatrix(12 , 12) = -5.0;
Amatrix(13 , 12) = 5.0;
Amatrix(13 , 13) = -5.0;
Amatrix(14 , 13) = 5.0;
Amatrix(14 , 14) = -5.0;
Amatrix(15 , 14) = 5.0;
Amatrix(15 , 15) = -5.0;
Amatrix(16 , 15) = 5.0;
Amatrix(16 , 16) = -5.0;
Amatrix(17 , 16) = 5.0;
Amatrix(17 , 17) = -5.0;
Amatrix(18 , 17) = 5.0;
Amatrix(18 , 18) = -5.0;
Amatrix(19 , 18) = 5.0;
Amatrix(19 , 19) = -5.0;
Amatrix(20 , 19) = 5.0;
Amatrix(20 , 20) = -5.0;
Amatrix(21 , 20) = 5.0;
Amatrix(21 , 21) = -5.0;
Amatrix(22 , 21) = 5.0;
Amatrix(22 , 22) = -5.0;
Amatrix(23 , 22) = 5.0;
Amatrix(23 , 23) = -5.0;
Amatrix(24 , 23) = 5.0;
Amatrix(24 , 24) = -5.0;
Amatrix(25 , 24) = 5.0;
Amatrix(25 , 25) = -5.0;
Amatrix(26 , 25) = 5.0;
Amatrix(26 , 26) = -5.0;
Amatrix(27 , 26) = 5.0;
Amatrix(27 , 27) = -5.0;
Amatrix(28 , 27) = 5.0;
Amatrix(28 , 28) = -5.0;
Amatrix(29 , 28) = 5.0;
Amatrix(29 , 29) = -5.0;
Amatrix(30 , 29) = 5.0;
Amatrix(30 , 30) = -5.0;
Amatrix(31 , 30) = 5.0;
Amatrix(31 , 31) = -5.0;
Amatrix(32 , 31) = 5.0;
Amatrix(32 , 32) = -5.0;
Amatrix(33 , 32) = 5.0;
Amatrix(33 , 33) = -5.0;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = -1.4;
C[1] = 0.7;
C[34] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 35;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= 1.0;
invariantConstraintsMatrix(1,0)= 0.714286;
invariantConstraintsMatrix(1,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc1;

// The transition label is null

// Original guard: y + 0.714286 * x = 0 & x <= 0

row = 3;
col = 35;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -0.714286;
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,0) = 0.714286;
guardConstraintsMatrix(1,1) = 1.0;
guardConstraintsMatrix(2,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 35;
col = 35;
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
R(11,11) =  1.0;
R(12,12) =  1.0;
R(13,13) =  1.0;
R(14,14) =  1.0;
R(15,15) =  1.0;
R(16,16) =  1.0;
R(17,17) =  1.0;
R(18,18) =  1.0;
R(19,19) =  1.0;
R(20,20) =  1.0;
R(21,21) =  1.0;
R(22,22) =  1.0;
R(23,23) =  1.0;
R(24,24) =  1.0;
R(25,25) =  1.0;
R(26,26) =  1.0;
R(27,27) =  1.0;
R(28,28) =  1.0;
R(29,29) =  1.0;
R(30,30) =  1.0;
R(31,31) =  1.0;
R(32,32) =  1.0;
R(33,33) =  1.0;
R(34,34) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(2,"null",2,1,guard_polytope,assignment));

Out_Going_Trans_fromloc1.push_back(t);
l = location::ptr(new location(2, "loc1", system_dynamics, invariant, true, Out_Going_Trans_fromloc1));
Hybrid_Automata.addLocation(l);


// The mode name is  loc3

row = 35;
col = 35;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -2.0;
Amatrix(1 , 1) = -1.0;
Amatrix(2 , 0) = 5.0;
Amatrix(2 , 2) = -5.0;
Amatrix(3 , 2) = 5.0;
Amatrix(3 , 3) = -5.0;
Amatrix(4 , 3) = 5.0;
Amatrix(4 , 4) = -5.0;
Amatrix(5 , 4) = 5.0;
Amatrix(5 , 5) = -5.0;
Amatrix(6 , 5) = 5.0;
Amatrix(6 , 6) = -5.0;
Amatrix(7 , 6) = 5.0;
Amatrix(7 , 7) = -5.0;
Amatrix(8 , 7) = 5.0;
Amatrix(8 , 8) = -5.0;
Amatrix(9 , 8) = 5.0;
Amatrix(9 , 9) = -5.0;
Amatrix(10 , 9) = 5.0;
Amatrix(10 , 10) = -5.0;
Amatrix(11 , 10) = 5.0;
Amatrix(11 , 11) = -5.0;
Amatrix(12 , 11) = 5.0;
Amatrix(12 , 12) = -5.0;
Amatrix(13 , 12) = 5.0;
Amatrix(13 , 13) = -5.0;
Amatrix(14 , 13) = 5.0;
Amatrix(14 , 14) = -5.0;
Amatrix(15 , 14) = 5.0;
Amatrix(15 , 15) = -5.0;
Amatrix(16 , 15) = 5.0;
Amatrix(16 , 16) = -5.0;
Amatrix(17 , 16) = 5.0;
Amatrix(17 , 17) = -5.0;
Amatrix(18 , 17) = 5.0;
Amatrix(18 , 18) = -5.0;
Amatrix(19 , 18) = 5.0;
Amatrix(19 , 19) = -5.0;
Amatrix(20 , 19) = 5.0;
Amatrix(20 , 20) = -5.0;
Amatrix(21 , 20) = 5.0;
Amatrix(21 , 21) = -5.0;
Amatrix(22 , 21) = 5.0;
Amatrix(22 , 22) = -5.0;
Amatrix(23 , 22) = 5.0;
Amatrix(23 , 23) = -5.0;
Amatrix(24 , 23) = 5.0;
Amatrix(24 , 24) = -5.0;
Amatrix(25 , 24) = 5.0;
Amatrix(25 , 25) = -5.0;
Amatrix(26 , 25) = 5.0;
Amatrix(26 , 26) = -5.0;
Amatrix(27 , 26) = 5.0;
Amatrix(27 , 27) = -5.0;
Amatrix(28 , 27) = 5.0;
Amatrix(28 , 28) = -5.0;
Amatrix(29 , 28) = 5.0;
Amatrix(29 , 29) = -5.0;
Amatrix(30 , 29) = 5.0;
Amatrix(30 , 30) = -5.0;
Amatrix(31 , 30) = 5.0;
Amatrix(31 , 31) = -5.0;
Amatrix(32 , 31) = 5.0;
Amatrix(32 , 32) = -5.0;
Amatrix(33 , 32) = 5.0;
Amatrix(33 , 33) = -5.0;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = 1.4;
C[1] = -0.7;
C[34] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 35;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= -0.714286;
invariantConstraintsMatrix(1,1)= -1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc3;

// The transition label is null

// Original guard: y + 0.714286 * x = 0 & x >= 0

row = 3;
col = 35;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -0.714286;
guardConstraintsMatrix(0,1) = -1.0;
guardConstraintsMatrix(1,0) = 0.714286;
guardConstraintsMatrix(1,1) = 1.0;
guardConstraintsMatrix(2,0) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 35;
col = 35;
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
R(11,11) =  1.0;
R(12,12) =  1.0;
R(13,13) =  1.0;
R(14,14) =  1.0;
R(15,15) =  1.0;
R(16,16) =  1.0;
R(17,17) =  1.0;
R(18,18) =  1.0;
R(19,19) =  1.0;
R(20,20) =  1.0;
R(21,21) =  1.0;
R(22,22) =  1.0;
R(23,23) =  1.0;
R(24,24) =  1.0;
R(25,25) =  1.0;
R(26,26) =  1.0;
R(27,27) =  1.0;
R(28,28) =  1.0;
R(29,29) =  1.0;
R(30,30) =  1.0;
R(31,31) =  1.0;
R(32,32) =  1.0;
R(33,33) =  1.0;
R(34,34) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(3,"null",3,4,guard_polytope,assignment));

Out_Going_Trans_fromloc3.push_back(t);
l = location::ptr(new location(3, "loc3", system_dynamics, invariant, true, Out_Going_Trans_fromloc3));

Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);


// The mode name is  loc4

row = 35;
col = 35;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -2.0;
Amatrix(1 , 1) = -1.0;
Amatrix(2 , 0) = 5.0;
Amatrix(2 , 2) = -5.0;
Amatrix(3 , 2) = 5.0;
Amatrix(3 , 3) = -5.0;
Amatrix(4 , 3) = 5.0;
Amatrix(4 , 4) = -5.0;
Amatrix(5 , 4) = 5.0;
Amatrix(5 , 5) = -5.0;
Amatrix(6 , 5) = 5.0;
Amatrix(6 , 6) = -5.0;
Amatrix(7 , 6) = 5.0;
Amatrix(7 , 7) = -5.0;
Amatrix(8 , 7) = 5.0;
Amatrix(8 , 8) = -5.0;
Amatrix(9 , 8) = 5.0;
Amatrix(9 , 9) = -5.0;
Amatrix(10 , 9) = 5.0;
Amatrix(10 , 10) = -5.0;
Amatrix(11 , 10) = 5.0;
Amatrix(11 , 11) = -5.0;
Amatrix(12 , 11) = 5.0;
Amatrix(12 , 12) = -5.0;
Amatrix(13 , 12) = 5.0;
Amatrix(13 , 13) = -5.0;
Amatrix(14 , 13) = 5.0;
Amatrix(14 , 14) = -5.0;
Amatrix(15 , 14) = 5.0;
Amatrix(15 , 15) = -5.0;
Amatrix(16 , 15) = 5.0;
Amatrix(16 , 16) = -5.0;
Amatrix(17 , 16) = 5.0;
Amatrix(17 , 17) = -5.0;
Amatrix(18 , 17) = 5.0;
Amatrix(18 , 18) = -5.0;
Amatrix(19 , 18) = 5.0;
Amatrix(19 , 19) = -5.0;
Amatrix(20 , 19) = 5.0;
Amatrix(20 , 20) = -5.0;
Amatrix(21 , 20) = 5.0;
Amatrix(21 , 21) = -5.0;
Amatrix(22 , 21) = 5.0;
Amatrix(22 , 22) = -5.0;
Amatrix(23 , 22) = 5.0;
Amatrix(23 , 23) = -5.0;
Amatrix(24 , 23) = 5.0;
Amatrix(24 , 24) = -5.0;
Amatrix(25 , 24) = 5.0;
Amatrix(25 , 25) = -5.0;
Amatrix(26 , 25) = 5.0;
Amatrix(26 , 26) = -5.0;
Amatrix(27 , 26) = 5.0;
Amatrix(27 , 27) = -5.0;
Amatrix(28 , 27) = 5.0;
Amatrix(28 , 28) = -5.0;
Amatrix(29 , 28) = 5.0;
Amatrix(29 , 29) = -5.0;
Amatrix(30 , 29) = 5.0;
Amatrix(30 , 30) = -5.0;
Amatrix(31 , 30) = 5.0;
Amatrix(31 , 31) = -5.0;
Amatrix(32 , 31) = 5.0;
Amatrix(32 , 32) = -5.0;
Amatrix(33 , 32) = 5.0;
Amatrix(33 , 33) = -5.0;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = -1.4;
C[1] = 0.7;
C[34] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 35;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 0.714286;
invariantConstraintsMatrix(1,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc4;

// The transition label is null

// Original guard: x = 0 & 0.714286 * x + y <= 0

row = 3;
col = 35;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,0) = 0.714286;
guardConstraintsMatrix(2,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 35;
col = 35;
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
R(11,11) =  1.0;
R(12,12) =  1.0;
R(13,13) =  1.0;
R(14,14) =  1.0;
R(15,15) =  1.0;
R(16,16) =  1.0;
R(17,17) =  1.0;
R(18,18) =  1.0;
R(19,19) =  1.0;
R(20,20) =  1.0;
R(21,21) =  1.0;
R(22,22) =  1.0;
R(23,23) =  1.0;
R(24,24) =  1.0;
R(25,25) =  1.0;
R(26,26) =  1.0;
R(27,27) =  1.0;
R(28,28) =  1.0;
R(29,29) =  1.0;
R(30,30) =  1.0;
R(31,31) =  1.0;
R(32,32) =  1.0;
R(33,33) =  1.0;
R(34,34) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(4,"null",4,2,guard_polytope,assignment));

Out_Going_Trans_fromloc4.push_back(t);
l = location::ptr(new location(4, "loc4", system_dynamics, invariant, true, Out_Going_Trans_fromloc4));
Hybrid_Automata.addLocation(l);


row = 70;
col = 35;
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
ConstraintsMatrixI(22 , 11) = 1;
ConstraintsMatrixI(23 , 11) = -1;
ConstraintsMatrixI(24 , 12) = 1;
ConstraintsMatrixI(25 , 12) = -1;
ConstraintsMatrixI(26 , 13) = 1;
ConstraintsMatrixI(27 , 13) = -1;
ConstraintsMatrixI(28 , 14) = 1;
ConstraintsMatrixI(29 , 14) = -1;
ConstraintsMatrixI(30 , 15) = 1;
ConstraintsMatrixI(31 , 15) = -1;
ConstraintsMatrixI(32 , 16) = 1;
ConstraintsMatrixI(33 , 16) = -1;
ConstraintsMatrixI(34 , 17) = 1;
ConstraintsMatrixI(35 , 17) = -1;
ConstraintsMatrixI(36 , 18) = 1;
ConstraintsMatrixI(37 , 18) = -1;
ConstraintsMatrixI(38 , 19) = 1;
ConstraintsMatrixI(39 , 19) = -1;
ConstraintsMatrixI(40 , 20) = 1;
ConstraintsMatrixI(41 , 20) = -1;
ConstraintsMatrixI(42 , 21) = 1;
ConstraintsMatrixI(43 , 21) = -1;
ConstraintsMatrixI(44 , 22) = 1;
ConstraintsMatrixI(45 , 22) = -1;
ConstraintsMatrixI(46 , 23) = 1;
ConstraintsMatrixI(47 , 23) = -1;
ConstraintsMatrixI(48 , 24) = 1;
ConstraintsMatrixI(49 , 24) = -1;
ConstraintsMatrixI(50 , 25) = 1;
ConstraintsMatrixI(51 , 25) = -1;
ConstraintsMatrixI(52 , 26) = 1;
ConstraintsMatrixI(53 , 26) = -1;
ConstraintsMatrixI(54 , 27) = 1;
ConstraintsMatrixI(55 , 27) = -1;
ConstraintsMatrixI(56 , 28) = 1;
ConstraintsMatrixI(57 , 28) = -1;
ConstraintsMatrixI(58 , 29) = 1;
ConstraintsMatrixI(59 , 29) = -1;
ConstraintsMatrixI(60 , 30) = 1;
ConstraintsMatrixI(61 , 30) = -1;
ConstraintsMatrixI(62 , 31) = 1;
ConstraintsMatrixI(63 , 31) = -1;
ConstraintsMatrixI(64 , 32) = 1;
ConstraintsMatrixI(65 , 32) = -1;
ConstraintsMatrixI(66 , 33) = 1;
ConstraintsMatrixI(67 , 33) = -1;
ConstraintsMatrixI(68 , 34) = 1;
ConstraintsMatrixI(69 , 34) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=0.3;
boundValueI[1]=-0.2;
boundValueI[2]=0.1;
boundValueI[3]=0.1;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =3;

symbolic_states::ptr S0;

initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

init_state_list.push_back(I0);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("x",0);
Hybrid_Automata.insert_to_map("y",1);
Hybrid_Automata.insert_to_map("f8af4ax1",2);
Hybrid_Automata.insert_to_map("f8af4ax2",3);
Hybrid_Automata.insert_to_map("f8af4ax3",4);
Hybrid_Automata.insert_to_map("f8ax1",5);
Hybrid_Automata.insert_to_map("f8af4bx1",6);
Hybrid_Automata.insert_to_map("f8af4bx2",7);
Hybrid_Automata.insert_to_map("f8af4bx3",8);
Hybrid_Automata.insert_to_map("x1",9);
Hybrid_Automata.insert_to_map("f8bf4ax1",10);
Hybrid_Automata.insert_to_map("f8bf4ax2",11);
Hybrid_Automata.insert_to_map("f8bf4ax3",12);
Hybrid_Automata.insert_to_map("f8bx1",13);
Hybrid_Automata.insert_to_map("f8bf4bx1",14);
Hybrid_Automata.insert_to_map("f8bf4bx2",15);
Hybrid_Automata.insert_to_map("f8bf4bx3",16);
Hybrid_Automata.insert_to_map("x2",17);
Hybrid_Automata.insert_to_map("f8cf4ax1",18);
Hybrid_Automata.insert_to_map("f8cf4ax2",19);
Hybrid_Automata.insert_to_map("f8cf4ax3",20);
Hybrid_Automata.insert_to_map("f8cx1",21);
Hybrid_Automata.insert_to_map("f8cf4bx1",22);
Hybrid_Automata.insert_to_map("f8cf4bx2",23);
Hybrid_Automata.insert_to_map("f8cf4bx3",24);
Hybrid_Automata.insert_to_map("x3",25);
Hybrid_Automata.insert_to_map("f8df4ax1",26);
Hybrid_Automata.insert_to_map("f8df4ax2",27);
Hybrid_Automata.insert_to_map("f8df4ax3",28);
Hybrid_Automata.insert_to_map("f8dx1",29);
Hybrid_Automata.insert_to_map("f8df4bx1",30);
Hybrid_Automata.insert_to_map("f8df4bx2",31);
Hybrid_Automata.insert_to_map("f8df4bx3",32);
Hybrid_Automata.insert_to_map("z",33);
Hybrid_Automata.insert_to_map("osc_w_32th_order_1_t",34);

}
