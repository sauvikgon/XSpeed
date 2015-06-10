#include "core_system/symbolic_states/symbolic_states.h"

symbolic_states::symbolic_states(){
	;
}
symbolic_states::symbolic_states(discrete_set DiscreteSet, polytope::ptr ContinuousSet){
	this->DiscreteSet = DiscreteSet;
	this->ContinuousSetptr = ContinuousSet;
}

polytope::ptr symbolic_states::getContinuousSet() {
	return ContinuousSetptr;
}

void symbolic_states::setContinuousSet(const polytope::ptr continuousSet) {
	this->ContinuousSetptr = continuousSet;
}

const discrete_set& symbolic_states::getDiscreteSet() const {
	return DiscreteSet;
}

void symbolic_states::setDiscreteSet(const discrete_set& discreteSet) {
	this->DiscreteSet = discreteSet;
}
