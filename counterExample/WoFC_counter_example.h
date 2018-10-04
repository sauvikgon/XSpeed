/*
 * WoFC_counter_example.h
 *
 *  Created on: 02-Oct-2018
 *      Author: amit
 */

#ifndef WOFC_COUNTER_EXAMPLE_H_
#define WOFC_COUNTER_EXAMPLE_H_

#include <list>
#include "core_system/symbolic_states/initial_state.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "counterExample/structuralPath.h"
#include "application/userOptions.h"
#include "counterExample/abstractCE.h"
#include "boost/timer/timer.hpp"



void runWoFC_counter_example(std::list<structuralPath::ptr>& allPaths,
		hybrid_automata& Hybrid_Automata,
		std::list<initial_state::ptr> init_state, polytope::ptr forbidden_set,
		userOptions& user_options);

bool gen_counter_example_WoFC(abstractCE::ptr abs_path,
		userOptions& user_options);

#endif /* WOFC_COUNTER_EXAMPLE_H_ */
