//
// Created by RAFAŁ on 2017-02-16.
//

#include "ZdarzeniePowrotDoDomu.h"
#include "Przystanek.h"
#include "Symulacja.h"
#include "Osoba.h"
#include "Budynek.h"

ZdarzeniePowrotDoDomu::ZdarzeniePowrotDoDomu(Czas* czasWyjscia, Symulacja* symulacja, Osoba* osoba)
        : Zdarzenie(czasWyjscia, symulacja), osoba(osoba){}

void ZdarzeniePowrotDoDomu::wykonajSie() {
    czasPlynie();
    osoba->jedzNaWybranyPrzystanek(osoba->dajDom()->getPobliskiPrzystanek());
}

std::string ZdarzeniePowrotDoDomu::opisZdarzenia() const {
    return osoba->kimJestem() + " wraca do domu.";
}

