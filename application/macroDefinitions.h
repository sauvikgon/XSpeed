/*
 * All_PP_Definition.h
 *
 *  Created on: 11-Dec-2014
 *      Author: amit
 */

#ifndef ALL_PP_DEFINITION_H_
#define ALL_PP_DEFINITION_H_

// *********** Various Algorithms ******************
#define SEQ_SF			1	//Sequential postC with supfunc.
#define PAR_SF		 	2	//Parallel postC using OpenMP Thread Creation, parallel sampling of supfunc over directions
#define TIME_SLICE	 	3	//Parallel postC with Time-slicing
#define FB_INTERPOL	 	4	//postC with fwd-bwd interpolation model.
#define AGJH_BFS		5	//Parallel BFS using G.J. Holzmann's Algorithm
#define TPBFS			6	//Parallel BFS using Load Balancing
#define ASYNC_BFS 		7	//Parallel Asynchronous BFS

// *********** Various Hybrid System Model ******************
#define BBALL				1		//Bouncing Ball
#define TBBALL				2		//Timed Bouncing Ball
#define FIVEDIMSYS			3		//Model of A Five Dimensional System
#define NAVIGATION_1		4		//NAVIGATION Benchmark model - NAV01 (3 x 3)
#define NAVIGATION_2		5		//NAVIGATION Benchmark model - NAV04 (5 x 5)
#define OSCILLATOR			6		//OSCILLATOR model without any Filter


// *********** Different Template Directions ******************
#define BOX			1
#define OCT			2
//#define UNIFORM		//values > 3

#define MAX_ALGO 	8	//Total number of existing Algorithm. This value need to be increased for new Algorithm when implemented


#endif /* ALL_PP_DEFINITION_H_ */
