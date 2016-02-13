#include "core_system/symbolic_states/symbolic_states.h"

symbolic_states::symbolic_states() {
	DiscreteSetptr = discrete_set::ptr(new discrete_set());
	ContinuousSetptr = template_polyhedra::ptr(new template_polyhedra());
}
/*
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
 */
symbolic_states::symbolic_states(discrete_set::ptr DSetptr,
		template_polyhedra::ptr ContinuousSetptr) {
	this->DiscreteSetptr = DSetptr;
	this->ContinuousSetptr = ContinuousSetptr;
}

symbolic_states::symbolic_states(discrete_set::ptr dsetPtr,
		template_polyhedra::ptr ContinuousSet,
		symbolic_states::ptr parentPtr_symbolic_state, int transition_id) {
	this->DiscreteSetptr = dsetPtr;
	this->ContinuousSetptr = ContinuousSet;
	this->parentPtr_symbolic_state = parentPtr_symbolic_state;
	this->transition_id = transition_id;
}

const discrete_set::ptr symbolic_states::getDiscreteSet() const {
	return DiscreteSetptr;
}

template_polyhedra::ptr symbolic_states::getContinuousSetptr() const {
	return ContinuousSetptr;
}

void symbolic_states::setDiscreteSet(const discrete_set::ptr dsetPtr) {
	this->DiscreteSetptr = dsetPtr;
}

void symbolic_states::setContinuousSetptr(
		template_polyhedra::ptr continuousSetptr) {
	ContinuousSetptr = continuousSetptr;
}

symbolic_states::ptr symbolic_states::getParentPtrSymbolicState() const {
	return parentPtr_symbolic_state;
}

void symbolic_states::setParentPtrSymbolicState(
		symbolic_states::ptr parentPtrSymbolicState) {
	parentPtr_symbolic_state = parentPtrSymbolicState;
}

int symbolic_states::getTransitionId() const {
	return transition_id;
}

void symbolic_states::setTransitionId(int transitionId) {
	transition_id = transitionId;
}

polytope::ptr symbolic_states::getInitial_ContinousSetptr() const {

	polytope p;
	p = this->ContinuousSetptr->getPolytope(0); //gets the 1st polytope from the sfm
	polytope::ptr initial_polytope_I;

	initial_polytope_I = polytope::ptr(
			new polytope(p.getCoeffMatrix(), p.getColumnVector(),
					p.getInEqualitySign()));
	return initial_polytope_I;
}
