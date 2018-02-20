//
// Created by RAFAŁ on 2017-02-06.
//

#ifndef RUCHDROGOWY_BUDYNEK_H
#define RUCHDROGOWY_BUDYNEK_H

#include <ostream>

class Przystanek;

class Budynek {

protected:
    std::string nazwa;
    Przystanek* pobliskiPrzystanek;

public:
    Budynek() = delete;
    Budynek(Przystanek*);
    Budynek(Budynek&) = default;
    virtual ~Budynek() = default;
    Budynek & operator=(const Budynek &) = default;
    friend std::ostream &operator<<(std::ostream &os, const Budynek &budynek);

    virtual std::string getNazwa() const;
    virtual Przystanek *getPobliskiPrzystanek() const;
};


#endif //RUCHDROGOWY_BUDYNEK_H
