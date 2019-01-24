#include <cstdlib>
#include <algorithm>
#include "SkatGame.h"

SkatGame::SkatGame() {
    for (unsigned int i = 0; i <= 3; i++) {
        for (unsigned int j = 0; j <= 7; j++) {
            deck[i * 8 + j] = Card((Suit)i, (Face)j);
        }
    }
}

void SkatGame::shuffle() {
    size_t randIndex;
    Card temp;

    for (size_t deckIndex = 0; deckIndex < deckSize; deckIndex++) {
        randIndex = rand() % 32;
        temp = Card(deck[deckIndex].getSuit(), deck[deckIndex].getFace());
        deck[deckIndex] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

void SkatGame::deal() {
    for (unsigned int i = 0; i <= 9; i++) {
        player1[i] = deck[3 * i];
        player2[i] = deck[3 * i + 1];
        player3[i] = deck[3 * i + 2];
    }

    skat[0] = deck[30];
    skat[1] = deck[31];

    sort(player1.begin(), player1.end());
    sort(player2.begin(), player2.end());
    sort(player3.begin(), player3.end());
}

string SkatGame::toString() const {
    string game;

    game += "Spieler 1:\n";
    for (unsigned int i = 0; i <= 9; i++) {
        game += player1[i].toString() + ", ";
    }
    game += "\n\n";

    game += "Spieler 2:\n";
    for (unsigned int j = 0; j <= 9; j++) {
        game += player2[j].toString() + ", ";
    }
    game += "\n\n";

    game += "Spieler 3:\n";
    for (unsigned int k = 0; k <= 9; k++) {
        game += player3[k].toString() + ", ";
    }
    game += "\n\n";

    game += "Skat:\n" + skat[0].toString() + ", " + skat[1].toString() + "\n";

    return game;
}

array <Card, skatSize> SkatGame::getSkat() const {
    return skat;
}