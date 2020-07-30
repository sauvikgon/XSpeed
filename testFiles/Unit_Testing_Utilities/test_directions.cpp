#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include "application/sfDirections.h"
#include "application/sfUtility.h"
#include <vector>
#include <list>
#include <string>
#include "core/math/matrix.h"

using namespace std;

SUITE(directions_TestSuite) {

	struct directions {
		directions() {
		}
		~directions() { /* some teardown */
		}
		stringstream out, proper;
	};

	TEST_FIXTURE(directions, octagonal_directions_Test) {

		unsigned int dim = 2;
		std::vector<std::vector<double> > dirs;

		math::matrix<double> mydirs;
		dirs = get_octagonal_directions(dim);

		get_ublas_matrix(dirs, mydirs); //it returns vector vector so need to do conversion here:: Temporary solution


		float output2d[8][2];
		for(unsigned int i = 0; i < mydirs.size1();i++){
			for(unsigned int j= 0; j <dim;j++){
				 output2d[i][j] = mydirs(i,j);
			}
		}
		const float res2d[8][2]=  { {1,0},{-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,1}, {0,-1} };
		CHECK_ARRAY2D_CLOSE(res2d,output2d,8,2,0.00);

		}

}
