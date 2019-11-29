/*
 * user_model.h
 *
 *  Created on: 26-Nov-2015
 *      Author: amit
 */

#ifndef USER_MODEL_H_
#define USER_MODEL_H_

#include "../../core/continuous/Polytope/Polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/HybridAutomata/Location.h"
#include "../../core/math/matrix.h"
#include "../../core/math/uni_sphere.h"	//for obtaining uniformly distributed directions
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"
#include "application/All_PP_Definition.h"
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "application/userOptions.h"


//void user_model(hybrid_automata& Hybrid_Automata,initial_state::ptr& init_state,ReachabilityParameters& reach_parameters);
void user_model(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters,
		userOptions& op);
void module1(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters,
		userOptions& op);
void module2(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters,
		userOptions& op);
void module3(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters,
		userOptions& op);
void module4(hybrid_automata& ha,
		std::list<initial_state::ptr>& init_state,
		ReachabilityParameters& reach_parameters,
		userOptions& op);

#endif /* USER_MODEL_H_ */
