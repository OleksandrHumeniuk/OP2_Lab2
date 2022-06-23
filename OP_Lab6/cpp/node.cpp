#include "node.h"

Node::Node(string val) {
	value = val;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	counter = 1;
}

string Node::getValue() {
	return value;
}

void Node::setValue(string val) {
	value = val;
}

int Node::getCounter() {
	return counter;
}

void Node::setCounter(int val) {
	counter = val;
}

void Node::increaseCounter() {
	counter++;
}

Node* Node::getLeft() {
	return left;
}

void Node::setLeft(Node* node) {
	left = node;
}

Node* Node::getRight() {
	return right;
}

void Node::setRight(Node* node) {
	right = node;
}

Node* Node::getParent() {
	return parent;
}

void Node::setParent(Node* node) {
	parent = node;
}

void Node::swap(Node* node) {
	string tempValue = node->getValue();
	int tempCounter = node->getCounter();
	node->setValue(value);
	node->setCounter(counter);

	value = tempValue;
	counter = tempCounter;
}



