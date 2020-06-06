/*
 * fb_interpol.h
 *
 *  Created on: 29-Apr-2018
 *      Author: rajarshi
 */

#ifndef FB_INTERPOL_H_
#define FB_INTERPOL_H_

#include <core/continuous/approxModel/approxModel.h>
#include "core/math/analyticODESol.h"
#include <nlopt.hpp>

/**
 * This class implements the intersection of forward-backward interpolation
 * approximation model of CAV'11 by Goran Frehse et. al.
 */
class fb_interpol : public approx_model
{
	math::matrix<double> transpose_phi_2;	//{\phi_2}^T
	math::matrix<double> transpose_A_square; //{A^2}^T
	math::matrix<double> transpose_AsquarePhi; //{A^2.expAt}^T
	math::matrix<double> transpose_A; //A^T
	unsigned int num_iters; // essential for efficient computation of rho_psi
	std::vector<double> rho_psi; // stores rho_{psi_k}
	std::vector<math::matrix<double> > phi_list; 

	std::vector<double> rho_AU_list;	
	std::vector<double> rho_symhull_AU_list;
	std::vector<double> rho_AsqrX0_list;
	std::vector<double> rho_AsqrPhiX0_list;
	std::vector<double> rho_symhull_AsqrX0_list;
	std::vector<double> rho_symhull_AsqrPhiX0_list;
	unsigned int dim; // dimension of the system.
	nlopt::opt myopt; //  nlopt obj for solving maximization problem
public:
	/* constructor */
	fb_interpol(math::matrix<double>& my_A, polytope::ptr X0, polytope::ptr U, math::matrix<double>& my_B, double delta, unsigned int num_iters);

	/** Virtual destructor class */
	virtual ~fb_interpol();

	/** computes the support function of Omega_0 w.r.t l */
	virtual double first_omega_support(const std::vector<double>& l, double time_step);

	/** Computes the support function of Omega_{iter*\delta} w.r.t l */
	virtual double omega_support(const std::vector<double>& l, unsigned int iter);

	/** Computes the support function of Psi w.r.t l */
	virtual double psi_support(const std::vector<double>& l, unsigned int iter);
	/** Called by nlp objective routine from outside class */ 
	double rho_fb_intersection(const std::vector<double>& l, double lambda);
private:
	double rho_symhull_AU(const std::vector<double>& l);
	double rho_epsilon_psi(const std::vector<double>& l);

	double rho_symhull_AsquareX0(const std::vector<double>& l);
	double rho_omega_plus(const std::vector<double>& l);

	double rho_symhull_AsquarePhiX0(const std::vector<double>& l);
	double rho_omega_minus(const std::vector<double>& l);

	void initialize_rho();
};

// structure to hold terms for computing the obj function
struct terms
{
	double sup_X0;
	double sup_phiX0;
	double sup_deltaU;
	double sup_epsilon_psi;
	std::vector<double> direction;
	fb_interpol* fb_interpol_obj;
};
typedef struct terms terms;

//Objective function for solving max opt. problem
double myobjfun(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

#endif /* FB_INTERPOL_H_ */
