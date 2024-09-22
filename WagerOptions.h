#ifndef WAGEROPTIONS_H
#define WAGEROPTIONS_H

#include <SFML/Graphics.hpp>

class WagerOptions {
public:
    WagerOptions();
    void update();
    void hoverCheck(const sf::Vector2i& mousePos);
    int isClicked();
    void draw(sf::RenderWindow& window);
    void setPosition();

private:
    sf::Sprite wagerBar;
    sf::Sprite halfButton;
    sf::Sprite doubleButton;
    sf::Sprite wagerBarLit;
    sf::Sprite halfButtonLit;
    sf::Sprite doubleButtonLit;


    int hover;
};

#endif // WAGEROPTIONS_H
