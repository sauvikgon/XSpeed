/*
 * transMinkPoly.cpp
 *
 *  Created on: 16-Nov-2014
 *      Author: amit
 */
#include "transMinkPoly.h"
#include "application/sf_utility.h"

transMinkPoly::transMinkPoly(polytope::ptr myX0, polytope::ptr myU, math::matrix<double> myTRANS, math::matrix<double> myB_TRANS, double mytime, double mybeta)
{
	X0 = myX0;
	U= myU;
	TRANS = myTRANS;
	B_TRANS = myB_TRANS;
	time = mytime;
	beta = mybeta;
}
transMinkPoly::transMinkPoly(polytope::ptr myX0, math::matrix<double> myTRANS)
{
	X0 = myX0;
	U = polytope::ptr(new polytope(true));
	TRANS = myTRANS;
	time = 0;
	beta = 0;
}
unsigned int transMinkPoly::getSystemDimension() const {
	return X0->getSystemDimension();
}

bool transMinkPoly::getIsEmpty() const {
	if(X0->getIsEmpty() && U->getIsEmpty())
		return true;
	else
		return false;
}

double transMinkPoly::computeSupportFunction(std::vector<double> direction, lp_solver &lp) {
//this function is also called from compute_beta, compute_alfa, etc
	std::vector<double> dprime;
	TRANS.mult_vector(direction,dprime);
	double res1 = X0->computeSupportFunction(dprime,lp);

	double res2 = 0;

	if(!U->getIsEmpty()){
		B_TRANS.mult_vector(direction,dprime);
		res2 = U->computeSupportFunction(dprime,lp);
	}

	double res = res1 + time * res2;
	if(beta!=0){
		double dir_norm = support_unitball_infnorm(direction);
		return res + beta*dir_norm;
	}
	else
		return res;
}

double transMinkPoly::max_norm(int lp_solver_type_choosen)
{
	unsigned int dimension_size = this->getSystemDimension();
		double Max_A, sf, Max = 0.0;
	//	std::cout << "Inside transmink max_norm\n";
		if (this->getIsEmpty()){
			sf = 0;	//returns zero for empty polytope
			//std::cout << "Inside transmink max_norm.. set empty\n";
		}
		/*else if (this->getIsUniverse())
			throw("\nUniverse Unbounded Polytope!!!\n"); */
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
			lp_solver lp(type), lp_U(type);

			if(!X0->getIsEmpty()){
				lp.setMin_Or_Max(2);	//Setting GLP_MAX
				lp.setConstraints(X0->getCoeffMatrix(), X0->getColumnVector(),
						X0->getInEqualitySign());
			}

			if(!U->getIsEmpty()){
				lp_U.setMin_Or_Max(2);	//Setting GLP_MAX
				lp_U.setConstraints(U->getCoeffMatrix(), U->getColumnVector(),
						U->getInEqualitySign());
			}

	//Finding the maximum of all Direction : Returns the max element
			for (unsigned int i = 0; i < generator_directions.size(); i++) {
				std::vector<double> each_generator;
				each_generator = generator_directions[i];
				//cout<<"Each Generator = (" << each_generator[0]<<" , "<<each_generator[1]<<") "<<endl;
				sf = computeSupportFunction(each_generator,lp);
				Max_A = (abs(sf));
				if (Max_A > Max)
					Max = Max_A;
			}
		}
		return Max;
}

