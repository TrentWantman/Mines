#include "CashoutButton.h"
#include "Texture.h"

CashoutButton::CashoutButton() {
    cashoutSprite.setTexture(Texture::GetTexture("cashout"));
    hover = false;
}

void CashoutButton::update() {
    // Update the cashout logic (hover state, animations, etc.)
}

void CashoutButton::hoverCheck(const sf::Vector2i& mousePos) {
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

bool CashoutButton::isClicked() {
    return hover;
}

void CashoutButton::draw(sf::RenderWindow& window) {
    window.draw(cashoutSprite);
}

void CashoutButton::setPosition(float x, float y) {
    cashoutSprite.setPosition(x, y);
}
