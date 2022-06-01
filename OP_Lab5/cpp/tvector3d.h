#pragma once
#include "tvector.h"
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class TVector3D : public TVector {
	double x, y, z;
public:
	TVector3D(double x, double y, double z) : x(x), y(y), z(z) {};

	double getScalar(TVector&);
	double getLength();
	double getCoordinate(char);
	void print(string);
};