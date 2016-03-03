/*
 * LockAvoidanceUtility.h
 *
 *  Created on: 24-Feb-2016
 *      Author: amit
 */

#ifndef LOCKAVOIDANCEUTILITY_H_
#define LOCKAVOIDANCEUTILITY_H_

#include <vector>
#include "core_system/PWL/pwlist.h"
#include "core_system/symbolic_states/initial_state.h"


// QpwList[t][list] for read and QpwList[t][list] for write
//Returns true if the entire vector of pwlist is empty otherwise false
bool isEmpty_Qpw_list(std::vector<pwlist::ptr> Qpw_list);

//Returns the size of the Qpw_list
unsigned int getSize_Qpw_list(std::vector<pwlist::ptr> Qpw_list);

//Returns a vector of all the waiting intial_state to be processed for flowpipe computation
std::vector<initial_state::ptr> getAllpw_list(std::vector<pwlist::ptr> Qpw_list,
		unsigned int size, pwlist::ptr& allPassedList);

#endif /* LOCKAVOIDANCEUTILITY_H_ */
