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

polytope::ptr PPL_Polyhedron::get_chull(polytope::ptr p){

	polytope::ptr res_poly;
//	PPL::NNC_Polyhedron this_nnc_poly = this->get_poly();
//	PPL_Polyhedron ppl_p(p->getCoeffMatrix(),p->getColumnVector(),p->getInEqualitySign());
//	PPL::NNC_Polyhedron other_nnc_poly = ppl_p.get_poly();
//
//	// get the chull
//	this_nnc_poly.poly_hull_assign(other_nnc_poly);
//
//
//	// Convert NNC poly to result poly
//	PPL::dimension_type ppl_system_dim = this_nnc_poly.space_dimension();
//
//	// Check to ensure that the dimension XSpeed polytope and PPL polytope space dimension match
//	assert(p->getSystemDimension() == ppl_system_dim);
//
//	Constraint_System cs = this_nnc_poly.constraints();
//	unsigned int row_size = cs.num_inequalities();
//	row_size+= 2*cs.num_equalities(); // equality to be converted to two inequalities
//
//	Constraint c;
//	PPL::Polyhedron p;
//
//	math::matrix<double> A(row_size,ppl_system_dim);
//
//	std::vector<double> b(p->getSystemDimension());
//
//	for(Constraint_System_const_iterator it = cs.begin();it!=cs.end();it++){ // iterate over the constraints
//		c = *it;
//		if(c.is_inequality()){
//			for(PPL::dimension_type i=0; i<ppl_system_dim; i++){
//				Variable v(i);
//				double coeff = c.coefficient(v);
//			}
//
//		}
//		else if(c.is_equality()){
//
//		}
//		else {}
//
//		}
//	}
//
//	//---
//	return res_poly;

}
