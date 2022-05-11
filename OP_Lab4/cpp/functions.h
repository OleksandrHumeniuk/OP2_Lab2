#pragma once

#include <string>
#include <iostream>
#include "date.h"

using namespace std;

bool isNum(string s);
int inputNum(string text);
void inputDates(Date& d1, Date& d2, Date& d3);
void printDates(Date& d1, Date& d2, Date& d3, string header);
Date performCalculations(Date& d1, Date& d2, Date& d3);