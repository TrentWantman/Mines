#include "Jeff.h"
#include "Bank.h"  // Include the Bank class

// Constructor initializes owedMoney to 0 and stores the Bank reference
Jeff::Jeff(Bank* bankRef) : owedMoney(0), bank(bankRef) {
    font.loadFromFile("../fonts/ProximaNova.ttc");
    money.setFont(font);
    money.setStyle(sf::Text::Bold);
    money.setString("You Owe Jeff: $");
    money.setCharacterSize(19);
    money.setFillColor(sf::Color::White);
    money.setPosition(69.93, 500);
    jeffBackground.setTexture(Texture::GetTexture("jeffScreen"));
    jeffBackground.setPosition(37.67, 416.96);
    payJeff.setTexture(Texture::GetTexture("payJeff"));
    payJeff.setPosition(47.59, 572.68);
    askForMoney.setTexture(Texture::GetTexture("askForMoney"));
    askForMoney.setPosition(46.31, 619.88);
}

// Function to increase owedMoney by $100
void Jeff::borrowMoney() {
    owedMoney += 100;
    bank->deposit(100);
    money.setString("You Owe Jeff: $" + to_string(owedMoney));
    // Access bank here if needed, e.g., bank->withdraw(100);
}

// Function to reset owedMoney to 0
void Jeff::pay() {
    if (bank->balance >= owedMoney){
        bank->withdrawl(owedMoney);
        owedMoney = 0;
    }
    // Access bank here if needed, e.g., bank->deposit(owedMoney);
}

// Getter function to return the current owedMoney
int Jeff::getOwedMoney() const {
    return owedMoney;
}

void Jeff::draw(sf::RenderWindow &window) {

    sf::FloatRect textRect = money.getLocalBounds();

    // Set the origin of the text to its center
    money.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    // Set the position after setting the origin
    money.setPosition(222.24, 540);  // Adjust position as needed

    money.setString("You Owe Jeff: $" + to_string(owedMoney));
    //window.draw(jeffBackground);
    window.draw(money);
    window.draw(payJeff);
    window.draw(askForMoney);
}
