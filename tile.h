#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "texture.h"
using namespace std;

struct tile
{
    sf::Sprite hidden;
    sf::Sprite hover;
    sf::Sprite reveal;
    sf::Sprite gem;
    sf::Sprite mine;

    bool hovered = false;
    bool revealed = false;
    bool hasMine = false;


    //constructor
    tile()
    {
        hidden.setTexture(texture::GetTexture("tile_hidden"));
        hover.setTexture(texture::GetTexture("tile_hover"));
        reveal.setTexture(texture::GetTexture("tile_revealed"));
        gem.setTexture(texture::GetTexture("gem"));
        mine.setTexture(texture::GetTexture("mine"));

    }

    //Set Position Each Loop!
    void SetPosition(float x, float y)
    {
        hidden.setPosition(x, y);
        hover.setPosition(x,y);
        reveal.setPosition(x,y);
        gem.setPosition(x, y);
        mine.setPosition(x,y);
    }

    void HoverChecker(const float& x, const float& y)
    {
        if(this->hidden.getGlobalBounds().contains(x,y))
        {
            hovered = true;
        }
        else
        {
            hovered = false;
        }
    }

    void TileRevealed(const float& x, const float& y)
    {
        if(this->hidden.getGlobalBounds().contains(x,y))
        {
            revealed = true;
        }
    }

};