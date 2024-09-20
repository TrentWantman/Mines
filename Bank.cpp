#include "Bank.h"

Bank::Bank() {
    sf::Font font;
    font.loadFromFile("./fonts/ProximaNova.ttc");
    balance = 100;
    bankText.setFont(font);
    bankText.setStyle(sf::Text::Bold);
    UpdateBankOutput();
    bankText.setCharacterSize(20);
    bankText.setFillColor(sf::Color::White);
    bankTextRect = bankText.getGlobalBounds();
    bankText.setOrigin(bankTextRect.width / 2.0f, bankTextRect.height / 2.0f);
    bankText.setPosition(20, 30);
}

void Bank::UpdateBankOutput() {
    ostringstream bankStream;
    bankStream << fixed << setprecision(2) << balance;
    bankText.setString("Bank: $" + bankStream.str());
}

void Bank::withdrawl(double amount) {
    balance -= amount;
    UpdateBankOutput();
}

void Bank::deposit(double amount) {
    balance += amount;
    UpdateBankOutput();
}

void Bank::drawBank(sf::RenderWindow& window) {
    window.draw(bankBox);
    window.draw(bankText);
}
