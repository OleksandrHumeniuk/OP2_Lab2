#include  <iostream>
#include <iomanip>
#include "tetrahedron.h"

using namespace std;

Tetrahedron::Tetrahedron() {};

Tetrahedron :: Tetrahedron(Point3D point1, Point3D point2, Point3D point3, Point3D point4) {
        this->point1 = Point3D(point1.getX(), point1.getY(), point1.getZ());
        this->point2 = Point3D(point2.getX(), point2.getY(), point2.getZ());
        this->point3 = Point3D(point3.getX(), point3.getY(), point3.getZ());
        this->point4 = Point3D(point4.getX(), point4.getY(), point4.getZ());

        this->volume = findVolume();
}

Tetrahedron::Tetrahedron(Point3D points[4]) {
    this->point1 = Point3D(points[0].getX(), points[0].getY(), points[0].getZ());
    this->point2 = Point3D(points[1].getX(), points[1].getY(), points[1].getZ());
    this->point3 = Point3D(points[2].getX(), points[2].getY(), points[2].getZ());
    this->point4 = Point3D(points[3].getX(), points[3].getY(), points[3].getZ());

    this->volume = findVolume();
}

double Tetrahedron :: getVolume() {
    return volume;
}

void Tetrahedron::display() {
    cout << "Volume: " << getVolume() << endl;
    cout << "Point #1: ";
    point1.display();
    cout << "Point #2: ";
    point2.display();
    cout << "Point #3: ";
    point3.display();
    cout << "Point #4: ";
    point4.display();
}

double Tetrahedron :: findVolume() {
    double det =
            point4.getX() * point3.getY() * point2.getZ() * 1 - point3.getX() * point4.getY() * point2.getZ() * 1 -
            point4.getX() * point2.getY() * point3.getZ() * 1 + point2.getX() * point4.getY() * point3.getZ() * 1 +
            point3.getX() * point2.getY() * point4.getZ() * 1 - point2.getX() * point3.getY() * point4.getZ() * 1 -
            point4.getX() * point3.getY() * point1.getZ() * 1 + point3.getX() * point4.getY() * point1.getZ() * 1 +
            point4.getX() * point1.getY() * point3.getZ() * 1 - point1.getX() * point4.getY() * point3.getZ() * 1 -
            point3.getX() * point1.getY() * point4.getZ() * 1 + point1.getX() * point3.getY() * point4.getZ() * 1 +
            point4.getX() * point2.getY() * point1.getZ() * 1 - point2.getX() * point4.getY() * point1.getZ() * 1 -
            point4.getX() * point1.getY() * point2.getZ() * 1 + point1.getX() * point4.getY() * point2.getZ() * 1 +
            point2.getX() * point1.getY() * point4.getZ() * 1 - point1.getX() * point2.getY() * point4.getZ() * 1 -
            point3.getX() * point2.getY() * point1.getZ() * 1 + point2.getX() * point3.getY() * point1.getZ() * 1 +
            point3.getX() * point1.getY() * point2.getZ() * 1 - point1.getX() * point3.getY() * point2.getZ() * 1 -
            point2.getX() * point1.getY() * point3.getZ() * 1 + point1.getX() * point2.getY() * point3.getZ() * 1;

    return abs(det/6);
 }