#pragma once
#include "Player.h"
#include "Cards.h"
#include "Deck.h"
#include "Map.h"
#include "MapLoader.h"
#include "GameObservers.h"

class Deck;

class GameState {

    private:
        int* numOfPlayers = 0;
        Map* map;
        Deck* deck;
        vector<Cards*>* topboard;
        vector<Player*>* players;

    public:
        GameState(bool tournament);
        ~GameState();

        //ACCESSORS
        int* getNumOfPlayers();

        Map* getMap();

        Deck* getDeck();

        vector<Cards*>* getTopboard();

        vector<Player*>* getPlayers();

        //MUTATORS
        void setNumOfPlayers(int nop);

        void setMap(Map m);

        void setDeck(Deck d);

        void setTopboard(vector<Cards*> tb);

        void setPlayers(vector<Player*> p);


};