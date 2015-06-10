/*
 * symbolic_states.h
 *
 *  Created on: 12-Nov-2014
 *      Author: amit
 */

#include "core_system/continuous/Polytope/Polytope.h"
#include "core_system/discrete/discrete_set/discrete_set.h"

#ifndef SYMBOLIC_STATES_H_
#define SYMBOLIC_STATES_H_

class symbolic_states{
public:
	symbolic_states();
	symbolic_states(discrete_set DiscreteSet, polytope::ptr ContinuousSet);
	polytope::ptr getContinuousSet();
	void setContinuousSet(const polytope::ptr continuousSet);
	const discrete_set& getDiscreteSet() const;
	void setDiscreteSet(const discrete_set& discreteSet);

private:
	discrete_set DiscreteSet;
	polytope::ptr ContinuousSetptr;
};

#endif /* SYMBOLIC_STATES_H_ */
