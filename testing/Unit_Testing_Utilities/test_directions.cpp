#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include "application/sf_directions.h"
#include<vector>
#include<list>

#include <string>

using namespace std;

SUITE(directions_TestSuite) {

struct directions {
	directions() {
	}
	~directions() { /* some teardown */
	}

};

TEST_FIXTURE(directions, octagonal_directions_Test) {

	unsigned int dim = 4;
	std::vector<std::vector<double> > mydirs;

	mydirs = get_octagonal_directions(dim);

	std::cout << "output from get_octagonal directions \n ";
	for(unsigned int i = 0; i<mydirs.size();i++){
		for(unsigned int j=0;j<dim;j++){
			std::cout << mydirs[i][j] << " ";
		}
		cout << endl;
	}

		 //CHECK_EQUAL(proper.str(),out.str());

}




}
