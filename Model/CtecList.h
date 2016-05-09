/*
  * CtecList.h
 *
 *  Created on: Feb 18, 2016
 *      Author: emad6932
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_

#include "ArrayNode.h"

template<class Type>
class CtecList
{
private:
	int size;
	void calculateSize();
	ArrayNode<Type> * head;
	ArrayNode<Type> * end;
    void selectionSort();
    void swap(int indexOne, int indexTwo);
public:
	CtecList();
	virtual ~CtecList();
	int getSize();
	void addToFront(const Type & value);
	void addToEnd(Type value);
	void addAtIndex(int index, Type value);
	Type getFront();
	Type getEnd();
	Type getFromIndex(int index);
	Type removeFromFront();
	Type removeFromEnd();
	Type removeFromIndex(int index);
	Type set(int index, Type value);

};



#endif /* MODEL_CTECLIST_H_ */
