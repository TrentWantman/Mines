#include "GameController.h"

#include <set>

GameController::GameController() : window(sf::VideoMode(1800, 980), "Mines") {
    InitializeTiles();

    //Gamestate and other booleans
    gameState = GameState::PreGame;
    prevState = GameState::MainMenu;
    won = false;
    setup = false;

    // Initialize background
    back.setSize(sf::Vector2f(1800, 980));
    back.setFillColor(sf::Color(15,33,46));
    back2.setSize(sf::Vector2f(450, 980));
    back2.setFillColor(sf::Color(85,112,100));

    //Initialize UI Elements
    overlay.setSize((sf::Vector2f(1350, 980)));
    overlay.setFillColor(sf::Color(255,255,255,155));
    overlay.setPosition(450,0);

    multiplierWindow.setTexture(Texture::GetTexture("multiplier"));
    double multiplierWindowOffsetX = multiplierWindow.getGlobalBounds().width/2;
    double multiplierWindowOffsetY = multiplierWindow.getGlobalBounds().height/2;
    double multiplierWindowX = 1126-multiplierWindowOffsetX;
    double multiplierWindowY = 492.558-multiplierWindowOffsetY;
    multiplierWindow.setPosition(multiplierWindowX, multiplierWindowY);

    cashoutButton.setPosition(18, 312);
    betButton.setPosition(18, 312);
    wagerOptions.setPosition(18, 132);
    mineOptions.setPosition(18, 236);

    //Initialize Texts
    font.loadFromFile("./fonts/ProximaNova.ttc");

    mineOutput.setFont(font);
    mineOutput.setStyle(sf::Text::Bold);
    mineOutput.setPosition(25, 248);
    mineOutput.setCharacterSize(20);
    mineOutput.setFillColor(sf::Color::White);

    gemOutput.setFont(font);
    gemOutput.setStyle(sf::Text::Bold);
    gemOutput.setPosition(236, 248);
    gemOutput.setCharacterSize(20);
    gemOutput.setFillColor(sf::Color::White);

    wagerOutput.setFont(font);
    wagerOutput.setStyle(sf::Text::Bold);
    wagerOutput.setPosition(25, 144);
    wagerOutput.setCharacterSize(20);
    wagerOutput.setFillColor(sf::Color::White);

    payoutOutput.setFont(font);
    payoutOutput.setStyle(sf::Text::Bold);
    payoutOutput.setCharacterSize(25);
    payoutOutput.setFillColor(sf::Color::White);
    payoutOutput.setPosition(multiplierWindowX+40, multiplierWindowY + 40);

    multiplierOutput.setFont(font);
    multiplierOutput.setStyle(sf::Text::Bold);
    multiplierOutput.setString("Help me");
    multiplierOutput.setCharacterSize(25);
    multiplierOutput.setFillColor(sf::Color::White);

    bankText.setFont(font);
    bankText.setStyle(sf::Text::Bold);
    bankText.setString("Bank: $" + std::to_string(bank));
    bankText.setCharacterSize(20);
    bankText.setFillColor(sf::Color::White);
    bankTextRect = bankText.getGlobalBounds();
    bankText.setOrigin(bankTextRect.width / 2.0f, bankTextRect.height / 2.0f);
    bankText.setPosition(cashoutButton.cashoutSprite.getGlobalBounds().width/2, 30);

    BetAmountTitle.setFont(font);
    BetAmountTitle.setStyle(sf::Text::Bold);
    BetAmountTitle.setString("Bet Amount");
    BetAmountTitle.setPosition(19, 105);
    BetAmountTitle.setCharacterSize(20);
    BetAmountTitle.setFillColor(sf::Color::White);

    MinesTitle.setFont(font);
    MinesTitle.setStyle(sf::Text::Bold);
    MinesTitle.setString("Mines");
    MinesTitle.setPosition(21, 209);
    MinesTitle.setCharacterSize(20);
    MinesTitle.setFillColor(sf::Color::White);

    GemsTitle.setFont(font);
    GemsTitle.setStyle(sf::Text::Bold);
    GemsTitle.setString("Gems");
    GemsTitle.setPosition(232, 209);
    GemsTitle.setCharacterSize(20);
    GemsTitle.setFillColor(sf::Color::White);
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
        HandleInput(event);
    }
}

void GameController::Update() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
}

void GameController::Render() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    window.clear();

    window.draw(back);
    window.draw(back2);

    DrawTiles(mousePos);
    cashoutButton.draw(window);
    betButton.draw(window);
    wagerOptions.draw(window);
    mineOptions.draw(window);
    window.draw(bankText);
    window.draw(BetAmountTitle);
    window.draw(MinesTitle);;
    window.draw(GemsTitle);



    window.display();
}

void GameController::InitializeTiles() {
    double tileX = 670;  // Starting X position for the first tile
    double tileY = 20;   // Starting Y position for the first tile
    double offsetX = 186; // Horizontal spacing between tiles
    double offsetY = 191.279; // Vertical spacing between rows

    int rows = 5;  // Number of rows (5x5 grid)
    int cols = 5;  // Number of columns

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Tile tile;
            tile.SetPosition(tileX + j * offsetX, tileY + i * offsetY);
            tiles.push_back(tile);
        }
    }
    for (int i = 0; i < mines; i++) {
        randomTile = random::Int(0, 24);
        if (tiles[randomTile].hasMine()) {
            i--;
        }
        else {
            tiles[randomTile].addMine();
        }
    }
}

void GameController::DrawTiles(sf::Vector2i mousePos) {
    for (auto& tile : tiles) {
        tile.draw(window);
    }
}

void GameController::HandleInput(sf::Event& event) {
    // Handle user inputs (mouse clicks, key presses)

    //Check for Hovering
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (auto& tile : tiles) {
        if (!tile.isRevealed()) {
            tile.hoverCheck(mousePos);
        }
    }

    cashoutButton.hoverCheck(mousePos);
    betButton.hoverCheck(mousePos);

    //Check for mouse button pressed
    if (event.type == sf::Event::MouseButtonPressed) {
        for (auto& tile : tiles) {
            if (!tile.isRevealed()) {
                tile.clickCheck(mousePos);
            }
        }
    }

}
