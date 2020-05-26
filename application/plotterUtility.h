/*
 * plotter_utility.h
 *
 *  Created on: 18-Nov-2015
 *      Author: amit
 */

#ifndef PLOTTER_UTILITY_H_
#define PLOTTER_UTILITY_H_

#include <core/symbolicStates/symbolicStates.h>

#include "utilities/templatePolyhedra.h"
#include "boost/lexical_cast.hpp"

void plot_output(std::list<symbolic_states::ptr>& Symbolic_states);

#endif /* PLOTTER_UTILITY_H_ */
