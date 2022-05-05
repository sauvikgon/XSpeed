/*
 * load_model.cpp
 *
 *  Created on: 09-May-2016
 *      Author: rajarshi
 */

#include <io/loadModel.h>


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
	location::ptr locPtr = ha.getInitialLocation();
	Dynamics D = locPtr->getSystemDynamics();
	for(unsigned int i=0;i<directions.size();i++){
		std::vector<double> ell = directions[i];
		math::matrix<double> C;
		D.MatrixT.transpose(C);
		C.mult_vector(ell,ell);
		res[i] = ell;
	}
}
