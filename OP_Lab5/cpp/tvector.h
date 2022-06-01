#pragma once
#include <string>

using namespace std;

class TVector {
public:
	virtual double getScalar(TVector &) = 0;
	virtual double getLength() = 0;
	virtual double getCoordinate(char) = 0;
	virtual void print(string) = 0;
};