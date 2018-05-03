/*
 * Node.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include "Node.h"
#include "Element.h"

Node::Node() {next = nullptr;}

Node::Node(const Element element)
{
	this->element = element;
	next = nullptr;
}

Node::~Node() {}


