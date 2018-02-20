//
// Created by RAFAŁ on 2017-02-10.
//

#include "CentrumHandlowe.h"
#include "Przystanek.h"

CentrumHandlowe::CentrumHandlowe(const std::string &nazwa, Przystanek *przystanek)
        : nazwa(nazwa), przystanek(przystanek) {}

std::ostream &operator<<(std::ostream &os, const CentrumHandlowe &centrumHandlowe) {
    os << "CentrumHandlowe " << centrumHandlowe.nazwa << ". Lokalizacja: " << centrumHandlowe.przystanek->nazwaPrzystanku();
    return os;
}
