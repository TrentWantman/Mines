#ifndef WALLPAPERS_H
#define WALLPAPERS_H
#include <SFML/Graphics.hpp>
#include "WallPaper.h"

class Wallpapers {
    public:
    Wallpapers ();

    Wallpaper* currentWallPaper;

    sf::Text wallpaper1;
    sf::Text wallpaper2;
    sf::Text wallpaper3;
    sf::Text wallpaper4;
    sf::Text wallpaper5;
    sf::Text wallpaper6;
    sf::Text wallpaper7;
    sf::Text wallpaper8;

    std::vector<sf::Text> wallpaperTexts;

    std::vector<Wallpaper> wallPaperMenu;

    void drawMenu(sf::RenderWindow& window);
    void unlockWallPaper(int number);
    void clickCheck(const sf::Vector2i& mousePos);
};

#endif // WALLPAPERS_h
