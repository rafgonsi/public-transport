//
// Created by RAFAŁ on 2017-02-06.
//

#ifndef RUCHDROGOWY_POJAZD_H
#define RUCHDROGOWY_POJAZD_H


#include <vector>
#include <list>
#include <ostream>
#include "Czas.h"

class Przystanek;
class Osoba;

class Pojazd {

protected:
    int numerLinii;
    int czasNaPetli;
    int ileNasJest; // ile jest pojazdów tej linii
    bool kierunek; // Jak jedzie? - true - zgodnie z trasą, false - pod prąd
    std::vector <int> czasyMiedzyPrzystankami;
    std::vector <Przystanek*> przystanki;
    Przystanek* aktualnyPrzystanek;
    int pojemnosc;
    std::list<Osoba*> pasazerowie; // wczesniej mialem tu vector
    Czas* czas;

public:
    Pojazd() = delete;
    Pojazd(int numerLinii, int czasNaPetli, int ileNasJest, const std::vector<int>& czasyMiedzyPrzystankami,
           const std::vector<Przystanek*>& przystanki, int pojemnosc, Czas* czas, bool kierunek);
    Pojazd(Pojazd&) = delete;
    virtual ~Pojazd() = default;
    Pojazd & operator=(const Pojazd&) = delete;
    friend std::ostream &operator<<(std::ostream &os, const Pojazd &pojazd);

    int ileJezdzi(int procentZmniejszeniaIchLiczby = 0); // np. w soboty i niedziele mniej
    int coIleJezdzi(int liczbaKursujacych); // z jaką częstotliwością są wysyłane na trasę
    virtual std::string jakiPojazd() const = 0; // np. Tramwaj
    virtual bool czyDojedzie(Przystanek*); // sprawdza czy ten pojazd dojedzie na pewien przystanek
    virtual int numerPrzystanku(Przystanek*); // podaje numer przystanku (w sensie miejsca w wektorze przystanków)
    virtual void wysadzPasazerow();
    virtual void zabierzPasazerow();
    virtual void zatrzymajSieNaPrzystanku(Przystanek*);
    virtual void zmienKierunek(); // na pętli
    virtual Przystanek* nastepnyPrzystanek(); // jaki przystanek jest następny na trasie
    virtual int czasMiedzyPrzystankami(Przystanek*, Przystanek*); // uwzględnia też postój na pętli, jeśli po drodze będzie pętla.
                                                                // Zatem ta metoda nie ejst symetryczna w swoich argumentach
    const std::vector<Przystanek*>& dajPrzystanki() const;
    int dajCzasNaPetli() const;
    int dajNumerLinii() const;
    Przystanek* dajPrzystanekPoczatkowy();
    Przystanek* dajPrzystanekKoncowy();
    void ustawKierunek(bool);
};


#endif //RUCHDROGOWY_POJAZD_H
