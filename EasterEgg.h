#ifndef EASTEREGG_H
#define EASTEREGG_H

#include <SFML/Graphics.hpp>
#include "Texture.h"
#include "GameState.h"
#include <iostream>

class EasterEgg {
public:
    EasterEgg();
    void checkStatus(double& bank, GameState gamestate, sf::Event& event);
    void update(sf::Event& event, double& bank);
    void processGameResult(double multiplier, double& bank);
    void activatePhone();
    void renderPhone(sf::RenderWindow& window);

    // Easter egg steps management
    void handleAllInBet(double& bank);
    void handleGameOutcome(double& bank, bool gameWon);
    void manageEndGameScenarios(double& bank);

    // Getters for rendering decisions
    bool isPhoneActive() const;

private:
    sf::Sprite phone;
    bool phoneVisible;
    int step;
};

#endif