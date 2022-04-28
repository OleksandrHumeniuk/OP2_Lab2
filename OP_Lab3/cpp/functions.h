#pragma once

#include <string>
#include <iostream>

using namespace std;

enum Mode {
	AUTOMATIC = 1,												
	MANUAL = 2											
};

enum NumInputMode {
	POSITIVE_INT = 1,
	INT = 2,
	DOUBLE = 3
};

int inputInt(string header, NumInputMode mode);
Mode chooseMode();
Tetrahedron* generateArray(int size, int mode);
int findMaxVolumeIndex(Tetrahedron* tetrahedrons, int len);
void printTetrahendronsArray(Tetrahedron* tetrahedrons, int len);