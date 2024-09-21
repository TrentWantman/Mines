#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Wallpapers.h"
#include "PayoutDisplay.h"
#include "History.h"

#include "Texture.h"

class Menu {
private:
    sf::Sprite backgroundSprite;
    sf::RectangleShape appsRect;
    sf::Sprite closeSprite;
    sf::Sprite restartSprite;
    sf::Sprite payoutSprite;
    sf::Sprite historySprite;
    sf::Sprite achievementsSprite;
    sf::Sprite profileSprite;
    sf::Sprite phoneSprite;

    sf::Sprite confirmSprite; // Used for restart/close confirmation

    bool showDropdown;
    bool showConfirmation;
    GameState* gameState; // A pointer to the current game state
    Wallpapers* wallpapers;
    PayoutDisplay* payoutDisplay;
    History* history;

    void changeMenuState(sf::Vector2i mousePos);

    void handleProfileClick(sf::Vector2i mousePos);
    void handleAchivementsClick(sf::Vector2i mousePos);
    void handleHistoryClick(sf::Vector2i mousePos);
    void handlePayoutClick(sf::Vector2i mousePos);
    void handleRestartClick(sf::Vector2i mousePos);
    void handleCloseClick(sf::Vector2i mousePos);

public:

    enum MenuState {
        PROFILE,
        ACHIEVEMENTS,
        HISTORY,
        PAYOUT,
        RESTART,
        CLOSE,
    };

    MenuState menuState;
    Menu(GameState* state, Wallpapers* wallpapers, PayoutDisplay* payoutDisplay, History* history);
    void render(sf::RenderWindow& window);
    void update(sf::Vector2i mousePos);
    void handleClick(sf::Vector2i mousePos);

    void setGameState(GameState* state); // Update the game state if needed
};



#endif //MENU_H
