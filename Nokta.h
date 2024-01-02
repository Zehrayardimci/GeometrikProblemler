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
    Nokta();  // Parametresiz yap�c�
    Nokta(double value);  // Tek parametreli yap�c�
    Nokta(double xCoord, double yCoord);  // �ki parametreli yap�c�
    Nokta(const Nokta& other);  // Kopya yap�c�
    Nokta(const Nokta& other, double offset_x, double offset_y);  // Ofsetli yap�c�
    double getX() const;
    double getY() const;
    void setX(double value);
    void setY(double value);
    void setCoordinates(double xCoord, double yCoord);
    string toString() const;
    void yazdir() const;
};

