/*
 * omega_abstract_model.h
 *
 *  Created on: 26-Apr-2018
 *      Author: rajarshi
 */

#ifndef APPROX_MODEL_H_
#define APPROX_MODEL_H_

#include <vector>
#include "core/math/matrix.h"
#include "core/math/lp_solver/lp_solver.h"
#include "core/continuous/Polytope/polytope.h"

/**
 * Creating the abstract factory class for abstract model in XSpeed. The
 * derived classes implement the various approximation models such as that
 * of SpaceEx.
 *
 * Omega is the approximation of Reach_{0,\delta}(X_0,U), that is the reachable
 * states in the time interval [0,\delta].
 *
 * Psi is the approximation of Reach_{\delta,\delta}({0},U). This is the
 * reachable states at time \delta, due to the effect of the input U on the
 * origin {0}. The principle of super-position says that:
 *
 * Reach_{t,t+\delta}(X_0,U) = e^At * Reach_{0,\delta}(X_0,U) \oplus Reach_{\delta,\delta}({0},U)
 *
 * It says that the reachable states in the time interval [t, t+\delta] can be
 * obtained by applying the linear transformation on Reach_{0,\delta}(X_0,U) to
 * and then bloating this with Reach_{\delta,\delta}({0},U), the reachable
 * states at time \delta under the influence of ofinputs on the origin {0} .
 */

class approx_model
{

public:

	typedef boost::shared_ptr<approx_model> ptr;

	/** Initializing constructor */
	approx_model(math::matrix<double> my_A, polytope::ptr X0, polytope::ptr U, double delta){
		this->my_A = my_A;
		this->my_X0 = X0;
		this->my_U = U;
		this->my_delta = delta;
	}
	/** virtual destructor */
	virtual ~approx_model(){};

	/** Returns the time-step */
	inline double get_delta() const {return my_delta;}
	
	/** Returns the dynamics matrix A*/
	inline math::matrix<double> get_A() const
	{return my_A;}

	/** Returns the initial_set */
	inline polytope::ptr get_X0() const{return my_X0;}

	/** Returns the input set */
	inline polytope::ptr get_U() const {return my_U;}
	
	/** Computes the support of X0 w.r.t. direction l. */
	virtual double rho_X0(const std::vector<double>& l);

	/** Compute the support of U w.r.t. direction l. */
	virtual double rho_U(const std::vector<double>& l);
	
	/** computes the support function of Omega_0 w.r.t l */
	virtual double first_omega_support(const std::vector<double>& l, double time_step) = 0;
	
	/** Computes the support function of Omega_{i*\delta} w.r.t l
	 *  This is an interface method to be implemented
	 *  by the deriving class.
	 */	
	virtual double omega_support(const std::vector<double>& l, unsigned int iter)  = 0;

private:
	math::matrix<double> my_A;
	double my_delta;
	polytope::ptr my_X0;
	polytope::ptr my_U;

	/** Computes the support function of Psi w.r.t l
	 */
	virtual double psi_support(const std::vector<double>& l, unsigned int iter) = 0;

};

#endif /* APPROX_MODEL_H_ */
