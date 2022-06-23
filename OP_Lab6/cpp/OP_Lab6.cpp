#include "functions.h"
#include "heap.h"


int main() {
	Heap heap = buildHeap();
	cout << "\nTree" << endl;
	heap.printHeap(heap.getRoot());

	cout << "\nTree words" << endl;
	heap.levelOrderPrint();
}