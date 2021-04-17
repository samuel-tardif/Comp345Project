#include "GameState.h"
#include <utility>

GameState::GameState(bool tournament) {

    //Validate Map and create
    bool validMap = false;

    while (!validMap)
    {
        // load map
        MapLoader loader;

        if (!tournament)
        {
            loader.GenerateMap();
        }
        else
        {
            // get file location
            std::string fileLocation;
            std::cout << "Enter map file location: ";
            std::cin >> fileLocation;
            loader.setFileName(fileLocation);
            loader.GenerateMap();
        }

        validMap = true;
    }
    int numOfPlayers;
    //Obtain the number of players who will be playing this game.
    std::cout << "How many people are playing (2~4)? : ";
    std::cin >> numOfPlayers;

    while (numOfPlayers < 2 || numOfPlayers > 4)
    {   
        cin.clear();
        cin.ignore();
        std::cout << "Invalid player count, please select a number between 2 and 4: ";
        std::cin >> numOfPlayers;
    }

    int initialCoins;

    //In tournament mode, everyone is going to have 14 coins since it's always 1v1
    if (tournament) {
        initialCoins = 14;
    } 
    else {
        //Decide how many coins each player will have (single mode)
        switch (numOfPlayers) {
        case 2:
            initialCoins = 14;
            break;
        case 3:
            initialCoins = 11;
            break;
        case 4:
            initialCoins = 9;
            break;
        }
    }

        //Create players
    for (int i = 0; i < numOfPlayers; i++) {
        
        string name;
        cout << "Enter the your player name: ";
        getline(cin, name) >> name;
        Player* p = new Player(name); //I'm inside a for loop, as soon as I get out of for loop it disappears so I need to make it into pointer.
        
        //Give coins to each player.
        p->setCoins(initialCoins);

        //Put the "player" in the vector of players
        players->push_back(p);
        
        //Had segmentation fault here because p->getname was pointing to a nullpointer
        std::cout << p->getName() << " is ready, and has " << p->getCoins() << " coins." << std::endl << std::endl;
        //SEGMENTATION FAULT? CAN'T FIND NAME AND COINS? BUT THERE ARE THERE IN LINE 76...
    }

    //MIGHT NEED TO BE IN ANOTHER FILE
    //Create 2 player deck during tournament mode
    int deckByNumOfPlayers = numOfPlayers;
    if (tournament) {
        deckByNumOfPlayers = 2;
    }

    //Create different deck depending on the number of players
    //The deck is shuffled when it is created.
    cout << "==Creating the deck==" << endl << endl;
    Deck *deck = new Deck(deckByNumOfPlayers);
}

GameState::~GameState() {
    if (map)
    {
        delete map;
        map = NULL;
    }
    if (players)
    {
        delete players;
        players = NULL;
    }
    if (deck)
    {
        delete deck;
        deck = NULL;
    }
}

int* GameState::getNumOfPlayers() {
    return numOfPlayers;
}

Map* GameState::getMap() {
    return map;
}

Deck* GameState::getDeck() {
    return deck;
}

vector<Cards*>* GameState::getTopboard() {
    return topboard;
}

vector<Player*>* GameState::getPlayers() {
    return players;
}

//MUTATORS
void GameState::setNumOfPlayers(int nop) {
    *numOfPlayers = nop;
}

void GameState::setMap(Map m) {
    *map = m;
}

void GameState::setDeck(Deck d) {
    *deck = d;
}

void GameState::setTopboard(vector<Cards*> tb) {
    *topboard = tb;
}

void GameState::setPlayers(vector<Player*> p) {
    *players = p;
}