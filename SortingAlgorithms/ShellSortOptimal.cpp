/*
 * ShellSortOptimal.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include "ShellSortOptimal.h"
#include <cmath>

ShellSortOptimal::ShellSortOptimal() :VectorSorter("Shellsort optimal") {}

ShellSortOptimal::~ShellSortOptimal() {}

void ShellSortOptimal::run_sort_algorithm()
{
	/*** reference - https://www.geeksforgeeks.org/shellsort/ ***/
	int i,j,k,h = 0;
	//cout<<"shell sort size = "<<size<<endl;
	for(i = 1; h < size; i++)
	{
		h = (pow(3,i) - 1)/2;
		//cout<<"h = "<<h<<endl;
	}
	i--;
	h = (pow(3,i) - 1)/2;
	//cout<<"h = "<<h<<endl;
	while( h > 0)
	{
		//cout<<"inside while, h = "<<h<<endl;
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
		i--;
		h = (pow(3,i) - 1)/2;
	}
}
