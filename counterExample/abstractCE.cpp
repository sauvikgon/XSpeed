/*
 * abstractCE.cpp
 *
 *  Created on: 12-Jan-2016
 *      Author: Rajarshi
 */

#include "counterExample/abstractCE.h"


const symbolic_states::ptr abstractCE::get_first_symbolic_state() const
{
	std::list<symbolic_states::ptr>::const_iterator it = sym_states.begin();
	return *it;

}
const symbolic_states::ptr abstractCE::get_unsafe_symbolic_state() const
{
	std::list<symbolic_states::ptr>::const_iterator it = sym_states.end();
	return *it;
}

