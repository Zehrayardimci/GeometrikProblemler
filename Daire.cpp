#include "Daire.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;
// Merkez ve yarýçapý parametre olarak alarak Daire nesnesini baþlatan yapýcý.
Daire::Daire(const Nokta& m, double r) {
    merkez = m;
    yaricap = r;
}
// Baþka bir Daire nesnesi alýp onun bir kopyasýný yeni bir Daire nesnesi olarak oluþturan yapýcý.
Daire::Daire(const Daire& other) {
    merkez = other.merkez;
    yaricap = other.yaricap;
}
//Baþka bir Daire nesnesi ve reel bir pozitif x deðeri alarak, parametre olarak alýnan Daire nesnesini yarýçapý x ile çarpýlmýþ olarak kopyalayan yapýcý.
Daire::Daire(const Daire& other, double x) {
    merkez = other.merkez;
    yaricap = other.yaricap * x;
}
// Dairenin alanýný hesaplayan metot.
double Daire::alan() const {
    return M_PI * yaricap * yaricap;
}
// Dairenin çevresini hesaplayan metot.
double Daire::cevre() const {
    return 2 * M_PI * yaricap;
}
// Ýki dairenin kesiþim durumunu kontrol eder. Ýç içe ise 0, örtüþüyorsa 1, hiç kesiþim yoksa 2 döndürür.
int Daire::kesisim(const Daire& digerDaire) const {
    double uzaklik = sqrt(pow(merkez.getX() - digerDaire.merkez.getX(), 2) + pow(merkez.getY() - digerDaire.merkez.getY(), 2));

    if (uzaklik > yaricap + digerDaire.yaricap) {
        return 2; // Daireler tamamen ayrýk
    }
    else if (uzaklik <= abs(yaricap - digerDaire.yaricap)) {
        if (yaricap < digerDaire.yaricap) {
            return (uzaklik < digerDaire.yaricap - yaricap) ? 1 : 0; 
        }
        else {
            return (uzaklik < yaricap - digerDaire.yaricap) ? 1 : 0; 
        }
    }
    else {
        return 2; // Daireler kesiþiyor, ancak birbiriyle iç içe deðil
    }
}
// Dairenin merkezi ve yarýçapýný String halinde döndüren metot.
string Daire::toString() const {
    return "Merkez: " + merkez.toString() + ", Yarýçap: " + to_string(yaricap);
}
// toString metodunu kullanarak ekrana direnin bilgilerini yazdýran metot.
void Daire::yazdir() const {
    cout << toString() << endl;
}