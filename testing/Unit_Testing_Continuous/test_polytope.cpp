/*
 * test_polytope.cpp
 *
 *  Created on: 05-Jul-2014
 *      Author: amit
 */

#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"
#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/math/matrix.h"

#include "Utilities/StandardVector.h"

using namespace std;

SUITE(sf_utility_TestSuite) {
struct ExamplePolytope {
	ExamplePolytope() {
		row = 6;
		col = 2;
		ConstraintsMatrixI.resize(row, col);
		ConstraintsMatrixI(0, 0) = -1;
		ConstraintsMatrixI(0, 1) = 0;
		ConstraintsMatrixI(1, 0) = 0;
		ConstraintsMatrixI(1, 1) = 1;
		ConstraintsMatrixI(2, 0) = 1;
		ConstraintsMatrixI(2, 1) = 1;
		ConstraintsMatrixI(3, 0) = 1;
		ConstraintsMatrixI(3, 1) = 0;
		ConstraintsMatrixI(4, 0) = 0;
		ConstraintsMatrixI(4, 1) = -1;
		ConstraintsMatrixI(5, 0) = -1;
		ConstraintsMatrixI(5, 1) = -1;

		boundValueI.resize(6);

		boundValueI[0] = -1;
		boundValueI[1] = 7;
		boundValueI[2] = 9;
		boundValueI[3] = 3;
		boundValueI[4] = -5;
		boundValueI[5] = -7;

		boundSignI = 1;

		direction.resize(2);
		direction[0] = 0;
		direction[1] = 1;

		I.setCoeffMatrix(ConstraintsMatrixI);
		I.setColumnVector(boundValueI);
		I.setInEqualitySign(boundSignI);

		P2.setCoeffMatrix(ConstraintsMatrixI);
		P2.setColumnVector(boundValueI);
		P2.setInEqualitySign(boundSignI);

	}
	~ExamplePolytope() { /* some teardown */
	}
	polytope I, P2;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	size_type row, col;
	int boundSignI, boundSignP, boundSignV;
	std::vector<double> boundValueI, boundValueP, boundValueV;
	math::matrix<double> ConstraintsMatrixI, ConstraintsMatrixP,
			ConstraintsMatrixV;
	std::vector<double> direction;
	stringstream out, proper;
};
TEST_FIXTURE(ExamplePolytope, polytope_max_norm_Test) {
	double res;

	res = I.max_norm(1);	//temp solu
	out << res;
	//std::cout << res;
	proper << "7";
	CHECK_EQUAL(proper.str(), out.str());

	polytope G;
	row = 4;
	col = 2;
	ConstraintsMatrixV.resize(row, col);
	ConstraintsMatrixV(0, 0) = 0;
	ConstraintsMatrixV(0, 1) = 1;
	ConstraintsMatrixV(1, 0) = 0;
	ConstraintsMatrixV(1, 1) = -1;
	ConstraintsMatrixV(2, 0) = 1;
	ConstraintsMatrixV(2, 1) = 0;
	ConstraintsMatrixV(3, 0) = -1;
	ConstraintsMatrixV(3, 1) = 0;

	boundValueV.resize(4);
	boundValueV[0] = -10;
	boundValueV[1] = 10;
	boundValueV[2] = 0;		//9.8;
	boundValueV[3] = 0;			//-9.8;

	boundSignV = 1;

	G.setCoeffMatrix(ConstraintsMatrixV);
	G.setColumnVector(boundValueV);
	G.setInEqualitySign(boundSignV);
	cout << endl << "Amit Gurung Value = " << endl;
	double val = G.max_norm(1);		//temp solu
	cout << endl << "Amit Gurung Over" << val << endl;
	out << "";
	proper << "";
	cout << "Out = " << out.str() << endl;
	out << val;
	proper << "10";
	CHECK_EQUAL(proper.str(), out.str());

	polytope k;
	row = 4;
	col = 2;
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
	boundValueV[0] = 2;
	boundValueV[1] = 2;
	boundValueV[2] = 2;
	boundValueV[3] = -6;

	k.setCoeffMatrix(ConstraintsMatrixV);
	k.setColumnVector(boundValueV);
	k.setInEqualitySign(boundSignV);

	cout << endl << "Raj Gurung Value = " << endl;
	val = k.max_norm(1);		//temp solu
	cout << endl << "Raj Gurung Over" << val << endl;

}
TEST_FIXTURE(ExamplePolytope, polytope_Compute_SF_Test) {
	double sf;

//	sf = I.computeSupportFunction(direction, 2);

	direction[0] = 1;
	direction[1] = 0;
//	sf = I.computeSupportFunction(direction, 2);
	out << sf;
	//std::cout << res;
	proper << "3";
	CHECK_EQUAL(proper.str(), out.str());

	polytope k;
	row = 4;
	col = 2;
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
	boundValueV[0] = 2;
	boundValueV[1] = 2;
	boundValueV[2] = 2;
	boundValueV[3] = -6;

	boundSignV = 1;
cout<<"\n\n\nHello A mit my output from here \n\n\n";
	k.setCoeffMatrix(ConstraintsMatrixV);
	k.setColumnVector(boundValueV);
	k.setInEqualitySign(boundSignV);
	direction[0] = 1;
	direction[1] = 0;
/*
	double sfunc = k.computeSupportFunction(direction, 2);
	cout<<"\n 1 = "<<sfunc<<endl;
*/
	/*out << "";
	proper << "";
	out << sfunc;
	proper << "2";
	CHECK_EQUAL(proper.str(), out.str());*/

	direction[0] = 1;
	direction[1] = 0;
/*
	sfunc = k.computeSupportFunction(direction, 1);
	cout<<"\n 2 = "<<sfunc<<endl;
*/
	/*out << "";
	proper << "";
	out << sfunc;
	proper << "-2";
	CHECK_EQUAL(proper.str(), out.str());
*/
	direction[0] = -1;
	direction[1] = 0;
/*
	sfunc = k.computeSupportFunction(direction, 2);
	cout<<"\n 3 = "<<sfunc<<endl;
*/
	/*out << "";
	proper << "";
	out << sfunc;
	proper << "-2";
	CHECK_EQUAL(proper.str(), out.str());
*/
	direction[0] = 0;
	direction[1] = -1;
/*
	sfunc = k.computeSupportFunction(direction, 2);
	cout<<"\n 4 = "<<sfunc<<endl;
*/
/*
	out << "";
	proper << "";
	out << sfunc;
	proper << "-6";
	CHECK_EQUAL(proper.str(), out.str());
*/


	direction[0] = 0;
	direction[1] = -1;
/*
	sfunc = k.computeSupportFunction(direction, 1);
	cout<<"\n 5 = "<<sfunc<<endl;
*/
	/*out << "";
	proper << "";
	out << sfunc;
	proper << "2";
	CHECK_EQUAL(proper.str(), out.str());
*/

	polytope quad3;
	row = 4;
	col = 2;
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
	boundValueV[0] = 3;
	boundValueV[1] = -2;
	boundValueV[2] = -2;
	boundValueV[3] = 4;

	boundSignV = 1;

	quad3.setCoeffMatrix(ConstraintsMatrixV);
	quad3.setColumnVector(boundValueV);
	quad3.setInEqualitySign(boundSignV);
		direction[0] = 0;
		direction[1] = -1;
/*
		sfunc = quad3.computeSupportFunction(direction, 2);
		cout<<"\n AmitShouldbe = -4 it is? = "<<sfunc<<endl;
*/


}
TEST_FIXTURE(ExamplePolytope, polytope_intersection_Test) {

	bool flag;
//	flag = I.check_polytope_intersection(P2);
	cout << "Same polytope so Intersecting";
	out << flag;
	proper << true;
	CHECK_EQUAL(proper.str(), out.str());
}

TEST_FIXTURE(ExamplePolytope, NOTintersectingPolytopes_Test) {

	bool flag;

	row = 4;
	col = 2;
	ConstraintsMatrixP.resize(row, col);
	ConstraintsMatrixP(0, 0) = -1;
	ConstraintsMatrixP(0, 1) = 0;
	ConstraintsMatrixP(1, 0) = 1;
	ConstraintsMatrixP(1, 1) = 0;
	ConstraintsMatrixP(2, 0) = 0;
	ConstraintsMatrixP(2, 1) = 1;
	ConstraintsMatrixP(3, 0) = 0;
	ConstraintsMatrixP(3, 1) = -1;

	boundValueP.resize(4);

	boundValueP[0] = -10;
	boundValueP[1] = 12;
	boundValueP[2] = 18;
	boundValueP[3] = -15;

	boundSignP = 1;

	P2.setCoeffMatrix(ConstraintsMatrixP);
	P2.setColumnVector(boundValueP);
	P2.setInEqualitySign(boundSignP);

//	flag = I.check_polytope_intersection(P2);
	cout << "Result should be false ie Not intersection" << endl;
	out << flag;
	proper << false;
	CHECK_EQUAL(proper.str(), out.str());
}

}

