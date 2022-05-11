#include "functions.h"

bool isNum(string s)
{
    for (char ch : s) {
        if (!isdigit(ch)) return false;
    }
    if (stoi(s) == 0) return false;

    return true;
}


int inputNum(string text) {
    string n;
    cout << text;
    cin >> n;

    while (!isNum(n)) {
        cout << "You can only enter a positive integer: ";
        cin >> n;
    }
    cin.ignore();
    return stoi(n);
}


void inputDates(Date& d1, Date& d2, Date& d3) {
    
    cout << "Dates are entered and displayed in logical view: 1 <= year, 1 <= month <= 12, 1 <= day <= 28-31 \n"
            "However, for all dates (years, month, days) you may enter any positive integer \n"
            "The program will automatically reformat the date \n" << endl;
    
    int year, month, day;
    year = inputNum("Input year number for D1: ");
    month = inputNum("Input month number for D1: ");
    day = inputNum("Input day number for D1: ");
    d1 = Date(day, month, year);

    month = inputNum("\nInput month number for D2: ");
    day = inputNum("Input day number for D2: ");
    d2 = Date(day, month);

    day = inputNum("\nInput day number for D3: ");
    d3 = Date(day);
}

void printDates(Date& d1, Date& d2, Date& d3, string header) {
    cout << header << endl;
    cout << "D1: "; d1.printDate();
    cout << "D2: "; d2.printDate();
    cout << "D3: "; d3.printDate();
    cout << "\n";
}


Date performCalculations(Date& d1, Date& d2, Date& d3) {
    d1 += 9;
    d2 += 14;
    Date interval = d1 - d2;
    return interval;
}