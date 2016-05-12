//
//  HashTable.hpp
//  UpdateNodes
//
//  Created by Madsen, Easton on 5/9/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp
#include "CTECList.cpp"
#include "HashNode.cpp"
template <class Type>
class HashTable
{
private:
    int capacity;
    int tableCapacity;
    double efficiencyPercentage;
    int size;
    Type * internalStorage;
    CtecList<HashNode<Type>> * tableStorage;
    
    int findPosition(HashNode<Type> currentNode); 
    int findTablePosition(HashNode<Type> currentNode);
    
    int handleCollision(HashNode<Type> currentNode);
    
    void updateCapacity();
    void updateTableCapacity();
    
    int getNextPrime();
    bool isPrime(int candidateNumber);
public:
    HashTable();
    ~HashTable();
    int getSize();
    void add(HashNode<Type> currentNode);
    void addToTable(HashNode<Type> currentNode);
    
    bool remove(HashNode<Type> currentNode);
    bool contains(HashNode<Type> currentNode);
};

#endif /* HashTable_hpp */
