//
// Created by RAFAŁ on 2017-02-13.
//

#ifndef RUCHDROGOWY_ZDARZENIEPOJAZDODWIEDZAPRZYSTANEK_H
#define RUCHDROGOWY_ZDARZENIEPOJAZDODWIEDZAPRZYSTANEK_H


#include <queue>
#include "Zdarzenie.h"

class Przystanek;
class Pojazd;

class ZdarzeniePojazdOdwiedzaPrzystanek : public Zdarzenie{

protected:
    Przystanek* przystanek;
    Pojazd* pojazd;

public:
    ZdarzeniePojazdOdwiedzaPrzystanek() = delete;
    ZdarzeniePojazdOdwiedzaPrzystanek(Czas*, Symulacja*, Przystanek*, Pojazd*);
    virtual ~ZdarzeniePojazdOdwiedzaPrzystanek() = default;
    ZdarzeniePojazdOdwiedzaPrzystanek(const ZdarzeniePojazdOdwiedzaPrzystanek&) = delete;
    ZdarzeniePojazdOdwiedzaPrzystanek & operator=(const ZdarzeniePojazdOdwiedzaPrzystanek &) = delete;

    void wykonajSie() override;
    std::string opisZdarzenia() const override;

};


#endif //RUCHDROGOWY_ZDARZENIEPOJAZDODWIEDZAPRZYSTANEK_H
