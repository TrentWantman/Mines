#ifndef WAGEROPTIONS_H
#define WAGEROPTIONS_H

#include <SFML/Graphics.hpp>

class WagerOptions {
public:
    WagerOptions();
    void update();
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);

private:
    sf::Sprite wagerSprite;
    int hovered;
};

#endif // WAGEROPTIONS_H
