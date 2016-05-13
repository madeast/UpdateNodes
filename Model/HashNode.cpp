//
//  HashNode.cpp
//  UpdateNodes
//
//  Created by Madsen, Easton on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "HashNode.hpp"

template<class Type>
HashNode<Type> :: HashNode(int key, const Type& value)
{
    this->key = key;
    this->value = value;
}

template<class Type>
HashNode<Type> :: HashNode()
{
    
}

template <class Type>
int HashNode<Type> :: getKey()
{
    return this->key;
}

template <class Type>
Type HashNode<Type> :: getValue()
{
    return this->value;
}

template <class Type>
void HashNode<Type> :: setValue(const Type& value)
{
    this->value = value;
}

template <class Type>
void HashNode<Type> :: setKey(int key)
{
    this->key = key;
}

