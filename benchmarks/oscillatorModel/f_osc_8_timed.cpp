// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/PostDocNITM/Benchmarks/timed/f_osc_8_timed.xml
// Command Line arguments: -tool xspeed "" -output /home/movies/MyData/PostDocNITM/Benchmarks/timed/f_osc_8_timed.cpp -input /home/movies/MyData/PostDocNITM/Benchmarks/timed/f_osc_8_timed.xml /home/movies/MyData/PostDocNITM/Benchmarks/timed/f_osc_8_timed.cfg


#include <benchmarks/oscillatorModel/f_osc_8_timed.h>

void set_f_osc_8_timed(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

row = 11;
col = 11;
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
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = 1.4;
C[1] = -0.7;
C[10] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 11;
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
col = 11;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,0) = -0.714286;
guardConstraintsMatrix(2,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 11;
col = 11;
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
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(1,"null",1,3,guard_polytope,assignment));

Out_Going_Trans_fromloc2.push_back(t);
l = location::ptr(new location(1, "loc2", system_dynamics, invariant, true, Out_Going_Trans_fromloc2));
Hybrid_Automata.addLocation(l);


// The mode name is  loc1

row = 11;
col = 11;
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
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = -1.4;
C[1] = 0.7;
C[10] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 11;
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
col = 11;

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


row = 11;
col = 11;
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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(2,"null",2,1,guard_polytope,assignment));

Out_Going_Trans_fromloc1.push_back(t);
l = location::ptr(new location(2, "loc1", system_dynamics, invariant, true, Out_Going_Trans_fromloc1));
Hybrid_Automata.addLocation(l);


// The mode name is  loc3

row = 11;
col = 11;
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
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = 1.4;
C[1] = -0.7;
C[10] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 11;
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
col = 11;

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


row = 11;
col = 11;
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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(3,"null",3,4,guard_polytope,assignment));

Out_Going_Trans_fromloc3.push_back(t);
l = location::ptr(new location(3, "loc3", system_dynamics, invariant, true, Out_Going_Trans_fromloc3));

Hybrid_Automata.addInitialLocation(l);
Hybrid_Automata.addLocation(l);


// The mode name is  loc4

row = 11;
col = 11;
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
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = -1.4;
C[1] = 0.7;
C[10] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 11;
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
col = 11;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,0) = 0.714286;
guardConstraintsMatrix(2,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 11;
col = 11;
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
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(4,"null",4,2,guard_polytope,assignment));

Out_Going_Trans_fromloc4.push_back(t);
l = location::ptr(new location(4, "loc4", system_dynamics, invariant, true, Out_Going_Trans_fromloc4));
Hybrid_Automata.addLocation(l);


row = 22;
col = 11;
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
Hybrid_Automata.insert_to_map("f4ax1",2);
Hybrid_Automata.insert_to_map("f4ax2",3);
Hybrid_Automata.insert_to_map("f4ax3",4);
Hybrid_Automata.insert_to_map("f8x1",5);
Hybrid_Automata.insert_to_map("f4bx1",6);
Hybrid_Automata.insert_to_map("f4bx2",7);
Hybrid_Automata.insert_to_map("f4bx3",8);
Hybrid_Automata.insert_to_map("z",9);
Hybrid_Automata.insert_to_map("t",10);

}
