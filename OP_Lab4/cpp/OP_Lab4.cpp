#include "functions.h"

int main()
{
    Date d1, d2, d3;
    inputDates(d1, d2, d3);

    printDates(d1, d2, d3, "\nBefore Calculations");

    Date interval = performCalculations(d1, d2, d3);

    printDates(d1, d2, d3, "After calculations");
    cout << "The interval between D1 and D2 is "; interval.printInterval();
    cout << "The season of D3 is " << d3.getSeason() << endl;

}