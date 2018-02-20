//
// Created by RAFAŁ on 2017-02-06.
//

#include <iostream>
#include "Pojazd.h"
#include "Przystanek.h"
#include "Osoba.h"
#include "JazdaBezPrzesiadek.h"

Pojazd::Pojazd(int numerLinii, int czasNaPetli, int ileNasJest, const std::vector<int> &czasyMiedzyPrzystankami,
               const std::vector<Przystanek*>& przystanki, int pojemnosc, Czas* czas, bool kierunek)
        : numerLinii(numerLinii), czasNaPetli(czasNaPetli), ileNasJest(ileNasJest),
          czasyMiedzyPrzystankami(czasyMiedzyPrzystankami), przystanki(przystanki),
          pojemnosc(pojemnosc), czas(czas), kierunek(kierunek) {

    aktualnyPrzystanek = (kierunek ? przystanki.front() : przystanki.back());
}

int Pojazd::ileJezdzi(int procentZmniejszeniaIchLiczby) {
    // np. mamy liczbę N = 15 i pytamy ile to jest p = 30% z niej. Odpowiedź jest typu int i wynosi tyle, ile zaokrąglenie.
    // Unikam w ten sposób rzutowania
    int wynik = (100 - procentZmniejszeniaIchLiczby) * ileNasJest / 100;
    // możliwe, że poprawna odpowiedź jest większa od tego o 1.
    // Dlatego chcemy sprawdzić cyfrę dziesiątek
    int cyfDz = ((100 - procentZmniejszeniaIchLiczby) * ileNasJest / 10) % 10;
    if (cyfDz >= 5){
        ++wynik;
    }
    return wynik;
}

int Pojazd::coIleJezdzi(int liczbaKursujacych) {
    int czas = czasMiedzyPrzystankami(przystanki.front(),przystanki.back())
               + czasMiedzyPrzystankami(przystanki.back(), przystanki.front());
    // w ten sposob, bo metoda czasMiedzyPrzystankami uwzglednia kierunek jazdy i czasem stalibysmy na petli dwa
    // razy, a czasem w ogole. W tym sposobie przejezdzamy całą trasę stojąc na pętlach dwa razy.
    // Właściwe zaokrąglenie:
    int wynik = czas / liczbaKursujacych;
    int cyfDz = ((10 * czas) / liczbaKursujacych) % 10;
    if (cyfDz >= 5){
        ++wynik;
    }
    return wynik;
}

std::ostream &operator<<(std::ostream &os, const Pojazd &pojazd) {
    os <<  pojazd.jakiPojazd() << " numerLinii: " << pojazd.numerLinii;
//    os << " czasNaPetli: " << pojazd.czasNaPetli << " ileNasJest: "
//       << pojazd.ileNasJest << " kierunek: " << pojazd.kierunek
//       << "\nTrasa: " << pojazd.przystanki[0]->nazwaPrzystanku() << " ";
//    for (int i = 0; i < pojazd.czasyMiedzyPrzystankami.size(); ++i) {
//        os << pojazd.czasyMiedzyPrzystankami[i] << " " << pojazd.przystanki[i+1]->nazwaPrzystanku() << " ";
//    }

//    os << ". aktualnyPrzystanek: " << (pojazd.aktualnyPrzystanek ? pojazd.aktualnyPrzystanek->nazwaPrzystanku() : "brak")
//       << ". Liczba osob w pojezdzie " << pojazd.pasazerowie.size() << ".\n";

//    os << " pojemnosc: " << pojazd.pojemnosc;
    return os;
}

const std::vector<Przystanek*>& Pojazd::dajPrzystanki() const {
    return przystanki;
}

void Pojazd::wysadzPasazerow() {
    for (auto iterator = pasazerowie.begin(), end = pasazerowie.end(); iterator != end; ++iterator) {
        if ((*iterator)->dajTrasa().front()->dajWyjscie() == aktualnyPrzystanek){
            std::cout << *czas << "\t" << (*iterator)->kimJestem() << " wysiada z " << (*this)
                      << " na " << aktualnyPrzystanek->nazwaPrzystanku() << "\n";
            (*iterator)->wysiadzZPojazduNaPrzystanek(aktualnyPrzystanek); // zmiana atrybutów pasazera
            (*iterator)->dajTrasa().pop(); // usuwa z kolejki ten etap podrozy
            iterator = pasazerowie.erase(iterator); // skoro wyszedl, to usuwamy go z listy pasazerow
            --iterator;
        }
    }
}

void Pojazd::zabierzPasazerow() {
    for (auto iterator = aktualnyPrzystanek->dajOsobyCzekajaceNaPrzystanku().begin(),
            end = aktualnyPrzystanek->dajOsobyCzekajaceNaPrzystanku().end();
            iterator != end; ++iterator){
        if (pasazerowie.size() == pojemnosc){
            std::cout << *czas << "\t" << jakiPojazd() << " jest przepelniony, odjazd!\n";
            break; // pojazd jest pelny ludzi - nikogo wiecej nie zabierze
        }
        if ( ((*iterator)->dajTrasa().front()->dajNrLinii() == numerLinii) // nowo dodany warunek ??? wymaga sprawdzenia
                && ((*iterator)->dajTrasa().front()->dajWejscie() == aktualnyPrzystanek)
                && (czyDojedzie((*iterator)->dajTrasa().front()->dajWyjscie())) ){ // drugi warunek - kierunek jazdy zgodny
            std::cout << *czas << "\t" << (*iterator)->kimJestem() << " wsiada do " << (*this)
                      << " na " << aktualnyPrzystanek->nazwaPrzystanku() << "\n";
            (*iterator)->wsiadzDoPojazdu(this); // zmiana atrybutów pasazera
            pasazerowie.push_back(*iterator); // zmienia stan pojazdu (osoba jest teraz na liscie pasazerow)
            iterator = aktualnyPrzystanek->dajOsobyCzekajaceNaPrzystanku().erase(iterator);
            // ^- skoro wyszedl, to usuwamy go z kolejki na przystanku
            --iterator;
        }
    }
}

bool Pojazd::czyDojedzie(Przystanek* cel) {
    int ktoryAktualny = numerPrzystanku(aktualnyPrzystanek);
    int ktoryDocelowy = numerPrzystanku(cel);
    if ( (ktoryDocelowy - ktoryAktualny > 0 && kierunek) || (ktoryDocelowy - ktoryAktualny < 0 && !kierunek)){
        return true;
    } else {
        return false;
    }
}

int Pojazd::numerPrzystanku(Przystanek* przystanek) {
    int numer = -1; // jeśli coś pójdzie nie tak zwraca -1
    for (int i = 0; i < przystanki.size(); ++i) {
        if (przystanki[i] == przystanek){
            numer = i;
            break;
        }
    }
    if (numer == -1){
        std::cerr << "Pojazd::numerPrzystanku - nieprawidlowe uzycie metody. "
                "Prawdopodobnie wybrany przystanek jest poza trasa wybranej linii";
    }
    return numer;
}

void Pojazd::zatrzymajSieNaPrzystanku(Przystanek* cel) {
    aktualnyPrzystanek = cel;

}

Przystanek* Pojazd::nastepnyPrzystanek() {
    int obecnyPrzyst = numerPrzystanku(aktualnyPrzystanek);
    if (kierunek && obecnyPrzyst < przystanki.size() - 1) return przystanki[obecnyPrzyst + 1];
    else if (!kierunek && obecnyPrzyst > 0) return przystanki[obecnyPrzyst - 1];
    else return nullptr;  //to się dzieje np kiedy tramwaj trafia na pętlę tramwajową
}

int Pojazd::czasMiedzyPrzystankami(Przystanek* poczatkowy, Przystanek* koncowy) {
    int pocz = numerPrzystanku(poczatkowy);
    int kon = numerPrzystanku(koncowy);
    if (pocz == kon) return 0;
    else if ((kierunek && pocz < kon) || (!kierunek && pocz > kon)){
        int mniejsza = std::min(pocz, kon), wieksza = std::max(pocz, kon);
        int suma = 0;
        for (int i = mniejsza; i < wieksza; ++i) {
            suma += czasyMiedzyPrzystankami[i];
        }
        return suma;
    } else {
        int suma = 0;
        if(kierunek){
            for (int i = pocz; i < czasyMiedzyPrzystankami.size(); ++i) {
                suma += czasyMiedzyPrzystankami[i];
            }
            suma += czasNaPetli;
            for (int i = kon; i < czasyMiedzyPrzystankami.size(); ++i) {
                suma += czasyMiedzyPrzystankami[i];
            }
        } else {
            for (int i = 0; i < pocz; ++i) {
                suma += czasyMiedzyPrzystankami[i];
            }
            suma += czasNaPetli;
            for (int i = 0; i < kon; ++i) {
                suma += czasyMiedzyPrzystankami[i];
            }
        }
        return suma;
    }
}

void Pojazd::zmienKierunek() {
    kierunek = !kierunek;
}

int Pojazd::dajCzasNaPetli() const {
    return czasNaPetli;
}

void Pojazd::ustawKierunek(bool kierunek) {
    Pojazd::kierunek = kierunek;
}

Przystanek* Pojazd::dajPrzystanekPoczatkowy() {
    return przystanki.front();
}

Przystanek* Pojazd::dajPrzystanekKoncowy() {
    return przystanki.back();
}

int Pojazd::dajNumerLinii() const {
    return numerLinii;
}
