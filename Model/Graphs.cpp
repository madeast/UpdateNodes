//
//  Graphs.cpp
//  NodesInXCode
//
//  Created by Madsen, Easton on 4/27/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "Graphs.hpp"
#include <queue>
#include <iostream>

using namespace std;

template<class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert(size() < MAXIMUM);
    int newVertexNumber = manyVertices;
    manyVertices++;
    
    for(int otherVertexxNumber = 0; otherVertexxNumber < manyVertices; otherVertexxNumber++)
    {
        edges[otherVertexxNumber][newVertexNumber] = false;
        edges[newVertexNumber][otherVertexxNumber] = false;
    }
    
    labels[newVertexNumber] =value;
}

template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source < size() && target < size());
    edges[source][target] = true;
}

template <class Type>
bool Graph<Type> :: isEdge(int source, int target) const
{
    assert(source < size() && target < size());
    
    bool isAnEdge = false;
    isAnEdge = edges[source][target];
    
    return isAnEdge;
}

template <class Type>
Type& Graph<Type> :: operator[](int vertex)
{
    assert(vertex < size());
    return labels[vertex];
}

template <class Type>
Type Graph<Type> :: operator[](int vertex) const
{
    assert(vertex < size());
    return labels[vertex];
}

template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    assert(vertex < size());
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < size(); index++)
    {
        if(edges[vertex][index])
        {
            vertexNeighbors.insert(index);
        }
    }
    return vertexNeighbors;
}

template <class Type>
void Graph<Type> :: removeEdge(int source, int target)
{
    assert(source < size() && target < size());
    edges[source][target] = false;
}

