#ifndef WAGEROPTIONS_H
#define WAGEROPTIONS_H

#include <SFML/Graphics.hpp>

class WagerOptions {
public:
    WagerOptions();
    void update();
    void hoverCheck(const sf::Vector2i& mousePos);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);

private:
    sf::Sprite wagerSprite;
    sf::RectangleShape wagerRect;
    sf::RectangleShape halfRect;
    sf::RectangleShape double2Rect;
    int hover;
};

#endif // WAGEROPTIONS_H
