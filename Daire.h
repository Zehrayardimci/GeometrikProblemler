#pragma once
#include "Nokta.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;

class Daire {
private:
    Nokta merkez;  // Dairenin merkezini temsil eden Nokta nesnesi
    double yaricap;  // Dairenin yar��ap�

public:
    // Merkez (Nokta nesnesi olarak) ve yar��ap� parametre olarak alan yap�c�.
    Daire(const Nokta& m, double r);
    // Ba�ka bir Daire nesnesi al�p onun bir kopyas�n� yeni bir Daire nesnesi olarak olu�turan yap�c�.
    Daire(const Daire& other);
    // Ba�ka bir Daire nesnesi ve reel bir pozitif x de�eri alarak, parametre olarak al�nan Daire nesnesini yar��ap� x ile �arp�lm�� olarak kopyalayan yap�c�.
    Daire(const Daire& other, double x);
    // Dairenin alan�n� hesaplayan metot.
    double alan() const;
    // Dairenin �evresini hesaplayan metot.
    double cevre() const;
    // �ki dairenin kesi�im durumunu kontrol eder. �� i�e ise 0, �rt���yorsa 1, hi� kesi�im yoksa 2 d�nd�r�r.
    int kesisim(const Daire& digerDaire) const;
    // Dairenin merkezi ve yar��ap�n� String halinde d�nd�ren metot.
    string toString() const;
    void yazdir() const;
};

