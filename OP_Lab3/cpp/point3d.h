#pragma once

class Point3D {
    double x;
    double y;
    double z;
public:
    Point3D();
    Point3D(int, int, int);
    void setX(double);
    void setY(double);
    void setZ(double);
    double getX();
    double getY();
    double getZ();
    void display();
};
