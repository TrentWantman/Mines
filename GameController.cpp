#include "GameController.h"

GameController::GameController() : window(sf::VideoMode(1800, 980), "Mines") {
    InitializeTiles();
}

void GameController::Run() {
    while (window.isOpen()) {
        ProcessEvents();
        Update();
        Render();
    }
}

void GameController::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        HandleInput();
    }
}

void GameController::Update() {
    // Update logic here (e.g., animations, game state changes)
}

void GameController::Render() {
    window.clear();

    // Draw the background and other static elements here
    DrawTiles();

    // Draw other elements like wagerOptions, betCashout, etc.

    window.display();
}

void GameController::InitializeTiles() {
    double tileX = 670;
    double tileY = 20;
    int posCount = 0;

    for (int i = 0; i < 25; i++) {
        tiles.push_back(Tile());
    }

    for (int i = 0; i < 5; i++) {
        double offsetX = 186 * i;
        tiles[i].SetPosition(tileX + offsetX, tileY);
    }
    // Initialize other rows similarly...
}

void GameController::DrawTiles() {
    for (auto& tile : tiles) {
        if (tile.isRevealed()) {
            if (tile.hasMine()) {
                window.draw(tile.getMineSprite());
            } else {
                window.draw(tile.getGemSprite());
            }
        } else {
            window.draw(tile.getHiddenSprite());
        }
    }
}

void GameController::HandleInput() {
    // Handle user inputs (mouse clicks, key presses)
}
