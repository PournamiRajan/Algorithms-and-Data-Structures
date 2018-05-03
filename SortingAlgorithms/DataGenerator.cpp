/*
 * DataGenerator.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include <string>
#include <vector>
#include "DataGenerator.h"

DataGenerator::DataGenerator(string name): name(name) {}

DataGenerator::~DataGenerator() {}

string DataGenerator::get_name() { return name; }
