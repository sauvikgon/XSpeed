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
	typedef boost::shared_ptr<const symbolic_states> const_ptr;

	symbolic_states();
	/*symbolic_states(discrete_set DiscreteSet, polytope::ptr ContinuousSet);
	 polytope::ptr getContinuousSet();
	 void setContinuousSet(const polytope::ptr continuousSet);
	 */
	symbolic_states(discrete_set DiscreteSet,
			template_polyhedra::ptr ContinuousSet);
	symbolic_states(discrete_set DiscreteSet,
			template_polyhedra::ptr ContinuousSet,
			symbolic_states::ptr parentPtr_symbolic_state, int transition_id);

	const discrete_set& getDiscreteSet() const;
	void setDiscreteSet(const discrete_set& discreteSet);
	template_polyhedra::ptr getContinuousSetptr() const;
	void setContinuousSetptr(template_polyhedra::ptr continuousSetptr);
	symbolic_states::ptr getParentPtrSymbolicState() const;
	void setParentPtrSymbolicState(symbolic_states::ptr parentPtrSymbolicState);
	int getTransitionId() const;
	void setTransitionId(int transitionId);

	/*
	 * Returns the initial polytope of the flowpipe
	 */
	polytope::ptr getInitialPolytope() const;

	void setInitialPolytope(polytope::ptr p){
		initial_polytope = p;
	}

private:
	discrete_set DiscreteSet; //locationID
	//polytope::ptr ContinuousSetptr;	//template_polyhedra
	template_polyhedra::ptr ContinuousSetptr; //template_polyhedra::ptr
	polytope::ptr initial_polytope; // the precise initial polytope of the flowpipe without approximation
	symbolic_states::ptr parentPtr_symbolic_state; //pointer to its parent symbolic_state
	int transition_id; //transition_id originating from the parent location to this sym state location
};

#endif /* SYMBOLIC_STATES_H_ */
