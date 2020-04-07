// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/01/bm01.xml
// Command Line arguments: -tool xspeed "-time_dynamics false" -verbose -output /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/01/bm01.cpp -input /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/01/bm01.xml /home/movies/MyData/Models-HybridSystems/1_Hyst-XSpeed_Shyambabu/01/bm01.cfg


#include "bm01.h"
void set_bm01_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  M1Part1

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.6004699253613575;
Amatrix(1 , 1) = -1.1031336922959145;
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
invariantBoundValue[2] = 60.0;
invariantBoundValue[3] = 60.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -108.03798862176546;
boundValueV[1] = 125.19793242561775;
boundValueV[2] = -198.4784587378641;
boundValueV[3] = 230.003288490284;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part1;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 60 & 1 * nu1 <= 60 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -60.0;
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

// Original guard: nu1 >= 60 & nu2 >= 0 & 1 * nu1 <= 120 & 1 * nu2 <= 60

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(2,"dummy",1,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part1.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 60 & 1 * nu1 <= 120 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(3,"dummy",1,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part1.push_back(t);
l = location::ptr(new location(1, "M1Part1", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part1));

Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part2

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.6004699253613575;
Amatrix(1 , 1) = -1.5396007176829094;
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
invariantBoundValue[1] = -60.0;
invariantBoundValue[2] = 60.0;
invariantBoundValue[3] = 120.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -108.03798862176546;
boundValueV[1] = 125.19793242561775;
boundValueV[2] = -219.18171557562076;
boundValueV[3] = 234.37166009636442;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part2;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 120 & 1 * nu1 <= 60 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
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

// Original guard: nu1 >= 60 & nu2 >= 60 & 1 * nu1 <= 120 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(5,"dummy",2,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part2.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 120 & 1 * nu1 <= 120 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(6,"dummy",2,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part2.push_back(t);
l = location::ptr(new location(2, "M1Part2", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part2));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part3

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.6004699253613575;
Amatrix(1 , 1) = -0.4364670255720054;
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
invariantBoundValue[1] = -120.0;
invariantBoundValue[2] = 60.0;
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
boundValueV[0] = -108.03798862176546;
boundValueV[1] = 125.19793242561775;
boundValueV[2] = -85.66072668363805;
boundValueV[3] = 101.9956158663883;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part3;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 180 & 1 * nu1 <= 60 & 1 * nu2 <= 240

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

t = transition::ptr(new transition(7,"dummy",3,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part3.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 120 & 1 * nu1 <= 120 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(8,"dummy",3,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part3.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 180 & 1 * nu1 <= 120 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
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

t = transition::ptr(new transition(9,"dummy",3,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part3.push_back(t);
l = location::ptr(new location(3, "M1Part3", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part3));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part4

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.6004699253613575;
Amatrix(1 , 1) = 0.4364670255720054;
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
invariantBoundValue[2] = 60.0;
invariantBoundValue[3] = 240.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -108.03798862176546;
boundValueV[1] = 125.19793242561775;
boundValueV[2] = 71.46740352191833;
boundValueV[3] = -55.13251231527094;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part4;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 240 & 1 * nu1 <= 60 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
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

// Original guard: nu1 >= 60 & nu2 >= 180 & 1 * nu1 <= 120 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
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

t = transition::ptr(new transition(11,"dummy",4,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part4.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 240 & 1 * nu1 <= 120 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(12,"dummy",4,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part4.push_back(t);
l = location::ptr(new location(4, "M1Part4", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part4));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part5

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.6004699253613575;
Amatrix(1 , 1) = 1.5396007176829094;
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
invariantBoundValue[1] = -240.0;
invariantBoundValue[2] = 60.0;
invariantBoundValue[3] = 300.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -108.03798862176546;
boundValueV[1] = 125.19793242561775;
boundValueV[2] = 335.0745437673987;
boundValueV[3] = -319.88459726801693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part5;

// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 300 & 1 * nu1 <= 60 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
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

// Original guard: nu1 >= 60 & nu2 >= 240 & 1 * nu1 <= 120 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(14,"dummy",5,11,guard_polytope,assignment));

Out_Going_Trans_fromM1Part5.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 300 & 1 * nu1 <= 120 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(15,"dummy",5,12,guard_polytope,assignment));

Out_Going_Trans_fromM1Part5.push_back(t);
l = location::ptr(new location(5, "M1Part5", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part5));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part6

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.6004699253613575;
Amatrix(1 , 1) = 1.1031336922959145;
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
invariantBoundValue[1] = -300.0;
invariantBoundValue[2] = 60.0;
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
boundValueV[0] = -108.03798862176546;
boundValueV[1] = 125.19793242561775;
boundValueV[2] = 198.64967637540454;
boundValueV[3] = -167.12483487450461;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part6;

// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 300 & 1 * nu1 <= 120 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(16,"dummy",6,12,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 360 & 1 * nu1 <= 120 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
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

t = transition::ptr(new transition(17,"dummy",6,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 360 & 1 * nu1 <= 120 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
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

t = transition::ptr(new transition(18,"dummy",6,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 60 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(19,"dummy",6,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 420 & 1 * nu2 <= 60

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

t = transition::ptr(new transition(20,"dummy",6,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 420 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(21,"dummy",6,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part6.push_back(t);
l = location::ptr(new location(6, "M1Part6", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part6));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part7

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.8380524814759222;
Amatrix(1 , 1) = -1.1031336922959145;
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
invariantBoundValue[0] = -60.0;
invariantBoundValue[2] = 120.0;
invariantBoundValue[3] = 60.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -119.30741427247452;
boundValueV[1] = 127.57577276524646;
boundValueV[2] = -198.4784587378641;
boundValueV[3] = 230.003288490284;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part7;

// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 60 & 1 * nu1 <= 120 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(22,"dummy",7,8,guard_polytope,assignment));

Out_Going_Trans_fromM1Part7.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 0 & 1 * nu1 <= 180 & 1 * nu2 <= 60

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(23,"dummy",7,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part7.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 60 & 1 * nu1 <= 180 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(24,"dummy",7,14,guard_polytope,assignment));

Out_Going_Trans_fromM1Part7.push_back(t);
l = location::ptr(new location(7, "M1Part7", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part7));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part8

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.8380524814759222;
Amatrix(1 , 1) = -1.5396007176829094;
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
invariantBoundValue[0] = -60.0;
invariantBoundValue[1] = -60.0;
invariantBoundValue[2] = 120.0;
invariantBoundValue[3] = 120.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -119.30741427247452;
boundValueV[1] = 127.57577276524646;
boundValueV[2] = -219.18171557562076;
boundValueV[3] = 234.37166009636442;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part8;

// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 120 & 1 * nu1 <= 120 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(25,"dummy",8,9,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 60 & 1 * nu1 <= 180 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(26,"dummy",8,14,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 120 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(27,"dummy",8,15,guard_polytope,assignment));

Out_Going_Trans_fromM1Part8.push_back(t);
l = location::ptr(new location(8, "M1Part8", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part8));
Hybrid_Automata.addLocation(l);

bm01_module1(Hybrid_Automata,init_state_list,reach_parameters);
bm01_module2(Hybrid_Automata,init_state_list,reach_parameters);
bm01_module3(Hybrid_Automata,init_state_list,reach_parameters);
bm01_module4(Hybrid_Automata,init_state_list,reach_parameters);

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
boundValueI[0]=5;
boundValueI[2]=5;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =1;

symbolic_states::ptr S0;

initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

init_state_list.push_back(I0);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("nu1",0);
Hybrid_Automata.insert_to_map("nu2",1);
Hybrid_Automata.insert_to_map("t",2);

}

void bm01_module1(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  M1Part9

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.8380524814759222;
Amatrix(1 , 1) = -0.4364670255720054;
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
invariantBoundValue[0] = -60.0;
invariantBoundValue[1] = -120.0;
invariantBoundValue[2] = 120.0;
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
boundValueV[0] = -119.30741427247452;
boundValueV[1] = 127.57577276524646;
boundValueV[2] = -85.66072668363805;
boundValueV[3] = 101.9956158663883;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part9;

// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 180 & 1 * nu1 <= 120 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -180.0;
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

t = transition::ptr(new transition(28,"dummy",9,10,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 120 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(29,"dummy",9,15,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
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

t = transition::ptr(new transition(30,"dummy",9,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part9.push_back(t);
l = location::ptr(new location(9, "M1Part9", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part9));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part10

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.8380524814759222;
Amatrix(1 , 1) = 0.4364670255720054;
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
invariantBoundValue[0] = -60.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 120.0;
invariantBoundValue[3] = 240.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -119.30741427247452;
boundValueV[1] = 127.57577276524646;
boundValueV[2] = 71.46740352191833;
boundValueV[3] = -55.13251231527094;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part10;

// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 240 & 1 * nu1 <= 120 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
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

// Original guard: nu1 >= 120 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
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

t = transition::ptr(new transition(32,"dummy",10,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 240 & 1 * nu1 <= 180 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(33,"dummy",10,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part10.push_back(t);
l = location::ptr(new location(10, "M1Part10", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part10));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part11

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.8380524814759222;
Amatrix(1 , 1) = 1.5396007176829094;
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
invariantBoundValue[0] = -60.0;
invariantBoundValue[1] = -240.0;
invariantBoundValue[2] = 120.0;
invariantBoundValue[3] = 300.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -119.30741427247452;
boundValueV[1] = 127.57577276524646;
boundValueV[2] = 335.0745437673987;
boundValueV[3] = -319.88459726801693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part11;

// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 300 & 1 * nu1 <= 120 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
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

// Original guard: nu1 >= 120 & nu2 >= 240 & 1 * nu1 <= 180 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(35,"dummy",11,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part11.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 300 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(36,"dummy",11,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part11.push_back(t);
l = location::ptr(new location(11, "M1Part11", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part11));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part12

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.8380524814759222;
Amatrix(1 , 1) = 1.1031336922959145;
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
invariantBoundValue[0] = -60.0;
invariantBoundValue[1] = -300.0;
invariantBoundValue[2] = 120.0;
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
boundValueV[0] = -119.30741427247452;
boundValueV[1] = 127.57577276524646;
boundValueV[2] = 198.64967637540454;
boundValueV[3] = -167.12483487450461;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part12;

// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 300 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(37,"dummy",12,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
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

t = transition::ptr(new transition(38,"dummy",12,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
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

t = transition::ptr(new transition(39,"dummy",12,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 360 & 1 * nu1 <= 120 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
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

t = transition::ptr(new transition(40,"dummy",12,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 60 & nu2 >= 360 & 1 * nu1 <= 120 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -60.0;
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

t = transition::ptr(new transition(41,"dummy",12,7,guard_polytope,assignment));

Out_Going_Trans_fromM1Part12.push_back(t);
l = location::ptr(new location(12, "M1Part12", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part12));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part13

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.2375825560681141;
Amatrix(1 , 1) = -1.1031336922959145;
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
invariantBoundValue[0] = -120.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 60.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.627793648126364;
boundValueV[1] = 55.5193810815122;
boundValueV[2] = -198.4784587378641;
boundValueV[3] = 230.003288490284;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part13;

// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 60 & 1 * nu1 <= 180 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(42,"dummy",13,14,guard_polytope,assignment));

Out_Going_Trans_fromM1Part13.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 0 & 1 * nu1 <= 240 & 1 * nu2 <= 60

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

t = transition::ptr(new transition(43,"dummy",13,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part13.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 60 & 1 * nu1 <= 240 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(44,"dummy",13,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part13.push_back(t);
l = location::ptr(new location(13, "M1Part13", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part13));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part14

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.2375825560681141;
Amatrix(1 , 1) = -1.5396007176829094;
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
invariantBoundValue[0] = -120.0;
invariantBoundValue[1] = -60.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 120.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.627793648126364;
boundValueV[1] = 55.5193810815122;
boundValueV[2] = -219.18171557562076;
boundValueV[3] = 234.37166009636442;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part14;

// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 120 & 1 * nu1 <= 180 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(45,"dummy",14,15,guard_polytope,assignment));

Out_Going_Trans_fromM1Part14.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 60 & 1 * nu1 <= 240 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(46,"dummy",14,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part14.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 120 & 1 * nu1 <= 240 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(47,"dummy",14,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part14.push_back(t);
l = location::ptr(new location(14, "M1Part14", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part14));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part15

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.2375825560681141;
Amatrix(1 , 1) = -0.4364670255720054;
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
invariantBoundValue[0] = -120.0;
invariantBoundValue[1] = -120.0;
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
boundValueV[0] = -46.627793648126364;
boundValueV[1] = 55.5193810815122;
boundValueV[2] = -85.66072668363805;
boundValueV[3] = 101.9956158663883;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part15;

// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 180 & 1 * nu1 <= 180 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
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

t = transition::ptr(new transition(48,"dummy",15,16,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 120 & 1 * nu1 <= 240 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(49,"dummy",15,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 240 & 1 * nu2 <= 240

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

t = transition::ptr(new transition(50,"dummy",15,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part15.push_back(t);
l = location::ptr(new location(15, "M1Part15", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part15));
Hybrid_Automata.addLocation(l);

}

void bm01_module2(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  M1Part16

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.2375825560681141;
Amatrix(1 , 1) = 0.4364670255720054;
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
invariantBoundValue[0] = -120.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 240.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.627793648126364;
boundValueV[1] = 55.5193810815122;
boundValueV[2] = 71.46740352191833;
boundValueV[3] = -55.13251231527094;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part16;

// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 240 & 1 * nu1 <= 180 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -240.0;
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

t = transition::ptr(new transition(51,"dummy",16,17,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 240 & 1 * nu2 <= 240

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

t = transition::ptr(new transition(52,"dummy",16,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 240 & 1 * nu1 <= 240 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(53,"dummy",16,23,guard_polytope,assignment));

Out_Going_Trans_fromM1Part16.push_back(t);
l = location::ptr(new location(16, "M1Part16", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part16));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part17

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.2375825560681141;
Amatrix(1 , 1) = 1.5396007176829094;
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
invariantBoundValue[0] = -120.0;
invariantBoundValue[1] = -240.0;
invariantBoundValue[2] = 180.0;
invariantBoundValue[3] = 300.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = -46.627793648126364;
boundValueV[1] = 55.5193810815122;
boundValueV[2] = 335.0745437673987;
boundValueV[3] = -319.88459726801693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part17;

// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 300 & 1 * nu1 <= 180 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(54,"dummy",17,18,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 240 & 1 * nu1 <= 240 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(55,"dummy",17,23,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 300 & 1 * nu1 <= 240 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(56,"dummy",17,24,guard_polytope,assignment));

Out_Going_Trans_fromM1Part17.push_back(t);
l = location::ptr(new location(17, "M1Part17", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part17));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part18

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.2375825560681141;
Amatrix(1 , 1) = 1.1031336922959145;
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
invariantBoundValue[0] = -120.0;
invariantBoundValue[1] = -300.0;
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
boundValueV[0] = -46.627793648126364;
boundValueV[1] = 55.5193810815122;
boundValueV[2] = 198.64967637540454;
boundValueV[3] = -167.12483487450461;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part18;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 300 & 1 * nu1 <= 240 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(57,"dummy",18,24,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 240 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(58,"dummy",18,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 240 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(59,"dummy",18,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
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

t = transition::ptr(new transition(60,"dummy",18,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 120 & nu2 >= 360 & 1 * nu1 <= 180 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -120.0;
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

t = transition::ptr(new transition(61,"dummy",18,13,guard_polytope,assignment));

Out_Going_Trans_fromM1Part18.push_back(t);
l = location::ptr(new location(18, "M1Part18", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part18));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part19

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.2375825560681141;
Amatrix(1 , 1) = -1.1031336922959145;
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
invariantBoundValue[2] = 240.0;
invariantBoundValue[3] = 60.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 38.90192707862119;
boundValueV[1] = -30.010338536387593;
boundValueV[2] = -198.4784587378641;
boundValueV[3] = 230.003288490284;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part19;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 60 & 1 * nu1 <= 240 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(62,"dummy",19,20,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 0 & 1 * nu1 <= 300 & 1 * nu2 <= 60

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(63,"dummy",19,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 60 & 1 * nu1 <= 300 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(64,"dummy",19,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part19.push_back(t);
l = location::ptr(new location(19, "M1Part19", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part19));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part20

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.2375825560681141;
Amatrix(1 , 1) = -1.5396007176829094;
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
invariantBoundValue[1] = -60.0;
invariantBoundValue[2] = 240.0;
invariantBoundValue[3] = 120.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 38.90192707862119;
boundValueV[1] = -30.010338536387593;
boundValueV[2] = -219.18171557562076;
boundValueV[3] = 234.37166009636442;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part20;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 120 & 1 * nu1 <= 240 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(65,"dummy",20,21,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 60 & 1 * nu1 <= 300 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(66,"dummy",20,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 120 & 1 * nu1 <= 300 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(67,"dummy",20,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part20.push_back(t);
l = location::ptr(new location(20, "M1Part20", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part20));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part21

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.2375825560681141;
Amatrix(1 , 1) = -0.4364670255720054;
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
invariantBoundValue[1] = -120.0;
invariantBoundValue[2] = 240.0;
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
boundValueV[0] = 38.90192707862119;
boundValueV[1] = -30.010338536387593;
boundValueV[2] = -85.66072668363805;
boundValueV[3] = 101.9956158663883;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part21;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 180 & 1 * nu1 <= 240 & 1 * nu2 <= 240

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

t = transition::ptr(new transition(68,"dummy",21,22,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 120 & 1 * nu1 <= 300 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(69,"dummy",21,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 180 & 1 * nu1 <= 300 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
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

t = transition::ptr(new transition(70,"dummy",21,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part21.push_back(t);
l = location::ptr(new location(21, "M1Part21", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part21));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part22

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.2375825560681141;
Amatrix(1 , 1) = 0.4364670255720054;
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
invariantBoundValue[2] = 240.0;
invariantBoundValue[3] = 240.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 38.90192707862119;
boundValueV[1] = -30.010338536387593;
boundValueV[2] = 71.46740352191833;
boundValueV[3] = -55.13251231527094;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part22;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 240 & 1 * nu1 <= 240 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(71,"dummy",22,23,guard_polytope,assignment));

Out_Going_Trans_fromM1Part22.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 180 & 1 * nu1 <= 300 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
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

t = transition::ptr(new transition(72,"dummy",22,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part22.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 240 & 1 * nu1 <= 300 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(73,"dummy",22,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part22.push_back(t);
l = location::ptr(new location(22, "M1Part22", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part22));
Hybrid_Automata.addLocation(l);

}

void bm01_module3(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  M1Part23

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.2375825560681141;
Amatrix(1 , 1) = 1.5396007176829094;
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
invariantBoundValue[1] = -240.0;
invariantBoundValue[2] = 240.0;
invariantBoundValue[3] = 300.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 38.90192707862119;
boundValueV[1] = -30.010338536387593;
boundValueV[2] = 335.0745437673987;
boundValueV[3] = -319.88459726801693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part23;

// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 300 & 1 * nu1 <= 240 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -180.0;
guardBoundValue[1] = -300.0;
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

t = transition::ptr(new transition(74,"dummy",23,24,guard_polytope,assignment));

Out_Going_Trans_fromM1Part23.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 240 & 1 * nu1 <= 300 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(75,"dummy",23,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part23.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 300 & 1 * nu1 <= 300 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(76,"dummy",23,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part23.push_back(t);
l = location::ptr(new location(23, "M1Part23", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part23));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part24

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.2375825560681141;
Amatrix(1 , 1) = 1.1031336922959145;
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
invariantBoundValue[1] = -300.0;
invariantBoundValue[2] = 240.0;
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
boundValueV[0] = 38.90192707862119;
boundValueV[1] = -30.010338536387593;
boundValueV[2] = 198.64967637540454;
boundValueV[3] = -167.12483487450461;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part24;

// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 300 & 1 * nu1 <= 300 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(77,"dummy",24,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 360 & 1 * nu1 <= 300 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
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

t = transition::ptr(new transition(78,"dummy",24,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 360 & 1 * nu1 <= 300 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
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

t = transition::ptr(new transition(79,"dummy",24,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 240 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(80,"dummy",24,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 180 & nu2 >= 360 & 1 * nu1 <= 240 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(81,"dummy",24,19,guard_polytope,assignment));

Out_Going_Trans_fromM1Part24.push_back(t);
l = location::ptr(new location(24, "M1Part24", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part24));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part25

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.8380524814759222;
Amatrix(1 , 1) = -1.1031336922959145;
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
invariantBoundValue[0] = -240.0;
invariantBoundValue[2] = 300.0;
invariantBoundValue[3] = 60.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 182.391479562464;
boundValueV[1] = -174.1231199720182;
boundValueV[2] = -198.4784587378641;
boundValueV[3] = 230.003288490284;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part25;

// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 60 & 1 * nu1 <= 300 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(82,"dummy",25,26,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 0 & 1 * nu1 <= 360 & 1 * nu2 <= 60

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(83,"dummy",25,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 60 & 1 * nu1 <= 360 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(84,"dummy",25,32,guard_polytope,assignment));

Out_Going_Trans_fromM1Part25.push_back(t);
l = location::ptr(new location(25, "M1Part25", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part25));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part26

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.8380524814759222;
Amatrix(1 , 1) = -1.5396007176829094;
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
invariantBoundValue[0] = -240.0;
invariantBoundValue[1] = -60.0;
invariantBoundValue[2] = 300.0;
invariantBoundValue[3] = 120.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 182.391479562464;
boundValueV[1] = -174.1231199720182;
boundValueV[2] = -219.18171557562076;
boundValueV[3] = 234.37166009636442;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part26;

// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 120 & 1 * nu1 <= 300 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(85,"dummy",26,27,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 60 & 1 * nu1 <= 360 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(86,"dummy",26,32,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 120 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(87,"dummy",26,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part26.push_back(t);
l = location::ptr(new location(26, "M1Part26", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part26));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part27

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.8380524814759222;
Amatrix(1 , 1) = -0.4364670255720054;
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
invariantBoundValue[0] = -240.0;
invariantBoundValue[1] = -120.0;
invariantBoundValue[2] = 300.0;
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
boundValueV[0] = 182.391479562464;
boundValueV[1] = -174.1231199720182;
boundValueV[2] = -85.66072668363805;
boundValueV[3] = 101.9956158663883;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part27;

// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 180 & 1 * nu1 <= 300 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
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

t = transition::ptr(new transition(88,"dummy",27,28,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 120 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(89,"dummy",27,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
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

t = transition::ptr(new transition(90,"dummy",27,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part27.push_back(t);
l = location::ptr(new location(27, "M1Part27", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part27));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part28

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.8380524814759222;
Amatrix(1 , 1) = 0.4364670255720054;
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
invariantBoundValue[0] = -240.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 300.0;
invariantBoundValue[3] = 240.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 182.391479562464;
boundValueV[1] = -174.1231199720182;
boundValueV[2] = 71.46740352191833;
boundValueV[3] = -55.13251231527094;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part28;

// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 240 & 1 * nu1 <= 300 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(91,"dummy",28,29,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
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

t = transition::ptr(new transition(92,"dummy",28,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 240 & 1 * nu1 <= 360 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(93,"dummy",28,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part28.push_back(t);
l = location::ptr(new location(28, "M1Part28", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part28));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part29

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.8380524814759222;
Amatrix(1 , 1) = 1.5396007176829094;
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
invariantBoundValue[0] = -240.0;
invariantBoundValue[1] = -240.0;
invariantBoundValue[2] = 300.0;
invariantBoundValue[3] = 300.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 182.391479562464;
boundValueV[1] = -174.1231199720182;
boundValueV[2] = 335.0745437673987;
boundValueV[3] = -319.88459726801693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part29;

// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 300 & 1 * nu1 <= 300 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(94,"dummy",29,30,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 240 & 1 * nu1 <= 360 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(95,"dummy",29,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 300 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(96,"dummy",29,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part29.push_back(t);
l = location::ptr(new location(29, "M1Part29", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part29));
Hybrid_Automata.addLocation(l);

}

void bm01_module4(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  M1Part30

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.8380524814759222;
Amatrix(1 , 1) = 1.1031336922959145;
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
invariantBoundValue[0] = -240.0;
invariantBoundValue[1] = -300.0;
invariantBoundValue[2] = 300.0;
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
boundValueV[0] = 182.391479562464;
boundValueV[1] = -174.1231199720182;
boundValueV[2] = 198.64967637540454;
boundValueV[3] = -167.12483487450461;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part30;

// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 300 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -300.0;
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

t = transition::ptr(new transition(97,"dummy",30,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
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

t = transition::ptr(new transition(98,"dummy",30,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
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

t = transition::ptr(new transition(99,"dummy",30,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 360 & 1 * nu1 <= 300 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
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

t = transition::ptr(new transition(100,"dummy",30,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 240 & nu2 >= 360 & 1 * nu1 <= 300 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -240.0;
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

t = transition::ptr(new transition(101,"dummy",30,25,guard_polytope,assignment));

Out_Going_Trans_fromM1Part30.push_back(t);
l = location::ptr(new location(30, "M1Part30", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part30));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part31

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.6004699253613575;
Amatrix(1 , 1) = -1.1031336922959145;
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
invariantBoundValue[0] = -300.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 60.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 108.1311877394636;
boundValueV[1] = -90.97123749456286;
boundValueV[2] = -198.4784587378641;
boundValueV[3] = 230.003288490284;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part31;

// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 60 & 1 * nu1 <= 360 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -60.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(102,"dummy",31,32,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 60 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(103,"dummy",31,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 420 & 1 * nu2 <= 60

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

t = transition::ptr(new transition(104,"dummy",31,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 420 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(105,"dummy",31,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 60 & 1 * nu1 <= 420 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -60.0;
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

t = transition::ptr(new transition(106,"dummy",31,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 60 & 1 * nu1 <= 420 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -60.0;
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

t = transition::ptr(new transition(107,"dummy",31,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part31.push_back(t);
l = location::ptr(new location(31, "M1Part31", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part31));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part32

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.6004699253613575;
Amatrix(1 , 1) = -1.5396007176829094;
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
invariantBoundValue[0] = -300.0;
invariantBoundValue[1] = -60.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 120.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 108.1311877394636;
boundValueV[1] = -90.97123749456286;
boundValueV[2] = -219.18171557562076;
boundValueV[3] = 234.37166009636442;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part32;

// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 120 & 1 * nu1 <= 360 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -120.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(108,"dummy",32,33,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 60 & 1 * nu1 <= 420 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -60.0;
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

t = transition::ptr(new transition(109,"dummy",32,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 60 & 1 * nu1 <= 420 & 1 * nu2 <= 120

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -60.0;
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

t = transition::ptr(new transition(110,"dummy",32,2,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 120 & 1 * nu1 <= 420 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -120.0;
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

t = transition::ptr(new transition(111,"dummy",32,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 120 & 1 * nu1 <= 420 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -120.0;
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

t = transition::ptr(new transition(112,"dummy",32,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part32.push_back(t);
l = location::ptr(new location(32, "M1Part32", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part32));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part33

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.6004699253613575;
Amatrix(1 , 1) = -0.4364670255720054;
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
invariantBoundValue[0] = -300.0;
invariantBoundValue[1] = -120.0;
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
boundValueV[0] = 108.1311877394636;
boundValueV[1] = -90.97123749456286;
boundValueV[2] = -85.66072668363805;
boundValueV[3] = 101.9956158663883;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part33;

// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 180 & 1 * nu1 <= 360 & 1 * nu2 <= 240

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
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

t = transition::ptr(new transition(113,"dummy",33,34,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 120 & 1 * nu1 <= 420 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -120.0;
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

t = transition::ptr(new transition(114,"dummy",33,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 120 & 1 * nu1 <= 420 & 1 * nu2 <= 180

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -120.0;
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

t = transition::ptr(new transition(115,"dummy",33,3,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 420 & 1 * nu2 <= 240

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

t = transition::ptr(new transition(116,"dummy",33,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 420 & 1 * nu2 <= 240

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

t = transition::ptr(new transition(117,"dummy",33,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part33.push_back(t);
l = location::ptr(new location(33, "M1Part33", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part33));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part34

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.6004699253613575;
Amatrix(1 , 1) = 0.4364670255720054;
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
invariantBoundValue[0] = -300.0;
invariantBoundValue[1] = -180.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 240.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 108.1311877394636;
boundValueV[1] = -90.97123749456286;
boundValueV[2] = 71.46740352191833;
boundValueV[3] = -55.13251231527094;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part34;

// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 240 & 1 * nu1 <= 360 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -240.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(118,"dummy",34,35,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 420 & 1 * nu2 <= 240

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

t = transition::ptr(new transition(119,"dummy",34,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 180 & 1 * nu1 <= 420 & 1 * nu2 <= 240

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

t = transition::ptr(new transition(120,"dummy",34,4,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 240 & 1 * nu1 <= 420 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -240.0;
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

t = transition::ptr(new transition(121,"dummy",34,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 240 & 1 * nu1 <= 420 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -240.0;
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

t = transition::ptr(new transition(122,"dummy",34,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part34.push_back(t);
l = location::ptr(new location(34, "M1Part34", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part34));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part35

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.6004699253613575;
Amatrix(1 , 1) = 1.5396007176829094;
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
invariantBoundValue[0] = -300.0;
invariantBoundValue[1] = -240.0;
invariantBoundValue[2] = 360.0;
invariantBoundValue[3] = 300.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

row = 4;
col = 2;
ConstraintsMatrixV.resize(row, col);
ConstraintsMatrixV(0,0)= -1.0;
ConstraintsMatrixV(1,0)= 1.0;
ConstraintsMatrixV(2,1)= -1.0;
ConstraintsMatrixV(3,1)= 1.0;

boundValueV.resize(row);
boundValueV[0] = 108.1311877394636;
boundValueV[1] = -90.97123749456286;
boundValueV[2] = 335.0745437673987;
boundValueV[3] = -319.88459726801693;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part35;

// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 300 & 1 * nu1 <= 360 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
guardBoundValue[1] = -300.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(123,"dummy",35,36,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 240 & 1 * nu1 <= 420 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -240.0;
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

t = transition::ptr(new transition(124,"dummy",35,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 240 & 1 * nu1 <= 420 & 1 * nu2 <= 300

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -240.0;
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

t = transition::ptr(new transition(125,"dummy",35,5,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 300 & 1 * nu1 <= 420 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -300.0;
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

t = transition::ptr(new transition(126,"dummy",35,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 300 & 1 * nu1 <= 420 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -300.0;
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

t = transition::ptr(new transition(127,"dummy",35,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part35.push_back(t);
l = location::ptr(new location(35, "M1Part35", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part35));
Hybrid_Automata.addLocation(l);


// The mode name is  M1Part36

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = 0.6004699253613575;
Amatrix(1 , 1) = 1.1031336922959145;
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
invariantBoundValue[0] = -300.0;
invariantBoundValue[1] = -300.0;
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
boundValueV[0] = 108.1311877394636;
boundValueV[1] = -90.97123749456286;
boundValueV[2] = 198.64967637540454;
boundValueV[3] = -167.12483487450461;
system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, boundSignV));


std::list<transition::ptr> Out_Going_Trans_fromM1Part36;

// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
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

t = transition::ptr(new transition(128,"dummy",36,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 300 & nu2 >= 360 & 1 * nu1 <= 360 & 1 * nu2 <= 420

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -300.0;
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

t = transition::ptr(new transition(129,"dummy",36,31,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 300 & 1 * nu1 <= 420 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -300.0;
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

t = transition::ptr(new transition(130,"dummy",36,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 300 & 1 * nu1 <= 420 & 1 * nu2 <= 360

row = 4;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -360.0;
guardBoundValue[1] = -300.0;
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

t = transition::ptr(new transition(131,"dummy",36,6,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 0 & nu2 >= 360 & 1 * nu1 <= 60 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(132,"dummy",36,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 0 & 1 * nu1 <= 420 & 1 * nu2 <= 60

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

t = transition::ptr(new transition(133,"dummy",36,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
// The transition label is dummy

// Original guard: nu1 >= 360 & nu2 >= 360 & 1 * nu1 <= 420 & 1 * nu2 <= 420

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

t = transition::ptr(new transition(134,"dummy",36,1,guard_polytope,assignment));

Out_Going_Trans_fromM1Part36.push_back(t);
l = location::ptr(new location(36, "M1Part36", system_dynamics, invariant, true, Out_Going_Trans_fromM1Part36));
Hybrid_Automata.addLocation(l);

}

