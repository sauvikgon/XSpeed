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

	hybrid_automata* ha;
	forbidden_states forbidden_s;
	z3::context c;
	z3::expr ha_encoding(c);
	z3::solver sol(c);
	unsigned int k; // The BMC bound on path-length, i.e., the number of edges.

	/* bmc uses this private member function to initialize the ha_encoding for the given
	 * forbidden location id
	 */
	void init_solver(unsigned int forbidden_loc_id);

public:

	bmc();

	/* To be used for BMC when a set of ha locations together assoc. polytopes are forbidden */
	bmc(hybrid_automata* ha_ptr, forbidden_states& forbidden, unsigned int k);

	virtual ~bmc();
	/*
	 * Computes the reachable states along the given path p
	 */
	region getPathRegion(path p);

	/*
	 * Returns the next unexplored path in the HA from the given source
	 * to the given destination node. The already explored paths are remembered
	 * in the z3 expression ha_encoding. The implementation is a SAT solver
	 * based path enumeration algorithm.
	 */
	path getNextPath();

	/*
	 * Returns false if the ha is found to be unsafe in the given bound.
	 * a return of true however, does not decide the safty of ha faithfully.
	 * This is due to the incompleteness of the ce search mechanism.
	 */
	bool isSafe();

	/*
	 * Updates the ha encoding with a given forbidden location in such a way
	 * that the next paths in the enumeration does not return any path containing
	 * the path p.
	 */
	void update_encoding(path p);
};

#endif /* XSPEED_PLAN_COUNTEREXAMPLE_BMC_H_ */
