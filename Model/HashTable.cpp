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
}

template <class Type>
HashTable<Type> :: ~HashTable<Type>()
{
    delete [] internalStorage;
}

template <class Type>
int HashTable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
void HashTable<Type> :: add(HashNode<Type> currentNode)
{
    if (!contains(currentNode))
    {
        if(this->size/this->ccity >= this->efficiencyPercentage)
        {
            updateSize();
        }
        
        int positionToInsert = findPosition(currentNode);
        
        if(internalStorage[positionToInsert] != nullptr)
        {
            while(internalStorage[positionToInsert] != nullptr)
            {
                positionToInsert = (positionToInsert + 1) % capacity;
            }
            internalStorage[positionToInsert] = currentNode;
        }
        else{
            internalStorage[positionToInsert] = currentNode;
        }
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
void HashTable<Type> :: updateSize()
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

