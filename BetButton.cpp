#include "BetButton.h"
#include "Texture.h"

BetButton::BetButton() {
    betSprite.setTexture(Texture::GetTexture("bet"));
    hover = false;
}

void BetButton::update() {
    // Update the cashout logic (hover state, animations, etc.)
}

void BetButton::hoverCheck(const sf::Vector2i& mousePos) {
    // Check if mouse is within the bounds of the sprite
    if (betSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        if (!hover) {
            // If not already hovered, change texture to the hover texture
            betSprite.setTexture(Texture::GetTexture("betLit"));
            hover = true;
        }
    } else {
        if (hover) {
            // If it was hovered but no longer is, revert to the normal texture
            betSprite.setTexture(Texture::GetTexture("bet"));
            hover = false;
        }
    }
}

void BetButton::draw(sf::RenderWindow& window) {
    window.draw(betSprite);
}

void BetButton::setPosition(float x, float y) {
    betSprite.setPosition(x, y);
}
