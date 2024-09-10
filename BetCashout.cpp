#include "BetCashout.h"
#include "Texture.h"

BetCashout::BetCashout() {
    cashoutSprite.setTexture(Texture::GetTexture("bet"));
    hover = false;
}

void BetCashout::update() {
    // Update the cashout logic (hover state, animations, etc.)
}

void BetCashout::hoverCheck(const sf::Vector2i& mousePos, GameState gameState) {
    // Check if mouse is within the bounds of the sprite
    if (cashoutSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        if (!hover) {
            // If not already hovered, change texture to the hover texture
            cashoutSprite.setTexture(Texture::GetTexture("cashoutLit"));
            hover = true;
        }
    } else {
        if (hover) {
            // If it was hovered but no longer is, revert to the normal texture
            cashoutSprite.setTexture(Texture::GetTexture("cashout"));
            hover = false;
        }
    }
}

void BetCashout::draw(sf::RenderWindow& window) {
    window.draw(cashoutSprite);
}

void BetCashout::setPosition(float x, float y) {
    cashoutSprite.setPosition(x, y);
}
