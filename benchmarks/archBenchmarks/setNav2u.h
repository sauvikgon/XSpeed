/*
 * setNav2u.h
 *
 *  Created on: 28-Jun-2018
 *      Author: rajarshi
 */

#ifndef SETNAV2U_H_
#define SETNAV2U_H_


#include <application/macroDefinitions.h>
#include <application/sfDirections.h>
#include <application/sfUtility.h>
#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/hybridAutomata.h>
#include <core/math/uniSphere.h>
#include <core/symbolicStates/initialState.h>
#include <core/symbolicStates/symbolicStates.h>
#include "core/math/matrix.h"
#include "application/userOptions.h"

/**
 * Model from HBMC category of ARCH 2018 Friendly Competition
 */
void setNav2u(hybrid_automata& Hybrid_Automata, std::list<initial_state::ptr>& init_state_list, ReachabilityParameters& reach_parameters);



#endif /* SETNAV2U_H_ */
