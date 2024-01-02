#pragma once
#include "Nokta.h"
#include "DogruParcasi.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;

class Ucgen {
private:
    Nokta nokta1;
    Nokta nokta2;
    Nokta nokta3;

public:
    // Üç tane Nokta nesnesi alan yapýcý.
    Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3);
    const Nokta& getNokta1() const;
    const Nokta& getNokta2() const;
    const Nokta& getNokta3() const;
    void setNokta1(const Nokta& n1);
    void setNokta2(const Nokta& n2);
    void setNokta3(const Nokta& n3);
    // Üçgenin String temsilini döndüren metot.
    string toString() const;
    // Üçgenin alanýný hesaplayan metot.
    double alan() const;
    // Üçgenin çevresini hesaplayan metot. Üç doðru parçasý oluþturarak DogruParcasi sýnýfýnýn uzunluk metodunu kullanýr.
    double cevre() const;
    // Üçgenin açýlarýný hesaplayan ve üç öðeli double dizisi olarak döndüren metot.
    double* acilar() const;
};

