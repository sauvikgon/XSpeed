/*
 * sf_utility.cpp
 *
 *  Created on: 14-Dec-2014
 *      Author: amit
 */

#include <application/sfUtility.h>


double W_Support(const ReachabilityParameters& ReachParameters,
		Dynamics& system_dynamics, std::vector<double> direction, lp_solver &lp,
		int Min_Or_Max) {
	double result;

	//int type = lp.getLP_Solver_Type();
	//lp_solver lp_dummy(type);		//16th Feb 2015 to avoid redundant object creation


	//Min_Or_Max = 2;	//Maximizing
	math::matrix<double> B_trans;
	B_trans = ReachParameters.B_trans;
	std::vector<double> trans_dir(direction);

	// todo: commented mult_vector. Seems mult vector impl is buggy
	//B_trans.mult_vector(direction, trans_dir);
	//double res1 = ReachParameters.time_step
	//		* system_dynamics.U->computeSupportFunction(trans_dir, lp, lp_dummy, Min_Or_Max);
	double res1 = ReachParameters.time_step
				* system_dynamics.U->computeSupportFunction(trans_dir, lp);

	double beta = ReachParameters.result_beta;
	double res_beta = beta * (double) support_unitball_infnorm(direction);
	result = res1 + res_beta;

	return result;
}


/* Change to remove matrix_exponentiation. Pass as Parameter structure */
double Omega_Support(const ReachabilityParameters& ReachParameters,
		std::vector<double> direction, supportFunctionProvider::ptr Initial_X0,
		Dynamics& system_dynamics, lp_solver &lp, lp_solver &lp_U, int Min_Or_Max) {

	double res1;

	res1 = Initial_X0->computeSupportFunction(direction, lp);

	std::vector<double> trans_dir;
	math::matrix<double> A, B, B_trans;
	math::matrix<double> phi_tau_Transpose;
	std::vector<double> r(direction.size(),0);

	//system_dynamics.MatrixA.matrix_exponentiation(phi_tau,tau);
	phi_tau_Transpose = ReachParameters.phi_trans;
	phi_tau_Transpose.mult_vector(direction, r);	//is this not repeated ? Sir


	double term1, term2, term3, term3a, term3b, res2;

	// todo: changed the above line to below to avoid runtime error
	term1 = Initial_X0->computeSupportFunction(direction, lp);


	// transpose to be done once and stored in the structure of parameters */
	B_trans = ReachParameters.B_trans;

	// todo: changed the above line to below to avoid runtime error
	term2 = ReachParameters.time_step* system_dynamics.U->computeSupportFunction(direction, lp_U);

	// compute alpha once and put it inside reach parameter
	term3a = ReachParameters.result_alfa;//compute_alfa(ReachParameters.time_step,system_dynamics,Initial_X0);

	term3b = support_unitball_infnorm(direction);
	term3 = term3a * term3b;


	res2 = term1 + term2 + term3;

	if (res1 > res2)
		return res1;
	else
		return res2;
}

double Omega_Support_Similar_Direction(const ReachabilityParameters& ReachParameters,
		std::vector<double> direction, supportFunctionProvider::ptr Initial_X0,
		Dynamics& system_dynamics, lp_solver &lp, lp_solver &lp_U,
		int Min_Or_Max, bool same_dir, Optimize_Omega_Support& optimize_omega){

	double res1;
	if (same_dir != true)	{	//if the directions is not similar only then we compute
		res1 = Initial_X0->computeSupportFunction(direction, lp);
		optimize_omega.dir1 = direction;
		optimize_omega.supp_X0 = res1;
	}
	else{
		res1 = optimize_omega.supp_X0;		//get from the stored table
	}

	std::vector<double> trans_dir;
	math::matrix<double> A, B, B_trans;
	math::matrix<double> phi_tau_Transpose;
	std::vector<double> r;
	phi_tau_Transpose = ReachParameters.phi_trans;
	phi_tau_Transpose.mult_vector(direction, r);	//is this not repeated ? Sir

	double term1, term2, term2a, term3, term3a, term3b, res2;
	if (same_dir != true){
		term1 = Initial_X0->computeSupportFunction(r, lp);
		optimize_omega.phi_trans_supp_X0 = term1;
	}else{
		term1 = optimize_omega.phi_trans_supp_X0;
	}


	B_trans = ReachParameters.B_trans;
	B_trans.mult_vector(direction, trans_dir);

	if (same_dir != true){
		term2a = system_dynamics.U->computeSupportFunction(trans_dir, lp_U);
		optimize_omega.Btrans_supp_U = term2a;
	}else{
		term2a = optimize_omega.Btrans_supp_U;
	}

	term2 = ReachParameters.time_step * term2a;

	term3a = ReachParameters.result_alfa;//compute_alfa(ReachParameters.time_step,system_dynamics,Initial_X0);

	term3b = support_unitball_infnorm(direction);
	term3 = term3a * term3b;

	res2 = term1 + term2 + term3;
	if (res1 > res2)
		return res1;
	else
		return res2;
}
