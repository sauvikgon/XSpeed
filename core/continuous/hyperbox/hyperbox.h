/*
 * Hyperbox.h
 *
 *  Created on: 15-Dec-2017
 *      Author: rajarshi
 */

#ifndef HYPERBOX_H_
#define HYPERBOX_H_

#include <utility>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <cassert>
#include "core/hybridAutomata/varToIndexMap.h"
#include "core/math/randNumberGenerator.h"

/**
 * A class to represent a hyperbox data-structure
 */
template<class T>
class hyperbox : public var_to_index_map
{
public:
	typedef std::pair<T, T> bounds;
	typedef boost::shared_ptr<hyperbox> ptr;

	hyperbox() // initialized an empty Hyperbox
	{
		dimension = 0;
		intervals = std::vector<bounds>(dimension);
		randgen = randNumberGenerator();
	}
	hyperbox(unsigned int n, std::vector<bounds> intervals)
	{
		assert(n==intervals.size());
		dimension = n;
		randgen = randNumberGenerator();
	}
	~hyperbox(){};
	unsigned int get_dimension(){
		return dimension;
	};
	void set_dimension(unsigned int n)
	{
		dimension = n;
		intervals.resize(n);
	};

	bounds get_bounds_on_dimension(unsigned int i);

	void set_bounds_on_dimension(unsigned int i, T a, T b);

	/**
	 * Returns a random point from inside the hyperbox
	 */
	std::vector<T> get_internal_point();

private:
	unsigned int dimension;
	std::vector<bounds> intervals;
	randNumberGenerator randgen; // A common random number generator for the Hyperbox class.

};

#include <core/continuous/hyperbox/hyperbox.hpp>

#endif /* HYPERBOX_H_ */
