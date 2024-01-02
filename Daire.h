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
    double yaricap;  // Dairenin yarýçapý

public:
    // Merkez (Nokta nesnesi olarak) ve yarýçapý parametre olarak alan yapýcý.
    Daire(const Nokta& m, double r);
    // Baþka bir Daire nesnesi alýp onun bir kopyasýný yeni bir Daire nesnesi olarak oluþturan yapýcý.
    Daire(const Daire& other);
    // Baþka bir Daire nesnesi ve reel bir pozitif x deðeri alarak, parametre olarak alýnan Daire nesnesini yarýçapý x ile çarpýlmýþ olarak kopyalayan yapýcý.
    Daire(const Daire& other, double x);
    // Dairenin alanýný hesaplayan metot.
    double alan() const;
    // Dairenin çevresini hesaplayan metot.
    double cevre() const;
    // Ýki dairenin kesiþim durumunu kontrol eder. Ýç içe ise 0, örtüþüyorsa 1, hiç kesiþim yoksa 2 döndürür.
    int kesisim(const Daire& digerDaire) const;
    // Dairenin merkezi ve yarýçapýný String halinde döndüren metot.
    string toString() const;
    void yazdir() const;
};

