#include "WagerOptions.h"
#include "Texture.h"

WagerOptions::WagerOptions() {
    wagerSprite.setTexture(Texture::GetTexture("wager"));
    halfRect.setSize(sf::Vector2f(55,58));
    double2Rect.setSize(sf::Vector2f(55,58));
    wagerRect.setSize(sf::Vector2f(290,58));
    hover = 0;
}

void WagerOptions::update() {
    // Update wager button states (hover, click, etc.)
}

void WagerOptions::hoverCheck(const sf::Vector2i& mousePos) {
    // Check if mouse is within the bounds of the sprite
    if (wagerSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        if (double2Rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            wagerSprite.setTexture(Texture::GetTexture("wager_double"));
            hover = 3;
        }
        else if (halfRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            wagerSprite.setTexture(Texture::GetTexture("wager_half"));
            hover = 2;
        }
        else {
            wagerSprite.setTexture(Texture::GetTexture("wager_hover"));
            hover = 1;
        }
    }
    else if (hover != 0) {
        wagerSprite.setTexture(Texture::GetTexture("wager"));
        hover = 0;
    }
}

int WagerOptions::isClicked() {
    return hover;
}

void WagerOptions::draw(sf::RenderWindow& window) {
    window.draw(wagerSprite);
}

void WagerOptions::setPosition(float x, float y) {
    wagerSprite.setPosition(x, y);
    halfRect.setPosition(x+290,y);
    double2Rect.setPosition(x+353,y);
    wagerRect.setPosition(x,y);
}

