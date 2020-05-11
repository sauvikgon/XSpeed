/*
 * vartoindexmap.h
 *
 *  Created on: 07-Feb-2016
 *      Author: rajarshi
 */

#ifndef VARTOINDEXMAP_H_
#define VARTOINDEXMAP_H_
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <boost/shared_ptr.hpp>

/**
 * Class to map model variables names to indices
 * This mapping should be used throughout the tool
 * implementation to ensure consistency.
 *
 * Later, added input variable to index map.
 */

class var_to_index_map {
public:
	typedef boost::shared_ptr< std::map<std::string, unsigned int> > map_ptr;

	var_to_index_map();
	virtual ~var_to_index_map();

	/**
	 * Returns the variable name with the given index
	 */
	std::string get_varname(unsigned int index);

	/**
	 * Returns the input-variable name with the given index
	 */
	std::string get_uvarname(unsigned int index);
	
	/**
	 * Returns the index of the parameter var_name
	 * in the varname to dimension index map
	 */
	unsigned int get_index(std::string var_name){
		unsigned int index;
		try{
			index = var_index_map_ptr->at(var_name);
		}catch(...)
		{
			std::cout << "index of variable not found in the variable to index map. Check the variable name.\n";
			exit(0);
		};
		return index;
	}
	/**
	 * Returns the index of the input uvar_name
	 * in the uname to dimension map
	 */
	unsigned int get_u_index(std::string uvar_name){
		unsigned int index;
		try{
			index = uvar_index_map_ptr->at(uvar_name);
		}catch(...)
		{
			std::cout << "index of input not found in the input to index map. Check the input name.\n";
			exit(0);
		};
		return index;
	}

	/**
	 * Inserts a varname, dimension index into the map.
	 */
	void insert_to_map(std::string name, unsigned int val)
	{
		var_index_map_ptr->insert(std::pair<std::string, unsigned int>(name,val));
	}

	/**
	 * Inserts an input, dimension index into the umap.
	 */
	void insert_to_input_map(std::string uname, unsigned int val)
	{
		uvar_index_map_ptr->insert(std::pair<std::string, unsigned int>(uname,val));
	}

	/**
	 * Sets this-> map to the new map passed as parameter
	 */
	void set_map(map_ptr m){
		var_index_map_ptr = m;
	}
	/**
	 * Sets this-> umap to the new map passed as parameter
	 */
	void set_umap(map_ptr umap){
		uvar_index_map_ptr = umap;
	}
	/**
	 * Prints the var_to_index map in the console
	 */
	void print_var_index_map();

	/**
	 * Prints the input_to_index map in the console
	 */
	void print_input_index_map();

	/** Return the size of the map */
	unsigned int map_size();

	/** Return the size of the umap */
	unsigned int umap_size();

	/* The variable to dimension index map */
	static map_ptr var_index_map_ptr;
	
	/* The input to index map */
	static map_ptr uvar_index_map_ptr;
};

#endif /* VARTOINDEXMAP_H_ */
