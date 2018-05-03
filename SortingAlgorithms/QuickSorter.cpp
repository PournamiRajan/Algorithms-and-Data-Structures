/*
 * QuickSorter.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include <iostream>
#include "QuickSorter.h"
using namespace std;

QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

QuickSorter::~QuickSorter() {}

void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

void QuickSorter::quicksort(const int left, const int right)
{
    // Continue the recursive calls until the indexes cross.
    if (left <= right)
    {
        // Choose the pivot and partition this subrange.
        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);

        quicksort(left, p-1);  // Sort elements <  pivot
        quicksort(p+1, right); // Sort elements >= pivot
    }
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	int i = right+1;  // Index of smaller element

	for (int j = right; j > left; j--)
	{
		// If current element is smaller than or
		// equal to pivot
		compare_count++;
		if (data[j] > pivot)
		{
			i--;    // increment index of smaller element
			swap(i, j);
		}
	}
	swap(i - 1, left);
	return (i - 1);
}
