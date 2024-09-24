#include "GameController.h"

#include <set>

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
        if (event.type == sf::Event::Closed) {
            gameSaver->saveGame(&easterEgg, menu, &bank, &gameState, history, payoutDisplay, &wallpapers, wagerAmount, jeff);
            window.close();
        }
        HandleInput(event);
    }

    if (menu->menuState == Menu::CLOSE) {
        gameSaver->saveGame(&easterEgg, menu, &bank, &gameState, history, payoutDisplay, &wallpapers, wagerAmount, jeff);
        window.close();
    }
}

void GameController::Update() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    payoutDisplay->calculatePayouts(mines, wagerAmount, gemsRevealed);
    if (gameState == GameState::GameOver) {
        // If the timer hasn't started yet, capture the current time

        if (!timerStarted) {
            gameOverStartTime = std::chrono::steady_clock::now();
            timerStarted = true;
        }

        // Calculate the time difference
        auto elapsedTime = std::chrono::steady_clock::now() - gameOverStartTime;
        auto secondsPassed = std::chrono::duration_cast<std::chrono::seconds>(elapsedTime).count();

        // Check if 10 seconds have passed
        if (secondsPassed >= 5) {
            gameState = GameState::PreGame; // Set gameState to PreGame
            timerStarted = false;           // Reset the timer flag for future use
        }
        //payoutDisplay->calculatePayouts(mines, wagerAmount, gemsRevealed);
    }
    if (gameState != GameState::Playing){
        if (wagerAmount > bank.balance){
            wagerAmount = bank.balance;
            UpdateWagerOutput();
        }
    }
}

void GameController::Render() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    window.clear();

    window.draw(menuBack);
    if (gameState == GameState::PreGame) {
        window.draw(wallpapers.currentWallPaper->sprite);
        window.draw(gameOptionsBack);
        betButton.draw(window);
        wagerOptions.draw(window);
        mineOptions.draw(window);
        //window.draw(bank.bankText);
        bank.drawBank(window);
        window.draw(BetAmountTitle);
        window.draw(MinesTitle);;
        window.draw(GemsTitle);
        window.draw(wagerOutput);
        window.draw(mineOutput);
        window.draw(gemOutput);
        DrawTiles();
        easterEgg.render(window, gameState);
        //wallpapers.drawMenu(window);
    }

    else if (gameState == GameState::Playing) {
        window.draw(wallpapers.currentWallPaper->sprite);
        window.draw(gameOptionsBack);
        cashoutButton.draw(window);
        wagerOptions.draw(window);
        mineOptions.draw(window);
        //window.draw(bank.bankText);
        bank.drawBank(window);
        window.draw(BetAmountTitle);
        window.draw(MinesTitle);;
        window.draw(GemsTitle);
        window.draw(wagerOutput);
        window.draw(mineOutput);
        window.draw(gemOutput);
        DrawTiles();
    }
    else if (gameState == GameState::GameOver) {
        window.draw(wallpapers.currentWallPaper->sprite);
        window.draw(gameOptionsBack);
        betButton.draw(window);
        wagerOptions.draw(window);
        mineOptions.draw(window);
        //window.draw(bank.bankText);
        bank.drawBank(window);
        window.draw(BetAmountTitle);
        window.draw(MinesTitle);;
        window.draw(GemsTitle);
        window.draw(wagerOutput);
        window.draw(mineOutput);
        window.draw(gemOutput);
        DrawTiles();
        window.draw(multiplierWindow);
        window.draw(multiplierOutput);
        window.draw(payoutOutput);
    }

    menu->render(window);
    window.display();
}

void GameController::HandleInput(sf::Event& event) {
    // Handle user inputs (mouse clicks, key presses)

    easterEgg.checkStatus(bank.balance, gameState, event, bank.bankText, wallpapers);

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

    if (gameState == GameState::GameOver) {
        if (event.type == sf::Event::MouseButtonPressed) {
            gameState = GameState::PreGame;
            timerStarted = false;
            menu->handleClick(mousePos);
        }
    }

    //PreGame State
    if (gameState == GameState::PreGame) {
        //Check for mouse button pressed
        if (event.type == sf::Event::MouseButtonPressed) {

            //Check Menu Button
            menu->handleClick(mousePos);

            //Check Bet Button
            if (betButton.isClicked() && gems > 0 && gems < 25 && wagerAmount > 0) {
                if(easterEgg.step == 4 && !easterEgg.allInStep4) {
                    easterEgg.checkStep4(bank.balance,wagerAmount, gameState, wallpapers);
                }
                gameState = GameState::Playing;
                bank.withdrawl(wagerAmount);
                SetTiles();
            }

            //Check Wager Button
            int wagerHover = wagerOptions.isClicked();
            if (wagerHover == 3) {
                wagerAmount *= 2;
                typingWager = false;
                // Ensure the wager does not exceed the bank
                if (wagerAmount > bank.balance) {
                    wagerAmount = bank.balance;
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
                InputWager(event);
            }
            else if (typingGems) {  // Typing gems
                InputMinesOrGems(event, gems, mines, gemInput);
            }
            else if (typingMines) {  // Typing mines
                InputMinesOrGems(event, mines, gems, mineInput);
            }
        }
    }

    //Playing State
    else if (gameState == GameState::Playing) {
        if (event.type == sf::Event::MouseButtonPressed) {
            CheckTiles(mousePos); //Check Tiles
            menu->handleClick(mousePos);
            if (cashoutButton.isClicked()) {
                EndGame(true);
                if(easterEgg.step == 4 && easterEgg.allInStep4) {
                    easterEgg.checkStep4(bank.balance,wagerAmount, gameState, wallpapers);
                }
            }
        }
    }

    easterEgg.update(event, bank.balance);
}

void GameController::UpdateWagerOutput() {
    ostringstream wagerStream;
    wagerStream << fixed << setprecision(2) << wagerAmount;
    wagerInput = wagerStream.str();
    wagerOutput.setString(wagerInput);
}

void GameController::UpdatePayoutOutput() {
    ostringstream payoutStream;
    payoutStream << fixed << setprecision(2) << payout;
    payoutOutput.setString("$" + payoutStream.str());
    payoutRect = payoutOutput.getGlobalBounds();
    payoutOutput.setOrigin(payoutRect.width / 2.0f, payoutRect.height / 2.0f);
    payoutOutput.setPosition(multiplierWindow.getPosition().x + (multiplierWindow.getGlobalBounds().width / 2.0f), (multiplierWindow.getPosition().y + (multiplierWindow.getGlobalBounds().height * 0.35)));
}

void GameController::UpdateMultiplierOutput() {
    ostringstream multiplierStream;
    if (multi == 0) { multiplierStream << fixed << setprecision(0) << multi; }
    else { multiplierStream << fixed << setprecision(2) << multi; }
    multiplierOutput.setString(multiplierStream.str() + "x");
    multiRect = multiplierOutput.getGlobalBounds();
    multiplierOutput.setOrigin(multiRect.width / 2.0f, multiRect.height / 2.0f);
    multiplierOutput.setPosition(multiplierWindow.getPosition().x + (multiplierWindow.getGlobalBounds().width / 2.0f), (multiplierWindow.getPosition().y + (multiplierWindow.getGlobalBounds().height * 0.72)));
}

void GameController::InputWager(sf::Event& event) {
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
    if (wagerAmount > bank.balance) {
        wagerAmount = bank.balance;
        wagerInput = (to_string(bank.balance));
        UpdateWagerOutput();
    }

    // Update wagerOutput text display
    wagerOutput.setString(wagerInput);
}

void GameController::InputMinesOrGems(sf::Event& event, int& integer, int& integer2, string& input) {
    // Handle backspace
    if (event.text.unicode == 'c') {
        bank.deposit(900);
    }
    if (event.text.unicode == 8 && !input.empty()) {
        input.pop_back();
    }
    // Allow only digit inputs
    else if (isdigit(event.text.unicode)) {
        input += static_cast<char>(event.text.unicode);
    }

    // Convert the input to an integer and apply constraints
    if (!input.empty()) {
        try {
            integer = std::stoi(input);  // Convert string to integer
        } catch (...) {
            integer = 0;  // Default to 1 if conversion fails
        }

        // Clamp mines between 1 and 24
        if (integer < 0) {
            integer = 0;
        } else if (integer > 24) {
            integer = 24;
        }
    }
    else {
        integer = 0;
    }
    // Automatically update gems
    integer2 = 25 - integer;

    // Update the output display
    UpdateMineGemOutput();
}

void GameController::UpdateMineGemOutput() {
    // Format and display the number of gems
    ostringstream gemStream;
    gemStream << gems;
    gemInput = gemStream.str();
    gemOutput.setString(gemInput);

    // Format and display the number of mines
    ostringstream mineStream;
    mineStream << mines;
    mineInput = mineStream.str();
    mineOutput.setString(mineInput);
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
    UpdateMineGemOutput();
    SetTiles();
}

void GameController::DrawTiles() {
    for (auto& tile : tiles) {
        tile.draw(window);
    }
}

void GameController::SetTiles() {
    for (auto& tile : tiles) {
        tile.reset();
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

void GameController::CheckTiles(sf::Vector2i mousePos) {
    gemsRevealed = 0;
    for (auto& tile : tiles) {
        if (!tile.isRevealed()) {
            tile.clickCheck(mousePos);
        }
        if (tile.isRevealed() && tile.hasMine()) {
            if(gameState != GameState::GameOver) {
                EndGame(false);
                return;
            }
        }
        else if (!tile.hasMine() && tile.isRevealed()) {
            gemsRevealed++;
        }
    }
}

void GameController::CountGems() {
    gemsRevealed = 0;
    for (auto& tile : tiles) {
        if (!tile.hasMine() && tile.isRevealed()) {
            gemsRevealed++;
        }
    }
}

void GameController::RevealTiles() {
    for (auto& tile : tiles) {
        tile.reveal();
    }
}

void GameController::EndGame(bool win) {
    if(!win) {
        RevealTiles();
        multi =  0;
        payout = 0;
        history->AddRound(mines, gemsRevealed, wagerAmount, multi, payout);
        if (wagerAmount >= bank.balance) { wagerAmount = bank.balance;}
        bank.deposit(payout);
        UpdateWagerOutput();
        UpdateMultiplierOutput();
        UpdatePayoutOutput();
        UpdateMineGemOutput();
        gameState = GameState::GameOver;
        gemsRevealed = 0;
    }
    else {
        RevealTiles();
        multi =  multiplier.multi(gemsRevealed,mines);
        payout = (wagerAmount * multi);
        history->AddRound(mines, gemsRevealed, wagerAmount, multi, payout);
        bank.deposit(payout);
        UpdateWagerOutput();
        UpdateMultiplierOutput();
        UpdatePayoutOutput();
        UpdateMineGemOutput();
        gameState = GameState::GameOver;
        gemsRevealed = 0;
    }
}


void GameController::UpdateEasterEgg() {

}

GameController::GameController() : window(sf::VideoMode(1800, 980), "Mines") {

    //Gamestate and other booleans
    gameState = GameState::PreGame;
    prevState = GameState::MainMenu;
    won = false;
    setup = false;
    typingWager = false;
    typingGems = false;
    typingMines = false;
    allInBetConfirmed = false;

    // Initialize background
    back.setSize(sf::Vector2f(1800, 980));
    back.setFillColor(sf::Color(15,33,46));
    back2.setSize(sf::Vector2f(450, 980));
    back2.setFillColor(sf::Color(85,112,100));

    menuBack.setTexture(Texture::GetTexture("menuBack"));
    menuBack.setPosition(0,0);

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

    cashoutButton.setPosition(28.35, 277.87);
    betButton.setPosition(28.35, 277.87);
    wagerOptions.setPosition();
    mineOptions.setPosition(28.35, 204.24);

    //Initialize Texts
    font.loadFromFile("./fonts/ProximaNova.ttc");

    mineOutput.setFont(font);
    mineOutput.setStyle(sf::Text::Bold);
    mineOutput.setPosition(99.33, 221.63);
    mineOutput.setCharacterSize(18.5);
    mineOutput.setFillColor(sf::Color::White);

    gemOutput.setFont(font);
    gemOutput.setStyle(sf::Text::Bold);
    gemOutput.setPosition(300.60, 221.63);
    gemOutput.setCharacterSize(18.43);
    gemOutput.setFillColor(sf::Color::White);

    wagerOutput.setFont(font);
    wagerOutput.setStyle(sf::Text::Bold);
    wagerOutput.setPosition(120, 148.04);
    wagerOutput.setCharacterSize(18.43);
    wagerOutput.setFillColor(sf::Color::White);
    wagerOutput.setString("0");

    payoutOutput.setFont(font);
    payoutOutput.setStyle(sf::Text::Bold);
    payoutOutput.setString("help me");
    payoutOutput.setCharacterSize(25);
    payoutOutput.setFillColor(sf::Color::White);
    payoutOutput.setPosition(multiplierWindowX+40, multiplierWindowY + 40);

    multiplierOutput.setFont(font);
    multiplierOutput.setStyle(sf::Text::Bold);
    //multiplierOutput.setString("0.00X");
    multiplierOutput.setCharacterSize(25);
    multiplierOutput.setFillColor(sf::Color::White);

    BetAmountTitle.setFont(font);
    BetAmountTitle.setStyle(sf::Text::Bold);
    BetAmountTitle.setString("Wager: $");
    BetAmountTitle.setPosition(39.68, 148.04);
    BetAmountTitle.setCharacterSize(18.5);
    BetAmountTitle.setFillColor(sf::Color::White);

    MinesTitle.setFont(font);
    MinesTitle.setStyle(sf::Text::Bold);
    MinesTitle.setString("Mines:");
    MinesTitle.setPosition(39.68, 221.63);
    MinesTitle.setCharacterSize(18.5);
    MinesTitle.setFillColor(sf::Color::White);

    GemsTitle.setFont(font);
    GemsTitle.setStyle(sf::Text::Bold);
    GemsTitle.setString("Gems:");
    GemsTitle.setPosition(243.30, 221.63);
    GemsTitle.setCharacterSize(18.5);
    GemsTitle.setFillColor(sf::Color::White);

    gameSaver = new GameSaver();
    payoutDisplay = new PayoutDisplay(&gameState, &multiplier);
    history = new History(&multiplier);
    jeff = new Jeff(&bank);
    menu = new Menu(&gameState, &wallpapers, payoutDisplay, history, &bank, &easterEgg, jeff);
    gameSaver->loadGame(&easterEgg, menu, &bank, &gameState, history, payoutDisplay, &wallpapers, wagerAmount, jeff);
    InitializeTiles();
}
