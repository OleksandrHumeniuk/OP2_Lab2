#pragma once
#include <string> 
#include <exception> 
#include <iostream> 
#include "tvector.h"
#include "tvector2d.h"
#include "tvector3d.h"

using namespace std;

double inputDouble(string header);
TVector2D* inputTVector2D(string header);
TVector3D* inputTVector3D(string header);