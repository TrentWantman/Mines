#ifndef BANK_H
#define BANK_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Bank {
public:
    Bank();
    void drawBank(sf::RenderWindow& window);
    void clickCheck(const sf::Vector2i& mousePos);
    void UpdateBankOutput();
    void withdrawl(double amount);
    void deposit(double amount);

    double balance;
    sf::Sprite bankBox;
    string bankString;
    sf::Text bankText;
    sf::FloatRect bankTextRect;

};

#endif // BANK_H
