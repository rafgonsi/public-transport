//
// Created by RAFAŁ on 2017-02-05.
//

#include "Czas.h"

Czas::Czas(int godzina, int minuta) : godzina(godzina), minuta(minuta) {}

std::ostream &operator<<(std::ostream &os, const Czas &czas) {
    os << czas.godzina << ":" << ( (czas.minuta < 10) ? "0" : "" ) << czas.minuta;
    return os;
}

void Czas::operator+=(int liczbaMinut) {
    minuta += liczbaMinut;
    if (minuta >= 60){
        int ileGodzin = minuta / 60;
        minuta -= ileGodzin * 60;
        godzina += ileGodzin;
    }
}

void Czas::operator-=(int liczbaMinut) {
    minuta -= liczbaMinut;
    while (minuta < 0){
        minuta += 60;
        --godzina;
    }
}

bool Czas::operator<(const Czas &rhs) const {
    if (godzina < rhs.godzina)
        return true;
    if (rhs.godzina < godzina)
        return false;
    return minuta < rhs.minuta;
}

bool Czas::operator>(const Czas &rhs) const {
    return rhs < *this;
}

bool Czas::operator<=(const Czas &rhs) const {
    return !(rhs < *this);
}

bool Czas::operator>=(const Czas &rhs) const {
    return !(*this < rhs);
}
