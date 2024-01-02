#pragma once
#include "Nokta.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;

class DogruParcasi {
private:
    Nokta baslangicNoktasi;
    Nokta bitisNoktasi;

public:
    // �ki u� noktay� Nokta nesnesi olarak alan yap�c�
    DogruParcasi(const Nokta& baslang�c, const Nokta& bitis);
    // Ba�ka bir DogruParcasi nesnesi al�p onun bir kopyas�n� yeni bir DogruParcasi nesnesi olarak olu�turan yap�c�.
    DogruParcasi(const DogruParcasi& other);
    // Bir Nokta nesnesi, uzunluk ve e�im alarak DogruParcasi nesnesi olu�turan yap�c�
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim);
    const Nokta& getBaslangicNoktasi() const;
    const Nokta& getBitisNoktasi() const;
    // Uzunlu�u hesaplayan metot
    double uzunluk() const;
    // Bir Nokta nesnesini parametre olarak alarak kesi�im noktas�n� hesaplayan metot
    Nokta kesisimNoktasi(const Nokta& digerNokta) const;
    // Do�ru par�as�n�n orta noktas�n� hesaplayan metot
    Nokta ortaNokta() const;
    // Nesneyi string olarak temsil eden metot
    string toString() const;
    void yazdir() const;
    void setP1(const Nokta& newP1);
    void setP2(const Nokta& newP2);
};

