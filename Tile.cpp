#include "Tile.h"
#include "Texture.h"

Tile::Tile() : revealed(false), mine(false) {
    hiddenSprite.setTexture(Texture::GetTexture("tile_hidden"));
    hoverSprite.setTexture(Texture::GetTexture("tile_hover"));
    gemSprite.setTexture(Texture::GetTexture("gem"));
    mineSprite.setTexture(Texture::GetTexture("mine"));
}

void Tile::SetPosition(float x, float y) {
    hiddenSprite.setPosition(x, y);
    hoverSprite.setPosition(x, y);
    gemSprite.setPosition(x, y);
    mineSprite.setPosition(x, y);
}

bool Tile::isRevealed() const {
    return revealed;
}

bool Tile::hasMine() const {
    return mine;
}

const sf::Sprite& Tile::getMineSprite() const {
    return mineSprite;
}

const sf::Sprite& Tile::getGemSprite() const {
    return gemSprite;
}

const sf::Sprite& Tile::getHiddenSprite() const {
    return hiddenSprite;
}

const sf::Sprite& Tile::getHoverSprite() const {
    return hoverSprite;
}

void Tile::reveal() {
    revealed = true;
}
