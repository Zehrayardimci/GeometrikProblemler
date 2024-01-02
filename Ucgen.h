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
    // �� tane Nokta nesnesi alan yap�c�.
    Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3);
    const Nokta& getNokta1() const;
    const Nokta& getNokta2() const;
    const Nokta& getNokta3() const;
    void setNokta1(const Nokta& n1);
    void setNokta2(const Nokta& n2);
    void setNokta3(const Nokta& n3);
    // ��genin String temsilini d�nd�ren metot.
    string toString() const;
    // ��genin alan�n� hesaplayan metot.
    double alan() const;
    // ��genin �evresini hesaplayan metot. �� do�ru par�as� olu�turarak DogruParcasi s�n�f�n�n uzunluk metodunu kullan�r.
    double cevre() const;
    // ��genin a��lar�n� hesaplayan ve �� ��eli double dizisi olarak d�nd�ren metot.
    double* acilar() const;
};

