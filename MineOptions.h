#ifndef MINEOPTIONS_H
#define MINEOPTIONS_H

#include <SFML/Graphics.hpp>

class MineOptions {
public:
    MineOptions();
    void update();
    void hoverCheck(const sf::Vector2i& mousePos);
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);

private:
    sf::Sprite mineOptionsSprite;
    sf::RectangleShape minesRect;
    sf::RectangleShape gemsRect;
    int hover;
};

#endif // WAGEROPTIONS_H
