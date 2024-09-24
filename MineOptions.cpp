#include "MineOptions.h"
#include "Texture.h"

MineOptions::MineOptions() {
    mineOptionsSprite.setTexture(Texture::GetTexture("splitField"));
    minesRect.setSize(sf::Vector2f(201,60));
    gemsRect.setSize(sf::Vector2f(201,60));
    hover = 0;
}

void MineOptions::update() {
    // Update wager button states (hover, click, etc.)
}

void MineOptions::hoverCheck(const sf::Vector2i& mousePos) {
    // Check if mouse is within the bounds of the sprite
    if (mineOptionsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        if (minesRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            mineOptionsSprite.setTexture(Texture::GetTexture("splitFieldMinesLit"));
            hover = 2;
        }
        else if (gemsRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            mineOptionsSprite.setTexture(Texture::GetTexture("splitFieldGemsLit"));
            hover = 1;
        }
    }
    else if (hover != 0) {
        mineOptionsSprite.setTexture(Texture::GetTexture("splitField"));
        hover = 0;
    }
}

int MineOptions::isClicked() {
    return hover;
}

void MineOptions::draw(sf::RenderWindow& window) {
    window.draw(mineOptionsSprite);
}

void MineOptions::setPosition(float x, float y) {
    mineOptionsSprite.setPosition(x, y);
    minesRect.setPosition(x,y);
    gemsRect.setPosition(x+213,y);
}
