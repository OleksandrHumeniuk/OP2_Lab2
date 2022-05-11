#include "date.h"

const vector<int> Date::monthsOfYear =     { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const vector<int> Date::monthsOfLeapYear = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int days, int months, int years) {
	this->day = days - 1;
	this->month = months - 1;
	this->year = years - 1;
	formatDate();
}

Date::Date(int days, int months) {
	this->day = days - 1;
	this->month = months - 1;
	this->year = 0;
	formatDate();
}

Date::Date(int days) {
	this->day = days - 1;
	this->month = 0;
	this->year = 0;
	formatDate();
}


bool Date::isLeapYear(int year) const {
	int tempYear = year + 1;
	return ((tempYear % 4 == 0 and tempYear % 100 != 0) or tempYear % 400 == 0);
}

void Date::formatYears() {
	year += month / 12;
	month = month % 12;

	while (day >= 366 || (day >= 365 && !isLeapYear(year))) {

		if (isLeapYear(year)) {
			day -= 366;
			year += 1;
		}
		else {
			day -= 365;
			year += 1;
		}
	}
}

void Date::formatMonths() {
	vector<int> currentMonthsOfYear;

	currentMonthsOfYear = isLeapYear(year) ? monthsOfLeapYear : monthsOfYear;

	while (day >= monthsOfYear[month]) {
		day -= monthsOfYear[month];
		month += 1;
		if (month == 12) {
			currentMonthsOfYear = isLeapYear(year) ? monthsOfLeapYear : monthsOfYear;
			year += 1;
			month = 0;
		}
	}
}


void Date::formatDate() {
	formatYears();
	formatMonths();
}

const Date Date::operator+=(const int days) {
	day += days;
	formatDate();
	return *this;
}

int Date::toDays() const {
	int days = day;
	int years = year;

	while (years >= 0) {
		if (isLeapYear(years)) days += 366;
		else 				   days += 365;
		years -= 1;
	}

	int months = month;

	vector<int> currentMonthsOfYear = isLeapYear(year) ? monthsOfLeapYear : monthsOfYear;

	while (months >= 0) {
		days += currentMonthsOfYear[months];
		months--;
	}

	return days + 1;
}

const Date Date::operator-(const Date date) {
	int days1 = this->toDays();
	int days2 = date.toDays();
	
	Date interval(abs(days1 - days2));

	return interval;
}

string Date::getSeason() {
	if (month < 2 || month == 11)  return "Winter";
	else if (month < 5)			   return "Spring";
	else if (month < 8)			   return "Summer";
	else                           return "Autumn";
}

int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}

void Date::printDate() {
	cout << "Year: " << year + 1<< " Month: " << month +1 << " Day: " << day + 1 << endl;
}

void Date::printInterval() {
	cout << year << " years " << month << " months " << day << " days" << endl;
}

