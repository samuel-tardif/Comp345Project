#include "EightMinuteEmpire.h"

int main() {

    GameEngine gameEngine;
    bool gameMode = gameEngine.selectGameMode();

    if (gameMode == false) {
        gameEngine.singleGameMode();
    }
    else {
        gameEngine.tournamentMode();
    }
    return 0;
}