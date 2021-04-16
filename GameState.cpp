#include "GameState.h"
#include <utility>

GameState::GameState(bool tournament) {

    //Validate Map and create
    bool validMap = false;

    while (!validMap)
    {
        try
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

        catch (const char *msg)
        {
            std::cout << "Error: Invalid map file. ";
            std::cout << msg << std::endl;
        }
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
        std::cout << p->getNameForOthers() << " is ready, and has " << p->getCoinsForOthers() << " coins." << std::endl << std::endl;
    }

    //Create 2 player deck during tournament mode
    int deckByBNumOfPlayers = numOfPlayers;
    if (tournament) {
        deckByBNumOfPlayers = 2;
    }

    //Create different deck depending on the number of players
    //The deck is shuffled when it is created.
    cout << "==Creating the deck==" << endl << endl;
    Deck *deck = new Deck(deckByBNumOfPlayers);
//==============================================================================================
    cout << "==Your hands==" << endl;
    //Create empty hands
    for (int i = 0; i < numOfPlayers; i++) {
		cout << players->at(i)->getNameForOthers() << ": ";
		players->at(i)->initializeHand(); //giving each player an empty hand with 0 cards
		players->at(i)->printHand(); //Displaying the hand. Shouldn't print anything
	}
	cout << endl;

	//The same for both game mode
    cout << "==Generating the topboard==" << endl;
    //Draw 6 cards (top board)
    vector<Cards*> *topboard = deck->topBoardGenetor(*deck);
    deck->displayTopBoard(*topboard);

    //Bidding
    //Obtain the bidding coins of each player.
    cout << endl;
    cout << "==Bidding==" << endl;
    for (int i = 0; i < numOfPlayers; i++) {
        cin.clear();
        cin.ignore();
        players->at(i)->setBid(players->at(i));
    }

    cout << endl;
    cout << "==Order==" << endl;
    BidingFacility calculator = BidingFacility();
    
    //Decides which player (e.g. 1 or 2 goes first depending on the amount of coins)
    Player* winner = calculator.resolveBids(*players);

    std::cout << winner->getNameForOthers() << " goes first." << std::endl;

    //the winner goes first 
    int playerOrder = 0;

    for (auto it = players->begin(); it != players->end(); ++it) {
        if (players->at(playerOrder)->getName() == winner->getName()) {
            auto first = *it;
            players->erase(it);
            players->insert(players->begin(), first /* or std::move(first)*/) ;
            break;
        }
    }
}