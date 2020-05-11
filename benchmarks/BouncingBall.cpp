/*
 * BouncingBall.cpp
 *
 *  Created on: 25-Nov-2014
 *      Author: amit
 */

#include "../benchmarks/BouncingBall.h"

void SetBouncingBall(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
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

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix, Bmatrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV, invariantBoundValue,
			guardBoundValue, boundValueF;

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1;

	Assign assignment;
	math::matrix<double> R;

// The mode name is  always

	row = 2;
	col = 2;
	Amatrix.resize(row, col);
	Amatrix.clear();
	Amatrix(0, 1) = 1.0;
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = false;

	Amatrix.matrix_Identity(col,Bmatrix);
	system_dynamics.MatrixB = Bmatrix;

	ConstraintsMatrixV.resize(4, 2);
	ConstraintsMatrixV.clear();
	ConstraintsMatrixV(0,0)=1;
	ConstraintsMatrixV(1,0)=-1;
	ConstraintsMatrixV(2,1)=1;
	ConstraintsMatrixV(3,1)=-1;
	
	boundValueV.resize(4,0);
	boundValueV[2] = -1; // This is the assumed acceleration due to gravity
	boundValueV[3] = 1;

	system_dynamics.U = polytope::ptr(new polytope(ConstraintsMatrixV, boundValueV, 1) );
	
	system_dynamics.isEmptyC = true;

	row = 1;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix.clear();
	invariantConstraintsMatrix(0, 0) = -1.0;

	invariantBoundValue.resize(row);
	invariantBoundValue.assign(row, 0);
	invariant = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	

	std::list<transition::ptr> Out_Going_Trans_fromalways;

// The transition label is hop

// Original guard: x <= 0 & v < 0

	row = 2;
	col = 2;

	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix.clear();
	guardConstraintsMatrix(0, 0) = 1.0;
	guardConstraintsMatrix(1, 1) = 1.0;

	guardBoundValue.resize(row);
	guardBoundValue.assign(row, 0);
	guard_polytope = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

	row = 2;
	col = 2;
	R.resize(row, col);
	R.clear();
	R(0, 0) = 1.0;
	R(1, 1) = -0.75;
	std::vector<double> w(row);
	w.assign(row, 0);

	assignment.Map = R;
	assignment.b = w;

	t = transition::ptr(
			new transition(1, "hop", 1, 1, guard_polytope, assignment));

	Out_Going_Trans_fromalways.push_back(t);
	l = location::ptr(
			new location(1, "always", system_dynamics, invariant, true,
					Out_Going_Trans_fromalways));

	Hybrid_Automata.addInitialLocation(l);
	Hybrid_Automata.addLocation(l);

	row = 4;
	col = 2;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI.clear();
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(3, 1) = -1;
	boundValueI.resize(row);
	boundValueI.assign(row, 0);
	boundValueI[0] = 10.2;
	boundValueI[1] = -10;

	initial_polytope_I0 = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

	dim = initial_polytope_I0->getSystemDimension();
	int transition_id = 0;
	unsigned int initial_location_id = 1;

	symbolic_states::ptr S0;

	initial_state::ptr I0 = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I0, S0,
					transition_id));

	init_state_list.push_back(I0);
	Hybrid_Automata.setDimension(dim);

	Hybrid_Automata.insert_to_map("x", 0);
	Hybrid_Automata.insert_to_map("v", 1);

}
