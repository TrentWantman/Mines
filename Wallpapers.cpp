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

    for (int i = 0; i < 8; i++) {
        Wallpaper wallpaper;
        std::string number = std::to_string(i+1);
        wallpaper.sprite.setTexture(Texture::GetTexture(number + "full"));
        wallpaper.miniSprite.setTexture(Texture::GetTexture(number));
        wallpaper.sprite.setPosition(450, 0);
        wallpaper.miniSprite.setPosition(57.78, (float)(i * 54) + 412);
        wallpaper.miniSprite.setScale(0.054f, 0.054f);
        wallPaperMenu.push_back(wallpaper);
    }
    unlockWallPaper(1);
}

void Wallpapers::drawMenu(sf::RenderWindow &window) {
    for (auto& wallpaper : wallPaperMenu) {
        // if(wallpaper.unlocked) {
             window.draw(wallpaper.miniSprite);
        // }
    }
}

void Wallpapers::unlockWallPaper(int number) {
    number--;
    wallPaperMenu[number].unlocked = true;
    currentWallPaper = &wallPaperMenu[number];
    std::string numberString = std::to_string(number+1);
    wallPaperMenu[number].miniSprite.setTexture(Texture::GetTexture(numberString + "full"));
}

void::Wallpapers::clickCheck(const sf::Vector2i& mousePos) {
    for (auto& wallpaper : wallPaperMenu) {
        if(wallpaper.miniSprite.getGlobalBounds().contains(mousePos.x, mousePos.y) && wallpaper.unlocked) {
            currentWallPaper = &wallpaper;
        }
    }
}


