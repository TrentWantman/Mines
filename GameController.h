#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iomanip>

#include "BetButton.h"
#include "Tile.h"
#include "CashoutButton.h"
#include "MineOptions.h"
#include "WagerOptions.h"
#include "Texture.h"
#include "Multiplier.h"
#include "Random.h"
#include "GameState.h"
using namespace std;

class GameController {
public:
    GameController();
    void Run();

private:
    void ProcessEvents();
    void Update();
    void Render();

    double mouseX;
    double mouseY;

    sf::RenderWindow window;
    sf::RectangleShape back, back2;
    sf::RectangleShape overlay;
    sf::Sprite multiplierWindow;

    GameState gameState;
    GameState prevState;
    bool won;
    bool setup;
    bool typingWager;
    bool typingMines;
    bool typingGems;

    std::vector<Tile> tiles;
    WagerOptions wagerOptions;
    MineOptions mineOptions;
    CashoutButton cashoutButton;
    BetButton betButton;

    int tilesRevealed;
    int gemsRevealed;
    int totalTilesRevealed;
    int totalGemsRevealed;
    int randomTile;
    int mines = 4;
    int gems = 21;

    double payout;
    double multiplier;
    double bank = 100;
    double wagerAmount = 0;

    sf::Font font;
    string mineInput;
    sf::Text mineOutput;
    string gemInput;
    sf::Text gemOutput;
    string wagerInput;
    sf::Text wagerOutput;
    string payoutString;
    sf::Text payoutOutput;
    sf::FloatRect payoutRect;
    string multiplierString;
    sf::Text multiplierOutput;
    sf::FloatRect multiRect;
    string bankString = "help me";
    sf::Text bankText;
    sf::FloatRect bankTextRect;
    sf::Text BetAmountTitle;
    sf::Text MinesTitle;
    sf::Text GemsTitle;

    void InitializeTiles();  // Function to initialize tile positions
    void DrawTiles();        // Function to draw tiles
    void HandleInput(sf::Event& event);      // Function to manage input

    void UpdateWagerOutput();
    void UpdateBankOutput();
    void UpdateMineGemOutput();
};

#endif // GAMECONTROLLER_H
