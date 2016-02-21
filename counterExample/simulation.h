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

/**
 * This class provides methods to simulate an ODE equation for a given
 * initial value.
 */
class simulation {

	/** The number of discrete samples to be computed
	 * in solving the ODE, in order to get the simulation.
	 */
	int N;
	/**
	 * The dimension of the ODE system.
	 */
	unsigned int dimension;
	Dynamics D;
	double reltol;
	double abstol;
	string filename;
	unsigned int x,y; // the output dimensions for plotting.

public:
	typedef boost::shared_ptr<simulation> ptr;
	/** To store the end point of the simulation trajectory and its distance
	 *  from a given polytope.
	 */
//	typedef std::pair<std::vector<double>, double> simD;

	simulation();
	simulation(unsigned int dim, unsigned int samples, Dynamics Dyn, double rel_tol=1e-6, double abs_tol=1e-8){
		dimension = dim;
		N = 1000;
		reltol = rel_tol;
		abstol = abs_tol;
		D = Dyn;
		filename=std::string();
		// default printing dimensions
		x = 0;
		y = 1;
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
	void set_out_dimension(unsigned int i, unsigned int j){
		x = i;
		y = j;
	}
	std::vector<double> simulate(std::vector<double>, double time);
};

#endif /* SIMULATION_H_ */
