#include <sstream>
#include <iostream>
//#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
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

		/*	std::cout << "output from get_octagonal directions \n ";
		 for(unsigned int i = 0; i<mydirs.size();i++){
		 for(unsigned int j=0;j<dim;j++){
		 std::cout << mydirs[i][j] << " ";
		 }
		 cout << endl;
		 }
		 std::cout<< mydirs;
		 * */
		out << mydirs;
		proper << "[8,2]((1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1),(0,1),(0,-1))";
		CHECK_EQUAL(proper.str(),out.str());

	}

}
