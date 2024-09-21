#include "History.h"

History::History(Multiplier* mult) : multiplier(mult) {
    font.loadFromFile("./fonts/ProximaNova.ttc");
    int headerSize = 20;

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

void History::AddRound(int numberOfMines, int gemsRevealed, double wager, double multi, double payout){
    std::stringstream wagerStream;
    wagerStream << std::fixed << std::setprecision(2) << wager;

    std::stringstream multiStream;
    multiStream << std::fixed << std::setprecision(2) << multi;

    std::stringstream payoutStream;
    payoutStream << std::fixed << std::setprecision(2) << payout;
    rounds.push_back({numberOfMines, gemsRevealed, wagerStream.str(), multiStream.str(), payoutStream.str()});
}

void History::displayHistory(sf::RenderWindow &window) {
    window.draw(headerMines);
    window.draw(headerGems);
    window.draw(headerWager);
    window.draw(headerMultiplier);
    window.draw(headerPayout);

    // Display each payout in reverse order, starting from the most recent round
    int yOffset = 440; // Starting Y position for the data rows
    for (auto it = rounds.rbegin(); it != rounds.rend(); ++it) {
        sf::Text mineText(std::to_string(it->mines), font, 20);
        sf::Text gemsText(std::to_string(it->gemsRevealed), font, 20);

        std::stringstream wagerStream;
        wagerStream << std::fixed << std::setprecision(2) << it->wager;
        sf::Text wagerText(wagerStream.str(), font, 20);

        std::stringstream multiStream;
        multiStream << std::fixed << std::setprecision(2) << it->multiplier;
        sf::Text multiplierText(multiStream.str(), font, 20);

        std::stringstream payoutStream;
        payoutStream << std::fixed << std::setprecision(2) << it->payout;
        sf::Text payoutText(payoutStream.str(), font, 20);

        // Set positions for each column
        mineText.setPosition(50, yOffset);
        gemsText.setPosition(100, yOffset);
        wagerText.setPosition(150, yOffset);
        multiplierText.setPosition(200, yOffset);
        payoutText.setPosition(250, yOffset);

        // Draw the text objects
        window.draw(mineText);
        window.draw(gemsText);
        window.draw(wagerText);
        window.draw(multiplierText);
        window.draw(payoutText);

        yOffset += 15; // Move the next row down
    }
}

