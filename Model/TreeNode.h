//
//  TreeNode.hpp
//  NodesInXCode
//
//  Created by Madsen, Easton on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h

#include <stdio.h>
#include "Node.h"

template <class Type>
class TreeNode : public Node<Type>
{
private:
    TreeNode<Type> * leftChild;
    TreeNode<Type> * rightChild;
    TreeNode<Type> * Parent;
public:
    TreeNode();
    TreeNode(const Type& value);
    TreeNode(const Type& value, TreeNode<Type> * parent);
    void setRightChild(TreeNode <Type>* rightChild);
    void setLeftChild(TreeNode <Type>* leftChild);
    void setParent(TreeNode <Type>* parent);
    TreeNode<Type> * getLeftChild();
    TreeNode<Type> * getRightChild();
    TreeNode<Type> * getParent();
    
};


#endif /* TreeNode_hpp */
