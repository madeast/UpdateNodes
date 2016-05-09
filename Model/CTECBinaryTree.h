//
//  CTECBinaryTree.hpp
//  NodesInXCode
//
//  Created by Madsen, Easton on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECBinaryTree_h
#define CTECBinaryTree_h

#include "TreeNode.cpp"

template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int height;
    int size;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree); //Done
    void calculateSize(TreeNode<Type> * currentNode); //Done
    TreeNode<Type> * getRightMostChild(CTECBinaryTree<Type> * leftSubTree);
    TreeNode<Type> * getLeftMostChild(CTECBinaryTree<Type> * rightSubTree);
    void remove(TreeNode<Type> * noddToBeDeleted);
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    bool contains(Type value);
    void remove(const Type& value);
    int getHeight();
    int getSize();
    bool isBalanced();
    TreeNode<Type>* getRoot();
    void inorderTraversal(TreeNode<Type> * currentNode);
    void postorderTraversal(TreeNode<Type> * currentNode);
    void preorderTraversal(TreeNode<Type> * currentNode);
    
};

#endif /* CTECBinaryTree_hpp */
