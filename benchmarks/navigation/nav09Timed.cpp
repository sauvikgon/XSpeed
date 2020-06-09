// Created by Hyst v1.3
// Hybrid Automaton in XSpeed
// Converted from file: /home/hazel/hazel/models/Benchmarks/Nav09t.xml
// Command Line arguments: -tool xspeed "" -verbose -output /home/hazel/hazel/models/Benchmarks/nv09test.cpp -input /home/hazel/hazel/models/Benchmarks/Nav09t.xml /home/hazel/hazel/models/Benchmarks/Nav09.cfg


#include <benchmarks/navigation/navigationBenchmark.h>

void SetNavigationModel9by9Timed(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters){


typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

// ************* Section required for Forbidden Inputs *************
unsigned int Directions_Type = 1;
unsigned int iter_max = 2143;
double time_horizon = 10.0;
double sampling_time = 0.1;
unsigned int dim;
size_type row, col;




polytope::ptr initial_polytope_I0, forbid_polytope;
polytope::ptr invariant0, invariant1, invariant2, invariant3, invariant4, invariant5, invariant6, invariant7, invariant8, invariant9, invariant10, invariant11, invariant12, invariant13, invariant14, invariant15, invariant16, invariant17, invariant18, invariant19, invariant20, invariant21, invariant22, invariant23, invariant24, invariant25, invariant26, invariant27, invariant28, invariant29, invariant30, invariant31, invariant32, invariant33, invariant34, invariant35, invariant36, invariant37, invariant38, invariant39, invariant40, invariant41, invariant42, invariant43, invariant44, invariant45, invariant46, invariant47, invariant48, invariant49, invariant50, invariant51, invariant52, invariant53, invariant54, invariant55, invariant56, invariant57, invariant58, invariant59, invariant60, invariant61, invariant62, invariant63, invariant64, invariant65, invariant66, invariant67, invariant68, invariant69, invariant70, invariant71, invariant72, invariant73, invariant74, invariant75, invariant76, invariant77, invariant78, invariant79, invariant80;

polytope::ptr guard_polytope0, guard_polytope1, guard_polytope2, guard_polytope3, guard_polytope4, guard_polytope5, guard_polytope6, guard_polytope7, guard_polytope8, guard_polytope9, guard_polytope10, guard_polytope11, guard_polytope12, guard_polytope13, guard_polytope14, guard_polytope15, guard_polytope16, guard_polytope17, guard_polytope18, guard_polytope19, guard_polytope20, guard_polytope21, guard_polytope22, guard_polytope23, guard_polytope24, guard_polytope25, guard_polytope26, guard_polytope27, guard_polytope28, guard_polytope29, guard_polytope30, guard_polytope31, guard_polytope32, guard_polytope33, guard_polytope34, guard_polytope35, guard_polytope36, guard_polytope37, guard_polytope38, guard_polytope39, guard_polytope40, guard_polytope41, guard_polytope42, guard_polytope43, guard_polytope44, guard_polytope45, guard_polytope46, guard_polytope47, guard_polytope48, guard_polytope49, guard_polytope50, guard_polytope51, guard_polytope52, guard_polytope53, guard_polytope54, guard_polytope55, guard_polytope56, guard_polytope57, guard_polytope58, guard_polytope59, guard_polytope60, guard_polytope61, guard_polytope62, guard_polytope63, guard_polytope64, guard_polytope65, guard_polytope66, guard_polytope67, guard_polytope68, guard_polytope69, guard_polytope70, guard_polytope71, guard_polytope72, guard_polytope73, guard_polytope74, guard_polytope75, guard_polytope76, guard_polytope77, guard_polytope78, guard_polytope79, guard_polytope80, guard_polytope81, guard_polytope82, guard_polytope83, guard_polytope84, guard_polytope85, guard_polytope86, guard_polytope87, guard_polytope88, guard_polytope89, guard_polytope90, guard_polytope91, guard_polytope92, guard_polytope93, guard_polytope94, guard_polytope95, guard_polytope96, guard_polytope97, guard_polytope98, guard_polytope99, guard_polytope100, guard_polytope101, guard_polytope102, guard_polytope103, guard_polytope104, guard_polytope105, guard_polytope106, guard_polytope107, guard_polytope108, guard_polytope109, guard_polytope110, guard_polytope111, guard_polytope112, guard_polytope113, guard_polytope114, guard_polytope115, guard_polytope116, guard_polytope117, guard_polytope118, guard_polytope119, guard_polytope120, guard_polytope121, guard_polytope122, guard_polytope123, guard_polytope124, guard_polytope125, guard_polytope126, guard_polytope127, guard_polytope128, guard_polytope129, guard_polytope130, guard_polytope131, guard_polytope132, guard_polytope133, guard_polytope134, guard_polytope135, guard_polytope136, guard_polytope137, guard_polytope138, guard_polytope139, guard_polytope140, guard_polytope141, guard_polytope142, guard_polytope143, guard_polytope144, guard_polytope145, guard_polytope146, guard_polytope147, guard_polytope148, guard_polytope149, guard_polytope150, guard_polytope151, guard_polytope152, guard_polytope153, guard_polytope154, guard_polytope155, guard_polytope156, guard_polytope157, guard_polytope158, guard_polytope159, guard_polytope160, guard_polytope161, guard_polytope162, guard_polytope163, guard_polytope164, guard_polytope165, guard_polytope166, guard_polytope167, guard_polytope168, guard_polytope169, guard_polytope170, guard_polytope171, guard_polytope172, guard_polytope173, guard_polytope174, guard_polytope175, guard_polytope176, guard_polytope177, guard_polytope178, guard_polytope179, guard_polytope180, guard_polytope181, guard_polytope182, guard_polytope183, guard_polytope184, guard_polytope185, guard_polytope186, guard_polytope187, guard_polytope188, guard_polytope189, guard_polytope190, guard_polytope191, guard_polytope192, guard_polytope193, guard_polytope194, guard_polytope195, guard_polytope196, guard_polytope197, guard_polytope198, guard_polytope199, guard_polytope200, guard_polytope201, guard_polytope202, guard_polytope203, guard_polytope204, guard_polytope205, guard_polytope206, guard_polytope207, guard_polytope208, guard_polytope209, guard_polytope210, guard_polytope211, guard_polytope212, guard_polytope213, guard_polytope214, guard_polytope215, guard_polytope216, guard_polytope217, guard_polytope218, guard_polytope219, guard_polytope220, guard_polytope221, guard_polytope222, guard_polytope223, guard_polytope224, guard_polytope225, guard_polytope226, guard_polytope227, guard_polytope228, guard_polytope229, guard_polytope230, guard_polytope231, guard_polytope232, guard_polytope233, guard_polytope234, guard_polytope235, guard_polytope236, guard_polytope237, guard_polytope238, guard_polytope239, guard_polytope240, guard_polytope241, guard_polytope242, guard_polytope243, guard_polytope244, guard_polytope245, guard_polytope246, guard_polytope247, guard_polytope248, guard_polytope249, guard_polytope250, guard_polytope251, guard_polytope252, guard_polytope253, guard_polytope254, guard_polytope255, guard_polytope256, guard_polytope257, guard_polytope258, guard_polytope259, guard_polytope260, guard_polytope261, guard_polytope262, guard_polytope263, guard_polytope264, guard_polytope265, guard_polytope266, guard_polytope267, guard_polytope268, guard_polytope269, guard_polytope270, guard_polytope271, guard_polytope272, guard_polytope273, guard_polytope274, guard_polytope275, guard_polytope276, guard_polytope277, guard_polytope278, guard_polytope279;

Dynamics system_dynamics;

math::matrix<double> ConstraintsMatrixI , ConstraintsMatrixV, invariantConstraintsMatrix , guardConstraintsMatrix , Amatrix , Bmatrix,forbiddenMatrixI;

std::vector<double> boundValueI,boundValueV , C , invariantBoundValue , guardBoundValue, boundValueF;

int boundSignI=1, invariantBoundSign=1, guardBoundSign=1, boundSignV=1;


// The mode name is  loc9

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant0 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc9;

// The transition label ist24

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope0 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


math::matrix<double> R;
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


Assign assignment;
assignment.Map = R;
assignment.b = w;

transition::ptr t1 = transition::ptr(new transition(1,"t24",1,2,guard_polytope0,assignment));

Out_Going_Trans_fromloc9.push_back(t1);
// The transition label ist25

// Original guard: x1 = 1 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope1 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t2 = transition::ptr(new transition(2,"t25",1,10,guard_polytope1,assignment));

Out_Going_Trans_fromloc9.push_back(t2);
location::ptr l1 = location::ptr(new location(1, "loc9", system_dynamics, invariant0, true, Out_Going_Trans_fromloc9));

Hybrid_Automata.addInitialLocation(l1);
Hybrid_Automata.addLocation(l1);


// The mode name is  loc8

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant1 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc8;

// The transition label ist23

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope2 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t3 = transition::ptr(new transition(3,"t23",2,1,guard_polytope2,assignment));

Out_Going_Trans_fromloc8.push_back(t3);
// The transition label ist21

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope3 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t4 = transition::ptr(new transition(4,"t21",2,3,guard_polytope3,assignment));

Out_Going_Trans_fromloc8.push_back(t4);
// The transition label ist22

// Original guard: x1 = 1 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope4 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t5 = transition::ptr(new transition(5,"t22",2,11,guard_polytope4,assignment));

Out_Going_Trans_fromloc8.push_back(t5);
location::ptr l2 = location::ptr(new location(2, "loc8", system_dynamics, invariant1, true, Out_Going_Trans_fromloc8));
Hybrid_Automata.addLocation(l2);


// The mode name is  loc7

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant2 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc7;

// The transition label ist20

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope5 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t6 = transition::ptr(new transition(6,"t20",3,2,guard_polytope5,assignment));

Out_Going_Trans_fromloc7.push_back(t6);
// The transition label ist18

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope6 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t7 = transition::ptr(new transition(7,"t18",3,4,guard_polytope6,assignment));

Out_Going_Trans_fromloc7.push_back(t7);
// The transition label ist19

// Original guard: x1 = 1 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope7 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t8 = transition::ptr(new transition(8,"t19",3,12,guard_polytope7,assignment));

Out_Going_Trans_fromloc7.push_back(t8);
location::ptr l3 = location::ptr(new location(3, "loc7", system_dynamics, invariant2, true, Out_Going_Trans_fromloc7));
Hybrid_Automata.addLocation(l3);


// The mode name is  loc6

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant3 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc6;

// The transition label ist17

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope8 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t9 = transition::ptr(new transition(9,"t17",4,3,guard_polytope8,assignment));

Out_Going_Trans_fromloc6.push_back(t9);
// The transition label ist15

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope9 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t10 = transition::ptr(new transition(10,"t15",4,5,guard_polytope9,assignment));

Out_Going_Trans_fromloc6.push_back(t10);
// The transition label ist16

// Original guard: x1 = 1 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope10 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t11 = transition::ptr(new transition(11,"t16",4,13,guard_polytope10,assignment));

Out_Going_Trans_fromloc6.push_back(t11);
location::ptr l4 = location::ptr(new location(4, "loc6", system_dynamics, invariant3, true, Out_Going_Trans_fromloc6));
Hybrid_Automata.addLocation(l4);


// The mode name is  loc5

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant4 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc5;

// The transition label ist14

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope11 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t12 = transition::ptr(new transition(12,"t14",5,4,guard_polytope11,assignment));

Out_Going_Trans_fromloc5.push_back(t12);
// The transition label ist12

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope12 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t13 = transition::ptr(new transition(13,"t12",5,6,guard_polytope12,assignment));

Out_Going_Trans_fromloc5.push_back(t13);
// The transition label ist13

// Original guard: x1 = 1 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope13 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t14 = transition::ptr(new transition(14,"t13",5,14,guard_polytope13,assignment));

Out_Going_Trans_fromloc5.push_back(t14);
location::ptr l5 = location::ptr(new location(5, "loc5", system_dynamics, invariant4, true, Out_Going_Trans_fromloc5));
Hybrid_Automata.addLocation(l5);


// The mode name is  loc4

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant5 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc4;

// The transition label ist11

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope14 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t15 = transition::ptr(new transition(15,"t11",6,5,guard_polytope14,assignment));

Out_Going_Trans_fromloc4.push_back(t15);
// The transition label ist9

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope15 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t16 = transition::ptr(new transition(16,"t9",6,7,guard_polytope15,assignment));

Out_Going_Trans_fromloc4.push_back(t16);
// The transition label ist10

// Original guard: x1 = 1 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope16 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t17 = transition::ptr(new transition(17,"t10",6,15,guard_polytope16,assignment));

Out_Going_Trans_fromloc4.push_back(t17);
location::ptr l6 = location::ptr(new location(6, "loc4", system_dynamics, invariant5, true, Out_Going_Trans_fromloc4));
Hybrid_Automata.addLocation(l6);


// The mode name is  loc3

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant6 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc3;

// The transition label ist8

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope17 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t18 = transition::ptr(new transition(18,"t8",7,6,guard_polytope17,assignment));

Out_Going_Trans_fromloc3.push_back(t18);
// The transition label ist6

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope18 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t19 = transition::ptr(new transition(19,"t6",7,8,guard_polytope18,assignment));

Out_Going_Trans_fromloc3.push_back(t19);
// The transition label ist7

// Original guard: x1 = 1 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope19 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t20 = transition::ptr(new transition(20,"t7",7,16,guard_polytope19,assignment));

Out_Going_Trans_fromloc3.push_back(t20);
location::ptr l7 = location::ptr(new location(7, "loc3", system_dynamics, invariant6, true, Out_Going_Trans_fromloc3));
Hybrid_Automata.addLocation(l7);


// The mode name is  loc2

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.20208;
C[3] = 1.20208;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant7 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc2;

// The transition label ist5

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope20 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t21 = transition::ptr(new transition(21,"t5",8,7,guard_polytope20,assignment));

Out_Going_Trans_fromloc2.push_back(t21);
// The transition label ist3

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope21 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t22 = transition::ptr(new transition(22,"t3",8,9,guard_polytope21,assignment));

Out_Going_Trans_fromloc2.push_back(t22);
// The transition label ist4

// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope22 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t23 = transition::ptr(new transition(23,"t4",8,17,guard_polytope22,assignment));

Out_Going_Trans_fromloc2.push_back(t23);
location::ptr l8 = location::ptr(new location(8, "loc2", system_dynamics, invariant7, true, Out_Going_Trans_fromloc2));
Hybrid_Automata.addLocation(l8);


// The mode name is  loc1

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.20208;
C[3] = 1.20208;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
col = 5;
invariantConstraintsMatrix.resize(row, col);
invariantConstraintsMatrix.clear();
invariantConstraintsMatrix(0,0)= -1.0;
invariantConstraintsMatrix(1,0)= 1.0;
invariantConstraintsMatrix(2,1)= -1.0;
invariantConstraintsMatrix(3,1)= 1.0;

invariantBoundValue.resize(row);
invariantBoundValue.assign(row,0);
invariantBoundValue[1] = 1.0;
invariantBoundValue[3] = 1.0;
invariant8 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc1;

// The transition label ist2

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope23 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t24 = transition::ptr(new transition(24,"t2",9,8,guard_polytope23,assignment));

Out_Going_Trans_fromloc1.push_back(t24);
// The transition label ist1

// Original guard: x1 = 1 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope24 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t25 = transition::ptr(new transition(25,"t1",9,18,guard_polytope24,assignment));

Out_Going_Trans_fromloc1.push_back(t25);
location::ptr l9 = location::ptr(new location(9, "loc1", system_dynamics, invariant8, true, Out_Going_Trans_fromloc1));
Hybrid_Automata.addLocation(l9);


// The mode name is  loc18

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.20208;
C[3] = 1.20208;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant9 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc18;

// The transition label ist57

// Original guard: x1 = 1 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope25 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t26 = transition::ptr(new transition(26,"t57",10,1,guard_polytope25,assignment));

Out_Going_Trans_fromloc18.push_back(t26);
// The transition label ist58

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope26 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t27 = transition::ptr(new transition(27,"t58",10,11,guard_polytope26,assignment));

Out_Going_Trans_fromloc18.push_back(t27);
// The transition label ist59

// Original guard: x1 = 2 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope27 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t28 = transition::ptr(new transition(28,"t59",10,19,guard_polytope27,assignment));

Out_Going_Trans_fromloc18.push_back(t28);
location::ptr l10 = location::ptr(new location(10, "loc18", system_dynamics, invariant9, true, Out_Going_Trans_fromloc18));
Hybrid_Automata.addLocation(l10);


// The mode name is  loc17

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.20208;
C[3] = 1.20208;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant10 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc17;

// The transition label ist53

// Original guard: x1 = 1 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope28 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t29 = transition::ptr(new transition(29,"t53",11,2,guard_polytope28,assignment));

Out_Going_Trans_fromloc17.push_back(t29);
// The transition label ist56

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope29 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t30 = transition::ptr(new transition(30,"t56",11,10,guard_polytope29,assignment));

Out_Going_Trans_fromloc17.push_back(t30);
// The transition label ist54

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope30 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t31 = transition::ptr(new transition(31,"t54",11,12,guard_polytope30,assignment));

Out_Going_Trans_fromloc17.push_back(t31);
// The transition label ist55

// Original guard: x1 = 2 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope31 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t32 = transition::ptr(new transition(32,"t55",11,20,guard_polytope31,assignment));

Out_Going_Trans_fromloc17.push_back(t32);
location::ptr l11 = location::ptr(new location(11, "loc17", system_dynamics, invariant10, true, Out_Going_Trans_fromloc17));
Hybrid_Automata.addLocation(l11);


// The mode name is  loc16

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.20208;
C[3] = 1.20208;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant11 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc16;

// The transition label ist49

// Original guard: x1 = 1 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope32 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t33 = transition::ptr(new transition(33,"t49",12,3,guard_polytope32,assignment));

Out_Going_Trans_fromloc16.push_back(t33);
// The transition label ist52

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope33 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t34 = transition::ptr(new transition(34,"t52",12,11,guard_polytope33,assignment));

Out_Going_Trans_fromloc16.push_back(t34);
// The transition label ist50

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope34 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t35 = transition::ptr(new transition(35,"t50",12,13,guard_polytope34,assignment));

Out_Going_Trans_fromloc16.push_back(t35);
// The transition label ist51

// Original guard: x1 = 2 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope35 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t36 = transition::ptr(new transition(36,"t51",12,21,guard_polytope35,assignment));

Out_Going_Trans_fromloc16.push_back(t36);
location::ptr l12 = location::ptr(new location(12, "loc16", system_dynamics, invariant11, true, Out_Going_Trans_fromloc16));
Hybrid_Automata.addLocation(l12);


// The mode name is  loc15

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant12 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc15;

// The transition label ist45

// Original guard: x1 = 1 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope36 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t37 = transition::ptr(new transition(37,"t45",13,4,guard_polytope36,assignment));

Out_Going_Trans_fromloc15.push_back(t37);
// The transition label ist48

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope37 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t38 = transition::ptr(new transition(38,"t48",13,12,guard_polytope37,assignment));

Out_Going_Trans_fromloc15.push_back(t38);
// The transition label ist46

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope38 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t39 = transition::ptr(new transition(39,"t46",13,14,guard_polytope38,assignment));

Out_Going_Trans_fromloc15.push_back(t39);
// The transition label ist47

// Original guard: x1 = 2 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope39 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t40 = transition::ptr(new transition(40,"t47",13,22,guard_polytope39,assignment));

Out_Going_Trans_fromloc15.push_back(t40);
location::ptr l13 = location::ptr(new location(13, "loc15", system_dynamics, invariant12, true, Out_Going_Trans_fromloc15));
Hybrid_Automata.addLocation(l13);


// The mode name is  loc14

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant13 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc14;

// The transition label ist41

// Original guard: x1 = 1 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope40 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t41 = transition::ptr(new transition(41,"t41",14,5,guard_polytope40,assignment));

Out_Going_Trans_fromloc14.push_back(t41);
// The transition label ist44

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope41 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t42 = transition::ptr(new transition(42,"t44",14,13,guard_polytope41,assignment));

Out_Going_Trans_fromloc14.push_back(t42);
// The transition label ist42

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope42 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t43 = transition::ptr(new transition(43,"t42",14,15,guard_polytope42,assignment));

Out_Going_Trans_fromloc14.push_back(t43);
// The transition label ist43

// Original guard: x1 = 2 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope43 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t44 = transition::ptr(new transition(44,"t43",14,23,guard_polytope43,assignment));

Out_Going_Trans_fromloc14.push_back(t44);
location::ptr l14 = location::ptr(new location(14, "loc14", system_dynamics, invariant13, true, Out_Going_Trans_fromloc14));
Hybrid_Automata.addLocation(l14);


// The mode name is  loc13

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant14 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc13;

// The transition label ist37

// Original guard: x1 = 1 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope44 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t45 = transition::ptr(new transition(45,"t37",15,6,guard_polytope44,assignment));

Out_Going_Trans_fromloc13.push_back(t45);
// The transition label ist40

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope45 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t46 = transition::ptr(new transition(46,"t40",15,14,guard_polytope45,assignment));

Out_Going_Trans_fromloc13.push_back(t46);
// The transition label ist38

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope46 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t47 = transition::ptr(new transition(47,"t38",15,16,guard_polytope46,assignment));

Out_Going_Trans_fromloc13.push_back(t47);
// The transition label ist39

// Original guard: x1 = 2 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope47 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t48 = transition::ptr(new transition(48,"t39",15,24,guard_polytope47,assignment));

Out_Going_Trans_fromloc13.push_back(t48);
location::ptr l15 = location::ptr(new location(15, "loc13", system_dynamics, invariant14, true, Out_Going_Trans_fromloc13));
Hybrid_Automata.addLocation(l15);


// The mode name is  loc12

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant15 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc12;

// The transition label ist33

// Original guard: x1 = 1 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope48 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t49 = transition::ptr(new transition(49,"t33",16,7,guard_polytope48,assignment));

Out_Going_Trans_fromloc12.push_back(t49);
// The transition label ist36

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope49 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t50 = transition::ptr(new transition(50,"t36",16,15,guard_polytope49,assignment));

Out_Going_Trans_fromloc12.push_back(t50);
// The transition label ist34

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope50 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t51 = transition::ptr(new transition(51,"t34",16,17,guard_polytope50,assignment));

Out_Going_Trans_fromloc12.push_back(t51);
// The transition label ist35

// Original guard: x1 = 2 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope51 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t52 = transition::ptr(new transition(52,"t35",16,25,guard_polytope51,assignment));

Out_Going_Trans_fromloc12.push_back(t52);
location::ptr l16 = location::ptr(new location(16, "loc12", system_dynamics, invariant15, true, Out_Going_Trans_fromloc12));
Hybrid_Automata.addLocation(l16);


// The mode name is  loc11

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.20208;
C[3] = 1.20208;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant16 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc11;

// The transition label ist29

// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope52 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t53 = transition::ptr(new transition(53,"t29",17,8,guard_polytope52,assignment));

Out_Going_Trans_fromloc11.push_back(t53);
// The transition label ist32

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope53 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t54 = transition::ptr(new transition(54,"t32",17,16,guard_polytope53,assignment));

Out_Going_Trans_fromloc11.push_back(t54);
// The transition label ist30

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope54 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t55 = transition::ptr(new transition(55,"t30",17,18,guard_polytope54,assignment));

Out_Going_Trans_fromloc11.push_back(t55);
// The transition label ist31

// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope55 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t56 = transition::ptr(new transition(56,"t31",17,26,guard_polytope55,assignment));

Out_Going_Trans_fromloc11.push_back(t56);
location::ptr l17 = location::ptr(new location(17, "loc11", system_dynamics, invariant16, true, Out_Going_Trans_fromloc11));
Hybrid_Automata.addLocation(l17);


// The mode name is  loc10

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.20208;
C[3] = 1.20208;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant17 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc10;

// The transition label ist26

// Original guard: x1 = 1 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope56 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t57 = transition::ptr(new transition(57,"t26",18,9,guard_polytope56,assignment));

Out_Going_Trans_fromloc10.push_back(t57);
// The transition label ist28

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -1.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope57 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t58 = transition::ptr(new transition(58,"t28",18,17,guard_polytope57,assignment));

Out_Going_Trans_fromloc10.push_back(t58);
// The transition label ist27

// Original guard: x1 = 2 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope58 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t59 = transition::ptr(new transition(59,"t27",18,27,guard_polytope58,assignment));

Out_Going_Trans_fromloc10.push_back(t59);
location::ptr l18 = location::ptr(new location(18, "loc10", system_dynamics, invariant17, true, Out_Going_Trans_fromloc10));
Hybrid_Automata.addLocation(l18);


// The mode name is  loc27

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant18 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc27;

// The transition label ist91

// Original guard: x1 = 2 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope59 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t60 = transition::ptr(new transition(60,"t91",19,10,guard_polytope59,assignment));

Out_Going_Trans_fromloc27.push_back(t60);
// The transition label ist92

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope60 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t61 = transition::ptr(new transition(61,"t92",19,20,guard_polytope60,assignment));

Out_Going_Trans_fromloc27.push_back(t61);
// The transition label ist93

// Original guard: x1 = 3 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope61 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t62 = transition::ptr(new transition(62,"t93",19,28,guard_polytope61,assignment));

Out_Going_Trans_fromloc27.push_back(t62);
location::ptr l19 = location::ptr(new location(19, "loc27", system_dynamics, invariant18, true, Out_Going_Trans_fromloc27));
Hybrid_Automata.addLocation(l19);


// The mode name is  loc26

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant19 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc26;

// The transition label ist87

// Original guard: x1 = 2 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope62 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t63 = transition::ptr(new transition(63,"t87",20,11,guard_polytope62,assignment));

Out_Going_Trans_fromloc26.push_back(t63);
// The transition label ist90

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope63 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t64 = transition::ptr(new transition(64,"t90",20,19,guard_polytope63,assignment));

Out_Going_Trans_fromloc26.push_back(t64);
// The transition label ist88

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope64 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t65 = transition::ptr(new transition(65,"t88",20,21,guard_polytope64,assignment));

Out_Going_Trans_fromloc26.push_back(t65);
// The transition label ist89

// Original guard: x1 = 3 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope65 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t66 = transition::ptr(new transition(66,"t89",20,29,guard_polytope65,assignment));

Out_Going_Trans_fromloc26.push_back(t66);
location::ptr l20 = location::ptr(new location(20, "loc26", system_dynamics, invariant19, true, Out_Going_Trans_fromloc26));
Hybrid_Automata.addLocation(l20);


// The mode name is  loc25

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant20 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc25;

// The transition label ist83

// Original guard: x1 = 2 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope66 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t67 = transition::ptr(new transition(67,"t83",21,12,guard_polytope66,assignment));

Out_Going_Trans_fromloc25.push_back(t67);
// The transition label ist86

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope67 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t68 = transition::ptr(new transition(68,"t86",21,20,guard_polytope67,assignment));

Out_Going_Trans_fromloc25.push_back(t68);
// The transition label ist84

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope68 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t69 = transition::ptr(new transition(69,"t84",21,22,guard_polytope68,assignment));

Out_Going_Trans_fromloc25.push_back(t69);
// The transition label ist85

// Original guard: x1 = 3 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope69 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t70 = transition::ptr(new transition(70,"t85",21,30,guard_polytope69,assignment));

Out_Going_Trans_fromloc25.push_back(t70);
location::ptr l21 = location::ptr(new location(21, "loc25", system_dynamics, invariant20, true, Out_Going_Trans_fromloc25));
Hybrid_Automata.addLocation(l21);


// The mode name is  loc24

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant21 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc24;

// The transition label ist79

// Original guard: x1 = 2 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope70 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t71 = transition::ptr(new transition(71,"t79",22,13,guard_polytope70,assignment));

Out_Going_Trans_fromloc24.push_back(t71);
// The transition label ist82

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope71 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t72 = transition::ptr(new transition(72,"t82",22,21,guard_polytope71,assignment));

Out_Going_Trans_fromloc24.push_back(t72);
// The transition label ist80

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope72 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t73 = transition::ptr(new transition(73,"t80",22,23,guard_polytope72,assignment));

Out_Going_Trans_fromloc24.push_back(t73);
// The transition label ist81

// Original guard: x1 = 3 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope73 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t74 = transition::ptr(new transition(74,"t81",22,31,guard_polytope73,assignment));

Out_Going_Trans_fromloc24.push_back(t74);
location::ptr l22 = location::ptr(new location(22, "loc24", system_dynamics, invariant21, true, Out_Going_Trans_fromloc24));
Hybrid_Automata.addLocation(l22);


// The mode name is  loc23

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant22 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc23;

// The transition label ist75

// Original guard: x1 = 2 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope74 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t75 = transition::ptr(new transition(75,"t75",23,14,guard_polytope74,assignment));

Out_Going_Trans_fromloc23.push_back(t75);
// The transition label ist78

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope75 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t76 = transition::ptr(new transition(76,"t78",23,22,guard_polytope75,assignment));

Out_Going_Trans_fromloc23.push_back(t76);
// The transition label ist76

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope76 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t77 = transition::ptr(new transition(77,"t76",23,24,guard_polytope76,assignment));

Out_Going_Trans_fromloc23.push_back(t77);
// The transition label ist77

// Original guard: x1 = 3 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope77 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t78 = transition::ptr(new transition(78,"t77",23,32,guard_polytope77,assignment));

Out_Going_Trans_fromloc23.push_back(t78);
location::ptr l23 = location::ptr(new location(23, "loc23", system_dynamics, invariant22, true, Out_Going_Trans_fromloc23));
Hybrid_Automata.addLocation(l23);


// The mode name is  loc22

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant23 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc22;

// The transition label ist71

// Original guard: x1 = 2 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope78 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t79 = transition::ptr(new transition(79,"t71",24,15,guard_polytope78,assignment));

Out_Going_Trans_fromloc22.push_back(t79);
// The transition label ist74

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope79 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t80 = transition::ptr(new transition(80,"t74",24,23,guard_polytope79,assignment));

Out_Going_Trans_fromloc22.push_back(t80);
// The transition label ist72

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope80 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t81 = transition::ptr(new transition(81,"t72",24,25,guard_polytope80,assignment));

Out_Going_Trans_fromloc22.push_back(t81);
// The transition label ist73

// Original guard: x1 = 3 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope81 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t82 = transition::ptr(new transition(82,"t73",24,33,guard_polytope81,assignment));

Out_Going_Trans_fromloc22.push_back(t82);
location::ptr l24 = location::ptr(new location(24, "loc22", system_dynamics, invariant23, true, Out_Going_Trans_fromloc22));
Hybrid_Automata.addLocation(l24);


// The mode name is  loc21

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant24 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc21;

// The transition label ist67

// Original guard: x1 = 2 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope82 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t83 = transition::ptr(new transition(83,"t67",25,16,guard_polytope82,assignment));

Out_Going_Trans_fromloc21.push_back(t83);
// The transition label ist70

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope83 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t84 = transition::ptr(new transition(84,"t70",25,24,guard_polytope83,assignment));

Out_Going_Trans_fromloc21.push_back(t84);
// The transition label ist68

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope84 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t85 = transition::ptr(new transition(85,"t68",25,26,guard_polytope84,assignment));

Out_Going_Trans_fromloc21.push_back(t85);
// The transition label ist69

// Original guard: x1 = 3 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope85 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t86 = transition::ptr(new transition(86,"t69",25,34,guard_polytope85,assignment));

Out_Going_Trans_fromloc21.push_back(t86);
location::ptr l25 = location::ptr(new location(25, "loc21", system_dynamics, invariant24, true, Out_Going_Trans_fromloc21));
Hybrid_Automata.addLocation(l25);


// The mode name is  loc20

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant25 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc20;

// The transition label ist63

// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope86 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t87 = transition::ptr(new transition(87,"t63",26,17,guard_polytope86,assignment));

Out_Going_Trans_fromloc20.push_back(t87);
// The transition label ist66

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope87 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t88 = transition::ptr(new transition(88,"t66",26,25,guard_polytope87,assignment));

Out_Going_Trans_fromloc20.push_back(t88);
// The transition label ist64

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope88 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t89 = transition::ptr(new transition(89,"t64",26,27,guard_polytope88,assignment));

Out_Going_Trans_fromloc20.push_back(t89);
// The transition label ist65

// Original guard: x1 = 3 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope89 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t90 = transition::ptr(new transition(90,"t65",26,35,guard_polytope89,assignment));

Out_Going_Trans_fromloc20.push_back(t90);
location::ptr l26 = location::ptr(new location(26, "loc20", system_dynamics, invariant25, true, Out_Going_Trans_fromloc20));
Hybrid_Automata.addLocation(l26);


// The mode name is  loc19

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[3] = 1.0;
invariant26 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc19;

// The transition label ist60

// Original guard: x1 = 2 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 2.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope90 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t91 = transition::ptr(new transition(91,"t60",27,18,guard_polytope90,assignment));

Out_Going_Trans_fromloc19.push_back(t91);
// The transition label ist62

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -2.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope91 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t92 = transition::ptr(new transition(92,"t62",27,26,guard_polytope91,assignment));

Out_Going_Trans_fromloc19.push_back(t92);
// The transition label ist61

// Original guard: x1 = 3 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope92 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t93 = transition::ptr(new transition(93,"t61",27,36,guard_polytope92,assignment));

Out_Going_Trans_fromloc19.push_back(t93);
location::ptr l27 = location::ptr(new location(27, "loc19", system_dynamics, invariant26, true, Out_Going_Trans_fromloc19));
Hybrid_Automata.addLocation(l27);


// The mode name is  loc36

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant27 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc36;

// The transition label ist125

// Original guard: x1 = 3 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope93 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t94 = transition::ptr(new transition(94,"t125",28,19,guard_polytope93,assignment));

Out_Going_Trans_fromloc36.push_back(t94);
// The transition label ist126

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope94 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t95 = transition::ptr(new transition(95,"t126",28,29,guard_polytope94,assignment));

Out_Going_Trans_fromloc36.push_back(t95);
// The transition label ist127

// Original guard: x1 = 4 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope95 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t96 = transition::ptr(new transition(96,"t127",28,37,guard_polytope95,assignment));

Out_Going_Trans_fromloc36.push_back(t96);
location::ptr l28 = location::ptr(new location(28, "loc36", system_dynamics, invariant27, true, Out_Going_Trans_fromloc36));
Hybrid_Automata.addLocation(l28);


// The mode name is  loc35

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant28 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc35;

// The transition label ist121

// Original guard: x1 = 3 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope96 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t97 = transition::ptr(new transition(97,"t121",29,20,guard_polytope96,assignment));

Out_Going_Trans_fromloc35.push_back(t97);
// The transition label ist124

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope97 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t98 = transition::ptr(new transition(98,"t124",29,28,guard_polytope97,assignment));

Out_Going_Trans_fromloc35.push_back(t98);
// The transition label ist122

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope98 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t99 = transition::ptr(new transition(99,"t122",29,30,guard_polytope98,assignment));

Out_Going_Trans_fromloc35.push_back(t99);
// The transition label ist123

// Original guard: x1 = 4 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope99 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t100 = transition::ptr(new transition(100,"t123",29,38,guard_polytope99,assignment));

Out_Going_Trans_fromloc35.push_back(t100);
location::ptr l29 = location::ptr(new location(29, "loc35", system_dynamics, invariant28, true, Out_Going_Trans_fromloc35));
Hybrid_Automata.addLocation(l29);


// The mode name is  loc34

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant29 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc34;

// The transition label ist117

// Original guard: x1 = 3 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope100 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t101 = transition::ptr(new transition(101,"t117",30,21,guard_polytope100,assignment));

Out_Going_Trans_fromloc34.push_back(t101);
// The transition label ist118

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope101 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t102 = transition::ptr(new transition(102,"t118",30,31,guard_polytope101,assignment));

Out_Going_Trans_fromloc34.push_back(t102);
// The transition label ist119

// Original guard: x1 = 4 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope102 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t103 = transition::ptr(new transition(103,"t119",30,39,guard_polytope102,assignment));

Out_Going_Trans_fromloc34.push_back(t103);
// The transition label ist120

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope103 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t104 = transition::ptr(new transition(104,"t120",30,29,guard_polytope103,assignment));

Out_Going_Trans_fromloc34.push_back(t104);
location::ptr l30 = location::ptr(new location(30, "loc34", system_dynamics, invariant29, true, Out_Going_Trans_fromloc34));
Hybrid_Automata.addLocation(l30);


// The mode name is  loc33

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant30 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc33;

// The transition label ist113

// Original guard: x1 = 3 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope104 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t105 = transition::ptr(new transition(105,"t113",31,22,guard_polytope104,assignment));

Out_Going_Trans_fromloc33.push_back(t105);
// The transition label ist116

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope105 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t106 = transition::ptr(new transition(106,"t116",31,30,guard_polytope105,assignment));

Out_Going_Trans_fromloc33.push_back(t106);
// The transition label ist114

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope106 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t107 = transition::ptr(new transition(107,"t114",31,32,guard_polytope106,assignment));

Out_Going_Trans_fromloc33.push_back(t107);
// The transition label ist115

// Original guard: x1 = 4 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope107 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t108 = transition::ptr(new transition(108,"t115",31,40,guard_polytope107,assignment));

Out_Going_Trans_fromloc33.push_back(t108);
location::ptr l31 = location::ptr(new location(31, "loc33", system_dynamics, invariant30, true, Out_Going_Trans_fromloc33));
Hybrid_Automata.addLocation(l31);


// The mode name is  loc32

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant31 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc32;

// The transition label ist109

// Original guard: x1 = 3 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope108 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t109 = transition::ptr(new transition(109,"t109",32,23,guard_polytope108,assignment));

Out_Going_Trans_fromloc32.push_back(t109);
// The transition label ist112

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope109 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t110 = transition::ptr(new transition(110,"t112",32,31,guard_polytope109,assignment));

Out_Going_Trans_fromloc32.push_back(t110);
// The transition label ist110

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope110 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t111 = transition::ptr(new transition(111,"t110",32,33,guard_polytope110,assignment));

Out_Going_Trans_fromloc32.push_back(t111);
// The transition label ist111

// Original guard: x1 = 4 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope111 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t112 = transition::ptr(new transition(112,"t111",32,41,guard_polytope111,assignment));

Out_Going_Trans_fromloc32.push_back(t112);
location::ptr l32 = location::ptr(new location(32, "loc32", system_dynamics, invariant31, true, Out_Going_Trans_fromloc32));
Hybrid_Automata.addLocation(l32);


// The mode name is  loc31

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant32 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc31;

// The transition label ist105

// Original guard: x1 = 3 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope112 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t113 = transition::ptr(new transition(113,"t105",33,24,guard_polytope112,assignment));

Out_Going_Trans_fromloc31.push_back(t113);
// The transition label ist108

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope113 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t114 = transition::ptr(new transition(114,"t108",33,32,guard_polytope113,assignment));

Out_Going_Trans_fromloc31.push_back(t114);
// The transition label ist106

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope114 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t115 = transition::ptr(new transition(115,"t106",33,34,guard_polytope114,assignment));

Out_Going_Trans_fromloc31.push_back(t115);
// The transition label ist107

// Original guard: x1 = 4 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope115 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t116 = transition::ptr(new transition(116,"t107",33,42,guard_polytope115,assignment));

Out_Going_Trans_fromloc31.push_back(t116);
location::ptr l33 = location::ptr(new location(33, "loc31", system_dynamics, invariant32, true, Out_Going_Trans_fromloc31));
Hybrid_Automata.addLocation(l33);


// The mode name is  loc30

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant33 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc30;

// The transition label ist101

// Original guard: x1 = 3 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope116 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t117 = transition::ptr(new transition(117,"t101",34,25,guard_polytope116,assignment));

Out_Going_Trans_fromloc30.push_back(t117);
// The transition label ist104

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope117 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t118 = transition::ptr(new transition(118,"t104",34,33,guard_polytope117,assignment));

Out_Going_Trans_fromloc30.push_back(t118);
// The transition label ist102

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope118 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t119 = transition::ptr(new transition(119,"t102",34,35,guard_polytope118,assignment));

Out_Going_Trans_fromloc30.push_back(t119);
// The transition label ist103

// Original guard: x1 = 4 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope119 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t120 = transition::ptr(new transition(120,"t103",34,43,guard_polytope119,assignment));

Out_Going_Trans_fromloc30.push_back(t120);
location::ptr l34 = location::ptr(new location(34, "loc30", system_dynamics, invariant33, true, Out_Going_Trans_fromloc30));
Hybrid_Automata.addLocation(l34);


// The mode name is  loc29

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant34 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc29;

// The transition label ist97

// Original guard: x1 = 3 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope120 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t121 = transition::ptr(new transition(121,"t97",35,26,guard_polytope120,assignment));

Out_Going_Trans_fromloc29.push_back(t121);
// The transition label ist100

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope121 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t122 = transition::ptr(new transition(122,"t100",35,34,guard_polytope121,assignment));

Out_Going_Trans_fromloc29.push_back(t122);
// The transition label ist98

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope122 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t123 = transition::ptr(new transition(123,"t98",35,36,guard_polytope122,assignment));

Out_Going_Trans_fromloc29.push_back(t123);
// The transition label ist99

// Original guard: x1 = 4 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope123 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t124 = transition::ptr(new transition(124,"t99",35,44,guard_polytope123,assignment));

Out_Going_Trans_fromloc29.push_back(t124);
location::ptr l35 = location::ptr(new location(35, "loc29", system_dynamics, invariant34, true, Out_Going_Trans_fromloc29));
Hybrid_Automata.addLocation(l35);


// The mode name is  loc28

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant35 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc28;

// The transition label ist94

// Original guard: x1 = 3 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 3.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope124 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t125 = transition::ptr(new transition(125,"t94",36,27,guard_polytope124,assignment));

Out_Going_Trans_fromloc28.push_back(t125);
// The transition label ist96

// Original guard: 3 <= x1 & x1 <= 4 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -3.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope125 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t126 = transition::ptr(new transition(126,"t96",36,35,guard_polytope125,assignment));

Out_Going_Trans_fromloc28.push_back(t126);
// The transition label ist95

// Original guard: x1 = 4 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope126 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t127 = transition::ptr(new transition(127,"t95",36,45,guard_polytope126,assignment));

Out_Going_Trans_fromloc28.push_back(t127);
location::ptr l36 = location::ptr(new location(36, "loc28", system_dynamics, invariant35, true, Out_Going_Trans_fromloc28));
Hybrid_Automata.addLocation(l36);


// The mode name is  loc45

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant36 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc45;

// The transition label ist159

// Original guard: x1 = 4 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope127 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t128 = transition::ptr(new transition(128,"t159",37,28,guard_polytope127,assignment));

Out_Going_Trans_fromloc45.push_back(t128);
// The transition label ist160

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope128 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t129 = transition::ptr(new transition(129,"t160",37,38,guard_polytope128,assignment));

Out_Going_Trans_fromloc45.push_back(t129);
// The transition label ist161

// Original guard: x1 = 5 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope129 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t130 = transition::ptr(new transition(130,"t161",37,46,guard_polytope129,assignment));

Out_Going_Trans_fromloc45.push_back(t130);
location::ptr l37 = location::ptr(new location(37, "loc45", system_dynamics, invariant36, true, Out_Going_Trans_fromloc45));
Hybrid_Automata.addLocation(l37);


// The mode name is  loc44

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant37 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc44;

// The transition label ist155

// Original guard: x1 = 4 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope130 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t131 = transition::ptr(new transition(131,"t155",38,29,guard_polytope130,assignment));

Out_Going_Trans_fromloc44.push_back(t131);
// The transition label ist158

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope131 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t132 = transition::ptr(new transition(132,"t158",38,37,guard_polytope131,assignment));

Out_Going_Trans_fromloc44.push_back(t132);
// The transition label ist156

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope132 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t133 = transition::ptr(new transition(133,"t156",38,39,guard_polytope132,assignment));

Out_Going_Trans_fromloc44.push_back(t133);
// The transition label ist157

// Original guard: x1 = 5 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope133 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t134 = transition::ptr(new transition(134,"t157",38,47,guard_polytope133,assignment));

Out_Going_Trans_fromloc44.push_back(t134);
location::ptr l38 = location::ptr(new location(38, "loc44", system_dynamics, invariant37, true, Out_Going_Trans_fromloc44));
Hybrid_Automata.addLocation(l38);


// The mode name is  loc43

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant38 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc43;

// The transition label ist151

// Original guard: x1 = 4 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope134 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t135 = transition::ptr(new transition(135,"t151",39,30,guard_polytope134,assignment));

Out_Going_Trans_fromloc43.push_back(t135);
// The transition label ist154

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope135 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t136 = transition::ptr(new transition(136,"t154",39,38,guard_polytope135,assignment));

Out_Going_Trans_fromloc43.push_back(t136);
// The transition label ist152

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope136 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t137 = transition::ptr(new transition(137,"t152",39,40,guard_polytope136,assignment));

Out_Going_Trans_fromloc43.push_back(t137);
// The transition label ist153

// Original guard: x1 = 5 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope137 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t138 = transition::ptr(new transition(138,"t153",39,48,guard_polytope137,assignment));

Out_Going_Trans_fromloc43.push_back(t138);
location::ptr l39 = location::ptr(new location(39, "loc43", system_dynamics, invariant38, true, Out_Going_Trans_fromloc43));
Hybrid_Automata.addLocation(l39);


// The mode name is  loc42

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant39 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc42;

// The transition label ist147

// Original guard: x1 = 4 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope138 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t139 = transition::ptr(new transition(139,"t147",40,31,guard_polytope138,assignment));

Out_Going_Trans_fromloc42.push_back(t139);
// The transition label ist150

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope139 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t140 = transition::ptr(new transition(140,"t150",40,39,guard_polytope139,assignment));

Out_Going_Trans_fromloc42.push_back(t140);
// The transition label ist148

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope140 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t141 = transition::ptr(new transition(141,"t148",40,41,guard_polytope140,assignment));

Out_Going_Trans_fromloc42.push_back(t141);
// The transition label ist149

// Original guard: x1 = 5 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope141 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t142 = transition::ptr(new transition(142,"t149",40,49,guard_polytope141,assignment));

Out_Going_Trans_fromloc42.push_back(t142);
location::ptr l40 = location::ptr(new location(40, "loc42", system_dynamics, invariant39, true, Out_Going_Trans_fromloc42));
Hybrid_Automata.addLocation(l40);


// The mode name is  loc41

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant40 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc41;

// The transition label ist143

// Original guard: x1 = 4 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope142 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t143 = transition::ptr(new transition(143,"t143",41,32,guard_polytope142,assignment));

Out_Going_Trans_fromloc41.push_back(t143);
// The transition label ist146

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope143 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t144 = transition::ptr(new transition(144,"t146",41,40,guard_polytope143,assignment));

Out_Going_Trans_fromloc41.push_back(t144);
// The transition label ist144

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope144 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t145 = transition::ptr(new transition(145,"t144",41,42,guard_polytope144,assignment));

Out_Going_Trans_fromloc41.push_back(t145);
// The transition label ist145

// Original guard: x1 = 5 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope145 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t146 = transition::ptr(new transition(146,"t145",41,50,guard_polytope145,assignment));

Out_Going_Trans_fromloc41.push_back(t146);
location::ptr l41 = location::ptr(new location(41, "loc41", system_dynamics, invariant40, true, Out_Going_Trans_fromloc41));
Hybrid_Automata.addLocation(l41);


// The mode name is  loc40

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant41 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc40;

// The transition label ist139

// Original guard: x1 = 4 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope146 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t147 = transition::ptr(new transition(147,"t139",42,33,guard_polytope146,assignment));

Out_Going_Trans_fromloc40.push_back(t147);
// The transition label ist142

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope147 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t148 = transition::ptr(new transition(148,"t142",42,41,guard_polytope147,assignment));

Out_Going_Trans_fromloc40.push_back(t148);
// The transition label ist140

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope148 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t149 = transition::ptr(new transition(149,"t140",42,43,guard_polytope148,assignment));

Out_Going_Trans_fromloc40.push_back(t149);
// The transition label ist141

// Original guard: x1 = 5 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope149 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t150 = transition::ptr(new transition(150,"t141",42,51,guard_polytope149,assignment));

Out_Going_Trans_fromloc40.push_back(t150);
location::ptr l42 = location::ptr(new location(42, "loc40", system_dynamics, invariant41, true, Out_Going_Trans_fromloc40));
Hybrid_Automata.addLocation(l42);


// The mode name is  loc39

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant42 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc39;

// The transition label ist135

// Original guard: x1 = 4 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope150 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t151 = transition::ptr(new transition(151,"t135",43,34,guard_polytope150,assignment));

Out_Going_Trans_fromloc39.push_back(t151);
// The transition label ist138

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope151 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t152 = transition::ptr(new transition(152,"t138",43,42,guard_polytope151,assignment));

Out_Going_Trans_fromloc39.push_back(t152);
// The transition label ist136

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope152 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t153 = transition::ptr(new transition(153,"t136",43,44,guard_polytope152,assignment));

Out_Going_Trans_fromloc39.push_back(t153);
// The transition label ist137

// Original guard: x1 = 5 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope153 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t154 = transition::ptr(new transition(154,"t137",43,52,guard_polytope153,assignment));

Out_Going_Trans_fromloc39.push_back(t154);
location::ptr l43 = location::ptr(new location(43, "loc39", system_dynamics, invariant42, true, Out_Going_Trans_fromloc39));
Hybrid_Automata.addLocation(l43);


// The mode name is  loc38

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant43 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc38;

// The transition label ist131

// Original guard: x1 = 4 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope154 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t155 = transition::ptr(new transition(155,"t131",44,35,guard_polytope154,assignment));

Out_Going_Trans_fromloc38.push_back(t155);
// The transition label ist134

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope155 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t156 = transition::ptr(new transition(156,"t134",44,43,guard_polytope155,assignment));

Out_Going_Trans_fromloc38.push_back(t156);
// The transition label ist132

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope156 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t157 = transition::ptr(new transition(157,"t132",44,45,guard_polytope156,assignment));

Out_Going_Trans_fromloc38.push_back(t157);
// The transition label ist133

// Original guard: x1 = 5 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope157 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t158 = transition::ptr(new transition(158,"t133",44,53,guard_polytope157,assignment));

Out_Going_Trans_fromloc38.push_back(t158);
location::ptr l44 = location::ptr(new location(44, "loc38", system_dynamics, invariant43, true, Out_Going_Trans_fromloc38));
Hybrid_Automata.addLocation(l44);


// The mode name is  loc37

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[3] = 1.0;
invariant44 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc37;

// The transition label ist128

// Original guard: x1 = 4 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 4.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope158 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t159 = transition::ptr(new transition(159,"t128",45,36,guard_polytope158,assignment));

Out_Going_Trans_fromloc37.push_back(t159);
// The transition label ist130

// Original guard: 4 <= x1 & x1 <= 5 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -4.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope159 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t160 = transition::ptr(new transition(160,"t130",45,44,guard_polytope159,assignment));

Out_Going_Trans_fromloc37.push_back(t160);
// The transition label ist129

// Original guard: x1 = 5 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope160 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t161 = transition::ptr(new transition(161,"t129",45,54,guard_polytope160,assignment));

Out_Going_Trans_fromloc37.push_back(t161);
location::ptr l45 = location::ptr(new location(45, "loc37", system_dynamics, invariant44, true, Out_Going_Trans_fromloc37));
Hybrid_Automata.addLocation(l45);


// The mode name is  loc54

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -1.202;
C[3] = -1.202;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant45 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc54;

// The transition label ist193

// Original guard: x1 = 5 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope161 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t162 = transition::ptr(new transition(162,"t193",46,37,guard_polytope161,assignment));

Out_Going_Trans_fromloc54.push_back(t162);
// The transition label ist194

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope162 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t163 = transition::ptr(new transition(163,"t194",46,47,guard_polytope162,assignment));

Out_Going_Trans_fromloc54.push_back(t163);
// The transition label ist195

// Original guard: x1 = 6 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope163 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t164 = transition::ptr(new transition(164,"t195",46,55,guard_polytope163,assignment));

Out_Going_Trans_fromloc54.push_back(t164);
location::ptr l46 = location::ptr(new location(46, "loc54", system_dynamics, invariant45, true, Out_Going_Trans_fromloc54));
Hybrid_Automata.addLocation(l46);


// The mode name is  loc53

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -1.202;
C[3] = -1.202;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant46 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc53;

// The transition label ist189

// Original guard: x1 = 5 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope164 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t165 = transition::ptr(new transition(165,"t189",47,38,guard_polytope164,assignment));

Out_Going_Trans_fromloc53.push_back(t165);
// The transition label ist192

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope165 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t166 = transition::ptr(new transition(166,"t192",47,46,guard_polytope165,assignment));

Out_Going_Trans_fromloc53.push_back(t166);
// The transition label ist190

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope166 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t167 = transition::ptr(new transition(167,"t190",47,48,guard_polytope166,assignment));

Out_Going_Trans_fromloc53.push_back(t167);
// The transition label ist191

// Original guard: x1 = 6 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope167 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t168 = transition::ptr(new transition(168,"t191",47,56,guard_polytope167,assignment));

Out_Going_Trans_fromloc53.push_back(t168);
location::ptr l47 = location::ptr(new location(47, "loc53", system_dynamics, invariant46, true, Out_Going_Trans_fromloc53));
Hybrid_Automata.addLocation(l47);


// The mode name is  loc52

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -1.202;
C[3] = -1.202;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant47 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc52;

// The transition label ist185

// Original guard: x1 = 5 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope168 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t169 = transition::ptr(new transition(169,"t185",48,39,guard_polytope168,assignment));

Out_Going_Trans_fromloc52.push_back(t169);
// The transition label ist188

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope169 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t170 = transition::ptr(new transition(170,"t188",48,47,guard_polytope169,assignment));

Out_Going_Trans_fromloc52.push_back(t170);
// The transition label ist186

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope170 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t171 = transition::ptr(new transition(171,"t186",48,49,guard_polytope170,assignment));

Out_Going_Trans_fromloc52.push_back(t171);
// The transition label ist187

// Original guard: x1 = 6 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope171 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t172 = transition::ptr(new transition(172,"t187",48,57,guard_polytope171,assignment));

Out_Going_Trans_fromloc52.push_back(t172);
location::ptr l48 = location::ptr(new location(48, "loc52", system_dynamics, invariant47, true, Out_Going_Trans_fromloc52));
Hybrid_Automata.addLocation(l48);


// The mode name is  loc51

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant48 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc51;

// The transition label ist181

// Original guard: x1 = 5 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope172 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t173 = transition::ptr(new transition(173,"t181",49,40,guard_polytope172,assignment));

Out_Going_Trans_fromloc51.push_back(t173);
// The transition label ist184

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope173 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t174 = transition::ptr(new transition(174,"t184",49,48,guard_polytope173,assignment));

Out_Going_Trans_fromloc51.push_back(t174);
// The transition label ist182

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope174 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t175 = transition::ptr(new transition(175,"t182",49,50,guard_polytope174,assignment));

Out_Going_Trans_fromloc51.push_back(t175);
// The transition label ist183

// Original guard: x1 = 6 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope175 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t176 = transition::ptr(new transition(176,"t183",49,58,guard_polytope175,assignment));

Out_Going_Trans_fromloc51.push_back(t176);
location::ptr l49 = location::ptr(new location(49, "loc51", system_dynamics, invariant48, true, Out_Going_Trans_fromloc51));
Hybrid_Automata.addLocation(l49);


// The mode name is  loc50

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant49 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc50;

// The transition label ist177

// Original guard: x1 = 5 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope176 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t177 = transition::ptr(new transition(177,"t177",50,41,guard_polytope176,assignment));

Out_Going_Trans_fromloc50.push_back(t177);
// The transition label ist180

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope177 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t178 = transition::ptr(new transition(178,"t180",50,49,guard_polytope177,assignment));

Out_Going_Trans_fromloc50.push_back(t178);
// The transition label ist178

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope178 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t179 = transition::ptr(new transition(179,"t178",50,51,guard_polytope178,assignment));

Out_Going_Trans_fromloc50.push_back(t179);
// The transition label ist179

// Original guard: x1 = 6 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope179 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t180 = transition::ptr(new transition(180,"t179",50,59,guard_polytope179,assignment));

Out_Going_Trans_fromloc50.push_back(t180);
location::ptr l50 = location::ptr(new location(50, "loc50", system_dynamics, invariant49, true, Out_Going_Trans_fromloc50));
Hybrid_Automata.addLocation(l50);


// The mode name is  loc49

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant50 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc49;

// The transition label ist173

// Original guard: x1 = 5 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope180 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t181 = transition::ptr(new transition(181,"t173",51,42,guard_polytope180,assignment));

Out_Going_Trans_fromloc49.push_back(t181);
// The transition label ist176

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope181 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t182 = transition::ptr(new transition(182,"t176",51,50,guard_polytope181,assignment));

Out_Going_Trans_fromloc49.push_back(t182);
// The transition label ist174

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope182 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t183 = transition::ptr(new transition(183,"t174",51,52,guard_polytope182,assignment));

Out_Going_Trans_fromloc49.push_back(t183);
// The transition label ist175

// Original guard: x1 = 6 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope183 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t184 = transition::ptr(new transition(184,"t175",51,60,guard_polytope183,assignment));

Out_Going_Trans_fromloc49.push_back(t184);
location::ptr l51 = location::ptr(new location(51, "loc49", system_dynamics, invariant50, true, Out_Going_Trans_fromloc49));
Hybrid_Automata.addLocation(l51);


// The mode name is  loc48

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant51 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc48;

// The transition label ist169

// Original guard: x1 = 5 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope184 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t185 = transition::ptr(new transition(185,"t169",52,43,guard_polytope184,assignment));

Out_Going_Trans_fromloc48.push_back(t185);
// The transition label ist172

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope185 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t186 = transition::ptr(new transition(186,"t172",52,51,guard_polytope185,assignment));

Out_Going_Trans_fromloc48.push_back(t186);
// The transition label ist170

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope186 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t187 = transition::ptr(new transition(187,"t170",52,53,guard_polytope186,assignment));

Out_Going_Trans_fromloc48.push_back(t187);
// The transition label ist171

// Original guard: x1 = 6 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope187 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t188 = transition::ptr(new transition(188,"t171",52,61,guard_polytope187,assignment));

Out_Going_Trans_fromloc48.push_back(t188);
location::ptr l52 = location::ptr(new location(52, "loc48", system_dynamics, invariant51, true, Out_Going_Trans_fromloc48));
Hybrid_Automata.addLocation(l52);


// The mode name is  loc47

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant52 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc47;

// The transition label ist165

// Original guard: x1 = 5 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope188 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t189 = transition::ptr(new transition(189,"t165",53,44,guard_polytope188,assignment));

Out_Going_Trans_fromloc47.push_back(t189);
// The transition label ist168

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope189 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t190 = transition::ptr(new transition(190,"t168",53,52,guard_polytope189,assignment));

Out_Going_Trans_fromloc47.push_back(t190);
// The transition label ist166

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope190 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t191 = transition::ptr(new transition(191,"t166",53,54,guard_polytope190,assignment));

Out_Going_Trans_fromloc47.push_back(t191);
// The transition label ist167

// Original guard: x1 = 6 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope191 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t192 = transition::ptr(new transition(192,"t167",53,62,guard_polytope191,assignment));

Out_Going_Trans_fromloc47.push_back(t192);
location::ptr l53 = location::ptr(new location(53, "loc47", system_dynamics, invariant52, true, Out_Going_Trans_fromloc47));
Hybrid_Automata.addLocation(l53);


// The mode name is  loc46

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant53 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc46;

// The transition label ist162

// Original guard: x1 = 5 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 5.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope192 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t193 = transition::ptr(new transition(193,"t162",54,45,guard_polytope192,assignment));

Out_Going_Trans_fromloc46.push_back(t193);
// The transition label ist164

// Original guard: 5 <= x1 & x1 <= 6 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -5.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope193 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t194 = transition::ptr(new transition(194,"t164",54,53,guard_polytope193,assignment));

Out_Going_Trans_fromloc46.push_back(t194);
// The transition label ist163

// Original guard: x1 = 6 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope194 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t195 = transition::ptr(new transition(195,"t163",54,63,guard_polytope194,assignment));

Out_Going_Trans_fromloc46.push_back(t195);
location::ptr l54 = location::ptr(new location(54, "loc46", system_dynamics, invariant53, true, Out_Going_Trans_fromloc46));
Hybrid_Automata.addLocation(l54);


// The mode name is  loc63

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant54 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc63;

// The transition label ist227

// Original guard: x1 = 6 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope195 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t196 = transition::ptr(new transition(196,"t227",55,46,guard_polytope195,assignment));

Out_Going_Trans_fromloc63.push_back(t196);
// The transition label ist228

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope196 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t197 = transition::ptr(new transition(197,"t228",55,56,guard_polytope196,assignment));

Out_Going_Trans_fromloc63.push_back(t197);
// The transition label ist229

// Original guard: x1 = 7 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope197 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t198 = transition::ptr(new transition(198,"t229",55,64,guard_polytope197,assignment));

Out_Going_Trans_fromloc63.push_back(t198);
location::ptr l55 = location::ptr(new location(55, "loc63", system_dynamics, invariant54, true, Out_Going_Trans_fromloc63));
Hybrid_Automata.addLocation(l55);


// The mode name is  loc62

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -1.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant55 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc62;

// The transition label ist223

// Original guard: x1 = 6 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope198 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t199 = transition::ptr(new transition(199,"t223",56,47,guard_polytope198,assignment));

Out_Going_Trans_fromloc62.push_back(t199);
// The transition label ist226

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope199 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t200 = transition::ptr(new transition(200,"t226",56,55,guard_polytope199,assignment));

Out_Going_Trans_fromloc62.push_back(t200);
// The transition label ist224

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope200 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t201 = transition::ptr(new transition(201,"t224",56,57,guard_polytope200,assignment));

Out_Going_Trans_fromloc62.push_back(t201);
// The transition label ist225

// Original guard: x1 = 7 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope201 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t202 = transition::ptr(new transition(202,"t225",56,65,guard_polytope201,assignment));

Out_Going_Trans_fromloc62.push_back(t202);
location::ptr l56 = location::ptr(new location(56, "loc62", system_dynamics, invariant55, true, Out_Going_Trans_fromloc62));
Hybrid_Automata.addLocation(l56);


// The mode name is  loc61

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant56 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc61;

// The transition label ist219

// Original guard: x1 = 6 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope202 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t203 = transition::ptr(new transition(203,"t219",57,48,guard_polytope202,assignment));

Out_Going_Trans_fromloc61.push_back(t203);
// The transition label ist222

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope203 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t204 = transition::ptr(new transition(204,"t222",57,56,guard_polytope203,assignment));

Out_Going_Trans_fromloc61.push_back(t204);
// The transition label ist220

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope204 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t205 = transition::ptr(new transition(205,"t220",57,58,guard_polytope204,assignment));

Out_Going_Trans_fromloc61.push_back(t205);
// The transition label ist221

// Original guard: x1 = 7 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope205 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t206 = transition::ptr(new transition(206,"t221",57,66,guard_polytope205,assignment));

Out_Going_Trans_fromloc61.push_back(t206);
location::ptr l57 = location::ptr(new location(57, "loc61", system_dynamics, invariant56, true, Out_Going_Trans_fromloc61));
Hybrid_Automata.addLocation(l57);


// The mode name is  loc60

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant57 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc60;

// The transition label ist215

// Original guard: x1 = 6 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope206 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t207 = transition::ptr(new transition(207,"t215",58,49,guard_polytope206,assignment));

Out_Going_Trans_fromloc60.push_back(t207);
// The transition label ist218

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope207 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t208 = transition::ptr(new transition(208,"t218",58,57,guard_polytope207,assignment));

Out_Going_Trans_fromloc60.push_back(t208);
// The transition label ist216

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope208 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t209 = transition::ptr(new transition(209,"t216",58,59,guard_polytope208,assignment));

Out_Going_Trans_fromloc60.push_back(t209);
// The transition label ist217

// Original guard: x1 = 7 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope209 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t210 = transition::ptr(new transition(210,"t217",58,67,guard_polytope209,assignment));

Out_Going_Trans_fromloc60.push_back(t210);
location::ptr l58 = location::ptr(new location(58, "loc60", system_dynamics, invariant57, true, Out_Going_Trans_fromloc60));
Hybrid_Automata.addLocation(l58);


// The mode name is  loc59

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant58 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc59;

// The transition label ist211

// Original guard: x1 = 6 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope210 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t211 = transition::ptr(new transition(211,"t211",59,50,guard_polytope210,assignment));

Out_Going_Trans_fromloc59.push_back(t211);
// The transition label ist214

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope211 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t212 = transition::ptr(new transition(212,"t214",59,58,guard_polytope211,assignment));

Out_Going_Trans_fromloc59.push_back(t212);
// The transition label ist212

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope212 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t213 = transition::ptr(new transition(213,"t212",59,60,guard_polytope212,assignment));

Out_Going_Trans_fromloc59.push_back(t213);
// The transition label ist213

// Original guard: x1 = 7 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope213 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t214 = transition::ptr(new transition(214,"t213",59,68,guard_polytope213,assignment));

Out_Going_Trans_fromloc59.push_back(t214);
location::ptr l59 = location::ptr(new location(59, "loc59", system_dynamics, invariant58, true, Out_Going_Trans_fromloc59));
Hybrid_Automata.addLocation(l59);


// The mode name is  loc58

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant59 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc58;

// The transition label ist207

// Original guard: x1 = 6 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope214 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t215 = transition::ptr(new transition(215,"t207",60,51,guard_polytope214,assignment));

Out_Going_Trans_fromloc58.push_back(t215);
// The transition label ist210

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope215 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t216 = transition::ptr(new transition(216,"t210",60,59,guard_polytope215,assignment));

Out_Going_Trans_fromloc58.push_back(t216);
// The transition label ist208

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope216 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t217 = transition::ptr(new transition(217,"t208",60,61,guard_polytope216,assignment));

Out_Going_Trans_fromloc58.push_back(t217);
// The transition label ist209

// Original guard: x1 = 7 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope217 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t218 = transition::ptr(new transition(218,"t209",60,69,guard_polytope217,assignment));

Out_Going_Trans_fromloc58.push_back(t218);
location::ptr l60 = location::ptr(new location(60, "loc58", system_dynamics, invariant59, true, Out_Going_Trans_fromloc58));
Hybrid_Automata.addLocation(l60);


// The mode name is  loc57

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant60 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc57;

// The transition label ist203

// Original guard: x1 = 6 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope218 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t219 = transition::ptr(new transition(219,"t203",61,52,guard_polytope218,assignment));

Out_Going_Trans_fromloc57.push_back(t219);
// The transition label ist206

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope219 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t220 = transition::ptr(new transition(220,"t206",61,60,guard_polytope219,assignment));

Out_Going_Trans_fromloc57.push_back(t220);
// The transition label ist204

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope220 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t221 = transition::ptr(new transition(221,"t204",61,62,guard_polytope220,assignment));

Out_Going_Trans_fromloc57.push_back(t221);
// The transition label ist205

// Original guard: x1 = 7 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope221 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t222 = transition::ptr(new transition(222,"t205",61,70,guard_polytope221,assignment));

Out_Going_Trans_fromloc57.push_back(t222);
location::ptr l61 = location::ptr(new location(61, "loc57", system_dynamics, invariant60, true, Out_Going_Trans_fromloc57));
Hybrid_Automata.addLocation(l61);


// The mode name is  loc56

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.9192;
C[3] = -0.495;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant61 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc56;

// The transition label ist199

// Original guard: x1 = 6 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope222 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t223 = transition::ptr(new transition(223,"t199",62,53,guard_polytope222,assignment));

Out_Going_Trans_fromloc56.push_back(t223);
// The transition label ist202

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope223 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t224 = transition::ptr(new transition(224,"t202",62,61,guard_polytope223,assignment));

Out_Going_Trans_fromloc56.push_back(t224);
// The transition label ist200

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope224 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t225 = transition::ptr(new transition(225,"t200",62,63,guard_polytope224,assignment));

Out_Going_Trans_fromloc56.push_back(t225);
// The transition label ist201

// Original guard: x1 = 7 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope225 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t226 = transition::ptr(new transition(226,"t201",62,71,guard_polytope225,assignment));

Out_Going_Trans_fromloc56.push_back(t226);
location::ptr l62 = location::ptr(new location(62, "loc56", system_dynamics, invariant61, true, Out_Going_Trans_fromloc56));
Hybrid_Automata.addLocation(l62);


// The mode name is  loc55

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[3] = 1.0;
invariant62 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc55;

// The transition label ist196

// Original guard: x1 = 6 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 6.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope226 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t227 = transition::ptr(new transition(227,"t196",63,54,guard_polytope226,assignment));

Out_Going_Trans_fromloc55.push_back(t227);
// The transition label ist198

// Original guard: 6 <= x1 & x1 <= 7 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -6.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope227 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t228 = transition::ptr(new transition(228,"t198",63,62,guard_polytope227,assignment));

Out_Going_Trans_fromloc55.push_back(t228);
// The transition label ist197

// Original guard: x1 = 7 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope228 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t229 = transition::ptr(new transition(229,"t197",63,72,guard_polytope228,assignment));

Out_Going_Trans_fromloc55.push_back(t229);
location::ptr l63 = location::ptr(new location(63, "loc55", system_dynamics, invariant62, true, Out_Going_Trans_fromloc55));
Hybrid_Automata.addLocation(l63);


// The mode name is  loc72

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant63 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc72;

// The transition label ist253

// Original guard: x1 = 7 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope229 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t230 = transition::ptr(new transition(230,"t253",64,55,guard_polytope229,assignment));

Out_Going_Trans_fromloc72.push_back(t230);
// The transition label ist254

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope230 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t231 = transition::ptr(new transition(231,"t254",64,65,guard_polytope230,assignment));

Out_Going_Trans_fromloc72.push_back(t231);
// The transition label ist255

// Original guard: x1 = 8 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope231 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t232 = transition::ptr(new transition(232,"t255",64,73,guard_polytope231,assignment));

Out_Going_Trans_fromloc72.push_back(t232);
location::ptr l64 = location::ptr(new location(64, "loc72", system_dynamics, invariant63, true, Out_Going_Trans_fromloc72));
Hybrid_Automata.addLocation(l64);


// The mode name is  BAD

row = 5;
col = 5;
system_dynamics.isEmptyMatrixA = true;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant64 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromBAD;


location::ptr l65 = location::ptr(new location(65, "BAD", system_dynamics, invariant64, true, Out_Going_Trans_fromBAD));
Hybrid_Automata.addLocation(l65);


// The mode name is  loc70

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant65 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc70;

// The transition label ist249

// Original guard: x1 = 7 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope232 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t233 = transition::ptr(new transition(233,"t249",66,57,guard_polytope232,assignment));

Out_Going_Trans_fromloc70.push_back(t233);
// The transition label ist252

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope233 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t234 = transition::ptr(new transition(234,"t252",66,65,guard_polytope233,assignment));

Out_Going_Trans_fromloc70.push_back(t234);
// The transition label ist250

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope234 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t235 = transition::ptr(new transition(235,"t250",66,67,guard_polytope234,assignment));

Out_Going_Trans_fromloc70.push_back(t235);
// The transition label ist251

// Original guard: x1 = 8 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope235 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t236 = transition::ptr(new transition(236,"t251",66,75,guard_polytope235,assignment));

Out_Going_Trans_fromloc70.push_back(t236);
location::ptr l66 = location::ptr(new location(66, "loc70", system_dynamics, invariant65, true, Out_Going_Trans_fromloc70));
Hybrid_Automata.addLocation(l66);


// The mode name is  loc69

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant66 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc69;

// The transition label ist245

// Original guard: x1 = 7 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope236 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t237 = transition::ptr(new transition(237,"t245",67,58,guard_polytope236,assignment));

Out_Going_Trans_fromloc69.push_back(t237);
// The transition label ist248

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope237 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t238 = transition::ptr(new transition(238,"t248",67,66,guard_polytope237,assignment));

Out_Going_Trans_fromloc69.push_back(t238);
// The transition label ist246

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope238 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t239 = transition::ptr(new transition(239,"t246",67,68,guard_polytope238,assignment));

Out_Going_Trans_fromloc69.push_back(t239);
// The transition label ist247

// Original guard: x1 = 8 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope239 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t240 = transition::ptr(new transition(240,"t247",67,76,guard_polytope239,assignment));

Out_Going_Trans_fromloc69.push_back(t240);
location::ptr l67 = location::ptr(new location(67, "loc69", system_dynamics, invariant66, true, Out_Going_Trans_fromloc69));
Hybrid_Automata.addLocation(l67);


// The mode name is  loc68

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant67 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc68;

// The transition label ist241

// Original guard: x1 = 7 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope240 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t241 = transition::ptr(new transition(241,"t241",68,59,guard_polytope240,assignment));

Out_Going_Trans_fromloc68.push_back(t241);
// The transition label ist244

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope241 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t242 = transition::ptr(new transition(242,"t244",68,67,guard_polytope241,assignment));

Out_Going_Trans_fromloc68.push_back(t242);
// The transition label ist242

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope242 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t243 = transition::ptr(new transition(243,"t242",68,69,guard_polytope242,assignment));

Out_Going_Trans_fromloc68.push_back(t243);
// The transition label ist243

// Original guard: x1 = 8 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope243 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t244 = transition::ptr(new transition(244,"t243",68,77,guard_polytope243,assignment));

Out_Going_Trans_fromloc68.push_back(t244);
location::ptr l68 = location::ptr(new location(68, "loc68", system_dynamics, invariant67, true, Out_Going_Trans_fromloc68));
Hybrid_Automata.addLocation(l68);


// The mode name is  loc67

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant68 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc67;

// The transition label ist237

// Original guard: x1 = 7 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope244 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t245 = transition::ptr(new transition(245,"t237",69,60,guard_polytope244,assignment));

Out_Going_Trans_fromloc67.push_back(t245);
// The transition label ist240

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope245 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t246 = transition::ptr(new transition(246,"t240",69,68,guard_polytope245,assignment));

Out_Going_Trans_fromloc67.push_back(t246);
// The transition label ist238

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope246 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t247 = transition::ptr(new transition(247,"t238",69,70,guard_polytope246,assignment));

Out_Going_Trans_fromloc67.push_back(t247);
// The transition label ist239

// Original guard: x1 = 8 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope247 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t248 = transition::ptr(new transition(248,"t239",69,78,guard_polytope247,assignment));

Out_Going_Trans_fromloc67.push_back(t248);
location::ptr l69 = location::ptr(new location(69, "loc67", system_dynamics, invariant68, true, Out_Going_Trans_fromloc67));
Hybrid_Automata.addLocation(l69);


// The mode name is  GOOD

row = 5;
col = 5;
system_dynamics.isEmptyMatrixA = true;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant69 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromGOOD;


location::ptr l70 = location::ptr(new location(70, "GOOD", system_dynamics, invariant69, true, Out_Going_Trans_fromGOOD));
Hybrid_Automata.addLocation(l70);


// The mode name is  loc65

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant70 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc65;

// The transition label ist233

// Original guard: x1 = 7 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope248 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t249 = transition::ptr(new transition(249,"t233",71,62,guard_polytope248,assignment));

Out_Going_Trans_fromloc65.push_back(t249);
// The transition label ist234

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope249 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t250 = transition::ptr(new transition(250,"t234",71,72,guard_polytope249,assignment));

Out_Going_Trans_fromloc65.push_back(t250);
// The transition label ist236

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope250 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t251 = transition::ptr(new transition(251,"t236",71,70,guard_polytope250,assignment));

Out_Going_Trans_fromloc65.push_back(t251);
// The transition label ist235

// Original guard: x1 = 8 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope251 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t252 = transition::ptr(new transition(252,"t235",71,80,guard_polytope251,assignment));

Out_Going_Trans_fromloc65.push_back(t252);
location::ptr l71 = location::ptr(new location(71, "loc65", system_dynamics, invariant70, true, Out_Going_Trans_fromloc65));
Hybrid_Automata.addLocation(l71);


// The mode name is  loc64

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariant71 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc64;

// The transition label ist230

// Original guard: x1 = 7 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 7.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope252 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t253 = transition::ptr(new transition(253,"t230",72,63,guard_polytope252,assignment));

Out_Going_Trans_fromloc64.push_back(t253);
// The transition label ist232

// Original guard: 7 <= x1 & x1 <= 8 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -7.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope253 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t254 = transition::ptr(new transition(254,"t232",72,71,guard_polytope253,assignment));

Out_Going_Trans_fromloc64.push_back(t254);
// The transition label ist231

// Original guard: x1 = 8 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope254 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t255 = transition::ptr(new transition(255,"t231",72,81,guard_polytope254,assignment));

Out_Going_Trans_fromloc64.push_back(t255);
location::ptr l72 = location::ptr(new location(72, "loc64", system_dynamics, invariant71, true, Out_Going_Trans_fromloc64));
Hybrid_Automata.addLocation(l72);


// The mode name is  loc81

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -8.0;
invariantBoundValue[3] = 9.0;
invariant72 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc81;

// The transition label ist279

// Original guard: x1 = 8 & 8 <= x2 & x2 <= 9 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 9.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope255 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t256 = transition::ptr(new transition(256,"t279",73,64,guard_polytope255,assignment));

Out_Going_Trans_fromloc81.push_back(t256);
// The transition label ist280

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope256 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t257 = transition::ptr(new transition(257,"t280",73,74,guard_polytope256,assignment));

Out_Going_Trans_fromloc81.push_back(t257);
location::ptr l73 = location::ptr(new location(73, "loc81", system_dynamics, invariant72, true, Out_Going_Trans_fromloc81));
Hybrid_Automata.addLocation(l73);


// The mode name is  loc80

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 1.5;
C[3] = 0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -7.0;
invariantBoundValue[3] = 8.0;
invariant73 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc80;

// The transition label ist276

// Original guard: x1 = 8 & 7 <= x2 & x2 <= 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope257 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t258 = transition::ptr(new transition(258,"t276",74,65,guard_polytope257,assignment));

Out_Going_Trans_fromloc80.push_back(t258);
// The transition label ist278

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 8 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -8.0;
guardBoundValue[3] = 8.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope258 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t259 = transition::ptr(new transition(259,"t278",74,73,guard_polytope258,assignment));

Out_Going_Trans_fromloc80.push_back(t259);
// The transition label ist277

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope259 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t260 = transition::ptr(new transition(260,"t277",74,75,guard_polytope259,assignment));

Out_Going_Trans_fromloc80.push_back(t260);
location::ptr l74 = location::ptr(new location(74, "loc80", system_dynamics, invariant73, true, Out_Going_Trans_fromloc80));
Hybrid_Automata.addLocation(l74);


// The mode name is  loc79

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -0.2;
C[3] = -1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -6.0;
invariantBoundValue[3] = 7.0;
invariant74 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc79;

// The transition label ist273

// Original guard: x1 = 8 & 6 <= x2 & x2 <= 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope260 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t261 = transition::ptr(new transition(261,"t273",75,66,guard_polytope260,assignment));

Out_Going_Trans_fromloc79.push_back(t261);
// The transition label ist275

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 7 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -7.0;
guardBoundValue[3] = 7.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope261 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t262 = transition::ptr(new transition(262,"t275",75,74,guard_polytope261,assignment));

Out_Going_Trans_fromloc79.push_back(t262);
// The transition label ist274

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope262 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t263 = transition::ptr(new transition(263,"t274",75,76,guard_polytope262,assignment));

Out_Going_Trans_fromloc79.push_back(t263);
location::ptr l75 = location::ptr(new location(75, "loc79", system_dynamics, invariant74, true, Out_Going_Trans_fromloc79));
Hybrid_Automata.addLocation(l75);


// The mode name is  loc78

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -1.202;
C[3] = -1.202;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -5.0;
invariantBoundValue[3] = 6.0;
invariant75 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc78;

// The transition label ist270

// Original guard: x1 = 8 & 5 <= x2 & x2 <= 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope263 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t264 = transition::ptr(new transition(264,"t270",76,67,guard_polytope263,assignment));

Out_Going_Trans_fromloc78.push_back(t264);
// The transition label ist272

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 6 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -6.0;
guardBoundValue[3] = 6.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope264 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t265 = transition::ptr(new transition(265,"t272",76,75,guard_polytope264,assignment));

Out_Going_Trans_fromloc78.push_back(t265);
// The transition label ist271

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope265 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t266 = transition::ptr(new transition(266,"t271",76,77,guard_polytope265,assignment));

Out_Going_Trans_fromloc78.push_back(t266);
location::ptr l76 = location::ptr(new location(76, "loc78", system_dynamics, invariant75, true, Out_Going_Trans_fromloc78));
Hybrid_Automata.addLocation(l76);


// The mode name is  loc77

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -1.202;
C[3] = -1.202;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -4.0;
invariantBoundValue[3] = 5.0;
invariant76 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc77;

// The transition label ist267

// Original guard: x1 = 8 & 4 <= x2 & x2 <= 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope266 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t267 = transition::ptr(new transition(267,"t267",77,68,guard_polytope266,assignment));

Out_Going_Trans_fromloc77.push_back(t267);
// The transition label ist269

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 5 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -5.0;
guardBoundValue[3] = 5.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope267 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t268 = transition::ptr(new transition(268,"t269",77,76,guard_polytope267,assignment));

Out_Going_Trans_fromloc77.push_back(t268);
// The transition label ist268

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope268 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t269 = transition::ptr(new transition(269,"t268",77,78,guard_polytope268,assignment));

Out_Going_Trans_fromloc77.push_back(t269);
location::ptr l77 = location::ptr(new location(77, "loc77", system_dynamics, invariant76, true, Out_Going_Trans_fromloc77));
Hybrid_Automata.addLocation(l77);


// The mode name is  loc76

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -1.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -3.0;
invariantBoundValue[3] = 4.0;
invariant77 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc76;

// The transition label ist264

// Original guard: x1 = 8 & 3 <= x2 & x2 <= 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope269 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t270 = transition::ptr(new transition(270,"t264",78,69,guard_polytope269,assignment));

Out_Going_Trans_fromloc76.push_back(t270);
// The transition label ist266

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 4 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -4.0;
guardBoundValue[3] = 4.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope270 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t271 = transition::ptr(new transition(271,"t266",78,77,guard_polytope270,assignment));

Out_Going_Trans_fromloc76.push_back(t271);
// The transition label ist265

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope271 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t272 = transition::ptr(new transition(272,"t265",78,79,guard_polytope271,assignment));

Out_Going_Trans_fromloc76.push_back(t272);
location::ptr l78 = location::ptr(new location(78, "loc76", system_dynamics, invariant77, true, Out_Going_Trans_fromloc76));
Hybrid_Automata.addLocation(l78);


// The mode name is  loc75

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = -1.5;
C[3] = -0.5;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -2.0;
invariantBoundValue[3] = 3.0;
invariant78 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc75;

// The transition label ist261

// Original guard: x1 = 8 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope272 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t273 = transition::ptr(new transition(273,"t261",79,70,guard_polytope272,assignment));

Out_Going_Trans_fromloc75.push_back(t273);
// The transition label ist263

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -3.0;
guardBoundValue[3] = 3.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope273 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t274 = transition::ptr(new transition(274,"t263",79,78,guard_polytope273,assignment));

Out_Going_Trans_fromloc75.push_back(t274);
// The transition label ist262

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope274 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t275 = transition::ptr(new transition(275,"t262",79,80,guard_polytope274,assignment));

Out_Going_Trans_fromloc75.push_back(t275);
location::ptr l79 = location::ptr(new location(79, "loc75", system_dynamics, invariant78, true, Out_Going_Trans_fromloc75));
Hybrid_Automata.addLocation(l79);


// The mode name is  loc74

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[2] = -1.0;
invariantBoundValue[3] = 2.0;
invariant79 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc74;

// The transition label ist258

// Original guard: x1 = 8 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope275 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t276 = transition::ptr(new transition(276,"t258",80,71,guard_polytope275,assignment));

Out_Going_Trans_fromloc74.push_back(t276);
// The transition label ist260

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -2.0;
guardBoundValue[3] = 2.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope276 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t277 = transition::ptr(new transition(277,"t260",80,79,guard_polytope276,assignment));

Out_Going_Trans_fromloc74.push_back(t277);
// The transition label ist259

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope277 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t278 = transition::ptr(new transition(278,"t259",80,81,guard_polytope277,assignment));

Out_Going_Trans_fromloc74.push_back(t278);
location::ptr l80 = location::ptr(new location(80, "loc74", system_dynamics, invariant79, true, Out_Going_Trans_fromloc74));
Hybrid_Automata.addLocation(l80);


// The mode name is  loc73

row = 5;
col = 5;
Amatrix.resize(row, col);
Amatrix.clear();
Amatrix(0 , 2) = 1.0;
Amatrix(1 , 3) = 1.0;
Amatrix(2 , 2) = -1.5;
Amatrix(2 , 3) = -0.2;
Amatrix(3 , 2) = -0.5;
Amatrix(3 , 3) = -1.2;
system_dynamics.isEmptyMatrixA = false;
system_dynamics.MatrixA = Amatrix;

system_dynamics.isEmptyMatrixB = true;

C.resize(row );
C.assign(row,0);
C[2] = 0.2;
C[3] = 1.2;
C[4] = 1.0;
system_dynamics.isEmptyC = false;
system_dynamics.C = C;


row = 5;
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
invariantBoundValue[3] = 1.0;
invariant80 = polytope::ptr(new polytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign));

system_dynamics.U = polytope::ptr(new polytope(true));


std::list<transition::ptr> Out_Going_Trans_fromloc73;

// The transition label ist256

// Original guard: x1 = 8 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 8.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope278 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t279 = transition::ptr(new transition(279,"t256",81,72,guard_polytope278,assignment));

Out_Going_Trans_fromloc73.push_back(t279);
// The transition label ist257

// Original guard: 8 <= x1 & x1 <= 9 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

row = 8;
col = 5;

guardConstraintsMatrix.resize(row, col);
guardConstraintsMatrix.clear();
guardConstraintsMatrix(0,0) = -1.0;
guardConstraintsMatrix(1,0) = 1.0;
guardConstraintsMatrix(2,1) = -1.0;
guardConstraintsMatrix(3,1) = 1.0;
guardConstraintsMatrix(4,2) = -1.0;
guardConstraintsMatrix(5,2) = 1.0;
guardConstraintsMatrix(6,3) = -1.0;
guardConstraintsMatrix(7,3) = 1.0;

guardBoundValue.resize(row);
guardBoundValue.assign(row,0);
guardBoundValue[0] = -8.0;
guardBoundValue[1] = 9.0;
guardBoundValue[2] = -1.0;
guardBoundValue[3] = 1.0;
guardBoundValue[4] = 1000.0;
guardBoundValue[5] = 1000.0;
guardBoundValue[6] = 1000.0;
guardBoundValue[7] = 1000.0;
guard_polytope279 = polytope::ptr(new polytope(guardConstraintsMatrix, guardBoundValue, guardBoundSign));


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

transition::ptr t280 = transition::ptr(new transition(280,"t257",81,80,guard_polytope279,assignment));

Out_Going_Trans_fromloc73.push_back(t280);
location::ptr l81 = location::ptr(new location(81, "loc73", system_dynamics, invariant80, true, Out_Going_Trans_fromloc73));
Hybrid_Automata.addLocation(l81);


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
boundValueI[0]=0.8;
boundValueI[1]=-0.4;
boundValueI[2]=0.8;
boundValueI[3]=-0.2;
boundValueI[4]=0.5;
boundValueI[5]=-0.5;
boundValueI[6]=0.5;
boundValueI[7]=-0.5;
boundValueI[8]=0.5;
boundValueI[9]=-0.5;


initial_polytope_I0 = polytope::ptr(new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

dim = initial_polytope_I0->getSystemDimension();
int transition_id = 0;
unsigned int initial_location_id =9;

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
