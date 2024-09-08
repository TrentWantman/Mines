#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "texture.h"
#include "tile.h"
#include "wager_options.h"
#include "bet_cashout.h"
#include "multiplier.h"
#include "mine_options.h"
#include "random.h"
using namespace std;

int main() {
    /*-------------------Window----------------*/
    sf::RenderWindow window(sf::VideoMode(1800, 980), "Mines");

    sf::RectangleShape back(sf::Vector2f(1800, 980));
    back.setFillColor(sf::Color(15,33,46));

    sf::RectangleShape back2(sf::Vector2f(450, 980));
    back2.setFillColor(sf::Color(85,112,100));

    sf::RectangleShape overlay(sf::Vector2f(1350, 980));
    overlay.setFillColor(sf::Color(255,255,255,155));
    overlay.setPosition(450,0);

    sf::Sprite multiplierWindow;
    multiplierWindow.setTexture(texture::GetTexture("multiplier"));
    double multiplierWindowOffsetX = multiplierWindow.getGlobalBounds().width/2;
    double multiplierWindowOffsetY = multiplierWindow.getGlobalBounds().height/2;
    double multiplierWindowX = 1126-multiplierWindowOffsetX;
    double multiplierWindowY = 492.558-multiplierWindowOffsetY;
    multiplierWindow.setPosition(multiplierWindowX, multiplierWindowY);

    /*-------------------Tiles----------------*/
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
    int mines;
    int gems;

    //Money
    double payout;
    double multiplier;
    double bank = 100;
    double wagerAmount;

    /*-------------------Menu Buttons----------------*/
    wager_options wagerOptions = wager_options();
    wagerOptions.SetPosition(18, 132);

    bet_cashout betCashout = bet_cashout();
    betCashout.SetPosition(18, 312);

    mine_options mineOptions = mine_options();
    mineOptions.SetPosition(18, 236);

    /*-------------------Dynamic Text----------------*/
    sf::Font font;
    font.loadFromFile("./fonts/ProximaNova.ttc");

    string mineInput;
    sf::Text mineOutput;
    mineOutput.setFont(font);
    mineOutput.setStyle(sf::Text::Bold);
    mineOutput.setPosition(25, 248);
    mineOutput.setCharacterSize(20);
    mineOutput.setFillColor(sf::Color::White);

    sf::Text gemOutput;
    gemOutput.setFont(font);
    gemOutput.setStyle(sf::Text::Bold);
    gemOutput.setPosition(236, 248);
    gemOutput.setCharacterSize(20);
    gemOutput.setFillColor(sf::Color::White);
    
    string wagerInput;
    sf::Text wagerOutput;
    wagerOutput.setFont(font);
    wagerOutput.setStyle(sf::Text::Bold);
    wagerOutput.setPosition(25, 144);
    wagerOutput.setCharacterSize(20);
    wagerOutput.setFillColor(sf::Color::White);

    sf::Text payoutOutput;
    payoutOutput.setFont(font);
    payoutOutput.setStyle(sf::Text::Bold);
    payoutOutput.setCharacterSize(25);
    payoutOutput.setFillColor(sf::Color::White);
    payoutOutput.setPosition(multiplierWindowX+40, multiplierWindowY + 40);

    sf::Text multiplierOutput;
    multiplierOutput.setFont(font);
    multiplierOutput.setStyle(sf::Text::Bold);
    multiplierOutput.setCharacterSize(25);
    multiplierOutput.setFillColor(sf::Color::White);
    multiplierOutput.setPosition(multiplierWindowY+40, multiplierWindowY + 100);

    sf::Text bankText;
    bankText.setFont(font);
    bankText.setStyle(sf::Text::Bold);
    bankText.setPosition(19, 30);
    bankText.setCharacterSize(20);
    bankText.setFillColor(sf::Color::White);

    /*-------------------Constant Text----------------*/
    sf::Text BetAmountTitle;
    BetAmountTitle.setFont(font);
    BetAmountTitle.setStyle(sf::Text::Bold);
    BetAmountTitle.setString("Bet Amount");
    BetAmountTitle.setPosition(19, 105);
    BetAmountTitle.setCharacterSize(20);
    BetAmountTitle.setFillColor(sf::Color::White);

    sf::Text MinesTitle;
    MinesTitle.setFont(font);
    MinesTitle.setStyle(sf::Text::Bold);
    MinesTitle.setString("Mines");
    MinesTitle.setPosition(21, 209);
    MinesTitle.setCharacterSize(20);
    MinesTitle.setFillColor(sf::Color::White);

    sf::Text GemsTitle;
    GemsTitle.setFont(font);
    GemsTitle.setStyle(sf::Text::Bold);
    GemsTitle.setString("Gems");
    GemsTitle.setPosition(232, 209);
    GemsTitle.setCharacterSize(20);
    GemsTitle.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
    }
}