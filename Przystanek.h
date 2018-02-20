//
// Created by RAFAŁ on 2017-02-05.
//

#ifndef RUCHDROGOWY_PRZYSTANEK_H
#define RUCHDROGOWY_PRZYSTANEK_H

#include <ostream>
#include <list>
#include <vector>

class Osoba;
class Miasto;
class Czas;
class Budynek;
class Teatr;
class Uniwersytet;
class CentrumHandlowe;

class Przystanek {

protected:
    std::string nazwa;
    Miasto* miasto;
    Czas* czas;
    Budynek* budynek;
    std::vector <Teatr*> teatry;
    std::vector <Uniwersytet*> uniwersytety;
    std::vector <CentrumHandlowe*> centraHandlowe;
    std::vector <Przystanek*> sasiedniePrzystanki;
    std::list <Osoba*> osobyCzekajaceNaPrzystanku;

public:
    Przystanek() = delete;
    Przystanek(const std::string &nazwa, Miasto *miasto, Czas *czas);
    Przystanek(Przystanek&) = delete;
    virtual ~Przystanek();
    Przystanek & operator=(const Przystanek &) = delete;
    friend std::ostream &operator<<(std::ostream &os, const Przystanek &przystanek);

    const std::string& nazwaPrzystanku() const;
    Budynek* dajBudynek();
    std::list<Osoba*>& dajOsobyCzekajaceNaPrzystanku();
    void dodajUniwersytet(Uniwersytet*);
    void dodajCentrumHandlowe(CentrumHandlowe*);
    void dodajTeatr(Teatr*);
    void dodajSasiedniPrzystanek(Przystanek*);
    void dodajOsobeDoKolejki(Osoba*);

};


#endif //RUCHDROGOWY_PRZYSTANEK_H
