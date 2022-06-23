#pragma once
#include <queue>
#include <iostream>
#include <iomanip>
#include "node.h"

class Heap {
	Node* root;

	void swapUp(Node*);
	void increasePriority(Node*);
	void levelOrderInsert(string);
	Node* findNode(string, Node*);
public:
	Node* getRoot();
	void insert(string);
	bool isEmpty();
	void printHeap(Node*, int = 0);
	void levelOrderPrint();
};