//
// Created by RAFAŁ on 2017-02-09.
//

#ifndef RUCHDROGOWY_SYMULACJA_H
#define RUCHDROGOWY_SYMULACJA_H

#include <string>
#include <vector>
#include <deque>
#include <queue>
#include "PorownywanieZdarzen.h"

class Miasto;
class Czas;
class Zdarzenie;


class Symulacja {

// Parametry symulacji:
protected:
    int liczbaDni;
    int liczbaPracujacych, liczbaStudentow, liczbaArtystow, liczbaUczniow;
    double prwdpPracujacegoWycieczki; // wyjście z pracy w czasie pracy, żeby coś załatwić
    double prwdpOsobyZakupowWTygodniu; //zakupy po pracy
    int procentStudentowZDwomaKierunkami;
    int procentZmniejszenialiczbabyTramwajowWWeekendy;
    double prwdTeatrPrac, prwdTeatrStud, prwdTeatrArt, prwdTeatrUcz;
    int pojemnoscTramwaju;
    int liczbaMiejsc; // czyli efektywnie liczba przystanków
    std::vector<std::string> nazwyPrzystankow;
    int liczbaLiniiTramwajowych;
    std::vector<int> liczbaTramwajowNaLinii;
    std::vector<int> liczbaPrzystankowNaLinii;
    std::vector<int> czasOczekiwaniaNaPetli;
    std::vector<std::vector<int> > czasMiedzyPrzystankami;
    std::vector<std::vector<std::string> > przystankiNaLinii;
    int liczbaUniwersytetow;
    std::vector<std::string> nazwaUniwersytetu;
    std::vector<std::string> miejsceUniwersytetu;
    int liczbaTeatrow;
    std::vector<std::string> nazwaTeatru;
    std::vector<std::string> miejsceTeatru;
    std::vector<int> liczbaFoteliWTeatrze;
    int liczbaCH;
    std::vector<std::string> nazwaCH;
    std::vector<std::string> miejsceCH;

protected:
    int dzien; // ktory to dzien symulacji
    Miasto* miasto;
    Czas* czas;
    std::priority_queue <Zdarzenie*, std::deque<Zdarzenie*>, PorownywanieZdarzen > kolejkaZdarzen;

public:
    Symulacja() = delete;
    Symulacja(std::string);
    Symulacja(Symulacja&) = delete;
    virtual ~Symulacja();
    Symulacja & operator=(const Symulacja &) = delete;

    void wczytajDane(std::string);
    void wypisz();
    void zmienCzas(Czas*);
    void dodajZdarzenieDoKolejki(Zdarzenie*);

    void rozpocznij();
    void rozpocznijDzien();

};


#endif //RUCHDROGOWY_SYMULACJA_H
