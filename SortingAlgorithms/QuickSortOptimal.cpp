/*
 * QuickSortOptimal.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include "QuickSortOptimal.h"

QuickSortOptimal::QuickSortOptimal() : QuickSorter("Quicksort optimal") {}

QuickSortOptimal::~QuickSortOptimal() {}


Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
	int mid = (left+right)/2;
	int pos = 0;
	compare_count++;
	if(data[left] > data[right])
	{
		compare_count++;
		if(data[mid] > data[left]) pos = left;
		else if(data[mid] > data[right])
		{
			compare_count++;
			pos = mid;
		}
		else pos = right;
	}
	else
	{
		compare_count++;
		if(data[mid] > data[right]) pos = right;
		else if(data[mid] > data[left])
		{
			compare_count++;
			pos = mid;
		}
		else pos = left;
	}
	swap(left, pos);
	return data[left];


}
