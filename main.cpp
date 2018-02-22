#include <iostream>
#include <ctime>
#include "Symulacja.h"

int main() {

    srand(time(0)); // potrzebne do losowania

    std::string adresPliku =
            R"(C:\Users\rafcik\Desktop\fizyka\Programowanie\C++\Projekt ruch miejski\plik.txt)";

    Symulacja s(adresPliku);
    s.wypisz();
    s.rozpocznij();
    
}