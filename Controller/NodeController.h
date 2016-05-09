/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: emad6932
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include <iostream>
#include <string>
#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.h"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.h"
#include "../Model/CTECArray.cpp"
#include "../Model/CTECBinaryTree.cpp"
#include "../Model/Timer.h"
#include "../Model/CtecList.cpp"
#include "../Model/Graphs.cpp"
using namespace std;

class NodeController
{
private:
    CTECArray<int> * notHipsterInts;
    CtecList<int> * numbers;
    Timer arrayTimer;
    int * mergeData;
    void testsLists();
    void doMergeSort();
    void mergesort(int dataArray [], int size);
    void merge(int data [], int sizeOne, int sizeTwo );
    void checkSorts();
    void swap(int first, int second);
    void quickSort(int first, int size);
    int partition(int first, int last);
    void tryTree();
    void doQuick();
    void tryGraphs();
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
