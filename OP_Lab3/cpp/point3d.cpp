#include <iostream>
#include <iomanip>
#include "point3d.h"

using namespace std;

Point3D::Point3D() {};

Point3D::Point3D(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point3D::setX(double x) {
    this->x = x;
}
void Point3D::setY(double y) {
    this->y = y;
}
void Point3D::setZ(double z) {
    this->z = z;
}

double Point3D::getX() {
    return this->x;
}
double Point3D::getY() {
    return this->y;
}
double Point3D::getZ() {
    return this->z;
}

void Point3D::display() {
    cout << "X = " << setw(4) << x << " Y = " << setw(4) << y << " Z = " << setw(4) << z << endl;
}