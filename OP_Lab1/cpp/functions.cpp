#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum Mode {
	OVERWRITING = 1,
	ADDING = 2
};

int chooseMode() {
	string ch;
	cout << "Choose writing mode (1 - for overwriting text, 2 - for adding text): ";
	cin >> ch;

	while (ch != "1" && ch != "2") {
		cout << "You may only enter a '1' or an '2'!" << endl;
		cout << "Choose writing mode (1 - for overwriting text, 2 - for adding text): ";
		cin >> ch;
	}
	
	return stoi(ch);
}

void createInputFile(string name, int mode) {

	ofstream inputFile;
	if (Mode::OVERWRITING == mode) {
		inputFile.open(name);
	}
	else {
		inputFile.open(name, ios::app);
	}
	
	string line;
	size_t combinationCode = 7; 

	cout << "Input your text. ENTER for next line. CTRL+G to stop" << endl;
	cin.ignore();

	if (inputFile) {
	
		getline(cin, line);
		if (line[0] != combinationCode) {
			inputFile << line;
			getline(cin, line);
			while (line[0] != combinationCode) {
				inputFile << "\n" << line;
				getline(cin, line);
			}
		}
	}
	inputFile.close();
}


vector <string> getWords(string name) {
	vector <string> words;
	string word;
	ifstream inputFile(name);

	while (!inputFile.eof()) {
		inputFile >> word;
		words.push_back(word);
	}

	inputFile.close();
	return words;
}

int countWords(string word, vector <string> words) {
	int counter = 0;
	for (string s : words) {
		if (s == word) {
			++counter;
		}
	}
	return counter;
}

bool isNum(string s)
{
	for (char ch : s) {
		if (!isdigit(ch) and ch != '-') return false;
	}
	return true;
}

int inputNum() {
	string n;
	cout << "Enter number N: ";
	cin >> n;

	while (!isNum(n)) {
		cout << "You can only enter an interger number: ";
		cin >> n;
	}
	return stoi(n);
}

vector <string> removeWord(vector<string> words, string word) {
	
	vector <string> newWords;

	for (string s : words) {
		if (s != word) {
			newWords.push_back(s);
		}
	}

	return newWords;
}

vector <string> createRepeatingVector(string name, int n) {

	vector <string> words = getWords(name);	
	
	vector <string> updatedWords = words;

	int counter;
	for (string word : words) {
		counter = countWords(word, words);
		if (counter <= n) {
			updatedWords = removeWord(updatedWords, word);
		}
	}

	return updatedWords;
}

void oddEvenSort(vector <string> &words) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;

		for (int i = 0; i < words.size() - 1; i += 2) {
			if (words[i].length() > words[i + 1].length()) {
				string temp = words[i];
				words[i] = words[i + 1];
				words[i + 1] = temp;
				sorted = false;
			}
		}

		for (int i = 1; i < words.size() - 1; i += 2) {
			if (words[i].length() > words[i + 1].length()) {
				string temp = words[i];
				words[i] = words[i + 1];
				words[i + 1] = temp;
				sorted = false;
			}
		}
	}
}

void createOutputFile(string outputName, string inputName) {

	int n = inputNum();
	vector <string> repeatingWords = createRepeatingVector(inputName, n);
	oddEvenSort(repeatingWords);

	ofstream outputFile(outputName);

	if (repeatingWords.size() > 0) outputFile << repeatingWords[0];
	for (int i = 1; i < repeatingWords.size(); i++) {
		outputFile << " " << repeatingWords[i];
	}
	outputFile.close();
}


void printFile(string name, string text) {

	string line;
	ifstream inputFile(name);

	cout << text << endl;

	while (!inputFile.eof()) {
		getline(inputFile, line);
		cout << line << endl;
	}

	inputFile.close();
}

