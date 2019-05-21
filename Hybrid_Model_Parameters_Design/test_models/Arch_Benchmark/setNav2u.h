/*
 * setNav2u.h
 *
 *  Created on: 28-Jun-2018
 *      Author: rajarshi
 */

#ifndef SETNAV2U_H_
#define SETNAV2U_H_


#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/math/matrix.h"
#include "application/userOptions.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "core_system/math/uni_sphere.h"

/**
 * Model from HBMC category of ARCH 2018 Friendly Competition
 */
void setNav2u(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);



#endif /* SETNAV2U_H_ */
