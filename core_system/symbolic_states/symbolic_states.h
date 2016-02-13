/*
 * symbolic_states.h
 *
 *  Created on: 12-Nov-2014
 *      Author: amit
 */


#ifndef SYMBOLIC_STATES_H_
#define SYMBOLIC_STATES_H_

#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/discrete/discrete_set/discrete_set.h"
#include "Utilities/Template_Polyhedra.h"

class symbolic_states {
public:
	typedef boost::shared_ptr<symbolic_states> ptr;

	symbolic_states();

	symbolic_states(discrete_set::ptr DiscreteSet,
			template_polyhedra::ptr ContinuousSet);
	symbolic_states(discrete_set::ptr DiscreteSet,
			template_polyhedra::ptr ContinuousSet,
			symbolic_states::ptr parentPtr_symbolic_state, int transition_id);

	const discrete_set::ptr getDiscreteSet() const;
	void setDiscreteSet(const discrete_set::ptr discreteSet);
	template_polyhedra::ptr getContinuousSetptr() const;
	void setContinuousSetptr(template_polyhedra::ptr continuousSetptr);
	symbolic_states::ptr getParentPtrSymbolicState() const;
	void setParentPtrSymbolicState(symbolic_states::ptr parentPtrSymbolicState);
	int getTransitionId() const;
	void setTransitionId(int transitionId);

	/*
	 * Returns the first column ie the initial polytope from the sfm(template_polyhedra)
	 */
	polytope::ptr getInitial_ContinousSetptr() const;

private:
	discrete_set::ptr DiscreteSetptr; //locationID
	//polytope::ptr ContinuousSetptr;	//template_polyhedra
	template_polyhedra::ptr ContinuousSetptr; //template_polyhedra::ptr

	symbolic_states::ptr parentPtr_symbolic_state; //pointer to its parent symbolic_state
	int transition_id; //transition_id originating from the parent location to itself
};

#endif /* SYMBOLIC_STATES_H_ */
