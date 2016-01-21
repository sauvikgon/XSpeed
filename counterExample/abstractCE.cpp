/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include "counterExample/abstractCE.h"

const abstract_symbolic_state::ptr abstractCE::get_first_symbolic_state() const {
	std::list<abstract_symbolic_state::ptr>::const_iterator it =
			sym_states.begin();
	return *it;

}
const abstract_symbolic_state::ptr abstractCE::get_unsafe_symbolic_state() const {
	std::list<abstract_symbolic_state::ptr>::const_iterator it =
			sym_states.end();
	return *it;
}

concreteCE abstractCE::get_concrete_CE() {
	// TODO: to be implemented
	concreteCE ce;
	return ce;
}
