/*
 * load_model.cpp
 *
 *  Created on: 09-May-2016
 *      Author: rajarshi
 */

#include <io/loadModel.h>

void load_ha_model(std::list<initial_state::ptr>& init_state,
		hybrid_automata& ha, ReachabilityParameters& reach_parameters, userOptions& op){
	
	unsigned int HybridSystem_Model_Type = op.get_model();

	if (HybridSystem_Model_Type == BBALL) {
		SetBouncingBall(ha, init_state, reach_parameters);
	}
	if (HybridSystem_Model_Type == TBBALL) {
		SetTimedBouncingBall(ha, init_state,	reach_parameters);
	}

	if (HybridSystem_Model_Type == FIVEDIMSYS) {
		setFiveDimSys(ha, init_state, reach_parameters);
	}

	if (HybridSystem_Model_Type == NAVIGATION_1) {
		set_nav04_timed(ha, init_state, reach_parameters);
	}

	if (HybridSystem_Model_Type == NAVIGATION_2) { // Model 8
		SetNavigationModel5by5Timed(ha, init_state, reach_parameters);
	}

	if (HybridSystem_Model_Type == OSCILLATOR) {
		setOscillatorTimed(ha, init_state, reach_parameters);
	}
	if (HybridSystem_Model_Type == 14) {

		//setNav30Timed(ha,init_state,reach_parameters);
		//set_watertank_controller(ha,init_state,reach_parameters);
	
	}

	if(HybridSystem_Model_Type == 18){ // Platoon Model
		//setplatoon_const_input(ha, init_state, reach_parameters); // dynamics with a constant input and deterministic transitions to c amd nc.
	}
	if(HybridSystem_Model_Type == 19){ // Timed Navigation instance 22 (15 x 15 locations)
		//setNav22Timed(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 20){ // Timed Navigation instance 25 (20 x 20 locations)
		//setNav25Timed(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 21){ // Timed Navigation instance navT02_Timed (20 x 20 locations) used in Int. J of STTT without input set
		//setnavT02_Timedmodel(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 22){ // Timed Navigation instance navT04_Timed (25 x 25 locations) used in Int. J of STTT without input set
		//setnavT04_Timedmodel(ha, init_state, reach_parameters);
	}

	if(HybridSystem_Model_Type == 25){ // vehicle_platoon model (5 Vehicles)
	//	set_platoon5_model(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 26){ // vehicle_platoon model (10 Vehicles)
	//	set_platoon10_model(ha, init_state, reach_parameters);
	}

	if(HybridSystem_Model_Type == 27){ // Filtered Oscillator model with 8 filters called
	//	set_f_osc_8_timed(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 28){ // Filtered Oscillator model with 32 filters called
	//	setf_osc_32_timedmodel(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 29){ // spacecraft rendezvous with no transition to mission abort
	//	setSpacecraft(ha, init_state, reach_parameters);
	}
	if(HybridSystem_Model_Type == 30){ // spacecraft rendezvous with mission abort
	//	setSpacecraftAbort(ha, init_state, reach_parameters);
	}
}

/* Sets the reachability options given by the user */

void set_params(hybrid_automata& ha, std::list<initial_state::ptr>& init_state,
		userOptions& op, ReachabilityParameters& reach_parameters,
		std::vector<forbidden>& forbidden_states) {

	unsigned int row, col;

	reach_parameters.TimeBound = op.get_timeHorizon(); //Total Time Interval
	reach_parameters.Iterations = (unsigned int) (op.get_timeHorizon() / op.get_timeStep()); // number of iterations
	reach_parameters.time_step = op.get_timeStep();
	
	//Assigning Directions
	unsigned int Directions_Type = op.get_directionTemplate(); 

	unsigned int dim=ha.ymap_size();
	if(dim==0){
		for (std::list<initial_state::ptr>::iterator it=init_state.begin();it!=init_state.end();it++){
			dim = (*it)->getInitialSet()->getSystemDimension();
		}
	}

	math::matrix<double> Real_Directions; //List of all directions
	std::vector<std::vector<double> > newDirections;

	if (Directions_Type == BOX) {
		unsigned int num_directions = 2 * dim; //Axis Directions
		newDirections = generate_axis_directions(dim);
		//if there are output variables related linearly with state variables
		if(ha.ymap_size()!=0){
			transformDirections(ha, newDirections, newDirections);
		}
		get_ublas_matrix(newDirections, Real_Directions);
		row = num_directions;
		col = dim;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	if (Directions_Type == OCT) {
		unsigned int num_directions = 2 * dim * dim; // Octagonal directions
		newDirections = get_octagonal_directions(dim);
		if(ha.ymap_size()!=0){
			transformDirections(ha, newDirections,newDirections);
		}
		get_ublas_matrix(newDirections, Real_Directions);
		row = num_directions;
		col = dim;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	if (Directions_Type > 2) {
		unsigned int dir_nums = op.get_directionTemplate(); // ASSIGN HERE Number of Vectors/Directions for UNIform spear algorithm
	//	newDirections = math::uni_sphere(dir_nums, dims, 100, 0.0005);
		//In SpaceEx math::uni_sphere(nb, dim, 10000 * nb, 1e-3);
		newDirections = math::uni_sphere(dir_nums, dim, 10000 * dir_nums, 0.001);
		get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here:: Temporary solution
		row = dir_nums;
		col = dim;
		reach_parameters.Directions.resize(row, col);
		reach_parameters.Directions = Real_Directions; //Direct Assignment
	}
	forbidden forbidden_set;
	if (!op.get_forbidden_set().empty()) {
		string_to_poly(op.get_forbidden_set(), forbidden_set);
		forbidden_states.clear(); // erase the cfg parsed input
		forbidden_states.push_back(forbidden_set); // overwrite with cdmline parsed input
	}
}
void transformDirections(hybrid_automata& ha, std::vector<std::vector<double> >& directions, std::vector<std::vector<double> >& res)
{
	// transform the directions with the MatrixT transformation matrix
	res.resize(directions.size());
	location::ptr locPtr = ha.getInitial_Location();
	Dynamics& D = locPtr->getSystem_Dynamics();
	for(unsigned int i=0;i<directions.size();i++){
		std::vector<double> ell = directions[i];
		math::matrix<double> C;
		D.MatrixT.transpose(C);
		C.mult_vector(ell,ell);
		res[i] = ell;
	}
}
