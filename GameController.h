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
#include "Wallpapers.h"
#include "EasterEgg.h"
#include <chrono>

#include "Wallpapers.h"
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
    EasterEgg easterEgg;
    int currStep = 0;
    int prevStep = 0;
    std::chrono::time_point<std::chrono::steady_clock> gameOverStartTime;
    bool timerStarted = false;
    bool won;
    bool setup;
    bool typingWager;
    bool typingMines;
    bool typingGems;
    bool allInBetConfirmed;

    std::vector<Tile> tiles;
    WagerOptions wagerOptions;
    MineOptions mineOptions;
    CashoutButton cashoutButton;
    BetButton betButton;
    Wallpapers wallpapers;

    int tilesRevealed;
    int gemsRevealed;
    int totalTilesRevealed;
    int totalGemsRevealed;
    int randomTile;
    int mines = 4;
    int gems = 21;
    int gemsAtStart = 21;

    double payout;
    double multiplier;
    double bank = 100;
    double wagerAmount = 0;
    double prevWager;

    sf::Font font;
    string mineInput = "4";
    sf::Text mineOutput;
    string gemInput = "21";
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

    void UpdateEasterEgg();
    void InitializeTiles();  // Function to initialize tile positions
    void SetTiles();
    void RevealTiles();
    void CheckTiles(sf::Vector2i mousePos);
    void CountGems();
    void DrawTiles();        // Function to draw tiles
    void HandleInput(sf::Event& event);      // Function to manage input
    void EndGame(bool win);

    void InputMinesOrGems(sf::Event&, int&, int&, string&);
    void InputWager(sf::Event&);
    void UpdateWagerOutput();
    void UpdateBankOutput();
    void UpdateMineGemOutput();
    void UpdateMultiplierOutput();
    void UpdatePayoutOutput();
};

#endif // GAMECONTROLLER_H
