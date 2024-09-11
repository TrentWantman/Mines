#include "GameController.h"

#include <set>

GameController::GameController() : window(sf::VideoMode(1800, 980), "Mines") {
    InitializeTiles();

    //Gamestate and other booleans
    gameState = GameState::PreGame;
    prevState = GameState::MainMenu;
    won = false;
    setup = false;
    typingWager = false;
    typingGems = false;
    typingMines = false;

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
    wagerOutput.setString("0");

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
    UpdateBankOutput();
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

    if (gameState == GameState::PreGame) {
        window.draw(back);
        window.draw(back2);
        betButton.draw(window);
        wagerOptions.draw(window);
        mineOptions.draw(window);
        window.draw(bankText);
        window.draw(BetAmountTitle);
        window.draw(MinesTitle);;
        window.draw(GemsTitle);
        window.draw(wagerOutput);
        window.draw(mineOutput);
        window.draw(gemOutput);
        DrawTiles();
    }
    else if (gameState == GameState::Playing) {
        window.draw(back);
        window.draw(back2);
        cashoutButton.draw(window);
        wagerOptions.draw(window);
        mineOptions.draw(window);
        window.draw(bankText);
        window.draw(BetAmountTitle);
        window.draw(MinesTitle);;
        window.draw(GemsTitle);
        window.draw(wagerOutput);
        window.draw(mineOutput);
        window.draw(gemOutput);
        DrawTiles();
    }
    else if (gameState == GameState::GameOver) {
        window.draw(back);
        window.draw(back2);
        DrawTiles();
    }

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

void GameController::DrawTiles() {
    for (auto& tile : tiles) {
        tile.draw(window);
    }
}

void GameController::HandleInput(sf::Event& event) {
    // Handle user inputs (mouse clicks, key presses)

    //Check for Tile Hovering
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (auto& tile : tiles) {
        if (!tile.isRevealed()) {
            tile.hoverCheck(mousePos);
        }
    }
    //Check for Wager hover
    wagerOptions.hoverCheck(mousePos);
    mineOptions.hoverCheck(mousePos);
    cashoutButton.hoverCheck(mousePos);
    betButton.hoverCheck(mousePos);

    //PreGame State
    if (gameState == GameState::PreGame) {
        //Check for mouse button pressed
        if (event.type == sf::Event::MouseButtonPressed) {

            //Check Bet Button
            if (betButton.isClicked()) {
                gameState = GameState::Playing;
                bank -= wagerAmount;
                UpdateBankOutput();
            }

            //Check Wager Button
            int wagerHover = wagerOptions.isClicked();
            if (wagerHover == 3) {
                wagerAmount *= 2;
                typingWager = false;
                // Ensure the wager does not exceed the bank
                if (wagerAmount > bank) {
                    wagerAmount = bank;
                }
                UpdateWagerOutput();
            }
            else if (wagerHover == 2) {
                wagerAmount /= 2;
                typingWager = false;
                UpdateWagerOutput();
            }
            else if (wagerHover == 1) {
                typingWager = true;
                if (wagerInput == "0" || wagerAmount == 0) {
                    wagerInput = "";  // Start with an empty string
                    wagerOutput.setString(wagerInput);  // Reflect empty input in the display
                }
            }
            if (wagerHover == 0) {
                typingWager = false;
            }

            //Check Mine Options Button
            int mineHover = mineOptions.isClicked();
            if (mineHover == 1) {  // If gems are clicked
                typingGems = true;  // Enable typing for gems
                typingMines = false;  // Disable typing for mines
                gemInput = "";  // Clear input when clicking to type
            } else if (mineHover == 2) {  // If mines are clicked
                typingMines = true;  // Enable typing for mines
                typingGems = false;  // Disable typing for gems
                mineInput = "";  // Clear input when clicking to type
            } else if (mineHover == 3) {
                typingGems = false;
                typingMines = false;
            }
        }

        if (event.type == sf::Event::TextEntered) {
            //Typing the Wager
            if (typingWager) {
                // Handle backspace
                if (event.text.unicode == 8 && !wagerInput.empty()) {  // Backspace handling
                    wagerInput.pop_back();
                }
                // Allow digits and one decimal point
                else if (isdigit(event.text.unicode) || (event.text.unicode == '.' && wagerInput.find('.') == std::string::npos)) {
                    // If there is already a decimal point, ensure we allow only two digits after it
                    if (wagerInput.find('.') != std::string::npos) {
                        size_t decimalPos = wagerInput.find('.');
                        if (wagerInput.size() - decimalPos <= 2) {  // Allow only two digits after decimal point
                            wagerInput += static_cast<char>(event.text.unicode);
                        }
                    }
                    else {
                        wagerInput += static_cast<char>(event.text.unicode);  // No decimal yet, allow digit or single decimal
                    }
                }

                // Update the wagerAmount based on the current valid input
                if (!wagerInput.empty()) {
                    try {
                        wagerAmount = std::stod(wagerInput);  // Convert string to double
                    } catch (...) {
                        wagerAmount = 0;  // Default to 0 if conversion fails
                    }
                    }
                else {
                    wagerAmount = 0;  // If input is empty, set wager to 0
                }

                // If wager exceeds the bank, set it to the bank value
                if (wagerAmount > bank) {
                    wagerAmount = bank;
                    wagerInput = (to_string(bank));
                    UpdateWagerOutput();
                }

                // Update wagerOutput text display
                wagerOutput.setString(wagerInput);
            }
            else if (typingGems) {  // Typing gems
            // Handle backspace
            if (event.text.unicode == 8 && !gemInput.empty()) {
                gemInput.pop_back();
            }
            // Allow only digit inputs
            else if (isdigit(event.text.unicode)) {
                gemInput += static_cast<char>(event.text.unicode);
            }

            // Convert the input to an integer and apply constraints
            if (!gemInput.empty()) {
                try {
                    gems = std::stoi(gemInput);  // Convert string to integer
                } catch (...) {
                    gems = 1;  // Default to 1 if conversion fails
                }

                // Clamp gems between 1 and 24
                if (gems < 1) {
                    gems = 1;
                } else if (gems > 24) {
                    gems = 24;
                }

                // Automatically update mines
                mines = 25 - gems;

                // Update the output display
                UpdateMineGemOutput();
            }
        } else if (typingMines) {  // Typing mines
            // Handle backspace
            if (event.text.unicode == 8 && !mineInput.empty()) {
                mineInput.pop_back();
            }
            // Allow only digit inputs
            else if (isdigit(event.text.unicode)) {
                mineInput += static_cast<char>(event.text.unicode);
            }

            // Convert the input to an integer and apply constraints
            if (!mineInput.empty()) {
                try {
                    mines = std::stoi(mineInput);  // Convert string to integer
                } catch (...) {
                    mines = 1;  // Default to 1 if conversion fails
                }

                // Clamp mines between 1 and 24
                if (mines < 1) {
                    mines = 1;
                } else if (mines > 24) {
                    mines = 24;
                }

                // Automatically update gems
                gems = 25 - mines;

                // Update the output display
                UpdateMineGemOutput();
            }
        }
        }
    }

    //Playing State
    else if (gameState == GameState::Playing) {
        if (event.type == sf::Event::MouseButtonPressed) {
            //Check Tiles
            for (auto& tile : tiles) {
                if (!tile.isRevealed()) {
                    tile.clickCheck(mousePos);
                }
            }
            //Check Cashout Button
            if (betButton.isClicked()) {
                gameState = GameState::PreGame;
            }
        }
    }
}

void GameController::UpdateWagerOutput() {
    ostringstream wagerStream;
    wagerStream << fixed << setprecision(2) << wagerAmount;
    wagerInput = wagerStream.str();
    wagerOutput.setString(wagerInput);
}

void GameController::UpdateBankOutput() {
    ostringstream bankStream;
    bankStream << fixed << setprecision(2) << bank;
    bankText.setString("Bank: $" + bankStream.str());
}

void GameController::UpdateMineGemOutput() {
    // Format and display the number of gems
    ostringstream gemStream;
    gemStream << gems;
    gemOutput.setString(gemStream.str());

    // Format and display the number of mines
    ostringstream mineStream;
    mineStream << mines;
    mineOutput.setString(mineStream.str());
}


