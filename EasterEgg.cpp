#include "EasterEgg.h"
#include <iostream>  // For debugging purposes

EasterEgg::EasterEgg() : step(0), triggered(false) {
    phone.setTexture(Texture::GetTexture("phone"));
    phone.setPosition(0,0);
    phone.scale(0.2, 0.2);
    phone.setOrigin(phone.getGlobalBounds().width / 2, phone.getGlobalBounds().height / 2);
}

// Check if Step 1 is triggered (bank has 0, game is over)
void EasterEgg::checkStep1(int bank) {
    if (bank == 0) {
        if (!triggered) {
            step = 1; // Set the step to 1
            triggered = true; // Mark as triggered
            std::cout << "Easter Egg Step 0 triggered!" << std::endl;
        }
    }
}


void EasterEgg::checkStep2(int bank) {
    if (bank >= 200) {
        step = 2;
        std::cout << "Easter Egg Step 2 triggered!" << std::endl;
    }
}

void EasterEgg::checkStep3(int bank) {
    if (bank >= 1000) {
        step = 3;
        std::cout << "Easter Egg Step 3 triggered!" << std::endl;
    }
}

// Return the current step of the Easter egg
int EasterEgg::getStep() const {
    return step;
}
