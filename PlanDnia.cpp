//
// Created by RAFAŁ on 2017-02-05.
//

#include <cassert>
#include "PlanDnia.h"
#include "Budynek.h"

PlanDnia::PlanDnia() {
    czyMaZajecie = false;
}

PlanDnia::PlanDnia(std::vector<Czas> godzinaRozpoczecia, std::vector<Czas> godzinaZakonczenia,
                   std::vector<Budynek*> budynekZajec)
        : godzinaRozpoczecia(godzinaRozpoczecia), godzinaZakonczenia(godzinaZakonczenia), budynekDzialalnosci(budynekZajec){

    czyMaZajecie = !godzinaRozpoczecia.empty();

    assert(godzinaRozpoczecia.size() == godzinaZakonczenia.size()
           && godzinaRozpoczecia.size() == budynekZajec.size()
           && budynekZajec.size() == godzinaZakonczenia.size()
           && "PlanDnia::PlanDnia(std::vector<Czas> godzinaRozpoczecia, "
                   "std::vector<Czas> godzinaZakonczenia), std::vector<Budynek *> budynekDzialalnosci "
                   "- niezgodne rozmiary argumentow. Wektory musza byc tej samej dlugosci.");
}

std::ostream &operator<<(std::ostream &os, const PlanDnia &planDnia) {
    os << "PlanDnia:: czyMaZajecie: " << planDnia.czyMaZajecie << ". ";
    if(planDnia.czyMaZajecie){
        os << "PLANY NA DZIS: ";
        for (int i = 0; i < planDnia.godzinaRozpoczecia.size(); ++i) {
            os << planDnia.godzinaRozpoczecia[i] << " - " << planDnia.godzinaZakonczenia[i]
               << " - " << *planDnia.budynekDzialalnosci[i] << ". ";
        }
    }
    return os;
}

bool PlanDnia::czyZajeta() const {
    return czyMaZajecie;
}

const std::vector<Czas>& PlanDnia::dajGodzinaRozpoczecia() const {
    return godzinaRozpoczecia;
}

const std::vector<Czas>& PlanDnia::dajGodzinaZakonczenia() const {
    return godzinaZakonczenia;
}

const std::vector<Budynek*>& PlanDnia::dajBudynekDzialalnosci() const {
    return budynekDzialalnosci;
}



