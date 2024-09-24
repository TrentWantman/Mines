#ifndef WALLPAPERS_H
#define WALLPAPERS_H
#include <SFML/Graphics.hpp>
#include "WallPaper.h"

class Wallpapers {
    public:
    Wallpapers ();

    Wallpaper* currentWallPaper;

    sf::Font font;

    std::vector<Wallpaper> wallPaperMenu;

    void drawMenu(sf::RenderWindow& window);
    void unlockWallPaper(int number);
    void clickCheck(const sf::Vector2i& mousePos);
};

#endif // WALLPAPERS_h
