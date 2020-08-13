
#ifndef SIMULATIONCALLER_H_
#define SIMULATIONCALLER_H_

#include <io/loadModel.h>
#include "counterExample/simulation.h"
#include "boost/timer/timer.hpp"


void simulationCaller(hybrid_automata& ha, std::list<initial_state::ptr>& init_state, ReachabilityParameters& reach_parameters,
		std::pair<int, polytope::ptr>& forbidden_set, userOptions& op);


#endif /* SIMULATIONCALLER_H_ */
