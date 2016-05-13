//
//  HashTable.cpp
//  UpdateNodes
//
//  Created by Madsen, Easton on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "HashTable.hpp"
#include "HashNode.hpp"
#include <cmath>

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficincyPercentage = .677;
    this->size = 0;
    this->internalStorage = new Type[capacity];
    this->tableStorage = new CtecList<HashNode<Type>>[capacity];
}

template <class Type>
HashTable<Type> :: ~HashTable<Type>()
{
    delete [] internalStorage;
    delete [] tableStorage;
}

template <class Type>
int HashTable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
void HashTable<Type> :: addToTable(HashNode<Type> currentNode)
{
    if(this->size/this->tableCapacity >= this->efficiencyPercentage)
    {
        updateTableCapacity();
    }
    //Find where to put the value
    int positionToInsert = findPosition(currentNode);
    //If the spot is empty, make a new list and add the node
    if(tableStorage[positionToInsert] == nullptr)
    {
        CtecList<HashNode<Type>> hashList;
        tableStorage[positionToInsert] = hashList;
        hashList.addEnd(currentNode);
    }
    else // add the node
    {
        tableStorage[positionToInsert].addEnd(currentNode);
    }
}

template <class Type>
void HashTable<Type> :: add(HashNode<Type> currentNode)
{
    if (!contains(currentNode))
    {
        if(this->size/this->city >= this->efficiencyPercentage)
        {
            updateCapacity();
        }
        
        int positionToInsert = findPosition(currentNode);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = handleCollision(currentNode);
            }
        }
        
        internalStorage[positionToInsert] = currentNode;
    }
}

/*
 *Very basic hashing algorithm.
 *Simply assigns a position based on modulo math.
 */
 template <class Type>
int HashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    //We are going "hash" the key of the HashNode to find its value.
    int position = 0;
    
    position = currentNode.getKEy() % capacity;
    return position;
}

template <class Type>
int HashTable<Type> :: findTablePosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % tableCapacity;
}

template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (capacity *2) +1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
bool HashTable<Type> :: isPrime(int canidateNumber)
{
    bool isPrime = false;
    
    if(canidateNumber <= 1)
    {
        return false;
    }
    else if(canidateNumber == 2 || canidateNumber == 3)
    {
        isPrime = 2;
    }
    else if(canidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    else{
        for(int next = 3; next <= sqrt(canidateNumber) + 1; next += 2)
        {
            if(canidateNumber % next == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
}

template <class Type>
void HashTable<Type> :: updateCapacity()
{
    int updatedCapacity = getNextPrime();
    HashNode<Type> * updatedStorage = new HashNode<Type> [updatedCapacity];
    
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
    }
    
    internalStorage = updatedStorage;
}

template <class Type>
void HashTable<Type> :: updateTableCapacity()
{
    int updatedCapacity = getNextPrime();
    CtecList<HashNode<Type>> * updateTable = new CtecList<HashNode<Type>>[updatedCapacity];
    int oldTableCapacity = tableCapacity;
    tableCapacity = updatedCapacity;
    
    for(int index = 0; index < oldTableCapacity; index++)
    {
        if(tableStorage[index] != nullptr)
        {
            CtecList<HashNode<Type>> temp = tableStorage[index];
            for(int innerIndex = 0; innerIndex < tableStorage[index].getSize(); innerIndex++)
            {
                int updatedTablePosition = findPosition(temp.get(index));
                if(updateTable[updatedTablePosition] == nullptr)
                {
                    CtecList<HashNode<Type>> updatedList;
                    updatedList.addEnd(temp.get(index));
                }
                else
                {
                    updateTable[updatedTablePosition].addEnd(temp.get(index));
                }
            }
        }
    }
}

template <class Type>
bool HashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool wasRemoved = false;
    if(contains(currentNode))
    {
        int index = findPosition(currentNode);
        while(internalStorage[index] != nullptr && !wasRemoved)
        {
            if(internalStorage[index].getValue() == currentNode.getValue())
            {
                wasRemoved = true;
                internalStorage[index] = nullptr;
                size--;
            }
            else
            {
                index = (index + 1) % capacity;
            }
        }
    }
    
    return wasRemoved;
}

template <class Type>
bool HashTable<Type> :: remove(HashNode<Type> currentNode)
{
    int index = findPosition(currentNode);
    if(contains(currentNode))
    {
        int index = findPosition(currentNode);
    }
}

template <class Type>
int HashTable<Type> :: handleCollision(HashNode<Type> currentNode)
{
    int reHashedPosition = findPosition(currentNode);
    int random = rand();
    reHashedPosition = random + (reHashedPosition * reHashedPosition) % capacity;
    
    return reHashedPosition;
}
