#include "EasterEgg.h"

EasterEgg::EasterEgg() : step(0), phoneVisible(false), allInStep4(false) {
    phone.setTexture(Texture::GetTexture("phone"));
    phone.setPosition(100, 100); // Position it appropriately
    phone.scale(0.2,0.2);
}

void EasterEgg::checkStatus(double& bank, GameState gamestate, sf::Event& event) {
    if (bank <= 0 && step == 0 && gamestate == GameState::GameOver) {
        activatePhone();
        step = 1;
    }
    else if (step == 1 && event.type == sf::Event::MouseButtonPressed){
        if (phone.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            bank += 100; // Add $100 to bank
            phoneVisible = false; // Hide phone after click
            step = 2; // Move to the next step or manage as needed
        }
    }
    else if (step == 2 && bank >= 200) {
        step = 3;
        std::cout << step << std::endl;
    }
    else if (step == 3 && bank >= 1000){
        step = 4;
        std::cout << step << std::endl;
    }
}

void EasterEgg::checkStep4(double bank, double wagerAmount, GameState gamestate) {
       if (gamestate == GameState::PreGame) {
           if (bank == wagerAmount) {
               allInAmount = wagerAmount;
               allInStep4 = true;
           }
       }
       else if (gamestate == GameState::GameOver && allInStep4) {
           if (bank >= allInAmount*2.0) {
               step = 5;
               std::cout << step << std::endl;
           }
       }
}

void EasterEgg::update(sf::Event& event, double& bank) {

}

void EasterEgg::processGameResult(double multiplier, double& bank) {
    double result = bank * multiplier;
    bank += result; // Update bank based on the game result
    handleGameOutcome(bank, multiplier > 1); // Check if the game was won
}

void EasterEgg::activatePhone() {
    phoneVisible = true;
}

void EasterEgg::renderPhone(sf::RenderWindow& window) {
    if (phoneVisible) {
        window.draw(phone);
    }
}

bool EasterEgg::isPhoneActive() const {
    return phoneVisible;
}

void EasterEgg::handleAllInBet(double& bank) {
    // Placeholder for handling all-in bets
}

void EasterEgg::handleGameOutcome(double& bank, bool gameWon) {
    // Handle different game outcomes
}

void EasterEgg::manageEndGameScenarios(double& bank) {
    // Implement endgame scenarios based on current bank and game steps
}