#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

enum class GameState {
    MainMenu,
    Playing,
    GameOver
};

class UI {
public:
    UI();

    void setGameState(GameState state);  // Set the current game state
    void draw(sf::RenderWindow& window); // Draw based on the game state

    void setScore(int score);  // Update the score during the game
    void setHealth(int health);  // Update the health during the game
    void setFinalScore(int finalScore);  // Set final score for the game over screen

private:
    // Common UI elements
    GameState currentState;

    // Main Menu UI elements
    sf::Font font;

    sf::Text title;
    sf::Text startButton;

    // In-game UI elements
    sf::Text scoreText;
    sf::Text healthText;

    // Game Over UI elements
    sf::Text gameOverText;
    sf::Text finalScoreText;
    sf::Text restartButton;
};

#endif // UI_H
