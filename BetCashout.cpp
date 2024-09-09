#include "BetCashout.h"
#include "Texture.h"

BetCashout::BetCashout() {
    cashoutSprite.setTexture(Texture::GetTexture("cashout"));
    hovered = false;
}

void BetCashout::update() {
    // Update the cashout logic (hover state, animations, etc.)
}

void BetCashout::draw(sf::RenderWindow& window) {
    window.draw(cashoutSprite);
}
