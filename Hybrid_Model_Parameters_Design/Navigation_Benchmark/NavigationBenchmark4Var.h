/*
 * NavigationBenchmark.h
 *
 *  Created on: 15-Nov-2014
 *      Author: amit
 *      Navigation Benchmark:: deals with an boject that moves in the R^2 plane with
 *      velocity V_d is determined by the position of the object in an n x m grid, and the desired velocities may
 *      take values [sin(i * pi/4), cos(i * pi/4)], for i=0, . . . , 7.
 *      The Grid is labled as below *
 *      	B 2 4
 *      	4 3 4
 *   		2 2 A
 *      ... from the paper title "Benchmarks for Hybrid System Verification" by Ansgar Fehnker and Franjo Ivancic
 */

/*
 * Basic Model Design requirements are ---
 *
 * Initial Polytope
 * Dynamics : Matrix A, Matrix B and Polytope U :: x' = Ax + Bu and u belongs to U. where x and u are convex polytope
 * Gaurd : Polytope
 * Invariant : Polytope *
 * Transition Dynamics  Rx + w : where R is a Assignment_mapping matrix and w a constant vector or a Polytope
 *
 */

#ifndef NAVIGATIONBENCHMARK4Var_H_
#define NAVIGATIONBENCHMARK4Var_H_

#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/symbolic_states/symbolic_states.h"

void SetNavigationBenchMark4Var(hybrid_automata& Hybrid_Automata,
		symbolic_states& initial_symbolic_state,
		ReachabilityParameters& reach_parameters);

//Only the desired-velocities of  Loc 3 and Loc 4 have been changed
void SetNavigationModel2(hybrid_automata& Hybrid_Automata,
		symbolic_states& initial_symbolic_state,
		ReachabilityParameters& reach_parameters);

/*
 * Only the desired-velocities of  Loc 1, Loc 2, Loc 3 and Loc 4 have been changed
 * Standard model used by most researchers by the Model name : NAV04
 */
void SetNavigationModel4(hybrid_automata& Hybrid_Automata,
		symbolic_states& initial_symbolic_state,
		ReachabilityParameters& reach_parameters);

void SetNavigationModel5by5(hybrid_automata& Hybrid_Automata,
		symbolic_states& initial_symbolic_state,
		ReachabilityParameters& reach_parameters);

#endif /* NAVIGATIONBENCHMARK4Var_H_ */
