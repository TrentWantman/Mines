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
    bool win = true;
    bool winState = true;
    bool setup14 = false;


    //Mouse
    double mouseX;
    double mouseY;

    //Tiles
    int tilesRevealed;
    int gemsRevealed;
    int totalTilesRevealed;
    int totalGemsRevealed;
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
    multiplierOutput.setPosition(multiplierWindowX+40, multiplierWindowY + 100);

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
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                mouseX = sf::Mouse::getPosition(window).x;
                mouseY = sf::Mouse::getPosition(window).y;

                if (state == 14) {
                    state = 0;
                    prevState = 14;
                }
                if ((!wagerOptions.wagerRect.getGlobalBounds().contains(mouseX, mouseY) && state == 11)||(!mineOptions.field.getGlobalBounds().contains(mouseX, mouseY) && state == 12)){
                    state = 0;
                }

                if (state == 0) {
                    //Wager Changes
                    if (wagerOptions.sprite.getGlobalBounds().contains(mouseX, mouseY)) {
                        //Cut wager in half
                        if (wagerOptions.halfRect.getGlobalBounds().contains(mouseX, mouseY)) {
                            wagerAmount = wagerAmount/2;
                            wagerInput = to_string(wagerAmount);
                        }
                        //Double Wager
                        else if (wagerOptions.double2Rect.getGlobalBounds().contains(mouseX,mouseY)) {
                            wagerAmount = wagerAmount*2;
                            wagerInput = to_string(wagerAmount);
                        }
                        //User clicked on wager amount, opens to state where they can type the wager
                        else {
                            wagerInput = "";
                            state = 11;
                        }
                    }
                    //User clicked on mine amount, opens to state where they can type the mine amount
                    else if (mineOptions.field.getGlobalBounds().contains(mouseX,mouseY)) {
                        mineInput = "";
                        state = 12;
                    }
                    //User clicked on "Bet" button and game will start
                    else if (betCashout.ClickChecker(mouseX,mouseY,state)) {
                        gemsRevealed = 0;
                        tilesRevealed = 0;
                        bank -= wagerAmount;

                        //Setup tiles for new game
                        for (int i = 0; i < 25; i++) {
                            tiles[i].hasMine = false;
                            tiles[i].hovered = false;
                            tiles[i].revealed = false;
                        }

                        //Set Mines
                        for (int i = 0; i < mines; i++) {
                            randomTile = random::Int(0, 24);
                            if (tiles[randomTile].hasMine) {
                                i--;
                            }
                            else {
                                tiles[randomTile].hasMine = true;
                            }
                        }

                        //Setup State 1
                        win = true;
                        setup14 = false;
                        prevState = 0;
                        state = 1;
                    }
                }
                //Game in progress. Checks for tile reveals and cashouts
                if (state == 1) {
                    //User Revealed Tile
                    for (int i = 0; i < 25; i++) {
                        if (!tiles[i].revealed) {
                            tiles[i].TileRevealed(mouseX, mouseY);
                            if(tiles[i].revealed && tiles[i].hasMine == false) {
                                gemsRevealed++;
                                tilesRevealed++;
                            }
                        }
                    }

                    //User Clicked Cashout Button
                    if (betCashout.ClickChecker(mouseX,mouseY,state) && gemsRevealed != 0) {
                        winState = true;
                        state = 14;
                    }
                }
            }

            //User Is Typing Wager Options
            if (state == 11) {
                if (event.type == sf::Event::TextEntered) {
                    if (wagerInput.size() > 0 && event.text.unicode == 8) {
                        wagerInput.pop_back();
                    }
                    else if (isdigit(event.text.unicode)) {
                        if (wagerAmount == 0) {
                            wagerInput = "";
                        }
                        wagerInput += static_cast<char>(event.text.unicode);
                    }
                    wagerOutput.setString(wagerInput);
                }
            }

            //User Is Typing Mine Options
            if (state == 12) {
                if (event.type == sf::Event::TextEntered) {
                    if (mineInput.size() == 2) {
                        mineInput = "";
                    }
                    if (mineInput.size() > 0 && event.text.unicode == 8) {
                        mineInput.pop_back();
                    }
                    else if (isdigit(event.text.unicode)) {
                        if (mines == 0) {
                            mineInput = "";
                        }
                        mineInput += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }

        /*---------------------Check if Game Is Over-----------------*/
        //In game, check if user hit a mine and end game
        if (state == 1) {
            for (int i = 0; i < 25; i++) {
                if (tiles[i].hasMine && tiles[i].revealed) {
                    tilesRevealed++;
                    win = false;
                    winState = false;
                    state = 14;
                }
            }
        }
        //Game is over, show payout status
        if (state == 14 && setup14 == false) {
            if (!win) {
                multiplier = 0;
                payout = 0;
                payoutOutput.setString("- $" + to_string(wagerAmount));
            }
            else {
                multiplier =  multiplier::multi(gemsRevealed,mines);
                payout = (wagerAmount * multiplier);
                bank += payout;
                win = false;

                if (multiplier != 0) {
                    payoutOutput.setString(to_string(payout));
                    multiplierOutput.setString(to_string(multiplier));
                }
                //Might be deleted
                else {
                    payoutOutput.setString(to_string(wagerAmount));
                    multiplierOutput.setString("1");
                }
            }
            setup14 = true;
        }

        /*---------------------Change Interface, Prepare Next Iteration, Update Data-----------------*/
        mouseX = sf::Mouse::getPosition(window).x;
        mouseY = sf::Mouse::getPosition(window).y;

        //Update Mine Options Output
        if (mines > 24) {
            mineInput = "24";
            mines = 24;
        }
        else if (mines < 0) {
            mineInput = "0";
            mines = 0;
        }
        if (mineInput.empty()) {
            mineInput = "0";
            mines = 0;
        }
        else {
            mines = stoi(mineInput);
        }
        mineOutput.setString(mineInput);

        //Update Wager Options Output
        if (wagerAmount < 0) {
            wagerInput = "0";
            wagerAmount = 0;
        }
        if (wagerInput.empty()) {
            wagerInput = "0";
            wagerAmount = 0;
        }
        else {
            wagerAmount = stod(wagerInput);
        }
        wagerOutput.setString(wagerInput);

        //Update Bank Output, Gem Output
        bankText.setString(to_string(bank));
        gems = 25 - mines - gemsRevealed;
        gemOutput.setString(to_string(gems));

        //Check if mouse is hovering over sprite and update interface
        if (mouseX > 455) {
            for (int i = 0; i < 25; ++i) {
                tiles[i].HoverChecker(mouseX, mouseY);
            }
        }
        else {
            wagerOptions.HoverChecker(mouseX, mouseY);
            betCashout.HoverChecker(mouseX, mouseY, state);
            mineOptions.HoverChecker(mouseX, mouseY, state);
        }

        /*-----------------------------------Clear Old Window-----------------------------------*/
        window.clear();
        /*-----------------------------------Draw New Window-----------------------------------*/
        window.draw(back);
        window.draw(back2);

        window.draw(wagerOutput);
        window.draw(mineOutput);

        //Draw Mine Options
        if (state == 0 || state == 11 || state == 12 || state == 14) {
            if (mineOptions.hovered == 0) {
                window.draw(mineOptions.field);
            }
            else {
                window.draw(mineOptions.fieldLit);
            }
        }
        else if (state == 1) {
            window.draw(GemsTitle);
            if (mineOptions.hovered == 0) {
                window.draw(mineOptions.splitField);
            }
            else if (mineOptions.hovered == 2) {
                window.draw(mineOptions.splitFieldMinesLit);
            }
            else if (mineOptions.hovered == 3){
                window.draw(mineOptions.splitFieldGemsLit);
            }

            window.draw(gemOutput);
        }
        //Bet/Cashout Button
        if (state == 0 || state == 11 || state == 12 || state == 14) {
            if (betCashout.hovered) {
                window.draw(betCashout.betLit);
            }
            else {
                window.draw(betCashout.bet);
            }
        }
        else if (state == 1) {
            window.draw(GemsTitle);

            if (betCashout.hovered) {
                window.draw(betCashout.cashoutLit);
            }
            else {
                window.draw(betCashout.cashout);
            }
        }

        //wager button
        if (wagerOptions.hovered == 0) {
            window.draw(wagerOptions.sprite);
        }
        else if (wagerOptions.hovered == 1) {
            window.draw(wagerOptions.hover);
        }
        else if (wagerOptions.hovered == 2) {
            window.draw(wagerOptions.half);
        }
        else if (wagerOptions.hovered == 3) {
            window.draw(wagerOptions.double2);
        }

        if (state == 14 || prevState == 14) {
            for (int i = 0; i < 25; i++) {
                if (!tiles[i].revealed) {
                    if (tiles[i].hasMine) {
                        window.draw(tiles[i].mine);
                    }
                    else {
                        window.draw(tiles[i].gem);
                    }
                }

            }
            window.draw(overlay);
        }


        //tiles
        for (int i = 0; i < 25; i++) {
            if (tiles[i].revealed) {
                if (tiles[i].hasMine) {
                    window.draw(tiles[i].mine);
                }
                else {
                    window.draw(tiles[i].gem);
                }
            }
            else if (state != 14 && prevState != 14)
            {
                window.draw(tiles[i].hidden);
                if (tiles[i].hovered) {
                    window.draw(tiles[i].hover);
                }
            }
        }

        if ((state == 14 || prevState == 14) && winState) {
            window.draw(multiplierWindow);
            window.draw(payoutOutput);
            window.draw(multiplierOutput);
        }

        window.draw(bankText);
        window.draw(wagerOutput);
        window.draw(mineOutput);

        window.display();
    }
    return 0;
}