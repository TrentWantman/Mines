#include "WagerOptions.h"
#include "Texture.h"


WagerOptions::WagerOptions() {
    wagerBar.setTexture(Texture::GetTexture("wagerBar"));
    halfButton.setTexture(Texture::GetTexture("halfButton"));
    doubleButton.setTexture(Texture::GetTexture("doubleButton"));
    wagerBarLit.setTexture(Texture::GetTexture("wagerBarLit"));
    halfButtonLit.setTexture(Texture::GetTexture("halfButtonLit"));
    doubleButtonLit.setTexture(Texture::GetTexture("doubleButtonLit"));

    hover = 0;
}

void WagerOptions::update() {
    // Update wager button states (hover, click, etc.)
}

void WagerOptions::hoverCheck(const sf::Vector2i& mousePos) {
    if (doubleButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        hover = 3;
    }
    else if (halfButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        hover = 2;
    }
    else if(wagerBar.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
        hover = 1;
    }
    else {
        hover = 0;
    }
}

int WagerOptions::isClicked() {
    return hover;
}

void WagerOptions::draw(sf::RenderWindow& window) {
    if (hover == 3){
        window.draw(wagerBar);
        window.draw(halfButton);
        window.draw(doubleButtonLit);
    }
    else if (hover == 2){
        window.draw(wagerBar);
        window.draw(halfButtonLit);
        window.draw(doubleButton);
    }
    else if (hover == 1){
        window.draw(wagerBarLit);
        window.draw(halfButton);
        window.draw(doubleButton);
    }
    else if (hover == 0){
        window.draw(wagerBar);
        window.draw(halfButton);
        window.draw(doubleButton);
    }
}

void WagerOptions::setPosition() {
    wagerBar.setPosition(28.35, 130.61);
    halfButton.setPosition(318.66 ,131.43);
    doubleButton.setPosition(371.16,131.43 );
    wagerBarLit.setPosition(28.35, 130.61);
    halfButtonLit.setPosition(318.66 ,131.43);
    doubleButtonLit.setPosition(371.16,131.43 );
}

