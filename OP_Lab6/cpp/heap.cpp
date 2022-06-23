#include "heap.h"


Node* Heap::getRoot() {
	return root;
}

bool Heap::isEmpty() {
	return root == nullptr;
}

void Heap::insert(string value) {
	if (isEmpty()) {
		root = new Node(value);
	}
	else {
		Node* node = findNode(value, root);
		if (node == nullptr) levelOrderInsert(value);
		else				 increasePriority(node);
	}
}

Node* Heap::findNode(string value, Node* node) {
	if (node != nullptr) {

		Node* leftNode = findNode(value, node->getLeft());
		Node* rightNode = findNode(value, node->getRight());

		if (node->getValue() == value) return node;
		else if (leftNode != nullptr)  return leftNode;
		else						   return rightNode;

	}
	else {
		return nullptr;
	}
}

void Heap::levelOrderInsert(string value) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->getLeft() == nullptr) {
			Node *node = new Node(value);
			node->setParent(temp);
			temp->setLeft(node);
			return;
		}
		else q.push(temp->getLeft());

		if (temp->getRight() == nullptr) {
			Node* node = new Node(value);
			node->setParent(temp);
			temp->setRight(node);
			return;
		}
		else q.push(temp->getRight());
	}
}

void Heap::swapUp(Node* node) {
	if (node->getParent() != nullptr && node->getParent()->getCounter() < node->getCounter()) {
		node->swap(node->getParent());
		swapUp(node->getParent());
	}
}


void Heap::increasePriority(Node* node) {
	node->increaseCounter();
	swapUp(node);
}

void Heap::printHeap(Node* node, int level) {
	if (node != nullptr) {
		printHeap(node->getRight(), level + 1);

		string spaces(10 * level, ' ');
		cout << spaces << "-> |" << node->getValue() << " : " << node->getCounter() << "|" << endl;

		printHeap(node->getLeft(), level + 1);
	}

}

void Heap::levelOrderPrint() {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		cout << setw(7) << temp->getValue() << " : " << temp->getCounter() << endl;

		if (temp->getLeft() != nullptr) {
			q.push(temp->getLeft());
		}

		if (temp->getRight() != nullptr) {
			q.push(temp->getRight());
		}
	}
}