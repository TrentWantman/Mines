#include "Menu.h"
#include <iostream>

#include "EasterEgg.h"

Menu::Menu(GameState* state, Wallpapers* wallpapers, PayoutDisplay* payoutDisplay, History* history, Bank* bank, EasterEgg* easterEgg)
:  showConfirmation(false), gameState(state), wallpapers(wallpapers), payoutDisplay(payoutDisplay), history(history), bank(bank), easterEgg(easterEgg)
{
    // Initialize the background sprite and options button sprite
    backgroundSprite.setTexture(Texture::GetTexture("menuBack"));
    appsRect.setTexture(Texture::GetTexture("appsRect"));
    backgroundSprite.setPosition(18, 414);
    appsRect.setPosition(57.78 ,852.7 );
    achievementsSprite.setTexture(Texture::GetTexture("achievements"));
    historySprite.setTexture(Texture::GetTexture("history"));
    payoutSprite.setTexture(Texture::GetTexture("payout"));
    restartSprite.setTexture(Texture::GetTexture("restart"));
    closeSprite.setTexture(Texture::GetTexture("close"));
    phoneSprite.setTexture(Texture::GetTexture("phone"));

    achievementsSprite.setPosition(134, 863.9705 );
    historySprite.setPosition(262, 863.9705 );
    payoutSprite.setPosition(198, 863.9705 );
    phoneSprite.setPosition(70, 863.9705 );
    closeSprite.setPosition(326, 863.9705 );
}

void Menu::render(sf::RenderWindow& window) {
    //window.draw(backgroundSprite);
    window.draw(appsRect);
    window.draw(achievementsSprite);
    window.draw(historySprite);
    window.draw(payoutSprite);
    window.draw(phoneSprite);
    window.draw(closeSprite);

    if (menuState == MenuState::ACHIEVEMENTS) {
        wallpapers->drawMenu(window);
    }
    else if (menuState == MenuState::HISTORY) {
        history->displayHistory(window);
    }
    else if (menuState == MenuState::PAYOUT) {
        payoutDisplay->displayPayoutsOnScreen(window);
    }
    else if (menuState == MenuState::PHONE) {
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
        if (menuState == MenuState::ACHIEVEMENTS) {
            handleAchivementsClick(mousePos);
        }
        else if (menuState == MenuState::HISTORY) {
            handleHistoryClick(mousePos);
        }
        else if (menuState == MenuState::PAYOUT) {
            handlePayoutClick(mousePos);
        }
        else if (menuState == MenuState::PHONE) {
            handlePhoneClick(mousePos);
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
    else if (phoneSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        std::cout << "phoneprite" << std::endl;
        menuState = MenuState::PHONE;
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
}

void Menu::handleAchivementsClick(sf::Vector2i mousePos) {
    //Check Wallpaper Menu
    wallpapers->clickCheck(mousePos);
}

void Menu::handleHistoryClick(sf::Vector2i mousePos) {
    if (history->downArrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
        history->scrollDown();
    }
    else if (history->upArrow.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
        history->scrollUp();
    }
}

void Menu::handlePayoutClick(sf::Vector2i mousePos) {
}

void Menu::handlePhoneClick(sf::Vector2i mousePos) {
    if (bank->balance == 0) {
        bank->deposit(100);
    }
}

void Menu::handleCloseClick(sf::Vector2i mousePos) {
}


void Menu::setGameState(GameState* state) {
    gameState = state;
}

// if (menuState == MenuState::ACHIEVEMENTS) {
// }
// else if (menuState == MenuState::HISTORY) {
// }
// else if (menuState == MenuState::PAYOUT) {
// }
// else if (menuState == MenuState::RESTART) {
// }
// else if (menuState == MenuState::CLOSE) {
// }