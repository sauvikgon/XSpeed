/*
 * vartoindexmap.h
 *
 *  Created on: 07-Feb-2016
 *      Author: rajarshi
 */

#ifndef VARTOINDEXMAP_H_
#define VARTOINDEXMAP_H_
#include <map>
#include <string>
#include <utility>
#include <boost/shared_ptr.hpp>

/**
 * Class to map model variables names to indices
 * This mapping should be used throughout the tool
 * implementation to ensure consistency.
 */

class var_to_index_map {
public:
	typedef boost::shared_ptr< std::map<std::string, unsigned int> > map_ptr;

	var_to_index_map();
	virtual ~var_to_index_map();
	unsigned int get_index(std::string var_name){
		return var_index_map_ptr->at(var_name);
	}
	void insert_to_map(std::string name, unsigned int val)
	{
		var_index_map_ptr->insert(std::pair<std::string, unsigned int>(name,val));
	}
	void set_map(map_ptr m){
		var_index_map_ptr = m;
	}
	void print_var_index_map();

	static map_ptr var_index_map_ptr;
};

#endif /* VARTOINDEXMAP_H_ */
