#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "texture.h"
using namespace std;

struct button
{
    sf::Sprite sprite;
    sf::Sprite hover;
    sf::Sprite half;
    sf::Sprite double2;

    sf::RectangleShape wagerRect;
    sf::RectangleShape halfRect;
    sf::RectangleShape double2Rect;

    int hovered = 0;


    //constructor
    button()
    {
        sprite.setTexture(texture::GetTexture("wager"));
        hover.setTexture(texture::GetTexture("wager_hover"));
        half.setTexture(texture::GetTexture("wager_half"));
        double2.setTexture(texture::GetTexture("wager_double"));
        halfRect.setSize(sf::Vector2f(55,58));
        double2Rect.setSize(sf::Vector2f(55,58));
        wagerRect.setSize(sf::Vector2f(290,58));
    }

    //Set Position Each Loop!
    void SetPosition(float x, float y)
    {
        sprite.setPosition(x, y);
        hover.setPosition(x,y);
        half.setPosition(x,y);
        double2.setPosition(x, y);
        halfRect.setPosition(x+290,y);
        double2Rect.setPosition(x+353,y);
        wagerRect.setPosition(x,y);
    }

    void HoverChecker(const float& x, const float& y)
    {
        if (this->double2Rect.getGlobalBounds().contains(x,y))
        {
            hovered = 3;
        }
        else if (this->halfRect.getGlobalBounds().contains(x,y))
        {
            hovered = 2;
        }
        else if (this->sprite.getGlobalBounds().contains(x,y))
        {
            hovered = 1;
        }
        else
        {
            hovered = 0;
        }
    }

    bool ClickChecker(const float& x, const float& y)
    {
        if (this->wagerRect.getGlobalBounds().contains(x,y))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};