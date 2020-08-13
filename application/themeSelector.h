/*
 * themeSelector.h
 *
 *  Created on: 12-Aug-2020
 *      Author: rajarshi
 */

#ifndef XSPEED_THEMESELECTOR_H_
#define XSPEED_THEMESELECTOR_H_

#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/initialState.h>
#include <core/continuous/polytope/polytope.h>
#include <application/userOptions.h>
#include <utilities/cpuUtilities/cpuUtilities.h>	//cpu usage functions
#include <utilities/memUtilities/memUsage.h> //memory usage functions
#include "application/simulationCaller.h"
#include "counterExample/abstractCE.h"
#include <boost/algorithm/string/predicate.hpp>
#include "utilities/statistics.h"
#include "application/reachabilityCaller.h"
#include <counterExample/wofcCounterExample.h>

/*
 * Selects one out of the three themes of the tool:
 * 1. Simulation
 * 2. Reachability
 * 3. Falsification
 */

typedef std::pair<int, polytope::ptr> forbidden; //(locId,Polytope1)
typedef std::vector<forbidden> forbidden_states; // vector of forbidden symb states.

class themeSelector {

public:
	themeSelector();

	void setUserOps(userOptions& op);
	void setHa(hybrid_automata& ha);
	void setInit(std::list<initial_state::ptr>& init);
	void setReachParams(ReachabilityParameters& params);
	void setForbidden(forbidden_states& forbidden);

	userOptions& getUserOps();
	hybrid_automata& getHa();
	std::list<initial_state::ptr>& getInit();
	ReachabilityParameters& getReachParams();
	forbidden_states& getForbidden();

	/*
	 * Selects reachability, simulation or falsification
	 */
	void select();

	virtual ~themeSelector();
private:
	hybrid_automata ha;
	std::list<initial_state::ptr> init;
	forbidden_states forbidden;
	userOptions userOps;
	ReachabilityParameters reach_params;
};

#endif /* XSPEED_THEMESELECTOR_H_ */
