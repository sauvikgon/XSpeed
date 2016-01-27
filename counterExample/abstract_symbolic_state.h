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

	abstract_symbolic_state();
	abstract_symbolic_state(discrete_set& discreteSet,
			polytope::ptr continuousSet);

	polytope::ptr getContinuousSet() const;
	void setContinuousSet(polytope::ptr continuousSet);
	const discrete_set& getDiscreteSet() const;
	void setDiscreteSet(const discrete_set& discreteSet);

private:
	discrete_set DiscreteSet; //locationID
	polytope::ptr ContinuousSet;	//bounding_box Polytope
};

#endif /* ABSTRACT_SYMBOLIC_STATE_H_ */