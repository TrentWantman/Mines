#include "Tile.h"
#include "Texture.h"

Tile::Tile() : revealed(false), mine(false), hover(false){
    // hiddenSprite.setTexture(Texture::GetTexture("tile_hidden"));
    // hoverSprite.setTexture(Texture::GetTexture("tile_hover"));
    // gemSprite.setTexture(Texture::GetTexture("gem"));
    // mineSprite.setTexture(Texture::GetTexture("mine"));
    tileSprite.setTexture(Texture::GetTexture("tile_hidden"));
}

void Tile::SetPosition(float x, float y) {
    // hiddenSprite.setPosition(x, y);
    // hoverSprite.setPosition(x, y);
    // gemSprite.setPosition(x, y);
    // mineSprite.setPosition(x, y);
    tileSprite.setPosition(x, y);
}
void Tile::hoverCheck(const sf::Vector2i& mousePos) {
    // Check if mouse is within the bounds of the sprite
    if (tileSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        if (!hover) {
            tileSprite.setTexture(Texture::GetTexture("tile_hover"));
            hover = true;
        }
    } else {
        if (hover) {
            // If it was hovered but no longer is, revert to the normal texture
            tileSprite.setTexture(Texture::GetTexture("tile_hidden"));
            hover = false;
        }
    }
}

void Tile::clickCheck(const sf::Vector2i& mousePos) {
    // Check if mouse is within the bounds of the sprite
    if (tileSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        if (!revealed) {
            if (mine) {
                tileSprite.setTexture(Texture::GetTexture("mine"));
            }
            else
                tileSprite.setTexture(Texture::GetTexture("gem"));
            revealed = true;
        }
    }
}

void Tile::draw(sf::RenderWindow& window) {
    window.draw(tileSprite);
}

bool Tile::isRevealed() const {
    return revealed;
}

bool Tile::hasMine() const {
    return mine;
}

void Tile::addMine() {
    mine = true;
}

void Tile::removeMine() {
    mine = false;
}

// const sf::Sprite& Tile::getMineSprite() const {
//     return mineSprite;
// }
//
// const sf::Sprite& Tile::getGemSprite() const {
//     return gemSprite;
// }
//
// const sf::Sprite& Tile::getHiddenSprite() const {
//     return hiddenSprite;
// }
//
// const sf::Sprite& Tile::getHoverSprite() const {
//     return hoverSprite;
// }

void Tile::reveal() {
    revealed = true;
}
