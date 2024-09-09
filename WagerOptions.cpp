#include "WagerOptions.h"
#include "Texture.h"

WagerOptions::WagerOptions() {
    wagerSprite.setTexture(Texture::GetTexture("wager"));
    hovered = 0;
}

void WagerOptions::update() {
    // Update wager button states (hover, click, etc.)
}

void WagerOptions::draw(sf::RenderWindow& window) {
    window.draw(wagerSprite);
}

void WagerOptions::setPosition(float x, float y) {
    wagerSprite.setPosition(x, y);
}

