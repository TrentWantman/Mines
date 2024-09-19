#include "EasterEgg.h"

EasterEgg::EasterEgg() : step(0), phoneVisible(false), allInStep4(false) {
    phone.setTexture(Texture::GetTexture("phone"));
    phone.setPosition(100, 100); // Position it appropriately
    phone.scale(0.2,0.2);
    font.loadFromFile("./fonts/ProximaNova.ttc");
    // Initialize rectangle shapes
    rect1.setSize(sf::Vector2f(414, 554));  // Size: 200x100
    rect1.setPosition(18, 414);  // Position rect1 at (100, 100)
    rect1.setFillColor(sf::Color(85,112,134,140));
    rect2.setSize(sf::Vector2f(414, 554));  // Size: 200x100
    rect2.setPosition(18, 414);  // Position rect1 at (100, 100)
    rect2.setFillColor(sf::Color::White);
    rect3.setSize(sf::Vector2f(416, 556));
    rect3.setPosition(17, 413);
    rect3.setFillColor(sf::Color::Black);

    text1.setFont(font);
    text1.setString("Rectangle 1");
    text1.setCharacterSize(24);  // Set character size
    text1.setFillColor(sf::Color::Black);  // Set text color

    // Center the origins of the texts
    sf::FloatRect text1Bounds = text1.getLocalBounds();
    text1.setOrigin(text1Bounds.left + text1Bounds.width / 2, text1Bounds.top + text1Bounds.height / 2);


    // Position the texts at the center of their respective rectangles
    text1.setPosition(rect1.getPosition().x + rect1.getSize().x / 2, rect1.getPosition().y + rect1.getSize().y / 2);
}


void EasterEgg::checkStatus(double& bank, GameState gameState, sf::Event& event, sf::Text& bankText) {
    if (bank <= 0 && step == 0 && gameState == GameState::GameOver) {
        activatePhone();
        step = 1;
    }
    else if (step == 1 && event.type == sf::Event::MouseButtonPressed){
        if (phone.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            bank += 100; // Add $100 to bank
            phoneVisible = false; // Hide phone after click
            step = 2; // Move to the next step or manage as needed
            ostringstream bankStream;
            bankStream << fixed << setprecision(2) << bank;
            bankText.setString("Bank: $" + bankStream.str());
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
    else if (step >= 5) {
        if (bank > allInAmount * 1.67){
            step = 6;
            std::cout << "Cashout now for rich ending scene" << std::endl;
        }
        else if (bank <= allInAmount * 1.67 && bank >= allInAmount){
            step = 6;
            std::cout << "Cashout now for good ending scene" << std::endl;
        }
        else if (bank < allInAmount && bank >= 100.00) {
            step = 6;
            std::cout << "Cashout now for righteous ending scene" << std::endl;
        }
        else if (bank == 0) {
            step = 6;
            std::cout << "Cashout now for bad ending scene" << std::endl;
        }
    }
}

void EasterEgg::checkStep4(double bank, double wagerAmount, GameState gameState) {
       if (gameState == GameState::PreGame) {
           if (bank == wagerAmount) {
               allInAmount = wagerAmount;
               allInStep4 = true;
           }
       }
       else if (gameState == GameState::GameOver && allInStep4) {
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

void EasterEgg::render(sf::RenderWindow& window, GameState gameState) {
    if (phoneVisible) {
        window.draw(phone);
    }
    window.draw(rect3);
    window.draw(rect2);
    window.draw(rect1);
    window.draw(text1);
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