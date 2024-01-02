#include "Nokta.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;
// Parametresiz yap�c�
Nokta::Nokta() {
    x = 0.0;
    y = 0.0;
}
// Tek parametreli yap�c�
Nokta::Nokta(double value) {
    x = value;
    y = value;
}
// �ki parametreli yap�c�
Nokta::Nokta(double xCoord, double yCoord) {
    x = xCoord;
    y = yCoord;
}
// Kopya yap�c�
Nokta::Nokta(const Nokta& other) {
    x = other.x;
    y = other.y;
}
// Ofsetli yap�c�
Nokta::Nokta(const Nokta& other, double offset_x, double offset_y) {
    x = other.x + offset_x;
    y = other.y + offset_y;
}

double Nokta::getX() const {
    return x;
}

double Nokta::getY() const {
    return y;
}

void Nokta::setX(double value) {
    x = value;
}

void Nokta::setY(double value) {
    y = value;
}

void Nokta::setCoordinates(double xCoord, double yCoord) {
    x = xCoord;
    y = yCoord;
}
// Noktay� string olarak temsil eden bir metin d�nd�r�r
string Nokta::toString() const {
    return "(" + to_string(x) + "," + to_string(y) + ")";
}

void Nokta::yazdir() const {
    cout << toString() << endl;
}