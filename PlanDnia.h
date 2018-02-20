//
// Created by RAFAŁ on 2017-02-05.
//

#ifndef RUCHDROGOWY_PLANDNIA_H
#define RUCHDROGOWY_PLANDNIA_H


#include <vector>
#include <ostream>
#include "Czas.h"

class Budynek;

class PlanDnia {

protected:
    bool czyMaZajecie;
    std::vector <Czas> godzinaRozpoczecia;
    std::vector <Czas> godzinaZakonczenia;
    std::vector <Budynek*> budynekDzialalnosci; // czyli gdzie pracuje, uczy sie, itd

public:
    PlanDnia(); // dzien, w którym nic się nie dzieje
    PlanDnia(std::vector<Czas> godzinaRozpoczecia, // !! nie lepiej tu przesyłać przez referencje?
             std::vector<Czas> godzinaZakonczenia, std::vector<Budynek*> budynekDzialalnosci);
    // trzeba zawrzec tez budynekDzialalnosci, bo jak np. artysta ma 3 miejsca to nie wiadomo,
    // o której godzinie do którego ma jechać. Kolejnosc jest ważna.
    PlanDnia(PlanDnia&) = default; // kopiujemy wskaźnik do budynku, a nie budynek - tak ma być
    virtual ~PlanDnia() = default;
    PlanDnia & operator=(const PlanDnia &) = default;
    friend std::ostream &operator<<(std::ostream &os, const PlanDnia &dnia);

    virtual bool czyZajeta() const;
    virtual const std::vector<Czas>& dajGodzinaRozpoczecia() const;
    virtual const std::vector<Czas>& dajGodzinaZakonczenia() const;
    virtual const std::vector<Budynek*>& dajBudynekDzialalnosci() const;
};


#endif //RUCHDROGOWY_PLANDNIA_H
