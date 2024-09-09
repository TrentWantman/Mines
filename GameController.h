#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"
#include "BetCashout.h"
#include "WagerOptions.h"
#include "Texture.h"
#include "Multiplier.h"
#include "Random.h"

class GameController {
public:
    GameController();
    void Run();

private:
    void ProcessEvents();
    void Update();
    void Render();

    sf::RenderWindow window;
    std::vector<Tile> tiles;
    WagerOptions wagerOptions;
    BetCashout betCashout;

    void InitializeTiles();  // Function to initialize tile positions
    void DrawTiles();        // Function to draw tiles
    void HandleInput();      // Function to manage input
};

#endif // GAMECONTROLLER_H
