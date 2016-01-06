/*
 * UnitTest_TemplatePolyhedra.cpp
 *
 *  Created on: 18-Nov-2014
 *      Author: amit
 */



//#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev
#include <string>
#include "Utilities/Template_Polyhedra.h"

using namespace std;

SUITE(TemplatePolyhedra_TestSuite) {

struct TemplatePolyhedra {
	TemplatePolyhedra() {
	}
	~TemplatePolyhedra() { /* some teardown */
	}
	stringstream out, proper;
};

TEST_FIXTURE(TemplatePolyhedra, union_TemplatePolytope_Test) {


	math::matrix<double> sfm(2,2), sfm2(2,2);
	math::matrix<double> dirs(2,2);
	sfm(0,0) = 1;	sfm(0,1) = 1;
	sfm(1,0) = 2;	sfm(1,1) = 2;

	sfm2(0,0) = 3;	sfm2(0,1) = 3;
	sfm2(1,0) = 3;	sfm2(1,1) = 3;

	dirs(0,0) = 1;
	dirs(0,1) = 1;
	dirs(1,0) = 2;
	dirs(1,1) = 2;

	template_polyhedra::ptr t,t2, test;
	//t(sfm,dirs), t2(sfm2,dirs), test;
t = template_polyhedra::ptr (new template_polyhedra(sfm,dirs));
t2 = template_polyhedra::ptr (new template_polyhedra(sfm2,dirs));
	test = t->union_TemplatePolytope(t2);
	test = test->union_TemplatePolytope(t);

	/*std::cout << "output union template Polytope \n ";
	for(unsigned int i = 0; i<test->getMatrixSupportFunction().size1();i++){
		for(unsigned int j=0;j<test->getMatrixSupportFunction().size2();j++){
			std::cout << test->getMatrixSupportFunction()(i,j) << "\t";
		}
		cout << endl;
	}*/
	out << test->getMatrixSupportFunction();
	proper << "[2,6]((1,1,3,3,1,1),(2,2,3,3,2,2))";

	CHECK_EQUAL(proper.str(), out.str());
}

}


