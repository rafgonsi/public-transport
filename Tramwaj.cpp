//
// Created by RAFAŁ on 2017-02-06.
//

#include "Tramwaj.h"

Tramwaj::Tramwaj(int numerLinii, int czasNaPetli, int ileNasJest, const std::vector<int> &czasyMiedzyPrzystankami,
                 const std::vector<Przystanek *> &przystanki, int pojemnosc, Czas *czas, bool kierunek)
        : Pojazd(numerLinii, czasNaPetli, ileNasJest, czasyMiedzyPrzystankami, przystanki, pojemnosc, czas, kierunek) {}

std::string Tramwaj::jakiPojazd() const {
    return "Tramwaj";
}
