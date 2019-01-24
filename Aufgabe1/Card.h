#pragma once
#include <string>
#include <array>

using namespace std;

enum Suit { KARO = 0, HERZ = 1, PIK = 2, KREUZ = 3 };
enum Face { SIEBEN = 0, ACHT = 1, NEUN = 2, ZEHN = 3, BUBE = 4, DAME = 5, KOENIG = 6, ASS = 7 };

class Card {
public:
    Card();
    Card(Suit, Face);
    Suit getSuit() const;
    Face getFace() const;
    std::string toString() const;
    bool operator<(const Card&) const;

private:
    Suit suit;
    Face face;
};