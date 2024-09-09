#ifndef BETCASHOUT_H
#define BETCASHOUT_H

#include <SFML/Graphics.hpp>

class BetCashout {
public:
    BetCashout();
    void update();
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite cashoutSprite;
    bool hovered;
};

#endif // BETCASHOUT_H
