/*
 * omega_abstract_model.h
 *
 *  Created on: 26-Apr-2018
 *      Author: rajarshi
 */

#ifndef OMEGA_ABSTRACT_MODEL_H_
#define OMEGA_ABSTRACT_MODEL_H_

#include <vector>
#include "core_system/math/matrix.h"

/**
 * Creating the abstract factory class for Omega model in XSpeed. This emulates the
 * approximation models in SpaceEx (by Goran Frehse).
 *
 * Omega is the approximation of Reach_{0,\delta}(X_0,U), that is the reachable states in the
 * time interval [0,\delta].
 *
 * Psi is the approximation of Reach_{\delta,\delta}({0},U). that is the reachable states at
 * time \delta, due to the effect of the input U on the origin {0}. The principle of super-position says that:
 *
 * Reach_{t,t+\delta}(X_0,U) = e^At * Reach_{0,\delta}(X_0,U) \oplus Reach_{\delta,\delta}({0},U)
 *
 * It says that the reachable states in the time interval [t, t+\delta] can be obtained by applying
 * the linear transformation on Reach_{0,\delta}(X_0,U) to t assuming there is no input and then bloating this
 * with Reach_{\delta,\delta}({0},U), the influence of inputs until t.
 */

class Omega
{

public:

	typedef boost::shared_ptr<Omega> ptr;

	/** Initializing constructor */
	Omega(const math::matrix<double> my_A, const polytope::ptr X0, const polytope::ptr U, const double delta){
		this->my_A = my_A;
		this->my_X0 = X0;
		this->my_U = U;
		this->my_delta = delta;
	}
	/** virtual destructor */
	virtual ~Omega();

	/** Computes the support of X0 w.r.t. direction l. */
	virtual double rho_X0(const std::vector<double>& l);

	/** Compute the support of U w.r.t. direction l. */
	virtual double rho_U(const std::vector<double>& l);

	/** Computes the support function of Omega w.r.t l
	 *  This is an interface method to be implemented
	 *  by the deriving class.
	 */
	virtual double Omega_support(const std::vector<double>& l)  = 0;

	/** Computes the support function of Psi w.r.t l
	 *  This is an interface method to be implemented
	 *  by the deriving class.
	 */
	virtual double Psi_support(const std::vector<double>& l) = 0;

private:
	math::matrix<double> my_A;
	double my_delta;
	polytope::ptr my_X0;
	polytope::ptr my_U;
//	double my_rho_X0;
//	double my_rho_U;
//	double my_rho_X0_next;
//	std::vector<double> my_l;
//	std::vector<double> my_l_next;
};


double Omega::rho_X0(const std::vector<double>& l)
{
	lp_solver lpsol;
	int lp_solver_type = 1; // glpk
	lpsol.setConstraints(this->my_X0->getCoeffMatrix(),this->my_X0->getColumnVector(),lp_solver_type);
	return this->my_X0->computeSupportFunction(l, lpsol);
}

double Omega::rho_U(const std::vector<double>& l)
{
	lp_solver lpsol;
	int lp_solver_type = 1; // glpk
	lpsol.setConstraints(this->my_U->getCoeffMatrix(),this->my_U->getColumnVector(),lp_solver_type);
	return this->my_U->computeSupportFunction(l, lpsol);
}

#endif /* OMEGA_ABSTRACT_MODEL_H_ */
