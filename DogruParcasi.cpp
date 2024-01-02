#include "DogruParcasi.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;
// Ýki uç noktayý Nokta nesnesi olarak alan yapýcý
DogruParcasi::DogruParcasi(const Nokta& baslangýc, const Nokta& bitis) {
    baslangicNoktasi.setX(baslangýc.getX());
    baslangicNoktasi.setY(baslangýc.getY());

    bitisNoktasi.setX(bitis.getX());
    bitisNoktasi.setY(bitis.getY());
}

// Baþka bir DogruParcasi nesnesi alýp onun bir kopyasýný yeni bir DogruParcasi nesnesi olarak oluþturan yapýcý.
DogruParcasi::DogruParcasi(const DogruParcasi& other) {
    baslangicNoktasi.setX(other.baslangicNoktasi.getX());
    baslangicNoktasi.setY(other.baslangicNoktasi.getY());

    bitisNoktasi.setX(other.bitisNoktasi.getX());
    bitisNoktasi.setY(other.bitisNoktasi.getY());
}
// Bir Nokta nesnesi, uzunluk ve eðim alarak DogruParcasi nesnesi oluþturan yapýcý
DogruParcasi::DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
    double m = tan(egim);
    double yariUzunluk = uzunluk / 2.0;
    double x1 = ortaNokta.getX() - yariUzunluk / sqrt(1 + m * m);
    double x2 = ortaNokta.getX() + yariUzunluk / sqrt(1 + m * m);
    double y1 = ortaNokta.getY() - m * yariUzunluk / sqrt(1 + m * m);
    double y2 = ortaNokta.getY() + m * yariUzunluk / sqrt(1 + m * m);
    baslangicNoktasi.setCoordinates(x1, y1);
    bitisNoktasi.setCoordinates(x2, y2);
}

const Nokta& DogruParcasi::getBaslangicNoktasi() const {
    return baslangicNoktasi;
}

const Nokta& DogruParcasi::getBitisNoktasi() const {
    return bitisNoktasi;
}
// Uzunluðu hesaplayan metot
double DogruParcasi::uzunluk() const {
    double deltaX = bitisNoktasi.getX() - baslangicNoktasi.getX();
    double deltaY = bitisNoktasi.getY() - baslangicNoktasi.getY();
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}
// Bir Nokta nesnesini parametre olarak alarak kesiþim noktasýný hesaplayan metot
Nokta DogruParcasi::kesisimNoktasi(const Nokta& digerNokta) const {
    double m1 = (bitisNoktasi.getY() - baslangicNoktasi.getY()) / (bitisNoktasi.getX() - baslangicNoktasi.getX());

    if (isinf(m1)) {
        // Eðimi sonsuz ise, doðru parçasý dikeydir ve kesiþim noktasýnýn x koordinatý baslangicNoktasi'nýn x koordinatýna eþittir.
        return Nokta(baslangicNoktasi.getX(), digerNokta.getY());
    }

    double m2 = -1.0 / m1;
    // Eðimleri farklý olan doðru parçalarýnýn kesiþim noktasýný hesaplama
    double xKesisim = (m2 * digerNokta.getX() - m1 * baslangicNoktasi.getX() + baslangicNoktasi.getY() - digerNokta.getY()) / (m2 - m1);
    double yKesisim = m2 * (xKesisim - digerNokta.getX()) + digerNokta.getY();
    return Nokta(xKesisim, yKesisim);
}

// Doðru parçasýnýn orta noktasýný hesaplayan metot
Nokta DogruParcasi::ortaNokta() const {
    double ortaX = (baslangicNoktasi.getX() + bitisNoktasi.getX()) / 2.0;
    double ortaY = (baslangicNoktasi.getY() + bitisNoktasi.getY()) / 2.0;
    return Nokta(ortaX, ortaY);
}
// Nesneyi string olarak temsil eden metot
string DogruParcasi::toString() const {
    return baslangicNoktasi.toString() + " -> " + bitisNoktasi.toString();
}

void DogruParcasi::yazdir() const {
    cout << toString() << endl;
}

void DogruParcasi::setP1(const Nokta& newP1) {
    baslangicNoktasi.setX(newP1.getX());
    baslangicNoktasi.setY(newP1.getY());
}

void DogruParcasi::setP2(const Nokta& newP2) {
    bitisNoktasi.setX(newP2.getX());
    bitisNoktasi.setY(newP2.getY());
}