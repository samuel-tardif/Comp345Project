#pragma once
#include "Player.h"
#include "Cards.h"
#include "Deck.h"
#include "Map.h"
#include "MapLoader.h"

class Deck;

class GameState {

    public:
        int numOfPlayers;
        Map *map;
        Deck *deck;
        vector<Cards*> *topboard;

        vector<Player*> *players;

        GameState(bool tournament);
        ~GameState();
};