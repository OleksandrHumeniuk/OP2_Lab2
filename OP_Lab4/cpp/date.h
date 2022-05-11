#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Date {
	int day, month, year;
	static const vector<int> monthsOfYear;
	static const vector<int> monthsOfLeapYear;
	
	void formatDate(); 
	void formatYears();
	void formatMonths();
	bool isLeapYear(int year) const;
	int toDays() const;
public:
	Date() :day(0), month(0), year(0) {};
	Date(int days, int months, int years);
	Date(int days, int months);
	Date(int days);

	const Date operator+=(const int days);
	const Date operator-(const Date date);
	int getDay();
	int getMonth();
	int getYear();
	string getSeason();
	void printDate();
	void printInterval();
};

