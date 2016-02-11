#include "abstract_symbolic_state.h"

abstract_symbolic_state::abstract_symbolic_state(discrete_set& discreteSet,
		polytope::ptr continuousSet) {
	DiscreteSet = discreteSet;
	ContinuousSet = continuousSet;
}

polytope::ptr abstract_symbolic_state::getContinuousSet() const {
	return ContinuousSet;
}

void abstract_symbolic_state::setContinuousSet(polytope::ptr continuousSet) {
	ContinuousSet = continuousSet;
}

const discrete_set& abstract_symbolic_state::getDiscreteSet() const {
	return DiscreteSet;
}

void abstract_symbolic_state::setDiscreteSet(const discrete_set& discreteSet) {
	DiscreteSet = discreteSet;
}
