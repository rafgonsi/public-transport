//
// Created by RAFAŁ on 2017-02-06.
//

#include "Budynek.h"
#include "Przystanek.h"

Budynek::Budynek(Przystanek *pobliskiPrzystanek) : pobliskiPrzystanek(pobliskiPrzystanek) {}

std::ostream &operator<<(std::ostream &os, const Budynek &budynek) {
    os << "Budynek przy " << budynek.pobliskiPrzystanek->nazwaPrzystanku();
    return os;
}

std::string Budynek::getNazwa() const {
    return nazwa;
}

Przystanek *Budynek::getPobliskiPrzystanek() const {
    return pobliskiPrzystanek;
}
