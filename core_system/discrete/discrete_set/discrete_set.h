/*
 * discrete_set.h
 *
 *  Created on: 12-Nov-2014
 *      Author: amit
 */

#ifndef DISCRETE_SET_H_
#define DISCRETE_SET_H_
#include <set>
#include <boost/shared_ptr.hpp>


class discrete_set
{
public:
	typedef boost::shared_ptr<discrete_set> ptr;
	void union_set(discrete_set d);
	void intersection_set(discrete_set d);
	bool contains(discrete_set d);

	const std::set<int>& getDiscreteElements() const;
	void setDiscreteElements(const std::set<int>& discreteElements);

	void insert_element(int element);
private:
	std::set<int> discrete_elements;
};


#endif /* DISCRETE_SET_H_ */
