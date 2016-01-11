/*
 * test_lp_gurobi_simplex.cpp
 *
 *  Created on: 11-Jul-2014
 *      Author: amit
 */
#include <string>
#include <sstream>
#include <iostream>
#include <boost/tokenizer.hpp>
//#include "UnitTest++/UnitTest++.h" //manual installation and copy in /usr/local/include/UnitTest++ folder
#include "unittest++/UnitTest++.h"	//installing using sudo aptitude install libunittest++-dev

//using namespace boost::numeric::ublas;
using namespace std;
using namespace boost;

SUITE(Helicopter_TestSuite) {
struct ExampleHelicopter_Model {
	ExampleHelicopter_Model() {

	}
	~ExampleHelicopter_Model() { /* some teardown */
	}

	stringstream out, proper;
};

TEST_FIXTURE(ExampleHelicopter_Model, Creating_Identity_Matrix_Test) {
//	math::matrix<double> Ident_B;
	/*	int size = 3;
	 identity_matrix<double> m(size);
	 //Ident_B = m;
	 cout<<"\n";
	 for (int i = 0; i < m.size1(); i++) {
	 for (int j = 0; j < m.size2(); j++)
	 cout << m(i, j) << "\t";
	 cout << endl;
	 }*/
/*

	int row = 2;
	Ident_B.resize(row, row);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (i == j)
				Ident_B(i, j) = 1;
			else
				Ident_B(i, j) = 0;
		}
	}
	cout << "\nPrinting Identity matrix\n";
	for (unsigned int i = 0; i < Ident_B.size1(); i++) {
		for (unsigned int j = 0; j < Ident_B.size2(); j++)
			cout << Ident_B(i, j) << "\t";
		cout << endl;
	}
*/

}

/*
TEST_FIXTURE(ExampleHelicopter_Model, Boost_Tokenizer_Test) {
	polytope initial_polytope_I, invariant,	gaurd_polytope;
	Dynamics system_dynamics;
	SetHelicopter_Parameters(initial_polytope_I,
			system_dynamics, invariant,	gaurd_polytope);
}
*/

}
