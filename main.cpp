#include <iostream>
#include <ctime>
#include "Symulacja.h"

int main() {

    srand(time(0)); // potrzebne do losowania

    std::string adresPliku = "C:\\projektycpp\\ruchdrogowy\\input2.txt";

    Symulacja s(adresPliku);
    s.wypisz();
    s.rozpocznij();

}