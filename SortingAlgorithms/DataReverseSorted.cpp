/*
 * DataReverseSorted.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include "DataReverseSorted.h"

DataReverseSorted::DataReverseSorted() : DataGenerator("Reverse sorted") {}

DataReverseSorted::~DataReverseSorted() {}

void DataReverseSorted::generate_data(vector<Element>& data, const int size)
{
	data.reserve(size);
	for(int i = 0; i< size; i++)
	{
		data[i] = size - i;
	}
}
