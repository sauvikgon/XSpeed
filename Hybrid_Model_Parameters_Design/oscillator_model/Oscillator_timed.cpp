// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/PostDocNITM/Benchmarks/Oscillator_timed.xml
// Command Line arguments: -tool xspeed "" -output /home/movies/MyData/PostDocNITM/Benchmarks/Oscillator_timed.cpp -input /home/movies/MyData/PostDocNITM/Benchmarks/Oscillator_timed.xml /home/movies/MyData/PostDocNITM/Benchmarks/Oscillator_timed.cfg


#include "Oscillator_timed.h"
void setOscillator_timedmodel(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

// The mode name is  loc1

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -2.0;
Amatrix(1 , 1) = -1.0;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = 1.4;
C[1] = -0.7;
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= 1.0;
invariantConstraintsMatrix(1,0)= -0.714286;
invariantConstraintsMatrix(1,1)= -1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc1;

// The transition label is hop1

// Original guard: x = 0 & 0.714286 * x + y >= 0

row = 3;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,0) = -0.714286;
guardConstraintsMatrix(2,1) = -1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
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

t = transition::ptr(new transition(1,"hop1",1,2,guard_polytope,assignment));

Out_Going_Trans_fromloc1.push_back(t);
l = location::ptr(new location(1, "loc1", system_dynamics, invariant, true, Out_Going_Trans_fromloc1));
Hybrid_Automata.addLocation(l);


// The mode name is  loc3

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -2.0;
Amatrix(1 , 1) = -1.0;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = 1.4;
C[1] = -0.7;
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 3;
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

// The transition label is hop2

// Original guard: x >= 0 & y + 0.714286 * x = 0

row = 3;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = -0.714286;
guardConstraintsMatrix(1,1) = -1.0;
guardConstraintsMatrix(2,0) = 0.714286;
guardConstraintsMatrix(2,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(2,"hop2",2,4,guard_polytope,assignment));

Out_Going_Trans_fromloc3.push_back(t);
l = location::ptr(new location(2, "loc3", system_dynamics, invariant, true, Out_Going_Trans_fromloc3));

Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);


// The mode name is  pp

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -2.0;
Amatrix(1 , 1) = -1.0;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = -1.4;
C[1] = 0.7;
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 3;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= 1.0;
invariantConstraintsMatrix(1,0)= 0.714286;
invariantConstraintsMatrix(1,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_frompp;

// The transition label is hop4

// Original guard: x <= 0 & y + 0.714286 * x = 0

row = 3;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = 1.0;
guardConstraintsMatrix(1,0) = -0.714286;
guardConstraintsMatrix(1,1) = -1.0;
guardConstraintsMatrix(2,0) = 0.714286;
guardConstraintsMatrix(2,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(3,"hop4",3,1,guard_polytope,assignment));

Out_Going_Trans_frompp.push_back(t);
l = location::ptr(new location(3, "pp", system_dynamics, invariant, true, Out_Going_Trans_frompp));
Hybrid_Automata.addLocation(l);


// The mode name is  loc4

row = 3;
col = 3;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -2.0;
Amatrix(1 , 1) = -1.0;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[0] = -1.4;
C[1] = 0.7;
C[2] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 4;
col = 3;
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

// The transition label is hop3

// Original guard: x = 0 & 0.714286 * x + y <= 0

row = 3;
col = 3;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,0) = 0.714286;
guardConstraintsMatrix(2,1) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 3;
col = 3;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(4,"hop3",4,3,guard_polytope,assignment));

Out_Going_Trans_fromloc4.push_back(t);
l = location::ptr(new location(4, "loc4", system_dynamics, invariant, true, Out_Going_Trans_fromloc4));
Hybrid_Automata.addLocation(l);


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
boundValueI[0]=0.3;
boundValueI[1]=-0.2;
boundValueI[2]=0.1;
boundValueI[3]=0.1;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =2;

symbolic_states::ptr S0;

initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

init_state_list.push_back(I0);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("x",0);
Hybrid_Automata.insert_to_map("y",1);
Hybrid_Automata.insert_to_map("t",2);

}
