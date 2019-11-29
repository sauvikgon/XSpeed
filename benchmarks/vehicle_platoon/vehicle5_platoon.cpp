// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/amit/MyData/Tools/spaceex_exe/plattonVehicle/5_vehicle_platoon/5_vehicle_platoon.xml
// Command Line arguments: -tool xspeed "" -verbose -output /home/amit/MyData/Tools/spaceex_exe/plattonVehicle/5_vehicle_platoon/5VehiclePlatoon.cpp -input /home/amit/MyData/Tools/spaceex_exe/plattonVehicle/5_vehicle_platoon/5_vehicle_platoon.xml /home/amit/MyData/Tools/spaceex_exe/plattonVehicle/5_vehicle_platoon/5_vehicle_platoon.cfg


#include "../../benchmarks/vehicle_platoon/vehicle5_platoon.h"

void set_platoon5_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;


unsigned int dim;
size_type row, col;

polytope::ptr initial_polytope_I0, forbid_polytope;
location::ptr l;
transition::ptr t;
polytope::ptr invariant = polytope::ptr(new polytope()); //creating a universe invariant polytope; Note dim set to 0

polytope::ptr guard_polytope;

Dynamics system_dynamics;

math::matrix<double> ConstraintsMatrixI , ConstraintsMatrixV, invariantConstraintsMatrix , guardConstraintsMatrix , Amatrix , Bmatrix,forbiddenMatrixI;

std::vector<double> boundValueI,boundValueV , C , invariantBoundValue , guardBoundValue, boundValueF;

int boundSignI=1;

Assign assignment;
math::matrix<double> R;

// The mode name is  ok

row = 17;
col = 17;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 1) = 1.0;
Amatrix(1 , 2) = -1.0;
Amatrix(2 , 0) = 1.7152555329;
Amatrix(2 , 1) = 3.9705119979;
Amatrix(2 , 2) = -4.3600526739;
Amatrix(2 , 3) = -0.9999330812;
Amatrix(2 , 4) = -1.5731541104;
Amatrix(2 , 5) = 0.2669165553;
Amatrix(2 , 6) = -0.2215507198;
Amatrix(2 , 7) = -0.4303855023;
Amatrix(2 , 8) = 0.0669078193;
Amatrix(2 , 9) = -0.0881500219;
Amatrix(2 , 10) = -0.1881468451;
Amatrix(2 , 11) = 0.0322187056;
Amatrix(2 , 12) = -0.0343095071;
Amatrix(2 , 13) = -0.0767587194;
Amatrix(2 , 14) = 0.0226660281;
Amatrix(3 , 4) = 1.0;
Amatrix(3 , 15) = 1.0;
Amatrix(4 , 2) = 1.0;
Amatrix(4 , 5) = -1.0;
Amatrix(5 , 0) = 0.7153224517;
Amatrix(5 , 1) = 2.3973578876;
Amatrix(5 , 2) = 0.2669165553;
Amatrix(5 , 3) = 1.4937048131;
Amatrix(5 , 4) = 3.5401264957;
Amatrix(5 , 5) = -4.2931448546;
Amatrix(5 , 6) = -1.0880831031;
Amatrix(5 , 7) = -1.7613009555;
Amatrix(5 , 8) = 0.2991352608;
Amatrix(5 , 9) = -0.2558602268;
Amatrix(5 , 10) = -0.5071442217;
Amatrix(5 , 11) = 0.0895738474;
Amatrix(5 , 12) = -0.0881500219;
Amatrix(5 , 13) = -0.1881468451;
Amatrix(5 , 14) = 0.0548847337;
Amatrix(6 , 7) = 1.0;
Amatrix(7 , 5) = 1.0;
Amatrix(7 , 8) = -1.0;
Amatrix(8 , 0) = 0.493771732;
Amatrix(8 , 1) = 1.9669723853;
Amatrix(8 , 2) = 0.0669078193;
Amatrix(8 , 3) = 0.6271724298;
Amatrix(8 , 4) = 2.2092110425;
Amatrix(8 , 5) = 0.2991352608;
Amatrix(8 , 6) = 1.4593953061;
Amatrix(8 , 7) = 3.4633677762;
Amatrix(8 , 8) = -4.2704788265;
Amatrix(8 , 9) = -1.0880831031;
Amatrix(8 , 10) = -1.7613009555;
Amatrix(8 , 11) = 0.3218012889;
Amatrix(8 , 12) = -0.2215507198;
Amatrix(8 , 13) = -0.4303855023;
Amatrix(8 , 14) = 0.121792553;
Amatrix(9 , 10) = 1.0;
Amatrix(10 , 8) = 1.0;
Amatrix(10 , 11) = -1.0;
Amatrix(11 , 0) = 0.40562171;
Amatrix(11 , 1) = 1.7788255402;
Amatrix(11 , 2) = 0.0322187056;
Amatrix(11 , 3) = 0.4594622249;
Amatrix(11 , 4) = 1.8902136659;
Amatrix(11 , 5) = 0.0895738474;
Amatrix(11 , 6) = 0.6271724298;
Amatrix(11 , 7) = 2.2092110425;
Amatrix(11 , 8) = 0.3218012889;
Amatrix(11 , 9) = 1.4937048131;
Amatrix(11 , 10) = 3.5401264957;
Amatrix(11 , 11) = -4.2382601209;
Amatrix(11 , 12) = -0.9999330812;
Amatrix(11 , 13) = -1.5731541104;
Amatrix(11 , 14) = 0.3887091083;
Amatrix(12 , 13) = 1.0;
Amatrix(13 , 11) = 1.0;
Amatrix(13 , 14) = -1.0;
Amatrix(14 , 0) = 0.371312203;
Amatrix(14 , 1) = 1.7020668208;
Amatrix(14 , 2) = 0.0226660281;
Amatrix(14 , 3) = 0.40562171;
Amatrix(14 , 4) = 1.7788255402;
Amatrix(14 , 5) = 0.0548847337;
Amatrix(14 , 6) = 0.493771732;
Amatrix(14 , 7) = 1.9669723853;
Amatrix(14 , 8) = 0.121792553;
Amatrix(14 , 9) = 0.7153224517;
Amatrix(14 , 10) = 2.3973578876;
Amatrix(14 , 11) = 0.3887091083;
Amatrix(14 , 12) = 1.7152555329;
Amatrix(14 , 13) = 3.9705119979;
Amatrix(14 , 14) = -3.9713435656;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[16] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


std::list<transition::ptr> Out_Going_Trans_fromok;


l =location::ptr(new location(1, "ok", system_dynamics, invariant, false, Out_Going_Trans_fromok));

Hybrid_Automata.addInitial_Location(l);
Hybrid_Automata.addLocation(l);


row = 34;
col = 17;
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
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1.1;
boundValueI[1]=-0.9;
boundValueI[2]=1.1;
boundValueI[3]=-0.9;
boundValueI[4]=1.1;
boundValueI[5]=-0.9;
boundValueI[6]=1.1;
boundValueI[7]=-0.9;
boundValueI[8]=1.1;
boundValueI[9]=-0.9;
boundValueI[10]=1.1;
boundValueI[11]=-0.9;
boundValueI[12]=1.1;
boundValueI[13]=-0.9;
boundValueI[14]=1.1;
boundValueI[15]=-0.9;
boundValueI[16]=1.1;
boundValueI[17]=-0.9;
boundValueI[18]=1.1;
boundValueI[19]=-0.9;
boundValueI[20]=1.1;
boundValueI[21]=-0.9;
boundValueI[22]=1.1;
boundValueI[23]=-0.9;
boundValueI[24]=1.1;
boundValueI[25]=-0.9;
boundValueI[26]=1.1;
boundValueI[27]=-0.9;
boundValueI[28]=1.1;
boundValueI[29]=-0.9;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =1;

symbolic_states::ptr S0;

initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

init_state_list.push_back(I0);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("x1",0);
Hybrid_Automata.insert_to_map("x1prime",1);
Hybrid_Automata.insert_to_map("a1",2);
Hybrid_Automata.insert_to_map("x2",3);
Hybrid_Automata.insert_to_map("x2prime",4);
Hybrid_Automata.insert_to_map("a2",5);
Hybrid_Automata.insert_to_map("x3",6);
Hybrid_Automata.insert_to_map("x3prime",7);
Hybrid_Automata.insert_to_map("a3",8);
Hybrid_Automata.insert_to_map("x4",9);
Hybrid_Automata.insert_to_map("x4prime",10);
Hybrid_Automata.insert_to_map("a4",11);
Hybrid_Automata.insert_to_map("x5",12);
Hybrid_Automata.insert_to_map("x5prime",13);
Hybrid_Automata.insert_to_map("a5",14);
Hybrid_Automata.insert_to_map("b",15);
Hybrid_Automata.insert_to_map("t",16);

}
