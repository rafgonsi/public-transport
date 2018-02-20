//
// Created by RAFAŁ on 2017-02-13.
//

#ifndef RUCHDROGOWY_POROWNYWANIEZDARZEN_H
#define RUCHDROGOWY_POROWNYWANIEZDARZEN_H

class Zdarzenie;

class PorownywanieZdarzen {

    // porownywanie wskaznikow do zdarzen dziala odwrotnie na potrzeby kolejki priorytetowej
    // wskaźnik do zdarzenia wcześniejszego jest większy tu od wsk do zd późniejszego
public:
    bool operator()(Zdarzenie*, Zdarzenie*);

};


#endif //RUCHDROGOWY_POROWNYWANIEZDARZEN_H
