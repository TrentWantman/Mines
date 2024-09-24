#include "Wallpapers.h"

#include "Texture.h"
#include <iostream>

Wallpapers::Wallpapers() {
    // baseWallPaper.setTexture(Texture::GetTexture("1"));
    // baseWallPaper.setPosition(450,0);
    // phoneAFriendWallPaper.setTexture(Texture::GetTexture("2"));
    // phoneAFriendWallPaper.setPosition(450,0);
    // imNotLeavingWallPaper.setTexture(Texture::GetTexture("3"));
    // imNotLeavingWallPaper.setPosition(450,0);
    // babyYourARichManWallPaper.setTexture(Texture::GetTexture("4"));
    // babyYourARichManWallPaper.setPosition(450,0);
    // babyYourOnFireWallPaper.setTexture(Texture::GetTexture("5"));
    // babyYourOnFireWallPaper.setPosition(450,0);
    // getOutNowWallpaper.setTexture(Texture::GetTexture("6"));
    // getOutNowWallpaper.setPosition(450,0);
    // makeTheRighteousWallpaper.setTexture(Texture::GetTexture("7"));
    // makeTheRighteousWallpaper.setPosition(450,0);
    // theBadEndingsWallpaper.setTexture(Texture::GetTexture("8"));
    // theBadEndingsWallpaper.setPosition(450,0);

    font.loadFromFile("./fonts/ProximaNova.ttc");
    for (int i = 0; i < 6; i++) {
        Wallpaper wallpaper;

        std::string number = std::to_string(i+1);

        wallpaper.sprite.setTexture(Texture::GetTexture(number + "full"));
        wallpaper.sprite.setPosition(450, 0);

        wallpaper.miniSprite.setTexture(Texture::GetTexture(number));
        wallpaper.miniSprite.setPosition(57.78, (float)(i * 70) + 412);
        wallpaper.miniSprite.setScale(0.07f, 0.07f);

        wallpaper.description.setFont(font);
        wallpaper.description.setStyle(sf::Text::Bold);

        if (i == 0) {
            wallpaper.description.setString("1) Welcome to Mines");
        }
        else if (i == 1) {
            wallpaper.description.setString("2) Phone A Friend");
        }
        else if (i == 2) {
            wallpaper.description.setString("3) Im Not Leaving");
        }
        else if (i == 3) {
            wallpaper.description.setString("4) Money Money Money!");
        }
        else if (i == 4) {
            wallpaper.description.setString("5) Go Big or Go Home");
        }
        else if (i == 5) {
            wallpaper.description.setString("6) The Right Thing");
        }

        wallpaper.description.setCharacterSize(18);
        wallpaper.description.setFillColor(sf::Color::White);
        wallpaper.description.setPosition(160, (float)(i * 70) + 430);

        wallPaperMenu.push_back(wallpaper);
    }
    unlockWallPaper(1);
}

void Wallpapers::drawMenu(sf::RenderWindow &window) {
    for (auto& wallpaper : wallPaperMenu) {
        window.draw(wallpaper.miniSprite);
        window.draw(wallpaper.description);
    }
}

void Wallpapers::unlockWallPaper(int number) {
    number--;
    wallPaperMenu[number].unlocked = true;
    currentWallPaper = &wallPaperMenu[number];
    std::string numberString = std::to_string(number+1);
    wallPaperMenu[number].miniSprite.setTexture(Texture::GetTexture(numberString + "full"));
    wallPaperMenu[number].description.setFillColor(sf::Color(0,230,1));
}

void::Wallpapers::clickCheck(const sf::Vector2i& mousePos) {
    for (auto& wallpaper : wallPaperMenu) {
        if(wallpaper.miniSprite.getGlobalBounds().contains(mousePos.x, mousePos.y) && wallpaper.unlocked) {
            currentWallPaper = &wallpaper;
        }
    }
}


