/*
 * LinkedList.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {};

LinkedList::LinkedList(Node *head, Node *tail, const int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;

    this->size = size;
}

LinkedList::~LinkedList() {}

Node *LinkedList::get_head() const { return head; }
Node *LinkedList::get_tail() const { return tail; }
int   LinkedList::get_size() const { return size; }

void LinkedList::set(Node *head, Node *tail, int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;
    this->size = size;
}

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

    // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::reset()
{
    head = tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

void LinkedList::split(LinkedList& a, LinkedList& b)
{
	/***** reference - https://www.geeksforgeeks.org/merge-sort-for-linked-list/ *****/
	if (size <= 1)return;
	LinkedList fast(head->next,tail,size);
	LinkedList slow(head,tail,size);
	int s = 1;



	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast.head != nullptr)
	{
		fast.head = fast.head->next;
		if (fast.head != nullptr)
		{
			s++;
			slow.head = slow.head->next;
			fast.head = fast.head->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two at that point. */
	a.head = head;
	a.tail = slow.head;
	a.size = s;
	b.head = slow.head->next;
	a.tail->next = nullptr;
	b.tail = tail;
	b.size = size - s;
	//cout<<"a size = "<<a.get_size()<<endl;
	//cout<<"b size = "<<b.get_size()<<endl;
}

void LinkedList::concatenate(LinkedList& other_list)
{
	if (head == nullptr)
	{
		head  = other_list.head;
		tail = other_list.tail;
	}
	else
	{
		tail->next = other_list.head;
	}
	size += other_list.size;
}
