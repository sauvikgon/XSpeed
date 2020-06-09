/*
 * flowpipe_cluster.h
 *
 *  Created on: 01-Apr-2017
 *      Author: rajarshi
 */

#ifndef UTILITIES_FLOWPIPE_CLUSTER_H_
#define UTILITIES_FLOWPIPE_CLUSTER_H_

#include <core/continuous/polytope/polytope.h>
#include <core/hybridAutomata/location.h>
#include <core/hybridAutomata/transition.h>
#include <io/ioUtility.h>
#include <utilities/templatePolyhedra.h>
#include <cassert>
/**
 * Clusters the template polyhedra. The parameter factor provides the
 * percent of clustering [can range from 0 to 100]
 *
 */
typedef std::list<polytope::ptr> poly_list;

poly_list flowpipe_cluster(template_polyhedra::ptr template_poly, int cluster);

/**
 * If the transition guard is universal, check the special case of continuation.
 * When the destination location dynamics is the same as the current location dynamics,
 * and the transition assignment is an identity, then no need to consider all the flowpipe
 * polytopes as new symbolic states in the waiting list. Instead, add only the last one
 * as the new symbolic state in the waiting list. The reachability is still guaranteed
 * and avoids the loss of precision due to clustering of flowpipe polytopes.
 */
bool check_continuation(location::ptr src_loc_ptr, location::ptr dest_loc_ptr, transition::ptr trans_ptr);

#endif /* UTILITIES_FLOWPIPE_CLUSTER_H_ */
