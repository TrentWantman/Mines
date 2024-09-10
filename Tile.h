#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
public:
    Tile();
    void SetPosition(float x, float y);
    bool isRevealed() const;
    bool hasMine() const;
    void addMine();
    void removeMine();
    void hoverCheck(const sf::Vector2i& mousePos);
    void clickCheck(const sf::Vector2i& mousePos);
    void draw(sf::RenderWindow& window);

    const sf::Sprite& getMineSprite() const;
    const sf::Sprite& getGemSprite() const;
    const sf::Sprite& getHiddenSprite() const;
    const sf::Sprite& getHoverSprite() const;

    void reveal();

private:
    bool revealed;
    bool mine;
    bool hover;
    sf::Sprite tileSprite;
    // sf::Sprite hiddenSprite;
    // sf::Sprite hoverSprite;
    // sf::Sprite gemSprite;
    // sf::Sprite mineSprite;
};

#endif // TILE_H
