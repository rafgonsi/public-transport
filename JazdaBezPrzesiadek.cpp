//
// Created by RAFAŁ on 2017-02-05.
//

#include "JazdaBezPrzesiadek.h"
#include "Przystanek.h"

JazdaBezPrzesiadek::JazdaBezPrzesiadek(int nrLinii, Przystanek *wejscie, Przystanek *wyjscie)
        : nrLinii(nrLinii), wejscie(wejscie), wyjscie(wyjscie) {}


int JazdaBezPrzesiadek::dajNrLinii() const {
    return nrLinii;
}

Przystanek *JazdaBezPrzesiadek::dajWejscie() const {
    return wejscie;
}

Przystanek *JazdaBezPrzesiadek::dajWyjscie() const {
    return wyjscie;
}
