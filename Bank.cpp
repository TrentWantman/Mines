#include "Bank.h"

Bank::Bank() {
    font.loadFromFile("./fonts/ProximaNova.ttc");
    balance = 100;
    bankText.setFont(font);
    bankText.setStyle(sf::Text::Bold);
    bankText.setCharacterSize(18.5);
    bankText.setFillColor(sf::Color::White);
    UpdateBankOutput();
    bankText.setPosition(39.68, 74.37);
    bankBox.setTexture(Texture::GetTexture("bankBox"));
    bankBox.setPosition(28.35,56.98);
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
    //window.draw(bankBox);
    window.draw(bankText);
}
