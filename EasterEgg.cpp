#include "EasterEgg.h"
#include <iostream>  // For debugging purposes

EasterEgg::EasterEgg() : step(0), triggered(false) {}

// Check if Step 1 is triggered (bank has 0, game is over)
void EasterEgg::checkStep1(int bank, GameState gameState) {
    if (bank == 0 && gameState == GameState::GameOver) {
        if (!triggered) {
            step = 1; // Set the step to 1
            triggered = true; // Mark as triggered
            std::cout << "Easter Egg Step 1 triggered!" << std::endl;
        }
    }
}

// Return the current step of the Easter egg
int EasterEgg::getStep() const {
    return step;
}
