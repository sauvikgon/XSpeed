/*
 * vartoindexmap.cpp
 *
 *  Created on: 07-Feb-2016
 *      Author: rajarshi
 */

#include <core_system/HybridAutomata/vartoindexmap.h>
#include <iostream>

var_to_index_map::map_ptr var_to_index_map::var_index_map_ptr =
		var_to_index_map::map_ptr(new std::map<std::string,unsigned int>());

var_to_index_map::var_to_index_map() {
	// TODO Auto-generated constructor stub
}

var_to_index_map::~var_to_index_map() {
	// TODO Auto-generated destructor stub
}
void var_to_index_map::print_var_index_map()
{
	unsigned int i = 0;
	std::cout << "The variable to index map is:\n";
//	while(i<var_index_map.size())
//
//		std::cout << "Variable = " << var_index_map << std::endl;

}
