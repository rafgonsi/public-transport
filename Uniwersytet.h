//
// Created by RAFAŁ on 2017-02-10.
//

#ifndef RUCHDROGOWY_UNIWERSYTET_H
#define RUCHDROGOWY_UNIWERSYTET_H

#include <string>
#include <ostream>

class Przystanek;

class Uniwersytet {

protected:
    std::string nazwa;
    Przystanek* przystanek;

public:
    Uniwersytet() = delete;
    Uniwersytet(const std::string &nazwa, Przystanek *przystanek);
    Uniwersytet(Uniwersytet&) = delete;
    virtual ~Uniwersytet() = default;
    Uniwersytet & operator=(const Uniwersytet &) = delete;
    friend std::ostream &operator<<(std::ostream &os, const Uniwersytet &uniwersytet);

};


#endif //RUCHDROGOWY_UNIWERSYTET_H
