#include <sstream>
#include <iostream>
#include "UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
//#include "UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include "application/sf_directions.h"
#include "application/sf_utility.h"
#include "core_system/math/matrix.h"
#include <vector>
#include <list>

#include <string>

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
		std::cout<< mydirs;

		const float res2d[8][2]=  { {1,0},{-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,1}, {0,-1} };
		CHECK_ARRAY2D_CLOSE(res2d,output2d,8,2,0.00);

		}

}
