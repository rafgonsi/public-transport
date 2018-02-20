//
// Created by RAFAŁ on 2017-02-06.
//

#ifndef RUCHDROGOWY_TRAMWAJ_H
#define RUCHDROGOWY_TRAMWAJ_H


#include "Pojazd.h"

class Tramwaj : public Pojazd {

public:

    Tramwaj() = delete;
    Tramwaj(int numerLinii, int czasNaPetli, int ileNasJest, const std::vector<int> &czasyMiedzyPrzystankami,
            const std::vector<Przystanek *> &przystanki, int pojemnosc, Czas *czas, bool kierunek);
    Tramwaj(Tramwaj&) = delete;
    virtual ~Tramwaj() = default;
    Tramwaj & operator=(const Tramwaj&) = delete;

    std::string jakiPojazd() const override;

};


#endif //RUCHDROGOWY_TRAMWAJ_H
