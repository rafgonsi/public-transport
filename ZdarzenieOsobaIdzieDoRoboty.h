//
// Created by RAFAŁ on 2017-02-15.
//

// Zdarzenie wysyła studenta na uczelnię, ucznia do szkoły, pracowników do pracy.

#ifndef RUCHDROGOWY_ZDARZENIEOSOBAIDZIEDOROBOTY_H
#define RUCHDROGOWY_ZDARZENIEOSOBAIDZIEDOROBOTY_H


#include "Zdarzenie.h"

class Osoba;
class Przystanek;

class ZdarzenieOsobaIdzieDoRoboty : public Zdarzenie{

protected:
    Osoba* osoba;
    Przystanek* przystanek;

public:
    ZdarzenieOsobaIdzieDoRoboty() = delete;
    ZdarzenieOsobaIdzieDoRoboty(Czas*, Symulacja*, Przystanek*, Osoba*);
    virtual ~ZdarzenieOsobaIdzieDoRoboty() = default;
    ZdarzenieOsobaIdzieDoRoboty(const ZdarzenieOsobaIdzieDoRoboty&) = delete;
    ZdarzenieOsobaIdzieDoRoboty & operator=(const ZdarzenieOsobaIdzieDoRoboty &) = delete;

    void wykonajSie() override;
    std::string opisZdarzenia() const override;

};


#endif //RUCHDROGOWY_ZDARZENIEOSOBAIDZIEDOROBOTY_H
