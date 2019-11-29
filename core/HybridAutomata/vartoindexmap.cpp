/*
 * vartoindexmap.cpp
 *
 *  Created on: 07-Feb-2016
 *      Author: rajarshi
 */

#include "../../core/HybridAutomata/vartoindexmap.h"

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
	for(std::map<std::string, unsigned int>::iterator it = var_index_map_ptr->begin(); it!=var_index_map_ptr->end();it++){
		std::cout << "Variable = " << (*it).first;
		std::cout << " Dimension = " << (*it).second << std::endl;
		i++;
	}
}

std::string var_to_index_map::get_varname(unsigned int index)
{
	for(std::map<std::string, unsigned int>::iterator it = var_index_map_ptr->begin(); it!=var_index_map_ptr->end();it++){
		if(index == (*it).second)
			return (*it).first;
	}
	throw std::runtime_error("var to index map: get_varname(): parameter index not in the map\n");
}

/**
 * Returns the size of the map, i.e., the number of variables of the map
 */
unsigned int var_to_index_map::map_size()
{
	return var_index_map_ptr->size();
}
