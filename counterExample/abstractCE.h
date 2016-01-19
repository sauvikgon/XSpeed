/*
 * abstractCE.h
 *
 *  Created on: 12-Jan-2016
 *      Author: rajarshi
 */

#ifndef ABSTRACTCE_H_
#define ABSTRACTCE_H_

#include "core_system/continuous/ConvexSet/supportFunctionProvider.h"

#include "core_system/HybridAutomata/Transition.h"
#include <list>
#include <boost/shared_ptr.hpp>

//#include "core_system/symbolic_states/symbolic_states.h"
#include "counterExample/abstract_symbolic_state.h"

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
	typedef boost::shared_ptr<abstractCE> ptr;

	/**empty constructor */
	abstractCE() {
	}
	;
	/* another constructor */
	abstractCE(std::list<abstract_symbolic_state::ptr> s_states,
			std::list<transition::ptr> ts) {
		//Assertion to check that the length of the counter-example is one minus
		// the number of sym states in the CE.
		assert(sym_states.size() == trans.size() - 1);
		sym_states = s_states;
		trans = ts;
		length = trans.size();
	}
	/* destructor */
	~abstractCE() {
	}
	;
	const std::list<abstract_symbolic_state::ptr> get_CE_sym_states() const {
		return sym_states;
	}
	const std::list<transition::ptr> get_CE_transitions() const {
		return trans;
	}

	const abstract_symbolic_state::ptr get_first_symbolic_state() const;

	/**
	 * The semantics assumes that the last abstract_symbolic_state in the list is the
	 * unsafe abstract_symbolic_state.
	 */
	const abstract_symbolic_state::ptr get_unsafe_symbolic_state() const;

	const unsigned int get_length() const {
		return length;
	}

	void set_length(unsigned int len) {
		length = len;
	}

	void set_sym_states(std::list<abstract_symbolic_state::ptr> sym) {
		sym_states = sym;
	}

	void set_transitions(std::list<transition::ptr> transitions) {
		trans = transitions;
	}

private:
	/**
	 * The first symbolic state is the initial symbolic state and the last one
	 * is the unsafe symbolic state
	 */
	std::list<abstract_symbolic_state::ptr> sym_states;

	/**
	 * The list of transitions taken from the initial abstract_symbolic_state to the
	 * final abstract_symbolic_state.
	 */
	std::list<transition::ptr> trans;
	/**
	 * length shows how many discrete transitions are present in the abstract counter
	 * example.
	 */
	unsigned int length;

};

#endif /* ABSTRACTCE_H_ */
