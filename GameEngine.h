#include "Player.h"
#include "Cards.h"
#include "Deck.h"
#include "Map.h"
#include "BidingFacility.h"
#include "MapLoader.h"
#include <vector>
#include <iostream>

class GameEngine {
    
    public:
        bool selectGameMode();
        void singleGameMode();
        void tournamentMode();
};