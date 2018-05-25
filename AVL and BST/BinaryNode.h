/*
 * BinaryNode.h
 *
 *  Created on: May 1, 2018
 *      Author: pournami
 */

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
    /**
     * Constructor.
     * @param data the data item.
     */
    BinaryNode(const int data);

    /**
     * Constructor.
     * @param data the data item.
     * @param left the left link.
     * @param right the right link.
     */
    BinaryNode(const int data, BinaryNode *left, BinaryNode *right);

    /**
     * Destructor.
     */
    virtual ~BinaryNode();

    int data;
    int height;  // node height

    BinaryNode *left;
    BinaryNode *right;
};


#endif // BINARY_TREE_PRINTER_H
