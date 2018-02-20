//
// Created by RAFAŁ on 2017-02-06.
//

#include "Miasto.h"
#include "Przystanek.h"
#include "Uniwersytet.h"
#include "CentrumHandlowe.h"
#include "Teatr.h"
#include "Uczen.h"
#include "Pojazd.h"
#include "Tramwaj.h"

Miasto::Miasto(int &liczbaPracujacych, int &liczbaStudentow, int &liczbaArtystow, int &liczbaUczniow,
               int &procentStudentowZDwomaKierunkami, int &procentZmniejszenialiczbabyTramwajowWWeekendy,
               int &pojemnoscTramwaju, int &liczbaLiniiTramwajowych, // te są na liście inicjalizacyjnej
               //
               double &prwdpPracujacegoWycieczki, double &prwdpOsobyZakupowWTygodniu,
               double &prwdTeatrPrac, double &prwdTeatrStud, double &prwdTeatrArt,
               double &prwdTeatrUcz, std::vector<std::string> &nazwyPrzystankow,
               std::vector<int> &liczbaTramwajowNaLinii, std::vector<int> &liczbaPrzystankowNaLinii,
               std::vector<int> &czasOczekiwaniaNaPetli, std::vector<std::vector<int> > &czasMiedzyPrzystankami,
               std::vector<std::vector<std::string> > &przystankiNaLinii, std::vector<std::string> &nazwaUniwersytetu,
               std::vector<std::string> &miejsceUniwersytetu, std::vector<std::string> &nazwaTeatru,
               std::vector<std::string> &miejsceTeatru, std::vector<int> &liczbaFoteliWTeatrze,
               std::vector<std::string> &nazwaCH, std::vector<std::string> &miejsceCH, Czas *czas)
        : liczbaPracujacych(liczbaPracujacych), liczbaStudentow(liczbaStudentow), liczbaArtystow(liczbaArtystow),
          liczbaUczniow(liczbaUczniow), procentStudentowZDwomaKierunkami(procentStudentowZDwomaKierunkami),
          procentZmniejszenialiczbabyTramwajowWWeekendy(procentZmniejszenialiczbabyTramwajowWWeekendy),
          pojemnoscTramwaju(pojemnoscTramwaju), liczbaLiniiTramwajowych(liczbaLiniiTramwajowych){
        //

    //przystanki
    for (int i = 0; i < nazwyPrzystankow.size(); i++){
        przystanki.push_back(new Przystanek(nazwyPrzystankow[i], this, czas));
    }

    // wpisuje przystankom ich sąsiadów:
    // To przyda się do efektywnego wyszukiwania trasy. Nie zdążyłem jednak zastosować.
    for (int i = 0; i < przystanki.size(); ++i) {
        for (int j = 0; j < przystankiNaLinii.size(); ++j) {
            for (int k = 0; k < przystankiNaLinii[j].size(); ++k) {
                if (przystankiNaLinii[j][k] == przystanki[i]->nazwaPrzystanku()){
                    // znaleźliśmy na liście nazwę naszego przystanku. Patrzymy na jego sąsiadów
                    if (k > 0) {
                    // k = 0 odpowiada petli tramwajowej
                        for (int l = 0; l < przystanki.size(); ++l) {
                            if (przystanki[l]->nazwaPrzystanku() == przystankiNaLinii[j][k-1]){
                                przystanki[i]->dodajSasiedniPrzystanek(przystanki[l]);
                            }
                        }
                    }
                    if (k < przystankiNaLinii[j].size() - 1){
                    // tam jest -1, bo k = przystankiNaLinii[j].size() odpowiada pętli tramwajowej
                        for (int l = 0; l < przystanki.size(); ++l) {
                            if (przystanki[l]->nazwaPrzystanku() == przystankiNaLinii[j][k+1]){
                                przystanki[i]->dodajSasiedniPrzystanek(przystanki[l]);
                            }
                        }
                    }
                }
            }
        }
    }

    //uniwersytety
    for (int i = 0; i < nazwaUniwersytetu.size(); i++){
        for (int j = 0; j < przystanki.size(); j++){
            if (przystanki[j]->nazwaPrzystanku() == miejsceUniwersytetu[i]){
                uniwersytety.push_back(new Uniwersytet(nazwaUniwersytetu[i], przystanki[j]));
                przystanki[j]->dodajUniwersytet(uniwersytety.back());
                break;
            }
        }
    }

    //centra handlowe
    for (int i = 0; i < nazwaCH.size(); i++){
        for (int j = 0; j < przystanki.size(); j++){
            if (przystanki[j]->nazwaPrzystanku() == miejsceCH[i]){
                centraHandlowe.push_back(new CentrumHandlowe(nazwaCH[i], przystanki[j]));
                przystanki[j]->dodajCentrumHandlowe(centraHandlowe.back());
                break;
            }
        }
    }

    //teatry
    for (int i = 0; i < nazwaTeatru.size(); i++){
        for (int j = 0; j < przystanki.size(); j++){
            if (przystanki[j]->nazwaPrzystanku() == miejsceTeatru[i]){
                teatry.push_back(new Teatr(nazwaTeatru[i], przystanki[j], liczbaFoteliWTeatrze[i]));
                przystanki[j]->dodajTeatr(teatry.back());
                break;
            }
        }
    }

    //uczniowie
    for (int i = 0; i < liczbaUczniow; ++i) {
        osoby.push_back(new Uczen(czas, this));
    }

    // przerabiamy wczytaną macierz nazw przystanków na macierz wskaźników do przystanków
    std::vector < std::vector < Przystanek* > > przystankiNaLiniiWsk; // pomocnicze
    for (int j = 0; j < przystankiNaLinii.size(); ++j) {
        przystankiNaLiniiWsk.push_back(std::vector <Przystanek*> (0));
        for (int k = 0; k < przystankiNaLinii[j].size(); ++k) {
            for (int i = 0; i < przystanki.size(); ++i) {
                if (przystankiNaLinii[j][k] == przystanki[i]->nazwaPrzystanku()) {
                    przystankiNaLiniiWsk[j].push_back(przystanki[i]);
                    break;
                }
            }
        }
    }

    // tramwaje:
    for (int i = 0; i < liczbaLiniiTramwajowych; ++i) {
        pojazdy.push_back(std::vector <Pojazd*> (0));
        for (int j = 0; j < liczbaTramwajowNaLinii[i]; ++j) {
            pojazdy[i].push_back(new Tramwaj(i, czasOczekiwaniaNaPetli[i], liczbaTramwajowNaLinii[i],
                                             czasMiedzyPrzystankami[i], przystankiNaLiniiWsk[i],
                                             pojemnoscTramwaju, czas, j % 2 == 0 ));
        }
    }

}

Miasto::~Miasto() {
    for (int i = 0; i < przystanki.size(); i++){
        delete przystanki[i];
    }
    for (int i = 0; i < uniwersytety.size(); i++){
        delete uniwersytety[i];
    }
    for (int i = 0; i < centraHandlowe.size(); i++){
        delete centraHandlowe[i];
    }
    for (int i = 0; i < teatry.size(); i++){
        delete teatry[i];
    }
    for (int i = 0; i < osoby.size(); ++i) {
        delete osoby[i];
    }
    for (int i = 0; i < pojazdy.size(); ++i) {
        for (int j = 0; j < pojazdy[i].size(); ++j) {
            delete pojazdy[i][j];
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Miasto &miasto) {
    os << "-------------- Miasto -------------\n";
    os << "\t---- Przystanki ----\n";
    for (int i = 0; i < miasto.przystanki.size(); i++){
        os  << *miasto.przystanki[i] << "\n";
    }
    os << "\t---- Uniwersytety ----\n";
    for (int i = 0; i < miasto.uniwersytety.size(); i++){
        os  << *miasto.uniwersytety[i] << "\n";
    }
    os << "\t---- Centra Handlowe ----\n";
    for (int i = 0; i < miasto.centraHandlowe.size(); i++){
        os  << *miasto.centraHandlowe[i] << "\n";
    }
    os << "\t---- Teatry ----\n";
    for (int i = 0; i < miasto.teatry.size(); i++){
        os  << *miasto.teatry[i] << "\n";
    }
    os << "\t---- Osoby ----\n";
    for (int i = 0; i < miasto.osoby.size(); i++){
        os  << *miasto.osoby[i] << "\n";
    }
    os << "\t---- Pojazdy ----\n";
    for (int i = 0; i < miasto.pojazdy.size(); i++){
        for (int j = 0; j < miasto.pojazdy[i].size(); ++j) {
            os << *miasto.pojazdy[i][j] << "\n";
        }
    }
    return os;
}

Przystanek* Miasto::dajLosowyPrzystanek() {
    int los;
    los = rand() % przystanki.size();
    return przystanki[los];
}

std::list<int> Miasto::dajLinieMiedzyPrzystankami(Przystanek* poczatkowy, Przystanek* koncowy) const {
    std::list<int> wynik;
    for (int i = 0; i < pojazdy.size(); ++i) {
        bool czyJestPoczatkowy = false, czyJestKoncowy = false;
        if (!pojazdy[i].empty()){
            for (int j = 0; j < pojazdy[i][0]->dajPrzystanki().size(); ++j) {
                if (poczatkowy == pojazdy[i][0]->dajPrzystanki()[j]){
                    czyJestPoczatkowy = true;
                }
                if (koncowy == pojazdy[i][0]->dajPrzystanki()[j]){
                    czyJestKoncowy = true;
                }
                if (czyJestPoczatkowy && czyJestKoncowy){
                    wynik.push_back(i);
                    break;
                }
            }
        }
    }
    return wynik;
}

// // to jest implementacja w przypadku, gdy w mieście wszędzie można dojechać bez przesiadek
// // zdecydowanie nie jest optymalna - nie uwzględnia np. aktualnego czasu
// // nie uwzględnia też zmian w kursowaniu tramwajów w weekendy :(
//std::queue<JazdaBezPrzesiadek *> Miasto::wyznaczTrase(Przystanek* start, Przystanek* meta, Czas termin) {
//    // wersja bardzo minimalistyczna, w której osoba po prostu wybiera przypadkowy tramwaj
//    JazdaBezPrzesiadek* jazda = new JazdaBezPrzesiadek(rand() % liczbaLiniiTramwajowych, start, meta);
//    std::queue<JazdaBezPrzesiadek *> wynik;
//    wynik.push(jazda);
//    return wynik;
//
////    int najkrotszyCzas = 1440; // liczba minut w dobie
////    int najszybszaLinia = -1;
////    int najszybszyPojazdLinii = -1;
////    Czas najpozniejszyOdjazd(6,0); // bedziemy szukać najpóźniejszego czasu odjazdu
////    for (int i = 0; i < pojazdy.size(); ++i) {
////        int coIleJezdzi = pojazdy[i].front()->coIleJezdzi(pojazdy[i].front()->ileJezdzi());
////        int czasMiedzyPrzystankami = std::min(pojazdy[i].front()->czasMiedzyPrzystankami(start, meta),
////                                              pojazdy[i].front()->czasMiedzyPrzystankami(meta, start));
////        if (najkrotszyCzas > coIleJezdzi + czasMiedzyPrzystankami){
////            najkrotszyCzas = coIleJezdzi + czasMiedzyPrzystankami;
////            najszybszaLinia = i;
////        }
////    }
////    bool kierunek = (pojazdy[najszybszaLinia].front()->numerPrzystanku(start)
////                     < pojazdy[najszybszaLinia].front()->numerPrzystanku(meta));
////    int czasOkrazenia = pojazdy[najszybszaLinia].front()->czasMiedzyPrzystankami(start, meta)
////                        + pojazdy[najszybszaLinia].front()->czasMiedzyPrzystankami(meta, start);
////    int czasZPetliDoStartu;
////    if(kierunek){
////        Przystanek* petla = pojazdy[najszybszaLinia].front()->dajPrzystanekPoczatkowy();
////        czasZPetliDoStartu = pojazdy[najszybszaLinia][0]->czasMiedzyPrzystankami(petla, start);
////    } else {
////        Przystanek* petla = pojazdy[najszybszaLinia].front()->dajPrzystanekKoncowy();
////        czasZPetliDoStartu = pojazdy[najszybszaLinia][1]->czasMiedzyPrzystankami(petla, start);
////    }
////    for (int j = 0; j < pojazdy[najszybszaLinia].size(); ++j) {
////        if (pojazdy[najszybszaLinia][j]->isKierunek() != kierunek){
////            continue;
////        }
////
////    }
//}
