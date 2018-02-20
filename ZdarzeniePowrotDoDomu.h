//
// Created by RAFAŁ on 2017-02-16.
//

#ifndef RUCHDROGOWY_ZDARZENIEPOWROTDODOMU_H
#define RUCHDROGOWY_ZDARZENIEPOWROTDODOMU_H

class Osoba;
class Przystanek;

#include "Zdarzenie.h"

class ZdarzeniePowrotDoDomu : public Zdarzenie {

protected:
    Osoba* osoba;

public:
    ZdarzeniePowrotDoDomu() = delete;
    ZdarzeniePowrotDoDomu(Czas*, Symulacja*, Osoba*);
    ~ZdarzeniePowrotDoDomu() = default;
    ZdarzeniePowrotDoDomu(const ZdarzeniePowrotDoDomu&) = delete;
    ZdarzeniePowrotDoDomu & operator=(const ZdarzeniePowrotDoDomu &) = delete;

    void wykonajSie() override;
    std::string opisZdarzenia() const override;

};


#endif //RUCHDROGOWY_ZDARZENIEPOWROTDODOMU_H
