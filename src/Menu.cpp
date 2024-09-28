#include "Menu.h"
#include <iostream>

#include "EasterEgg.h"

Menu::Menu(GameState* state, Wallpapers* wallpapers, PayoutDisplay* payoutDisplay, History* history, Bank* bank, EasterEgg* easterEgg, Jeff* jeff)
:  showConfirmation(false), gameState(state), wallpapers(wallpapers), payoutDisplay(payoutDisplay), history(history), bank(bank), easterEgg(easterEgg), jeff(jeff)
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

    confirmClose.setTexture(Texture::GetTexture("confirmClose"));
    confirmClose.setPosition(633.98, 335.46);
    yes.setTexture(Texture::GetTexture("yes"));
    yes.setPosition(687.76, 482.97);
    no.setTexture(Texture::GetTexture("no"));
    no.setPosition(917.67, 482.97);

    achievementsSprite.setPosition(134, 863.9705 );
    historySprite.setPosition(262, 863.9705 );
    payoutSprite.setPosition(198, 863.9705 );
    phoneSprite.setPosition(70, 863.9705 );
    closeSprite.setPosition(326, 863.9705 );
    menuState = MenuState::PAYOUT;
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
        jeff->draw(window);
    }
    if (confirmingClose) {
        window.draw(confirmClose);
        window.draw(yes);
        window.draw(no);
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
    }
    if (confirmingClose) {
        handleCloseClick(mousePos);
    }
}

void::Menu::changeMenuState(sf::Vector2i mousePos) {
    if (closeSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        confirmingClose = true;
    }
    else if (phoneSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        menuState = MenuState::PHONE;
    }
    else if (payoutSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        menuState = MenuState::PAYOUT;
    }
    else if (historySprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        menuState = MenuState::HISTORY;
    }
    else if (achievementsSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
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
    if(bank->balance == 0 && *gameState != GameState::Playing){
        if (jeff->askForMoney.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
            jeff->borrowMoney();
        }
    }
    else if (jeff->payJeff.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
        jeff->pay();
    }
}

void Menu::handleCloseClick(sf::Vector2i mousePos) {
    if(yes.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
        menuState = MenuState::CLOSE;
    }
    else if (no.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
        confirmingClose = false;
    }
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