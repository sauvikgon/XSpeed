/*
 * UnitTest_TemplatePolyhedra.cpp
 *
 *  Created on: 18-Nov-2014
 *      Author: amit
 */



#include "UnitTest++/UnitTest++.h"
#include <string>
#include "Utilities/Template_Polyhedra.h"

using namespace std;

SUITE(TemplatePolyhedra_TestSuite) {

struct TemplatePolyhedra {
	TemplatePolyhedra() {
	}
	~TemplatePolyhedra() { /* some teardown */
	}

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

	template_polyhedra::ptr t = template_polyhedra::ptr(new template_polyhedra(sfm,dirs));
	template_polyhedra::ptr t2 = template_polyhedra::ptr(new template_polyhedra(sfm2,dirs));
	template_polyhedra::ptr	test;

	test = t->union_TemplatePolytope(t2);
	test = test->union_TemplatePolytope(t);

	std::cout << "output union template Polytope \n ";
	for(unsigned int i = 0; i<test->getMatrixSupportFunction().size1();i++){
		for(unsigned int j=0;j<test->getMatrixSupportFunction().size2();j++){
			std::cout << test->getMatrixSupportFunction()(i,j) << "\t";
		}
		cout << endl;
	}
}

}


