/*
template<class Type>
CTECArray<Type>:: get(int position)
{

} * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: emad6932
 */

#include "CTECArray.h"
#include <assert.h>

using namespace std;


template <class Type>
CTECArray<Type>::CTECArray(int size)
{
	// TODO Auto-generated constructor stub
	this->size = size;
	this->head = nullptr;

	assert(size > 0);

	if(size <= 0)
	{
		cerr << "Impossible!" << endl;
		return;
	}

	for(int index = 0; index < size; index++)
	{
		if(head != nullptr)
		{
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode->setNext(head);
			head = nextNode;
		}
		else
		{
			ArrayNode<Type> * first = new ArrayNode<Type>();
			head = first;
		}
	}

}

template<class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for(int index = 0; index < size; index++)
	{
		if(deleteMe->getNext() != nullptr)
		{
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);
		}
		delete deleteMe->getNext();
		deleteMe = head;
	}

	delete head;
}

template<class Type>
int CTECArray<Type>:: getSize()
{
	return this->size;
}

template<class Type>
Type CTECArray<Type>:: get(int position)
{
	//Bounds check for size and negative.


    assert(position < size && position >= 0);


    ArrayNode<Type> * current = head;
		//Inclusive because I am inside the bounds guaranteed :D
    for(int spot = 0; spot <= position; spot++)
    {
        if(spot != position)
        {
            current = current->getNext();
        }
        else
        {
            return current->getValue(); //Grab the value stroed in the Node
                            //Return a pointer to the value
        }
    }
    return current->getValue();
}

template<class Type>
void CTECArray<Type>:: set(int position, const Type& value)
{

	assert(position < size && position >= 0);

	ArrayNode<Type> * current = head;
	for(int spot = 0; spot <= position; spot++)
	{
		if(position != spot )
			{
				 current = current->getNext();
			}
			else
			{
				current->setValue(value);
			}
	}

}
/*
 1) Assert size is greater than 0.
 2) Declare and init valid return variable;
 3) Reference head and loop
 4) If there, return index, else go to next.
 5) Return index
 */

template <class Type>
int CTECArray<Type>:: indexOf(Type searchValue)
{
    assert(this->size > 0);
    
    int indexNotFound = -1;
    
    ArrayNode<Type> * current = head;
    
    for(int spot = 0; spot < this->size; spot++)
    {
        if(current->getValue() == searchValue)
        {
            return spot;
        }
        else
        {
            current = current->getNext();
        }
    }
    
    return indexNotFound;
};

template <class Type>
int CTECArray<Type>:: nextIndexOf(int startingIndex, Type searchValue)
{
    assert(this->size > 0);
    assert(startingIndex >= 0 && startingIndex < this->size);
           
        int indexNotFound = -1;
           
        ArrayNode<Type> * current = head;
        for(int index = 0; index < startingIndex; index++)
        {
            current = current->getNext();
        }
           
        for(int index = startingIndex; index < this->size; index++)
        {
            if(current->getValue() == searchValue)
            {
                return index;
            }
            else
            {
                current = current->getNext();
            }
        }
           
    return indexNotFound;
}

template <class Type>
void ArrayNode<Type> :: swap (int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    ArrayNode<Type> * first = get(indexOne);
    ArrayNode<Type> * second = get(indexTwo);
    ArrayNode<Type> * temp = new ArrayNode<Type>();
    
    temp->setValue(first->getValue());
    first->setValue(second->getValue());
    second->setValue(temp->getValue());
    
    delete temp;
}



