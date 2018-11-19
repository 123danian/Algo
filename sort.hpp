#pragma once
#ifndef SORTS_SORTS_HPP_
#define SORTS_SORTS_HPP_

#include <iterator>
//#include <functional>

template <typename BidirIt,
	typename BinaryPred = std::less<typename std::iterator_traits<BidirIt>::value_type>>
	void bubble_sort(BidirIt first, BidirIt last, BinaryPred comp = BinaryPred()) 
{
	if (std::distance(first, last) <= 1) { return; }

	bool flag = true;
	for (auto it = first; flag and it != last; ++it) 
	{
		flag = false;
		for (auto itt = first; itt != last - std::distance(first, it) - 1; ++itt) 
		{
			if (comp(*(itt + 1), *itt)) 
			{
				std::swap(*itt, *(itt + 1));
				flag = true;
			}
		}
	}
}

#endif