/*
 * TestSuite.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: pournami
 */

#include <string>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;
/**
 * Test function: Insert new nodes at the beginning of the vector.
 *                The final node data values are 0, 1, 2, ..., size-1.
 * @param sv the vector test subject.
 * @param size the data size of the vector.
 */
void vector_prepends(SortedVector& sv, const int size)
{
	for (int i = 0; i < size; i++) sv.prepend(i);
}

void list_prepends(SortedList& sl, const int size)
{
	for (int i = 0; i < size; i++) sl.prepend(i);
}

void vector_appends(SortedVector& sv, const int size)
{
    for (int i = 0; i < size; i++) sv.append(i);
}

void list_appends(SortedList& sl, const int size)
{
    for (int i = 0; i < size; i++) sl.append(i);
}

void vector_gets(SortedVector& sv, const int size) throw(string)
{

    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand() % size;
        long value = sv[index].get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}

void list_gets(SortedList& sl, const int size) throw(string)
{


    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand() % size;
        long value = sl[index].get_value();

        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }
}

void vector_inserts(SortedVector& sv, const int size) throw(string)
{
	for (int i = 0; i < size; i++)
	{
		sv.insert(i);
	}

    if (!sv.check()) throw("Vector sort error!");
}

void list_inserts(SortedList& sl, const int size) throw(string)
{
	for (int i = 0; i < size; i++)
		{
			sl.insert(i);
		}

    if (!sl.check()) throw("List sort error!");
}

void vector_removes(SortedVector& sv, const int size)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    for (int i = 0; i < size; i++)
	{
		sv.remove(i);
	}
}

void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();
    for (int i = 0; i < size; i++)
    	{
    		sl.remove(i);
    	}

}

void vector_reverse(SortedVector& sv, const int size) throw(string)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    sv.reverse();

    //if (!sv.check_reversed()) throw("Vector reverse sort error!");
}

void list_reverse(SortedList& sl, const int size) throw(string)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    sl.reverse();

    if (!sl.check_reversed()) throw("List reverse sort error!");
}

