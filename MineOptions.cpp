#include "MineOptions.h"
#include "Texture.h"

MineOptions::MineOptions() {
    mineOptionsSprite.setTexture(Texture::GetTexture("minesOption"));
    hovered = 0;
}

void MineOptions::update() {
    // Update wager button states (hover, click, etc.)
}

void MineOptions::draw(sf::RenderWindow& window) {
    window.draw(mineOptionsSprite);
}

void MineOptions::setPosition(float x, float y) {
    mineOptionsSprite.setPosition(x, y);
}
