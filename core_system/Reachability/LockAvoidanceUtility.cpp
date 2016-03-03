/*
 * LockAvoidanceUtility.cpp
 *
 *  Created on: 24-Feb-2016
 *      Author: amit
 */

#include "LockAvoidanceUtility.h"
#include "assert.h"

using namespace std;

// QpwList[t][list] for read and QpwList[t][list] for write
//Returns true if the entire vector of pwlist is empty otherwise false
bool isEmpty_Qpw_list(std::vector<pwlist::ptr> Qpw_list) {
	bool emptyFlag = true;
	for (int i = 0; i < Qpw_list.size(); i++) {
		emptyFlag = Qpw_list[i]->isEmpty_WaitingList();
		if (!emptyFlag)
			break;
	}
	return emptyFlag;
}

unsigned int getSize_Qpw_list(std::vector<pwlist::ptr> Qpw_list) {
	unsigned int list_size, total_size = 0;
	for (int i = 0; i < Qpw_list.size(); i++) {
		list_size = Qpw_list[i]->getWaitingListSize();
		total_size = total_size + list_size;
	}
	return total_size;
}


std::vector<initial_state::ptr> getAllpw_list(std::vector<pwlist::ptr> Qpw_list,
		unsigned int size, pwlist::ptr& allPassedList) {
	std::vector<initial_state::ptr> allList(size); //size is required for static allocate the allList vector size
	unsigned int vectorSize = Qpw_list.size();
	unsigned int index = 0;

	for (int i = 0; i < vectorSize; i++) { //verify by printing   Qpw_list.size()
		//each Qpw_list[i] is a pwlist ... so have to iterate
		unsigned int vectorSize = Qpw_list[i]->getWaitingListSize();
		for (int j = 0; j < vectorSize; j++) {
			allList[index] = Qpw_list[i]->WaitingList_delete_front();	//POP operation
			allPassedList->PassedList_insert(allList[index]);			//PUSH operation
			index++;
		}
	}
	assert(size ==index);
	return allList;
}
