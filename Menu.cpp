#include "Menu.h"
#include <iostream>

Menu::Menu(GameState* state, Wallpapers* wallpapers, PayoutDisplay* payoutDisplay, History* history)
:  showConfirmation(false), gameState(state), wallpapers(wallpapers), payoutDisplay(payoutDisplay), history(history)
{
    // Initialize the background sprite and options button sprite
    backgroundSprite.setTexture(Texture::GetTexture("menuBack"));
    backgroundSprite.setPosition(18, 414);

    appsRect.setSize(sf::Vector2f(412, 50));
    appsRect.setPosition(20,900);
    profileSprite.setTexture(Texture::GetTexture("profile"));
    achievementsSprite.setTexture(Texture::GetTexture("achievments"));
    historySprite.setTexture(Texture::GetTexture("history"));
    payoutSprite.setTexture(Texture::GetTexture("payout"));
    restartSprite.setTexture(Texture::GetTexture("restart"));
    closeSprite.setTexture(Texture::GetTexture("close"));
    phoneSprite.setTexture(Texture::GetTexture("phone"));

    profileSprite.setPosition(50, 900);
    achievementsSprite.setPosition(110, 900);
    historySprite.setPosition(170, 900);
    payoutSprite.setPosition(230, 900);
    restartSprite.setPosition(290, 900);
    closeSprite.setPosition(350, 900);
}

void Menu::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    window.draw(profileSprite);
    window.draw(achievementsSprite);
    window.draw(historySprite);
    window.draw(payoutSprite);
    window.draw(restartSprite);
    window.draw(closeSprite);

    if (menuState == MenuState::PROFILE) {
    }
    else if (menuState == MenuState::ACHIEVEMENTS) {
        wallpapers->drawMenu(window);
    }
    else if (menuState == MenuState::HISTORY) {
        history->displayHistory(window);
    }
    else if (menuState == MenuState::PAYOUT) {
        payoutDisplay->displayPayoutsOnScreen(window);
    }
    else if (menuState == MenuState::RESTART) {
    }
    else if (menuState == MenuState::CLOSE) {
    }
    //If dropdown is visible, render it
    //
    // // If confirmation dialog is shown, render the confirmation sprite
    // if (showConfirmation) {
    //     window.draw(confirmSprite);
    // }
}

void Menu::update(sf::Vector2i mousePos) {
    // Handle hover effects for options button

}

void Menu::handleClick(sf::Vector2i mousePos) {
    if (backgroundSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {

        if (appsRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            changeMenuState(mousePos);
        }
        else if (menuState == MenuState::PROFILE) {
            handleProfileClick(mousePos);
        }
        else if (menuState == MenuState::ACHIEVEMENTS) {
            handleAchivementsClick(mousePos);
        }
        else if (menuState == MenuState::HISTORY) {
            handleHistoryClick(mousePos);
        }
        else if (menuState == MenuState::PAYOUT) {
            handlePayoutClick(mousePos);
        }
        else if (menuState == MenuState::RESTART) {
            handleRestartClick(mousePos);
        }
        else if (menuState == MenuState::CLOSE) {
            handleCloseClick(mousePos);
        }

    }
}

void::Menu::changeMenuState(sf::Vector2i mousePos) {
    if (closeSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        std::cout << "closeSprite" << std::endl;
        menuState = MenuState::CLOSE;
    }
    else if (restartSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        std::cout << "restartSprite" << std::endl;
        menuState = MenuState::RESTART;
    }
    else if (payoutSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        std::cout << "payoutSprite" << std::endl;
        menuState = MenuState::PAYOUT;
    }
    else if (historySprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        std::cout << "historySprite" << std::endl;
        menuState = MenuState::HISTORY;
    }
    else if (achievementsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        std::cout << "achievementsSprite" << std::endl;
        menuState = MenuState::ACHIEVEMENTS;
    }
    else if (profileSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        std::cout << "profileSprite" << std::endl;
        menuState = MenuState::PROFILE;
    }
}

void Menu::handleProfileClick(sf::Vector2i mousePos) {
}

void Menu::handleAchivementsClick(sf::Vector2i mousePos) {
    //Check Wallpaper Menu
    wallpapers->clickCheck(mousePos);
}

void Menu::handleHistoryClick(sf::Vector2i mousePos) {
}

void Menu::handlePayoutClick(sf::Vector2i mousePos) {
}

void Menu::handleRestartClick(sf::Vector2i mousePos) {
}

void Menu::handleCloseClick(sf::Vector2i mousePos) {
}


void Menu::setGameState(GameState* state) {
    gameState = state;
}

// if (menuState == MenuState::PROFILE) {
// }
// else if (menuState == MenuState::ACHIEVEMENTS) {
// }
// else if (menuState == MenuState::HISTORY) {
// }
// else if (menuState == MenuState::PAYOUT) {
// }
// else if (menuState == MenuState::RESTART) {
// }
// else if (menuState == MenuState::CLOSE) {
// }