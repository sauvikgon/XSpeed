/*
 * BouncingBall.cpp
 *
 *  Created on: 25-Nov-2014
 *      Author: amit
 */

#include "Hybrid_Model_Parameters_Design/BouncingBall.h"
/*
 void SetBouncingBall_Parameters(hybrid_automata& Hybrid_Automata,
 std::list<initial_state::ptr>& init_state_list,
 ReachabilityParameters& reach_parameters) {

 typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
 polytope::ptr initial_polytope_I;
 polytope::ptr invariant;
 polytope::ptr gaurd_polytope;
 Dynamics system_dynamics;

 math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixV,
 invariantConstraintsMatrix, gaurdConstraintsMatrix, Amatrix,
 Bmatrix;
 std::vector<double> boundValueI, boundValueV, invariantBoundValue,
 gaurdBoundValue;
 int boundSignI, invariantBoundSign, gaurdBoundSign, boundSignV;

 size_type row, col;

 //Polytope I Declaration in the form of Ax<=b
 //Input Polytope I as a line(bar) 10<=x(position)<=10.2 y(velocity)== 0.
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

 boundValueI.resize(4);
 boundValueI[0] = 10.2;
 boundValueI[1] = -10;
 boundValueI[2] = 0;
 boundValueI[3] = 0;

 boundSignI = 1;

 // Change in dynamics system  dx/dt=+v and dv/dt = -g
 ConstraintsMatrixV.resize(row, col);
 ConstraintsMatrixV(0, 0) = 0;
 ConstraintsMatrixV(0, 1) = -1;
 ConstraintsMatrixV(1, 0) = 0;
 ConstraintsMatrixV(1, 1) = 1;
 ConstraintsMatrixV(2, 0) = -1;
 ConstraintsMatrixV(2, 1) = 0;
 ConstraintsMatrixV(3, 0) = 1;
 ConstraintsMatrixV(3, 1) = 0;

 boundValueV.resize(4);
 boundValueV[0] = 1; //10;
 boundValueV[1] = -1; //-10;
 boundValueV[2] = 0;
 boundValueV[3] = 0;

 boundSignV = 1;

 row = 2;
 col = 2;
 Amatrix.resize(row, col);
 Amatrix(0, 0) = 0;
 Amatrix(0, 1) = 1;
 Amatrix(1, 0) = 0;
 Amatrix(1, 1) = 0;

 Bmatrix.resize(row, col);
 Bmatrix(0, 0) = 0;
 Bmatrix(0, 1) = 0;
 Bmatrix(1, 0) = 0;
 Bmatrix(1, 1) = 1;

 row = 3;
 col = 2;
 gaurdConstraintsMatrix.resize(row, col);
 gaurdConstraintsMatrix(0, 0) = 1;
 gaurdConstraintsMatrix(0, 1) = 0;
 gaurdConstraintsMatrix(1, 0) = -1;
 gaurdConstraintsMatrix(1, 1) = 0;
 gaurdConstraintsMatrix(2, 0) = 0;
 gaurdConstraintsMatrix(2, 1) = 1;

 gaurdBoundValue.resize(3);
 gaurdBoundValue[0] = 0;
 gaurdBoundValue[1] = 1;
 gaurdBoundValue[2] = 0; //gaurd is:: Position==0 and velocity <=0         0 <=x<= 0 and y<=0

 gaurdBoundSign = 1;

 * Invariant constraint : position >=0
 *  (x >= 0) or (-x <= 0)

 row = 1;
 col = 2;
 invariantConstraintsMatrix.resize(row, col);
 invariantConstraintsMatrix(0, 0) = -1;
 invariantConstraintsMatrix(0, 1) = 0;

 invariantBoundValue.resize(1);
 invariantBoundValue[0] = -0;

 invariantBoundSign = 1;

 //invariant.setPolytope(invariantConstraintsMatrix, invariantBoundValue,invariantBoundSign);
 invariant = polytope::ptr(
 new polytope(invariantConstraintsMatrix, invariantBoundValue,
 invariantBoundSign));
 // Invariant Initialised above
 //ReachParameters.TotalDirections(lastDirs + eachInvDirection + 1, i) = invariant->getCoeffMatrix()(eachInvDirection, i);

 system_dynamics.isEmptyMatrixA = false;
 system_dynamics.MatrixA = Amatrix;

 system_dynamics.isEmptyMatrixB = false;
 system_dynamics.MatrixB = Bmatrix;

 system_dynamics.isEmptyC = true;

 //system_dynamics.U->setPolytope(ConstraintsMatrixV, boundValueV, boundSignV);
 system_dynamics.U = polytope::ptr(
 new polytope(ConstraintsMatrixV, boundValueV, boundSignV));
 //	Dynamics Initalised ---------------------

 // Initial Polytope is initialised
 //initial_polytope_I.setPolytope(ConstraintsMatrixI, boundValueI, boundSignI);
 initial_polytope_I = polytope::ptr(
 new polytope(ConstraintsMatrixI, boundValueI, boundSignI));
 //--------------
 //gaurd_polytope.setPolytope(gaurdConstraintsMatrix, gaurdBoundValue,	gaurdBoundSign);
 gaurd_polytope = polytope::ptr(
 new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
 gaurdBoundSign));


 math::matrix<double> inv_directions;
 inv_directions.resize(2, 2);
 inv_directions(0, 0) = -1;			// L1 directions
 inv_directions(0, 1) = 0;
 inv_directions(1, 0) = 1;			// L2 directions
 inv_directions(1, 1) = 0;
 //some improvement has to be done here later to avoid repeated Direction in the case of Box
 //	reach_parameters.InvariantDirections = inv_directions;
 reach_parameters.InvariantExists = true;	//Invariant exists.
 //Invariant's Directions iniatialised ------



 * Transition Dynamics  Rx + w where R is the Assignment Mapping and w is a vector

 math::matrix<double> R; //Transition Dynamics
 row = 2;
 col = 2;
 R.resize(row, col);
 R(0, 0) = 1;
 R(0, 1) = 0;
 R(1, 0) = 0;
 R(1, 1) = -0.75;

 std::vector<double> w(2);
 w[0] = 0;
 w[1] = 0;

 Assign assignment;
 assignment.Map = R;
 assignment.b = w;

 transition::ptr trans = transition::ptr(
 new transition(1, "hop", 1, 1, gaurd_polytope, assignment));
 location::ptr source;
 source = location::ptr(new location());
 source->setLocId(1);
 source->setName("Always");
 source->setSystem_Dynamics(system_dynamics);
 source->setInvariant(invariant);
 source->setInvariantExists(true);
 source->add_Out_Going_Transition(trans);

 int dim = initial_polytope_I->getSystemDimension();

 Hybrid_Automata.addInitial_Location(source);
 Hybrid_Automata.addLocation(source);
 Hybrid_Automata.setDimension(dim);

 Hybrid_Automata.insert_to_map("x", 0);
 Hybrid_Automata.insert_to_map("v", 1);

 discrete_set d_set;		//now not needed
 d_set.insert_element(1);

 unsigned int initial_location_id = 1; //the initial Location ID
 symbolic_states::ptr S; //null_pointer as there is no instantiation
 //	S=symbolic_states::ptr (new symbolic_states());
 int transition_id = 0; //initial location no transition taken yet
 initial_state::ptr Init_state;

 //	Init_state = initial_state::ptr(
 //			new initial_state(initial_location_id, initial_polytope_I, S,
 //					transition_id));

 init_state_list.push_back(Init_state);

 }
 */

void SetBouncingBall_Parameters(hybrid_automata& Hybrid_Automata,
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
			invariantConstraintsMatrix, guardConstraintsMatrix, Amatrix,
			Bmatrix, forbiddenMatrixI;

	std::vector<double> boundValueI, boundValueV, C, invariantBoundValue,
			guardBoundValue, boundValueF;

	int boundSignI = 1, invariantBoundSign = 1, guardBoundSign = 1, boundSignV =
			1;

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

	system_dynamics.isEmptyMatrixB = true;

	C.resize(row);
	C.assign(row, 0);
	C[1] = -9.81;
	system_dynamics.isEmptyC = false;
	system_dynamics.C = C;

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

	system_dynamics.U = polytope::ptr(new polytope(true));

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

	Hybrid_Automata.addInitial_Location(l);
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

// ************* Section required for setting Reach Parameters & User Options *************
	/*unsigned int Directions_Type = 1;
	 unsigned int iter_max = 0;
	 double time_horizon = 1.0;
	 double sampling_time = 0.01;
	 std::vector<std::string> output_variables;
	 output_variables.push_back("x");
	 output_variables.push_back("v");

	 op.set_timeStep(sampling_time);
	 op.set_timeHorizon(time_horizon);
	 op.set_bfs_level(iter_max);
	 op.set_directionTemplate(Directions_Type);

	 int x1 = Hybrid_Automata.get_index(output_variables[0]);
	 int x2 = Hybrid_Automata.get_index(output_variables[1]);
	 op.set_first_plot_dimension(x1);
	 op.set_second_plot_dimension(x2);
	 reach_parameters.TimeBound = op.get_timeHorizon();
	 reach_parameters.Iterations = (unsigned int) op.get_timeHorizon()/ op.get_timeStep();
	 reach_parameters.time_step = op.get_timeStep();

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
	 reach_parameters.Directions = Real_Directions;*/
}
