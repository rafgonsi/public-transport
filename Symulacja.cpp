//
// Created by RAFAŁ on 2017-02-09.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Symulacja.h"
#include "Przystanek.h"
#include "Tramwaj.h"
#include "Miasto.h"
#include "Zdarzenie.h"
#include "Osoba.h"
#include "Czas.h"
#include "ZdarzeniePojazdOdwiedzaPrzystanek.h"
#include "PlanDnia.h"
#include "ZdarzenieOsobaIdzieDoRoboty.h"
#include "Budynek.h"
#include "ZdarzeniePowrotDoDomu.h"

Symulacja::Symulacja(std::string adresPliku){
    wczytajDane(adresPliku);
    dzien = 0;
    czas = new Czas(0,0); // tu środowisko podpowiada mi, że mam błąd i inicjalizuję obiekt
        // klasy abstrakcyjnej. Ale Czas nie jest klasą abstrakcyjną. Ponadto kompilator nie pokazuje tu błędu.
    miasto = new Miasto(liczbaPracujacych, liczbaStudentow, liczbaArtystow, liczbaUczniow,
                        procentStudentowZDwomaKierunkami, procentZmniejszenialiczbabyTramwajowWWeekendy,
                        pojemnoscTramwaju, liczbaLiniiTramwajowych,
                        prwdpPracujacegoWycieczki, prwdpOsobyZakupowWTygodniu, prwdTeatrPrac,
                        prwdTeatrStud, prwdTeatrArt, prwdTeatrUcz, nazwyPrzystankow,
                        liczbaTramwajowNaLinii, liczbaPrzystankowNaLinii,
                        czasOczekiwaniaNaPetli, czasMiedzyPrzystankami,
                        przystankiNaLinii, nazwaUniwersytetu,
                        miejsceUniwersytetu, nazwaTeatru,
                        miejsceTeatru, liczbaFoteliWTeatrze,
                        nazwaCH, miejsceCH, czas);
}

void Symulacja::wczytajDane(std::string adresPliku) {
    std::ifstream plik(adresPliku);
    if (plik.is_open()) {
        std::string linia, slowo;

        getline(plik, linia);
        liczbaDni = stoi(linia);

        getline(plik, linia);
        std::istringstream strumien1(linia);
        strumien1 >> slowo;
        liczbaPracujacych = stoi(slowo);
        strumien1 >> slowo;
        liczbaStudentow = stoi(slowo);
        strumien1 >> slowo;
        liczbaArtystow = stoi(slowo);
        strumien1 >> slowo;
        liczbaUczniow = stoi(slowo);

        getline(plik, linia);
        prwdpPracujacegoWycieczki = stod(linia);

        getline(plik, linia);
        prwdpOsobyZakupowWTygodniu = stod(linia);

        getline(plik, linia);
        procentStudentowZDwomaKierunkami = stoi(linia);

        getline(plik, linia);
        procentZmniejszenialiczbabyTramwajowWWeekendy = stoi(linia);

        getline(plik, linia);
        std::istringstream strumien2(linia);
        strumien2 >> slowo;
        prwdTeatrPrac = stod(slowo);
        strumien2 >> slowo;
        prwdTeatrStud = stod(slowo);
        strumien2 >> slowo;
        prwdTeatrArt = stod(slowo);
        strumien2 >> slowo;
        prwdTeatrUcz = stod(slowo);

        getline(plik, linia);
        pojemnoscTramwaju = stoi(linia);

        getline(plik, linia);
        liczbaMiejsc = stoi(linia);

//        std::vector<std::string> nazwyPrzystankow;

        for (int i = 0; i < liczbaMiejsc; i++) { // nazwy miejsce (czyli nazwy Przystanków)
            getline(plik, linia);
            nazwyPrzystankow.push_back(linia);
        }

        getline(plik, linia);
        liczbaLiniiTramwajowych = stoi(linia);

        przystankiNaLinii.resize(liczbaLiniiTramwajowych);
        czasMiedzyPrzystankami.resize(liczbaLiniiTramwajowych);

        for (int i = 0; i < liczbaLiniiTramwajowych; i++) {
            getline(plik, linia);
            std::vector<std::string> pomocniczy;
            std::istringstream strumien3(linia);
            while (strumien3 >> slowo) {
                pomocniczy.push_back(slowo);
            }
            liczbaTramwajowNaLinii.push_back(stoi(pomocniczy.front()));
            liczbaPrzystankowNaLinii.push_back((pomocniczy.size() - 1) / 2);
            czasOczekiwaniaNaPetli.push_back(stoi(pomocniczy.back()));
            for (int j = 1; j <= (pomocniczy.size() - 3) / 2; j++) {
                przystankiNaLinii[i].push_back(pomocniczy[2 * j - 1]);
                czasMiedzyPrzystankami[i].push_back((stoi(pomocniczy[2 * j])));
            }
            przystankiNaLinii[i].push_back(pomocniczy[pomocniczy.size() - 2]);
        }

        getline(plik, linia);
        liczbaUniwersytetow = stoi(linia);

        for (int i = 0; i < liczbaUniwersytetow; i++) {
            getline(plik, linia);
            std::istringstream strumien3(linia);
            strumien3 >> slowo;
            nazwaUniwersytetu.push_back(slowo);
            strumien3 >> slowo;
            miejsceUniwersytetu.push_back(slowo);
        }

        getline(plik, linia);
        liczbaTeatrow = stoi(linia);

        for (int i = 0; i < liczbaTeatrow; i++) {
            getline(plik, linia);
            std::istringstream strumien3(linia);
            strumien3 >> slowo;
            nazwaTeatru.push_back(slowo);
            strumien3 >> slowo;
            miejsceTeatru.push_back(slowo);
            strumien3 >> slowo;
            liczbaFoteliWTeatrze.push_back(stoi(slowo));
        }

        getline(plik, linia);
        liczbaCH = stoi(linia);

        for (int i = 0; i < liczbaCH; i++) {
            getline(plik, linia);
            std::istringstream strumien3(linia);
            strumien3 >> slowo;
            nazwaCH.push_back(slowo);
            strumien3 >> slowo;
            miejsceCH.push_back(slowo);
        }

        plik.close();
    } else {
        std::cerr << "Plik nie zostal otwarty. Przerywam działanie programu.\n";
        exit(1);
    }
}

void Symulacja::wypisz() {
    std::cout << "-------------- Dane wejsciowe ---------------\n"
              << "Czas trwania symulacji: "<< liczbaDni << " dni.\n"
              << "Liczba osob pracujacych: " << liczbaPracujacych << ".\n"
              << "Liczba studentow: " << liczbaStudentow << ".\n"
              << "Liczba artystow: " << liczbaArtystow << ".\n"
              << "Liczba uczniow: " << liczbaUczniow << ".\n"
              << "Prawdopodobienstwo dla pracujacego wyjazdu w ciagu dnia: " <<prwdpPracujacegoWycieczki << ".\n"
              << "Prawdopodobienstwo dla osoby zakupow w tygodniu: " << prwdpOsobyZakupowWTygodniu << ".\n"
              << "Procent studentow z dwoma kierunkami studiow: " << procentStudentowZDwomaKierunkami << "%.\n"
              << "Procent zmniejszenia liczby tramwajow w weekendy: " << procentZmniejszenialiczbabyTramwajowWWeekendy << "%.\n"
              << "Prawdopodobienstwo pojscia do teatry dla pracujacych: " << prwdTeatrPrac << ".\n"
              << "Prawdopodobienstwo pojscia do teatry dla studentow: " << prwdTeatrStud << ".\n"
              << "Prawdopodobienstwo pojscia do teatry dla artystow: " << prwdTeatrArt << ".\n"
              << "Prawdopodobienstwo pojscia do teatry dla uczniow: " << prwdTeatrUcz << ".\n"
              << "Pojemnosc tramwaju: " << pojemnoscTramwaju << ".\n"
              << "Liczba przystankow " << liczbaMiejsc << ".\n"
              << "Przystanki: ";
    for (int i = 0; i < nazwyPrzystankow.size(); i++){
        std::cout << nazwyPrzystankow[i] << (i != nazwyPrzystankow.size() - 1 ? ", " : ".\n");
    }
    std::cout << "Liczba linii tramwajowych: " << liczbaLiniiTramwajowych << ".\n"
              << "Liczba uniwersytetow: " << liczbaUniwersytetow << ".\n"
              << "Liczba teatrow: " << liczbaTeatrow << ".\n"
              << "Liczba centrow handlowych " << liczbaCH << ".\n";

    std::cout << "-------------- Koniec danych wejsciowych ---------------\n\n";

    std::cout << *miasto << std::endl;

}

Symulacja::~Symulacja() {
    delete miasto;
    delete czas;
}

void Symulacja::zmienCzas(Czas* nowyCzas) {
    *czas = *nowyCzas;
}

void Symulacja::dodajZdarzenieDoKolejki(Zdarzenie* dodawaneZdarzenie) {
    kolejkaZdarzen.push(dodawaneZdarzenie);
}

void Symulacja::rozpocznijDzien() {
    std::cout << "----------------------------------------------\n";
    std::cout << "Dzien " << dzien + 1 << ", "; // w programie numeruję dni od 0.
    switch(dzien % 7){
        case 0:
            std::cout << "poniedzialek.\n";
            break;
        case 1:
            std::cout << "wtorek.\n";
            break;
        case 2:
            std::cout << "sroda.\n";
            break;
        case 3:
            std::cout << "czwartek.\n";
            break;
        case 4:
            std::cout << "piatek.\n";
            break;
        case 5:
            std::cout << "sobota.\n";
            break;
        case 6:
            std::cout << "niedziela.\n";
            break;
    }
    std::cout << "----------------------------------------------\n";
    *czas = Czas(0, 0); // jest północ

    // Wypuszczamy tramwaje:
    for (int i = 0; i < miasto->liczbaLiniiTramwajowych; ++i) {
        int liczbaTramwajowTejLinii // zależy od dnia tygodnia
                = miasto->pojazdy[i][0]->ileJezdzi((dzien % 7 < 5) ? 0 : procentZmniejszenialiczbabyTramwajowWWeekendy);
        Przystanek* poczatekTrasy = miasto->pojazdy[i][0]->dajPrzystanekPoczatkowy();
        Przystanek* koniecTrasy = miasto->pojazdy[i][0]->dajPrzystanekKoncowy();
        int coIleWypuszczac = miasto->pojazdy[i][0]->coIleJezdzi(liczbaTramwajowTejLinii);

        for (int j = 0; j < liczbaTramwajowTejLinii; j += 2) { // kierunek zgodny z trasą
            miasto->pojazdy[i][j]->ustawKierunek(true);
            Czas czasNastepnegoZdarzenia(6,0);
            czasNastepnegoZdarzenia += j * coIleWypuszczac;
            dodajZdarzenieDoKolejki(new ZdarzeniePojazdOdwiedzaPrzystanek(&czasNastepnegoZdarzenia, this, poczatekTrasy,
                                                                          miasto->pojazdy[i][j]));
        }

        for (int j = 1; j < liczbaTramwajowTejLinii; j += 2) { // kierunek pod prąd
            miasto->pojazdy[i][j]->ustawKierunek(false);
            Czas czasNastepnegoZdarzenia(6,0);
            czasNastepnegoZdarzenia += (j - 1) * coIleWypuszczac;
            dodajZdarzenieDoKolejki(new ZdarzeniePojazdOdwiedzaPrzystanek(&czasNastepnegoZdarzenia, this, koniecTrasy,
                                                                          miasto->pojazdy[i][j]));
        }
    }

    // Osoby:
    for (int i = 0; i < miasto->osoby.size(); ++i) {
        //najpierw każda osoba znajduje się w domu
        miasto->osoby[i]->ustawObecnyBudynek(miasto->osoby[i]->dajDom());
        miasto->osoby[i]->ustawObecnyPojazd(nullptr);
        miasto->osoby[i]->ustawObecnyPrzystanek(nullptr);
        // każda osoba wrzuca swoje zaplanowane zdarzenia
        if (!(miasto->osoby[i]->getPlanDnia(dzien)->czyZajeta())){
            continue;
        }
        // potem rozpoczyna swoją działalność np. student studia, uczeń szkołę itd. Tu jest pętla, bo niektórzy
        // mają więcej niż jedną działalność np niektórzy studenci mają dwa kierunki
        for (int j = 0; j < miasto->osoby[i]->getPlanDnia(dzien)->dajGodzinaRozpoczecia().size(); ++j) {
            Czas czasZdarzenia(miasto->osoby[i]->getPlanDnia(dzien)->dajGodzinaRozpoczecia()[j]);
            czasZdarzenia -= 30;
            czasZdarzenia += rand() % 15; // wychodza o roznych godzinach.
            // Oczywiście powinni wychodzić z domu o czasie skorelowanym z ruchem tramwajów,
            // ale brakuje mi czasu, żeby się tym zająć.
            Przystanek* przystanekDzialalnosci = miasto->osoby[i]->dajBudynekDzialalnosci()[j]->getPobliskiPrzystanek();
            dodajZdarzenieDoKolejki(new ZdarzenieOsobaIdzieDoRoboty(&czasZdarzenia, this, przystanekDzialalnosci,
                                                                    miasto->osoby[i]));
        }
        // a po wszystkim wracają do domu (tutaj jeszcze może uda się dołożyć zakupy w przyszłości)
        Czas czasZdarzenia(miasto->osoby[i]->getPlanDnia(dzien)->dajGodzinaZakonczenia().back());
                                                // ^czyli godzina zakończenia ostatniego z zajęć
        dodajZdarzenieDoKolejki(new ZdarzeniePowrotDoDomu(&czasZdarzenia, this, miasto->osoby[i]));
    }

    // Tutaj płynie czas:
    while (!kolejkaZdarzen.empty()){
        Zdarzenie* aktualneZdarzenie = kolejkaZdarzen.top();
        std::cout << *aktualneZdarzenie << "\n";
        aktualneZdarzenie->wykonajSie();
        kolejkaZdarzen.pop();
        delete aktualneZdarzenie;
    }

    ++dzien;
}

void Symulacja::rozpocznij() {
    while(dzien < liczbaDni){ // numerujemy dni od zera - wypisując piszemy dzień 1, choć w programie ma numer 0
        rozpocznijDzien();
    }
    std::cout << "----------------------------------------------\n";
    std::cout << "Symulacja zakonczona.\n";
    std::cout << "----------------------------------------------\n";
}

