/*
 * All_PP_Definition.h
 *
 *  Created on: 11-Dec-2014
 *      Author: amit
 */

#ifndef ALL_PP_DEFINITION_H_
#define ALL_PP_DEFINITION_H_

// *********** Various Algorithms ******************
#define SEQ			 	1	//Sequential Reachability Algorithm
#define PAR_OMP		 	2	//Parallel Reachability Algorithm using OpenMP Thread Creation, using parallelizing over Directions
#define PAR_PROCESS	 	3	//Parallel Reachability Algorithm using Process Creation, using parallelizing over Directions
#define PAR_ITER	 	4	//Parallel Reachability Algorithm using OpenMP Thread Creation, using parallelizing over Iterations
#define PAR_ITER_DIR	5	//Parallel Reachability Algorithm using parallelizing over Iterations and Directions (using OpenMP Thread Creation)
#define PAR_BY_PARTS	6	//Parallel Reachability Algorithm parallelizing over Initial Set Partitioning (using OpenMP Thread Creation)
#define PAR_BY_PARTS_ITERS	7	//Parallel Reachability Algorithm parallelizing over multiple Initial Set ALSO Partitioning iterations.
#define SAME_DIRS		8	//If dir1 = phi_transpose x dir then no need to compute support function for dir1
#define ALL_DIRS		9	//compute all the list of transpose directions
#define GPU_MULTI_SEQ	10	//Matrix-Vector GPU multiplication
#define GPU_SF			11	//reachability algorithm using GPU for computing Support Function

// *********** Various Algorithms ******************

// *********** Various Hybrid System Model ******************
#define BBALL				1		//Bouncing Ball
#define TBBALL				2		//Timed Bouncing Ball
#define HELICOPTER			3		//HELICOPTER Model
#define FIVEDIMSYS			4		//Model of A Five Dimensional System
#define NAVIGATION			5		//NAVIGATION Benchmark model
#define CIRCLE				6		//CIRCLE model with two locations
#define CIRCLE_FOUR_LOC		7		//CIRCLE model with four locations
#define CIRCLE_ONE_LOC		8		//CIRCLE model with one location
//**************** Hybrid Automata Definition ***********************

// *********** Different Template Directions ******************
#define BOX			1
#define OCT			2
//#define UNIFORM		//values > 3

#endif /* ALL_PP_DEFINITION_H_ */
