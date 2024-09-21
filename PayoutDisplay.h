#ifndef PAYOUTDISPLAY_H
#define PAYOUTDISPLAY_H

#include "GameState.h"
#include "Multiplier.h"

struct PayoutInfo {
    int gemsFound;          // Integer for gems found
    double multiplier;      // Double for the multiplier
    double payout;          // Double for the payout value
};

class PayoutDisplay {
private:
    GameState* gameState;   // Pointer to the game state instance
    Multiplier* multiplier; // Pointer to the multiplier class
    std::vector<PayoutInfo> payouts;

    sf::Font font;
    sf::Text headerGems;
    sf::Text headerMultiplier;
    sf::Text headerPayout;

public:
    PayoutDisplay(GameState* state, Multiplier* mult);
    void calculatePayouts(int numberOfMines, double currentWager, int gemsRevealed);
    void displayPayoutsOnScreen(sf::RenderWindow& window);
};

#endif
