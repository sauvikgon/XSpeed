/*
 * Polyhedron.h
 *
 * Created on: 02-April-2017
 *      Author: Amit
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
	PPL::NNC_Polyhedron myPoly;
	PPL::NNC_Polyhedron get_poly();
public:
	typedef boost::shared_ptr<PPL_Polyhedron> ptr;
	PPL_Polyhedron();
	virtual ~PPL_Polyhedron();
	PPL_Polyhedron(PPL::NNC_Polyhedron mypoly);
	PPL_Polyhedron(math::matrix<double> A, std::vector<double> b, int sgn);

	/*
	 * Converts the calling PPL polyhedron into XSpeed's format polytopes component matrix A and vector b
	 */
	void convert_to_poly(math::matrix<double>& a, std::vector<double> & b);

	/*
	 * The polyhedron poly will be tested in the calling polyhedron if it is contained within it.
	 */
	bool is_contained(PPL_Polyhedron::ptr poly);

	/*
	 * returns the convex_hull of p with the calling Polyhedron
	 */
	void convex_hull(PPL_Polyhedron::ptr p );

	PPL::NNC_Polyhedron get_ppl_poly();

};

#endif /* PPL_POLYHEDRON_H_ */
