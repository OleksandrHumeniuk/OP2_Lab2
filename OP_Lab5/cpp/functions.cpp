#include "functions.h"


TVector2D* inputTVector2D(string header) {
    cout << header << endl;

    double x, y;

    x = inputDouble("Input x coordinate: ");
    y = inputDouble("Input y coordinate: ");

    TVector2D* p = new TVector2D(x, y);
    return p;
}

TVector3D* inputTVector3D(string header) {
    cout << header << endl;

    double x, y, z;

    x = inputDouble("Input x coordinate: ");
    y = inputDouble("Input y coordinate: ");
    z = inputDouble("Input z coordinate: ");

    TVector3D* p = new TVector3D(x, y, z);
    return p;
}

double inputDouble(string header)
{
    string num;
    double parsedNumber = 0.0;
    bool isValid = false;

    while (!isValid) {
        try
        {
            cout << header;
            cin >> num;
            parsedNumber = std::stod(num);
            isValid = true;
        }
        catch (const exception e)
        {
            cout << "You can only enter a number!" << endl;
            isValid = false;
        }
    }
    
    return parsedNumber;
}
    

 