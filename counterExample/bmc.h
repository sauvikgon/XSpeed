/*
 * bmc.h
 *
 *  Created on: 14-Sep-2020
 *      Author: rajarshi
 */

#ifndef XSPEED_PLAN_COUNTEREXAMPLE_BMC_H_
#define XSPEED_PLAN_COUNTEREXAMPLE_BMC_H_

#include <core/hybridAutomata/hybridAutomata.h>
#include <core/symbolicStates/symbolicStates.h>
#include <core/symbolicStates/initialState.h>
#include <core/continuous/approxModel/fbInterpol.h>
#include <core/reachability/postCSequential.h>
#include <utilities/templatePolyhedra.h>
#include <utilities/postAssignment.h>
#include <application/userOptions.h>
#include <boost/algorithm/string.hpp>
#include <io/ioUtility.h>
#include <vector>
#include <list>
#include <z3++.h>

/*
 * A path oriented BMC of Affine HA. Path enumeration is performed
 * with SAT solving. Path feasibility is checked with symbolic
 * RA. A feasible path is searched for concrete counterexample
 * trajectory using trajectory splicing algorithm. An unsuccessful
 * search of a ce along a path, say pi, alters the SAT encoding in
 * such a way that the next paths in the enumeration does not
 * contain the path pi within it. This reduces the candidate set of
 * paths for ce searching.
 */
typedef std::vector<unsigned int> path;
typedef std::list<symbolic_states::ptr> region;
typedef std::pair<int, polytope::ptr> forbidden; //(locId,Polytope)
typedef std::vector<forbidden> forbidden_states; // vector of forbidden symb states.

class bmc {

	const hybrid_automata::ptr ha_ptr;
	const std::list<initial_state::ptr>& init;
	const forbidden_states& forbidden_s;
	const ReachabilityParameters& reach_params;
	const userOptions& user_ops;
	z3::context c;
	z3::expr ha_encoding;
	z3::solver sol;

	unsigned int k; // The BMC bound on path-length, i.e., the number of edges.

	/* bmc uses this private member function to initialize the ha_encoding for the given
	 * forbidden location id
	 */
	void init_solver(unsigned int forbidden_loc_id, unsigned int k1);

public:

	/* To be used for BMC when a set of ha locations together with assoc. polytopes are forbidden */
	bmc(const hybrid_automata::ptr haPtr, const std::list<initial_state::ptr>& init, const forbidden_states& forbidden,
			const ReachabilityParameters& r_params, const userOptions& user_ops);

	virtual ~bmc();
	/*
	 * Computes the reachable states along the given path p and gets the path feasibility
	 * as a boolean flag.
	 */
	region getPathRegion(path p, bool& feasible);

	/*
	 * Returns the next unexplored path in the HA from the given source
	 * to the given destination node. The already explored paths are remembered
	 * in the z3 expression ha_encoding. The implementation is a SAT solver
	 * based path enumeration algorithm.
	 */
	path getNextPath(unsigned int k1);

	/*
	 * Returns false if the ha is found to be unsafe in the given bound.
	 * a return of true however, does not decide the safety of ha faithfully.
	 * This is due to the incompleteness of the ce search mechanism.
	 */
	bool safe();

	/*
	 * Updates the ha encoding with a given forbidden location in such a way
	 * that the next paths in the enumeration does not return any path containing
	 * the path p.
	 */
	void update_encoding(path p);
};

#endif /* XSPEED_PLAN_COUNTEREXAMPLE_BMC_H_ */
