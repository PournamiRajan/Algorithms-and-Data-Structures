/*
 * AvlTree.cpp
 *
 *  Created on: May 1, 2018
 *      Author: pournami
 */

#include <iostream>
#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree() : BinarySearchTree() {}

AvlTree::~AvlTree() {}

int AvlTree::height(const BinaryNode *ptr) const
{
	// reference : https://www.sanfoundry.com/cpp-program-implement-avl-trees/
	return BinarySearchTree::height(ptr);
}

void AvlTree::insert(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
    if (ptr == nullptr) return ptr;


	 int bal_factor = height(ptr->left) - height(ptr->right);
	 if (bal_factor > 1)
	 {
		if (ptr->left && (height(ptr->left->left) - height(ptr->left->right) > 0))
		{
		   ptr = single_left_rotation(ptr);
		   cout<<"    --- Single right rotation at node "<<ptr->data<<endl;

		}
		else
		{
		   ptr = double_left_right_rotation(ptr);
		   cout<<"    --- Double left-right rotation at node "<<ptr->data<<endl;

		}
	 }
	 else if (bal_factor < -1)
	 {
		if (ptr->right && (height(ptr->right->left) - height(ptr->right->right) > 0))
		{
		   ptr = double_right_left_rotation(ptr);
		   cout<<"    --- Double right-left rotation at node "<<ptr->data<<endl;

		}

		else
		{
		   ptr = single_right_rotation(ptr);
		   cout<<"    --- Single left rotation at node "<<ptr->data<<endl;

		}
	 }
    // Recompute the node's height.
    ptr->height = (max(height(ptr->left),
                       height(ptr->right)) + 1);
    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{

	BinaryNode *temp;

	temp = k2->right;
	k2->right = temp->left;
	temp->left = k2;
	return temp;
}

BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{


	BinaryNode *temp;
    temp = k3->left;
    k3->left = single_right_rotation (temp);
    return single_left_rotation(k3);
}

BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{


	BinaryNode *temp;
    temp = k1->right;
    k1->right = single_left_rotation (temp);
    return single_right_rotation (k1);
}

BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{


	BinaryNode *temp;
    temp = k1->left;
    k1->left = temp->right;
    temp->right = k1;
    return temp;
}

int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
