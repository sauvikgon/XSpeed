/*
 * simulationCaller.h
 *
 *  Created on: 26-Feb-2018
 *      Author: amit
 */

#ifndef SIMULATIONCALLER_H_
#define SIMULATIONCALLER_H_

#include "../io/load_model.h"
#include "counterExample/simulation.h"
#include "boost/timer/timer.hpp"


void simulationCaller(ReachabilityParameters& reach_parameters,
		hybrid_automata& ha, std::list<initial_state::ptr> init_state,
		userOptions& op);


#endif /* SIMULATIONCALLER_H_ */
