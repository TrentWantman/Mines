#include "PayoutDisplay.h"
#include <iostream>
#include <sstream>
#include <iomanip>

PayoutDisplay::PayoutDisplay(GameState* state, Multiplier* mult) : gameState(state), multiplier(mult) {
    font.loadFromFile("../fonts/ProximaNova.ttc");

    payoutScreen.setTexture(Texture::GetTexture("payoutScreen"));
    payoutScreen.setPosition(37.67, 416.960);

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
    window.draw(payoutScreen);

    // Use the same boundaries and padding as the History display
    float startY = 470.0f;  // Same top padding as the History
    float endY = 880.0f;    // Same bottom padding
    float gemsX = 50.0f;    // Move Gems a bit to the left
    float multiplierX = 120.0f;  // Shift Multiplier to the left
    float payoutX = 260.0f;  // Shift Payout to the left to avoid overflow

    // Calculate space available and offset per entry
    float availableHeight = endY - startY;
    float entryHeight = availableHeight / 28.0f;  // Space per entry
    float yOffset = startY;

    int fontSize = 12;  // Keep the font size small to fit (same as History)

    // Display each payout in separate columns for Gems, Multiplier, and Payout
    for (const auto& payout : payouts) {
        // Create text objects for each element

        // Gems Text
        sf::Text gemsText("Gems: " + std::to_string(payout.gemsFound), font, fontSize);
        gemsText.setPosition(gemsX, yOffset);

        // Multiplier Text with "x"
        std::stringstream multiplierStream;
        multiplierStream << "Multiplier: " << std::fixed << std::setprecision(2) << payout.multiplier << "x";
        sf::Text multiplierText(multiplierStream.str(), font, fontSize);
        multiplierText.setPosition(multiplierX, yOffset);

        // Payout Text formatted to 2 decimals
        std::stringstream payoutStream;
        payoutStream << "Payout: $" << std::fixed << std::setprecision(2) << payout.payout;
        sf::Text payoutText(payoutStream.str(), font, fontSize);
        payoutText.setPosition(payoutX, yOffset);

        // Draw the text objects on the screen
        window.draw(gemsText);
        window.draw(multiplierText);
        window.draw(payoutText);

        // Increment the Y offset for the next entry
        yOffset += entryHeight;
    }
}




void PayoutDisplay::calculatePayouts(int numberOfMines, double currentWager, int gemsRevealed) {
    if (numberOfMines == 0) {
        return;  // Skips the rest of the function
    }

    payouts.clear();

    // Check the current game state
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
