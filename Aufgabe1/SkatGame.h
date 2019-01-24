#pragma once
#include "Card.h"

const static size_t deckSize = 32;
const static size_t playerSize = 10;
const static size_t skatSize = 2;

class SkatGame {
public:
    SkatGame();
    void shuffle();
    void deal();
    std::string toString() const;
    array <Card, skatSize> getSkat() const;

private:
    array <Card, deckSize> deck;
    array <Card, playerSize> player1;
    array <Card, playerSize> player2;
    array <Card, playerSize> player3;
    array <Card, skatSize> skat;
};