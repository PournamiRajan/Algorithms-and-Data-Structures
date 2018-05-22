/*
 * BinarySearchTree.cpp
 *
 *  Created on: May 1, 2018
 *      Author: pournami
 */
#include <string>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() { clear(); }

BinaryNode *BinarySearchTree::get_root() const { return root; }

int BinarySearchTree::height() const { return height(root); }

int BinarySearchTree::height(const BinaryNode *ptr) const
{
	int sum1 = 0, sum2 = 0, sum;
	if(ptr == nullptr) return -1;
    if(ptr->left == nullptr && ptr->right == nullptr) return 0;
    else if(ptr->left == nullptr) sum2 += height(ptr->right);
    else if(ptr->right == nullptr) sum1 += height(ptr->left);
    else
    {
    	sum1 += height(ptr->left);
    	sum2 += height(ptr->right);
    }
    sum = (sum1>sum2)? sum1+1: sum2+1;
    return sum;
}

int BinarySearchTree::find_min() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_min(root)->data;
}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
    if(ptr->left == nullptr) return ptr;
	return find_min(ptr->left);
}

int BinarySearchTree::find_max() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_max(root)->data;
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
	if(ptr->right == nullptr) return ptr;
	return find_min(ptr->right);
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
	while(ptr != nullptr) remove(ptr->data, ptr);
}

bool BinarySearchTree::is_empty() const
{
    return root == nullptr;
}

bool BinarySearchTree::contains(const int data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{
    if(ptr == nullptr) return false;
	if(ptr->data == data) return true;
    else if(ptr->data < data) return contains(data, ptr->right);
    else return contains(data, ptr->left);
}

void BinarySearchTree::insert(const int data)
{
    insert(data, root);
}

void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    if(ptr == nullptr)
    {
    	ptr = new BinaryNode(data);
    	return;
    }
    else if(data < ptr->data) insert(data, ptr->left);
    else insert(data, ptr->right);
}

void BinarySearchTree::remove(const int data)
{
    remove(data, root);
}

void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
	if (ptr == nullptr) return;
	if (ptr->data < data) remove(data, ptr->right);
	else if (ptr->data > data) remove(data, ptr->left);
	else
	{
		if(ptr->left == nullptr && ptr->right == nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
		else if(ptr->right == nullptr)
		{
			BinaryNode *temp = ptr;
			ptr = ptr->left;
			delete temp;
		}
		else if(ptr->left == nullptr)
		{
			BinaryNode *temp = ptr;
			ptr = ptr->right;
			delete temp;
		}
		else
		{
			BinaryNode *temp = find_min(ptr->right);
			ptr->data = temp->data;
			remove(ptr->data, ptr->right);
		}
	}
}
