/*
 * computeInitialPolytope.cpp
 *
 *  Created on: 24-Nov-2014
 *      Author: amit
 */

#include "../utilities/computeInitialPolytope.h"

polytope::ptr create_polytope_set(supportFunctionProvider::ptr Initial,
		ReachabilityParameters& ReachParameters, Dynamics& SystemDynamics) {

	std::vector<double> columnvector(ReachParameters.Directions.size1());
	lp_solver lp;
	lp.setMin_Or_Max(2);
	if (!Initial->getIsEmpty()) //set glpk constraints If not an empty polytope
		lp.setConstraints(ReachParameters.X0->getCoeffMatrix(),
				ReachParameters.X0->getColumnVector(),
				ReachParameters.X0->getInEqualitySign());

	int dim = ReachParameters.Directions.size2();
	std::vector<double> direction(dim);

	for (unsigned int i = 0; i < ReachParameters.Directions.size1(); i++) {
		//std::cout << "loop 1 \n";
		for (int j = 0; j < dim; j++) {
			direction[j] = ReachParameters.Directions(i, j);
			//std::cout << "loop 2 \n";
		}
		columnvector[i] = Initial->computeSupportFunction(direction, lp);
	}
	polytope::ptr p = polytope::ptr(new polytope(ReachParameters.Directions, columnvector, 1));

	return p;
}

