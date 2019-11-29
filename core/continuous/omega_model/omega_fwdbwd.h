/*
 * omega_fwdbwd.h
 *
 *  Created on: 29-Apr-2018
 *      Author: rajarshi
 */

#ifndef OMEGA_FWDBWD_H_
#define OMEGA_FWDBWD_H_

#include "../../../core/continuous/omega_model/omega_abstract_model.h"


/**
 * This class implements the intersection of forward-backward interpolation
 * approximation model.
 */
class Omega_fwdbwd: public Omega
{

	/** Empty Constructor */
	Omega_fwdbwd();

	Omega_fwdbwd(const math::matrix<double> my_A, const polytope::ptr X0, const polytope::ptr U, const double delta)
	{
		this->Omega(my_A, X0, U, delta);

	}
	/** Virtual destructor class */
	~Omega_fwdbwd();

	/** Computes the support function of Omega w.r.t l */
	virtual double Omega_support(const std::vector<double>& l);

	/** Computes the support function of Psi w.r.t l */
	virtual double Psi_support(const std::vector<double>& l);
};

double Omega_fwdbwd::Omega_support(const std::vector<double>& l)
{
	double res;

	return res;
}

double Omega_fwdbwd::Psi_support(const std::vector<double>& l)
{
	double res;
	return res;
}
#endif /* OMEGA_FWDBWD_H_ */
