#ifndef HISTORY_H
#define HISTORY_H

#include "multiplier.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

struct Round{
    int mines;
    int gemsRevealed;
    string wager;
    string multiplier;
    string payout;

};

class History {
private:

    Multiplier* multiplier; // Pointer to the multiplier class
    std::vector<Round> rounds;

    sf::Font font;
    sf::Text headerGems;
    sf::Text headerMultiplier;
    sf::Text headerPayout;
    sf::Text headerMines;
    sf::Text headerWager;




public:
    History(Multiplier* mult);
    void displayHistory(sf::RenderWindow& window);
    void AddRound(int numberOfMines, int gemsRevealed, double wager, double payout, double multiplier);


};


#endif //HISTORY_H
