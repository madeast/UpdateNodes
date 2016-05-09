/*
 * Node.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: emad6932
 */

#include "Node.h"
#include <iostream>
//using namespace std;
template <class Type>
Node<Type>::Node()
{
	// TODO Auto-generated constructor stub
	pointers = nullptr;
}

template <class Type>
Node<Type>::Node(const Type value)
{

	this->value = value;
	pointers = nullptr;
}

template <class Type>
Node<Type>::~Node()
{
	// TODO Auto-generated destructor stub
}


template <class Type>
Type Node<Type> :: getValue()
{
	return this->value;
}

template <class Type>
void Node<Type> :: setValue(const Type value)
{
	this->value = value;

}

template <class Type>
Node<Type> * Node<Type> :: getPointers()
{
	return this->pointers;
}
