//
// Created by RAFAŁ on 2017-02-05.
//

#ifndef RUCHDROGOWY_OSOBA_H
#define RUCHDROGOWY_OSOBA_H


#include <vector>
#include <ostream>
#include <queue>

class Budynek;
class PlanDnia;
class Pojazd;
class Przystanek;
class Czas;
class Miasto;
class JazdaBezPrzesiadek;

class Osoba {

protected:
    Budynek* dom;
    std::vector<Budynek*> budynekDzialalnosci;
    Budynek* obecnyBudynek;
    Pojazd* obecnyPojazd;
    Przystanek* obecnyPrzystanek;
    PlanDnia* planDnia[7];
    Czas* czas;
    Miasto* miasto;
    std::queue <JazdaBezPrzesiadek*> trasa;

public:
    Osoba() = delete;
    Osoba(Czas *czas, Miasto *miasto);
    Osoba(Osoba&) = delete; // osoby są niepowtarzalne
    virtual ~Osoba();
    Osoba & operator=(const Osoba &) = delete;
    friend std::ostream &operator<<(std::ostream &os, const Osoba &osoba);

    virtual void dodajBudynekDzialalnosci(Budynek*);
    virtual std::string kimJestem() const = 0; // np Uczen, Student...
    virtual std::string dokadChodzi() const = 0; // np do szkoły
    void ustawObecnyBudynek(Budynek* obecnyBudynek);
    void ustawObecnyPojazd(Pojazd* obecnyPojazd);
    void ustawObecnyPrzystanek(Przystanek* obecnyPrzystanek);
    Budynek* dajDom() const;
    std::queue<JazdaBezPrzesiadek*> &dajTrasa();
    PlanDnia* getPlanDnia(int) const;
    const std::vector<Budynek *>& dajBudynekDzialalnosci() const;

    virtual void wyjdzZBudynku();
    virtual void wejdzDoBudynku();
    virtual void jedzNaWybranyPrzystanek(Przystanek*);
    virtual void ustawSieWKolejceNaPrzystanku();
    virtual void wsiadzDoPojazdu(Pojazd*); // wywolywane przez pojazd. zmienia tylko stan osoby. Nie zmienia stanu pojazdu,
    virtual void wysiadzZPojazduNaPrzystanek(Przystanek*); // służą jako pomocnicze funkcje, które same nie powinny być wywoływane, a tylko przez pojazdy.

protected:
    virtual void wyznaczTrase(Przystanek*);
};


#endif //RUCHDROGOWY_OSOBA_H
