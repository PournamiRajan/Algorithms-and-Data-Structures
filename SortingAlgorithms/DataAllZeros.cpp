/*
 * DataAllZeroes.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */
#include "DataAllZeros.h"

DataAllZeros::DataAllZeros() : DataGenerator("All zeroes") {}

DataAllZeros::~DataAllZeros() {}

void DataAllZeros::generate_data(vector<Element>& data, const int size)
{
	Element obj(0);
	for(int i = 0; i<size; i++)
	{
		data.push_back(obj);
	}
}
