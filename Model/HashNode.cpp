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

template <class Type>
int HashNode<Type> :: getKey()
{
    return this->key;
}