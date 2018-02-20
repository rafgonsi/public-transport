//
// Created by RAFAŁ on 2017-02-10.
//

#ifndef RUCHDROGOWY_UCZEN_H
#define RUCHDROGOWY_UCZEN_H



#include "Osoba.h"

class Uczen : public Osoba{

public:
    Uczen() = delete;
    Uczen(Czas *czas, Miasto *miasto);
    Uczen(Uczen&) = delete;
    virtual ~Uczen();
    Uczen & operator=(const Uczen &) = delete;
    std::string kimJestem() const override; // zwraca string "Uczen"
    std::string dokadChodzi() const override; // zwraca string "do szkoly"


};


#endif //RUCHDROGOWY_UCZEN_H
