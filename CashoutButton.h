#ifndef CASHOUTBUTTON_H
#define CASHOUTBUTTON_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

class CashoutButton {
public:
    CashoutButton();
    void update();
    void hoverCheck(const sf::Vector2i& mousePos);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);

//private:
    sf::Sprite cashoutSprite;
    bool hover;
};

#endif // BETCASHOUT_H
