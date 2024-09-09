#ifndef MINEOPTIONS_H
#define MINEOPTIONS_H

#include <SFML/Graphics.hpp>

class MineOptions {
public:
    MineOptions();
    void update();
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);

private:
    sf::Sprite mineOptionsSprite;
    int hovered;
};

#endif // WAGEROPTIONS_H
