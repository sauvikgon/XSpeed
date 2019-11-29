/*
 * PPL_Polyhedron.cpp
 *
 *  Created on: 20-Dec-2016
 *      Author: hazel
 */

#include "../../../core/math/PPL_Polyhedron/PPL_Polyhedron.h"

#include <sstream>


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
		if(sgn==1){	//sgn==1 for <=
			PPL :: Constraint c= operator<=(expr, b[j]);
			myPoly.add_constraint(c);
		} else if(sgn==2){	//sgn==2 for >=
			PPL :: Constraint c= operator>=(expr, b[j]);
			myPoly.add_constraint(c);
		}  else if(sgn==0){	//sgn==0 for =
			PPL :: Constraint c= operator==(expr, b[j]);
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
	unsigned int row_size = 0;
	for(PPL::Constraint_System::const_iterator i = cs.begin(); i != cs.end(); ++i){
		PPL::Constraint c = *i;
		if(c.is_equality())
			row_size+=2;
		else
			row_size++;
	}

	a.resize(row_size,cs.space_dimension());
	b.resize(row_size);

	std::stringstream strstream; // used for checking the inequality sign

	unsigned int row=0;
	PPL::Constraint c;
	for (PPL::Constraint_System::const_iterator i = cs.begin(); i != cs.end(); ++i){
		c = *i;
	//	std::cout << "Printing Constraint in the PPL polyhedron\n";
		c.ascii_dump(strstream);
		std::string cons = strstream.str();

		std::size_t found_equal = cons.find("=");
		std::size_t found_geq = cons.find(">=");
		std::size_t found_ge = cons.find(">");
		std::size_t found_leq = cons.find("<=");
		std::size_t found_le = cons.find("<");

		if(found_equal!=std::string::npos && found_geq==std::string::npos && found_leq==std::string::npos ){

			//<= constraint
			for (unsigned int j=0;j<c.space_dimension();j++){
					double x =c.coefficient(PPL::Variable(j)).get_d();
					a(row,j)= x;
			}
			b[row] = -1 * c.inhomogeneous_term().get_d();
			row++;
			//>= constraint
			for (unsigned int j=0;j<c.space_dimension();j++){
					double x =c.coefficient(PPL::Variable(j)).get_d();
					x = -1 * x;//-1 todo::need to understand why but works
					a(row,j)= x;
			}
			b[row] = c.inhomogeneous_term().get_d();
			row++;
		}
		else if(found_geq || found_ge){ // convert ge as geq since it overapproximates
			//>= constraint
			for (unsigned int j=0;j<c.space_dimension();j++){
					double x =c.coefficient(PPL::Variable(j)).get_d();
					x = -1 * x;//-1 todo::need to understand why but works
					a(row,j)= x;
			}
			b[row] = c.inhomogeneous_term().get_d();
			row++;
		}

		else if(found_leq || found_le){ // convert ge as geq since it overapproximates
			for (unsigned int j=0;j<c.space_dimension();j++){
					double x =c.coefficient(PPL::Variable(j)).get_d();
					a(row,j)= x;
			}
			b[row] = -1 * c.inhomogeneous_term().get_d();
			row++;
		}
		else{}
		strstream.str("");
	}
	assert(row == row_size);

}

void PPL_Polyhedron::convex_hull(PPL_Polyhedron::ptr p ){
	(this->myPoly).poly_hull_assign(p->myPoly);
	this->myPoly.print();
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
