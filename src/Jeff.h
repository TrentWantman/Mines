#ifndef JEFF_H
#define JEFF_H

#include "Bank.h"
#include "Texture.h"

class Jeff {
public:
    // Constructor now takes a pointer to the bank
    Jeff(Bank* bankRef);

    void borrowMoney();  // Function to increase owedMoney by $100
    void pay();  // Function to reset owedMoney to 0

    int getOwedMoney() const;  // Getter for owedMoney

    sf::Sprite payJeff;
    sf::Sprite askForMoney;
    sf::Sprite jeffBackground;
    sf::Font font;
    sf::Text money;

    void draw(sf::RenderWindow &window);
    int owedMoney;  // Variable to store the money Jeff owes
    Bank* bank;  // Pointer to the Bank object
};

#endif
