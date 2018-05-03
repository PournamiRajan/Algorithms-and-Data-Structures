/*
 * MergeSort.cpp
 *
 *  Created on: Apr 22, 2018
 *      Author: pournami
 */

#include <string>
#include "MergeSort.h"

MergeSort::MergeSort() : ListSorter("Mergesort") {}

MergeSort::~MergeSort() {}

void MergeSort::run_sort_algorithm() throw(string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

void MergeSort::mergesort(LinkedList& list)
{
    /***** reference - https://www.geeksforgeeks.org/merge-sort-for-linked-list/ *****/
	LinkedList a;
	LinkedList b;
	//cout<<"\ninside merge sort"<<endl;
	//cout<<"list size = "<<list.get_size()<<endl;
	/* Base case -- length 0 or 1 */
	if (list.get_size() <= 1)
	{
	    return;
	}

	/* Split head into 'a' and 'b' sublists */
	list.split(a,b);

	/* Recursively sort the sublists */
	mergesort(a);
	mergesort(b);
	list.reset();
	/* answer = merge the two sorted lists together */
	merge(list,a, b);
}

void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    /***** reference - https://www.geeksforgeeks.org/merge-sort-for-linked-list/ *****/
	/* Base cases */
	//cout<<"inside merge"<<endl;
	if (sublist1.get_size() == 0)
	{
		list.concatenate(sublist2);
		return;
	}
	if (sublist2.get_size() == 0)
	{
		list.concatenate(sublist1);
		return;
	}

	/* Pick either a or b, and recur */
	compare_count++;
	if (sublist1.get_head()->element < sublist2.get_head()->element)
	{
		list.add(sublist1.remove_head());
		merge(list, sublist1, sublist2);
	}
	else
	{
		list.add(sublist2.remove_head());
		merge(list, sublist1, sublist2);
	}
}

void MergeSort::clear() { data.clear(); }
