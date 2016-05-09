/*
 * CtecList.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: emad6932
 */

#include "CtecList.h"
#include "assert.h"

template<class Type>
CtecList<Type>::CtecList()
{
	this->size= 0;
	this->head = nullptr;
	this->end = nullptr;

}

template <class Type>
CtecList<Type>::~CtecList()
{

	ArrayNode<Type> * current = head;

	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type> * temp = current;

		current = current->getNext();
		head = current;
		delete temp;
	}

	while(current->getNext() != nullptr)
	{
		ArrayNode<Type> * temp = current;

		current = current->getNext();
		head = current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}

template <class Type>
int CtecList<Type> :: getSize()
{
	/**
	 * Function to return the number of nodes in the list.
	 * Postcondition: The value of count is returned.
	 */

	return size;
}

template<class Type>
Type CtecList<Type>:: removeFromFront()
{

	Type returnValue; //In case we need to use the value we are removing.

	assert(this->size > 0);
	//Create a pointer to what is after head.
	ArrayNode<Type> * newHead;
	newHead = head->getNext();

	Type thingToRemove;
	//Get what was in head node!
	thingToRemove = returnValue = head->getValue();
	//Delete what head is pointing to
	delete this->head;
	//Set head to the new head
	this->head = newHead;

	this->calculateSize();

	return thingToRemove;
}

template<class Type>
Type CtecList<Type>:: removeFromIndex(int index)
{

	Type returnValue; //In case we need to use the value we are removing.

	assert(this->size > 0);

	assert(size > 0 && index >= 0 && index < size);

	Type thingToRemove;
	ArrayNode<Type> * current = head;

	ArrayNode<Type> * previous, deleteMe, newNext;

	if(index == 0)
	{
		thingToRemove = removeFromFront();
	}
	else if(index == size-1)
	{
		thingToRemove = removeFromEnd();
	}
	else
	{
		for(int spot = 0; spot < index +1; spot++)
		{
			current = spot;
			delete current;
		}

		this->calculateSize();
	}

	return thingToRemove;
}

/**
 * Calculates the size of the list by iterating over all of the nodes in the list
 */

template <class Type>
void CtecList<Type> :: calculateSize()
{
	assert(size >= 0);

	ArrayNode<Type> * counterPointer = head;
	int count = 0;
	if(counterPointer == nullptr)
	{
		this->size = 0;
		return;
	}
	else
	{
		count++;
		while(counterPointer->getNext() != nullptr)
		{
			counterPointer= counterPointer->getNext();
			count++;

		}
		this->size = count;
	}
}

template <class Type>
Type CtecList<Type> :: removeFromEnd()
{
	//loop over size
	//or
	//loop until getNext->getNext() == nullptr
	//Before return the variable call calculateSize().
	assert(size >0);

	Type valueToRemove;

	if(size == 1)
	{
		valueToRemove = removeFromFront();
		end = nullptr;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot < size-1; spot++)
		{
			current = current->getNext();
		}

		valueToRemove = current->getNext()->getValue();
		end = current;
		delete current->getNext();

	}
	this->calculateSize();
	return valueToRemove();
}

template <class Type>
void CtecList<Type> :: addToFront(const Type& value)
{
	ArrayNode<Type> * newStuff = new ArrayNode<Type>(value, head);
	head = newStuff;

	calculateSize();
}

template <class Type>
void CtecList<Type> :: addToEnd(Type value)
{
	/**
	 * Function to insert newItem at the end of the list.
	 * Postcondition: first points to the new list, newItem is
	 * inserted at the beginning of the list, last points to
	 * the last node in the list, and count is incremented by one.
	 */

	ArrayNode<Type> * newStuff = new ArrayNode<Type>(value);
	end->setNext(newStuff);
	end = newStuff;

	calculateSize();



}

template <class Type>
void CtecList<Type> :: addAtIndex(int index, Type value)
{
	ArrayNode<Type> * current = head;
	ArrayNode<Type> * newNode;
	newNode = new ArrayNode<Type>;


		assert(index >= 0 && index < size);

	for(int spot = 0; spot <= index; spot++)
		{
		while(current->getNext != NULL)
		{

		}
			if(index == spot)
			{
				newNode = spot;
			}
		}

	ArrayNode<Type> * previous, next;
}

template <class Type>
Type CtecList<Type> :: getFront()
{
	/**
	 * Function to return the last element of the list.
	 * Precondition: The list must exist and must not be empty.
	 * Postcondition: If the list is empty, the program
	 * terminates; otherwise, the last
	 * element of the list is returned.
	 */
	Type returnValue;
	Type thingToGet;
	thingToGet = returnValue = head->getValue();
    return returnValue;
}

template <class Type>
Type CtecList<Type> :: getEnd()
{
	/**
	 * Function to return the last element of the list.
	 * Precondition: The list must exist and must not be empty.
	 * Postcondition: If the list is empty, the program terminates;
	 * 	otherwise, the first element of the list is returned.
	 */

	Type valueToGet;

	if(size == 1)
	{
		valueToGet = getFront();
		end = nullptr;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot < size-1; spot++)
		{
			current = current->getNext();
		}

		valueToGet = current->getNext()->getValue();
		end = current;

	}
	this->calculateSize();
	return valueToGet;
}

template <class Type>
Type CtecList<Type> :: getFromIndex(int index)
{
	/**
	 * Function to determine whether searchItem is in the list.
	 * Postcondition: If the list is empty, the program
	 * terminates; otherwise, the last
	 * element of the list is returned.
	 */
	ArrayNode<Type> * current = head;

	assert(index >= 0 && index < size);

	for(int spot = 0; spot <= index; spot++)
	{
		if(index == spot)
		{
			return current->getValue();
		}
	}
}

template <class Type>
Type CtecList<Type> :: set(int index, Type value)
{

	ArrayNode<Type> * current = head;
	assert(index < size && index >= 0);

	for(int spot = 0; spot <= index; spot++)
	{
		if(index != spot)
			{
				 current = current->getNext();
			}
			else
			{
				current->setValue(value);
			}
	}

	return current;
}

template <class Type>
void CtecList<Type> :: swap (int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    Type temp = getFromIndex(indexOne);
    set(indexOne, getFromIndex(indexTwo));
    set(indexTwo, temp);
}

template <class Type>
void CtecList<Type>::selectionSort()
{
    int innerLoop, outerLoop;
    for(outerLoop = 0; outerLoop < this->size-1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        for(innerLoop = outerLoop+1; innerLoop < size; innerLoop++)
        {
            if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
            {
                selectedMinimum = innerLoop;
            }
        }
        if(selectedMinimum != outerLoop)
        {
            swap(outerLoop, selectedMinimum);
        }
    }
}



