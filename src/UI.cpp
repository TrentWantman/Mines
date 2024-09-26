#include "UI.h"

UI::UI() {
    // Initialize main menu elements
    font.loadFromFile("../fonts/ProximaNova.ttc");

    title.setFont(font);
    title.setString("Mines");
    title.setPosition(800, 100);

    startButton.setFont(font);
    startButton.setString("Start Game");
    startButton.setPosition(800, 300);

    // Initialize in-game elements
    scoreText.setFont(font);
    scoreText.setString("Score: 0");
    scoreText.setPosition(50, 50);

    healthText.setFont(font);
    healthText.setString("Health: 100");
    healthText.setPosition(50, 100);

    // Initialize game over elements
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setPosition(800, 100);

    // Start in the MainMenu state by default
    currentState = GameState::MainMenu;
}

void UI::setGameState(GameState state) {
    currentState = state;
}

void UI::setScore(int score) {
    scoreText.setString("Score: " + std::to_string(score));
}

void UI::setHealth(int health) {
    healthText.setString("Health: " + std::to_string(health));
}

void UI::setFinalScore(int finalScore) {
    finalScoreText.setString("Final Score: " + std::to_string(finalScore));
}

void UI::draw(sf::RenderWindow& window) {
    switch (currentState) {
        case GameState::MainMenu:
            window.draw(title);
        window.draw(startButton);
        break;
        case GameState::Playing:
            window.draw(scoreText);
        window.draw(healthText);
        break;
        case GameState::GameOver:
            window.draw(gameOverText);
        window.draw(finalScoreText);
        window.draw(restartButton);
        break;
    }
}
