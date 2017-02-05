/*
 * Polyhedron.h
 *
 *  Created on: 20-Dec-2016
 *      Author: hazel
 */

#ifndef PPL_POLYHEDRON_H_
#define PPL_POLYHEDRON_H_

#include "core_system/math/matrix.h"
#include <ppl.hh>
#include <string>
#include <sstream>
#include <boost/shared_ptr.hpp>


namespace PPL = Parma_Polyhedra_Library ;

class PPL_Polyhedron {
private:
	math::matrix<double> coeff;
	std::vector<double> bound;
	int sign;
	PPL::NNC_Polyhedron myPoly;
	PPL::NNC_Polyhedron get_poly();
public:
	typedef boost::shared_ptr<PPL_Polyhedron> ptr;
	PPL_Polyhedron();
	virtual ~PPL_Polyhedron();
	PPL_Polyhedron(math::matrix<double> A, std::vector<double> b, int sgn);
	const std::vector<double>& getB() const;
	void setB(const std::vector<double>& b);
	const math::matrix<double>& getCoeff() const;
	void setCoeff(const math::matrix<double>& coeff);
	int getSign() const;
	void setSign(int sign);

	/*
	 * The polyhedron poly will be tested in the calling polyhedron if it is contained within it.
	 */
	bool is_contained(PPL_Polyhedron::ptr poly);

};

#endif /* PPL_POLYHEDRON_H_ */
