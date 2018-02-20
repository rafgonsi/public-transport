//
// Created by RAFAŁ on 2017-02-06.
//

#ifndef RUCHDROGOWY_MIASTO_H
#define RUCHDROGOWY_MIASTO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "Czas.h"
#include "JazdaBezPrzesiadek.h"

class Przystanek;
class Osoba;
class Pojazd;
class Uniwersytet;
class Teatr;
class CentrumHandlowe;
class Symulacja;

class Miasto {

    friend class Symulacja;

protected:
    int liczbaPracujacych, liczbaStudentow, liczbaArtystow, liczbaUczniow;
    std::vector<Osoba*> osoby;
    int procentStudentowZDwomaKierunkami;
    int procentZmniejszenialiczbabyTramwajowWWeekendy;
    int pojemnoscTramwaju;
    std::vector<Przystanek*> przystanki;
    int liczbaLiniiTramwajowych;
    std::vector < std::vector <Pojazd*> > pojazdy; // pierwszy numeruje linie, drugi tramwaje na tej linii
    std::vector<Uniwersytet*> uniwersytety;
    std::vector<Teatr*> teatry;
    std::vector<CentrumHandlowe*> centraHandlowe;

public:
    Miasto() = delete;
    Miasto(int& liczbaPracujacych, int& liczbaStudentow, int& liczbaArtystow, int& liczbaUczniow,
           int& procentStudentowZDwomaKierunkami, int& procentZmniejszenialiczbabyTramwajowWWeekendy,
           int& pojemnoscTramwaju, int& liczbaLiniiTramwajowych,
           double& prwdpPracujacegoWycieczki, double& prwdpOsobyZakupowWTygodniu, double& prwdTeatrPrac,
           double& prwdTeatrStud, double& prwdTeatrArt, double& prwdTeatrUcz, std::vector<std::string>& nazwyPrzystankow,
           std::vector<int>& liczbaTramwajowNaLinii, std::vector<int>& liczbaPrzystankowNaLinii,
           std::vector<int>& czasOczekiwaniaNaPetli, std::vector<std::vector<int> >& czasMiedzyPrzystankami,
           std::vector<std::vector<std::string> >& przystankiNaLinii, std::vector<std::string>& nazwaUniwersytetu,
           std::vector<std::string>& miejsceUniwersytetu, std::vector<std::string>& nazwaTeatru,
           std::vector<std::string>& miejsceTeatru, std::vector<int>& liczbaFoteliWTeatrze,
           std::vector<std::string>& nazwaCH, std::vector<std::string>& miejsceCH, Czas* czas);
    Miasto(Miasto&) = delete;
    virtual ~Miasto();
    Miasto & operator=(const Miasto &) = delete;
    friend std::ostream &operator<<(std::ostream &os, const Miasto &miasto);

    virtual Przystanek* dajLosowyPrzystanek();
    virtual std::list <int> dajLinieMiedzyPrzystankami(Przystanek*, Przystanek*) const;

};


#endif //RUCHDROGOWY_MIASTO_H
