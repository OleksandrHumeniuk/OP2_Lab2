#pragma once
#include "tvector.h"
#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

class TVector2D : public TVector {
	double x, y;
public:
	TVector2D(double x, double y) : x(x), y(y) {};
	
	double getScalar(TVector &);
	double getLength();
	double getCoordinate(char);
	void print(string);
};
