//
// Created by litte on 9/21/2024.
//

#include "GameSaver.h"

GameSaver::GameSaver() {

};

void GameSaver::saveGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers, double wagerAmount, Jeff* jeff) {
    std::ofstream mainSave("saveFile.txt");

    if (!mainSave) {
        std::cerr << "Failed to open file for saving." << std::endl;
        return;
    }

    // Save relevant game state, e.g., player score, bank, round number, etc.
    if (*gameState == GameState::Playing){
        mainSave << (bank->balance + wagerAmount) << std::endl;
    }
    else{
        mainSave << bank->balance << std::endl;
    }

    mainSave << easterEgg->step << std::endl;

    mainSave << jeff->owedMoney << std::endl;

    for (auto& wallpaper : wallpapers->wallPaperMenu) {
        // if(wallpaper.unlocked) {
        mainSave << wallpaper.unlocked << std::endl;
        // }
    }

    mainSave << history->rounds.size() << std::endl; // Save the size of the rounds vector
    for (auto& round : history->rounds) {
        mainSave << round.mines << " "
                 << round.gemsRevealed << " "
                 << round.wager << " "
                 << round.multiplier << " "
                 << round.payout << std::endl;
    }


    mainSave.close();
}

void GameSaver::loadGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers, double wagerAmount, Jeff* jeff) {
    std::ifstream mainLoad("saveFile.txt");

    if (!mainLoad) {
        std::cerr << "Failed to open file for loading." << std::endl;
        return;
    }

    if (mainLoad.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Save file is empty. No data to load." << std::endl;
        mainLoad.close();
        return;
    }

    // Load bank balance
    double balance;
    mainLoad >> balance;
    bank->withdrawl(bank->balance);
    bank->deposit(balance);

    // Load EasterEgg step
    int step;
    mainLoad >> step;
    easterEgg->step = step;

    int owedMoney;
    mainLoad >> owedMoney;
    jeff->owedMoney = owedMoney;

    // Load wallpapers unlocked status
    int index = 1;
    for (auto& wallpaper : wallpapers->wallPaperMenu) {
        bool unlocked;
        mainLoad >> unlocked;
        if (unlocked) {
            wallpapers->unlockWallPaper(index);  // Use index to unlock wallpaper
        }
        index++;  // Increment the index for the next wallpaper
    }

    // Load history of rounds
    size_t roundsSize;
    mainLoad >> roundsSize;
    history->rounds.clear(); // Clear existing rounds before loading

    for (size_t i = 0; i < roundsSize; ++i) {
        Round round;
        mainLoad >> round.mines
                 >> round.gemsRevealed
                 >> round.wager
                 >> round.multiplier
                 >> round.payout;
        history->rounds.push_back(round);
    }

    mainLoad.close();
}
