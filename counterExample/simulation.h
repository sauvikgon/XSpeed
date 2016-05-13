/*
 * simulation.h
 *
 *  Created on: 12-Feb-2016
 *      Author: rajarshi
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_
#include <vector>
#include <cvode/cvode.h>
#include <nvector/nvector_serial.h>
#include <cvode/cvode_dense.h>
#include <sundials/sundials_dense.h>
#include <sundials/sundials_types.h>
#include "application/DataStructureDirections.h"

/*
 * A structure to return the last point in Invariant and the
 * time of crossing the invariant
 */
struct bound_sim
{
	std::vector<double> v;
	double cross_over_time;
};

/**
 * This class provides methods to simulate an ODE equation for a given
 * initial value.
 */
class simulation : public var_to_index_map {

	/** The number of discrete samples to be computed
	 * in solving the ODE, in order to get the simulation.

	int N;*/
	/**
	 * The simulation time_step. The number of samples is adjusted
	 * based on the Tfinal and the time_step as N = Tfinal/time_step.
	 */
	double time_step;
	/**
	 * The dimension of the ODE system.
	 */
	unsigned int dimension;
	Dynamics D;
	double reltol;
	double abstol;
	string filename;
	unsigned int x; // the output dimension for plotting wrt time.

public:
	typedef boost::shared_ptr<simulation> ptr;
	/** To store the end point of the simulation trajectory and its distance
	 *  from a given polytope.
	 */
//	typedef std::pair<std::vector<double>, double> simD;

	simulation();
	simulation(unsigned int dim, double step_size, Dynamics Dyn, double rel_tol=1e-6, double abs_tol=1e-8){
		dimension = dim;
		time_step = step_size;
		reltol = rel_tol;
		abstol = abs_tol;
		D = Dyn;
		filename=std::string();
		// default ploting dimension
		x = 0; // The plotting of this dimension is w.r.t time
	}
	virtual ~simulation();
	/**
	 * Sets the name of the output file to the parameter string.
	 * The parameter string should be the absolute path.
	 * The simulation shall be printed to this file if filename is not
	 * empty
	 */
	void set_outfile(std::string s){
		filename = s;
	}
	/**
	 * Returns the dimension of the simulation object.
	 */
	unsigned int get_system_dimension()
	{
		return dimension;
	}
	/**
	 * sets the projection dimensions to output the simulation points
	 * in a file
	 */
	void set_out_dimension(unsigned int i){
		x = i;
	}
	/*
	 * Set the simulation time_step
	 */
	void set_time_step(double t)
	{
		time_step = t;
	}
	/**
	 * Generates a simulation trace for time duration, starting at start_time.
	 * The initial state is given by the first parameter
	 */
	std::vector<double> simulate(std::vector<double>, double time);

	/**
	 * Generates a simulation trace for time duration, starting at start_time.
	 * The time instant, within the simulation time, when the polytope I is
	 * violated by the trace is returned and with the last simulation point
	 * that satisfied I, as a struct object
	 */
	bound_sim bounded_simulation(std::vector<double>, double time, polytope::ptr I);

};

#endif /* SIMULATION_H_ */
