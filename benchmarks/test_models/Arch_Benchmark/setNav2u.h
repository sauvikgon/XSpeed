/*
 * setNav2u.h
 *
 *  Created on: 28-Jun-2018
 *      Author: rajarshi
 */

#ifndef SETNAV2U_H_
#define SETNAV2U_H_


#include "../../../core/continuous/Polytope/Polytope.h"
#include "../../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../../core/math/matrix.h"
#include "../../../core/math/uni_sphere.h"
#include "../../../core/symbolic_states/initial_state.h"
#include "../../../core/symbolic_states/symbolic_states.h"
#include "application/userOptions.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"

/**
 * Model from HBMC category of ARCH 2018 Friendly Competition
 */
void setNav2u(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);



#endif /* SETNAV2U_H_ */
