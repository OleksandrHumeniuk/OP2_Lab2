#pragma once
#include <string>

using namespace std;

class Node {
	string value;
	int counter;
	Node* left;
	Node* right;
	Node* parent;
public:
	Node(string);

	string getValue();
	void setValue(string);

	int getCounter();
	void setCounter(int);
	void increaseCounter();

	Node* getLeft();
	void setLeft(Node*);

	Node* getRight();
	void setRight(Node*);

	Node* getParent();
	void setParent(Node*);

	void swap(Node*);
};
