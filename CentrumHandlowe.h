//
// Created by RAFAŁ on 2017-02-10.
//

#ifndef RUCHDROGOWY_CENTRUMHANDLOWE_H
#define RUCHDROGOWY_CENTRUMHANDLOWE_H

#include <ostream>

class Przystanek;

class CentrumHandlowe {

protected:
    std::string nazwa;
    Przystanek* przystanek;

public:
    CentrumHandlowe() = delete;
    CentrumHandlowe(const std::string &nazwa, Przystanek *przystanek);
    CentrumHandlowe(CentrumHandlowe&) = delete;
    virtual ~CentrumHandlowe() = default;
    CentrumHandlowe & operator=(const CentrumHandlowe &) = delete;
    friend std::ostream &operator<<(std::ostream &os, const CentrumHandlowe &centrumHandlowe);

};


#endif //RUCHDROGOWY_CENTRUMHANDLOWE_H
