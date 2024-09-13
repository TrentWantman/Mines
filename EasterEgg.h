#ifndef EASTER_EGG_H
#define EASTER_EGG_H

#include "GameState.h"
#include "Texture.h"
#include <SFML/Graphics.hpp>

class EasterEgg {
public:
    EasterEgg();

    sf::Sprite phone;
    bool friendLoanedMoney = false;

    void checkStep1(int bank); //Lose All Your Money
    void checkStep2(int bank); //Get Back Money You Lost
    void checkStep3(int bank); //Get Rich
    void checkStep4(int bank, GameState gameState); //Once rich go all In and double money in one game
    void checkStep5(int bank, GameState gameState); //Loose all the money you doubled. Still rich and should back out and enjoy good ending cutscene.
    void checkStep6(int bank, GameState gameState); //Get back to money your friend lended you. Give it back to them and enjoy the rightous cutscene.
    void checkStep7(int bank, GameState gameState); //Lose all your money and can't pay back friend. End the game and enjoy the bad ending cutscene.

    int getStep() const;

private:
    int step;
    bool triggered;
};

#endif // EASTER_EGG_H
