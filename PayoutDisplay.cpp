#include "PayoutDisplay.h"
#include <iostream>
#include <sstream>
#include <iomanip>

PayoutDisplay::PayoutDisplay(GameState* state, Multiplier* mult) : gameState(state), multiplier(mult) {
    font.loadFromFile("./fonts/ProximaNova.ttc");

    headerGems.setFont(font);
    headerGems.setString("Gems");
    headerGems.setCharacterSize(20);
    headerGems.setPosition(50, 420);

    headerMultiplier.setFont(font);
    headerMultiplier.setString("Multiplier");
    headerMultiplier.setCharacterSize(20);
    headerMultiplier.setPosition(150, 420);

    headerPayout.setFont(font);
    headerPayout.setString("Payout");
    headerPayout.setCharacterSize(20);
    headerPayout.setPosition(300, 420);
}

void PayoutDisplay::displayPayoutsOnScreen(sf::RenderWindow& window) {
    // Render headers
    window.draw(headerGems);
    window.draw(headerMultiplier);
    window.draw(headerPayout);

    // Display each payout in a row under the headers
    int yOffset = 440; // Starting Y position for the data rows
    for (const auto& payout : payouts) {
        // Create text objects for gems, multiplier, and payout
        sf::Text gemsText(std::to_string(payout.gemsFound), font, 15);

        // Format multiplier and payout to 2 decimal places using stringstream
        std::stringstream multiplierStream;
        multiplierStream << std::fixed << std::setprecision(2) << payout.multiplier;
        sf::Text multiplierText(multiplierStream.str(), font, 15);

        std::stringstream payoutStream;
        payoutStream << std::fixed << std::setprecision(2) << payout.payout;
        sf::Text payoutText(payoutStream.str(), font, 15);

        // Set positions for each column
        gemsText.setPosition(50, yOffset);
        multiplierText.setPosition(150, yOffset);
        payoutText.setPosition(300, yOffset);

        // Draw the text objects
        window.draw(gemsText);
        window.draw(multiplierText);
        window.draw(payoutText);

        yOffset += 15; // Move the next row down
    }
}


void PayoutDisplay::calculatePayouts(int numberOfMines, double currentWager, int gemsRevealed) {
    if (numberOfMines == 0) {
        return;  // Skips the rest of the function
    }

    payouts.clear();

    // Check the current game state
    if (*gameState == GameState::PreGame || *gameState == GameState::GameOver) {

        // Loop through each number of gems that can be revealed
        for (int gems = 1; gems <= (25-numberOfMines); ++gems) {
            double payoutMultiplier = multiplier->calculateMultiplier(gems, numberOfMines);
            double payoutValue = payoutMultiplier * currentWager;
            payouts.push_back({gems, payoutMultiplier, payoutValue});
        }
    }
    else if (*gameState == GameState::Playing) {
        if (gemsRevealed == 0) {
            gemsRevealed = 1;
        }
        // Start from the number of gems already revealed and go up
        for (int gems = gemsRevealed; gems <= (25-numberOfMines); ++gems) {
            double payoutMultiplier = multiplier->calculateMultiplier(gems, numberOfMines);
            double payoutValue = payoutMultiplier * currentWager;
            payouts.push_back({gems, payoutMultiplier, payoutValue});
        }
    }
}
