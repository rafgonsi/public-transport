//
// Created by RAFAŁ on 2017-02-13.
//

#ifndef RUCHDROGOWY_ZDARZENIE_H
#define RUCHDROGOWY_ZDARZENIE_H

#include <ostream>

class Czas;
class Symulacja;

class Zdarzenie {

protected:
    Czas* czasZdarzenia;
    Symulacja* symulacja;

public:
    Zdarzenie() = delete;
    Zdarzenie(Czas*, Symulacja*);
    Zdarzenie(const Zdarzenie&) = delete;
    virtual ~Zdarzenie();
    Zdarzenie & operator=(const Zdarzenie &) = delete;
    friend std::ostream &operator<<(std::ostream &os, const Zdarzenie &zdarzenie);

    virtual Czas* podajCzasZdarzenia() const;
    virtual void wykonajSie() = 0;
    virtual std::string opisZdarzenia() const = 0;
    virtual void czasPlynie(); // zmienia czas symulacji - jak z kolejki schodzi zdarzenie z czasem np. 12:15
    // to w symulacji też ma ustawić się czas 12:15

};


#endif //RUCHDROGOWY_ZDARZENIE_H
