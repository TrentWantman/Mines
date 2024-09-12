#ifndef EASTER_EGG_H
#define EASTER_EGG_H

#include "GameState.h"

class EasterEgg {
public:
    EasterEgg();

    void checkStep1(int bank, GameState gameState);

    int getStep() const;

private:
    int step;
    bool triggered;
};

#endif // EASTER_EGG_H
