// Skat
// Autor: Suayb Yurdakul
// Datum: 2019-01-24

#include <iostream>
#include "SkatGame.h"
#include "ctime"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    SkatGame spiel = SkatGame();

    for (unsigned int i = 1; i <= 5; i++) {
        spiel.shuffle();
        spiel.deal();
        cout << "------------------------------------------------------------------------------------------------------------------------" << "\n"
            << "Runde " << i << ":" << "\n\n" << spiel.toString()
            << "------------------------------------------------------------------------------------------------------------------------" << "\n";
    }

    unsigned int bubeC = 0;

    for (unsigned int i = 1; i <= 10000; i++) {
        spiel.shuffle();
        spiel.deal();
        if (spiel.getSkat()[0].getFace() == BUBE || spiel.getSkat()[1].getFace() == BUBE) bubeC++;
    }

    cout << "Bei 10000 betrachteten Spielen ist bei " << bubeC << " Spielen mindesten ein Bube im Skat." << endl;
    cout << (float)bubeC / 100 << " Prozent der Skat-Blaetter enthalten mindestens einen Buben im Skat." << endl << endl;

    bubeC = 0;

    for (unsigned int i = 1; i <= 10000; i++) {
        spiel.shuffle();
        spiel.deal();
        if (spiel.getSkat()[0].getFace() == BUBE && spiel.getSkat()[1].getFace() == BUBE) bubeC++;
    }

    cout << "Bei 10000 betrachteten Spielen sind bei " << bubeC << " Spielen genau zwei Buben im Skat." << endl;
    cout << (float)bubeC / 100 << " Prozent der Skat-Blaetter enthalten genau zwei Buben im Skat." << endl << endl;
}