/*
 * test_HybridAutomata.cpp
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */

#include <string>
#include <sstream>
#include <iostream>
#include "UnitTest++/UnitTest++.h"

#include <list>
#include <iterator>

#include "application/DataStructureDirections.h"
#include "core_system/HybridAutomata/Hybrid_Automata.h"
#include "core_system/HybridAutomata/Transition.h"
#include "core_system/math/matrix.h"
/*
 hybrid_automata();
 hybrid_automata(std::list<transitions> transition, location init_loc, int dim);
 void addInitLoc(const location& initLoc);
 const location& getInitLoc() const;
 const std::list<transitions>& getTransition() const;
 void addTransition(const std::list<transitions>& transition);
 int getDimension() const;
 void setDimension(int dimension);
 */

using namespace std;
using namespace math;

SUITE(HybridAutomata_TestSuite) {
struct ClassHybridAutomata {
	ClassHybridAutomata() {
		nn = "Hello Welcome";

		size_type row = 2;
		size_type col = 2;
		D.MatrixA.resize(row, col);
		D.MatrixA(0, 0) = 1;
		D.MatrixA(0, 1) = 2;
		D.MatrixA(1, 0) = 3;
		D.MatrixA(1, 1) = 4;

		D.MatrixB.resize(row, col);
		D.MatrixB(0, 0) = 5;
		D.MatrixB(0, 1) = 6;
		D.MatrixB(1, 0) = 7;
		D.MatrixB(1, 1) = 8;

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

		D.U->setCoeffMatrix(ConstraintsMatrixI);
		D.U->setColumnVector(boundValueI);
		D.U->setInEqualitySign(boundSignI);

		Inv.setCoeffMatrix(ConstraintsMatrixI);
		Inv.setColumnVector(boundValueI);
		Inv.setInEqualitySign(boundSignI);
	}
	~ClassHybridAutomata() { /* some teardown */
	}
	string nn;
	typedef typename boost::numeric::ublas::matrix<double>::size_type size_type;
	Dynamics D, outD;
	polytope Gaurd, GaurdOut, Inv, outInv;
	math::matrix<double> ConstraintsMatrixI;
	int boundSignI;
	std::vector<double> boundValueI;

	stringstream out, proper;
};
TEST_FIXTURE(ClassHybridAutomata , constructor1_HybridAutomata_Test) {

	hybrid_automata ha;
	cout << "Just testing the Empty Hybrid Automata's Dimension = "
			<< ha.getDimension() << "\t" << endl;

}
TEST_FIXTURE(ClassHybridAutomata , constructor2_HybridAutomata_Test) {
	//hybrid_automata(std::list<transitions> transition, location init_loc, int dim);

	std::list<transitions> all_trans, all_trans_out;
	location loc(nn, D, Inv), loc_src("WelCome", D, Inv), loc_dest("GoodBye", D,
			Inv), loc_out;
	int dimen = 2;

	Gaurd.setCoeffMatrix(ConstraintsMatrixI);
	Gaurd.setColumnVector(boundValueI);
	Gaurd.setInEqualitySign(boundSignI);

	string label1 = "Amit Gurung";
	string label2 = "Raj Gurung";

	math::matrix<double> m(2, 2);
	m(0, 0) = 7;
	m(0, 1) = 7;
	m(1, 0) = 7;
	m(1, 1) = 7;
	std::vector<double> b(2, 99.0);	//assigning with 99 as all values
	Assign T, Tout;
	T.Map = m;
	T.b = b;

	transitions trans1(label1, loc_src, loc_dest, Gaurd, T);//creating object of location as loc
	transitions trans2(label2, loc_src, loc_dest, Gaurd, T);//creating object of location as loc
	transitions trans3();	//creating object of location as loc
	all_trans.push_back(trans1);
	all_trans.push_back(trans2);

	hybrid_automata ha(all_trans, loc, dimen);

	all_trans_out = ha.getTransition();
	loc_out = ha.getInitLoc();
	cout << "Dimension from Object H A = " << ha.getDimension() << " Good Work"
			<< endl;
	cout << "**********************************************" << endl;
	std::list<transitions>::iterator i;
	for (i = all_trans_out.begin(); i != all_trans_out.end(); i++) {
		//trans3 = all_trans_out.front().label;		not working
		cout << "Label from the list of Transitions = " << (*i).getLabel()
				<< endl;
		cout << "from the List of Transitions::Source->location::Name = "
				<< (*i).getSource().getName() << endl;
		cout << "from the List of Transitions::Destination->location::Name = "
				<< (*i).getDestination().getName() << endl;

		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	}

}

}

