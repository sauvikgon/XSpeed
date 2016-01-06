// Created by Hyst v1.2
// Hybrid Automaton in Xspeed
// Converted from file: /home/amit/MyData/Flora/FromArup/arup/nav04/Nav04.xml
// Command Line arguments: -xspeed -o /home/amit/cuda-workspace/XSpeed/src/Hybrid_Model_Parameters_Design/user_model/user_model.cpp /home/amit/MyData/Flora/FromArup/arup/nav04/Nav04.xml /home/amit/MyData/Flora/FromArup/arup/nav04/Nav04.cfg

#include "user_model.h"
void user_model(hybrid_automata& Hybrid_Automata,
		initial_state::ptr& init_state,
		ReachabilityParameters& reach_parameters, int& transition_iterations) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	unsigned int Directions_Type = 1;
	unsigned int iter_max = 2;
	double time_horizon = 10.0;
	double sampling_time = 0.1;
	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I;

	polytope::ptr invariant0, invariant1, invariant2, invariant3, invariant4,
			invariant5, invariant6, invariant7, invariant8;

	polytope::ptr gaurd_polytope0, gaurd_polytope1, gaurd_polytope2,
			gaurd_polytope3, gaurd_polytope4, gaurd_polytope5, gaurd_polytope6,
			gaurd_polytope7, gaurd_polytope8, gaurd_polytope9, gaurd_polytope10,
			gaurd_polytope11, gaurd_polytope12, gaurd_polytope13,
			gaurd_polytope14, gaurd_polytope15, gaurd_polytope16,
			gaurd_polytope17, gaurd_polytope18, gaurd_polytope19;

	Dynamics system_dynamics0, system_dynamics1, system_dynamics2,
			system_dynamics3, system_dynamics4, system_dynamics5,
			system_dynamics6, system_dynamics7, system_dynamics8;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV0,
			ConstraintsMatrixV1, ConstraintsMatrixV2, ConstraintsMatrixV3,
			ConstraintsMatrixV4, ConstraintsMatrixV5, ConstraintsMatrixV6,
			ConstraintsMatrixV7, ConstraintsMatrixV8,
			invariantConstraintsMatrix0, invariantConstraintsMatrix1,
			invariantConstraintsMatrix2, invariantConstraintsMatrix3,
			invariantConstraintsMatrix4, invariantConstraintsMatrix5,
			invariantConstraintsMatrix6, invariantConstraintsMatrix7,
			invariantConstraintsMatrix8, gaurdConstraintsMatrix0,
			gaurdConstraintsMatrix1, gaurdConstraintsMatrix2,
			gaurdConstraintsMatrix3, gaurdConstraintsMatrix4,
			gaurdConstraintsMatrix5, gaurdConstraintsMatrix6,
			gaurdConstraintsMatrix7, gaurdConstraintsMatrix8,
			gaurdConstraintsMatrix9, gaurdConstraintsMatrix10,
			gaurdConstraintsMatrix11, gaurdConstraintsMatrix12,
			gaurdConstraintsMatrix13, gaurdConstraintsMatrix14,
			gaurdConstraintsMatrix15, gaurdConstraintsMatrix16,
			gaurdConstraintsMatrix17, gaurdConstraintsMatrix18,
			gaurdConstraintsMatrix19, A0matrix, A1matrix, A2matrix, A3matrix,
			A4matrix, A5matrix, A6matrix, A7matrix, A8matrix, B0matrix,
			B1matrix, B2matrix, B3matrix, B4matrix, B5matrix, B6matrix,
			B7matrix, B8matrix;

	std::vector<double> boundValueI, boundValueV0, boundValueV1, boundValueV2,
			boundValueV3, boundValueV4, boundValueV5, boundValueV6,
			boundValueV7, boundValueV8, C0, C1, C2, C3, C4, C5, C6, C7, C8,
			invariantBoundValue0, invariantBoundValue1, invariantBoundValue2,
			invariantBoundValue3, invariantBoundValue4, invariantBoundValue5,
			invariantBoundValue6, invariantBoundValue7, invariantBoundValue8,
			gaurdBoundValue0, gaurdBoundValue1, gaurdBoundValue2,
			gaurdBoundValue3, gaurdBoundValue4, gaurdBoundValue5,
			gaurdBoundValue6, gaurdBoundValue7, gaurdBoundValue8,
			gaurdBoundValue9, gaurdBoundValue10, gaurdBoundValue11,
			gaurdBoundValue12, gaurdBoundValue13, gaurdBoundValue14,
			gaurdBoundValue15, gaurdBoundValue16, gaurdBoundValue17,
			gaurdBoundValue18, gaurdBoundValue19;

	int boundSignI, invariantBoundSign, gaurdBoundSign, boundSignV;

// The mode name is  loc9

	system_dynamics0.isEmptyMatrixA = true;

	system_dynamics0.isEmptyMatrixB = true;

	system_dynamics0.isEmptyC = true;

	invariant0 = polytope::ptr(new polytope());
	invariant0->setIsUniverse(true);

	row = 4;
	col = 4;
	ConstraintsMatrixV0.resize(row, col);
	ConstraintsMatrixV0(0, 0) = -1.0;
	ConstraintsMatrixV0(0, 1) = 0.0;
	ConstraintsMatrixV0(0, 2) = 0.0;
	ConstraintsMatrixV0(0, 3) = 0.0;
	ConstraintsMatrixV0(1, 0) = 1.0;
	ConstraintsMatrixV0(1, 1) = 0.0;
	ConstraintsMatrixV0(1, 2) = 0.0;
	ConstraintsMatrixV0(1, 3) = 0.0;
	ConstraintsMatrixV0(2, 0) = 0.0;
	ConstraintsMatrixV0(2, 1) = -1.0;
	ConstraintsMatrixV0(2, 2) = 0.0;
	ConstraintsMatrixV0(2, 3) = 0.0;
	ConstraintsMatrixV0(3, 0) = 0.0;
	ConstraintsMatrixV0(3, 1) = 1.0;
	ConstraintsMatrixV0(3, 2) = 0.0;
	ConstraintsMatrixV0(3, 3) = 0.0;

	boundValueV0.resize(row);
	boundValueV0[0] = -0.0;
	boundValueV0[1] = 1.0;
	boundValueV0[2] = -2.0;
	boundValueV0[3] = 3.0;
	boundSignV = 1;
	system_dynamics0.U = polytope::ptr(
			new polytope(ConstraintsMatrixV0, boundValueV0, boundSignV));

// The mode name is  loc5

	row = 4;
	col = 4;
	A1matrix.resize(row, col);
	A1matrix(0, 0) = 0.0;
	A1matrix(0, 1) = 0.0;
	A1matrix(0, 2) = 1.0;
	A1matrix(0, 3) = 0.0;
	A1matrix(1, 0) = 0.0;
	A1matrix(1, 1) = 0.0;
	A1matrix(1, 2) = 0.0;
	A1matrix(1, 3) = 1.0;
	A1matrix(2, 0) = 0.0;
	A1matrix(2, 1) = 0.0;
	A1matrix(2, 2) = -1.2;
	A1matrix(2, 3) = 0.1;
	A1matrix(3, 0) = 0.0;
	A1matrix(3, 1) = 0.0;
	A1matrix(3, 2) = 0.1;
	A1matrix(3, 3) = -1.2;
	system_dynamics1.isEmptyMatrixA = false;
	system_dynamics1.MatrixA = A1matrix;

	system_dynamics1.isEmptyMatrixB = true;

	C1.resize(row);
	C1[0] = 0.0;
	C1[1] = 0.0;
	C1[2] = 1.2;
	C1[3] = -0.1;
	system_dynamics1.isEmptyC = false;
	system_dynamics1.C = C1;

	row = 4;
	col = 4;
	invariantConstraintsMatrix1.resize(row, col);
	invariantConstraintsMatrix1(0, 0) = -1.0;
	invariantConstraintsMatrix1(0, 1) = 0.0;
	invariantConstraintsMatrix1(0, 2) = 0.0;
	invariantConstraintsMatrix1(0, 3) = 0.0;
	invariantConstraintsMatrix1(1, 0) = 1.0;
	invariantConstraintsMatrix1(1, 1) = 0.0;
	invariantConstraintsMatrix1(1, 2) = 0.0;
	invariantConstraintsMatrix1(1, 3) = 0.0;
	invariantConstraintsMatrix1(2, 0) = 0.0;
	invariantConstraintsMatrix1(2, 1) = -1.0;
	invariantConstraintsMatrix1(2, 2) = 0.0;
	invariantConstraintsMatrix1(2, 3) = 0.0;
	invariantConstraintsMatrix1(3, 0) = 0.0;
	invariantConstraintsMatrix1(3, 1) = 1.0;
	invariantConstraintsMatrix1(3, 2) = 0.0;
	invariantConstraintsMatrix1(3, 3) = 0.0;

	invariantBoundValue1.resize(row);
	invariantBoundValue1[0] = -1.0;
	invariantBoundValue1[1] = 2.0;
	invariantBoundValue1[2] = -2.0;
	invariantBoundValue1[3] = 3.0;
	invariantBoundSign = 1;
	invariant1 = polytope::ptr(
			new polytope(invariantConstraintsMatrix1, invariantBoundValue1,
					invariantBoundSign));

	system_dynamics1.U = polytope::ptr(new polytope(true));

// The mode name is  loc7

	row = 4;
	col = 4;
	A2matrix.resize(row, col);
	A2matrix(0, 0) = 0.0;
	A2matrix(0, 1) = 0.0;
	A2matrix(0, 2) = 1.0;
	A2matrix(0, 3) = 0.0;
	A2matrix(1, 0) = 0.0;
	A2matrix(1, 1) = 0.0;
	A2matrix(1, 2) = 0.0;
	A2matrix(1, 3) = 1.0;
	A2matrix(2, 0) = 0.0;
	A2matrix(2, 1) = 0.0;
	A2matrix(2, 2) = -1.2;
	A2matrix(2, 3) = 0.1;
	A2matrix(3, 0) = 0.0;
	A2matrix(3, 1) = 0.0;
	A2matrix(3, 2) = 0.1;
	A2matrix(3, 3) = -1.2;
	system_dynamics2.isEmptyMatrixA = false;
	system_dynamics2.MatrixA = A2matrix;

	system_dynamics2.isEmptyMatrixB = true;

	C2.resize(row);
	C2[0] = 0.0;
	C2[1] = 0.0;
	C2[2] = 0.1;
	C2[3] = -1.2;
	system_dynamics2.isEmptyC = false;
	system_dynamics2.C = C2;

	row = 4;
	col = 4;
	invariantConstraintsMatrix2.resize(row, col);
	invariantConstraintsMatrix2(0, 0) = -1.0;
	invariantConstraintsMatrix2(0, 1) = 0.0;
	invariantConstraintsMatrix2(0, 2) = 0.0;
	invariantConstraintsMatrix2(0, 3) = 0.0;
	invariantConstraintsMatrix2(1, 0) = 1.0;
	invariantConstraintsMatrix2(1, 1) = 0.0;
	invariantConstraintsMatrix2(1, 2) = 0.0;
	invariantConstraintsMatrix2(1, 3) = 0.0;
	invariantConstraintsMatrix2(2, 0) = 0.0;
	invariantConstraintsMatrix2(2, 1) = -1.0;
	invariantConstraintsMatrix2(2, 2) = 0.0;
	invariantConstraintsMatrix2(2, 3) = 0.0;
	invariantConstraintsMatrix2(3, 0) = 0.0;
	invariantConstraintsMatrix2(3, 1) = 1.0;
	invariantConstraintsMatrix2(3, 2) = 0.0;
	invariantConstraintsMatrix2(3, 3) = 0.0;

	invariantBoundValue2.resize(row);
	invariantBoundValue2[0] = -2.0;
	invariantBoundValue2[1] = 3.0;
	invariantBoundValue2[2] = -2.0;
	invariantBoundValue2[3] = 3.0;
	invariantBoundSign = 1;
	invariant2 = polytope::ptr(
			new polytope(invariantConstraintsMatrix2, invariantBoundValue2,
					invariantBoundSign));

	system_dynamics2.U = polytope::ptr(new polytope(true));

// The mode name is  loc1

	row = 4;
	col = 4;
	A3matrix.resize(row, col);
	A3matrix(0, 0) = 0.0;
	A3matrix(0, 1) = 0.0;
	A3matrix(0, 2) = 1.0;
	A3matrix(0, 3) = 0.0;
	A3matrix(1, 0) = 0.0;
	A3matrix(1, 1) = 0.0;
	A3matrix(1, 2) = 0.0;
	A3matrix(1, 3) = 1.0;
	A3matrix(2, 0) = 0.0;
	A3matrix(2, 1) = 0.0;
	A3matrix(2, 2) = -1.2;
	A3matrix(2, 3) = 0.1;
	A3matrix(3, 0) = 0.0;
	A3matrix(3, 1) = 0.0;
	A3matrix(3, 2) = 0.1;
	A3matrix(3, 3) = -1.2;
	system_dynamics3.isEmptyMatrixA = false;
	system_dynamics3.MatrixA = A3matrix;

	system_dynamics3.isEmptyMatrixB = true;

	C3.resize(row);
	C3[0] = 0.0;
	C3[1] = 0.0;
	C3[2] = 1.2;
	C3[3] = -0.1;
	system_dynamics3.isEmptyC = false;
	system_dynamics3.C = C3;

	row = 4;
	col = 4;
	invariantConstraintsMatrix3.resize(row, col);
	invariantConstraintsMatrix3(0, 0) = -1.0;
	invariantConstraintsMatrix3(0, 1) = 0.0;
	invariantConstraintsMatrix3(0, 2) = 0.0;
	invariantConstraintsMatrix3(0, 3) = 0.0;
	invariantConstraintsMatrix3(1, 0) = 1.0;
	invariantConstraintsMatrix3(1, 1) = 0.0;
	invariantConstraintsMatrix3(1, 2) = 0.0;
	invariantConstraintsMatrix3(1, 3) = 0.0;
	invariantConstraintsMatrix3(2, 0) = 0.0;
	invariantConstraintsMatrix3(2, 1) = -1.0;
	invariantConstraintsMatrix3(2, 2) = 0.0;
	invariantConstraintsMatrix3(2, 3) = 0.0;
	invariantConstraintsMatrix3(3, 0) = 0.0;
	invariantConstraintsMatrix3(3, 1) = 1.0;
	invariantConstraintsMatrix3(3, 2) = 0.0;
	invariantConstraintsMatrix3(3, 3) = 0.0;

	invariantBoundValue3.resize(row);
	invariantBoundValue3[0] = -0.0;
	invariantBoundValue3[1] = 1.0;
	invariantBoundValue3[2] = -1.0;
	invariantBoundValue3[3] = 2.0;
	invariantBoundSign = 1;
	invariant3 = polytope::ptr(
			new polytope(invariantConstraintsMatrix3, invariantBoundValue3,
					invariantBoundSign));

	system_dynamics3.U = polytope::ptr(new polytope(true));

// The mode name is  loc4

	row = 4;
	col = 4;
	A4matrix.resize(row, col);
	A4matrix(0, 0) = 0.0;
	A4matrix(0, 1) = 0.0;
	A4matrix(0, 2) = 1.0;
	A4matrix(0, 3) = 0.0;
	A4matrix(1, 0) = 0.0;
	A4matrix(1, 1) = 0.0;
	A4matrix(1, 2) = 0.0;
	A4matrix(1, 3) = 1.0;
	A4matrix(2, 0) = 0.0;
	A4matrix(2, 1) = 0.0;
	A4matrix(2, 2) = -1.2;
	A4matrix(2, 3) = 0.1;
	A4matrix(3, 0) = 0.0;
	A4matrix(3, 1) = 0.0;
	A4matrix(3, 2) = 0.1;
	A4matrix(3, 3) = -1.2;
	system_dynamics4.isEmptyMatrixA = false;
	system_dynamics4.MatrixA = A4matrix;

	system_dynamics4.isEmptyMatrixB = true;

	C4.resize(row);
	C4[0] = 0.0;
	C4[1] = 0.0;
	C4[2] = 1.2;
	C4[3] = -0.1;
	system_dynamics4.isEmptyC = false;
	system_dynamics4.C = C4;

	row = 4;
	col = 4;
	invariantConstraintsMatrix4.resize(row, col);
	invariantConstraintsMatrix4(0, 0) = -1.0;
	invariantConstraintsMatrix4(0, 1) = 0.0;
	invariantConstraintsMatrix4(0, 2) = 0.0;
	invariantConstraintsMatrix4(0, 3) = 0.0;
	invariantConstraintsMatrix4(1, 0) = 1.0;
	invariantConstraintsMatrix4(1, 1) = 0.0;
	invariantConstraintsMatrix4(1, 2) = 0.0;
	invariantConstraintsMatrix4(1, 3) = 0.0;
	invariantConstraintsMatrix4(2, 0) = 0.0;
	invariantConstraintsMatrix4(2, 1) = -1.0;
	invariantConstraintsMatrix4(2, 2) = 0.0;
	invariantConstraintsMatrix4(2, 3) = 0.0;
	invariantConstraintsMatrix4(3, 0) = 0.0;
	invariantConstraintsMatrix4(3, 1) = 1.0;
	invariantConstraintsMatrix4(3, 2) = 0.0;
	invariantConstraintsMatrix4(3, 3) = 0.0;

	invariantBoundValue4.resize(row);
	invariantBoundValue4[0] = -1.0;
	invariantBoundValue4[1] = 2.0;
	invariantBoundValue4[2] = -1.0;
	invariantBoundValue4[3] = 2.0;
	invariantBoundSign = 1;
	invariant4 = polytope::ptr(
			new polytope(invariantConstraintsMatrix4, invariantBoundValue4,
					invariantBoundSign));

	system_dynamics4.U = polytope::ptr(new polytope(true));

// The mode name is  loc6

	row = 4;
	col = 4;
	A5matrix.resize(row, col);
	A5matrix(0, 0) = 0.0;
	A5matrix(0, 1) = 0.0;
	A5matrix(0, 2) = 1.0;
	A5matrix(0, 3) = 0.0;
	A5matrix(1, 0) = 0.0;
	A5matrix(1, 1) = 0.0;
	A5matrix(1, 2) = 0.0;
	A5matrix(1, 3) = 1.0;
	A5matrix(2, 0) = 0.0;
	A5matrix(2, 1) = 0.0;
	A5matrix(2, 2) = -1.2;
	A5matrix(2, 3) = 0.1;
	A5matrix(3, 0) = 0.0;
	A5matrix(3, 1) = 0.0;
	A5matrix(3, 2) = 0.1;
	A5matrix(3, 3) = -1.2;
	system_dynamics5.isEmptyMatrixA = false;
	system_dynamics5.MatrixA = A5matrix;

	system_dynamics5.isEmptyMatrixB = true;

	C5.resize(row);
	C5[0] = 0.0;
	C5[1] = 0.0;
	C5[2] = 0.1;
	C5[3] = -1.2;
	system_dynamics5.isEmptyC = false;
	system_dynamics5.C = C5;

	row = 4;
	col = 4;
	invariantConstraintsMatrix5.resize(row, col);
	invariantConstraintsMatrix5(0, 0) = -1.0;
	invariantConstraintsMatrix5(0, 1) = 0.0;
	invariantConstraintsMatrix5(0, 2) = 0.0;
	invariantConstraintsMatrix5(0, 3) = 0.0;
	invariantConstraintsMatrix5(1, 0) = 1.0;
	invariantConstraintsMatrix5(1, 1) = 0.0;
	invariantConstraintsMatrix5(1, 2) = 0.0;
	invariantConstraintsMatrix5(1, 3) = 0.0;
	invariantConstraintsMatrix5(2, 0) = 0.0;
	invariantConstraintsMatrix5(2, 1) = -1.0;
	invariantConstraintsMatrix5(2, 2) = 0.0;
	invariantConstraintsMatrix5(2, 3) = 0.0;
	invariantConstraintsMatrix5(3, 0) = 0.0;
	invariantConstraintsMatrix5(3, 1) = 1.0;
	invariantConstraintsMatrix5(3, 2) = 0.0;
	invariantConstraintsMatrix5(3, 3) = 0.0;

	invariantBoundValue5.resize(row);
	invariantBoundValue5[0] = -2.0;
	invariantBoundValue5[1] = 3.0;
	invariantBoundValue5[2] = -1.0;
	invariantBoundValue5[3] = 2.0;
	invariantBoundSign = 1;
	invariant5 = polytope::ptr(
			new polytope(invariantConstraintsMatrix5, invariantBoundValue5,
					invariantBoundSign));

	system_dynamics5.U = polytope::ptr(new polytope(true));

// The mode name is  loc3

	row = 4;
	col = 4;
	A6matrix.resize(row, col);
	A6matrix(0, 0) = 0.0;
	A6matrix(0, 1) = 0.0;
	A6matrix(0, 2) = 1.0;
	A6matrix(0, 3) = 0.0;
	A6matrix(1, 0) = 0.0;
	A6matrix(1, 1) = 0.0;
	A6matrix(1, 2) = 0.0;
	A6matrix(1, 3) = 1.0;
	A6matrix(2, 0) = 0.0;
	A6matrix(2, 1) = 0.0;
	A6matrix(2, 2) = -1.2;
	A6matrix(2, 3) = 0.1;
	A6matrix(3, 0) = 0.0;
	A6matrix(3, 1) = 0.0;
	A6matrix(3, 2) = 0.1;
	A6matrix(3, 3) = -1.2;
	system_dynamics6.isEmptyMatrixA = false;
	system_dynamics6.MatrixA = A6matrix;

	system_dynamics6.isEmptyMatrixB = true;

	C6.resize(row);
	C6[0] = 0.0;
	C6[1] = 0.0;
	C6[2] = 0.777821;
	C6[3] = 0.777821;
	system_dynamics6.isEmptyC = false;
	system_dynamics6.C = C6;

	row = 4;
	col = 4;
	invariantConstraintsMatrix6.resize(row, col);
	invariantConstraintsMatrix6(0, 0) = -1.0;
	invariantConstraintsMatrix6(0, 1) = 0.0;
	invariantConstraintsMatrix6(0, 2) = 0.0;
	invariantConstraintsMatrix6(0, 3) = 0.0;
	invariantConstraintsMatrix6(1, 0) = 1.0;
	invariantConstraintsMatrix6(1, 1) = 0.0;
	invariantConstraintsMatrix6(1, 2) = 0.0;
	invariantConstraintsMatrix6(1, 3) = 0.0;
	invariantConstraintsMatrix6(2, 0) = 0.0;
	invariantConstraintsMatrix6(2, 1) = -1.0;
	invariantConstraintsMatrix6(2, 2) = 0.0;
	invariantConstraintsMatrix6(2, 3) = 0.0;
	invariantConstraintsMatrix6(3, 0) = 0.0;
	invariantConstraintsMatrix6(3, 1) = 1.0;
	invariantConstraintsMatrix6(3, 2) = 0.0;
	invariantConstraintsMatrix6(3, 3) = 0.0;

	invariantBoundValue6.resize(row);
	invariantBoundValue6[0] = -1.0;
	invariantBoundValue6[1] = 2.0;
	invariantBoundValue6[2] = -0.0;
	invariantBoundValue6[3] = 1.0;
	invariantBoundSign = 1;
	invariant6 = polytope::ptr(
			new polytope(invariantConstraintsMatrix6, invariantBoundValue6,
					invariantBoundSign));

	system_dynamics6.U = polytope::ptr(new polytope(true));

// The mode name is  loc8

	system_dynamics7.isEmptyMatrixA = true;

	system_dynamics7.isEmptyMatrixB = true;

	system_dynamics7.isEmptyC = true;

	invariant7 = polytope::ptr(new polytope());
	invariant7->setIsUniverse(true);

	row = 4;
	col = 4;
	ConstraintsMatrixV7.resize(row, col);
	ConstraintsMatrixV7(0, 0) = -1.0;
	ConstraintsMatrixV7(0, 1) = 0.0;
	ConstraintsMatrixV7(0, 2) = 0.0;
	ConstraintsMatrixV7(0, 3) = 0.0;
	ConstraintsMatrixV7(1, 0) = 1.0;
	ConstraintsMatrixV7(1, 1) = 0.0;
	ConstraintsMatrixV7(1, 2) = 0.0;
	ConstraintsMatrixV7(1, 3) = 0.0;
	ConstraintsMatrixV7(2, 0) = 0.0;
	ConstraintsMatrixV7(2, 1) = -1.0;
	ConstraintsMatrixV7(2, 2) = 0.0;
	ConstraintsMatrixV7(2, 3) = 0.0;
	ConstraintsMatrixV7(3, 0) = 0.0;
	ConstraintsMatrixV7(3, 1) = 1.0;
	ConstraintsMatrixV7(3, 2) = 0.0;
	ConstraintsMatrixV7(3, 3) = 0.0;

	boundValueV7.resize(row);
	boundValueV7[0] = -2.0;
	boundValueV7[1] = 3.0;
	boundValueV7[2] = -0.0;
	boundValueV7[3] = 1.0;
	boundSignV = 1;
	system_dynamics7.U = polytope::ptr(
			new polytope(ConstraintsMatrixV7, boundValueV7, boundSignV));

// The mode name is  loc2

	row = 4;
	col = 4;
	A8matrix.resize(row, col);
	A8matrix(0, 0) = 0.0;
	A8matrix(0, 1) = 0.0;
	A8matrix(0, 2) = 1.0;
	A8matrix(0, 3) = 0.0;
	A8matrix(1, 0) = 0.0;
	A8matrix(1, 1) = 0.0;
	A8matrix(1, 2) = 0.0;
	A8matrix(1, 3) = 1.0;
	A8matrix(2, 0) = 0.0;
	A8matrix(2, 1) = 0.0;
	A8matrix(2, 2) = -1.2;
	A8matrix(2, 3) = 0.1;
	A8matrix(3, 0) = 0.0;
	A8matrix(3, 1) = 0.0;
	A8matrix(3, 2) = 0.1;
	A8matrix(3, 3) = -1.2;
	system_dynamics8.isEmptyMatrixA = false;
	system_dynamics8.MatrixA = A8matrix;

	system_dynamics8.isEmptyMatrixB = true;

	C8.resize(row);
	C8[0] = 0.0;
	C8[1] = 0.0;
	C8[2] = 0.777821;
	C8[3] = 0.777821;
	system_dynamics8.isEmptyC = false;
	system_dynamics8.C = C8;

	row = 4;
	col = 4;
	invariantConstraintsMatrix8.resize(row, col);
	invariantConstraintsMatrix8(0, 0) = -1.0;
	invariantConstraintsMatrix8(0, 1) = 0.0;
	invariantConstraintsMatrix8(0, 2) = 0.0;
	invariantConstraintsMatrix8(0, 3) = 0.0;
	invariantConstraintsMatrix8(1, 0) = 1.0;
	invariantConstraintsMatrix8(1, 1) = 0.0;
	invariantConstraintsMatrix8(1, 2) = 0.0;
	invariantConstraintsMatrix8(1, 3) = 0.0;
	invariantConstraintsMatrix8(2, 0) = 0.0;
	invariantConstraintsMatrix8(2, 1) = -1.0;
	invariantConstraintsMatrix8(2, 2) = 0.0;
	invariantConstraintsMatrix8(2, 3) = 0.0;
	invariantConstraintsMatrix8(3, 0) = 0.0;
	invariantConstraintsMatrix8(3, 1) = 1.0;
	invariantConstraintsMatrix8(3, 2) = 0.0;
	invariantConstraintsMatrix8(3, 3) = 0.0;

	invariantBoundValue8.resize(row);
	invariantBoundValue8[0] = -0.0;
	invariantBoundValue8[1] = 1.0;
	invariantBoundValue8[2] = -0.0;
	invariantBoundValue8[3] = 1.0;
	invariantBoundSign = 1;
	invariant8 = polytope::ptr(
			new polytope(invariantConstraintsMatrix8, invariantBoundValue8,
					invariantBoundSign));

	system_dynamics8.U = polytope::ptr(new polytope(true));

	row = 8;
	col = 4;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(0, 2) = 0;
	ConstraintsMatrixI(0, 3) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(1, 2) = 0;
	ConstraintsMatrixI(1, 3) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(2, 2) = 0;
	ConstraintsMatrixI(2, 3) = 0;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(3, 2) = 0;
	ConstraintsMatrixI(3, 3) = 0;
	ConstraintsMatrixI(4, 0) = 0;
	ConstraintsMatrixI(4, 1) = 0;
	ConstraintsMatrixI(4, 2) = 1;
	ConstraintsMatrixI(4, 3) = 0;
	ConstraintsMatrixI(5, 0) = 0;
	ConstraintsMatrixI(5, 1) = 0;
	ConstraintsMatrixI(5, 2) = -1;
	ConstraintsMatrixI(5, 3) = 0;
	ConstraintsMatrixI(6, 0) = 0;
	ConstraintsMatrixI(6, 1) = 0;
	ConstraintsMatrixI(6, 2) = 0;
	ConstraintsMatrixI(6, 3) = 1;
	ConstraintsMatrixI(7, 0) = 0;
	ConstraintsMatrixI(7, 1) = 0;
	ConstraintsMatrixI(7, 2) = 0;
	ConstraintsMatrixI(7, 3) = -1;
	boundValueI.resize(row);
	boundValueI[0] = 0.5;
	boundValueI[1] = -0.5;
	boundValueI[2] = 0.5;
	boundValueI[3] = -0.5;
	boundValueI[4] = 0;
	boundValueI[5] = 0;
	boundValueI[6] = 0;
	boundValueI[7] = 0;
	boundSignI = 1;

// The transition label ist13

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix0.resize(row, col);
	gaurdConstraintsMatrix0(0, 0) = -1.0;
	gaurdConstraintsMatrix0(0, 1) = 0.0;
	gaurdConstraintsMatrix0(0, 2) = 0.0;
	gaurdConstraintsMatrix0(0, 3) = 0.0;
	gaurdConstraintsMatrix0(1, 0) = 1.0;
	gaurdConstraintsMatrix0(1, 1) = 0.0;
	gaurdConstraintsMatrix0(1, 2) = 0.0;
	gaurdConstraintsMatrix0(1, 3) = 0.0;
	gaurdConstraintsMatrix0(2, 0) = 0.0;
	gaurdConstraintsMatrix0(2, 1) = -1.0;
	gaurdConstraintsMatrix0(2, 2) = 0.0;
	gaurdConstraintsMatrix0(2, 3) = 0.0;
	gaurdConstraintsMatrix0(3, 0) = 0.0;
	gaurdConstraintsMatrix0(3, 1) = 1.0;
	gaurdConstraintsMatrix0(3, 2) = 0.0;
	gaurdConstraintsMatrix0(3, 3) = 0.0;
	gaurdConstraintsMatrix0(4, 0) = 0.0;
	gaurdConstraintsMatrix0(4, 1) = 0.0;
	gaurdConstraintsMatrix0(4, 2) = -1.0;
	gaurdConstraintsMatrix0(4, 3) = 0.0;
	gaurdConstraintsMatrix0(5, 0) = 0.0;
	gaurdConstraintsMatrix0(5, 1) = 0.0;
	gaurdConstraintsMatrix0(5, 2) = 1.0;
	gaurdConstraintsMatrix0(5, 3) = 0.0;
	gaurdConstraintsMatrix0(6, 0) = 0.0;
	gaurdConstraintsMatrix0(6, 1) = 0.0;
	gaurdConstraintsMatrix0(6, 2) = 0.0;
	gaurdConstraintsMatrix0(6, 3) = -1.0;
	gaurdConstraintsMatrix0(7, 0) = 0.0;
	gaurdConstraintsMatrix0(7, 1) = 0.0;
	gaurdConstraintsMatrix0(7, 2) = 0.0;
	gaurdConstraintsMatrix0(7, 3) = 1.0;

	gaurdBoundValue0.resize(row);
	gaurdBoundValue0[0] = -1.0;
	gaurdBoundValue0[1] = 2.0;
	gaurdBoundValue0[2] = -2.0;
	gaurdBoundValue0[3] = 2.0;
	gaurdBoundValue0[4] = 1000.0;
	gaurdBoundValue0[5] = 1000.0;
	gaurdBoundValue0[6] = 1000.0;
	gaurdBoundValue0[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope0 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix0, gaurdBoundValue0,
					gaurdBoundSign));

// The transition label ist14

// Original guard: x1 = 2 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix1.resize(row, col);
	gaurdConstraintsMatrix1(0, 0) = -1.0;
	gaurdConstraintsMatrix1(0, 1) = 0.0;
	gaurdConstraintsMatrix1(0, 2) = 0.0;
	gaurdConstraintsMatrix1(0, 3) = 0.0;
	gaurdConstraintsMatrix1(1, 0) = 1.0;
	gaurdConstraintsMatrix1(1, 1) = 0.0;
	gaurdConstraintsMatrix1(1, 2) = 0.0;
	gaurdConstraintsMatrix1(1, 3) = 0.0;
	gaurdConstraintsMatrix1(2, 0) = 0.0;
	gaurdConstraintsMatrix1(2, 1) = -1.0;
	gaurdConstraintsMatrix1(2, 2) = 0.0;
	gaurdConstraintsMatrix1(2, 3) = 0.0;
	gaurdConstraintsMatrix1(3, 0) = 0.0;
	gaurdConstraintsMatrix1(3, 1) = 1.0;
	gaurdConstraintsMatrix1(3, 2) = 0.0;
	gaurdConstraintsMatrix1(3, 3) = 0.0;
	gaurdConstraintsMatrix1(4, 0) = 0.0;
	gaurdConstraintsMatrix1(4, 1) = 0.0;
	gaurdConstraintsMatrix1(4, 2) = -1.0;
	gaurdConstraintsMatrix1(4, 3) = 0.0;
	gaurdConstraintsMatrix1(5, 0) = 0.0;
	gaurdConstraintsMatrix1(5, 1) = 0.0;
	gaurdConstraintsMatrix1(5, 2) = 1.0;
	gaurdConstraintsMatrix1(5, 3) = 0.0;
	gaurdConstraintsMatrix1(6, 0) = 0.0;
	gaurdConstraintsMatrix1(6, 1) = 0.0;
	gaurdConstraintsMatrix1(6, 2) = 0.0;
	gaurdConstraintsMatrix1(6, 3) = -1.0;
	gaurdConstraintsMatrix1(7, 0) = 0.0;
	gaurdConstraintsMatrix1(7, 1) = 0.0;
	gaurdConstraintsMatrix1(7, 2) = 0.0;
	gaurdConstraintsMatrix1(7, 3) = 1.0;

	gaurdBoundValue1.resize(row);
	gaurdBoundValue1[0] = -2.0;
	gaurdBoundValue1[1] = 2.0;
	gaurdBoundValue1[2] = -2.0;
	gaurdBoundValue1[3] = 3.0;
	gaurdBoundValue1[4] = 1000.0;
	gaurdBoundValue1[5] = 1000.0;
	gaurdBoundValue1[6] = 1000.0;
	gaurdBoundValue1[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope1 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix1, gaurdBoundValue1,
					gaurdBoundSign));

// The transition label ist15

// Original guard: x1 = 1 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix2.resize(row, col);
	gaurdConstraintsMatrix2(0, 0) = -1.0;
	gaurdConstraintsMatrix2(0, 1) = 0.0;
	gaurdConstraintsMatrix2(0, 2) = 0.0;
	gaurdConstraintsMatrix2(0, 3) = 0.0;
	gaurdConstraintsMatrix2(1, 0) = 1.0;
	gaurdConstraintsMatrix2(1, 1) = 0.0;
	gaurdConstraintsMatrix2(1, 2) = 0.0;
	gaurdConstraintsMatrix2(1, 3) = 0.0;
	gaurdConstraintsMatrix2(2, 0) = 0.0;
	gaurdConstraintsMatrix2(2, 1) = -1.0;
	gaurdConstraintsMatrix2(2, 2) = 0.0;
	gaurdConstraintsMatrix2(2, 3) = 0.0;
	gaurdConstraintsMatrix2(3, 0) = 0.0;
	gaurdConstraintsMatrix2(3, 1) = 1.0;
	gaurdConstraintsMatrix2(3, 2) = 0.0;
	gaurdConstraintsMatrix2(3, 3) = 0.0;
	gaurdConstraintsMatrix2(4, 0) = 0.0;
	gaurdConstraintsMatrix2(4, 1) = 0.0;
	gaurdConstraintsMatrix2(4, 2) = -1.0;
	gaurdConstraintsMatrix2(4, 3) = 0.0;
	gaurdConstraintsMatrix2(5, 0) = 0.0;
	gaurdConstraintsMatrix2(5, 1) = 0.0;
	gaurdConstraintsMatrix2(5, 2) = 1.0;
	gaurdConstraintsMatrix2(5, 3) = 0.0;
	gaurdConstraintsMatrix2(6, 0) = 0.0;
	gaurdConstraintsMatrix2(6, 1) = 0.0;
	gaurdConstraintsMatrix2(6, 2) = 0.0;
	gaurdConstraintsMatrix2(6, 3) = -1.0;
	gaurdConstraintsMatrix2(7, 0) = 0.0;
	gaurdConstraintsMatrix2(7, 1) = 0.0;
	gaurdConstraintsMatrix2(7, 2) = 0.0;
	gaurdConstraintsMatrix2(7, 3) = 1.0;

	gaurdBoundValue2.resize(row);
	gaurdBoundValue2[0] = -1.0;
	gaurdBoundValue2[1] = 1.0;
	gaurdBoundValue2[2] = -2.0;
	gaurdBoundValue2[3] = 3.0;
	gaurdBoundValue2[4] = 1000.0;
	gaurdBoundValue2[5] = 1000.0;
	gaurdBoundValue2[6] = 1000.0;
	gaurdBoundValue2[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope2 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix2, gaurdBoundValue2,
					gaurdBoundSign));

// The transition label ist19

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix3.resize(row, col);
	gaurdConstraintsMatrix3(0, 0) = -1.0;
	gaurdConstraintsMatrix3(0, 1) = 0.0;
	gaurdConstraintsMatrix3(0, 2) = 0.0;
	gaurdConstraintsMatrix3(0, 3) = 0.0;
	gaurdConstraintsMatrix3(1, 0) = 1.0;
	gaurdConstraintsMatrix3(1, 1) = 0.0;
	gaurdConstraintsMatrix3(1, 2) = 0.0;
	gaurdConstraintsMatrix3(1, 3) = 0.0;
	gaurdConstraintsMatrix3(2, 0) = 0.0;
	gaurdConstraintsMatrix3(2, 1) = -1.0;
	gaurdConstraintsMatrix3(2, 2) = 0.0;
	gaurdConstraintsMatrix3(2, 3) = 0.0;
	gaurdConstraintsMatrix3(3, 0) = 0.0;
	gaurdConstraintsMatrix3(3, 1) = 1.0;
	gaurdConstraintsMatrix3(3, 2) = 0.0;
	gaurdConstraintsMatrix3(3, 3) = 0.0;
	gaurdConstraintsMatrix3(4, 0) = 0.0;
	gaurdConstraintsMatrix3(4, 1) = 0.0;
	gaurdConstraintsMatrix3(4, 2) = -1.0;
	gaurdConstraintsMatrix3(4, 3) = 0.0;
	gaurdConstraintsMatrix3(5, 0) = 0.0;
	gaurdConstraintsMatrix3(5, 1) = 0.0;
	gaurdConstraintsMatrix3(5, 2) = 1.0;
	gaurdConstraintsMatrix3(5, 3) = 0.0;
	gaurdConstraintsMatrix3(6, 0) = 0.0;
	gaurdConstraintsMatrix3(6, 1) = 0.0;
	gaurdConstraintsMatrix3(6, 2) = 0.0;
	gaurdConstraintsMatrix3(6, 3) = -1.0;
	gaurdConstraintsMatrix3(7, 0) = 0.0;
	gaurdConstraintsMatrix3(7, 1) = 0.0;
	gaurdConstraintsMatrix3(7, 2) = 0.0;
	gaurdConstraintsMatrix3(7, 3) = 1.0;

	gaurdBoundValue3.resize(row);
	gaurdBoundValue3[0] = -2.0;
	gaurdBoundValue3[1] = 3.0;
	gaurdBoundValue3[2] = -2.0;
	gaurdBoundValue3[3] = 2.0;
	gaurdBoundValue3[4] = 1000.0;
	gaurdBoundValue3[5] = 1000.0;
	gaurdBoundValue3[6] = 1000.0;
	gaurdBoundValue3[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope3 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix3, gaurdBoundValue3,
					gaurdBoundSign));

// The transition label ist20

// Original guard: x1 = 2 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix4.resize(row, col);
	gaurdConstraintsMatrix4(0, 0) = -1.0;
	gaurdConstraintsMatrix4(0, 1) = 0.0;
	gaurdConstraintsMatrix4(0, 2) = 0.0;
	gaurdConstraintsMatrix4(0, 3) = 0.0;
	gaurdConstraintsMatrix4(1, 0) = 1.0;
	gaurdConstraintsMatrix4(1, 1) = 0.0;
	gaurdConstraintsMatrix4(1, 2) = 0.0;
	gaurdConstraintsMatrix4(1, 3) = 0.0;
	gaurdConstraintsMatrix4(2, 0) = 0.0;
	gaurdConstraintsMatrix4(2, 1) = -1.0;
	gaurdConstraintsMatrix4(2, 2) = 0.0;
	gaurdConstraintsMatrix4(2, 3) = 0.0;
	gaurdConstraintsMatrix4(3, 0) = 0.0;
	gaurdConstraintsMatrix4(3, 1) = 1.0;
	gaurdConstraintsMatrix4(3, 2) = 0.0;
	gaurdConstraintsMatrix4(3, 3) = 0.0;
	gaurdConstraintsMatrix4(4, 0) = 0.0;
	gaurdConstraintsMatrix4(4, 1) = 0.0;
	gaurdConstraintsMatrix4(4, 2) = -1.0;
	gaurdConstraintsMatrix4(4, 3) = 0.0;
	gaurdConstraintsMatrix4(5, 0) = 0.0;
	gaurdConstraintsMatrix4(5, 1) = 0.0;
	gaurdConstraintsMatrix4(5, 2) = 1.0;
	gaurdConstraintsMatrix4(5, 3) = 0.0;
	gaurdConstraintsMatrix4(6, 0) = 0.0;
	gaurdConstraintsMatrix4(6, 1) = 0.0;
	gaurdConstraintsMatrix4(6, 2) = 0.0;
	gaurdConstraintsMatrix4(6, 3) = -1.0;
	gaurdConstraintsMatrix4(7, 0) = 0.0;
	gaurdConstraintsMatrix4(7, 1) = 0.0;
	gaurdConstraintsMatrix4(7, 2) = 0.0;
	gaurdConstraintsMatrix4(7, 3) = 1.0;

	gaurdBoundValue4.resize(row);
	gaurdBoundValue4[0] = -2.0;
	gaurdBoundValue4[1] = 2.0;
	gaurdBoundValue4[2] = -2.0;
	gaurdBoundValue4[3] = 3.0;
	gaurdBoundValue4[4] = 1000.0;
	gaurdBoundValue4[5] = 1000.0;
	gaurdBoundValue4[6] = 1000.0;
	gaurdBoundValue4[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope4 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix4, gaurdBoundValue4,
					gaurdBoundSign));

// The transition label ist1

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix5.resize(row, col);
	gaurdConstraintsMatrix5(0, 0) = -1.0;
	gaurdConstraintsMatrix5(0, 1) = 0.0;
	gaurdConstraintsMatrix5(0, 2) = 0.0;
	gaurdConstraintsMatrix5(0, 3) = 0.0;
	gaurdConstraintsMatrix5(1, 0) = 1.0;
	gaurdConstraintsMatrix5(1, 1) = 0.0;
	gaurdConstraintsMatrix5(1, 2) = 0.0;
	gaurdConstraintsMatrix5(1, 3) = 0.0;
	gaurdConstraintsMatrix5(2, 0) = 0.0;
	gaurdConstraintsMatrix5(2, 1) = -1.0;
	gaurdConstraintsMatrix5(2, 2) = 0.0;
	gaurdConstraintsMatrix5(2, 3) = 0.0;
	gaurdConstraintsMatrix5(3, 0) = 0.0;
	gaurdConstraintsMatrix5(3, 1) = 1.0;
	gaurdConstraintsMatrix5(3, 2) = 0.0;
	gaurdConstraintsMatrix5(3, 3) = 0.0;
	gaurdConstraintsMatrix5(4, 0) = 0.0;
	gaurdConstraintsMatrix5(4, 1) = 0.0;
	gaurdConstraintsMatrix5(4, 2) = -1.0;
	gaurdConstraintsMatrix5(4, 3) = 0.0;
	gaurdConstraintsMatrix5(5, 0) = 0.0;
	gaurdConstraintsMatrix5(5, 1) = 0.0;
	gaurdConstraintsMatrix5(5, 2) = 1.0;
	gaurdConstraintsMatrix5(5, 3) = 0.0;
	gaurdConstraintsMatrix5(6, 0) = 0.0;
	gaurdConstraintsMatrix5(6, 1) = 0.0;
	gaurdConstraintsMatrix5(6, 2) = 0.0;
	gaurdConstraintsMatrix5(6, 3) = -1.0;
	gaurdConstraintsMatrix5(7, 0) = 0.0;
	gaurdConstraintsMatrix5(7, 1) = 0.0;
	gaurdConstraintsMatrix5(7, 2) = 0.0;
	gaurdConstraintsMatrix5(7, 3) = 1.0;

	gaurdBoundValue5.resize(row);
	gaurdBoundValue5[0] = -0.0;
	gaurdBoundValue5[1] = 1.0;
	gaurdBoundValue5[2] = -2.0;
	gaurdBoundValue5[3] = 2.0;
	gaurdBoundValue5[4] = 1000.0;
	gaurdBoundValue5[5] = 1000.0;
	gaurdBoundValue5[6] = 1000.0;
	gaurdBoundValue5[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope5 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix5, gaurdBoundValue5,
					gaurdBoundSign));

// The transition label ist2

// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix6.resize(row, col);
	gaurdConstraintsMatrix6(0, 0) = -1.0;
	gaurdConstraintsMatrix6(0, 1) = 0.0;
	gaurdConstraintsMatrix6(0, 2) = 0.0;
	gaurdConstraintsMatrix6(0, 3) = 0.0;
	gaurdConstraintsMatrix6(1, 0) = 1.0;
	gaurdConstraintsMatrix6(1, 1) = 0.0;
	gaurdConstraintsMatrix6(1, 2) = 0.0;
	gaurdConstraintsMatrix6(1, 3) = 0.0;
	gaurdConstraintsMatrix6(2, 0) = 0.0;
	gaurdConstraintsMatrix6(2, 1) = -1.0;
	gaurdConstraintsMatrix6(2, 2) = 0.0;
	gaurdConstraintsMatrix6(2, 3) = 0.0;
	gaurdConstraintsMatrix6(3, 0) = 0.0;
	gaurdConstraintsMatrix6(3, 1) = 1.0;
	gaurdConstraintsMatrix6(3, 2) = 0.0;
	gaurdConstraintsMatrix6(3, 3) = 0.0;
	gaurdConstraintsMatrix6(4, 0) = 0.0;
	gaurdConstraintsMatrix6(4, 1) = 0.0;
	gaurdConstraintsMatrix6(4, 2) = -1.0;
	gaurdConstraintsMatrix6(4, 3) = 0.0;
	gaurdConstraintsMatrix6(5, 0) = 0.0;
	gaurdConstraintsMatrix6(5, 1) = 0.0;
	gaurdConstraintsMatrix6(5, 2) = 1.0;
	gaurdConstraintsMatrix6(5, 3) = 0.0;
	gaurdConstraintsMatrix6(6, 0) = 0.0;
	gaurdConstraintsMatrix6(6, 1) = 0.0;
	gaurdConstraintsMatrix6(6, 2) = 0.0;
	gaurdConstraintsMatrix6(6, 3) = -1.0;
	gaurdConstraintsMatrix6(7, 0) = 0.0;
	gaurdConstraintsMatrix6(7, 1) = 0.0;
	gaurdConstraintsMatrix6(7, 2) = 0.0;
	gaurdConstraintsMatrix6(7, 3) = 1.0;

	gaurdBoundValue6.resize(row);
	gaurdBoundValue6[0] = -1.0;
	gaurdBoundValue6[1] = 1.0;
	gaurdBoundValue6[2] = -1.0;
	gaurdBoundValue6[3] = 2.0;
	gaurdBoundValue6[4] = 1000.0;
	gaurdBoundValue6[5] = 1000.0;
	gaurdBoundValue6[6] = 1000.0;
	gaurdBoundValue6[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope6 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix6, gaurdBoundValue6,
					gaurdBoundSign));

// The transition label ist3

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix7.resize(row, col);
	gaurdConstraintsMatrix7(0, 0) = -1.0;
	gaurdConstraintsMatrix7(0, 1) = 0.0;
	gaurdConstraintsMatrix7(0, 2) = 0.0;
	gaurdConstraintsMatrix7(0, 3) = 0.0;
	gaurdConstraintsMatrix7(1, 0) = 1.0;
	gaurdConstraintsMatrix7(1, 1) = 0.0;
	gaurdConstraintsMatrix7(1, 2) = 0.0;
	gaurdConstraintsMatrix7(1, 3) = 0.0;
	gaurdConstraintsMatrix7(2, 0) = 0.0;
	gaurdConstraintsMatrix7(2, 1) = -1.0;
	gaurdConstraintsMatrix7(2, 2) = 0.0;
	gaurdConstraintsMatrix7(2, 3) = 0.0;
	gaurdConstraintsMatrix7(3, 0) = 0.0;
	gaurdConstraintsMatrix7(3, 1) = 1.0;
	gaurdConstraintsMatrix7(3, 2) = 0.0;
	gaurdConstraintsMatrix7(3, 3) = 0.0;
	gaurdConstraintsMatrix7(4, 0) = 0.0;
	gaurdConstraintsMatrix7(4, 1) = 0.0;
	gaurdConstraintsMatrix7(4, 2) = -1.0;
	gaurdConstraintsMatrix7(4, 3) = 0.0;
	gaurdConstraintsMatrix7(5, 0) = 0.0;
	gaurdConstraintsMatrix7(5, 1) = 0.0;
	gaurdConstraintsMatrix7(5, 2) = 1.0;
	gaurdConstraintsMatrix7(5, 3) = 0.0;
	gaurdConstraintsMatrix7(6, 0) = 0.0;
	gaurdConstraintsMatrix7(6, 1) = 0.0;
	gaurdConstraintsMatrix7(6, 2) = 0.0;
	gaurdConstraintsMatrix7(6, 3) = -1.0;
	gaurdConstraintsMatrix7(7, 0) = 0.0;
	gaurdConstraintsMatrix7(7, 1) = 0.0;
	gaurdConstraintsMatrix7(7, 2) = 0.0;
	gaurdConstraintsMatrix7(7, 3) = 1.0;

	gaurdBoundValue7.resize(row);
	gaurdBoundValue7[0] = -0.0;
	gaurdBoundValue7[1] = 1.0;
	gaurdBoundValue7[2] = -1.0;
	gaurdBoundValue7[3] = 1.0;
	gaurdBoundValue7[4] = 1000.0;
	gaurdBoundValue7[5] = 1000.0;
	gaurdBoundValue7[6] = 1000.0;
	gaurdBoundValue7[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope7 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix7, gaurdBoundValue7,
					gaurdBoundSign));

// The transition label ist9

// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix8.resize(row, col);
	gaurdConstraintsMatrix8(0, 0) = -1.0;
	gaurdConstraintsMatrix8(0, 1) = 0.0;
	gaurdConstraintsMatrix8(0, 2) = 0.0;
	gaurdConstraintsMatrix8(0, 3) = 0.0;
	gaurdConstraintsMatrix8(1, 0) = 1.0;
	gaurdConstraintsMatrix8(1, 1) = 0.0;
	gaurdConstraintsMatrix8(1, 2) = 0.0;
	gaurdConstraintsMatrix8(1, 3) = 0.0;
	gaurdConstraintsMatrix8(2, 0) = 0.0;
	gaurdConstraintsMatrix8(2, 1) = -1.0;
	gaurdConstraintsMatrix8(2, 2) = 0.0;
	gaurdConstraintsMatrix8(2, 3) = 0.0;
	gaurdConstraintsMatrix8(3, 0) = 0.0;
	gaurdConstraintsMatrix8(3, 1) = 1.0;
	gaurdConstraintsMatrix8(3, 2) = 0.0;
	gaurdConstraintsMatrix8(3, 3) = 0.0;
	gaurdConstraintsMatrix8(4, 0) = 0.0;
	gaurdConstraintsMatrix8(4, 1) = 0.0;
	gaurdConstraintsMatrix8(4, 2) = -1.0;
	gaurdConstraintsMatrix8(4, 3) = 0.0;
	gaurdConstraintsMatrix8(5, 0) = 0.0;
	gaurdConstraintsMatrix8(5, 1) = 0.0;
	gaurdConstraintsMatrix8(5, 2) = 1.0;
	gaurdConstraintsMatrix8(5, 3) = 0.0;
	gaurdConstraintsMatrix8(6, 0) = 0.0;
	gaurdConstraintsMatrix8(6, 1) = 0.0;
	gaurdConstraintsMatrix8(6, 2) = 0.0;
	gaurdConstraintsMatrix8(6, 3) = -1.0;
	gaurdConstraintsMatrix8(7, 0) = 0.0;
	gaurdConstraintsMatrix8(7, 1) = 0.0;
	gaurdConstraintsMatrix8(7, 2) = 0.0;
	gaurdConstraintsMatrix8(7, 3) = 1.0;

	gaurdBoundValue8.resize(row);
	gaurdBoundValue8[0] = -1.0;
	gaurdBoundValue8[1] = 1.0;
	gaurdBoundValue8[2] = -1.0;
	gaurdBoundValue8[3] = 2.0;
	gaurdBoundValue8[4] = 1000.0;
	gaurdBoundValue8[5] = 1000.0;
	gaurdBoundValue8[6] = 1000.0;
	gaurdBoundValue8[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope8 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix8, gaurdBoundValue8,
					gaurdBoundSign));

// The transition label ist10

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix9.resize(row, col);
	gaurdConstraintsMatrix9(0, 0) = -1.0;
	gaurdConstraintsMatrix9(0, 1) = 0.0;
	gaurdConstraintsMatrix9(0, 2) = 0.0;
	gaurdConstraintsMatrix9(0, 3) = 0.0;
	gaurdConstraintsMatrix9(1, 0) = 1.0;
	gaurdConstraintsMatrix9(1, 1) = 0.0;
	gaurdConstraintsMatrix9(1, 2) = 0.0;
	gaurdConstraintsMatrix9(1, 3) = 0.0;
	gaurdConstraintsMatrix9(2, 0) = 0.0;
	gaurdConstraintsMatrix9(2, 1) = -1.0;
	gaurdConstraintsMatrix9(2, 2) = 0.0;
	gaurdConstraintsMatrix9(2, 3) = 0.0;
	gaurdConstraintsMatrix9(3, 0) = 0.0;
	gaurdConstraintsMatrix9(3, 1) = 1.0;
	gaurdConstraintsMatrix9(3, 2) = 0.0;
	gaurdConstraintsMatrix9(3, 3) = 0.0;
	gaurdConstraintsMatrix9(4, 0) = 0.0;
	gaurdConstraintsMatrix9(4, 1) = 0.0;
	gaurdConstraintsMatrix9(4, 2) = -1.0;
	gaurdConstraintsMatrix9(4, 3) = 0.0;
	gaurdConstraintsMatrix9(5, 0) = 0.0;
	gaurdConstraintsMatrix9(5, 1) = 0.0;
	gaurdConstraintsMatrix9(5, 2) = 1.0;
	gaurdConstraintsMatrix9(5, 3) = 0.0;
	gaurdConstraintsMatrix9(6, 0) = 0.0;
	gaurdConstraintsMatrix9(6, 1) = 0.0;
	gaurdConstraintsMatrix9(6, 2) = 0.0;
	gaurdConstraintsMatrix9(6, 3) = -1.0;
	gaurdConstraintsMatrix9(7, 0) = 0.0;
	gaurdConstraintsMatrix9(7, 1) = 0.0;
	gaurdConstraintsMatrix9(7, 2) = 0.0;
	gaurdConstraintsMatrix9(7, 3) = 1.0;

	gaurdBoundValue9.resize(row);
	gaurdBoundValue9[0] = -1.0;
	gaurdBoundValue9[1] = 2.0;
	gaurdBoundValue9[2] = -2.0;
	gaurdBoundValue9[3] = 2.0;
	gaurdBoundValue9[4] = 1000.0;
	gaurdBoundValue9[5] = 1000.0;
	gaurdBoundValue9[6] = 1000.0;
	gaurdBoundValue9[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope9 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix9, gaurdBoundValue9,
					gaurdBoundSign));

// The transition label ist11

// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix10.resize(row, col);
	gaurdConstraintsMatrix10(0, 0) = -1.0;
	gaurdConstraintsMatrix10(0, 1) = 0.0;
	gaurdConstraintsMatrix10(0, 2) = 0.0;
	gaurdConstraintsMatrix10(0, 3) = 0.0;
	gaurdConstraintsMatrix10(1, 0) = 1.0;
	gaurdConstraintsMatrix10(1, 1) = 0.0;
	gaurdConstraintsMatrix10(1, 2) = 0.0;
	gaurdConstraintsMatrix10(1, 3) = 0.0;
	gaurdConstraintsMatrix10(2, 0) = 0.0;
	gaurdConstraintsMatrix10(2, 1) = -1.0;
	gaurdConstraintsMatrix10(2, 2) = 0.0;
	gaurdConstraintsMatrix10(2, 3) = 0.0;
	gaurdConstraintsMatrix10(3, 0) = 0.0;
	gaurdConstraintsMatrix10(3, 1) = 1.0;
	gaurdConstraintsMatrix10(3, 2) = 0.0;
	gaurdConstraintsMatrix10(3, 3) = 0.0;
	gaurdConstraintsMatrix10(4, 0) = 0.0;
	gaurdConstraintsMatrix10(4, 1) = 0.0;
	gaurdConstraintsMatrix10(4, 2) = -1.0;
	gaurdConstraintsMatrix10(4, 3) = 0.0;
	gaurdConstraintsMatrix10(5, 0) = 0.0;
	gaurdConstraintsMatrix10(5, 1) = 0.0;
	gaurdConstraintsMatrix10(5, 2) = 1.0;
	gaurdConstraintsMatrix10(5, 3) = 0.0;
	gaurdConstraintsMatrix10(6, 0) = 0.0;
	gaurdConstraintsMatrix10(6, 1) = 0.0;
	gaurdConstraintsMatrix10(6, 2) = 0.0;
	gaurdConstraintsMatrix10(6, 3) = -1.0;
	gaurdConstraintsMatrix10(7, 0) = 0.0;
	gaurdConstraintsMatrix10(7, 1) = 0.0;
	gaurdConstraintsMatrix10(7, 2) = 0.0;
	gaurdConstraintsMatrix10(7, 3) = 1.0;

	gaurdBoundValue10.resize(row);
	gaurdBoundValue10[0] = -2.0;
	gaurdBoundValue10[1] = 2.0;
	gaurdBoundValue10[2] = -1.0;
	gaurdBoundValue10[3] = 2.0;
	gaurdBoundValue10[4] = 1000.0;
	gaurdBoundValue10[5] = 1000.0;
	gaurdBoundValue10[6] = 1000.0;
	gaurdBoundValue10[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope10 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix10, gaurdBoundValue10,
					gaurdBoundSign));

// The transition label ist12

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix11.resize(row, col);
	gaurdConstraintsMatrix11(0, 0) = -1.0;
	gaurdConstraintsMatrix11(0, 1) = 0.0;
	gaurdConstraintsMatrix11(0, 2) = 0.0;
	gaurdConstraintsMatrix11(0, 3) = 0.0;
	gaurdConstraintsMatrix11(1, 0) = 1.0;
	gaurdConstraintsMatrix11(1, 1) = 0.0;
	gaurdConstraintsMatrix11(1, 2) = 0.0;
	gaurdConstraintsMatrix11(1, 3) = 0.0;
	gaurdConstraintsMatrix11(2, 0) = 0.0;
	gaurdConstraintsMatrix11(2, 1) = -1.0;
	gaurdConstraintsMatrix11(2, 2) = 0.0;
	gaurdConstraintsMatrix11(2, 3) = 0.0;
	gaurdConstraintsMatrix11(3, 0) = 0.0;
	gaurdConstraintsMatrix11(3, 1) = 1.0;
	gaurdConstraintsMatrix11(3, 2) = 0.0;
	gaurdConstraintsMatrix11(3, 3) = 0.0;
	gaurdConstraintsMatrix11(4, 0) = 0.0;
	gaurdConstraintsMatrix11(4, 1) = 0.0;
	gaurdConstraintsMatrix11(4, 2) = -1.0;
	gaurdConstraintsMatrix11(4, 3) = 0.0;
	gaurdConstraintsMatrix11(5, 0) = 0.0;
	gaurdConstraintsMatrix11(5, 1) = 0.0;
	gaurdConstraintsMatrix11(5, 2) = 1.0;
	gaurdConstraintsMatrix11(5, 3) = 0.0;
	gaurdConstraintsMatrix11(6, 0) = 0.0;
	gaurdConstraintsMatrix11(6, 1) = 0.0;
	gaurdConstraintsMatrix11(6, 2) = 0.0;
	gaurdConstraintsMatrix11(6, 3) = -1.0;
	gaurdConstraintsMatrix11(7, 0) = 0.0;
	gaurdConstraintsMatrix11(7, 1) = 0.0;
	gaurdConstraintsMatrix11(7, 2) = 0.0;
	gaurdConstraintsMatrix11(7, 3) = 1.0;

	gaurdBoundValue11.resize(row);
	gaurdBoundValue11[0] = -1.0;
	gaurdBoundValue11[1] = 2.0;
	gaurdBoundValue11[2] = -1.0;
	gaurdBoundValue11[3] = 1.0;
	gaurdBoundValue11[4] = 1000.0;
	gaurdBoundValue11[5] = 1000.0;
	gaurdBoundValue11[6] = 1000.0;
	gaurdBoundValue11[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope11 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix11, gaurdBoundValue11,
					gaurdBoundSign));

// The transition label ist16

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix12.resize(row, col);
	gaurdConstraintsMatrix12(0, 0) = -1.0;
	gaurdConstraintsMatrix12(0, 1) = 0.0;
	gaurdConstraintsMatrix12(0, 2) = 0.0;
	gaurdConstraintsMatrix12(0, 3) = 0.0;
	gaurdConstraintsMatrix12(1, 0) = 1.0;
	gaurdConstraintsMatrix12(1, 1) = 0.0;
	gaurdConstraintsMatrix12(1, 2) = 0.0;
	gaurdConstraintsMatrix12(1, 3) = 0.0;
	gaurdConstraintsMatrix12(2, 0) = 0.0;
	gaurdConstraintsMatrix12(2, 1) = -1.0;
	gaurdConstraintsMatrix12(2, 2) = 0.0;
	gaurdConstraintsMatrix12(2, 3) = 0.0;
	gaurdConstraintsMatrix12(3, 0) = 0.0;
	gaurdConstraintsMatrix12(3, 1) = 1.0;
	gaurdConstraintsMatrix12(3, 2) = 0.0;
	gaurdConstraintsMatrix12(3, 3) = 0.0;
	gaurdConstraintsMatrix12(4, 0) = 0.0;
	gaurdConstraintsMatrix12(4, 1) = 0.0;
	gaurdConstraintsMatrix12(4, 2) = -1.0;
	gaurdConstraintsMatrix12(4, 3) = 0.0;
	gaurdConstraintsMatrix12(5, 0) = 0.0;
	gaurdConstraintsMatrix12(5, 1) = 0.0;
	gaurdConstraintsMatrix12(5, 2) = 1.0;
	gaurdConstraintsMatrix12(5, 3) = 0.0;
	gaurdConstraintsMatrix12(6, 0) = 0.0;
	gaurdConstraintsMatrix12(6, 1) = 0.0;
	gaurdConstraintsMatrix12(6, 2) = 0.0;
	gaurdConstraintsMatrix12(6, 3) = -1.0;
	gaurdConstraintsMatrix12(7, 0) = 0.0;
	gaurdConstraintsMatrix12(7, 1) = 0.0;
	gaurdConstraintsMatrix12(7, 2) = 0.0;
	gaurdConstraintsMatrix12(7, 3) = 1.0;

	gaurdBoundValue12.resize(row);
	gaurdBoundValue12[0] = -2.0;
	gaurdBoundValue12[1] = 3.0;
	gaurdBoundValue12[2] = -2.0;
	gaurdBoundValue12[3] = 2.0;
	gaurdBoundValue12[4] = 1000.0;
	gaurdBoundValue12[5] = 1000.0;
	gaurdBoundValue12[6] = 1000.0;
	gaurdBoundValue12[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope12 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix12, gaurdBoundValue12,
					gaurdBoundSign));

// The transition label ist17

// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix13.resize(row, col);
	gaurdConstraintsMatrix13(0, 0) = -1.0;
	gaurdConstraintsMatrix13(0, 1) = 0.0;
	gaurdConstraintsMatrix13(0, 2) = 0.0;
	gaurdConstraintsMatrix13(0, 3) = 0.0;
	gaurdConstraintsMatrix13(1, 0) = 1.0;
	gaurdConstraintsMatrix13(1, 1) = 0.0;
	gaurdConstraintsMatrix13(1, 2) = 0.0;
	gaurdConstraintsMatrix13(1, 3) = 0.0;
	gaurdConstraintsMatrix13(2, 0) = 0.0;
	gaurdConstraintsMatrix13(2, 1) = -1.0;
	gaurdConstraintsMatrix13(2, 2) = 0.0;
	gaurdConstraintsMatrix13(2, 3) = 0.0;
	gaurdConstraintsMatrix13(3, 0) = 0.0;
	gaurdConstraintsMatrix13(3, 1) = 1.0;
	gaurdConstraintsMatrix13(3, 2) = 0.0;
	gaurdConstraintsMatrix13(3, 3) = 0.0;
	gaurdConstraintsMatrix13(4, 0) = 0.0;
	gaurdConstraintsMatrix13(4, 1) = 0.0;
	gaurdConstraintsMatrix13(4, 2) = -1.0;
	gaurdConstraintsMatrix13(4, 3) = 0.0;
	gaurdConstraintsMatrix13(5, 0) = 0.0;
	gaurdConstraintsMatrix13(5, 1) = 0.0;
	gaurdConstraintsMatrix13(5, 2) = 1.0;
	gaurdConstraintsMatrix13(5, 3) = 0.0;
	gaurdConstraintsMatrix13(6, 0) = 0.0;
	gaurdConstraintsMatrix13(6, 1) = 0.0;
	gaurdConstraintsMatrix13(6, 2) = 0.0;
	gaurdConstraintsMatrix13(6, 3) = -1.0;
	gaurdConstraintsMatrix13(7, 0) = 0.0;
	gaurdConstraintsMatrix13(7, 1) = 0.0;
	gaurdConstraintsMatrix13(7, 2) = 0.0;
	gaurdConstraintsMatrix13(7, 3) = 1.0;

	gaurdBoundValue13.resize(row);
	gaurdBoundValue13[0] = -2.0;
	gaurdBoundValue13[1] = 2.0;
	gaurdBoundValue13[2] = -1.0;
	gaurdBoundValue13[3] = 2.0;
	gaurdBoundValue13[4] = 1000.0;
	gaurdBoundValue13[5] = 1000.0;
	gaurdBoundValue13[6] = 1000.0;
	gaurdBoundValue13[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope13 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix13, gaurdBoundValue13,
					gaurdBoundSign));

// The transition label ist18

// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix14.resize(row, col);
	gaurdConstraintsMatrix14(0, 0) = -1.0;
	gaurdConstraintsMatrix14(0, 1) = 0.0;
	gaurdConstraintsMatrix14(0, 2) = 0.0;
	gaurdConstraintsMatrix14(0, 3) = 0.0;
	gaurdConstraintsMatrix14(1, 0) = 1.0;
	gaurdConstraintsMatrix14(1, 1) = 0.0;
	gaurdConstraintsMatrix14(1, 2) = 0.0;
	gaurdConstraintsMatrix14(1, 3) = 0.0;
	gaurdConstraintsMatrix14(2, 0) = 0.0;
	gaurdConstraintsMatrix14(2, 1) = -1.0;
	gaurdConstraintsMatrix14(2, 2) = 0.0;
	gaurdConstraintsMatrix14(2, 3) = 0.0;
	gaurdConstraintsMatrix14(3, 0) = 0.0;
	gaurdConstraintsMatrix14(3, 1) = 1.0;
	gaurdConstraintsMatrix14(3, 2) = 0.0;
	gaurdConstraintsMatrix14(3, 3) = 0.0;
	gaurdConstraintsMatrix14(4, 0) = 0.0;
	gaurdConstraintsMatrix14(4, 1) = 0.0;
	gaurdConstraintsMatrix14(4, 2) = -1.0;
	gaurdConstraintsMatrix14(4, 3) = 0.0;
	gaurdConstraintsMatrix14(5, 0) = 0.0;
	gaurdConstraintsMatrix14(5, 1) = 0.0;
	gaurdConstraintsMatrix14(5, 2) = 1.0;
	gaurdConstraintsMatrix14(5, 3) = 0.0;
	gaurdConstraintsMatrix14(6, 0) = 0.0;
	gaurdConstraintsMatrix14(6, 1) = 0.0;
	gaurdConstraintsMatrix14(6, 2) = 0.0;
	gaurdConstraintsMatrix14(6, 3) = -1.0;
	gaurdConstraintsMatrix14(7, 0) = 0.0;
	gaurdConstraintsMatrix14(7, 1) = 0.0;
	gaurdConstraintsMatrix14(7, 2) = 0.0;
	gaurdConstraintsMatrix14(7, 3) = 1.0;

	gaurdBoundValue14.resize(row);
	gaurdBoundValue14[0] = -2.0;
	gaurdBoundValue14[1] = 3.0;
	gaurdBoundValue14[2] = -1.0;
	gaurdBoundValue14[3] = 1.0;
	gaurdBoundValue14[4] = 1000.0;
	gaurdBoundValue14[5] = 1000.0;
	gaurdBoundValue14[6] = 1000.0;
	gaurdBoundValue14[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope14 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix14, gaurdBoundValue14,
					gaurdBoundSign));

// The transition label ist6

// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix15.resize(row, col);
	gaurdConstraintsMatrix15(0, 0) = -1.0;
	gaurdConstraintsMatrix15(0, 1) = 0.0;
	gaurdConstraintsMatrix15(0, 2) = 0.0;
	gaurdConstraintsMatrix15(0, 3) = 0.0;
	gaurdConstraintsMatrix15(1, 0) = 1.0;
	gaurdConstraintsMatrix15(1, 1) = 0.0;
	gaurdConstraintsMatrix15(1, 2) = 0.0;
	gaurdConstraintsMatrix15(1, 3) = 0.0;
	gaurdConstraintsMatrix15(2, 0) = 0.0;
	gaurdConstraintsMatrix15(2, 1) = -1.0;
	gaurdConstraintsMatrix15(2, 2) = 0.0;
	gaurdConstraintsMatrix15(2, 3) = 0.0;
	gaurdConstraintsMatrix15(3, 0) = 0.0;
	gaurdConstraintsMatrix15(3, 1) = 1.0;
	gaurdConstraintsMatrix15(3, 2) = 0.0;
	gaurdConstraintsMatrix15(3, 3) = 0.0;
	gaurdConstraintsMatrix15(4, 0) = 0.0;
	gaurdConstraintsMatrix15(4, 1) = 0.0;
	gaurdConstraintsMatrix15(4, 2) = -1.0;
	gaurdConstraintsMatrix15(4, 3) = 0.0;
	gaurdConstraintsMatrix15(5, 0) = 0.0;
	gaurdConstraintsMatrix15(5, 1) = 0.0;
	gaurdConstraintsMatrix15(5, 2) = 1.0;
	gaurdConstraintsMatrix15(5, 3) = 0.0;
	gaurdConstraintsMatrix15(6, 0) = 0.0;
	gaurdConstraintsMatrix15(6, 1) = 0.0;
	gaurdConstraintsMatrix15(6, 2) = 0.0;
	gaurdConstraintsMatrix15(6, 3) = -1.0;
	gaurdConstraintsMatrix15(7, 0) = 0.0;
	gaurdConstraintsMatrix15(7, 1) = 0.0;
	gaurdConstraintsMatrix15(7, 2) = 0.0;
	gaurdConstraintsMatrix15(7, 3) = 1.0;

	gaurdBoundValue15.resize(row);
	gaurdBoundValue15[0] = -1.0;
	gaurdBoundValue15[1] = 2.0;
	gaurdBoundValue15[2] = -1.0;
	gaurdBoundValue15[3] = 1.0;
	gaurdBoundValue15[4] = 1000.0;
	gaurdBoundValue15[5] = 1000.0;
	gaurdBoundValue15[6] = 1000.0;
	gaurdBoundValue15[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope15 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix15, gaurdBoundValue15,
					gaurdBoundSign));

// The transition label ist7

// Original guard: x1 = 1 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix16.resize(row, col);
	gaurdConstraintsMatrix16(0, 0) = -1.0;
	gaurdConstraintsMatrix16(0, 1) = 0.0;
	gaurdConstraintsMatrix16(0, 2) = 0.0;
	gaurdConstraintsMatrix16(0, 3) = 0.0;
	gaurdConstraintsMatrix16(1, 0) = 1.0;
	gaurdConstraintsMatrix16(1, 1) = 0.0;
	gaurdConstraintsMatrix16(1, 2) = 0.0;
	gaurdConstraintsMatrix16(1, 3) = 0.0;
	gaurdConstraintsMatrix16(2, 0) = 0.0;
	gaurdConstraintsMatrix16(2, 1) = -1.0;
	gaurdConstraintsMatrix16(2, 2) = 0.0;
	gaurdConstraintsMatrix16(2, 3) = 0.0;
	gaurdConstraintsMatrix16(3, 0) = 0.0;
	gaurdConstraintsMatrix16(3, 1) = 1.0;
	gaurdConstraintsMatrix16(3, 2) = 0.0;
	gaurdConstraintsMatrix16(3, 3) = 0.0;
	gaurdConstraintsMatrix16(4, 0) = 0.0;
	gaurdConstraintsMatrix16(4, 1) = 0.0;
	gaurdConstraintsMatrix16(4, 2) = -1.0;
	gaurdConstraintsMatrix16(4, 3) = 0.0;
	gaurdConstraintsMatrix16(5, 0) = 0.0;
	gaurdConstraintsMatrix16(5, 1) = 0.0;
	gaurdConstraintsMatrix16(5, 2) = 1.0;
	gaurdConstraintsMatrix16(5, 3) = 0.0;
	gaurdConstraintsMatrix16(6, 0) = 0.0;
	gaurdConstraintsMatrix16(6, 1) = 0.0;
	gaurdConstraintsMatrix16(6, 2) = 0.0;
	gaurdConstraintsMatrix16(6, 3) = -1.0;
	gaurdConstraintsMatrix16(7, 0) = 0.0;
	gaurdConstraintsMatrix16(7, 1) = 0.0;
	gaurdConstraintsMatrix16(7, 2) = 0.0;
	gaurdConstraintsMatrix16(7, 3) = 1.0;

	gaurdBoundValue16.resize(row);
	gaurdBoundValue16[0] = -1.0;
	gaurdBoundValue16[1] = 1.0;
	gaurdBoundValue16[2] = -0.0;
	gaurdBoundValue16[3] = 1.0;
	gaurdBoundValue16[4] = 1000.0;
	gaurdBoundValue16[5] = 1000.0;
	gaurdBoundValue16[6] = 1000.0;
	gaurdBoundValue16[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope16 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix16, gaurdBoundValue16,
					gaurdBoundSign));

// The transition label ist8

// Original guard: x1 = 2 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix17.resize(row, col);
	gaurdConstraintsMatrix17(0, 0) = -1.0;
	gaurdConstraintsMatrix17(0, 1) = 0.0;
	gaurdConstraintsMatrix17(0, 2) = 0.0;
	gaurdConstraintsMatrix17(0, 3) = 0.0;
	gaurdConstraintsMatrix17(1, 0) = 1.0;
	gaurdConstraintsMatrix17(1, 1) = 0.0;
	gaurdConstraintsMatrix17(1, 2) = 0.0;
	gaurdConstraintsMatrix17(1, 3) = 0.0;
	gaurdConstraintsMatrix17(2, 0) = 0.0;
	gaurdConstraintsMatrix17(2, 1) = -1.0;
	gaurdConstraintsMatrix17(2, 2) = 0.0;
	gaurdConstraintsMatrix17(2, 3) = 0.0;
	gaurdConstraintsMatrix17(3, 0) = 0.0;
	gaurdConstraintsMatrix17(3, 1) = 1.0;
	gaurdConstraintsMatrix17(3, 2) = 0.0;
	gaurdConstraintsMatrix17(3, 3) = 0.0;
	gaurdConstraintsMatrix17(4, 0) = 0.0;
	gaurdConstraintsMatrix17(4, 1) = 0.0;
	gaurdConstraintsMatrix17(4, 2) = -1.0;
	gaurdConstraintsMatrix17(4, 3) = 0.0;
	gaurdConstraintsMatrix17(5, 0) = 0.0;
	gaurdConstraintsMatrix17(5, 1) = 0.0;
	gaurdConstraintsMatrix17(5, 2) = 1.0;
	gaurdConstraintsMatrix17(5, 3) = 0.0;
	gaurdConstraintsMatrix17(6, 0) = 0.0;
	gaurdConstraintsMatrix17(6, 1) = 0.0;
	gaurdConstraintsMatrix17(6, 2) = 0.0;
	gaurdConstraintsMatrix17(6, 3) = -1.0;
	gaurdConstraintsMatrix17(7, 0) = 0.0;
	gaurdConstraintsMatrix17(7, 1) = 0.0;
	gaurdConstraintsMatrix17(7, 2) = 0.0;
	gaurdConstraintsMatrix17(7, 3) = 1.0;

	gaurdBoundValue17.resize(row);
	gaurdBoundValue17[0] = -2.0;
	gaurdBoundValue17[1] = 2.0;
	gaurdBoundValue17[2] = -0.0;
	gaurdBoundValue17[3] = 1.0;
	gaurdBoundValue17[4] = 1000.0;
	gaurdBoundValue17[5] = 1000.0;
	gaurdBoundValue17[6] = 1000.0;
	gaurdBoundValue17[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope17 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix17, gaurdBoundValue17,
					gaurdBoundSign));

// The transition label ist5

// Original guard: x1 = 1 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix18.resize(row, col);
	gaurdConstraintsMatrix18(0, 0) = -1.0;
	gaurdConstraintsMatrix18(0, 1) = 0.0;
	gaurdConstraintsMatrix18(0, 2) = 0.0;
	gaurdConstraintsMatrix18(0, 3) = 0.0;
	gaurdConstraintsMatrix18(1, 0) = 1.0;
	gaurdConstraintsMatrix18(1, 1) = 0.0;
	gaurdConstraintsMatrix18(1, 2) = 0.0;
	gaurdConstraintsMatrix18(1, 3) = 0.0;
	gaurdConstraintsMatrix18(2, 0) = 0.0;
	gaurdConstraintsMatrix18(2, 1) = -1.0;
	gaurdConstraintsMatrix18(2, 2) = 0.0;
	gaurdConstraintsMatrix18(2, 3) = 0.0;
	gaurdConstraintsMatrix18(3, 0) = 0.0;
	gaurdConstraintsMatrix18(3, 1) = 1.0;
	gaurdConstraintsMatrix18(3, 2) = 0.0;
	gaurdConstraintsMatrix18(3, 3) = 0.0;
	gaurdConstraintsMatrix18(4, 0) = 0.0;
	gaurdConstraintsMatrix18(4, 1) = 0.0;
	gaurdConstraintsMatrix18(4, 2) = -1.0;
	gaurdConstraintsMatrix18(4, 3) = 0.0;
	gaurdConstraintsMatrix18(5, 0) = 0.0;
	gaurdConstraintsMatrix18(5, 1) = 0.0;
	gaurdConstraintsMatrix18(5, 2) = 1.0;
	gaurdConstraintsMatrix18(5, 3) = 0.0;
	gaurdConstraintsMatrix18(6, 0) = 0.0;
	gaurdConstraintsMatrix18(6, 1) = 0.0;
	gaurdConstraintsMatrix18(6, 2) = 0.0;
	gaurdConstraintsMatrix18(6, 3) = -1.0;
	gaurdConstraintsMatrix18(7, 0) = 0.0;
	gaurdConstraintsMatrix18(7, 1) = 0.0;
	gaurdConstraintsMatrix18(7, 2) = 0.0;
	gaurdConstraintsMatrix18(7, 3) = 1.0;

	gaurdBoundValue18.resize(row);
	gaurdBoundValue18[0] = -1.0;
	gaurdBoundValue18[1] = 1.0;
	gaurdBoundValue18[2] = -0.0;
	gaurdBoundValue18[3] = 1.0;
	gaurdBoundValue18[4] = 1000.0;
	gaurdBoundValue18[5] = 1000.0;
	gaurdBoundValue18[6] = 1000.0;
	gaurdBoundValue18[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope18 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix18, gaurdBoundValue18,
					gaurdBoundSign));

// The transition label ist4

// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 4;

	gaurdConstraintsMatrix19.resize(row, col);
	gaurdConstraintsMatrix19(0, 0) = -1.0;
	gaurdConstraintsMatrix19(0, 1) = 0.0;
	gaurdConstraintsMatrix19(0, 2) = 0.0;
	gaurdConstraintsMatrix19(0, 3) = 0.0;
	gaurdConstraintsMatrix19(1, 0) = 1.0;
	gaurdConstraintsMatrix19(1, 1) = 0.0;
	gaurdConstraintsMatrix19(1, 2) = 0.0;
	gaurdConstraintsMatrix19(1, 3) = 0.0;
	gaurdConstraintsMatrix19(2, 0) = 0.0;
	gaurdConstraintsMatrix19(2, 1) = -1.0;
	gaurdConstraintsMatrix19(2, 2) = 0.0;
	gaurdConstraintsMatrix19(2, 3) = 0.0;
	gaurdConstraintsMatrix19(3, 0) = 0.0;
	gaurdConstraintsMatrix19(3, 1) = 1.0;
	gaurdConstraintsMatrix19(3, 2) = 0.0;
	gaurdConstraintsMatrix19(3, 3) = 0.0;
	gaurdConstraintsMatrix19(4, 0) = 0.0;
	gaurdConstraintsMatrix19(4, 1) = 0.0;
	gaurdConstraintsMatrix19(4, 2) = -1.0;
	gaurdConstraintsMatrix19(4, 3) = 0.0;
	gaurdConstraintsMatrix19(5, 0) = 0.0;
	gaurdConstraintsMatrix19(5, 1) = 0.0;
	gaurdConstraintsMatrix19(5, 2) = 1.0;
	gaurdConstraintsMatrix19(5, 3) = 0.0;
	gaurdConstraintsMatrix19(6, 0) = 0.0;
	gaurdConstraintsMatrix19(6, 1) = 0.0;
	gaurdConstraintsMatrix19(6, 2) = 0.0;
	gaurdConstraintsMatrix19(6, 3) = -1.0;
	gaurdConstraintsMatrix19(7, 0) = 0.0;
	gaurdConstraintsMatrix19(7, 1) = 0.0;
	gaurdConstraintsMatrix19(7, 2) = 0.0;
	gaurdConstraintsMatrix19(7, 3) = 1.0;

	gaurdBoundValue19.resize(row);
	gaurdBoundValue19[0] = -0.0;
	gaurdBoundValue19[1] = 1.0;
	gaurdBoundValue19[2] = -1.0;
	gaurdBoundValue19[3] = 1.0;
	gaurdBoundValue19[4] = 1000.0;
	gaurdBoundValue19[5] = 1000.0;
	gaurdBoundValue19[6] = 1000.0;
	gaurdBoundValue19[7] = 1000.0;
	gaurdBoundSign = 1;
	gaurd_polytope19 = polytope::ptr(
			new polytope(gaurdConstraintsMatrix19, gaurdBoundValue19,
					gaurdBoundSign));

// The transition label is   t13

	math::matrix<double> R0;
	row = 4;
	col = 4;
	R0.resize(row, col);
	R0(0, 0) = 1.0;
	R0(0, 1) = 0.0;
	R0(0, 2) = 0.0;
	R0(0, 3) = 0.0;
	R0(1, 0) = 0.0;
	R0(1, 1) = 1.0;
	R0(1, 2) = 0.0;
	R0(1, 3) = 0.0;
	R0(2, 0) = 0.0;
	R0(2, 1) = 0.0;
	R0(2, 2) = 1.0;
	R0(2, 3) = 0.0;
	R0(3, 0) = 0.0;
	R0(3, 1) = 0.0;
	R0(3, 2) = 0.0;
	R0(3, 3) = 1.0;
	std::vector<double> w0(row);
	w0[0] = 0.0;
	w0[1] = 0.0;
	w0[2] = 0.0;
	w0[3] = 0.0;

	Assign assignment0;
	assignment0.Map = R0;
	assignment0.b = w0;

// The transition label is   t14

	math::matrix<double> R1;
	row = 4;
	col = 4;
	R1.resize(row, col);
	R1(0, 0) = 1.0;
	R1(0, 1) = 0.0;
	R1(0, 2) = 0.0;
	R1(0, 3) = 0.0;
	R1(1, 0) = 0.0;
	R1(1, 1) = 1.0;
	R1(1, 2) = 0.0;
	R1(1, 3) = 0.0;
	R1(2, 0) = 0.0;
	R1(2, 1) = 0.0;
	R1(2, 2) = 1.0;
	R1(2, 3) = 0.0;
	R1(3, 0) = 0.0;
	R1(3, 1) = 0.0;
	R1(3, 2) = 0.0;
	R1(3, 3) = 1.0;
	std::vector<double> w1(row);
	w1[0] = 0.0;
	w1[1] = 0.0;
	w1[2] = 0.0;
	w1[3] = 0.0;

	Assign assignment1;
	assignment1.Map = R1;
	assignment1.b = w1;

// The transition label is   t15

	math::matrix<double> R2;
	row = 4;
	col = 4;
	R2.resize(row, col);
	R2(0, 0) = 1.0;
	R2(0, 1) = 0.0;
	R2(0, 2) = 0.0;
	R2(0, 3) = 0.0;
	R2(1, 0) = 0.0;
	R2(1, 1) = 1.0;
	R2(1, 2) = 0.0;
	R2(1, 3) = 0.0;
	R2(2, 0) = 0.0;
	R2(2, 1) = 0.0;
	R2(2, 2) = 1.0;
	R2(2, 3) = 0.0;
	R2(3, 0) = 0.0;
	R2(3, 1) = 0.0;
	R2(3, 2) = 0.0;
	R2(3, 3) = 1.0;
	std::vector<double> w2(row);
	w2[0] = 0.0;
	w2[1] = 0.0;
	w2[2] = 0.0;
	w2[3] = 0.0;

	Assign assignment2;
	assignment2.Map = R2;
	assignment2.b = w2;

// The transition label is   t19

	math::matrix<double> R3;
	row = 4;
	col = 4;
	R3.resize(row, col);
	R3(0, 0) = 1.0;
	R3(0, 1) = 0.0;
	R3(0, 2) = 0.0;
	R3(0, 3) = 0.0;
	R3(1, 0) = 0.0;
	R3(1, 1) = 1.0;
	R3(1, 2) = 0.0;
	R3(1, 3) = 0.0;
	R3(2, 0) = 0.0;
	R3(2, 1) = 0.0;
	R3(2, 2) = 1.0;
	R3(2, 3) = 0.0;
	R3(3, 0) = 0.0;
	R3(3, 1) = 0.0;
	R3(3, 2) = 0.0;
	R3(3, 3) = 1.0;
	std::vector<double> w3(row);
	w3[0] = 0.0;
	w3[1] = 0.0;
	w3[2] = 0.0;
	w3[3] = 0.0;

	Assign assignment3;
	assignment3.Map = R3;
	assignment3.b = w3;

// The transition label is   t20

	math::matrix<double> R4;
	row = 4;
	col = 4;
	R4.resize(row, col);
	R4(0, 0) = 1.0;
	R4(0, 1) = 0.0;
	R4(0, 2) = 0.0;
	R4(0, 3) = 0.0;
	R4(1, 0) = 0.0;
	R4(1, 1) = 1.0;
	R4(1, 2) = 0.0;
	R4(1, 3) = 0.0;
	R4(2, 0) = 0.0;
	R4(2, 1) = 0.0;
	R4(2, 2) = 1.0;
	R4(2, 3) = 0.0;
	R4(3, 0) = 0.0;
	R4(3, 1) = 0.0;
	R4(3, 2) = 0.0;
	R4(3, 3) = 1.0;
	std::vector<double> w4(row);
	w4[0] = 0.0;
	w4[1] = 0.0;
	w4[2] = 0.0;
	w4[3] = 0.0;

	Assign assignment4;
	assignment4.Map = R4;
	assignment4.b = w4;

// The transition label is   t1

	math::matrix<double> R5;
	row = 4;
	col = 4;
	R5.resize(row, col);
	R5(0, 0) = 1.0;
	R5(0, 1) = 0.0;
	R5(0, 2) = 0.0;
	R5(0, 3) = 0.0;
	R5(1, 0) = 0.0;
	R5(1, 1) = 1.0;
	R5(1, 2) = 0.0;
	R5(1, 3) = 0.0;
	R5(2, 0) = 0.0;
	R5(2, 1) = 0.0;
	R5(2, 2) = 1.0;
	R5(2, 3) = 0.0;
	R5(3, 0) = 0.0;
	R5(3, 1) = 0.0;
	R5(3, 2) = 0.0;
	R5(3, 3) = 1.0;
	std::vector<double> w5(row);
	w5[0] = 0.0;
	w5[1] = 0.0;
	w5[2] = 0.0;
	w5[3] = 0.0;

	Assign assignment5;
	assignment5.Map = R5;
	assignment5.b = w5;

// The transition label is   t2

	math::matrix<double> R6;
	row = 4;
	col = 4;
	R6.resize(row, col);
	R6(0, 0) = 1.0;
	R6(0, 1) = 0.0;
	R6(0, 2) = 0.0;
	R6(0, 3) = 0.0;
	R6(1, 0) = 0.0;
	R6(1, 1) = 1.0;
	R6(1, 2) = 0.0;
	R6(1, 3) = 0.0;
	R6(2, 0) = 0.0;
	R6(2, 1) = 0.0;
	R6(2, 2) = 1.0;
	R6(2, 3) = 0.0;
	R6(3, 0) = 0.0;
	R6(3, 1) = 0.0;
	R6(3, 2) = 0.0;
	R6(3, 3) = 1.0;
	std::vector<double> w6(row);
	w6[0] = 0.0;
	w6[1] = 0.0;
	w6[2] = 0.0;
	w6[3] = 0.0;

	Assign assignment6;
	assignment6.Map = R6;
	assignment6.b = w6;

// The transition label is   t3

	math::matrix<double> R7;
	row = 4;
	col = 4;
	R7.resize(row, col);
	R7(0, 0) = 1.0;
	R7(0, 1) = 0.0;
	R7(0, 2) = 0.0;
	R7(0, 3) = 0.0;
	R7(1, 0) = 0.0;
	R7(1, 1) = 1.0;
	R7(1, 2) = 0.0;
	R7(1, 3) = 0.0;
	R7(2, 0) = 0.0;
	R7(2, 1) = 0.0;
	R7(2, 2) = 1.0;
	R7(2, 3) = 0.0;
	R7(3, 0) = 0.0;
	R7(3, 1) = 0.0;
	R7(3, 2) = 0.0;
	R7(3, 3) = 1.0;
	std::vector<double> w7(row);
	w7[0] = 0.0;
	w7[1] = 0.0;
	w7[2] = 0.0;
	w7[3] = 0.0;

	Assign assignment7;
	assignment7.Map = R7;
	assignment7.b = w7;

// The transition label is   t9

	math::matrix<double> R8;
	row = 4;
	col = 4;
	R8.resize(row, col);
	R8(0, 0) = 1.0;
	R8(0, 1) = 0.0;
	R8(0, 2) = 0.0;
	R8(0, 3) = 0.0;
	R8(1, 0) = 0.0;
	R8(1, 1) = 1.0;
	R8(1, 2) = 0.0;
	R8(1, 3) = 0.0;
	R8(2, 0) = 0.0;
	R8(2, 1) = 0.0;
	R8(2, 2) = 1.0;
	R8(2, 3) = 0.0;
	R8(3, 0) = 0.0;
	R8(3, 1) = 0.0;
	R8(3, 2) = 0.0;
	R8(3, 3) = 1.0;
	std::vector<double> w8(row);
	w8[0] = 0.0;
	w8[1] = 0.0;
	w8[2] = 0.0;
	w8[3] = 0.0;

	Assign assignment8;
	assignment8.Map = R8;
	assignment8.b = w8;

// The transition label is   t10

	math::matrix<double> R9;
	row = 4;
	col = 4;
	R9.resize(row, col);
	R9(0, 0) = 1.0;
	R9(0, 1) = 0.0;
	R9(0, 2) = 0.0;
	R9(0, 3) = 0.0;
	R9(1, 0) = 0.0;
	R9(1, 1) = 1.0;
	R9(1, 2) = 0.0;
	R9(1, 3) = 0.0;
	R9(2, 0) = 0.0;
	R9(2, 1) = 0.0;
	R9(2, 2) = 1.0;
	R9(2, 3) = 0.0;
	R9(3, 0) = 0.0;
	R9(3, 1) = 0.0;
	R9(3, 2) = 0.0;
	R9(3, 3) = 1.0;
	std::vector<double> w9(row);
	w9[0] = 0.0;
	w9[1] = 0.0;
	w9[2] = 0.0;
	w9[3] = 0.0;

	Assign assignment9;
	assignment9.Map = R9;
	assignment9.b = w9;

// The transition label is   t11

	math::matrix<double> R10;
	row = 4;
	col = 4;
	R10.resize(row, col);
	R10(0, 0) = 1.0;
	R10(0, 1) = 0.0;
	R10(0, 2) = 0.0;
	R10(0, 3) = 0.0;
	R10(1, 0) = 0.0;
	R10(1, 1) = 1.0;
	R10(1, 2) = 0.0;
	R10(1, 3) = 0.0;
	R10(2, 0) = 0.0;
	R10(2, 1) = 0.0;
	R10(2, 2) = 1.0;
	R10(2, 3) = 0.0;
	R10(3, 0) = 0.0;
	R10(3, 1) = 0.0;
	R10(3, 2) = 0.0;
	R10(3, 3) = 1.0;
	std::vector<double> w10(row);
	w10[0] = 0.0;
	w10[1] = 0.0;
	w10[2] = 0.0;
	w10[3] = 0.0;

	Assign assignment10;
	assignment10.Map = R10;
	assignment10.b = w10;

// The transition label is   t12

	math::matrix<double> R11;
	row = 4;
	col = 4;
	R11.resize(row, col);
	R11(0, 0) = 1.0;
	R11(0, 1) = 0.0;
	R11(0, 2) = 0.0;
	R11(0, 3) = 0.0;
	R11(1, 0) = 0.0;
	R11(1, 1) = 1.0;
	R11(1, 2) = 0.0;
	R11(1, 3) = 0.0;
	R11(2, 0) = 0.0;
	R11(2, 1) = 0.0;
	R11(2, 2) = 1.0;
	R11(2, 3) = 0.0;
	R11(3, 0) = 0.0;
	R11(3, 1) = 0.0;
	R11(3, 2) = 0.0;
	R11(3, 3) = 1.0;
	std::vector<double> w11(row);
	w11[0] = 0.0;
	w11[1] = 0.0;
	w11[2] = 0.0;
	w11[3] = 0.0;

	Assign assignment11;
	assignment11.Map = R11;
	assignment11.b = w11;

// The transition label is   t16

	math::matrix<double> R12;
	row = 4;
	col = 4;
	R12.resize(row, col);
	R12(0, 0) = 1.0;
	R12(0, 1) = 0.0;
	R12(0, 2) = 0.0;
	R12(0, 3) = 0.0;
	R12(1, 0) = 0.0;
	R12(1, 1) = 1.0;
	R12(1, 2) = 0.0;
	R12(1, 3) = 0.0;
	R12(2, 0) = 0.0;
	R12(2, 1) = 0.0;
	R12(2, 2) = 1.0;
	R12(2, 3) = 0.0;
	R12(3, 0) = 0.0;
	R12(3, 1) = 0.0;
	R12(3, 2) = 0.0;
	R12(3, 3) = 1.0;
	std::vector<double> w12(row);
	w12[0] = 0.0;
	w12[1] = 0.0;
	w12[2] = 0.0;
	w12[3] = 0.0;

	Assign assignment12;
	assignment12.Map = R12;
	assignment12.b = w12;

// The transition label is   t17

	math::matrix<double> R13;
	row = 4;
	col = 4;
	R13.resize(row, col);
	R13(0, 0) = 1.0;
	R13(0, 1) = 0.0;
	R13(0, 2) = 0.0;
	R13(0, 3) = 0.0;
	R13(1, 0) = 0.0;
	R13(1, 1) = 1.0;
	R13(1, 2) = 0.0;
	R13(1, 3) = 0.0;
	R13(2, 0) = 0.0;
	R13(2, 1) = 0.0;
	R13(2, 2) = 1.0;
	R13(2, 3) = 0.0;
	R13(3, 0) = 0.0;
	R13(3, 1) = 0.0;
	R13(3, 2) = 0.0;
	R13(3, 3) = 1.0;
	std::vector<double> w13(row);
	w13[0] = 0.0;
	w13[1] = 0.0;
	w13[2] = 0.0;
	w13[3] = 0.0;

	Assign assignment13;
	assignment13.Map = R13;
	assignment13.b = w13;

// The transition label is   t18

	math::matrix<double> R14;
	row = 4;
	col = 4;
	R14.resize(row, col);
	R14(0, 0) = 1.0;
	R14(0, 1) = 0.0;
	R14(0, 2) = 0.0;
	R14(0, 3) = 0.0;
	R14(1, 0) = 0.0;
	R14(1, 1) = 1.0;
	R14(1, 2) = 0.0;
	R14(1, 3) = 0.0;
	R14(2, 0) = 0.0;
	R14(2, 1) = 0.0;
	R14(2, 2) = 1.0;
	R14(2, 3) = 0.0;
	R14(3, 0) = 0.0;
	R14(3, 1) = 0.0;
	R14(3, 2) = 0.0;
	R14(3, 3) = 1.0;
	std::vector<double> w14(row);
	w14[0] = 0.0;
	w14[1] = 0.0;
	w14[2] = 0.0;
	w14[3] = 0.0;

	Assign assignment14;
	assignment14.Map = R14;
	assignment14.b = w14;

// The transition label is   t6

	math::matrix<double> R15;
	row = 4;
	col = 4;
	R15.resize(row, col);
	R15(0, 0) = 1.0;
	R15(0, 1) = 0.0;
	R15(0, 2) = 0.0;
	R15(0, 3) = 0.0;
	R15(1, 0) = 0.0;
	R15(1, 1) = 1.0;
	R15(1, 2) = 0.0;
	R15(1, 3) = 0.0;
	R15(2, 0) = 0.0;
	R15(2, 1) = 0.0;
	R15(2, 2) = 1.0;
	R15(2, 3) = 0.0;
	R15(3, 0) = 0.0;
	R15(3, 1) = 0.0;
	R15(3, 2) = 0.0;
	R15(3, 3) = 1.0;
	std::vector<double> w15(row);
	w15[0] = 0.0;
	w15[1] = 0.0;
	w15[2] = 0.0;
	w15[3] = 0.0;

	Assign assignment15;
	assignment15.Map = R15;
	assignment15.b = w15;

// The transition label is   t7

	math::matrix<double> R16;
	row = 4;
	col = 4;
	R16.resize(row, col);
	R16(0, 0) = 1.0;
	R16(0, 1) = 0.0;
	R16(0, 2) = 0.0;
	R16(0, 3) = 0.0;
	R16(1, 0) = 0.0;
	R16(1, 1) = 1.0;
	R16(1, 2) = 0.0;
	R16(1, 3) = 0.0;
	R16(2, 0) = 0.0;
	R16(2, 1) = 0.0;
	R16(2, 2) = 1.0;
	R16(2, 3) = 0.0;
	R16(3, 0) = 0.0;
	R16(3, 1) = 0.0;
	R16(3, 2) = 0.0;
	R16(3, 3) = 1.0;
	std::vector<double> w16(row);
	w16[0] = 0.0;
	w16[1] = 0.0;
	w16[2] = 0.0;
	w16[3] = 0.0;

	Assign assignment16;
	assignment16.Map = R16;
	assignment16.b = w16;

// The transition label is   t8

	math::matrix<double> R17;
	row = 4;
	col = 4;
	R17.resize(row, col);
	R17(0, 0) = 1.0;
	R17(0, 1) = 0.0;
	R17(0, 2) = 0.0;
	R17(0, 3) = 0.0;
	R17(1, 0) = 0.0;
	R17(1, 1) = 1.0;
	R17(1, 2) = 0.0;
	R17(1, 3) = 0.0;
	R17(2, 0) = 0.0;
	R17(2, 1) = 0.0;
	R17(2, 2) = 1.0;
	R17(2, 3) = 0.0;
	R17(3, 0) = 0.0;
	R17(3, 1) = 0.0;
	R17(3, 2) = 0.0;
	R17(3, 3) = 1.0;
	std::vector<double> w17(row);
	w17[0] = 0.0;
	w17[1] = 0.0;
	w17[2] = 0.0;
	w17[3] = 0.0;

	Assign assignment17;
	assignment17.Map = R17;
	assignment17.b = w17;

// The transition label is   t5

	math::matrix<double> R18;
	row = 4;
	col = 4;
	R18.resize(row, col);
	R18(0, 0) = 1.0;
	R18(0, 1) = 0.0;
	R18(0, 2) = 0.0;
	R18(0, 3) = 0.0;
	R18(1, 0) = 0.0;
	R18(1, 1) = 1.0;
	R18(1, 2) = 0.0;
	R18(1, 3) = 0.0;
	R18(2, 0) = 0.0;
	R18(2, 1) = 0.0;
	R18(2, 2) = 1.0;
	R18(2, 3) = 0.0;
	R18(3, 0) = 0.0;
	R18(3, 1) = 0.0;
	R18(3, 2) = 0.0;
	R18(3, 3) = 1.0;
	std::vector<double> w18(row);
	w18[0] = 0.0;
	w18[1] = 0.0;
	w18[2] = 0.0;
	w18[3] = 0.0;

	Assign assignment18;
	assignment18.Map = R18;
	assignment18.b = w18;

// The transition label is   t4

	math::matrix<double> R19;
	row = 4;
	col = 4;
	R19.resize(row, col);
	R19(0, 0) = 1.0;
	R19(0, 1) = 0.0;
	R19(0, 2) = 0.0;
	R19(0, 3) = 0.0;
	R19(1, 0) = 0.0;
	R19(1, 1) = 1.0;
	R19(1, 2) = 0.0;
	R19(1, 3) = 0.0;
	R19(2, 0) = 0.0;
	R19(2, 1) = 0.0;
	R19(2, 2) = 1.0;
	R19(2, 3) = 0.0;
	R19(3, 0) = 0.0;
	R19(3, 1) = 0.0;
	R19(3, 2) = 0.0;
	R19(3, 3) = 1.0;
	std::vector<double> w19(row);
	w19[0] = 0.0;
	w19[1] = 0.0;
	w19[2] = 0.0;
	w19[3] = 0.0;

	Assign assignment19;
	assignment19.Map = R19;
	assignment19.b = w19;

	initial_polytope_I = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	transition t1(1, "t13", 2, 5, gaurd_polytope0, assignment0);
	transition t2(2, "t14", 2, 3, gaurd_polytope1, assignment1);
	transition t3(3, "t15", 2, 1, gaurd_polytope2, assignment2);
	transition t4(4, "t19", 3, 6, gaurd_polytope3, assignment3);
	transition t5(5, "t20", 3, 2, gaurd_polytope4, assignment4);
	transition t6(6, "t1", 4, 1, gaurd_polytope5, assignment5);
	transition t7(7, "t2", 4, 5, gaurd_polytope6, assignment6);
	transition t8(8, "t3", 4, 9, gaurd_polytope7, assignment7);
	transition t9(9, "t9", 5, 4, gaurd_polytope8, assignment8);
	transition t10(10, "t10", 5, 2, gaurd_polytope9, assignment9);
	transition t11(11, "t11", 5, 6, gaurd_polytope10, assignment10);
	transition t12(12, "t12", 5, 7, gaurd_polytope11, assignment11);
	transition t13(13, "t16", 6, 3, gaurd_polytope12, assignment12);
	transition t14(14, "t17", 6, 5, gaurd_polytope13, assignment13);
	transition t15(15, "t18", 6, 8, gaurd_polytope14, assignment14);
	transition t16(16, "t6", 7, 5, gaurd_polytope15, assignment15);
	transition t17(17, "t7", 7, 9, gaurd_polytope16, assignment16);
	transition t18(18, "t8", 7, 8, gaurd_polytope17, assignment17);
	transition t19(19, "t5", 9, 7, gaurd_polytope18, assignment18);
	transition t20(20, "t4", 9, 4, gaurd_polytope19, assignment19);

	std::list<transition> Out_Going_Trans_fromloc9;

	location l1(1, "loc9", system_dynamics0, invariant0, true,
			Out_Going_Trans_fromloc9);

	std::list<transition> Out_Going_Trans_fromloc5;

	Out_Going_Trans_fromloc5.push_back(t1);
	Out_Going_Trans_fromloc5.push_back(t2);
	Out_Going_Trans_fromloc5.push_back(t3);
	location l2(2, "loc5", system_dynamics1, invariant1, true,
			Out_Going_Trans_fromloc5);

	std::list<transition> Out_Going_Trans_fromloc7;

	Out_Going_Trans_fromloc7.push_back(t4);
	Out_Going_Trans_fromloc7.push_back(t5);
	location l3(3, "loc7", system_dynamics2, invariant2, true,
			Out_Going_Trans_fromloc7);

	std::list<transition> Out_Going_Trans_fromloc1;

	Out_Going_Trans_fromloc1.push_back(t6);
	Out_Going_Trans_fromloc1.push_back(t7);
	Out_Going_Trans_fromloc1.push_back(t8);
	location l4(4, "loc1", system_dynamics3, invariant3, true,
			Out_Going_Trans_fromloc1);

	std::list<transition> Out_Going_Trans_fromloc4;

	Out_Going_Trans_fromloc4.push_back(t9);
	Out_Going_Trans_fromloc4.push_back(t10);
	Out_Going_Trans_fromloc4.push_back(t11);
	Out_Going_Trans_fromloc4.push_back(t12);
	location l5(5, "loc4", system_dynamics4, invariant4, true,
			Out_Going_Trans_fromloc4);

	std::list<transition> Out_Going_Trans_fromloc6;

	Out_Going_Trans_fromloc6.push_back(t13);
	Out_Going_Trans_fromloc6.push_back(t14);
	Out_Going_Trans_fromloc6.push_back(t15);
	location l6(6, "loc6", system_dynamics5, invariant5, true,
			Out_Going_Trans_fromloc6);

	std::list<transition> Out_Going_Trans_fromloc3;

	Out_Going_Trans_fromloc3.push_back(t16);
	Out_Going_Trans_fromloc3.push_back(t17);
	Out_Going_Trans_fromloc3.push_back(t18);
	location l7(7, "loc3", system_dynamics6, invariant6, true,
			Out_Going_Trans_fromloc3);

	std::list<transition> Out_Going_Trans_fromloc8;

	location l8(8, "loc8", system_dynamics7, invariant7, true,
			Out_Going_Trans_fromloc8);

	std::list<transition> Out_Going_Trans_fromloc2;

	Out_Going_Trans_fromloc2.push_back(t19);
	Out_Going_Trans_fromloc2.push_back(t20);
	location l9(9, "loc2", system_dynamics8, invariant8, true,
			Out_Going_Trans_fromloc2);

	dim = initial_polytope_I->getSystemDimension();
	Hybrid_Automata.addInitial_Location(l1);
	Hybrid_Automata.addLocation(l1);
	Hybrid_Automata.addLocation(l2);
	Hybrid_Automata.addLocation(l3);
	Hybrid_Automata.addLocation(l4);
	Hybrid_Automata.addLocation(l5);
	Hybrid_Automata.addLocation(l6);
	Hybrid_Automata.addLocation(l7);
	Hybrid_Automata.addLocation(l8);
	Hybrid_Automata.addLocation(l9);
	Hybrid_Automata.setDimension(dim);

	unsigned int initial_location_id = 9; //the initial Location ID
	symbolic_states::ptr S; //null_pointer as there is no instantiation
	int transition_id = 0;	//initial location no transition taken yet
	initial_state::ptr I = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I, S,
					transition_id));

	init_state = I;

	dim = init_state->getInitialSet()->getSystemDimension();

	std::vector<std::vector<double> > newDirections;
	math::matrix<double> Real_Directions;
	unsigned int dir_nums;
	if (Directions_Type == BOX) {
		dir_nums = 2 * dim;
		newDirections = generate_axis_directions(dim);
	}
	if (Directions_Type == OCT) {
		dir_nums = 2 * dim * dim;
		newDirections = get_octagonal_directions(dim);
	}
	if (Directions_Type > 2) {
		dir_nums = Directions_Type;
		newDirections = math::uni_sphere(dir_nums, dim, 100, 0.0005);
	}
	get_ublas_matrix(newDirections, Real_Directions);
	row = dir_nums;
	col = dim;
	reach_parameters.Directions.resize(row, col);
	reach_parameters.Directions = Real_Directions;
	transition_iterations = iter_max;
	reach_parameters.Iterations = time_horizon / sampling_time;
	reach_parameters.TimeBound = time_horizon;
	reach_parameters.time_step = reach_parameters.TimeBound
			/ reach_parameters.Iterations;

}
