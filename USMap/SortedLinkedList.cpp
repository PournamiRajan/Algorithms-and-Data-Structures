#include "SortedLinkedList.h"
/*
 * Constructor
 */
SortedLinkedList::SortedLinkedList()
{
	head = nullptr;
}
/*
 * Sorted Linked list insertion
 */
void SortedLinkedList::insert(Node *node)
{
   Node *p = head;
   Node *prev = p;
   if(p == nullptr)
   {
      head = node;
   }
   else if (*p > *node)
   {
      node->next = head;
      head = node;
   }
   else
   {
      while ((p != nullptr) && (*node > *p)  )
      {
          prev = p;
          p = p->next;
      }
      prev->next = node;
      node->next = p;
   }
}
/*
 * Overloaded output operator
 */
ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
   Node *p = list.head;
   Node n = *p;
   Node::i = 0;
   Node::j = 0;

   while(p != nullptr)
   {
	   Node n = *p;
	   outs << n;
	   p = p->next;
   }

   return outs;
}

SortedLinkedList::~SortedLinkedList()
{

}
