#ifndef BETCASHOUT_H
#define BETCASHOUT_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

class BetCashout {
public:
    BetCashout();
    void update();
    void hoverCheck(const sf::Vector2i& mousePos, GameState gameState);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);

//private:
    sf::Sprite cashoutSprite;
    bool hover;
};

#endif // BETCASHOUT_H
