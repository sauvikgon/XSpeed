/*
 * Transition.cpp
 *
 *  Created on: 09-Jul-2014
 *      Author: amit
 */
//#include "HybridAutomata/Location.h"
#include "core_system/HybridAutomata/Transition.h"

using namespace std;

transition::transition() {
	trans_id = -1;	//indicates Empty Transition
	label = "";
	math::matrix<double> m;
	Gaurd = polytope::ptr(new polytope()); // universal guard, always true
	unsigned int dim = Gaurd->map_size();
	m.matrix_Identity(dim, Assign_T.Map);
	Assign_T.b = std::vector<double>(dim,0);
}
transition::transition(int transition_id, string label_name, int source_id,
		int dest_id, polytope::ptr gaurd, Assign assign_Trans) {
	trans_id = transition_id;
	label = label_name;
	source_location_id =source_id;
	destination_location_id = dest_id;
	Gaurd = gaurd;
	Assign_T = assign_Trans;
}

Assign& transition::getAssignT() {
	return Assign_T;
}

void transition::setAssignT(Assign assignT) {
	Assign_T = assignT;
	/*Assign_T.Map = assignT.Map;
	 Assign_T.b = assignT.b;	*/
}

polytope::ptr transition::getGaurd() {
	return Gaurd;
}

void transition::setGaurd(polytope::ptr gaurd) {
	Gaurd = gaurd;
}

const string& transition::getLabel() const {
	return label;
}

void transition::setLabel(const string& label) {
	this->label = label;
}

int transition::getDestination_Location_Id() {
	return destination_location_id;
}

void transition::setDestination_Location_Id(int dest_loc_id) {
	destination_location_id = dest_loc_id;
}

int transition::getSource_Location_Id() {
	return source_location_id;
}

void transition::setSource_Location_Id(int source_loc_id) {
	source_location_id = source_loc_id;
}
int transition::getTransitionId() const {
	return trans_id;
}

void transition::setTransitionId(int transId) {
	trans_id = transId;
}

std::vector<double> transition::applyTransitionMap(std::vector<double> x)
{

	std::vector<double> x_prime(x.size());

	math::matrix<double> R = this->Assign_T.Map;
	std::vector<double> w = this->Assign_T.b;

	assert(x.size() == R.size2());
	assert(x.size() == w.size());

	for (unsigned int i = 0; i < R.size1(); i++) {
		double row_sum = 0.0;
		for (unsigned int j = 0; j < R.size2(); j++) {
			row_sum = row_sum + R(i, j) * x[j];
		}
		x_prime[i] = row_sum + w[i];
	}
	return x_prime;
}
