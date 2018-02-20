//
// Created by RAFAŁ on 2017-02-05.
//

#include <cassert>
#include "Osoba.h"
#include "Budynek.h"
#include "PlanDnia.h"
#include "Pojazd.h"
#include "Przystanek.h"
#include "Czas.h"
#include "Miasto.h"
#include "JazdaBezPrzesiadek.h"


Osoba::Osoba(Czas* czas, Miasto* miasto) : czas(czas), miasto(miasto) {

    dom = miasto->dajLosowyPrzystanek()->dajBudynek();
    obecnyBudynek = dom;
    obecnyPojazd = nullptr;
    obecnyPrzystanek = nullptr;
}

Osoba::~Osoba() {
    while(!trasa.empty()){
        delete trasa.front();
        trasa.pop();
    }
}

void Osoba::dodajBudynekDzialalnosci(Budynek* budynek) {
    budynekDzialalnosci.push_back(budynek);
}

std::ostream &operator<<(std::ostream &os, const Osoba &osoba) {
    os << osoba.kimJestem();
//    os << ", dom: " << *osoba.dom << ". ";
//    for (int i = 0; i < osoba.budynekDzialalnosci.size(); ++i) {
//        os << "BudynekDzialalnosci: " << *osoba.budynekDzialalnosci[i] << ". ";
//    }
    os << ". ObecnyBudynek: ";
    if (osoba.obecnyBudynek){
        os << *osoba.obecnyBudynek;
    }
//    os << ". ObecnyPojazd: ";
//    if (osoba.obecnyPojazd){
//        os << *osoba.obecnyPojazd;
//    }
//    os << ". ObecnyPrzystanek: ";
//    if (osoba.obecnyPrzystanek){
//        os << osoba.obecnyPrzystanek->nazwaPrzystanku();
//    }
//     plany dnia:
//    for (int i = 0; i < 7; ++i) {
//        os << "Dzien " << i <<": " << *osoba.planDnia[i] << ". ";
//    }
    return os;
}

void Osoba::wyjdzZBudynku() {
    if (obecnyBudynek != nullptr){
        obecnyPrzystanek = obecnyBudynek->getPobliskiPrzystanek();
        obecnyBudynek = nullptr;
    }
}

void Osoba::wejdzDoBudynku() {
    obecnyBudynek = obecnyPrzystanek->dajBudynek();
    obecnyPrzystanek = nullptr;
}

void Osoba::jedzNaWybranyPrzystanek(Przystanek* przystanekDocelowy) { //dokończ
    if (obecnyPrzystanek != przystanekDocelowy){
        if (obecnyBudynek != nullptr) {
            wyjdzZBudynku();
        }
        if (obecnyPojazd != nullptr) {
            // tu trzeba ruszyć głową
            // możliwa jest taka sytuacja, że w czasie podróży z kolejki zejdzie zdarzenie,
            // które będzie kazało osobie jechać w inne miejsce
            assert(false &&
                   "Osoba::jedzNaWybranyPrzystanek(Przystanek *)"
                           " Jestes juz w drodze. Co mam zrobic??");
        }
        assert(obecnyPrzystanek && "Osoba::jedzNaWybranyPrzystanek(Przystanek *)"
                " - nie ma obecnegoPrzystanku!!");

        for (int i = 0; i < trasa.size(); ++i) {
            // czyszczenie trasy
            delete trasa.front();
            trasa.pop();
        }
        wyznaczTrase(przystanekDocelowy);
        ustawSieWKolejceNaPrzystanku();
    }
}

void Osoba::ustawSieWKolejceNaPrzystanku() {
    assert(obecnyPrzystanek != nullptr && "Osoba::ustawSieWKolejceNaPrzystanku() - nie wiem na jakim przystanku!");
    obecnyPrzystanek->dodajOsobeDoKolejki(this);
}

void Osoba::wsiadzDoPojazdu(Pojazd* pojazd) {
    // ta metoda wywolywana bedzie przez pojazdy
    obecnyPrzystanek = nullptr;
    obecnyPojazd = pojazd;
}

void Osoba::wysiadzZPojazduNaPrzystanek(Przystanek* przystanek) {
    // ta metoda wywolywana bedzie przez pojazdy
    obecnyPojazd = nullptr;
    obecnyPrzystanek = przystanek;
}

void Osoba::wyznaczTrase(Przystanek* przystanek) {
    std::list <int> listaLinii = miasto->dajLinieMiedzyPrzystankami(obecnyPrzystanek, przystanek);
    if (!listaLinii.empty()){
        trasa.push(new JazdaBezPrzesiadek(listaLinii.front(), obecnyPrzystanek, przystanek));
    } else {
        assert(false && "Osoba::wyznaczTrase() - nie da sie wyznaczyc bezprzesiadkowej trasy miedzy tymi przystankami.");
    }
}

std::queue<JazdaBezPrzesiadek *>& Osoba::dajTrasa() {
    return trasa;
}

PlanDnia* Osoba::getPlanDnia(int dzien) const {
    return planDnia[dzien%7];
}

const std::vector<Budynek *> &Osoba::dajBudynekDzialalnosci() const {
    return budynekDzialalnosci;
}

void Osoba::ustawObecnyBudynek(Budynek* obecnyBudynek) {
    Osoba::obecnyBudynek = obecnyBudynek;
}

void Osoba::ustawObecnyPojazd(Pojazd* obecnyPojazd) {
    Osoba::obecnyPojazd = obecnyPojazd;
}

void Osoba::ustawObecnyPrzystanek(Przystanek* obecnyPrzystanek) {
    Osoba::obecnyPrzystanek = obecnyPrzystanek;
}

Budynek* Osoba::dajDom() const {
    return dom;
}
