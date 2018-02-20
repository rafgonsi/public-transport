//
// Created by RAFAŁ on 2017-02-05.
//

#ifndef RUCHDROGOWY_CZAS_H
#define RUCHDROGOWY_CZAS_H


#include <ostream>

class Czas {

protected:
    int godzina;
    int minuta;

public:
    Czas(int godzina = 0, int minuta = 0);
    Czas(const Czas&) = default;
    virtual ~Czas() = default;
    Czas & operator=(const Czas& czas) = default;
    friend std::ostream &operator<<(std::ostream &os, const Czas &czas);
    void operator+=(int);
    void operator-=(int);
    bool operator<(const Czas &) const;
    bool operator>(const Czas &) const;
    bool operator<=(const Czas &) const;
    bool operator>=(const Czas &) const;

};


#endif //RUCHDROGOWY_CZAS_H

