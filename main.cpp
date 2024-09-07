#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "texture.h"
#include "tile.h"
#include "button.h"
#include "betCashout.h"
#include "multiplier.h"
#include "minesOption.h"
#include "random.h"
using namespace std;

int main()
{

    /*-------------------Create Window----------------*/
    sf::RenderWindow window(sf::VideoMode(1800, 980), "Mines");
    sf::RectangleShape back(sf::Vector2f(1800, 980));
    back.setFillColor(sf::Color(15,33,46));
    sf::RectangleShape back2(sf::Vector2f(450, 980));
    back2.setFillColor(sf::Color(85,112,100));
    sf::RectangleShape overlay(sf::Vector2f(1350, 980));
    overlay.setFillColor(sf::Color(255,255,255,155));
    overlay.setPosition(450,0);

    /*-------------------Support Variables----------------*/

    bool setup14 = false;

    int state = 0;
    int lastState;

    int mineClickedInt;

    int gemsRevealed;

    double payoutNum;
    double money = 100;

    bool win = true;
    int wins;
    bool winState = true;

    double mouseX;
    double mouseY;

    //Tiles/Board
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

    //Number of Mines and Gems, and Wager
    string wagerStr;
    double wagerAmount;

    string mineStr;
    int randomTile;
    int numMines;
    int numGems;




    //Menu
    button wager = button();
    wager.SetPosition(18, 132);

    betCashout betCash = betCashout();
    betCash.SetPosition(18, 312);

    minesOption field = minesOption();
    field.SetPosition(18, 236);

    //Text
    sf::Font font;
    font.loadFromFile("./fonts/ProximaNova.ttc");

    sf::Text moneyNum;
    moneyNum.setFont(font);
    moneyNum.setStyle(sf::Text::Bold);
    moneyNum.setString("Bet Amount");
    moneyNum.setPosition(19, 30);
    moneyNum.setCharacterSize(20);
    moneyNum.setFillColor(sf::Color::White);

    sf::Text wagerNum;
    wagerNum.setFont(font);
    wagerNum.setStyle(sf::Text::Bold);
    wagerNum.setString("Bet Amount");
    wagerNum.setPosition(19, 105);
    wagerNum.setCharacterSize(20);
    wagerNum.setFillColor(sf::Color::White);

    sf::Text wagerOutput;
    wagerOutput.setFont(font);
    wagerOutput.setStyle(sf::Text::Bold);
    wagerOutput.setPosition(25, 144);
    wagerOutput.setCharacterSize(20);
    wagerOutput.setFillColor(sf::Color::White);


    sf::Text minesNum;
    minesNum.setFont(font);
    minesNum.setStyle(sf::Text::Bold);
    minesNum.setString("Mines");
    minesNum.setPosition(21, 209);
    minesNum.setCharacterSize(20);
    minesNum.setFillColor(sf::Color::White);

    sf::Text mineOutput;
    mineOutput.setFont(font);
    mineOutput.setStyle(sf::Text::Bold);
    mineOutput.setPosition(25, 248);
    mineOutput.setCharacterSize(20);
    mineOutput.setFillColor(sf::Color::White);


    sf::Text gemsNum;
    gemsNum.setFont(font);
    gemsNum.setStyle(sf::Text::Bold);
    gemsNum.setString("Gems");
    gemsNum.setPosition(232, 209);
    gemsNum.setCharacterSize(20);
    gemsNum.setFillColor(sf::Color::White);

    sf::Text gemOutput;
    gemOutput.setFont(font);
    gemOutput.setStyle(sf::Text::Bold);
    gemOutput.setPosition(236, 248);
    gemOutput.setCharacterSize(20);
    gemOutput.setFillColor(sf::Color::White);

    sf::Sprite profit;
    profit.setTexture(texture::GetTexture("multiplier"));
    double profitOffsetX = profit.getGlobalBounds().width/2;
    double profitOffsetY = profit.getGlobalBounds().height/2;
    double profitX = 1126-profitOffsetX;
    double profitY = 492.558-profitOffsetY;
    profit.setPosition(profitX, profitY);

    sf::Text profitOutput;
    profitOutput.setFont(font);
    profitOutput.setStyle(sf::Text::Bold);
    profitOutput.setCharacterSize(25);
    profitOutput.setFillColor(sf::Color::White);
    profitOutput.setPosition(profitX+40, profitY + 40);

    double multiplierNum;
    sf::Text multiplierOutput;
    multiplierOutput.setFont(font);
    multiplierOutput.setStyle(sf::Text::Bold);
    multiplierOutput.setCharacterSize(25);
    multiplierOutput.setFillColor(sf::Color::White);
    multiplierOutput.setPosition(profitX+40, profitY + 100);

    /*-----------------------------------The Forbidden Vindaloop----------------------------------------*/

    while (window.isOpen())
    {

        /*-----------------------------------Events & Reactions----------------------------------*/


        sf::Event event;
        while (window.pollEvent(event))
        {
            //Closing Window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                mouseX = sf::Mouse::getPosition(window).x;
                mouseY = sf::Mouse::getPosition(window).y;

                if (state == 14)
                {
                    state = 0;
                    lastState = 14;

                }

                if (!field.field.getGlobalBounds().contains(mouseX, mouseY) && state == 12)
                {
                    state = 0;
                }

                if (!wager.wagerRect.getGlobalBounds().contains(mouseX, mouseY) && state == 11)
                {
                    state = 0;
                }


                // State 0 (input wager and mines count)
                if (state == 0)
                {

                    if (wager.sprite.getGlobalBounds().contains(mouseX,mouseY))
                    {
                        if (wager.halfRect.getGlobalBounds().contains(mouseX,mouseY))
                        {
                            wagerAmount = wagerAmount/2;
                            wagerStr = to_string(wagerAmount);
                        }
                        else if (wager.double2Rect.getGlobalBounds().contains(mouseX,mouseY))
                        {
                            wagerAmount = wagerAmount*2;
                            wagerStr = to_string(wagerAmount);
                        }
                        else
                        {
                            wagerStr = "";
                            state = 11;
                        }
                    }

                    else if (field.field.getGlobalBounds().contains(mouseX,mouseY))
                    {
                        mineStr = "";
                        state = 12;
                    }

                    else if (betCash.ClickChecker(mouseX,mouseY,state))
                    {

                        gemsRevealed = 0;

                        //Reset tiles
                        for (int i = 0; i < 25; i++)
                        {
                            tiles[i].hasMine = false;
                            tiles[i].hovered = false;
                            tiles[i].revealed = false;
                        }

                        //Set Mines
                        for (int i = 0; i < numMines; i++)
                        {
                            randomTile = random::Int(0, 24);

                            if (tiles[randomTile].hasMine)
                            {
                                i--;
                            }
                            else
                            {
                                tiles[randomTile].hasMine = true;
                            }
                        }

                        //Reset win bool
                        win = true;
                        setup14 = false;
                        lastState = 0;
                        state = 1;

                        cout << "Money: " << money << endl;
                        money -= wagerAmount;
                        cout << "Money: " << money << endl;
                    }
                }



                if (state == 1)
                {
                    for (int i = 0; i < 25; i++)
                    {
                        if (!tiles[i].revealed)
                        {
                            tiles[i].TileRevealed(mouseX, mouseY);

                            if(tiles[i].revealed && tiles[i].hasMine == false)
                            {
                                gemsRevealed++;
                            }
                        }
                    }

                    if (betCash.ClickChecker(mouseX,mouseY,state))
                    {
                        winState = true;
                        state = 14;
                    }
                }
            }



            if (state == 11)
            {
                if (event.type == sf::Event::TextEntered)
                {
                    if (wagerStr.size() > 0 && event.text.unicode == 8)
                    {
                        wagerStr.pop_back();
                    }
                    else if (isdigit(event.text.unicode))
                    {
                        if (wagerAmount == 0)
                        {
                            wagerStr = "";
                        }

                        wagerStr += static_cast<char>(event.text.unicode);
                    }
                    wagerOutput.setString(wagerStr);
                }
            }

            if (state == 12)
            {
                if (event.type == sf::Event::TextEntered)
                {
                    if (mineStr.size() == 2)
                    {
                        mineStr = "";
                    }

                    if (mineStr.size() > 0 && event.text.unicode == 8)
                    {
                        mineStr.pop_back();
                    }
                    else if (isdigit(event.text.unicode))
                    {
                        if (numMines == 0)
                        {
                            mineStr = "";
                        }
                        mineStr += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }


        /*---------------------Make Changes, Design Next Iteration, Prepare Data-----------------*/
        mouseX = sf::Mouse::getPosition(window).x;
        mouseY = sf::Mouse::getPosition(window).y;

        if (numMines > 24)
        {
            mineStr = "24";
            numMines = 24;
        }
        else if (numMines < 0)
        {
            mineStr = "0";
            numMines = 0;
        }
        if (mineStr.empty())
        {
            mineStr = "0";
            numMines = 0;
        }
        else
        {
            numMines = stoi(mineStr);
        }

        mineOutput.setString(mineStr);

        if (wagerAmount < 0)
        {
            wagerStr = "0";
            wagerAmount = 0;
        }
        if (wagerStr.empty())
        {
            wagerStr = "0";
            wagerAmount = 0;
        }
        else
        {
            wagerAmount = stod(wagerStr);
        }
        wagerOutput.setString(wagerStr);


        for (int i = 0; i < 25; ++i)
        {
            tiles[i].HoverChecker(mouseX, mouseY);
        }

        if (mouseX < 455)
        {
            wager.HoverChecker(mouseX, mouseY);
            betCash.HoverChecker(mouseX, mouseY, state);
            field.HoverChecker(mouseX, mouseY, state);
        }

        if (state == 1)
        {
            for (int i = 0; i < 25; i++)
            {
                if (tiles[i].hasMine && tiles[i].revealed)
                {
                    mineClickedInt = i;
                    win = false;
                    winState = false;
                    state = 14;
                }
            }
        }


        if (state == 14 && setup14 == false)
        {

            if (!win)
            {
                multiplierNum = 0;
                payoutNum = 0;
                profitOutput.setString("- $" + to_string(wagerAmount));
            }
            else
            {
                wins = 0;
                for (int i = 0; i < 25; i++)
                {
                    if (tiles[i].revealed)
                    {
                        wins++;
                    }
                }
                multiplierNum =  multiplier::multi(wins,numMines);
                payoutNum = (wagerAmount * multiplierNum);
                money += payoutNum;
                win = false;

                if (multiplierNum != 0)
                {
                    profitOutput.setString(to_string(payoutNum));
                    multiplierOutput.setString(to_string(multiplierNum));
                }
                else
                {
                 profitOutput.setString(to_string(wagerAmount));
                 multiplierOutput.setString("1");
                }
            }

            setup14 = true;

        }

        moneyNum.setString(to_string(money));
        numGems = 25 -numMines - gemsRevealed;
        gemOutput.setString(to_string(numGems));


        /*-----------------------------------Clear Old Window-----------------------------------*/

        window.clear();



        /*-----------------------------------Draw New Window-----------------------------------*/
        window.draw(back);
        window.draw(back2);

        window.draw(wagerNum);
        window.draw(minesNum);

        //field
        if (state == 0 || state == 11 || state == 12 || state == 14)
        {

            if (field.hovered == 0)
            {
                window.draw(field.field);
            }
            else
            {
                window.draw(field.fieldLit);
            }
        }
        else if (state == 1)
        {
            window.draw(gemsNum);
            if (field.hovered == 0)
            {
                window.draw(field.splitField);
            }
            else if (field.hovered == 2)
            {
                window.draw(field.splitFieldMinesLit);
            }
            else if (field.hovered == 3)
            {
                window.draw(field.splitFieldGemsLit);
            }

            window.draw(gemOutput);
        }

        else if (state == 2)
        {

        }


        //Bet/Cashout Button
        if (state == 0 || state == 11 || state == 12 || state == 14)
        {
            if (betCash.hovered)
            {
                window.draw(betCash.betLit);
            }
            else
            {
                window.draw(betCash.bet);
            }
        }
        else if (state == 1)
        {
            window.draw(gemsNum);

            if (betCash.hovered)
            {
                window.draw(betCash.cashoutLit);
            }
            else
            {
                window.draw(betCash.cashout);
            }
        }

        //wager button
        if (wager.hovered == 0)
        {
            window.draw(wager.sprite);
        }
        else if (wager.hovered == 1)
        {
            window.draw(wager.hover);
        }
        else if (wager.hovered == 2)
        {
            window.draw(wager.half);
        }
        else if (wager.hovered == 3)
        {
            window.draw(wager.double2);
        }


        if (state == 14 || lastState == 14)
        {
            for (int i = 0; i < 25; i++)
            {
                if (!tiles[i].revealed)
                {
                    if (tiles[i].hasMine)
                    {
                        window.draw(tiles[i].mine);
                    }
                    else
                    {
                        window.draw(tiles[i].gem);
                    }
                }

            }

            window.draw(overlay);

        }


        //tiles
        for (int i = 0; i < 25; i++)
        {

            if (tiles[i].revealed)
            {
                if (tiles[i].hasMine)
                {
                    window.draw(tiles[i].mine);
                }
                else
                {
                    window.draw(tiles[i].gem);
                }
            }
            else if (state != 14 && lastState != 14)
            {
                window.draw(tiles[i].hidden);

                if (tiles[i].hovered)
                {
                    window.draw(tiles[i].hover);
                }
            }
        }

        if ((state == 14 || lastState == 14) && winState)
        {
            window.draw(profit);
            window.draw(profitOutput);
            window.draw(multiplierOutput);

        }



        window.draw(moneyNum);
        window.draw(wagerOutput);
        window.draw(mineOutput);



        window.display();
    }
    /*----------^^^^^-----LOOP-----^^^^^----------*/
    return 0;
}
