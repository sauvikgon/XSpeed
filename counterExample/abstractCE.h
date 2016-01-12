/*
 * abstractCE.h
 *
 *  Created on: 12-Jan-2016
 *      Author: rajarshi
 */

#ifndef ABSTRACTCE_H_
#define ABSTRACTCE_H_

#include "core_system/continuous/ConvexSet/supportFunctionProvider.h"
#include "core_system/symbolic_states/symbolic_states.h"
#include "core_system/HybridAutomata/Transition.h"
#include <list>

/**
 * This class is a data structure to store the abstract counter-example generated
 * by XSpeed when given an unsafe symbolic state. An abstract counter example
 * is an ordered list of symbolic states starting from an initial and ending in an
 * unsafe symbolic symbolic state.
 *
 * @author: Rajarshi
 */

class abstractCE
{
public:
	/**empty constructor */
	abstractCE(){};
	/* another constructor */
	abstractCE(std::list<symbolic_states::ptr> s_states, std::list<transition::ptr> ts)
	{
		//Assertion to check that the length of the counter-example is one minus
		// the number of sym states in the CE.
		assert (sym_states.size() == trans.size() - 1);
		sym_states = s_states;
		trans = ts;
		length = trans.size();
	}
	/* destructor */
	~abstractCE(){};
	const std::list<symbolic_states::ptr> get_CE_sym_states() const{
		return sym_states;
	}
	const std::list<transition::ptr> get_CE_transitions() const{
		return trans;
	}

	const symbolic_states::ptr get_first_symbolic_state() const;

	/**
	 * The semantics assumes that the last symbolic state in the list is the
	 * unsafe symbolic state.
	 */
	const symbolic_states::ptr get_unsafe_symbolic_state() const;

	const unsigned int get_length() const
	{
		return length;
	}

private:
	/**
	 * The first symbolic state is the initial symbolic state and the last one
	 * is the unsafe symbolic state
	 */
	std::list<symbolic_states::ptr> sym_states;

	/**
	 * The list of transitions taken from the initial symbolic state to the
	 * final symbolic state.
	 */
	std::list<transition::ptr> trans;
	/**
	 * length shows how many discrete transitions are present in the abstract counter
	 * example.
	 */
	unsigned int length;

};

#endif /* ABSTRACTCE_H_ */
