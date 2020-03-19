/*
 * load_model.cpp
 *
 *  Created on: 09-May-2016
 *      Author: rajarshi
 */

#include "../io/load_model.h"

void load_ha_models(std::list<initial_state::ptr>& init_state,
		hybrid_automata& ha, ReachabilityParameters& reach_parameters, userOptions& op){

	reach_parameters.TimeBound = op.get_timeHorizon(); //Total Time Interval
	reach_parameters.Iterations = (unsigned int) (op.get_timeHorizon() / op.get_timeStep()); // number of iterations
	reach_parameters.time_step = op.get_timeStep();
	//reach_parameters.Iterations = (unsigned int) (op.get_timeHorizon() / op.get_timeStep()); // number of iterations

	//Assigning the Model of the Hybrid System
	//	(1,2,3,4,5,6,7) = (BBALL, TBBALL, HELICOPTER, FIVEDIMSYS, NAVIGATION, CIRCLE, CIRCLE_FOUR_LOC)
	unsigned int HybridSystem_Model_Type = op.get_model();

	if (HybridSystem_Model_Type == BBALL) {
		SetBouncingBall_Parameters(ha, init_state, reach_parameters);
	}
	if (HybridSystem_Model_Type == TBBALL) {
		SetTimedBouncingBall_ParametersHystOutput(ha, init_state,	reach_parameters);
		//SetTimedBouncingBall_2initSet(ha, init_state, reach_parameters);
	}
	if (HybridSystem_Model_Type == HELICOPTER) {
		SetHelicopter_Parameters3(ha, init_state, reach_parameters);
	}
	if (HybridSystem_Model_Type == FIVEDIMSYS) {
		setSysParams(ha, init_state, reach_parameters);
	}

	if (HybridSystem_Model_Type == NAVIGATION_1) {
		set_nav04_timed(ha, init_state, reach_parameters);
		//Set_NavTimedEpsilonRelaxGuard(ha, init_state, reach_parameters);
		//SetNavigationBenchMark4Var(ha, init_state, reach_parameters); //Paper's Model
		//Set_NavTimed_Parameters(ha, init_state, reach_parameters);
	}

	if (HybridSystem_Model_Type == NAVIGATION_2) {
		SetNavigationModel2(ha, init_state, reach_parameters); //My own testing Model NAV2
	}

	if (HybridSystem_Model_Type == NAVIGATION_3) {
		SetNavigationModel4(ha, init_state, reach_parameters); //Model NAV04
	}

	if (HybridSystem_Model_Type == NAVIGATION_4) { // Model 8
		SetNavigationModel5by5Timed(ha, init_state, reach_parameters);
		//SetNavigationModel5by5(ha, init_state, reach_parameters); // This is the timed Model of NAV_5by5
		//SetNavigationNav5by5WithOutTime(ha, init_state, reach_parameters); //This is the un-timed Model NAV_5by5
	}

	if (HybridSystem_Model_Type == NAVIGATION_5) { // Model 9
		SetNavigationModel9by9Timed(ha,init_state,reach_parameters); // NAV_9by9 Timed model
	}

	if (HybridSystem_Model_Type == CIRCLE_ONE_LOC) {
		SetRotationCircleOneLocation_Parameters(ha, init_state, reach_parameters);
	}
	if (HybridSystem_Model_Type == CIRCLE_TWO_LOC) {
		//SetRotationCircle_Parameters(ha, init_state, reach_parameters);
		SetRotationTimedCircle_Parameters(ha, init_state, reach_parameters);
	}
	if (HybridSystem_Model_Type == CIRCLE_FOUR_LOC) {
		SetRotationCircle4Location_Parameters(ha, init_state, reach_parameters);
		//SetRotation_Navtimed_Parameters(ha, init_state,reach_parameters);
	}
	if (HybridSystem_Model_Type == OSCILLATOR) {
		setOscillatorTimed(ha, init_state, reach_parameters);
	}
	if (HybridSystem_Model_Type == 14) {

		//SetBilliardModel(ha, init_state, reach_parameters);

		//SetConstantMotion(ha, init_state,reach_parameters);	//Call to constant dynamic Model
		//Set_NavTimed_Parameters(ha, init_state, reach_parameters);
		//user_model(ha, init_state,reach_parameters);
		//Set_NavTimed_5by5(ha, init_state, reach_parameters);
		//SetNavigationModel9by9Timed(ha,init_state,reach_parameters);

		setNav30Timed(ha,init_state,reach_parameters);

		//setTTEthernetModel2(ha, init_state, reach_parameters);

		//---------------Not working models-------------
//amit		setbuild48(ha, init_state, reach_parameters);
		//setfwr(ha, init_state, reach_parameters);
		//setpllConv(ha, init_state, reach_parameters);
		//setheart(ha, init_state, reach_parameters);
		// --------------------------------------------


		//setTTEthernet5(ha, init_state, reach_parameters);

		//setmesh(ha, init_state, reach_parameters);	//precision issue

		//setplatoon_const_input(ha, init_state, reach_parameters); // dynamics with a constant input and deterministic transitions to c amd nc.
		//setplatoon(ha, init_state, reach_parameters); // deterministic transitions to communicating (c) and non-communicating modes (nc)
		//setplatoon_ndt(ha, init_state, reach_parameters); // non-deterministic transitions to c and nc modes.
		//setplatoon_na(ha, init_state, reach_parameters); // non-deterministic transitios with arbitrary transitions to c and nc modes.

		//setFisher_Star(ha,init_state,reach_parameters);		

		//set_watertank_controller(ha,init_state,reach_parameters);
		//setISS_270(ha,init_state,reach_parameters); // International Space Station-217 vars, continuous system.
		//SetTimedZigZag(ha,init_state,reach_parameters);
		//setSpacecraft(ha,init_state,reach_parameters);
		//setSpacecraftAbort(ha,init_state,reach_parameters);

	}
	if(HybridSystem_Model_Type == 16){
		//setMotorcade(ha,init_state,reach_parameters);
	}
	if(HybridSystem_Model_Type == 17){
		//setNav2u(ha,init_state,reach_parameters);
		//setNav3u(ha,init_state,reach_parameters);
		//setNav4u(ha,init_state,reach_parameters);
	}
	if(HybridSystem_Model_Type == 18){ // Platoon Model
		setplatoon_const_input(ha, init_state, reach_parameters); // dynamics with a constant input and deterministic transitions to c amd nc.
	}
	if(HybridSystem_Model_Type == 19){ // Timed Navigation instance 22 (15 x 15 locations)
		setNav22Timed(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 20){ // Timed Navigation instance 25 (20 x 20 locations)
		setNav25Timed(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 21){ // Timed Navigation instance navT02_Timed (20 x 20 locations) used in Int. J of STTT without input set
		setnavT02_Timedmodel(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 22){ // Timed Navigation instance navT04_Timed (25 x 25 locations) used in Int. J of STTT without input set
		setnavT04_Timedmodel(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 23){ // Timed Navigation instance navT04_Timed (25 x 25 locations) used in Int. J of STTT without input set
		setnavT13_Timedmodel(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 24){ // Timed Navigation instance navT07_Timed (25 x 25 locations) used in Int. J of STTT without input set
		setnavT07_Timedmodel(ha, init_state, reach_parameters);
	}

	if(HybridSystem_Model_Type == 25){ // vehicle_platoon model (5 Vehicles)
		set_platoon5_model(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 26){ // vehicle_platoon model (10 Vehicles)
		set_platoon10_model(ha, init_state, reach_parameters);
	}

	if(HybridSystem_Model_Type == 27){ // Filtered Oscillator model with 8 filters called
		set_f_osc_8_timed(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 28){ // Filtered Oscillator model with 32 filters called
		setf_osc_32_timedmodel(ha, init_state, reach_parameters);
	}
}

void load_model(std::list<initial_state::ptr>& init_state, hybrid_automata& ha,
		userOptions& op, ReachabilityParameters& reach_parameters,
		std::pair<int, polytope::ptr>& forbidden_set) {
	unsigned int row, col;

	//Loads the HA models and set the reach_parameters from user-options
	load_ha_models(init_state, ha, reach_parameters,op); //function re-used

//Assigning Directions
	unsigned int Directions_Type = op.get_directionTemplate(); //(1,2,>2) = (BOX, OCT, UNIFORM)

	unsigned int dims=0;
	for (std::list<initial_state::ptr>::iterator it=init_state.begin();it!=init_state.end();it++){
		dims = (*it)->getInitialSet()->getSystemDimension();
	}

	//Assigning the Number of Directions and Generating the Template Directions from the above given dimension of the model
	//todo:: needs to decide that, is this the right place to include Invariant direction
	//and also Redundant invariant directional constraints to be removed

	math::matrix<double> Real_Directions; //List of all directions
	std::vector<std::vector<double> > newDirections;

	if (Directions_Type == BOX) {
		unsigned int dir_nums = 2 * dims; //Axis Directions
		newDirections = generate_axis_directions(dims);
		get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here:: Temporary solution
		row = dir_nums;
		col = dims;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	if (Directions_Type == OCT) {
		unsigned int dir_nums = 2 * dims * dims; // Octagonal directions
		newDirections = get_octagonal_directions(dims);
		get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here:: Temporary solution
		row = dir_nums;
		col = dims;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	if (Directions_Type > 2) {
		unsigned int dir_nums = op.get_directionTemplate(); // ASSIGN HERE Number of Vectors/Directions for UNIform spear algorithm
	//	newDirections = math::uni_sphere(dir_nums, dims, 100, 0.0005);
		//In SpaceEx math::uni_sphere(nb, dim, 10000 * nb, 1e-3);
		newDirections = math::uni_sphere(dir_nums, dims, 10000 * dir_nums, 0.001);

		get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here:: Temporary solution
		row = dir_nums;
		col = dims;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	if (!op.get_forbidden_set().empty()) {
		string_to_poly(op.get_forbidden_set(), forbidden_set);
		//string_to_poly_HystFormat(op.get_forbidden_set(), forbidden_set);
	}
}

