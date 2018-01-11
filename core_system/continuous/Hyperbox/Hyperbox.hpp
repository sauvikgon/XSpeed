/*
 * Hyperbox.cpp
 *
 *  Created on: 15-Dec-2017
 *      Author: rajarshi
 */



template<class T>
std::vector<T> hyperbox<T>::get_internal_point()
{
	std::vector<T> point(dimension);
	std::vector<double> res;
	for(unsigned int i=0;i<dimension;i++)
	{
		bounds b = intervals[i];
		res = randgen.getRands(b.first, b.second, 1);
		point[i] = res[0];
	}
	return point;
};
template<class T>
typename hyperbox<T>::bounds hyperbox<T>::get_bounds_on_dimension(unsigned int i)
{
	assert(i < intervals.size() && i >= 0);
	hyperbox::bounds b = intervals[i];
	return b;
};

template<class T>
void hyperbox<T>::set_bounds_on_dimension(unsigned int i, T a, T b)
{
	assert(i>=0 && i<dimension);

	bounds limits;
	limits.first = a;
	limits.second = b;
	intervals[i] = limits;
};
