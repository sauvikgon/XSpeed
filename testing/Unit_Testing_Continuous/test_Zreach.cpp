#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"

#include "core_system/math/uni_sphere.h"
#include "application/DataStructureDirections.h"
#include "application/sf_directions.h"
#include "core_system/Reachability/reachabilitySequential.h"
#include "core_system/Reachability/reachabilityParallel_Process.h"
#include "core_system/math/basic_functions.h"
#include "core_system/math/matrix.h"

#include "Utilities/Template_Polyhedra.h"
#include "Utilities/Post_Assignment.h"

//#define PAR
#define BOX

using namespace std;

SUITE(continuous_reach_TestSuite) {
struct ReachExamples {
	ReachExamples() {
#ifdef BOX
		dir_nums = 4;	//Axis Directions
#else
		dir_nums = 32;// ASSIGN HERE Number of Vectors/Directions for UNIform spear algorithm
#endif
		transition_iterations = 3;//Number of iterations for transition of the Hybrid system
		iterations = 100; // number of iterations :: try with iterations = 1000
		reach_paramters.TimeBound = 2; //Total Time Interval and ::reach_paramters.TimeBound = 5;

		reach_paramters.Iterations = iterations;
		dimension = 2;	//Number of Dimension for the Current Working System
		/*
		 * Invariant constraint
		 * position >=0 (x >= 0)
		 */
		size_type row = 1;
		size_type col = 2;
		invariantConstraintsMatrix.resize(row, col);
		invariantConstraintsMatrix(0, 0) = -1;
		invariantConstraintsMatrix(0, 1) = 0;

		invariantBoundValue.resize(1);
		invariantBoundValue[0] = 0;

		invariantBoundSign = 1;

		invariant->setCoeffMatrix(invariantConstraintsMatrix);
		invariant->setColumnVector(invariantBoundValue);
		invariant->setInEqualitySign(invariantBoundSign); //Assuming size is <= .... as we are only using  Ax<=b format.

	}

	~ReachExamples() { /* some teardown */
	}
	/*
	 * Variable declaration
	 */
	math::matrix<double> ConstraintsMatrixI, gaurdConstraintsMatrix,
			invariantConstraintsMatrix;
	std::vector<double> boundValueI, gaurdBoundValue, invariantBoundValue;
	int boundSignI, gaurdBoundSign, invariantBoundSign;

	math::matrix<double> ConstraintsMatrixV;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	std::vector<double> boundValueV;
	int boundSignV;
	math::matrix<double> Amatrix, Bmatrix;	//, Output;
	template_polyhedra Templet_polys;

	Dynamics system_dynamics;
	ReachabilityParameters reach_paramters;
	unsigned int dir_nums;
	int iterations, dimension, transition_iterations;
	std::vector<std::vector<double> > directions; //List of all directions
	math::matrix<double> Real_Directions; //List of all directions

	polytope::ptr initial_polytope_I, invariant;
};

/* I should try this but by just finding how to use plotter to plot in different axis
 *

 TEST_FIXTURE(ReachExamples, Reach_BBall_Xvelocity_and_Yposition_Test) {
 //System with X-axis as Velocity of the Bouncing Ball
 //	and Y-axis as Position of the Bouncing Ball
 //Input Polytope I as a line(bar) 10<=y(is position)<=10.2 x(is velocity v)== 0.
 size_type row = 4;
 size_type col = 2;
 ConstraintsMatrixI.resize(row, col);
 ConstraintsMatrixI(0, 0) = 0;
 ConstraintsMatrixI(0, 1) = 1;
 ConstraintsMatrixI(1, 0) = 0;
 ConstraintsMatrixI(1, 1) = -1;
 ConstraintsMatrixI(2, 0) = 1;
 ConstraintsMatrixI(2, 1) = 0;
 ConstraintsMatrixI(3, 0) = -1;
 ConstraintsMatrixI(3, 1) = 0;

 boundValueI.resize(4);
 boundValueI[0] = 10.2;
 boundValueI[1] = -10;
 boundValueI[2] = 0;
 boundValueI[3] = 0;

 boundSignI = 1;

 row = 4;
 col = 2;

 // Here Dynamics system  dx/dt=-v and dv/dt = +g
 ConstraintsMatrixV.resize(row, col);
 ConstraintsMatrixV(0, 0) = 1;
 ConstraintsMatrixV(0, 1) = 0;
 ConstraintsMatrixV(1, 0) = -1;
 ConstraintsMatrixV(1, 1) = 0;
 ConstraintsMatrixV(2, 0) = 0;
 ConstraintsMatrixV(2, 1) = 1;
 ConstraintsMatrixV(3, 0) = 0;
 ConstraintsMatrixV(3, 1) = -1;

 boundValueV.resize(4);
 boundValueV[0] = 0;
 boundValueV[1] = 0;
 boundValueV[2] = -9.8;
 boundValueV[3] = 9.8;

 boundSignV = 1;

 row = 2;
 col = 2;
 Amatrix.resize(row, col);
 Amatrix(0, 0) = 0;
 Amatrix(0, 1) = 1;
 Amatrix(1, 0) = 0;
 Amatrix(1, 1) = 0;

 Bmatrix.resize(row, col);
 Bmatrix(0, 0) = 1;
 Bmatrix(0, 1) = 0;
 Bmatrix(1, 0) = 0;
 Bmatrix(1, 1) = 1;

 system_dynamics.MatrixB = Bmatrix;
 system_dynamics.MatrixA = Amatrix;

 system_dynamics.U.setCoeffMatrix(ConstraintsMatrixV);//I have a doubt here whether without resize it can set or not?????
 system_dynamics.U.setColumnVector(boundValueV);
 system_dynamics.U.setInEqualitySign(boundSignV);//Assuming size is <= .... as we are only using  Ax<=b format.

 initial_polytope_I.setCoeffMatrix(ConstraintsMatrixI);
 initial_polytope_I.setColumnVector(boundValueI);
 initial_polytope_I.setInEqualitySign(boundSignI); //Assuming size is <= .... as we are only using  Ax<=b format.

 #ifdef BOX
 std::vector<vector<double> > axis_directions;
 axis_directions = generate_axis_directions(dimension);
 for (int i = 0; i < 2 * dimension; i++) {
 directions.push_back(axis_directions[i]);
 }
 #else
 directions = math::uni_sphere(dir_nums, dimension, 100, 0.0005);
 #endif

 get_ublas_matrix(directions, Real_Directions); //it returns vector vector so need to do conversion here****** Temporary solution

 row = dir_nums;
 col = iterations;
 //Output.resize(row, col);

 row = dir_nums;
 col = dimension;
 reach_paramters.Directions.resize(row, col);

 std::ofstream MatLabfile;
 //file for making matrix 'A' for MatLab output function con2vert(A,b) to be executed from plotoutput.m
 MatLabfile.open("/home/amit/matlabTest/ProjectOutput/DirectionsMatrix.txt");
 for (int i = 0; i < dir_nums; i++) {
 for (int j = 0; j < dimension; j++) {
 //	Vector_R[i][j] = directions[i][j];
 reach_paramters.Directions(i, j) = Real_Directions(i, j); //directions[i][j];
 MatLabfile << Real_Directions(i, j) << " ";		//Vector_R[i][j]
 }
 MatLabfile << std::endl;
 }
 MatLabfile.close();

 #ifdef PAR
 Templet_polys = reachabilityParallel_Process(system_dynamics,
 initial_polytope_I, reach_paramters);
 #else
 Templet_polys = reachabilitySequential(system_dynamics, initial_polytope_I,
 reach_paramters);
 #endif

 cout << endl << "Number of Vectors = " << dir_nums;
 cout << endl << "Number of Iteration = " << iterations << endl;

 std::ofstream MatLabfile2;
 //file for making matrix 'b' for MatLab output function con2vert(A,b) to be executed from plotoutput.m
 //Note Each column will make b for 'j nos of iterations'.
 MatLabfile2.open(
 "/home/amit/matlabTest/ProjectOutput/SupportFunctionMatrix.txt");
 for (int i = 0; i < dir_nums; i++) {
 for (int j = 0; j < iterations; j++) {
 MatLabfile2 << Templet_polys.getMatrixSupportFunction()(i, j)
 << " ";
 }
 MatLabfile2 << endl;
 }
 MatLabfile2.close();
 }
 */
/*

 TEST_FIXTURE(ReachExamples, Reach_Rotation10Degree_Test)
 {


 /*Amatrix.resize(2);
 for (int i=0;i<2;i++)
 Amatrix[i].resize(2);
 Amatrix[0][0]=0.985;
 Amatrix[0][1]=-0.174;
 Amatrix[1][0]=0.174;
 Amatrix[1][1]=0.985;

 Bmatrix.resize(2);
 for(int i=0;i<2;i++)
 Bmatrix[i].resize(2);
 Bmatrix[0][0] = 1;
 Bmatrix[0][1] = 1;
 Bmatrix[1][0] = 1;
 Bmatrix[1][1] = 1;





 row = 2;	col = 2;
 Amatrix.resize(row, col);
 Amatrix(0, 0) = 0.985;
 Amatrix(0, 1) =-0.174;
 Amatrix(1, 0) = 0.174;
 Amatrix(1, 1) = 0.985;

 Bmatrix.resize(row, col);
 Bmatrix(0, 0) = 1;
 Bmatrix(0, 1) = 1;
 Bmatrix(1, 0) = 1;
 Bmatrix(1, 1) = 1;

 system_dynamics.MatrixB = Bmatrix;
 system_dynamics.MatrixA = Amatrix;

 system_dynamics.U.setCoeffMatrix(ConstraintsMatrixV); //I have a doubt here whether without resize it can set or not?????
 system_dynamics.U.setColumnVector(boundValueV);
 system_dynamics.U.setInEqualitySign(boundSignV); //Assuming size is <= .... as we are only using  Ax<=b format.

 initial_polytope_I.setCoeffMatrix(ConstraintsMatrixI);
 initial_polytope_I.setColumnVector(boundValueI);
 initial_polytope_I.setInEqualitySign(boundSignI); //Assuming size is <= .... as we are only using  Ax<=b format.


 system_dynamics.MatrixB = Bmatrix;
 system_dynamics.MatrixA = Amatrix;

 system_dynamics.U.setCoeffMatrix(ConstraintsMatrixV);			//I have a doubt here whether without resize it can set or not?????
 system_dynamics.U.setColumnVector(boundValueV);
 system_dynamics.U.setInEqualitySign(boundSignV);		//Assuming size is <= .... as we are only using  Ax<=b format.

 initial_polytope_I.setCoeffMatrix(ConstraintsMatrixI);
 initial_polytope_I.setColumnVector(boundValueI);
 initial_polytope_I.setInEqualitySign(boundSignI); 		//Assuming size is <= .... as we are only using  Ax<=b format.


 #ifdef PAR
 Output = reachabilityParallel_Process(system_dynamics, initial_polytope_I, reach_paramters);
 #else
 Output = reachabilitySequential(system_dynamics, initial_polytope_I,
 reach_paramters);
 #endif


 cout << endl << "Number of Vectors = " << dir_nums;
 cout << endl << "Number of Iteration = " << iterations << endl;

 std::ofstream MatLabfile2;
 //file for making matrix 'b' for MatLab output function con2vert(A,b) to be executed from plotoutput.m
 //Note Each column will make b for 'j nos of iterations'.
 MatLabfile2.open(
 "/home/amit/matlabTest/ProjectOutput/SupportFunctionMatrix.txt");
 for (int i = 0; i < dir_nums; i++) {
 for (int j = 0; j < iterations; j++) {
 MatLabfile2 << Output(i,j) << " ";
 }
 MatLabfile2 << endl;
 }
 MatLabfile2.close();
 }
 */

/*
 TEST_FIXTURE(ReachExamples, Reach_Circle_Test) {

 Amatrix.resize(2);
 for (int i = 0; i < 2; i++)
 Amatrix[i].resize(2);
 Amatrix[0][0] = 0;
 Amatrix[0][1] = -1;
 Amatrix[1][0] = 1;
 Amatrix[1][1] = 0;

 Bmatrix.resize(2);
 for (int i = 0; i < 2; i++)
 Bmatrix[i].resize(2);
 Bmatrix[0][0] = 0;
 Bmatrix[0][1] = 0;
 Bmatrix[1][0] = 0;
 Bmatrix[1][1] = 0;

 system_dynamics.MatrixB = Bmatrix;
 system_dynamics.MatrixA = Amatrix;

 system_dynamics.U.setCoeffMatrix(ConstraintsMatrixV);//I have a doubt here whether without resize it can set or not?????
 system_dynamics.U.setColumnVector(boundValueV);
 system_dynamics.U.setInEqualitySign(boundSignV);//Assuming size is <= .... as we are only using  Ax<=b format.

 initial_polytope_I.setCoeffMatrix(ConstraintsMatrixI);
 initial_polytope_I.setColumnVector(boundValueI);
 initial_polytope_I.setInEqualitySign(boundSignI); //Assuming size is <= .... as we are only using  Ax<=b format.

 //Calling reachability Algorithm
 try{
 #ifdef PAR
 Output = reachabilityParallel_Process(system_dynamics, initial_polytope_I, reach_paramters);
 #else
 Output = reachabilitySequential(system_dynamics, initial_polytope_I,
 reach_paramters);
 #endif
 }catch(exception& e){
 std::cout << e.what() << std::endl;
 }

 cout << endl << "Number of Vectors = " << dir_nums;
 cout << endl << "Number of Iteration = " << iterations << endl;

 std::ofstream MatLabfile2;
 //file for making matrix 'b' for MatLab output function con2vert(A,b) to be executed from plotoutput.m
 //Note Each column will make b for 'j nos of iterations'.
 MatLabfile2.open(
 "/home/amit/matlabTest/ProjectOutput/SupportFunctionMatrix.txt");
 for (int i = 0; i < dir_nums; i++) {
 for (int j = 0; j < iterations; j++) {
 MatLabfile2 << Output[i][j] << " ";
 }
 MatLabfile2 << endl;
 }
 MatLabfile2.close();
 } */

TEST_FIXTURE(ReachExamples, Reach_BBall_Xposition_and_Yvelocity_Test) {
	//System with X-axis as Position of the Bouncing Ball
	//	and Y-axis as Velocity of the Bouncing Ball
	//Input Polytope I as a line(bar) 10<=y(is position)<=10.2 x(is velocity v)== 0.
	size_type row = 4;
	size_type col = 2;
	ConstraintsMatrixI.resize(row, col);
	ConstraintsMatrixI(0, 0) = 1;
	ConstraintsMatrixI(0, 1) = 0;
	ConstraintsMatrixI(1, 0) = -1;
	ConstraintsMatrixI(1, 1) = 0;
	ConstraintsMatrixI(2, 0) = 0;
	ConstraintsMatrixI(2, 1) = 1;
	ConstraintsMatrixI(3, 0) = 0;
	ConstraintsMatrixI(3, 1) = -1;

	boundValueI.resize(4);
	boundValueI[0] = 10.2;
	boundValueI[1] = -10;
	boundValueI[2] = 0;
	boundValueI[3] = 0;

	boundSignI = 1;

	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = 0;
	ConstraintsMatrixV(0, 1) = -1;
	ConstraintsMatrixV(1, 0) = 0;
	ConstraintsMatrixV(1, 1) = 1;
	ConstraintsMatrixV(2, 0) = -1;
	ConstraintsMatrixV(2, 1) = 0;
	ConstraintsMatrixV(3, 0) = 1;
	ConstraintsMatrixV(3, 1) = 0;

	boundValueV.resize(4);
	boundValueV[0] = 9.8;		//10;
	boundValueV[1] = -9.8;		//-10;
	boundValueV[2] = 0;
	boundValueV[3] = 0;

	boundSignV = 1;

	row = 2;
	col = 2;
	Amatrix.resize(row, col);
	Amatrix(0, 0) = 0;
	Amatrix(0, 1) = 1;
	Amatrix(1, 0) = 0;
	Amatrix(1, 1) = 0;

	Bmatrix.resize(row, col);
	Bmatrix(0, 0) = 1;
	Bmatrix(0, 1) = 0;
	Bmatrix(1, 0) = 0;
	Bmatrix(1, 1) = 1;

	//cout<<"1 = Testing amit \n";
	row = 3;
	col = 2;
	gaurdConstraintsMatrix.resize(row, col);
	gaurdConstraintsMatrix(0, 0) = 1;
	gaurdConstraintsMatrix(0, 1) = 0;
	gaurdConstraintsMatrix(1, 0) = -1;
	gaurdConstraintsMatrix(1, 1) = 0;
	gaurdConstraintsMatrix(2, 0) = 0;
	gaurdConstraintsMatrix(2, 1) = 1;

	gaurdBoundValue.resize(3);
	gaurdBoundValue[0] = 0;
	gaurdBoundValue[1] = 0;
	gaurdBoundValue[2] = 0;	//gaurd is:: Position==0 and velocity <=0         0 <=x<= 0 and y<=0

	gaurdBoundSign = 1;

	//	cout<<"2 = Testing amit \n";

	system_dynamics.MatrixB = Bmatrix;
	system_dynamics.MatrixA = Amatrix;

	system_dynamics.U->setCoeffMatrix(ConstraintsMatrixV);//I have a doubt here whether without resize it can set or not?????
	system_dynamics.U->setColumnVector(boundValueV);
	system_dynamics.U->setInEqualitySign(boundSignV);//Assuming size is <= .... as we are only using  Ax<=b format.

	initial_polytope_I->setCoeffMatrix(ConstraintsMatrixI);
	initial_polytope_I->setColumnVector(boundValueI);
	initial_polytope_I->setInEqualitySign(boundSignI); //Assuming size is <= .... as we are only using  Ax<=b format.

	std::vector<double> invariant_direction(dimension);
	std::vector<std::vector<double> > newDirections;
	invariant_direction[0] = -1;
	invariant_direction[1] = 0;
	newDirections.push_back(invariant_direction); //some improvement has to be done here later to avoid repeated Direction

#ifdef BOX
	std::vector<vector<double> > axis_directions;
	axis_directions = generate_axis_directions(dimension);
	for (int i = 0; i < 2 * dimension; i++) {
		newDirections.push_back(axis_directions[i]);
	}
#else
	directions = math::uni_sphere(dir_nums, dimension, 100, 0.0005);
	for (int i=0;i<dir_nums;i++)
	newDirections.push_back(directions[i]);

#endif
	dir_nums++;	//Directions increased by 1 for invariant's direction :: Note : some improvement has to be done here later to avoid repeated Direction
	get_ublas_matrix(newDirections, Real_Directions); //it returns vector vector so need to do conversion here****** Temporary solution

	row = dir_nums;
	col = dimension;
	reach_paramters.Directions.resize(row, col);

	std::ofstream MatLabfile;
	//file for making matrix 'A' for MatLab output function con2vert(A,b) to be executed from plotoutput.m
	MatLabfile.open("/home/amit/matlabTest/ProjectOutput/DirectionsMatrix.txt");
	for (int i = 0; i < dir_nums; i++) {
		for (int j = 0; j < dimension; j++) {
			//	Vector_R[i][j] = directions[i][j];
			reach_paramters.Directions(i, j) = Real_Directions(i, j); //directions[i][j];
			MatLabfile << Real_Directions(i, j) << " ";		//Vector_R[i][j]
		}
		MatLabfile << std::endl;
	}
	MatLabfile.close();

	polytope::ptr gaurd_polytope = polytope::ptr(new polytope(gaurdConstraintsMatrix, gaurdBoundValue,
			gaurdBoundSign));

	template_polyhedra intersected_polyhedra;
	polytope::ptr intersectedRegion, newPolytope;
	polytope::ptr newShiftedPolytope;
	/*
	 * Transition Dynamics  Rx + w
	 */
	math::matrix<double> R;	//Transition Dynamics
	row = 2;
	col = 2;
	R.resize(row, col);
	R(0, 0) = 1;
	R(0, 1) = 0;
	R(1, 0) = 0;
	R(1, 1) = -0.6;

	std::vector<double> w(2);
	w[0] = 0;
	w[1] = 0;
	std::ofstream MatLabfile2;
	MatLabfile2.open(
			"/home/amit/matlabTest/ProjectOutput/SupportFunctionMatrix.txt");

	//int intersection_start_point;

	for (int number_times = 1; number_times <= transition_iterations;
			number_times++) {
#ifdef PAR
		Templet_polys = reachabilityParallel_Process(system_dynamics,
				initial_polytope_I, reach_paramters);
#else
		Templet_polys = reachabilitySequential(system_dynamics,
				initial_polytope_I, reach_paramters, invariant, true, 1);
#endif
		cout << "\n3 = Testing amit \n";
		 cout << "\nPrinting the New number of Iteration = "
		 << Templet_polys.getMatrixSupportFunction().size2() << endl;

		for (int i = 0; i < dir_nums; i++) {
			for (int j = 0;
					j < Templet_polys.getMatrixSupportFunction().size2(); j++) {
				MatLabfile2 << Templet_polys.getMatrixSupportFunction()(i, j)
						<< " ";
			}
			MatLabfile2 << endl;
		}

		std::list<template_polyhedra> intersected_polyhedra = Templet_polys.polys_intersection(
				gaurd_polytope,1);//, intersection_start_point); //returns the list of polytopes that intersects with the gaurd_polytope
		//unsigned int iterations_before_intersection = intersection_start_point - 1;
		//Templet_polys.resize_matrix_SupportFunction(dir_nums, iterations_before_intersection);

		/* Todo: deprecated after change of interface */
	//	intersectedRegion = intersected_polyhedra.getTemplate_approx(1);	//Returns a single over-approximated polytope from the list of intersected polytopes
	//	newPolytope = intersectedRegion->GetPolytope_Intersection(
	//			gaurd_polytope,1);//Retuns only the intersected region as a single newpolytope.

		/*		std::ofstream MatLabfile5;
		 MatLabfile5.open(
		 "/home/amit/matlabTest/ProjectOutput/NewDirectionMatrix.txt");
		 for (int i = 0; i < newPolytope.getCoeffMatrix().size1(); i++) {
		 for (int j = 0; j < dimension; j++) {
		 MatLabfile5 << newPolytope.getCoeffMatrix()(i, j) << " ";
		 }
		 MatLabfile5 << endl;
		 }
		 MatLabfile5.close();

		 std::ofstream MatLabfile3;
		 MatLabfile3.open(
		 "/home/amit/matlabTest/ProjectOutput/NewSupportFunctionMatrix.txt");
		 for (int i = 0; i < newPolytope.getColumnVector().size(); i++) {
		 MatLabfile3 << newPolytope.getColumnVector()[i] << endl;
		 }
		 MatLabfile3.close();
		 */
//		initial_polytope_I = post_assign_exact(newPolytope, R, w);//newShiftedPolytope = post_assign_exact(newPolytope, R, w);

	}	//end-of Number of transition's Loop

	MatLabfile2.close();

	/*
	 cout << endl << "Number of Vectors = " << dir_nums;
	 cout << endl << "Number of Iteration = " << iterations << endl;
	 */

}

}

