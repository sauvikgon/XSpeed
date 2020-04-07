// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/05/bm05.xml
// Command Line arguments: -tool xspeed "-time_dynamics false" -verbose -output /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/05/bm05.cpp -input /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/05/bm05.xml /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/05/bm05.cfg


#include "bm05.h"
void set_bm05_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63,initial_polytope_I64,initial_polytope_I65,initial_polytope_I66,initial_polytope_I67,initial_polytope_I68,initial_polytope_I69,initial_polytope_I70,initial_polytope_I71,initial_polytope_I72,initial_polytope_I73,initial_polytope_I74,initial_polytope_I75,initial_polytope_I76,initial_polytope_I77,initial_polytope_I78,initial_polytope_I79,initial_polytope_I80,initial_polytope_I81,initial_polytope_I82,initial_polytope_I83,initial_polytope_I84,initial_polytope_I85,initial_polytope_I86,initial_polytope_I87,initial_polytope_I88,initial_polytope_I89,initial_polytope_I90,initial_polytope_I91,initial_polytope_I92,initial_polytope_I93,initial_polytope_I94,initial_polytope_I95,initial_polytope_I96,initial_polytope_I97,initial_polytope_I98,initial_polytope_I99, forbid_polytope;
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
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[2] = 36.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part1;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 36 & 1 * nu1 <= 36 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -36.0;
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

// Original guard: nu1 >= 36 & nu2 >= 0 & 1 * nu1 <= 72 & 1 * nu2 <= 36

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
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

t = transition::ptr(new transition(2,"dummy",1,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part1.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 36 & 1 * nu1 <= 72 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(3,"dummy",1,12,guard_polytope,assignment));

Out_Going_Trans_fromM1Part1.push_back(t);
l = location::ptr(new location(1, "M1Part1", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part1));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part2

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 36.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part2;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 72 & 1 * nu1 <= 36 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -72.0;
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

// Original guard: nu1 >= 36 & nu2 >= 36 & 1 * nu1 <= 72 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(5,"dummy",2,12,guard_polytope,assignment));

Out_Going_Trans_fromM1Part2.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 72 & 1 * nu1 <= 72 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(6,"dummy",2,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part2.push_back(t);
l = location::ptr(new location(2, "M1Part2", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part2));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part3

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 36.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part3;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 108 & 1 * nu1 <= 36 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -108.0;
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

// Original guard: nu1 >= 36 & nu2 >= 72 & 1 * nu1 <= 72 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(8,"dummy",3,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part3.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 108 & 1 * nu1 <= 72 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(9,"dummy",3,14,guard_polytope,assignment));

Out_Going_Trans_fromM1Part3.push_back(t);
l = location::ptr(new location(3, "M1Part3", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part3));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part4

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 36.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part4;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 144 & 1 * nu1 <= 36 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -144.0;
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

// Original guard: nu1 >= 36 & nu2 >= 108 & 1 * nu1 <= 72 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(11,"dummy",4,14,guard_polytope,assignment));

Out_Going_Trans_fromM1Part4.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 144 & 1 * nu1 <= 72 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(12,"dummy",4,15,guard_polytope,assignment));

Out_Going_Trans_fromM1Part4.push_back(t);
l = location::ptr(new location(4, "M1Part4", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part4));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part5

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -144.0;
invariantBoundValue[2] = 36.0;
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
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part5;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 180 & 1 * nu1 <= 36 & 1 * nu2 <= 216

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

t = transition::ptr(new transition(13,"dummy",5,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part5.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 144 & 1 * nu1 <= 72 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(14,"dummy",5,15,guard_polytope,assignment));

Out_Going_Trans_fromM1Part5.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 180 & 1 * nu1 <= 72 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
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

t = transition::ptr(new transition(15,"dummy",5,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part5.push_back(t);
l = location::ptr(new location(5, "M1Part5", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part5));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part6

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[2] = 36.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part6;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 216 & 1 * nu1 <= 36 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -216.0;
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

// Original guard: nu1 >= 36 & nu2 >= 180 & 1 * nu1 <= 72 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
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

t = transition::ptr(new transition(17,"dummy",6,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 216 & 1 * nu1 <= 72 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(18,"dummy",6,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
l = location::ptr(new location(6, "M1Part6", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part6));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part7

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 36.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part7;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 252 & 1 * nu1 <= 36 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -252.0;
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

// Original guard: nu1 >= 36 & nu2 >= 216 & 1 * nu1 <= 72 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(20,"dummy",7,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part7.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 252 & 1 * nu1 <= 72 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(21,"dummy",7,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part7.push_back(t);
l = location::ptr(new location(7, "M1Part7", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part7));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part8

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 36.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part8;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 288 & 1 * nu1 <= 36 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(22,"dummy",8,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 252 & 1 * nu1 <= 72 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(23,"dummy",8,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 288 & 1 * nu1 <= 72 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(24,"dummy",8,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
l = location::ptr(new location(8, "M1Part8", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part8));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part9

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 36.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part9;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 324 & 1 * nu1 <= 36 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(25,"dummy",9,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 288 & 1 * nu1 <= 72 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(26,"dummy",9,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 324 & 1 * nu1 <= 72 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(27,"dummy",9,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
l = location::ptr(new location(9, "M1Part9", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part9));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part10

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.050026145876263535;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -324.0;
invariantBoundValue[2] = 36.0;
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
boundValueV[0] = -97.62026666666667;
boundValueV[1] = 98.51219200817056;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part10;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 324 & 1 * nu1 <= 72 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(28,"dummy",10,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 360 & 1 * nu1 <= 72 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
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

t = transition::ptr(new transition(29,"dummy",10,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 360 & 1 * nu1 <= 72 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
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

t = transition::ptr(new transition(30,"dummy",10,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 36 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(31,"dummy",10,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 396 & 1 * nu2 <= 36

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

t = transition::ptr(new transition(32,"dummy",10,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 396 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(33,"dummy",10,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
l = location::ptr(new location(10, "M1Part10", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part10));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part11

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[2] = 72.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part11;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 36 & 1 * nu1 <= 72 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -36.0;
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

// Original guard: nu1 >= 72 & nu2 >= 0 & 1 * nu1 <= 108 & 1 * nu2 <= 36

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
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

t = transition::ptr(new transition(35,"dummy",11,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part11.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 36 & 1 * nu1 <= 108 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(36,"dummy",11,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part11.push_back(t);
l = location::ptr(new location(11, "M1Part11", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part11));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part12

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 72.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part12;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 72 & 1 * nu1 <= 72 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -72.0;
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

// Original guard: nu1 >= 72 & nu2 >= 36 & 1 * nu1 <= 108 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(38,"dummy",12,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 72 & 1 * nu1 <= 108 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(39,"dummy",12,23,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
l = location::ptr(new location(12, "M1Part12", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part12));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part13

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 72.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part13;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 108 & 1 * nu1 <= 72 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -108.0;
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

// Original guard: nu1 >= 72 & nu2 >= 72 & 1 * nu1 <= 108 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(41,"dummy",13,23,guard_polytope,assignment));

Out_Going_Trans_fromM1Part13.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 108 & 1 * nu1 <= 108 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(42,"dummy",13,24,guard_polytope,assignment));

Out_Going_Trans_fromM1Part13.push_back(t);
l = location::ptr(new location(13, "M1Part13", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part13));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part14

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 72.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part14;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 144 & 1 * nu1 <= 72 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -144.0;
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

// Original guard: nu1 >= 72 & nu2 >= 108 & 1 * nu1 <= 108 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(44,"dummy",14,24,guard_polytope,assignment));

Out_Going_Trans_fromM1Part14.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 144 & 1 * nu1 <= 108 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(45,"dummy",14,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part14.push_back(t);
l = location::ptr(new location(14, "M1Part14", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part14));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part15

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -144.0;
invariantBoundValue[2] = 72.0;
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
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part15;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 180 & 1 * nu1 <= 72 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
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

t = transition::ptr(new transition(46,"dummy",15,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 144 & 1 * nu1 <= 108 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(47,"dummy",15,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 180 & 1 * nu1 <= 108 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
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

t = transition::ptr(new transition(48,"dummy",15,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
l = location::ptr(new location(15, "M1Part15", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part15));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part16

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 72.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part16;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 216 & 1 * nu1 <= 72 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(49,"dummy",16,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 180 & 1 * nu1 <= 108 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
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

t = transition::ptr(new transition(50,"dummy",16,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 216 & 1 * nu1 <= 108 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(51,"dummy",16,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
l = location::ptr(new location(16, "M1Part16", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part16));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part17

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 72.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part17;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 252 & 1 * nu1 <= 72 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(52,"dummy",17,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 216 & 1 * nu1 <= 108 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(53,"dummy",17,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 252 & 1 * nu1 <= 108 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(54,"dummy",17,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
l = location::ptr(new location(17, "M1Part17", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part17));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part18

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 72.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part18;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 288 & 1 * nu1 <= 72 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(55,"dummy",18,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 252 & 1 * nu1 <= 108 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(56,"dummy",18,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 288 & 1 * nu1 <= 108 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(57,"dummy",18,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
l = location::ptr(new location(18, "M1Part18", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part18));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part19

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 72.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part19;

// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 324 & 1 * nu1 <= 72 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(58,"dummy",19,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 288 & 1 * nu1 <= 108 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(59,"dummy",19,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 324 & 1 * nu1 <= 108 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(60,"dummy",19,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
l = location::ptr(new location(19, "M1Part19", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part19));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part20

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.1286992531977437;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -36.0;
invariantBoundValue[1] = -324.0;
invariantBoundValue[2] = 72.0;
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
boundValueV[0] = -100.48591194968553;
boundValueV[1] = 101.06450417052827;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part20;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 324 & 1 * nu1 <= 108 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(61,"dummy",20,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 360 & 1 * nu1 <= 108 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
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

t = transition::ptr(new transition(62,"dummy",20,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 360 & 1 * nu1 <= 108 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
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

t = transition::ptr(new transition(63,"dummy",20,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 360 & 1 * nu1 <= 72 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
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

t = transition::ptr(new transition(64,"dummy",20,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 36 & nu2 >= 360 & 1 * nu1 <= 72 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -36.0;
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

t = transition::ptr(new transition(65,"dummy",20,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
l = location::ptr(new location(20, "M1Part20", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part20));
Hybrid_Automata.addLocation(l);

bm05_module1(Hybrid_Automata,init_state_list,reach_parameters);
bm05_module2(Hybrid_Automata,init_state_list,reach_parameters);
bm05_module3(Hybrid_Automata,init_state_list,reach_parameters);
bm05_module4(Hybrid_Automata,init_state_list,reach_parameters);

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


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =100;

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


initial_polytope_I63 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I63->getSystemDimension();

symbolic_states::ptr S63;

initial_state::ptr I63 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I63, S63, transition_id));

init_state_list.push_back(I63);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I64 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I64->getSystemDimension();

symbolic_states::ptr S64;

initial_state::ptr I64 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I64, S64, transition_id));

init_state_list.push_back(I64);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I65 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I65->getSystemDimension();

symbolic_states::ptr S65;

initial_state::ptr I65 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I65, S65, transition_id));

init_state_list.push_back(I65);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I66 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I66->getSystemDimension();

symbolic_states::ptr S66;

initial_state::ptr I66 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I66, S66, transition_id));

init_state_list.push_back(I66);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I67 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I67->getSystemDimension();

symbolic_states::ptr S67;

initial_state::ptr I67 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I67, S67, transition_id));

init_state_list.push_back(I67);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I68 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I68->getSystemDimension();

symbolic_states::ptr S68;

initial_state::ptr I68 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I68, S68, transition_id));

init_state_list.push_back(I68);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I69 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I69->getSystemDimension();

symbolic_states::ptr S69;

initial_state::ptr I69 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I69, S69, transition_id));

init_state_list.push_back(I69);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I70 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I70->getSystemDimension();

symbolic_states::ptr S70;

initial_state::ptr I70 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I70, S70, transition_id));

init_state_list.push_back(I70);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I71 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I71->getSystemDimension();

symbolic_states::ptr S71;

initial_state::ptr I71 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I71, S71, transition_id));

init_state_list.push_back(I71);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I72 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I72->getSystemDimension();

symbolic_states::ptr S72;

initial_state::ptr I72 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I72, S72, transition_id));

init_state_list.push_back(I72);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I73 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I73->getSystemDimension();

symbolic_states::ptr S73;

initial_state::ptr I73 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I73, S73, transition_id));

init_state_list.push_back(I73);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I74 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I74->getSystemDimension();

symbolic_states::ptr S74;

initial_state::ptr I74 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I74, S74, transition_id));

init_state_list.push_back(I74);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I75 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I75->getSystemDimension();

symbolic_states::ptr S75;

initial_state::ptr I75 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I75, S75, transition_id));

init_state_list.push_back(I75);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I76 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I76->getSystemDimension();

symbolic_states::ptr S76;

initial_state::ptr I76 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I76, S76, transition_id));

init_state_list.push_back(I76);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I77 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I77->getSystemDimension();

symbolic_states::ptr S77;

initial_state::ptr I77 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I77, S77, transition_id));

init_state_list.push_back(I77);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I78 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I78->getSystemDimension();

symbolic_states::ptr S78;

initial_state::ptr I78 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I78, S78, transition_id));

init_state_list.push_back(I78);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I79 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I79->getSystemDimension();

symbolic_states::ptr S79;

initial_state::ptr I79 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I79, S79, transition_id));

init_state_list.push_back(I79);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I80 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I80->getSystemDimension();

symbolic_states::ptr S80;

initial_state::ptr I80 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I80, S80, transition_id));

init_state_list.push_back(I80);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I81 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I81->getSystemDimension();

symbolic_states::ptr S81;

initial_state::ptr I81 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I81, S81, transition_id));

init_state_list.push_back(I81);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I82 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I82->getSystemDimension();

symbolic_states::ptr S82;

initial_state::ptr I82 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I82, S82, transition_id));

init_state_list.push_back(I82);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I83 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I83->getSystemDimension();

symbolic_states::ptr S83;

initial_state::ptr I83 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I83, S83, transition_id));

init_state_list.push_back(I83);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I84 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I84->getSystemDimension();

symbolic_states::ptr S84;

initial_state::ptr I84 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I84, S84, transition_id));

init_state_list.push_back(I84);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I85 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I85->getSystemDimension();

symbolic_states::ptr S85;

initial_state::ptr I85 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I85, S85, transition_id));

init_state_list.push_back(I85);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I86 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I86->getSystemDimension();

symbolic_states::ptr S86;

initial_state::ptr I86 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I86, S86, transition_id));

init_state_list.push_back(I86);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I87 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I87->getSystemDimension();

symbolic_states::ptr S87;

initial_state::ptr I87 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I87, S87, transition_id));

init_state_list.push_back(I87);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I88 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I88->getSystemDimension();

symbolic_states::ptr S88;

initial_state::ptr I88 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I88, S88, transition_id));

init_state_list.push_back(I88);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I89 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I89->getSystemDimension();

symbolic_states::ptr S89;

initial_state::ptr I89 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I89, S89, transition_id));

init_state_list.push_back(I89);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I90 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I90->getSystemDimension();

symbolic_states::ptr S90;

initial_state::ptr I90 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I90, S90, transition_id));

init_state_list.push_back(I90);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I91 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I91->getSystemDimension();

symbolic_states::ptr S91;

initial_state::ptr I91 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I91, S91, transition_id));

init_state_list.push_back(I91);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I92 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I92->getSystemDimension();

symbolic_states::ptr S92;

initial_state::ptr I92 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I92, S92, transition_id));

init_state_list.push_back(I92);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I93 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I93->getSystemDimension();

symbolic_states::ptr S93;

initial_state::ptr I93 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I93, S93, transition_id));

init_state_list.push_back(I93);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I94 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I94->getSystemDimension();

symbolic_states::ptr S94;

initial_state::ptr I94 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I94, S94, transition_id));

init_state_list.push_back(I94);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I95 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I95->getSystemDimension();

symbolic_states::ptr S95;

initial_state::ptr I95 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I95, S95, transition_id));

init_state_list.push_back(I95);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I96 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I96->getSystemDimension();

symbolic_states::ptr S96;

initial_state::ptr I96 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I96, S96, transition_id));

init_state_list.push_back(I96);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I97 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I97->getSystemDimension();

symbolic_states::ptr S97;

initial_state::ptr I97 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I97, S97, transition_id));

init_state_list.push_back(I97);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I98 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I98->getSystemDimension();

symbolic_states::ptr S98;

initial_state::ptr I98 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I98, S98, transition_id));

init_state_list.push_back(I98);
ConstraintsMatrixI(0 , 0) = 1;
ConstraintsMatrixI(1 , 0) = -1;
ConstraintsMatrixI(2 , 1) = 1;
ConstraintsMatrixI(3 , 1) = -1;
ConstraintsMatrixI(4 , 2) = 1;
ConstraintsMatrixI(5 , 2) = -1;
boundValueI.resize(row );
boundValueI.assign(row,0);


initial_polytope_I99 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I99->getSystemDimension();

symbolic_states::ptr S99;

initial_state::ptr I99 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I99, S99, transition_id));

init_state_list.push_back(I99);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("nu1",0);
Hybrid_Automata.insert_to_map("nu2",1);
Hybrid_Automata.insert_to_map("t",2);

}

void bm05_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63,initial_polytope_I64,initial_polytope_I65,initial_polytope_I66,initial_polytope_I67,initial_polytope_I68,initial_polytope_I69,initial_polytope_I70,initial_polytope_I71,initial_polytope_I72,initial_polytope_I73,initial_polytope_I74,initial_polytope_I75,initial_polytope_I76,initial_polytope_I77,initial_polytope_I78,initial_polytope_I79,initial_polytope_I80,initial_polytope_I81,initial_polytope_I82,initial_polytope_I83,initial_polytope_I84,initial_polytope_I85,initial_polytope_I86,initial_polytope_I87,initial_polytope_I88,initial_polytope_I89,initial_polytope_I90,initial_polytope_I91,initial_polytope_I92,initial_polytope_I93,initial_polytope_I94,initial_polytope_I95,initial_polytope_I96,initial_polytope_I97,initial_polytope_I98,initial_polytope_I99, forbid_polytope;
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

// The mode name is  M1Part21

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[2] = 108.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part21;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 36 & 1 * nu1 <= 108 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(66,"dummy",21,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 0 & 1 * nu1 <= 144 & 1 * nu2 <= 36

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
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

t = transition::ptr(new transition(67,"dummy",21,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 36 & 1 * nu1 <= 144 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(68,"dummy",21,32,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
l = location::ptr(new location(21, "M1Part21", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part21));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part22

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 108.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part22;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 72 & 1 * nu1 <= 108 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -72.0;
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

// Original guard: nu1 >= 108 & nu2 >= 36 & 1 * nu1 <= 144 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(70,"dummy",22,32,guard_polytope,assignment));

Out_Going_Trans_fromM1Part22.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 72 & 1 * nu1 <= 144 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(71,"dummy",22,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part22.push_back(t);
l = location::ptr(new location(22, "M1Part22", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part22));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part23

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 108.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part23;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 108 & 1 * nu1 <= 108 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -108.0;
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

// Original guard: nu1 >= 108 & nu2 >= 72 & 1 * nu1 <= 144 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(73,"dummy",23,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part23.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 108 & 1 * nu1 <= 144 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(74,"dummy",23,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part23.push_back(t);
l = location::ptr(new location(23, "M1Part23", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part23));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part24

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 108.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part24;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 144 & 1 * nu1 <= 108 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(75,"dummy",24,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 108 & 1 * nu1 <= 144 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(76,"dummy",24,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 144 & 1 * nu1 <= 144 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(77,"dummy",24,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
l = location::ptr(new location(24, "M1Part24", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part24));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part25

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -144.0;
invariantBoundValue[2] = 108.0;
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
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part25;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 180 & 1 * nu1 <= 108 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
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

t = transition::ptr(new transition(78,"dummy",25,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 144 & 1 * nu1 <= 144 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(79,"dummy",25,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 180 & 1 * nu1 <= 144 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
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

t = transition::ptr(new transition(80,"dummy",25,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
l = location::ptr(new location(25, "M1Part25", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part25));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part26

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 108.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part26;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 216 & 1 * nu1 <= 108 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(81,"dummy",26,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 180 & 1 * nu1 <= 144 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
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

t = transition::ptr(new transition(82,"dummy",26,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 216 & 1 * nu1 <= 144 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(83,"dummy",26,37,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
l = location::ptr(new location(26, "M1Part26", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part26));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part27

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 108.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part27;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 252 & 1 * nu1 <= 108 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(84,"dummy",27,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 216 & 1 * nu1 <= 144 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(85,"dummy",27,37,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 252 & 1 * nu1 <= 144 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(86,"dummy",27,38,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
l = location::ptr(new location(27, "M1Part27", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part27));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part28

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 108.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part28;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 288 & 1 * nu1 <= 108 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(87,"dummy",28,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 252 & 1 * nu1 <= 144 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(88,"dummy",28,38,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 288 & 1 * nu1 <= 144 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(89,"dummy",28,39,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
l = location::ptr(new location(28, "M1Part28", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part28));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part29

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 108.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part29;

// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 324 & 1 * nu1 <= 108 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(90,"dummy",29,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 288 & 1 * nu1 <= 144 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(91,"dummy",29,39,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 324 & 1 * nu1 <= 144 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(92,"dummy",29,40,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
l = location::ptr(new location(29, "M1Part29", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part29));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part30

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.15453923154881496;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -72.0;
invariantBoundValue[1] = -324.0;
invariantBoundValue[2] = 108.0;
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
boundValueV[0] = -102.38631857237277;
boundValueV[1] = 102.51965780851839;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part30;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 324 & 1 * nu1 <= 144 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(93,"dummy",30,40,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 360 & 1 * nu1 <= 144 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
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

t = transition::ptr(new transition(94,"dummy",30,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 360 & 1 * nu1 <= 144 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
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

t = transition::ptr(new transition(95,"dummy",30,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 360 & 1 * nu1 <= 108 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
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

t = transition::ptr(new transition(96,"dummy",30,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 72 & nu2 >= 360 & 1 * nu1 <= 108 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -72.0;
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

t = transition::ptr(new transition(97,"dummy",30,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
l = location::ptr(new location(30, "M1Part30", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part30));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part31

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[2] = 144.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part31;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 36 & 1 * nu1 <= 144 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -36.0;
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

// Original guard: nu1 >= 144 & nu2 >= 0 & 1 * nu1 <= 180 & 1 * nu2 <= 36

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
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

t = transition::ptr(new transition(99,"dummy",31,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 36 & 1 * nu1 <= 180 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(100,"dummy",31,42,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
l = location::ptr(new location(31, "M1Part31", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part31));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part32

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 144.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part32;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 72 & 1 * nu1 <= 144 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(101,"dummy",32,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 36 & 1 * nu1 <= 180 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(102,"dummy",32,42,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 72 & 1 * nu1 <= 180 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(103,"dummy",32,43,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
l = location::ptr(new location(32, "M1Part32", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part32));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part33

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 144.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part33;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 108 & 1 * nu1 <= 144 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(104,"dummy",33,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 72 & 1 * nu1 <= 180 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(105,"dummy",33,43,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 108 & 1 * nu1 <= 180 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(106,"dummy",33,44,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
l = location::ptr(new location(33, "M1Part33", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part33));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part34

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 144.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part34;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 144 & 1 * nu1 <= 144 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(107,"dummy",34,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 108 & 1 * nu1 <= 180 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(108,"dummy",34,44,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 144 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(109,"dummy",34,45,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
l = location::ptr(new location(34, "M1Part34", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part34));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part35

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -144.0;
invariantBoundValue[2] = 144.0;
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
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part35;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 180 & 1 * nu1 <= 144 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
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

t = transition::ptr(new transition(110,"dummy",35,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 144 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(111,"dummy",35,45,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
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

t = transition::ptr(new transition(112,"dummy",35,46,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
l = location::ptr(new location(35, "M1Part35", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part35));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part36

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 144.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part36;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 216 & 1 * nu1 <= 144 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(113,"dummy",36,37,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
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

t = transition::ptr(new transition(114,"dummy",36,46,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 216 & 1 * nu1 <= 180 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(115,"dummy",36,47,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
l = location::ptr(new location(36, "M1Part36", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part36));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part37

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 144.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part37;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 252 & 1 * nu1 <= 144 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(116,"dummy",37,38,guard_polytope,assignment));

Out_Going_Trans_fromM1Part37.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 216 & 1 * nu1 <= 180 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(117,"dummy",37,47,guard_polytope,assignment));

Out_Going_Trans_fromM1Part37.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 252 & 1 * nu1 <= 180 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(118,"dummy",37,48,guard_polytope,assignment));

Out_Going_Trans_fromM1Part37.push_back(t);
l = location::ptr(new location(37, "M1Part37", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part37));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part38

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 144.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part38;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 288 & 1 * nu1 <= 144 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(119,"dummy",38,39,guard_polytope,assignment));

Out_Going_Trans_fromM1Part38.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 252 & 1 * nu1 <= 180 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(120,"dummy",38,48,guard_polytope,assignment));

Out_Going_Trans_fromM1Part38.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 288 & 1 * nu1 <= 180 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(121,"dummy",38,49,guard_polytope,assignment));

Out_Going_Trans_fromM1Part38.push_back(t);
l = location::ptr(new location(38, "M1Part38", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part38));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part39

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 144.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part39;

// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 324 & 1 * nu1 <= 144 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(122,"dummy",39,40,guard_polytope,assignment));

Out_Going_Trans_fromM1Part39.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 288 & 1 * nu1 <= 180 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(123,"dummy",39,49,guard_polytope,assignment));

Out_Going_Trans_fromM1Part39.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 324 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(124,"dummy",39,50,guard_polytope,assignment));

Out_Going_Trans_fromM1Part39.push_back(t);
l = location::ptr(new location(39, "M1Part39", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part39));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part40

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.12135047605133076;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -108.0;
invariantBoundValue[1] = -324.0;
invariantBoundValue[2] = 144.0;
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
boundValueV[0] = -98.4127562642369;
boundValueV[1] = 99.00041000410005;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part40;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 324 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(125,"dummy",40,50,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
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

t = transition::ptr(new transition(126,"dummy",40,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
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

t = transition::ptr(new transition(127,"dummy",40,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 360 & 1 * nu1 <= 144 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
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

t = transition::ptr(new transition(128,"dummy",40,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 108 & nu2 >= 360 & 1 * nu1 <= 144 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -108.0;
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

t = transition::ptr(new transition(129,"dummy",40,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part40.push_back(t);
l = location::ptr(new location(40, "M1Part40", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part40));
Hybrid_Automata.addLocation(l);

}

void bm05_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63,initial_polytope_I64,initial_polytope_I65,initial_polytope_I66,initial_polytope_I67,initial_polytope_I68,initial_polytope_I69,initial_polytope_I70,initial_polytope_I71,initial_polytope_I72,initial_polytope_I73,initial_polytope_I74,initial_polytope_I75,initial_polytope_I76,initial_polytope_I77,initial_polytope_I78,initial_polytope_I79,initial_polytope_I80,initial_polytope_I81,initial_polytope_I82,initial_polytope_I83,initial_polytope_I84,initial_polytope_I85,initial_polytope_I86,initial_polytope_I87,initial_polytope_I88,initial_polytope_I89,initial_polytope_I90,initial_polytope_I91,initial_polytope_I92,initial_polytope_I93,initial_polytope_I94,initial_polytope_I95,initial_polytope_I96,initial_polytope_I97,initial_polytope_I98,initial_polytope_I99, forbid_polytope;
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
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part41;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 36 & 1 * nu1 <= 180 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(130,"dummy",41,42,guard_polytope,assignment));

Out_Going_Trans_fromM1Part41.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 0 & 1 * nu1 <= 216 & 1 * nu2 <= 36

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

t = transition::ptr(new transition(131,"dummy",41,51,guard_polytope,assignment));

Out_Going_Trans_fromM1Part41.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 36 & 1 * nu1 <= 216 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(132,"dummy",41,52,guard_polytope,assignment));

Out_Going_Trans_fromM1Part41.push_back(t);
l = location::ptr(new location(41, "M1Part41", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part41));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part42

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part42;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 72 & 1 * nu1 <= 180 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(133,"dummy",42,43,guard_polytope,assignment));

Out_Going_Trans_fromM1Part42.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 36 & 1 * nu1 <= 216 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(134,"dummy",42,52,guard_polytope,assignment));

Out_Going_Trans_fromM1Part42.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 72 & 1 * nu1 <= 216 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(135,"dummy",42,53,guard_polytope,assignment));

Out_Going_Trans_fromM1Part42.push_back(t);
l = location::ptr(new location(42, "M1Part42", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part42));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part43

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part43;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 108 & 1 * nu1 <= 180 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(136,"dummy",43,44,guard_polytope,assignment));

Out_Going_Trans_fromM1Part43.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 72 & 1 * nu1 <= 216 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(137,"dummy",43,53,guard_polytope,assignment));

Out_Going_Trans_fromM1Part43.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 108 & 1 * nu1 <= 216 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(138,"dummy",43,54,guard_polytope,assignment));

Out_Going_Trans_fromM1Part43.push_back(t);
l = location::ptr(new location(43, "M1Part43", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part43));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part44

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part44;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 144 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(139,"dummy",44,45,guard_polytope,assignment));

Out_Going_Trans_fromM1Part44.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 108 & 1 * nu1 <= 216 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(140,"dummy",44,54,guard_polytope,assignment));

Out_Going_Trans_fromM1Part44.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 144 & 1 * nu1 <= 216 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(141,"dummy",44,55,guard_polytope,assignment));

Out_Going_Trans_fromM1Part44.push_back(t);
l = location::ptr(new location(44, "M1Part44", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part44));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part45

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -144.0;
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
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part45;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
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

t = transition::ptr(new transition(142,"dummy",45,46,guard_polytope,assignment));

Out_Going_Trans_fromM1Part45.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 144 & 1 * nu1 <= 216 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(143,"dummy",45,55,guard_polytope,assignment));

Out_Going_Trans_fromM1Part45.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 216 & 1 * nu2 <= 216

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

t = transition::ptr(new transition(144,"dummy",45,56,guard_polytope,assignment));

Out_Going_Trans_fromM1Part45.push_back(t);
l = location::ptr(new location(45, "M1Part45", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part45));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part46

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part46;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 216 & 1 * nu1 <= 180 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(145,"dummy",46,47,guard_polytope,assignment));

Out_Going_Trans_fromM1Part46.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 216 & 1 * nu2 <= 216

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

t = transition::ptr(new transition(146,"dummy",46,56,guard_polytope,assignment));

Out_Going_Trans_fromM1Part46.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 216 & 1 * nu1 <= 216 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(147,"dummy",46,57,guard_polytope,assignment));

Out_Going_Trans_fromM1Part46.push_back(t);
l = location::ptr(new location(46, "M1Part46", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part46));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part47

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part47;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 252 & 1 * nu1 <= 180 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(148,"dummy",47,48,guard_polytope,assignment));

Out_Going_Trans_fromM1Part47.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 216 & 1 * nu1 <= 216 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(149,"dummy",47,57,guard_polytope,assignment));

Out_Going_Trans_fromM1Part47.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 252 & 1 * nu1 <= 216 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(150,"dummy",47,58,guard_polytope,assignment));

Out_Going_Trans_fromM1Part47.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 216 & 1 * nu1 <= 180 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(151,"dummy",47,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part47.push_back(t);
l = location::ptr(new location(47, "M1Part47", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part47));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part48

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part48;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 288 & 1 * nu1 <= 180 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(152,"dummy",48,49,guard_polytope,assignment));

Out_Going_Trans_fromM1Part48.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 252 & 1 * nu1 <= 216 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(153,"dummy",48,58,guard_polytope,assignment));

Out_Going_Trans_fromM1Part48.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 288 & 1 * nu1 <= 216 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(154,"dummy",48,59,guard_polytope,assignment));

Out_Going_Trans_fromM1Part48.push_back(t);
l = location::ptr(new location(48, "M1Part48", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part48));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part49

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part49;

// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 324 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(155,"dummy",49,50,guard_polytope,assignment));

Out_Going_Trans_fromM1Part49.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 288 & 1 * nu1 <= 216 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(156,"dummy",49,59,guard_polytope,assignment));

Out_Going_Trans_fromM1Part49.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 324 & 1 * nu1 <= 216 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(157,"dummy",49,60,guard_polytope,assignment));

Out_Going_Trans_fromM1Part49.push_back(t);
l = location::ptr(new location(49, "M1Part49", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part49));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part50

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.045484351817547744;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -144.0;
invariantBoundValue[1] = -324.0;
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
boundValueV[0] = -87.28558014755198;
boundValueV[1] = 88.09855403348554;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part50;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 324 & 1 * nu1 <= 216 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(158,"dummy",50,60,guard_polytope,assignment));

Out_Going_Trans_fromM1Part50.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 216 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(159,"dummy",50,51,guard_polytope,assignment));

Out_Going_Trans_fromM1Part50.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 216 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(160,"dummy",50,51,guard_polytope,assignment));

Out_Going_Trans_fromM1Part50.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
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

t = transition::ptr(new transition(161,"dummy",50,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part50.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 144 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -144.0;
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

t = transition::ptr(new transition(162,"dummy",50,41,guard_polytope,assignment));

Out_Going_Trans_fromM1Part50.push_back(t);
l = location::ptr(new location(50, "M1Part50", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part50));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part51

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[2] = 216.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part51;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 36 & 1 * nu1 <= 216 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(163,"dummy",51,52,guard_polytope,assignment));

Out_Going_Trans_fromM1Part51.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 0 & 1 * nu1 <= 252 & 1 * nu2 <= 36

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
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

t = transition::ptr(new transition(164,"dummy",51,61,guard_polytope,assignment));

Out_Going_Trans_fromM1Part51.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 36 & 1 * nu1 <= 252 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(165,"dummy",51,62,guard_polytope,assignment));

Out_Going_Trans_fromM1Part51.push_back(t);
l = location::ptr(new location(51, "M1Part51", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part51));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part52

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 216.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part52;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 72 & 1 * nu1 <= 216 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(166,"dummy",52,53,guard_polytope,assignment));

Out_Going_Trans_fromM1Part52.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 36 & 1 * nu1 <= 252 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(167,"dummy",52,62,guard_polytope,assignment));

Out_Going_Trans_fromM1Part52.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 72 & 1 * nu1 <= 252 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(168,"dummy",52,63,guard_polytope,assignment));

Out_Going_Trans_fromM1Part52.push_back(t);
l = location::ptr(new location(52, "M1Part52", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part52));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part53

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 216.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part53;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 108 & 1 * nu1 <= 216 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(169,"dummy",53,54,guard_polytope,assignment));

Out_Going_Trans_fromM1Part53.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 72 & 1 * nu1 <= 252 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(170,"dummy",53,63,guard_polytope,assignment));

Out_Going_Trans_fromM1Part53.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 108 & 1 * nu1 <= 252 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(171,"dummy",53,64,guard_polytope,assignment));

Out_Going_Trans_fromM1Part53.push_back(t);
l = location::ptr(new location(53, "M1Part53", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part53));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part54

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 216.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part54;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 144 & 1 * nu1 <= 216 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(172,"dummy",54,55,guard_polytope,assignment));

Out_Going_Trans_fromM1Part54.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 108 & 1 * nu1 <= 252 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(173,"dummy",54,64,guard_polytope,assignment));

Out_Going_Trans_fromM1Part54.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 144 & 1 * nu1 <= 252 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(174,"dummy",54,65,guard_polytope,assignment));

Out_Going_Trans_fromM1Part54.push_back(t);
l = location::ptr(new location(54, "M1Part54", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part54));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part55

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -144.0;
invariantBoundValue[2] = 216.0;
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
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part55;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 216 & 1 * nu2 <= 216

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

t = transition::ptr(new transition(175,"dummy",55,56,guard_polytope,assignment));

Out_Going_Trans_fromM1Part55.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 144 & 1 * nu1 <= 252 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(176,"dummy",55,65,guard_polytope,assignment));

Out_Going_Trans_fromM1Part55.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 180 & 1 * nu1 <= 252 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
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

t = transition::ptr(new transition(177,"dummy",55,66,guard_polytope,assignment));

Out_Going_Trans_fromM1Part55.push_back(t);
l = location::ptr(new location(55, "M1Part55", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part55));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part56

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[2] = 216.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part56;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 216 & 1 * nu1 <= 216 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(178,"dummy",56,57,guard_polytope,assignment));

Out_Going_Trans_fromM1Part56.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 180 & 1 * nu1 <= 252 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
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

t = transition::ptr(new transition(179,"dummy",56,66,guard_polytope,assignment));

Out_Going_Trans_fromM1Part56.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 216 & 1 * nu1 <= 252 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(180,"dummy",56,67,guard_polytope,assignment));

Out_Going_Trans_fromM1Part56.push_back(t);
l = location::ptr(new location(56, "M1Part56", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part56));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part57

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 216.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part57;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 252 & 1 * nu1 <= 216 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(181,"dummy",57,58,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 216 & 1 * nu1 <= 252 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(182,"dummy",57,67,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 252 & 1 * nu1 <= 252 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(183,"dummy",57,68,guard_polytope,assignment));

Out_Going_Trans_fromM1Part57.push_back(t);
l = location::ptr(new location(57, "M1Part57", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part57));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part58

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 216.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part58;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 288 & 1 * nu1 <= 216 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(184,"dummy",58,59,guard_polytope,assignment));

Out_Going_Trans_fromM1Part58.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 252 & 1 * nu1 <= 252 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(185,"dummy",58,68,guard_polytope,assignment));

Out_Going_Trans_fromM1Part58.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 288 & 1 * nu1 <= 252 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(186,"dummy",58,69,guard_polytope,assignment));

Out_Going_Trans_fromM1Part58.push_back(t);
l = location::ptr(new location(58, "M1Part58", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part58));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part59

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 216.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part59;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 324 & 1 * nu1 <= 216 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(187,"dummy",59,60,guard_polytope,assignment));

Out_Going_Trans_fromM1Part59.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 288 & 1 * nu1 <= 252 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(188,"dummy",59,69,guard_polytope,assignment));

Out_Going_Trans_fromM1Part59.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 324 & 1 * nu1 <= 252 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(189,"dummy",59,70,guard_polytope,assignment));

Out_Going_Trans_fromM1Part59.push_back(t);
l = location::ptr(new location(59, "M1Part59", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part59));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part60

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.045484351817547744;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[1] = -324.0;
invariantBoundValue[2] = 216.0;
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
boundValueV[0] = -70.91121351766513;
boundValueV[1] = 71.72418738049713;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part60;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 324 & 1 * nu1 <= 252 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(190,"dummy",60,70,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 360 & 1 * nu1 <= 252 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
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

t = transition::ptr(new transition(191,"dummy",60,61,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 360 & 1 * nu1 <= 252 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
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

t = transition::ptr(new transition(192,"dummy",60,61,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 216 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(193,"dummy",60,51,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 216 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(194,"dummy",60,51,guard_polytope,assignment));

Out_Going_Trans_fromM1Part60.push_back(t);
l = location::ptr(new location(60, "M1Part60", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part60));
Hybrid_Automata.addLocation(l);

}

void bm05_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63,initial_polytope_I64,initial_polytope_I65,initial_polytope_I66,initial_polytope_I67,initial_polytope_I68,initial_polytope_I69,initial_polytope_I70,initial_polytope_I71,initial_polytope_I72,initial_polytope_I73,initial_polytope_I74,initial_polytope_I75,initial_polytope_I76,initial_polytope_I77,initial_polytope_I78,initial_polytope_I79,initial_polytope_I80,initial_polytope_I81,initial_polytope_I82,initial_polytope_I83,initial_polytope_I84,initial_polytope_I85,initial_polytope_I86,initial_polytope_I87,initial_polytope_I88,initial_polytope_I89,initial_polytope_I90,initial_polytope_I91,initial_polytope_I92,initial_polytope_I93,initial_polytope_I94,initial_polytope_I95,initial_polytope_I96,initial_polytope_I97,initial_polytope_I98,initial_polytope_I99, forbid_polytope;
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

// The mode name is  M1Part61

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[2] = 252.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part61;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 36 & 1 * nu1 <= 252 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(195,"dummy",61,62,guard_polytope,assignment));

Out_Going_Trans_fromM1Part61.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 0 & 1 * nu1 <= 288 & 1 * nu2 <= 36

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
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

t = transition::ptr(new transition(196,"dummy",61,71,guard_polytope,assignment));

Out_Going_Trans_fromM1Part61.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 36 & 1 * nu1 <= 288 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(197,"dummy",61,72,guard_polytope,assignment));

Out_Going_Trans_fromM1Part61.push_back(t);
l = location::ptr(new location(61, "M1Part61", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part61));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part62

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 252.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part62;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 72 & 1 * nu1 <= 252 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(198,"dummy",62,63,guard_polytope,assignment));

Out_Going_Trans_fromM1Part62.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 36 & 1 * nu1 <= 288 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(199,"dummy",62,72,guard_polytope,assignment));

Out_Going_Trans_fromM1Part62.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 72 & 1 * nu1 <= 288 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(200,"dummy",62,73,guard_polytope,assignment));

Out_Going_Trans_fromM1Part62.push_back(t);
l = location::ptr(new location(62, "M1Part62", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part62));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part63

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 252.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part63;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 108 & 1 * nu1 <= 252 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(201,"dummy",63,64,guard_polytope,assignment));

Out_Going_Trans_fromM1Part63.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 72 & 1 * nu1 <= 288 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(202,"dummy",63,73,guard_polytope,assignment));

Out_Going_Trans_fromM1Part63.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 108 & 1 * nu1 <= 288 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(203,"dummy",63,74,guard_polytope,assignment));

Out_Going_Trans_fromM1Part63.push_back(t);
l = location::ptr(new location(63, "M1Part63", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part63));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part64

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 252.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part64;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 144 & 1 * nu1 <= 252 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(204,"dummy",64,65,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 108 & 1 * nu1 <= 288 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(205,"dummy",64,74,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 144 & 1 * nu1 <= 288 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(206,"dummy",64,75,guard_polytope,assignment));

Out_Going_Trans_fromM1Part64.push_back(t);
l = location::ptr(new location(64, "M1Part64", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part64));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part65

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -144.0;
invariantBoundValue[2] = 252.0;
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
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part65;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 180 & 1 * nu1 <= 252 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
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

t = transition::ptr(new transition(207,"dummy",65,66,guard_polytope,assignment));

Out_Going_Trans_fromM1Part65.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 144 & 1 * nu1 <= 288 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(208,"dummy",65,75,guard_polytope,assignment));

Out_Going_Trans_fromM1Part65.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 180 & 1 * nu1 <= 288 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
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

t = transition::ptr(new transition(209,"dummy",65,76,guard_polytope,assignment));

Out_Going_Trans_fromM1Part65.push_back(t);
l = location::ptr(new location(65, "M1Part65", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part65));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part66

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 252.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part66;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 216 & 1 * nu1 <= 252 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(210,"dummy",66,67,guard_polytope,assignment));

Out_Going_Trans_fromM1Part66.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 180 & 1 * nu1 <= 288 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
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

t = transition::ptr(new transition(211,"dummy",66,76,guard_polytope,assignment));

Out_Going_Trans_fromM1Part66.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 216 & 1 * nu1 <= 288 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(212,"dummy",66,77,guard_polytope,assignment));

Out_Going_Trans_fromM1Part66.push_back(t);
l = location::ptr(new location(66, "M1Part66", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part66));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part67

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 252.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part67;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 252 & 1 * nu1 <= 252 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(213,"dummy",67,68,guard_polytope,assignment));

Out_Going_Trans_fromM1Part67.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 216 & 1 * nu1 <= 288 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(214,"dummy",67,77,guard_polytope,assignment));

Out_Going_Trans_fromM1Part67.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 252 & 1 * nu1 <= 288 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(215,"dummy",67,78,guard_polytope,assignment));

Out_Going_Trans_fromM1Part67.push_back(t);
l = location::ptr(new location(67, "M1Part67", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part67));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part68

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 252.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part68;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 288 & 1 * nu1 <= 252 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(216,"dummy",68,69,guard_polytope,assignment));

Out_Going_Trans_fromM1Part68.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 252 & 1 * nu1 <= 288 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(217,"dummy",68,78,guard_polytope,assignment));

Out_Going_Trans_fromM1Part68.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 288 & 1 * nu1 <= 288 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(218,"dummy",68,79,guard_polytope,assignment));

Out_Going_Trans_fromM1Part68.push_back(t);
l = location::ptr(new location(68, "M1Part68", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part68));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part69

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 252.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part69;

// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 324 & 1 * nu1 <= 252 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(219,"dummy",69,70,guard_polytope,assignment));

Out_Going_Trans_fromM1Part69.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 288 & 1 * nu1 <= 288 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(220,"dummy",69,79,guard_polytope,assignment));

Out_Going_Trans_fromM1Part69.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 324 & 1 * nu1 <= 288 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(221,"dummy",69,80,guard_polytope,assignment));

Out_Going_Trans_fromM1Part69.push_back(t);
l = location::ptr(new location(69, "M1Part69", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part69));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part70

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.12135047605133076;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -216.0;
invariantBoundValue[1] = -324.0;
invariantBoundValue[2] = 252.0;
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
boundValueV[0] = -54.72658483268875;
boundValueV[1] = 55.31423865300147;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part70;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 324 & 1 * nu1 <= 288 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(222,"dummy",70,80,guard_polytope,assignment));

Out_Going_Trans_fromM1Part70.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 360 & 1 * nu1 <= 288 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
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

t = transition::ptr(new transition(223,"dummy",70,71,guard_polytope,assignment));

Out_Going_Trans_fromM1Part70.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 360 & 1 * nu1 <= 288 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
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

t = transition::ptr(new transition(224,"dummy",70,71,guard_polytope,assignment));

Out_Going_Trans_fromM1Part70.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 360 & 1 * nu1 <= 252 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
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

t = transition::ptr(new transition(225,"dummy",70,61,guard_polytope,assignment));

Out_Going_Trans_fromM1Part70.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 216 & nu2 >= 360 & 1 * nu1 <= 252 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -216.0;
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

t = transition::ptr(new transition(226,"dummy",70,61,guard_polytope,assignment));

Out_Going_Trans_fromM1Part70.push_back(t);
l = location::ptr(new location(70, "M1Part70", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part70));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part71

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[2] = 288.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part71;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 36 & 1 * nu1 <= 288 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(227,"dummy",71,72,guard_polytope,assignment));

Out_Going_Trans_fromM1Part71.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 0 & 1 * nu1 <= 324 & 1 * nu2 <= 36

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
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

t = transition::ptr(new transition(228,"dummy",71,81,guard_polytope,assignment));

Out_Going_Trans_fromM1Part71.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 36 & 1 * nu1 <= 324 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(229,"dummy",71,82,guard_polytope,assignment));

Out_Going_Trans_fromM1Part71.push_back(t);
l = location::ptr(new location(71, "M1Part71", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part71));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part72

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 288.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part72;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 72 & 1 * nu1 <= 288 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(230,"dummy",72,73,guard_polytope,assignment));

Out_Going_Trans_fromM1Part72.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 36 & 1 * nu1 <= 324 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(231,"dummy",72,82,guard_polytope,assignment));

Out_Going_Trans_fromM1Part72.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 72 & 1 * nu1 <= 324 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(232,"dummy",72,83,guard_polytope,assignment));

Out_Going_Trans_fromM1Part72.push_back(t);
l = location::ptr(new location(72, "M1Part72", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part72));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part73

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 288.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part73;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 108 & 1 * nu1 <= 288 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(233,"dummy",73,74,guard_polytope,assignment));

Out_Going_Trans_fromM1Part73.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 72 & 1 * nu1 <= 324 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(234,"dummy",73,83,guard_polytope,assignment));

Out_Going_Trans_fromM1Part73.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 108 & 1 * nu1 <= 324 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(235,"dummy",73,84,guard_polytope,assignment));

Out_Going_Trans_fromM1Part73.push_back(t);
l = location::ptr(new location(73, "M1Part73", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part73));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part74

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 288.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part74;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 144 & 1 * nu1 <= 288 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(236,"dummy",74,75,guard_polytope,assignment));

Out_Going_Trans_fromM1Part74.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 108 & 1 * nu1 <= 324 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(237,"dummy",74,84,guard_polytope,assignment));

Out_Going_Trans_fromM1Part74.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 144 & 1 * nu1 <= 324 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(238,"dummy",74,85,guard_polytope,assignment));

Out_Going_Trans_fromM1Part74.push_back(t);
l = location::ptr(new location(74, "M1Part74", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part74));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part75

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -144.0;
invariantBoundValue[2] = 288.0;
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
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part75;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 180 & 1 * nu1 <= 288 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
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

t = transition::ptr(new transition(239,"dummy",75,76,guard_polytope,assignment));

Out_Going_Trans_fromM1Part75.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 144 & 1 * nu1 <= 324 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(240,"dummy",75,85,guard_polytope,assignment));

Out_Going_Trans_fromM1Part75.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 180 & 1 * nu1 <= 324 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
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

t = transition::ptr(new transition(241,"dummy",75,86,guard_polytope,assignment));

Out_Going_Trans_fromM1Part75.push_back(t);
l = location::ptr(new location(75, "M1Part75", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part75));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part76

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 288.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part76;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 216 & 1 * nu1 <= 288 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(242,"dummy",76,77,guard_polytope,assignment));

Out_Going_Trans_fromM1Part76.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 180 & 1 * nu1 <= 324 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
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

t = transition::ptr(new transition(243,"dummy",76,86,guard_polytope,assignment));

Out_Going_Trans_fromM1Part76.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 216 & 1 * nu1 <= 324 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(244,"dummy",76,87,guard_polytope,assignment));

Out_Going_Trans_fromM1Part76.push_back(t);
l = location::ptr(new location(76, "M1Part76", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part76));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part77

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 288.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part77;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 252 & 1 * nu1 <= 288 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(245,"dummy",77,78,guard_polytope,assignment));

Out_Going_Trans_fromM1Part77.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 216 & 1 * nu1 <= 324 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(246,"dummy",77,87,guard_polytope,assignment));

Out_Going_Trans_fromM1Part77.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 252 & 1 * nu1 <= 324 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(247,"dummy",77,88,guard_polytope,assignment));

Out_Going_Trans_fromM1Part77.push_back(t);
l = location::ptr(new location(77, "M1Part77", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part77));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part78

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 288.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part78;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 288 & 1 * nu1 <= 288 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(248,"dummy",78,79,guard_polytope,assignment));

Out_Going_Trans_fromM1Part78.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 252 & 1 * nu1 <= 324 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(249,"dummy",78,88,guard_polytope,assignment));

Out_Going_Trans_fromM1Part78.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 288 & 1 * nu1 <= 324 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(250,"dummy",78,89,guard_polytope,assignment));

Out_Going_Trans_fromM1Part78.push_back(t);
l = location::ptr(new location(78, "M1Part78", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part78));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part79

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 288.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part79;

// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 324 & 1 * nu1 <= 288 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(251,"dummy",79,80,guard_polytope,assignment));

Out_Going_Trans_fromM1Part79.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 288 & 1 * nu1 <= 324 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(252,"dummy",79,89,guard_polytope,assignment));

Out_Going_Trans_fromM1Part79.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 324 & 1 * nu1 <= 324 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(253,"dummy",79,90,guard_polytope,assignment));

Out_Going_Trans_fromM1Part79.push_back(t);
l = location::ptr(new location(79, "M1Part79", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part79));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part80

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.15453923154881496;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -252.0;
invariantBoundValue[1] = -324.0;
invariantBoundValue[2] = 288.0;
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
boundValueV[0] = -46.75219522156422;
boundValueV[1] = 46.88553447646844;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part80;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 324 & 1 * nu1 <= 324 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(254,"dummy",80,90,guard_polytope,assignment));

Out_Going_Trans_fromM1Part80.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 360 & 1 * nu1 <= 324 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
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

t = transition::ptr(new transition(255,"dummy",80,81,guard_polytope,assignment));

Out_Going_Trans_fromM1Part80.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 360 & 1 * nu1 <= 324 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
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

t = transition::ptr(new transition(256,"dummy",80,81,guard_polytope,assignment));

Out_Going_Trans_fromM1Part80.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 360 & 1 * nu1 <= 288 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
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

t = transition::ptr(new transition(257,"dummy",80,71,guard_polytope,assignment));

Out_Going_Trans_fromM1Part80.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 252 & nu2 >= 360 & 1 * nu1 <= 288 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -252.0;
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

t = transition::ptr(new transition(258,"dummy",80,71,guard_polytope,assignment));

Out_Going_Trans_fromM1Part80.push_back(t);
l = location::ptr(new location(80, "M1Part80", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part80));
Hybrid_Automata.addLocation(l);

}

void bm05_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0,initial_polytope_I1,initial_polytope_I2,initial_polytope_I3,initial_polytope_I4,initial_polytope_I5,initial_polytope_I6,initial_polytope_I7,initial_polytope_I8,initial_polytope_I9,initial_polytope_I10,initial_polytope_I11,initial_polytope_I12,initial_polytope_I13,initial_polytope_I14,initial_polytope_I15,initial_polytope_I16,initial_polytope_I17,initial_polytope_I18,initial_polytope_I19,initial_polytope_I20,initial_polytope_I21,initial_polytope_I22,initial_polytope_I23,initial_polytope_I24,initial_polytope_I25,initial_polytope_I26,initial_polytope_I27,initial_polytope_I28,initial_polytope_I29,initial_polytope_I30,initial_polytope_I31,initial_polytope_I32,initial_polytope_I33,initial_polytope_I34,initial_polytope_I35,initial_polytope_I36,initial_polytope_I37,initial_polytope_I38,initial_polytope_I39,initial_polytope_I40,initial_polytope_I41,initial_polytope_I42,initial_polytope_I43,initial_polytope_I44,initial_polytope_I45,initial_polytope_I46,initial_polytope_I47,initial_polytope_I48,initial_polytope_I49,initial_polytope_I50,initial_polytope_I51,initial_polytope_I52,initial_polytope_I53,initial_polytope_I54,initial_polytope_I55,initial_polytope_I56,initial_polytope_I57,initial_polytope_I58,initial_polytope_I59,initial_polytope_I60,initial_polytope_I61,initial_polytope_I62,initial_polytope_I63,initial_polytope_I64,initial_polytope_I65,initial_polytope_I66,initial_polytope_I67,initial_polytope_I68,initial_polytope_I69,initial_polytope_I70,initial_polytope_I71,initial_polytope_I72,initial_polytope_I73,initial_polytope_I74,initial_polytope_I75,initial_polytope_I76,initial_polytope_I77,initial_polytope_I78,initial_polytope_I79,initial_polytope_I80,initial_polytope_I81,initial_polytope_I82,initial_polytope_I83,initial_polytope_I84,initial_polytope_I85,initial_polytope_I86,initial_polytope_I87,initial_polytope_I88,initial_polytope_I89,initial_polytope_I90,initial_polytope_I91,initial_polytope_I92,initial_polytope_I93,initial_polytope_I94,initial_polytope_I95,initial_polytope_I96,initial_polytope_I97,initial_polytope_I98,initial_polytope_I99, forbid_polytope;
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

// The mode name is  M1Part81

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[2] = 324.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part81;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 36 & 1 * nu1 <= 324 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(259,"dummy",81,82,guard_polytope,assignment));

Out_Going_Trans_fromM1Part81.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 0 & 1 * nu1 <= 360 & 1 * nu2 <= 36

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
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

t = transition::ptr(new transition(260,"dummy",81,91,guard_polytope,assignment));

Out_Going_Trans_fromM1Part81.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 36 & 1 * nu1 <= 360 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(261,"dummy",81,92,guard_polytope,assignment));

Out_Going_Trans_fromM1Part81.push_back(t);
l = location::ptr(new location(81, "M1Part81", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part81));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part82

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 324.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part82;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 72 & 1 * nu1 <= 324 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(262,"dummy",82,83,guard_polytope,assignment));

Out_Going_Trans_fromM1Part82.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 36 & 1 * nu1 <= 360 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(263,"dummy",82,92,guard_polytope,assignment));

Out_Going_Trans_fromM1Part82.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 72 & 1 * nu1 <= 360 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(264,"dummy",82,93,guard_polytope,assignment));

Out_Going_Trans_fromM1Part82.push_back(t);
l = location::ptr(new location(82, "M1Part82", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part82));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part83

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 324.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part83;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 108 & 1 * nu1 <= 324 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(265,"dummy",83,84,guard_polytope,assignment));

Out_Going_Trans_fromM1Part83.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 72 & 1 * nu1 <= 360 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(266,"dummy",83,93,guard_polytope,assignment));

Out_Going_Trans_fromM1Part83.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 108 & 1 * nu1 <= 360 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(267,"dummy",83,94,guard_polytope,assignment));

Out_Going_Trans_fromM1Part83.push_back(t);
l = location::ptr(new location(83, "M1Part83", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part83));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part84

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 324.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part84;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 144 & 1 * nu1 <= 324 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(268,"dummy",84,85,guard_polytope,assignment));

Out_Going_Trans_fromM1Part84.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 108 & 1 * nu1 <= 360 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(269,"dummy",84,94,guard_polytope,assignment));

Out_Going_Trans_fromM1Part84.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 144 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(270,"dummy",84,95,guard_polytope,assignment));

Out_Going_Trans_fromM1Part84.push_back(t);
l = location::ptr(new location(84, "M1Part84", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part84));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part85

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -144.0;
invariantBoundValue[2] = 324.0;
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
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part85;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 180 & 1 * nu1 <= 324 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
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

t = transition::ptr(new transition(271,"dummy",85,86,guard_polytope,assignment));

Out_Going_Trans_fromM1Part85.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 144 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(272,"dummy",85,95,guard_polytope,assignment));

Out_Going_Trans_fromM1Part85.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
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

t = transition::ptr(new transition(273,"dummy",85,96,guard_polytope,assignment));

Out_Going_Trans_fromM1Part85.push_back(t);
l = location::ptr(new location(85, "M1Part85", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part85));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part86

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 324.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part86;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 216 & 1 * nu1 <= 324 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(274,"dummy",86,87,guard_polytope,assignment));

Out_Going_Trans_fromM1Part86.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
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

t = transition::ptr(new transition(275,"dummy",86,96,guard_polytope,assignment));

Out_Going_Trans_fromM1Part86.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 216 & 1 * nu1 <= 360 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(276,"dummy",86,97,guard_polytope,assignment));

Out_Going_Trans_fromM1Part86.push_back(t);
l = location::ptr(new location(86, "M1Part86", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part86));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part87

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 324.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part87;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 252 & 1 * nu1 <= 324 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(277,"dummy",87,88,guard_polytope,assignment));

Out_Going_Trans_fromM1Part87.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 216 & 1 * nu1 <= 360 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(278,"dummy",87,97,guard_polytope,assignment));

Out_Going_Trans_fromM1Part87.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 252 & 1 * nu1 <= 360 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(279,"dummy",87,98,guard_polytope,assignment));

Out_Going_Trans_fromM1Part87.push_back(t);
l = location::ptr(new location(87, "M1Part87", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part87));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part88

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 324.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part88;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 288 & 1 * nu1 <= 324 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(280,"dummy",88,89,guard_polytope,assignment));

Out_Going_Trans_fromM1Part88.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 252 & 1 * nu1 <= 360 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(281,"dummy",88,98,guard_polytope,assignment));

Out_Going_Trans_fromM1Part88.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 288 & 1 * nu1 <= 360 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(282,"dummy",88,99,guard_polytope,assignment));

Out_Going_Trans_fromM1Part88.push_back(t);
l = location::ptr(new location(88, "M1Part88", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part88));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part89

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 324.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part89;

// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 324 & 1 * nu1 <= 324 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(283,"dummy",89,90,guard_polytope,assignment));

Out_Going_Trans_fromM1Part89.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 288 & 1 * nu1 <= 360 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(284,"dummy",89,99,guard_polytope,assignment));

Out_Going_Trans_fromM1Part89.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 324 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(285,"dummy",89,100,guard_polytope,assignment));

Out_Going_Trans_fromM1Part89.push_back(t);
l = location::ptr(new location(89, "M1Part89", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part89));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part90

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.1286992531977437;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -288.0;
invariantBoundValue[1] = -324.0;
invariantBoundValue[2] = 324.0;
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
boundValueV[0] = -54.154180668116226;
boundValueV[1] = 54.73277315494643;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part90;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 324 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(286,"dummy",90,100,guard_polytope,assignment));

Out_Going_Trans_fromM1Part90.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
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

t = transition::ptr(new transition(287,"dummy",90,91,guard_polytope,assignment));

Out_Going_Trans_fromM1Part90.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
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

t = transition::ptr(new transition(288,"dummy",90,91,guard_polytope,assignment));

Out_Going_Trans_fromM1Part90.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 360 & 1 * nu1 <= 324 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
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

t = transition::ptr(new transition(289,"dummy",90,81,guard_polytope,assignment));

Out_Going_Trans_fromM1Part90.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 288 & nu2 >= 360 & 1 * nu1 <= 324 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -288.0;
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

t = transition::ptr(new transition(290,"dummy",90,81,guard_polytope,assignment));

Out_Going_Trans_fromM1Part90.push_back(t);
l = location::ptr(new location(90, "M1Part90", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part90));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part91

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = -1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 36.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = -561.3817934782609;
boundValueV[3] = 596.5259599783667;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part91;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 36 & 1 * nu1 <= 360 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(291,"dummy",91,92,guard_polytope,assignment));

Out_Going_Trans_fromM1Part91.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 36 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(292,"dummy",91,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part91.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 396 & 1 * nu2 <= 36

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

t = transition::ptr(new transition(293,"dummy",91,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part91.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 396 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(294,"dummy",91,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part91.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 36 & 1 * nu1 <= 396 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(295,"dummy",91,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part91.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 36 & 1 * nu1 <= 396 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(296,"dummy",91,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part91.push_back(t);
l = location::ptr(new location(91, "M1Part91", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part91));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part92

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = -4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -36.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 72.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = -656.2817213842059;
boundValueV[3] = 671.4364384971693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part92;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 72 & 1 * nu1 <= 360 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(297,"dummy",92,93,guard_polytope,assignment));

Out_Going_Trans_fromM1Part92.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 36 & 1 * nu1 <= 396 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(298,"dummy",92,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part92.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 36 & 1 * nu1 <= 396 & 1 * nu2 <= 72

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -36.0;
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

t = transition::ptr(new transition(299,"dummy",92,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part92.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 72 & 1 * nu1 <= 396 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(300,"dummy",92,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part92.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 72 & 1 * nu1 <= 396 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(301,"dummy",92,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part92.push_back(t);
l = location::ptr(new location(92, "M1Part92", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part92));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part93

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = -4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -72.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 108.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = -634.1820098383696;
boundValueV[3] = 648.6606606606607;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part93;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 108 & 1 * nu1 <= 360 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(302,"dummy",93,94,guard_polytope,assignment));

Out_Going_Trans_fromM1Part93.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 72 & 1 * nu1 <= 396 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(303,"dummy",93,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part93.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 72 & 1 * nu1 <= 396 & 1 * nu2 <= 108

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -72.0;
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

t = transition::ptr(new transition(304,"dummy",93,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part93.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 108 & 1 * nu1 <= 396 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(305,"dummy",93,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part93.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 108 & 1 * nu1 <= 396 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(306,"dummy",93,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part93.push_back(t);
l = location::ptr(new location(93, "M1Part93", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part93));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part94

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = -2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -108.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 144.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = -428.6547464239272;
boundValueV[3] = 447.02000493949123;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part94;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 144 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(307,"dummy",94,95,guard_polytope,assignment));

Out_Going_Trans_fromM1Part94.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 108 & 1 * nu1 <= 396 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(308,"dummy",94,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part94.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 108 & 1 * nu1 <= 396 & 1 * nu2 <= 144

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -108.0;
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

t = transition::ptr(new transition(309,"dummy",94,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part94.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 144 & 1 * nu1 <= 396 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(310,"dummy",94,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part94.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 144 & 1 * nu1 <= 396 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(311,"dummy",94,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part94.push_back(t);
l = location::ptr(new location(94, "M1Part94", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part94));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part95

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = -0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -144.0;
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
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = -175.82257685989205;
boundValueV[3] = 190.1058055650979;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part95;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 216

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
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

t = transition::ptr(new transition(312,"dummy",95,96,guard_polytope,assignment));

Out_Going_Trans_fromM1Part95.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 144 & 1 * nu1 <= 396 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(313,"dummy",95,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part95.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 144 & 1 * nu1 <= 396 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -144.0;
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

t = transition::ptr(new transition(314,"dummy",95,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part95.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 396 & 1 * nu2 <= 216

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

t = transition::ptr(new transition(315,"dummy",95,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part95.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 396 & 1 * nu2 <= 216

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

t = transition::ptr(new transition(316,"dummy",95,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part95.push_back(t);
l = location::ptr(new location(95, "M1Part95", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part95));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part96

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = 0.7057608379400641;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 216.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = 78.25132572714125;
boundValueV[3] = -63.968095329617526;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part96;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 216 & 1 * nu1 <= 360 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(317,"dummy",96,97,guard_polytope,assignment));

Out_Going_Trans_fromM1Part96.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 396 & 1 * nu2 <= 216

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

t = transition::ptr(new transition(318,"dummy",96,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part96.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 396 & 1 * nu2 <= 216

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

t = transition::ptr(new transition(319,"dummy",96,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part96.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 216 & 1 * nu1 <= 396 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(320,"dummy",96,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part96.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 216 & 1 * nu1 <= 396 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(321,"dummy",96,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part96.push_back(t);
l = location::ptr(new location(96, "M1Part96", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part96));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part97

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = 2.4876053936274354;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -216.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 252.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = 466.88319751649203;
boundValueV[3] = -448.5179347826087;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part97;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 252 & 1 * nu1 <= 360 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(322,"dummy",97,98,guard_polytope,assignment));

Out_Going_Trans_fromM1Part97.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 216 & 1 * nu1 <= 396 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(323,"dummy",97,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part97.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 216 & 1 * nu1 <= 396 & 1 * nu2 <= 252

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -216.0;
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

t = transition::ptr(new transition(324,"dummy",97,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part97.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 252 & 1 * nu1 <= 396 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(325,"dummy",97,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part97.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 252 & 1 * nu1 <= 396 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(326,"dummy",97,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part97.push_back(t);
l = location::ptr(new location(97, "M1Part97", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part97));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part98

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = 4.354648431382785;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -252.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 288.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = 933.4914272990426;
boundValueV[3] = -919.0127729707458;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part98;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 288 & 1 * nu1 <= 360 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(327,"dummy",98,99,guard_polytope,assignment));

Out_Going_Trans_fromM1Part98.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 252 & 1 * nu1 <= 396 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(328,"dummy",98,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part98.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 252 & 1 * nu1 <= 396 & 1 * nu2 <= 288

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -252.0;
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

t = transition::ptr(new transition(329,"dummy",98,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part98.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 288 & 1 * nu1 <= 396 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(330,"dummy",98,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part98.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 288 & 1 * nu1 <= 396 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(331,"dummy",98,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part98.push_back(t);
l = location::ptr(new location(98, "M1Part98", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part98));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part99

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = 4.558363777924178;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -288.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 324.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = 984.72924270073;
boundValueV[3] = -969.5745173745174;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part99;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 324 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(332,"dummy",99,100,guard_polytope,assignment));

Out_Going_Trans_fromM1Part99.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 288 & 1 * nu1 <= 396 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(333,"dummy",99,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part99.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 288 & 1 * nu1 <= 396 & 1 * nu2 <= 324

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -288.0;
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

t = transition::ptr(new transition(334,"dummy",99,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part99.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 324 & 1 * nu1 <= 396 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(335,"dummy",99,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part99.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 324 & 1 * nu1 <= 396 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(336,"dummy",99,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part99.push_back(t);
l = location::ptr(new location(99, "M1Part99", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part99));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part100

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.050026145876263535;
Amatrix(1 , 1) = 1.985559901671279;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

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
invariantBoundValue[0] = -324.0;
invariantBoundValue[1] = -324.0;
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
boundValueV[0] = -79.61085390946502;
boundValueV[1] = 80.50277975766215;
boundValueV[2] = 153.419781792166;
boundValueV[3] = -118.2755939524838;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part100;

// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
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

t = transition::ptr(new transition(337,"dummy",100,91,guard_polytope,assignment));

Out_Going_Trans_fromM1Part100.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 324 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 396

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -324.0;
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

t = transition::ptr(new transition(338,"dummy",100,91,guard_polytope,assignment));

Out_Going_Trans_fromM1Part100.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 324 & 1 * nu1 <= 396 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(339,"dummy",100,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part100.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 324 & 1 * nu1 <= 396 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -324.0;
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

t = transition::ptr(new transition(340,"dummy",100,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part100.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 36 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(341,"dummy",100,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part100.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 396 & 1 * nu2 <= 36

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

t = transition::ptr(new transition(342,"dummy",100,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part100.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 396 & 1 * nu2 <= 396

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

t = transition::ptr(new transition(343,"dummy",100,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part100.push_back(t);
l = location::ptr(new location(100, "M1Part100", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part100));

Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);

}

