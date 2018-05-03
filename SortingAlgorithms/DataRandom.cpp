/*
 * DataRandom.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include <stdlib.h>
#include <time.h>
#include "DataRandom.h"
#include "Element.h"

DataRandom::DataRandom() : DataGenerator("Unsorted random") {}

DataRandom::~DataRandom(){}

void DataRandom::generate_data(vector<Element>& data, const int size)
{
	srand (time(NULL));
	for(int i = 0; i < size; i++)
	{
		Element obj(rand());
		data.push_back(obj);
	}
}
