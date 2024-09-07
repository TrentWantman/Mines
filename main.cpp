#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "texture.h"
#include "tile.h"
#include "wager_menu.h"
#include "betCashout.h"
#include "multiplier.h"
#include "minesOption.h"
#include "random.h"
using namespace std;

int main() {
    /*-------------------Create Window----------------*/
    sf::RenderWindow window(sf::VideoMode(1800, 980), "Mines");
    sf::RectangleShape back(sf::Vector2f(1800, 980));
    back.setFillColor(sf::Color(15,33,46));
    sf::RectangleShape back2(sf::Vector2f(450, 980));
    back2.setFillColor(sf::Color(85,112,100));
    sf::RectangleShape overlay(sf::Vector2f(1350, 980));
    overlay.setFillColor(sf::Color(255,255,255,155));
    overlay.setPosition(450,0);

    /*-------------------Create Tiles----------------*/
    vector<tile> tiles;

    for (int i = 0; i < 25; i++)
    {
        tiles.push_back(tile());
    }

    double tileX = 670;
    double tileY = 20;
    int posCount = 0;

    for (int i = 0; i < 5; i++)
    {
        double offsetX = 186 * i;
        tiles[i].SetPosition(tileX + offsetX, tileY);
    }
    posCount = 0;
    for (int i = 5; i < 10; i++)
    {
        double offsetX = 186 * posCount;
        tiles[i].SetPosition(tileX + offsetX, tileY + 191.279);
        posCount++;
    }
    posCount = 0;
    for (int i = 10; i < 15; i++)
    {
        double offsetX = 186 * posCount;
        tiles[i].SetPosition(tileX + offsetX, tileY + 191.279*2);
        posCount++;
    }
    posCount = 0;
    for (int i = 15; i < 20; i++)
    {
        double offsetX = 186 * posCount;
        tiles[i].SetPosition(tileX + offsetX, tileY + 191.279*3);
        posCount++;
    }
    posCount = 0;
    for (int i = 20; i < 25; i++)
    {
        double offsetX = 186 * posCount;
        tiles[i].SetPosition(tileX + offsetX, tileY + 191.279*4);
        posCount++;
    }
    posCount = 0;

    /*-------------------Variables----------------*/
    //State
    int state = 0;
    int prevState;

    //Mouse
    double mouseX;
    double mouseY;

    //Tiles
    int tilesRevealed;
    int randomTile;
    string mineInput;
    int mines;
    int gems;


    //Money
    double payout;
    double bank = 100;
    string wagerString;
    double wagerAmount;

    /*-------------------Menu Buttons----------------*/

}