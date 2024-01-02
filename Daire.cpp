#include "Daire.h"
#include<iostream>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

using namespace std;
// Merkez ve yar��ap� parametre olarak alarak Daire nesnesini ba�latan yap�c�.
Daire::Daire(const Nokta& m, double r) {
    merkez = m;
    yaricap = r;
}
// Ba�ka bir Daire nesnesi al�p onun bir kopyas�n� yeni bir Daire nesnesi olarak olu�turan yap�c�.
Daire::Daire(const Daire& other) {
    merkez = other.merkez;
    yaricap = other.yaricap;
}
//Ba�ka bir Daire nesnesi ve reel bir pozitif x de�eri alarak, parametre olarak al�nan Daire nesnesini yar��ap� x ile �arp�lm�� olarak kopyalayan yap�c�.
Daire::Daire(const Daire& other, double x) {
    merkez = other.merkez;
    yaricap = other.yaricap * x;
}
// Dairenin alan�n� hesaplayan metot.
double Daire::alan() const {
    return M_PI * yaricap * yaricap;
}
// Dairenin �evresini hesaplayan metot.
double Daire::cevre() const {
    return 2 * M_PI * yaricap;
}
// �ki dairenin kesi�im durumunu kontrol eder. �� i�e ise 0, �rt���yorsa 1, hi� kesi�im yoksa 2 d�nd�r�r.
int Daire::kesisim(const Daire& digerDaire) const {
    double uzaklik = sqrt(pow(merkez.getX() - digerDaire.merkez.getX(), 2) + pow(merkez.getY() - digerDaire.merkez.getY(), 2));

    if (uzaklik > yaricap + digerDaire.yaricap) {
        return 2; // Daireler tamamen ayr�k
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
        return 2; // Daireler kesi�iyor, ancak birbiriyle i� i�e de�il
    }
}
// Dairenin merkezi ve yar��ap�n� String halinde d�nd�ren metot.
string Daire::toString() const {
    return "Merkez: " + merkez.toString() + ", Yar��ap: " + to_string(yaricap);
}
// toString metodunu kullanarak ekrana direnin bilgilerini yazd�ran metot.
void Daire::yazdir() const {
    cout << toString() << endl;
}