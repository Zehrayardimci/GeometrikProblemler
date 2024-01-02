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
    // Ýki uç noktayý Nokta nesnesi olarak alan yapýcý
    DogruParcasi(const Nokta& baslangýc, const Nokta& bitis);
    // Baþka bir DogruParcasi nesnesi alýp onun bir kopyasýný yeni bir DogruParcasi nesnesi olarak oluþturan yapýcý.
    DogruParcasi(const DogruParcasi& other);
    // Bir Nokta nesnesi, uzunluk ve eðim alarak DogruParcasi nesnesi oluþturan yapýcý
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim);
    const Nokta& getBaslangicNoktasi() const;
    const Nokta& getBitisNoktasi() const;
    // Uzunluðu hesaplayan metot
    double uzunluk() const;
    // Bir Nokta nesnesini parametre olarak alarak kesiþim noktasýný hesaplayan metot
    Nokta kesisimNoktasi(const Nokta& digerNokta) const;
    // Doðru parçasýnýn orta noktasýný hesaplayan metot
    Nokta ortaNokta() const;
    // Nesneyi string olarak temsil eden metot
    string toString() const;
    void yazdir() const;
    void setP1(const Nokta& newP1);
    void setP2(const Nokta& newP2);
};

