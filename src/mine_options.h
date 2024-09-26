#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "Texture.h"
using namespace std;

struct mine_options
{
    sf::Sprite field;
    sf::Sprite fieldLit;
    sf::Sprite splitField;
    sf::Sprite splitFieldMinesLit;
    sf::Sprite splitFieldGemsLit;

    sf::RectangleShape minesRect;
    sf::RectangleShape gemsRect;

    int hovered = 0;


    //constructor
    mine_options()
    {
        field.setTexture(Texture::GetTexture("minesOption"));
        fieldLit.setTexture(Texture::GetTexture("minesOptionLit"));
        splitField.setTexture(Texture::GetTexture("splitField"));
        splitFieldMinesLit.setTexture(Texture::GetTexture("splitFieldMinesLit"));
        splitFieldGemsLit.setTexture(Texture::GetTexture("splitFieldGemsLit"));

        minesRect.setSize(sf::Vector2f(201,60));
        gemsRect.setSize(sf::Vector2f(201,60));
    }

    //Set Position Each Loop!
    void SetPosition(float x, float y)
    {
        field.setPosition(x, y);
        fieldLit.setPosition(x,y);
        splitField.setPosition(x,y);
        splitFieldMinesLit.setPosition(x,y);
        splitFieldGemsLit.setPosition(x,y);

        minesRect.setPosition(x,y);
        gemsRect.setPosition(x+213,y);
    }

    void HoverChecker(const float& x, const float& y, int state)
    {
        if (state != 1)
        {
            if (this->field.getGlobalBounds().contains(x,y))
            {
                hovered = 1;
            }
            else
            {
                hovered = 0;
            }
        }
        if (state == 1)
        {
            if (this->minesRect.getGlobalBounds().contains(x,y))
            {
                hovered = 2;
            }
            else if (this->gemsRect.getGlobalBounds().contains(x,y))
            {
                hovered = 3;
            }
            else
            {
                hovered = 0;
            }
        }
    }

};