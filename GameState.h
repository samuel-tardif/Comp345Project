#pragma once
#include "Player.h"
#include "Cards.h"
#include "Deck.h"
#include "Map.h"
#include "MapLoader.h"
#include "GameObservers.h"

class Deck;

class GameState : public Observable {

    public:
        int numOfPlayers;
        Map *map;
        Deck *deck;
        vector<Cards*> *topboard;

        vector<Player*> *players;

        GameState(bool tournament);
        ~GameState();
};