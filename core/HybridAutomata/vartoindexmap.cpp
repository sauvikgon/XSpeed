/*
 * vartoindexmap.cpp
 *
 *  Created on: 07-Feb-2016
 *      Author: rajarshi
 */

#include "../../core/HybridAutomata/vartoindexmap.h"

#include <iostream>

/* The variable to dimension index map */
var_to_index_map::map_ptr var_to_index_map::var_index_map_ptr =
		var_to_index_map::map_ptr(new std::map<std::string,unsigned int>());

/* The input to index map*/
var_to_index_map::map_ptr var_to_index_map::uvar_index_map_ptr =
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

void var_to_index_map::print_input_index_map()
{
	unsigned int i = 0;
	std::cout << "The input to index map is:\n";
	for(std::map<std::string, unsigned int>::iterator it = uvar_index_map_ptr->begin(); it!=uvar_index_map_ptr->end();it++){
		std::cout << "Input = " << (*it).first;
		std::cout << " Dimension = " << (*it).second << std::endl;
		i++;
	}
}

/* returns the variable name with the given index */
std::string var_to_index_map::get_varname(unsigned int index)
{
	for(std::map<std::string, unsigned int>::iterator it = var_index_map_ptr->begin(); it!=var_index_map_ptr->end();it++){
		if(index == (*it).second)
			return (*it).first;
	}
	throw std::runtime_error("var to index map: get_varname(): parameter index not in the map\n");
}

/* returns the input name with the given index */
std::string var_to_index_map::get_uvarname(unsigned int index)
{
	for(std::map<std::string, unsigned int>::iterator it = uvar_index_map_ptr->begin(); it!=uvar_index_map_ptr->end();it++){
		if(index == (*it).second)
			return (*it).first;
	}
	throw std::runtime_error("var to index map: get_uvarname(): parameter index not in the map\n");
}

/**
 * Returns the size of the map, i.e., the number of variables of the map
 */
unsigned int var_to_index_map::map_size()
{
	return var_index_map_ptr->size();
}

/**
 * Returns the size of the umap, i.e., the number of inputs in the map
 */
unsigned int var_to_index_map::umap_size()
{
	return uvar_index_map_ptr->size();
}
