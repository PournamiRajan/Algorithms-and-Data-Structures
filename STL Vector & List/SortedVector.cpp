/*
 * SortedVector.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: pournami
 */

#include <iostream>
#include <iterator>
#include <vector>
#include "SortedVector.h"

using namespace std;

/**
 * Defaut constructor.
 * Reset the global Node counters.
 */

SortedVector::SortedVector()
{
    Node::reset();
}
/**
 * Destructor.
 * Reset the global Node counters.
 */

SortedVector::~SortedVector()
{
    Node::reset();
}

/**
 * Insert a new node at the beginning of the vector.
 * @param value the new node's value.
 */
void SortedVector::prepend(const long value)
{
	SortedVector::insert(value);

}

/**
 * Append a new node at the end of the vector.
 * @param value the new node's value.
 */
void SortedVector::append(const long value)
{
	Node new_obj(value);
	vector<Node>::push_back(new_obj);
}

/**
 * Insert a new node into the vector at the
 * appropriate position to keep the vector sorted.
 * @param value the value of the node to insert.
 */
void SortedVector::insert(const long value)
{
	Node new_obj(value);
	vector<Node>::iterator iterator = vector<Node>::begin();
	while(iterator != end())
	{
		if((*iterator) >= new_obj) break;
		++iterator;
	}
	if (iterator != end()) *iterator = new_obj;
	else push_back(new_obj);

}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedVector::remove(const int index)
{
	vector<Node>::erase(begin() + index);
}

/**
 * Reverse in place the order of the nodes of the vector.
 */
void SortedVector::reverse()
{
	vector<Node>::iterator iterator1 = vector<Node>::begin();
	int i =1;
	while((vector<Node>::begin()+i) != vector<Node>::end())
	{
		iterator1 = vector<Node>::begin();
		vector<Node>::insert(iterator1, vector<Node>::begin()+i, vector<Node>::begin()+i+1);
        iterator1 = vector<Node>::begin();
        vector<Node>::erase(iterator1 + (++i));
	}
}

bool SortedVector::check() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal to the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}
