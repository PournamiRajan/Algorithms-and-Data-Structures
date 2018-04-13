/*
 * Node.cpp
 *
 *  Created on: Apr 1, 2018
 *      Author: pournami
 */

#include <iostream>
#include "Node.h"

using namespace std;

// Static member variables, which are global to the class.
// These variables exist independently from any Node objects.
long Node::constructor_count;
long Node::copy_count;
long Node::assign_count;
long Node::destructor_count;
/**
    * Constructor.
    * Globally count how many times a constructor is called.
    * @param the_value the initial value.
    */
   Node::Node(const long the_value)
   {
	   value = the_value;
	   constructor_count++;
   }

   /**
    * Copy constructor.
    * Globally count how many times a copy constructor is called.
    * @param other the other node object to copy.
    */
   Node::Node(const Node& other)
   {
	   value = other.value;
	   copy_count++;
   }

   /**
    * Overloaded assignment operator.
    * Globally count how many times an assignment operator is called.
    * @param rhs the right-hand-side node object.
    */
   Node& Node::operator =(const Node& rhs)
   {
	   value = rhs.get_value();
	   assign_count++;
	   return *this;
   }

   /**
    * Destructor.
    * Globally count how many times a destructor is called.
    */
   Node::~Node()
   {
	   destructor_count++;
   }

   /**
    * Getter.
    * @return the value.
    */
   long Node::get_value() const
   {
	   return value;
   }

   /**
    * Getter.
    * @return the value of the global constructor_count.
    */
   long Node::get_constructor_count()
   {
	   return constructor_count;
   }

   /**
    * Getter.
    * @return the value of the global copy_count.
    */
   long Node::get_copy_count()
   {
	   return copy_count;
   }

   /**
    * Getter.
    * @return the value of the global assign_count.
    */
   long Node::get_assign_count()
   {
	   return assign_count;
   }

   /**
    * Getter.
    * @return the value of the global destructor_count.
    */
   long Node::get_destructor_count()
   {
	   return destructor_count;
   }

   /**
    * Reset the values of the global counters.
    */
   void Node::reset()
   {
	   constructor_count = 0;
	   copy_count = 0;
	   assign_count = 0;
	   destructor_count = 0;
   }

   /**
    * Overloaded == operator.
    * @return true if the values of two nodes are equal, else false.
    */
   bool Node::operator ==(const Node& other) const
	{
	   return value == other.value;
	}

   /**
    * Overloaded <= operator.
    * @return true if the value of this node is less than or equal to
    *              the value of the other node, else false.
    */
   bool Node::operator <=(const Node& other) const
	{
	   return value <= other.value;
	}

   /**
    * Overloaded >= operator.
    * @return true if the value of this node is greater than or equal to
    *              the value of the other node, else false.
    */
   bool Node::operator >=(const Node& other) const
	{
	   return value >= other.value;
	}

