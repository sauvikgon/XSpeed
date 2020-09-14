/*
 * bmc.cpp
 *
 *  Created on: 14-Sep-2020
 *      Author: rajarshi
 */

#include <counterExample/bmc.h>

bmc::bmc() {
	// TODO Auto-generated constructor stub
}

bmc::~bmc() {
	// TODO Auto-generated destructor stub
}

bmc::bmc(hybrid_automata* ha_ptr, forbidden_states& forbidden, unsigned int k){
	this->ha = ha;
	this->forbidden = forbidden;
	this->k = k;
}

/*
 *
 */
path bmc::getNextPath(unsigned int forbid_locId)
{
	path p;
	return p;
}

/*
 * Performs symbolic reachability analysis on a given path p
 * and return the result as a list of symbolic states.
 */
region bmc::getPathRegion(path p){
	region r;
	return r;
}
