//
// Created by RAFAŁ on 2017-02-10.
//

#ifndef RUCHDROGOWY_TEATR_H
#define RUCHDROGOWY_TEATR_H

#include <string>
#include <ostream>

class Przystanek;

class Teatr {
protected:
    std::string nazwa;
    Przystanek* przystanek;
    int liczbaMiejsc;

public:
    Teatr() = delete;
    Teatr(const std::string &nazwa, Przystanek *przystanek, int liczbaMiejsc);
    Teatr(Teatr&) = delete;
    ~Teatr() = default;
    Teatr & operator=(const Teatr &) = delete;
    friend std::ostream &operator<<(std::ostream &os, const Teatr &teatr);
};


#endif //RUCHDROGOWY_TEATR_H
