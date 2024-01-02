#pragma once

#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;

class Nokta {
private:
    double x;
    double y;

public:
    Nokta();  // Parametresiz yapýcý
    Nokta(double value);  // Tek parametreli yapýcý
    Nokta(double xCoord, double yCoord);  // Ýki parametreli yapýcý
    Nokta(const Nokta& other);  // Kopya yapýcý
    Nokta(const Nokta& other, double offset_x, double offset_y);  // Ofsetli yapýcý
    double getX() const;
    double getY() const;
    void setX(double value);
    void setY(double value);
    void setCoordinates(double xCoord, double yCoord);
    string toString() const;
    void yazdir() const;
};

