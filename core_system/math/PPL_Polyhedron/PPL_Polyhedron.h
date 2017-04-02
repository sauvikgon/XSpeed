/*
 * Polyhedron.h
 *
 *  Created on: 20-Dec-2016
 *      Author: hazel
 */

#ifndef PPL_POLYHEDRON_H_
#define PPL_POLYHEDRON_H_

#include "core_system/math/matrix.h"
#include "core_system/continuous/Polytope/Polytope.h"
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

	void convert_to_poly(math::matrix<double>& a, std::vector<double> & b);
	/*
	 * The polyhedron poly will be tested in the calling polyhedron if it is contained within it.
	 */
	bool is_contained(PPL_Polyhedron::ptr poly);


	/*
	 * returns the convex_hull of calling PPL with the PPL_Polyhedron::ptr p
	 */
	void convex_hull(PPL_Polyhedron::ptr p );

	PPL::NNC_Polyhedron get_ppl_poly();

	/**
	 * Returns the convex hull of the current PPL polyhedron with the passed XSpeed polyhedron.
	 * The returned polytope is XSpeed polytoep type.
	 */
	polytope::ptr get_chull(polytope::ptr p);


};

#endif /* PPL_POLYHEDRON_H_ */
