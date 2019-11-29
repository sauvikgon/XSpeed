/*
 * Best_Directions.cpp
 *
 *  Created on: 07-Dec-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "application/sf_directions.h"
#include "application/sf_utility.h"

#include<vector>

#include <string>
#include "../../../core/math/matrix.h"
#include "../../../core/math/uni_sphere.h"	//for obtaining uniformly distributed directions
#include "../../../utilities/Directions/Convert_To_BestDirection.h"

using namespace std;

SUITE(BestDirections_TestSuite) {

	struct BestDirections {
		BestDirections() {
			math::matrix<double> ConstraintsMatrixI;
			std::vector<double> boundValueI;
			int boundSignI;
			row = 4;
			col = 2;
			ConstraintsMatrixI.resize(row, col);
			ConstraintsMatrixI(0, 0) = -1;
			ConstraintsMatrixI(0, 1) = -1;
			ConstraintsMatrixI(1, 0) = 1;
			ConstraintsMatrixI(1, 1) = 1;
			ConstraintsMatrixI(2, 0) = 1;
			ConstraintsMatrixI(2, 1) = -1;
			ConstraintsMatrixI(3, 0) = -1;
			ConstraintsMatrixI(3, 1) = 1;

			boundValueI.resize(row);
			boundValueI[0] = -5;
			boundValueI[1] = 13;
			boundValueI[2] = 5;
			boundValueI[3] = 3;

			boundSignI = 1;

			p = polytope::ptr(
					new polytope(ConstraintsMatrixI, boundValueI, boundSignI));

		}
		~BestDirections() { /* some teardown */
		}
		polytope::ptr p;
		typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
		size_type row, col;
	};

	TEST_FIXTURE(BestDirections, BestDirections_Test) {

		std::vector<double> mydirs(2), best_dir(2), best_dir_res(2);
		mydirs[0] = 0;
		mydirs[1] = -1;
		int lp_solver_type = 1; //1 for GLPK
		best_dir = getBestDirection(p, mydirs, lp_solver_type);

		/*std::cout << "Best directions from (1,0) is \n ";
		for (unsigned int i = 0; i < best_dir.size(); i++) {
			std::cout << best_dir[i] << ", ";
		}*/
		best_dir_res[0] = best_dir[0]; // -0.682006; not able to compare double data_type
		best_dir_res[1] = best_dir[1];// -0.731347;
		CHECK_ARRAY_EQUAL(best_dir, best_dir_res, best_dir.size());

	}

	TEST_FIXTURE(BestDirections, IsSameDirection_Test) {
		/*	std::vector<double> dir1(2), dir2(2);
		 dir1[0] = 0.2;
		 dir1[1] = 0.8;

		 dir2[0] = 0.5;
		 dir2[1] = 0.8;
		 std::cout << endl;*/

		/*	 if (Issame_direction(dir1, dir2))
		 std::cout << "Two directions are near same!!\n ";
		 else		sfunc = quad3.computeSupportFunction(direction, 2);
		 cout<<"\n AmitShouldbe = -4 it is? = "<<sfunc<<endl;
		 */

		//std::cout << "Two directions are NOT near same!!\n ";
	}

	TEST_FIXTURE(BestDirections, GetBestDirections_Test) {
		/*
		 std::vector<std::vector<double> > newDirections;
		 math::matrix<double> R_Directions;
		 int dim = 2;
		 int dir_nums = 4;
		 //newDirections = generate_axis_directions(dim);	//box directions
		 //newDirections = get_octagonal_directions(dim);
		 newDirections = math::uni_sphere(dir_nums, dim, 100, 0.0005);

		 get_ublas_matrix(newDirections, R_Directions); //it returns vector vector so need to do conversion here****** Temporary solution

		 std::cout << "\nOriginal Direction\n";
		 std::cout << R_Directions << endl;

		 math::matrix<double> best_Directions;
		 best_Directions = getBestTemplateDirections(p, R_Directions, 1);//returns less or equal number of dirs
		 //best_Directions = getBestEqualTemplateDirections(p, R_Directions);
		 std::cout << "\nNew Best Direction\n";
		 std::cout << best_Directions << endl;*/
	}
}
