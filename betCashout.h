#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "texture.h"
using namespace std;

struct bet_or_cashout
{
    sf::Sprite bet;
    sf::Sprite cashout;
    sf::Sprite betLit;
    sf::Sprite cashoutLit;

    bool hovered = false;


    //constructor
    bet_or_cashout()
    {
        bet.setTexture(texture::GetTexture("bet"));
        betLit.setTexture(texture::GetTexture("betLit"));
        cashout.setTexture(texture::GetTexture("cashout"));
        cashoutLit.setTexture(texture::GetTexture("cashoutLit"));

    }

    //Set Position Each Loop!
    void SetPosition(float x, float y)
    {
        bet.setPosition(x, y);
        betLit.setPosition(x,y);
        cashout.setPosition(x,y+186);
        cashoutLit.setPosition(x, y+186);
    }

    void HoverChecker(const float& x, const float& y, int state)
    {
        if (state == 0)
        {
            if (this->bet.getGlobalBounds().contains(x,y))
            {
                hovered = true;
            }
            else
            {
                hovered = false;
            }
        }
        if (state == 1)
        {
            if (this->cashout.getGlobalBounds().contains(x,y))
            {
                hovered = true;
            }
            else
            {
                hovered = false;
            }
        }
    }

    bool ClickChecker(const float& x, const float& y, int state)
    {
        if (state == 0 || state == 14)
        {
            if (this->bet.getGlobalBounds().contains(x,y))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (state == 1)
        {
            if (this->cashout.getGlobalBounds().contains(x,y))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

};