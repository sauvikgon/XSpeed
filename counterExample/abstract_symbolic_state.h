/*
 * abstract_symbolic_state.h
 *
 *  Created on: 19-Jan-2016
 *      Author: amit
 */

#ifndef ABSTRACT_SYMBOLIC_STATE_H_
#define ABSTRACT_SYMBOLIC_STATE_H_

#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/discrete/discrete_set/discrete_set.h"

class abstract_symbolic_state {
public:
	typedef boost::shared_ptr<abstract_symbolic_state> ptr;
	typedef boost::shared_ptr<const abstract_symbolic_state> const_ptr;

	abstract_symbolic_state(){
		discreteSet_ptr = discrete_set::ptr(new discrete_set()); // Initialize object
		continuousSet_ptr = polytope::ptr(new polytope());
	}
	~abstract_symbolic_state(){
		discreteSet_ptr.reset();
		continuousSet_ptr.reset();
	};
	abstract_symbolic_state(discrete_set::ptr discreteSet,
			polytope::ptr continuousSet);

	polytope::ptr getContinuousSet() const;
	void setContinuousSet(polytope::ptr continuousSet);
	const discrete_set::ptr getDiscreteSet() const;
	void setDiscreteSet(discrete_set::ptr discreteSet);

private:
	discrete_set::ptr discreteSet_ptr; //locationID
	polytope::ptr continuousSet_ptr;
	;	//bounding_box Polytope
};

#endif /* ABSTRACT_SYMBOLIC_STATE_H_ */
