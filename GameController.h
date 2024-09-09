#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"
#include "BetCashout.h"
#include "MineOptions.h"
#include "WagerOptions.h"
#include "Texture.h"
#include "Multiplier.h"
#include "Random.h"

enum class GameState {
    MainMenu,
    Playing,
    GameOver
};

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

    std::vector<Tile> tiles;
    WagerOptions wagerOptions;
    MineOptions mineOptions;
    BetCashout betCashout;

    int tilesRevealed;
    int gemsRevealed;
    int totalTilesRevealed;
    int totalGemsRevealed;
    int randomTile;
    int mines;
    int gems;

    double payout;
    double multiplier;
    double bank = 100;
    double wagerAmount;

    sf::Font font;
    string mineInput;
    sf::Text mineOutput;
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
    void HandleInput();      // Function to manage input
};

#endif // GAMECONTROLLER_H
