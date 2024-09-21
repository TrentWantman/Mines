//
// Created by litte on 9/21/2024.
//

#include "GameSaver.h"

GameSaver::GameSaver() {

};

void GameSaver::saveGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers) {
    std::ofstream saveFile("saveFile.txt");

    if (!saveFile) {
        std::cerr << "Failed to open file for saving." << std::endl;
        return;
    }

    // Save relevant game state, e.g., player score, bank, round number, etc.
    saveFile << bank->balance << std::endl;
    saveFile << easterEgg->step << std::endl;
    saveFile << easterEgg->allInStep4 << std::endl;
    saveFile << easterEgg->allInAmount << std::endl;
    //saveFile << history->() << std::endl;
    // Add more game state variables as needed

    saveFile.close();
}

void GameSaver::loadGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers) {

}