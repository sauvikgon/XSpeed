// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/03/bm03.xml
// Command Line arguments: -tool xspeed "-time_dynamics false" -verbose -output /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/03/bm03.cpp -input /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/03/bm03.xml /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/03/bm03.cfg


#include "bm03.h"
void set_bm03_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63, forbid_polytope;
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

// The mode name is  M1Part1

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[2] = 45.0;
invariantBoundValue[3] = 45.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part1;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 45 & 1 * nu1 <= 45 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(1,"dummy",1,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part1.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 0 & 1 * nu1 <= 90 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(2,"dummy",1,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part1.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 45 & 1 * nu1 <= 90 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(3,"dummy",1,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part1.push_back(t);
l = location::ptr(new location(1, "M1Part1", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part1));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part2

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = -45.0;
invariantBoundValue[2] = 45.0;
invariantBoundValue[3] = 90.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part2;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 90 & 1 * nu1 <= 45 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(4,"dummy",2,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part2.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 45 & 1 * nu1 <= 90 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(5,"dummy",2,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part2.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 90 & 1 * nu1 <= 90 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(6,"dummy",2,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part2.push_back(t);
l = location::ptr(new location(2, "M1Part2", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part2));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part3

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = -90.0;
invariantBoundValue[2] = 45.0;
invariantBoundValue[3] = 135.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part3;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 135 & 1 * nu1 <= 45 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(7,"dummy",3,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part3.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 90 & 1 * nu1 <= 90 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(8,"dummy",3,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part3.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 135 & 1 * nu1 <= 90 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(9,"dummy",3,12,guard_polytope,assignment));

Out_Going_Trans_fromM1Part3.push_back(t);
l = location::ptr(new location(3, "M1Part3", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part3));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part4

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = -135.0;
invariantBoundValue[2] = 45.0;
invariantBoundValue[3] = 180.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part4;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 180 & 1 * nu1 <= 45 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(10,"dummy",4,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part4.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 135 & 1 * nu1 <= 90 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(11,"dummy",4,12,guard_polytope,assignment));

Out_Going_Trans_fromM1Part4.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 180 & 1 * nu1 <= 90 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(12,"dummy",4,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part4.push_back(t);
l = location::ptr(new location(4, "M1Part4", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part4));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part5

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 45.0;
invariantBoundValue[3] = 225.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part5;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 225 & 1 * nu1 <= 45 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(13,"dummy",5,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part5.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 180 & 1 * nu1 <= 90 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(14,"dummy",5,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part5.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 225 & 1 * nu1 <= 90 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(15,"dummy",5,14,guard_polytope,assignment));

Out_Going_Trans_fromM1Part5.push_back(t);
l = location::ptr(new location(5, "M1Part5", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part5));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part6

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = -225.0;
invariantBoundValue[2] = 45.0;
invariantBoundValue[3] = 270.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part6;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 270 & 1 * nu1 <= 45 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(16,"dummy",6,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 225 & 1 * nu1 <= 90 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(17,"dummy",6,14,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 270 & 1 * nu1 <= 90 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(18,"dummy",6,15,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
l = location::ptr(new location(6, "M1Part6", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part6));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part7

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = -270.0;
invariantBoundValue[2] = 45.0;
invariantBoundValue[3] = 315.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part7;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 315 & 1 * nu1 <= 45 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(19,"dummy",7,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part7.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 270 & 1 * nu1 <= 90 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(20,"dummy",7,15,guard_polytope,assignment));

Out_Going_Trans_fromM1Part7.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 315 & 1 * nu1 <= 90 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(21,"dummy",7,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part7.push_back(t);
l = location::ptr(new location(7, "M1Part7", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part7));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part8

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = -315.0;
invariantBoundValue[2] = 45.0;
invariantBoundValue[3] = 360.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part8;

// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 315 & 1 * nu1 <= 90 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(22,"dummy",8,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 360 & 1 * nu1 <= 90 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(23,"dummy",8,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 360 & 1 * nu1 <= 90 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(24,"dummy",8,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 45 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(25,"dummy",8,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 405 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(26,"dummy",8,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 405 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(27,"dummy",8,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
l = location::ptr(new location(8, "M1Part8", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part8));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part9

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -45.0;
invariantBoundValue[2] = 90.0;
invariantBoundValue[3] = 45.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part9;

// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 45 & 1 * nu1 <= 90 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(28,"dummy",9,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 0 & 1 * nu1 <= 135 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(29,"dummy",9,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 45 & 1 * nu1 <= 135 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(30,"dummy",9,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
l = location::ptr(new location(9, "M1Part9", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part9));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part10

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -45.0;
invariantBoundValue[1] = -45.0;
invariantBoundValue[2] = 90.0;
invariantBoundValue[3] = 90.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part10;

// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 90 & 1 * nu1 <= 90 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(31,"dummy",10,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 45 & 1 * nu1 <= 135 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(32,"dummy",10,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 90 & 1 * nu1 <= 135 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(33,"dummy",10,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
l = location::ptr(new location(10, "M1Part10", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part10));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part11

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -45.0;
invariantBoundValue[1] = -90.0;
invariantBoundValue[2] = 90.0;
invariantBoundValue[3] = 135.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part11;

// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 135 & 1 * nu1 <= 90 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(34,"dummy",11,12,guard_polytope,assignment));

Out_Going_Trans_fromM1Part11.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 90 & 1 * nu1 <= 135 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(35,"dummy",11,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part11.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 135 & 1 * nu1 <= 135 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(36,"dummy",11,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part11.push_back(t);
l = location::ptr(new location(11, "M1Part11", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part11));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part12

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -45.0;
invariantBoundValue[1] = -135.0;
invariantBoundValue[2] = 90.0;
invariantBoundValue[3] = 180.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part12;

// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 180 & 1 * nu1 <= 90 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(37,"dummy",12,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 135 & 1 * nu1 <= 135 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(38,"dummy",12,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 180 & 1 * nu1 <= 135 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(39,"dummy",12,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
l = location::ptr(new location(12, "M1Part12", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part12));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part13

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -45.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 90.0;
invariantBoundValue[3] = 225.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part13;

// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 225 & 1 * nu1 <= 90 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(40,"dummy",13,14,guard_polytope,assignment));

Out_Going_Trans_fromM1Part13.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 180 & 1 * nu1 <= 135 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(41,"dummy",13,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part13.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 225 & 1 * nu1 <= 135 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(42,"dummy",13,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part13.push_back(t);
l = location::ptr(new location(13, "M1Part13", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part13));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part14

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -45.0;
invariantBoundValue[1] = -225.0;
invariantBoundValue[2] = 90.0;
invariantBoundValue[3] = 270.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part14;

// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 270 & 1 * nu1 <= 90 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(43,"dummy",14,15,guard_polytope,assignment));

Out_Going_Trans_fromM1Part14.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 225 & 1 * nu1 <= 135 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(44,"dummy",14,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part14.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 270 & 1 * nu1 <= 135 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(45,"dummy",14,23,guard_polytope,assignment));

Out_Going_Trans_fromM1Part14.push_back(t);
l = location::ptr(new location(14, "M1Part14", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part14));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part15

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -45.0;
invariantBoundValue[1] = -270.0;
invariantBoundValue[2] = 90.0;
invariantBoundValue[3] = 315.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part15;

// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 315 & 1 * nu1 <= 90 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(46,"dummy",15,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 270 & 1 * nu1 <= 135 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(47,"dummy",15,23,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 315 & 1 * nu1 <= 135 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(48,"dummy",15,24,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
l = location::ptr(new location(15, "M1Part15", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part15));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part16

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -45.0;
invariantBoundValue[1] = -315.0;
invariantBoundValue[2] = 90.0;
invariantBoundValue[3] = 360.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part16;

// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 315 & 1 * nu1 <= 135 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(49,"dummy",16,24,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 360 & 1 * nu1 <= 135 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(50,"dummy",16,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 360 & 1 * nu1 <= 135 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(51,"dummy",16,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 360 & 1 * nu1 <= 90 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(52,"dummy",16,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 45 & nu2 >= 360 & 1 * nu1 <= 90 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -45.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(53,"dummy",16,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
l = location::ptr(new location(16, "M1Part16", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part16));
Hybrid_Automata.addLocation(l);

bm03_module1(Hybrid_Automata,init_state_list,reach_parameters);
bm03_module2(Hybrid_Automata,init_state_list,reach_parameters);
bm03_module3(Hybrid_Automata,init_state_list,reach_parameters);
bm03_module4(Hybrid_Automata,init_state_list,reach_parameters);

row = 6;
col = 3;
ConstraintsMatrixI.resize(row, col);
ConstraintsMatrixI.clear();
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =64;

symbolic_states::ptr S0;

initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

init_state_list.push_back(I0);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I1 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I1->getSystemDimension();

symbolic_states::ptr S1;

initial_state::ptr I1 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I1, S1, transition_id));

init_state_list.push_back(I1);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I2 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I2->getSystemDimension();

symbolic_states::ptr S2;

initial_state::ptr I2 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I2, S2, transition_id));

init_state_list.push_back(I2);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I3 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I3->getSystemDimension();

symbolic_states::ptr S3;

initial_state::ptr I3 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I3, S3, transition_id));

init_state_list.push_back(I3);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I4 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I4->getSystemDimension();

symbolic_states::ptr S4;

initial_state::ptr I4 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I4, S4, transition_id));

init_state_list.push_back(I4);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I5 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I5->getSystemDimension();

symbolic_states::ptr S5;

initial_state::ptr I5 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I5, S5, transition_id));

init_state_list.push_back(I5);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I6 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I6->getSystemDimension();

symbolic_states::ptr S6;

initial_state::ptr I6 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I6, S6, transition_id));

init_state_list.push_back(I6);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I7 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I7->getSystemDimension();

symbolic_states::ptr S7;

initial_state::ptr I7 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I7, S7, transition_id));

init_state_list.push_back(I7);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I8 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I8->getSystemDimension();

symbolic_states::ptr S8;

initial_state::ptr I8 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I8, S8, transition_id));

init_state_list.push_back(I8);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I9 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I9->getSystemDimension();

symbolic_states::ptr S9;

initial_state::ptr I9 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I9, S9, transition_id));

init_state_list.push_back(I9);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I10 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I10->getSystemDimension();

symbolic_states::ptr S10;

initial_state::ptr I10 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I10, S10, transition_id));

init_state_list.push_back(I10);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I11 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I11->getSystemDimension();

symbolic_states::ptr S11;

initial_state::ptr I11 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I11, S11, transition_id));

init_state_list.push_back(I11);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I12 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I12->getSystemDimension();

symbolic_states::ptr S12;

initial_state::ptr I12 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I12, S12, transition_id));

init_state_list.push_back(I12);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I13 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I13->getSystemDimension();

symbolic_states::ptr S13;

initial_state::ptr I13 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I13, S13, transition_id));

init_state_list.push_back(I13);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I14 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I14->getSystemDimension();

symbolic_states::ptr S14;

initial_state::ptr I14 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I14, S14, transition_id));

init_state_list.push_back(I14);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I15 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I15->getSystemDimension();

symbolic_states::ptr S15;

initial_state::ptr I15 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I15, S15, transition_id));

init_state_list.push_back(I15);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I16 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I16->getSystemDimension();

symbolic_states::ptr S16;

initial_state::ptr I16 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I16, S16, transition_id));

init_state_list.push_back(I16);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I17 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I17->getSystemDimension();

symbolic_states::ptr S17;

initial_state::ptr I17 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I17, S17, transition_id));

init_state_list.push_back(I17);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I18 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I18->getSystemDimension();

symbolic_states::ptr S18;

initial_state::ptr I18 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I18, S18, transition_id));

init_state_list.push_back(I18);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I19 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I19->getSystemDimension();

symbolic_states::ptr S19;

initial_state::ptr I19 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I19, S19, transition_id));

init_state_list.push_back(I19);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I20 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I20->getSystemDimension();

symbolic_states::ptr S20;

initial_state::ptr I20 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I20, S20, transition_id));

init_state_list.push_back(I20);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I21 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I21->getSystemDimension();

symbolic_states::ptr S21;

initial_state::ptr I21 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I21, S21, transition_id));

init_state_list.push_back(I21);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I22 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I22->getSystemDimension();

symbolic_states::ptr S22;

initial_state::ptr I22 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I22, S22, transition_id));

init_state_list.push_back(I22);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I23 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I23->getSystemDimension();

symbolic_states::ptr S23;

initial_state::ptr I23 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I23, S23, transition_id));

init_state_list.push_back(I23);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I24 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I24->getSystemDimension();

symbolic_states::ptr S24;

initial_state::ptr I24 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I24, S24, transition_id));

init_state_list.push_back(I24);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I25 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I25->getSystemDimension();

symbolic_states::ptr S25;

initial_state::ptr I25 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I25, S25, transition_id));

init_state_list.push_back(I25);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I26 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I26->getSystemDimension();

symbolic_states::ptr S26;

initial_state::ptr I26 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I26, S26, transition_id));

init_state_list.push_back(I26);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I27 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I27->getSystemDimension();

symbolic_states::ptr S27;

initial_state::ptr I27 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I27, S27, transition_id));

init_state_list.push_back(I27);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I28 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I28->getSystemDimension();

symbolic_states::ptr S28;

initial_state::ptr I28 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I28, S28, transition_id));

init_state_list.push_back(I28);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I29 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I29->getSystemDimension();

symbolic_states::ptr S29;

initial_state::ptr I29 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I29, S29, transition_id));

init_state_list.push_back(I29);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I30 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I30->getSystemDimension();

symbolic_states::ptr S30;

initial_state::ptr I30 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I30, S30, transition_id));

init_state_list.push_back(I30);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I31 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I31->getSystemDimension();

symbolic_states::ptr S31;

initial_state::ptr I31 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I31, S31, transition_id));

init_state_list.push_back(I31);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I32 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I32->getSystemDimension();

symbolic_states::ptr S32;

initial_state::ptr I32 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I32, S32, transition_id));

init_state_list.push_back(I32);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I33 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I33->getSystemDimension();

symbolic_states::ptr S33;

initial_state::ptr I33 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I33, S33, transition_id));

init_state_list.push_back(I33);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I34 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I34->getSystemDimension();

symbolic_states::ptr S34;

initial_state::ptr I34 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I34, S34, transition_id));

init_state_list.push_back(I34);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I35 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I35->getSystemDimension();

symbolic_states::ptr S35;

initial_state::ptr I35 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I35, S35, transition_id));

init_state_list.push_back(I35);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I36 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I36->getSystemDimension();

symbolic_states::ptr S36;

initial_state::ptr I36 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I36, S36, transition_id));

init_state_list.push_back(I36);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I37 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I37->getSystemDimension();

symbolic_states::ptr S37;

initial_state::ptr I37 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I37, S37, transition_id));

init_state_list.push_back(I37);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I38 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I38->getSystemDimension();

symbolic_states::ptr S38;

initial_state::ptr I38 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I38, S38, transition_id));

init_state_list.push_back(I38);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I39 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I39->getSystemDimension();

symbolic_states::ptr S39;

initial_state::ptr I39 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I39, S39, transition_id));

init_state_list.push_back(I39);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I40 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I40->getSystemDimension();

symbolic_states::ptr S40;

initial_state::ptr I40 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I40, S40, transition_id));

init_state_list.push_back(I40);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I41 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I41->getSystemDimension();

symbolic_states::ptr S41;

initial_state::ptr I41 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I41, S41, transition_id));

init_state_list.push_back(I41);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I42 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I42->getSystemDimension();

symbolic_states::ptr S42;

initial_state::ptr I42 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I42, S42, transition_id));

init_state_list.push_back(I42);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I43 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I43->getSystemDimension();

symbolic_states::ptr S43;

initial_state::ptr I43 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I43, S43, transition_id));

init_state_list.push_back(I43);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I44 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I44->getSystemDimension();

symbolic_states::ptr S44;

initial_state::ptr I44 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I44, S44, transition_id));

init_state_list.push_back(I44);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I45 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I45->getSystemDimension();

symbolic_states::ptr S45;

initial_state::ptr I45 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I45, S45, transition_id));

init_state_list.push_back(I45);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I46 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I46->getSystemDimension();

symbolic_states::ptr S46;

initial_state::ptr I46 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I46, S46, transition_id));

init_state_list.push_back(I46);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I47 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I47->getSystemDimension();

symbolic_states::ptr S47;

initial_state::ptr I47 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I47, S47, transition_id));

init_state_list.push_back(I47);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I48 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I48->getSystemDimension();

symbolic_states::ptr S48;

initial_state::ptr I48 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I48, S48, transition_id));

init_state_list.push_back(I48);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I49 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I49->getSystemDimension();

symbolic_states::ptr S49;

initial_state::ptr I49 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I49, S49, transition_id));

init_state_list.push_back(I49);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I50 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I50->getSystemDimension();

symbolic_states::ptr S50;

initial_state::ptr I50 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I50, S50, transition_id));

init_state_list.push_back(I50);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I51 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I51->getSystemDimension();

symbolic_states::ptr S51;

initial_state::ptr I51 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I51, S51, transition_id));

init_state_list.push_back(I51);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I52 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I52->getSystemDimension();

symbolic_states::ptr S52;

initial_state::ptr I52 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I52, S52, transition_id));

init_state_list.push_back(I52);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I53 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I53->getSystemDimension();

symbolic_states::ptr S53;

initial_state::ptr I53 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I53, S53, transition_id));

init_state_list.push_back(I53);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I54 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I54->getSystemDimension();

symbolic_states::ptr S54;

initial_state::ptr I54 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I54, S54, transition_id));

init_state_list.push_back(I54);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I55 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I55->getSystemDimension();

symbolic_states::ptr S55;

initial_state::ptr I55 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I55, S55, transition_id));

init_state_list.push_back(I55);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I56 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I56->getSystemDimension();

symbolic_states::ptr S56;

initial_state::ptr I56 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I56, S56, transition_id));

init_state_list.push_back(I56);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I57 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I57->getSystemDimension();

symbolic_states::ptr S57;

initial_state::ptr I57 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I57, S57, transition_id));

init_state_list.push_back(I57);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I58 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I58->getSystemDimension();

symbolic_states::ptr S58;

initial_state::ptr I58 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I58, S58, transition_id));

init_state_list.push_back(I58);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I59 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I59->getSystemDimension();

symbolic_states::ptr S59;

initial_state::ptr I59 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I59, S59, transition_id));

init_state_list.push_back(I59);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I60 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I60->getSystemDimension();

symbolic_states::ptr S60;

initial_state::ptr I60 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I60, S60, transition_id));

init_state_list.push_back(I60);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I61 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I61->getSystemDimension();

symbolic_states::ptr S61;

initial_state::ptr I61 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I61, S61, transition_id));

init_state_list.push_back(I61);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I62 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I62->getSystemDimension();

symbolic_states::ptr S62;

initial_state::ptr I62 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I62, S62, transition_id));

init_state_list.push_back(I62);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[2]=1;


initial_polytope_I63 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I63->getSystemDimension();

symbolic_states::ptr S63;

initial_state::ptr I63 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I63, S63, transition_id));

init_state_list.push_back(I63);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("nu1",0);
Hybrid_Automata.insert_to_map("nu2",1);
Hybrid_Automata.insert_to_map("t",2);

}

void bm03_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63, forbid_polytope;
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

// The mode name is  M1Part17

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -90.0;
invariantBoundValue[2] = 135.0;
invariantBoundValue[3] = 45.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part17;

// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 45 & 1 * nu1 <= 135 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(54,"dummy",17,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 0 & 1 * nu1 <= 180 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(55,"dummy",17,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 45 & 1 * nu1 <= 180 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(56,"dummy",17,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
l = location::ptr(new location(17, "M1Part17", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part17));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part18

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -90.0;
invariantBoundValue[1] = -45.0;
invariantBoundValue[2] = 135.0;
invariantBoundValue[3] = 90.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part18;

// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 90 & 1 * nu1 <= 135 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(57,"dummy",18,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 45 & 1 * nu1 <= 180 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(58,"dummy",18,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 90 & 1 * nu1 <= 180 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(59,"dummy",18,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
l = location::ptr(new location(18, "M1Part18", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part18));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part19

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -90.0;
invariantBoundValue[1] = -90.0;
invariantBoundValue[2] = 135.0;
invariantBoundValue[3] = 135.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part19;

// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 135 & 1 * nu1 <= 135 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(60,"dummy",19,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 90 & 1 * nu1 <= 180 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(61,"dummy",19,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 135 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(62,"dummy",19,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
l = location::ptr(new location(19, "M1Part19", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part19));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part20

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -90.0;
invariantBoundValue[1] = -135.0;
invariantBoundValue[2] = 135.0;
invariantBoundValue[3] = 180.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part20;

// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 180 & 1 * nu1 <= 135 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(63,"dummy",20,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 135 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(64,"dummy",20,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(65,"dummy",20,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
l = location::ptr(new location(20, "M1Part20", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part20));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part21

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -90.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 135.0;
invariantBoundValue[3] = 225.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part21;

// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 225 & 1 * nu1 <= 135 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(66,"dummy",21,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(67,"dummy",21,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 225 & 1 * nu1 <= 180 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(68,"dummy",21,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
l = location::ptr(new location(21, "M1Part21", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part21));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part22

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -90.0;
invariantBoundValue[1] = -225.0;
invariantBoundValue[2] = 135.0;
invariantBoundValue[3] = 270.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part22;

// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 270 & 1 * nu1 <= 135 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(69,"dummy",22,23,guard_polytope,assignment));

Out_Going_Trans_fromM1Part22.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 225 & 1 * nu1 <= 180 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(70,"dummy",22,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part22.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 270 & 1 * nu1 <= 180 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(71,"dummy",22,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part22.push_back(t);
l = location::ptr(new location(22, "M1Part22", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part22));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part23

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -90.0;
invariantBoundValue[1] = -270.0;
invariantBoundValue[2] = 135.0;
invariantBoundValue[3] = 315.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part23;

// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 315 & 1 * nu1 <= 135 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(72,"dummy",23,24,guard_polytope,assignment));

Out_Going_Trans_fromM1Part23.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 270 & 1 * nu1 <= 180 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(73,"dummy",23,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part23.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 315 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(74,"dummy",23,32,guard_polytope,assignment));

Out_Going_Trans_fromM1Part23.push_back(t);
l = location::ptr(new location(23, "M1Part23", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part23));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part24

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -90.0;
invariantBoundValue[1] = -315.0;
invariantBoundValue[2] = 135.0;
invariantBoundValue[3] = 360.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part24;

// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 315 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(75,"dummy",24,32,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(76,"dummy",24,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(77,"dummy",24,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 360 & 1 * nu1 <= 135 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(78,"dummy",24,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 90 & nu2 >= 360 & 1 * nu1 <= 135 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -90.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(79,"dummy",24,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
l = location::ptr(new location(24, "M1Part24", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part24));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part25

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -135.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 45.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part25;

// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 45 & 1 * nu1 <= 180 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(80,"dummy",25,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 0 & 1 * nu1 <= 225 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(81,"dummy",25,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 45 & 1 * nu1 <= 225 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(82,"dummy",25,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
l = location::ptr(new location(25, "M1Part25", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part25));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part26

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -135.0;
invariantBoundValue[1] = -45.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 90.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part26;

// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 90 & 1 * nu1 <= 180 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(83,"dummy",26,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 45 & 1 * nu1 <= 225 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(84,"dummy",26,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 90 & 1 * nu1 <= 225 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(85,"dummy",26,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
l = location::ptr(new location(26, "M1Part26", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part26));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part27

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -135.0;
invariantBoundValue[1] = -90.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 135.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part27;

// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 135 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(86,"dummy",27,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 90 & 1 * nu1 <= 225 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(87,"dummy",27,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 135 & 1 * nu1 <= 225 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(88,"dummy",27,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
l = location::ptr(new location(27, "M1Part27", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part27));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part28

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -135.0;
invariantBoundValue[1] = -135.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 180.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part28;

// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(89,"dummy",28,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 135 & 1 * nu1 <= 225 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(90,"dummy",28,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 225 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(91,"dummy",28,37,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
l = location::ptr(new location(28, "M1Part28", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part28));
Hybrid_Automata.addLocation(l);

}

void bm03_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63, forbid_polytope;
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

// The mode name is  M1Part29

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -135.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 225.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part29;

// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 225 & 1 * nu1 <= 180 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(92,"dummy",29,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 225 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(93,"dummy",29,37,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 225 & 1 * nu1 <= 225 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(94,"dummy",29,38,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
l = location::ptr(new location(29, "M1Part29", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part29));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part30

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -135.0;
invariantBoundValue[1] = -225.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 270.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part30;

// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 270 & 1 * nu1 <= 180 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(95,"dummy",30,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 225 & 1 * nu1 <= 225 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(96,"dummy",30,38,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 270 & 1 * nu1 <= 225 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(97,"dummy",30,39,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
l = location::ptr(new location(30, "M1Part30", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part30));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part31

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -135.0;
invariantBoundValue[1] = -270.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 315.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part31;

// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 315 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(98,"dummy",31,32,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 270 & 1 * nu1 <= 225 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(99,"dummy",31,39,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 315 & 1 * nu1 <= 225 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(100,"dummy",31,40,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
l = location::ptr(new location(31, "M1Part31", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part31));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part32

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -135.0;
invariantBoundValue[1] = -315.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 360.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part32;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 315 & 1 * nu1 <= 225 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(101,"dummy",32,40,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 225 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(102,"dummy",32,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 225 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(103,"dummy",32,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(104,"dummy",32,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 135 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -135.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(105,"dummy",32,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
l = location::ptr(new location(32, "M1Part32", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part32));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part33

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -180.0;
invariantBoundValue[2] = 225.0;
invariantBoundValue[3] = 45.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part33;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 45 & 1 * nu1 <= 225 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(106,"dummy",33,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 0 & 1 * nu1 <= 270 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(107,"dummy",33,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 45 & 1 * nu1 <= 270 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(108,"dummy",33,42,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
l = location::ptr(new location(33, "M1Part33", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part33));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part34

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -180.0;
invariantBoundValue[1] = -45.0;
invariantBoundValue[2] = 225.0;
invariantBoundValue[3] = 90.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part34;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 90 & 1 * nu1 <= 225 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(109,"dummy",34,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 45 & 1 * nu1 <= 270 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(110,"dummy",34,42,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 90 & 1 * nu1 <= 270 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(111,"dummy",34,43,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
l = location::ptr(new location(34, "M1Part34", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part34));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part35

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -180.0;
invariantBoundValue[1] = -90.0;
invariantBoundValue[2] = 225.0;
invariantBoundValue[3] = 135.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part35;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 135 & 1 * nu1 <= 225 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(112,"dummy",35,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 90 & 1 * nu1 <= 270 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(113,"dummy",35,43,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 135 & 1 * nu1 <= 270 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(114,"dummy",35,44,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
l = location::ptr(new location(35, "M1Part35", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part35));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part36

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -180.0;
invariantBoundValue[1] = -135.0;
invariantBoundValue[2] = 225.0;
invariantBoundValue[3] = 180.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part36;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 225 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(115,"dummy",36,37,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 135 & 1 * nu1 <= 270 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(116,"dummy",36,44,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 180 & 1 * nu1 <= 270 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(117,"dummy",36,45,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
l = location::ptr(new location(36, "M1Part36", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part36));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part37

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -180.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 225.0;
invariantBoundValue[3] = 225.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part37;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 225 & 1 * nu1 <= 225 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(118,"dummy",37,38,guard_polytope,assignment));

Out_Going_Trans_fromM1Part37.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 180 & 1 * nu1 <= 270 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(119,"dummy",37,45,guard_polytope,assignment));

Out_Going_Trans_fromM1Part37.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 225 & 1 * nu1 <= 270 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(120,"dummy",37,46,guard_polytope,assignment));

Out_Going_Trans_fromM1Part37.push_back(t);
l = location::ptr(new location(37, "M1Part37", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part37));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part38

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -180.0;
invariantBoundValue[1] = -225.0;
invariantBoundValue[2] = 225.0;
invariantBoundValue[3] = 270.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part38;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 270 & 1 * nu1 <= 225 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(121,"dummy",38,39,guard_polytope,assignment));

Out_Going_Trans_fromM1Part38.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 225 & 1 * nu1 <= 270 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(122,"dummy",38,46,guard_polytope,assignment));

Out_Going_Trans_fromM1Part38.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 270 & 1 * nu1 <= 270 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(123,"dummy",38,47,guard_polytope,assignment));

Out_Going_Trans_fromM1Part38.push_back(t);
l = location::ptr(new location(38, "M1Part38", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part38));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part39

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -180.0;
invariantBoundValue[1] = -270.0;
invariantBoundValue[2] = 225.0;
invariantBoundValue[3] = 315.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part39;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 315 & 1 * nu1 <= 225 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(124,"dummy",39,40,guard_polytope,assignment));

Out_Going_Trans_fromM1Part39.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 270 & 1 * nu1 <= 270 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(125,"dummy",39,47,guard_polytope,assignment));

Out_Going_Trans_fromM1Part39.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 315 & 1 * nu1 <= 270 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(126,"dummy",39,48,guard_polytope,assignment));

Out_Going_Trans_fromM1Part39.push_back(t);
l = location::ptr(new location(39, "M1Part39", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part39));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part40

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -180.0;
invariantBoundValue[1] = -315.0;
invariantBoundValue[2] = 225.0;
invariantBoundValue[3] = 360.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part40;

// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 315 & 1 * nu1 <= 270 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(127,"dummy",40,48,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 360 & 1 * nu1 <= 270 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(128,"dummy",40,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 360 & 1 * nu1 <= 270 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(129,"dummy",40,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 225 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(130,"dummy",40,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 225 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(131,"dummy",40,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
l = location::ptr(new location(40, "M1Part40", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part40));
Hybrid_Automata.addLocation(l);

}

void bm03_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63, forbid_polytope;
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

// The mode name is  M1Part41

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -225.0;
invariantBoundValue[2] = 270.0;
invariantBoundValue[3] = 45.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part41;

// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 45 & 1 * nu1 <= 270 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(132,"dummy",41,42,guard_polytope,assignment));

Out_Going_Trans_fromM1Part41.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 0 & 1 * nu1 <= 315 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(133,"dummy",41,49,guard_polytope,assignment));

Out_Going_Trans_fromM1Part41.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 45 & 1 * nu1 <= 315 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(134,"dummy",41,50,guard_polytope,assignment));

Out_Going_Trans_fromM1Part41.push_back(t);
l = location::ptr(new location(41, "M1Part41", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part41));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part42

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -225.0;
invariantBoundValue[1] = -45.0;
invariantBoundValue[2] = 270.0;
invariantBoundValue[3] = 90.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part42;

// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 90 & 1 * nu1 <= 270 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(135,"dummy",42,43,guard_polytope,assignment));

Out_Going_Trans_fromM1Part42.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 45 & 1 * nu1 <= 315 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(136,"dummy",42,50,guard_polytope,assignment));

Out_Going_Trans_fromM1Part42.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 90 & 1 * nu1 <= 315 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(137,"dummy",42,51,guard_polytope,assignment));

Out_Going_Trans_fromM1Part42.push_back(t);
l = location::ptr(new location(42, "M1Part42", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part42));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part43

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -225.0;
invariantBoundValue[1] = -90.0;
invariantBoundValue[2] = 270.0;
invariantBoundValue[3] = 135.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part43;

// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 135 & 1 * nu1 <= 270 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(138,"dummy",43,44,guard_polytope,assignment));

Out_Going_Trans_fromM1Part43.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 90 & 1 * nu1 <= 315 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(139,"dummy",43,51,guard_polytope,assignment));

Out_Going_Trans_fromM1Part43.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 135 & 1 * nu1 <= 315 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(140,"dummy",43,52,guard_polytope,assignment));

Out_Going_Trans_fromM1Part43.push_back(t);
l = location::ptr(new location(43, "M1Part43", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part43));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part44

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -225.0;
invariantBoundValue[1] = -135.0;
invariantBoundValue[2] = 270.0;
invariantBoundValue[3] = 180.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part44;

// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 180 & 1 * nu1 <= 270 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(141,"dummy",44,45,guard_polytope,assignment));

Out_Going_Trans_fromM1Part44.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 135 & 1 * nu1 <= 315 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(142,"dummy",44,52,guard_polytope,assignment));

Out_Going_Trans_fromM1Part44.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 180 & 1 * nu1 <= 315 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(143,"dummy",44,53,guard_polytope,assignment));

Out_Going_Trans_fromM1Part44.push_back(t);
l = location::ptr(new location(44, "M1Part44", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part44));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part45

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -225.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 270.0;
invariantBoundValue[3] = 225.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part45;

// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 225 & 1 * nu1 <= 270 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(144,"dummy",45,46,guard_polytope,assignment));

Out_Going_Trans_fromM1Part45.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 180 & 1 * nu1 <= 315 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(145,"dummy",45,53,guard_polytope,assignment));

Out_Going_Trans_fromM1Part45.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 225 & 1 * nu1 <= 315 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(146,"dummy",45,54,guard_polytope,assignment));

Out_Going_Trans_fromM1Part45.push_back(t);
l = location::ptr(new location(45, "M1Part45", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part45));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part46

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -225.0;
invariantBoundValue[1] = -225.0;
invariantBoundValue[2] = 270.0;
invariantBoundValue[3] = 270.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part46;

// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 270 & 1 * nu1 <= 270 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(147,"dummy",46,47,guard_polytope,assignment));

Out_Going_Trans_fromM1Part46.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 225 & 1 * nu1 <= 315 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(148,"dummy",46,54,guard_polytope,assignment));

Out_Going_Trans_fromM1Part46.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 270 & 1 * nu1 <= 315 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(149,"dummy",46,55,guard_polytope,assignment));

Out_Going_Trans_fromM1Part46.push_back(t);
l = location::ptr(new location(46, "M1Part46", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part46));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part47

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -225.0;
invariantBoundValue[1] = -270.0;
invariantBoundValue[2] = 270.0;
invariantBoundValue[3] = 315.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part47;

// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 315 & 1 * nu1 <= 270 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(150,"dummy",47,48,guard_polytope,assignment));

Out_Going_Trans_fromM1Part47.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 270 & 1 * nu1 <= 315 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(151,"dummy",47,55,guard_polytope,assignment));

Out_Going_Trans_fromM1Part47.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 315 & 1 * nu1 <= 315 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(152,"dummy",47,56,guard_polytope,assignment));

Out_Going_Trans_fromM1Part47.push_back(t);
l = location::ptr(new location(47, "M1Part47", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part47));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part48

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -225.0;
invariantBoundValue[1] = -315.0;
invariantBoundValue[2] = 270.0;
invariantBoundValue[3] = 360.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part48;

// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 315 & 1 * nu1 <= 315 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(153,"dummy",48,56,guard_polytope,assignment));

Out_Going_Trans_fromM1Part48.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 360 & 1 * nu1 <= 315 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(154,"dummy",48,49,guard_polytope,assignment));

Out_Going_Trans_fromM1Part48.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 360 & 1 * nu1 <= 315 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(155,"dummy",48,49,guard_polytope,assignment));

Out_Going_Trans_fromM1Part48.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 360 & 1 * nu1 <= 270 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(156,"dummy",48,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part48.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 225 & nu2 >= 360 & 1 * nu1 <= 270 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -225.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(157,"dummy",48,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part48.push_back(t);
l = location::ptr(new location(48, "M1Part48", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part48));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part49

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -270.0;
invariantBoundValue[2] = 315.0;
invariantBoundValue[3] = 45.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part49;

// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 45 & 1 * nu1 <= 315 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(158,"dummy",49,50,guard_polytope,assignment));

Out_Going_Trans_fromM1Part49.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 0 & 1 * nu1 <= 360 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(159,"dummy",49,57,guard_polytope,assignment));

Out_Going_Trans_fromM1Part49.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 45 & 1 * nu1 <= 360 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(160,"dummy",49,58,guard_polytope,assignment));

Out_Going_Trans_fromM1Part49.push_back(t);
l = location::ptr(new location(49, "M1Part49", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part49));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part50

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -270.0;
invariantBoundValue[1] = -45.0;
invariantBoundValue[2] = 315.0;
invariantBoundValue[3] = 90.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part50;

// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 90 & 1 * nu1 <= 315 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(161,"dummy",50,51,guard_polytope,assignment));

Out_Going_Trans_fromM1Part50.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 45 & 1 * nu1 <= 360 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(162,"dummy",50,58,guard_polytope,assignment));

Out_Going_Trans_fromM1Part50.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 90 & 1 * nu1 <= 360 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(163,"dummy",50,59,guard_polytope,assignment));

Out_Going_Trans_fromM1Part50.push_back(t);
l = location::ptr(new location(50, "M1Part50", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part50));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part51

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -270.0;
invariantBoundValue[1] = -90.0;
invariantBoundValue[2] = 315.0;
invariantBoundValue[3] = 135.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part51;

// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 135 & 1 * nu1 <= 315 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(164,"dummy",51,52,guard_polytope,assignment));

Out_Going_Trans_fromM1Part51.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 90 & 1 * nu1 <= 360 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(165,"dummy",51,59,guard_polytope,assignment));

Out_Going_Trans_fromM1Part51.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 135 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(166,"dummy",51,60,guard_polytope,assignment));

Out_Going_Trans_fromM1Part51.push_back(t);
l = location::ptr(new location(51, "M1Part51", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part51));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part52

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -270.0;
invariantBoundValue[1] = -135.0;
invariantBoundValue[2] = 315.0;
invariantBoundValue[3] = 180.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part52;

// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 180 & 1 * nu1 <= 315 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(167,"dummy",52,53,guard_polytope,assignment));

Out_Going_Trans_fromM1Part52.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 135 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(168,"dummy",52,60,guard_polytope,assignment));

Out_Going_Trans_fromM1Part52.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(169,"dummy",52,61,guard_polytope,assignment));

Out_Going_Trans_fromM1Part52.push_back(t);
l = location::ptr(new location(52, "M1Part52", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part52));
Hybrid_Automata.addLocation(l);

}

void bm03_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63, forbid_polytope;
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

// The mode name is  M1Part53

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -270.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 315.0;
invariantBoundValue[3] = 225.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part53;

// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 225 & 1 * nu1 <= 315 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(170,"dummy",53,54,guard_polytope,assignment));

Out_Going_Trans_fromM1Part53.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(171,"dummy",53,61,guard_polytope,assignment));

Out_Going_Trans_fromM1Part53.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 225 & 1 * nu1 <= 360 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(172,"dummy",53,62,guard_polytope,assignment));

Out_Going_Trans_fromM1Part53.push_back(t);
l = location::ptr(new location(53, "M1Part53", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part53));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part54

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -270.0;
invariantBoundValue[1] = -225.0;
invariantBoundValue[2] = 315.0;
invariantBoundValue[3] = 270.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part54;

// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 270 & 1 * nu1 <= 315 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(173,"dummy",54,55,guard_polytope,assignment));

Out_Going_Trans_fromM1Part54.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 225 & 1 * nu1 <= 360 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(174,"dummy",54,62,guard_polytope,assignment));

Out_Going_Trans_fromM1Part54.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 270 & 1 * nu1 <= 360 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(175,"dummy",54,63,guard_polytope,assignment));

Out_Going_Trans_fromM1Part54.push_back(t);
l = location::ptr(new location(54, "M1Part54", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part54));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part55

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -270.0;
invariantBoundValue[1] = -270.0;
invariantBoundValue[2] = 315.0;
invariantBoundValue[3] = 315.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part55;

// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 315 & 1 * nu1 <= 315 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(176,"dummy",55,56,guard_polytope,assignment));

Out_Going_Trans_fromM1Part55.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 270 & 1 * nu1 <= 360 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(177,"dummy",55,63,guard_polytope,assignment));

Out_Going_Trans_fromM1Part55.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 315 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(178,"dummy",55,64,guard_polytope,assignment));

Out_Going_Trans_fromM1Part55.push_back(t);
l = location::ptr(new location(55, "M1Part55", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part55));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part56

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -270.0;
invariantBoundValue[1] = -315.0;
invariantBoundValue[2] = 315.0;
invariantBoundValue[3] = 360.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part56;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 315 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(179,"dummy",56,64,guard_polytope,assignment));

Out_Going_Trans_fromM1Part56.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(180,"dummy",56,57,guard_polytope,assignment));

Out_Going_Trans_fromM1Part56.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(181,"dummy",56,57,guard_polytope,assignment));

Out_Going_Trans_fromM1Part56.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 360 & 1 * nu1 <= 315 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(182,"dummy",56,49,guard_polytope,assignment));

Out_Going_Trans_fromM1Part56.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 270 & nu2 >= 360 & 1 * nu1 <= 315 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -270.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(183,"dummy",56,49,guard_polytope,assignment));

Out_Going_Trans_fromM1Part56.push_back(t);
l = location::ptr(new location(56, "M1Part56", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part56));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part57

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -315.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 45.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part57;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 45 & 1 * nu1 <= 360 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(184,"dummy",57,58,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 45 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(185,"dummy",57,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 405 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(186,"dummy",57,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 405 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(187,"dummy",57,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 45 & 1 * nu1 <= 405 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(188,"dummy",57,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 45 & 1 * nu1 <= 405 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(189,"dummy",57,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
l = location::ptr(new location(57, "M1Part57", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part57));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part58

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -315.0;
invariantBoundValue[1] = -45.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 90.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part58;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 90 & 1 * nu1 <= 360 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(190,"dummy",58,59,guard_polytope,assignment));

Out_Going_Trans_fromM1Part58.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 45 & 1 * nu1 <= 405 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(191,"dummy",58,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part58.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 45 & 1 * nu1 <= 405 & 1 * nu2 <= 90

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -45.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(192,"dummy",58,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part58.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 90 & 1 * nu1 <= 405 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(193,"dummy",58,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part58.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 90 & 1 * nu1 <= 405 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(194,"dummy",58,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part58.push_back(t);
l = location::ptr(new location(58, "M1Part58", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part58));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part59

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -315.0;
invariantBoundValue[1] = -90.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 135.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part59;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 135 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(195,"dummy",59,60,guard_polytope,assignment));

Out_Going_Trans_fromM1Part59.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 90 & 1 * nu1 <= 405 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(196,"dummy",59,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part59.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 90 & 1 * nu1 <= 405 & 1 * nu2 <= 135

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -90.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(197,"dummy",59,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part59.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 135 & 1 * nu1 <= 405 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(198,"dummy",59,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part59.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 135 & 1 * nu1 <= 405 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(199,"dummy",59,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part59.push_back(t);
l = location::ptr(new location(59, "M1Part59", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part59));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part60

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -315.0;
invariantBoundValue[1] = -135.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 180.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part60;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(200,"dummy",60,61,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 135 & 1 * nu1 <= 405 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(201,"dummy",60,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 135 & 1 * nu1 <= 405 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -135.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(202,"dummy",60,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 405 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(203,"dummy",60,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 405 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(204,"dummy",60,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
l = location::ptr(new location(60, "M1Part60", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part60));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part61

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -315.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 225.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part61;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 225 & 1 * nu1 <= 360 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(205,"dummy",61,62,guard_polytope,assignment));

Out_Going_Trans_fromM1Part61.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 405 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(206,"dummy",61,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part61.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 405 & 1 * nu2 <= 225

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -180.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(207,"dummy",61,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part61.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 225 & 1 * nu1 <= 405 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(208,"dummy",61,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part61.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 225 & 1 * nu1 <= 405 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(209,"dummy",61,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part61.push_back(t);
l = location::ptr(new location(61, "M1Part61", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part61));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part62

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -315.0;
invariantBoundValue[1] = -225.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 270.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part62;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 270 & 1 * nu1 <= 360 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(210,"dummy",62,63,guard_polytope,assignment));

Out_Going_Trans_fromM1Part62.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 225 & 1 * nu1 <= 405 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(211,"dummy",62,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part62.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 225 & 1 * nu1 <= 405 & 1 * nu2 <= 270

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -225.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(212,"dummy",62,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part62.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 270 & 1 * nu1 <= 405 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(213,"dummy",62,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part62.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 270 & 1 * nu1 <= 405 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(214,"dummy",62,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part62.push_back(t);
l = location::ptr(new location(62, "M1Part62", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part62));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part63

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -315.0;
invariantBoundValue[1] = -270.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 315.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part63;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 315 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(215,"dummy",63,64,guard_polytope,assignment));

Out_Going_Trans_fromM1Part63.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 270 & 1 * nu1 <= 405 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(216,"dummy",63,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part63.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 270 & 1 * nu1 <= 405 & 1 * nu2 <= 315

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -270.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(217,"dummy",63,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part63.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 315 & 1 * nu1 <= 405 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(218,"dummy",63,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part63.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 315 & 1 * nu1 <= 405 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(219,"dummy",63,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part63.push_back(t);
l = location::ptr(new location(63, "M1Part63", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part63));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part64

row = 3;
col = 3;
system_dynamics.isEmptyMatrixA = true;

col = 2;
Bmatrix.resize(row, col);
Bmatrix.clear();
Bmatrix(0 , 0) = 1.0;
Bmatrix(1 , 1) = 1.0;
system_dynamics.isEmptyMatrixB = false;
system_dynamics.MatrixB = Bmatrix;

C.resize(row );
C.assign(row,0);
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 12;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,1)= -1.0;
invariantConstraintsMatrix(2,0)= 1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -315.0;
invariantBoundValue[1] = -315.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 360.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -20.25711711711712;
boundValueV[1] = 20.25711711711712;
boundValueV[2] = -57.295779520295206;
boundValueV[3] = 57.295779520295206;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part64;

// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(220,"dummy",64,57,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 315 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -315.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(221,"dummy",64,57,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 315 & 1 * nu1 <= 405 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(222,"dummy",64,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 315 & 1 * nu1 <= 405 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -315.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(223,"dummy",64,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 45 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(224,"dummy",64,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 405 & 1 * nu2 <= 45

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(225,"dummy",64,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 405 & 1 * nu2 <= 405

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -360.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(226,"dummy",64,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
l = location::ptr(new location(64, "M1Part64", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part64));

Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);

}

