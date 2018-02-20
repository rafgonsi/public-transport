//
// Created by RAFAŁ on 2017-02-10.
//

#include "Uczen.h"
#include "Miasto.h"
#include "Przystanek.h"
#include "PlanDnia.h"
#include "Czas.h"

Uczen::Uczen(Czas *czas, Miasto *miasto) : Osoba(czas, miasto) {

    dodajBudynekDzialalnosci(miasto->dajLosowyPrzystanek()->dajBudynek()); // czyli szkoła

    // plan dnia - uczen ma lekcje zawsze na 8. Trwaja 4-9 godzin. Od poniedzialku do piatku.

    // w tej klasie te vectory beda zawieraly tylko jeden element, wiec to raczej komplikowanie kodu,
    // natomiast w innych podklasach Osoby, wektory beda juz zawieraly kilka elementow i wowczas
    // poslugiwanie sie wektorami bedzie sensowne
    std::vector <Czas> poczatekLekcji;
    poczatekLekcji.push_back(Czas(8,0));
    for (int i = 0; i < 5; ++i) {
        int los;
        los = 240 + rand() % 301; // czyli 240 <= los <= 540 (czas w minutach)
        Czas koniec(8,0);
        koniec += los;
        std::vector <Czas> koniecLekcji;
        koniecLekcji.push_back(koniec);
        planDnia[i] = new PlanDnia(poczatekLekcji, koniecLekcji, budynekDzialalnosci);
    }
    planDnia[5] = new PlanDnia; // sobota
    planDnia[6] = new PlanDnia; // niedziela
}

Uczen::~Uczen() {
    for (int i = 0; i < 7; ++i) {
        delete planDnia[i];
    }
}

std::string Uczen::kimJestem() const {
    return "Uczen";
}

std::string Uczen::dokadChodzi() const {
    return "do szkoly";
}
