/*
 * PPL_Polyhedron.cpp
 *
 *  Created on: 02-April-2017
 *      Author: Amit
 */

#include "core_system/math/PPL_Polyhedron/PPL_Polyhedron.h"


namespace PPL = Parma_Polyhedra_Library ;

PPL_Polyhedron::PPL_Polyhedron() {
	// TODO Auto-generated constructor stub
}

PPL_Polyhedron::PPL_Polyhedron(math::matrix<double> A, std::vector<double> b, int sgn){
	int noOfCons = A.size1();
	int dim = A.size2();
	myPoly = PPL:: NNC_Polyhedron(dim);

	for(int j=0;j<noOfCons;j++)
	{
		PPL :: Linear_Expression expr;
		PPL :: Linear_Expression ex;
		for (int i=0;i<dim;i++)
		{
			PPL :: Variable var(i);
			PPL :: Linear_Expression ep=var;
			ep.set_coefficient(var,A(j,i));
			if(i==0)
				expr=ep;//e//xpr.print();std::cout<<"\n"<<std::endl;
			else {
				PPL :: Linear_Expression e(expr+ep);
				expr=e;
			}
		}
		if(sgn==1){	//sgn is <=
			PPL :: Constraint c= operator<=(expr, b[j]);
			myPoly.add_constraint(c);
		}
	}
}
PPL::NNC_Polyhedron PPL_Polyhedron::get_ppl_poly(){
	return myPoly;
}
PPL_Polyhedron::PPL_Polyhedron(PPL::NNC_Polyhedron mypoly){
	myPoly = mypoly;
}
void PPL_Polyhedron::convert_to_poly(math::matrix<double>& a, std::vector<double> & b){

	const PPL::Constraint_System cs = myPoly.constraints();
	unsigned int nosCons=0;
	for (PPL::Constraint_System::const_iterator i = cs.begin(); i != cs.end(); ++i){
		nosCons++;
	}
	a.resize(nosCons,cs.space_dimension());
	b.resize(nosCons);
	unsigned int row=0,col=0;
	for (PPL::Constraint_System::const_iterator i = cs.begin(); i != cs.end(); ++i){
		for (unsigned int j=0;j<(*i).space_dimension();j++){
			double x =(*i).coefficient(PPL::Variable(j)).get_d();
			if (x != 0)
				x = -1 * x;//-1 todo::need to understand why but works
			a(row,col)= x;
			col++;
		}
		b[row] = (*i).inhomogeneous_term().get_d();
		row++; col=0;
	}
}

void PPL_Polyhedron::convex_hull(PPL_Polyhedron::ptr p ){
	(this->myPoly).poly_hull_assign(p->myPoly);

}

bool PPL_Polyhedron::is_contained(PPL_Polyhedron::ptr poly){
	return (this->myPoly).contains(poly->myPoly);
}

PPL::NNC_Polyhedron PPL_Polyhedron::get_poly() {
	return this->myPoly;
}

PPL_Polyhedron::~PPL_Polyhedron() {
	// TODO Auto-generated destructor stub
}

