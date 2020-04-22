/*
 * NavigationTimed3by3.cpp
 *
 *  Created on: 22-May-2016
 *      Author: rajarshi
 */

#include "../../benchmarks/Navigation_Benchmark/NavigationTimed3by3.h"

void Set_NavTimed_Parameters(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;

	// ************* Section required for Forbidden Inputs *************
	unsigned int Directions_Type = 1;
	unsigned int iter_max = 35;
	double time_horizon = 10.0;
	double sampling_time = 0.01;
	unsigned int dim;
	size_type row, col;

	polytope::ptr initial_polytope_I, forbid_polytope;

	polytope::ptr invariant0, invariant1, invariant2, invariant3, invariant4,
			invariant5, invariant6, invariant7, invariant8;

	polytope::ptr guard_polytope0, guard_polytope1, guard_polytope2,
			guard_polytope3, guard_polytope4, guard_polytope5, guard_polytope6,
			guard_polytope7, guard_polytope8, guard_polytope9, guard_polytope10,
			guard_polytope11, guard_polytope12, guard_polytope13,
			guard_polytope14, guard_polytope15, guard_polytope16,
			guard_polytope17, guard_polytope18, guard_polytope19;

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
			invariantConstraintsMatrix8, guardConstraintsMatrix0,
			guardConstraintsMatrix1, guardConstraintsMatrix2,
			guardConstraintsMatrix3, guardConstraintsMatrix4,
			guardConstraintsMatrix5, guardConstraintsMatrix6,
			guardConstraintsMatrix7, guardConstraintsMatrix8,
			guardConstraintsMatrix9, guardConstraintsMatrix10,
			guardConstraintsMatrix11, guardConstraintsMatrix12,
			guardConstraintsMatrix13, guardConstraintsMatrix14,
			guardConstraintsMatrix15, guardConstraintsMatrix16,
			guardConstraintsMatrix17, guardConstraintsMatrix18,
			guardConstraintsMatrix19, A0matrix, A1matrix, A2matrix, A3matrix,
			A4matrix, A5matrix, A6matrix, A7matrix, A8matrix, B0matrix,
			B1matrix, B2matrix, B3matrix, B4matrix, B5matrix, B6matrix,
			B7matrix, B8matrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV0, boundValueV1, boundValueV2,
			boundValueV3, boundValueV4, boundValueV5, boundValueV6,
			boundValueV7, boundValueV8, C0, C1, C2, C3, C4, C5, C6, C7, C8,
			invariantBoundValue0, invariantBoundValue1, invariantBoundValue2,
			invariantBoundValue3, invariantBoundValue4, invariantBoundValue5,
			invariantBoundValue6, invariantBoundValue7, invariantBoundValue8,
			guardBoundValue0, guardBoundValue1, guardBoundValue2,
			guardBoundValue3, guardBoundValue4, guardBoundValue5,
			guardBoundValue6, guardBoundValue7, guardBoundValue8,
			guardBoundValue9, guardBoundValue10, guardBoundValue11,
			guardBoundValue12, guardBoundValue13, guardBoundValue14,
			guardBoundValue15, guardBoundValue16, guardBoundValue17,
			guardBoundValue18, guardBoundValue19, boundValueF;

	int boundSignI, invariantBoundSign, guardBoundSign, boundSignV;

	// The mode name is  loc9

	system_dynamics0.isEmptyMatrixA = true;

	system_dynamics0.isEmptyMatrixB = true;

	system_dynamics0.isEmptyC = true;

	invariant0 = polytope::ptr(new polytope());
	invariant0->setIsUniverse(true);

	row = 4;
	col = 5;
	ConstraintsMatrixV0.resize(row, col);
	ConstraintsMatrixV0(0, 0) = -1.0;
	ConstraintsMatrixV0(0, 1) = 0.0;
	ConstraintsMatrixV0(0, 2) = 0.0;
	ConstraintsMatrixV0(0, 3) = 0.0;
	ConstraintsMatrixV0(0, 4) = 0.0;
	ConstraintsMatrixV0(1, 0) = 1.0;
	ConstraintsMatrixV0(1, 1) = 0.0;
	ConstraintsMatrixV0(1, 2) = 0.0;
	ConstraintsMatrixV0(1, 3) = 0.0;
	ConstraintsMatrixV0(1, 4) = 0.0;
	ConstraintsMatrixV0(2, 0) = 0.0;
	ConstraintsMatrixV0(2, 1) = -1.0;
	ConstraintsMatrixV0(2, 2) = 0.0;
	ConstraintsMatrixV0(2, 3) = 0.0;
	ConstraintsMatrixV0(2, 4) = 0.0;
	ConstraintsMatrixV0(3, 0) = 0.0;
	ConstraintsMatrixV0(3, 1) = 1.0;
	ConstraintsMatrixV0(3, 2) = 0.0;
	ConstraintsMatrixV0(3, 3) = 0.0;
	ConstraintsMatrixV0(3, 4) = 0.0;

	boundValueV0.resize(row);
	boundValueV0[0] = -0.0;
	boundValueV0[1] = 1.0;
	boundValueV0[2] = -2.0;
	boundValueV0[3] = 3.0;
	boundSignV = 1;
	system_dynamics0.U = polytope::ptr(
			new polytope(ConstraintsMatrixV0, boundValueV0, boundSignV));

	// The mode name is  loc5

	row = 5;
	col = 5;
	A1matrix.resize(row, col);
	A1matrix(0, 0) = 0.0;
	A1matrix(0, 1) = 0.0;
	A1matrix(0, 2) = 1.0;
	A1matrix(0, 3) = 0.0;
	A1matrix(0, 4) = 0.0;
	A1matrix(1, 0) = 0.0;
	A1matrix(1, 1) = 0.0;
	A1matrix(1, 2) = 0.0;
	A1matrix(1, 3) = 1.0;
	A1matrix(1, 4) = 0.0;
	A1matrix(2, 0) = 0.0;
	A1matrix(2, 1) = 0.0;
	A1matrix(2, 2) = -1.2;
	A1matrix(2, 3) = 0.1;
	A1matrix(2, 4) = 0.0;
	A1matrix(3, 0) = 0.0;
	A1matrix(3, 1) = 0.0;
	A1matrix(3, 2) = 0.1;
	A1matrix(3, 3) = -1.2;
	A1matrix(3, 4) = 0.0;
	A1matrix(4, 0) = 0.0;
	A1matrix(4, 1) = 0.0;
	A1matrix(4, 2) = 0.0;
	A1matrix(4, 3) = 0.0;
	A1matrix(4, 4) = 0.0;
	system_dynamics1.isEmptyMatrixA = false;
	system_dynamics1.MatrixA = A1matrix;

	system_dynamics1.isEmptyMatrixB = true;

	C1.resize(row);
	C1[0] = 0.0;
	C1[1] = 0.0;
	C1[2] = 1.2;
	C1[3] = -0.1;
	C1[4] = 1.0;
	system_dynamics1.isEmptyC = false;
	system_dynamics1.C = C1;

	row = 4;
	col = 5;
	invariantConstraintsMatrix1.resize(row, col);
	invariantConstraintsMatrix1(0, 0) = -1.0;
	invariantConstraintsMatrix1(0, 1) = 0.0;
	invariantConstraintsMatrix1(0, 2) = 0.0;
	invariantConstraintsMatrix1(0, 3) = 0.0;
	invariantConstraintsMatrix1(0, 4) = 0.0;
	invariantConstraintsMatrix1(1, 0) = 1.0;
	invariantConstraintsMatrix1(1, 1) = 0.0;
	invariantConstraintsMatrix1(1, 2) = 0.0;
	invariantConstraintsMatrix1(1, 3) = 0.0;
	invariantConstraintsMatrix1(1, 4) = 0.0;
	invariantConstraintsMatrix1(2, 0) = 0.0;
	invariantConstraintsMatrix1(2, 1) = -1.0;
	invariantConstraintsMatrix1(2, 2) = 0.0;
	invariantConstraintsMatrix1(2, 3) = 0.0;
	invariantConstraintsMatrix1(2, 4) = 0.0;
	invariantConstraintsMatrix1(3, 0) = 0.0;
	invariantConstraintsMatrix1(3, 1) = 1.0;
	invariantConstraintsMatrix1(3, 2) = 0.0;
	invariantConstraintsMatrix1(3, 3) = 0.0;
	invariantConstraintsMatrix1(3, 4) = 0.0;

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

	row = 5;
	col = 5;
	A2matrix.resize(row, col);
	A2matrix(0, 0) = 0.0;
	A2matrix(0, 1) = 0.0;
	A2matrix(0, 2) = 1.0;
	A2matrix(0, 3) = 0.0;
	A2matrix(0, 4) = 0.0;
	A2matrix(1, 0) = 0.0;
	A2matrix(1, 1) = 0.0;
	A2matrix(1, 2) = 0.0;
	A2matrix(1, 3) = 1.0;
	A2matrix(1, 4) = 0.0;
	A2matrix(2, 0) = 0.0;
	A2matrix(2, 1) = 0.0;
	A2matrix(2, 2) = -1.2;
	A2matrix(2, 3) = 0.1;
	A2matrix(2, 4) = 0.0;
	A2matrix(3, 0) = 0.0;
	A2matrix(3, 1) = 0.0;
	A2matrix(3, 2) = 0.1;
	A2matrix(3, 3) = -1.2;
	A2matrix(3, 4) = 0.0;
	A2matrix(4, 0) = 0.0;
	A2matrix(4, 1) = 0.0;
	A2matrix(4, 2) = 0.0;
	A2matrix(4, 3) = 0.0;
	A2matrix(4, 4) = 0.0;
	system_dynamics2.isEmptyMatrixA = false;
	system_dynamics2.MatrixA = A2matrix;

	system_dynamics2.isEmptyMatrixB = true;

	C2.resize(row);
	C2[0] = 0.0;
	C2[1] = 0.0;
	C2[2] = 0.1;
	C2[3] = -1.2;
	C2[4] = 1.0;
	system_dynamics2.isEmptyC = false;
	system_dynamics2.C = C2;

	row = 4;
	col = 5;
	invariantConstraintsMatrix2.resize(row, col);
	invariantConstraintsMatrix2(0, 0) = -1.0;
	invariantConstraintsMatrix2(0, 1) = 0.0;
	invariantConstraintsMatrix2(0, 2) = 0.0;
	invariantConstraintsMatrix2(0, 3) = 0.0;
	invariantConstraintsMatrix2(0, 4) = 0.0;
	invariantConstraintsMatrix2(1, 0) = 1.0;
	invariantConstraintsMatrix2(1, 1) = 0.0;
	invariantConstraintsMatrix2(1, 2) = 0.0;
	invariantConstraintsMatrix2(1, 3) = 0.0;
	invariantConstraintsMatrix2(1, 4) = 0.0;
	invariantConstraintsMatrix2(2, 0) = 0.0;
	invariantConstraintsMatrix2(2, 1) = -1.0;
	invariantConstraintsMatrix2(2, 2) = 0.0;
	invariantConstraintsMatrix2(2, 3) = 0.0;
	invariantConstraintsMatrix2(2, 4) = 0.0;
	invariantConstraintsMatrix2(3, 0) = 0.0;
	invariantConstraintsMatrix2(3, 1) = 1.0;
	invariantConstraintsMatrix2(3, 2) = 0.0;
	invariantConstraintsMatrix2(3, 3) = 0.0;
	invariantConstraintsMatrix2(3, 4) = 0.0;

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

	row = 5;
	col = 5;
	A3matrix.resize(row, col);
	A3matrix(0, 0) = 0.0;
	A3matrix(0, 1) = 0.0;
	A3matrix(0, 2) = 1.0;
	A3matrix(0, 3) = 0.0;
	A3matrix(0, 4) = 0.0;
	A3matrix(1, 0) = 0.0;
	A3matrix(1, 1) = 0.0;
	A3matrix(1, 2) = 0.0;
	A3matrix(1, 3) = 1.0;
	A3matrix(1, 4) = 0.0;
	A3matrix(2, 0) = 0.0;
	A3matrix(2, 1) = 0.0;
	A3matrix(2, 2) = -1.2;
	A3matrix(2, 3) = 0.1;
	A3matrix(2, 4) = 0.0;
	A3matrix(3, 0) = 0.0;
	A3matrix(3, 1) = 0.0;
	A3matrix(3, 2) = 0.1;
	A3matrix(3, 3) = -1.2;
	A3matrix(3, 4) = 0.0;
	A3matrix(4, 0) = 0.0;
	A3matrix(4, 1) = 0.0;
	A3matrix(4, 2) = 0.0;
	A3matrix(4, 3) = 0.0;
	A3matrix(4, 4) = 0.0;
	system_dynamics3.isEmptyMatrixA = false;
	system_dynamics3.MatrixA = A3matrix;

	system_dynamics3.isEmptyMatrixB = true;

	C3.resize(row);
	C3[0] = 0.0;
	C3[1] = 0.0;
	C3[2] = 1.2;
	C3[3] = -0.1;
	C3[4] = 1.0;
	system_dynamics3.isEmptyC = false;
	system_dynamics3.C = C3;

	row = 4;
	col = 5;
	invariantConstraintsMatrix3.resize(row, col);
	invariantConstraintsMatrix3(0, 0) = -1.0;
	invariantConstraintsMatrix3(0, 1) = 0.0;
	invariantConstraintsMatrix3(0, 2) = 0.0;
	invariantConstraintsMatrix3(0, 3) = 0.0;
	invariantConstraintsMatrix3(0, 4) = 0.0;
	invariantConstraintsMatrix3(1, 0) = 1.0;
	invariantConstraintsMatrix3(1, 1) = 0.0;
	invariantConstraintsMatrix3(1, 2) = 0.0;
	invariantConstraintsMatrix3(1, 3) = 0.0;
	invariantConstraintsMatrix3(1, 4) = 0.0;
	invariantConstraintsMatrix3(2, 0) = 0.0;
	invariantConstraintsMatrix3(2, 1) = -1.0;
	invariantConstraintsMatrix3(2, 2) = 0.0;
	invariantConstraintsMatrix3(2, 3) = 0.0;
	invariantConstraintsMatrix3(2, 4) = 0.0;
	invariantConstraintsMatrix3(3, 0) = 0.0;
	invariantConstraintsMatrix3(3, 1) = 1.0;
	invariantConstraintsMatrix3(3, 2) = 0.0;
	invariantConstraintsMatrix3(3, 3) = 0.0;
	invariantConstraintsMatrix3(3, 4) = 0.0;

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

	row = 5;
	col = 5;
	A4matrix.resize(row, col);
	A4matrix(0, 0) = 0.0;
	A4matrix(0, 1) = 0.0;
	A4matrix(0, 2) = 1.0;
	A4matrix(0, 3) = 0.0;
	A4matrix(0, 4) = 0.0;
	A4matrix(1, 0) = 0.0;
	A4matrix(1, 1) = 0.0;
	A4matrix(1, 2) = 0.0;
	A4matrix(1, 3) = 1.0;
	A4matrix(1, 4) = 0.0;
	A4matrix(2, 0) = 0.0;
	A4matrix(2, 1) = 0.0;
	A4matrix(2, 2) = -1.2;
	A4matrix(2, 3) = 0.1;
	A4matrix(2, 4) = 0.0;
	A4matrix(3, 0) = 0.0;
	A4matrix(3, 1) = 0.0;
	A4matrix(3, 2) = 0.1;
	A4matrix(3, 3) = -1.2;
	A4matrix(3, 4) = 0.0;
	A4matrix(4, 0) = 0.0;
	A4matrix(4, 1) = 0.0;
	A4matrix(4, 2) = 0.0;
	A4matrix(4, 3) = 0.0;
	A4matrix(4, 4) = 0.0;
	system_dynamics4.isEmptyMatrixA = false;
	system_dynamics4.MatrixA = A4matrix;

	system_dynamics4.isEmptyMatrixB = true;

	C4.resize(row);
	C4[0] = 0.0;
	C4[1] = 0.0;
	C4[2] = 1.2;
	C4[3] = -0.1;
	C4[4] = 1.0;
	system_dynamics4.isEmptyC = false;
	system_dynamics4.C = C4;

	row = 4;
	col = 5;
	invariantConstraintsMatrix4.resize(row, col);
	invariantConstraintsMatrix4(0, 0) = -1.0;
	invariantConstraintsMatrix4(0, 1) = 0.0;
	invariantConstraintsMatrix4(0, 2) = 0.0;
	invariantConstraintsMatrix4(0, 3) = 0.0;
	invariantConstraintsMatrix4(0, 4) = 0.0;
	invariantConstraintsMatrix4(1, 0) = 1.0;
	invariantConstraintsMatrix4(1, 1) = 0.0;
	invariantConstraintsMatrix4(1, 2) = 0.0;
	invariantConstraintsMatrix4(1, 3) = 0.0;
	invariantConstraintsMatrix4(1, 4) = 0.0;
	invariantConstraintsMatrix4(2, 0) = 0.0;
	invariantConstraintsMatrix4(2, 1) = -1.0;
	invariantConstraintsMatrix4(2, 2) = 0.0;
	invariantConstraintsMatrix4(2, 3) = 0.0;
	invariantConstraintsMatrix4(2, 4) = 0.0;
	invariantConstraintsMatrix4(3, 0) = 0.0;
	invariantConstraintsMatrix4(3, 1) = 1.0;
	invariantConstraintsMatrix4(3, 2) = 0.0;
	invariantConstraintsMatrix4(3, 3) = 0.0;
	invariantConstraintsMatrix4(3, 4) = 0.0;

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

	row = 5;
	col = 5;
	A5matrix.resize(row, col);
	A5matrix(0, 0) = 0.0;
	A5matrix(0, 1) = 0.0;
	A5matrix(0, 2) = 1.0;
	A5matrix(0, 3) = 0.0;
	A5matrix(0, 4) = 0.0;
	A5matrix(1, 0) = 0.0;
	A5matrix(1, 1) = 0.0;
	A5matrix(1, 2) = 0.0;
	A5matrix(1, 3) = 1.0;
	A5matrix(1, 4) = 0.0;
	A5matrix(2, 0) = 0.0;
	A5matrix(2, 1) = 0.0;
	A5matrix(2, 2) = -1.2;
	A5matrix(2, 3) = 0.1;
	A5matrix(2, 4) = 0.0;
	A5matrix(3, 0) = 0.0;
	A5matrix(3, 1) = 0.0;
	A5matrix(3, 2) = 0.1;
	A5matrix(3, 3) = -1.2;
	A5matrix(3, 4) = 0.0;
	A5matrix(4, 0) = 0.0;
	A5matrix(4, 1) = 0.0;
	A5matrix(4, 2) = 0.0;
	A5matrix(4, 3) = 0.0;
	A5matrix(4, 4) = 0.0;
	system_dynamics5.isEmptyMatrixA = false;
	system_dynamics5.MatrixA = A5matrix;

	system_dynamics5.isEmptyMatrixB = true;

	C5.resize(row);
	C5[0] = 0.0;
	C5[1] = 0.0;
	C5[2] = 0.1;
	C5[3] = -1.2;
	C5[4] = 1.0;
	system_dynamics5.isEmptyC = false;
	system_dynamics5.C = C5;

	row = 4;
	col = 5;
	invariantConstraintsMatrix5.resize(row, col);
	invariantConstraintsMatrix5(0, 0) = -1.0;
	invariantConstraintsMatrix5(0, 1) = 0.0;
	invariantConstraintsMatrix5(0, 2) = 0.0;
	invariantConstraintsMatrix5(0, 3) = 0.0;
	invariantConstraintsMatrix5(0, 4) = 0.0;
	invariantConstraintsMatrix5(1, 0) = 1.0;
	invariantConstraintsMatrix5(1, 1) = 0.0;
	invariantConstraintsMatrix5(1, 2) = 0.0;
	invariantConstraintsMatrix5(1, 3) = 0.0;
	invariantConstraintsMatrix5(1, 4) = 0.0;
	invariantConstraintsMatrix5(2, 0) = 0.0;
	invariantConstraintsMatrix5(2, 1) = -1.0;
	invariantConstraintsMatrix5(2, 2) = 0.0;
	invariantConstraintsMatrix5(2, 3) = 0.0;
	invariantConstraintsMatrix5(2, 4) = 0.0;
	invariantConstraintsMatrix5(3, 0) = 0.0;
	invariantConstraintsMatrix5(3, 1) = 1.0;
	invariantConstraintsMatrix5(3, 2) = 0.0;
	invariantConstraintsMatrix5(3, 3) = 0.0;
	invariantConstraintsMatrix5(3, 4) = 0.0;

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

	row = 5;
	col = 5;
	A6matrix.resize(row, col);
	A6matrix(0, 0) = 0.0;
	A6matrix(0, 1) = 0.0;
	A6matrix(0, 2) = 1.0;
	A6matrix(0, 3) = 0.0;
	A6matrix(0, 4) = 0.0;
	A6matrix(1, 0) = 0.0;
	A6matrix(1, 1) = 0.0;
	A6matrix(1, 2) = 0.0;
	A6matrix(1, 3) = 1.0;
	A6matrix(1, 4) = 0.0;
	A6matrix(2, 0) = 0.0;
	A6matrix(2, 1) = 0.0;
	A6matrix(2, 2) = -1.2;
	A6matrix(2, 3) = 0.1;
	A6matrix(2, 4) = 0.0;
	A6matrix(3, 0) = 0.0;
	A6matrix(3, 1) = 0.0;
	A6matrix(3, 2) = 0.1;
	A6matrix(3, 3) = -1.2;
	A6matrix(3, 4) = 0.0;
	A6matrix(4, 0) = 0.0;
	A6matrix(4, 1) = 0.0;
	A6matrix(4, 2) = 0.0;
	A6matrix(4, 3) = 0.0;
	A6matrix(4, 4) = 0.0;
	system_dynamics6.isEmptyMatrixA = false;
	system_dynamics6.MatrixA = A6matrix;

	system_dynamics6.isEmptyMatrixB = true;

	C6.resize(row);
	C6[0] = 0.0;
	C6[1] = 0.0;
	C6[2] = 0.777821;
	C6[3] = 0.777821;
	C6[4] = 1.0;
	system_dynamics6.isEmptyC = false;
	system_dynamics6.C = C6;

	row = 4;
	col = 5;
	invariantConstraintsMatrix6.resize(row, col);
	invariantConstraintsMatrix6(0, 0) = -1.0;
	invariantConstraintsMatrix6(0, 1) = 0.0;
	invariantConstraintsMatrix6(0, 2) = 0.0;
	invariantConstraintsMatrix6(0, 3) = 0.0;
	invariantConstraintsMatrix6(0, 4) = 0.0;
	invariantConstraintsMatrix6(1, 0) = 1.0;
	invariantConstraintsMatrix6(1, 1) = 0.0;
	invariantConstraintsMatrix6(1, 2) = 0.0;
	invariantConstraintsMatrix6(1, 3) = 0.0;
	invariantConstraintsMatrix6(1, 4) = 0.0;
	invariantConstraintsMatrix6(2, 0) = 0.0;
	invariantConstraintsMatrix6(2, 1) = -1.0;
	invariantConstraintsMatrix6(2, 2) = 0.0;
	invariantConstraintsMatrix6(2, 3) = 0.0;
	invariantConstraintsMatrix6(2, 4) = 0.0;
	invariantConstraintsMatrix6(3, 0) = 0.0;
	invariantConstraintsMatrix6(3, 1) = 1.0;
	invariantConstraintsMatrix6(3, 2) = 0.0;
	invariantConstraintsMatrix6(3, 3) = 0.0;
	invariantConstraintsMatrix6(3, 4) = 0.0;

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
	col = 5;
	ConstraintsMatrixV7.resize(row, col);
	ConstraintsMatrixV7(0, 0) = -1.0;
	ConstraintsMatrixV7(0, 1) = 0.0;
	ConstraintsMatrixV7(0, 2) = 0.0;
	ConstraintsMatrixV7(0, 3) = 0.0;
	ConstraintsMatrixV7(0, 4) = 0.0;
	ConstraintsMatrixV7(1, 0) = 1.0;
	ConstraintsMatrixV7(1, 1) = 0.0;
	ConstraintsMatrixV7(1, 2) = 0.0;
	ConstraintsMatrixV7(1, 3) = 0.0;
	ConstraintsMatrixV7(1, 4) = 0.0;
	ConstraintsMatrixV7(2, 0) = 0.0;
	ConstraintsMatrixV7(2, 1) = -1.0;
	ConstraintsMatrixV7(2, 2) = 0.0;
	ConstraintsMatrixV7(2, 3) = 0.0;
	ConstraintsMatrixV7(2, 4) = 0.0;
	ConstraintsMatrixV7(3, 0) = 0.0;
	ConstraintsMatrixV7(3, 1) = 1.0;
	ConstraintsMatrixV7(3, 2) = 0.0;
	ConstraintsMatrixV7(3, 3) = 0.0;
	ConstraintsMatrixV7(3, 4) = 0.0;

	boundValueV7.resize(row);
	boundValueV7[0] = -2.0;
	boundValueV7[1] = 3.0;
	boundValueV7[2] = -0.0;
	boundValueV7[3] = 1.0;
	boundSignV = 1;
	system_dynamics7.U = polytope::ptr(
			new polytope(ConstraintsMatrixV7, boundValueV7, boundSignV));

	// The mode name is  loc2

	row = 5;
	col = 5;
	A8matrix.resize(row, col);
	A8matrix(0, 0) = 0.0;
	A8matrix(0, 1) = 0.0;
	A8matrix(0, 2) = 1.0;
	A8matrix(0, 3) = 0.0;
	A8matrix(0, 4) = 0.0;
	A8matrix(1, 0) = 0.0;
	A8matrix(1, 1) = 0.0;
	A8matrix(1, 2) = 0.0;
	A8matrix(1, 3) = 1.0;
	A8matrix(1, 4) = 0.0;
	A8matrix(2, 0) = 0.0;
	A8matrix(2, 1) = 0.0;
	A8matrix(2, 2) = -1.2;
	A8matrix(2, 3) = 0.1;
	A8matrix(2, 4) = 0.0;
	A8matrix(3, 0) = 0.0;
	A8matrix(3, 1) = 0.0;
	A8matrix(3, 2) = 0.1;
	A8matrix(3, 3) = -1.2;
	A8matrix(3, 4) = 0.0;
	A8matrix(4, 0) = 0.0;
	A8matrix(4, 1) = 0.0;
	A8matrix(4, 2) = 0.0;
	A8matrix(4, 3) = 0.0;
	A8matrix(4, 4) = 0.0;
	system_dynamics8.isEmptyMatrixA = false;
	system_dynamics8.MatrixA = A8matrix;

	system_dynamics8.isEmptyMatrixB = true;

	C8.resize(row);
	C8[0] = 0.0;
	C8[1] = 0.0;
	C8[2] = 0.777821;
	C8[3] = 0.777821;
	C8[4] = 1.0;
	system_dynamics8.isEmptyC = false;
	system_dynamics8.C = C8;

	row = 4;
	col = 5;
	invariantConstraintsMatrix8.resize(row, col);
	invariantConstraintsMatrix8(0, 0) = -1.0;
	invariantConstraintsMatrix8(0, 1) = 0.0;
	invariantConstraintsMatrix8(0, 2) = 0.0;
	invariantConstraintsMatrix8(0, 3) = 0.0;
	invariantConstraintsMatrix8(0, 4) = 0.0;
	invariantConstraintsMatrix8(1, 0) = 1.0;
	invariantConstraintsMatrix8(1, 1) = 0.0;
	invariantConstraintsMatrix8(1, 2) = 0.0;
	invariantConstraintsMatrix8(1, 3) = 0.0;
	invariantConstraintsMatrix8(1, 4) = 0.0;
	invariantConstraintsMatrix8(2, 0) = 0.0;
	invariantConstraintsMatrix8(2, 1) = -1.0;
	invariantConstraintsMatrix8(2, 2) = 0.0;
	invariantConstraintsMatrix8(2, 3) = 0.0;
	invariantConstraintsMatrix8(2, 4) = 0.0;
	invariantConstraintsMatrix8(3, 0) = 0.0;
	invariantConstraintsMatrix8(3, 1) = 1.0;
	invariantConstraintsMatrix8(3, 2) = 0.0;
	invariantConstraintsMatrix8(3, 3) = 0.0;
	invariantConstraintsMatrix8(3, 4) = 0.0;

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

	row = 10;
	col = 5;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(0, 2) = 0;
	ConstraintsMatrixI(0, 3) = 0;
	ConstraintsMatrixI(0, 4) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(1, 2) = 0;
	ConstraintsMatrixI(1, 3) = 0;
	ConstraintsMatrixI(1, 4) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(2, 2) = 0;
	ConstraintsMatrixI(2, 3) = 0;
	ConstraintsMatrixI(2, 4) = 0;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;
	ConstraintsMatrixI(3, 2) = 0;
	ConstraintsMatrixI(3, 3) = 0;
	ConstraintsMatrixI(3, 4) = 0;
	ConstraintsMatrixI(4, 0) = 0;
	ConstraintsMatrixI(4, 1) = 0;
	ConstraintsMatrixI(4, 2) = 1;
	ConstraintsMatrixI(4, 3) = 0;
	ConstraintsMatrixI(4, 4) = 0;
	ConstraintsMatrixI(5, 0) = 0;
	ConstraintsMatrixI(5, 1) = 0;
	ConstraintsMatrixI(5, 2) = -1;
	ConstraintsMatrixI(5, 3) = 0;
	ConstraintsMatrixI(5, 4) = 0;
	ConstraintsMatrixI(6, 0) = 0;
	ConstraintsMatrixI(6, 1) = 0;
	ConstraintsMatrixI(6, 2) = 0;
	ConstraintsMatrixI(6, 3) = 1;
	ConstraintsMatrixI(6, 4) = 0;
	ConstraintsMatrixI(7, 0) = 0;
	ConstraintsMatrixI(7, 1) = 0;
	ConstraintsMatrixI(7, 2) = 0;
	ConstraintsMatrixI(7, 3) = -1;
	ConstraintsMatrixI(7, 4) = 0;
	ConstraintsMatrixI(8, 0) = 0;
	ConstraintsMatrixI(8, 1) = 0;
	ConstraintsMatrixI(8, 2) = 0;
	ConstraintsMatrixI(8, 3) = 0;
	ConstraintsMatrixI(8, 4) = 1;
	ConstraintsMatrixI(9, 0) = 0;
	ConstraintsMatrixI(9, 1) = 0;
	ConstraintsMatrixI(9, 2) = 0;
	ConstraintsMatrixI(9, 3) = 0;
	ConstraintsMatrixI(9, 4) = -1;
	boundValueI.resize(row);
	boundValueI[0] = 0.7;
	boundValueI[1] = -0.2;
	boundValueI[2] = 0.5;
	boundValueI[3] = -0.2;
	boundValueI[4] = 0.8;
	boundValueI[5] = -0.8;
	boundValueI[6] = 0;
	boundValueI[7] = 0;
	boundValueI[8] = 0;
	boundValueI[9] = 0;
	boundSignI = 1;

	// The transition label ist13

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix0.resize(row, col);
	guardConstraintsMatrix0(0, 0) = -1.0;
	guardConstraintsMatrix0(0, 1) = 0.0;
	guardConstraintsMatrix0(0, 2) = 0.0;
	guardConstraintsMatrix0(0, 3) = 0.0;
	guardConstraintsMatrix0(0, 4) = 0.0;
	guardConstraintsMatrix0(1, 0) = 1.0;
	guardConstraintsMatrix0(1, 1) = 0.0;
	guardConstraintsMatrix0(1, 2) = 0.0;
	guardConstraintsMatrix0(1, 3) = 0.0;
	guardConstraintsMatrix0(1, 4) = 0.0;
	guardConstraintsMatrix0(2, 0) = 0.0;
	guardConstraintsMatrix0(2, 1) = -1.0;
	guardConstraintsMatrix0(2, 2) = 0.0;
	guardConstraintsMatrix0(2, 3) = 0.0;
	guardConstraintsMatrix0(2, 4) = 0.0;
	guardConstraintsMatrix0(3, 0) = 0.0;
	guardConstraintsMatrix0(3, 1) = 1.0;
	guardConstraintsMatrix0(3, 2) = 0.0;
	guardConstraintsMatrix0(3, 3) = 0.0;
	guardConstraintsMatrix0(3, 4) = 0.0;
	guardConstraintsMatrix0(4, 0) = 0.0;
	guardConstraintsMatrix0(4, 1) = 0.0;
	guardConstraintsMatrix0(4, 2) = -1.0;
	guardConstraintsMatrix0(4, 3) = 0.0;
	guardConstraintsMatrix0(4, 4) = 0.0;
	guardConstraintsMatrix0(5, 0) = 0.0;
	guardConstraintsMatrix0(5, 1) = 0.0;
	guardConstraintsMatrix0(5, 2) = 1.0;
	guardConstraintsMatrix0(5, 3) = 0.0;
	guardConstraintsMatrix0(5, 4) = 0.0;
	guardConstraintsMatrix0(6, 0) = 0.0;
	guardConstraintsMatrix0(6, 1) = 0.0;
	guardConstraintsMatrix0(6, 2) = 0.0;
	guardConstraintsMatrix0(6, 3) = -1.0;
	guardConstraintsMatrix0(6, 4) = 0.0;
	guardConstraintsMatrix0(7, 0) = 0.0;
	guardConstraintsMatrix0(7, 1) = 0.0;
	guardConstraintsMatrix0(7, 2) = 0.0;
	guardConstraintsMatrix0(7, 3) = 1.0;
	guardConstraintsMatrix0(7, 4) = 0.0;

	guardBoundValue0.resize(row);
	guardBoundValue0[0] = -1.0;
	guardBoundValue0[1] = 2.0;
	guardBoundValue0[2] = -2.0;
	guardBoundValue0[3] = 2.0;
	guardBoundValue0[4] = 1000.0;
	guardBoundValue0[5] = 1000.0;
	guardBoundValue0[6] = 1000.0;
	guardBoundValue0[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope0 = polytope::ptr(
			new polytope(guardConstraintsMatrix0, guardBoundValue0,
					guardBoundSign));

	// The transition label ist14

	// Original guard: x1 = 2 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix1.resize(row, col);
	guardConstraintsMatrix1(0, 0) = -1.0;
	guardConstraintsMatrix1(0, 1) = 0.0;
	guardConstraintsMatrix1(0, 2) = 0.0;
	guardConstraintsMatrix1(0, 3) = 0.0;
	guardConstraintsMatrix1(0, 4) = 0.0;
	guardConstraintsMatrix1(1, 0) = 1.0;
	guardConstraintsMatrix1(1, 1) = 0.0;
	guardConstraintsMatrix1(1, 2) = 0.0;
	guardConstraintsMatrix1(1, 3) = 0.0;
	guardConstraintsMatrix1(1, 4) = 0.0;
	guardConstraintsMatrix1(2, 0) = 0.0;
	guardConstraintsMatrix1(2, 1) = -1.0;
	guardConstraintsMatrix1(2, 2) = 0.0;
	guardConstraintsMatrix1(2, 3) = 0.0;
	guardConstraintsMatrix1(2, 4) = 0.0;
	guardConstraintsMatrix1(3, 0) = 0.0;
	guardConstraintsMatrix1(3, 1) = 1.0;
	guardConstraintsMatrix1(3, 2) = 0.0;
	guardConstraintsMatrix1(3, 3) = 0.0;
	guardConstraintsMatrix1(3, 4) = 0.0;
	guardConstraintsMatrix1(4, 0) = 0.0;
	guardConstraintsMatrix1(4, 1) = 0.0;
	guardConstraintsMatrix1(4, 2) = -1.0;
	guardConstraintsMatrix1(4, 3) = 0.0;
	guardConstraintsMatrix1(4, 4) = 0.0;
	guardConstraintsMatrix1(5, 0) = 0.0;
	guardConstraintsMatrix1(5, 1) = 0.0;
	guardConstraintsMatrix1(5, 2) = 1.0;
	guardConstraintsMatrix1(5, 3) = 0.0;
	guardConstraintsMatrix1(5, 4) = 0.0;
	guardConstraintsMatrix1(6, 0) = 0.0;
	guardConstraintsMatrix1(6, 1) = 0.0;
	guardConstraintsMatrix1(6, 2) = 0.0;
	guardConstraintsMatrix1(6, 3) = -1.0;
	guardConstraintsMatrix1(6, 4) = 0.0;
	guardConstraintsMatrix1(7, 0) = 0.0;
	guardConstraintsMatrix1(7, 1) = 0.0;
	guardConstraintsMatrix1(7, 2) = 0.0;
	guardConstraintsMatrix1(7, 3) = 1.0;
	guardConstraintsMatrix1(7, 4) = 0.0;

	guardBoundValue1.resize(row);
	guardBoundValue1[0] = -2.0;
	guardBoundValue1[1] = 2.0;
	guardBoundValue1[2] = -2.0;
	guardBoundValue1[3] = 3.0;
	guardBoundValue1[4] = 1000.0;
	guardBoundValue1[5] = 1000.0;
	guardBoundValue1[6] = 1000.0;
	guardBoundValue1[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope1 = polytope::ptr(
			new polytope(guardConstraintsMatrix1, guardBoundValue1,
					guardBoundSign));

	// The transition label ist15

	// Original guard: x1 = 1 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix2.resize(row, col);
	guardConstraintsMatrix2(0, 0) = -1.0;
	guardConstraintsMatrix2(0, 1) = 0.0;
	guardConstraintsMatrix2(0, 2) = 0.0;
	guardConstraintsMatrix2(0, 3) = 0.0;
	guardConstraintsMatrix2(0, 4) = 0.0;
	guardConstraintsMatrix2(1, 0) = 1.0;
	guardConstraintsMatrix2(1, 1) = 0.0;
	guardConstraintsMatrix2(1, 2) = 0.0;
	guardConstraintsMatrix2(1, 3) = 0.0;
	guardConstraintsMatrix2(1, 4) = 0.0;
	guardConstraintsMatrix2(2, 0) = 0.0;
	guardConstraintsMatrix2(2, 1) = -1.0;
	guardConstraintsMatrix2(2, 2) = 0.0;
	guardConstraintsMatrix2(2, 3) = 0.0;
	guardConstraintsMatrix2(2, 4) = 0.0;
	guardConstraintsMatrix2(3, 0) = 0.0;
	guardConstraintsMatrix2(3, 1) = 1.0;
	guardConstraintsMatrix2(3, 2) = 0.0;
	guardConstraintsMatrix2(3, 3) = 0.0;
	guardConstraintsMatrix2(3, 4) = 0.0;
	guardConstraintsMatrix2(4, 0) = 0.0;
	guardConstraintsMatrix2(4, 1) = 0.0;
	guardConstraintsMatrix2(4, 2) = -1.0;
	guardConstraintsMatrix2(4, 3) = 0.0;
	guardConstraintsMatrix2(4, 4) = 0.0;
	guardConstraintsMatrix2(5, 0) = 0.0;
	guardConstraintsMatrix2(5, 1) = 0.0;
	guardConstraintsMatrix2(5, 2) = 1.0;
	guardConstraintsMatrix2(5, 3) = 0.0;
	guardConstraintsMatrix2(5, 4) = 0.0;
	guardConstraintsMatrix2(6, 0) = 0.0;
	guardConstraintsMatrix2(6, 1) = 0.0;
	guardConstraintsMatrix2(6, 2) = 0.0;
	guardConstraintsMatrix2(6, 3) = -1.0;
	guardConstraintsMatrix2(6, 4) = 0.0;
	guardConstraintsMatrix2(7, 0) = 0.0;
	guardConstraintsMatrix2(7, 1) = 0.0;
	guardConstraintsMatrix2(7, 2) = 0.0;
	guardConstraintsMatrix2(7, 3) = 1.0;
	guardConstraintsMatrix2(7, 4) = 0.0;

	guardBoundValue2.resize(row);
	guardBoundValue2[0] = -1.0;
	guardBoundValue2[1] = 1.0;
	guardBoundValue2[2] = -2.0;
	guardBoundValue2[3] = 3.0;
	guardBoundValue2[4] = 1000.0;
	guardBoundValue2[5] = 1000.0;
	guardBoundValue2[6] = 1000.0;
	guardBoundValue2[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope2 = polytope::ptr(
			new polytope(guardConstraintsMatrix2, guardBoundValue2,
					guardBoundSign));

	// The transition label ist19

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix3.resize(row, col);
	guardConstraintsMatrix3(0, 0) = -1.0;
	guardConstraintsMatrix3(0, 1) = 0.0;
	guardConstraintsMatrix3(0, 2) = 0.0;
	guardConstraintsMatrix3(0, 3) = 0.0;
	guardConstraintsMatrix3(0, 4) = 0.0;
	guardConstraintsMatrix3(1, 0) = 1.0;
	guardConstraintsMatrix3(1, 1) = 0.0;
	guardConstraintsMatrix3(1, 2) = 0.0;
	guardConstraintsMatrix3(1, 3) = 0.0;
	guardConstraintsMatrix3(1, 4) = 0.0;
	guardConstraintsMatrix3(2, 0) = 0.0;
	guardConstraintsMatrix3(2, 1) = -1.0;
	guardConstraintsMatrix3(2, 2) = 0.0;
	guardConstraintsMatrix3(2, 3) = 0.0;
	guardConstraintsMatrix3(2, 4) = 0.0;
	guardConstraintsMatrix3(3, 0) = 0.0;
	guardConstraintsMatrix3(3, 1) = 1.0;
	guardConstraintsMatrix3(3, 2) = 0.0;
	guardConstraintsMatrix3(3, 3) = 0.0;
	guardConstraintsMatrix3(3, 4) = 0.0;
	guardConstraintsMatrix3(4, 0) = 0.0;
	guardConstraintsMatrix3(4, 1) = 0.0;
	guardConstraintsMatrix3(4, 2) = -1.0;
	guardConstraintsMatrix3(4, 3) = 0.0;
	guardConstraintsMatrix3(4, 4) = 0.0;
	guardConstraintsMatrix3(5, 0) = 0.0;
	guardConstraintsMatrix3(5, 1) = 0.0;
	guardConstraintsMatrix3(5, 2) = 1.0;
	guardConstraintsMatrix3(5, 3) = 0.0;
	guardConstraintsMatrix3(5, 4) = 0.0;
	guardConstraintsMatrix3(6, 0) = 0.0;
	guardConstraintsMatrix3(6, 1) = 0.0;
	guardConstraintsMatrix3(6, 2) = 0.0;
	guardConstraintsMatrix3(6, 3) = -1.0;
	guardConstraintsMatrix3(6, 4) = 0.0;
	guardConstraintsMatrix3(7, 0) = 0.0;
	guardConstraintsMatrix3(7, 1) = 0.0;
	guardConstraintsMatrix3(7, 2) = 0.0;
	guardConstraintsMatrix3(7, 3) = 1.0;
	guardConstraintsMatrix3(7, 4) = 0.0;

	guardBoundValue3.resize(row);
	guardBoundValue3[0] = -2.0;
	guardBoundValue3[1] = 3.0;
	guardBoundValue3[2] = -2.0;
	guardBoundValue3[3] = 2.0;
	guardBoundValue3[4] = 1000.0;
	guardBoundValue3[5] = 1000.0;
	guardBoundValue3[6] = 1000.0;
	guardBoundValue3[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope3 = polytope::ptr(
			new polytope(guardConstraintsMatrix3, guardBoundValue3,
					guardBoundSign));

	// The transition label ist20

	// Original guard: x1 = 2 & 2 <= x2 & x2 <= 3 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix4.resize(row, col);
	guardConstraintsMatrix4(0, 0) = -1.0;
	guardConstraintsMatrix4(0, 1) = 0.0;
	guardConstraintsMatrix4(0, 2) = 0.0;
	guardConstraintsMatrix4(0, 3) = 0.0;
	guardConstraintsMatrix4(0, 4) = 0.0;
	guardConstraintsMatrix4(1, 0) = 1.0;
	guardConstraintsMatrix4(1, 1) = 0.0;
	guardConstraintsMatrix4(1, 2) = 0.0;
	guardConstraintsMatrix4(1, 3) = 0.0;
	guardConstraintsMatrix4(1, 4) = 0.0;
	guardConstraintsMatrix4(2, 0) = 0.0;
	guardConstraintsMatrix4(2, 1) = -1.0;
	guardConstraintsMatrix4(2, 2) = 0.0;
	guardConstraintsMatrix4(2, 3) = 0.0;
	guardConstraintsMatrix4(2, 4) = 0.0;
	guardConstraintsMatrix4(3, 0) = 0.0;
	guardConstraintsMatrix4(3, 1) = 1.0;
	guardConstraintsMatrix4(3, 2) = 0.0;
	guardConstraintsMatrix4(3, 3) = 0.0;
	guardConstraintsMatrix4(3, 4) = 0.0;
	guardConstraintsMatrix4(4, 0) = 0.0;
	guardConstraintsMatrix4(4, 1) = 0.0;
	guardConstraintsMatrix4(4, 2) = -1.0;
	guardConstraintsMatrix4(4, 3) = 0.0;
	guardConstraintsMatrix4(4, 4) = 0.0;
	guardConstraintsMatrix4(5, 0) = 0.0;
	guardConstraintsMatrix4(5, 1) = 0.0;
	guardConstraintsMatrix4(5, 2) = 1.0;
	guardConstraintsMatrix4(5, 3) = 0.0;
	guardConstraintsMatrix4(5, 4) = 0.0;
	guardConstraintsMatrix4(6, 0) = 0.0;
	guardConstraintsMatrix4(6, 1) = 0.0;
	guardConstraintsMatrix4(6, 2) = 0.0;
	guardConstraintsMatrix4(6, 3) = -1.0;
	guardConstraintsMatrix4(6, 4) = 0.0;
	guardConstraintsMatrix4(7, 0) = 0.0;
	guardConstraintsMatrix4(7, 1) = 0.0;
	guardConstraintsMatrix4(7, 2) = 0.0;
	guardConstraintsMatrix4(7, 3) = 1.0;
	guardConstraintsMatrix4(7, 4) = 0.0;

	guardBoundValue4.resize(row);
	guardBoundValue4[0] = -2.0;
	guardBoundValue4[1] = 2.0;
	guardBoundValue4[2] = -2.0;
	guardBoundValue4[3] = 3.0;
	guardBoundValue4[4] = 1000.0;
	guardBoundValue4[5] = 1000.0;
	guardBoundValue4[6] = 1000.0;
	guardBoundValue4[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope4 = polytope::ptr(
			new polytope(guardConstraintsMatrix4, guardBoundValue4,
					guardBoundSign));

	// The transition label ist1

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix5.resize(row, col);
	guardConstraintsMatrix5(0, 0) = -1.0;
	guardConstraintsMatrix5(0, 1) = 0.0;
	guardConstraintsMatrix5(0, 2) = 0.0;
	guardConstraintsMatrix5(0, 3) = 0.0;
	guardConstraintsMatrix5(0, 4) = 0.0;
	guardConstraintsMatrix5(1, 0) = 1.0;
	guardConstraintsMatrix5(1, 1) = 0.0;
	guardConstraintsMatrix5(1, 2) = 0.0;
	guardConstraintsMatrix5(1, 3) = 0.0;
	guardConstraintsMatrix5(1, 4) = 0.0;
	guardConstraintsMatrix5(2, 0) = 0.0;
	guardConstraintsMatrix5(2, 1) = -1.0;
	guardConstraintsMatrix5(2, 2) = 0.0;
	guardConstraintsMatrix5(2, 3) = 0.0;
	guardConstraintsMatrix5(2, 4) = 0.0;
	guardConstraintsMatrix5(3, 0) = 0.0;
	guardConstraintsMatrix5(3, 1) = 1.0;
	guardConstraintsMatrix5(3, 2) = 0.0;
	guardConstraintsMatrix5(3, 3) = 0.0;
	guardConstraintsMatrix5(3, 4) = 0.0;
	guardConstraintsMatrix5(4, 0) = 0.0;
	guardConstraintsMatrix5(4, 1) = 0.0;
	guardConstraintsMatrix5(4, 2) = -1.0;
	guardConstraintsMatrix5(4, 3) = 0.0;
	guardConstraintsMatrix5(4, 4) = 0.0;
	guardConstraintsMatrix5(5, 0) = 0.0;
	guardConstraintsMatrix5(5, 1) = 0.0;
	guardConstraintsMatrix5(5, 2) = 1.0;
	guardConstraintsMatrix5(5, 3) = 0.0;
	guardConstraintsMatrix5(5, 4) = 0.0;
	guardConstraintsMatrix5(6, 0) = 0.0;
	guardConstraintsMatrix5(6, 1) = 0.0;
	guardConstraintsMatrix5(6, 2) = 0.0;
	guardConstraintsMatrix5(6, 3) = -1.0;
	guardConstraintsMatrix5(6, 4) = 0.0;
	guardConstraintsMatrix5(7, 0) = 0.0;
	guardConstraintsMatrix5(7, 1) = 0.0;
	guardConstraintsMatrix5(7, 2) = 0.0;
	guardConstraintsMatrix5(7, 3) = 1.0;
	guardConstraintsMatrix5(7, 4) = 0.0;

	guardBoundValue5.resize(row);
	guardBoundValue5[0] = -0.0;
	guardBoundValue5[1] = 1.0;
	guardBoundValue5[2] = -2.0;
	guardBoundValue5[3] = 2.0;
	guardBoundValue5[4] = 1000.0;
	guardBoundValue5[5] = 1000.0;
	guardBoundValue5[6] = 1000.0;
	guardBoundValue5[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope5 = polytope::ptr(
			new polytope(guardConstraintsMatrix5, guardBoundValue5,
					guardBoundSign));

	// The transition label ist2

	// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix6.resize(row, col);
	guardConstraintsMatrix6(0, 0) = -1.0;
	guardConstraintsMatrix6(0, 1) = 0.0;
	guardConstraintsMatrix6(0, 2) = 0.0;
	guardConstraintsMatrix6(0, 3) = 0.0;
	guardConstraintsMatrix6(0, 4) = 0.0;
	guardConstraintsMatrix6(1, 0) = 1.0;
	guardConstraintsMatrix6(1, 1) = 0.0;
	guardConstraintsMatrix6(1, 2) = 0.0;
	guardConstraintsMatrix6(1, 3) = 0.0;
	guardConstraintsMatrix6(1, 4) = 0.0;
	guardConstraintsMatrix6(2, 0) = 0.0;
	guardConstraintsMatrix6(2, 1) = -1.0;
	guardConstraintsMatrix6(2, 2) = 0.0;
	guardConstraintsMatrix6(2, 3) = 0.0;
	guardConstraintsMatrix6(2, 4) = 0.0;
	guardConstraintsMatrix6(3, 0) = 0.0;
	guardConstraintsMatrix6(3, 1) = 1.0;
	guardConstraintsMatrix6(3, 2) = 0.0;
	guardConstraintsMatrix6(3, 3) = 0.0;
	guardConstraintsMatrix6(3, 4) = 0.0;
	guardConstraintsMatrix6(4, 0) = 0.0;
	guardConstraintsMatrix6(4, 1) = 0.0;
	guardConstraintsMatrix6(4, 2) = -1.0;
	guardConstraintsMatrix6(4, 3) = 0.0;
	guardConstraintsMatrix6(4, 4) = 0.0;
	guardConstraintsMatrix6(5, 0) = 0.0;
	guardConstraintsMatrix6(5, 1) = 0.0;
	guardConstraintsMatrix6(5, 2) = 1.0;
	guardConstraintsMatrix6(5, 3) = 0.0;
	guardConstraintsMatrix6(5, 4) = 0.0;
	guardConstraintsMatrix6(6, 0) = 0.0;
	guardConstraintsMatrix6(6, 1) = 0.0;
	guardConstraintsMatrix6(6, 2) = 0.0;
	guardConstraintsMatrix6(6, 3) = -1.0;
	guardConstraintsMatrix6(6, 4) = 0.0;
	guardConstraintsMatrix6(7, 0) = 0.0;
	guardConstraintsMatrix6(7, 1) = 0.0;
	guardConstraintsMatrix6(7, 2) = 0.0;
	guardConstraintsMatrix6(7, 3) = 1.0;
	guardConstraintsMatrix6(7, 4) = 0.0;

	guardBoundValue6.resize(row);
	guardBoundValue6[0] = -1.0;
	guardBoundValue6[1] = 1.0;
	guardBoundValue6[2] = -1.0;
	guardBoundValue6[3] = 2.0;
	guardBoundValue6[4] = 1000.0;
	guardBoundValue6[5] = 1000.0;
	guardBoundValue6[6] = 1000.0;
	guardBoundValue6[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope6 = polytope::ptr(
			new polytope(guardConstraintsMatrix6, guardBoundValue6,
					guardBoundSign));

	// The transition label ist3

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix7.resize(row, col);
	guardConstraintsMatrix7(0, 0) = -1.0;
	guardConstraintsMatrix7(0, 1) = 0.0;
	guardConstraintsMatrix7(0, 2) = 0.0;
	guardConstraintsMatrix7(0, 3) = 0.0;
	guardConstraintsMatrix7(0, 4) = 0.0;
	guardConstraintsMatrix7(1, 0) = 1.0;
	guardConstraintsMatrix7(1, 1) = 0.0;
	guardConstraintsMatrix7(1, 2) = 0.0;
	guardConstraintsMatrix7(1, 3) = 0.0;
	guardConstraintsMatrix7(1, 4) = 0.0;
	guardConstraintsMatrix7(2, 0) = 0.0;
	guardConstraintsMatrix7(2, 1) = -1.0;
	guardConstraintsMatrix7(2, 2) = 0.0;
	guardConstraintsMatrix7(2, 3) = 0.0;
	guardConstraintsMatrix7(2, 4) = 0.0;
	guardConstraintsMatrix7(3, 0) = 0.0;
	guardConstraintsMatrix7(3, 1) = 1.0;
	guardConstraintsMatrix7(3, 2) = 0.0;
	guardConstraintsMatrix7(3, 3) = 0.0;
	guardConstraintsMatrix7(3, 4) = 0.0;
	guardConstraintsMatrix7(4, 0) = 0.0;
	guardConstraintsMatrix7(4, 1) = 0.0;
	guardConstraintsMatrix7(4, 2) = -1.0;
	guardConstraintsMatrix7(4, 3) = 0.0;
	guardConstraintsMatrix7(4, 4) = 0.0;
	guardConstraintsMatrix7(5, 0) = 0.0;
	guardConstraintsMatrix7(5, 1) = 0.0;
	guardConstraintsMatrix7(5, 2) = 1.0;
	guardConstraintsMatrix7(5, 3) = 0.0;
	guardConstraintsMatrix7(5, 4) = 0.0;
	guardConstraintsMatrix7(6, 0) = 0.0;
	guardConstraintsMatrix7(6, 1) = 0.0;
	guardConstraintsMatrix7(6, 2) = 0.0;
	guardConstraintsMatrix7(6, 3) = -1.0;
	guardConstraintsMatrix7(6, 4) = 0.0;
	guardConstraintsMatrix7(7, 0) = 0.0;
	guardConstraintsMatrix7(7, 1) = 0.0;
	guardConstraintsMatrix7(7, 2) = 0.0;
	guardConstraintsMatrix7(7, 3) = 1.0;
	guardConstraintsMatrix7(7, 4) = 0.0;

	guardBoundValue7.resize(row);
	guardBoundValue7[0] = -0.0;
	guardBoundValue7[1] = 1.0;
	guardBoundValue7[2] = -1.0;
	guardBoundValue7[3] = 1.0;
	guardBoundValue7[4] = 1000.0;
	guardBoundValue7[5] = 1000.0;
	guardBoundValue7[6] = 1000.0;
	guardBoundValue7[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope7 = polytope::ptr(
			new polytope(guardConstraintsMatrix7, guardBoundValue7,
					guardBoundSign));

	// The transition label ist9

	// Original guard: x1 = 1 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix8.resize(row, col);
	guardConstraintsMatrix8(0, 0) = -1.0;
	guardConstraintsMatrix8(0, 1) = 0.0;
	guardConstraintsMatrix8(0, 2) = 0.0;
	guardConstraintsMatrix8(0, 3) = 0.0;
	guardConstraintsMatrix8(0, 4) = 0.0;
	guardConstraintsMatrix8(1, 0) = 1.0;
	guardConstraintsMatrix8(1, 1) = 0.0;
	guardConstraintsMatrix8(1, 2) = 0.0;
	guardConstraintsMatrix8(1, 3) = 0.0;
	guardConstraintsMatrix8(1, 4) = 0.0;
	guardConstraintsMatrix8(2, 0) = 0.0;
	guardConstraintsMatrix8(2, 1) = -1.0;
	guardConstraintsMatrix8(2, 2) = 0.0;
	guardConstraintsMatrix8(2, 3) = 0.0;
	guardConstraintsMatrix8(2, 4) = 0.0;
	guardConstraintsMatrix8(3, 0) = 0.0;
	guardConstraintsMatrix8(3, 1) = 1.0;
	guardConstraintsMatrix8(3, 2) = 0.0;
	guardConstraintsMatrix8(3, 3) = 0.0;
	guardConstraintsMatrix8(3, 4) = 0.0;
	guardConstraintsMatrix8(4, 0) = 0.0;
	guardConstraintsMatrix8(4, 1) = 0.0;
	guardConstraintsMatrix8(4, 2) = -1.0;
	guardConstraintsMatrix8(4, 3) = 0.0;
	guardConstraintsMatrix8(4, 4) = 0.0;
	guardConstraintsMatrix8(5, 0) = 0.0;
	guardConstraintsMatrix8(5, 1) = 0.0;
	guardConstraintsMatrix8(5, 2) = 1.0;
	guardConstraintsMatrix8(5, 3) = 0.0;
	guardConstraintsMatrix8(5, 4) = 0.0;
	guardConstraintsMatrix8(6, 0) = 0.0;
	guardConstraintsMatrix8(6, 1) = 0.0;
	guardConstraintsMatrix8(6, 2) = 0.0;
	guardConstraintsMatrix8(6, 3) = -1.0;
	guardConstraintsMatrix8(6, 4) = 0.0;
	guardConstraintsMatrix8(7, 0) = 0.0;
	guardConstraintsMatrix8(7, 1) = 0.0;
	guardConstraintsMatrix8(7, 2) = 0.0;
	guardConstraintsMatrix8(7, 3) = 1.0;
	guardConstraintsMatrix8(7, 4) = 0.0;

	guardBoundValue8.resize(row);
	guardBoundValue8[0] = -1.0;
	guardBoundValue8[1] = 1.0;
	guardBoundValue8[2] = -1.0;
	guardBoundValue8[3] = 2.0;
	guardBoundValue8[4] = 1000.0;
	guardBoundValue8[5] = 1000.0;
	guardBoundValue8[6] = 1000.0;
	guardBoundValue8[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope8 = polytope::ptr(
			new polytope(guardConstraintsMatrix8, guardBoundValue8,
					guardBoundSign));

	// The transition label ist10

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix9.resize(row, col);
	guardConstraintsMatrix9(0, 0) = -1.0;
	guardConstraintsMatrix9(0, 1) = 0.0;
	guardConstraintsMatrix9(0, 2) = 0.0;
	guardConstraintsMatrix9(0, 3) = 0.0;
	guardConstraintsMatrix9(0, 4) = 0.0;
	guardConstraintsMatrix9(1, 0) = 1.0;
	guardConstraintsMatrix9(1, 1) = 0.0;
	guardConstraintsMatrix9(1, 2) = 0.0;
	guardConstraintsMatrix9(1, 3) = 0.0;
	guardConstraintsMatrix9(1, 4) = 0.0;
	guardConstraintsMatrix9(2, 0) = 0.0;
	guardConstraintsMatrix9(2, 1) = -1.0;
	guardConstraintsMatrix9(2, 2) = 0.0;
	guardConstraintsMatrix9(2, 3) = 0.0;
	guardConstraintsMatrix9(2, 4) = 0.0;
	guardConstraintsMatrix9(3, 0) = 0.0;
	guardConstraintsMatrix9(3, 1) = 1.0;
	guardConstraintsMatrix9(3, 2) = 0.0;
	guardConstraintsMatrix9(3, 3) = 0.0;
	guardConstraintsMatrix9(3, 4) = 0.0;
	guardConstraintsMatrix9(4, 0) = 0.0;
	guardConstraintsMatrix9(4, 1) = 0.0;
	guardConstraintsMatrix9(4, 2) = -1.0;
	guardConstraintsMatrix9(4, 3) = 0.0;
	guardConstraintsMatrix9(4, 4) = 0.0;
	guardConstraintsMatrix9(5, 0) = 0.0;
	guardConstraintsMatrix9(5, 1) = 0.0;
	guardConstraintsMatrix9(5, 2) = 1.0;
	guardConstraintsMatrix9(5, 3) = 0.0;
	guardConstraintsMatrix9(5, 4) = 0.0;
	guardConstraintsMatrix9(6, 0) = 0.0;
	guardConstraintsMatrix9(6, 1) = 0.0;
	guardConstraintsMatrix9(6, 2) = 0.0;
	guardConstraintsMatrix9(6, 3) = -1.0;
	guardConstraintsMatrix9(6, 4) = 0.0;
	guardConstraintsMatrix9(7, 0) = 0.0;
	guardConstraintsMatrix9(7, 1) = 0.0;
	guardConstraintsMatrix9(7, 2) = 0.0;
	guardConstraintsMatrix9(7, 3) = 1.0;
	guardConstraintsMatrix9(7, 4) = 0.0;

	guardBoundValue9.resize(row);
	guardBoundValue9[0] = -1.0;
	guardBoundValue9[1] = 2.0;
	guardBoundValue9[2] = -2.0;
	guardBoundValue9[3] = 2.0;
	guardBoundValue9[4] = 1000.0;
	guardBoundValue9[5] = 1000.0;
	guardBoundValue9[6] = 1000.0;
	guardBoundValue9[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope9 = polytope::ptr(
			new polytope(guardConstraintsMatrix9, guardBoundValue9,
					guardBoundSign));

	// The transition label ist11

	// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix10.resize(row, col);
	guardConstraintsMatrix10(0, 0) = -1.0;
	guardConstraintsMatrix10(0, 1) = 0.0;
	guardConstraintsMatrix10(0, 2) = 0.0;
	guardConstraintsMatrix10(0, 3) = 0.0;
	guardConstraintsMatrix10(0, 4) = 0.0;
	guardConstraintsMatrix10(1, 0) = 1.0;
	guardConstraintsMatrix10(1, 1) = 0.0;
	guardConstraintsMatrix10(1, 2) = 0.0;
	guardConstraintsMatrix10(1, 3) = 0.0;
	guardConstraintsMatrix10(1, 4) = 0.0;
	guardConstraintsMatrix10(2, 0) = 0.0;
	guardConstraintsMatrix10(2, 1) = -1.0;
	guardConstraintsMatrix10(2, 2) = 0.0;
	guardConstraintsMatrix10(2, 3) = 0.0;
	guardConstraintsMatrix10(2, 4) = 0.0;
	guardConstraintsMatrix10(3, 0) = 0.0;
	guardConstraintsMatrix10(3, 1) = 1.0;
	guardConstraintsMatrix10(3, 2) = 0.0;
	guardConstraintsMatrix10(3, 3) = 0.0;
	guardConstraintsMatrix10(3, 4) = 0.0;
	guardConstraintsMatrix10(4, 0) = 0.0;
	guardConstraintsMatrix10(4, 1) = 0.0;
	guardConstraintsMatrix10(4, 2) = -1.0;
	guardConstraintsMatrix10(4, 3) = 0.0;
	guardConstraintsMatrix10(4, 4) = 0.0;
	guardConstraintsMatrix10(5, 0) = 0.0;
	guardConstraintsMatrix10(5, 1) = 0.0;
	guardConstraintsMatrix10(5, 2) = 1.0;
	guardConstraintsMatrix10(5, 3) = 0.0;
	guardConstraintsMatrix10(5, 4) = 0.0;
	guardConstraintsMatrix10(6, 0) = 0.0;
	guardConstraintsMatrix10(6, 1) = 0.0;
	guardConstraintsMatrix10(6, 2) = 0.0;
	guardConstraintsMatrix10(6, 3) = -1.0;
	guardConstraintsMatrix10(6, 4) = 0.0;
	guardConstraintsMatrix10(7, 0) = 0.0;
	guardConstraintsMatrix10(7, 1) = 0.0;
	guardConstraintsMatrix10(7, 2) = 0.0;
	guardConstraintsMatrix10(7, 3) = 1.0;
	guardConstraintsMatrix10(7, 4) = 0.0;

	guardBoundValue10.resize(row);
	guardBoundValue10[0] = -2.0;
	guardBoundValue10[1] = 2.0;
	guardBoundValue10[2] = -1.0;
	guardBoundValue10[3] = 2.0;
	guardBoundValue10[4] = 1000.0;
	guardBoundValue10[5] = 1000.0;
	guardBoundValue10[6] = 1000.0;
	guardBoundValue10[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope10 = polytope::ptr(
			new polytope(guardConstraintsMatrix10, guardBoundValue10,
					guardBoundSign));

	// The transition label ist12

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix11.resize(row, col);
	guardConstraintsMatrix11(0, 0) = -1.0;
	guardConstraintsMatrix11(0, 1) = 0.0;
	guardConstraintsMatrix11(0, 2) = 0.0;
	guardConstraintsMatrix11(0, 3) = 0.0;
	guardConstraintsMatrix11(0, 4) = 0.0;
	guardConstraintsMatrix11(1, 0) = 1.0;
	guardConstraintsMatrix11(1, 1) = 0.0;
	guardConstraintsMatrix11(1, 2) = 0.0;
	guardConstraintsMatrix11(1, 3) = 0.0;
	guardConstraintsMatrix11(1, 4) = 0.0;
	guardConstraintsMatrix11(2, 0) = 0.0;
	guardConstraintsMatrix11(2, 1) = -1.0;
	guardConstraintsMatrix11(2, 2) = 0.0;
	guardConstraintsMatrix11(2, 3) = 0.0;
	guardConstraintsMatrix11(2, 4) = 0.0;
	guardConstraintsMatrix11(3, 0) = 0.0;
	guardConstraintsMatrix11(3, 1) = 1.0;
	guardConstraintsMatrix11(3, 2) = 0.0;
	guardConstraintsMatrix11(3, 3) = 0.0;
	guardConstraintsMatrix11(3, 4) = 0.0;
	guardConstraintsMatrix11(4, 0) = 0.0;
	guardConstraintsMatrix11(4, 1) = 0.0;
	guardConstraintsMatrix11(4, 2) = -1.0;
	guardConstraintsMatrix11(4, 3) = 0.0;
	guardConstraintsMatrix11(4, 4) = 0.0;
	guardConstraintsMatrix11(5, 0) = 0.0;
	guardConstraintsMatrix11(5, 1) = 0.0;
	guardConstraintsMatrix11(5, 2) = 1.0;
	guardConstraintsMatrix11(5, 3) = 0.0;
	guardConstraintsMatrix11(5, 4) = 0.0;
	guardConstraintsMatrix11(6, 0) = 0.0;
	guardConstraintsMatrix11(6, 1) = 0.0;
	guardConstraintsMatrix11(6, 2) = 0.0;
	guardConstraintsMatrix11(6, 3) = -1.0;
	guardConstraintsMatrix11(6, 4) = 0.0;
	guardConstraintsMatrix11(7, 0) = 0.0;
	guardConstraintsMatrix11(7, 1) = 0.0;
	guardConstraintsMatrix11(7, 2) = 0.0;
	guardConstraintsMatrix11(7, 3) = 1.0;
	guardConstraintsMatrix11(7, 4) = 0.0;

	guardBoundValue11.resize(row);
	guardBoundValue11[0] = -1.0;
	guardBoundValue11[1] = 2.0;
	guardBoundValue11[2] = -1.0;
	guardBoundValue11[3] = 1.0;
	guardBoundValue11[4] = 1000.0;
	guardBoundValue11[5] = 1000.0;
	guardBoundValue11[6] = 1000.0;
	guardBoundValue11[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope11 = polytope::ptr(
			new polytope(guardConstraintsMatrix11, guardBoundValue11,
					guardBoundSign));

	// The transition label ist16

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix12.resize(row, col);
	guardConstraintsMatrix12(0, 0) = -1.0;
	guardConstraintsMatrix12(0, 1) = 0.0;
	guardConstraintsMatrix12(0, 2) = 0.0;
	guardConstraintsMatrix12(0, 3) = 0.0;
	guardConstraintsMatrix12(0, 4) = 0.0;
	guardConstraintsMatrix12(1, 0) = 1.0;
	guardConstraintsMatrix12(1, 1) = 0.0;
	guardConstraintsMatrix12(1, 2) = 0.0;
	guardConstraintsMatrix12(1, 3) = 0.0;
	guardConstraintsMatrix12(1, 4) = 0.0;
	guardConstraintsMatrix12(2, 0) = 0.0;
	guardConstraintsMatrix12(2, 1) = -1.0;
	guardConstraintsMatrix12(2, 2) = 0.0;
	guardConstraintsMatrix12(2, 3) = 0.0;
	guardConstraintsMatrix12(2, 4) = 0.0;
	guardConstraintsMatrix12(3, 0) = 0.0;
	guardConstraintsMatrix12(3, 1) = 1.0;
	guardConstraintsMatrix12(3, 2) = 0.0;
	guardConstraintsMatrix12(3, 3) = 0.0;
	guardConstraintsMatrix12(3, 4) = 0.0;
	guardConstraintsMatrix12(4, 0) = 0.0;
	guardConstraintsMatrix12(4, 1) = 0.0;
	guardConstraintsMatrix12(4, 2) = -1.0;
	guardConstraintsMatrix12(4, 3) = 0.0;
	guardConstraintsMatrix12(4, 4) = 0.0;
	guardConstraintsMatrix12(5, 0) = 0.0;
	guardConstraintsMatrix12(5, 1) = 0.0;
	guardConstraintsMatrix12(5, 2) = 1.0;
	guardConstraintsMatrix12(5, 3) = 0.0;
	guardConstraintsMatrix12(5, 4) = 0.0;
	guardConstraintsMatrix12(6, 0) = 0.0;
	guardConstraintsMatrix12(6, 1) = 0.0;
	guardConstraintsMatrix12(6, 2) = 0.0;
	guardConstraintsMatrix12(6, 3) = -1.0;
	guardConstraintsMatrix12(6, 4) = 0.0;
	guardConstraintsMatrix12(7, 0) = 0.0;
	guardConstraintsMatrix12(7, 1) = 0.0;
	guardConstraintsMatrix12(7, 2) = 0.0;
	guardConstraintsMatrix12(7, 3) = 1.0;
	guardConstraintsMatrix12(7, 4) = 0.0;

	guardBoundValue12.resize(row);
	guardBoundValue12[0] = -2.0;
	guardBoundValue12[1] = 3.0;
	guardBoundValue12[2] = -2.0;
	guardBoundValue12[3] = 2.0;
	guardBoundValue12[4] = 1000.0;
	guardBoundValue12[5] = 1000.0;
	guardBoundValue12[6] = 1000.0;
	guardBoundValue12[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope12 = polytope::ptr(
			new polytope(guardConstraintsMatrix12, guardBoundValue12,
					guardBoundSign));

	// The transition label ist17

	// Original guard: x1 = 2 & 1 <= x2 & x2 <= 2 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix13.resize(row, col);
	guardConstraintsMatrix13(0, 0) = -1.0;
	guardConstraintsMatrix13(0, 1) = 0.0;
	guardConstraintsMatrix13(0, 2) = 0.0;
	guardConstraintsMatrix13(0, 3) = 0.0;
	guardConstraintsMatrix13(0, 4) = 0.0;
	guardConstraintsMatrix13(1, 0) = 1.0;
	guardConstraintsMatrix13(1, 1) = 0.0;
	guardConstraintsMatrix13(1, 2) = 0.0;
	guardConstraintsMatrix13(1, 3) = 0.0;
	guardConstraintsMatrix13(1, 4) = 0.0;
	guardConstraintsMatrix13(2, 0) = 0.0;
	guardConstraintsMatrix13(2, 1) = -1.0;
	guardConstraintsMatrix13(2, 2) = 0.0;
	guardConstraintsMatrix13(2, 3) = 0.0;
	guardConstraintsMatrix13(2, 4) = 0.0;
	guardConstraintsMatrix13(3, 0) = 0.0;
	guardConstraintsMatrix13(3, 1) = 1.0;
	guardConstraintsMatrix13(3, 2) = 0.0;
	guardConstraintsMatrix13(3, 3) = 0.0;
	guardConstraintsMatrix13(3, 4) = 0.0;
	guardConstraintsMatrix13(4, 0) = 0.0;
	guardConstraintsMatrix13(4, 1) = 0.0;
	guardConstraintsMatrix13(4, 2) = -1.0;
	guardConstraintsMatrix13(4, 3) = 0.0;
	guardConstraintsMatrix13(4, 4) = 0.0;
	guardConstraintsMatrix13(5, 0) = 0.0;
	guardConstraintsMatrix13(5, 1) = 0.0;
	guardConstraintsMatrix13(5, 2) = 1.0;
	guardConstraintsMatrix13(5, 3) = 0.0;
	guardConstraintsMatrix13(5, 4) = 0.0;
	guardConstraintsMatrix13(6, 0) = 0.0;
	guardConstraintsMatrix13(6, 1) = 0.0;
	guardConstraintsMatrix13(6, 2) = 0.0;
	guardConstraintsMatrix13(6, 3) = -1.0;
	guardConstraintsMatrix13(6, 4) = 0.0;
	guardConstraintsMatrix13(7, 0) = 0.0;
	guardConstraintsMatrix13(7, 1) = 0.0;
	guardConstraintsMatrix13(7, 2) = 0.0;
	guardConstraintsMatrix13(7, 3) = 1.0;
	guardConstraintsMatrix13(7, 4) = 0.0;

	guardBoundValue13.resize(row);
	guardBoundValue13[0] = -2.0;
	guardBoundValue13[1] = 2.0;
	guardBoundValue13[2] = -1.0;
	guardBoundValue13[3] = 2.0;
	guardBoundValue13[4] = 1000.0;
	guardBoundValue13[5] = 1000.0;
	guardBoundValue13[6] = 1000.0;
	guardBoundValue13[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope13 = polytope::ptr(
			new polytope(guardConstraintsMatrix13, guardBoundValue13,
					guardBoundSign));

	// The transition label ist18

	// Original guard: 2 <= x1 & x1 <= 3 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix14.resize(row, col);
	guardConstraintsMatrix14(0, 0) = -1.0;
	guardConstraintsMatrix14(0, 1) = 0.0;
	guardConstraintsMatrix14(0, 2) = 0.0;
	guardConstraintsMatrix14(0, 3) = 0.0;
	guardConstraintsMatrix14(0, 4) = 0.0;
	guardConstraintsMatrix14(1, 0) = 1.0;
	guardConstraintsMatrix14(1, 1) = 0.0;
	guardConstraintsMatrix14(1, 2) = 0.0;
	guardConstraintsMatrix14(1, 3) = 0.0;
	guardConstraintsMatrix14(1, 4) = 0.0;
	guardConstraintsMatrix14(2, 0) = 0.0;
	guardConstraintsMatrix14(2, 1) = -1.0;
	guardConstraintsMatrix14(2, 2) = 0.0;
	guardConstraintsMatrix14(2, 3) = 0.0;
	guardConstraintsMatrix14(2, 4) = 0.0;
	guardConstraintsMatrix14(3, 0) = 0.0;
	guardConstraintsMatrix14(3, 1) = 1.0;
	guardConstraintsMatrix14(3, 2) = 0.0;
	guardConstraintsMatrix14(3, 3) = 0.0;
	guardConstraintsMatrix14(3, 4) = 0.0;
	guardConstraintsMatrix14(4, 0) = 0.0;
	guardConstraintsMatrix14(4, 1) = 0.0;
	guardConstraintsMatrix14(4, 2) = -1.0;
	guardConstraintsMatrix14(4, 3) = 0.0;
	guardConstraintsMatrix14(4, 4) = 0.0;
	guardConstraintsMatrix14(5, 0) = 0.0;
	guardConstraintsMatrix14(5, 1) = 0.0;
	guardConstraintsMatrix14(5, 2) = 1.0;
	guardConstraintsMatrix14(5, 3) = 0.0;
	guardConstraintsMatrix14(5, 4) = 0.0;
	guardConstraintsMatrix14(6, 0) = 0.0;
	guardConstraintsMatrix14(6, 1) = 0.0;
	guardConstraintsMatrix14(6, 2) = 0.0;
	guardConstraintsMatrix14(6, 3) = -1.0;
	guardConstraintsMatrix14(6, 4) = 0.0;
	guardConstraintsMatrix14(7, 0) = 0.0;
	guardConstraintsMatrix14(7, 1) = 0.0;
	guardConstraintsMatrix14(7, 2) = 0.0;
	guardConstraintsMatrix14(7, 3) = 1.0;
	guardConstraintsMatrix14(7, 4) = 0.0;

	guardBoundValue14.resize(row);
	guardBoundValue14[0] = -2.0;
	guardBoundValue14[1] = 3.0;
	guardBoundValue14[2] = -1.0;
	guardBoundValue14[3] = 1.0;
	guardBoundValue14[4] = 1000.0;
	guardBoundValue14[5] = 1000.0;
	guardBoundValue14[6] = 1000.0;
	guardBoundValue14[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope14 = polytope::ptr(
			new polytope(guardConstraintsMatrix14, guardBoundValue14,
					guardBoundSign));

	// The transition label ist6

	// Original guard: 1 <= x1 & x1 <= 2 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix15.resize(row, col);
	guardConstraintsMatrix15(0, 0) = -1.0;
	guardConstraintsMatrix15(0, 1) = 0.0;
	guardConstraintsMatrix15(0, 2) = 0.0;
	guardConstraintsMatrix15(0, 3) = 0.0;
	guardConstraintsMatrix15(0, 4) = 0.0;
	guardConstraintsMatrix15(1, 0) = 1.0;
	guardConstraintsMatrix15(1, 1) = 0.0;
	guardConstraintsMatrix15(1, 2) = 0.0;
	guardConstraintsMatrix15(1, 3) = 0.0;
	guardConstraintsMatrix15(1, 4) = 0.0;
	guardConstraintsMatrix15(2, 0) = 0.0;
	guardConstraintsMatrix15(2, 1) = -1.0;
	guardConstraintsMatrix15(2, 2) = 0.0;
	guardConstraintsMatrix15(2, 3) = 0.0;
	guardConstraintsMatrix15(2, 4) = 0.0;
	guardConstraintsMatrix15(3, 0) = 0.0;
	guardConstraintsMatrix15(3, 1) = 1.0;
	guardConstraintsMatrix15(3, 2) = 0.0;
	guardConstraintsMatrix15(3, 3) = 0.0;
	guardConstraintsMatrix15(3, 4) = 0.0;
	guardConstraintsMatrix15(4, 0) = 0.0;
	guardConstraintsMatrix15(4, 1) = 0.0;
	guardConstraintsMatrix15(4, 2) = -1.0;
	guardConstraintsMatrix15(4, 3) = 0.0;
	guardConstraintsMatrix15(4, 4) = 0.0;
	guardConstraintsMatrix15(5, 0) = 0.0;
	guardConstraintsMatrix15(5, 1) = 0.0;
	guardConstraintsMatrix15(5, 2) = 1.0;
	guardConstraintsMatrix15(5, 3) = 0.0;
	guardConstraintsMatrix15(5, 4) = 0.0;
	guardConstraintsMatrix15(6, 0) = 0.0;
	guardConstraintsMatrix15(6, 1) = 0.0;
	guardConstraintsMatrix15(6, 2) = 0.0;
	guardConstraintsMatrix15(6, 3) = -1.0;
	guardConstraintsMatrix15(6, 4) = 0.0;
	guardConstraintsMatrix15(7, 0) = 0.0;
	guardConstraintsMatrix15(7, 1) = 0.0;
	guardConstraintsMatrix15(7, 2) = 0.0;
	guardConstraintsMatrix15(7, 3) = 1.0;
	guardConstraintsMatrix15(7, 4) = 0.0;

	guardBoundValue15.resize(row);
	guardBoundValue15[0] = -1.0;
	guardBoundValue15[1] = 2.0;
	guardBoundValue15[2] = -1.0;
	guardBoundValue15[3] = 1.0;
	guardBoundValue15[4] = 1000.0;
	guardBoundValue15[5] = 1000.0;
	guardBoundValue15[6] = 1000.0;
	guardBoundValue15[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope15 = polytope::ptr(
			new polytope(guardConstraintsMatrix15, guardBoundValue15,
					guardBoundSign));

	// The transition label ist7

	// Original guard: x1 = 1 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix16.resize(row, col);
	guardConstraintsMatrix16(0, 0) = -1.0;
	guardConstraintsMatrix16(0, 1) = 0.0;
	guardConstraintsMatrix16(0, 2) = 0.0;
	guardConstraintsMatrix16(0, 3) = 0.0;
	guardConstraintsMatrix16(0, 4) = 0.0;
	guardConstraintsMatrix16(1, 0) = 1.0;
	guardConstraintsMatrix16(1, 1) = 0.0;
	guardConstraintsMatrix16(1, 2) = 0.0;
	guardConstraintsMatrix16(1, 3) = 0.0;
	guardConstraintsMatrix16(1, 4) = 0.0;
	guardConstraintsMatrix16(2, 0) = 0.0;
	guardConstraintsMatrix16(2, 1) = -1.0;
	guardConstraintsMatrix16(2, 2) = 0.0;
	guardConstraintsMatrix16(2, 3) = 0.0;
	guardConstraintsMatrix16(2, 4) = 0.0;
	guardConstraintsMatrix16(3, 0) = 0.0;
	guardConstraintsMatrix16(3, 1) = 1.0;
	guardConstraintsMatrix16(3, 2) = 0.0;
	guardConstraintsMatrix16(3, 3) = 0.0;
	guardConstraintsMatrix16(3, 4) = 0.0;
	guardConstraintsMatrix16(4, 0) = 0.0;
	guardConstraintsMatrix16(4, 1) = 0.0;
	guardConstraintsMatrix16(4, 2) = -1.0;
	guardConstraintsMatrix16(4, 3) = 0.0;
	guardConstraintsMatrix16(4, 4) = 0.0;
	guardConstraintsMatrix16(5, 0) = 0.0;
	guardConstraintsMatrix16(5, 1) = 0.0;
	guardConstraintsMatrix16(5, 2) = 1.0;
	guardConstraintsMatrix16(5, 3) = 0.0;
	guardConstraintsMatrix16(5, 4) = 0.0;
	guardConstraintsMatrix16(6, 0) = 0.0;
	guardConstraintsMatrix16(6, 1) = 0.0;
	guardConstraintsMatrix16(6, 2) = 0.0;
	guardConstraintsMatrix16(6, 3) = -1.0;
	guardConstraintsMatrix16(6, 4) = 0.0;
	guardConstraintsMatrix16(7, 0) = 0.0;
	guardConstraintsMatrix16(7, 1) = 0.0;
	guardConstraintsMatrix16(7, 2) = 0.0;
	guardConstraintsMatrix16(7, 3) = 1.0;
	guardConstraintsMatrix16(7, 4) = 0.0;

	guardBoundValue16.resize(row);
	guardBoundValue16[0] = -1.0;
	guardBoundValue16[1] = 1.0;
	guardBoundValue16[2] = -0.0;
	guardBoundValue16[3] = 1.0;
	guardBoundValue16[4] = 1000.0;
	guardBoundValue16[5] = 1000.0;
	guardBoundValue16[6] = 1000.0;
	guardBoundValue16[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope16 = polytope::ptr(
			new polytope(guardConstraintsMatrix16, guardBoundValue16,
					guardBoundSign));

	// The transition label ist8

	// Original guard: x1 = 2 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix17.resize(row, col);
	guardConstraintsMatrix17(0, 0) = -1.0;
	guardConstraintsMatrix17(0, 1) = 0.0;
	guardConstraintsMatrix17(0, 2) = 0.0;
	guardConstraintsMatrix17(0, 3) = 0.0;
	guardConstraintsMatrix17(0, 4) = 0.0;
	guardConstraintsMatrix17(1, 0) = 1.0;
	guardConstraintsMatrix17(1, 1) = 0.0;
	guardConstraintsMatrix17(1, 2) = 0.0;
	guardConstraintsMatrix17(1, 3) = 0.0;
	guardConstraintsMatrix17(1, 4) = 0.0;
	guardConstraintsMatrix17(2, 0) = 0.0;
	guardConstraintsMatrix17(2, 1) = -1.0;
	guardConstraintsMatrix17(2, 2) = 0.0;
	guardConstraintsMatrix17(2, 3) = 0.0;
	guardConstraintsMatrix17(2, 4) = 0.0;
	guardConstraintsMatrix17(3, 0) = 0.0;
	guardConstraintsMatrix17(3, 1) = 1.0;
	guardConstraintsMatrix17(3, 2) = 0.0;
	guardConstraintsMatrix17(3, 3) = 0.0;
	guardConstraintsMatrix17(3, 4) = 0.0;
	guardConstraintsMatrix17(4, 0) = 0.0;
	guardConstraintsMatrix17(4, 1) = 0.0;
	guardConstraintsMatrix17(4, 2) = -1.0;
	guardConstraintsMatrix17(4, 3) = 0.0;
	guardConstraintsMatrix17(4, 4) = 0.0;
	guardConstraintsMatrix17(5, 0) = 0.0;
	guardConstraintsMatrix17(5, 1) = 0.0;
	guardConstraintsMatrix17(5, 2) = 1.0;
	guardConstraintsMatrix17(5, 3) = 0.0;
	guardConstraintsMatrix17(5, 4) = 0.0;
	guardConstraintsMatrix17(6, 0) = 0.0;
	guardConstraintsMatrix17(6, 1) = 0.0;
	guardConstraintsMatrix17(6, 2) = 0.0;
	guardConstraintsMatrix17(6, 3) = -1.0;
	guardConstraintsMatrix17(6, 4) = 0.0;
	guardConstraintsMatrix17(7, 0) = 0.0;
	guardConstraintsMatrix17(7, 1) = 0.0;
	guardConstraintsMatrix17(7, 2) = 0.0;
	guardConstraintsMatrix17(7, 3) = 1.0;
	guardConstraintsMatrix17(7, 4) = 0.0;

	guardBoundValue17.resize(row);
	guardBoundValue17[0] = -2.0;
	guardBoundValue17[1] = 2.0;
	guardBoundValue17[2] = -0.0;
	guardBoundValue17[3] = 1.0;
	guardBoundValue17[4] = 1000.0;
	guardBoundValue17[5] = 1000.0;
	guardBoundValue17[6] = 1000.0;
	guardBoundValue17[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope17 = polytope::ptr(
			new polytope(guardConstraintsMatrix17, guardBoundValue17,
					guardBoundSign));

	// The transition label ist5

	// Original guard: x1 = 1 & 0 <= x2 & x2 <= 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix18.resize(row, col);
	guardConstraintsMatrix18(0, 0) = -1.0;
	guardConstraintsMatrix18(0, 1) = 0.0;
	guardConstraintsMatrix18(0, 2) = 0.0;
	guardConstraintsMatrix18(0, 3) = 0.0;
	guardConstraintsMatrix18(0, 4) = 0.0;
	guardConstraintsMatrix18(1, 0) = 1.0;
	guardConstraintsMatrix18(1, 1) = 0.0;
	guardConstraintsMatrix18(1, 2) = 0.0;
	guardConstraintsMatrix18(1, 3) = 0.0;
	guardConstraintsMatrix18(1, 4) = 0.0;
	guardConstraintsMatrix18(2, 0) = 0.0;
	guardConstraintsMatrix18(2, 1) = -1.0;
	guardConstraintsMatrix18(2, 2) = 0.0;
	guardConstraintsMatrix18(2, 3) = 0.0;
	guardConstraintsMatrix18(2, 4) = 0.0;
	guardConstraintsMatrix18(3, 0) = 0.0;
	guardConstraintsMatrix18(3, 1) = 1.0;
	guardConstraintsMatrix18(3, 2) = 0.0;
	guardConstraintsMatrix18(3, 3) = 0.0;
	guardConstraintsMatrix18(3, 4) = 0.0;
	guardConstraintsMatrix18(4, 0) = 0.0;
	guardConstraintsMatrix18(4, 1) = 0.0;
	guardConstraintsMatrix18(4, 2) = -1.0;
	guardConstraintsMatrix18(4, 3) = 0.0;
	guardConstraintsMatrix18(4, 4) = 0.0;
	guardConstraintsMatrix18(5, 0) = 0.0;
	guardConstraintsMatrix18(5, 1) = 0.0;
	guardConstraintsMatrix18(5, 2) = 1.0;
	guardConstraintsMatrix18(5, 3) = 0.0;
	guardConstraintsMatrix18(5, 4) = 0.0;
	guardConstraintsMatrix18(6, 0) = 0.0;
	guardConstraintsMatrix18(6, 1) = 0.0;
	guardConstraintsMatrix18(6, 2) = 0.0;
	guardConstraintsMatrix18(6, 3) = -1.0;
	guardConstraintsMatrix18(6, 4) = 0.0;
	guardConstraintsMatrix18(7, 0) = 0.0;
	guardConstraintsMatrix18(7, 1) = 0.0;
	guardConstraintsMatrix18(7, 2) = 0.0;
	guardConstraintsMatrix18(7, 3) = 1.0;
	guardConstraintsMatrix18(7, 4) = 0.0;

	guardBoundValue18.resize(row);
	guardBoundValue18[0] = -1.0;
	guardBoundValue18[1] = 1.0;
	guardBoundValue18[2] = -0.0;
	guardBoundValue18[3] = 1.0;
	guardBoundValue18[4] = 1000.0;
	guardBoundValue18[5] = 1000.0;
	guardBoundValue18[6] = 1000.0;
	guardBoundValue18[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope18 = polytope::ptr(
			new polytope(guardConstraintsMatrix18, guardBoundValue18,
					guardBoundSign));

	// The transition label ist4

	// Original guard: 0 <= x1 & x1 <= 1 & x2 = 1 & -1000 <= v1 & v1 <= 1000 & -1000 <= v2 & v2 <= 1000

	row = 8;
	col = 5;

	guardConstraintsMatrix19.resize(row, col);
	guardConstraintsMatrix19(0, 0) = -1.0;
	guardConstraintsMatrix19(0, 1) = 0.0;
	guardConstraintsMatrix19(0, 2) = 0.0;
	guardConstraintsMatrix19(0, 3) = 0.0;
	guardConstraintsMatrix19(0, 4) = 0.0;
	guardConstraintsMatrix19(1, 0) = 1.0;
	guardConstraintsMatrix19(1, 1) = 0.0;
	guardConstraintsMatrix19(1, 2) = 0.0;
	guardConstraintsMatrix19(1, 3) = 0.0;
	guardConstraintsMatrix19(1, 4) = 0.0;
	guardConstraintsMatrix19(2, 0) = 0.0;
	guardConstraintsMatrix19(2, 1) = -1.0;
	guardConstraintsMatrix19(2, 2) = 0.0;
	guardConstraintsMatrix19(2, 3) = 0.0;
	guardConstraintsMatrix19(2, 4) = 0.0;
	guardConstraintsMatrix19(3, 0) = 0.0;
	guardConstraintsMatrix19(3, 1) = 1.0;
	guardConstraintsMatrix19(3, 2) = 0.0;
	guardConstraintsMatrix19(3, 3) = 0.0;
	guardConstraintsMatrix19(3, 4) = 0.0;
	guardConstraintsMatrix19(4, 0) = 0.0;
	guardConstraintsMatrix19(4, 1) = 0.0;
	guardConstraintsMatrix19(4, 2) = -1.0;
	guardConstraintsMatrix19(4, 3) = 0.0;
	guardConstraintsMatrix19(4, 4) = 0.0;
	guardConstraintsMatrix19(5, 0) = 0.0;
	guardConstraintsMatrix19(5, 1) = 0.0;
	guardConstraintsMatrix19(5, 2) = 1.0;
	guardConstraintsMatrix19(5, 3) = 0.0;
	guardConstraintsMatrix19(5, 4) = 0.0;
	guardConstraintsMatrix19(6, 0) = 0.0;
	guardConstraintsMatrix19(6, 1) = 0.0;
	guardConstraintsMatrix19(6, 2) = 0.0;
	guardConstraintsMatrix19(6, 3) = -1.0;
	guardConstraintsMatrix19(6, 4) = 0.0;
	guardConstraintsMatrix19(7, 0) = 0.0;
	guardConstraintsMatrix19(7, 1) = 0.0;
	guardConstraintsMatrix19(7, 2) = 0.0;
	guardConstraintsMatrix19(7, 3) = 1.0;
	guardConstraintsMatrix19(7, 4) = 0.0;

	guardBoundValue19.resize(row);
	guardBoundValue19[0] = -0.0;
	guardBoundValue19[1] = 1.0;
	guardBoundValue19[2] = -1.0;
	guardBoundValue19[3] = 1.0;
	guardBoundValue19[4] = 1000.0;
	guardBoundValue19[5] = 1000.0;
	guardBoundValue19[6] = 1000.0;
	guardBoundValue19[7] = 1000.0;
	guardBoundSign = 1;
	guard_polytope19 = polytope::ptr(
			new polytope(guardConstraintsMatrix19, guardBoundValue19,
					guardBoundSign));

	// The transition label is   t13

	math::matrix<double> R0;
	row = 5;
	col = 5;
	R0.resize(row, col);
	R0(0, 0) = 1.0;
	R0(0, 1) = 0.0;
	R0(0, 2) = 0.0;
	R0(0, 3) = 0.0;
	R0(0, 4) = 0.0;
	R0(1, 0) = 0.0;
	R0(1, 1) = 1.0;
	R0(1, 2) = 0.0;
	R0(1, 3) = 0.0;
	R0(1, 4) = 0.0;
	R0(2, 0) = 0.0;
	R0(2, 1) = 0.0;
	R0(2, 2) = 1.0;
	R0(2, 3) = 0.0;
	R0(2, 4) = 0.0;
	R0(3, 0) = 0.0;
	R0(3, 1) = 0.0;
	R0(3, 2) = 0.0;
	R0(3, 3) = 1.0;
	R0(3, 4) = 0.0;
	R0(4, 0) = 0.0;
	R0(4, 1) = 0.0;
	R0(4, 2) = 0.0;
	R0(4, 3) = 0.0;
	R0(4, 4) = 1.0;
	std::vector<double> w0(row);
	w0[0] = 0.0;
	w0[1] = 0.0;
	w0[2] = 0.0;
	w0[3] = 0.0;
	w0[4] = 0.0;

	Assign assignment0;
	assignment0.Map = R0;
	assignment0.b = w0;

	// The transition label is   t14

	math::matrix<double> R1;
	row = 5;
	col = 5;
	R1.resize(row, col);
	R1(0, 0) = 1.0;
	R1(0, 1) = 0.0;
	R1(0, 2) = 0.0;
	R1(0, 3) = 0.0;
	R1(0, 4) = 0.0;
	R1(1, 0) = 0.0;
	R1(1, 1) = 1.0;
	R1(1, 2) = 0.0;
	R1(1, 3) = 0.0;
	R1(1, 4) = 0.0;
	R1(2, 0) = 0.0;
	R1(2, 1) = 0.0;
	R1(2, 2) = 1.0;
	R1(2, 3) = 0.0;
	R1(2, 4) = 0.0;
	R1(3, 0) = 0.0;
	R1(3, 1) = 0.0;
	R1(3, 2) = 0.0;
	R1(3, 3) = 1.0;
	R1(3, 4) = 0.0;
	R1(4, 0) = 0.0;
	R1(4, 1) = 0.0;
	R1(4, 2) = 0.0;
	R1(4, 3) = 0.0;
	R1(4, 4) = 1.0;
	std::vector<double> w1(row);
	w1[0] = 0.0;
	w1[1] = 0.0;
	w1[2] = 0.0;
	w1[3] = 0.0;
	w1[4] = 0.0;

	Assign assignment1;
	assignment1.Map = R1;
	assignment1.b = w1;

	// The transition label is   t15

	math::matrix<double> R2;
	row = 5;
	col = 5;
	R2.resize(row, col);
	R2(0, 0) = 1.0;
	R2(0, 1) = 0.0;
	R2(0, 2) = 0.0;
	R2(0, 3) = 0.0;
	R2(0, 4) = 0.0;
	R2(1, 0) = 0.0;
	R2(1, 1) = 1.0;
	R2(1, 2) = 0.0;
	R2(1, 3) = 0.0;
	R2(1, 4) = 0.0;
	R2(2, 0) = 0.0;
	R2(2, 1) = 0.0;
	R2(2, 2) = 1.0;
	R2(2, 3) = 0.0;
	R2(2, 4) = 0.0;
	R2(3, 0) = 0.0;
	R2(3, 1) = 0.0;
	R2(3, 2) = 0.0;
	R2(3, 3) = 1.0;
	R2(3, 4) = 0.0;
	R2(4, 0) = 0.0;
	R2(4, 1) = 0.0;
	R2(4, 2) = 0.0;
	R2(4, 3) = 0.0;
	R2(4, 4) = 1.0;
	std::vector<double> w2(row);
	w2[0] = 0.0;
	w2[1] = 0.0;
	w2[2] = 0.0;
	w2[3] = 0.0;
	w2[4] = 0.0;

	Assign assignment2;
	assignment2.Map = R2;
	assignment2.b = w2;

	// The transition label is   t19

	math::matrix<double> R3;
	row = 5;
	col = 5;
	R3.resize(row, col);
	R3(0, 0) = 1.0;
	R3(0, 1) = 0.0;
	R3(0, 2) = 0.0;
	R3(0, 3) = 0.0;
	R3(0, 4) = 0.0;
	R3(1, 0) = 0.0;
	R3(1, 1) = 1.0;
	R3(1, 2) = 0.0;
	R3(1, 3) = 0.0;
	R3(1, 4) = 0.0;
	R3(2, 0) = 0.0;
	R3(2, 1) = 0.0;
	R3(2, 2) = 1.0;
	R3(2, 3) = 0.0;
	R3(2, 4) = 0.0;
	R3(3, 0) = 0.0;
	R3(3, 1) = 0.0;
	R3(3, 2) = 0.0;
	R3(3, 3) = 1.0;
	R3(3, 4) = 0.0;
	R3(4, 0) = 0.0;
	R3(4, 1) = 0.0;
	R3(4, 2) = 0.0;
	R3(4, 3) = 0.0;
	R3(4, 4) = 1.0;
	std::vector<double> w3(row);
	w3[0] = 0.0;
	w3[1] = 0.0;
	w3[2] = 0.0;
	w3[3] = 0.0;
	w3[4] = 0.0;

	Assign assignment3;
	assignment3.Map = R3;
	assignment3.b = w3;

	// The transition label is   t20

	math::matrix<double> R4;
	row = 5;
	col = 5;
	R4.resize(row, col);
	R4(0, 0) = 1.0;
	R4(0, 1) = 0.0;
	R4(0, 2) = 0.0;
	R4(0, 3) = 0.0;
	R4(0, 4) = 0.0;
	R4(1, 0) = 0.0;
	R4(1, 1) = 1.0;
	R4(1, 2) = 0.0;
	R4(1, 3) = 0.0;
	R4(1, 4) = 0.0;
	R4(2, 0) = 0.0;
	R4(2, 1) = 0.0;
	R4(2, 2) = 1.0;
	R4(2, 3) = 0.0;
	R4(2, 4) = 0.0;
	R4(3, 0) = 0.0;
	R4(3, 1) = 0.0;
	R4(3, 2) = 0.0;
	R4(3, 3) = 1.0;
	R4(3, 4) = 0.0;
	R4(4, 0) = 0.0;
	R4(4, 1) = 0.0;
	R4(4, 2) = 0.0;
	R4(4, 3) = 0.0;
	R4(4, 4) = 1.0;
	std::vector<double> w4(row);
	w4[0] = 0.0;
	w4[1] = 0.0;
	w4[2] = 0.0;
	w4[3] = 0.0;
	w4[4] = 0.0;

	Assign assignment4;
	assignment4.Map = R4;
	assignment4.b = w4;

	// The transition label is   t1

	math::matrix<double> R5;
	row = 5;
	col = 5;
	R5.resize(row, col);
	R5(0, 0) = 1.0;
	R5(0, 1) = 0.0;
	R5(0, 2) = 0.0;
	R5(0, 3) = 0.0;
	R5(0, 4) = 0.0;
	R5(1, 0) = 0.0;
	R5(1, 1) = 1.0;
	R5(1, 2) = 0.0;
	R5(1, 3) = 0.0;
	R5(1, 4) = 0.0;
	R5(2, 0) = 0.0;
	R5(2, 1) = 0.0;
	R5(2, 2) = 1.0;
	R5(2, 3) = 0.0;
	R5(2, 4) = 0.0;
	R5(3, 0) = 0.0;
	R5(3, 1) = 0.0;
	R5(3, 2) = 0.0;
	R5(3, 3) = 1.0;
	R5(3, 4) = 0.0;
	R5(4, 0) = 0.0;
	R5(4, 1) = 0.0;
	R5(4, 2) = 0.0;
	R5(4, 3) = 0.0;
	R5(4, 4) = 1.0;
	std::vector<double> w5(row);
	w5[0] = 0.0;
	w5[1] = 0.0;
	w5[2] = 0.0;
	w5[3] = 0.0;
	w5[4] = 0.0;

	Assign assignment5;
	assignment5.Map = R5;
	assignment5.b = w5;

	// The transition label is   t2

	math::matrix<double> R6;
	row = 5;
	col = 5;
	R6.resize(row, col);
	R6(0, 0) = 1.0;
	R6(0, 1) = 0.0;
	R6(0, 2) = 0.0;
	R6(0, 3) = 0.0;
	R6(0, 4) = 0.0;
	R6(1, 0) = 0.0;
	R6(1, 1) = 1.0;
	R6(1, 2) = 0.0;
	R6(1, 3) = 0.0;
	R6(1, 4) = 0.0;
	R6(2, 0) = 0.0;
	R6(2, 1) = 0.0;
	R6(2, 2) = 1.0;
	R6(2, 3) = 0.0;
	R6(2, 4) = 0.0;
	R6(3, 0) = 0.0;
	R6(3, 1) = 0.0;
	R6(3, 2) = 0.0;
	R6(3, 3) = 1.0;
	R6(3, 4) = 0.0;
	R6(4, 0) = 0.0;
	R6(4, 1) = 0.0;
	R6(4, 2) = 0.0;
	R6(4, 3) = 0.0;
	R6(4, 4) = 1.0;
	std::vector<double> w6(row);
	w6[0] = 0.0;
	w6[1] = 0.0;
	w6[2] = 0.0;
	w6[3] = 0.0;
	w6[4] = 0.0;

	Assign assignment6;
	assignment6.Map = R6;
	assignment6.b = w6;

	// The transition label is   t3

	math::matrix<double> R7;
	row = 5;
	col = 5;
	R7.resize(row, col);
	R7(0, 0) = 1.0;
	R7(0, 1) = 0.0;
	R7(0, 2) = 0.0;
	R7(0, 3) = 0.0;
	R7(0, 4) = 0.0;
	R7(1, 0) = 0.0;
	R7(1, 1) = 1.0;
	R7(1, 2) = 0.0;
	R7(1, 3) = 0.0;
	R7(1, 4) = 0.0;
	R7(2, 0) = 0.0;
	R7(2, 1) = 0.0;
	R7(2, 2) = 1.0;
	R7(2, 3) = 0.0;
	R7(2, 4) = 0.0;
	R7(3, 0) = 0.0;
	R7(3, 1) = 0.0;
	R7(3, 2) = 0.0;
	R7(3, 3) = 1.0;
	R7(3, 4) = 0.0;
	R7(4, 0) = 0.0;
	R7(4, 1) = 0.0;
	R7(4, 2) = 0.0;
	R7(4, 3) = 0.0;
	R7(4, 4) = 1.0;
	std::vector<double> w7(row);
	w7[0] = 0.0;
	w7[1] = 0.0;
	w7[2] = 0.0;
	w7[3] = 0.0;
	w7[4] = 0.0;

	Assign assignment7;
	assignment7.Map = R7;
	assignment7.b = w7;

	// The transition label is   t9

	math::matrix<double> R8;
	row = 5;
	col = 5;
	R8.resize(row, col);
	R8(0, 0) = 1.0;
	R8(0, 1) = 0.0;
	R8(0, 2) = 0.0;
	R8(0, 3) = 0.0;
	R8(0, 4) = 0.0;
	R8(1, 0) = 0.0;
	R8(1, 1) = 1.0;
	R8(1, 2) = 0.0;
	R8(1, 3) = 0.0;
	R8(1, 4) = 0.0;
	R8(2, 0) = 0.0;
	R8(2, 1) = 0.0;
	R8(2, 2) = 1.0;
	R8(2, 3) = 0.0;
	R8(2, 4) = 0.0;
	R8(3, 0) = 0.0;
	R8(3, 1) = 0.0;
	R8(3, 2) = 0.0;
	R8(3, 3) = 1.0;
	R8(3, 4) = 0.0;
	R8(4, 0) = 0.0;
	R8(4, 1) = 0.0;
	R8(4, 2) = 0.0;
	R8(4, 3) = 0.0;
	R8(4, 4) = 1.0;
	std::vector<double> w8(row);
	w8[0] = 0.0;
	w8[1] = 0.0;
	w8[2] = 0.0;
	w8[3] = 0.0;
	w8[4] = 0.0;

	Assign assignment8;
	assignment8.Map = R8;
	assignment8.b = w8;

	// The transition label is   t10

	math::matrix<double> R9;
	row = 5;
	col = 5;
	R9.resize(row, col);
	R9(0, 0) = 1.0;
	R9(0, 1) = 0.0;
	R9(0, 2) = 0.0;
	R9(0, 3) = 0.0;
	R9(0, 4) = 0.0;
	R9(1, 0) = 0.0;
	R9(1, 1) = 1.0;
	R9(1, 2) = 0.0;
	R9(1, 3) = 0.0;
	R9(1, 4) = 0.0;
	R9(2, 0) = 0.0;
	R9(2, 1) = 0.0;
	R9(2, 2) = 1.0;
	R9(2, 3) = 0.0;
	R9(2, 4) = 0.0;
	R9(3, 0) = 0.0;
	R9(3, 1) = 0.0;
	R9(3, 2) = 0.0;
	R9(3, 3) = 1.0;
	R9(3, 4) = 0.0;
	R9(4, 0) = 0.0;
	R9(4, 1) = 0.0;
	R9(4, 2) = 0.0;
	R9(4, 3) = 0.0;
	R9(4, 4) = 1.0;
	std::vector<double> w9(row);
	w9[0] = 0.0;
	w9[1] = 0.0;
	w9[2] = 0.0;
	w9[3] = 0.0;
	w9[4] = 0.0;

	Assign assignment9;
	assignment9.Map = R9;
	assignment9.b = w9;

	// The transition label is   t11

	math::matrix<double> R10;
	row = 5;
	col = 5;
	R10.resize(row, col);
	R10(0, 0) = 1.0;
	R10(0, 1) = 0.0;
	R10(0, 2) = 0.0;
	R10(0, 3) = 0.0;
	R10(0, 4) = 0.0;
	R10(1, 0) = 0.0;
	R10(1, 1) = 1.0;
	R10(1, 2) = 0.0;
	R10(1, 3) = 0.0;
	R10(1, 4) = 0.0;
	R10(2, 0) = 0.0;
	R10(2, 1) = 0.0;
	R10(2, 2) = 1.0;
	R10(2, 3) = 0.0;
	R10(2, 4) = 0.0;
	R10(3, 0) = 0.0;
	R10(3, 1) = 0.0;
	R10(3, 2) = 0.0;
	R10(3, 3) = 1.0;
	R10(3, 4) = 0.0;
	R10(4, 0) = 0.0;
	R10(4, 1) = 0.0;
	R10(4, 2) = 0.0;
	R10(4, 3) = 0.0;
	R10(4, 4) = 1.0;
	std::vector<double> w10(row);
	w10[0] = 0.0;
	w10[1] = 0.0;
	w10[2] = 0.0;
	w10[3] = 0.0;
	w10[4] = 0.0;

	Assign assignment10;
	assignment10.Map = R10;
	assignment10.b = w10;

	// The transition label is   t12

	math::matrix<double> R11;
	row = 5;
	col = 5;
	R11.resize(row, col);
	R11(0, 0) = 1.0;
	R11(0, 1) = 0.0;
	R11(0, 2) = 0.0;
	R11(0, 3) = 0.0;
	R11(0, 4) = 0.0;
	R11(1, 0) = 0.0;
	R11(1, 1) = 1.0;
	R11(1, 2) = 0.0;
	R11(1, 3) = 0.0;
	R11(1, 4) = 0.0;
	R11(2, 0) = 0.0;
	R11(2, 1) = 0.0;
	R11(2, 2) = 1.0;
	R11(2, 3) = 0.0;
	R11(2, 4) = 0.0;
	R11(3, 0) = 0.0;
	R11(3, 1) = 0.0;
	R11(3, 2) = 0.0;
	R11(3, 3) = 1.0;
	R11(3, 4) = 0.0;
	R11(4, 0) = 0.0;
	R11(4, 1) = 0.0;
	R11(4, 2) = 0.0;
	R11(4, 3) = 0.0;
	R11(4, 4) = 1.0;
	std::vector<double> w11(row);
	w11[0] = 0.0;
	w11[1] = 0.0;
	w11[2] = 0.0;
	w11[3] = 0.0;
	w11[4] = 0.0;

	Assign assignment11;
	assignment11.Map = R11;
	assignment11.b = w11;

	// The transition label is   t16

	math::matrix<double> R12;
	row = 5;
	col = 5;
	R12.resize(row, col);
	R12(0, 0) = 1.0;
	R12(0, 1) = 0.0;
	R12(0, 2) = 0.0;
	R12(0, 3) = 0.0;
	R12(0, 4) = 0.0;
	R12(1, 0) = 0.0;
	R12(1, 1) = 1.0;
	R12(1, 2) = 0.0;
	R12(1, 3) = 0.0;
	R12(1, 4) = 0.0;
	R12(2, 0) = 0.0;
	R12(2, 1) = 0.0;
	R12(2, 2) = 1.0;
	R12(2, 3) = 0.0;
	R12(2, 4) = 0.0;
	R12(3, 0) = 0.0;
	R12(3, 1) = 0.0;
	R12(3, 2) = 0.0;
	R12(3, 3) = 1.0;
	R12(3, 4) = 0.0;
	R12(4, 0) = 0.0;
	R12(4, 1) = 0.0;
	R12(4, 2) = 0.0;
	R12(4, 3) = 0.0;
	R12(4, 4) = 1.0;
	std::vector<double> w12(row);
	w12[0] = 0.0;
	w12[1] = 0.0;
	w12[2] = 0.0;
	w12[3] = 0.0;
	w12[4] = 0.0;

	Assign assignment12;
	assignment12.Map = R12;
	assignment12.b = w12;

	// The transition label is   t17

	math::matrix<double> R13;
	row = 5;
	col = 5;
	R13.resize(row, col);
	R13(0, 0) = 1.0;
	R13(0, 1) = 0.0;
	R13(0, 2) = 0.0;
	R13(0, 3) = 0.0;
	R13(0, 4) = 0.0;
	R13(1, 0) = 0.0;
	R13(1, 1) = 1.0;
	R13(1, 2) = 0.0;
	R13(1, 3) = 0.0;
	R13(1, 4) = 0.0;
	R13(2, 0) = 0.0;
	R13(2, 1) = 0.0;
	R13(2, 2) = 1.0;
	R13(2, 3) = 0.0;
	R13(2, 4) = 0.0;
	R13(3, 0) = 0.0;
	R13(3, 1) = 0.0;
	R13(3, 2) = 0.0;
	R13(3, 3) = 1.0;
	R13(3, 4) = 0.0;
	R13(4, 0) = 0.0;
	R13(4, 1) = 0.0;
	R13(4, 2) = 0.0;
	R13(4, 3) = 0.0;
	R13(4, 4) = 1.0;
	std::vector<double> w13(row);
	w13[0] = 0.0;
	w13[1] = 0.0;
	w13[2] = 0.0;
	w13[3] = 0.0;
	w13[4] = 0.0;

	Assign assignment13;
	assignment13.Map = R13;
	assignment13.b = w13;

	// The transition label is   t18

	math::matrix<double> R14;
	row = 5;
	col = 5;
	R14.resize(row, col);
	R14(0, 0) = 1.0;
	R14(0, 1) = 0.0;
	R14(0, 2) = 0.0;
	R14(0, 3) = 0.0;
	R14(0, 4) = 0.0;
	R14(1, 0) = 0.0;
	R14(1, 1) = 1.0;
	R14(1, 2) = 0.0;
	R14(1, 3) = 0.0;
	R14(1, 4) = 0.0;
	R14(2, 0) = 0.0;
	R14(2, 1) = 0.0;
	R14(2, 2) = 1.0;
	R14(2, 3) = 0.0;
	R14(2, 4) = 0.0;
	R14(3, 0) = 0.0;
	R14(3, 1) = 0.0;
	R14(3, 2) = 0.0;
	R14(3, 3) = 1.0;
	R14(3, 4) = 0.0;
	R14(4, 0) = 0.0;
	R14(4, 1) = 0.0;
	R14(4, 2) = 0.0;
	R14(4, 3) = 0.0;
	R14(4, 4) = 1.0;
	std::vector<double> w14(row);
	w14[0] = 0.0;
	w14[1] = 0.0;
	w14[2] = 0.0;
	w14[3] = 0.0;
	w14[4] = 0.0;

	Assign assignment14;
	assignment14.Map = R14;
	assignment14.b = w14;

	// The transition label is   t6

	math::matrix<double> R15;
	row = 5;
	col = 5;
	R15.resize(row, col);
	R15(0, 0) = 1.0;
	R15(0, 1) = 0.0;
	R15(0, 2) = 0.0;
	R15(0, 3) = 0.0;
	R15(0, 4) = 0.0;
	R15(1, 0) = 0.0;
	R15(1, 1) = 1.0;
	R15(1, 2) = 0.0;
	R15(1, 3) = 0.0;
	R15(1, 4) = 0.0;
	R15(2, 0) = 0.0;
	R15(2, 1) = 0.0;
	R15(2, 2) = 1.0;
	R15(2, 3) = 0.0;
	R15(2, 4) = 0.0;
	R15(3, 0) = 0.0;
	R15(3, 1) = 0.0;
	R15(3, 2) = 0.0;
	R15(3, 3) = 1.0;
	R15(3, 4) = 0.0;
	R15(4, 0) = 0.0;
	R15(4, 1) = 0.0;
	R15(4, 2) = 0.0;
	R15(4, 3) = 0.0;
	R15(4, 4) = 1.0;
	std::vector<double> w15(row);
	w15[0] = 0.0;
	w15[1] = 0.0;
	w15[2] = 0.0;
	w15[3] = 0.0;
	w15[4] = 0.0;

	Assign assignment15;
	assignment15.Map = R15;
	assignment15.b = w15;

	// The transition label is   t7

	math::matrix<double> R16;
	row = 5;
	col = 5;
	R16.resize(row, col);
	R16(0, 0) = 1.0;
	R16(0, 1) = 0.0;
	R16(0, 2) = 0.0;
	R16(0, 3) = 0.0;
	R16(0, 4) = 0.0;
	R16(1, 0) = 0.0;
	R16(1, 1) = 1.0;
	R16(1, 2) = 0.0;
	R16(1, 3) = 0.0;
	R16(1, 4) = 0.0;
	R16(2, 0) = 0.0;
	R16(2, 1) = 0.0;
	R16(2, 2) = 1.0;
	R16(2, 3) = 0.0;
	R16(2, 4) = 0.0;
	R16(3, 0) = 0.0;
	R16(3, 1) = 0.0;
	R16(3, 2) = 0.0;
	R16(3, 3) = 1.0;
	R16(3, 4) = 0.0;
	R16(4, 0) = 0.0;
	R16(4, 1) = 0.0;
	R16(4, 2) = 0.0;
	R16(4, 3) = 0.0;
	R16(4, 4) = 1.0;
	std::vector<double> w16(row);
	w16[0] = 0.0;
	w16[1] = 0.0;
	w16[2] = 0.0;
	w16[3] = 0.0;
	w16[4] = 0.0;

	Assign assignment16;
	assignment16.Map = R16;
	assignment16.b = w16;

	// The transition label is   t8

	math::matrix<double> R17;
	row = 5;
	col = 5;
	R17.resize(row, col);
	R17(0, 0) = 1.0;
	R17(0, 1) = 0.0;
	R17(0, 2) = 0.0;
	R17(0, 3) = 0.0;
	R17(0, 4) = 0.0;
	R17(1, 0) = 0.0;
	R17(1, 1) = 1.0;
	R17(1, 2) = 0.0;
	R17(1, 3) = 0.0;
	R17(1, 4) = 0.0;
	R17(2, 0) = 0.0;
	R17(2, 1) = 0.0;
	R17(2, 2) = 1.0;
	R17(2, 3) = 0.0;
	R17(2, 4) = 0.0;
	R17(3, 0) = 0.0;
	R17(3, 1) = 0.0;
	R17(3, 2) = 0.0;
	R17(3, 3) = 1.0;
	R17(3, 4) = 0.0;
	R17(4, 0) = 0.0;
	R17(4, 1) = 0.0;
	R17(4, 2) = 0.0;
	R17(4, 3) = 0.0;
	R17(4, 4) = 1.0;
	std::vector<double> w17(row);
	w17[0] = 0.0;
	w17[1] = 0.0;
	w17[2] = 0.0;
	w17[3] = 0.0;
	w17[4] = 0.0;

	Assign assignment17;
	assignment17.Map = R17;
	assignment17.b = w17;

	// The transition label is   t5

	math::matrix<double> R18;
	row = 5;
	col = 5;
	R18.resize(row, col);
	R18(0, 0) = 1.0;
	R18(0, 1) = 0.0;
	R18(0, 2) = 0.0;
	R18(0, 3) = 0.0;
	R18(0, 4) = 0.0;
	R18(1, 0) = 0.0;
	R18(1, 1) = 1.0;
	R18(1, 2) = 0.0;
	R18(1, 3) = 0.0;
	R18(1, 4) = 0.0;
	R18(2, 0) = 0.0;
	R18(2, 1) = 0.0;
	R18(2, 2) = 1.0;
	R18(2, 3) = 0.0;
	R18(2, 4) = 0.0;
	R18(3, 0) = 0.0;
	R18(3, 1) = 0.0;
	R18(3, 2) = 0.0;
	R18(3, 3) = 1.0;
	R18(3, 4) = 0.0;
	R18(4, 0) = 0.0;
	R18(4, 1) = 0.0;
	R18(4, 2) = 0.0;
	R18(4, 3) = 0.0;
	R18(4, 4) = 1.0;
	std::vector<double> w18(row);
	w18[0] = 0.0;
	w18[1] = 0.0;
	w18[2] = 0.0;
	w18[3] = 0.0;
	w18[4] = 0.0;

	Assign assignment18;
	assignment18.Map = R18;
	assignment18.b = w18;

	// The transition label is   t4

	math::matrix<double> R19;
	row = 5;
	col = 5;
	R19.resize(row, col);
	R19(0, 0) = 1.0;
	R19(0, 1) = 0.0;
	R19(0, 2) = 0.0;
	R19(0, 3) = 0.0;
	R19(0, 4) = 0.0;
	R19(1, 0) = 0.0;
	R19(1, 1) = 1.0;
	R19(1, 2) = 0.0;
	R19(1, 3) = 0.0;
	R19(1, 4) = 0.0;
	R19(2, 0) = 0.0;
	R19(2, 1) = 0.0;
	R19(2, 2) = 1.0;
	R19(2, 3) = 0.0;
	R19(2, 4) = 0.0;
	R19(3, 0) = 0.0;
	R19(3, 1) = 0.0;
	R19(3, 2) = 0.0;
	R19(3, 3) = 1.0;
	R19(3, 4) = 0.0;
	R19(4, 0) = 0.0;
	R19(4, 1) = 0.0;
	R19(4, 2) = 0.0;
	R19(4, 3) = 0.0;
	R19(4, 4) = 1.0;
	std::vector<double> w19(row);
	w19[0] = 0.0;
	w19[1] = 0.0;
	w19[2] = 0.0;
	w19[3] = 0.0;
	w19[4] = 0.0;

	Assign assignment19;
	assignment19.Map = R19;
	assignment19.b = w19;

	initial_polytope_I = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	transition::ptr t1 = transition::ptr(
			new transition(1, "t13", 2, 5, guard_polytope0, assignment0));
	transition::ptr t2 = transition::ptr(
			new transition(2, "t14", 2, 3, guard_polytope1, assignment1));
	transition::ptr t3 = transition::ptr(
			new transition(3, "t15", 2, 1, guard_polytope2, assignment2));
	transition::ptr t4 = transition::ptr(
			new transition(4, "t19", 3, 6, guard_polytope3, assignment3));
	transition::ptr t5 = transition::ptr(
			new transition(5, "t20", 3, 2, guard_polytope4, assignment4));
	transition::ptr t6 = transition::ptr(
			new transition(6, "t1", 4, 1, guard_polytope5, assignment5));
	transition::ptr t7 = transition::ptr(
			new transition(7, "t2", 4, 5, guard_polytope6, assignment6));
	transition::ptr t8 = transition::ptr(
			new transition(8, "t3", 4, 9, guard_polytope7, assignment7));
	transition::ptr t9 = transition::ptr(
			new transition(9, "t9", 5, 4, guard_polytope8, assignment8));
	transition::ptr t10 = transition::ptr(
			new transition(10, "t10", 5, 2, guard_polytope9, assignment9));
	transition::ptr t11 = transition::ptr(
			new transition(11, "t11", 5, 6, guard_polytope10, assignment10));
	transition::ptr t12 = transition::ptr(
			new transition(12, "t12", 5, 7, guard_polytope11, assignment11));
	transition::ptr t13 = transition::ptr(
			new transition(13, "t16", 6, 3, guard_polytope12, assignment12));
	transition::ptr t14 = transition::ptr(
			new transition(14, "t17", 6, 5, guard_polytope13, assignment13));
	transition::ptr t15 = transition::ptr(
			new transition(15, "t18", 6, 8, guard_polytope14, assignment14));
	transition::ptr t16 = transition::ptr(
			new transition(16, "t6", 7, 5, guard_polytope15, assignment15));
	transition::ptr t17 = transition::ptr(
			new transition(17, "t7", 7, 9, guard_polytope16, assignment16));
	transition::ptr t18 = transition::ptr(
			new transition(18, "t8", 7, 8, guard_polytope17, assignment17));
	transition::ptr t19 = transition::ptr(
			new transition(19, "t5", 9, 7, guard_polytope18, assignment18));
	transition::ptr t20 = transition::ptr(
			new transition(20, "t4", 9, 4, guard_polytope19, assignment19));

	std::list<transition::ptr> Out_Going_Trans_fromloc9;

	location::ptr l1 = location::ptr(
			new location(1, "BAD", system_dynamics0, invariant0, true,
					Out_Going_Trans_fromloc9));

	std::list<transition::ptr> Out_Going_Trans_fromloc5;

	Out_Going_Trans_fromloc5.push_back(t1);
	Out_Going_Trans_fromloc5.push_back(t2);
	Out_Going_Trans_fromloc5.push_back(t3);
	location::ptr l2 = location::ptr(
			new location(2, "loc5", system_dynamics1, invariant1, true,
					Out_Going_Trans_fromloc5));

	std::list<transition::ptr> Out_Going_Trans_fromloc7;

	Out_Going_Trans_fromloc7.push_back(t4);
	Out_Going_Trans_fromloc7.push_back(t5);
	location::ptr l3 = location::ptr(
			new location(3, "loc7", system_dynamics2, invariant2, true,
					Out_Going_Trans_fromloc7));

	std::list<transition::ptr> Out_Going_Trans_fromloc1;

	Out_Going_Trans_fromloc1.push_back(t6);
	Out_Going_Trans_fromloc1.push_back(t7);
	Out_Going_Trans_fromloc1.push_back(t8);
	location::ptr l4 = location::ptr(
			new location(4, "loc1", system_dynamics3, invariant3, true,
					Out_Going_Trans_fromloc1));

	std::list<transition::ptr> Out_Going_Trans_fromloc4;

	Out_Going_Trans_fromloc4.push_back(t9);
	Out_Going_Trans_fromloc4.push_back(t10);
	Out_Going_Trans_fromloc4.push_back(t11);
	Out_Going_Trans_fromloc4.push_back(t12);
	location::ptr l5 = location::ptr(
			new location(5, "loc4", system_dynamics4, invariant4, true,
					Out_Going_Trans_fromloc4));

	std::list<transition::ptr> Out_Going_Trans_fromloc6;

	Out_Going_Trans_fromloc6.push_back(t13);
	Out_Going_Trans_fromloc6.push_back(t14);
	Out_Going_Trans_fromloc6.push_back(t15);
	location::ptr l6 = location::ptr(
			new location(6, "loc6", system_dynamics5, invariant5, true,
					Out_Going_Trans_fromloc6));

	std::list<transition::ptr> Out_Going_Trans_fromloc3;

	Out_Going_Trans_fromloc3.push_back(t16);
	Out_Going_Trans_fromloc3.push_back(t17);
	Out_Going_Trans_fromloc3.push_back(t18);
	location::ptr l7 = location::ptr(
			new location(7, "loc3", system_dynamics6, invariant6, true,
					Out_Going_Trans_fromloc3));

	std::list<transition::ptr> Out_Going_Trans_fromloc8;

	location::ptr l8 = location::ptr(
			new location(8, "GOOD", system_dynamics7, invariant7, true,
					Out_Going_Trans_fromloc8));

	std::list<transition::ptr> Out_Going_Trans_fromloc2;

	Out_Going_Trans_fromloc2.push_back(t19);
	Out_Going_Trans_fromloc2.push_back(t20);
	location::ptr l9 = location::ptr(
			new location(9, "loc2", system_dynamics8, invariant8, true,
					Out_Going_Trans_fromloc2));

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

	// the variable to id map
	Hybrid_Automata.insert_to_map("x1", 0);
	Hybrid_Automata.insert_to_map("x2", 1);
	Hybrid_Automata.insert_to_map("v1", 2);
	Hybrid_Automata.insert_to_map("v2", 3);
	Hybrid_Automata.insert_to_map("t", 4);

	unsigned int initial_location_id = 9;
	symbolic_states::ptr S;
	int transition_id = 0;
	initial_state::ptr I = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I, S,
					transition_id));
	init_state_list.push_back(I);
}

