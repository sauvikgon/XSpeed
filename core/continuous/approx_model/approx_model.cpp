#include "approx_model.h"

double approx_model::rho_X0(const std::vector<double>& l)
{
	if(my_X0->getIsEmpty())
	{
		return 0;
	}
	lp_solver lpsol;
	unsigned int bounds_sign = 1; // less than equals constraints
	lpsol.setConstraints(my_X0->getCoeffMatrix(),my_X0->getColumnVector(),bounds_sign);
	return lpsol.Compute_LLP(l);
}

double approx_model::rho_U(const std::vector<double>& l)
{
	if(my_U->getIsEmpty())
	{
		//std::cout << "Empty U set in rho_U" << std::endl;
		return 0;
	}
	math::matrix<double> B = get_B();
	std::vector<double> trans_l;
	if(!B.isIdentity()){
		math::matrix<double> B_trans;
		B.transpose(B_trans);
		B_trans.mult_vector(l,trans_l);
	}
	else trans_l = l;
	lp_solver lpsol;
	unsigned int bounds_sign = 1; // less than equals constraints
	lpsol.setConstraints(my_U->getCoeffMatrix(),my_U->getColumnVector(),bounds_sign);
	return lpsol.Compute_LLP(trans_l);
}
