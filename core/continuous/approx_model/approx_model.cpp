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
		/*std::cout<< "Btrans dim: row=" << B_trans.size1() << ", col="<<B_trans.size2() << std::endl;
		std::cout << "size of trans_l=" << trans_l.size() << std::endl;
		*/
	}
	else trans_l = l;
	lp_solver lpsol;
	unsigned int bounds_sign = 1; // less than equals constraints
	/*std::cout << "dim of U:" << my_U->getSystemDimension() << std::endl;
	std::cout << "U.numrows=" << my_U->getCoeffMatrix().size1() << std::endl;
	std::cout << "U.numcols=" << my_U->getCoeffMatrix().size2() << std::endl;
	std::cout << "U colvector size=" << my_U->getColumnVector().size() << std::endl;

	std::cout << "coeff of U:" << my_U->getCoeffMatrix() << std::endl;	
	std::cout << "col vec of U:\n";
	for(unsigned int i=0;i<my_U->getColumnVector().size();i++){
		std::cout << my_U->getColumnVector()[i] << " " << std::endl;
	}	
	*/	
	
	lpsol.setConstraints(my_U->getCoeffMatrix(),my_U->getColumnVector(),bounds_sign);
	return lpsol.Compute_LLP(trans_l);
}
