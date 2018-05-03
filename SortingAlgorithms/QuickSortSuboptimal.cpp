/*
 * QuickSortSuboptimal.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include "QuickSortSuboptimal.h"

QuickSortSuboptimal::QuickSortSuboptimal() : QuickSorter("Quicksort suboptimal") {}

QuickSortSuboptimal::~QuickSortSuboptimal() {}

Element& QuickSortSuboptimal::choose_pivot_strategy(const int left, const int right)
{
	return data[left];
}
