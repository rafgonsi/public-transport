//
// Created by RAFAŁ on 2017-02-13.
//

#include <iostream>
#include "Zdarzenie.h"
#include "Czas.h"
#include "Symulacja.h"

Zdarzenie::Zdarzenie(Czas* czas, Symulacja* symulacja)
        : symulacja(symulacja) {
    czasZdarzenia = new Czas(*czas);
}

std::ostream &operator<<(std::ostream &os, const Zdarzenie &zdarzenie) {
    os << *zdarzenie.czasZdarzenia << "\t" << zdarzenie.opisZdarzenia();
    return os;
}

Czas *Zdarzenie::podajCzasZdarzenia() const {
    return czasZdarzenia;
}

void Zdarzenie::czasPlynie() {
    symulacja->zmienCzas(czasZdarzenia);
}

Zdarzenie::~Zdarzenie() {
    delete czasZdarzenia;
}

