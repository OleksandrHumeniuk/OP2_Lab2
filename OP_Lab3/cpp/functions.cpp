#include <string>
#include <iostream>
#include <time.h>
#include <math.h>
#include "tetrahedron.h"

using namespace std;


enum NumInputMode {
	POSITIVE_INT = 1,
	INT = 2,
	DOUBLE = 3
};

bool isNum(string s, NumInputMode mode)
{	
	if (mode == NumInputMode::POSITIVE_INT) {
		for (char ch : s) {
			if (!isdigit(ch)) return false;
		}
		if (stoi(s) < 1) return false;
		return true;
	}
	else if (mode == NumInputMode::INT) {
		for (char ch : s) {
			if (!isdigit(ch) and ch != '-') return false;
		}
		return true;
	}
	else {
		for (char ch : s) {
			if (!isdigit(ch) and ch != '-' and ch != '.') return false;
		}
		return true;
	}
}

int inputInt(string header, NumInputMode mode) {
	string n;
	cout << header;
	cin >> n;

	string message;
	if (mode == NumInputMode::POSITIVE_INT) message = "You can only enter a positive integer: ";
	else if (mode == NumInputMode::INT)     message = "You can only enter an integer: ";
	else									return 0;

	while (!isNum(n, mode)) {
		cout << message;
		cin >> n;
	}
	return stoi(n);
}

double inputDouble(string header) {
	string n;
	cout << header;
	cin >> n;

	while (!isNum(n, NumInputMode :: DOUBLE)) {
		cout << "You can only enter a number: ";
		cin >> n;
	}
	return stod(n);
}

enum Mode {
	AUTOMATIC = 1,												
	MANUAL = 2													
};

Mode chooseMode() {
	string ch;														
	cout << "Choose generating mode (1 - for automatic generation, 2 - for manual input): ";
	cin >> ch;

	while (ch != "1" && ch != "2") {								
		cout << "You may only enter a '1' or an '2'!" << endl;
		cout << "Choose generating mode (1 - for automatic generation, 2 - for manual input): ";
		cin >> ch;
	}

	return ch == "1" ? Mode::AUTOMATIC : Mode::MANUAL;
}																	

Tetrahedron* automaticGeneration(int size) {
	srand(unsigned(time(NULL)));
	Tetrahedron* tetrahedrons = new Tetrahedron[size];

	for (int i = 0; i < size; i++) {
		Point3D points[4];

		for (int j = 0; j < 4; j++) {
			int x = rand() % 100 - 50;
			int y = rand() % 100 - 50;
			int z = rand() % 100 - 50;
			points[j] = Point3D(x, y, z);
		}

		tetrahedrons[i] = Tetrahedron(points);
	}

	return tetrahedrons;
}

Tetrahedron* manualGeneration(int size) {
	Tetrahedron* tetrahedrons = new Tetrahedron[size];

	for (int i = 0; i < size; i++) {
		Point3D points[4];

		cout << "\nTetrahedron #" << i + 1 << endl;
		for (int j = 0; j < 4; j++) {
			int x = inputDouble("Enter x coordinate for point #" + to_string(j + 1) + ": ");
			int y = inputDouble("Enter y coordinate for point #" + to_string(j + 1) + ": ");
			int z = inputDouble("Enter z coordinate for point #" + to_string(j + 1) + ": ");
			points[j] = Point3D(x, y, z);
		}
		tetrahedrons[i] = Tetrahedron(points);
	}
	return tetrahedrons;
}

Tetrahedron* generateArray(int size, int mode) {
	Tetrahedron* tetrahedrons;

	if (Mode::AUTOMATIC == mode) {
		tetrahedrons = automaticGeneration(size);
	}
	else {
		tetrahedrons = manualGeneration(size);
	}
	return tetrahedrons;
}

int findMaxVolumeIndex(Tetrahedron* tetrahedrons, int len) {

	if (len < 1) return -1;

	int maxIndex = 0;

	for (int i = 1; i < len; i++) {
		if (tetrahedrons[i].getVolume() > tetrahedrons[maxIndex].getVolume()) maxIndex = i;
	}

	return maxIndex;
}

void printTetrahendronsArray(Tetrahedron* tetrahedrons, int len) {
	for (int i = 0; i < len; i++) {
		cout << "\nTetrahedron #" << i + 1 << endl;
		tetrahedrons[i].display();
	}
}