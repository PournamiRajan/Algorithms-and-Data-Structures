/*
 * SortedList.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: pournami
 */

#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

/**
     * Insert a new node at the beginning of the list.
     * @param value the new node's value.
     */
void SortedList::prepend(const long value)
{
	Node new_node(value);
	list<Node>::push_front(new_node);
}

    /**
     * Append a new node at the end of the list.
     * @param value the new node's value.
     */
void SortedList::append(const long value)
{
	Node new_node(value);
	list<Node>::push_back(new_node);
}

    /**
     * Insert a new node into the list at the
     * appropriate position to keep the list sorted.
     * @param value the value of the node to insert.
     */
void SortedList::insert(const long value)
{
	Node new_obj(value);
	list<Node>::iterator iterator = list<Node>::begin();
	while(iterator != list<Node>::end())
	{
		if((*iterator).get_value() > value) break;

		++iterator;
	}
	if (iterator != list<Node>::end()) list<Node>::insert(iterator, new_obj);
	else list<Node>::push_back(new_obj);

}

    /**
     * Remove a node.
     * @param index the index of the node to remove.
     */
void SortedList::remove(const int index)
{
	list<Node>::iterator iterator = list<Node>::begin();
	for(int i = 0; i<= index; i++) ++iterator;
	list<Node>::remove(*iterator);

}

    /**
     * Reverse in place the order of the nodes of the list.
     */
void SortedList::reverse()
{
	//list<Node>::reverse();

	list<Node>::iterator it = begin();
	it++;
	while(it != end())
	{
		list<Node>::insert(begin(), *it);
		it = list<Node>::erase(it);
	}


}

    /**
     * Check that the nodes are sorted.
     * @return true if sorted, false if not.
     */
bool SortedList::check() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}


    /**
     * Check that the nodes are reverse sorted.
     * @return true if reverse sorted, false if not.
     */

bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

/**
 * Overloaded [] operator that returns
 * a reference to a Node element.
 * @param index the index of the element to return.
 * @return a reference to the element.
 */
Node& SortedList::operator[](const int index)
{
	list<Node>::iterator iterator = list<Node>::begin();
	while(iterator != list<Node>::end())
	{
		if((*iterator).get_value() == index) return *iterator;

		++iterator;
	}
	return *iterator;

}
