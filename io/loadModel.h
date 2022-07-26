#ifndef __LOAD_MODEL_H
#define __LOAD_MODEL_H

#include <application/macroDefinitions.h>
#include <application/sfDirections.h>
#include <application/sfUtility.h>
#include <application/structures.h>
#include <core/math/uniSphere.h>
#include <cstring>
#include <utility>


#include "core/continuous/polytope/polytope.h"
#include "core/hybridAutomata/hybridAutomata.h"
#include "core/symbolicStates/initialState.h"
#include "application/userOptions.h"

typedef std::pair<int, polytope::ptr> forbidden;

/* Sets the reachability options given by the user */

void set_params(hybrid_automata& ha, std::list<initial_state::ptr>& init_state,
		userOptions& op, ReachabilityParameters& reach_parameters,
		std::vector<forbidden>& forbidden_states);

/* Applies linear transformation on the directions. The result is stores in res.
 * Used in dealing with output variables equated to linear combination of state
 * variables.
 */
void transformDirections(hybrid_automata& ha, std::vector<std::vector<double> >& directions,
		std::vector<std::vector<double> >& res);

#endif
