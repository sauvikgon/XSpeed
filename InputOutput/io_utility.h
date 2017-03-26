/*
 * io_utility.h
 *
 *  Created on: 19-Jan-2016
 *      Author: amit
 */

#ifndef IO_UTILITY_H_
#define IO_UTILITY_H_

#include <vector>
#include <list>
#include <utility>

#include "../core_system/continuous/Polytope/Polytope.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/symbolic_states/initial_state.h"
#include "Utilities/StandardVector.h"
#include "application/userOptions.h"
#include <fstream>

typedef std::vector<std::pair<double, double> > Intervals;

/**
 * Outputs the result in Interval form
 */
void interval_generator(std::list<symbolic_states::ptr>& symbolic_states_list, userOptions user_ops);
/*
 * Outputs the result in vertex enumerated form
 */
void vertex_generator(std::list<symbolic_states::ptr>& symbolic_states_list, userOptions user_ops);

polytope::ptr convertBounding_Box(template_polyhedra::ptr sfm);

#endif /* IO_UTILITY_H_ */

