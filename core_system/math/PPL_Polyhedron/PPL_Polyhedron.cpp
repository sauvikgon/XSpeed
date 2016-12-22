/*
 * PPL_Polyhedron.cpp
 *
 *  Created on: 20-Dec-2016
 *      Author: hazel
 */

#include "core_system/math/PPL_Polyhedron/PPL_Polyhedron.h"


namespace PPL = Parma_Polyhedra_Library ;

PPL_Polyhedron::PPL_Polyhedron() {
	// TODO Auto-generated constructor stub
sign=1;
}

PPL_Polyhedron::PPL_Polyhedron(math::matrix<double> A, std::vector<double> b, int sgn){

	coeff = A;
	bound = b;
	sign = sgn;
	int noOfCons = A.size1();
	int dim = A.size2();
	myPoly = PPL:: NNC_Polyhedron(dim);

	for(int j=0;j<noOfCons;j++) {
		PPL :: Linear_Expression expr;
		PPL :: Linear_Expression ex;
		for (int i=0;i<dim;i++) {
			PPL :: Variable var(i);
			PPL :: Linear_Expression ep=var;
			ep.set_coefficient(var,coeff(j,i));
			if(i==0) {
				expr=ep;
			}else {
				PPL :: Linear_Expression e(expr+ep);
				expr=e;
			}
			ex=ep;
		}
		if(sign==1) {
			PPL :: Constraint c= operator<=(expr,bound[j]);
			myPoly.add_constraint(c);
		}
	}
}

bool PPL_Polyhedron::is_contained(PPL_Polyhedron::ptr poly){
	return (this->myPoly).contains(poly->get_poly());
}
const std::vector<double>& PPL_Polyhedron::getB() const {
	return bound;
}

void PPL_Polyhedron::setB(const std::vector<double>& b) {
	this->bound = b;
}

const math::matrix<double>& PPL_Polyhedron::getCoeff() const {
	return coeff;
}

void PPL_Polyhedron::setCoeff(const math::matrix<double>& coeff) {
	this->coeff = coeff;
}

int PPL_Polyhedron::getSign() const {
	return sign;
}

void PPL_Polyhedron::setSign(int sgn) {
	this->sign = sign;
}
PPL::NNC_Polyhedron PPL_Polyhedron::get_poly() {
		return this->myPoly;
	}
PPL_Polyhedron::~PPL_Polyhedron() {
	// TODO Auto-generated destructor stub
}

