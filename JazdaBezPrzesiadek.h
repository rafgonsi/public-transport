//
// Created by RAFAŁ on 2017-02-05.
//

#ifndef RUCHDROGOWY_JAZDABEZPRZESIADEK_H
#define RUCHDROGOWY_JAZDABEZPRZESIADEK_H


class Przystanek;

class JazdaBezPrzesiadek {

protected:
    int nrLinii;
    Przystanek* wejscie;
    Przystanek* wyjscie;

public:
    JazdaBezPrzesiadek() = delete;
    JazdaBezPrzesiadek(int nrLinii, Przystanek *wejscie, Przystanek *wyjscie);
    JazdaBezPrzesiadek(JazdaBezPrzesiadek&) = default;
    virtual ~JazdaBezPrzesiadek() = default; // Nie chcemy przecież usuwać przystanków!
    JazdaBezPrzesiadek &operator=(const JazdaBezPrzesiadek &) = default;

    virtual int dajNrLinii() const;
    virtual Przystanek *dajWejscie() const;
    virtual Przystanek *dajWyjscie() const;

};


#endif //RUCHDROGOWY_JAZDABEZPRZESIADEK_H
