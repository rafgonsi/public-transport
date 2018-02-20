//
// Created by RAFAŁ on 2017-02-13.
//

#include "PorownywanieZdarzen.h"
#include "Zdarzenie.h"
#include "Czas.h"

bool PorownywanieZdarzen::operator()(Zdarzenie* z1, Zdarzenie* z2) {
    return *z2->podajCzasZdarzenia() < *z1->podajCzasZdarzenia();
}
