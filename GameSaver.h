#ifndef GAMESAVER_H
#define GAMESAVER_H

#include <string>
//#include "GameController.h"
#include "EasterEgg.h"
#include "Menu.h"
#include "Bank.h"
#include "GameState.h"
#include "History.h"
#include "PayoutDisplay.h"
#include "Wallpapers.h"
#include "WallPaper.h"

class GameSaver {
public:
    GameSaver();
    //void saveGame();
    void saveGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers);
    void loadGame(EasterEgg* easterEgg, Menu* menu, Bank* bank, GameState* gameState, History* history, PayoutDisplay* payoutDisplay, Wallpapers* wallpapers);
};

#endif // GAMESAVER_H
