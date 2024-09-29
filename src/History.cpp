#include "History.h"

History::History(Multiplier* mult) : multiplier(mult), currentStartIndex(0) {
    font.loadFromFile("../fonts/ProximaNova.ttc");
    int headerSize = 20;

    upArrow.setTexture(Texture::GetTexture("upArrow"));
    upArrow.setPosition(67.36, 451.51);

    downArrow.setTexture(Texture::GetTexture("downArrow"));
    downArrow.setPosition(67.36, 813.41);

    historyScreen.setTexture(Texture::GetTexture("historyScreen"));
    historyScreen.setPosition(37.67, 416.960);

    headerMines.setFont(font);
    headerMines.setString("Mines");
    headerMines.setCharacterSize(headerSize);
    headerMines.setPosition(40, 420);

    headerGems.setFont(font);
    headerGems.setString("Gems");
    headerGems.setCharacterSize(headerSize);
    headerGems.setPosition(headerMines.getPosition().x + headerMines.getGlobalBounds().width + 15, 420);

    headerWager.setFont(font);
    headerWager.setString("Wager");
    headerWager.setCharacterSize(headerSize);
    headerWager.setPosition(headerGems.getPosition().x + headerGems.getGlobalBounds().width + 15, 420);

    headerMultiplier.setFont(font);
    headerMultiplier.setString("Multiplier");
    headerMultiplier.setCharacterSize(headerSize);
    headerMultiplier.setPosition(headerWager.getPosition().x + headerWager.getGlobalBounds().width + 15, 420);

    headerPayout.setFont(font);
    headerPayout.setString("Payout");
    headerPayout.setCharacterSize(headerSize);
    headerPayout.setPosition(headerMultiplier.getPosition().x + headerMultiplier.getGlobalBounds().width + 15, 420);
}

void History::AddRound(int numberOfMines, int gemsRevealed, double wager, double multi, double payout) {
    std::stringstream wagerStream;
    wagerStream << std::fixed << std::setprecision(2) << wager;

    std::stringstream multiStream;
    multiStream << std::fixed << std::setprecision(2) << multi;

    std::stringstream payoutStream;
    payoutStream << std::fixed << std::setprecision(2) << payout;
    rounds.push_back({numberOfMines, gemsRevealed, stod(wagerStream.str()),stod( multiStream.str()), stod(payoutStream.str())});
}

void History::scrollDown() {
    // Scroll up, but don't exceed the total rounds count
    if (currentStartIndex + 12 < rounds.size()) {
        currentStartIndex += 12;
    }
}

void History::scrollUp() {
    // Scroll down, but ensure index stays >= 0
    if (currentStartIndex - 12 >= 0) {
        currentStartIndex -= 12;
    } else {
        currentStartIndex = 0;
    }
}

void History::displayHistory(sf::RenderWindow &window) {
    window.draw(historyScreen);

    window.draw(upArrow);
    window.draw(downArrow);

    // Boundaries with adjusted padding
    float startY = 475.0f;  // Slightly increase the top padding
    float endY = 800.0f;    // Slightly reduce the bottom padding
    float startX = 50.0f;   // Shift the text slightly to the right for balance
    float endX = 400.0f;    // Adjust the right boundary for better balance

    // Calculate space available and offset per entry
    float availableHeight = endY - startY;
    float entryHeight = availableHeight / 12.0f;  // Space per entry
    float yOffset = startY;

    int itemsToDisplay = std::min(12, static_cast<int>(rounds.size()) - currentStartIndex);  // Only show 12 items or less
    int fontSize = 13;  // Keep the font size small to fit

    for (int i = 0; i < itemsToDisplay; ++i) {
        auto& round = rounds[rounds.size() - 1 - (currentStartIndex + i)]; // Access the most recent rounds first

        // Create a stringstream to combine round data with the desired formatting
        std::stringstream roundStream;
        roundStream << "Wager: $" << std::fixed << std::setprecision(2) << round.wager
                    << " , Multiplier: " << std::fixed << std::setprecision(2) << round.multiplier << "x"
                    << " , Payout: $" << std::fixed << std::setprecision(2) << round.payout;

        // Create a single sf::Text object with the combined string
        sf::Text roundText(roundStream.str(), font, fontSize);
        roundText.setPosition(startX, yOffset); // Position within the X and Y bounds


        // Draw the combined text object
        window.draw(roundText);

        // Increment the Y offset for the next entry, based on the calculated height per entry
        yOffset += entryHeight;
    }
}




