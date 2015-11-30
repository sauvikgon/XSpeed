#ifndef POLYTOPE_CPP_
#define POLYTOPE_CPP_

/*
 * polytope.cpp
 *
 *  Created on: 30-Jun-2014
 *      Author: amit
 */

#include "core_system/continuous/Polytope/Polytope.h"
//#include "core_system/math/glpk_lp_solver/glpk_lp_solver.h"
//#include "math/lp_gurobi_simplex.h"

//#include <stdlib.h>
#include "core_system/math/basic_functions.h"
#include "core_system/math/matrix.h"
#include "Utilities/StandardVector.h"
#include "Utilities/vector_operations.h"
#include "core_system/math/2d_geometry.h"
#include <set>
#include <utility>

//#include "math/lp_solver_ourSimplex/simplex.h"

using namespace std;

/*
 * to create an empty polytope call the polytope(bool true) constructor
 * to make a polytope non-empty explicit call to setIsEmpty(false) is to be invoked, even if constraints are set to the
 * polytope it will not be converted into non-empty polytope
 * Universe polytope is created by default and is unbounded by default, whenever any constraints are set it automatically
 * becomes bounded universe polytope
 */

polytope::polytope() {
	//lp_init = false;
	InEqualitySign = 0;
	number_facets = 0;
	system_dimension = 0;
	this->IsUniverse = true; //It is a Universe polytope
	this->IsEmpty = false;
}
polytope::polytope(bool empty) {
	//lp_init = false;
	InEqualitySign = 0;
	number_facets = 0;
	system_dimension = 0;
	this->IsEmpty = true;
	this->IsUniverse = true; //It is empty so neither 'bounded' not 'unbounded'
}

polytope::polytope(math::matrix<double> coeffMatrix,
		std::vector<double> columnVector, int InEqualitySign) {

	this->setNumberFacets(coeffMatrix.size1());
	this->setSystemDimension(coeffMatrix.size2());
	this->coeffMatrix = coeffMatrix;
	this->columnVector.resize(this->number_facets);
	this->columnVector = columnVector;
	this->InEqualitySign = InEqualitySign;
	//Since constraints are set So it is not empty and is Universe but 'bounded'
	this->setIsEmpty(false);	//Not an empty Polytope
	this->setIsUniverse(false);	//Not a universe Polytope and is now a 'Bounded' polytope

	//lp.setConstraints(coeffMatrix, columnVector,InEqualitySign);
}

void polytope::setPolytope( math::matrix<double> coeffMatrix,
		 std::vector<double> columnVector, int inEqualitySign) {
	//this->setCoeffMatrix(coeffMatrix);
	this->setNumberFacets(coeffMatrix.size1());
	this->setSystemDimension(coeffMatrix.size2());
	this->coeffMatrix = coeffMatrix;

	//this->setColumnVector(columnVector);
	this->columnVector.resize(this->number_facets);
	this->columnVector = columnVector;
	//this->setNumberFacets(columnVector.size());

	//this->setInEqualitySign(inEqualitySign);
	this->InEqualitySign = inEqualitySign;

	this->setIsUniverse(false);	//Not a Universe Polytope and is now 'Bounded' polytope

	//call to lp.set_Min_Or_Max() must be call before setConstraints()
	//lp.setConstraints(coeffMatrix, columnVector,inEqualitySign);
}

/*
 void polytope::set_Default_lp_init(){
 lp_init = false;
 }
 */
//void polytope::set_lp_object(glpk_lp_solver* newObject){
//	lp = *newObject;
//	lp_init = false;
//}
void polytope::setIsEmpty(bool empty) {
	this->IsEmpty = empty;
}
bool polytope::getIsEmpty() const {
	return this->IsEmpty;
}
void polytope::setIsUniverse(bool universe) {
	this->IsUniverse = universe;
}
bool polytope::getIsUniverse() {
	return this->IsUniverse;
}
math::matrix<double>& polytope::getCoeffMatrix() {
	return this->coeffMatrix;
}
void polytope::setCoeffMatrix(const math::matrix<double> coeffMatrix) {

	this->setNumberFacets(coeffMatrix.size1());
	this->setSystemDimension(coeffMatrix.size2());

	this->coeffMatrix = coeffMatrix;
	this->setIsUniverse(false);	//Not a Universe Polytope and is now 'Bounded' polytope
}
void polytope::setMoreConstraints(std::vector<double> coeff_constraint,
		double bound_value) {
	unsigned int row_size, col_size;
	row_size = this->getCoeffMatrix().size1();
	col_size = this->getCoeffMatrix().size2();	//dimension of the polytope
	this->coeffMatrix.resize(row_size + 1, col_size, true);	//adding one more constraint
	this->columnVector.resize(row_size + 1);//adding one more constraint's bound value
	for (unsigned int i = 0; i < col_size; i++) {
		this->coeffMatrix(row_size, i) = coeff_constraint[i];
	}
	this->columnVector[row_size] = bound_value;
}

void polytope::setMoreConstraints(math::matrix<double> coeff_constraints,
		std::vector<double> bound_values) {
	unsigned int row_size, dim_size, rows_new;
	row_size = this->getCoeffMatrix().size1();
	dim_size = this->getCoeffMatrix().size2();	//dimension of the polytope
	rows_new = coeff_constraints.size1();
	//dim_size =coeff_constraints.size2();
	unsigned int new_total_rows = row_size + rows_new;

	this->coeffMatrix.resize(new_total_rows, dim_size, true);//adding more constraints
	this->columnVector.resize(new_total_rows);//adding more constraint's bound values
	for (unsigned int i = 0; i < rows_new; i++) {
		for (unsigned int j = 0; j < dim_size; j++) {
			this->coeffMatrix(row_size + i, j) = coeff_constraints(i, j);
		}
		this->columnVector[row_size + i] = bound_values[i];
	}
}

int polytope::getInEqualitySign() const {
	return InEqualitySign;
}
void polytope::setInEqualitySign(int inEqualitySign) {
	InEqualitySign = inEqualitySign;
}
void polytope::setColumnVector(const std::vector<double> columnVector) {
	this->columnVector.resize(this->number_facets);
	this->columnVector = columnVector;
	this->setNumberFacets(columnVector.size());
}
std::vector<double> polytope::getColumnVector() {
	return columnVector;
}

double polytope::computeSupportFunction(std::vector<double> direction,
		lp_solver &lp, lp_solver& lp_U, int Min_Or_Max) {
	double sf;

	/*
	 glpk_lp_solver lp1;	//Create only one lp at the time of creation of the polytope
	 lp1.setMin_Or_Max(Min_Or_Max);
	 lp1.setConstraints(this->coeffMatrix, this->columnVector,
	 this->InEqualitySign);
	 sf = lp1.Compute_LLP(direction);
	 */

	if (this->getIsEmpty())
		sf = 0;	//returns zero for empty polytope
	else if (this->getIsUniverse())
		throw("\nUniverse Unbounded Polytope!!!\n");
	else
		sf = lp.Compute_LLP(direction);	//since lp has already been created and set with constraints at the time of creation

	return sf;
}

unsigned int polytope::getNumberFacets() const {
	return number_facets;
}

void polytope::setNumberFacets(unsigned int numberFacets) {
	number_facets = numberFacets;
}

unsigned int polytope::getSystemDimension() const {
	return system_dimension;
}

void polytope::setSystemDimension(unsigned int systemDimension) {
	system_dimension = systemDimension;
}

double polytope::max_norm(int lp_solver_type_choosen, unsigned int dim_for_Max_Norm) {
	//unsigned int dimension_size = this->system_dimension;
	unsigned int dimension_size = dim_for_Max_Norm;
	double Max_A, sf, Max = 0.0;
	if (this->getIsEmpty())
		sf = 0;	//returns zero for empty polytope
	else if (this->getIsUniverse())
		throw("\nUniverse Unbounded Polytope!!!\n");
	else {
		//sf = lp.Compute_LLP(direction);	//since lp has already been created and set with constraints at the time of creation
		std::vector<std::vector<double> > generator_directions;	//this vector-vector is used only in this function not affecting the rest of the codes
		//Generator for Positive Directions for example Right and Up
		for (unsigned int i = 0; i < dimension_size; i++) {
			std::vector<double> directions(dimension_size, 0.0);
			directions[i] = 1;		//Positive Generators
			generator_directions.push_back(directions);
		}
		//Generator for Negative Directions for example Left and Down
		for (unsigned int i = 0; i < dimension_size; i++) {
			std::vector<double> directions(dimension_size, 0.0);
			directions[i] = -1;		//Negative Generators
			generator_directions.push_back(directions);
		}
		int type = lp_solver_type_choosen;
		lp_solver lp1(type);
		lp1.setMin_Or_Max(2);	//Setting GLP_MAX
		lp1.setConstraints(this->coeffMatrix, this->columnVector, this->InEqualitySign);
//Finding the maximum of all Direction : Returns the max element
		for (unsigned int i = 0; i < generator_directions.size(); i++) {
			std::vector<double> each_generator;
			each_generator = generator_directions[i];
			//cout<<"Each Generator = (" << each_generator[0]<<" , "<<each_generator[1]<<") "<<endl;
			sf = lp1.Compute_LLP(each_generator);
			Max_A = (abs(sf));
			if (Max_A > Max)
				Max = Max_A;
		}
	}
	return Max;
}

const polytope::ptr polytope::GetPolytope_Intersection(polytope::ptr P2,
		int lp_solver_type) {

	math::matrix<double> total_coeffMatrix, m1;
	m1 = this->getCoeffMatrix();//assigning constant matrix to matrix m1 so that matrix_join function can be called
	m1.matrix_join(P2->getCoeffMatrix(), total_coeffMatrix);
	std::vector<double> total_columnVector;
	total_columnVector = vector_join(this->getColumnVector(),
			P2->getColumnVector());

	polytope::ptr newp = polytope::ptr(
			new polytope(total_coeffMatrix, total_columnVector, 1));

	/*newp.setCoeffMatrix(total_coeffMatrix);
	 newp.setColumnVector(total_columnVector);
	 newp.setInEqualitySign(1);*/
	/*
	 //This newp is a polytope with extra directions added which will be more than the template directions
	 //Have to over-approximate the newp polytope to restrict it to just templated directions
	 int type = lp_solver_type;
	 int Min_Or_Max=2;	//maximizing
	 lp_solver lp(type);
	 if (newp->getIsEmpty()==false){
	 lp.setMin_Or_Max(Min_Or_Max);
	 lp.setConstraints(newp->getCoeffMatrix(),newp->getColumnVector(),1);
	 }
	 unsigned int number_of_template_directions, dim; 	//same as the calling polytope's coefficient_matrix
	 number_of_template_directions = this->getCoeffMatrix().size1();	// m1 can also be used
	 dim = this->getCoeffMatrix().size2();
	 std::vector<double> new_columnVector(number_of_template_directions), eachDirection(dim);

	 for (unsigned int i = 0; i < number_of_template_directions; i++){
	 for (unsigned int j=0;j<dim;j++){
	 eachDirection[j]=this->getCoeffMatrix()(i,j);
	 }
	 new_columnVector[i] = lp.Compute_LLP(eachDirection);
	 }
	 polytope::ptr OverNewPolytope = polytope::ptr(new polytope(this->getCoeffMatrix(), new_columnVector, 1));
	 return OverNewPolytope;
	 */
	return newp;
}

/*
 * Checks if the calling Polytope intersects with the polytope P2
 * Return True if it intersects otherwise False
 */

bool polytope::check_polytope_intersection(polytope::ptr p2,
		int lp_solver_type_choosen) {
	bool flag = false;
	/*
	 * Process: Add all constraints of P1(the calling polytope object) and P2 to form new constraints
	 * then run lp_solver's TestConstraints function to test if the constraints have No Feasible Solution,
	 *
	 */
	int Min_Or_Max = 2;
	int type = lp_solver_type_choosen;
	lp_solver lp2(type);
	//lp2.setDefalultObject();		//executed by default now
	lp2.setMin_Or_Max(Min_Or_Max);

	math::matrix<double> total_coeffMatrix, m1;
	m1 = this->getCoeffMatrix();//assigning constant matrix to matrix m1 so that matrix_join function can be called
	m1.matrix_join(p2->getCoeffMatrix(), total_coeffMatrix);

	std::vector<double> total_columnVector;

	total_columnVector = vector_join(this->getColumnVector(),
			p2->getColumnVector());

	/*cout<<"Printing the total ColumnVector = "<<endl;
	 for(unsigned int i=0;i<total_columnVector.size();i++)
	 cout<<total_columnVector[i]<<"\t";
	 cout<<endl;*/

	lp2.setConstraints(total_coeffMatrix, total_columnVector,
			this->InEqualitySign);

	unsigned int checkStatus = lp2.TestConstraints();
	//Later i may have to perform checking if its an empty polytope should not execute this.
	//cout << "\n\nResult of TestConstriants = " << checkStatus << endl;
	//4 for GLP_NOFEAS; 3 for GLP_INFEAS; 6 for solution is unbounded
	if (checkStatus == 4 || checkStatus == 3 || checkStatus == 6)
		flag = false;
	else
		flag = true;

	return flag;
}
/*
 * Searches the 2D vertices of the polytope between the directions u and v
 */

void polytope::enum_2dVert_restrict(std::vector<double> u, std::vector<double> v, int i, int j,
		std::set<std::pair<double,double> >& pts){
	std::vector<double> sv_u(getSystemDimension(),0), sv_v(getSystemDimension(),0);
	std::vector<double> sv_bisect;
	lp_solver solver(1); // to choose glpk
	solver.setConstraints(getCoeffMatrix(),getColumnVector(),getInEqualitySign());

	// get the support
	computeSupportFunction(u,solver,solver,2);
	sv_u = solver.get_sv();
	computeSupportFunction(v,solver,solver,2);
	sv_v = solver.get_sv();
	// add the sv's to the set of points
	// make a point of 2 dimension point

	std::pair<double,double> p1,p2,p3;
	p1.first = sv_u[i];
	p1.second = sv_u[j];

	p2.first = sv_v[i];
	p2.second = sv_v[j];

	pts.insert(p1);
	pts.insert(p2);

	//get the bisector vector;
	std::vector<double> bisector = bisect_vector(normalize_vector(u),normalize_vector(v));
	computeSupportFunction(bisector,solver,solver,2);
	sv_bisect = solver.get_sv();
	p3.first = sv_bisect[i];
	p3.second = sv_bisect[j];

	if(is_collinear(p1,p2,p3)){
		return;
	}
	else{
		pts.insert(p3);
		enum_2dVert_restrict(u,bisector,i,j,pts);
		enum_2dVert_restrict(bisector,v,i,j,pts);
	}
}

std::set<std::pair<double,double> > polytope::enumerate_2dVertices(int i, int j){
	std::set<std::pair<double,double> > All_vertices;

	//enumerate the vertices in the first quadrant
	std::vector<double> u(getSystemDimension(),0);
	u[i]=1;
	std::vector<double> v(getSystemDimension(),0);
	v[j]=1;


	enum_2dVert_restrict(u,v,i,j,All_vertices);

	//enumerate vertices in the second quadrant
	u[i]=-1;
	enum_2dVert_restrict(u,v,i,j,All_vertices);

	//enumerate vertices in the third quadrant
	v[j]=-1;
	enum_2dVert_restrict(u,v,i,j,All_vertices);

	//enumerate vertices in the fourth quadrant
	u[i]=1;
	enum_2dVert_restrict(u,v,i,j,All_vertices);

	return All_vertices;
}


#endif /* POLYTOPE_CPP_ */
