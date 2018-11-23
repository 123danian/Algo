#pragma once
#ifndef SORTS_SORTS_HPP_
#define SORTS_SORTS_HPP_

#include <iterator>
//#include <functional>

//冒泡排序
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

//插入排序
//template<typename BidirIt, typename BinaryPred = std::less<typename std::iterator_traits<BidirIt>::value_type> >
template<typename BidirIt, typename BinaryPred = std::less<typename BidirIt::value_type> >
void Insertion_Sort(BidirIt first, BidirIt last, BinaryPred comp = BinaryPred())
{
	if (std::distance(first, last) <= 1)
	{
		return;
	}

	for (auto it = first + 1; it != last; it++)
	{
		auto item = *it;
		auto itt = it;
		for (; itt != first; itt--)
		{
			if (comp(*itt, *(itt - 1)))
			{
				//std::swap(*itt, *(itt - 1));//元素后移一位
				*itt = *(itt - 1);//元素后移一位
			}
			else
			{
				break;
			}
		}
		*itt = item;
	}
}

//选择排序
template <typename BidirIt, typename BinaryPred = std::less<typename std::iterator_traits<BidirIt>::value_type> >
void Selection_Sort(BidirIt first, BidirIt last, BinaryPred comp = BinaryPred())
{
	if (std::distance(first, last) <= 1)
	{
		return;
	}
	for (auto it = first; it != last - 1; it++)
	{
		auto tag = it;
		for (auto itt = it + 1; itt != last; itt++)
		{
			if (comp(*itt, *tag))
			{
				tag = itt;
			}
		}
		if (tag != it)
		{
			std::swap(*it, *tag);//交换迭代器执行的元素
		}
	}
}


#endif
