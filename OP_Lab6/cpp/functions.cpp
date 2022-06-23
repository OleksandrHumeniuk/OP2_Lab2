#include "functions.h"

vector <string> splitWords(string line) {

	line = line + " ";
	vector <string> words;
	string word = "";

	for (auto letter : line) {
		if (letter == ' ') {
			if (word != "") {
				words.push_back(word);
			}
			word = "";
		}
		else {
			word += letter;
		}
	}

	return words;
}

void insertWordsInHeap(Heap &heap, string line) {
	vector <string> words = splitWords(line);

	for (auto word : words) {
		heap.insert(word);
	}

}


Heap buildHeap() {
	string line;
	size_t combinationCode = 7;
	Heap heap{};

	cout << "Input your text. ENTER for next line. CTRL+G to stop" << endl;
	cin.ignore();

	getline(cin, line);
	while (line[0] != combinationCode) {
		insertWordsInHeap(heap, line);
		getline(cin, line);
	}

	return heap;
}