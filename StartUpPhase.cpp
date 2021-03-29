#include "StartUpPhase.h"

void Start() {

    int numOfPlayers;

    int initialCoins;

    vector<Player> players;

    Map m;

    //Obtain the number of players who will be playing this game.
    std::cout << "How many people are playing (2~4)? :";
    std::cin >> numOfPlayers;

    while (numOfPlayers < 2 || numOfPlayers > 4)
    {   
        cin.clear();
        cin.ignore();
        std::cout << "Invalid player count, please select a number between 2 and 4: ";
        std::cin >> numOfPlayers;
    }

    //Decide how many coins each player will have.
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

    //Create players
    for (int i = 0; i < numOfPlayers; i++) {
        //Maybe ask the names?
        Player p = Player();
        
        //Give coins to each player.
        p.setCoins(initialCoins);

        //Set a player ID. Maybe not needed
        p.setPlayerID(i); 

        //Put the "player" in the vector of players
        players.insert(players.begin()+1, p);
        
        //Print 
        std::cout << "Player " << p.getPlayerID() + 1 << " is ready, and has " << p.getCoins() << " coins." << std::endl;
    }

    //Create different deck depending on the number of players
    //The deck is shuffled when it is created.
    Deck deck = Deck(numOfPlayers);
    
    //Create empty hands
    for (int i = 0; i < numOfPlayers; i++) {
		cout << "Player " << i + 1 << ": ";
		players[i].initializeHand(); //giving each player an empty hand with 0 cards
		players[i].printHand(); //Displaying the hand. Shouldn't print anything
	}
    //Draw 6 cards (top board)
    vector<Cards*> topboard = deck.topBoardGenetor(deck);
    deck.displayTopBoard(topboard);

    //Bidding
    //Obtain the bidding coins of each player.
    for (int i = 0; i < numOfPlayers; i++) {
        cin.clear();
        cin.ignore();
        players[i].setBid();
    }
    BidingFacility calculator = BidingFacility();

    //Decides which player (e.g. 1 or 2 goes first depending on the amount of coins)
    Player* winner = calculator.resolveBids();

    std::cout << winner << " goes first." << std::endl;

    //the winner goes first (Only works for 2 player game)
    if (players[0].getName() != winner->getName()) {
        Player tempPlayer = players[0];
        players[0] = *winner;
        players[1] = tempPlayer;
    }

    //Assign resources to players
    for (int i = 0; i < numOfPlayers; i++) {
        players[i].Player::SetCubes(14);
        players[i].Player::SetDisks(3);

        players[i].placeNewArmies(m, 0, 4, i);
        
        std::cout << "Choose the index of the territory you want to place your army (except the starting region)." << std::endl;
        int index;
        cin >> index;
        while (index == 0 || index > m.getTerritoriesVector()->size()) {
            cout << "You can't place your army there. Try again." << endl;
        };
        players[i].placeNewArmies(m, index, 1, i);
    }
    int indexOfPlayers = 0;
    //Take turn to place 10 non-player owned armies (2 players) 
    if (numOfPlayers == 2) {
		Player npc = Player();
		npc.SetCubes(10);
		int selectTerr = 0;
		for (int i = 0; i < npc.getCubes(); i++) {

            indexOfPlayers %= 2; //This decides whose turn it is.

			cout << players[indexOfPlayers].getName() << ", enter the territory index to place non-player army: ";
			cin >> selectTerr;
			while (selectTerr > m.getTerritoriesVector()->size() || selectTerr < 1) {
				cout << "Invalid Territory ID. Try again: ";
				cin >> selectTerr;
			}
			players[i].placeNewArmies(m, selectTerr, 1, numOfPlayers+1);

            indexOfPlayers++;
		}
	}



//=====================================================================================================================================================================
    std::cout << "[PART 3: MAIN GAME LOOP]\n" << std::endl;

    indexOfPlayers = 0;
    //keep doing until the hands of both players are over 11 (2 players)
    do {
        indexOfPlayers %= 2; //This decides whose turn it is.
        std::cout << "It is currently " << players[indexOfPlayers].getName() << "'s turn to play." << std::endl;
        
        //Buy
        deck.exchange(players[indexOfPlayers], topboard, deck);

        indexOfPlayers++;
    }
    //Keep doing this until both players have 11 cards in their hand.
    while (players[indexOfPlayers].getHand().size() < 11 && players[indexOfPlayers+1].getHand().size() < 11);

};


