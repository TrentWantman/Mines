#ifndef WALLPAPER_H
#define WALLPAPER_H
#include <SFML/Graphics.hpp>

class Wallpaper {
public:
    Wallpaper();
    sf::Sprite sprite;
    sf::Sprite miniSprite;
    sf::Text description;
    bool unlocked;
};

#endif // WALLPAPER_h
