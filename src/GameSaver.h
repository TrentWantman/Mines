#ifndef GAMESAVER_H
#define GAMESAVER_H

#include <string>
#include "EasterEgg.h"
#include "Menu.h"
#include "Bank.h"
#include "GameState.h"
#include "History.h"
#include "PayoutDisplay.h"
#include "Wallpapers.h"
#include "Jeff.h"

class GameSaver {
public:
    GameSaver();
    // Save game data to a hidden binary file
    void saveGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers, double wagerAmount, Jeff* jeff);

    // Load game data from a hidden binary file
    void loadGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers, double wagerAmount, Jeff* jeff);

private:
    // Helper function to determine the correct path to save data
    std::string getSaveFilePath();
};

#endif // GAMESAVER_H
