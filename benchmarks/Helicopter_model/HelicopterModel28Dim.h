/*
 * HelicopterModel28Dim.h
 *
 *  Created on: 12-Oct-2014
 *      Author: amit
 */

#ifndef HELICOPTERMODEL28DIM_H_
#define HELICOPTERMODEL28DIM_H_

/*	Trying with 28 variables i.e., x1 to x28
 *
 * Basic Model Design requirements are ---
 *
 * Initial Polytope (take x values followed by u values and then t values)
 * Dynamics : Matrix A(take Aut), Matrix B(identity matrix) and Polytope U(for U take an Empty polytope)
 * Guard : Polytope	Not requred for Helicopter
 * Invariant : Polytope take a Universe polytope bounded for all cases ...  or invariant <= T; T=timebound
 * Transition Dynamics : Just a single location so no transition
 *
 */

#include <boost/numeric/ublas/matrix.hpp>
#include <iostream>
#include "application/DataStructureDirections.h"
#include <fstream>
#include <string>

#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <boost/config.hpp>
#include <boost/lexical_cast.hpp>
#include "../../core/continuous/Polytope/polytope.h"
#include "../../core/HybridAutomata/Hybrid_Automata.h"
#include "../../core/math/matrix.h"
#include "../../core/symbolic_states/initial_state.h"
#include "../../core/symbolic_states/symbolic_states.h"

using namespace std;
using namespace boost::numeric::ublas;
//using namespace boost;

/*void SetHelicopter_Parameters3(ReachabilityParameters& reach_parameters,
 polytope& initial_polytope_I, Dynamics& system_dynamics,
 polytope& invariant, polytope& guard_polytope) */

void SetHelicopter(hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr>& init_state_list,
		ReachabilityParameters& reach_parameters);

#endif /* HELICOPTERMODEL28DIM_H_ */
