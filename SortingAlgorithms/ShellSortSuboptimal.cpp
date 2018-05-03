/*
 * ShellSortSuboptimal.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include "ShellSortSuboptimal.h"

ShellSortSuboptimal::ShellSortSuboptimal() : VectorSorter("Shellsort suboptimal") {}

ShellSortSuboptimal::~ShellSortSuboptimal() {}

void ShellSortSuboptimal::run_sort_algorithm()
{
	/*** reference - https://www.geeksforgeeks.org/shellsort/ ***/
	int i,j,k,h;
	for(h = size/2; h > 0; h/=2)
	{
		for (j = h; j < size; j++)
		{
			Element temp = data[j];

			// shift earlier gap-sorted elements up until the correct location for data[j] is found
			compare_count++;
			for (k = j; k >= h && data[k - h] > temp; k -= h)
			{
				data[k] = data[k - h];
				move_count++;
			}
			//  put temp (the original data[i]) in its correct location
			data[k] = temp;
			move_count++;
		}
	}
}
