//
// Created by RAFAŁ on 2017-02-10.
//

#include "Teatr.h"
#include "Przystanek.h"

Teatr::Teatr(const std::string &nazwa, Przystanek *przystanek, int liczbaMiejsc)
        : nazwa(nazwa), przystanek(przystanek), liczbaMiejsc(liczbaMiejsc) {}

std::ostream &operator<<(std::ostream &os, const Teatr &teatr) {
    os << "Teatr " << teatr.nazwa << " Lokalizacja: " << teatr.przystanek->nazwaPrzystanku()
       << ". LiczbaMiejsc: " << teatr.liczbaMiejsc;
    return os;
}
