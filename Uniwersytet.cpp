//
// Created by RAFAŁ on 2017-02-10.
//

#include "Uniwersytet.h"
#include "Przystanek.h"
Uniwersytet::Uniwersytet(const std::string &nazwa, Przystanek *przystanek) : nazwa(nazwa), przystanek(przystanek) {}

std::ostream &operator<<(std::ostream &os, const Uniwersytet &uniwersytet) {
    os << "Uniwersytet " << uniwersytet.nazwa << ". Lokalizacja: " << uniwersytet.przystanek->nazwaPrzystanku();
    return os;
}
