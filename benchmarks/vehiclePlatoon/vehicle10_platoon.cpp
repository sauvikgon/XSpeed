// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/amit/MyData/Tools/spaceex_exe/plattonVehicle/10_vehicle_platoon/vehicle10_platoon.xml
// Command Line arguments: -tool xspeed "" -verbose -output /home/amit/MyData/Tools/spaceex_exe/plattonVehicle/10_vehicle_platoon/vehicle10_platoon.cpp -input /home/amit/MyData/Tools/spaceex_exe/plattonVehicle/10_vehicle_platoon/vehicle10_platoon.xml /home/amit/MyData/Tools/spaceex_exe/plattonVehicle/10_vehicle_platoon/vehicle10_platoon.cfg


#include <benchmarks/vehiclePlatoon/vehicle10_platoon.h>
void set_platoon10_model(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters) {


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

int boundSignI=1, invariantBoundSign=1, guardBoundSign=1, boundSignV=1;

Assign assignment;
math::matrix<double> R;

// The mode name is  ok

row = 31;
col = 31;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 1) = 1.0;
Amatrix(1 , 2) = -1.0;
Amatrix(2 , 0) = 1.702423734;
Amatrix(2 , 1) = 3.929356551;
Amatrix(2 , 2) = -4.3607983776;
Amatrix(2 , 3) = -1.01374489;
Amatrix(2 , 4) = -1.6167727749;
Amatrix(2 , 5) = 0.2653009364;
Amatrix(2 , 6) = -0.2375199245;
Amatrix(2 , 7) = -0.4793543458;
Amatrix(2 , 8) = 0.06412815;
Amatrix(2 , 9) = -0.1079326841;
Amatrix(2 , 10) = -0.2463610381;
Amatrix(2 , 11) = 0.0276872161;
Amatrix(2 , 12) = -0.0605561959;
Amatrix(2 , 13) = -0.1501445039;
Amatrix(2 , 14) = 0.0151944922;
Amatrix(2 , 15) = -0.0374830081;
Amatrix(2 , 16) = -0.0986391305;
Amatrix(2 , 17) = 0.009628751;
Amatrix(2 , 18) = -0.0242136837;
Amatrix(2 , 19) = -0.0665592904;
Amatrix(2 , 20) = 0.0067836913;
Amatrix(2 , 21) = -0.015601062;
Amatrix(2 , 22) = -0.0442510048;
Amatrix(2 , 23) = 0.0052325207;
Amatrix(2 , 24) = -0.0093924696;
Amatrix(2 , 25) = -0.0272127915;
Amatrix(2 , 26) = 0.0043984935;
Amatrix(2 , 27) = -0.0044278796;
Amatrix(2 , 28) = -0.0129879863;
Amatrix(2 , 29) = 0.0040303349;
Amatrix(3 , 4) = 1.0;
Amatrix(4 , 2) = 1.0;
Amatrix(4 , 5) = -1.0;
Amatrix(5 , 0) = 0.688678844;
Amatrix(5 , 1) = 2.3125837761;
Amatrix(5 , 2) = 0.2653009364;
Amatrix(5 , 3) = 1.4649038095;
Amatrix(5 , 4) = 3.4500022052;
Amatrix(5 , 5) = -4.2966702275;
Amatrix(5 , 6) = -1.1216775741;
Amatrix(5 , 7) = -1.863133813;
Amatrix(5 , 8) = 0.2929881525;
Amatrix(5 , 9) = -0.2980761204;
Amatrix(5 , 10) = -0.6294988497;
Amatrix(5 , 11) = 0.0793226422;
Amatrix(5 , 12) = -0.1454156921;
Amatrix(5 , 13) = -0.3450001686;
Amatrix(5 , 14) = 0.0373159671;
Amatrix(5 , 15) = -0.0847698796;
Amatrix(5 , 16) = -0.2167037943;
Amatrix(5 , 17) = 0.0219781835;
Amatrix(5 , 18) = -0.0530840701;
Amatrix(5 , 19) = -0.1428901352;
Amatrix(5 , 20) = 0.0148612718;
Amatrix(5 , 21) = -0.0336061533;
Amatrix(5 , 22) = -0.0937720819;
Amatrix(5 , 23) = 0.0111821848;
Amatrix(5 , 24) = -0.0200289416;
Amatrix(5 , 25) = -0.057238991;
Amatrix(5 , 26) = 0.0092628557;
Amatrix(5 , 27) = -0.0093924696;
Amatrix(5 , 28) = -0.0272127915;
Amatrix(5 , 29) = 0.0084288284;
Amatrix(6 , 7) = 1.0;
Amatrix(7 , 5) = 1.0;
Amatrix(7 , 8) = -1.0;
Amatrix(8 , 0) = 0.4511589195;
Amatrix(8 , 1) = 1.8332294303;
Amatrix(8 , 2) = 0.06412815;
Amatrix(8 , 3) = 0.5807461599;
Amatrix(8 , 4) = 2.066222738;
Amatrix(8 , 5) = 0.2929881525;
Amatrix(8 , 6) = 1.4043476136;
Amatrix(8 , 7) = 3.2998577013;
Amatrix(8 , 8) = -4.2814757354;
Amatrix(8 , 9) = -1.1591605822;
Amatrix(8 , 10) = -1.9617729435;
Amatrix(8 , 11) = 0.3026169036;
Amatrix(8 , 12) = -0.3222898041;
Amatrix(8 , 13) = -0.6960581401;
Amatrix(8 , 14) = 0.0861063336;
Amatrix(8 , 15) = -0.1610167541;
Amatrix(8 , 16) = -0.3892511733;
Amatrix(8 , 17) = 0.0425484878;
Amatrix(8 , 18) = -0.0941623492;
Amatrix(8 , 19) = -0.2439165858;
Amatrix(8 , 20) = 0.026376677;
Amatrix(8 , 21) = -0.0575119497;
Amatrix(8 , 22) = -0.1558781215;
Amatrix(8 , 23) = 0.0188916067;
Amatrix(8 , 24) = -0.0336061533;
Amatrix(8 , 25) = -0.0937720819;
Amatrix(8 , 26) = 0.0152125197;
Amatrix(8 , 27) = -0.015601062;
Amatrix(8 , 28) = -0.0442510048;
Amatrix(8 , 29) = 0.0136613491;
Amatrix(9 , 10) = 1.0;
Amatrix(10 , 8) = 1.0;
Amatrix(10 , 11) = -1.0;
Amatrix(11 , 0) = 0.3432262354;
Amatrix(11 , 1) = 1.5868683922;
Amatrix(11 , 2) = 0.0276872161;
Amatrix(11 , 3) = 0.3906027236;
Amatrix(11 , 4) = 1.6830849264;
Amatrix(11 , 5) = 0.0793226422;
Amatrix(11 , 6) = 0.5432631518;
Amatrix(11 , 7) = 1.9675836075;
Amatrix(11 , 8) = 0.3026169036;
Amatrix(11 , 9) = 1.3801339299;
Amatrix(11 , 10) = 3.2332984109;
Amatrix(11 , 11) = -4.274692044;
Amatrix(11 , 12) = -1.1747616442;
Amatrix(11 , 13) = -2.0060239482;
Amatrix(11 , 14) = 0.3078494243;
Amatrix(11 , 15) = -0.3316822737;
Amatrix(11 , 16) = -0.7232709316;
Amatrix(11 , 17) = 0.090504827;
Amatrix(11 , 18) = -0.1654446337;
Amatrix(11 , 19) = -0.4022391596;
Amatrix(11 , 20) = 0.0465788228;
Amatrix(11 , 21) = -0.0941623492;
Amatrix(11 , 22) = -0.2439165858;
Amatrix(11 , 23) = 0.0304070119;
Amatrix(11 , 24) = -0.0530840701;
Amatrix(11 , 25) = -0.1428901352;
Amatrix(11 , 26) = 0.0232901001;
Amatrix(11 , 27) = -0.0242136837;
Amatrix(11 , 28) = -0.0665592904;
Amatrix(11 , 29) = 0.0204450405;
Amatrix(12 , 13) = 1.0;
Amatrix(13 , 11) = 1.0;
Amatrix(13 , 14) = -1.0;
Amatrix(14 , 0) = 0.2826700395;
Amatrix(14 , 1) = 1.4367238883;
Amatrix(14 , 2) = 0.0151944922;
Amatrix(14 , 3) = 0.3057432273;
Amatrix(14 , 4) = 1.4882292617;
Amatrix(14 , 5) = 0.0373159671;
Amatrix(14 , 6) = 0.3663890398;
Amatrix(14 , 7) = 1.616525636;
Amatrix(14 , 8) = 0.0861063336;
Amatrix(14 , 9) = 0.5276620899;
Amatrix(14 , 10) = 1.9233326028;
Amatrix(14 , 11) = 0.3078494243;
Amatrix(14 , 12) = 1.3707414603;
Amatrix(14 , 13) = 3.2060856194;
Amatrix(14 , 14) = -4.2702935506;
Amatrix(14 , 15) = -1.1791895238;
Amatrix(14 , 16) = -2.0190119345;
Amatrix(14 , 17) = 0.3118797592;
Amatrix(14 , 18) = -0.3316822737;
Amatrix(14 , 19) = -0.7232709316;
Amatrix(14 , 20) = 0.094535162;
Amatrix(14 , 21) = -0.1610167541;
Amatrix(14 , 22) = -0.3892511733;
Amatrix(14 , 23) = 0.0509773162;
Amatrix(14 , 24) = -0.0847698796;
Amatrix(14 , 25) = -0.2167037943;
Amatrix(14 , 26) = 0.0356395326;
Amatrix(14 , 27) = -0.0374830081;
Amatrix(14 , 28) = -0.0986391305;
Amatrix(14 , 29) = 0.0300737915;
Amatrix(15 , 16) = 1.0;
Amatrix(16 , 14) = 1.0;
Amatrix(16 , 17) = -1.0;
Amatrix(17 , 0) = 0.2451870315;
Amatrix(17 , 1) = 1.3380847578;
Amatrix(17 , 2) = 0.009628751;
Amatrix(17 , 3) = 0.2584563558;
Amatrix(17 , 4) = 1.3701645979;
Amatrix(17 , 5) = 0.0219781835;
Amatrix(17 , 6) = 0.2901421653;
Amatrix(17 , 7) = 1.443978257;
Amatrix(17 , 8) = 0.0425484878;
Amatrix(17 , 9) = 0.3569965702;
Amatrix(17 , 10) = 1.5893128445;
Amatrix(17 , 11) = 0.090504827;
Amatrix(17 , 12) = 0.5232342102;
Amatrix(17 , 13) = 1.9103446165;
Amatrix(17 , 14) = 0.3118797592;
Amatrix(17 , 15) = 1.3707414603;
Amatrix(17 , 16) = 3.2060856194;
Amatrix(17 , 17) = -4.2662632156;
Amatrix(17 , 18) = -1.1747616442;
Amatrix(17 , 19) = -2.0060239482;
Amatrix(17 , 20) = 0.3162782527;
Amatrix(17 , 21) = -0.3222898041;
Amatrix(17 , 22) = -0.6960581401;
Amatrix(17 , 23) = 0.0997676827;
Amatrix(17 , 24) = -0.1454156921;
Amatrix(17 , 25) = -0.3450001686;
Amatrix(17 , 26) = 0.0577610076;
Amatrix(17 , 27) = -0.0605561959;
Amatrix(17 , 28) = -0.1501445039;
Amatrix(17 , 29) = 0.0452682837;
Amatrix(18 , 19) = 1.0;
Amatrix(19 , 17) = 1.0;
Amatrix(19 , 20) = -1.0;
Amatrix(20 , 0) = 0.2209733477;
Amatrix(20 , 1) = 1.2715254674;
Amatrix(20 , 2) = 0.0067836913;
Amatrix(20 , 3) = 0.2295859695;
Amatrix(20 , 4) = 1.2938337531;
Amatrix(20 , 5) = 0.0148612718;
Amatrix(20 , 6) = 0.2490638862;
Amatrix(20 , 7) = 1.3429518064;
Amatrix(20 , 8) = 0.026376677;
Amatrix(20 , 9) = 0.2857142857;
Amatrix(20 , 10) = 1.4309902707;
Amatrix(20 , 11) = 0.0465788228;
Amatrix(20 , 12) = 0.3569965702;
Amatrix(20 , 13) = 1.5893128445;
Amatrix(20 , 14) = 0.094535162;
Amatrix(20 , 15) = 0.5276620899;
Amatrix(20 , 16) = 1.9233326028;
Amatrix(20 , 17) = 0.3162782527;
Amatrix(20 , 18) = 1.3801339299;
Amatrix(20 , 19) = 3.2332984109;
Amatrix(20 , 20) = -4.2610306949;
Amatrix(20 , 21) = -1.1591605822;
Amatrix(20 , 22) = -1.9617729435;
Amatrix(20 , 23) = 0.323061944;
Amatrix(20 , 24) = -0.2980761204;
Amatrix(20 , 25) = -0.6294988497;
Amatrix(20 , 26) = 0.1093964337;
Amatrix(20 , 27) = -0.1079326841;
Amatrix(20 , 28) = -0.2463610381;
Amatrix(20 , 29) = 0.0729554998;
Amatrix(21 , 22) = 1.0;
Amatrix(22 , 20) = 1.0;
Amatrix(22 , 23) = -1.0;
Amatrix(23 , 0) = 0.2053722857;
Amatrix(23 , 1) = 1.2272744627;
Amatrix(23 , 2) = 0.0052325207;
Amatrix(23 , 3) = 0.2115808781;
Amatrix(23 , 4) = 1.2443126759;
Amatrix(23 , 5) = 0.0111821848;
Amatrix(23 , 6) = 0.2251580898;
Amatrix(23 , 7) = 1.2808457668;
Amatrix(23 , 8) = 0.0188916067;
Amatrix(23 , 9) = 0.2490638862;
Amatrix(23 , 10) = 1.3429518064;
Amatrix(23 , 11) = 0.0304070119;
Amatrix(23 , 12) = 0.2901421653;
Amatrix(23 , 13) = 1.443978257;
Amatrix(23 , 14) = 0.0509773162;
Amatrix(23 , 15) = 0.3663890398;
Amatrix(23 , 16) = 1.616525636;
Amatrix(23 , 17) = 0.0997676827;
Amatrix(23 , 18) = 0.5432631518;
Amatrix(23 , 19) = 1.9675836075;
Amatrix(23 , 20) = 0.323061944;
Amatrix(23 , 21) = 1.4043476136;
Amatrix(23 , 22) = 3.2998577013;
Amatrix(23 , 23) = -4.2514019439;
Amatrix(23 , 24) = -1.1216775741;
Amatrix(23 , 25) = -1.863133813;
Amatrix(23 , 26) = 0.3382564362;
Amatrix(23 , 27) = -0.2375199245;
Amatrix(23 , 28) = -0.4793543458;
Amatrix(23 , 29) = 0.1370836498;
Amatrix(24 , 25) = 1.0;
Amatrix(25 , 23) = 1.0;
Amatrix(25 , 26) = -1.0;
Amatrix(26 , 0) = 0.1959798161;
Amatrix(26 , 1) = 1.2000616712;
Amatrix(26 , 2) = 0.0043984935;
Amatrix(26 , 3) = 0.2009444061;
Amatrix(26 , 4) = 1.2142864764;
Amatrix(26 , 5) = 0.0092628557;
Amatrix(26 , 6) = 0.2115808781;
Amatrix(26 , 7) = 1.2443126759;
Amatrix(26 , 8) = 0.0152125197;
Amatrix(26 , 9) = 0.2295859695;
Amatrix(26 , 10) = 1.2938337531;
Amatrix(26 , 11) = 0.0232901001;
Amatrix(26 , 12) = 0.2584563558;
Amatrix(26 , 13) = 1.3701645979;
Amatrix(26 , 14) = 0.0356395326;
Amatrix(26 , 15) = 0.3057432273;
Amatrix(26 , 16) = 1.4882292617;
Amatrix(26 , 17) = 0.0577610076;
Amatrix(26 , 18) = 0.3906027236;
Amatrix(26 , 19) = 1.6830849264;
Amatrix(26 , 20) = 0.1093964337;
Amatrix(26 , 21) = 0.5807461599;
Amatrix(26 , 22) = 2.066222738;
Amatrix(26 , 23) = 0.3382564362;
Amatrix(26 , 24) = 1.4649038095;
Amatrix(26 , 25) = 3.4500022052;
Amatrix(26 , 26) = -4.2237147278;
Amatrix(26 , 27) = -1.01374489;
Amatrix(26 , 28) = -1.6167727749;
Amatrix(26 , 29) = 0.4023845862;
Amatrix(27 , 28) = 1.0;
Amatrix(28 , 26) = 1.0;
Amatrix(28 , 29) = -1.0;
Amatrix(29 , 0) = 0.1915519365;
Amatrix(29 , 1) = 1.1870736849;
Amatrix(29 , 2) = 0.0040303349;
Amatrix(29 , 3) = 0.1959798161;
Amatrix(29 , 4) = 1.2000616712;
Amatrix(29 , 5) = 0.0084288284;
Amatrix(29 , 6) = 0.2053722857;
Amatrix(29 , 7) = 1.2272744627;
Amatrix(29 , 8) = 0.0136613491;
Amatrix(29 , 9) = 0.2209733477;
Amatrix(29 , 10) = 1.2715254674;
Amatrix(29 , 11) = 0.0204450405;
Amatrix(29 , 12) = 0.2451870315;
Amatrix(29 , 13) = 1.3380847578;
Amatrix(29 , 14) = 0.0300737915;
Amatrix(29 , 15) = 0.2826700395;
Amatrix(29 , 16) = 1.4367238883;
Amatrix(29 , 17) = 0.0452682837;
Amatrix(29 , 18) = 0.3432262354;
Amatrix(29 , 19) = 1.5868683922;
Amatrix(29 , 20) = 0.0729554998;
Amatrix(29 , 21) = 0.4511589195;
Amatrix(29 , 22) = 1.8332294303;
Amatrix(29 , 23) = 0.1370836498;
Amatrix(29 , 24) = 0.688678844;
Amatrix(29 , 25) = 2.3125837761;
Amatrix(29 , 26) = 0.4023845862;
Amatrix(29 , 27) = 1.702423734;
Amatrix(29 , 28) = 3.929356551;
Amatrix(29 , 29) = -3.9584137913;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;
system_dynamics.U = polytope::ptr(new polytope(true));

C.resize(row );
C.assign(row,0);
C[30] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


std::list<transition::ptr> Out_Going_Trans_fromok;


l =location::ptr(new location(1, "ok", system_dynamics, invariant, false, Out_Going_Trans_fromok));

Hybrid_Automata.addInitialLocation(l);
Hybrid_Automata.addLocation(l);


row = 62;
col = 31;
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
boundValueI.resize(row );
boundValueI.assign(row,0);
boundValueI[0]=1;
boundValueI[1]=-1;
boundValueI[2]=1;
boundValueI[3]=-1;
boundValueI[4]=1;
boundValueI[5]=-1;
boundValueI[6]=1;
boundValueI[7]=-1;
boundValueI[8]=1;
boundValueI[9]=-1;
boundValueI[10]=1;
boundValueI[11]=-1;
boundValueI[12]=1;
boundValueI[13]=-1;
boundValueI[14]=1;
boundValueI[15]=-1;
boundValueI[16]=1;
boundValueI[17]=-1;
boundValueI[18]=1;
boundValueI[19]=-1;
boundValueI[20]=1;
boundValueI[21]=-1;
boundValueI[22]=1;
boundValueI[23]=-1;
boundValueI[24]=1;
boundValueI[25]=-1;
boundValueI[26]=1;
boundValueI[27]=-1;
boundValueI[28]=1;
boundValueI[29]=-1;
boundValueI[30]=1;
boundValueI[31]=-1;
boundValueI[32]=1;
boundValueI[33]=-1;
boundValueI[34]=1;
boundValueI[35]=-1;
boundValueI[36]=1;
boundValueI[37]=-1;
boundValueI[38]=1;
boundValueI[39]=-1;
boundValueI[40]=1;
boundValueI[41]=-1;
boundValueI[42]=1;
boundValueI[43]=-1;
boundValueI[44]=1;
boundValueI[45]=-1;
boundValueI[46]=1;
boundValueI[47]=-1;
boundValueI[48]=1;
boundValueI[49]=-1;
boundValueI[50]=1;
boundValueI[51]=-1;
boundValueI[52]=1;
boundValueI[53]=-1;
boundValueI[54]=1;
boundValueI[55]=-1;
boundValueI[56]=1;
boundValueI[57]=-1;
boundValueI[58]=1;
boundValueI[59]=-1;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =1;

symbolic_states::ptr S0;

initial_state::ptr I0 = initial_state::ptr(new initial_state(initial_location_id, initial_polytope_I0, S0, transition_id));

init_state_list.push_back(I0);
Hybrid_Automata.setDimension(dim);



Hybrid_Automata.insert_to_map("e1",0);
Hybrid_Automata.insert_to_map("e1prime",1);
Hybrid_Automata.insert_to_map("a1",2);
Hybrid_Automata.insert_to_map("e2",3);
Hybrid_Automata.insert_to_map("e2prime",4);
Hybrid_Automata.insert_to_map("a2",5);
Hybrid_Automata.insert_to_map("e3",6);
Hybrid_Automata.insert_to_map("e3prime",7);
Hybrid_Automata.insert_to_map("a3",8);
Hybrid_Automata.insert_to_map("e4",9);
Hybrid_Automata.insert_to_map("e4prime",10);
Hybrid_Automata.insert_to_map("a4",11);
Hybrid_Automata.insert_to_map("e5",12);
Hybrid_Automata.insert_to_map("e5prime",13);
Hybrid_Automata.insert_to_map("a5",14);
Hybrid_Automata.insert_to_map("e6",15);
Hybrid_Automata.insert_to_map("e6prime",16);
Hybrid_Automata.insert_to_map("a6",17);
Hybrid_Automata.insert_to_map("e7",18);
Hybrid_Automata.insert_to_map("e7prime",19);
Hybrid_Automata.insert_to_map("a7",20);
Hybrid_Automata.insert_to_map("e8",21);
Hybrid_Automata.insert_to_map("e8prime",22);
Hybrid_Automata.insert_to_map("a8",23);
Hybrid_Automata.insert_to_map("e9",24);
Hybrid_Automata.insert_to_map("e9prime",25);
Hybrid_Automata.insert_to_map("a9",26);
Hybrid_Automata.insert_to_map("e10",27);
Hybrid_Automata.insert_to_map("e10prime",28);
Hybrid_Automata.insert_to_map("a10",29);
Hybrid_Automata.insert_to_map("t",30);

}
