/*
 * Oscillator.cpp
 *
 *  Created on: 10-May-2016
 *      Author: amit
 *
 *
 */

#include "../../benchmarks/oscillator_model/Oscillator.h"

/*
 * Reference for model is https://ths.rwth-aachen.de/research/projects/hypro/filtered-oscillator/
 *
 */
void SetOscillator(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters) {

	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	polytope::ptr initial_polytope_I;
	polytope::ptr invariant1, invariant2, invariant3, invariant4;
	polytope::ptr guard_polytope1, guard_polytope2, guard_polytope3,
			guard_polytope4;
	Dynamics system_dynamics;

	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix,
			Bmatrix;
	std::vector<double> boundValueI, boundValueV, invariantBoundValue,
			guardBoundValue;

	std::vector<double> vector_c;
	int boundSignI, invariantBoundSign, guardBoundSign;

	size_type row, col;

	unsigned int initial_location_id = 3; //the initial Location ID
// ********************* Initial Set Assignment **********************
	//Polytope I Declaration in the form of Ax<=b
	//Input Polytope I as a 0.2<=x<=0.3 and -0.1<=y<=0.1.
	row = 4;
	col = 2;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;

	boundValueI.resize(row);
	boundValueI[0] = 0.3;
	boundValueI[1] = -0.2;
	boundValueI[2] = 0.1;
	boundValueI[3] = 0.1;

	boundSignI = 1;
	// Initial Polytope is initialised
	initial_polytope_I = polytope::ptr(
			new polytope(ConstraintsMatrixI, boundValueI, boundSignI));
// ********************* Initial Set Assignment Done **********************
// **************************** Location ID=1 Label=np  ***************************

	//polytope U =0		not required

	//Dynamics  x' = -y and y' = x
	row = 2;
	col = 2;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = -2;
	Amatrix(0, 1) = 0;
	Amatrix(1, 0) = 0;
	Amatrix(1, 1) = -1;

	vector_c.resize(row);
	vector_c[0] = 1.4;
	vector_c[1] = -0.7;

	//Common Parameters : initial polytope and dynamics
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	system_dynamics.isEmptyC = false;
	system_dynamics.C = vector_c;

	system_dynamics.U = polytope::ptr(new polytope(true));//system_dynamics.U->setIsEmpty(true); //set empty

	//	Dynamics Initalised ---------------------
	//Location 'loc1' has Transition 't1' with guard is x==0 & y + 0.714268*x >= 0 and No Assignment so its identity i.e., x'=x and y'=y

	row = 3;
	col = 2;
	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = 1;
	guardConstraintsMatrix(0, 1) = 0;
	guardConstraintsMatrix(1, 0) = -1;
	guardConstraintsMatrix(1, 1) = 0;
	guardConstraintsMatrix(2, 0) = -0.714286;
	guardConstraintsMatrix(2, 1) = -1;

	guardBoundValue.resize(row);
	guardBoundValue[0] = 0;
	guardBoundValue[1] = 0;
	guardBoundValue[2] = 0;

	guardBoundSign = 1;
	guard_polytope1 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));

//Transition Dynamics  Rx + w where R is the Assignment Mapping and w is a vector
	math::matrix<double> R;	//Transition Dynamics
	row = 2;
	col = 2;
	R.resize(row, col);
	R(0, 0) = 1;
	R(0, 1) = 0;
	R(1, 0) = 0;
	R(1, 1) = 1;
	std::vector<double> w(row);
	w[0] = 0;
	w[1] = 0;
	Assign assignment;
	assignment.Map = R;
	assignment.b = w;
//--------------
	transition::ptr t1 = transition::ptr(
			new transition(1, "t1", 1, 3, guard_polytope1, assignment));

//Location 1:: Invariant constraint : x<=0 &  y >= -c/x0 * x
	row = 2;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = 1;
	invariantConstraintsMatrix(0, 1) = 0;
	invariantConstraintsMatrix(1, 0) = -0.714286;
	invariantConstraintsMatrix(1, 1) = -1;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 0;
	invariantBoundValue[1] = 0;
	invariantBoundSign = 1;
	invariant1 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	std::list<transition::ptr> Out_Going_Trans_fromLoc1;
	Out_Going_Trans_fromLoc1.push_back(t1);

	location::ptr l1 = location::ptr(
			new location(1, "loc1", system_dynamics, invariant1, true,
					Out_Going_Trans_fromLoc1));
// ********************** Initalised for Location 1 Done **********************

// **************************** Location ID=2 Label=pp  ***************************
//Location 'loc2' has Transition 't2' with guard is x<=0 & y + 0.714268*x == 0  and No Assignment so its identity i.e., x'=x and y'=y

	//Dynamics  matrix A is common for all locations
	row = 2;
	vector_c.resize(row);
	vector_c[0] = -1.4;
	vector_c[1] = 0.7;

	//Common Parameters : initial polytope and dynamics
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	system_dynamics.isEmptyC = false;
	system_dynamics.C = vector_c;

	system_dynamics.U = polytope::ptr(new polytope(true));//system_dynamics.U->setIsEmpty(true); //set empty

	row = 3;
	col = 2;
	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = 1;
	guardConstraintsMatrix(0, 1) = 0;
	guardConstraintsMatrix(1, 0) = 0.714286;
	guardConstraintsMatrix(1, 1) = 1;
	guardConstraintsMatrix(2, 0) = -0.714286;
	guardConstraintsMatrix(2, 1) = -1;

	guardBoundValue.resize(row);
	guardBoundValue[0] = 0;
	guardBoundValue[1] = 0;
	guardBoundValue[2] = 0;

	guardBoundSign = 1;
	guard_polytope2 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));
	transition::ptr t2 = transition::ptr(
			new transition(2, "t2", 2, 1, guard_polytope2, assignment));

//Location 2:: Invariant constraint : y <=0
	row = 2;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = 1;
	invariantConstraintsMatrix(0, 1) = 0;
	invariantConstraintsMatrix(1, 0) = 0.714286;
	invariantConstraintsMatrix(1, 1) = 1;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 0;
	invariantBoundValue[1] = 0;
	invariantBoundSign = 1;
	invariant2 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	std::list<transition::ptr> Out_Going_Trans_fromLoc2;
	Out_Going_Trans_fromLoc2.push_back(t2);

	location::ptr l2 = location::ptr(
			new location(2, "loc2", system_dynamics, invariant2, true,
					Out_Going_Trans_fromLoc2));
// ********************** Initalised for Location 2 Done **********************

// **************************** Location ID=3 Label=loc3  ***************************
//Location 'loc3' has Transition 't3' with guard is x>=0 & y + 0.714268*x == 0  and No Assignment so its identity i.e., x'=x and y'=y

	//Dynamics  x' = -y and y' = x
	row = 2;
	vector_c.resize(row);
	vector_c[0] = 1.4;
	vector_c[1] = -0.7;

	//Common Parameters : initial polytope and dynamics
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	system_dynamics.isEmptyC = false;
	system_dynamics.C = vector_c;

	system_dynamics.U = polytope::ptr(new polytope(true));//system_dynamics.U->setIsEmpty(true); //set empty
//	Dynamics Initalised ---------------------
			//Location 3::has transition t3::with guard is x>=0 & y<=0
	row = 3;
	col = 2;
	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = -1;
	guardConstraintsMatrix(0, 1) = 0;
	guardConstraintsMatrix(1, 0) = 0.714286;
	guardConstraintsMatrix(1, 1) = 1;
	guardConstraintsMatrix(2, 0) = -0.714286;
	guardConstraintsMatrix(2, 1) = -1;

	guardBoundValue.resize(row);
	guardBoundValue[0] = 0;
	guardBoundValue[1] = 0;
	guardBoundValue[2] = 0;
	guardBoundSign = 1;
	guard_polytope3 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));
	transition::ptr t3 = transition::ptr(
			new transition(3, "t3", 3, 4, guard_polytope3, assignment));

	//Location 3:: Invariant constraint : x<=0 & y<=0
	row = 2;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1;
	invariantConstraintsMatrix(0, 1) = 0;
	invariantConstraintsMatrix(1, 0) = -0.714286;
	invariantConstraintsMatrix(1, 1) = -1;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 0;
	invariantBoundValue[1] = 0;
	invariantBoundSign = 1;
	invariant3 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	std::list<transition::ptr> Out_Going_Trans_fromLoc3;
	Out_Going_Trans_fromLoc3.push_back(t3);

	location::ptr l3 = location::ptr(
			new location(3, "loc3", system_dynamics, invariant3, true,
					Out_Going_Trans_fromLoc3));
// ********************** Initalised for Location 3 Done **********************

// **************************** Location ID=4 Label=loc4  ***************************
//Location 'loc4' has Transition 't4' with guard is x==0 & y + 0.714286 * x <=0 and No Assignment so its identity i.e., x'=x and y'=y
	//Dynamics
	row = 2;
	vector_c.resize(row);
	vector_c[0] = -1.4;
	vector_c[1] = 0.7;

	//Common Parameters : initial polytope and dynamics
	system_dynamics.isEmptyMatrixA = false;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.isEmptyMatrixB = true;

	system_dynamics.isEmptyC = false;
	system_dynamics.C = vector_c;

	system_dynamics.U = polytope::ptr(new polytope(true));//system_dynamics.U->setIsEmpty(true); //set empty
	//	Dynamics Initalised ---------------------

	row = 3;
	col = 2;
	guardConstraintsMatrix.resize(row, col);
	guardConstraintsMatrix(0, 0) = 1;
	guardConstraintsMatrix(0, 1) = 0;
	guardConstraintsMatrix(1, 0) = -1;
	guardConstraintsMatrix(1, 1) = 0;
	guardConstraintsMatrix(2, 0) = 0.714286;
	guardConstraintsMatrix(2, 1) = 1;

	guardBoundValue.resize(row);
	guardBoundValue[0] = 0;
	guardBoundValue[1] = 0;
	guardBoundValue[2] = 0;
	guardBoundSign = 1;

	guard_polytope4 = polytope::ptr(
			new polytope(guardConstraintsMatrix, guardBoundValue,
					guardBoundSign));
	transition::ptr t4 = transition::ptr(
			new transition(4, "t4", 4, 2, guard_polytope4, assignment));

	//Location 4:: Invariant constraint : x<=0 & y<=-c/x0 * x
	row = 2;
	col = 2;
	invariantConstraintsMatrix.resize(row, col);
	invariantConstraintsMatrix(0, 0) = -1;
	invariantConstraintsMatrix(0, 1) = 0;
	invariantConstraintsMatrix(1, 0) = 0.714286;
	invariantConstraintsMatrix(1, 1) = 1;

	invariantBoundValue.resize(row);
	invariantBoundValue[0] = 0;
	invariantBoundValue[1] = 0;
	invariantBoundSign = 1;
	invariant4 = polytope::ptr(
			new polytope(invariantConstraintsMatrix, invariantBoundValue,
					invariantBoundSign));

	std::list<transition::ptr> Out_Going_Trans_fromLoc4;
	Out_Going_Trans_fromLoc4.push_back(t4);

	location::ptr l4 = location::ptr(
			new location(4, "loc4", system_dynamics, invariant4, true,
					Out_Going_Trans_fromLoc4));
// ********************** Initalised for Location 3 Done **********************

	int dim = initial_polytope_I->getSystemDimension();
	Hybrid_Automata.setDimension(dim);
	Hybrid_Automata.addInitialLocation(l3);
	Hybrid_Automata.addLocation(l1);
	Hybrid_Automata.addLocation(l2);
	Hybrid_Automata.addLocation(l3);
	Hybrid_Automata.addLocation(l4);

	Hybrid_Automata.insert_to_map("x", 0);
	Hybrid_Automata.insert_to_map("y", 1);

	symbolic_states::ptr S; //null_pointer as there is no instantiation
	int transition_id = 0; //initial location no transition taken yet
	initial_state::ptr I = initial_state::ptr(
			new initial_state(initial_location_id, initial_polytope_I, S,
					transition_id));

	init_state_list.push_back(I);
}

