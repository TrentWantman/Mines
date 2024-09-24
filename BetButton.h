#ifndef BETBUTTON_H
#define BETBUTTON_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

class BetButton {
public:
    BetButton();
    void update();
    void hoverCheck(const sf::Vector2i& mousePos);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    bool isClicked();

    //private:
    sf::Sprite betSprite;
    bool hover;
};

#endif // BETCASHOUT_H
