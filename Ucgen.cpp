#include "Ucgen.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;
// Üç tane Nokta nesnesi alan yapýcý.
Ucgen::Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3) {
    nokta1 = n1;
    nokta2 = n2;
    nokta3 = n3;
}

const Nokta& Ucgen::getNokta1() const {
    return nokta1;
}

const Nokta& Ucgen::getNokta2() const {
    return nokta2;
}

const Nokta& Ucgen::getNokta3() const {
    return nokta3;
}

void Ucgen::setNokta1(const Nokta& n1) {
    nokta1 = n1;
}

void Ucgen::setNokta2(const Nokta& n2) {
    nokta2 = n2;
}

void Ucgen::setNokta3(const Nokta& n3) {
    nokta3 = n3;
}
// Üçgenin String temsilini döndüren metot.
string Ucgen::toString() const {
    return "üçgen; " + nokta1.toString() + ", " + nokta2.toString() + ", " + nokta3.toString();
}
// Üçgenin alanýný hesaplayan metot.
double Ucgen::alan() const {
    double a = nokta1.getX(), b = nokta1.getY();
    double c = nokta2.getX(), d = nokta2.getY();
    double e = nokta3.getX(), f = nokta3.getY();
    // Üçgenin kenar uzunluklarýný hesapla
    double u = sqrt(pow(c - a, 2) + pow(d - b, 2));
    double v = sqrt(pow(e - c, 2) + pow(f - d, 2));
    double w = sqrt(pow(a - e, 2) + pow(b - f, 2));

    double s = (u + v + w) / 2; // Yarý çevre

    return sqrt(s * (s - u) * (s - v) * (s - w));
}
// Üçgenin çevresini hesaplayan metot. Üç doðru parçasý oluþturarak DogruParcasi sýnýfýnýn uzunluk metodunu kullanýr.
double Ucgen::cevre() const {
    // Ucgenin kenarlarýný temsil eden DogruParcasi nesnelerini oluþtur
    DogruParcasi dp1(nokta1, nokta2);
    DogruParcasi dp2(nokta2, nokta3);
    DogruParcasi dp3(nokta3, nokta1);

    return dp1.uzunluk() + dp2.uzunluk() + dp3.uzunluk();
}
// Üçgenin açýlarýný hesaplayan ve üç öðeli double dizisi olarak döndüren metot.
double* Ucgen::acilar() const {
    double* angles = new double[3];

    double a = nokta1.getX(), b = nokta1.getY();
    double c = nokta2.getX(), d = nokta2.getY();
    double e = nokta3.getX(), f = nokta3.getY();

    double x1 = a - c;
    double y1 = b - d;
    double x2 = e - c;
    double y2 = f - d;
    double x3 = a - e;
    double y3 = b - f;
    // Ýki vektör arasýndaki iç çarpýmý hesapla
    double dot1 = x1 * x2 + y1 * y2;
    double dot2 = x1 * x3 + y1 * y3;
    // Ýki vektör arasýndaki açýlarý hesapla
    angles[0] = acos(dot1 / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2)));
    angles[1] = acos(dot2 / (sqrt(x1 * x1 + y1 * y1) * sqrt(x3 * x3 + y3 * y3)));
    angles[2] = M_PI - angles[0] - angles[1];

    // Açýlarý dereceye çevirme
    angles[0] = angles[0] * 180 / M_PI;
    angles[1] = angles[1] * 180 / M_PI;
    angles[2] = angles[2] * 180 / M_PI;

    return angles;
}