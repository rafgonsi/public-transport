//
// Created by RAFAŁ on 2017-02-15.
//

#include "ZdarzenieOsobaIdzieDoRoboty.h"
#include "Przystanek.h"
#include "Symulacja.h"
#include "Osoba.h"

ZdarzenieOsobaIdzieDoRoboty::ZdarzenieOsobaIdzieDoRoboty(Czas* czasWyjscia, Symulacja* symulacja,
                                                         Przystanek* przystanek, Osoba* osoba)
        : Zdarzenie(czasWyjscia, symulacja), przystanek(przystanek), osoba(osoba){}

void ZdarzenieOsobaIdzieDoRoboty::wykonajSie() {
    czasPlynie();
    osoba->jedzNaWybranyPrzystanek(przystanek);
}

std::string ZdarzenieOsobaIdzieDoRoboty::opisZdarzenia() const {
    return osoba->kimJestem() + " udaje sie " + osoba->dokadChodzi() + ".";
}

