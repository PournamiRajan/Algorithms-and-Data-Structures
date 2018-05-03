/*
 * Element.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include <iostream>
#include "Element.h"

using namespace std;

// Static member variables, which are global to the class.
long Element::copy_count;
long Element::destructor_count;

Element::Element()         : value(0) {}
Element::Element(long val) : value(val) {}

Element::Element(const Element& other) {
	value = other.value;
	copy_count++;
}

Element::~Element() { destructor_count++; }

long Element:: get_copy_count() { return copy_count; }

long Element:: get_destructor_count() { return destructor_count; }

long Element::get_value() const { return value; }

void Element::reset()
{
	copy_count = 0;
	destructor_count = 0;
}

bool operator ==(const Element& elmt1, const Element& elmt2) { return  elmt1.get_value() == elmt2.get_value(); }

bool operator <(const Element& elmt1, const Element& elmt2) { return  elmt1.get_value() < elmt2.get_value(); }

bool operator >(const Element& elmt1, const Element& elmt2) { return  elmt1.get_value() > elmt2.get_value(); }

ostream& operator <<(ostream& outs, const Element& elmt)
{
	outs<<Element::copy_count<<"\t"<<Element::destructor_count;
	return outs;

}
