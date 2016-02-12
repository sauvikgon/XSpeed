#include "abstract_symbolic_state.h"

abstract_symbolic_state::abstract_symbolic_state(discrete_set::ptr discreteSet,
		polytope::ptr continuousSet) {
	discreteSet_ptr = discreteSet;
	continuousSet_ptr = continuousSet;
}

polytope::ptr abstract_symbolic_state::getContinuousSet() const {
	return continuousSet_ptr;
}

void abstract_symbolic_state::setContinuousSet(polytope::ptr continuousSet) {
	continuousSet_ptr = continuousSet;
}

const discrete_set::ptr abstract_symbolic_state::getDiscreteSet() const {
	return discreteSet_ptr;
}

void abstract_symbolic_state::setDiscreteSet(const discrete_set::ptr dset_ptr) {
	discreteSet_ptr = dset_ptr;
}
