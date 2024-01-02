#include "DogruParcasi.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;
// �ki u� noktay� Nokta nesnesi olarak alan yap�c�
DogruParcasi::DogruParcasi(const Nokta& baslang�c, const Nokta& bitis) {
    baslangicNoktasi.setX(baslang�c.getX());
    baslangicNoktasi.setY(baslang�c.getY());

    bitisNoktasi.setX(bitis.getX());
    bitisNoktasi.setY(bitis.getY());
}

// Ba�ka bir DogruParcasi nesnesi al�p onun bir kopyas�n� yeni bir DogruParcasi nesnesi olarak olu�turan yap�c�.
DogruParcasi::DogruParcasi(const DogruParcasi& other) {
    baslangicNoktasi.setX(other.baslangicNoktasi.getX());
    baslangicNoktasi.setY(other.baslangicNoktasi.getY());

    bitisNoktasi.setX(other.bitisNoktasi.getX());
    bitisNoktasi.setY(other.bitisNoktasi.getY());
}
// Bir Nokta nesnesi, uzunluk ve e�im alarak DogruParcasi nesnesi olu�turan yap�c�
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
// Uzunlu�u hesaplayan metot
double DogruParcasi::uzunluk() const {
    double deltaX = bitisNoktasi.getX() - baslangicNoktasi.getX();
    double deltaY = bitisNoktasi.getY() - baslangicNoktasi.getY();
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}
// Bir Nokta nesnesini parametre olarak alarak kesi�im noktas�n� hesaplayan metot
Nokta DogruParcasi::kesisimNoktasi(const Nokta& digerNokta) const {
    double m1 = (bitisNoktasi.getY() - baslangicNoktasi.getY()) / (bitisNoktasi.getX() - baslangicNoktasi.getX());

    if (isinf(m1)) {
        // E�imi sonsuz ise, do�ru par�as� dikeydir ve kesi�im noktas�n�n x koordinat� baslangicNoktasi'n�n x koordinat�na e�ittir.
        return Nokta(baslangicNoktasi.getX(), digerNokta.getY());
    }

    double m2 = -1.0 / m1;
    // E�imleri farkl� olan do�ru par�alar�n�n kesi�im noktas�n� hesaplama
    double xKesisim = (m2 * digerNokta.getX() - m1 * baslangicNoktasi.getX() + baslangicNoktasi.getY() - digerNokta.getY()) / (m2 - m1);
    double yKesisim = m2 * (xKesisim - digerNokta.getX()) + digerNokta.getY();
    return Nokta(xKesisim, yKesisim);
}

// Do�ru par�as�n�n orta noktas�n� hesaplayan metot
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