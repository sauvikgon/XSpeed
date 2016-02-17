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

public:
	typedef boost::shared_ptr<simulation> ptr;
	simulation();
	simulation(unsigned int dim, unsigned int samples, Dynamics Dyn, double rel_tol=1e-6, double abs_tol=1e-8){
		dimension = dim;
		N=samples;
		reltol = rel_tol;
		abstol = abs_tol;
		D = Dyn;
	}
	virtual ~simulation();
	std::vector<double> simulate(std::vector<double>, double time);
};

#endif /* SIMULATION_H_ */
