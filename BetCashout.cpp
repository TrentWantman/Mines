#include "BetCashout.h"
#include "Texture.h"

BetCashout::BetCashout() {
    cashoutSprite.setTexture(Texture::GetTexture("bet"));
    hovered = false;
}

void BetCashout::update() {
    // Update the cashout logic (hover state, animations, etc.)
}

void BetCashout::draw(sf::RenderWindow& window) {
    window.draw(cashoutSprite);
}

void BetCashout::setPosition(float x, float y) {
    cashoutSprite.setPosition(x, y);
}
