/*
 * DataSorted.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include "DataSorted.h"

DataSorted::DataSorted() : DataGenerator("Already sorted") {}

DataSorted::~DataSorted() {}

void DataSorted::generate_data(vector<Element>& data, const int size)
{
	data.reserve(size);
	for(int i = 0; i< size; i++)
	{
		data[i] = i;
	}
}
