/*
 * reachabilityCaller.h
 *
 *  Created on: 27-Oct-2016
 *      Author: amit
 */

#ifndef REACHABILITYCALLER_H_
#define REACHABILITYCALLER_H_

#include <core/reachability/agjh.h>
#include <core/reachability/asyncBFS.h>
#include <core/reachability/tpbfs.h>
#include "userOptions.h"
#include "counterExample/abstractCE.h"
#include "application/userOptions.h"
#include "utilities/statistics.h"
#include <list>

#include "core/reachability/reachability.h"
#include "core/symbolicStates/symbolicStates.h"

extern unsigned int ce_search_time;

void reachabilityCaller(hybrid_automata& H, std::list<initial_state::ptr>& I,
		ReachabilityParameters& reach_parameters, userOptions& user_options,
		int lp_solver_type, std::pair<int, polytope::ptr> forbidden_set,
		std::list<symbolic_states::ptr>& Symbolic_states_list,
		std::list<abstractCE::ptr>& ce_candidates);

#endif /* REACHABILITYCALLER_H_ */
