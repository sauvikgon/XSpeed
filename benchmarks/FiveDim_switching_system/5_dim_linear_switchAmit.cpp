// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/movies/MyData/Models-HybridSystems/shyambabu_Hyst-XSpeed/5_dim_linear_switch/5_dim_linear_switchCORRECTED.xml
// Command Line arguments: -tool xspeed "-time_dynamics false" -output /home/movies/MyData/Models-HybridSystems/shyambabu_Hyst-XSpeed/5_dim_linear_switch/5_dim_linear_switchAmit.cpp -input /home/movies/MyData/Models-HybridSystems/shyambabu_Hyst-XSpeed/5_dim_linear_switch/5_dim_linear_switchCORRECTED.xml /home/movies/MyData/Models-HybridSystems/shyambabu_Hyst-XSpeed/5_dim_linear_switch/5_dim_linear_switch.cfg


#include "benchmarks/FiveDim_switching_linear_system/5_dim_linear_switchCORRECTED.h"

void set_5_dim_linear_switchCORRECTED_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {


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

// The mode name is  q1

row = 6;
col = 6;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.8047;
Amatrix(0 , 1) = 8.742;
Amatrix(0 , 2) = -2.4591;
Amatrix(0 , 3) = -8.2714;
Amatrix(0 , 4) = -1.864;
Amatrix(1 , 0) = -8.6329;
Amatrix(1 , 1) = -0.586;
Amatrix(1 , 2) = -2.1006;
Amatrix(1 , 3) = 3.6035;
Amatrix(1 , 4) = -1.8423;
Amatrix(2 , 0) = 2.4511;
Amatrix(2 , 1) = 2.2394;
Amatrix(2 , 2) = -0.7538;
Amatrix(2 , 3) = -3.6934;
Amatrix(2 , 4) = 2.4585;
Amatrix(3 , 0) = 8.3858;
Amatrix(3 , 1) = -3.1739;
Amatrix(3 , 2) = 3.7822;
Amatrix(3 , 3) = -0.6249;
Amatrix(3 , 4) = 1.8829;
Amatrix(4 , 0) = 1.8302;
Amatrix(4 , 1) = 1.9869;
Amatrix(4 , 2) = -2.4539;
Amatrix(4 , 3) = -1.7726;
Amatrix(4 , 4) = -0.7911;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[5] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 2;
col = 6;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -3.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromq1;

// The transition label is null

// Original guard: x1 = 3

row = 2;
col = 6;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 6;
col = 6;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
R(5,5) =  1.0;
std::vector<double> w(row);
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(1,"null",1,2,guard_polytope,assignment));

Out_Going_Trans_fromq1.push_back(t);
l = location::ptr(new location(1, "q1", system_dynamics, invariant, true, Out_Going_Trans_fromq1));

Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);


// The mode name is  q2

row = 6;
col = 6;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.8316;
Amatrix(0 , 1) = 8.7658;
Amatrix(0 , 2) = -2.4744;
Amatrix(0 , 3) = -8.2608;
Amatrix(0 , 4) = -1.9033;
Amatrix(1 , 0) = -8.6329;
Amatrix(1 , 1) = -0.586;
Amatrix(1 , 2) = -2.1006;
Amatrix(1 , 3) = 3.6035;
Amatrix(1 , 4) = -1.8423;
Amatrix(2 , 0) = 2.4511;
Amatrix(2 , 1) = 2.2394;
Amatrix(2 , 2) = -0.7538;
Amatrix(2 , 3) = -3.6934;
Amatrix(2 , 4) = 2.4585;
Amatrix(3 , 0) = 8.3858;
Amatrix(3 , 1) = -3.1739;
Amatrix(3 , 2) = 3.7822;
Amatrix(3 , 3) = -0.6249;
Amatrix(3 , 4) = 1.8829;
Amatrix(4 , 0) = 1.5964;
Amatrix(4 , 1) = 2.1936;
Amatrix(4 , 2) = -2.5872;
Amatrix(4 , 3) = -1.6812;
Amatrix(4 , 4) = -1.1324;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[5] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 2;
col = 6;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -2.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromq2;

// The transition label is null

// Original guard: x1 = 2

row = 2;
col = 6;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 6;
col = 6;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
R(5,5) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(2,"null",2,3,guard_polytope,assignment));

Out_Going_Trans_fromq2.push_back(t);
l = location::ptr(new location(2, "q2", system_dynamics, invariant, true, Out_Going_Trans_fromq2));
Hybrid_Automata.addLocation(l);


// The mode name is  q3

row = 6;
col = 6;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -0.9275;
Amatrix(0 , 1) = 8.8628;
Amatrix(0 , 2) = -2.5428;
Amatrix(0 , 3) = -8.2329;
Amatrix(0 , 4) = -2.0324;
Amatrix(1 , 0) = -8.6329;
Amatrix(1 , 1) = -0.586;
Amatrix(1 , 2) = -2.1006;
Amatrix(1 , 3) = 3.6035;
Amatrix(1 , 4) = -1.8423;
Amatrix(2 , 0) = 2.4511;
Amatrix(2 , 1) = 2.2394;
Amatrix(2 , 2) = -0.7538;
Amatrix(2 , 3) = -3.6934;
Amatrix(2 , 4) = 2.4585;
Amatrix(3 , 0) = 8.3858;
Amatrix(3 , 1) = -3.1739;
Amatrix(3 , 2) = 3.7822;
Amatrix(3 , 3) = -0.6249;
Amatrix(3 , 4) = 1.8829;
Amatrix(4 , 0) = 0.7635;
Amatrix(4 , 1) = 3.0357;
Amatrix(4 , 2) = -3.1814;
Amatrix(4 , 3) = -1.4388;
Amatrix(4 , 4) = -2.2538;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[5] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 2;
col = 6;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = -1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromq3;

// The transition label is null

// Original guard: x1 = 1

row = 2;
col = 6;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 6;
col = 6;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
R(5,5) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(3,"null",3,4,guard_polytope,assignment));

Out_Going_Trans_fromq3.push_back(t);
l = location::ptr(new location(3, "q3", system_dynamics, invariant, true, Out_Going_Trans_fromq3));
Hybrid_Automata.addLocation(l);


// The mode name is  q4

row = 6;
col = 6;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -1.0145;
Amatrix(0 , 1) = 8.9701;
Amatrix(0 , 2) = -2.6207;
Amatrix(0 , 3) = -8.2199;
Amatrix(0 , 4) = -2.1469;
Amatrix(1 , 0) = -8.6329;
Amatrix(1 , 1) = -0.586;
Amatrix(1 , 2) = -2.1006;
Amatrix(1 , 3) = 3.6035;
Amatrix(1 , 4) = -1.8423;
Amatrix(2 , 0) = 2.4511;
Amatrix(2 , 1) = 2.2394;
Amatrix(2 , 2) = -0.7538;
Amatrix(2 , 3) = -3.6934;
Amatrix(2 , 4) = 2.4585;
Amatrix(3 , 0) = 8.3858;
Amatrix(3 , 1) = -3.1739;
Amatrix(3 , 2) = 3.7822;
Amatrix(3 , 3) = -0.6249;
Amatrix(3 , 4) = 1.8829;
Amatrix(4 , 0) = 0.0076;
Amatrix(4 , 1) = 3.9682;
Amatrix(4 , 2) = -3.8578;
Amatrix(4 , 3) = -1.3253;
Amatrix(4 , 4) = -3.2477;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[5] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 2;
col = 6;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromq4;

// The transition label is null

// Original guard: x1 = 0

row = 2;
col = 6;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 6;
col = 6;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
R(5,5) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(4,"null",4,5,guard_polytope,assignment));

Out_Going_Trans_fromq4.push_back(t);
l = location::ptr(new location(4, "q4", system_dynamics, invariant, true, Out_Going_Trans_fromq4));
Hybrid_Automata.addLocation(l);


// The mode name is  q5

row = 6;
col = 6;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 0) = -1.4021;
Amatrix(0 , 1) = 10.1647;
Amatrix(0 , 2) = -3.3937;
Amatrix(0 , 3) = -8.5139;
Amatrix(0 , 4) = -2.9602;
Amatrix(1 , 0) = -8.6329;
Amatrix(1 , 1) = -0.586;
Amatrix(1 , 2) = -2.1006;
Amatrix(1 , 3) = 3.6035;
Amatrix(1 , 4) = -1.8423;
Amatrix(2 , 0) = 2.4511;
Amatrix(2 , 1) = 2.2394;
Amatrix(2 , 2) = -0.7538;
Amatrix(2 , 3) = -3.6934;
Amatrix(2 , 4) = 2.4585;
Amatrix(3 , 0) = 8.3858;
Amatrix(3 , 1) = -3.1739;
Amatrix(3 , 2) = 3.7822;
Amatrix(3 , 3) = -0.6249;
Amatrix(3 , 4) = 1.8829;
Amatrix(4 , 0) = -3.3585;
Amatrix(4 , 1) = 14.3426;
Amatrix(4 , 2) = -10.5703;
Amatrix(4 , 3) = -3.8785;
Amatrix(4 , 4) = -10.3111;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[5] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 2;
col = 6;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[0] = 1.0;
invariant = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromq5;

// The transition label is null

// Original guard: x1 = 1

row = 2;
col = 6;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guard_polytope = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


row = 6;
col = 6;
R.resize(row, col);
R.clear();
R(0,0) =  1.0;
R(1,1) =  1.0;
R(2,2) =  1.0;
R(3,3) =  1.0;
R(4,4) =  1.0;
R(5,5) =  1.0;
w.assign(row,0);


assignment.Map = R;
assignment.b = w;

t = transition::ptr(new transition(5,"null",5,1,guard_polytope,assignment));

Out_Going_Trans_fromq5.push_back(t);
l = location::ptr(new location(5, "q5", system_dynamics, invariant, true, Out_Going_Trans_fromq5));
Hybrid_Automata.addLocation(l);


row = 12;
col = 6;
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
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=3.3;
boundValueI[1]=-3.1;
boundValueI[2]=4;
boundValueI[3]=-4;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =1;

symbolic_states::ptr S0;

initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

init_state_list.push_back(I0);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("x1",0);
Hybrid_Automata.insert_to_map("x2",1);
Hybrid_Automata.insert_to_map("x3",2);
Hybrid_Automata.insert_to_map("x4",3);
Hybrid_Automata.insert_to_map("x5",4);
Hybrid_Automata.insert_to_map("t",5);

}
