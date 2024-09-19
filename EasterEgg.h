#ifndef EASTEREGG_H
#define EASTEREGG_H

#include <SFML/Graphics.hpp>
#include "Texture.h"
#include "GameState.h"
#include <iostream>
#include <ostream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include "Wallpapers.h"

using namespace std;

class EasterEgg {
public:
    EasterEgg();
    void checkStatus(double& bank, GameState gameState, sf::Event& event, sf::Text& bankText, Wallpapers& wallpapers);
    void update(sf::Event& event, double& bank);
    void processGameResult(double multiplier, double& bank);
    void activatePhone();
    void renderPhone(sf::RenderWindow& window);
    void checkStep4(double bank, double wagerAmount, GameState gamestate, Wallpapers& wallpapers);
    void render(sf::RenderWindow& window, GameState gameState);

    // Easter egg steps management
    void handleAllInBet(double& bank);
    void handleGameOutcome(double& bank, bool gameWon);
    void manageEndGameScenarios(double& bank);

    // Getters for rendering decisions
    bool isPhoneActive() const;
    bool phoneVisible;
    sf::Sprite phone;

    bool allInStep4;
    double allInAmount;

    int step;

    sf::RectangleShape rect1;
    sf::RectangleShape rect2;
    sf::RectangleShape rect3;
    sf::Text text1;
    sf::Text text2;
    sf::Font font;
};

#endif