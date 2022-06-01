#include "functions.h"


int main()
{
    TVector *vectors[4];
    vectors[0] = inputTVector3D("Enter information for 3D Vector A");
    vectors[1] = inputTVector3D("\nEnter information for 3D Vector B");
    vectors[2] = inputTVector2D("\nEnter information for 2D Vector C");
    vectors[3] = inputTVector2D("\nEnter information for 2D Vector D");

    vectors[0]->print("\nVector A -> ");
    vectors[1]->print("Vector B -> ");
    vectors[2]->print("Vector C -> ");
    vectors[3]->print("Vector D -> ");

    double S = vectors[0]->getScalar(*vectors[1]) + vectors[2]->getScalar(*vectors[3]) + vectors[0]->getLength();
    cout << "\nResult of calculations S: " << S << endl;
}



