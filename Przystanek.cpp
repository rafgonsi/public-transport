//
// Created by RAFAŁ on 2017-02-05.
//

#include "Przystanek.h"
#include "Osoba.h"
#include "Miasto.h"
#include "Budynek.h"
#include "Uniwersytet.h"
#include "CentrumHandlowe.h"
#include "Teatr.h"
#include "Czas.h"

Przystanek::Przystanek(const std::string &nazwa, Miasto *miasto, Czas *czas)
        : nazwa(nazwa), miasto(miasto), czas(czas) {
    budynek = new Budynek(this);
}

Przystanek::~Przystanek() {
    delete budynek;
}

std::ostream &operator<<(std::ostream &os, const Przystanek &przystanek) {
    os << "Przystanek " << przystanek.nazwa;
//    os << ". Sasiednie przystanki: ";
//    for (int i = 0; i < przystanek.sasiedniePrzystanki.size(); ++i) {
//        os << przystanek.sasiedniePrzystanki[i]->nazwaPrzystanku() << ", ";
//    }
    os << ". Liczba osob w kolejce: " << przystanek.osobyCzekajaceNaPrzystanku.size() << ".";
//    // wypisywanie wszystkiego, co jest na przystanku
//    os << ".\nUniwersytety na tym przystanku:\n";
//    for (int i = 0; i < przystanek.uniwersytety.size(); i++){
//        os << *przystanek.uniwersytety[i] << "\n";
//    }
//    os << "\nCentra handlowe na tym przystanku:\n";
//    for (int i = 0; i < przystanek.centraHandlowe.size(); i++){
//        os << *przystanek.centraHandlowe[i] << "\n";
//    }
//    os << "\nTeatry na tym przystanku:\n";
//    for (int i = 0; i < przystanek.teatry.size(); i++){
//        os << *przystanek.teatry[i] << "\n";
//    }
    return os;
}

const std::string& Przystanek::nazwaPrzystanku() const {
    return nazwa;
}

Budynek* Przystanek::dajBudynek() {
    return budynek;
}

void Przystanek::dodajUniwersytet(Uniwersytet* dodawanyUniwersytet) {
    uniwersytety.push_back(dodawanyUniwersytet);
}

void Przystanek::dodajCentrumHandlowe(CentrumHandlowe* dodawaneCentrumHandlowe) {
    centraHandlowe.push_back(dodawaneCentrumHandlowe);
}

void Przystanek::dodajTeatr(Teatr* dodawanyTeatr) {
    teatry.push_back(dodawanyTeatr);
}

void Przystanek::dodajSasiedniPrzystanek(Przystanek* dodawanyPrzystanek) {
    bool czyJuzJest = false;
    for (int i = 0; i < sasiedniePrzystanki.size(); ++i) {
        if (sasiedniePrzystanki[i] == dodawanyPrzystanek){
            czyJuzJest = true;
            break;
        }
    }
    if (!czyJuzJest){
        sasiedniePrzystanki.push_back(dodawanyPrzystanek);
    }
}

void Przystanek::dodajOsobeDoKolejki(Osoba* osoba) {
    osobyCzekajaceNaPrzystanku.push_back(osoba);
}

std::list<Osoba *> &Przystanek::dajOsobyCzekajaceNaPrzystanku() {
    return osobyCzekajaceNaPrzystanku;
}
