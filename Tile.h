#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
public:
    Tile();
    void SetPosition(float x, float y);
    bool isRevealed() const;
    bool hasMine() const;

    const sf::Sprite& getMineSprite() const;
    const sf::Sprite& getGemSprite() const;
    const sf::Sprite& getHiddenSprite() const;
    const sf::Sprite& getHoverSprite() const;

    void reveal();

private:
    bool revealed;
    bool mine;
    sf::Sprite hiddenSprite;
    sf::Sprite hoverSprite;
    sf::Sprite gemSprite;
    sf::Sprite mineSprite;
};

#endif // TILE_H
