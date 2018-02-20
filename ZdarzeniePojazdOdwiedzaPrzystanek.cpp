//
// Created by RAFAŁ on 2017-02-13.
//

#include <iostream>
#include "ZdarzeniePojazdOdwiedzaPrzystanek.h"
#include "Pojazd.h"
#include "Przystanek.h"
#include "Symulacja.h"

ZdarzeniePojazdOdwiedzaPrzystanek::ZdarzeniePojazdOdwiedzaPrzystanek(Czas* czas, Symulacja* symulacja,
                                                                     Przystanek* przystanek, Pojazd* pojazd)
        : Zdarzenie(czas, symulacja), przystanek(przystanek), pojazd(pojazd) {}

void ZdarzeniePojazdOdwiedzaPrzystanek::wykonajSie() {
    czasPlynie();
    pojazd->zatrzymajSieNaPrzystanku(przystanek);
    pojazd->wysadzPasazerow();
    Przystanek* nastepnyPrzystanek = pojazd->nastepnyPrzystanek();
    pojazd->zabierzPasazerow();
        if (nastepnyPrzystanek) {
        Czas czasNastepnegoZdarzenia(*czasZdarzenia);
        czasNastepnegoZdarzenia += pojazd->czasMiedzyPrzystankami(przystanek, nastepnyPrzystanek);
        symulacja->dodajZdarzenieDoKolejki(
                new ZdarzeniePojazdOdwiedzaPrzystanek(&czasNastepnegoZdarzenia, symulacja, nastepnyPrzystanek, pojazd));
    } else {
        pojazd->zmienKierunek(); // tramwaj wykonuje nawrót na pętli
        Czas czasNastepnegoZdarzenia(*czasZdarzenia);
        czasNastepnegoZdarzenia += pojazd->dajCzasNaPetli();

        if (czasNastepnegoZdarzenia <= Czas(23,0)){
            symulacja->dodajZdarzenieDoKolejki(
                    new ZdarzeniePojazdOdwiedzaPrzystanek(&czasNastepnegoZdarzenia, symulacja, przystanek, pojazd));
        } else {
            std::cout << *czasZdarzenia << "\t" << *pojazd
                      <<" konczy bieg (czas oczekiwania na petli wynosi "
                      << pojazd->dajCzasNaPetli() << " minut).\n";
        }
    }
}


std::string ZdarzeniePojazdOdwiedzaPrzystanek::opisZdarzenia() const {
    return pojazd->jakiPojazd() + " numerLinii: " + std::to_string(pojazd->dajNumerLinii())
           + " przyjezdza na przystanek " + przystanek->nazwaPrzystanku();
}
