#pragma once

#include "point3d.h"


class Tetrahedron {
    Point3D point1, point2, point3, point4;
    double volume;
    double findVolume();
public:
    Tetrahedron();
    Tetrahedron(Point3D point1, Point3D point2, Point3D point3, Point3D point4);
    Tetrahedron(Point3D points[4]);
    void display();
    double getVolume();
};